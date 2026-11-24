#include "../my_decimal.h"

unsigned getbits(unsigned x, int start_pos, int n) {
  return (x >> start_pos) & ~(~0U << n);
}

unsigned long long getbits_u64(unsigned long long x, int start_pos, int n) {
  if (n <= 0 || start_pos < 0 || start_pos >= (int)LIMB_BIG_W) return 0;
  return (x >> start_pos) & ~(~0ULL << n);
}

short max_digit(unsigned number) {
  if (number == 0) return -1;

  unsigned max = LIMB_W - 1;
  for (; number < (1U << max) && max != 0; --max);
  return max;
}

short big_dec_max_digit(unsigned long long number) {
  if (number == 0) return -1;

  unsigned long long max = LIMB_BIG_W - 1;
  for (; number < (1LLU << max) && max != 0; --max);

  return (short)max;
}

unsigned long long full_adder_u64(unsigned long long b1, unsigned long long b2,
                                  unsigned long long *cin) {
  unsigned long long xor1 = b1 ^ b2;
  unsigned long long cout1 = b1 & b2, cout2 = xor1 & *cin;
  unsigned long long sum = xor1 ^ *cin;
  *cin = cout1 | cout2;
  return sum;
}

unsigned setbits(unsigned x, int start_pos, int n, unsigned y) {
  unsigned left_mask = ~(~0U << start_pos);
  unsigned right_mask = ~0U << (start_pos + n);
  unsigned keyhole_mask = left_mask | right_mask;

  return (getbits(y, 0, n) << start_pos) | (x & keyhole_mask);
}
