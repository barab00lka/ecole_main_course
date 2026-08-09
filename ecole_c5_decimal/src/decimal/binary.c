#include "binary.h"

#include "../int/bit_operations.h"

unsigned my_dec_getbit(my_decimal num, short di) {
  return ((num.bits[di / LIMB_W] >> (di % LIMB_W)) & 1U);
}

my_decimal my_dec_or(my_decimal n1, my_decimal n2) {
  my_decimal res = {0};
  for (int i = 0; i <= HI; i++) {
    res.bits[i] = n1.bits[i] | n2.bits[i];
  }
  return res;
}

static my_decimal _dec_left_shift(my_decimal num, int n_shift, int *status) {
  if (n_shift > (int)(MANTISSA_W - 1) || n_shift < 0) {
    *status = ERROR;
    return num;
  }

  const unsigned short limb_shift = (unsigned short)n_shift / LIMB_W;
  const unsigned short bit_shift = (unsigned short)n_shift % LIMB_W;

  unsigned carry = 0U;
  for (unsigned short i = LO; bit_shift && i <= HI; ++i) {
    unsigned new = num.bits[i] << (bit_shift) | carry;
    carry = getbits(num.bits[i], (LIMB_W - (bit_shift)), bit_shift);
    num.bits[i] = new;
  }

  carry = num.bits[HI];
  for (unsigned short i = 0; i < limb_shift; ++i) {
    unsigned short j = HI;
    for (; j > LO; --j) num.bits[j] = num.bits[j - 1];
    num.bits[j] = 0U;
  }

  if (carry) *status = SHIFT_OVERFLOW;

  return num;
}

static my_decimal _dec_right_shift(my_decimal num, int n_shift, int *status) {
  if (n_shift > (int)(MANTISSA_BIG_W - 1) || n_shift < 0) {
    *status = ERROR;
    return num;
  }

  const unsigned short limb_shift = (unsigned short)n_shift / LIMB_W;
  const unsigned short bit_shift = (unsigned short)n_shift % LIMB_W;

  unsigned carry = 0U;
  for (short i = HI; bit_shift && i >= LO; --i) {
    unsigned new = num.bits[i] >> (bit_shift) | carry;
    carry = getbits(num.bits[i], 0, bit_shift) << (LIMB_W - bit_shift);
    num.bits[i] = new;
  }

  carry = num.bits[LO];
  for (unsigned short i = 0; i < limb_shift; ++i) {
    unsigned short j = LO;
    for (; j < HI; ++j) num.bits[j] = num.bits[j + 1];
    num.bits[j] = 0U;
  }

  return num;
}

my_decimal my_dec_shift(my_decimal num, int n_shift, int *status) {
  if (n_shift == 0) {
    return num;
  }

  return (n_shift > 0) ? _dec_right_shift(num, n_shift, status)
                       : _dec_left_shift(num, -n_shift, status);
}
