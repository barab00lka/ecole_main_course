#ifndef DEBUG_H
#define DEBUG_H

#include "../my_decimal.h"

#define UNKNOWN_ERR_FMT "Unknown error: %d"
#define ERR_STR_LEN 64
#define ERR_LIST_SIZE 15

static const char errors_list[ERR_LIST_SIZE][ERR_STR_LEN] = {
    "Success",        "Infinity",    "Negative infinity", "NAN ( / 0 )",
    "SHIFT-OVERFLOW", "ERROR_ARG",   "ERROR_SCALE",       "ERROR_TRIM",
    "ADD-OVERFLOW",   "SUB-OVERFLOW"};

#define PRINT_STATUS(X)                            \
  do {                                             \
    printf("\nStatus: %s\n", my_dec_strerror(X)); \
  } while (0)

/**
 * @brief возвращает указатель на строку с ошибкой для последующего выведения
 * через printf("%s\n", my_dec_strerror(error));
 *
 * @param int errnum
 * @retval (char*) указатель на ошибку
 */
char *my_dec_strerror(int errnum);

void my_dec_debug_print(my_decimal number);

void my_dec_print_binary(my_decimal number);
void my_dec_print_decimal(my_decimal number);

void escape(char *s, char *t);

void my_big_dec_print_decimal(my_big_decimal number);
void my_big_dec_print_binary(my_big_decimal number);
void my_big_dec_debug_print(my_big_decimal number);
#endif
