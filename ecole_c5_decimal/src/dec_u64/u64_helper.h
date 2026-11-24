#ifndef U64_HELPER_H_
#define U64_HELPER_H_
#include "../my_decimal.h"

//* helper functions and macros for decimal */

#define MINUS 1U << 31
#define PLUS 0U >> 1

#define BIG_DEC_ONE   \
  (my_big_decimal) { \
    .bits = { 1LLU }  \
  }
#define BIG_DEC_FIVE \
  (my_big_decimal) { {5LLU, 0LLU, 0LLU}, 0LLU }
#define BIG_DEC_TEN \
  (my_big_decimal) { {10LLU, 0LLU, 0LLU}, 0LLU }
#define BIG_DEC_FULL \
  (my_big_decimal) { {~0LLU, ~0LLU, ~0LLU}, 0LLU }

#define BIG_DEC_IS_EMPTY(BX)                                  \
  ((BX.meta == 0U && BX.bits[HI] == 0 && BX.bits[MID] == 0 && \
    BX.bits[LO] == 0)                                         \
       ? 1                                                    \
       : 0)

#define BIG_DEC_IS_ZERO(X) \
  ((X.bits[LO] == 0LLU && X.bits[HI] == 0LLU && X.bits[MID] == 0LLU) ? 1 : 0)

signed char big_dec_getsign(const my_big_decimal *n);
signed char big_dec_setsign(my_big_decimal *n, int sign);
short my_big_dec_highest_digit(my_big_decimal n);
short big_dec_getpower(const my_big_decimal *n);
short big_dec_setpower(my_big_decimal *n, int power);
signed char my_big_dec_bit_cmp(my_big_decimal mant1, my_big_decimal mant2);
my_big_decimal my_big_dec_bank(my_big_decimal num, short scale_cut,
                                 int *status);
my_big_decimal my_big_dec_trim_zeros(my_big_decimal num, int *status);

my_big_decimal convert_to_big_dec(my_decimal value);
my_decimal convert_to_dec(my_big_decimal big_value);

#endif
