#include "../dec_u64/u64_arithmetic.h"
#include "../dec_u64/u64_helper.h"
#include "../my_decimal.h"

#define TRUE 1
#define FALSE 0

#define EQUAL_TYPE 0
#define LESS_TYPE -1
#define GREATER_TYPE 1

static int my_big_dec_sign_cmp(my_big_decimal value_1,
                                my_big_decimal value_2, int *invert) {
  int status = 0;
  const int sign_1 = big_dec_getsign(&value_1),
            sign_2 = big_dec_getsign(&value_2);

  if (sign_1 == NEGATIVE_SIGN && sign_2 == POSITIVE_SIGN) status = -1;
  if (sign_1 == POSITIVE_SIGN && sign_2 == NEGATIVE_SIGN) status = 1;
  if (sign_1 == sign_2) status = 0;

  if (sign_1 == NEGATIVE_SIGN && sign_2 == NEGATIVE_SIGN) *invert = 1;

  return status;
}

static int compare_equality(my_big_decimal value_1, my_big_decimal value_2,
                            int compare_type, int invert_cmp_res_flag) {
  (void)my_big_dec_normalize(&value_1, &value_2);

  signed char cmp_res = my_big_dec_bit_cmp(value_1, value_2);
  int status = (cmp_res == compare_type) ? TRUE : FALSE;
  if (invert_cmp_res_flag) {
    status = !status;
  }

  return status;
}

static int my_big_dec_is_less(my_big_decimal value_1,
                               my_big_decimal value_2) {
  if (BIG_DEC_IS_ZERO(value_1) && BIG_DEC_IS_ZERO(value_2)) return FALSE;
  int invert = 0;
  int sign_cmp = my_big_dec_sign_cmp(value_1, value_2, &invert);

  if (sign_cmp != 0) {
    return (sign_cmp < 0);
  }

  int type = LESS_TYPE;
  if (invert) type = GREATER_TYPE;
  return compare_equality(value_1, value_2, type, 0);
}

static int my_big_dec_is_greater(my_big_decimal value_1,
                                  my_big_decimal value_2) {
  if (BIG_DEC_IS_ZERO(value_1) && BIG_DEC_IS_ZERO(value_2)) return FALSE;
  int invert = 0;
  int sign_cmp = my_big_dec_sign_cmp(value_1, value_2, &invert);

  if (sign_cmp != 0) {
    return !(sign_cmp < 0);
  }

  int type = GREATER_TYPE;
  if (invert) type = LESS_TYPE;
  return compare_equality(value_1, value_2, type, 0);
}

static int my_big_dec_is_equal(my_big_decimal value_1,
                                my_big_decimal value_2) {
  int sign_1 = big_dec_getsign(&value_1), sign_2 = big_dec_getsign(&value_2);
  int status;

  if (sign_1 == sign_2)
    status = compare_equality(value_1, value_2, EQUAL_TYPE, 0);
  else
    status = FALSE;

  return status;
}

static int my_big_dec_is_not_equal(my_big_decimal value_1,
                                    my_big_decimal value_2) {
  int sign_1 = big_dec_getsign(&value_1), sign_2 = big_dec_getsign(&value_2);
  int status;

  if (sign_1 == sign_2)
    status = compare_equality(value_1, value_2, EQUAL_TYPE, 1);
  else
    status = TRUE;

  return status;
}

int my_is_less(my_decimal value_1, my_decimal value_2) {
  my_big_decimal big_value_1 = convert_to_big_dec(value_1);
  my_big_decimal big_value_2 = convert_to_big_dec(value_2);
  return my_big_dec_is_less(big_value_1, big_value_2);
}

int my_is_greater(my_decimal value_1, my_decimal value_2) {
  my_big_decimal big_value_1 = convert_to_big_dec(value_1);
  my_big_decimal big_value_2 = convert_to_big_dec(value_2);
  return my_big_dec_is_greater(big_value_1, big_value_2);
}

int my_is_equal(my_decimal value_1, my_decimal value_2) {
  my_big_decimal big_value_1 = convert_to_big_dec(value_1);
  my_big_decimal big_value_2 = convert_to_big_dec(value_2);
  return my_big_dec_is_equal(big_value_1, big_value_2);
}

int my_is_not_equal(my_decimal value_1, my_decimal value_2) {
  my_big_decimal big_value_1 = convert_to_big_dec(value_1);
  my_big_decimal big_value_2 = convert_to_big_dec(value_2);
  return my_big_dec_is_not_equal(big_value_1, big_value_2);
}

int my_is_less_or_equal(my_decimal value_1, my_decimal value_2) {
  return my_is_less(value_1, value_2) || my_is_equal(value_1, value_2);
}

int my_is_greater_or_equal(my_decimal value_1, my_decimal value_2) {
  return my_is_greater(value_1, value_2) || my_is_equal(value_1, value_2);
}
