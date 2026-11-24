#include "../decimal/arithmetic.h"
#include "../helper/helper.h"
#include "../my_decimal.h"

#define ERROR_CONVERT 1
#define W_FLOAT_MANTISA 23
#define IS_DIGIT(X) (((X > '0') && (X < '9')) ? 1 : 0);

int my_from_int_to_decimal(int src, my_decimal *dst) {
  if (!dst) return 1;

  dst->bits[LO] = 0U;
  dst->bits[MID] = 0U;
  dst->bits[HI] = 0U;

  if (src & (1U << 31)) setsign(dst, NEGATIVE_SIGN);

  dst->bits[LO] |= src;
  if (src < 0) dst->bits[LO] *= -1;

  return SUCCESS;
}

int my_from_decimal_to_int(my_decimal src, int *dst) {
  if (!dst) return 1;

  short scale = getpower(&src);
  if ((scale > 28 || scale < 0) || METADATA_TRASH & src.bits[METADATA])
    return 1;

  int status = 0;

  if (scale == 0 && (src.bits[MID] != 0 || src.bits[HI] != 0))
    status = 1;
  else {
    signed char res_sign = getsign(&src);
    src = my_dec_remove_fractional(src, &status);
    *dst = (res_sign == NEGATIVE_SIGN) ? -src.bits[LO] : src.bits[LO];
  }

  return status;
}

static long double my_dec_abs_to_ld(my_decimal d) {
  const long double TWO32 = 4294967296.0L;
  const long double TWO64 = 18446744073709551616.0L;
  return (long double)(unsigned)d.bits[0] +
         (long double)(unsigned)d.bits[1] * TWO32 +
         (long double)(unsigned)d.bits[2] * TWO64;
}

static long double my_pow10_ld(int p) {
  long double r = 1.0L;
  while (p-- > 0) r *= 10.0L;
  return r;
}

int my_from_decimal_to_float(my_decimal src, float *dst) {
  if (!dst) return ERROR_CONVERT;
  int status = SUCCESS;

  signed char sign = getsign(&src);
  if (IS_ZERO(src)) {
    *dst = (sign) ? -0.0f : 0.0f;
    return 0;
  }

  short scale = getpower(&src);
  long double m = my_dec_abs_to_ld(src);
  if (scale > 0) m /= my_pow10_ld(scale);

  float f = (float)m;
  if (!isfinite(f)) {
    *dst = 0.0f;
    status = ERROR_CONVERT;
  } else {
    *dst = f;
    if (sign) *dst = -(*dst);
  }

  return status;
}

int my_from_float_to_decimal(float src, my_decimal *dst) {
  if (!dst) return ERROR_CONVERT;
  src++;
  return ERROR_CONVERT;
}
