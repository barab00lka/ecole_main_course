#include "u64_arithmetic.h"

#include "../int/bit_operations.h"
#include "../my_decimal.h"
#include "u64_binary.h"
#include "u64_helper.h"

static my_big_decimal big_dec_round_to_decimal(my_big_decimal value,
                                                int *scale, int *status) {
  *scale = big_dec_getpower(&value);
  if (*scale >= 29) {
    value = my_big_dec_bank(value, *scale - 28, status);
    *scale -= (*scale - 28);
  }

  for (; my_big_dec_highest_digit(value) >= 96 && *scale > 0; --(*scale)) {
    value = my_big_dec_bank(value, 1, status);
  }

  return value;
}

int my_big_dec_add_sub(my_big_decimal value_1, my_big_decimal value_2,
                        my_big_decimal *result, int flag) {
  if (!result) {
    return ERROR_ARG;
  }

  int status = SUCCESS;
  signed char res_sign = POSITIVE_SIGN;

  status = my_big_dec_normalize(&value_1, &value_2);

  short cmp = my_big_dec_bit_cmp(value_1, value_2);

  if (flag == IS_ADD_FUNCTION)
    res_sign = big_dec_plus_handle_signs(&value_1, &value_2, &cmp);
  if (flag == IS_SUB_FUNCTION)
    res_sign = big_dec_minus_handle_signs(&value_1, &value_2, &cmp);

  int scale = big_dec_getpower(&value_1);

  if (cmp == CHOOSE_ADDITION) {
    *result = my_big_dec_bit_add(value_1, value_2, &status);
    big_dec_setpower(result, scale);

  } else if (cmp == CHOOSE_SUBSTRACTION) {
    *result = my_big_dec_bit_sub(value_1, value_2, &status);
    big_dec_setpower(result, scale);
  }

  *result = big_dec_round_to_decimal(*result, &scale, &status);

  if (scale == 0 && my_big_dec_highest_digit(*result) >= 96) {
    status = (res_sign) ? N_INF : INF;
  }

  big_dec_setsign(result, res_sign);

  return status;
}

int my_big_dec_mul(my_big_decimal value_1, my_big_decimal value_2,
                    my_big_decimal *result) {
  int status = SUCCESS;
  signed char sign_1 = big_dec_getsign(&value_1),
              sign_2 = big_dec_getsign(&value_2);
  int scale = big_dec_getpower(&value_1) + big_dec_getpower(&value_2);

  *result = my_big_dec_bit_mul(value_1, value_2, &status);
  big_dec_setpower(result, scale);

  *result = big_dec_round_to_decimal(*result, &scale, &status);

  if (my_big_dec_highest_digit(*result) >= 96 && scale == 0) {
    status = (sign_1 ^ sign_2) ? N_INF : INF;
  }

  big_dec_setsign(result, sign_1 ^ sign_2);
  return status;
}

static short big_dec_calc_fractional(my_big_decimal *src,
                                     my_big_decimal divisor,
                                     my_big_decimal *remainder) {
  short power = 0;
  int status = SUCCESS;

  for (; (!(BIG_DEC_IS_ZERO((*remainder)))) && power < (SCALE_MAX + 2);
       ++power) {
    *remainder = my_big_dec_power10(*remainder, 1, &status);
    *src = my_big_dec_power10(*src, 1, &status);

    my_big_decimal new_rem = {0};
    my_big_decimal new_int =
        my_big_dec_bit_div(*remainder, divisor, &new_rem, &status);

    *src = my_big_dec_bit_add(*src, new_int, &status);
    *remainder = new_rem;
  }
  return power;
}

int my_big_dec_div(my_big_decimal value_1, my_big_decimal value_2,
                    my_big_decimal *result) {
  int status = SUCCESS;
  short p1 = big_dec_getpower(&value_1), p2 = big_dec_getpower(&value_2);

  int sign_1 = big_dec_getsign(&value_1), sign_2 = big_dec_getsign(&value_2);

  my_big_decimal integer = {0};

  my_big_decimal remainder = {0};
  integer = my_big_dec_bit_div(value_1, value_2, &remainder, &status);

  big_dec_setpower(&remainder, 0), big_dec_setpower(&integer, 0);

  short power = big_dec_calc_fractional(&integer, value_2, &remainder);

  short scale_out = power + p1 - p2;

  if (scale_out < 0) {
    integer = my_big_dec_power10(integer, -scale_out, &status);
    scale_out = 0;
  }

  big_dec_setpower(&integer, scale_out);

  if (scale_out >= 29) {
    integer = my_big_dec_bank(integer, scale_out - 28, &status);
    scale_out -= (scale_out - 28);
  }

  int scale_cut = 0;
  my_big_decimal n = integer;
  while (my_big_dec_highest_digit(n) >= 96) {
    n = my_big_dec_bank(n, 1, &status);
    scale_cut += 1;
  }

  if (my_big_dec_highest_digit(integer) >= 96 &&
      (scale_out - scale_cut) >= 0) {
    integer = my_big_dec_bank(integer, scale_cut, &status);
  }

  if (my_big_dec_highest_digit(integer) >= 96 && scale_out == 0) {
    status = (sign_1 ^ sign_2) ? N_INF : INF;
  }

  integer = my_big_dec_trim_zeros(integer, &status);

  big_dec_setsign(&integer,
                  (sign_1 + sign_2 == 1) ? NEGATIVE_SIGN : POSITIVE_SIGN);

  *result = integer;
  return status;
}

