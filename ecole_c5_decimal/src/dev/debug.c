#include "debug.h"

#include <stdio.h>

#include "../dec_u64/u64_helper.h"
#include "../helper/helper.h"

static void print_bin128_dec(const char *bin) {
  int dec[30] = {0};
  int len = 1;

  for (int i = 0; bin[i]; i++) {
    int carry = bin[i] - '0';

    for (int j = 0; j < len; j++) {
      int v = dec[j] * 2 + carry;
      dec[j] = v % 10;
      carry = v / 10;
    }

    while (carry) {
      dec[len++] = carry % 10;
      carry /= 10;
    }
  }

  for (int i = len - 1; i >= 0; i--) {
    putchar('0' + dec[i]);
  }
  // putchar('\n');
}

static void print_bin192_dec(const char *bin) {
  int dec[60] = {0};
  int len = 1;

  for (int i = 0; bin[i]; i++) {
    int carry = bin[i] - '0';

    for (int j = 0; j < len; j++) {
      int v = dec[j] * 2 + carry;
      dec[j] = v % 10;
      carry = v / 10;
    }

    while (carry) {
      dec[len++] = carry % 10;
      carry /= 10;
    }
  }

  for (int i = len - 1; i >= 0; i--) {
    putchar('0' + dec[i]);
  }
  putchar('\n');
}

void my_dec_print_decimal(my_decimal number) {
  printf("%c", getsign(&number) ? '-' : '+');

  char result[MANTISSA_W] = {0};

  for (int idx = 0, b = HI; idx <= HI; ++idx, --b)
    sprintf(result + (idx * LIMB_W), "%0*b", LIMB_W, number.bits[b]);

  print_bin128_dec(result);

  printf(" / 10^%d\n", getpower(&number));
}

void my_big_dec_print_decimal(my_big_decimal number) {
  printf("%c", big_dec_getsign(&number) ? '-' : '+');

  char result[MANTISSA_BIG_W] = {0};

  for (int idx = 0, b = HI; idx <= HI; ++idx, --b)
    sprintf(result + (idx * LIMB_BIG_W), "%0*llb", LIMB_BIG_W, number.bits[b]);

  print_bin192_dec(result);

  printf(" / 10^%d\n", big_dec_getpower(&number));
}

char *my_dec_strerror(int errnum) {
  static char unknown_error_str[ERR_STR_LEN];
  char *res_ptr = (void *)0;

  if (errnum >= 0 && errnum < ERR_LIST_SIZE)
    res_ptr = (char *)errors_list[errnum];
  else {
    sprintf(unknown_error_str, UNKNOWN_ERR_FMT, errnum);
    res_ptr = unknown_error_str;
  }

  return res_ptr;
}

void my_dec_debug_print(my_decimal number) {
  int n_pow = getpower(&number);
  char n_sign = getsign(&number);
  if (n_sign == POSITIVE_SIGN)
    n_sign = '+';
  else if (n_sign == NEGATIVE_SIGN)
    n_sign = '-';
  else
    n_sign = '?';

  printf(
      "#----------------Debug my_dec print------------------------------#\n");
  printf("Power = %u\nSign = %c\n", n_pow, n_sign);
  for (int i = METADATA; i >= LO; --i)
    printf("bits[%d]: %0*b\n", i, LIMB_W, number.bits[i]);
  printf(
      "#----------------Debug my_dec print------------------------------#\n");
}

void my_big_dec_debug_print(my_big_decimal number) {
  int n_pow = big_dec_getpower(&number);
  char n_sign = big_dec_getsign(&number);
  if (n_sign == POSITIVE_SIGN)
    n_sign = '+';
  else if (n_sign == NEGATIVE_SIGN)
    n_sign = '-';
  else
    n_sign = '?';

  printf(
      "#----------------Debug BIG my_dec "
      "print------------------------------#\n");
  printf("Power = %u\nSign = %c\n", n_pow, n_sign);
  for (int i = METADATA; i >= LO; --i)
    printf("bits[%d]: %0*llb\n", i, LIMB_BIG_W, number.bits[i]);
  printf(
      "#----------------Debug BIG my_dec "
      "print------------------------------#\n");
}

void my_dec_print_binary(my_decimal number) {
  int n_pow = getpower(&number);
  char n_sign = getsign(&number);
  if (n_sign == POSITIVE_SIGN)
    n_sign = '+';
  else if (n_sign == NEGATIVE_SIGN)
    n_sign = '-';
  else
    n_sign = '?';

  printf("\nPower = %u, Sign = %c\n", n_pow, n_sign);
  for (int i = HI; i >= 0; --i) printf("%0*b", LIMB_W, number.bits[i]);
}

void my_big_dec_print_binary(my_big_decimal number) {
  int n_pow = big_dec_getpower(&number);
  char n_sign = big_dec_getsign(&number);
  if (n_sign == POSITIVE_SIGN)
    n_sign = '+';
  else if (n_sign == NEGATIVE_SIGN)
    n_sign = '-';
  else
    n_sign = '?';

  printf("\nPower = %u, Sign = %c\n", n_pow, n_sign);
  for (int i = HI; i >= 0; --i) printf("%0*llb", LIMB_BIG_W, number.bits[i]);
  printf("\n");
}

void escape(char *s, char *t) {
  int c;
  for (; (c = *t) != '\0'; ++t) {
    switch (c) {
      case '\t':
        *(s++) = '\\', *(s++) = 't';
        break;
      case '\n':
        *(s++) = '\\', *(s++) = 'n';
        break;
      case '\r':
        *(s++) = '\\', *(s++) = 'r';
        break;
      case '\v':
        *(s++) = '\\', *(s++) = 'v';
        break;
      case '\b':
        *(s++) = '\\', *(s++) = 'b';
        break;
      case '\f':
        *(s++) = '\\', *(s++) = 'f';
        break;
      default:
        *(s++) = c;
        break;
    }
  }
  *(s++) = '\\', *(s++) = '0';
  *s = '\0';
}
