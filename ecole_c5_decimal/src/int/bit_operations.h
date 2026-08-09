#ifndef BIT_OPERATIONS_H_
#define BIT_OPERATIONS_H_

/* UNSIGNED INT bit operations. */

/**
 * @brief Извлекает n-битное поле, начиная с указанной позиции
 *
 * @param x Исходное значение для извлечения битов
 * @param start_pos Начальная позиция
 * @param n Количество извлекаемых битов (отсчет от младшего бита к старшему)
 * @return unsigned Извлеченные n битов, сдвинутые к правому краю
 *
 * @note Если n превышает доступное количество битов, возвращает только
 * доступные биты
 * @example getbits(0b11001011, 2, 3) возвращает (0b...010.. >> 2) == 0b010
 * (биты 2,3,4)
 */
unsigned getbits(unsigned x, int start_pos, int n);

/**
 * @brief Возвращает индекс самого старшего включенного бита в беззнаковом числе
 *
 * @param unsigned number
 * @return short индекс (0, (UINT_W - 1))
 *
 */
short max_digit(unsigned number);

/**
 * @brief Реализует полный сумматор с помощью логических вентилей.
 *
 * Эта функция вычисляет сумму двух неотрицательных целых битов,
 * `b1` и `b2`, вместе с входным переносом, на который ссылается `cin`.
 * Она возвращает результирующую сумму и обновляет выходной перенос.
 *
 * Полный сумматор работает следующим образом:
 * - Вычисляет бит суммы, который является результатом сложения
 *   соответствующих битов `b1`, `b2` и `cin`.
 * - Определяет бит переноса, который возникает, если происходит
 *   переполнение при сложении битов.
 *
 * @param a1   Первое слагаемое (бит).
 * @param a2   Второе слагаемое (бит)
 * @param cin  Указатель на входной перенос (1 бит).
 * @return     Результирующая сумма.
 */
unsigned long long full_adder_u64(unsigned long long b1, unsigned long long b2,
                                  unsigned long long *cin);

/**
 * @brief Устанавливает n битов в x, начиная с start_pos, в значения крайних
 * правых n битов y
 *
 * @param x Целевое значение для модификации
 * @param start_pos Начальная позиция бита в x (0 = младший бит)
 * @param n Количество устанавливаемых битов (1-32)
 * @param y Источник битов для установки (берутся младшие n битов)
 * @return unsigned Результат с установленными битами
 *
 * @note Остальные биты x остаются неизменными
 * @example setbits(0b11111111, 2, 3, 0b101) → 0b11101011 (биты 2-4 заменены на
 * 101)
 */
unsigned setbits(unsigned x, int start_pos, int n, unsigned y);

/**
 * @brief Инвертирует n битов, начиная с указанной позиции
 *
 * @param x Исходное значение
 * @param start_pos Начальная позиция бита (0 = младший бит)
 * @param n Количество инвертируемых битов (1-32)
 * @return unsigned Результат с инвертированными битами
 *
 * @note 1→0, 0→1 в указанном диапазоне
 * @note Остальные биты остаются неизменными
 * @example invert(0b00001111, 4, 4) → 0b11110000 (биты 4-7 инвертированы)
 */
unsigned invert(unsigned x, int start_pos, int n);

/**
 * @brief Циклически сдвигает биты в беззнаковом int на n позиций (при
 * отрицательном n сдвигает биты влево, при положительном вправо)
 *
 * @param x Исходное значение
 * @param n Количество позиций для циклического сдвига
 * @return unsigned Результат циклического сдвига
 *
 * @note Биты, выходящие справа, появляются слева
 * @example rotate(0b11001010, 3) → 0b01011001 (3 правых бита перемещены в
 * начало)
 */
unsigned rotate(unsigned x, int n);

/**
 * @brief Возвращает количество включенных битов (1) в числе беззнаковом целом
 * числе x
 *
 * @param x Исходное значение
 * @return int количество битов равных 1
 *
 * @example bitcount(0b11001010) → 4
 */
int bitcount(unsigned x);

unsigned long long getbits_u64(unsigned long long x, int start_pos, int n);
short big_dec_max_digit(unsigned long long number);
unsigned long long setbits_u64(unsigned long long x, int start_pos, int n,
                               unsigned long long y);
unsigned full_adder(unsigned b1, unsigned b2, unsigned *cin);
#endif
