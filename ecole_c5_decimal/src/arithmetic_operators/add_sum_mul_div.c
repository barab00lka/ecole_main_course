#include "../dec_u64/u64_arithmetic.h"
#include "../dec_u64/u64_helper.h"
#include "../helper/helper.h"
#include "../my_decimal.h"

int my_add(my_decimal value_1, my_decimal value_2, my_decimal *result) {
  int status = SUCCESS;
  if (!result) return status;
  my_big_decimal big_value_1 = convert_to_big_dec(value_1);
  my_big_decimal big_value_2 = convert_to_big_dec(value_2);
  my_big_decimal big_result = {0};

  status = my_big_dec_add_sub(big_value_1, big_value_2, &big_result,
                               IS_ADD_FUNCTION);
  if (status != N_INF && status != INF)
    *result = convert_to_dec(big_result);
  else
    *result = value_1;

  return status;
}

int my_sub(my_decimal value_1, my_decimal value_2, my_decimal *result) {
  int status = SUCCESS;
  if (!result) return status;

  my_big_decimal big_value_1 = convert_to_big_dec(value_1);
  my_big_decimal big_value_2 = convert_to_big_dec(value_2);
  my_big_decimal big_result = {0};

  status = my_big_dec_add_sub(big_value_1, big_value_2, &big_result,
                               IS_SUB_FUNCTION);

  if (status != N_INF && status != INF)
    *result = convert_to_dec(big_result);
  else
    *result = value_1;
  return status;
}

int my_mul(my_decimal value_1, my_decimal value_2, my_decimal *result) {
  int status = SUCCESS;
  if (!result) return status;

  my_big_decimal big_value_1 = convert_to_big_dec(value_1);
  my_big_decimal big_value_2 = convert_to_big_dec(value_2);
  my_big_decimal big_result = {0};

  status = my_big_dec_mul(big_value_1, big_value_2, &big_result);

  if (status != N_INF && status != INF)
    *result = convert_to_dec(big_result);

  else
    *result = value_1;

  return status;
}

int my_div(my_decimal value_1, my_decimal value_2, my_decimal *result) {
  int status = SUCCESS;

  if (IS_ZERO(value_2)) return NaN;
  if (!result) return status;

  my_big_decimal big_value_1 = convert_to_big_dec(value_1);
  my_big_decimal big_value_2 = convert_to_big_dec(value_2);
  my_big_decimal big_result = {0};

  status = my_big_dec_div(big_value_1, big_value_2, &big_result);

  if (status != N_INF && status != INF && status != NaN)
    *result = convert_to_dec(big_result);
  else
    *result = value_1;

  return status;
}
