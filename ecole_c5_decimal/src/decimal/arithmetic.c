#include "arithmetic.h"
#include "../helper/helper.h"
#include "../my_decimal.h"
#include "binary.h"

my_decimal my_dec_bit_sub(my_decimal value_1, my_decimal value_2,
                            int *status) {
  my_decimal result = {0};
  unsigned borrow = 0;
  *status = SUCCESS;
  for (int i = 0; i < (int)MANTISSA_W; i++) {
    unsigned bit_a = my_dec_getbit(value_1, i);
    unsigned bit_b = my_dec_getbit(value_2, i);

    unsigned bit_result = bit_a ^ bit_b ^ borrow;

    if (bit_result) {
      my_decimal bit_di = my_dec_shift(DEC_ONE, -i, status);
      result = my_dec_or(result, bit_di);
    }

    borrow = (bit_a < bit_b + borrow) ? 1 : 0;
  }

  setpower(&result, getpower(&value_1));
  *status = borrow ? SUB_OVERFLOW : SUCCESS;

  return result;
}

my_decimal my_dec_bit_div(my_decimal value_1, my_decimal value_2,
                            my_decimal *rem, int *status) {
  if (value_2.bits[2] == 0U && value_2.bits[1] == 0U && value_2.bits[0] == 0U) {
    *status = NaN;
    return value_1;
  }
  *status = SUCCESS;
  short m1 = my_highest_digit(value_1), m2 = my_highest_digit(value_2);
  *rem = value_1;
  if (m2 < m1) {
    value_2 = my_dec_shift(value_2, -(m1 - m2), status);
  }
  my_decimal result = {0};
  for (int di = (m1 - m2); di >= 0; --di) {
    if (my_dec_bit_cmp(*rem, value_2) >= 0) {
      *rem = my_dec_bit_sub(*rem, value_2, status);
      result = my_dec_or(result, my_dec_shift(DEC_ONE, -di, status));
    }
    value_2 = my_dec_shift(value_2, 1, status);
  }
  setpower(&result, getpower(&value_1) - getpower(&value_2));
  return result;
}
