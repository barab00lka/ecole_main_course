#include "u64_binary.h"

#include "../int/bit_operations.h"

unsigned long long my_big_dec_getbit(my_big_decimal num, short di) {
  return ((num.bits[di / LIMB_BIG_W] >> (di % LIMB_BIG_W)) & 1LLU);
}

my_big_decimal my_big_dec_or(my_big_decimal n1, my_big_decimal n2) {
  my_big_decimal res = {0};
  for (int i = 0; i <= HI; i++) {
    res.bits[i] = n1.bits[i] | n2.bits[i];
  }
  return res;
}

static my_big_decimal _big_dec_left_shift(my_big_decimal num, int n_shift,
                                           int *status) {
  if (n_shift > (int)(MANTISSA_BIG_W - 1) || n_shift < 0) {
    *status = ERROR;
    return num;
  }

  const unsigned short limb_shift = (unsigned short)n_shift / LIMB_BIG_W;
  const unsigned short bit_shift = (unsigned short)n_shift % LIMB_BIG_W;

  unsigned long long carry = 0;
  for (unsigned short i = LO; bit_shift && i <= HI; ++i) {
    unsigned long long new = num.bits[i] << (bit_shift) | carry;
    carry = getbits_u64(num.bits[i], (LIMB_BIG_W - (bit_shift)), bit_shift);
    num.bits[i] = new;
  }

  carry = num.bits[HI];
  for (unsigned short i = 0; i < limb_shift; ++i) {
    unsigned short j = HI;
    for (; j > LO; --j) num.bits[j] = num.bits[j - 1];
    num.bits[j] = 0;
  }

  if (carry) *status = SHIFT_OVERFLOW;

  return num;
}

static my_big_decimal _big_dec_right_shift(my_big_decimal num, int n_shift,
                                            int *status) {
  if (n_shift > (int)(MANTISSA_BIG_W - 1) || n_shift < 0) {
    *status = ERROR;
    return num;
  }

  const unsigned short limb_shift = (unsigned short)n_shift / LIMB_BIG_W;
  const unsigned short bit_shift = (unsigned short)n_shift % LIMB_BIG_W;

  unsigned long long carry = 0;
  for (short i = HI; bit_shift && i >= LO; --i) {
    unsigned long long new = num.bits[i] >> (bit_shift) | carry;
    carry = getbits_u64(num.bits[i], 0, bit_shift) << (LIMB_BIG_W - bit_shift);
    num.bits[i] = new;
  }

  carry = num.bits[LO];
  for (unsigned short i = 0; i < limb_shift; ++i) {
    unsigned short j = LO;
    for (; j < HI; ++j) num.bits[j] = num.bits[j + 1];
    num.bits[j] = 0;
  }

  return num;
}

my_big_decimal my_big_dec_shift(my_big_decimal num, int n_shift,
                                  int *status) {
  if (n_shift == 0) {
    return num;
  }

  return (n_shift > 0) ? _big_dec_right_shift(num, n_shift, status)
                       : _big_dec_left_shift(num, -n_shift, status);
}