int my_big_dec_normalize(my_big_decimal *value_1, my_big_decimal *value_2) {
  if (!value_1 || !value_2) {
    return ERROR_ARG;
  }

  const short p1 = big_dec_getpower(value_1);
  const short p2 = big_dec_getpower(value_2);

  if (p1 == ERROR || p2 == ERROR) {
    return ERROR_SCALE;
  }

  if (p1 == p2) {
    return SUCCESS;
  }

  int status = SUCCESS;

  const short power_difference = p1 - p2;
  const short abs_power_difference =
      (power_difference > 0) ? power_difference : -1 * power_difference;

  my_big_decimal *choosen_value = (power_difference > 0) ? value_2 : value_1;

  my_big_decimal tmp = {0};

  tmp = my_big_dec_power10(*choosen_value, abs_power_difference, &status);

  if (status == SUCCESS) {
    *choosen_value = tmp;
  } else if (status == ERROR || status == ADD_OVERFLOW) {
    my_big_decimal *choosen_value = (power_difference > 0) ? value_1 : value_2;

    my_big_decimal remainder = {0};
    my_big_decimal ten_nth_power =
        my_big_dec_power10(BIG_DEC_ONE, abs_power_difference, &status);

    *choosen_value =
        my_big_dec_bit_div(*choosen_value, ten_nth_power, &remainder, &status);
  }

  return status;
}

my_big_decimal my_big_dec_bit_add(my_big_decimal value_1,
                                    my_big_decimal value_2, int *status) {
  if (!status) {
    return (my_big_decimal){0};
  }

  short di1 = my_big_dec_highest_digit(value_1),
        di2 = my_big_dec_highest_digit(value_2);
  short max_di = (di1 > di2) ? di1 : di2;

  my_big_decimal result = {0};
  unsigned long long carry = 0;

  for (int di = 0; di <= max_di + 1; di++) {
    unsigned long a = my_big_dec_getbit(value_1, di);
    unsigned long b = my_big_dec_getbit(value_2, di);

    unsigned long long sum_bit =
        (di < (int)MANTISSA_BIG_W) ? full_adder_u64(a, b, &carry) : 0;

    if (sum_bit) {
      my_big_decimal bit_di = my_big_dec_shift(BIG_DEC_ONE, -di, status);
      result = my_big_dec_or(result, bit_di);
    }
  }

  *status = carry ? ADD_OVERFLOW : SUCCESS;

  return result;
}

my_big_decimal my_big_dec_bit_sub(my_big_decimal value_1,
                                    my_big_decimal value_2, int *status) {
  my_big_decimal result = {0};
  unsigned borrow = 0;
  *status = SUCCESS;

  for (int i = 0; i < (int)MANTISSA_BIG_W; i++) {
    unsigned bit_a = my_big_dec_getbit(value_1, i);
    unsigned bit_b = my_big_dec_getbit(value_2, i);

    unsigned bit_result = bit_a ^ bit_b ^ borrow;

    if (bit_result) {
      my_big_decimal bit_di = my_big_dec_shift(BIG_DEC_ONE, -i, status);
      result = my_big_dec_or(result, bit_di);
    }

    borrow = (bit_a < bit_b + borrow) ? 1 : 0;
  }

  big_dec_setpower(&result, big_dec_getpower(&value_1));
  *status = borrow ? SUB_OVERFLOW : SUCCESS;

  return result;
}

