#include "../compare/compare.c"
#include "../decimal/arithmetic.h"
#include "../helper/helper.h"
#include "../my_decimal.h"

int my_floor(my_decimal value, my_decimal *result) {
  if (!result) return 1;
  int status = SUCCESS;
  short scale = getpower(&value);
  if (scale > 28 || scale < 0 || METADATA_TRASH & value.bits[METADATA])
    return 1;

  signed char sign = getsign(&value);
  if (scale == 0 || my_highest_digit(value) == -1)
    *result = value;

  else {
    my_decimal rem = {0};
    signed char flag = 0;
    for (int i = scale; i > 0; --i) {
      value = my_dec_bit_div(value, DEC_TEN, &rem, &status);
      if (!IS_ZERO(rem)) flag++;
    }
    if (sign == NEGATIVE_SIGN && flag) value.bits[LO] += 1;
    *result = value;
  }
  setpower(result, 0), setsign(result, sign);
  return status;
}

int my_round(my_decimal value, my_decimal *result) {
  if (!result) return 1;
  short scale = getpower(&value);
  if (scale > 28 || scale < 0 || METADATA_TRASH & value.bits[METADATA])
    return 1;

  int status = SUCCESS;
  signed char sign = getsign(&value);
  if (scale == 0 || my_highest_digit(value) == -1)
    *result = value;

  else {
    my_decimal rem = {0};
	int flag = 0;
    for (int i = scale - 1; i > 0; --i) {
      value = my_dec_bit_div(value, DEC_TEN, &rem, &status);
	  if (!IS_ZERO(rem)) ++flag;
    }
    *result = my_dec_bit_div(value, DEC_TEN, &rem, &status);
    if (rem.bits[LO] > 5U || (rem.bits[LO] == 5 && (flag || !IS_EVEN((*result))))) result->bits[LO] += 1; // Bank round by default. IS_EVEN check can be omitted for standard mathematical rounding
  }
  setpower(result, 0), setsign(result, sign);
  return status;
}

int my_truncate(my_decimal value, my_decimal *result) {
  if (!result) return 1;
  short scale = getpower(&value);
  if (scale > 28 || scale < 0 || METADATA_TRASH & value.bits[METADATA])
    return 1;

  int status = SUCCESS;
  value = my_dec_remove_fractional(value, &status);
  if (status == ERROR) return 1;
  *result = my_dec_trim_zeros(value, &status);
  setpower(result, 0);
  return status;
}

int my_negate(my_decimal value, my_decimal *result) {
  if (!result) return 1;
  short scale = getpower(&value);
  if (scale > 28 || scale < 0 || METADATA_TRASH & value.bits[METADATA])
    return 1;

  *result = (my_decimal)value;
  if (value.bits[METADATA] & 1U << 31)
    result->bits[METADATA] &= ~0U >> 1;
  else
    result->bits[METADATA] |= 1U << 31;
  return 0;
}
