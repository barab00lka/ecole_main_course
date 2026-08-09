#include <stdio.h>
#include <stdlib.h>

#include "./../../my_decimal.h"
#include "./../test.h"

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * * * * * * * * * * * * * * Тесты на некорректные данные (ручные)
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * * * * * * * * * * * * * */

START_TEST(test_truncate_fail1) {
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x140000}};

  int code = my_truncate(decimal, NULL);

  ck_assert_int_eq(code, TEST_OTHER_ERROR);
}

START_TEST(test_truncate_fail2) {
  my_decimal decimal = {{0, 0, 0, 1000000000}};
  my_decimal result;

  int code = my_truncate(decimal, &result);

  ck_assert_int_eq(code, TEST_OTHER_ERROR);
}
END_TEST

START_TEST(test_truncate_fail3) {
  my_decimal decimal = {{-1, 0, 0, 0x1D0000}};
  my_decimal result;

  int code = my_truncate(decimal, &result);

  ck_assert_int_eq(code, TEST_OTHER_ERROR);
}
END_TEST

START_TEST(test_truncate_fail4) {
  my_decimal decimal = {{0, 0, 0, 0x1D0000}};
  my_decimal result;

  int code = my_truncate(decimal, &result);

  ck_assert_int_eq(code, TEST_OTHER_ERROR);
}
END_TEST

START_TEST(test_truncate_fail5) {
  my_decimal decimal = {{-1, 0, 0, 0x1C0001}};
  my_decimal result;

  int code = my_truncate(decimal, &result);

  ck_assert_int_eq(code, TEST_OTHER_ERROR);
}
END_TEST

START_TEST(test_truncate_fail6) {
  my_decimal decimal = {{-1, 0, 0, 0x1C8000}};
  my_decimal result;

  int code = my_truncate(decimal, &result);

  ck_assert_int_eq(code, TEST_OTHER_ERROR);
}
END_TEST

START_TEST(test_truncate_fail7) {
  my_decimal decimal = {{-1, 0, 0, 0x11C0000}};
  my_decimal result;

  int code = my_truncate(decimal, &result);

  ck_assert_int_eq(code, TEST_OTHER_ERROR);
}
END_TEST

START_TEST(test_truncate_fail8) {
  my_decimal decimal = {{-1, 0, 0, 0x401C0000}};
  my_decimal result;

  int code = my_truncate(decimal, &result);

  ck_assert_int_eq(code, TEST_OTHER_ERROR);
}
END_TEST

START_TEST(test_truncate_fail9) {
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF}};
  my_decimal result;

  int code = my_truncate(decimal, &result);

  ck_assert_int_eq(code, TEST_OTHER_ERROR);
}
END_TEST

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * * * * * * * * * * * * * * * Tests for correct data (automatic)
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * * * * * * * * * * * * * * */

