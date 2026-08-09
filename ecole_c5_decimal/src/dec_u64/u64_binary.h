#ifndef U64_BINARY_H_
#define U64_BINARY_H_

#include "../my_decimal.h"
#define OVERFLOW 4

my_big_decimal my_big_dec_shift(my_big_decimal num, int n_shift,
                                  int *status);
my_big_decimal my_big_dec_invert(my_big_decimal src);
my_big_decimal my_big_dec_xor(my_big_decimal n1, my_big_decimal n2);
my_big_decimal my_big_dec_or(my_big_decimal n1, my_big_decimal n2);
unsigned long long my_big_dec_getbit(my_big_decimal num, short di);

#endif
