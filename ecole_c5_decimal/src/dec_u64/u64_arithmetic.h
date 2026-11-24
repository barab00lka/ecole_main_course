#ifndef U64_ARITHMETIC_H_
#define U64_ARITHMETIC_H_

#include "../my_decimal.h"

#define IS_EVEN(X) !(X.bits[LO] & 1U)

#define IS_ADD_FUNCTION 1
#define IS_SUB_FUNCTION 2
#define CHOOSE_ADDITION -2
#define CHOOSE_SUBSTRACTION -3

int my_big_dec_add_sub(my_big_decimal value_1, my_big_decimal value_2,
                        my_big_decimal *result, int flag);
int my_big_dec_mul(my_big_decimal value_1, my_big_decimal value_2,
                    my_big_decimal *result);
int my_big_dec_div(my_big_decimal value_1, my_big_decimal value_2,
                    my_big_decimal *result);

my_big_decimal my_big_dec_bit_add(my_big_decimal value_1,
                                    my_big_decimal value_2, int *status);
my_big_decimal my_big_dec_bit_sub(my_big_decimal value_1,
                                    my_big_decimal value_2, int *status);
my_big_decimal my_big_dec_bit_mul(my_big_decimal value_1,
                                    my_big_decimal value_2, int *status);
my_big_decimal my_big_dec_bit_div(my_big_decimal value_1,
                                    my_big_decimal value_2,
                                    my_big_decimal *rem, int *status);
my_big_decimal my_big_dec_power10(my_big_decimal num, short scale,
                                    int *status);

int my_big_dec_normalize(my_big_decimal *value_1, my_big_decimal *value_2);
signed char big_dec_minus_handle_signs(my_big_decimal *x, my_big_decimal *y,
                                       short *compare);
signed char big_dec_plus_handle_signs(my_big_decimal *x, my_big_decimal *y,
                                      short *compare);

#endif
