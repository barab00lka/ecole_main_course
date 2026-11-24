#include "helper.h"

#include "../decimal/arithmetic.h"
#include "../decimal/binary.h"
#include "../int/bit_operations.h"

signed char my_dec_bit_cmp(my_decimal mant1, my_decimal mant2) {
  signed char result = 0;
  for (int i = LIMB_MAX - 2; i >= LO; --i)
    result += (mant2.bits[i] == mant1.bits[i]);
  if (result == LIMB_MAX - 1)
    return 0;
  else
    result = 0;

  short max_bit = 0, m2 = 0, m1 = 0;
  max_bit = m1 = m2 = 0;
  m1 = my_highest_digit(mant1), m2 = my_highest_digit(mant2);
  max_bit = (m1 > m2) ? m1 : m2;

  for (short di = max_bit; di >= 0 && !result; --di) {
    unsigned b1 = my_dec_getbit(mant1, di), b2 = my_dec_getbit(mant2, di);
    if (b1 > b2)
      result = 1;
    else if (b1 < b2)
      result = -1;
  }
  return result;
}

my_decimal my_dec_trim_zeros(my_decimal num, int *status) {
  if (DEC_IS_EMPTY(num)) {
    return num;
  }
  short scale = getpower(&num);
  signed char sign = getsign(&num);
  my_decimal rem = {0};
  my_decimal del = {0};

  for (; scale > 0 && DEC_IS_EMPTY(rem); scale--) {
    del = my_dec_bit_div(num, DEC_TEN, &rem, status);
    if (DEC_IS_EMPTY(rem)) num = del;
  }

  setsign(&num, sign), setpower(&num, ++scale);
  return num;
}

my_decimal my_dec_remove_fractional(my_decimal num, int *status) {
  short scale = getpower(&num);
  if (scale > 28 || scale < 0 || METADATA_TRASH & num.bits[METADATA]) {
    *status = ERROR;
    return num;
  }
  signed char sign = getsign(&num);
  my_decimal rem = {0};
  for (int i = scale; i > 0; --i)
    num = my_dec_bit_div(num, DEC_TEN, &rem, status);
  setsign(&num, sign);
  return num;
}

short setpower(my_decimal *n, int power) {
  if (!n || (power > SCALE_MAX || power < 0)) {
    return ERROR;
  }
  n->bits[METADATA] = setbits(n->bits[METADATA], 16, CHAR_BIT, power);
  return SUCCESS;
}

short getpower(const my_decimal *n) {
  if (!n) return ERROR;
  return getbits(n->bits[METADATA], 16, CHAR_BIT);
}

short my_highest_digit(my_decimal n) {
  short res = -1;
  for (short limb = HI; limb >= LO && res == -1; --limb) {
    res = max_digit(n.bits[limb]);
    if (res != -1) res += limb * LIMB_W;
  }
  return res;
}

signed char setsign(my_decimal *n, int sign) {
  if (!n || (sign != POSITIVE_SIGN && sign != NEGATIVE_SIGN)) {
    return ERROR;
  }

  if (sign == NEGATIVE_SIGN) n->bits[METADATA] |= MINUS;
  return SUCCESS;
}

signed char getsign(const my_decimal *n) {
  if (!n) return ERROR;

  return (n->bits[METADATA] & MINUS) ? NEGATIVE_SIGN : POSITIVE_SIGN;
}