my_big_decimal my_big_dec_bit_mul(my_big_decimal value_1,
                                    my_big_decimal value_2, int *status) {
  my_big_decimal result = {0};

  my_big_decimal product = value_1;

  short max_bit_val2 = my_big_dec_highest_digit(value_2);
  for (int i = 0; i <= max_bit_val2; ++i) {
    if (my_big_dec_getbit(value_2, i)) {
      my_big_decimal sum_res = {0};
      sum_res = my_big_dec_bit_add(result, product, status);
      result = sum_res;
    }
    product = my_big_dec_shift(product, -1, status);
  }

  big_dec_setpower(&result,
                   big_dec_getpower(&value_1) + big_dec_getpower(&value_2));
  return result;
}

my_big_decimal my_big_dec_bit_div(my_big_decimal value_1,
                                    my_big_decimal value_2,
                                    my_big_decimal *rem, int *status) {
  if (value_2.bits[2] == 0U && value_2.bits[1] == 0U && value_2.bits[0] == 0U) {
    *status = NaN;
    return value_1;
  }

  *status = SUCCESS;
  short m1 = my_big_dec_highest_digit(value_1),
        m2 = my_big_dec_highest_digit(value_2);

  *rem = value_1;
  if (m2 < m1) {
    value_2 = my_big_dec_shift(value_2, -(m1 - m2), status);
  }

  my_big_decimal result = {0};

  for (int di = (m1 - m2); di >= 0; --di) {
    if (my_big_dec_bit_cmp(*rem, value_2) >= 0) {
      *rem = my_big_dec_bit_sub(*rem, value_2, status);
      result =
          my_big_dec_or(result, my_big_dec_shift(BIG_DEC_ONE, -di, status));
    }

    value_2 = my_big_dec_shift(value_2, 1, status);
  }

  big_dec_setpower(&result,
                   big_dec_getpower(&value_1) - big_dec_getpower(&value_2));

  return result;
}

my_big_decimal my_big_dec_power10(my_big_decimal num, short scale,
                                    int *status) {
  if (scale == 0) return num;

  short old_power = big_dec_getpower(&num), old_sign = big_dec_getsign(&num);
  my_big_decimal sum_res = {0};
  for (int i = 0; i < scale; ++i) {
    sum_res = my_big_dec_bit_add(my_big_dec_shift(num, -3, status),
                                  my_big_dec_shift(num, -1, status), status);
    num = sum_res;
  }

  big_dec_setsign(&num, old_sign);

  big_dec_setpower(&num, (old_power + scale));

  return num;
}

signed char big_dec_plus_handle_signs(my_big_decimal *x, my_big_decimal *y,
                                      short *compare) {
  signed char res_sign = POSITIVE_SIGN;

  signed char s1 = big_dec_getsign(x), s2 = big_dec_getsign(y);

  switch (*compare) {
    case 1:
      if ((s1 == NEGATIVE_SIGN && s2 == POSITIVE_SIGN) || s1 + s2 == 2)
        res_sign = NEGATIVE_SIGN;
      break;
    case -1:
      if (s1 + s2 == 2)
        res_sign = NEGATIVE_SIGN;
      else if (s1 ^ s2) {
        my_big_decimal temp = *x;
        *x = *y, *y = temp;
        if (s2 == NEGATIVE_SIGN) {
          big_dec_setsign(y, POSITIVE_SIGN);
          res_sign = NEGATIVE_SIGN;
        } else
          big_dec_setsign(x, POSITIVE_SIGN);
      }
      break;

    case 0:

      if (s1 + s2 == 2) res_sign = NEGATIVE_SIGN;
      break;
  }

  *compare = (s1 ^ s2) ? CHOOSE_SUBSTRACTION : CHOOSE_ADDITION;

  return res_sign;
}

signed char big_dec_minus_handle_signs(my_big_decimal *x, my_big_decimal *y,
                                       short *compare) {
  signed char res_sign = POSITIVE_SIGN;

  signed char s1 = big_dec_getsign(x), s2 = big_dec_getsign(y);

  switch (*compare) {
    case 1:
      if (s1 + s2 == 2)
        res_sign = NEGATIVE_SIGN;
      else if (s1 - s2 == 1)
        res_sign = NEGATIVE_SIGN;
      break;
    case -1:
      if (s1 == s2) {
        my_big_decimal temp = *x;
        *x = *y, *y = temp;
        if (s1 == POSITIVE_SIGN) res_sign = NEGATIVE_SIGN;
      } else if (s2 == POSITIVE_SIGN)
        res_sign = NEGATIVE_SIGN;
      break;
    case 0:

      if (s1 - s2 == 1) res_sign = NEGATIVE_SIGN;

      break;
  }

  *compare = (s1 ^ s2) ? CHOOSE_ADDITION : CHOOSE_SUBSTRACTION;

  return res_sign;
}
