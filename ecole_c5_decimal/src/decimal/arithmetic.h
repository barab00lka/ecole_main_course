#ifndef ARITHMETIC_H_
#define ARITHMETIC_H_

#include "../my_decimal.h"

#define IS_EVEN(X) !(X.bits[LO] & 1U)

/* Арифметические операции с типом my_decimal */
/**
 * @brief
 * @note
 *
 * @param
 * @param
 * @retval
 */
my_decimal my_dec_bit_sub(my_decimal value_1, my_decimal value_2,
                            int *status);
/**
 * @brief
 * @note
 *
 * @param
 * @param
 * @retval
 */
my_decimal my_dec_bit_div(my_decimal value_1, my_decimal value_2,
                            my_decimal *rem, int *status);

short my_dec_highest_digit(my_decimal n);
#endif