START_TEST(test_truncate_ok1) {
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};

  my_decimal decimal_check = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok2) {
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};

  my_decimal decimal_check = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok3) {
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};

  my_decimal decimal_check = {{0x99999999, 0x99999999, 0x19999999, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok4) {
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80010000}};

  my_decimal decimal_check = {
      {0x99999999, 0x99999999, 0x19999999, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok5) {
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x20000}};

  my_decimal decimal_check = {{0x28F5C28F, 0xF5C28F5C, 0x28F5C28, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok6) {
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80020000}};

  my_decimal decimal_check = {{0x28F5C28F, 0xF5C28F5C, 0x28F5C28, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok7) {
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x30000}};

  my_decimal decimal_check = {{0x9DB22D0E, 0x4BC6A7EF, 0x418937, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok8) {
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80030000}};

  my_decimal decimal_check = {{0x9DB22D0E, 0x4BC6A7EF, 0x418937, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok9) {
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x40000}};

  my_decimal decimal_check = {{0x295E9E1B, 0xBAC710CB, 0x68DB8, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok10) {
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80040000}};

  my_decimal decimal_check = {{0x295E9E1B, 0xBAC710CB, 0x68DB8, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok11) {
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x50000}};

  my_decimal decimal_check = {{0x84230FCF, 0xAC471B47, 0xA7C5, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok12) {
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80050000}};

  my_decimal decimal_check = {{0x84230FCF, 0xAC471B47, 0xA7C5, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok13) {
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x60000}};

  my_decimal decimal_check = {{0x8D36B4C7, 0xF7A0B5ED, 0x10C6, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok14) {
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80060000}};

  my_decimal decimal_check = {{0x8D36B4C7, 0xF7A0B5ED, 0x10C6, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok15) {
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x70000}};

  my_decimal decimal_check = {{0xF485787A, 0x7F29ABCA, 0x1AD, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok16) {
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80070000}};

  my_decimal decimal_check = {{0xF485787A, 0x7F29ABCA, 0x1AD, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok17) {
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000}};

  my_decimal decimal_check = {{0x1873BF3F, 0xF31DC461, 0x2A, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok18) {
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80080000}};

  my_decimal decimal_check = {{0x1873BF3F, 0xF31DC461, 0x2A, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok19) {
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x90000}};

  my_decimal decimal_check = {{0xB5A52CB9, 0x4B82FA09, 0x4, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok20) {
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80090000}};

  my_decimal decimal_check = {{0xB5A52CB9, 0x4B82FA09, 0x4, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok21) {
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xA0000}};

  my_decimal decimal_check = {{0x5EF6EADF, 0x6DF37F67, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok22) {
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x800A0000}};

  my_decimal decimal_check = {{0x5EF6EADF, 0x6DF37F67, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok23) {
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xB0000}};

  my_decimal decimal_check = {{0xBCB24AAF, 0xAFEBFF0, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok24) {
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x800B0000}};

  my_decimal decimal_check = {{0xBCB24AAF, 0xAFEBFF0, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok25) {
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xC0000}};

  my_decimal decimal_check = {{0x12DEA111, 0x1197998, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok26) {
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x800C0000}};

  my_decimal decimal_check = {{0x12DEA111, 0x1197998, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok27) {
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xD0000}};

  my_decimal decimal_check = {{0x68497681, 0x1C25C2, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok28) {
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x800D0000}};

  my_decimal decimal_check = {{0x68497681, 0x1C25C2, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok29) {
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xE0000}};

  my_decimal decimal_check = {{0x70D42573, 0x2D093, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok30) {
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x800E0000}};

  my_decimal decimal_check = {{0x70D42573, 0x2D093, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok31) {
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xF0000}};

  my_decimal decimal_check = {{0xBE7B9D58, 0x480E, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok32) {
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x800F0000}};

  my_decimal decimal_check = {{0xBE7B9D58, 0x480E, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok33) {
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x100000}};

  my_decimal decimal_check = {{0xACA5F622, 0x734, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok34) {
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80100000}};

  my_decimal decimal_check = {{0xACA5F622, 0x734, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok35) {
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x110000}};

  my_decimal decimal_check = {{0x77AA3236, 0xB8, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok36) {
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80110000}};

  my_decimal decimal_check = {{0x77AA3236, 0xB8, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok37) {
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x120000}};

  my_decimal decimal_check = {{0x725DD1D2, 0x12, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok38) {
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80120000}};

  my_decimal decimal_check = {{0x725DD1D2, 0x12, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok39) {
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x130000}};

  my_decimal decimal_check = {{0xD83C94FB, 0x1, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok40) {
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80130000}};

  my_decimal decimal_check = {{0xD83C94FB, 0x1, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok41) {
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x140000}};

  my_decimal decimal_check = {{0x2F394219, 0x0, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok42) {
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80140000}};

  my_decimal decimal_check = {{0x2F394219, 0x0, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok43) {
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x150000}};

  my_decimal decimal_check = {{0x4B8ED02, 0x0, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok44) {
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80150000}};

  my_decimal decimal_check = {{0x4B8ED02, 0x0, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok45) {
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x160000}};

  my_decimal decimal_check = {{0x78E480, 0x0, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok46) {
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80160000}};

  my_decimal decimal_check = {{0x78E480, 0x0, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok47) {
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x170000}};

  my_decimal decimal_check = {{0xC16D9, 0x0, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok48) {
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80170000}};

  my_decimal decimal_check = {{0xC16D9, 0x0, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok49) {
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x180000}};

  my_decimal decimal_check = {{0x1357C, 0x0, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok50) {
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80180000}};

  my_decimal decimal_check = {{0x1357C, 0x0, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok51) {
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x190000}};

  my_decimal decimal_check = {{0x1EF2, 0x0, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok52) {
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80190000}};

  my_decimal decimal_check = {{0x1EF2, 0x0, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok53) {
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x1A0000}};

  my_decimal decimal_check = {{0x318, 0x0, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok54) {
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x801A0000}};

  my_decimal decimal_check = {{0x318, 0x0, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok55) {
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x1B0000}};

  my_decimal decimal_check = {{0x4F, 0x0, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok56) {
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x801B0000}};

  my_decimal decimal_check = {{0x4F, 0x0, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok57) {
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x1C0000}};

  my_decimal decimal_check = {{0x7, 0x0, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok58) {
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x801C0000}};

  my_decimal decimal_check = {{0x7, 0x0, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok59) {
  my_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};

  my_decimal decimal_check = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok60) {
  my_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};

  my_decimal decimal_check = {
      {0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok61) {
  my_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};

  my_decimal decimal_check = {{0x99999999, 0x99999999, 0x19999999, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok62) {
  my_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80010000}};

  my_decimal decimal_check = {
      {0x99999999, 0x99999999, 0x19999999, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok63) {
  my_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x20000}};

  my_decimal decimal_check = {{0x28F5C28F, 0xF5C28F5C, 0x28F5C28, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok64) {
  my_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80020000}};

  my_decimal decimal_check = {{0x28F5C28F, 0xF5C28F5C, 0x28F5C28, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok65) {
  my_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x30000}};

  my_decimal decimal_check = {{0x9DB22D0E, 0x4BC6A7EF, 0x418937, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok66) {
  my_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80030000}};

  my_decimal decimal_check = {{0x9DB22D0E, 0x4BC6A7EF, 0x418937, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok67) {
  my_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x40000}};

  my_decimal decimal_check = {{0x295E9E1B, 0xBAC710CB, 0x68DB8, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok68) {
  my_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80040000}};

  my_decimal decimal_check = {{0x295E9E1B, 0xBAC710CB, 0x68DB8, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok69) {
  my_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x50000}};

  my_decimal decimal_check = {{0x84230FCF, 0xAC471B47, 0xA7C5, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok70) {
  my_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80050000}};

  my_decimal decimal_check = {{0x84230FCF, 0xAC471B47, 0xA7C5, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok71) {
  my_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x60000}};

  my_decimal decimal_check = {{0x8D36B4C7, 0xF7A0B5ED, 0x10C6, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok72) {
  my_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80060000}};

  my_decimal decimal_check = {{0x8D36B4C7, 0xF7A0B5ED, 0x10C6, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok73) {
  my_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x70000}};

  my_decimal decimal_check = {{0xF485787A, 0x7F29ABCA, 0x1AD, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok74) {
  my_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80070000}};

  my_decimal decimal_check = {{0xF485787A, 0x7F29ABCA, 0x1AD, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok75) {
  my_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000}};

  my_decimal decimal_check = {{0x1873BF3F, 0xF31DC461, 0x2A, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok76) {
  my_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80080000}};

  my_decimal decimal_check = {{0x1873BF3F, 0xF31DC461, 0x2A, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok77) {
  my_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x90000}};

  my_decimal decimal_check = {{0xB5A52CB9, 0x4B82FA09, 0x4, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok78) {
  my_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80090000}};

  my_decimal decimal_check = {{0xB5A52CB9, 0x4B82FA09, 0x4, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok79) {
  my_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0xA0000}};

  my_decimal decimal_check = {{0x5EF6EADF, 0x6DF37F67, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok80) {
  my_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x800A0000}};

  my_decimal decimal_check = {{0x5EF6EADF, 0x6DF37F67, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok81) {
  my_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0xB0000}};

  my_decimal decimal_check = {{0xBCB24AAF, 0xAFEBFF0, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok82) {
  my_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x800B0000}};

  my_decimal decimal_check = {{0xBCB24AAF, 0xAFEBFF0, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok83) {
  my_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0xC0000}};

  my_decimal decimal_check = {{0x12DEA111, 0x1197998, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok84) {
  my_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x800C0000}};

  my_decimal decimal_check = {{0x12DEA111, 0x1197998, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok85) {
  my_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0xD0000}};

  my_decimal decimal_check = {{0x68497681, 0x1C25C2, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok86) {
  my_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x800D0000}};

  my_decimal decimal_check = {{0x68497681, 0x1C25C2, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok87) {
  my_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0xE0000}};

  my_decimal decimal_check = {{0x70D42573, 0x2D093, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok88) {
  my_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x800E0000}};

  my_decimal decimal_check = {{0x70D42573, 0x2D093, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok89) {
  my_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0xF0000}};

  my_decimal decimal_check = {{0xBE7B9D58, 0x480E, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok90) {
  my_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x800F0000}};

  my_decimal decimal_check = {{0xBE7B9D58, 0x480E, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok91) {
  my_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x100000}};

  my_decimal decimal_check = {{0xACA5F622, 0x734, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok92) {
  my_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80100000}};

  my_decimal decimal_check = {{0xACA5F622, 0x734, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok93) {
  my_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x110000}};

  my_decimal decimal_check = {{0x77AA3236, 0xB8, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok94) {
  my_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80110000}};

  my_decimal decimal_check = {{0x77AA3236, 0xB8, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok95) {
  my_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x120000}};

  my_decimal decimal_check = {{0x725DD1D2, 0x12, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok96) {
  my_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80120000}};

  my_decimal decimal_check = {{0x725DD1D2, 0x12, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok97) {
  my_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x130000}};

  my_decimal decimal_check = {{0xD83C94FB, 0x1, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok98) {
  my_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80130000}};

  my_decimal decimal_check = {{0xD83C94FB, 0x1, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok99) {
  my_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x140000}};

  my_decimal decimal_check = {{0x2F394219, 0x0, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok100) {
  my_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80140000}};

  my_decimal decimal_check = {{0x2F394219, 0x0, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok101) {
  my_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x150000}};

  my_decimal decimal_check = {{0x4B8ED02, 0x0, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok102) {
  my_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80150000}};

  my_decimal decimal_check = {{0x4B8ED02, 0x0, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok103) {
  my_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x160000}};

  my_decimal decimal_check = {{0x78E480, 0x0, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok104) {
  my_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80160000}};

  my_decimal decimal_check = {{0x78E480, 0x0, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok105) {
  my_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x170000}};

  my_decimal decimal_check = {{0xC16D9, 0x0, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok106) {
  my_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80170000}};

  my_decimal decimal_check = {{0xC16D9, 0x0, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok107) {
  my_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x180000}};

  my_decimal decimal_check = {{0x1357C, 0x0, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok108) {
  my_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80180000}};

  my_decimal decimal_check = {{0x1357C, 0x0, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok109) {
  my_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x190000}};

  my_decimal decimal_check = {{0x1EF2, 0x0, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok110) {
  my_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80190000}};

  my_decimal decimal_check = {{0x1EF2, 0x0, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok111) {
  my_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x1A0000}};

  my_decimal decimal_check = {{0x318, 0x0, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok112) {
  my_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x801A0000}};

  my_decimal decimal_check = {{0x318, 0x0, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok113) {
  my_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x1B0000}};

  my_decimal decimal_check = {{0x4F, 0x0, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok114) {
  my_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x801B0000}};

  my_decimal decimal_check = {{0x4F, 0x0, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok115) {
  my_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x1C0000}};

  my_decimal decimal_check = {{0x7, 0x0, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok116) {
  my_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x801C0000}};

  my_decimal decimal_check = {{0x7, 0x0, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok117) {
  my_decimal decimal = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x0}};

  my_decimal decimal_check = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok118) {
  my_decimal decimal = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x80000000}};

  my_decimal decimal_check = {
      {0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok119) {
  my_decimal decimal = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x10000}};

  my_decimal decimal_check = {{0x11111111, 0x11111111, 0x11111111, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok120) {
  my_decimal decimal = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x80010000}};

  my_decimal decimal_check = {
      {0x11111111, 0x11111111, 0x11111111, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok121) {
  my_decimal decimal = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0xD0000}};

  my_decimal decimal_check = {{0xF030F9AB, 0x12C3D6, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok122) {
  my_decimal decimal = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x800D0000}};

  my_decimal decimal_check = {{0xF030F9AB, 0x12C3D6, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok123) {
  my_decimal decimal = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x1C0000}};

  my_decimal decimal_check = {{0x5, 0x0, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok124) {
  my_decimal decimal = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x801C0000}};

  my_decimal decimal_check = {{0x5, 0x0, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok125) {
  my_decimal decimal = {{0x0, 0xAAAAAAAA, 0xAAAAAAAA, 0x0}};

  my_decimal decimal_check = {{0x0, 0xAAAAAAAA, 0xAAAAAAAA, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok126) {
  my_decimal decimal = {{0x0, 0xAAAAAAAA, 0xAAAAAAAA, 0x80000000}};

  my_decimal decimal_check = {{0x0, 0xAAAAAAAA, 0xAAAAAAAA, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok127) {
  my_decimal decimal = {{0x0, 0xAAAAAAAA, 0xAAAAAAAA, 0x10000}};

  my_decimal decimal_check = {{0x0, 0x11111111, 0x11111111, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok128) {
  my_decimal decimal = {{0x0, 0xAAAAAAAA, 0xAAAAAAAA, 0x80010000}};

  my_decimal decimal_check = {{0x0, 0x11111111, 0x11111111, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok129) {
  my_decimal decimal = {{0x0, 0xAAAAAAAA, 0xAAAAAAAA, 0xD0000}};

  my_decimal decimal_check = {{0xF030F9AB, 0x12C3D6, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok130) {
  my_decimal decimal = {{0x0, 0xAAAAAAAA, 0xAAAAAAAA, 0x800D0000}};

  my_decimal decimal_check = {{0xF030F9AB, 0x12C3D6, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok131) {
  my_decimal decimal = {{0x0, 0xAAAAAAAA, 0xAAAAAAAA, 0x1C0000}};

  my_decimal decimal_check = {{0x5, 0x0, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok132) {
  my_decimal decimal = {{0x0, 0xAAAAAAAA, 0xAAAAAAAA, 0x801C0000}};

  my_decimal decimal_check = {{0x5, 0x0, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok133) {
  my_decimal decimal = {{0xAAAAAAAA, 0x0, 0xAAAAAAAA, 0x0}};

  my_decimal decimal_check = {{0xAAAAAAAA, 0x0, 0xAAAAAAAA, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok134) {
  my_decimal decimal = {{0xAAAAAAAA, 0x0, 0xAAAAAAAA, 0x80000000}};

  my_decimal decimal_check = {{0xAAAAAAAA, 0x0, 0xAAAAAAAA, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok135) {
  my_decimal decimal = {{0xAAAAAAAA, 0x0, 0xAAAAAAAA, 0x10000}};

  my_decimal decimal_check = {{0x11111111, 0x0, 0x11111111, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok136) {
  my_decimal decimal = {{0xAAAAAAAA, 0x0, 0xAAAAAAAA, 0x80010000}};

  my_decimal decimal_check = {{0x11111111, 0x0, 0x11111111, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok137) {
  my_decimal decimal = {{0xAAAAAAAA, 0x0, 0xAAAAAAAA, 0xD0000}};

  my_decimal decimal_check = {{0xF01E35D4, 0x12C3D6, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok138) {
  my_decimal decimal = {{0xAAAAAAAA, 0x0, 0xAAAAAAAA, 0x800D0000}};

  my_decimal decimal_check = {{0xF01E35D4, 0x12C3D6, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok139) {
  my_decimal decimal = {{0xAAAAAAAA, 0x0, 0xAAAAAAAA, 0x1C0000}};

  my_decimal decimal_check = {{0x5, 0x0, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok140) {
  my_decimal decimal = {{0xAAAAAAAA, 0x0, 0xAAAAAAAA, 0x801C0000}};

  my_decimal decimal_check = {{0x5, 0x0, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok141) {
  my_decimal decimal = {{0x0, 0x0, 0xAAAAAAAA, 0x0}};

  my_decimal decimal_check = {{0x0, 0x0, 0xAAAAAAAA, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok142) {
  my_decimal decimal = {{0x0, 0x0, 0xAAAAAAAA, 0x80000000}};

  my_decimal decimal_check = {{0x0, 0x0, 0xAAAAAAAA, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok143) {
  my_decimal decimal = {{0x0, 0x0, 0xAAAAAAAA, 0x10000}};

  my_decimal decimal_check = {{0x0, 0x0, 0x11111111, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok144) {
  my_decimal decimal = {{0x0, 0x0, 0xAAAAAAAA, 0x80010000}};

  my_decimal decimal_check = {{0x0, 0x0, 0x11111111, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok145) {
  my_decimal decimal = {{0x0, 0x0, 0xAAAAAAAA, 0xD0000}};

  my_decimal decimal_check = {{0xF01E35D4, 0x12C3D6, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok146) {
  my_decimal decimal = {{0x0, 0x0, 0xAAAAAAAA, 0x800D0000}};

  my_decimal decimal_check = {{0xF01E35D4, 0x12C3D6, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok147) {
  my_decimal decimal = {{0x0, 0x0, 0xAAAAAAAA, 0x1C0000}};

  my_decimal decimal_check = {{0x5, 0x0, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok148) {
  my_decimal decimal = {{0x0, 0x0, 0xAAAAAAAA, 0x801C0000}};

  my_decimal decimal_check = {{0x5, 0x0, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok149) {
  my_decimal decimal = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x0}};

  my_decimal decimal_check = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok150) {
  my_decimal decimal = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x80000000}};

  my_decimal decimal_check = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok151) {
  my_decimal decimal = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x10000}};

  my_decimal decimal_check = {{0x11111111, 0x11111111, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok152) {
  my_decimal decimal = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x80010000}};

  my_decimal decimal_check = {{0x11111111, 0x11111111, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok153) {
  my_decimal decimal = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0xB0000}};

  my_decimal decimal_check = {{0x7547FF5, 0x0, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok154) {
  my_decimal decimal = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x800B0000}};

  my_decimal decimal_check = {{0x7547FF5, 0x0, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok155) {
  my_decimal decimal = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x130000}};

  my_decimal decimal_check = {{0x1, 0x0, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok156) {
  my_decimal decimal = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x80130000}};

  my_decimal decimal_check = {{0x1, 0x0, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok157) {
  my_decimal decimal = {{0x0, 0xAAAAAAAA, 0x0, 0x0}};

  my_decimal decimal_check = {{0x0, 0xAAAAAAAA, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok158) {
  my_decimal decimal = {{0x0, 0xAAAAAAAA, 0x0, 0x80000000}};

  my_decimal decimal_check = {{0x0, 0xAAAAAAAA, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok159) {
  my_decimal decimal = {{0x0, 0xAAAAAAAA, 0x0, 0x10000}};

  my_decimal decimal_check = {{0x0, 0x11111111, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok160) {
  my_decimal decimal = {{0x0, 0xAAAAAAAA, 0x0, 0x80010000}};

  my_decimal decimal_check = {{0x0, 0x11111111, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok161) {
  my_decimal decimal = {{0x0, 0xAAAAAAAA, 0x0, 0xB0000}};

  my_decimal decimal_check = {{0x7547FF5, 0x0, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok162) {
  my_decimal decimal = {{0x0, 0xAAAAAAAA, 0x0, 0x800B0000}};

  my_decimal decimal_check = {{0x7547FF5, 0x0, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok163) {
  my_decimal decimal = {{0x0, 0xAAAAAAAA, 0x0, 0x130000}};

  my_decimal decimal_check = {{0x1, 0x0, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok164) {
  my_decimal decimal = {{0x0, 0xAAAAAAAA, 0x0, 0x80130000}};

  my_decimal decimal_check = {{0x1, 0x0, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok165) {
  my_decimal decimal = {{0xAAAAAAAA, 0x0, 0x0, 0x0}};

  my_decimal decimal_check = {{0xAAAAAAAA, 0x0, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok166) {
  my_decimal decimal = {{0xAAAAAAAA, 0x0, 0x0, 0x80000000}};

  my_decimal decimal_check = {{0xAAAAAAAA, 0x0, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok167) {
  my_decimal decimal = {{0xAAAAAAAA, 0x0, 0x0, 0x10000}};

  my_decimal decimal_check = {{0x11111111, 0x0, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok168) {
  my_decimal decimal = {{0xAAAAAAAA, 0x0, 0x0, 0x80010000}};

  my_decimal decimal_check = {{0x11111111, 0x0, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok169) {
  my_decimal decimal = {{0xAAAAAAAA, 0x0, 0x0, 0x40000}};

  my_decimal decimal_check = {{0x45E7B, 0x0, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok170) {
  my_decimal decimal = {{0xAAAAAAAA, 0x0, 0x0, 0x80040000}};

  my_decimal decimal_check = {{0x45E7B, 0x0, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok171) {
  my_decimal decimal = {{0xAAAAAAAA, 0x0, 0x0, 0x90000}};

  my_decimal decimal_check = {{0x2, 0x0, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok172) {
  my_decimal decimal = {{0xAAAAAAAA, 0x0, 0x0, 0x80090000}};

  my_decimal decimal_check = {{0x2, 0x0, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok173) {
  my_decimal decimal = {{0x55555555, 0x55555555, 0x55555555, 0x0}};

  my_decimal decimal_check = {{0x55555555, 0x55555555, 0x55555555, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok174) {
  my_decimal decimal = {{0x55555555, 0x55555555, 0x55555555, 0x80000000}};

  my_decimal decimal_check = {
      {0x55555555, 0x55555555, 0x55555555, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok175) {
  my_decimal decimal = {{0x55555555, 0x55555555, 0x55555555, 0x10000}};

  my_decimal decimal_check = {{0x88888888, 0x88888888, 0x8888888, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok176) {
  my_decimal decimal = {{0x55555555, 0x55555555, 0x55555555, 0x80010000}};

  my_decimal decimal_check = {{0x88888888, 0x88888888, 0x8888888, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok177) {
  my_decimal decimal = {{0x55555555, 0x55555555, 0x55555555, 0xD0000}};

  my_decimal decimal_check = {{0x78187CD5, 0x961EB, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok178) {
  my_decimal decimal = {{0x55555555, 0x55555555, 0x55555555, 0x800D0000}};

  my_decimal decimal_check = {{0x78187CD5, 0x961EB, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok179) {
  my_decimal decimal = {{0x55555555, 0x55555555, 0x55555555, 0x1C0000}};

  my_decimal decimal_check = {{0x2, 0x0, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok180) {
  my_decimal decimal = {{0x55555555, 0x55555555, 0x55555555, 0x801C0000}};

  my_decimal decimal_check = {{0x2, 0x0, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok181) {
  my_decimal decimal = {{0x0, 0x55555555, 0x55555555, 0x0}};

  my_decimal decimal_check = {{0x0, 0x55555555, 0x55555555, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok182) {
  my_decimal decimal = {{0x0, 0x55555555, 0x55555555, 0x80000000}};

  my_decimal decimal_check = {{0x0, 0x55555555, 0x55555555, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok183) {
  my_decimal decimal = {{0x0, 0x55555555, 0x55555555, 0x10000}};

  my_decimal decimal_check = {{0x80000000, 0x88888888, 0x8888888, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok184) {
  my_decimal decimal = {{0x0, 0x55555555, 0x55555555, 0x80010000}};

  my_decimal decimal_check = {{0x80000000, 0x88888888, 0x8888888, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok185) {
  my_decimal decimal = {{0x0, 0x55555555, 0x55555555, 0xD0000}};

  my_decimal decimal_check = {{0x78187CD5, 0x961EB, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok186) {
  my_decimal decimal = {{0x0, 0x55555555, 0x55555555, 0x800D0000}};

  my_decimal decimal_check = {{0x78187CD5, 0x961EB, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok187) {
  my_decimal decimal = {{0x0, 0x55555555, 0x55555555, 0x1C0000}};

  my_decimal decimal_check = {{0x2, 0x0, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok188) {
  my_decimal decimal = {{0x0, 0x55555555, 0x55555555, 0x801C0000}};

  my_decimal decimal_check = {{0x2, 0x0, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok189) {
  my_decimal decimal = {{0x55555555, 0x0, 0x55555555, 0x0}};

  my_decimal decimal_check = {{0x55555555, 0x0, 0x55555555, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok190) {
  my_decimal decimal = {{0x55555555, 0x0, 0x55555555, 0x80000000}};

  my_decimal decimal_check = {{0x55555555, 0x0, 0x55555555, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok191) {
  my_decimal decimal = {{0x55555555, 0x0, 0x55555555, 0x10000}};

  my_decimal decimal_check = {{0x8888888, 0x80000000, 0x8888888, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok192) {
  my_decimal decimal = {{0x55555555, 0x0, 0x55555555, 0x80010000}};

  my_decimal decimal_check = {{0x8888888, 0x80000000, 0x8888888, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok193) {
  my_decimal decimal = {{0x55555555, 0x0, 0x55555555, 0xD0000}};

  my_decimal decimal_check = {{0x780F1AEA, 0x961EB, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok194) {
  my_decimal decimal = {{0x55555555, 0x0, 0x55555555, 0x800D0000}};

  my_decimal decimal_check = {{0x780F1AEA, 0x961EB, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok195) {
  my_decimal decimal = {{0x55555555, 0x0, 0x55555555, 0x1C0000}};

  my_decimal decimal_check = {{0x2, 0x0, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok196) {
  my_decimal decimal = {{0x55555555, 0x0, 0x55555555, 0x801C0000}};

  my_decimal decimal_check = {{0x2, 0x0, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok197) {
  my_decimal decimal = {{0x0, 0x0, 0x55555555, 0x0}};

  my_decimal decimal_check = {{0x0, 0x0, 0x55555555, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok198) {
  my_decimal decimal = {{0x0, 0x0, 0x55555555, 0x80000000}};

  my_decimal decimal_check = {{0x0, 0x0, 0x55555555, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok199) {
  my_decimal decimal = {{0x0, 0x0, 0x55555555, 0x10000}};

  my_decimal decimal_check = {{0x0, 0x80000000, 0x8888888, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok200) {
  my_decimal decimal = {{0x0, 0x0, 0x55555555, 0x80010000}};

  my_decimal decimal_check = {{0x0, 0x80000000, 0x8888888, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok201) {
  my_decimal decimal = {{0x0, 0x0, 0x55555555, 0xD0000}};

  my_decimal decimal_check = {{0x780F1AEA, 0x961EB, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok202) {
  my_decimal decimal = {{0x0, 0x0, 0x55555555, 0x800D0000}};

  my_decimal decimal_check = {{0x780F1AEA, 0x961EB, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok203) {
  my_decimal decimal = {{0x0, 0x0, 0x55555555, 0x1C0000}};

  my_decimal decimal_check = {{0x2, 0x0, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok204) {
  my_decimal decimal = {{0x0, 0x0, 0x55555555, 0x801C0000}};

  my_decimal decimal_check = {{0x2, 0x0, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok205) {
  my_decimal decimal = {{0x55555555, 0x55555555, 0x0, 0x0}};

  my_decimal decimal_check = {{0x55555555, 0x55555555, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok206) {
  my_decimal decimal = {{0x55555555, 0x55555555, 0x0, 0x80000000}};

  my_decimal decimal_check = {{0x55555555, 0x55555555, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok207) {
  my_decimal decimal = {{0x55555555, 0x55555555, 0x0, 0x10000}};

  my_decimal decimal_check = {{0x88888888, 0x8888888, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok208) {
  my_decimal decimal = {{0x55555555, 0x55555555, 0x0, 0x80010000}};

  my_decimal decimal_check = {{0x88888888, 0x8888888, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok209) {
  my_decimal decimal = {{0x55555555, 0x55555555, 0x0, 0xC0000}};

  my_decimal decimal_check = {{0x5DD332, 0x0, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok210) {
  my_decimal decimal = {{0x55555555, 0x55555555, 0x0, 0x800C0000}};

  my_decimal decimal_check = {{0x5DD332, 0x0, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok211) {
  my_decimal decimal = {{0x55555555, 0x55555555, 0x0, 0x120000}};

  my_decimal decimal_check = {{0x6, 0x0, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok212) {
  my_decimal decimal = {{0x55555555, 0x55555555, 0x0, 0x80120000}};

  my_decimal decimal_check = {{0x6, 0x0, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok213) {
  my_decimal decimal = {{0x0, 0x55555555, 0x0, 0x0}};

  my_decimal decimal_check = {{0x0, 0x55555555, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok214) {
  my_decimal decimal = {{0x0, 0x55555555, 0x0, 0x80000000}};

  my_decimal decimal_check = {{0x0, 0x55555555, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok215) {
  my_decimal decimal = {{0x0, 0x55555555, 0x0, 0x10000}};

  my_decimal decimal_check = {{0x80000000, 0x8888888, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok216) {
  my_decimal decimal = {{0x0, 0x55555555, 0x0, 0x80010000}};

  my_decimal decimal_check = {{0x80000000, 0x8888888, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok217) {
  my_decimal decimal = {{0x0, 0x55555555, 0x0, 0xC0000}};

  my_decimal decimal_check = {{0x5DD332, 0x0, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok218) {
  my_decimal decimal = {{0x0, 0x55555555, 0x0, 0x800C0000}};

  my_decimal decimal_check = {{0x5DD332, 0x0, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok219) {
  my_decimal decimal = {{0x0, 0x55555555, 0x0, 0x120000}};

  my_decimal decimal_check = {{0x6, 0x0, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok220) {
  my_decimal decimal = {{0x0, 0x55555555, 0x0, 0x80120000}};

  my_decimal decimal_check = {{0x6, 0x0, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok221) {
  my_decimal decimal = {{0x55555555, 0x0, 0x0, 0x0}};

  my_decimal decimal_check = {{0x55555555, 0x0, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok222) {
  my_decimal decimal = {{0x55555555, 0x0, 0x0, 0x80000000}};

  my_decimal decimal_check = {{0x55555555, 0x0, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok223) {
  my_decimal decimal = {{0x55555555, 0x0, 0x0, 0x10000}};

  my_decimal decimal_check = {{0x8888888, 0x0, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok224) {
  my_decimal decimal = {{0x55555555, 0x0, 0x0, 0x80010000}};

  my_decimal decimal_check = {{0x8888888, 0x0, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok225) {
  my_decimal decimal = {{0x55555555, 0x0, 0x0, 0x40000}};

  my_decimal decimal_check = {{0x22F3D, 0x0, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok226) {
  my_decimal decimal = {{0x55555555, 0x0, 0x0, 0x80040000}};

  my_decimal decimal_check = {{0x22F3D, 0x0, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok227) {
  my_decimal decimal = {{0x55555555, 0x0, 0x0, 0x90000}};

  my_decimal decimal_check = {{0x1, 0x0, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok228) {
  my_decimal decimal = {{0x55555555, 0x0, 0x0, 0x80090000}};

  my_decimal decimal_check = {{0x1, 0x0, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok229) {
  my_decimal decimal = {{0x1, 0x1, 0x1, 0x0}};

  my_decimal decimal_check = {{0x1, 0x1, 0x1, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok230) {
  my_decimal decimal = {{0x1, 0x1, 0x1, 0x80000000}};

  my_decimal decimal_check = {{0x1, 0x1, 0x1, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok231) {
  my_decimal decimal = {{0x1, 0x1, 0x1, 0x10000}};

  my_decimal decimal_check = {{0xB3333333, 0x19999999, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok232) {
  my_decimal decimal = {{0x1, 0x1, 0x1, 0x80010000}};

  my_decimal decimal_check = {{0xB3333333, 0x19999999, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok233) {
  my_decimal decimal = {{0x1, 0x1, 0x1, 0x80000}};

  my_decimal decimal_check = {{0xF31DC48C, 0x2A, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok234) {
  my_decimal decimal = {{0x1, 0x1, 0x1, 0x80080000}};

  my_decimal decimal_check = {{0xF31DC48C, 0x2A, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok235) {
  my_decimal decimal = {{0x1, 0x1, 0x1, 0x130000}};

  my_decimal decimal_check = {{0x1, 0x0, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok236) {
  my_decimal decimal = {{0x1, 0x1, 0x1, 0x80130000}};

  my_decimal decimal_check = {{0x1, 0x0, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok237) {
  my_decimal decimal = {{0x0, 0x1, 0x1, 0x0}};

  my_decimal decimal_check = {{0x0, 0x1, 0x1, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok238) {
  my_decimal decimal = {{0x0, 0x1, 0x1, 0x80000000}};

  my_decimal decimal_check = {{0x0, 0x1, 0x1, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok239) {
  my_decimal decimal = {{0x0, 0x1, 0x1, 0x10000}};

  my_decimal decimal_check = {{0xB3333333, 0x19999999, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok240) {
  my_decimal decimal = {{0x0, 0x1, 0x1, 0x80010000}};

  my_decimal decimal_check = {{0xB3333333, 0x19999999, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok241) {
  my_decimal decimal = {{0x0, 0x1, 0x1, 0x90000}};

  my_decimal decimal_check = {{0x4B82FA0E, 0x4, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok242) {
  my_decimal decimal = {{0x0, 0x1, 0x1, 0x80090000}};

  my_decimal decimal_check = {{0x4B82FA0E, 0x4, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok243) {
  my_decimal decimal = {{0x0, 0x1, 0x1, 0x130000}};

  my_decimal decimal_check = {{0x1, 0x0, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok244) {
  my_decimal decimal = {{0x0, 0x1, 0x1, 0x80130000}};

  my_decimal decimal_check = {{0x1, 0x0, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok245) {
  my_decimal decimal = {{0x1, 0x0, 0x1, 0x0}};

  my_decimal decimal_check = {{0x1, 0x0, 0x1, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok246) {
  my_decimal decimal = {{0x1, 0x0, 0x1, 0x80000000}};

  my_decimal decimal_check = {{0x1, 0x0, 0x1, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok247) {
  my_decimal decimal = {{0x1, 0x0, 0x1, 0x10000}};

  my_decimal decimal_check = {{0x99999999, 0x19999999, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok248) {
  my_decimal decimal = {{0x1, 0x0, 0x1, 0x80010000}};

  my_decimal decimal_check = {{0x99999999, 0x19999999, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok249) {
  my_decimal decimal = {{0x1, 0x0, 0x1, 0xA0000}};

  my_decimal decimal_check = {{0x6DF37F67, 0x0, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok250) {
  my_decimal decimal = {{0x1, 0x0, 0x1, 0x800A0000}};

  my_decimal decimal_check = {{0x6DF37F67, 0x0, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok251) {
  my_decimal decimal = {{0x1, 0x0, 0x1, 0x130000}};

  my_decimal decimal_check = {{0x1, 0x0, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok252) {
  my_decimal decimal = {{0x1, 0x0, 0x1, 0x80130000}};

  my_decimal decimal_check = {{0x1, 0x0, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok253) {
  my_decimal decimal = {{0x0, 0x0, 0x1, 0x0}};

  my_decimal decimal_check = {{0x0, 0x0, 0x1, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok254) {
  my_decimal decimal = {{0x0, 0x0, 0x1, 0x80000000}};

  my_decimal decimal_check = {{0x0, 0x0, 0x1, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok255) {
  my_decimal decimal = {{0x0, 0x0, 0x1, 0x10000}};

  my_decimal decimal_check = {{0x99999999, 0x19999999, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok256) {
  my_decimal decimal = {{0x0, 0x0, 0x1, 0x80010000}};

  my_decimal decimal_check = {{0x99999999, 0x19999999, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok257) {
  my_decimal decimal = {{0x0, 0x0, 0x1, 0xB0000}};

  my_decimal decimal_check = {{0xAFEBFF0, 0x0, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok258) {
  my_decimal decimal = {{0x0, 0x0, 0x1, 0x800B0000}};

  my_decimal decimal_check = {{0xAFEBFF0, 0x0, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok259) {
  my_decimal decimal = {{0x0, 0x0, 0x1, 0x130000}};

  my_decimal decimal_check = {{0x1, 0x0, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok260) {
  my_decimal decimal = {{0x0, 0x0, 0x1, 0x80130000}};

  my_decimal decimal_check = {{0x1, 0x0, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok261) {
  my_decimal decimal = {{0x1, 0x1, 0x0, 0x0}};

  my_decimal decimal_check = {{0x1, 0x1, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok262) {
  my_decimal decimal = {{0x1, 0x1, 0x0, 0x80000000}};

  my_decimal decimal_check = {{0x1, 0x1, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok263) {
  my_decimal decimal = {{0x1, 0x1, 0x0, 0x10000}};

  my_decimal decimal_check = {{0x19999999, 0x0, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok264) {
  my_decimal decimal = {{0x1, 0x1, 0x0, 0x80010000}};

  my_decimal decimal_check = {{0x19999999, 0x0, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok265) {
  my_decimal decimal = {{0x1, 0x1, 0x0, 0x20000}};

  my_decimal decimal_check = {{0x28F5C28, 0x0, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok266) {
  my_decimal decimal = {{0x1, 0x1, 0x0, 0x80020000}};

  my_decimal decimal_check = {{0x28F5C28, 0x0, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok267) {
  my_decimal decimal = {{0x1, 0x1, 0x0, 0x40000}};

  my_decimal decimal_check = {{0x68DB8, 0x0, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok268) {
  my_decimal decimal = {{0x1, 0x1, 0x0, 0x80040000}};

  my_decimal decimal_check = {{0x68DB8, 0x0, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok269) {
  my_decimal decimal = {{0x1, 0x1, 0x0, 0x90000}};

  my_decimal decimal_check = {{0x4, 0x0, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok270) {
  my_decimal decimal = {{0x1, 0x1, 0x0, 0x80090000}};

  my_decimal decimal_check = {{0x4, 0x0, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok271) {
  my_decimal decimal = {{0x1, 0x1, 0x0, 0x80000}};

  my_decimal decimal_check = {{0x2A, 0x0, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok272) {
  my_decimal decimal = {{0x1, 0x1, 0x0, 0x80080000}};

  my_decimal decimal_check = {{0x2A, 0x0, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok273) {
  my_decimal decimal = {{0x0, 0x1, 0x0, 0x0}};

  my_decimal decimal_check = {{0x0, 0x1, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok274) {
  my_decimal decimal = {{0x0, 0x1, 0x0, 0x80000000}};

  my_decimal decimal_check = {{0x0, 0x1, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok275) {
  my_decimal decimal = {{0x0, 0x1, 0x0, 0x10000}};

  my_decimal decimal_check = {{0x19999999, 0x0, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok276) {
  my_decimal decimal = {{0x0, 0x1, 0x0, 0x80010000}};

  my_decimal decimal_check = {{0x19999999, 0x0, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok277) {
  my_decimal decimal = {{0x0, 0x1, 0x0, 0x20000}};

  my_decimal decimal_check = {{0x28F5C28, 0x0, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok278) {
  my_decimal decimal = {{0x0, 0x1, 0x0, 0x80020000}};

  my_decimal decimal_check = {{0x28F5C28, 0x0, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok279) {
  my_decimal decimal = {{0x0, 0x1, 0x0, 0x30000}};

  my_decimal decimal_check = {{0x418937, 0x0, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok280) {
  my_decimal decimal = {{0x0, 0x1, 0x0, 0x80030000}};

  my_decimal decimal_check = {{0x418937, 0x0, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok281) {
  my_decimal decimal = {{0x0, 0x1, 0x0, 0x90000}};

  my_decimal decimal_check = {{0x4, 0x0, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok282) {
  my_decimal decimal = {{0x0, 0x1, 0x0, 0x80090000}};

  my_decimal decimal_check = {{0x4, 0x0, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok283) {
  my_decimal decimal = {{0x0, 0x1, 0x0, 0x80000}};

  my_decimal decimal_check = {{0x2A, 0x0, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok284) {
  my_decimal decimal = {{0x0, 0x1, 0x0, 0x80080000}};

  my_decimal decimal_check = {{0x2A, 0x0, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok285) {
  my_decimal decimal = {{0x1, 0x0, 0x0, 0x0}};

  my_decimal decimal_check = {{0x1, 0x0, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok286) {
  my_decimal decimal = {{0x1, 0x0, 0x0, 0x80000000}};

  my_decimal decimal_check = {{0x1, 0x0, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok287) {
  my_decimal decimal = {{0x1, 0x0, 0x0, 0x10000}};

  my_decimal decimal_check = {{0x0, 0x0, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok288) {
  my_decimal decimal = {{0x1, 0x0, 0x0, 0x80010000}};

  my_decimal decimal_check = {{0x0, 0x0, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok289) {
  my_decimal decimal = {{0x1, 0x0, 0x0, 0xD0000}};

  my_decimal decimal_check = {{0x0, 0x0, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok290) {
  my_decimal decimal = {{0x1, 0x0, 0x0, 0x800D0000}};

  my_decimal decimal_check = {{0x0, 0x0, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok291) {
  my_decimal decimal = {{0x1, 0x0, 0x0, 0xE0000}};

  my_decimal decimal_check = {{0x0, 0x0, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok292) {
  my_decimal decimal = {{0x1, 0x0, 0x0, 0x800E0000}};

  my_decimal decimal_check = {{0x0, 0x0, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok293) {
  my_decimal decimal = {{0x1, 0x0, 0x0, 0x1B0000}};

  my_decimal decimal_check = {{0x0, 0x0, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok294) {
  my_decimal decimal = {{0x1, 0x0, 0x0, 0x801B0000}};

  my_decimal decimal_check = {{0x0, 0x0, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok295) {
  my_decimal decimal = {{0x1, 0x0, 0x0, 0x1C0000}};

  my_decimal decimal_check = {{0x0, 0x0, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok296) {
  my_decimal decimal = {{0x1, 0x0, 0x0, 0x801C0000}};

  my_decimal decimal_check = {{0x0, 0x0, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok297) {
  my_decimal decimal = {{0x80000000, 0x80000000, 0x80000000, 0x0}};

  my_decimal decimal_check = {{0x80000000, 0x80000000, 0x80000000, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok298) {
  my_decimal decimal = {{0x80000000, 0x80000000, 0x80000000, 0x80000000}};

  my_decimal decimal_check = {
      {0x80000000, 0x80000000, 0x80000000, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok299) {
  my_decimal decimal = {{0x80000000, 0x80000000, 0x80000000, 0x10000}};

  my_decimal decimal_check = {{0xA6666666, 0xD9999999, 0xCCCCCCC, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok300) {
  my_decimal decimal = {{0x80000000, 0x80000000, 0x80000000, 0x80010000}};

  my_decimal decimal_check = {{0xA6666666, 0xD9999999, 0xCCCCCCC, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok301) {
  my_decimal decimal = {{0x80000000, 0x80000000, 0x80000000, 0xF0000}};

  my_decimal decimal_check = {{0x5F3DF2B3, 0x2407, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok302) {
  my_decimal decimal = {{0x80000000, 0x80000000, 0x80000000, 0x800F0000}};

  my_decimal decimal_check = {{0x5F3DF2B3, 0x2407, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok303) {
  my_decimal decimal = {{0x80000000, 0x80000000, 0x80000000, 0x1C0000}};

  my_decimal decimal_check = {{0x3, 0x0, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok304) {
  my_decimal decimal = {{0x80000000, 0x80000000, 0x80000000, 0x801C0000}};

  my_decimal decimal_check = {{0x3, 0x0, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok305) {
  my_decimal decimal = {{0x0, 0x80000000, 0x80000000, 0x0}};

  my_decimal decimal_check = {{0x0, 0x80000000, 0x80000000, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok306) {
  my_decimal decimal = {{0x0, 0x80000000, 0x80000000, 0x80000000}};

  my_decimal decimal_check = {{0x0, 0x80000000, 0x80000000, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok307) {
  my_decimal decimal = {{0x0, 0x80000000, 0x80000000, 0x10000}};

  my_decimal decimal_check = {{0x99999999, 0xD9999999, 0xCCCCCCC, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok308) {
  my_decimal decimal = {{0x0, 0x80000000, 0x80000000, 0x80010000}};

  my_decimal decimal_check = {{0x99999999, 0xD9999999, 0xCCCCCCC, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok309) {
  my_decimal decimal = {{0x0, 0x80000000, 0x80000000, 0xD0000}};

  my_decimal decimal_check = {{0x3432CE22, 0xE12E1, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok310) {
  my_decimal decimal = {{0x0, 0x80000000, 0x80000000, 0x800D0000}};

  my_decimal decimal_check = {{0x3432CE22, 0xE12E1, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok311) {
  my_decimal decimal = {{0x0, 0x80000000, 0x80000000, 0x1C0000}};

  my_decimal decimal_check = {{0x3, 0x0, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok312) {
  my_decimal decimal = {{0x0, 0x80000000, 0x80000000, 0x801C0000}};

  my_decimal decimal_check = {{0x3, 0x0, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok313) {
  my_decimal decimal = {{0x80000000, 0x0, 0x80000000, 0x0}};

  my_decimal decimal_check = {{0x80000000, 0x0, 0x80000000, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok314) {
  my_decimal decimal = {{0x80000000, 0x0, 0x80000000, 0x80000000}};

  my_decimal decimal_check = {{0x80000000, 0x0, 0x80000000, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok315) {
  my_decimal decimal = {{0x80000000, 0x0, 0x80000000, 0x10000}};

  my_decimal decimal_check = {{0xD9999999, 0xCCCCCCCC, 0xCCCCCCC, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok316) {
  my_decimal decimal = {{0x80000000, 0x0, 0x80000000, 0x80010000}};

  my_decimal decimal_check = {{0xD9999999, 0xCCCCCCCC, 0xCCCCCCC, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok317) {
  my_decimal decimal = {{0x80000000, 0x0, 0x80000000, 0xC0000}};

  my_decimal decimal_check = {{0x96F5088, 0x8CBCCC, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok318) {
  my_decimal decimal = {{0x80000000, 0x0, 0x80000000, 0x800C0000}};

  my_decimal decimal_check = {{0x96F5088, 0x8CBCCC, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok319) {
  my_decimal decimal = {{0x80000000, 0x0, 0x80000000, 0x1C0000}};

  my_decimal decimal_check = {{0x3, 0x0, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok320) {
  my_decimal decimal = {{0x80000000, 0x0, 0x80000000, 0x801C0000}};

  my_decimal decimal_check = {{0x3, 0x0, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok321) {
  my_decimal decimal = {{0x0, 0x0, 0x80000000, 0x0}};

  my_decimal decimal_check = {{0x0, 0x0, 0x80000000, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok322) {
  my_decimal decimal = {{0x0, 0x0, 0x80000000, 0x80000000}};

  my_decimal decimal_check = {{0x0, 0x0, 0x80000000, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok323) {
  my_decimal decimal = {{0x0, 0x0, 0x80000000, 0x10000}};

  my_decimal decimal_check = {{0xCCCCCCCC, 0xCCCCCCCC, 0xCCCCCCC, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok324) {
  my_decimal decimal = {{0x0, 0x0, 0x80000000, 0x80010000}};

  my_decimal decimal_check = {{0xCCCCCCCC, 0xCCCCCCCC, 0xCCCCCCC, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok325) {
  my_decimal decimal = {{0x0, 0x0, 0x80000000, 0xB0000}};

  my_decimal decimal_check = {{0x5E592557, 0x57F5FF8, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok326) {
  my_decimal decimal = {{0x0, 0x0, 0x80000000, 0x800B0000}};

  my_decimal decimal_check = {{0x5E592557, 0x57F5FF8, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok327) {
  my_decimal decimal = {{0x0, 0x0, 0x80000000, 0x1C0000}};

  my_decimal decimal_check = {{0x3, 0x0, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok328) {
  my_decimal decimal = {{0x0, 0x0, 0x80000000, 0x801C0000}};

  my_decimal decimal_check = {{0x3, 0x0, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok329) {
  my_decimal decimal = {{0x80000000, 0x80000000, 0x0, 0x0}};

  my_decimal decimal_check = {{0x80000000, 0x80000000, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok330) {
  my_decimal decimal = {{0x80000000, 0x80000000, 0x0, 0x80000000}};

  my_decimal decimal_check = {{0x80000000, 0x80000000, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok331) {
  my_decimal decimal = {{0x80000000, 0x80000000, 0x0, 0x10000}};

  my_decimal decimal_check = {{0xD9999999, 0xCCCCCCC, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok332) {
  my_decimal decimal = {{0x80000000, 0x80000000, 0x0, 0x80010000}};

  my_decimal decimal_check = {{0xD9999999, 0xCCCCCCC, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok333) {
  my_decimal decimal = {{0x80000000, 0x80000000, 0x0, 0x70000}};

  my_decimal decimal_check = {{0xBF94D6BC, 0xD6, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok334) {
  my_decimal decimal = {{0x80000000, 0x80000000, 0x0, 0x80070000}};

  my_decimal decimal_check = {{0xBF94D6BC, 0xD6, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok335) {
  my_decimal decimal = {{0x80000000, 0x80000000, 0x0, 0x120000}};

  my_decimal decimal_check = {{0x9, 0x0, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok336) {
  my_decimal decimal = {{0x80000000, 0x80000000, 0x0, 0x80120000}};

  my_decimal decimal_check = {{0x9, 0x0, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok337) {
  my_decimal decimal = {{0x0, 0x80000000, 0x0, 0x0}};

  my_decimal decimal_check = {{0x0, 0x80000000, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok338) {
  my_decimal decimal = {{0x0, 0x80000000, 0x0, 0x80000000}};

  my_decimal decimal_check = {{0x0, 0x80000000, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok339) {
  my_decimal decimal = {{0x0, 0x80000000, 0x0, 0x10000}};

  my_decimal decimal_check = {{0xCCCCCCCC, 0xCCCCCCC, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok340) {
  my_decimal decimal = {{0x0, 0x80000000, 0x0, 0x80010000}};

  my_decimal decimal_check = {{0xCCCCCCCC, 0xCCCCCCC, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok341) {
  my_decimal decimal = {{0x0, 0x80000000, 0x0, 0x80000}};

  my_decimal decimal_check = {{0x798EE230, 0x15, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok342) {
  my_decimal decimal = {{0x0, 0x80000000, 0x0, 0x80080000}};

  my_decimal decimal_check = {{0x798EE230, 0x15, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok343) {
  my_decimal decimal = {{0x0, 0x80000000, 0x0, 0x120000}};

  my_decimal decimal_check = {{0x9, 0x0, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok344) {
  my_decimal decimal = {{0x0, 0x80000000, 0x0, 0x80120000}};

  my_decimal decimal_check = {{0x9, 0x0, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok345) {
  my_decimal decimal = {{0x80000000, 0x0, 0x0, 0x0}};

  my_decimal decimal_check = {{0x80000000, 0x0, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok346) {
  my_decimal decimal = {{0x80000000, 0x0, 0x0, 0x80000000}};

  my_decimal decimal_check = {{0x80000000, 0x0, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok347) {
  my_decimal decimal = {{0x80000000, 0x0, 0x0, 0x10000}};

  my_decimal decimal_check = {{0xCCCCCCC, 0x0, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok348) {
  my_decimal decimal = {{0x80000000, 0x0, 0x0, 0x80010000}};

  my_decimal decimal_check = {{0xCCCCCCC, 0x0, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok349) {
  my_decimal decimal = {{0x80000000, 0x0, 0x0, 0x20000}};

  my_decimal decimal_check = {{0x147AE14, 0x0, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok350) {
  my_decimal decimal = {{0x80000000, 0x0, 0x0, 0x80020000}};

  my_decimal decimal_check = {{0x147AE14, 0x0, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok351) {
  my_decimal decimal = {{0x80000000, 0x0, 0x0, 0x40000}};

  my_decimal decimal_check = {{0x346DC, 0x0, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok352) {
  my_decimal decimal = {{0x80000000, 0x0, 0x0, 0x80040000}};

  my_decimal decimal_check = {{0x346DC, 0x0, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok353) {
  my_decimal decimal = {{0x80000000, 0x0, 0x0, 0x80000}};

  my_decimal decimal_check = {{0x15, 0x0, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok354) {
  my_decimal decimal = {{0x80000000, 0x0, 0x0, 0x80080000}};

  my_decimal decimal_check = {{0x15, 0x0, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok355) {
  my_decimal decimal = {{0x80000000, 0x0, 0x0, 0x90000}};

  my_decimal decimal_check = {{0x2, 0x0, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok356) {
  my_decimal decimal = {{0x80000000, 0x0, 0x0, 0x80090000}};

  my_decimal decimal_check = {{0x2, 0x0, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok357) {
  my_decimal decimal = {{0x811800, 0x811800, 0x811800, 0x0}};

  my_decimal decimal_check = {{0x811800, 0x811800, 0x811800, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok358) {
  my_decimal decimal = {{0x811800, 0x811800, 0x811800, 0x80000000}};

  my_decimal decimal_check = {{0x811800, 0x811800, 0x811800, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok359) {
  my_decimal decimal = {{0x811800, 0x811800, 0x811800, 0x10000}};

  my_decimal decimal_check = {{0x99A68266, 0xCCD9B599, 0xCE8CC, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok360) {
  my_decimal decimal = {{0x811800, 0x811800, 0x811800, 0x80010000}};

  my_decimal decimal_check = {{0x99A68266, 0xCCD9B599, 0xCE8CC, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok361) {
  my_decimal decimal = {{0x811800, 0x811800, 0x811800, 0x140000}};

  my_decimal decimal_check = {{0x17D047, 0x0, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok362) {
  my_decimal decimal = {{0x811800, 0x811800, 0x811800, 0x80140000}};

  my_decimal decimal_check = {{0x17D047, 0x0, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok363) {
  my_decimal decimal = {{0x811800, 0x811800, 0x811800, 0x1A0000}};

  my_decimal decimal_check = {{0x1, 0x0, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok364) {
  my_decimal decimal = {{0x811800, 0x811800, 0x811800, 0x801A0000}};

  my_decimal decimal_check = {{0x1, 0x0, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok365) {
  my_decimal decimal = {{0x0, 0x811800, 0x811800, 0x0}};

  my_decimal decimal_check = {{0x0, 0x811800, 0x811800, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok366) {
  my_decimal decimal = {{0x0, 0x811800, 0x811800, 0x80000000}};

  my_decimal decimal_check = {{0x0, 0x811800, 0x811800, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok367) {
  my_decimal decimal = {{0x0, 0x811800, 0x811800, 0x10000}};

  my_decimal decimal_check = {{0x99999999, 0xCCD9B599, 0xCE8CC, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok368) {
  my_decimal decimal = {{0x0, 0x811800, 0x811800, 0x80010000}};

  my_decimal decimal_check = {{0x99999999, 0xCCD9B599, 0xCE8CC, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok369) {
  my_decimal decimal = {{0x0, 0x811800, 0x811800, 0x40000}};

  my_decimal decimal_check = {{0x27525460, 0x75F7320, 0x34E, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok370) {
  my_decimal decimal = {{0x0, 0x811800, 0x811800, 0x80040000}};

  my_decimal decimal_check = {{0x27525460, 0x75F7320, 0x34E, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok371) {
  my_decimal decimal = {{0x0, 0x811800, 0x811800, 0x1A0000}};

  my_decimal decimal_check = {{0x1, 0x0, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok372) {
  my_decimal decimal = {{0x0, 0x811800, 0x811800, 0x801A0000}};

  my_decimal decimal_check = {{0x1, 0x0, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok373) {
  my_decimal decimal = {{0x811800, 0x0, 0x811800, 0x0}};

  my_decimal decimal_check = {{0x811800, 0x0, 0x811800, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok374) {
  my_decimal decimal = {{0x811800, 0x0, 0x811800, 0x80000000}};

  my_decimal decimal_check = {{0x811800, 0x0, 0x811800, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok375) {
  my_decimal decimal = {{0x811800, 0x0, 0x811800, 0x10000}};

  my_decimal decimal_check = {{0xCCD9B599, 0xCCCCCCCC, 0xCE8CC, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok376) {
  my_decimal decimal = {{0x811800, 0x0, 0x811800, 0x80010000}};

  my_decimal decimal_check = {{0xCCD9B599, 0xCCCCCCCC, 0xCE8CC, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok377) {
  my_decimal decimal = {{0x811800, 0x0, 0x811800, 0xB0000}};

  my_decimal decimal_check = {{0x9A4DA788, 0x58B66, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok378) {
  my_decimal decimal = {{0x811800, 0x0, 0x811800, 0x800B0000}};

  my_decimal decimal_check = {{0x9A4DA788, 0x58B66, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok379) {
  my_decimal decimal = {{0x811800, 0x0, 0x811800, 0x1A0000}};

  my_decimal decimal_check = {{0x1, 0x0, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok380) {
  my_decimal decimal = {{0x811800, 0x0, 0x811800, 0x801A0000}};

  my_decimal decimal_check = {{0x1, 0x0, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok381) {
  my_decimal decimal = {{0x0, 0x0, 0x811800, 0x0}};

  my_decimal decimal_check = {{0x0, 0x0, 0x811800, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok382) {
  my_decimal decimal = {{0x0, 0x0, 0x811800, 0x80000000}};

  my_decimal decimal_check = {{0x0, 0x0, 0x811800, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok383) {
  my_decimal decimal = {{0x0, 0x0, 0x811800, 0x10000}};

  my_decimal decimal_check = {{0xCCCCCCCC, 0xCCCCCCCC, 0xCE8CC, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok384) {
  my_decimal decimal = {{0x0, 0x0, 0x811800, 0x80010000}};

  my_decimal decimal_check = {{0xCCCCCCCC, 0xCCCCCCCC, 0xCE8CC, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok385) {
  my_decimal decimal = {{0x0, 0x0, 0x811800, 0x130000}};

  my_decimal decimal_check = {{0xEE22CC, 0x0, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok386) {
  my_decimal decimal = {{0x0, 0x0, 0x811800, 0x80130000}};

  my_decimal decimal_check = {{0xEE22CC, 0x0, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok387) {
  my_decimal decimal = {{0x0, 0x0, 0x811800, 0x1A0000}};

  my_decimal decimal_check = {{0x1, 0x0, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok388) {
  my_decimal decimal = {{0x0, 0x0, 0x811800, 0x801A0000}};

  my_decimal decimal_check = {{0x1, 0x0, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok389) {
  my_decimal decimal = {{0x811800, 0x811800, 0x0, 0x0}};

  my_decimal decimal_check = {{0x811800, 0x811800, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok390) {
  my_decimal decimal = {{0x811800, 0x811800, 0x0, 0x80000000}};

  my_decimal decimal_check = {{0x811800, 0x811800, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok391) {
  my_decimal decimal = {{0x811800, 0x811800, 0x0, 0x10000}};

  my_decimal decimal_check = {{0xCCD9B599, 0xCE8CC, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok392) {
  my_decimal decimal = {{0x811800, 0x811800, 0x0, 0x80010000}};

  my_decimal decimal_check = {{0xCCD9B599, 0xCE8CC, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok393) {
  my_decimal decimal = {{0x811800, 0x811800, 0x0, 0x80000}};

  my_decimal decimal_check = {{0x15A888CA, 0x0, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok394) {
  my_decimal decimal = {{0x811800, 0x811800, 0x0, 0x80080000}};

  my_decimal decimal_check = {{0x15A888CA, 0x0, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok395) {
  my_decimal decimal = {{0x811800, 0x811800, 0x0, 0x100000}};

  my_decimal decimal_check = {{0x3, 0x0, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok396) {
  my_decimal decimal = {{0x811800, 0x811800, 0x0, 0x80100000}};

  my_decimal decimal_check = {{0x3, 0x0, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok397) {
  my_decimal decimal = {{0x0, 0x811800, 0x0, 0x0}};

  my_decimal decimal_check = {{0x0, 0x811800, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok398) {
  my_decimal decimal = {{0x0, 0x811800, 0x0, 0x80000000}};

  my_decimal decimal_check = {{0x0, 0x811800, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok399) {
  my_decimal decimal = {{0x0, 0x811800, 0x0, 0x10000}};

  my_decimal decimal_check = {{0xCCCCCCCC, 0xCE8CC, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok400) {
  my_decimal decimal = {{0x0, 0x811800, 0x0, 0x80010000}};

  my_decimal decimal_check = {{0xCCCCCCCC, 0xCE8CC, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok401) {
  my_decimal decimal = {{0x0, 0x811800, 0x0, 0x20000}};

  my_decimal decimal_check = {{0xE147AE14, 0x14A7A, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok402) {
  my_decimal decimal = {{0x0, 0x811800, 0x0, 0x80020000}};

  my_decimal decimal_check = {{0xE147AE14, 0x14A7A, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok403) {
  my_decimal decimal = {{0x0, 0x811800, 0x0, 0x80000}};

  my_decimal decimal_check = {{0x15A888CA, 0x0, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok404) {
  my_decimal decimal = {{0x0, 0x811800, 0x0, 0x80080000}};

  my_decimal decimal_check = {{0x15A888CA, 0x0, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok405) {
  my_decimal decimal = {{0x0, 0x811800, 0x0, 0xF0000}};

  my_decimal decimal_check = {{0x24, 0x0, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok406) {
  my_decimal decimal = {{0x0, 0x811800, 0x0, 0x800F0000}};

  my_decimal decimal_check = {{0x24, 0x0, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok407) {
  my_decimal decimal = {{0x0, 0x811800, 0x0, 0x100000}};

  my_decimal decimal_check = {{0x3, 0x0, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok408) {
  my_decimal decimal = {{0x0, 0x811800, 0x0, 0x80100000}};

  my_decimal decimal_check = {{0x3, 0x0, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok409) {
  my_decimal decimal = {{0x811800, 0x0, 0x0, 0x0}};

  my_decimal decimal_check = {{0x811800, 0x0, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok410) {
  my_decimal decimal = {{0x811800, 0x0, 0x0, 0x80000000}};

  my_decimal decimal_check = {{0x811800, 0x0, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok411) {
  my_decimal decimal = {{0x811800, 0x0, 0x0, 0x10000}};

  my_decimal decimal_check = {{0xCE8CC, 0x0, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok412) {
  my_decimal decimal = {{0x811800, 0x0, 0x0, 0x80010000}};

  my_decimal decimal_check = {{0xCE8CC, 0x0, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok413) {
  my_decimal decimal = {{0x811800, 0x0, 0x0, 0x20000}};

  my_decimal decimal_check = {{0x14A7A, 0x0, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok414) {
  my_decimal decimal = {{0x811800, 0x0, 0x0, 0x80020000}};

  my_decimal decimal_check = {{0x14A7A, 0x0, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok415) {
  my_decimal decimal = {{0x811800, 0x0, 0x0, 0x30000}};

  my_decimal decimal_check = {{0x210C, 0x0, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok416) {
  my_decimal decimal = {{0x811800, 0x0, 0x0, 0x80030000}};

  my_decimal decimal_check = {{0x210C, 0x0, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok417) {
  my_decimal decimal = {{0x811800, 0x0, 0x0, 0x50000}};

  my_decimal decimal_check = {{0x54, 0x0, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok418) {
  my_decimal decimal = {{0x811800, 0x0, 0x0, 0x80050000}};

  my_decimal decimal_check = {{0x54, 0x0, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok419) {
  my_decimal decimal = {{0x811800, 0x0, 0x0, 0x60000}};

  my_decimal decimal_check = {{0x8, 0x0, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok420) {
  my_decimal decimal = {{0x811800, 0x0, 0x0, 0x80060000}};

  my_decimal decimal_check = {{0x8, 0x0, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok421) {
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};

  my_decimal decimal_check = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok422) {
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};

  my_decimal decimal_check = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok423) {
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};

  my_decimal decimal_check = {{0x99999999, 0x99999999, 0x19999999, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok424) {
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80010000}};

  my_decimal decimal_check = {
      {0x99999999, 0x99999999, 0x19999999, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok425) {
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x110000}};

  my_decimal decimal_check = {{0x77AA3236, 0xB8, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok426) {
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80110000}};

  my_decimal decimal_check = {{0x77AA3236, 0xB8, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok427) {
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x1C0000}};

  my_decimal decimal_check = {{0x7, 0x0, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok428) {
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x801C0000}};

  my_decimal decimal_check = {{0x7, 0x0, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok429) {
  my_decimal decimal = {{0x0, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};

  my_decimal decimal_check = {{0x0, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok430) {
  my_decimal decimal = {{0x0, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};

  my_decimal decimal_check = {{0x0, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok431) {
  my_decimal decimal = {{0x0, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};

  my_decimal decimal_check = {{0x80000000, 0x99999999, 0x19999999, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok432) {
  my_decimal decimal = {{0x0, 0xFFFFFFFF, 0xFFFFFFFF, 0x80010000}};

  my_decimal decimal_check = {
      {0x80000000, 0x99999999, 0x19999999, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok433) {
  my_decimal decimal = {{0x0, 0xFFFFFFFF, 0xFFFFFFFF, 0xF0000}};

  my_decimal decimal_check = {{0xBE7B9D58, 0x480E, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok434) {
  my_decimal decimal = {{0x0, 0xFFFFFFFF, 0xFFFFFFFF, 0x800F0000}};

  my_decimal decimal_check = {{0xBE7B9D58, 0x480E, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok435) {
  my_decimal decimal = {{0x0, 0xFFFFFFFF, 0xFFFFFFFF, 0x1C0000}};

  my_decimal decimal_check = {{0x7, 0x0, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok436) {
  my_decimal decimal = {{0x0, 0xFFFFFFFF, 0xFFFFFFFF, 0x801C0000}};

  my_decimal decimal_check = {{0x7, 0x0, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok437) {
  my_decimal decimal = {{0xFFFFFFFF, 0x0, 0xFFFFFFFF, 0x0}};

  my_decimal decimal_check = {{0xFFFFFFFF, 0x0, 0xFFFFFFFF, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok438) {
  my_decimal decimal = {{0xFFFFFFFF, 0x0, 0xFFFFFFFF, 0x80000000}};

  my_decimal decimal_check = {{0xFFFFFFFF, 0x0, 0xFFFFFFFF, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok439) {
  my_decimal decimal = {{0xFFFFFFFF, 0x0, 0xFFFFFFFF, 0x10000}};

  my_decimal decimal_check = {{0x19999999, 0x80000000, 0x19999999, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok440) {
  my_decimal decimal = {{0xFFFFFFFF, 0x0, 0xFFFFFFFF, 0x80010000}};

  my_decimal decimal_check = {
      {0x19999999, 0x80000000, 0x19999999, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok441) {
  my_decimal decimal = {{0xFFFFFFFF, 0x0, 0xFFFFFFFF, 0x110000}};

  my_decimal decimal_check = {{0x77AA317E, 0xB8, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok442) {
  my_decimal decimal = {{0xFFFFFFFF, 0x0, 0xFFFFFFFF, 0x80110000}};

  my_decimal decimal_check = {{0x77AA317E, 0xB8, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok443) {
  my_decimal decimal = {{0xFFFFFFFF, 0x0, 0xFFFFFFFF, 0x1C0000}};

  my_decimal decimal_check = {{0x7, 0x0, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok444) {
  my_decimal decimal = {{0xFFFFFFFF, 0x0, 0xFFFFFFFF, 0x801C0000}};

  my_decimal decimal_check = {{0x7, 0x0, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok445) {
  my_decimal decimal = {{0x0, 0x0, 0xFFFFFFFF, 0x0}};

  my_decimal decimal_check = {{0x0, 0x0, 0xFFFFFFFF, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok446) {
  my_decimal decimal = {{0x0, 0x0, 0xFFFFFFFF, 0x80000000}};

  my_decimal decimal_check = {{0x0, 0x0, 0xFFFFFFFF, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok447) {
  my_decimal decimal = {{0x0, 0x0, 0xFFFFFFFF, 0x10000}};

  my_decimal decimal_check = {{0x0, 0x80000000, 0x19999999, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok448) {
  my_decimal decimal = {{0x0, 0x0, 0xFFFFFFFF, 0x80010000}};

  my_decimal decimal_check = {{0x0, 0x80000000, 0x19999999, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok449) {
  my_decimal decimal = {{0x0, 0x0, 0xFFFFFFFF, 0x120000}};

  my_decimal decimal_check = {{0x725DD1BF, 0x12, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok450) {
  my_decimal decimal = {{0x0, 0x0, 0xFFFFFFFF, 0x80120000}};

  my_decimal decimal_check = {{0x725DD1BF, 0x12, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok451) {
  my_decimal decimal = {{0x0, 0x0, 0xFFFFFFFF, 0x1C0000}};

  my_decimal decimal_check = {{0x7, 0x0, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok452) {
  my_decimal decimal = {{0x0, 0x0, 0xFFFFFFFF, 0x801C0000}};

  my_decimal decimal_check = {{0x7, 0x0, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok453) {
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0x0, 0x0}};

  my_decimal decimal_check = {{0xFFFFFFFF, 0xFFFFFFFF, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok454) {
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0x0, 0x80000000}};

  my_decimal decimal_check = {{0xFFFFFFFF, 0xFFFFFFFF, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok455) {
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0x0, 0x10000}};

  my_decimal decimal_check = {{0x99999999, 0x19999999, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok456) {
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0x0, 0x80010000}};

  my_decimal decimal_check = {{0x99999999, 0x19999999, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok457) {
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0x0, 0x30000}};

  my_decimal decimal_check = {{0x4BC6A7EF, 0x418937, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok458) {
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0x0, 0x80030000}};

  my_decimal decimal_check = {{0x4BC6A7EF, 0x418937, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok459) {
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0x0, 0xB0000}};

  my_decimal decimal_check = {{0xAFEBFF0, 0x0, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok460) {
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0x0, 0x800B0000}};

  my_decimal decimal_check = {{0xAFEBFF0, 0x0, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok461) {
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0x0, 0x110000}};

  my_decimal decimal_check = {{0xB8, 0x0, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok462) {
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0x0, 0x80110000}};

  my_decimal decimal_check = {{0xB8, 0x0, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok463) {
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0x0, 0x130000}};

  my_decimal decimal_check = {{0x1, 0x0, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok464) {
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0x0, 0x80130000}};

  my_decimal decimal_check = {{0x1, 0x0, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok465) {
  my_decimal decimal = {{0x0, 0xFFFFFFFF, 0x0, 0x0}};

  my_decimal decimal_check = {{0x0, 0xFFFFFFFF, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok466) {
  my_decimal decimal = {{0x0, 0xFFFFFFFF, 0x0, 0x80000000}};

  my_decimal decimal_check = {{0x0, 0xFFFFFFFF, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok467) {
  my_decimal decimal = {{0x0, 0xFFFFFFFF, 0x0, 0x10000}};

  my_decimal decimal_check = {{0x80000000, 0x19999999, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok468) {
  my_decimal decimal = {{0x0, 0xFFFFFFFF, 0x0, 0x80010000}};

  my_decimal decimal_check = {{0x80000000, 0x19999999, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok469) {
  my_decimal decimal = {{0x0, 0xFFFFFFFF, 0x0, 0x30000}};

  my_decimal decimal_check = {{0x4B851EB8, 0x418937, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok470) {
  my_decimal decimal = {{0x0, 0xFFFFFFFF, 0x0, 0x80030000}};

  my_decimal decimal_check = {{0x4B851EB8, 0x418937, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok471) {
  my_decimal decimal = {{0x0, 0xFFFFFFFF, 0x0, 0x90000}};

  my_decimal decimal_check = {{0x4B82FA05, 0x4, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok472) {
  my_decimal decimal = {{0x0, 0xFFFFFFFF, 0x0, 0x80090000}};

  my_decimal decimal_check = {{0x4B82FA05, 0x4, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok473) {
  my_decimal decimal = {{0x0, 0xFFFFFFFF, 0x0, 0x110000}};

  my_decimal decimal_check = {{0xB8, 0x0, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok474) {
  my_decimal decimal = {{0x0, 0xFFFFFFFF, 0x0, 0x80110000}};

  my_decimal decimal_check = {{0xB8, 0x0, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok475) {
  my_decimal decimal = {{0x0, 0xFFFFFFFF, 0x0, 0x130000}};

  my_decimal decimal_check = {{0x1, 0x0, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok476) {
  my_decimal decimal = {{0x0, 0xFFFFFFFF, 0x0, 0x80130000}};

  my_decimal decimal_check = {{0x1, 0x0, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok477) {
  my_decimal decimal = {{0xFFFFFFFF, 0x0, 0x0, 0x0}};

  my_decimal decimal_check = {{0xFFFFFFFF, 0x0, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok478) {
  my_decimal decimal = {{0xFFFFFFFF, 0x0, 0x0, 0x80000000}};

  my_decimal decimal_check = {{0xFFFFFFFF, 0x0, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok479) {
  my_decimal decimal = {{0xFFFFFFFF, 0x0, 0x0, 0x10000}};

  my_decimal decimal_check = {{0x19999999, 0x0, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok480) {
  my_decimal decimal = {{0xFFFFFFFF, 0x0, 0x0, 0x80010000}};

  my_decimal decimal_check = {{0x19999999, 0x0, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok481) {
  my_decimal decimal = {{0xFFFFFFFF, 0x0, 0x0, 0x20000}};

  my_decimal decimal_check = {{0x28F5C28, 0x0, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok482) {
  my_decimal decimal = {{0xFFFFFFFF, 0x0, 0x0, 0x80020000}};

  my_decimal decimal_check = {{0x28F5C28, 0x0, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok483) {
  my_decimal decimal = {{0xFFFFFFFF, 0x0, 0x0, 0x50000}};

  my_decimal decimal_check = {{0xA7C5, 0x0, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok484) {
  my_decimal decimal = {{0xFFFFFFFF, 0x0, 0x0, 0x80050000}};

  my_decimal decimal_check = {{0xA7C5, 0x0, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok485) {
  my_decimal decimal = {{0xFFFFFFFF, 0x0, 0x0, 0x80000}};

  my_decimal decimal_check = {{0x2A, 0x0, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok486) {
  my_decimal decimal = {{0xFFFFFFFF, 0x0, 0x0, 0x80080000}};

  my_decimal decimal_check = {{0x2A, 0x0, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok487) {
  my_decimal decimal = {{0xFFFFFFFF, 0x0, 0x0, 0x90000}};

  my_decimal decimal_check = {{0x4, 0x0, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok488) {
  my_decimal decimal = {{0xFFFFFFFF, 0x0, 0x0, 0x80090000}};

  my_decimal decimal_check = {{0x4, 0x0, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok489) {
  my_decimal decimal = {{0xA, 0x0, 0x0, 0x10000}};

  my_decimal decimal_check = {{0x1, 0x0, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok490) {
  my_decimal decimal = {{0xA, 0x0, 0x0, 0x80010000}};

  my_decimal decimal_check = {{0x1, 0x0, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok491) {
  my_decimal decimal = {{0x64, 0x0, 0x0, 0x20000}};

  my_decimal decimal_check = {{0x1, 0x0, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok492) {
  my_decimal decimal = {{0x64, 0x0, 0x0, 0x80020000}};

  my_decimal decimal_check = {{0x1, 0x0, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok493) {
  my_decimal decimal = {{0x3E8, 0x0, 0x0, 0x30000}};

  my_decimal decimal_check = {{0x1, 0x0, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok494) {
  my_decimal decimal = {{0x3E8, 0x0, 0x0, 0x80030000}};

  my_decimal decimal_check = {{0x1, 0x0, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok495) {
  my_decimal decimal = {{0x540BE400, 0x2, 0x0, 0xA0000}};

  my_decimal decimal_check = {{0x1, 0x0, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok496) {
  my_decimal decimal = {{0x540BE400, 0x2, 0x0, 0x800A0000}};

  my_decimal decimal_check = {{0x1, 0x0, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok497) {
  my_decimal decimal = {{0x6FC10000, 0x2386F2, 0x0, 0x100000}};

  my_decimal decimal_check = {{0x1, 0x0, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok498) {
  my_decimal decimal = {{0x6FC10000, 0x2386F2, 0x0, 0x80100000}};

  my_decimal decimal_check = {{0x1, 0x0, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok499) {
  my_decimal decimal = {{0xF6800000, 0x2C7E14A, 0x152D, 0x170000}};

  my_decimal decimal_check = {{0x1, 0x0, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok500) {
  my_decimal decimal = {{0xF6800000, 0x2C7E14A, 0x152D, 0x80170000}};

  my_decimal decimal_check = {{0x1, 0x0, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok501) {
  my_decimal decimal = {{0xE8000000, 0x9FD0803C, 0x33B2E3C, 0x1B0000}};

  my_decimal decimal_check = {{0x1, 0x0, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok502) {
  my_decimal decimal = {{0xE8000000, 0x9FD0803C, 0x33B2E3C, 0x801B0000}};

  my_decimal decimal_check = {{0x1, 0x0, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok503) {
  my_decimal decimal = {{0x10000000, 0x3E250261, 0x204FCE5E, 0x1C0000}};

  my_decimal decimal_check = {{0x1, 0x0, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok504) {
  my_decimal decimal = {{0x10000000, 0x3E250261, 0x204FCE5E, 0x801C0000}};

  my_decimal decimal_check = {{0x1, 0x0, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok505) {
  my_decimal decimal = {{0xB, 0x0, 0x0, 0x10000}};

  my_decimal decimal_check = {{0x1, 0x0, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok506) {
  my_decimal decimal = {{0xB, 0x0, 0x0, 0x80010000}};

  my_decimal decimal_check = {{0x1, 0x0, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok507) {
  my_decimal decimal = {{0x4BC, 0x0, 0x0, 0x20000}};

  my_decimal decimal_check = {{0xC, 0x0, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok508) {
  my_decimal decimal = {{0x4BC, 0x0, 0x0, 0x80020000}};

  my_decimal decimal_check = {{0xC, 0x0, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok509) {
  my_decimal decimal = {{0x1E0F3, 0x0, 0x0, 0x30000}};

  my_decimal decimal_check = {{0x7B, 0x0, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok510) {
  my_decimal decimal = {{0x1E0F3, 0x0, 0x0, 0x80030000}};

  my_decimal decimal_check = {{0x7B, 0x0, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok511) {
  my_decimal decimal = {{0xBC4FF2, 0x0, 0x0, 0x40000}};

  my_decimal decimal_check = {{0x4D2, 0x0, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok512) {
  my_decimal decimal = {{0xBC4FF2, 0x0, 0x0, 0x80040000}};

  my_decimal decimal_check = {{0x4D2, 0x0, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok513) {
  my_decimal decimal = {{0x499529D9, 0x0, 0x0, 0x50000}};

  my_decimal decimal_check = {{0x3039, 0x0, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok514) {
  my_decimal decimal = {{0x499529D9, 0x0, 0x0, 0x80050000}};

  my_decimal decimal_check = {{0x3039, 0x0, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok515) {
  my_decimal decimal = {{0xBE8EF240, 0x1C, 0x0, 0x60000}};

  my_decimal decimal_check = {{0x1E240, 0x0, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok516) {
  my_decimal decimal = {{0xBE8EF240, 0x1C, 0x0, 0x80060000}};

  my_decimal decimal_check = {{0x1E240, 0x0, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok517) {
  my_decimal decimal = {{0x73593407, 0xB3A, 0x0, 0x70000}};

  my_decimal decimal_check = {{0x12D687, 0x0, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok518) {
  my_decimal decimal = {{0x73593407, 0xB3A, 0x0, 0x80070000}};

  my_decimal decimal_check = {{0x12D687, 0x0, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok519) {
  my_decimal decimal = {{0xEB1F0AD2, 0xAB54A98C, 0x0, 0xA0000}};

  my_decimal decimal_check = {{0x499602D2, 0x0, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok520) {
  my_decimal decimal = {{0xEB1F0AD2, 0xAB54A98C, 0x0, 0x800A0000}};

  my_decimal decimal_check = {{0x499602D2, 0x0, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok521) {
  my_decimal decimal = {{0xF91EAFF2, 0x6D795225, 0x3FD35EB, 0xE0000}};

  my_decimal decimal_check = {{0x73CE2FF2, 0xB3A, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok522) {
  my_decimal decimal = {{0xF91EAFF2, 0x6D795225, 0x3FD35EB, 0x800E0000}};

  my_decimal decimal_check = {{0x73CE2FF2, 0xB3A, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok523) {
  my_decimal decimal = {{0x63, 0x0, 0x0, 0x0}};

  my_decimal decimal_check = {{0x63, 0x0, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok524) {
  my_decimal decimal = {{0x63, 0x0, 0x0, 0x80000000}};

  my_decimal decimal_check = {{0x63, 0x0, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok525) {
  my_decimal decimal = {{0x63, 0x0, 0x0, 0x10000}};

  my_decimal decimal_check = {{0x9, 0x0, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok526) {
  my_decimal decimal = {{0x63, 0x0, 0x0, 0x80010000}};

  my_decimal decimal_check = {{0x9, 0x0, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok527) {
  my_decimal decimal = {{0x270F, 0x0, 0x0, 0x20000}};

  my_decimal decimal_check = {{0x63, 0x0, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok528) {
  my_decimal decimal = {{0x270F, 0x0, 0x0, 0x80020000}};

  my_decimal decimal_check = {{0x63, 0x0, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok529) {
  my_decimal decimal = {{0xF423F, 0x0, 0x0, 0x30000}};

  my_decimal decimal_check = {{0x3E7, 0x0, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok530) {
  my_decimal decimal = {{0xF423F, 0x0, 0x0, 0x80030000}};

  my_decimal decimal_check = {{0x3E7, 0x0, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok531) {
  my_decimal decimal = {{0x5F5E0FF, 0x0, 0x0, 0x40000}};

  my_decimal decimal_check = {{0x270F, 0x0, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok532) {
  my_decimal decimal = {{0x5F5E0FF, 0x0, 0x0, 0x80040000}};

  my_decimal decimal_check = {{0x270F, 0x0, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok533) {
  my_decimal decimal = {{0x540BE3FF, 0x2, 0x0, 0x50000}};

  my_decimal decimal_check = {{0x1869F, 0x0, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok534) {
  my_decimal decimal = {{0x540BE3FF, 0x2, 0x0, 0x80050000}};

  my_decimal decimal_check = {{0x1869F, 0x0, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok535) {
  my_decimal decimal = {{0xD4A50FFF, 0xE8, 0x0, 0x60000}};

  my_decimal decimal_check = {{0xF423F, 0x0, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok536) {
  my_decimal decimal = {{0xD4A50FFF, 0xE8, 0x0, 0x80060000}};

  my_decimal decimal_check = {{0xF423F, 0x0, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok537) {
  my_decimal decimal = {{0x107A3FFF, 0x5AF3, 0x0, 0x70000}};

  my_decimal decimal_check = {{0x98967F, 0x0, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok538) {
  my_decimal decimal = {{0x107A3FFF, 0x5AF3, 0x0, 0x80070000}};

  my_decimal decimal_check = {{0x98967F, 0x0, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok539) {
  my_decimal decimal = {{0x6FC0FFFF, 0x2386F2, 0x0, 0x80000}};

  my_decimal decimal_check = {{0x5F5E0FF, 0x0, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok540) {
  my_decimal decimal = {{0x6FC0FFFF, 0x2386F2, 0x0, 0x80080000}};

  my_decimal decimal_check = {{0x5F5E0FF, 0x0, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok541) {
  my_decimal decimal = {{0xA763FFFF, 0xDE0B6B3, 0x0, 0x90000}};

  my_decimal decimal_check = {{0x3B9AC9FF, 0x0, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok542) {
  my_decimal decimal = {{0xA763FFFF, 0xDE0B6B3, 0x0, 0x80090000}};

  my_decimal decimal_check = {{0x3B9AC9FF, 0x0, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok543) {
  my_decimal decimal = {{0x630FFFFF, 0x6BC75E2D, 0x5, 0xA0000}};

  my_decimal decimal_check = {{0x540BE3FF, 0x2, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok544) {
  my_decimal decimal = {{0x630FFFFF, 0x6BC75E2D, 0x5, 0x800A0000}};

  my_decimal decimal_check = {{0x540BE3FF, 0x2, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok545) {
  my_decimal decimal = {{0x9, 0x0, 0x0, 0x0}};

  my_decimal decimal_check = {{0x9, 0x0, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok546) {
  my_decimal decimal = {{0x9, 0x0, 0x0, 0x80000000}};

  my_decimal decimal_check = {{0x9, 0x0, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok547) {
  my_decimal decimal = {{0x9, 0x0, 0x0, 0x10000}};

  my_decimal decimal_check = {{0x0, 0x0, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok548) {
  my_decimal decimal = {{0x9, 0x0, 0x0, 0x80010000}};

  my_decimal decimal_check = {{0x0, 0x0, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok549) {
  my_decimal decimal = {{0x63, 0x0, 0x0, 0x20000}};

  my_decimal decimal_check = {{0x0, 0x0, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok550) {
  my_decimal decimal = {{0x63, 0x0, 0x0, 0x80020000}};

  my_decimal decimal_check = {{0x0, 0x0, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok551) {
  my_decimal decimal = {{0x3E7, 0x0, 0x0, 0x30000}};

  my_decimal decimal_check = {{0x0, 0x0, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok552) {
  my_decimal decimal = {{0x3E7, 0x0, 0x0, 0x80030000}};

  my_decimal decimal_check = {{0x0, 0x0, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok553) {
  my_decimal decimal = {{0x270F, 0x0, 0x0, 0x40000}};

  my_decimal decimal_check = {{0x0, 0x0, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok554) {
  my_decimal decimal = {{0x270F, 0x0, 0x0, 0x80040000}};

  my_decimal decimal_check = {{0x0, 0x0, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok555) {
  my_decimal decimal = {{0x1869F, 0x0, 0x0, 0x50000}};

  my_decimal decimal_check = {{0x0, 0x0, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok556) {
  my_decimal decimal = {{0x1869F, 0x0, 0x0, 0x80050000}};

  my_decimal decimal_check = {{0x0, 0x0, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok557) {
  my_decimal decimal = {{0xF423F, 0x0, 0x0, 0x60000}};

  my_decimal decimal_check = {{0x0, 0x0, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok558) {
  my_decimal decimal = {{0xF423F, 0x0, 0x0, 0x80060000}};

  my_decimal decimal_check = {{0x0, 0x0, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok559) {
  my_decimal decimal = {{0x98967F, 0x0, 0x0, 0x70000}};

  my_decimal decimal_check = {{0x0, 0x0, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok560) {
  my_decimal decimal = {{0x98967F, 0x0, 0x0, 0x80070000}};

  my_decimal decimal_check = {{0x0, 0x0, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok561) {
  my_decimal decimal = {{0x5F5E0FF, 0x0, 0x0, 0x80000}};

  my_decimal decimal_check = {{0x0, 0x0, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok562) {
  my_decimal decimal = {{0x5F5E0FF, 0x0, 0x0, 0x80080000}};

  my_decimal decimal_check = {{0x0, 0x0, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok563) {
  my_decimal decimal = {{0x3B9AC9FF, 0x0, 0x0, 0x90000}};

  my_decimal decimal_check = {{0x0, 0x0, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok564) {
  my_decimal decimal = {{0x3B9AC9FF, 0x0, 0x0, 0x80090000}};

  my_decimal decimal_check = {{0x0, 0x0, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok565) {
  my_decimal decimal = {{0x540BE3FF, 0x2, 0x0, 0xA0000}};

  my_decimal decimal_check = {{0x0, 0x0, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok566) {
  my_decimal decimal = {{0x540BE3FF, 0x2, 0x0, 0x800A0000}};

  my_decimal decimal_check = {{0x0, 0x0, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok567) {
  my_decimal decimal = {{0x630FFFFF, 0x6BC75E2D, 0x5, 0x140000}};

  my_decimal decimal_check = {{0x0, 0x0, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok568) {
  my_decimal decimal = {{0x630FFFFF, 0x6BC75E2D, 0x5, 0x80140000}};

  my_decimal decimal_check = {{0x0, 0x0, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok569) {
  my_decimal decimal = {{0x0, 0x0, 0x0, 0x80000000}};

  my_decimal decimal_check = {{0x0, 0x0, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok570) {
  my_decimal decimal = {{0x0, 0x0, 0x0, 0x0}};

  my_decimal decimal_check = {{0x0, 0x0, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok571) {
  my_decimal decimal = {{0x0, 0x0, 0x0, 0x80010000}};

  my_decimal decimal_check = {{0x0, 0x0, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok572) {
  my_decimal decimal = {{0x0, 0x0, 0x0, 0x10000}};

  my_decimal decimal_check = {{0x0, 0x0, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok573) {
  my_decimal decimal = {{0x0, 0x0, 0x0, 0x80020000}};

  my_decimal decimal_check = {{0x0, 0x0, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok574) {
  my_decimal decimal = {{0x0, 0x0, 0x0, 0x20000}};

  my_decimal decimal_check = {{0x0, 0x0, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok575) {
  my_decimal decimal = {{0x0, 0x0, 0x0, 0x800E0000}};

  my_decimal decimal_check = {{0x0, 0x0, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok576) {
  my_decimal decimal = {{0x0, 0x0, 0x0, 0xE0000}};

  my_decimal decimal_check = {{0x0, 0x0, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok577) {
  my_decimal decimal = {{0x0, 0x0, 0x0, 0x801B0000}};

  my_decimal decimal_check = {{0x0, 0x0, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok578) {
  my_decimal decimal = {{0x0, 0x0, 0x0, 0x1B0000}};

  my_decimal decimal_check = {{0x0, 0x0, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok579) {
  my_decimal decimal = {{0x0, 0x0, 0x0, 0x801C0000}};

  my_decimal decimal_check = {{0x0, 0x0, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok580) {
  my_decimal decimal = {{0x0, 0x0, 0x0, 0x1C0000}};

  my_decimal decimal_check = {{0x0, 0x0, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok581) {
  my_decimal decimal = {{0x5, 0x0, 0x0, 0x10000}};

  my_decimal decimal_check = {{0x0, 0x0, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok582) {
  my_decimal decimal = {{0x5, 0x0, 0x0, 0x80010000}};

  my_decimal decimal_check = {{0x0, 0x0, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok583) {
  my_decimal decimal = {{0x31, 0x0, 0x0, 0x20000}};

  my_decimal decimal_check = {{0x0, 0x0, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok584) {
  my_decimal decimal = {{0x31, 0x0, 0x0, 0x80020000}};

  my_decimal decimal_check = {{0x0, 0x0, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok585) {
  my_decimal decimal = {{0x33, 0x0, 0x0, 0x20000}};

  my_decimal decimal_check = {{0x0, 0x0, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok586) {
  my_decimal decimal = {{0x33, 0x0, 0x0, 0x80020000}};

  my_decimal decimal_check = {{0x0, 0x0, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok587) {
  my_decimal decimal = {{0x2FAF07F, 0x0, 0x0, 0x80000}};

  my_decimal decimal_check = {{0x0, 0x0, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok588) {
  my_decimal decimal = {{0x2FAF07F, 0x0, 0x0, 0x80080000}};

  my_decimal decimal_check = {{0x0, 0x0, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok589) {
  my_decimal decimal = {{0x87FFFFFF, 0x1F128130, 0x1027E72F, 0x1C0000}};

  my_decimal decimal_check = {{0x0, 0x0, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok590) {
  my_decimal decimal = {{0x87FFFFFF, 0x1F128130, 0x1027E72F, 0x801C0000}};

  my_decimal decimal_check = {{0x0, 0x0, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok591) {
  my_decimal decimal = {{0x88000001, 0x1F128130, 0x1027E72F, 0x1C0000}};

  my_decimal decimal_check = {{0x0, 0x0, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok592) {
  my_decimal decimal = {{0x88000001, 0x1F128130, 0x1027E72F, 0x801C0000}};

  my_decimal decimal_check = {{0x0, 0x0, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok593) {
  my_decimal decimal = {{0x88000000, 0x1F128130, 0x1027E72F, 0x1C0000}};

  my_decimal decimal_check = {{0x0, 0x0, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok594) {
  my_decimal decimal = {{0x88000000, 0x1F128130, 0x1027E72F, 0x801C0000}};

  my_decimal decimal_check = {{0x0, 0x0, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok595) {
  my_decimal decimal = {{0x63, 0x0, 0x0, 0x20000}};

  my_decimal decimal_check = {{0x0, 0x0, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok596) {
  my_decimal decimal = {{0x63, 0x0, 0x0, 0x80020000}};

  my_decimal decimal_check = {{0x0, 0x0, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok597) {
  my_decimal decimal = {{0x3B9AC9FF, 0x0, 0x0, 0x90000}};

  my_decimal decimal_check = {{0x0, 0x0, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok598) {
  my_decimal decimal = {{0x3B9AC9FF, 0x0, 0x0, 0x80090000}};

  my_decimal decimal_check = {{0x0, 0x0, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok599) {
  my_decimal decimal = {{0xFFFFFFF, 0x3E250261, 0x204FCE5E, 0x1C0000}};

  my_decimal decimal_check = {{0x0, 0x0, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok600) {
  my_decimal decimal = {{0xFFFFFFF, 0x3E250261, 0x204FCE5E, 0x801C0000}};

  my_decimal decimal_check = {{0x0, 0x0, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok601) {
  my_decimal decimal = {{0x10000001, 0x3E250261, 0x204FCE5E, 0x1C0000}};

  my_decimal decimal_check = {{0x1, 0x0, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok602) {
  my_decimal decimal = {{0x10000001, 0x3E250261, 0x204FCE5E, 0x801C0000}};

  my_decimal decimal_check = {{0x1, 0x0, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok603) {
  my_decimal decimal = {{0xF, 0x0, 0x0, 0x10000}};

  my_decimal decimal_check = {{0x1, 0x0, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok604) {
  my_decimal decimal = {{0xF, 0x0, 0x0, 0x80010000}};

  my_decimal decimal_check = {{0x1, 0x0, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok605) {
  my_decimal decimal = {{0x95, 0x0, 0x0, 0x20000}};

  my_decimal decimal_check = {{0x1, 0x0, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok606) {
  my_decimal decimal = {{0x95, 0x0, 0x0, 0x80020000}};

  my_decimal decimal_check = {{0x1, 0x0, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok607) {
  my_decimal decimal = {{0x97, 0x0, 0x0, 0x20000}};

  my_decimal decimal_check = {{0x1, 0x0, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok608) {
  my_decimal decimal = {{0x97, 0x0, 0x0, 0x80020000}};

  my_decimal decimal_check = {{0x1, 0x0, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok609) {
  my_decimal decimal = {{0x8F0D17F, 0x0, 0x0, 0x80000}};

  my_decimal decimal_check = {{0x1, 0x0, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok610) {
  my_decimal decimal = {{0x8F0D17F, 0x0, 0x0, 0x80080000}};

  my_decimal decimal_check = {{0x1, 0x0, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok611) {
  my_decimal decimal = {{0x97FFFFFF, 0x5D378391, 0x3077B58D, 0x1C0000}};

  my_decimal decimal_check = {{0x1, 0x0, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok612) {
  my_decimal decimal = {{0x97FFFFFF, 0x5D378391, 0x3077B58D, 0x801C0000}};

  my_decimal decimal_check = {{0x1, 0x0, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok613) {
  my_decimal decimal = {{0x98000001, 0x5D378391, 0x3077B58D, 0x1C0000}};

  my_decimal decimal_check = {{0x1, 0x0, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok614) {
  my_decimal decimal = {{0x98000001, 0x5D378391, 0x3077B58D, 0x801C0000}};

  my_decimal decimal_check = {{0x1, 0x0, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok615) {
  my_decimal decimal = {{0x98000000, 0x5D378391, 0x3077B58D, 0x1C0000}};

  my_decimal decimal_check = {{0x1, 0x0, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok616) {
  my_decimal decimal = {{0x98000000, 0x5D378391, 0x3077B58D, 0x801C0000}};

  my_decimal decimal_check = {{0x1, 0x0, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok617) {
  my_decimal decimal = {{0x1E847F, 0x0, 0x0, 0x60000}};

  my_decimal decimal_check = {{0x1, 0x0, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok618) {
  my_decimal decimal = {{0x1E847F, 0x0, 0x0, 0x80060000}};

  my_decimal decimal_check = {{0x1, 0x0, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok619) {
  my_decimal decimal = {{0x1FFFFFFF, 0x7C4A04C2, 0x409F9CBC, 0x1C0000}};

  my_decimal decimal_check = {{0x1, 0x0, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok620) {
  my_decimal decimal = {{0x1FFFFFFF, 0x7C4A04C2, 0x409F9CBC, 0x801C0000}};

  my_decimal decimal_check = {{0x1, 0x0, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok621) {
  my_decimal decimal = {{0x53270A49, 0x54E37A35, 0x5640E6AF, 0x800E0000}};

  my_decimal decimal_check = {{0x361574B7, 0xF2C8, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok622) {
  my_decimal decimal = {{0x53270A49, 0x54E37A35, 0x5640E6AF, 0xE0000}};

  my_decimal decimal_check = {{0x361574B7, 0xF2C8, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok623) {
  my_decimal decimal = {{0xE6BF6481, 0x21096819, 0x97BC72CD, 0x80090000}};

  my_decimal decimal_check = {{0xB264A84A, 0x8BB3A2BC, 0x2, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok624) {
  my_decimal decimal = {{0xE6BF6481, 0x21096819, 0x97BC72CD, 0x90000}};

  my_decimal decimal_check = {{0xB264A84A, 0x8BB3A2BC, 0x2, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok625) {
  my_decimal decimal = {{0xCEC8B484, 0x3257F0F7, 0x7E21738B, 0x80090000}};

  my_decimal decimal_check = {{0xB1511F78, 0x1DBA2334, 0x2, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok626) {
  my_decimal decimal = {{0xCEC8B484, 0x3257F0F7, 0x7E21738B, 0x90000}};

  my_decimal decimal_check = {{0xB1511F78, 0x1DBA2334, 0x2, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok627) {
  my_decimal decimal = {{0x93849660, 0xF437B63C, 0x32779CDC, 0x800B0000}};

  my_decimal decimal_check = {{0xF82362D6, 0x22AE4A4, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok628) {
  my_decimal decimal = {{0x93849660, 0xF437B63C, 0x32779CDC, 0xB0000}};

  my_decimal decimal_check = {{0xF82362D6, 0x22AE4A4, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok629) {
  my_decimal decimal = {{0x29BD0E86, 0x789AE890, 0xF37BF67A, 0x80000000}};

  my_decimal decimal_check = {
      {0x29BD0E86, 0x789AE890, 0xF37BF67A, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok630) {
  my_decimal decimal = {{0x29BD0E86, 0x789AE890, 0xF37BF67A, 0x0}};

  my_decimal decimal_check = {{0x29BD0E86, 0x789AE890, 0xF37BF67A, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok631) {
  my_decimal decimal = {{0x3E55BD95, 0xA7D45A16, 0x9EC9011, 0x80030000}};

  my_decimal decimal_check = {{0xC8411C17, 0x52580535, 0x28A62, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok632) {
  my_decimal decimal = {{0x3E55BD95, 0xA7D45A16, 0x9EC9011, 0x30000}};

  my_decimal decimal_check = {{0xC8411C17, 0x52580535, 0x28A62, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok633) {
  my_decimal decimal = {{0xD8053E58, 0x7D420262, 0xFFCBE3F, 0x801C0000}};

  my_decimal decimal_check = {{0x0, 0x0, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok634) {
  my_decimal decimal = {{0xD8053E58, 0x7D420262, 0xFFCBE3F, 0x1C0000}};

  my_decimal decimal_check = {{0x0, 0x0, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok635) {
  my_decimal decimal = {{0xD8415F6E, 0xF0B28E5E, 0x85F6D222, 0x150000}};

  my_decimal decimal_check = {{0x278A0B6, 0x0, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok636) {
  my_decimal decimal = {{0xD8415F6E, 0xF0B28E5E, 0x85F6D222, 0x80150000}};

  my_decimal decimal_check = {{0x278A0B6, 0x0, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok637) {
  my_decimal decimal = {{0x826662E9, 0xC6E7BE7D, 0xA05159A7, 0xC0000}};

  my_decimal decimal_check = {{0x18A800B9, 0xB04571, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok638) {
  my_decimal decimal = {{0x826662E9, 0xC6E7BE7D, 0xA05159A7, 0x800C0000}};

  my_decimal decimal_check = {{0x18A800B9, 0xB04571, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok639) {
  my_decimal decimal = {{0x1C33A6BC, 0x2FCAA2A1, 0x51D625B0, 0x140000}};

  my_decimal decimal_check = {{0xF189EBA, 0x0, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok640) {
  my_decimal decimal = {{0x1C33A6BC, 0x2FCAA2A1, 0x51D625B0, 0x80140000}};

  my_decimal decimal_check = {{0xF189EBA, 0x0, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok641) {
  my_decimal decimal = {{0xE1075CBF, 0x83C69196, 0xB2A69DCA, 0xD0000}};

  my_decimal decimal_check = {{0x1FF368C, 0x13A493, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok642) {
  my_decimal decimal = {{0xE1075CBF, 0x83C69196, 0xB2A69DCA, 0x800D0000}};

  my_decimal decimal_check = {{0x1FF368C, 0x13A493, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok643) {
  my_decimal decimal = {{0x21D50F21, 0x99AB7C96, 0xBAC78E9E, 0x801C0000}};

  my_decimal decimal_check = {{0x5, 0x0, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok644) {
  my_decimal decimal = {{0x21D50F21, 0x99AB7C96, 0xBAC78E9E, 0x1C0000}};

  my_decimal decimal_check = {{0x5, 0x0, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok645) {
  my_decimal decimal = {{0xA520BE02, 0x853E1C8D, 0xEAA33BF8, 0x100000}};

  my_decimal decimal_check = {{0xBE09C338, 0x69A, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok646) {
  my_decimal decimal = {{0xA520BE02, 0x853E1C8D, 0xEAA33BF8, 0x80100000}};

  my_decimal decimal_check = {{0xBE09C338, 0x69A, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok647) {
  my_decimal decimal = {{0x181A7DE, 0x5AF79424, 0x80172A0, 0x20000}};

  my_decimal decimal_check = {{0x3D747F1E, 0x1563C17B, 0x147E96, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok648) {
  my_decimal decimal = {{0x181A7DE, 0x5AF79424, 0x80172A0, 0x80020000}};

  my_decimal decimal_check = {{0x3D747F1E, 0x1563C17B, 0x147E96, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok649) {
  my_decimal decimal = {{0x80AADE5, 0x194A5D29, 0x342C88FA, 0x800C0000}};

  my_decimal decimal_check = {{0x658DCE27, 0x395DAA, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok650) {
  my_decimal decimal = {{0x80AADE5, 0x194A5D29, 0x342C88FA, 0xC0000}};

  my_decimal decimal_check = {{0x658DCE27, 0x395DAA, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok651) {
  my_decimal decimal = {{0xDE206D9B, 0x932B1202, 0x33F6991A, 0x30000}};

  my_decimal decimal_check = {{0xF265EBA1, 0x110B0D12, 0xD4D77, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok652) {
  my_decimal decimal = {{0xDE206D9B, 0x932B1202, 0x33F6991A, 0x80030000}};

  my_decimal decimal_check = {{0xF265EBA1, 0x110B0D12, 0xD4D77, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok653) {
  my_decimal decimal = {{0x6974E296, 0xB7161497, 0x98BF3BA6, 0x800F0000}};

  my_decimal decimal_check = {{0x94E3D6A5, 0x2AFE, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok654) {
  my_decimal decimal = {{0x6974E296, 0xB7161497, 0x98BF3BA6, 0xF0000}};

  my_decimal decimal_check = {{0x94E3D6A5, 0x2AFE, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok655) {
  my_decimal decimal = {{0xF0FA2056, 0x483F7913, 0xACFC175E, 0x800E0000}};

  my_decimal decimal_check = {{0xA2B83AA1, 0x1E6E8, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok656) {
  my_decimal decimal = {{0xF0FA2056, 0x483F7913, 0xACFC175E, 0xE0000}};

  my_decimal decimal_check = {{0xA2B83AA1, 0x1E6E8, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok657) {
  my_decimal decimal = {{0xD3D886A2, 0x30680690, 0xE81C7418, 0x150000}};

  my_decimal decimal_check = {{0x4481D28, 0x0, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok658) {
  my_decimal decimal = {{0xD3D886A2, 0x30680690, 0xE81C7418, 0x80150000}};

  my_decimal decimal_check = {{0x4481D28, 0x0, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok659) {
  my_decimal decimal = {{0xA241800C, 0xCA321138, 0x954901E8, 0xC0000}};

  my_decimal decimal_check = {{0x48C7101D, 0xA4240B, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok660) {
  my_decimal decimal = {{0xA241800C, 0xCA321138, 0x954901E8, 0x800C0000}};

  my_decimal decimal_check = {{0x48C7101D, 0xA4240B, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok661) {
  my_decimal decimal = {{0x7F8E3786, 0x289F2726, 0xC9982A4A, 0x801B0000}};

  my_decimal decimal_check = {{0x3E, 0x0, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok662) {
  my_decimal decimal = {{0x7F8E3786, 0x289F2726, 0xC9982A4A, 0x1B0000}};

  my_decimal decimal_check = {{0x3E, 0x0, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok663) {
  my_decimal decimal = {{0xB3231627, 0x2B3B9762, 0x1FB13E98, 0x0}};

  my_decimal decimal_check = {{0xB3231627, 0x2B3B9762, 0x1FB13E98, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok664) {
  my_decimal decimal = {{0xB3231627, 0x2B3B9762, 0x1FB13E98, 0x80000000}};

  my_decimal decimal_check = {
      {0xB3231627, 0x2B3B9762, 0x1FB13E98, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok665) {
  my_decimal decimal = {{0x8BFA0F9E, 0xF4FEA973, 0x5C54FD67, 0x1A0000}};

  my_decimal decimal_check = {{0x11D, 0x0, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok666) {
  my_decimal decimal = {{0x8BFA0F9E, 0xF4FEA973, 0x5C54FD67, 0x801A0000}};

  my_decimal decimal_check = {{0x11D, 0x0, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok667) {
  my_decimal decimal = {{0xA8B1DD68, 0xF858C391, 0x5F1B09D2, 0x80140000}};

  my_decimal decimal_check = {{0x118B3C61, 0x0, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok668) {
  my_decimal decimal = {{0xA8B1DD68, 0xF858C391, 0x5F1B09D2, 0x140000}};

  my_decimal decimal_check = {{0x118B3C61, 0x0, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok669) {
  my_decimal decimal = {{0xCE3BC3D, 0xE49077A5, 0x406D23C5, 0x80020000}};

  my_decimal decimal_check = {{0x6916C1E1, 0xF15ECB7, 0xA4EE70, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok670) {
  my_decimal decimal = {{0xCE3BC3D, 0xE49077A5, 0x406D23C5, 0x20000}};

  my_decimal decimal_check = {{0x6916C1E1, 0xF15ECB7, 0xA4EE70, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok671) {
  my_decimal decimal = {{0xCE0004B2, 0xFE2AB6BB, 0x508AFE45, 0x30000}};

  my_decimal decimal_check = {{0x17808313, 0x578CD7BC, 0x149E76, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok672) {
  my_decimal decimal = {{0xCE0004B2, 0xFE2AB6BB, 0x508AFE45, 0x80030000}};

  my_decimal decimal_check = {{0x17808313, 0x578CD7BC, 0x149E76, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok673) {
  my_decimal decimal = {{0x9555C8F0, 0xE0B0D013, 0xF10A3BA0, 0x80030000}};

  my_decimal decimal_check = {{0x4480577F, 0xAE4E0035, 0x3DB4CB, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok674) {
  my_decimal decimal = {{0x9555C8F0, 0xE0B0D013, 0xF10A3BA0, 0x30000}};

  my_decimal decimal_check = {{0x4480577F, 0xAE4E0035, 0x3DB4CB, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok675) {
  my_decimal decimal = {{0x2FEEE3CD, 0x4D7246A1, 0x8338B7AA, 0x800F0000}};

  my_decimal decimal_check = {{0x82656650, 0x24EF, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok676) {
  my_decimal decimal = {{0x2FEEE3CD, 0x4D7246A1, 0x8338B7AA, 0xF0000}};

  my_decimal decimal_check = {{0x82656650, 0x24EF, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok677) {
  my_decimal decimal = {{0x41151F02, 0xF5D2C738, 0x5416B21C, 0x801C0000}};

  my_decimal decimal_check = {{0x2, 0x0, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok678) {
  my_decimal decimal = {{0x41151F02, 0xF5D2C738, 0x5416B21C, 0x1C0000}};

  my_decimal decimal_check = {{0x2, 0x0, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok679) {
  my_decimal decimal = {{0x86A6AB79, 0xE0F35639, 0x851A9780, 0xB0000}};

  my_decimal decimal_check = {{0x5CBC1E0B, 0x5B77E19, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok680) {
  my_decimal decimal = {{0x86A6AB79, 0xE0F35639, 0x851A9780, 0x800B0000}};

  my_decimal decimal_check = {{0x5CBC1E0B, 0x5B77E19, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok681) {
  my_decimal decimal = {{0x547899BF, 0x61506CE1, 0xBACA4FC7, 0x801B0000}};

  my_decimal decimal_check = {{0x39, 0x0, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok682) {
  my_decimal decimal = {{0x547899BF, 0x61506CE1, 0xBACA4FC7, 0x1B0000}};

  my_decimal decimal_check = {{0x39, 0x0, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok683) {
  my_decimal decimal = {{0x98FE3F6D, 0xAA12CDCB, 0xCB6815FF, 0x80150000}};

  my_decimal decimal_check = {{0x3C08F79, 0x0, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok684) {
  my_decimal decimal = {{0x98FE3F6D, 0xAA12CDCB, 0xCB6815FF, 0x150000}};

  my_decimal decimal_check = {{0x3C08F79, 0x0, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok685) {
  my_decimal decimal = {{0xAE60C07F, 0x9A40295B, 0x27D2F744, 0x80120000}};

  my_decimal decimal_check = {{0xDE9FED37, 0x2, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok686) {
  my_decimal decimal = {{0xAE60C07F, 0x9A40295B, 0x27D2F744, 0x120000}};

  my_decimal decimal_check = {{0xDE9FED37, 0x2, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok687) {
  my_decimal decimal = {{0x36D8B134, 0x2A8A075E, 0xEA814492, 0x800D0000}};

  my_decimal decimal_check = {{0x44638D49, 0x19C8BA, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok688) {
  my_decimal decimal = {{0x36D8B134, 0x2A8A075E, 0xEA814492, 0xD0000}};

  my_decimal decimal_check = {{0x44638D49, 0x19C8BA, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok689) {
  my_decimal decimal = {{0x9527ECA3, 0x6CB6E55B, 0x27D50173, 0x80070000}};

  my_decimal decimal_check = {{0x89008808, 0xD3BC95FD, 0x42, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok690) {
  my_decimal decimal = {{0x9527ECA3, 0x6CB6E55B, 0x27D50173, 0x70000}};

  my_decimal decimal_check = {{0x89008808, 0xD3BC95FD, 0x42, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok691) {
  my_decimal decimal = {{0xF7451F83, 0x4E979D4A, 0x71A7727A, 0x800F0000}};

  my_decimal decimal_check = {{0xA3EBD110, 0x1FFD, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok692) {
  my_decimal decimal = {{0xF7451F83, 0x4E979D4A, 0x71A7727A, 0xF0000}};

  my_decimal decimal_check = {{0xA3EBD110, 0x1FFD, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok693) {
  my_decimal decimal = {{0x3ED9B58B, 0x1E7C60BB, 0x2BFBB214, 0x801B0000}};

  my_decimal decimal_check = {{0xD, 0x0, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok694) {
  my_decimal decimal = {{0x3ED9B58B, 0x1E7C60BB, 0x2BFBB214, 0x1B0000}};

  my_decimal decimal_check = {{0xD, 0x0, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok695) {
  my_decimal decimal = {{0x4155D537, 0xA999C35D, 0x415D26C6, 0x800B0000}};

  my_decimal decimal_check = {{0x332CC94A, 0x2CEAEF2, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok696) {
  my_decimal decimal = {{0x4155D537, 0xA999C35D, 0x415D26C6, 0xB0000}};

  my_decimal decimal_check = {{0x332CC94A, 0x2CEAEF2, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok697) {
  my_decimal decimal = {{0x1C89A3E6, 0x1233D892, 0x706DE84D, 0x80180000}};

  my_decimal decimal_check = {{0x87EB, 0x0, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok698) {
  my_decimal decimal = {{0x1C89A3E6, 0x1233D892, 0x706DE84D, 0x180000}};

  my_decimal decimal_check = {{0x87EB, 0x0, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok699) {
  my_decimal decimal = {{0xF0742AB5, 0x548F8762, 0x3E0A8D05, 0x80010000}};

  my_decimal decimal_check = {{0xE4D86AAB, 0x55418D89, 0x634414D, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok700) {
  my_decimal decimal = {{0xF0742AB5, 0x548F8762, 0x3E0A8D05, 0x10000}};

  my_decimal decimal_check = {{0xE4D86AAB, 0x55418D89, 0x634414D, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok701) {
  my_decimal decimal = {{0xD25C7DD5, 0x58A7890, 0x9CE06852, 0x80130000}};

  my_decimal decimal_check = {{0x2162E03B, 0x1, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok702) {
  my_decimal decimal = {{0xD25C7DD5, 0x58A7890, 0x9CE06852, 0x130000}};

  my_decimal decimal_check = {{0x2162E03B, 0x1, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok703) {
  my_decimal decimal = {{0xE2B3131E, 0xC587AF42, 0x812772FA, 0x90000}};

  my_decimal decimal_check = {{0x5DA5F54B, 0x2AB66EC8, 0x2, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok704) {
  my_decimal decimal = {{0xE2B3131E, 0xC587AF42, 0x812772FA, 0x80090000}};

  my_decimal decimal_check = {{0x5DA5F54B, 0x2AB66EC8, 0x2, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok705) {
  my_decimal decimal = {{0xC8654667, 0xD2B33151, 0x8A80E154, 0x170000}};

  my_decimal decimal_check = {{0x68A67, 0x0, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok706) {
  my_decimal decimal = {{0xC8654667, 0xD2B33151, 0x8A80E154, 0x80170000}};

  my_decimal decimal_check = {{0x68A67, 0x0, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok707) {
  my_decimal decimal = {{0x86321886, 0xB2A8516C, 0xB11BB332, 0x180000}};

  my_decimal decimal_check = {{0xD61C, 0x0, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok708) {
  my_decimal decimal = {{0x86321886, 0xB2A8516C, 0xB11BB332, 0x80180000}};

  my_decimal decimal_check = {{0xD61C, 0x0, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok709) {
  my_decimal decimal = {{0xBCBCBE29, 0x7C4286CA, 0x474948DA, 0x160000}};

  my_decimal decimal_check = {{0x21A9FB, 0x0, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok710) {
  my_decimal decimal = {{0xBCBCBE29, 0x7C4286CA, 0x474948DA, 0x80160000}};

  my_decimal decimal_check = {{0x21A9FB, 0x0, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok711) {
  my_decimal decimal = {{0x3B2ADF78, 0x1888FFCF, 0x1451755C, 0x60000}};

  my_decimal decimal_check = {{0x31C74B32, 0xE1FDE059, 0x154, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok712) {
  my_decimal decimal = {{0x3B2ADF78, 0x1888FFCF, 0x1451755C, 0x80060000}};

  my_decimal decimal_check = {{0x31C74B32, 0xE1FDE059, 0x154, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok713) {
  my_decimal decimal = {{0x5F6C656, 0xBE29140, 0x1B4EEC04, 0x150000}};

  my_decimal decimal_check = {{0x80F5B2, 0x0, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok714) {
  my_decimal decimal = {{0x5F6C656, 0xBE29140, 0x1B4EEC04, 0x80150000}};

  my_decimal decimal_check = {{0x80F5B2, 0x0, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok715) {
  my_decimal decimal = {{0x672FE2D3, 0x9DD1ACC1, 0xFB16DD98, 0x190000}};

  my_decimal decimal_check = {{0x1E5A, 0x0, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok716) {
  my_decimal decimal = {{0x672FE2D3, 0x9DD1ACC1, 0xFB16DD98, 0x80190000}};

  my_decimal decimal_check = {{0x1E5A, 0x0, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok717) {
  my_decimal decimal = {{0xEBC01C17, 0x3C92064E, 0x6A3D4FC2, 0x801C0000}};

  my_decimal decimal_check = {{0x3, 0x0, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok718) {
  my_decimal decimal = {{0xEBC01C17, 0x3C92064E, 0x6A3D4FC2, 0x1C0000}};

  my_decimal decimal_check = {{0x3, 0x0, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok719) {
  my_decimal decimal = {{0x6ECAF8B9, 0xDBF8B808, 0xC5FC3D61, 0x80110000}};

  my_decimal decimal_check = {{0xA9D7FF34, 0x8E, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok720) {
  my_decimal decimal = {{0x6ECAF8B9, 0xDBF8B808, 0xC5FC3D61, 0x110000}};

  my_decimal decimal_check = {{0xA9D7FF34, 0x8E, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok721) {
  my_decimal decimal = {{0x5A68B182, 0x15709A71, 0x54A1574B, 0x40000}};

  my_decimal decimal_check = {{0xB4AB11D5, 0xFA8CA1CE, 0x22AA1, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok722) {
  my_decimal decimal = {{0x5A68B182, 0x15709A71, 0x54A1574B, 0x80040000}};

  my_decimal decimal_check = {{0xB4AB11D5, 0xFA8CA1CE, 0x22AA1, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok723) {
  my_decimal decimal = {{0xDC2CA5CA, 0x276D60A8, 0xFE5D500, 0x80050000}};

  my_decimal decimal_check = {{0x8D2BBC48, 0x3482D862, 0xA6B, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok724) {
  my_decimal decimal = {{0xDC2CA5CA, 0x276D60A8, 0xFE5D500, 0x50000}};

  my_decimal decimal_check = {{0x8D2BBC48, 0x3482D862, 0xA6B, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok725) {
  my_decimal decimal = {{0xE2BE921, 0x7A8CEBD7, 0x1A1A612A, 0x40000}};

  my_decimal decimal_check = {{0xFC7E8503, 0xA4849225, 0xAB11, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok726) {
  my_decimal decimal = {{0xE2BE921, 0x7A8CEBD7, 0x1A1A612A, 0x80040000}};

  my_decimal decimal_check = {{0xFC7E8503, 0xA4849225, 0xAB11, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok727) {
  my_decimal decimal = {{0xCA5A0248, 0xB388AE53, 0x2A3FA330, 0x60000}};

  my_decimal decimal_check = {{0x94DEBE3D, 0xD0492F23, 0x2C4, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok728) {
  my_decimal decimal = {{0xCA5A0248, 0xB388AE53, 0x2A3FA330, 0x80060000}};

  my_decimal decimal_check = {{0x94DEBE3D, 0xD0492F23, 0x2C4, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok729) {
  my_decimal decimal = {{0xBE4CC6F4, 0x98196B31, 0x9DF7B9E, 0xD0000}};

  my_decimal decimal_check = {{0x5197DC77, 0x115E6, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok730) {
  my_decimal decimal = {{0xBE4CC6F4, 0x98196B31, 0x9DF7B9E, 0x800D0000}};

  my_decimal decimal_check = {{0x5197DC77, 0x115E6, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok731) {
  my_decimal decimal = {{0x674C8700, 0x5C829A58, 0x1982BC52, 0x100000}};

  my_decimal decimal_check = {{0xD2E8E194, 0xB7, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok732) {
  my_decimal decimal = {{0x674C8700, 0x5C829A58, 0x1982BC52, 0x80100000}};

  my_decimal decimal_check = {{0xD2E8E194, 0xB7, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok733) {
  my_decimal decimal = {{0x94B0177A, 0x49E87C14, 0xA857318A, 0x1A0000}};

  my_decimal decimal_check = {{0x208, 0x0, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok734) {
  my_decimal decimal = {{0x94B0177A, 0x49E87C14, 0xA857318A, 0x801A0000}};

  my_decimal decimal_check = {{0x208, 0x0, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok735) {
  my_decimal decimal = {{0x57EC56B, 0xDF610C3E, 0x113D8B3F, 0x0}};

  my_decimal decimal_check = {{0x57EC56B, 0xDF610C3E, 0x113D8B3F, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok736) {
  my_decimal decimal = {{0x57EC56B, 0xDF610C3E, 0x113D8B3F, 0x80000000}};

  my_decimal decimal_check = {{0x57EC56B, 0xDF610C3E, 0x113D8B3F, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok737) {
  my_decimal decimal = {{0x735A0D2A, 0xDDF74292, 0xAA40B4B2, 0x80100000}};

  my_decimal decimal_check = {{0xCCE77134, 0x4CA, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok738) {
  my_decimal decimal = {{0x735A0D2A, 0xDDF74292, 0xAA40B4B2, 0x100000}};

  my_decimal decimal_check = {{0xCCE77134, 0x4CA, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok739) {
  my_decimal decimal = {{0x80FB6C46, 0x95AED177, 0xA2C1DED9, 0x180000}};

  my_decimal decimal_check = {{0xC4C2, 0x0, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok740) {
  my_decimal decimal = {{0x80FB6C46, 0x95AED177, 0xA2C1DED9, 0x80180000}};

  my_decimal decimal_check = {{0xC4C2, 0x0, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok741) {
  my_decimal decimal = {{0xB9108000, 0xA16D998A, 0x80A07704, 0x800F0000}};

  my_decimal decimal_check = {{0x89F50425, 0x2434, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok742) {
  my_decimal decimal = {{0xB9108000, 0xA16D998A, 0x80A07704, 0xF0000}};

  my_decimal decimal_check = {{0x89F50425, 0x2434, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok743) {
  my_decimal decimal = {{0x30CB0F58, 0x86E539AD, 0xE065EA7B, 0x80130000}};

  my_decimal decimal_check = {{0x9DF102CE, 0x1, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok744) {
  my_decimal decimal = {{0x30CB0F58, 0x86E539AD, 0xE065EA7B, 0x130000}};

  my_decimal decimal_check = {{0x9DF102CE, 0x1, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok745) {
  my_decimal decimal = {{0xBF6626DF, 0xA069D1BD, 0x9D956782, 0x190000}};

  my_decimal decimal_check = {{0x130C, 0x0, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok746) {
  my_decimal decimal = {{0xBF6626DF, 0xA069D1BD, 0x9D956782, 0x80190000}};

  my_decimal decimal_check = {{0x130C, 0x0, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok747) {
  my_decimal decimal = {{0x8F2D002B, 0xEF2BBB83, 0x7C2D06CB, 0xF0000}};

  my_decimal decimal_check = {{0xD0C51B6B, 0x22F3, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok748) {
  my_decimal decimal = {{0x8F2D002B, 0xEF2BBB83, 0x7C2D06CB, 0x800F0000}};

  my_decimal decimal_check = {{0xD0C51B6B, 0x22F3, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok749) {
  my_decimal decimal = {{0xB901A1E0, 0x2A0DBDA5, 0x541A13EE, 0x80140000}};

  my_decimal decimal_check = {{0xF83992E, 0x0, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok750) {
  my_decimal decimal = {{0xB901A1E0, 0x2A0DBDA5, 0x541A13EE, 0x140000}};

  my_decimal decimal_check = {{0xF83992E, 0x0, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok751) {
  my_decimal decimal = {{0x3C29F2DF, 0xB645C2C8, 0xDE8A1490, 0x80070000}};

  my_decimal decimal_check = {{0x31C1BC5C, 0x5BEF3029, 0x175, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok752) {
  my_decimal decimal = {{0x3C29F2DF, 0xB645C2C8, 0xDE8A1490, 0x70000}};

  my_decimal decimal_check = {{0x31C1BC5C, 0x5BEF3029, 0x175, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok753) {
  my_decimal decimal = {{0x16632459, 0x49565B09, 0x7AFF1E43, 0x801A0000}};

  my_decimal decimal_check = {{0x17C, 0x0, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok754) {
  my_decimal decimal = {{0x16632459, 0x49565B09, 0x7AFF1E43, 0x1A0000}};

  my_decimal decimal_check = {{0x17C, 0x0, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok755) {
  my_decimal decimal = {{0xC65BBD62, 0x14855E29, 0xA2FF9942, 0x80140000}};

  my_decimal decimal_check = {{0x1E116222, 0x0, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok756) {
  my_decimal decimal = {{0xC65BBD62, 0x14855E29, 0xA2FF9942, 0x140000}};

  my_decimal decimal_check = {{0x1E116222, 0x0, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok757) {
  my_decimal decimal = {{0xA26B5019, 0x3B5615EF, 0x97E78960, 0x180000}};

  my_decimal decimal_check = {{0xB7A4, 0x0, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok758) {
  my_decimal decimal = {{0xA26B5019, 0x3B5615EF, 0x97E78960, 0x80180000}};

  my_decimal decimal_check = {{0xB7A4, 0x0, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok759) {
  my_decimal decimal = {{0x88F5E715, 0x2CDFC557, 0x63F011D0, 0xE0000}};

  my_decimal decimal_check = {{0xC0FF91F7, 0x1194C, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok760) {
  my_decimal decimal = {{0x88F5E715, 0x2CDFC557, 0x63F011D0, 0x800E0000}};

  my_decimal decimal_check = {{0xC0FF91F7, 0x1194C, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok761) {
  my_decimal decimal = {{0x1696555A, 0x801FC3C6, 0x46172DB, 0x80170000}};

  my_decimal decimal_check = {{0x34F5, 0x0, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok762) {
  my_decimal decimal = {{0x1696555A, 0x801FC3C6, 0x46172DB, 0x170000}};

  my_decimal decimal_check = {{0x34F5, 0x0, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok763) {
  my_decimal decimal = {{0xFEDF687E, 0x4A8BFDB7, 0xBBBE8D78, 0x20000}};

  my_decimal decimal_check = {{0x7ADE64E2, 0x7BA01EB2, 0x1E0A022, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok764) {
  my_decimal decimal = {{0xFEDF687E, 0x4A8BFDB7, 0xBBBE8D78, 0x80020000}};

  my_decimal decimal_check = {{0x7ADE64E2, 0x7BA01EB2, 0x1E0A022, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok765) {
  my_decimal decimal = {{0x1EDDFF88, 0xAC5A9D89, 0xD6E02AA9, 0x70000}};

  my_decimal decimal_check = {{0xEC263DB5, 0x8063AD98, 0x168, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok766) {
  my_decimal decimal = {{0x1EDDFF88, 0xAC5A9D89, 0xD6E02AA9, 0x80070000}};

  my_decimal decimal_check = {{0xEC263DB5, 0x8063AD98, 0x168, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok767) {
  my_decimal decimal = {{0xEA8814A, 0x107DB523, 0xC86FA52, 0x30000}};

  my_decimal decimal_check = {{0x3C2CB666, 0x7F812653, 0x334FC, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok768) {
  my_decimal decimal = {{0xEA8814A, 0x107DB523, 0xC86FA52, 0x80030000}};

  my_decimal decimal_check = {{0x3C2CB666, 0x7F812653, 0x334FC, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok769) {
  my_decimal decimal = {{0x8FF748BB, 0x51D59A21, 0x50675A25, 0x80130000}};

  my_decimal decimal_check = {{0x94519538, 0x0, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok770) {
  my_decimal decimal = {{0x8FF748BB, 0x51D59A21, 0x50675A25, 0x130000}};

  my_decimal decimal_check = {{0x94519538, 0x0, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok771) {
  my_decimal decimal = {{0xB8F9DF2B, 0xF4032AC4, 0xCC0337E4, 0x140000}};

  my_decimal decimal_check = {{0x25A238A7, 0x0, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok772) {
  my_decimal decimal = {{0xB8F9DF2B, 0xF4032AC4, 0xCC0337E4, 0x80140000}};

  my_decimal decimal_check = {{0x25A238A7, 0x0, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok773) {
  my_decimal decimal = {{0xBA7DFC3C, 0x84F77204, 0x9E6DC4F1, 0xB0000}};

  my_decimal decimal_check = {{0xB8735FC5, 0x6CDF163, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok774) {
  my_decimal decimal = {{0xBA7DFC3C, 0x84F77204, 0x9E6DC4F1, 0x800B0000}};

  my_decimal decimal_check = {{0xB8735FC5, 0x6CDF163, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok775) {
  my_decimal decimal = {{0x457F5E4, 0xB64E1955, 0xEF17B797, 0x10000}};

  my_decimal decimal_check = {{0x1A08CBCA, 0x2BD49C22, 0x17E8C58F, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok776) {
  my_decimal decimal = {{0x457F5E4, 0xB64E1955, 0xEF17B797, 0x80010000}};

  my_decimal decimal_check = {
      {0x1A08CBCA, 0x2BD49C22, 0x17E8C58F, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok777) {
  my_decimal decimal = {{0x73316F95, 0x464F3620, 0xE5D55BDF, 0x80080000}};

  my_decimal decimal_check = {{0x6729B543, 0x8F455250, 0x26, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok778) {
  my_decimal decimal = {{0x73316F95, 0x464F3620, 0xE5D55BDF, 0x80000}};

  my_decimal decimal_check = {{0x6729B543, 0x8F455250, 0x26, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok779) {
  my_decimal decimal = {{0x7EF813AE, 0x897520E1, 0xBA12FBE7, 0x800D0000}};

  my_decimal decimal_check = {{0x99EB8106, 0x147585, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok780) {
  my_decimal decimal = {{0x7EF813AE, 0x897520E1, 0xBA12FBE7, 0xD0000}};

  my_decimal decimal_check = {{0x99EB8106, 0x147585, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok781) {
  my_decimal decimal = {{0x3AAB9152, 0xF6D0CC9C, 0x57AC47B0, 0x80100000}};

  my_decimal decimal_check = {{0xC014FD32, 0x277, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok782) {
  my_decimal decimal = {{0x3AAB9152, 0xF6D0CC9C, 0x57AC47B0, 0x100000}};

  my_decimal decimal_check = {{0xC014FD32, 0x277, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok783) {
  my_decimal decimal = {{0xFAB8F741, 0x4C11EAA1, 0x841CFBB5, 0x190000}};

  my_decimal decimal_check = {{0xFF8, 0x0, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok784) {
  my_decimal decimal = {{0xFAB8F741, 0x4C11EAA1, 0x841CFBB5, 0x80190000}};

  my_decimal decimal_check = {{0xFF8, 0x0, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok785) {
  my_decimal decimal = {{0xEBE2DF5E, 0xA51CCC28, 0xB00F2C3D, 0x80080000}};

  my_decimal decimal_check = {{0x1DF8507, 0x89B021E2, 0x1D, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok786) {
  my_decimal decimal = {{0xEBE2DF5E, 0xA51CCC28, 0xB00F2C3D, 0x80000}};

  my_decimal decimal_check = {{0x1DF8507, 0x89B021E2, 0x1D, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok787) {
  my_decimal decimal = {{0x898C2EF3, 0x6C7B5D81, 0xCEF88625, 0x1A0000}};

  my_decimal decimal_check = {{0x280, 0x0, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok788) {
  my_decimal decimal = {{0x898C2EF3, 0x6C7B5D81, 0xCEF88625, 0x801A0000}};

  my_decimal decimal_check = {{0x280, 0x0, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok789) {
  my_decimal decimal = {{0x61304FA3, 0x5980AA25, 0x14BE7EF5, 0x80170000}};

  my_decimal decimal_check = {{0xFAC7, 0x0, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok790) {
  my_decimal decimal = {{0x61304FA3, 0x5980AA25, 0x14BE7EF5, 0x170000}};

  my_decimal decimal_check = {{0xFAC7, 0x0, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok791) {
  my_decimal decimal = {{0x5931FC87, 0x67E7A33C, 0xE9FDE345, 0x40000}};

  my_decimal decimal_check = {{0xBF996D01, 0x3016E60, 0x5FD7D, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok792) {
  my_decimal decimal = {{0x5931FC87, 0x67E7A33C, 0xE9FDE345, 0x80040000}};

  my_decimal decimal_check = {{0xBF996D01, 0x3016E60, 0x5FD7D, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok793) {
  my_decimal decimal = {{0x7A56A9B3, 0x3ABE4E20, 0x6DE3C68E, 0x20000}};

  my_decimal decimal_check = {{0xD8436D37, 0x7658F16B, 0x1195158, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok794) {
  my_decimal decimal = {{0x7A56A9B3, 0x3ABE4E20, 0x6DE3C68E, 0x80020000}};

  my_decimal decimal_check = {{0xD8436D37, 0x7658F16B, 0x1195158, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok795) {
  my_decimal decimal = {{0xE7BC1D05, 0x407CCB3A, 0xFDFA310C, 0xD0000}};

  my_decimal decimal_check = {{0x657D8418, 0x1BECD3, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok796) {
  my_decimal decimal = {{0xE7BC1D05, 0x407CCB3A, 0xFDFA310C, 0x800D0000}};

  my_decimal decimal_check = {{0x657D8418, 0x1BECD3, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok797) {
  my_decimal decimal = {{0x64D661FB, 0x74903382, 0x36F0AA7F, 0x150000}};

  my_decimal decimal_check = {{0x1037281, 0x0, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok798) {
  my_decimal decimal = {{0x64D661FB, 0x74903382, 0x36F0AA7F, 0x80150000}};

  my_decimal decimal_check = {{0x1037281, 0x0, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok799) {
  my_decimal decimal = {{0x596AA6D5, 0xA202180B, 0x2A4F58F8, 0x800E0000}};

  my_decimal decimal_check = {{0x8871253D, 0x7717, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok800) {
  my_decimal decimal = {{0x596AA6D5, 0xA202180B, 0x2A4F58F8, 0xE0000}};

  my_decimal decimal_check = {{0x8871253D, 0x7717, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok801) {
  my_decimal decimal = {{0xBDEE3A10, 0xC8029FB, 0xD21B9261, 0x80040000}};

  my_decimal decimal_check = {{0x52A15455, 0x3B025E36, 0x560F6, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok802) {
  my_decimal decimal = {{0xBDEE3A10, 0xC8029FB, 0xD21B9261, 0x40000}};

  my_decimal decimal_check = {{0x52A15455, 0x3B025E36, 0x560F6, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok803) {
  my_decimal decimal = {{0xB352B0D9, 0xB7F76AA2, 0x7CBD3518, 0x80040000}};

  my_decimal decimal_check = {{0xCC44891, 0x77D38EBB, 0x3317D, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok804) {
  my_decimal decimal = {{0xB352B0D9, 0xB7F76AA2, 0x7CBD3518, 0x40000}};

  my_decimal decimal_check = {{0xCC44891, 0x77D38EBB, 0x3317D, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok805) {
  my_decimal decimal = {{0x346A73BC, 0xD3423149, 0xC50166F7, 0x150000}};

  my_decimal decimal_check = {{0x3A25502, 0x0, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok806) {
  my_decimal decimal = {{0x346A73BC, 0xD3423149, 0xC50166F7, 0x80150000}};

  my_decimal decimal_check = {{0x3A25502, 0x0, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok807) {
  my_decimal decimal = {{0x21CA65AD, 0x402B056E, 0xECCCB19E, 0x170000}};

  my_decimal decimal_check = {{0xB2EBB, 0x0, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok808) {
  my_decimal decimal = {{0x21CA65AD, 0x402B056E, 0xECCCB19E, 0x80170000}};

  my_decimal decimal_check = {{0xB2EBB, 0x0, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok809) {
  my_decimal decimal = {{0xC9E6AD18, 0xFF1C617D, 0x19D1FDA8, 0x800F0000}};

  my_decimal decimal_check = {{0x8C09B904, 0x744, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok810) {
  my_decimal decimal = {{0xC9E6AD18, 0xFF1C617D, 0x19D1FDA8, 0xF0000}};

  my_decimal decimal_check = {{0x8C09B904, 0x744, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok811) {
  my_decimal decimal = {{0x9B41E7D4, 0xCBC3B08B, 0x14590574, 0x800D0000}};

  my_decimal decimal_check = {{0xEA504E62, 0x23CBC, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok812) {
  my_decimal decimal = {{0x9B41E7D4, 0xCBC3B08B, 0x14590574, 0xD0000}};

  my_decimal decimal_check = {{0xEA504E62, 0x23CBC, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok813) {
  my_decimal decimal = {{0x64365EDD, 0xA98D0464, 0x4C71727C, 0x800A0000}};

  my_decimal decimal_check = {{0xE652472F, 0x20D50379, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok814) {
  my_decimal decimal = {{0x64365EDD, 0xA98D0464, 0x4C71727C, 0xA0000}};

  my_decimal decimal_check = {{0xE652472F, 0x20D50379, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok815) {
  my_decimal decimal = {{0xF29E76C4, 0xFCCF7397, 0x33500B43, 0x170000}};

  my_decimal decimal_check = {{0x26C55, 0x0, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok816) {
  my_decimal decimal = {{0xF29E76C4, 0xFCCF7397, 0x33500B43, 0x80170000}};

  my_decimal decimal_check = {{0x26C55, 0x0, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok817) {
  my_decimal decimal = {{0xFC4514EE, 0xA6526D5B, 0x362143EC, 0x800E0000}};

  my_decimal decimal_check = {{0xBBFEFDDA, 0x985C, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok818) {
  my_decimal decimal = {{0xFC4514EE, 0xA6526D5B, 0x362143EC, 0xE0000}};

  my_decimal decimal_check = {{0xBBFEFDDA, 0x985C, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok819) {
  my_decimal decimal = {{0x42DFD49C, 0x8AC2B989, 0x1F64BCDC, 0x80010000}};

  my_decimal decimal_check = {{0x537CC876, 0x7446AC27, 0x323AC7C, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok820) {
  my_decimal decimal = {{0x42DFD49C, 0x8AC2B989, 0x1F64BCDC, 0x10000}};

  my_decimal decimal_check = {{0x537CC876, 0x7446AC27, 0x323AC7C, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok821) {
  my_decimal decimal = {{0x7B14DCC9, 0x672DB47A, 0xFE165EF1, 0x800E0000}};

  my_decimal decimal_check = {{0x41DBD00A, 0x2CB31, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok822) {
  my_decimal decimal = {{0x7B14DCC9, 0x672DB47A, 0xFE165EF1, 0xE0000}};

  my_decimal decimal_check = {{0x41DBD00A, 0x2CB31, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok823) {
  my_decimal decimal = {{0x488F2803, 0xD882C783, 0x4EDF49AE, 0x170000}};

  my_decimal decimal_check = {{0x3B981, 0x0, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok824) {
  my_decimal decimal = {{0x488F2803, 0xD882C783, 0x4EDF49AE, 0x80170000}};

  my_decimal decimal_check = {{0x3B981, 0x0, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok825) {
  my_decimal decimal = {{0x44D745A6, 0x642CBC68, 0x7269ECF9, 0x180000}};

  my_decimal decimal_check = {{0x8A51, 0x0, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok826) {
  my_decimal decimal = {{0x44D745A6, 0x642CBC68, 0x7269ECF9, 0x80180000}};

  my_decimal decimal_check = {{0x8A51, 0x0, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok827) {
  my_decimal decimal = {{0x4543DE24, 0x6A54AFD7, 0x4D51B149, 0x20000}};

  my_decimal decimal_check = {{0x85F660F, 0x558B163D, 0xC5EFDA, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok828) {
  my_decimal decimal = {{0x4543DE24, 0x6A54AFD7, 0x4D51B149, 0x80020000}};

  my_decimal decimal_check = {{0x85F660F, 0x558B163D, 0xC5EFDA, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok829) {
  my_decimal decimal = {{0xA53AE848, 0x36B57E3D, 0x752C5262, 0x80120000}};

  my_decimal decimal_check = {{0x717678BA, 0x8, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok830) {
  my_decimal decimal = {{0xA53AE848, 0x36B57E3D, 0x752C5262, 0x120000}};

  my_decimal decimal_check = {{0x717678BA, 0x8, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok831) {
  my_decimal decimal = {{0x3899BBE7, 0x67C139A8, 0x8E3F22D2, 0x160000}};

  my_decimal decimal_check = {{0x432C8F, 0x0, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok832) {
  my_decimal decimal = {{0x3899BBE7, 0x67C139A8, 0x8E3F22D2, 0x80160000}};

  my_decimal decimal_check = {{0x432C8F, 0x0, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok833) {
  my_decimal decimal = {{0x5D05E9C7, 0xF5D32F5F, 0x9359DC1D, 0x1B0000}};

  my_decimal decimal_check = {{0x2D, 0x0, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok834) {
  my_decimal decimal = {{0x5D05E9C7, 0xF5D32F5F, 0x9359DC1D, 0x801B0000}};

  my_decimal decimal_check = {{0x2D, 0x0, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok835) {
  my_decimal decimal = {{0xC71D8543, 0x901ADF12, 0xFA0BA0FD, 0x80070000}};

  my_decimal decimal_check = {{0x10AD15EE, 0x81B14171, 0x1A3, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok836) {
  my_decimal decimal = {{0xC71D8543, 0x901ADF12, 0xFA0BA0FD, 0x70000}};

  my_decimal decimal_check = {{0x10AD15EE, 0x81B14171, 0x1A3, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok837) {
  my_decimal decimal = {{0xACCB6861, 0x5772BE97, 0xBF0D53D9, 0x801C0000}};

  my_decimal decimal_check = {{0x5, 0x0, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok838) {
  my_decimal decimal = {{0xACCB6861, 0x5772BE97, 0xBF0D53D9, 0x1C0000}};

  my_decimal decimal_check = {{0x5, 0x0, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok839) {
  my_decimal decimal = {{0x8AC1155B, 0xFDF19B7, 0xCCFE73A3, 0x1C0000}};

  my_decimal decimal_check = {{0x6, 0x0, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok840) {
  my_decimal decimal = {{0x8AC1155B, 0xFDF19B7, 0xCCFE73A3, 0x801C0000}};

  my_decimal decimal_check = {{0x6, 0x0, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok841) {
  my_decimal decimal = {{0x17C17E76, 0x27C615EF, 0x3A4C3D4D, 0x80070000}};

  my_decimal decimal_check = {{0xE3D35D31, 0xCEB80A09, 0x61, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok842) {
  my_decimal decimal = {{0x17C17E76, 0x27C615EF, 0x3A4C3D4D, 0x70000}};

  my_decimal decimal_check = {{0xE3D35D31, 0xCEB80A09, 0x61, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok843) {
  my_decimal decimal = {{0x47794A5F, 0xD901C5EA, 0xF411E0F7, 0x80070000}};

  my_decimal decimal_check = {{0x14D3A82A, 0x7B329898, 0x199, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok844) {
  my_decimal decimal = {{0x47794A5F, 0xD901C5EA, 0xF411E0F7, 0x70000}};

  my_decimal decimal_check = {{0x14D3A82A, 0x7B329898, 0x199, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok845) {
  my_decimal decimal = {{0x16147FD3, 0x43F6BA66, 0x119E71C6, 0x80080000}};

  my_decimal decimal_check = {{0x3A4734CB, 0xF4BA1CFD, 0x2, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok846) {
  my_decimal decimal = {{0x16147FD3, 0x43F6BA66, 0x119E71C6, 0x80000}};

  my_decimal decimal_check = {{0x3A4734CB, 0xF4BA1CFD, 0x2, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok847) {
  my_decimal decimal = {{0xC2AA2AE9, 0x59F1067, 0x3ED0AAC, 0x80170000}};

  my_decimal decimal_check = {{0x2F76, 0x0, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok848) {
  my_decimal decimal = {{0xC2AA2AE9, 0x59F1067, 0x3ED0AAC, 0x170000}};

  my_decimal decimal_check = {{0x2F76, 0x0, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok849) {
  my_decimal decimal = {{0x96025569, 0xC67B5ECC, 0x219B8978, 0x170000}};

  my_decimal decimal_check = {{0x1964A, 0x0, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok850) {
  my_decimal decimal = {{0x96025569, 0xC67B5ECC, 0x219B8978, 0x80170000}};

  my_decimal decimal_check = {{0x1964A, 0x0, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok851) {
  my_decimal decimal = {{0x23CAF28, 0xC367515C, 0xC7B55ECC, 0x80000000}};

  my_decimal decimal_check = {{0x23CAF28, 0xC367515C, 0xC7B55ECC, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok852) {
  my_decimal decimal = {{0x23CAF28, 0xC367515C, 0xC7B55ECC, 0x0}};

  my_decimal decimal_check = {{0x23CAF28, 0xC367515C, 0xC7B55ECC, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok853) {
  my_decimal decimal = {{0x2734DF2C, 0x3345F96A, 0x27AA647A, 0xB0000}};

  my_decimal decimal_check = {{0xE531BBD3, 0x1B420B9, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok854) {
  my_decimal decimal = {{0x2734DF2C, 0x3345F96A, 0x27AA647A, 0x800B0000}};

  my_decimal decimal_check = {{0xE531BBD3, 0x1B420B9, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok855) {
  my_decimal decimal = {{0x685B1FBF, 0x93D7DEF, 0xD190FBAC, 0x80130000}};

  my_decimal decimal_check = {{0x8294E7F5, 0x1, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok856) {
  my_decimal decimal = {{0x685B1FBF, 0x93D7DEF, 0xD190FBAC, 0x130000}};

  my_decimal decimal_check = {{0x8294E7F5, 0x1, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok857) {
  my_decimal decimal = {{0x26CACE5B, 0xF978BB08, 0x6C2BB582, 0xA0000}};

  my_decimal decimal_check = {{0x6C4D9896, 0x2E757F9B, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok858) {
  my_decimal decimal = {{0x26CACE5B, 0xF978BB08, 0x6C2BB582, 0x800A0000}};

  my_decimal decimal_check = {{0x6C4D9896, 0x2E757F9B, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok859) {
  my_decimal decimal = {{0xEA88C01C, 0xFFCD6876, 0x6A493D48, 0x80160000}};

  my_decimal decimal_check = {{0x323133, 0x0, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok860) {
  my_decimal decimal = {{0xEA88C01C, 0xFFCD6876, 0x6A493D48, 0x160000}};

  my_decimal decimal_check = {{0x323133, 0x0, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok861) {
  my_decimal decimal = {{0xCED51229, 0x1697706, 0xDF8B0002, 0x60000}};

  my_decimal decimal_check = {{0x559FE0FD, 0x6DBD9462, 0xEA6, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok862) {
  my_decimal decimal = {{0xCED51229, 0x1697706, 0xDF8B0002, 0x80060000}};

  my_decimal decimal_check = {{0x559FE0FD, 0x6DBD9462, 0xEA6, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok863) {
  my_decimal decimal = {{0x3B90310D, 0xDDE14A9E, 0xF6A15029, 0x60000}};

  my_decimal decimal_check = {{0x193903E3, 0xC45716AF, 0x1029, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok864) {
  my_decimal decimal = {{0x3B90310D, 0xDDE14A9E, 0xF6A15029, 0x80060000}};

  my_decimal decimal_check = {{0x193903E3, 0xC45716AF, 0x1029, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok865) {
  my_decimal decimal = {{0x9977AD, 0x9BB9B0B7, 0x28396573, 0x90000}};

  my_decimal decimal_check = {{0x65DD3DD1, 0xACC2FAF6, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok866) {
  my_decimal decimal = {{0x9977AD, 0x9BB9B0B7, 0x28396573, 0x80090000}};

  my_decimal decimal_check = {{0x65DD3DD1, 0xACC2FAF6, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok867) {
  my_decimal decimal = {{0x9B575401, 0x8A427AFE, 0xF39E6FB4, 0xE0000}};

  my_decimal decimal_check = {{0xE9851D3D, 0x2ADB9, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok868) {
  my_decimal decimal = {{0x9B575401, 0x8A427AFE, 0xF39E6FB4, 0x800E0000}};

  my_decimal decimal_check = {{0xE9851D3D, 0x2ADB9, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok869) {
  my_decimal decimal = {{0x1D247AE3, 0x958FD6B9, 0xD16462B3, 0x10000}};

  my_decimal decimal_check = {{0xB61D3F7D, 0x288E6245, 0x14F07045, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok870) {
  my_decimal decimal = {{0x1D247AE3, 0x958FD6B9, 0xD16462B3, 0x80010000}};

  my_decimal decimal_check = {
      {0xB61D3F7D, 0x288E6245, 0x14F07045, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok871) {
  my_decimal decimal = {{0x6E6B2532, 0xF640C16B, 0x93BCCCDA, 0x160000}};

  my_decimal decimal_check = {{0x45C45E, 0x0, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok872) {
  my_decimal decimal = {{0x6E6B2532, 0xF640C16B, 0x93BCCCDA, 0x80160000}};

  my_decimal decimal_check = {{0x45C45E, 0x0, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok873) {
  my_decimal decimal = {{0x3F79827B, 0x7C42A335, 0x6F870F87, 0x80170000}};

  my_decimal decimal_check = {{0x54449, 0x0, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok874) {
  my_decimal decimal = {{0x3F79827B, 0x7C42A335, 0x6F870F87, 0x170000}};

  my_decimal decimal_check = {{0x54449, 0x0, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok875) {
  my_decimal decimal = {{0x56871EA6, 0xF31964B3, 0xA2F26A88, 0xF0000}};

  my_decimal decimal_check = {{0x9076F18E, 0x2DDD, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok876) {
  my_decimal decimal = {{0x56871EA6, 0xF31964B3, 0xA2F26A88, 0x800F0000}};

  my_decimal decimal_check = {{0x9076F18E, 0x2DDD, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok877) {
  my_decimal decimal = {{0x1945E545, 0xAD97659B, 0xFE0E6DFE, 0x80000}};

  my_decimal decimal_check = {{0x1769EE09, 0x9FA348B7, 0x2A, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok878) {
  my_decimal decimal = {{0x1945E545, 0xAD97659B, 0xFE0E6DFE, 0x80080000}};

  my_decimal decimal_check = {{0x1769EE09, 0x9FA348B7, 0x2A, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok879) {
  my_decimal decimal = {{0xA0F0151B, 0x448E93EF, 0xE353BD09, 0x80150000}};

  my_decimal decimal_check = {{0x431859A, 0x0, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok880) {
  my_decimal decimal = {{0xA0F0151B, 0x448E93EF, 0xE353BD09, 0x150000}};

  my_decimal decimal_check = {{0x431859A, 0x0, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok881) {
  my_decimal decimal = {{0xF9B86D02, 0x807E0C7F, 0x675F2F62, 0x10000}};

  my_decimal decimal_check = {{0x3292714D, 0xD9A63473, 0xA565189, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok882) {
  my_decimal decimal = {{0xF9B86D02, 0x807E0C7F, 0x675F2F62, 0x80010000}};

  my_decimal decimal_check = {{0x3292714D, 0xD9A63473, 0xA565189, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok883) {
  my_decimal decimal = {{0x9E17DC3C, 0x1D4B451D, 0x842C0212, 0x800F0000}};

  my_decimal decimal_check = {{0xFD55B125, 0x2533, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok884) {
  my_decimal decimal = {{0x9E17DC3C, 0x1D4B451D, 0x842C0212, 0xF0000}};

  my_decimal decimal_check = {{0xFD55B125, 0x2533, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok885) {
  my_decimal decimal = {{0xB2EE0F16, 0x7D18867, 0x6DD6B298, 0x80090000}};

  my_decimal decimal_check = {{0x2FA8E6CE, 0xD7C0E301, 0x1, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok886) {
  my_decimal decimal = {{0xB2EE0F16, 0x7D18867, 0x6DD6B298, 0x90000}};

  my_decimal decimal_check = {{0x2FA8E6CE, 0xD7C0E301, 0x1, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok887) {
  my_decimal decimal = {{0xEB7CC984, 0x5615EC52, 0x8FC0862C, 0x10000}};

  my_decimal decimal_check = {{0xE459475A, 0xD56897A1, 0xE600D6A, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok888) {
  my_decimal decimal = {{0xEB7CC984, 0x5615EC52, 0x8FC0862C, 0x80010000}};

  my_decimal decimal_check = {{0xE459475A, 0xD56897A1, 0xE600D6A, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok889) {
  my_decimal decimal = {{0x1AC06DED, 0xC2B3FE1E, 0xCDD4CFE4, 0xE0000}};

  my_decimal decimal_check = {{0x149E7142, 0x2435D, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok890) {
  my_decimal decimal = {{0x1AC06DED, 0xC2B3FE1E, 0xCDD4CFE4, 0x800E0000}};

  my_decimal decimal_check = {{0x149E7142, 0x2435D, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok891) {
  my_decimal decimal = {{0x3B6DFED8, 0x2D6FE049, 0xBACCC0D6, 0x800F0000}};

  my_decimal decimal_check = {{0x586CF2CD, 0x3494, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok892) {
  my_decimal decimal = {{0x3B6DFED8, 0x2D6FE049, 0xBACCC0D6, 0xF0000}};

  my_decimal decimal_check = {{0x586CF2CD, 0x3494, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok893) {
  my_decimal decimal = {{0xA5DB09F1, 0x82047880, 0x252758CC, 0x80150000}};

  my_decimal decimal_check = {{0xAF7410, 0x0, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok894) {
  my_decimal decimal = {{0xA5DB09F1, 0x82047880, 0x252758CC, 0x150000}};

  my_decimal decimal_check = {{0xAF7410, 0x0, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok895) {
  my_decimal decimal = {{0x4947D0C1, 0xF2CB3791, 0x2D919F82, 0x80120000}};

  my_decimal decimal_check = {{0x4898C37D, 0x3, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok896) {
  my_decimal decimal = {{0x4947D0C1, 0xF2CB3791, 0x2D919F82, 0x120000}};

  my_decimal decimal_check = {{0x4898C37D, 0x3, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok897) {
  my_decimal decimal = {{0x6F4FDD71, 0x8810CE24, 0x84A26B76, 0xF0000}};

  my_decimal decimal_check = {{0x51CBCE11, 0x2555, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok898) {
  my_decimal decimal = {{0x6F4FDD71, 0x8810CE24, 0x84A26B76, 0x800F0000}};

  my_decimal decimal_check = {{0x51CBCE11, 0x2555, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok899) {
  my_decimal decimal = {{0x5BF555CA, 0xD71B5DD2, 0xE8E6AD2A, 0x80110000}};

  my_decimal decimal_check = {{0xD2AA8827, 0xA7, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok900) {
  my_decimal decimal = {{0x5BF555CA, 0xD71B5DD2, 0xE8E6AD2A, 0x110000}};

  my_decimal decimal_check = {{0xD2AA8827, 0xA7, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok901) {
  my_decimal decimal = {{0xA52A64E4, 0xC2FEBC2A, 0x906AE84C, 0x80180000}};

  my_decimal decimal_check = {{0xAE97, 0x0, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok902) {
  my_decimal decimal = {{0xA52A64E4, 0xC2FEBC2A, 0x906AE84C, 0x180000}};

  my_decimal decimal_check = {{0xAE97, 0x0, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok903) {
  my_decimal decimal = {{0x425675DD, 0x5DF98125, 0x24DFAAF1, 0x80010000}};

  my_decimal decimal_check = {{0x536F0BC9, 0x8965C01D, 0x3AFF77E, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok904) {
  my_decimal decimal = {{0x425675DD, 0x5DF98125, 0x24DFAAF1, 0x10000}};

  my_decimal decimal_check = {{0x536F0BC9, 0x8965C01D, 0x3AFF77E, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok905) {
  my_decimal decimal = {{0xEAEAA330, 0x257A1D41, 0x503A51B8, 0xC0000}};

  my_decimal decimal_check = {{0xEC4B90E3, 0x58361E, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok906) {
  my_decimal decimal = {{0xEAEAA330, 0x257A1D41, 0x503A51B8, 0x800C0000}};

  my_decimal decimal_check = {{0xEC4B90E3, 0x58361E, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok907) {
  my_decimal decimal = {{0x43CD87CC, 0x14062F31, 0x980D1D39, 0x80120000}};

  my_decimal decimal_check = {{0xF4D99E6A, 0xA, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok908) {
  my_decimal decimal = {{0x43CD87CC, 0x14062F31, 0x980D1D39, 0x120000}};

  my_decimal decimal_check = {{0xF4D99E6A, 0xA, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok909) {
  my_decimal decimal = {{0x92C50F6A, 0x59DF1C69, 0x80EDEC9A, 0x80100000}};

  my_decimal decimal_check = {{0x8BFB816, 0x3A1, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok910) {
  my_decimal decimal = {{0x92C50F6A, 0x59DF1C69, 0x80EDEC9A, 0x100000}};

  my_decimal decimal_check = {{0x8BFB816, 0x3A1, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok911) {
  my_decimal decimal = {{0xA537B012, 0x966C13AD, 0xCD680A1D, 0x80170000}};

  my_decimal decimal_check = {{0x9B336, 0x0, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok912) {
  my_decimal decimal = {{0xA537B012, 0x966C13AD, 0xCD680A1D, 0x170000}};

  my_decimal decimal_check = {{0x9B336, 0x0, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok913) {
  my_decimal decimal = {{0xA753ACA7, 0x9540CBA4, 0x5FD09374, 0x800D0000}};

  my_decimal decimal_check = {{0x92825BD, 0xA88F2, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok914) {
  my_decimal decimal = {{0xA753ACA7, 0x9540CBA4, 0x5FD09374, 0xD0000}};

  my_decimal decimal_check = {{0x92825BD, 0xA88F2, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok915) {
  my_decimal decimal = {{0x9E87449D, 0xA1D36D7A, 0xE6C68276, 0x30000}};

  my_decimal decimal_check = {{0xDFE70C19, 0x34E5D7EA, 0x3B1419, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok916) {
  my_decimal decimal = {{0x9E87449D, 0xA1D36D7A, 0xE6C68276, 0x80030000}};

  my_decimal decimal_check = {{0xDFE70C19, 0x34E5D7EA, 0x3B1419, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok917) {
  my_decimal decimal = {{0x86E114B6, 0x9BA69286, 0x944AB077, 0x0}};

  my_decimal decimal_check = {{0x86E114B6, 0x9BA69286, 0x944AB077, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok918) {
  my_decimal decimal = {{0x86E114B6, 0x9BA69286, 0x944AB077, 0x80000000}};

  my_decimal decimal_check = {
      {0x86E114B6, 0x9BA69286, 0x944AB077, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok919) {
  my_decimal decimal = {{0x4A18BBBD, 0x6C172A97, 0x2551249F, 0x30000}};

  my_decimal decimal_check = {{0x53C93DA0, 0xC88E5BF2, 0x98D9A, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok920) {
  my_decimal decimal = {{0x4A18BBBD, 0x6C172A97, 0x2551249F, 0x80030000}};

  my_decimal decimal_check = {{0x53C93DA0, 0xC88E5BF2, 0x98D9A, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok921) {
  my_decimal decimal = {{0x2A389151, 0x61F75FD9, 0x7CFCD2B7, 0x10000}};

  my_decimal decimal_check = {{0x8438DB54, 0xF0325662, 0xC7FAEAB, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok922) {
  my_decimal decimal = {{0x2A389151, 0x61F75FD9, 0x7CFCD2B7, 0x80010000}};

  my_decimal decimal_check = {{0x8438DB54, 0xF0325662, 0xC7FAEAB, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok923) {
  my_decimal decimal = {{0x5FA4A99B, 0x3F558885, 0xEEFE6AA, 0x190000}};

  my_decimal decimal_check = {{0x1CE, 0x0, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok924) {
  my_decimal decimal = {{0x5FA4A99B, 0x3F558885, 0xEEFE6AA, 0x80190000}};

  my_decimal decimal_check = {{0x1CE, 0x0, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok925) {
  my_decimal decimal = {{0xAD1774AD, 0xA859DEBD, 0xC54F90CB, 0x80010000}};

  my_decimal decimal_check = {
      {0x2AE8BEDE, 0x5DA29646, 0x13BB2814, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok926) {
  my_decimal decimal = {{0xAD1774AD, 0xA859DEBD, 0xC54F90CB, 0x10000}};

  my_decimal decimal_check = {{0x2AE8BEDE, 0x5DA29646, 0x13BB2814, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok927) {
  my_decimal decimal = {{0xF34134F9, 0xDCD3496D, 0xE71E14CE, 0x80150000}};

  my_decimal decimal_check = {{0x4436BEB, 0x0, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok928) {
  my_decimal decimal = {{0xF34134F9, 0xDCD3496D, 0xE71E14CE, 0x150000}};

  my_decimal decimal_check = {{0x4436BEB, 0x0, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok929) {
  my_decimal decimal = {{0xC2AA75CE, 0xD04810C8, 0x1189711B, 0x80150000}};

  my_decimal decimal_check = {{0x52D0CA, 0x0, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok930) {
  my_decimal decimal = {{0xC2AA75CE, 0xD04810C8, 0x1189711B, 0x150000}};

  my_decimal decimal_check = {{0x52D0CA, 0x0, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok931) {
  my_decimal decimal = {{0xBB3CB172, 0xC173AF91, 0x9ED03BD9, 0x800C0000}};

  my_decimal decimal_check = {{0x75A78E6B, 0xAE9E00, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok932) {
  my_decimal decimal = {{0xBB3CB172, 0xC173AF91, 0x9ED03BD9, 0xC0000}};

  my_decimal decimal_check = {{0x75A78E6B, 0xAE9E00, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok933) {
  my_decimal decimal = {{0xFBC75E8C, 0xC95419C, 0xC18289C9, 0x1C0000}};

  my_decimal decimal_check = {{0x5, 0x0, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok934) {
  my_decimal decimal = {{0xFBC75E8C, 0xC95419C, 0xC18289C9, 0x801C0000}};

  my_decimal decimal_check = {{0x5, 0x0, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok935) {
  my_decimal decimal = {{0x3CCF427C, 0x2F9DDA8B, 0xC57587E, 0xA0000}};

  my_decimal decimal_check = {{0xAAC9708, 0x54CEDBB, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok936) {
  my_decimal decimal = {{0x3CCF427C, 0x2F9DDA8B, 0xC57587E, 0x800A0000}};

  my_decimal decimal_check = {{0xAAC9708, 0x54CEDBB, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok937) {
  my_decimal decimal = {{0xE1A1BB8B, 0x390C63CE, 0x6C0259EE, 0x1A0000}};

  my_decimal decimal_check = {{0x14E, 0x0, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok938) {
  my_decimal decimal = {{0xE1A1BB8B, 0x390C63CE, 0x6C0259EE, 0x801A0000}};

  my_decimal decimal_check = {{0x14E, 0x0, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok939) {
  my_decimal decimal = {{0xE68304B7, 0x999A569C, 0xDAA5B56C, 0x1C0000}};

  my_decimal decimal_check = {{0x6, 0x0, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok940) {
  my_decimal decimal = {{0xE68304B7, 0x999A569C, 0xDAA5B56C, 0x801C0000}};

  my_decimal decimal_check = {{0x6, 0x0, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok941) {
  my_decimal decimal = {{0x5364A8BB, 0x486E535, 0x207C0E36, 0x40000}};

  my_decimal decimal_check = {{0xC03D1E05, 0x19F5775E, 0xD4E4, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok942) {
  my_decimal decimal = {{0x5364A8BB, 0x486E535, 0x207C0E36, 0x80040000}};

  my_decimal decimal_check = {{0xC03D1E05, 0x19F5775E, 0xD4E4, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok943) {
  my_decimal decimal = {{0x9997A070, 0xE4B04914, 0xCA8B62A4, 0x120000}};

  my_decimal decimal_check = {{0x98493C2A, 0xE, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok944) {
  my_decimal decimal = {{0x9997A070, 0xE4B04914, 0xCA8B62A4, 0x80120000}};

  my_decimal decimal_check = {{0x98493C2A, 0xE, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok945) {
  my_decimal decimal = {{0x619C417A, 0x958C5F40, 0x1FEC5461, 0xB0000}};

  my_decimal decimal_check = {{0xE0B590A9, 0x15EFFB6, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok946) {
  my_decimal decimal = {{0x619C417A, 0x958C5F40, 0x1FEC5461, 0x800B0000}};

  my_decimal decimal_check = {{0xE0B590A9, 0x15EFFB6, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok947) {
  my_decimal decimal = {{0x7A17D3E, 0x783B7A66, 0x16CC5EDC, 0x50000}};

  my_decimal decimal_check = {{0xAEFF1E50, 0xEC7E76EF, 0xEF0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok948) {
  my_decimal decimal = {{0x7A17D3E, 0x783B7A66, 0x16CC5EDC, 0x80050000}};

  my_decimal decimal_check = {{0xAEFF1E50, 0xEC7E76EF, 0xEF0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok949) {
  my_decimal decimal = {{0x803AE7C1, 0x33E59D01, 0x922DDC77, 0x20000}};

  my_decimal decimal_check = {{0xBC298C8E, 0xF3B80E5E, 0x17637F6, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok950) {
  my_decimal decimal = {{0x803AE7C1, 0x33E59D01, 0x922DDC77, 0x80020000}};

  my_decimal decimal_check = {{0xBC298C8E, 0xF3B80E5E, 0x17637F6, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok951) {
  my_decimal decimal = {{0x2AE6C27D, 0x56C8F164, 0x88A1F346, 0x0}};

  my_decimal decimal_check = {{0x2AE6C27D, 0x56C8F164, 0x88A1F346, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok952) {
  my_decimal decimal = {{0x2AE6C27D, 0x56C8F164, 0x88A1F346, 0x80000000}};

  my_decimal decimal_check = {
      {0x2AE6C27D, 0x56C8F164, 0x88A1F346, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok953) {
  my_decimal decimal = {{0x69164A00, 0x9EA1ABF7, 0x9A9C0559, 0x80060000}};

  my_decimal decimal_check = {{0x635DE40D, 0xEA8F55C7, 0xA21, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok954) {
  my_decimal decimal = {{0x69164A00, 0x9EA1ABF7, 0x9A9C0559, 0x60000}};

  my_decimal decimal_check = {{0x635DE40D, 0xEA8F55C7, 0xA21, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok955) {
  my_decimal decimal = {{0x3DE4B341, 0xA3DDC494, 0x9262D402, 0xE0000}};

  my_decimal decimal_check = {{0x438BB666, 0x19C0A, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok956) {
  my_decimal decimal = {{0x3DE4B341, 0xA3DDC494, 0x9262D402, 0x800E0000}};

  my_decimal decimal_check = {{0x438BB666, 0x19C0A, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok957) {
  my_decimal decimal = {{0xA2B61F1D, 0xB98B4CF9, 0xD3D88900, 0x180000}};

  my_decimal decimal_check = {{0x1001B, 0x0, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok958) {
  my_decimal decimal = {{0xA2B61F1D, 0xB98B4CF9, 0xD3D88900, 0x80180000}};

  my_decimal decimal_check = {{0x1001B, 0x0, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok959) {
  my_decimal decimal = {{0x4E0B651C, 0xA8A2D5F9, 0x19A71CC8, 0xB0000}};

  my_decimal decimal_check = {{0x33BAF6AC, 0x11A0E2A, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok960) {
  my_decimal decimal = {{0x4E0B651C, 0xA8A2D5F9, 0x19A71CC8, 0x800B0000}};

  my_decimal decimal_check = {{0x33BAF6AC, 0x11A0E2A, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok961) {
  my_decimal decimal = {{0xF1DA2B9, 0x1774BE81, 0xA0B23B4F, 0x180000}};

  my_decimal decimal_check = {{0xC245, 0x0, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok962) {
  my_decimal decimal = {{0xF1DA2B9, 0x1774BE81, 0xA0B23B4F, 0x80180000}};

  my_decimal decimal_check = {{0xC245, 0x0, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok963) {
  my_decimal decimal = {{0xCCC549EB, 0x8286AD88, 0x9933EF18, 0x90000}};

  my_decimal decimal_check = {{0x29D05BFB, 0x92005570, 0x2, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok964) {
  my_decimal decimal = {{0xCCC549EB, 0x8286AD88, 0x9933EF18, 0x80090000}};

  my_decimal decimal_check = {{0x29D05BFB, 0x92005570, 0x2, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok965) {
  my_decimal decimal = {{0xDF53C8B3, 0x33D782D, 0x2D2CEFFB, 0x30000}};

  my_decimal decimal_check = {{0xDA976139, 0xBD2FEEF7, 0xB909F, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok966) {
  my_decimal decimal = {{0xDF53C8B3, 0x33D782D, 0x2D2CEFFB, 0x80030000}};

  my_decimal decimal_check = {{0xDA976139, 0xBD2FEEF7, 0xB909F, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok967) {
  my_decimal decimal = {{0xC4803DE6, 0x97964D6E, 0xB73EE927, 0x800A0000}};

  my_decimal decimal_check = {{0x60142DF5, 0x4EB4152F, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok968) {
  my_decimal decimal = {{0xC4803DE6, 0x97964D6E, 0xB73EE927, 0xA0000}};

  my_decimal decimal_check = {{0x60142DF5, 0x4EB4152F, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok969) {
  my_decimal decimal = {{0x38F8B5B0, 0xB3027414, 0xF73EA362, 0x80130000}};

  my_decimal decimal_check = {{0xC815FFCF, 0x1, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok970) {
  my_decimal decimal = {{0x38F8B5B0, 0xB3027414, 0xF73EA362, 0x130000}};

  my_decimal decimal_check = {{0xC815FFCF, 0x1, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok971) {
  my_decimal decimal = {{0x728077C, 0x569179, 0xE6509F8A, 0x80150000}};

  my_decimal decimal_check = {{0x43FA1AB, 0x0, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok972) {
  my_decimal decimal = {{0x728077C, 0x569179, 0xE6509F8A, 0x150000}};

  my_decimal decimal_check = {{0x43FA1AB, 0x0, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok973) {
  my_decimal decimal = {{0xB03D4EFF, 0xF6DC352F, 0x3142135C, 0x800D0000}};

  my_decimal decimal_check = {{0x131B16B9, 0x56A7E, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok974) {
  my_decimal decimal = {{0xB03D4EFF, 0xF6DC352F, 0x3142135C, 0xD0000}};

  my_decimal decimal_check = {{0x131B16B9, 0x56A7E, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok975) {
  my_decimal decimal = {{0x6176B527, 0x6016929F, 0x84E10427, 0x80010000}};

  my_decimal decimal_check = {{0x568BDEEA, 0x899BDB76, 0xD49B39D, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok976) {
  my_decimal decimal = {{0x6176B527, 0x6016929F, 0x84E10427, 0x10000}};

  my_decimal decimal_check = {{0x568BDEEA, 0x899BDB76, 0xD49B39D, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok977) {
  my_decimal decimal = {{0xD75243FA, 0x7B16C6FF, 0xBE194CC7, 0x110000}};

  my_decimal decimal_check = {{0xFB0B5427, 0x88, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok978) {
  my_decimal decimal = {{0xD75243FA, 0x7B16C6FF, 0xBE194CC7, 0x80110000}};

  my_decimal decimal_check = {{0xFB0B5427, 0x88, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok979) {
  my_decimal decimal = {{0x632A79D6, 0xF15F100A, 0x2ADBD7B9, 0x160000}};

  my_decimal decimal_check = {{0x143D4E, 0x0, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok980) {
  my_decimal decimal = {{0x632A79D6, 0xF15F100A, 0x2ADBD7B9, 0x80160000}};

  my_decimal decimal_check = {{0x143D4E, 0x0, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok981) {
  my_decimal decimal = {{0xA28180A1, 0x2135C434, 0x55088FFA, 0x100000}};

  my_decimal decimal_check = {{0xBB05F6B9, 0x264, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok982) {
  my_decimal decimal = {{0xA28180A1, 0x2135C434, 0x55088FFA, 0x80100000}};

  my_decimal decimal_check = {{0xBB05F6B9, 0x264, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok983) {
  my_decimal decimal = {{0x43C4985A, 0xEFC56C4C, 0xDEB768CE, 0x1A0000}};

  my_decimal decimal_check = {{0x2B1, 0x0, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok984) {
  my_decimal decimal = {{0x43C4985A, 0xEFC56C4C, 0xDEB768CE, 0x801A0000}};

  my_decimal decimal_check = {{0x2B1, 0x0, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok985) {
  my_decimal decimal = {{0xBF602793, 0xD73CD1A9, 0xE7E49E0F, 0x80170000}};

  my_decimal decimal_check = {{0xAF36A, 0x0, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok986) {
  my_decimal decimal = {{0xBF602793, 0xD73CD1A9, 0xE7E49E0F, 0x170000}};

  my_decimal decimal_check = {{0xAF36A, 0x0, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok987) {
  my_decimal decimal = {{0x7E77F658, 0xEB1284F, 0x8A16957E, 0x80090000}};

  my_decimal decimal_check = {{0x5DD96A2B, 0x51159A1B, 0x2, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok988) {
  my_decimal decimal = {{0x7E77F658, 0xEB1284F, 0x8A16957E, 0x90000}};

  my_decimal decimal_check = {{0x5DD96A2B, 0x51159A1B, 0x2, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok989) {
  my_decimal decimal = {{0xEE37E2B8, 0xF2F3BE69, 0x512D1BBF, 0x80150000}};

  my_decimal decimal_check = {{0x17F5802, 0x0, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok990) {
  my_decimal decimal = {{0xEE37E2B8, 0xF2F3BE69, 0x512D1BBF, 0x150000}};

  my_decimal decimal_check = {{0x17F5802, 0x0, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok991) {
  my_decimal decimal = {{0x1E585DEE, 0x4B1DBED3, 0x72171380, 0xF0000}};

  my_decimal decimal_check = {{0xFA35DD3, 0x201D, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok992) {
  my_decimal decimal = {{0x1E585DEE, 0x4B1DBED3, 0x72171380, 0x800F0000}};

  my_decimal decimal_check = {{0xFA35DD3, 0x201D, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok993) {
  my_decimal decimal = {{0x3B7037C8, 0x4594DE34, 0x3572AB3E, 0x80050000}};

  my_decimal decimal_check = {{0x3FBE46F, 0x12EB49DD, 0x2307, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok994) {
  my_decimal decimal = {{0x3B7037C8, 0x4594DE34, 0x3572AB3E, 0x50000}};

  my_decimal decimal_check = {{0x3FBE46F, 0x12EB49DD, 0x2307, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok995) {
  my_decimal decimal = {{0x9690C467, 0xA3CCE52B, 0xF398C503, 0x0}};

  my_decimal decimal_check = {{0x9690C467, 0xA3CCE52B, 0xF398C503, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok996) {
  my_decimal decimal = {{0x9690C467, 0xA3CCE52B, 0xF398C503, 0x80000000}};

  my_decimal decimal_check = {
      {0x9690C467, 0xA3CCE52B, 0xF398C503, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok997) {
  my_decimal decimal = {{0x453A601C, 0x20AF06EB, 0xC29BFB5B, 0x1C0000}};

  my_decimal decimal_check = {{0x6, 0x0, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok998) {
  my_decimal decimal = {{0x453A601C, 0x20AF06EB, 0xC29BFB5B, 0x801C0000}};

  my_decimal decimal_check = {{0x6, 0x0, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok999) {
  my_decimal decimal = {{0x6861C540, 0xCBA96476, 0xE4216C0E, 0x110000}};

  my_decimal decimal_check = {{0x62A8DECE, 0xA4, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok1000) {
  my_decimal decimal = {{0x6861C540, 0xCBA96476, 0xE4216C0E, 0x80110000}};

  my_decimal decimal_check = {{0x62A8DECE, 0xA4, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok1001) {
  my_decimal decimal = {{0xE5389022, 0x262241AD, 0x8DD9034, 0x800F0000}};

  my_decimal decimal_check = {{0xD3454681, 0x27E, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok1002) {
  my_decimal decimal = {{0xE5389022, 0x262241AD, 0x8DD9034, 0xF0000}};

  my_decimal decimal_check = {{0xD3454681, 0x27E, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok1003) {
  my_decimal decimal = {{0x3545B851, 0xE9D8131F, 0xE347A2F2, 0x70000}};

  my_decimal decimal_check = {{0x83774CC1, 0x4FF199E6, 0x17D, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok1004) {
  my_decimal decimal = {{0x3545B851, 0xE9D8131F, 0xE347A2F2, 0x80070000}};

  my_decimal decimal_check = {{0x83774CC1, 0x4FF199E6, 0x17D, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok1005) {
  my_decimal decimal = {{0xBE13F541, 0xBF523B87, 0x9F61A8C6, 0xF0000}};

  my_decimal decimal_check = {{0xA56691D3, 0x2CDC, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok1006) {
  my_decimal decimal = {{0xBE13F541, 0xBF523B87, 0x9F61A8C6, 0x800F0000}};

  my_decimal decimal_check = {{0xA56691D3, 0x2CDC, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok1007) {
  my_decimal decimal = {{0x5D45B80C, 0x54F2C2FE, 0x325EC60C, 0x80060000}};

  my_decimal decimal_check = {{0x4D2B108C, 0x126702F6, 0x34D, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok1008) {
  my_decimal decimal = {{0x5D45B80C, 0x54F2C2FE, 0x325EC60C, 0x60000}};

  my_decimal decimal_check = {{0x4D2B108C, 0x126702F6, 0x34D, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok1009) {
  my_decimal decimal = {{0x7C327475, 0xD5CB59E5, 0x695E8ACE, 0x20000}};

  my_decimal decimal_check = {{0x5FF643B9, 0xFD0497F0, 0x10DBED3, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok1010) {
  my_decimal decimal = {{0x7C327475, 0xD5CB59E5, 0x695E8ACE, 0x80020000}};

  my_decimal decimal_check = {{0x5FF643B9, 0xFD0497F0, 0x10DBED3, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok1011) {
  my_decimal decimal = {{0x676684CF, 0x854DF1E7, 0xFEB694CA, 0x80150000}};

  my_decimal decimal_check = {{0x4B2D95F, 0x0, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok1012) {
  my_decimal decimal = {{0x676684CF, 0x854DF1E7, 0xFEB694CA, 0x150000}};

  my_decimal decimal_check = {{0x4B2D95F, 0x0, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok1013) {
  my_decimal decimal = {{0x90B7D067, 0xA04AF869, 0xCFF6186E, 0x80160000}};

  my_decimal decimal_check = {{0x6234FA, 0x0, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok1014) {
  my_decimal decimal = {{0x90B7D067, 0xA04AF869, 0xCFF6186E, 0x160000}};

  my_decimal decimal_check = {{0x6234FA, 0x0, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok1015) {
  my_decimal decimal = {{0xF928F0B6, 0xA4245237, 0x8CD382, 0x80010000}};

  my_decimal decimal_check = {{0x65B74B45, 0xAA03A1D2, 0xE1526, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok1016) {
  my_decimal decimal = {{0xF928F0B6, 0xA4245237, 0x8CD382, 0x10000}};

  my_decimal decimal_check = {{0x65B74B45, 0xAA03A1D2, 0xE1526, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok1017) {
  my_decimal decimal = {{0xBBE6161B, 0x80B5390B, 0x6AD80C1C, 0x80190000}};

  my_decimal decimal_check = {{0xCEA, 0x0, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok1018) {
  my_decimal decimal = {{0xBBE6161B, 0x80B5390B, 0x6AD80C1C, 0x190000}};

  my_decimal decimal_check = {{0xCEA, 0x0, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok1019) {
  my_decimal decimal = {{0xFF53F260, 0xE7DD3002, 0xB41F0546, 0x130000}};

  my_decimal decimal_check = {{0x4C43D1D2, 0x1, 0x0, 0x0}};

  test_truncate(decimal, decimal_check);
}

START_TEST(test_truncate_ok1020) {
  my_decimal decimal = {{0xFF53F260, 0xE7DD3002, 0xB41F0546, 0x80130000}};

  my_decimal decimal_check = {{0x4C43D1D2, 0x1, 0x0, 0x80000000}};

  test_truncate(decimal, decimal_check);
}

Suite *truncate_suite1(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("truncate_suite1");
  tc_core = tcase_create("Core");
  tcase_add_test(tc_core, test_truncate_ok1);
  tcase_add_test(tc_core, test_truncate_ok2);
  tcase_add_test(tc_core, test_truncate_ok3);
  tcase_add_test(tc_core, test_truncate_ok4);
  tcase_add_test(tc_core, test_truncate_ok5);
  tcase_add_test(tc_core, test_truncate_ok6);
  tcase_add_test(tc_core, test_truncate_ok7);
  tcase_add_test(tc_core, test_truncate_ok8);
  tcase_add_test(tc_core, test_truncate_ok9);
  tcase_add_test(tc_core, test_truncate_ok10);
  tcase_add_test(tc_core, test_truncate_ok11);
  tcase_add_test(tc_core, test_truncate_ok12);
  tcase_add_test(tc_core, test_truncate_ok13);
  tcase_add_test(tc_core, test_truncate_ok14);
  tcase_add_test(tc_core, test_truncate_ok15);
  tcase_add_test(tc_core, test_truncate_ok16);
  tcase_add_test(tc_core, test_truncate_ok17);
  tcase_add_test(tc_core, test_truncate_ok18);
  tcase_add_test(tc_core, test_truncate_ok19);
  tcase_add_test(tc_core, test_truncate_ok20);
  tcase_add_test(tc_core, test_truncate_ok21);
  tcase_add_test(tc_core, test_truncate_ok22);
  tcase_add_test(tc_core, test_truncate_ok23);
  tcase_add_test(tc_core, test_truncate_ok24);
  tcase_add_test(tc_core, test_truncate_ok25);
  tcase_add_test(tc_core, test_truncate_ok26);
  tcase_add_test(tc_core, test_truncate_ok27);
  tcase_add_test(tc_core, test_truncate_ok28);
  tcase_add_test(tc_core, test_truncate_ok29);
  tcase_add_test(tc_core, test_truncate_ok30);
  tcase_add_test(tc_core, test_truncate_ok31);
  tcase_add_test(tc_core, test_truncate_ok32);
  tcase_add_test(tc_core, test_truncate_ok33);
  tcase_add_test(tc_core, test_truncate_ok34);
  tcase_add_test(tc_core, test_truncate_ok35);
  tcase_add_test(tc_core, test_truncate_ok36);
  tcase_add_test(tc_core, test_truncate_ok37);
  tcase_add_test(tc_core, test_truncate_ok38);
  tcase_add_test(tc_core, test_truncate_ok39);
  tcase_add_test(tc_core, test_truncate_ok40);
  tcase_add_test(tc_core, test_truncate_ok41);
  tcase_add_test(tc_core, test_truncate_ok42);
  tcase_add_test(tc_core, test_truncate_ok43);
  tcase_add_test(tc_core, test_truncate_ok44);
  tcase_add_test(tc_core, test_truncate_ok45);
  tcase_add_test(tc_core, test_truncate_ok46);
  tcase_add_test(tc_core, test_truncate_ok47);
  tcase_add_test(tc_core, test_truncate_ok48);
  tcase_add_test(tc_core, test_truncate_ok49);
  tcase_add_test(tc_core, test_truncate_ok50);
  tcase_add_test(tc_core, test_truncate_ok51);
  tcase_add_test(tc_core, test_truncate_ok52);
  tcase_add_test(tc_core, test_truncate_ok53);
  tcase_add_test(tc_core, test_truncate_ok54);
  tcase_add_test(tc_core, test_truncate_ok55);
  tcase_add_test(tc_core, test_truncate_ok56);
  tcase_add_test(tc_core, test_truncate_ok57);
  tcase_add_test(tc_core, test_truncate_ok58);
  tcase_add_test(tc_core, test_truncate_ok59);
  tcase_add_test(tc_core, test_truncate_ok60);
  tcase_add_test(tc_core, test_truncate_ok61);
  tcase_add_test(tc_core, test_truncate_ok62);
  tcase_add_test(tc_core, test_truncate_ok63);
  tcase_add_test(tc_core, test_truncate_ok64);
  tcase_add_test(tc_core, test_truncate_ok65);
  tcase_add_test(tc_core, test_truncate_ok66);
  tcase_add_test(tc_core, test_truncate_ok67);
  tcase_add_test(tc_core, test_truncate_ok68);
  tcase_add_test(tc_core, test_truncate_ok69);
  tcase_add_test(tc_core, test_truncate_ok70);
  tcase_add_test(tc_core, test_truncate_ok71);
  tcase_add_test(tc_core, test_truncate_ok72);
  tcase_add_test(tc_core, test_truncate_ok73);
  tcase_add_test(tc_core, test_truncate_ok74);
  tcase_add_test(tc_core, test_truncate_ok75);
  tcase_add_test(tc_core, test_truncate_ok76);
  tcase_add_test(tc_core, test_truncate_ok77);
  tcase_add_test(tc_core, test_truncate_ok78);
  tcase_add_test(tc_core, test_truncate_ok79);
  tcase_add_test(tc_core, test_truncate_ok80);
  tcase_add_test(tc_core, test_truncate_ok81);
  tcase_add_test(tc_core, test_truncate_ok82);
  tcase_add_test(tc_core, test_truncate_ok83);
  tcase_add_test(tc_core, test_truncate_ok84);
  tcase_add_test(tc_core, test_truncate_ok85);
  tcase_add_test(tc_core, test_truncate_ok86);
  tcase_add_test(tc_core, test_truncate_ok87);
  tcase_add_test(tc_core, test_truncate_ok88);
  tcase_add_test(tc_core, test_truncate_ok89);
  tcase_add_test(tc_core, test_truncate_ok90);
  tcase_add_test(tc_core, test_truncate_ok91);
  tcase_add_test(tc_core, test_truncate_ok92);
  tcase_add_test(tc_core, test_truncate_ok93);
  tcase_add_test(tc_core, test_truncate_ok94);
  tcase_add_test(tc_core, test_truncate_ok95);
  tcase_add_test(tc_core, test_truncate_ok96);
  tcase_add_test(tc_core, test_truncate_ok97);
  tcase_add_test(tc_core, test_truncate_ok98);
  tcase_add_test(tc_core, test_truncate_ok99);
  tcase_add_test(tc_core, test_truncate_ok100);
  tcase_add_test(tc_core, test_truncate_ok101);
  tcase_add_test(tc_core, test_truncate_ok102);
  tcase_add_test(tc_core, test_truncate_ok103);
  tcase_add_test(tc_core, test_truncate_ok104);
  tcase_add_test(tc_core, test_truncate_ok105);
  tcase_add_test(tc_core, test_truncate_ok106);
  tcase_add_test(tc_core, test_truncate_ok107);
  tcase_add_test(tc_core, test_truncate_ok108);
  tcase_add_test(tc_core, test_truncate_ok109);
  tcase_add_test(tc_core, test_truncate_ok110);
  tcase_add_test(tc_core, test_truncate_ok111);
  tcase_add_test(tc_core, test_truncate_ok112);
  tcase_add_test(tc_core, test_truncate_ok113);
  tcase_add_test(tc_core, test_truncate_ok114);
  tcase_add_test(tc_core, test_truncate_ok115);
  tcase_add_test(tc_core, test_truncate_ok116);
  tcase_add_test(tc_core, test_truncate_ok117);
  tcase_add_test(tc_core, test_truncate_ok118);
  tcase_add_test(tc_core, test_truncate_ok119);
  tcase_add_test(tc_core, test_truncate_ok120);
  tcase_add_test(tc_core, test_truncate_ok121);
  tcase_add_test(tc_core, test_truncate_ok122);
  tcase_add_test(tc_core, test_truncate_ok123);
  tcase_add_test(tc_core, test_truncate_ok124);
  tcase_add_test(tc_core, test_truncate_ok125);
  tcase_add_test(tc_core, test_truncate_ok126);
  tcase_add_test(tc_core, test_truncate_ok127);
  tcase_add_test(tc_core, test_truncate_ok128);
  tcase_add_test(tc_core, test_truncate_ok129);
  tcase_add_test(tc_core, test_truncate_ok130);
  tcase_add_test(tc_core, test_truncate_ok131);
  tcase_add_test(tc_core, test_truncate_ok132);
  tcase_add_test(tc_core, test_truncate_ok133);
  tcase_add_test(tc_core, test_truncate_ok134);
  tcase_add_test(tc_core, test_truncate_ok135);
  tcase_add_test(tc_core, test_truncate_ok136);
  tcase_add_test(tc_core, test_truncate_ok137);
  tcase_add_test(tc_core, test_truncate_ok138);
  tcase_add_test(tc_core, test_truncate_ok139);
  tcase_add_test(tc_core, test_truncate_ok140);
  tcase_add_test(tc_core, test_truncate_ok141);
  tcase_add_test(tc_core, test_truncate_ok142);
  tcase_add_test(tc_core, test_truncate_ok143);
  tcase_add_test(tc_core, test_truncate_ok144);
  tcase_add_test(tc_core, test_truncate_ok145);
  tcase_add_test(tc_core, test_truncate_ok146);
  tcase_add_test(tc_core, test_truncate_ok147);
  tcase_add_test(tc_core, test_truncate_ok148);
  tcase_add_test(tc_core, test_truncate_ok149);
  tcase_add_test(tc_core, test_truncate_ok150);
  tcase_add_test(tc_core, test_truncate_ok151);
  tcase_add_test(tc_core, test_truncate_ok152);
  tcase_add_test(tc_core, test_truncate_ok153);
  tcase_add_test(tc_core, test_truncate_ok154);
  tcase_add_test(tc_core, test_truncate_ok155);
  tcase_add_test(tc_core, test_truncate_ok156);
  tcase_add_test(tc_core, test_truncate_ok157);
  tcase_add_test(tc_core, test_truncate_ok158);
  tcase_add_test(tc_core, test_truncate_ok159);
  tcase_add_test(tc_core, test_truncate_ok160);
  tcase_add_test(tc_core, test_truncate_ok161);
  tcase_add_test(tc_core, test_truncate_ok162);
  tcase_add_test(tc_core, test_truncate_ok163);
  tcase_add_test(tc_core, test_truncate_ok164);
  tcase_add_test(tc_core, test_truncate_ok165);
  tcase_add_test(tc_core, test_truncate_ok166);
  tcase_add_test(tc_core, test_truncate_ok167);
  tcase_add_test(tc_core, test_truncate_ok168);
  tcase_add_test(tc_core, test_truncate_ok169);
  tcase_add_test(tc_core, test_truncate_ok170);
  tcase_add_test(tc_core, test_truncate_ok171);
  tcase_add_test(tc_core, test_truncate_ok172);
  tcase_add_test(tc_core, test_truncate_ok173);
  tcase_add_test(tc_core, test_truncate_ok174);
  tcase_add_test(tc_core, test_truncate_ok175);
  tcase_add_test(tc_core, test_truncate_ok176);
  tcase_add_test(tc_core, test_truncate_ok177);
  tcase_add_test(tc_core, test_truncate_ok178);
  tcase_add_test(tc_core, test_truncate_ok179);
  tcase_add_test(tc_core, test_truncate_ok180);
  tcase_add_test(tc_core, test_truncate_ok181);
  tcase_add_test(tc_core, test_truncate_ok182);
  tcase_add_test(tc_core, test_truncate_ok183);
  tcase_add_test(tc_core, test_truncate_ok184);
  tcase_add_test(tc_core, test_truncate_ok185);
  tcase_add_test(tc_core, test_truncate_ok186);
  tcase_add_test(tc_core, test_truncate_ok187);
  tcase_add_test(tc_core, test_truncate_ok188);
  tcase_add_test(tc_core, test_truncate_ok189);
  tcase_add_test(tc_core, test_truncate_ok190);
  tcase_add_test(tc_core, test_truncate_ok191);
  tcase_add_test(tc_core, test_truncate_ok192);
  tcase_add_test(tc_core, test_truncate_ok193);
  tcase_add_test(tc_core, test_truncate_ok194);
  tcase_add_test(tc_core, test_truncate_ok195);
  tcase_add_test(tc_core, test_truncate_ok196);
  tcase_add_test(tc_core, test_truncate_ok197);
  tcase_add_test(tc_core, test_truncate_ok198);
  tcase_add_test(tc_core, test_truncate_ok199);
  tcase_add_test(tc_core, test_truncate_ok200);
  tcase_add_test(tc_core, test_truncate_ok201);
  tcase_add_test(tc_core, test_truncate_ok202);
  tcase_add_test(tc_core, test_truncate_ok203);
  tcase_add_test(tc_core, test_truncate_ok204);
  tcase_add_test(tc_core, test_truncate_ok205);
  tcase_add_test(tc_core, test_truncate_ok206);
  tcase_add_test(tc_core, test_truncate_ok207);
  tcase_add_test(tc_core, test_truncate_ok208);
  tcase_add_test(tc_core, test_truncate_ok209);
  tcase_add_test(tc_core, test_truncate_ok210);
  tcase_add_test(tc_core, test_truncate_ok211);
  tcase_add_test(tc_core, test_truncate_ok212);
  tcase_add_test(tc_core, test_truncate_ok213);
  tcase_add_test(tc_core, test_truncate_ok214);
  tcase_add_test(tc_core, test_truncate_ok215);
  tcase_add_test(tc_core, test_truncate_ok216);
  tcase_add_test(tc_core, test_truncate_ok217);
  tcase_add_test(tc_core, test_truncate_ok218);
  tcase_add_test(tc_core, test_truncate_ok219);
  tcase_add_test(tc_core, test_truncate_ok220);
  tcase_add_test(tc_core, test_truncate_ok221);
  tcase_add_test(tc_core, test_truncate_ok222);
  tcase_add_test(tc_core, test_truncate_ok223);
  tcase_add_test(tc_core, test_truncate_ok224);
  tcase_add_test(tc_core, test_truncate_ok225);
  tcase_add_test(tc_core, test_truncate_ok226);
  tcase_add_test(tc_core, test_truncate_ok227);
  tcase_add_test(tc_core, test_truncate_ok228);
  tcase_add_test(tc_core, test_truncate_ok229);
  tcase_add_test(tc_core, test_truncate_ok230);
  tcase_add_test(tc_core, test_truncate_ok231);
  tcase_add_test(tc_core, test_truncate_ok232);
  tcase_add_test(tc_core, test_truncate_ok233);
  tcase_add_test(tc_core, test_truncate_ok234);
  tcase_add_test(tc_core, test_truncate_ok235);
  tcase_add_test(tc_core, test_truncate_ok236);
  tcase_add_test(tc_core, test_truncate_ok237);
  tcase_add_test(tc_core, test_truncate_ok238);
  tcase_add_test(tc_core, test_truncate_ok239);
  tcase_add_test(tc_core, test_truncate_ok240);
  tcase_add_test(tc_core, test_truncate_ok241);
  tcase_add_test(tc_core, test_truncate_ok242);
  tcase_add_test(tc_core, test_truncate_ok243);
  tcase_add_test(tc_core, test_truncate_ok244);
  tcase_add_test(tc_core, test_truncate_ok245);
  tcase_add_test(tc_core, test_truncate_ok246);
  tcase_add_test(tc_core, test_truncate_ok247);
  tcase_add_test(tc_core, test_truncate_ok248);
  tcase_add_test(tc_core, test_truncate_ok249);
  tcase_add_test(tc_core, test_truncate_ok250);
  tcase_add_test(tc_core, test_truncate_ok251);
  tcase_add_test(tc_core, test_truncate_ok252);
  tcase_add_test(tc_core, test_truncate_ok253);
  tcase_add_test(tc_core, test_truncate_ok254);
  tcase_add_test(tc_core, test_truncate_ok255);
  tcase_add_test(tc_core, test_truncate_ok256);
  tcase_add_test(tc_core, test_truncate_ok257);
  tcase_add_test(tc_core, test_truncate_ok258);
  tcase_add_test(tc_core, test_truncate_ok259);
  tcase_add_test(tc_core, test_truncate_ok260);
  tcase_add_test(tc_core, test_truncate_ok261);
  tcase_add_test(tc_core, test_truncate_ok262);
  tcase_add_test(tc_core, test_truncate_ok263);
  tcase_add_test(tc_core, test_truncate_ok264);
  tcase_add_test(tc_core, test_truncate_ok265);
  tcase_add_test(tc_core, test_truncate_ok266);
  tcase_add_test(tc_core, test_truncate_ok267);
  tcase_add_test(tc_core, test_truncate_ok268);
  tcase_add_test(tc_core, test_truncate_ok269);
  tcase_add_test(tc_core, test_truncate_ok270);
  tcase_add_test(tc_core, test_truncate_ok271);
  tcase_add_test(tc_core, test_truncate_ok272);
  tcase_add_test(tc_core, test_truncate_ok273);
  tcase_add_test(tc_core, test_truncate_ok274);
  tcase_add_test(tc_core, test_truncate_ok275);
  tcase_add_test(tc_core, test_truncate_ok276);
  tcase_add_test(tc_core, test_truncate_ok277);
  tcase_add_test(tc_core, test_truncate_ok278);
  tcase_add_test(tc_core, test_truncate_ok279);
  tcase_add_test(tc_core, test_truncate_ok280);
  tcase_add_test(tc_core, test_truncate_ok281);
  tcase_add_test(tc_core, test_truncate_ok282);
  tcase_add_test(tc_core, test_truncate_ok283);
  tcase_add_test(tc_core, test_truncate_ok284);
  tcase_add_test(tc_core, test_truncate_ok285);
  tcase_add_test(tc_core, test_truncate_ok286);
  tcase_add_test(tc_core, test_truncate_ok287);
  tcase_add_test(tc_core, test_truncate_ok288);
  tcase_add_test(tc_core, test_truncate_ok289);
  tcase_add_test(tc_core, test_truncate_ok290);
  tcase_add_test(tc_core, test_truncate_ok291);
  tcase_add_test(tc_core, test_truncate_ok292);
  tcase_add_test(tc_core, test_truncate_ok293);
  tcase_add_test(tc_core, test_truncate_ok294);
  tcase_add_test(tc_core, test_truncate_ok295);
  tcase_add_test(tc_core, test_truncate_ok296);
  tcase_add_test(tc_core, test_truncate_ok297);
  tcase_add_test(tc_core, test_truncate_ok298);
  tcase_add_test(tc_core, test_truncate_ok299);
  tcase_add_test(tc_core, test_truncate_ok300);
  tcase_add_test(tc_core, test_truncate_ok301);
  tcase_add_test(tc_core, test_truncate_ok302);
  tcase_add_test(tc_core, test_truncate_ok303);
  tcase_add_test(tc_core, test_truncate_ok304);
  tcase_add_test(tc_core, test_truncate_ok305);
  tcase_add_test(tc_core, test_truncate_ok306);
  tcase_add_test(tc_core, test_truncate_ok307);
  tcase_add_test(tc_core, test_truncate_ok308);
  tcase_add_test(tc_core, test_truncate_ok309);
  tcase_add_test(tc_core, test_truncate_ok310);
  tcase_add_test(tc_core, test_truncate_ok311);
  tcase_add_test(tc_core, test_truncate_ok312);
  tcase_add_test(tc_core, test_truncate_ok313);
  tcase_add_test(tc_core, test_truncate_ok314);
  tcase_add_test(tc_core, test_truncate_ok315);
  tcase_add_test(tc_core, test_truncate_ok316);
  tcase_add_test(tc_core, test_truncate_ok317);
  tcase_add_test(tc_core, test_truncate_ok318);
  tcase_add_test(tc_core, test_truncate_ok319);
  tcase_add_test(tc_core, test_truncate_ok320);
  tcase_add_test(tc_core, test_truncate_ok321);
  tcase_add_test(tc_core, test_truncate_ok322);
  tcase_add_test(tc_core, test_truncate_ok323);
  tcase_add_test(tc_core, test_truncate_ok324);
  tcase_add_test(tc_core, test_truncate_ok325);
  tcase_add_test(tc_core, test_truncate_ok326);
  tcase_add_test(tc_core, test_truncate_ok327);
  tcase_add_test(tc_core, test_truncate_ok328);
  tcase_add_test(tc_core, test_truncate_ok329);
  tcase_add_test(tc_core, test_truncate_ok330);
  tcase_add_test(tc_core, test_truncate_ok331);
  tcase_add_test(tc_core, test_truncate_ok332);
  tcase_add_test(tc_core, test_truncate_ok333);
  tcase_add_test(tc_core, test_truncate_ok334);
  tcase_add_test(tc_core, test_truncate_ok335);
  tcase_add_test(tc_core, test_truncate_ok336);
  tcase_add_test(tc_core, test_truncate_ok337);
  tcase_add_test(tc_core, test_truncate_ok338);
  tcase_add_test(tc_core, test_truncate_ok339);
  tcase_add_test(tc_core, test_truncate_ok340);
  tcase_add_test(tc_core, test_truncate_ok341);
  tcase_add_test(tc_core, test_truncate_ok342);
  tcase_add_test(tc_core, test_truncate_ok343);
  tcase_add_test(tc_core, test_truncate_ok344);
  tcase_add_test(tc_core, test_truncate_ok345);
  tcase_add_test(tc_core, test_truncate_ok346);
  tcase_add_test(tc_core, test_truncate_ok347);
  tcase_add_test(tc_core, test_truncate_ok348);
  tcase_add_test(tc_core, test_truncate_ok349);
  tcase_add_test(tc_core, test_truncate_ok350);
  tcase_add_test(tc_core, test_truncate_ok351);
  tcase_add_test(tc_core, test_truncate_ok352);
  tcase_add_test(tc_core, test_truncate_ok353);
  tcase_add_test(tc_core, test_truncate_ok354);
  tcase_add_test(tc_core, test_truncate_ok355);
  tcase_add_test(tc_core, test_truncate_ok356);
  tcase_add_test(tc_core, test_truncate_ok357);
  tcase_add_test(tc_core, test_truncate_ok358);
  tcase_add_test(tc_core, test_truncate_ok359);
  tcase_add_test(tc_core, test_truncate_ok360);
  tcase_add_test(tc_core, test_truncate_ok361);
  tcase_add_test(tc_core, test_truncate_ok362);
  tcase_add_test(tc_core, test_truncate_ok363);
  tcase_add_test(tc_core, test_truncate_ok364);
  tcase_add_test(tc_core, test_truncate_ok365);
  tcase_add_test(tc_core, test_truncate_ok366);
  tcase_add_test(tc_core, test_truncate_ok367);
  tcase_add_test(tc_core, test_truncate_ok368);
  tcase_add_test(tc_core, test_truncate_ok369);
  tcase_add_test(tc_core, test_truncate_ok370);
  tcase_add_test(tc_core, test_truncate_ok371);
  tcase_add_test(tc_core, test_truncate_ok372);
  tcase_add_test(tc_core, test_truncate_ok373);
  tcase_add_test(tc_core, test_truncate_ok374);
  tcase_add_test(tc_core, test_truncate_ok375);
  tcase_add_test(tc_core, test_truncate_ok376);
  tcase_add_test(tc_core, test_truncate_ok377);
  tcase_add_test(tc_core, test_truncate_ok378);
  tcase_add_test(tc_core, test_truncate_ok379);
  tcase_add_test(tc_core, test_truncate_ok380);
  tcase_add_test(tc_core, test_truncate_ok381);
  tcase_add_test(tc_core, test_truncate_ok382);
  tcase_add_test(tc_core, test_truncate_ok383);
  tcase_add_test(tc_core, test_truncate_ok384);
  tcase_add_test(tc_core, test_truncate_ok385);
  tcase_add_test(tc_core, test_truncate_ok386);
  tcase_add_test(tc_core, test_truncate_ok387);
  tcase_add_test(tc_core, test_truncate_ok388);
  tcase_add_test(tc_core, test_truncate_ok389);
  tcase_add_test(tc_core, test_truncate_ok390);
  tcase_add_test(tc_core, test_truncate_ok391);
  tcase_add_test(tc_core, test_truncate_ok392);
  tcase_add_test(tc_core, test_truncate_ok393);
  tcase_add_test(tc_core, test_truncate_ok394);
  tcase_add_test(tc_core, test_truncate_ok395);
  tcase_add_test(tc_core, test_truncate_ok396);
  tcase_add_test(tc_core, test_truncate_ok397);
  tcase_add_test(tc_core, test_truncate_ok398);
  tcase_add_test(tc_core, test_truncate_ok399);
  tcase_add_test(tc_core, test_truncate_ok400);

  suite_add_tcase(s, tc_core);
  return s;
}

Suite *truncate_suite2(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("truncate_suite2");
  tc_core = tcase_create("Core");
  tcase_add_test(tc_core, test_truncate_ok401);
  tcase_add_test(tc_core, test_truncate_ok402);
  tcase_add_test(tc_core, test_truncate_ok403);
  tcase_add_test(tc_core, test_truncate_ok404);
  tcase_add_test(tc_core, test_truncate_ok405);
  tcase_add_test(tc_core, test_truncate_ok406);
  tcase_add_test(tc_core, test_truncate_ok407);
  tcase_add_test(tc_core, test_truncate_ok408);
  tcase_add_test(tc_core, test_truncate_ok409);
  tcase_add_test(tc_core, test_truncate_ok410);
  tcase_add_test(tc_core, test_truncate_ok411);
  tcase_add_test(tc_core, test_truncate_ok412);
  tcase_add_test(tc_core, test_truncate_ok413);
  tcase_add_test(tc_core, test_truncate_ok414);
  tcase_add_test(tc_core, test_truncate_ok415);
  tcase_add_test(tc_core, test_truncate_ok416);
  tcase_add_test(tc_core, test_truncate_ok417);
  tcase_add_test(tc_core, test_truncate_ok418);
  tcase_add_test(tc_core, test_truncate_ok419);
  tcase_add_test(tc_core, test_truncate_ok420);
  tcase_add_test(tc_core, test_truncate_ok421);
  tcase_add_test(tc_core, test_truncate_ok422);
  tcase_add_test(tc_core, test_truncate_ok423);
  tcase_add_test(tc_core, test_truncate_ok424);
  tcase_add_test(tc_core, test_truncate_ok425);
  tcase_add_test(tc_core, test_truncate_ok426);
  tcase_add_test(tc_core, test_truncate_ok427);
  tcase_add_test(tc_core, test_truncate_ok428);
  tcase_add_test(tc_core, test_truncate_ok429);
  tcase_add_test(tc_core, test_truncate_ok430);
  tcase_add_test(tc_core, test_truncate_ok431);
  tcase_add_test(tc_core, test_truncate_ok432);
  tcase_add_test(tc_core, test_truncate_ok433);
  tcase_add_test(tc_core, test_truncate_ok434);
  tcase_add_test(tc_core, test_truncate_ok435);
  tcase_add_test(tc_core, test_truncate_ok436);
  tcase_add_test(tc_core, test_truncate_ok437);
  tcase_add_test(tc_core, test_truncate_ok438);
  tcase_add_test(tc_core, test_truncate_ok439);
  tcase_add_test(tc_core, test_truncate_ok440);
  tcase_add_test(tc_core, test_truncate_ok441);
  tcase_add_test(tc_core, test_truncate_ok442);
  tcase_add_test(tc_core, test_truncate_ok443);
  tcase_add_test(tc_core, test_truncate_ok444);
  tcase_add_test(tc_core, test_truncate_ok445);
  tcase_add_test(tc_core, test_truncate_ok446);
  tcase_add_test(tc_core, test_truncate_ok447);
  tcase_add_test(tc_core, test_truncate_ok448);
  tcase_add_test(tc_core, test_truncate_ok449);
  tcase_add_test(tc_core, test_truncate_ok450);
  tcase_add_test(tc_core, test_truncate_ok451);
  tcase_add_test(tc_core, test_truncate_ok452);
  tcase_add_test(tc_core, test_truncate_ok453);
  tcase_add_test(tc_core, test_truncate_ok454);
  tcase_add_test(tc_core, test_truncate_ok455);
  tcase_add_test(tc_core, test_truncate_ok456);
  tcase_add_test(tc_core, test_truncate_ok457);
  tcase_add_test(tc_core, test_truncate_ok458);
  tcase_add_test(tc_core, test_truncate_ok459);
  tcase_add_test(tc_core, test_truncate_ok460);
  tcase_add_test(tc_core, test_truncate_ok461);
  tcase_add_test(tc_core, test_truncate_ok462);
  tcase_add_test(tc_core, test_truncate_ok463);
  tcase_add_test(tc_core, test_truncate_ok464);
  tcase_add_test(tc_core, test_truncate_ok465);
  tcase_add_test(tc_core, test_truncate_ok466);
  tcase_add_test(tc_core, test_truncate_ok467);
  tcase_add_test(tc_core, test_truncate_ok468);
  tcase_add_test(tc_core, test_truncate_ok469);
  tcase_add_test(tc_core, test_truncate_ok470);
  tcase_add_test(tc_core, test_truncate_ok471);
  tcase_add_test(tc_core, test_truncate_ok472);
  tcase_add_test(tc_core, test_truncate_ok473);
  tcase_add_test(tc_core, test_truncate_ok474);
  tcase_add_test(tc_core, test_truncate_ok475);
  tcase_add_test(tc_core, test_truncate_ok476);
  tcase_add_test(tc_core, test_truncate_ok477);
  tcase_add_test(tc_core, test_truncate_ok478);
  tcase_add_test(tc_core, test_truncate_ok479);
  tcase_add_test(tc_core, test_truncate_ok480);
  tcase_add_test(tc_core, test_truncate_ok481);
  tcase_add_test(tc_core, test_truncate_ok482);
  tcase_add_test(tc_core, test_truncate_ok483);
  tcase_add_test(tc_core, test_truncate_ok484);
  tcase_add_test(tc_core, test_truncate_ok485);
  tcase_add_test(tc_core, test_truncate_ok486);
  tcase_add_test(tc_core, test_truncate_ok487);
  tcase_add_test(tc_core, test_truncate_ok488);
  tcase_add_test(tc_core, test_truncate_ok489);
  tcase_add_test(tc_core, test_truncate_ok490);
  tcase_add_test(tc_core, test_truncate_ok491);
  tcase_add_test(tc_core, test_truncate_ok492);
  tcase_add_test(tc_core, test_truncate_ok493);
  tcase_add_test(tc_core, test_truncate_ok494);
  tcase_add_test(tc_core, test_truncate_ok495);
  tcase_add_test(tc_core, test_truncate_ok496);
  tcase_add_test(tc_core, test_truncate_ok497);
  tcase_add_test(tc_core, test_truncate_ok498);
  tcase_add_test(tc_core, test_truncate_ok499);
  tcase_add_test(tc_core, test_truncate_ok500);
  tcase_add_test(tc_core, test_truncate_ok501);
  tcase_add_test(tc_core, test_truncate_ok502);
  tcase_add_test(tc_core, test_truncate_ok503);
  tcase_add_test(tc_core, test_truncate_ok504);
  tcase_add_test(tc_core, test_truncate_ok505);
  tcase_add_test(tc_core, test_truncate_ok506);
  tcase_add_test(tc_core, test_truncate_ok507);
  tcase_add_test(tc_core, test_truncate_ok508);
  tcase_add_test(tc_core, test_truncate_ok509);
  tcase_add_test(tc_core, test_truncate_ok510);
  tcase_add_test(tc_core, test_truncate_ok511);
  tcase_add_test(tc_core, test_truncate_ok512);
  tcase_add_test(tc_core, test_truncate_ok513);
  tcase_add_test(tc_core, test_truncate_ok514);
  tcase_add_test(tc_core, test_truncate_ok515);
  tcase_add_test(tc_core, test_truncate_ok516);
  tcase_add_test(tc_core, test_truncate_ok517);
  tcase_add_test(tc_core, test_truncate_ok518);
  tcase_add_test(tc_core, test_truncate_ok519);
  tcase_add_test(tc_core, test_truncate_ok520);
  tcase_add_test(tc_core, test_truncate_ok521);
  tcase_add_test(tc_core, test_truncate_ok522);
  tcase_add_test(tc_core, test_truncate_ok523);
  tcase_add_test(tc_core, test_truncate_ok524);
  tcase_add_test(tc_core, test_truncate_ok525);
  tcase_add_test(tc_core, test_truncate_ok526);
  tcase_add_test(tc_core, test_truncate_ok527);
  tcase_add_test(tc_core, test_truncate_ok528);
  tcase_add_test(tc_core, test_truncate_ok529);
  tcase_add_test(tc_core, test_truncate_ok530);
  tcase_add_test(tc_core, test_truncate_ok531);
  tcase_add_test(tc_core, test_truncate_ok532);
  tcase_add_test(tc_core, test_truncate_ok533);
  tcase_add_test(tc_core, test_truncate_ok534);
  tcase_add_test(tc_core, test_truncate_ok535);
  tcase_add_test(tc_core, test_truncate_ok536);
  tcase_add_test(tc_core, test_truncate_ok537);
  tcase_add_test(tc_core, test_truncate_ok538);
  tcase_add_test(tc_core, test_truncate_ok539);
  tcase_add_test(tc_core, test_truncate_ok540);
  tcase_add_test(tc_core, test_truncate_ok541);
  tcase_add_test(tc_core, test_truncate_ok542);
  tcase_add_test(tc_core, test_truncate_ok543);
  tcase_add_test(tc_core, test_truncate_ok544);
  tcase_add_test(tc_core, test_truncate_ok545);
  tcase_add_test(tc_core, test_truncate_ok546);
  tcase_add_test(tc_core, test_truncate_ok547);
  tcase_add_test(tc_core, test_truncate_ok548);
  tcase_add_test(tc_core, test_truncate_ok549);
  tcase_add_test(tc_core, test_truncate_ok550);
  tcase_add_test(tc_core, test_truncate_ok551);
  tcase_add_test(tc_core, test_truncate_ok552);
  tcase_add_test(tc_core, test_truncate_ok553);
  tcase_add_test(tc_core, test_truncate_ok554);
  tcase_add_test(tc_core, test_truncate_ok555);
  tcase_add_test(tc_core, test_truncate_ok556);
  tcase_add_test(tc_core, test_truncate_ok557);
  tcase_add_test(tc_core, test_truncate_ok558);
  tcase_add_test(tc_core, test_truncate_ok559);
  tcase_add_test(tc_core, test_truncate_ok560);
  tcase_add_test(tc_core, test_truncate_ok561);
  tcase_add_test(tc_core, test_truncate_ok562);
  tcase_add_test(tc_core, test_truncate_ok563);
  tcase_add_test(tc_core, test_truncate_ok564);
  tcase_add_test(tc_core, test_truncate_ok565);
  tcase_add_test(tc_core, test_truncate_ok566);
  tcase_add_test(tc_core, test_truncate_ok567);
  tcase_add_test(tc_core, test_truncate_ok568);
  tcase_add_test(tc_core, test_truncate_ok569);
  tcase_add_test(tc_core, test_truncate_ok570);
  tcase_add_test(tc_core, test_truncate_ok571);
  tcase_add_test(tc_core, test_truncate_ok572);
  tcase_add_test(tc_core, test_truncate_ok573);
  tcase_add_test(tc_core, test_truncate_ok574);
  tcase_add_test(tc_core, test_truncate_ok575);
  tcase_add_test(tc_core, test_truncate_ok576);
  tcase_add_test(tc_core, test_truncate_ok577);
  tcase_add_test(tc_core, test_truncate_ok578);
  tcase_add_test(tc_core, test_truncate_ok579);
  tcase_add_test(tc_core, test_truncate_ok580);
  tcase_add_test(tc_core, test_truncate_ok581);
  tcase_add_test(tc_core, test_truncate_ok582);
  tcase_add_test(tc_core, test_truncate_ok583);
  tcase_add_test(tc_core, test_truncate_ok584);
  tcase_add_test(tc_core, test_truncate_ok585);
  tcase_add_test(tc_core, test_truncate_ok586);
  tcase_add_test(tc_core, test_truncate_ok587);
  tcase_add_test(tc_core, test_truncate_ok588);
  tcase_add_test(tc_core, test_truncate_ok589);
  tcase_add_test(tc_core, test_truncate_ok590);
  tcase_add_test(tc_core, test_truncate_ok591);
  tcase_add_test(tc_core, test_truncate_ok592);
  tcase_add_test(tc_core, test_truncate_ok593);
  tcase_add_test(tc_core, test_truncate_ok594);
  tcase_add_test(tc_core, test_truncate_ok595);
  tcase_add_test(tc_core, test_truncate_ok596);
  tcase_add_test(tc_core, test_truncate_ok597);
  tcase_add_test(tc_core, test_truncate_ok598);
  tcase_add_test(tc_core, test_truncate_ok599);
  tcase_add_test(tc_core, test_truncate_ok600);
  tcase_add_test(tc_core, test_truncate_ok601);
  tcase_add_test(tc_core, test_truncate_ok602);
  tcase_add_test(tc_core, test_truncate_ok603);
  tcase_add_test(tc_core, test_truncate_ok604);
  tcase_add_test(tc_core, test_truncate_ok605);
  tcase_add_test(tc_core, test_truncate_ok606);
  tcase_add_test(tc_core, test_truncate_ok607);
  tcase_add_test(tc_core, test_truncate_ok608);
  tcase_add_test(tc_core, test_truncate_ok609);
  tcase_add_test(tc_core, test_truncate_ok610);
  tcase_add_test(tc_core, test_truncate_ok611);
  tcase_add_test(tc_core, test_truncate_ok612);
  tcase_add_test(tc_core, test_truncate_ok613);
  tcase_add_test(tc_core, test_truncate_ok614);
  tcase_add_test(tc_core, test_truncate_ok615);
  tcase_add_test(tc_core, test_truncate_ok616);
  tcase_add_test(tc_core, test_truncate_ok617);
  tcase_add_test(tc_core, test_truncate_ok618);
  tcase_add_test(tc_core, test_truncate_ok619);
  tcase_add_test(tc_core, test_truncate_ok620);
  tcase_add_test(tc_core, test_truncate_ok621);
  tcase_add_test(tc_core, test_truncate_ok622);
  tcase_add_test(tc_core, test_truncate_ok623);
  tcase_add_test(tc_core, test_truncate_ok624);
  tcase_add_test(tc_core, test_truncate_ok625);
  tcase_add_test(tc_core, test_truncate_ok626);
  tcase_add_test(tc_core, test_truncate_ok627);
  tcase_add_test(tc_core, test_truncate_ok628);
  tcase_add_test(tc_core, test_truncate_ok629);
  tcase_add_test(tc_core, test_truncate_ok630);
  tcase_add_test(tc_core, test_truncate_ok631);
  tcase_add_test(tc_core, test_truncate_ok632);
  tcase_add_test(tc_core, test_truncate_ok633);
  tcase_add_test(tc_core, test_truncate_ok634);
  tcase_add_test(tc_core, test_truncate_ok635);
  tcase_add_test(tc_core, test_truncate_ok636);
  tcase_add_test(tc_core, test_truncate_ok637);
  tcase_add_test(tc_core, test_truncate_ok638);
  tcase_add_test(tc_core, test_truncate_ok639);
  tcase_add_test(tc_core, test_truncate_ok640);
  tcase_add_test(tc_core, test_truncate_ok641);
  tcase_add_test(tc_core, test_truncate_ok642);
  tcase_add_test(tc_core, test_truncate_ok643);
  tcase_add_test(tc_core, test_truncate_ok644);
  tcase_add_test(tc_core, test_truncate_ok645);
  tcase_add_test(tc_core, test_truncate_ok646);
  tcase_add_test(tc_core, test_truncate_ok647);
  tcase_add_test(tc_core, test_truncate_ok648);
  tcase_add_test(tc_core, test_truncate_ok649);
  tcase_add_test(tc_core, test_truncate_ok650);
  tcase_add_test(tc_core, test_truncate_ok651);
  tcase_add_test(tc_core, test_truncate_ok652);
  tcase_add_test(tc_core, test_truncate_ok653);
  tcase_add_test(tc_core, test_truncate_ok654);
  tcase_add_test(tc_core, test_truncate_ok655);
  tcase_add_test(tc_core, test_truncate_ok656);
  tcase_add_test(tc_core, test_truncate_ok657);
  tcase_add_test(tc_core, test_truncate_ok658);
  tcase_add_test(tc_core, test_truncate_ok659);
  tcase_add_test(tc_core, test_truncate_ok660);
  tcase_add_test(tc_core, test_truncate_ok661);
  tcase_add_test(tc_core, test_truncate_ok662);
  tcase_add_test(tc_core, test_truncate_ok663);
  tcase_add_test(tc_core, test_truncate_ok664);
  tcase_add_test(tc_core, test_truncate_ok665);
  tcase_add_test(tc_core, test_truncate_ok666);
  tcase_add_test(tc_core, test_truncate_ok667);
  tcase_add_test(tc_core, test_truncate_ok668);
  tcase_add_test(tc_core, test_truncate_ok669);
  tcase_add_test(tc_core, test_truncate_ok670);
  tcase_add_test(tc_core, test_truncate_ok671);
  tcase_add_test(tc_core, test_truncate_ok672);
  tcase_add_test(tc_core, test_truncate_ok673);
  tcase_add_test(tc_core, test_truncate_ok674);
  tcase_add_test(tc_core, test_truncate_ok675);
  tcase_add_test(tc_core, test_truncate_ok676);
  tcase_add_test(tc_core, test_truncate_ok677);
  tcase_add_test(tc_core, test_truncate_ok678);
  tcase_add_test(tc_core, test_truncate_ok679);
  tcase_add_test(tc_core, test_truncate_ok680);
  tcase_add_test(tc_core, test_truncate_ok681);
  tcase_add_test(tc_core, test_truncate_ok682);
  tcase_add_test(tc_core, test_truncate_ok683);
  tcase_add_test(tc_core, test_truncate_ok684);
  tcase_add_test(tc_core, test_truncate_ok685);
  tcase_add_test(tc_core, test_truncate_ok686);
  tcase_add_test(tc_core, test_truncate_ok687);
  tcase_add_test(tc_core, test_truncate_ok688);
  tcase_add_test(tc_core, test_truncate_ok689);
  tcase_add_test(tc_core, test_truncate_ok690);
  tcase_add_test(tc_core, test_truncate_ok691);
  tcase_add_test(tc_core, test_truncate_ok692);
  tcase_add_test(tc_core, test_truncate_ok693);
  tcase_add_test(tc_core, test_truncate_ok694);
  tcase_add_test(tc_core, test_truncate_ok695);
  tcase_add_test(tc_core, test_truncate_ok696);
  tcase_add_test(tc_core, test_truncate_ok697);
  tcase_add_test(tc_core, test_truncate_ok698);
  tcase_add_test(tc_core, test_truncate_ok699);
  tcase_add_test(tc_core, test_truncate_ok700);
  tcase_add_test(tc_core, test_truncate_ok701);
  tcase_add_test(tc_core, test_truncate_ok702);
  tcase_add_test(tc_core, test_truncate_ok703);
  tcase_add_test(tc_core, test_truncate_ok704);
  tcase_add_test(tc_core, test_truncate_ok705);
  tcase_add_test(tc_core, test_truncate_ok706);
  tcase_add_test(tc_core, test_truncate_ok707);
  tcase_add_test(tc_core, test_truncate_ok708);
  tcase_add_test(tc_core, test_truncate_ok709);
  tcase_add_test(tc_core, test_truncate_ok710);
  tcase_add_test(tc_core, test_truncate_ok711);
  tcase_add_test(tc_core, test_truncate_ok712);
  tcase_add_test(tc_core, test_truncate_ok713);
  tcase_add_test(tc_core, test_truncate_ok714);
  tcase_add_test(tc_core, test_truncate_ok715);
  tcase_add_test(tc_core, test_truncate_ok716);
  tcase_add_test(tc_core, test_truncate_ok717);
  tcase_add_test(tc_core, test_truncate_ok718);
  tcase_add_test(tc_core, test_truncate_ok719);
  tcase_add_test(tc_core, test_truncate_ok720);
  tcase_add_test(tc_core, test_truncate_ok721);
  tcase_add_test(tc_core, test_truncate_ok722);
  tcase_add_test(tc_core, test_truncate_ok723);
  tcase_add_test(tc_core, test_truncate_ok724);
  tcase_add_test(tc_core, test_truncate_ok725);
  tcase_add_test(tc_core, test_truncate_ok726);
  tcase_add_test(tc_core, test_truncate_ok727);
  tcase_add_test(tc_core, test_truncate_ok728);
  tcase_add_test(tc_core, test_truncate_ok729);
  tcase_add_test(tc_core, test_truncate_ok730);
  tcase_add_test(tc_core, test_truncate_ok731);
  tcase_add_test(tc_core, test_truncate_ok732);
  tcase_add_test(tc_core, test_truncate_ok733);
  tcase_add_test(tc_core, test_truncate_ok734);
  tcase_add_test(tc_core, test_truncate_ok735);
  tcase_add_test(tc_core, test_truncate_ok736);
  tcase_add_test(tc_core, test_truncate_ok737);
  tcase_add_test(tc_core, test_truncate_ok738);
  tcase_add_test(tc_core, test_truncate_ok739);
  tcase_add_test(tc_core, test_truncate_ok740);
  tcase_add_test(tc_core, test_truncate_ok741);
  tcase_add_test(tc_core, test_truncate_ok742);
  tcase_add_test(tc_core, test_truncate_ok743);
  tcase_add_test(tc_core, test_truncate_ok744);
  tcase_add_test(tc_core, test_truncate_ok745);
  tcase_add_test(tc_core, test_truncate_ok746);
  tcase_add_test(tc_core, test_truncate_ok747);
  tcase_add_test(tc_core, test_truncate_ok748);
  tcase_add_test(tc_core, test_truncate_ok749);
  tcase_add_test(tc_core, test_truncate_ok750);
  tcase_add_test(tc_core, test_truncate_ok751);
  tcase_add_test(tc_core, test_truncate_ok752);
  tcase_add_test(tc_core, test_truncate_ok753);
  tcase_add_test(tc_core, test_truncate_ok754);
  tcase_add_test(tc_core, test_truncate_ok755);
  tcase_add_test(tc_core, test_truncate_ok756);
  tcase_add_test(tc_core, test_truncate_ok757);
  tcase_add_test(tc_core, test_truncate_ok758);
  tcase_add_test(tc_core, test_truncate_ok759);
  tcase_add_test(tc_core, test_truncate_ok760);
  tcase_add_test(tc_core, test_truncate_ok761);
  tcase_add_test(tc_core, test_truncate_ok762);
  tcase_add_test(tc_core, test_truncate_ok763);
  tcase_add_test(tc_core, test_truncate_ok764);
  tcase_add_test(tc_core, test_truncate_ok765);
  tcase_add_test(tc_core, test_truncate_ok766);
  tcase_add_test(tc_core, test_truncate_ok767);
  tcase_add_test(tc_core, test_truncate_ok768);
  tcase_add_test(tc_core, test_truncate_ok769);
  tcase_add_test(tc_core, test_truncate_ok770);
  tcase_add_test(tc_core, test_truncate_ok771);
  tcase_add_test(tc_core, test_truncate_ok772);
  tcase_add_test(tc_core, test_truncate_ok773);
  tcase_add_test(tc_core, test_truncate_ok774);
  tcase_add_test(tc_core, test_truncate_ok775);
  tcase_add_test(tc_core, test_truncate_ok776);
  tcase_add_test(tc_core, test_truncate_ok777);
  tcase_add_test(tc_core, test_truncate_ok778);
  tcase_add_test(tc_core, test_truncate_ok779);
  tcase_add_test(tc_core, test_truncate_ok780);
  tcase_add_test(tc_core, test_truncate_ok781);
  tcase_add_test(tc_core, test_truncate_ok782);
  tcase_add_test(tc_core, test_truncate_ok783);
  tcase_add_test(tc_core, test_truncate_ok784);
  tcase_add_test(tc_core, test_truncate_ok785);
  tcase_add_test(tc_core, test_truncate_ok786);
  tcase_add_test(tc_core, test_truncate_ok787);
  tcase_add_test(tc_core, test_truncate_ok788);
  tcase_add_test(tc_core, test_truncate_ok789);
  tcase_add_test(tc_core, test_truncate_ok790);
  tcase_add_test(tc_core, test_truncate_ok791);
  tcase_add_test(tc_core, test_truncate_ok792);
  tcase_add_test(tc_core, test_truncate_ok793);
  tcase_add_test(tc_core, test_truncate_ok794);
  tcase_add_test(tc_core, test_truncate_ok795);
  tcase_add_test(tc_core, test_truncate_ok796);
  tcase_add_test(tc_core, test_truncate_ok797);
  tcase_add_test(tc_core, test_truncate_ok798);
  tcase_add_test(tc_core, test_truncate_ok799);
  tcase_add_test(tc_core, test_truncate_ok800);

  suite_add_tcase(s, tc_core);
  return s;
}

Suite *truncate_suite3(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("truncate_suite3");
  tc_core = tcase_create("Core");
  tcase_add_test(tc_core, test_truncate_ok801);
  tcase_add_test(tc_core, test_truncate_ok802);
  tcase_add_test(tc_core, test_truncate_ok803);
  tcase_add_test(tc_core, test_truncate_ok804);
  tcase_add_test(tc_core, test_truncate_ok805);
  tcase_add_test(tc_core, test_truncate_ok806);
  tcase_add_test(tc_core, test_truncate_ok807);
  tcase_add_test(tc_core, test_truncate_ok808);
  tcase_add_test(tc_core, test_truncate_ok809);
  tcase_add_test(tc_core, test_truncate_ok810);
  tcase_add_test(tc_core, test_truncate_ok811);
  tcase_add_test(tc_core, test_truncate_ok812);
  tcase_add_test(tc_core, test_truncate_ok813);
  tcase_add_test(tc_core, test_truncate_ok814);
  tcase_add_test(tc_core, test_truncate_ok815);
  tcase_add_test(tc_core, test_truncate_ok816);
  tcase_add_test(tc_core, test_truncate_ok817);
  tcase_add_test(tc_core, test_truncate_ok818);
  tcase_add_test(tc_core, test_truncate_ok819);
  tcase_add_test(tc_core, test_truncate_ok820);
  tcase_add_test(tc_core, test_truncate_ok821);
  tcase_add_test(tc_core, test_truncate_ok822);
  tcase_add_test(tc_core, test_truncate_ok823);
  tcase_add_test(tc_core, test_truncate_ok824);
  tcase_add_test(tc_core, test_truncate_ok825);
  tcase_add_test(tc_core, test_truncate_ok826);
  tcase_add_test(tc_core, test_truncate_ok827);
  tcase_add_test(tc_core, test_truncate_ok828);
  tcase_add_test(tc_core, test_truncate_ok829);
  tcase_add_test(tc_core, test_truncate_ok830);
  tcase_add_test(tc_core, test_truncate_ok831);
  tcase_add_test(tc_core, test_truncate_ok832);
  tcase_add_test(tc_core, test_truncate_ok833);
  tcase_add_test(tc_core, test_truncate_ok834);
  tcase_add_test(tc_core, test_truncate_ok835);
  tcase_add_test(tc_core, test_truncate_ok836);
  tcase_add_test(tc_core, test_truncate_ok837);
  tcase_add_test(tc_core, test_truncate_ok838);
  tcase_add_test(tc_core, test_truncate_ok839);
  tcase_add_test(tc_core, test_truncate_ok840);
  tcase_add_test(tc_core, test_truncate_ok841);
  tcase_add_test(tc_core, test_truncate_ok842);
  tcase_add_test(tc_core, test_truncate_ok843);
  tcase_add_test(tc_core, test_truncate_ok844);
  tcase_add_test(tc_core, test_truncate_ok845);
  tcase_add_test(tc_core, test_truncate_ok846);
  tcase_add_test(tc_core, test_truncate_ok847);
  tcase_add_test(tc_core, test_truncate_ok848);
  tcase_add_test(tc_core, test_truncate_ok849);
  tcase_add_test(tc_core, test_truncate_ok850);
  tcase_add_test(tc_core, test_truncate_ok851);
  tcase_add_test(tc_core, test_truncate_ok852);
  tcase_add_test(tc_core, test_truncate_ok853);
  tcase_add_test(tc_core, test_truncate_ok854);
  tcase_add_test(tc_core, test_truncate_ok855);
  tcase_add_test(tc_core, test_truncate_ok856);
  tcase_add_test(tc_core, test_truncate_ok857);
  tcase_add_test(tc_core, test_truncate_ok858);
  tcase_add_test(tc_core, test_truncate_ok859);
  tcase_add_test(tc_core, test_truncate_ok860);
  tcase_add_test(tc_core, test_truncate_ok861);
  tcase_add_test(tc_core, test_truncate_ok862);
  tcase_add_test(tc_core, test_truncate_ok863);
  tcase_add_test(tc_core, test_truncate_ok864);
  tcase_add_test(tc_core, test_truncate_ok865);
  tcase_add_test(tc_core, test_truncate_ok866);
  tcase_add_test(tc_core, test_truncate_ok867);
  tcase_add_test(tc_core, test_truncate_ok868);
  tcase_add_test(tc_core, test_truncate_ok869);
  tcase_add_test(tc_core, test_truncate_ok870);
  tcase_add_test(tc_core, test_truncate_ok871);
  tcase_add_test(tc_core, test_truncate_ok872);
  tcase_add_test(tc_core, test_truncate_ok873);
  tcase_add_test(tc_core, test_truncate_ok874);
  tcase_add_test(tc_core, test_truncate_ok875);
  tcase_add_test(tc_core, test_truncate_ok876);
  tcase_add_test(tc_core, test_truncate_ok877);
  tcase_add_test(tc_core, test_truncate_ok878);
  tcase_add_test(tc_core, test_truncate_ok879);
  tcase_add_test(tc_core, test_truncate_ok880);
  tcase_add_test(tc_core, test_truncate_ok881);
  tcase_add_test(tc_core, test_truncate_ok882);
  tcase_add_test(tc_core, test_truncate_ok883);
  tcase_add_test(tc_core, test_truncate_ok884);
  tcase_add_test(tc_core, test_truncate_ok885);
  tcase_add_test(tc_core, test_truncate_ok886);
  tcase_add_test(tc_core, test_truncate_ok887);
  tcase_add_test(tc_core, test_truncate_ok888);
  tcase_add_test(tc_core, test_truncate_ok889);
  tcase_add_test(tc_core, test_truncate_ok890);
  tcase_add_test(tc_core, test_truncate_ok891);
  tcase_add_test(tc_core, test_truncate_ok892);
  tcase_add_test(tc_core, test_truncate_ok893);
  tcase_add_test(tc_core, test_truncate_ok894);
  tcase_add_test(tc_core, test_truncate_ok895);
  tcase_add_test(tc_core, test_truncate_ok896);
  tcase_add_test(tc_core, test_truncate_ok897);
  tcase_add_test(tc_core, test_truncate_ok898);
  tcase_add_test(tc_core, test_truncate_ok899);
  tcase_add_test(tc_core, test_truncate_ok900);
  tcase_add_test(tc_core, test_truncate_ok901);
  tcase_add_test(tc_core, test_truncate_ok902);
  tcase_add_test(tc_core, test_truncate_ok903);
  tcase_add_test(tc_core, test_truncate_ok904);
  tcase_add_test(tc_core, test_truncate_ok905);
  tcase_add_test(tc_core, test_truncate_ok906);
  tcase_add_test(tc_core, test_truncate_ok907);
  tcase_add_test(tc_core, test_truncate_ok908);
  tcase_add_test(tc_core, test_truncate_ok909);
  tcase_add_test(tc_core, test_truncate_ok910);
  tcase_add_test(tc_core, test_truncate_ok911);
  tcase_add_test(tc_core, test_truncate_ok912);
  tcase_add_test(tc_core, test_truncate_ok913);
  tcase_add_test(tc_core, test_truncate_ok914);
  tcase_add_test(tc_core, test_truncate_ok915);
  tcase_add_test(tc_core, test_truncate_ok916);
  tcase_add_test(tc_core, test_truncate_ok917);
  tcase_add_test(tc_core, test_truncate_ok918);
  tcase_add_test(tc_core, test_truncate_ok919);
  tcase_add_test(tc_core, test_truncate_ok920);
  tcase_add_test(tc_core, test_truncate_ok921);
  tcase_add_test(tc_core, test_truncate_ok922);
  tcase_add_test(tc_core, test_truncate_ok923);
  tcase_add_test(tc_core, test_truncate_ok924);
  tcase_add_test(tc_core, test_truncate_ok925);
  tcase_add_test(tc_core, test_truncate_ok926);
  tcase_add_test(tc_core, test_truncate_ok927);
  tcase_add_test(tc_core, test_truncate_ok928);
  tcase_add_test(tc_core, test_truncate_ok929);
  tcase_add_test(tc_core, test_truncate_ok930);
  tcase_add_test(tc_core, test_truncate_ok931);
  tcase_add_test(tc_core, test_truncate_ok932);
  tcase_add_test(tc_core, test_truncate_ok933);
  tcase_add_test(tc_core, test_truncate_ok934);
  tcase_add_test(tc_core, test_truncate_ok935);
  tcase_add_test(tc_core, test_truncate_ok936);
  tcase_add_test(tc_core, test_truncate_ok937);
  tcase_add_test(tc_core, test_truncate_ok938);
  tcase_add_test(tc_core, test_truncate_ok939);
  tcase_add_test(tc_core, test_truncate_ok940);
  tcase_add_test(tc_core, test_truncate_ok941);
  tcase_add_test(tc_core, test_truncate_ok942);
  tcase_add_test(tc_core, test_truncate_ok943);
  tcase_add_test(tc_core, test_truncate_ok944);
  tcase_add_test(tc_core, test_truncate_ok945);
  tcase_add_test(tc_core, test_truncate_ok946);
  tcase_add_test(tc_core, test_truncate_ok947);
  tcase_add_test(tc_core, test_truncate_ok948);
  tcase_add_test(tc_core, test_truncate_ok949);
  tcase_add_test(tc_core, test_truncate_ok950);
  tcase_add_test(tc_core, test_truncate_ok951);
  tcase_add_test(tc_core, test_truncate_ok952);
  tcase_add_test(tc_core, test_truncate_ok953);
  tcase_add_test(tc_core, test_truncate_ok954);
  tcase_add_test(tc_core, test_truncate_ok955);
  tcase_add_test(tc_core, test_truncate_ok956);
  tcase_add_test(tc_core, test_truncate_ok957);
  tcase_add_test(tc_core, test_truncate_ok958);
  tcase_add_test(tc_core, test_truncate_ok959);
  tcase_add_test(tc_core, test_truncate_ok960);
  tcase_add_test(tc_core, test_truncate_ok961);
  tcase_add_test(tc_core, test_truncate_ok962);
  tcase_add_test(tc_core, test_truncate_ok963);
  tcase_add_test(tc_core, test_truncate_ok964);
  tcase_add_test(tc_core, test_truncate_ok965);
  tcase_add_test(tc_core, test_truncate_ok966);
  tcase_add_test(tc_core, test_truncate_ok967);
  tcase_add_test(tc_core, test_truncate_ok968);
  tcase_add_test(tc_core, test_truncate_ok969);
  tcase_add_test(tc_core, test_truncate_ok970);
  tcase_add_test(tc_core, test_truncate_ok971);
  tcase_add_test(tc_core, test_truncate_ok972);
  tcase_add_test(tc_core, test_truncate_ok973);
  tcase_add_test(tc_core, test_truncate_ok974);
  tcase_add_test(tc_core, test_truncate_ok975);
  tcase_add_test(tc_core, test_truncate_ok976);
  tcase_add_test(tc_core, test_truncate_ok977);
  tcase_add_test(tc_core, test_truncate_ok978);
  tcase_add_test(tc_core, test_truncate_ok979);
  tcase_add_test(tc_core, test_truncate_ok980);
  tcase_add_test(tc_core, test_truncate_ok981);
  tcase_add_test(tc_core, test_truncate_ok982);
  tcase_add_test(tc_core, test_truncate_ok983);
  tcase_add_test(tc_core, test_truncate_ok984);
  tcase_add_test(tc_core, test_truncate_ok985);
  tcase_add_test(tc_core, test_truncate_ok986);
  tcase_add_test(tc_core, test_truncate_ok987);
  tcase_add_test(tc_core, test_truncate_ok988);
  tcase_add_test(tc_core, test_truncate_ok989);
  tcase_add_test(tc_core, test_truncate_ok990);
  tcase_add_test(tc_core, test_truncate_ok991);
  tcase_add_test(tc_core, test_truncate_ok992);
  tcase_add_test(tc_core, test_truncate_ok993);
  tcase_add_test(tc_core, test_truncate_ok994);
  tcase_add_test(tc_core, test_truncate_ok995);
  tcase_add_test(tc_core, test_truncate_ok996);
  tcase_add_test(tc_core, test_truncate_ok997);
  tcase_add_test(tc_core, test_truncate_ok998);
  tcase_add_test(tc_core, test_truncate_ok999);
  tcase_add_test(tc_core, test_truncate_ok1000);
  tcase_add_test(tc_core, test_truncate_ok1001);
  tcase_add_test(tc_core, test_truncate_ok1002);
  tcase_add_test(tc_core, test_truncate_ok1003);
  tcase_add_test(tc_core, test_truncate_ok1004);
  tcase_add_test(tc_core, test_truncate_ok1005);
  tcase_add_test(tc_core, test_truncate_ok1006);
  tcase_add_test(tc_core, test_truncate_ok1007);
  tcase_add_test(tc_core, test_truncate_ok1008);
  tcase_add_test(tc_core, test_truncate_ok1009);
  tcase_add_test(tc_core, test_truncate_ok1010);
  tcase_add_test(tc_core, test_truncate_ok1011);
  tcase_add_test(tc_core, test_truncate_ok1012);
  tcase_add_test(tc_core, test_truncate_ok1013);
  tcase_add_test(tc_core, test_truncate_ok1014);
  tcase_add_test(tc_core, test_truncate_ok1015);
  tcase_add_test(tc_core, test_truncate_ok1016);
  tcase_add_test(tc_core, test_truncate_ok1017);
  tcase_add_test(tc_core, test_truncate_ok1018);
  tcase_add_test(tc_core, test_truncate_ok1019);
  tcase_add_test(tc_core, test_truncate_ok1020);

  suite_add_tcase(s, tc_core);
  return s;
}

Suite *truncate_suite0(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("truncate_suite0");
  tc_core = tcase_create("Core");
  tcase_add_test(tc_core, test_truncate_fail1);
  tcase_add_test(tc_core, test_truncate_fail2);
  tcase_add_test(tc_core, test_truncate_fail3);
  tcase_add_test(tc_core, test_truncate_fail4);
  tcase_add_test(tc_core, test_truncate_fail5);
  tcase_add_test(tc_core, test_truncate_fail6);
  tcase_add_test(tc_core, test_truncate_fail7);
  tcase_add_test(tc_core, test_truncate_fail8);
  tcase_add_test(tc_core, test_truncate_fail9);

  suite_add_tcase(s, tc_core);
  return s;
}

void test_truncate(my_decimal decimal, my_decimal decimal_check) {
  my_decimal result;

  int code = my_truncate(decimal, &result);
  int sign_check = test_decimal_get_sign(decimal_check);
  int sign_result = test_decimal_get_sign(result);

#if defined(__DEBUG)
  printf("---------------------------------\n");
  printf("\n\nTests:\n");
  my_print_decimal_bits(decimal);
  my_print_decimal_string(decimal);
  printf("\ncheck:\n");
  my_print_decimal_bits(decimal_check);
  my_print_decimal_string(decimal_check);
  printf("sign = %d\n", sign_check);
  printf("\nres:\n");
  my_print_decimal_bits(result);
  my_print_decimal_string(result);
  printf("sign = %d\n", sign_result);
  printf("---------------------------------\n\n\n\n");
#endif

  ck_assert_int_eq(code, TEST_OTHER_OK);
  ck_assert_int_eq(test_decimal_is_full_equal(result, decimal_check), 1);
  ck_assert_int_eq(sign_check, sign_result);
}
