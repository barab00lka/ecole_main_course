#ifndef HELPER_H_
#define HELPER_H_
#include <math.h>

#include "../my_decimal.h"

//* helper functions and macros for decimal */
#define MINUS 1U << 31
#define PLUS 0U >> 1
#define METADATA_TRASH 0x7F00FFFF
#define MANTISSA_FULL UINT_MAX, UINT_MAX, UINT_MAX
#define DEC_ONE    \
  (my_decimal) {  \
    .bits = { 1U } \
  }
#define DEC_FIVE       \
  (my_decimal) {      \
    { 5U, 0U, 0U, 0U } \
  }
#define DEC_TEN         \
  (my_decimal) {       \
    { 10U, 0U, 0U, 0U } \
  }
#define DEC_FULL          \
  (my_decimal) {         \
    { MANTISSA_FULL, 0U } \
  }

#define DEC_IS_EMPTY(X)                                                \
  ((X.bits[METADATA] == 0U && X.bits[HI] == 0U && X.bits[MID] == 0U && \
    X.bits[LO] == 0U)                                                  \
       ? 1                                                             \
       : 0)

#define IS_ZERO(X) \
  ((X.bits[LO] == 0U && X.bits[HI] == 0U && X.bits[MID] == 0U) ? 1 : 0)

/**
 *
 * @brief побитовое сравнение my_decimal мантисс
 *
 * @param my_decimal mant1
 * @param my_decimal mant2
 * @retval 1 если mantissa 1 больше
 * @retval -1 если mantissa 2 больше
 * @retval 0 если равны
 */
signed char my_dec_bit_cmp(my_decimal mant1, my_decimal mant2);

/**
 * @brief Returns the power (bits) from my_decimal.
 *
 * @param n Pointer to decimal number
 * @return short Power value (0-28) or error code
 * @retval 0-28 Successful, returns power
 * @retval -1 ERROR (if my_decimal n is NULL or power is incorrect)
 */
short getpower(const my_decimal *n);

/**
 * @brief Sets the power (scale) for decimal number
 *
 * @param n Pointer to decimal number
 * @param power Power value to set (0-28)
 * @return short Operation status
 * @retval 0 Success
 * @retval -1 Error (null pointer or invalid power)
 */
short setpower(my_decimal *n, int power);

/**
 * @brief Sets the sign bit to my_decimal number n. Returns ERROR if n = NULL
 * or sign is not 0 or 1
 *
 * @param n Pointer to decimal number
 * @param sign Sign to set (0 for positive, 1 for negative)
 * @return short Operation status
 * @retval 0 SUCCESS
 * @retval -1 ERROR
 */
signed char setsign(my_decimal *n, int sign);

/**
 * @brief Returns the sign bit from my_decimal number n. Returns ERROR if n =
 * NULL or sign is not 0 or 1.
 *
 * @param n Pointer to decimal number
 * @return short Sign value or error
 * @retval 0 POSITIVE_SIGN
 * @retval 1 NEGATIVE_SIGN
 * @retval -1 ERROR
 */
signed char getsign(const my_decimal *n);

/**
 * @brief Возвращает индекс самого старшего включенного бита в my_decimal - от
 * (MANTISSA_W - 1) до 0.
 * @note Вернет -1 (ERROR) , если mantissa пустая , то есть включенных битов не
 * найдено.
 *
 * @param my_decimal number
 * @retval int Индекс MSB (Самый Cтарший Бит)
 * @retval -1 ERROR
 */
short my_highest_digit(my_decimal n);
/**
 * @brief
 * @note
 *
 * @param
 * @param
 * @retval
 */
my_decimal my_dec_trim_zeros(my_decimal num, int *status);

/**
 * @brief
 * @note
 *
 * @param
 * @param
 * @retval
 */
my_decimal my_dec_remove_fractional(my_decimal num, int *status);

#endif
