#ifndef MY_DECIMAL_H
#define MY_DECIMAL_H

#include <limits.h>

enum {
  ERROR = -1,
  SUCCESS,
  INF,
  N_INF,
  NaN,
  SHIFT_OVERFLOW,
  ERROR_ARG,
  ERROR_SCALE,
  ERROR_TRIM,
  ADD_OVERFLOW,
  SUB_OVERFLOW
};

#define LIMB_MAX 4

/* type sizes decimal*/
#define POSITIVE_SIGN 0
#define NEGATIVE_SIGN 1
#define SCALE_MAX 28
#define LIMB_W (short)(sizeof(unsigned) * CHAR_BIT)
#define MANTISSA_W (LIMB_W * (LIMB_MAX - 1))

typedef struct {
  unsigned bits[LIMB_MAX];
} my_decimal;

/* type sizes big decimal*/
#define SCALE_BIG_MAX 58
#define LIMB_BIG_W (short)(sizeof(unsigned long long) * CHAR_BIT)
#define MANTISSA_BIG_W (LIMB_BIG_W * (LIMB_MAX - 1))

typedef struct {
  unsigned long long bits[LIMB_MAX - 1];
  unsigned meta;
} my_big_decimal;

enum { LO, MID, HI, METADATA };

int my_add(my_decimal value_1, my_decimal value_2, my_decimal *result);
int my_sub(my_decimal value_1, my_decimal value_2, my_decimal *result);
int my_mul(my_decimal value_1, my_decimal value_2, my_decimal *result);
int my_div(my_decimal value_1, my_decimal value_2, my_decimal *result);
int my_is_less(my_decimal, my_decimal);
int my_is_less_or_equal(my_decimal, my_decimal);
int my_is_greater(my_decimal, my_decimal);
int my_is_greater_or_equal(my_decimal, my_decimal);
int my_is_equal(my_decimal, my_decimal);
int my_is_not_equal(my_decimal, my_decimal);
int my_floor(my_decimal value, my_decimal *result);
int my_round(my_decimal value, my_decimal *result);
int my_truncate(my_decimal value, my_decimal *result);
int my_negate(my_decimal value, my_decimal *result);
int my_from_int_to_decimal(int src, my_decimal *dst);
int my_from_decimal_to_int(my_decimal src, int *dst);
int my_from_decimal_to_float(my_decimal src, float *dst);
int my_from_float_to_decimal(float src, my_decimal *dst);

#endif
