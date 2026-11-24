#include "u64_helper.h"

#include "../int/bit_operations.h"
#include "u64_arithmetic.h"
#include "u64_binary.h"

my_big_decimal convert_to_big_dec(my_decimal value) {
  int status = SUCCESS;
  my_big_decimal big_value = {0};

  big_value.bits[0] = value.bits[1];
  big_value = my_big_dec_shift(big_value, -LIMB_W, &status);

  big_value.bits[0] |= value.bits[0];
  big_value.bits[1] = value.bits[2];

  big_value.meta = value.bits[METADATA];

  return big_value;
}

my_decimal convert_to_dec(my_big_decimal big_value) {
  my_decimal value = {0};

  unsigned long long mask0 = ~0U;
  unsigned long long mask1 = ~0LLU << LIMB_W;

  value.bits[0] = big_value.bits[0] & mask0;
  value.bits[1] = ((big_value.bits[0] & mask1) >> LIMB_W);

  value.bits[2] = big_value.bits[1];

  value.bits[METADATA] = big_value.meta;

  return value;
}

signed char my_big_dec_bit_cmp(my_big_decimal mant1, my_big_decimal mant2) {
  signed char result = 0;
  for (int i = LIMB_MAX - 2; i >= LO; --i)
    result += (mant2.bits[i] == mant1.bits[i]);
  if (result == LIMB_MAX - 1)
    return 0;
  else
    result = 0;

  short max_bit = 0, m2 = 0, m1 = 0;
  m1 = my_big_dec_highest_digit(mant1), m2 = my_big_dec_highest_digit(mant2);
  max_bit = (m1 > m2) ? m1 : m2;

  for (short di = max_bit; di >= 0 && !result; --di) {
    unsigned b1 = my_big_dec_getbit(mant1, di),
             b2 = my_big_dec_getbit(mant2, di);
    if (b1 > b2)
      result = 1;
    else if (b1 < b2)
      result = -1;
  }
  return result;
}
my_big_decimal my_big_dec_trim_zeros(my_big_decimal num, int *status) {
  if (BIG_DEC_IS_EMPTY(num)) return num;

  short scale = big_dec_getpower(&num);
  signed char sign = big_dec_getsign(&num);

  int can_trim = 1;
  while (scale > 0 && can_trim) {
    my_big_decimal rem = (my_big_decimal){0};
    my_big_decimal del = my_big_dec_bit_div(num, BIG_DEC_TEN, &rem, status);
    if (BIG_DEC_IS_ZERO(rem)) {
      num = del;
      scale--;
    } else {
      can_trim = 0;
    }
  }

  big_dec_setsign(&num, sign);
  big_dec_setpower(&num, scale);
  return num;
}

my_big_decimal my_big_dec_bank(my_big_decimal num, short scale_cut,
                                 int *status) {
  my_big_decimal rem = {0};
  my_big_decimal ten_nth_power =
      my_big_dec_power10(BIG_DEC_ONE, scale_cut, status);

  num = my_big_dec_bit_div(num, ten_nth_power, &rem, status);
  my_big_dec_trim_zeros(num, status);
  my_big_decimal rounded = {0};

  my_big_decimal int_rem_div = {0};

  int rem_flag = 0;
  rem = my_big_dec_bit_div(rem, BIG_DEC_TEN, &int_rem_div, status);
  while (!BIG_DEC_IS_ZERO(rem)) {
    rem = my_big_dec_bit_div(rem, BIG_DEC_TEN, &int_rem_div, status);
    if (!BIG_DEC_IS_ZERO(int_rem_div)) rem_flag = 1;
  }
  rem = int_rem_div;

  short result_cmp = 0;
  result_cmp = my_big_dec_bit_cmp(rem, BIG_DEC_FIVE);

  if ((result_cmp == 0 && (!IS_EVEN(num) || rem_flag == 1)) ||
      (result_cmp == 1)) {
    rounded = my_big_dec_bit_add(num, BIG_DEC_ONE, status);
    rounded.meta = num.meta;
  } else
    rounded = num;

  return rounded;
}

short big_dec_setpower(my_big_decimal *n, int power) {
  if (!n || (power > SCALE_BIG_MAX || power < 0)) {
    return ERROR;
  }
  n->meta = setbits(n->meta, 16, CHAR_BIT, power);
  return SUCCESS;
}

short big_dec_getpower(const my_big_decimal *n) {
  if (!n) return ERROR;
  return getbits(n->meta, 16, CHAR_BIT);
}

short my_big_dec_highest_digit(my_big_decimal n) {
  short res = -1;
  for (short limb = HI; limb >= LO && res == -1; --limb) {
    res = big_dec_max_digit(n.bits[limb]);
    if (res != -1) res += limb * LIMB_BIG_W;
  }
  return res;
}

signed char big_dec_setsign(my_big_decimal *n, int sign) {
  if (!n || (sign != POSITIVE_SIGN && sign != NEGATIVE_SIGN)) {
    return ERROR;
  }

  if (sign == NEGATIVE_SIGN) n->meta |= MINUS;
  return SUCCESS;
}

signed char big_dec_getsign(const my_big_decimal *n) {
  if (!n) {
    return ERROR;
  }

  return (n->meta & MINUS) ? NEGATIVE_SIGN : POSITIVE_SIGN;
}
