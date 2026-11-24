#include <stdio.h>
#include <stdlib.h>

#include "./../../my_decimal.h"
#include "./../test.h"

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * * * * * * * * * * * * * * Тесты на некорректные данные (ручные)
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * * * * * * * * * * * * * */

START_TEST(test_round_fail1) {
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x140000}};

  int code = my_round(decimal, NULL);

  ck_assert_int_eq(code, TEST_OTHER_ERROR);
}

START_TEST(test_round_fail2) {
  my_decimal decimal = {{0, 0, 0, 1000000000}};
  my_decimal result;

  int code = my_round(decimal, &result);

  ck_assert_int_eq(code, TEST_OTHER_ERROR);
}
END_TEST

START_TEST(test_round_fail3) {
  my_decimal decimal = {{-1, 0, 0, 0x1D0000}};
  my_decimal result;

  int code = my_round(decimal, &result);

  ck_assert_int_eq(code, TEST_OTHER_ERROR);
}
END_TEST

START_TEST(test_round_fail4) {
  my_decimal decimal = {{0, 0, 0, 0x1D0000}};
  my_decimal result;

  int code = my_round(decimal, &result);

  ck_assert_int_eq(code, TEST_OTHER_ERROR);
}
END_TEST

START_TEST(test_round_fail5) {
  my_decimal decimal = {{-1, 0, 0, 0x1C0001}};
  my_decimal result;

  int code = my_round(decimal, &result);

  ck_assert_int_eq(code, TEST_OTHER_ERROR);
}
END_TEST

START_TEST(test_round_fail6) {
  my_decimal decimal = {{-1, 0, 0, 0x1C8000}};
  my_decimal result;

  int code = my_round(decimal, &result);

  ck_assert_int_eq(code, TEST_OTHER_ERROR);
}
END_TEST

START_TEST(test_round_fail7) {
  my_decimal decimal = {{-1, 0, 0, 0x11C0000}};
  my_decimal result;

  int code = my_round(decimal, &result);

  ck_assert_int_eq(code, TEST_OTHER_ERROR);
}
END_TEST

START_TEST(test_round_fail8) {
  my_decimal decimal = {{-1, 0, 0, 0x401C0000}};
  my_decimal result;

  int code = my_round(decimal, &result);

  ck_assert_int_eq(code, TEST_OTHER_ERROR);
}
END_TEST

START_TEST(test_round_fail9) {
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF}};
  my_decimal result;

  int code = my_round(decimal, &result);

  ck_assert_int_eq(code, TEST_OTHER_ERROR);
}
END_TEST

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * * * * * * * * * * * * * * * Tests for correct data (automatic)
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * * * * * * * * * * * * * * */

START_TEST(test_round_ok1) {
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};

  my_decimal decimal_check = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok2) {
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};

  my_decimal decimal_check = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok3) {
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};

  my_decimal decimal_check = {{0x9999999A, 0x99999999, 0x19999999, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok4) {
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80010000}};

  my_decimal decimal_check = {
      {0x9999999A, 0x99999999, 0x19999999, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok5) {
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x20000}};

  my_decimal decimal_check = {{0x28F5C28F, 0xF5C28F5C, 0x28F5C28, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok6) {
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80020000}};

  my_decimal decimal_check = {{0x28F5C28F, 0xF5C28F5C, 0x28F5C28, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok7) {
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x30000}};

  my_decimal decimal_check = {{0x9DB22D0E, 0x4BC6A7EF, 0x418937, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok8) {
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80030000}};

  my_decimal decimal_check = {{0x9DB22D0E, 0x4BC6A7EF, 0x418937, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok9) {
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x40000}};

  my_decimal decimal_check = {{0x295E9E1B, 0xBAC710CB, 0x68DB8, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok10) {
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80040000}};

  my_decimal decimal_check = {{0x295E9E1B, 0xBAC710CB, 0x68DB8, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok11) {
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x50000}};

  my_decimal decimal_check = {{0x84230FD0, 0xAC471B47, 0xA7C5, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok12) {
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80050000}};

  my_decimal decimal_check = {{0x84230FD0, 0xAC471B47, 0xA7C5, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok13) {
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x60000}};

  my_decimal decimal_check = {{0x8D36B4C8, 0xF7A0B5ED, 0x10C6, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok14) {
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80060000}};

  my_decimal decimal_check = {{0x8D36B4C8, 0xF7A0B5ED, 0x10C6, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok15) {
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x70000}};

  my_decimal decimal_check = {{0xF485787A, 0x7F29ABCA, 0x1AD, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok16) {
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80070000}};

  my_decimal decimal_check = {{0xF485787A, 0x7F29ABCA, 0x1AD, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok17) {
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000}};

  my_decimal decimal_check = {{0x1873BF3F, 0xF31DC461, 0x2A, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok18) {
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80080000}};

  my_decimal decimal_check = {{0x1873BF3F, 0xF31DC461, 0x2A, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok19) {
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x90000}};

  my_decimal decimal_check = {{0xB5A52CBA, 0x4B82FA09, 0x4, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok20) {
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80090000}};

  my_decimal decimal_check = {{0xB5A52CBA, 0x4B82FA09, 0x4, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok21) {
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xA0000}};

  my_decimal decimal_check = {{0x5EF6EADF, 0x6DF37F67, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok22) {
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x800A0000}};

  my_decimal decimal_check = {{0x5EF6EADF, 0x6DF37F67, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok23) {
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xB0000}};

  my_decimal decimal_check = {{0xBCB24AB0, 0xAFEBFF0, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok24) {
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x800B0000}};

  my_decimal decimal_check = {{0xBCB24AB0, 0xAFEBFF0, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok25) {
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xC0000}};

  my_decimal decimal_check = {{0x12DEA112, 0x1197998, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok26) {
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x800C0000}};

  my_decimal decimal_check = {{0x12DEA112, 0x1197998, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok27) {
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xD0000}};

  my_decimal decimal_check = {{0x68497682, 0x1C25C2, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok28) {
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x800D0000}};

  my_decimal decimal_check = {{0x68497682, 0x1C25C2, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok29) {
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xE0000}};

  my_decimal decimal_check = {{0x70D42573, 0x2D093, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok30) {
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x800E0000}};

  my_decimal decimal_check = {{0x70D42573, 0x2D093, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok31) {
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xF0000}};

  my_decimal decimal_check = {{0xBE7B9D58, 0x480E, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok32) {
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x800F0000}};

  my_decimal decimal_check = {{0xBE7B9D58, 0x480E, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok33) {
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x100000}};

  my_decimal decimal_check = {{0xACA5F622, 0x734, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok34) {
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80100000}};

  my_decimal decimal_check = {{0xACA5F622, 0x734, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok35) {
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x110000}};

  my_decimal decimal_check = {{0x77AA3237, 0xB8, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok36) {
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80110000}};

  my_decimal decimal_check = {{0x77AA3237, 0xB8, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok37) {
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x120000}};

  my_decimal decimal_check = {{0x725DD1D2, 0x12, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok38) {
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80120000}};

  my_decimal decimal_check = {{0x725DD1D2, 0x12, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok39) {
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x130000}};

  my_decimal decimal_check = {{0xD83C94FB, 0x1, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok40) {
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80130000}};

  my_decimal decimal_check = {{0xD83C94FB, 0x1, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok41) {
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x140000}};

  my_decimal decimal_check = {{0x2F394219, 0x0, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok42) {
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80140000}};

  my_decimal decimal_check = {{0x2F394219, 0x0, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok43) {
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x150000}};

  my_decimal decimal_check = {{0x4B8ED03, 0x0, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok44) {
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80150000}};

  my_decimal decimal_check = {{0x4B8ED03, 0x0, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok45) {
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x160000}};

  my_decimal decimal_check = {{0x78E480, 0x0, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok46) {
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80160000}};

  my_decimal decimal_check = {{0x78E480, 0x0, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok47) {
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x170000}};

  my_decimal decimal_check = {{0xC16DA, 0x0, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok48) {
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80170000}};

  my_decimal decimal_check = {{0xC16DA, 0x0, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok49) {
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x180000}};

  my_decimal decimal_check = {{0x1357C, 0x0, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok50) {
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80180000}};

  my_decimal decimal_check = {{0x1357C, 0x0, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok51) {
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x190000}};

  my_decimal decimal_check = {{0x1EF3, 0x0, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok52) {
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80190000}};

  my_decimal decimal_check = {{0x1EF3, 0x0, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok53) {
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x1A0000}};

  my_decimal decimal_check = {{0x318, 0x0, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok54) {
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x801A0000}};

  my_decimal decimal_check = {{0x318, 0x0, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok55) {
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x1B0000}};

  my_decimal decimal_check = {{0x4F, 0x0, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok56) {
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x801B0000}};

  my_decimal decimal_check = {{0x4F, 0x0, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok57) {
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x1C0000}};

  my_decimal decimal_check = {{0x8, 0x0, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok58) {
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x801C0000}};

  my_decimal decimal_check = {{0x8, 0x0, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok59) {
  my_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};

  my_decimal decimal_check = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok60) {
  my_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};

  my_decimal decimal_check = {
      {0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok61) {
  my_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};

  my_decimal decimal_check = {{0x99999999, 0x99999999, 0x19999999, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok62) {
  my_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80010000}};

  my_decimal decimal_check = {
      {0x99999999, 0x99999999, 0x19999999, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok63) {
  my_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x20000}};

  my_decimal decimal_check = {{0x28F5C28F, 0xF5C28F5C, 0x28F5C28, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok64) {
  my_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80020000}};

  my_decimal decimal_check = {{0x28F5C28F, 0xF5C28F5C, 0x28F5C28, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok65) {
  my_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x30000}};

  my_decimal decimal_check = {{0x9DB22D0E, 0x4BC6A7EF, 0x418937, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok66) {
  my_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80030000}};

  my_decimal decimal_check = {{0x9DB22D0E, 0x4BC6A7EF, 0x418937, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok67) {
  my_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x40000}};

  my_decimal decimal_check = {{0x295E9E1B, 0xBAC710CB, 0x68DB8, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok68) {
  my_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80040000}};

  my_decimal decimal_check = {{0x295E9E1B, 0xBAC710CB, 0x68DB8, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok69) {
  my_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x50000}};

  my_decimal decimal_check = {{0x84230FD0, 0xAC471B47, 0xA7C5, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok70) {
  my_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80050000}};

  my_decimal decimal_check = {{0x84230FD0, 0xAC471B47, 0xA7C5, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok71) {
  my_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x60000}};

  my_decimal decimal_check = {{0x8D36B4C8, 0xF7A0B5ED, 0x10C6, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok72) {
  my_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80060000}};

  my_decimal decimal_check = {{0x8D36B4C8, 0xF7A0B5ED, 0x10C6, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok73) {
  my_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x70000}};

  my_decimal decimal_check = {{0xF485787A, 0x7F29ABCA, 0x1AD, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok74) {
  my_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80070000}};

  my_decimal decimal_check = {{0xF485787A, 0x7F29ABCA, 0x1AD, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok75) {
  my_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000}};

  my_decimal decimal_check = {{0x1873BF3F, 0xF31DC461, 0x2A, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok76) {
  my_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80080000}};

  my_decimal decimal_check = {{0x1873BF3F, 0xF31DC461, 0x2A, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok77) {
  my_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x90000}};

  my_decimal decimal_check = {{0xB5A52CBA, 0x4B82FA09, 0x4, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok78) {
  my_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80090000}};

  my_decimal decimal_check = {{0xB5A52CBA, 0x4B82FA09, 0x4, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok79) {
  my_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0xA0000}};

  my_decimal decimal_check = {{0x5EF6EADF, 0x6DF37F67, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok80) {
  my_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x800A0000}};

  my_decimal decimal_check = {{0x5EF6EADF, 0x6DF37F67, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok81) {
  my_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0xB0000}};

  my_decimal decimal_check = {{0xBCB24AB0, 0xAFEBFF0, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok82) {
  my_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x800B0000}};

  my_decimal decimal_check = {{0xBCB24AB0, 0xAFEBFF0, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok83) {
  my_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0xC0000}};

  my_decimal decimal_check = {{0x12DEA112, 0x1197998, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok84) {
  my_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x800C0000}};

  my_decimal decimal_check = {{0x12DEA112, 0x1197998, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok85) {
  my_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0xD0000}};

  my_decimal decimal_check = {{0x68497682, 0x1C25C2, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok86) {
  my_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x800D0000}};

  my_decimal decimal_check = {{0x68497682, 0x1C25C2, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok87) {
  my_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0xE0000}};

  my_decimal decimal_check = {{0x70D42573, 0x2D093, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok88) {
  my_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x800E0000}};

  my_decimal decimal_check = {{0x70D42573, 0x2D093, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok89) {
  my_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0xF0000}};

  my_decimal decimal_check = {{0xBE7B9D58, 0x480E, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok90) {
  my_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x800F0000}};

  my_decimal decimal_check = {{0xBE7B9D58, 0x480E, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok91) {
  my_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x100000}};

  my_decimal decimal_check = {{0xACA5F622, 0x734, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok92) {
  my_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80100000}};

  my_decimal decimal_check = {{0xACA5F622, 0x734, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok93) {
  my_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x110000}};

  my_decimal decimal_check = {{0x77AA3237, 0xB8, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok94) {
  my_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80110000}};

  my_decimal decimal_check = {{0x77AA3237, 0xB8, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok95) {
  my_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x120000}};

  my_decimal decimal_check = {{0x725DD1D2, 0x12, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok96) {
  my_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80120000}};

  my_decimal decimal_check = {{0x725DD1D2, 0x12, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok97) {
  my_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x130000}};

  my_decimal decimal_check = {{0xD83C94FB, 0x1, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok98) {
  my_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80130000}};

  my_decimal decimal_check = {{0xD83C94FB, 0x1, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok99) {
  my_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x140000}};

  my_decimal decimal_check = {{0x2F394219, 0x0, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok100) {
  my_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80140000}};

  my_decimal decimal_check = {{0x2F394219, 0x0, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok101) {
  my_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x150000}};

  my_decimal decimal_check = {{0x4B8ED03, 0x0, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok102) {
  my_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80150000}};

  my_decimal decimal_check = {{0x4B8ED03, 0x0, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok103) {
  my_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x160000}};

  my_decimal decimal_check = {{0x78E480, 0x0, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok104) {
  my_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80160000}};

  my_decimal decimal_check = {{0x78E480, 0x0, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok105) {
  my_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x170000}};

  my_decimal decimal_check = {{0xC16DA, 0x0, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok106) {
  my_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80170000}};

  my_decimal decimal_check = {{0xC16DA, 0x0, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok107) {
  my_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x180000}};

  my_decimal decimal_check = {{0x1357C, 0x0, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok108) {
  my_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80180000}};

  my_decimal decimal_check = {{0x1357C, 0x0, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok109) {
  my_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x190000}};

  my_decimal decimal_check = {{0x1EF3, 0x0, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok110) {
  my_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80190000}};

  my_decimal decimal_check = {{0x1EF3, 0x0, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok111) {
  my_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x1A0000}};

  my_decimal decimal_check = {{0x318, 0x0, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok112) {
  my_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x801A0000}};

  my_decimal decimal_check = {{0x318, 0x0, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok113) {
  my_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x1B0000}};

  my_decimal decimal_check = {{0x4F, 0x0, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok114) {
  my_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x801B0000}};

  my_decimal decimal_check = {{0x4F, 0x0, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok115) {
  my_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x1C0000}};

  my_decimal decimal_check = {{0x8, 0x0, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok116) {
  my_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x801C0000}};

  my_decimal decimal_check = {{0x8, 0x0, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok117) {
  my_decimal decimal = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x0}};

  my_decimal decimal_check = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok118) {
  my_decimal decimal = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x80000000}};

  my_decimal decimal_check = {
      {0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok119) {
  my_decimal decimal = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x10000}};

  my_decimal decimal_check = {{0x11111111, 0x11111111, 0x11111111, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok120) {
  my_decimal decimal = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x80010000}};

  my_decimal decimal_check = {
      {0x11111111, 0x11111111, 0x11111111, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok121) {
  my_decimal decimal = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0xD0000}};

  my_decimal decimal_check = {{0xF030F9AC, 0x12C3D6, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok122) {
  my_decimal decimal = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x800D0000}};

  my_decimal decimal_check = {{0xF030F9AC, 0x12C3D6, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok123) {
  my_decimal decimal = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x1C0000}};

  my_decimal decimal_check = {{0x5, 0x0, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok124) {
  my_decimal decimal = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x801C0000}};

  my_decimal decimal_check = {{0x5, 0x0, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok125) {
  my_decimal decimal = {{0x0, 0xAAAAAAAA, 0xAAAAAAAA, 0x0}};

  my_decimal decimal_check = {{0x0, 0xAAAAAAAA, 0xAAAAAAAA, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok126) {
  my_decimal decimal = {{0x0, 0xAAAAAAAA, 0xAAAAAAAA, 0x80000000}};

  my_decimal decimal_check = {{0x0, 0xAAAAAAAA, 0xAAAAAAAA, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok127) {
  my_decimal decimal = {{0x0, 0xAAAAAAAA, 0xAAAAAAAA, 0x10000}};

  my_decimal decimal_check = {{0x0, 0x11111111, 0x11111111, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok128) {
  my_decimal decimal = {{0x0, 0xAAAAAAAA, 0xAAAAAAAA, 0x80010000}};

  my_decimal decimal_check = {{0x0, 0x11111111, 0x11111111, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok129) {
  my_decimal decimal = {{0x0, 0xAAAAAAAA, 0xAAAAAAAA, 0xD0000}};

  my_decimal decimal_check = {{0xF030F9AC, 0x12C3D6, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok130) {
  my_decimal decimal = {{0x0, 0xAAAAAAAA, 0xAAAAAAAA, 0x800D0000}};

  my_decimal decimal_check = {{0xF030F9AC, 0x12C3D6, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok131) {
  my_decimal decimal = {{0x0, 0xAAAAAAAA, 0xAAAAAAAA, 0x1C0000}};

  my_decimal decimal_check = {{0x5, 0x0, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok132) {
  my_decimal decimal = {{0x0, 0xAAAAAAAA, 0xAAAAAAAA, 0x801C0000}};

  my_decimal decimal_check = {{0x5, 0x0, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok133) {
  my_decimal decimal = {{0xAAAAAAAA, 0x0, 0xAAAAAAAA, 0x0}};

  my_decimal decimal_check = {{0xAAAAAAAA, 0x0, 0xAAAAAAAA, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok134) {
  my_decimal decimal = {{0xAAAAAAAA, 0x0, 0xAAAAAAAA, 0x80000000}};

  my_decimal decimal_check = {{0xAAAAAAAA, 0x0, 0xAAAAAAAA, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok135) {
  my_decimal decimal = {{0xAAAAAAAA, 0x0, 0xAAAAAAAA, 0x10000}};

  my_decimal decimal_check = {{0x11111111, 0x0, 0x11111111, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok136) {
  my_decimal decimal = {{0xAAAAAAAA, 0x0, 0xAAAAAAAA, 0x80010000}};

  my_decimal decimal_check = {{0x11111111, 0x0, 0x11111111, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok137) {
  my_decimal decimal = {{0xAAAAAAAA, 0x0, 0xAAAAAAAA, 0xD0000}};

  my_decimal decimal_check = {{0xF01E35D5, 0x12C3D6, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok138) {
  my_decimal decimal = {{0xAAAAAAAA, 0x0, 0xAAAAAAAA, 0x800D0000}};

  my_decimal decimal_check = {{0xF01E35D5, 0x12C3D6, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok139) {
  my_decimal decimal = {{0xAAAAAAAA, 0x0, 0xAAAAAAAA, 0x1C0000}};

  my_decimal decimal_check = {{0x5, 0x0, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok140) {
  my_decimal decimal = {{0xAAAAAAAA, 0x0, 0xAAAAAAAA, 0x801C0000}};

  my_decimal decimal_check = {{0x5, 0x0, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok141) {
  my_decimal decimal = {{0x0, 0x0, 0xAAAAAAAA, 0x0}};

  my_decimal decimal_check = {{0x0, 0x0, 0xAAAAAAAA, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok142) {
  my_decimal decimal = {{0x0, 0x0, 0xAAAAAAAA, 0x80000000}};

  my_decimal decimal_check = {{0x0, 0x0, 0xAAAAAAAA, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok143) {
  my_decimal decimal = {{0x0, 0x0, 0xAAAAAAAA, 0x10000}};

  my_decimal decimal_check = {{0x0, 0x0, 0x11111111, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok144) {
  my_decimal decimal = {{0x0, 0x0, 0xAAAAAAAA, 0x80010000}};

  my_decimal decimal_check = {{0x0, 0x0, 0x11111111, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok145) {
  my_decimal decimal = {{0x0, 0x0, 0xAAAAAAAA, 0xD0000}};

  my_decimal decimal_check = {{0xF01E35D5, 0x12C3D6, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok146) {
  my_decimal decimal = {{0x0, 0x0, 0xAAAAAAAA, 0x800D0000}};

  my_decimal decimal_check = {{0xF01E35D5, 0x12C3D6, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok147) {
  my_decimal decimal = {{0x0, 0x0, 0xAAAAAAAA, 0x1C0000}};

  my_decimal decimal_check = {{0x5, 0x0, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok148) {
  my_decimal decimal = {{0x0, 0x0, 0xAAAAAAAA, 0x801C0000}};

  my_decimal decimal_check = {{0x5, 0x0, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok149) {
  my_decimal decimal = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x0}};

  my_decimal decimal_check = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok150) {
  my_decimal decimal = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x80000000}};

  my_decimal decimal_check = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok151) {
  my_decimal decimal = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x10000}};

  my_decimal decimal_check = {{0x11111111, 0x11111111, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok152) {
  my_decimal decimal = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x80010000}};

  my_decimal decimal_check = {{0x11111111, 0x11111111, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok153) {
  my_decimal decimal = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0xB0000}};

  my_decimal decimal_check = {{0x7547FF6, 0x0, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok154) {
  my_decimal decimal = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x800B0000}};

  my_decimal decimal_check = {{0x7547FF6, 0x0, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok155) {
  my_decimal decimal = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x130000}};

  my_decimal decimal_check = {{0x1, 0x0, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok156) {
  my_decimal decimal = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x80130000}};

  my_decimal decimal_check = {{0x1, 0x0, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok157) {
  my_decimal decimal = {{0x0, 0xAAAAAAAA, 0x0, 0x0}};

  my_decimal decimal_check = {{0x0, 0xAAAAAAAA, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok158) {
  my_decimal decimal = {{0x0, 0xAAAAAAAA, 0x0, 0x80000000}};

  my_decimal decimal_check = {{0x0, 0xAAAAAAAA, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok159) {
  my_decimal decimal = {{0x0, 0xAAAAAAAA, 0x0, 0x10000}};

  my_decimal decimal_check = {{0x0, 0x11111111, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok160) {
  my_decimal decimal = {{0x0, 0xAAAAAAAA, 0x0, 0x80010000}};

  my_decimal decimal_check = {{0x0, 0x11111111, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok161) {
  my_decimal decimal = {{0x0, 0xAAAAAAAA, 0x0, 0xB0000}};

  my_decimal decimal_check = {{0x7547FF6, 0x0, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok162) {
  my_decimal decimal = {{0x0, 0xAAAAAAAA, 0x0, 0x800B0000}};

  my_decimal decimal_check = {{0x7547FF6, 0x0, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok163) {
  my_decimal decimal = {{0x0, 0xAAAAAAAA, 0x0, 0x130000}};

  my_decimal decimal_check = {{0x1, 0x0, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok164) {
  my_decimal decimal = {{0x0, 0xAAAAAAAA, 0x0, 0x80130000}};

  my_decimal decimal_check = {{0x1, 0x0, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok165) {
  my_decimal decimal = {{0xAAAAAAAA, 0x0, 0x0, 0x0}};

  my_decimal decimal_check = {{0xAAAAAAAA, 0x0, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok166) {
  my_decimal decimal = {{0xAAAAAAAA, 0x0, 0x0, 0x80000000}};

  my_decimal decimal_check = {{0xAAAAAAAA, 0x0, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok167) {
  my_decimal decimal = {{0xAAAAAAAA, 0x0, 0x0, 0x10000}};

  my_decimal decimal_check = {{0x11111111, 0x0, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok168) {
  my_decimal decimal = {{0xAAAAAAAA, 0x0, 0x0, 0x80010000}};

  my_decimal decimal_check = {{0x11111111, 0x0, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok169) {
  my_decimal decimal = {{0xAAAAAAAA, 0x0, 0x0, 0x40000}};

  my_decimal decimal_check = {{0x45E7B, 0x0, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok170) {
  my_decimal decimal = {{0xAAAAAAAA, 0x0, 0x0, 0x80040000}};

  my_decimal decimal_check = {{0x45E7B, 0x0, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok171) {
  my_decimal decimal = {{0xAAAAAAAA, 0x0, 0x0, 0x90000}};

  my_decimal decimal_check = {{0x3, 0x0, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok172) {
  my_decimal decimal = {{0xAAAAAAAA, 0x0, 0x0, 0x80090000}};

  my_decimal decimal_check = {{0x3, 0x0, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok173) {
  my_decimal decimal = {{0x55555555, 0x55555555, 0x55555555, 0x0}};

  my_decimal decimal_check = {{0x55555555, 0x55555555, 0x55555555, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok174) {
  my_decimal decimal = {{0x55555555, 0x55555555, 0x55555555, 0x80000000}};

  my_decimal decimal_check = {
      {0x55555555, 0x55555555, 0x55555555, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok175) {
  my_decimal decimal = {{0x55555555, 0x55555555, 0x55555555, 0x10000}};

  my_decimal decimal_check = {{0x88888888, 0x88888888, 0x8888888, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok176) {
  my_decimal decimal = {{0x55555555, 0x55555555, 0x55555555, 0x80010000}};

  my_decimal decimal_check = {{0x88888888, 0x88888888, 0x8888888, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok177) {
  my_decimal decimal = {{0x55555555, 0x55555555, 0x55555555, 0xD0000}};

  my_decimal decimal_check = {{0x78187CD6, 0x961EB, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok178) {
  my_decimal decimal = {{0x55555555, 0x55555555, 0x55555555, 0x800D0000}};

  my_decimal decimal_check = {{0x78187CD6, 0x961EB, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok179) {
  my_decimal decimal = {{0x55555555, 0x55555555, 0x55555555, 0x1C0000}};

  my_decimal decimal_check = {{0x3, 0x0, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok180) {
  my_decimal decimal = {{0x55555555, 0x55555555, 0x55555555, 0x801C0000}};

  my_decimal decimal_check = {{0x3, 0x0, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok181) {
  my_decimal decimal = {{0x0, 0x55555555, 0x55555555, 0x0}};

  my_decimal decimal_check = {{0x0, 0x55555555, 0x55555555, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok182) {
  my_decimal decimal = {{0x0, 0x55555555, 0x55555555, 0x80000000}};

  my_decimal decimal_check = {{0x0, 0x55555555, 0x55555555, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok183) {
  my_decimal decimal = {{0x0, 0x55555555, 0x55555555, 0x10000}};

  my_decimal decimal_check = {{0x80000000, 0x88888888, 0x8888888, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok184) {
  my_decimal decimal = {{0x0, 0x55555555, 0x55555555, 0x80010000}};

  my_decimal decimal_check = {{0x80000000, 0x88888888, 0x8888888, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok185) {
  my_decimal decimal = {{0x0, 0x55555555, 0x55555555, 0xD0000}};

  my_decimal decimal_check = {{0x78187CD6, 0x961EB, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok186) {
  my_decimal decimal = {{0x0, 0x55555555, 0x55555555, 0x800D0000}};

  my_decimal decimal_check = {{0x78187CD6, 0x961EB, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok187) {
  my_decimal decimal = {{0x0, 0x55555555, 0x55555555, 0x1C0000}};

  my_decimal decimal_check = {{0x3, 0x0, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok188) {
  my_decimal decimal = {{0x0, 0x55555555, 0x55555555, 0x801C0000}};

  my_decimal decimal_check = {{0x3, 0x0, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok189) {
  my_decimal decimal = {{0x55555555, 0x0, 0x55555555, 0x0}};

  my_decimal decimal_check = {{0x55555555, 0x0, 0x55555555, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok190) {
  my_decimal decimal = {{0x55555555, 0x0, 0x55555555, 0x80000000}};

  my_decimal decimal_check = {{0x55555555, 0x0, 0x55555555, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok191) {
  my_decimal decimal = {{0x55555555, 0x0, 0x55555555, 0x10000}};

  my_decimal decimal_check = {{0x8888888, 0x80000000, 0x8888888, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok192) {
  my_decimal decimal = {{0x55555555, 0x0, 0x55555555, 0x80010000}};

  my_decimal decimal_check = {{0x8888888, 0x80000000, 0x8888888, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok193) {
  my_decimal decimal = {{0x55555555, 0x0, 0x55555555, 0xD0000}};

  my_decimal decimal_check = {{0x780F1AEA, 0x961EB, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok194) {
  my_decimal decimal = {{0x55555555, 0x0, 0x55555555, 0x800D0000}};

  my_decimal decimal_check = {{0x780F1AEA, 0x961EB, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok195) {
  my_decimal decimal = {{0x55555555, 0x0, 0x55555555, 0x1C0000}};

  my_decimal decimal_check = {{0x3, 0x0, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok196) {
  my_decimal decimal = {{0x55555555, 0x0, 0x55555555, 0x801C0000}};

  my_decimal decimal_check = {{0x3, 0x0, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok197) {
  my_decimal decimal = {{0x0, 0x0, 0x55555555, 0x0}};

  my_decimal decimal_check = {{0x0, 0x0, 0x55555555, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok198) {
  my_decimal decimal = {{0x0, 0x0, 0x55555555, 0x80000000}};

  my_decimal decimal_check = {{0x0, 0x0, 0x55555555, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok199) {
  my_decimal decimal = {{0x0, 0x0, 0x55555555, 0x10000}};

  my_decimal decimal_check = {{0x0, 0x80000000, 0x8888888, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok200) {
  my_decimal decimal = {{0x0, 0x0, 0x55555555, 0x80010000}};

  my_decimal decimal_check = {{0x0, 0x80000000, 0x8888888, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok201) {
  my_decimal decimal = {{0x0, 0x0, 0x55555555, 0xD0000}};

  my_decimal decimal_check = {{0x780F1AEA, 0x961EB, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok202) {
  my_decimal decimal = {{0x0, 0x0, 0x55555555, 0x800D0000}};

  my_decimal decimal_check = {{0x780F1AEA, 0x961EB, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok203) {
  my_decimal decimal = {{0x0, 0x0, 0x55555555, 0x1C0000}};

  my_decimal decimal_check = {{0x3, 0x0, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok204) {
  my_decimal decimal = {{0x0, 0x0, 0x55555555, 0x801C0000}};

  my_decimal decimal_check = {{0x3, 0x0, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok205) {
  my_decimal decimal = {{0x55555555, 0x55555555, 0x0, 0x0}};

  my_decimal decimal_check = {{0x55555555, 0x55555555, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok206) {
  my_decimal decimal = {{0x55555555, 0x55555555, 0x0, 0x80000000}};

  my_decimal decimal_check = {{0x55555555, 0x55555555, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok207) {
  my_decimal decimal = {{0x55555555, 0x55555555, 0x0, 0x10000}};

  my_decimal decimal_check = {{0x88888888, 0x8888888, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok208) {
  my_decimal decimal = {{0x55555555, 0x55555555, 0x0, 0x80010000}};

  my_decimal decimal_check = {{0x88888888, 0x8888888, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok209) {
  my_decimal decimal = {{0x55555555, 0x55555555, 0x0, 0xC0000}};

  my_decimal decimal_check = {{0x5DD333, 0x0, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok210) {
  my_decimal decimal = {{0x55555555, 0x55555555, 0x0, 0x800C0000}};

  my_decimal decimal_check = {{0x5DD333, 0x0, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok211) {
  my_decimal decimal = {{0x55555555, 0x55555555, 0x0, 0x120000}};

  my_decimal decimal_check = {{0x6, 0x0, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok212) {
  my_decimal decimal = {{0x55555555, 0x55555555, 0x0, 0x80120000}};

  my_decimal decimal_check = {{0x6, 0x0, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok213) {
  my_decimal decimal = {{0x0, 0x55555555, 0x0, 0x0}};

  my_decimal decimal_check = {{0x0, 0x55555555, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok214) {
  my_decimal decimal = {{0x0, 0x55555555, 0x0, 0x80000000}};

  my_decimal decimal_check = {{0x0, 0x55555555, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok215) {
  my_decimal decimal = {{0x0, 0x55555555, 0x0, 0x10000}};

  my_decimal decimal_check = {{0x80000000, 0x8888888, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok216) {
  my_decimal decimal = {{0x0, 0x55555555, 0x0, 0x80010000}};

  my_decimal decimal_check = {{0x80000000, 0x8888888, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok217) {
  my_decimal decimal = {{0x0, 0x55555555, 0x0, 0xC0000}};

  my_decimal decimal_check = {{0x5DD333, 0x0, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok218) {
  my_decimal decimal = {{0x0, 0x55555555, 0x0, 0x800C0000}};

  my_decimal decimal_check = {{0x5DD333, 0x0, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok219) {
  my_decimal decimal = {{0x0, 0x55555555, 0x0, 0x120000}};

  my_decimal decimal_check = {{0x6, 0x0, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok220) {
  my_decimal decimal = {{0x0, 0x55555555, 0x0, 0x80120000}};

  my_decimal decimal_check = {{0x6, 0x0, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok221) {
  my_decimal decimal = {{0x55555555, 0x0, 0x0, 0x0}};

  my_decimal decimal_check = {{0x55555555, 0x0, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok222) {
  my_decimal decimal = {{0x55555555, 0x0, 0x0, 0x80000000}};

  my_decimal decimal_check = {{0x55555555, 0x0, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok223) {
  my_decimal decimal = {{0x55555555, 0x0, 0x0, 0x10000}};

  my_decimal decimal_check = {{0x8888888, 0x0, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok224) {
  my_decimal decimal = {{0x55555555, 0x0, 0x0, 0x80010000}};

  my_decimal decimal_check = {{0x8888888, 0x0, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok225) {
  my_decimal decimal = {{0x55555555, 0x0, 0x0, 0x40000}};

  my_decimal decimal_check = {{0x22F3E, 0x0, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok226) {
  my_decimal decimal = {{0x55555555, 0x0, 0x0, 0x80040000}};

  my_decimal decimal_check = {{0x22F3E, 0x0, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok227) {
  my_decimal decimal = {{0x55555555, 0x0, 0x0, 0x90000}};

  my_decimal decimal_check = {{0x1, 0x0, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok228) {
  my_decimal decimal = {{0x55555555, 0x0, 0x0, 0x80090000}};

  my_decimal decimal_check = {{0x1, 0x0, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok229) {
  my_decimal decimal = {{0x1, 0x1, 0x1, 0x0}};

  my_decimal decimal_check = {{0x1, 0x1, 0x1, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok230) {
  my_decimal decimal = {{0x1, 0x1, 0x1, 0x80000000}};

  my_decimal decimal_check = {{0x1, 0x1, 0x1, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok231) {
  my_decimal decimal = {{0x1, 0x1, 0x1, 0x10000}};

  my_decimal decimal_check = {{0xB3333333, 0x19999999, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok232) {
  my_decimal decimal = {{0x1, 0x1, 0x1, 0x80010000}};

  my_decimal decimal_check = {{0xB3333333, 0x19999999, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok233) {
  my_decimal decimal = {{0x1, 0x1, 0x1, 0x80000}};

  my_decimal decimal_check = {{0xF31DC48C, 0x2A, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok234) {
  my_decimal decimal = {{0x1, 0x1, 0x1, 0x80080000}};

  my_decimal decimal_check = {{0xF31DC48C, 0x2A, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok235) {
  my_decimal decimal = {{0x1, 0x1, 0x1, 0x130000}};

  my_decimal decimal_check = {{0x2, 0x0, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok236) {
  my_decimal decimal = {{0x1, 0x1, 0x1, 0x80130000}};

  my_decimal decimal_check = {{0x2, 0x0, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok237) {
  my_decimal decimal = {{0x0, 0x1, 0x1, 0x0}};

  my_decimal decimal_check = {{0x0, 0x1, 0x1, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok238) {
  my_decimal decimal = {{0x0, 0x1, 0x1, 0x80000000}};

  my_decimal decimal_check = {{0x0, 0x1, 0x1, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok239) {
  my_decimal decimal = {{0x0, 0x1, 0x1, 0x10000}};

  my_decimal decimal_check = {{0xB3333333, 0x19999999, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok240) {
  my_decimal decimal = {{0x0, 0x1, 0x1, 0x80010000}};

  my_decimal decimal_check = {{0xB3333333, 0x19999999, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok241) {
  my_decimal decimal = {{0x0, 0x1, 0x1, 0x90000}};

  my_decimal decimal_check = {{0x4B82FA0E, 0x4, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok242) {
  my_decimal decimal = {{0x0, 0x1, 0x1, 0x80090000}};

  my_decimal decimal_check = {{0x4B82FA0E, 0x4, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok243) {
  my_decimal decimal = {{0x0, 0x1, 0x1, 0x130000}};

  my_decimal decimal_check = {{0x2, 0x0, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok244) {
  my_decimal decimal = {{0x0, 0x1, 0x1, 0x80130000}};

  my_decimal decimal_check = {{0x2, 0x0, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok245) {
  my_decimal decimal = {{0x1, 0x0, 0x1, 0x0}};

  my_decimal decimal_check = {{0x1, 0x0, 0x1, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok246) {
  my_decimal decimal = {{0x1, 0x0, 0x1, 0x80000000}};

  my_decimal decimal_check = {{0x1, 0x0, 0x1, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok247) {
  my_decimal decimal = {{0x1, 0x0, 0x1, 0x10000}};

  my_decimal decimal_check = {{0x9999999A, 0x19999999, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok248) {
  my_decimal decimal = {{0x1, 0x0, 0x1, 0x80010000}};

  my_decimal decimal_check = {{0x9999999A, 0x19999999, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok249) {
  my_decimal decimal = {{0x1, 0x0, 0x1, 0xA0000}};

  my_decimal decimal_check = {{0x6DF37F67, 0x0, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok250) {
  my_decimal decimal = {{0x1, 0x0, 0x1, 0x800A0000}};

  my_decimal decimal_check = {{0x6DF37F67, 0x0, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok251) {
  my_decimal decimal = {{0x1, 0x0, 0x1, 0x130000}};

  my_decimal decimal_check = {{0x2, 0x0, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok252) {
  my_decimal decimal = {{0x1, 0x0, 0x1, 0x80130000}};

  my_decimal decimal_check = {{0x2, 0x0, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok253) {
  my_decimal decimal = {{0x0, 0x0, 0x1, 0x0}};

  my_decimal decimal_check = {{0x0, 0x0, 0x1, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok254) {
  my_decimal decimal = {{0x0, 0x0, 0x1, 0x80000000}};

  my_decimal decimal_check = {{0x0, 0x0, 0x1, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok255) {
  my_decimal decimal = {{0x0, 0x0, 0x1, 0x10000}};

  my_decimal decimal_check = {{0x9999999A, 0x19999999, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok256) {
  my_decimal decimal = {{0x0, 0x0, 0x1, 0x80010000}};

  my_decimal decimal_check = {{0x9999999A, 0x19999999, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok257) {
  my_decimal decimal = {{0x0, 0x0, 0x1, 0xB0000}};

  my_decimal decimal_check = {{0xAFEBFF1, 0x0, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok258) {
  my_decimal decimal = {{0x0, 0x0, 0x1, 0x800B0000}};

  my_decimal decimal_check = {{0xAFEBFF1, 0x0, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok259) {
  my_decimal decimal = {{0x0, 0x0, 0x1, 0x130000}};

  my_decimal decimal_check = {{0x2, 0x0, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok260) {
  my_decimal decimal = {{0x0, 0x0, 0x1, 0x80130000}};

  my_decimal decimal_check = {{0x2, 0x0, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok261) {
  my_decimal decimal = {{0x1, 0x1, 0x0, 0x0}};

  my_decimal decimal_check = {{0x1, 0x1, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok262) {
  my_decimal decimal = {{0x1, 0x1, 0x0, 0x80000000}};

  my_decimal decimal_check = {{0x1, 0x1, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok263) {
  my_decimal decimal = {{0x1, 0x1, 0x0, 0x10000}};

  my_decimal decimal_check = {{0x1999999A, 0x0, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok264) {
  my_decimal decimal = {{0x1, 0x1, 0x0, 0x80010000}};

  my_decimal decimal_check = {{0x1999999A, 0x0, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok265) {
  my_decimal decimal = {{0x1, 0x1, 0x0, 0x20000}};

  my_decimal decimal_check = {{0x28F5C29, 0x0, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok266) {
  my_decimal decimal = {{0x1, 0x1, 0x0, 0x80020000}};

  my_decimal decimal_check = {{0x28F5C29, 0x0, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok267) {
  my_decimal decimal = {{0x1, 0x1, 0x0, 0x40000}};

  my_decimal decimal_check = {{0x68DB9, 0x0, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok268) {
  my_decimal decimal = {{0x1, 0x1, 0x0, 0x80040000}};

  my_decimal decimal_check = {{0x68DB9, 0x0, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok269) {
  my_decimal decimal = {{0x1, 0x1, 0x0, 0x90000}};

  my_decimal decimal_check = {{0x4, 0x0, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok270) {
  my_decimal decimal = {{0x1, 0x1, 0x0, 0x80090000}};

  my_decimal decimal_check = {{0x4, 0x0, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok271) {
  my_decimal decimal = {{0x1, 0x1, 0x0, 0x80000}};

  my_decimal decimal_check = {{0x2B, 0x0, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok272) {
  my_decimal decimal = {{0x1, 0x1, 0x0, 0x80080000}};

  my_decimal decimal_check = {{0x2B, 0x0, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok273) {
  my_decimal decimal = {{0x0, 0x1, 0x0, 0x0}};

  my_decimal decimal_check = {{0x0, 0x1, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok274) {
  my_decimal decimal = {{0x0, 0x1, 0x0, 0x80000000}};

  my_decimal decimal_check = {{0x0, 0x1, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok275) {
  my_decimal decimal = {{0x0, 0x1, 0x0, 0x10000}};

  my_decimal decimal_check = {{0x1999999A, 0x0, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok276) {
  my_decimal decimal = {{0x0, 0x1, 0x0, 0x80010000}};

  my_decimal decimal_check = {{0x1999999A, 0x0, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok277) {
  my_decimal decimal = {{0x0, 0x1, 0x0, 0x20000}};

  my_decimal decimal_check = {{0x28F5C29, 0x0, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok278) {
  my_decimal decimal = {{0x0, 0x1, 0x0, 0x80020000}};

  my_decimal decimal_check = {{0x28F5C29, 0x0, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok279) {
  my_decimal decimal = {{0x0, 0x1, 0x0, 0x30000}};

  my_decimal decimal_check = {{0x418937, 0x0, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok280) {
  my_decimal decimal = {{0x0, 0x1, 0x0, 0x80030000}};

  my_decimal decimal_check = {{0x418937, 0x0, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok281) {
  my_decimal decimal = {{0x0, 0x1, 0x0, 0x90000}};

  my_decimal decimal_check = {{0x4, 0x0, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok282) {
  my_decimal decimal = {{0x0, 0x1, 0x0, 0x80090000}};

  my_decimal decimal_check = {{0x4, 0x0, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok283) {
  my_decimal decimal = {{0x0, 0x1, 0x0, 0x80000}};

  my_decimal decimal_check = {{0x2B, 0x0, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok284) {
  my_decimal decimal = {{0x0, 0x1, 0x0, 0x80080000}};

  my_decimal decimal_check = {{0x2B, 0x0, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok285) {
  my_decimal decimal = {{0x1, 0x0, 0x0, 0x0}};

  my_decimal decimal_check = {{0x1, 0x0, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok286) {
  my_decimal decimal = {{0x1, 0x0, 0x0, 0x80000000}};

  my_decimal decimal_check = {{0x1, 0x0, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok287) {
  my_decimal decimal = {{0x1, 0x0, 0x0, 0x10000}};

  my_decimal decimal_check = {{0x0, 0x0, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok288) {
  my_decimal decimal = {{0x1, 0x0, 0x0, 0x80010000}};

  my_decimal decimal_check = {{0x0, 0x0, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok289) {
  my_decimal decimal = {{0x1, 0x0, 0x0, 0xD0000}};

  my_decimal decimal_check = {{0x0, 0x0, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok290) {
  my_decimal decimal = {{0x1, 0x0, 0x0, 0x800D0000}};

  my_decimal decimal_check = {{0x0, 0x0, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok291) {
  my_decimal decimal = {{0x1, 0x0, 0x0, 0xE0000}};

  my_decimal decimal_check = {{0x0, 0x0, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok292) {
  my_decimal decimal = {{0x1, 0x0, 0x0, 0x800E0000}};

  my_decimal decimal_check = {{0x0, 0x0, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok293) {
  my_decimal decimal = {{0x1, 0x0, 0x0, 0x1B0000}};

  my_decimal decimal_check = {{0x0, 0x0, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok294) {
  my_decimal decimal = {{0x1, 0x0, 0x0, 0x801B0000}};

  my_decimal decimal_check = {{0x0, 0x0, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok295) {
  my_decimal decimal = {{0x1, 0x0, 0x0, 0x1C0000}};

  my_decimal decimal_check = {{0x0, 0x0, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok296) {
  my_decimal decimal = {{0x1, 0x0, 0x0, 0x801C0000}};

  my_decimal decimal_check = {{0x0, 0x0, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok297) {
  my_decimal decimal = {{0x80000000, 0x80000000, 0x80000000, 0x0}};

  my_decimal decimal_check = {{0x80000000, 0x80000000, 0x80000000, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok298) {
  my_decimal decimal = {{0x80000000, 0x80000000, 0x80000000, 0x80000000}};

  my_decimal decimal_check = {
      {0x80000000, 0x80000000, 0x80000000, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok299) {
  my_decimal decimal = {{0x80000000, 0x80000000, 0x80000000, 0x10000}};

  my_decimal decimal_check = {{0xA6666666, 0xD9999999, 0xCCCCCCC, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok300) {
  my_decimal decimal = {{0x80000000, 0x80000000, 0x80000000, 0x80010000}};

  my_decimal decimal_check = {{0xA6666666, 0xD9999999, 0xCCCCCCC, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok301) {
  my_decimal decimal = {{0x80000000, 0x80000000, 0x80000000, 0xF0000}};

  my_decimal decimal_check = {{0x5F3DF2B4, 0x2407, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok302) {
  my_decimal decimal = {{0x80000000, 0x80000000, 0x80000000, 0x800F0000}};

  my_decimal decimal_check = {{0x5F3DF2B4, 0x2407, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok303) {
  my_decimal decimal = {{0x80000000, 0x80000000, 0x80000000, 0x1C0000}};

  my_decimal decimal_check = {{0x4, 0x0, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok304) {
  my_decimal decimal = {{0x80000000, 0x80000000, 0x80000000, 0x801C0000}};

  my_decimal decimal_check = {{0x4, 0x0, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok305) {
  my_decimal decimal = {{0x0, 0x80000000, 0x80000000, 0x0}};

  my_decimal decimal_check = {{0x0, 0x80000000, 0x80000000, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok306) {
  my_decimal decimal = {{0x0, 0x80000000, 0x80000000, 0x80000000}};

  my_decimal decimal_check = {{0x0, 0x80000000, 0x80000000, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok307) {
  my_decimal decimal = {{0x0, 0x80000000, 0x80000000, 0x10000}};

  my_decimal decimal_check = {{0x9999999A, 0xD9999999, 0xCCCCCCC, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok308) {
  my_decimal decimal = {{0x0, 0x80000000, 0x80000000, 0x80010000}};

  my_decimal decimal_check = {{0x9999999A, 0xD9999999, 0xCCCCCCC, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok309) {
  my_decimal decimal = {{0x0, 0x80000000, 0x80000000, 0xD0000}};

  my_decimal decimal_check = {{0x3432CE22, 0xE12E1, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok310) {
  my_decimal decimal = {{0x0, 0x80000000, 0x80000000, 0x800D0000}};

  my_decimal decimal_check = {{0x3432CE22, 0xE12E1, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok311) {
  my_decimal decimal = {{0x0, 0x80000000, 0x80000000, 0x1C0000}};

  my_decimal decimal_check = {{0x4, 0x0, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok312) {
  my_decimal decimal = {{0x0, 0x80000000, 0x80000000, 0x801C0000}};

  my_decimal decimal_check = {{0x4, 0x0, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok313) {
  my_decimal decimal = {{0x80000000, 0x0, 0x80000000, 0x0}};

  my_decimal decimal_check = {{0x80000000, 0x0, 0x80000000, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok314) {
  my_decimal decimal = {{0x80000000, 0x0, 0x80000000, 0x80000000}};

  my_decimal decimal_check = {{0x80000000, 0x0, 0x80000000, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok315) {
  my_decimal decimal = {{0x80000000, 0x0, 0x80000000, 0x10000}};

  my_decimal decimal_check = {{0xD999999A, 0xCCCCCCCC, 0xCCCCCCC, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok316) {
  my_decimal decimal = {{0x80000000, 0x0, 0x80000000, 0x80010000}};

  my_decimal decimal_check = {{0xD999999A, 0xCCCCCCCC, 0xCCCCCCC, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok317) {
  my_decimal decimal = {{0x80000000, 0x0, 0x80000000, 0xC0000}};

  my_decimal decimal_check = {{0x96F5089, 0x8CBCCC, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok318) {
  my_decimal decimal = {{0x80000000, 0x0, 0x80000000, 0x800C0000}};

  my_decimal decimal_check = {{0x96F5089, 0x8CBCCC, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok319) {
  my_decimal decimal = {{0x80000000, 0x0, 0x80000000, 0x1C0000}};

  my_decimal decimal_check = {{0x4, 0x0, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok320) {
  my_decimal decimal = {{0x80000000, 0x0, 0x80000000, 0x801C0000}};

  my_decimal decimal_check = {{0x4, 0x0, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok321) {
  my_decimal decimal = {{0x0, 0x0, 0x80000000, 0x0}};

  my_decimal decimal_check = {{0x0, 0x0, 0x80000000, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok322) {
  my_decimal decimal = {{0x0, 0x0, 0x80000000, 0x80000000}};

  my_decimal decimal_check = {{0x0, 0x0, 0x80000000, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok323) {
  my_decimal decimal = {{0x0, 0x0, 0x80000000, 0x10000}};

  my_decimal decimal_check = {{0xCCCCCCCD, 0xCCCCCCCC, 0xCCCCCCC, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok324) {
  my_decimal decimal = {{0x0, 0x0, 0x80000000, 0x80010000}};

  my_decimal decimal_check = {{0xCCCCCCCD, 0xCCCCCCCC, 0xCCCCCCC, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok325) {
  my_decimal decimal = {{0x0, 0x0, 0x80000000, 0xB0000}};

  my_decimal decimal_check = {{0x5E592558, 0x57F5FF8, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok326) {
  my_decimal decimal = {{0x0, 0x0, 0x80000000, 0x800B0000}};

  my_decimal decimal_check = {{0x5E592558, 0x57F5FF8, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok327) {
  my_decimal decimal = {{0x0, 0x0, 0x80000000, 0x1C0000}};

  my_decimal decimal_check = {{0x4, 0x0, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok328) {
  my_decimal decimal = {{0x0, 0x0, 0x80000000, 0x801C0000}};

  my_decimal decimal_check = {{0x4, 0x0, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok329) {
  my_decimal decimal = {{0x80000000, 0x80000000, 0x0, 0x0}};

  my_decimal decimal_check = {{0x80000000, 0x80000000, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok330) {
  my_decimal decimal = {{0x80000000, 0x80000000, 0x0, 0x80000000}};

  my_decimal decimal_check = {{0x80000000, 0x80000000, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok331) {
  my_decimal decimal = {{0x80000000, 0x80000000, 0x0, 0x10000}};

  my_decimal decimal_check = {{0xD999999A, 0xCCCCCCC, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok332) {
  my_decimal decimal = {{0x80000000, 0x80000000, 0x0, 0x80010000}};

  my_decimal decimal_check = {{0xD999999A, 0xCCCCCCC, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok333) {
  my_decimal decimal = {{0x80000000, 0x80000000, 0x0, 0x70000}};

  my_decimal decimal_check = {{0xBF94D6BC, 0xD6, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok334) {
  my_decimal decimal = {{0x80000000, 0x80000000, 0x0, 0x80070000}};

  my_decimal decimal_check = {{0xBF94D6BC, 0xD6, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok335) {
  my_decimal decimal = {{0x80000000, 0x80000000, 0x0, 0x120000}};

  my_decimal decimal_check = {{0x9, 0x0, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok336) {
  my_decimal decimal = {{0x80000000, 0x80000000, 0x0, 0x80120000}};

  my_decimal decimal_check = {{0x9, 0x0, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok337) {
  my_decimal decimal = {{0x0, 0x80000000, 0x0, 0x0}};

  my_decimal decimal_check = {{0x0, 0x80000000, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok338) {
  my_decimal decimal = {{0x0, 0x80000000, 0x0, 0x80000000}};

  my_decimal decimal_check = {{0x0, 0x80000000, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok339) {
  my_decimal decimal = {{0x0, 0x80000000, 0x0, 0x10000}};

  my_decimal decimal_check = {{0xCCCCCCCD, 0xCCCCCCC, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok340) {
  my_decimal decimal = {{0x0, 0x80000000, 0x0, 0x80010000}};

  my_decimal decimal_check = {{0xCCCCCCCD, 0xCCCCCCC, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok341) {
  my_decimal decimal = {{0x0, 0x80000000, 0x0, 0x80000}};

  my_decimal decimal_check = {{0x798EE231, 0x15, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok342) {
  my_decimal decimal = {{0x0, 0x80000000, 0x0, 0x80080000}};

  my_decimal decimal_check = {{0x798EE231, 0x15, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok343) {
  my_decimal decimal = {{0x0, 0x80000000, 0x0, 0x120000}};

  my_decimal decimal_check = {{0x9, 0x0, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok344) {
  my_decimal decimal = {{0x0, 0x80000000, 0x0, 0x80120000}};

  my_decimal decimal_check = {{0x9, 0x0, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok345) {
  my_decimal decimal = {{0x80000000, 0x0, 0x0, 0x0}};

  my_decimal decimal_check = {{0x80000000, 0x0, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok346) {
  my_decimal decimal = {{0x80000000, 0x0, 0x0, 0x80000000}};

  my_decimal decimal_check = {{0x80000000, 0x0, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok347) {
  my_decimal decimal = {{0x80000000, 0x0, 0x0, 0x10000}};

  my_decimal decimal_check = {{0xCCCCCCD, 0x0, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok348) {
  my_decimal decimal = {{0x80000000, 0x0, 0x0, 0x80010000}};

  my_decimal decimal_check = {{0xCCCCCCD, 0x0, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok349) {
  my_decimal decimal = {{0x80000000, 0x0, 0x0, 0x20000}};

  my_decimal decimal_check = {{0x147AE14, 0x0, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok350) {
  my_decimal decimal = {{0x80000000, 0x0, 0x0, 0x80020000}};

  my_decimal decimal_check = {{0x147AE14, 0x0, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok351) {
  my_decimal decimal = {{0x80000000, 0x0, 0x0, 0x40000}};

  my_decimal decimal_check = {{0x346DC, 0x0, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok352) {
  my_decimal decimal = {{0x80000000, 0x0, 0x0, 0x80040000}};

  my_decimal decimal_check = {{0x346DC, 0x0, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok353) {
  my_decimal decimal = {{0x80000000, 0x0, 0x0, 0x80000}};

  my_decimal decimal_check = {{0x15, 0x0, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok354) {
  my_decimal decimal = {{0x80000000, 0x0, 0x0, 0x80080000}};

  my_decimal decimal_check = {{0x15, 0x0, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok355) {
  my_decimal decimal = {{0x80000000, 0x0, 0x0, 0x90000}};

  my_decimal decimal_check = {{0x2, 0x0, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok356) {
  my_decimal decimal = {{0x80000000, 0x0, 0x0, 0x80090000}};

  my_decimal decimal_check = {{0x2, 0x0, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok357) {
  my_decimal decimal = {{0x811800, 0x811800, 0x811800, 0x0}};

  my_decimal decimal_check = {{0x811800, 0x811800, 0x811800, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok358) {
  my_decimal decimal = {{0x811800, 0x811800, 0x811800, 0x80000000}};

  my_decimal decimal_check = {{0x811800, 0x811800, 0x811800, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok359) {
  my_decimal decimal = {{0x811800, 0x811800, 0x811800, 0x10000}};

  my_decimal decimal_check = {{0x99A68266, 0xCCD9B599, 0xCE8CC, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok360) {
  my_decimal decimal = {{0x811800, 0x811800, 0x811800, 0x80010000}};

  my_decimal decimal_check = {{0x99A68266, 0xCCD9B599, 0xCE8CC, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok361) {
  my_decimal decimal = {{0x811800, 0x811800, 0x811800, 0x140000}};

  my_decimal decimal_check = {{0x17D048, 0x0, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok362) {
  my_decimal decimal = {{0x811800, 0x811800, 0x811800, 0x80140000}};

  my_decimal decimal_check = {{0x17D048, 0x0, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok363) {
  my_decimal decimal = {{0x811800, 0x811800, 0x811800, 0x1A0000}};

  my_decimal decimal_check = {{0x2, 0x0, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok364) {
  my_decimal decimal = {{0x811800, 0x811800, 0x811800, 0x801A0000}};

  my_decimal decimal_check = {{0x2, 0x0, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok365) {
  my_decimal decimal = {{0x0, 0x811800, 0x811800, 0x0}};

  my_decimal decimal_check = {{0x0, 0x811800, 0x811800, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok366) {
  my_decimal decimal = {{0x0, 0x811800, 0x811800, 0x80000000}};

  my_decimal decimal_check = {{0x0, 0x811800, 0x811800, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok367) {
  my_decimal decimal = {{0x0, 0x811800, 0x811800, 0x10000}};

  my_decimal decimal_check = {{0x9999999A, 0xCCD9B599, 0xCE8CC, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok368) {
  my_decimal decimal = {{0x0, 0x811800, 0x811800, 0x80010000}};

  my_decimal decimal_check = {{0x9999999A, 0xCCD9B599, 0xCE8CC, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok369) {
  my_decimal decimal = {{0x0, 0x811800, 0x811800, 0x40000}};

  my_decimal decimal_check = {{0x27525461, 0x75F7320, 0x34E, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok370) {
  my_decimal decimal = {{0x0, 0x811800, 0x811800, 0x80040000}};

  my_decimal decimal_check = {{0x27525461, 0x75F7320, 0x34E, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok371) {
  my_decimal decimal = {{0x0, 0x811800, 0x811800, 0x1A0000}};

  my_decimal decimal_check = {{0x2, 0x0, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok372) {
  my_decimal decimal = {{0x0, 0x811800, 0x811800, 0x801A0000}};

  my_decimal decimal_check = {{0x2, 0x0, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok373) {
  my_decimal decimal = {{0x811800, 0x0, 0x811800, 0x0}};

  my_decimal decimal_check = {{0x811800, 0x0, 0x811800, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok374) {
  my_decimal decimal = {{0x811800, 0x0, 0x811800, 0x80000000}};

  my_decimal decimal_check = {{0x811800, 0x0, 0x811800, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok375) {
  my_decimal decimal = {{0x811800, 0x0, 0x811800, 0x10000}};

  my_decimal decimal_check = {{0xCCD9B59A, 0xCCCCCCCC, 0xCE8CC, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok376) {
  my_decimal decimal = {{0x811800, 0x0, 0x811800, 0x80010000}};

  my_decimal decimal_check = {{0xCCD9B59A, 0xCCCCCCCC, 0xCE8CC, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok377) {
  my_decimal decimal = {{0x811800, 0x0, 0x811800, 0xB0000}};

  my_decimal decimal_check = {{0x9A4DA788, 0x58B66, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok378) {
  my_decimal decimal = {{0x811800, 0x0, 0x811800, 0x800B0000}};

  my_decimal decimal_check = {{0x9A4DA788, 0x58B66, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok379) {
  my_decimal decimal = {{0x811800, 0x0, 0x811800, 0x1A0000}};

  my_decimal decimal_check = {{0x2, 0x0, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok380) {
  my_decimal decimal = {{0x811800, 0x0, 0x811800, 0x801A0000}};

  my_decimal decimal_check = {{0x2, 0x0, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok381) {
  my_decimal decimal = {{0x0, 0x0, 0x811800, 0x0}};

  my_decimal decimal_check = {{0x0, 0x0, 0x811800, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok382) {
  my_decimal decimal = {{0x0, 0x0, 0x811800, 0x80000000}};

  my_decimal decimal_check = {{0x0, 0x0, 0x811800, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok383) {
  my_decimal decimal = {{0x0, 0x0, 0x811800, 0x10000}};

  my_decimal decimal_check = {{0xCCCCCCCD, 0xCCCCCCCC, 0xCE8CC, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok384) {
  my_decimal decimal = {{0x0, 0x0, 0x811800, 0x80010000}};

  my_decimal decimal_check = {{0xCCCCCCCD, 0xCCCCCCCC, 0xCE8CC, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok385) {
  my_decimal decimal = {{0x0, 0x0, 0x811800, 0x130000}};

  my_decimal decimal_check = {{0xEE22CD, 0x0, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok386) {
  my_decimal decimal = {{0x0, 0x0, 0x811800, 0x80130000}};

  my_decimal decimal_check = {{0xEE22CD, 0x0, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok387) {
  my_decimal decimal = {{0x0, 0x0, 0x811800, 0x1A0000}};

  my_decimal decimal_check = {{0x2, 0x0, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok388) {
  my_decimal decimal = {{0x0, 0x0, 0x811800, 0x801A0000}};

  my_decimal decimal_check = {{0x2, 0x0, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok389) {
  my_decimal decimal = {{0x811800, 0x811800, 0x0, 0x0}};

  my_decimal decimal_check = {{0x811800, 0x811800, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok390) {
  my_decimal decimal = {{0x811800, 0x811800, 0x0, 0x80000000}};

  my_decimal decimal_check = {{0x811800, 0x811800, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok391) {
  my_decimal decimal = {{0x811800, 0x811800, 0x0, 0x10000}};

  my_decimal decimal_check = {{0xCCD9B59A, 0xCE8CC, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok392) {
  my_decimal decimal = {{0x811800, 0x811800, 0x0, 0x80010000}};

  my_decimal decimal_check = {{0xCCD9B59A, 0xCE8CC, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok393) {
  my_decimal decimal = {{0x811800, 0x811800, 0x0, 0x80000}};

  my_decimal decimal_check = {{0x15A888CB, 0x0, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok394) {
  my_decimal decimal = {{0x811800, 0x811800, 0x0, 0x80080000}};

  my_decimal decimal_check = {{0x15A888CB, 0x0, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok395) {
  my_decimal decimal = {{0x811800, 0x811800, 0x0, 0x100000}};

  my_decimal decimal_check = {{0x4, 0x0, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok396) {
  my_decimal decimal = {{0x811800, 0x811800, 0x0, 0x80100000}};

  my_decimal decimal_check = {{0x4, 0x0, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok397) {
  my_decimal decimal = {{0x0, 0x811800, 0x0, 0x0}};

  my_decimal decimal_check = {{0x0, 0x811800, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok398) {
  my_decimal decimal = {{0x0, 0x811800, 0x0, 0x80000000}};

  my_decimal decimal_check = {{0x0, 0x811800, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok399) {
  my_decimal decimal = {{0x0, 0x811800, 0x0, 0x10000}};

  my_decimal decimal_check = {{0xCCCCCCCD, 0xCE8CC, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok400) {
  my_decimal decimal = {{0x0, 0x811800, 0x0, 0x80010000}};

  my_decimal decimal_check = {{0xCCCCCCCD, 0xCE8CC, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok401) {
  my_decimal decimal = {{0x0, 0x811800, 0x0, 0x20000}};

  my_decimal decimal_check = {{0xE147AE14, 0x14A7A, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok402) {
  my_decimal decimal = {{0x0, 0x811800, 0x0, 0x80020000}};

  my_decimal decimal_check = {{0xE147AE14, 0x14A7A, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok403) {
  my_decimal decimal = {{0x0, 0x811800, 0x0, 0x80000}};

  my_decimal decimal_check = {{0x15A888CB, 0x0, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok404) {
  my_decimal decimal = {{0x0, 0x811800, 0x0, 0x80080000}};

  my_decimal decimal_check = {{0x15A888CB, 0x0, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok405) {
  my_decimal decimal = {{0x0, 0x811800, 0x0, 0xF0000}};

  my_decimal decimal_check = {{0x24, 0x0, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok406) {
  my_decimal decimal = {{0x0, 0x811800, 0x0, 0x800F0000}};

  my_decimal decimal_check = {{0x24, 0x0, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok407) {
  my_decimal decimal = {{0x0, 0x811800, 0x0, 0x100000}};

  my_decimal decimal_check = {{0x4, 0x0, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok408) {
  my_decimal decimal = {{0x0, 0x811800, 0x0, 0x80100000}};

  my_decimal decimal_check = {{0x4, 0x0, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok409) {
  my_decimal decimal = {{0x811800, 0x0, 0x0, 0x0}};

  my_decimal decimal_check = {{0x811800, 0x0, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok410) {
  my_decimal decimal = {{0x811800, 0x0, 0x0, 0x80000000}};

  my_decimal decimal_check = {{0x811800, 0x0, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok411) {
  my_decimal decimal = {{0x811800, 0x0, 0x0, 0x10000}};

  my_decimal decimal_check = {{0xCE8CD, 0x0, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok412) {
  my_decimal decimal = {{0x811800, 0x0, 0x0, 0x80010000}};

  my_decimal decimal_check = {{0xCE8CD, 0x0, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok413) {
  my_decimal decimal = {{0x811800, 0x0, 0x0, 0x20000}};

  my_decimal decimal_check = {{0x14A7B, 0x0, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok414) {
  my_decimal decimal = {{0x811800, 0x0, 0x0, 0x80020000}};

  my_decimal decimal_check = {{0x14A7B, 0x0, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok415) {
  my_decimal decimal = {{0x811800, 0x0, 0x0, 0x30000}};

  my_decimal decimal_check = {{0x210C, 0x0, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok416) {
  my_decimal decimal = {{0x811800, 0x0, 0x0, 0x80030000}};

  my_decimal decimal_check = {{0x210C, 0x0, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok417) {
  my_decimal decimal = {{0x811800, 0x0, 0x0, 0x50000}};

  my_decimal decimal_check = {{0x55, 0x0, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok418) {
  my_decimal decimal = {{0x811800, 0x0, 0x0, 0x80050000}};

  my_decimal decimal_check = {{0x55, 0x0, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok419) {
  my_decimal decimal = {{0x811800, 0x0, 0x0, 0x60000}};

  my_decimal decimal_check = {{0x8, 0x0, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok420) {
  my_decimal decimal = {{0x811800, 0x0, 0x0, 0x80060000}};

  my_decimal decimal_check = {{0x8, 0x0, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok421) {
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};

  my_decimal decimal_check = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok422) {
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};

  my_decimal decimal_check = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok423) {
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};

  my_decimal decimal_check = {{0x9999999A, 0x99999999, 0x19999999, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok424) {
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80010000}};

  my_decimal decimal_check = {
      {0x9999999A, 0x99999999, 0x19999999, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok425) {
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x110000}};

  my_decimal decimal_check = {{0x77AA3237, 0xB8, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok426) {
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80110000}};

  my_decimal decimal_check = {{0x77AA3237, 0xB8, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok427) {
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x1C0000}};

  my_decimal decimal_check = {{0x8, 0x0, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok428) {
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x801C0000}};

  my_decimal decimal_check = {{0x8, 0x0, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok429) {
  my_decimal decimal = {{0x0, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};

  my_decimal decimal_check = {{0x0, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok430) {
  my_decimal decimal = {{0x0, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};

  my_decimal decimal_check = {{0x0, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok431) {
  my_decimal decimal = {{0x0, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};

  my_decimal decimal_check = {{0x80000000, 0x99999999, 0x19999999, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok432) {
  my_decimal decimal = {{0x0, 0xFFFFFFFF, 0xFFFFFFFF, 0x80010000}};

  my_decimal decimal_check = {
      {0x80000000, 0x99999999, 0x19999999, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok433) {
  my_decimal decimal = {{0x0, 0xFFFFFFFF, 0xFFFFFFFF, 0xF0000}};

  my_decimal decimal_check = {{0xBE7B9D58, 0x480E, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok434) {
  my_decimal decimal = {{0x0, 0xFFFFFFFF, 0xFFFFFFFF, 0x800F0000}};

  my_decimal decimal_check = {{0xBE7B9D58, 0x480E, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok435) {
  my_decimal decimal = {{0x0, 0xFFFFFFFF, 0xFFFFFFFF, 0x1C0000}};

  my_decimal decimal_check = {{0x8, 0x0, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok436) {
  my_decimal decimal = {{0x0, 0xFFFFFFFF, 0xFFFFFFFF, 0x801C0000}};

  my_decimal decimal_check = {{0x8, 0x0, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok437) {
  my_decimal decimal = {{0xFFFFFFFF, 0x0, 0xFFFFFFFF, 0x0}};

  my_decimal decimal_check = {{0xFFFFFFFF, 0x0, 0xFFFFFFFF, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok438) {
  my_decimal decimal = {{0xFFFFFFFF, 0x0, 0xFFFFFFFF, 0x80000000}};

  my_decimal decimal_check = {{0xFFFFFFFF, 0x0, 0xFFFFFFFF, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok439) {
  my_decimal decimal = {{0xFFFFFFFF, 0x0, 0xFFFFFFFF, 0x10000}};

  my_decimal decimal_check = {{0x1999999A, 0x80000000, 0x19999999, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok440) {
  my_decimal decimal = {{0xFFFFFFFF, 0x0, 0xFFFFFFFF, 0x80010000}};

  my_decimal decimal_check = {
      {0x1999999A, 0x80000000, 0x19999999, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok441) {
  my_decimal decimal = {{0xFFFFFFFF, 0x0, 0xFFFFFFFF, 0x110000}};

  my_decimal decimal_check = {{0x77AA317E, 0xB8, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok442) {
  my_decimal decimal = {{0xFFFFFFFF, 0x0, 0xFFFFFFFF, 0x80110000}};

  my_decimal decimal_check = {{0x77AA317E, 0xB8, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok443) {
  my_decimal decimal = {{0xFFFFFFFF, 0x0, 0xFFFFFFFF, 0x1C0000}};

  my_decimal decimal_check = {{0x8, 0x0, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok444) {
  my_decimal decimal = {{0xFFFFFFFF, 0x0, 0xFFFFFFFF, 0x801C0000}};

  my_decimal decimal_check = {{0x8, 0x0, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok445) {
  my_decimal decimal = {{0x0, 0x0, 0xFFFFFFFF, 0x0}};

  my_decimal decimal_check = {{0x0, 0x0, 0xFFFFFFFF, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok446) {
  my_decimal decimal = {{0x0, 0x0, 0xFFFFFFFF, 0x80000000}};

  my_decimal decimal_check = {{0x0, 0x0, 0xFFFFFFFF, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok447) {
  my_decimal decimal = {{0x0, 0x0, 0xFFFFFFFF, 0x10000}};

  my_decimal decimal_check = {{0x0, 0x80000000, 0x19999999, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok448) {
  my_decimal decimal = {{0x0, 0x0, 0xFFFFFFFF, 0x80010000}};

  my_decimal decimal_check = {{0x0, 0x80000000, 0x19999999, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok449) {
  my_decimal decimal = {{0x0, 0x0, 0xFFFFFFFF, 0x120000}};

  my_decimal decimal_check = {{0x725DD1C0, 0x12, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok450) {
  my_decimal decimal = {{0x0, 0x0, 0xFFFFFFFF, 0x80120000}};

  my_decimal decimal_check = {{0x725DD1C0, 0x12, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok451) {
  my_decimal decimal = {{0x0, 0x0, 0xFFFFFFFF, 0x1C0000}};

  my_decimal decimal_check = {{0x8, 0x0, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok452) {
  my_decimal decimal = {{0x0, 0x0, 0xFFFFFFFF, 0x801C0000}};

  my_decimal decimal_check = {{0x8, 0x0, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok453) {
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0x0, 0x0}};

  my_decimal decimal_check = {{0xFFFFFFFF, 0xFFFFFFFF, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok454) {
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0x0, 0x80000000}};

  my_decimal decimal_check = {{0xFFFFFFFF, 0xFFFFFFFF, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok455) {
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0x0, 0x10000}};

  my_decimal decimal_check = {{0x9999999A, 0x19999999, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok456) {
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0x0, 0x80010000}};

  my_decimal decimal_check = {{0x9999999A, 0x19999999, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok457) {
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0x0, 0x30000}};

  my_decimal decimal_check = {{0x4BC6A7F0, 0x418937, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok458) {
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0x0, 0x80030000}};

  my_decimal decimal_check = {{0x4BC6A7F0, 0x418937, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok459) {
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0x0, 0xB0000}};

  my_decimal decimal_check = {{0xAFEBFF1, 0x0, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok460) {
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0x0, 0x800B0000}};

  my_decimal decimal_check = {{0xAFEBFF1, 0x0, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok461) {
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0x0, 0x110000}};

  my_decimal decimal_check = {{0xB8, 0x0, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok462) {
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0x0, 0x80110000}};

  my_decimal decimal_check = {{0xB8, 0x0, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok463) {
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0x0, 0x130000}};

  my_decimal decimal_check = {{0x2, 0x0, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok464) {
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0x0, 0x80130000}};

  my_decimal decimal_check = {{0x2, 0x0, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok465) {
  my_decimal decimal = {{0x0, 0xFFFFFFFF, 0x0, 0x0}};

  my_decimal decimal_check = {{0x0, 0xFFFFFFFF, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok466) {
  my_decimal decimal = {{0x0, 0xFFFFFFFF, 0x0, 0x80000000}};

  my_decimal decimal_check = {{0x0, 0xFFFFFFFF, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok467) {
  my_decimal decimal = {{0x0, 0xFFFFFFFF, 0x0, 0x10000}};

  my_decimal decimal_check = {{0x80000000, 0x19999999, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok468) {
  my_decimal decimal = {{0x0, 0xFFFFFFFF, 0x0, 0x80010000}};

  my_decimal decimal_check = {{0x80000000, 0x19999999, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok469) {
  my_decimal decimal = {{0x0, 0xFFFFFFFF, 0x0, 0x30000}};

  my_decimal decimal_check = {{0x4B851EB8, 0x418937, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok470) {
  my_decimal decimal = {{0x0, 0xFFFFFFFF, 0x0, 0x80030000}};

  my_decimal decimal_check = {{0x4B851EB8, 0x418937, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok471) {
  my_decimal decimal = {{0x0, 0xFFFFFFFF, 0x0, 0x90000}};

  my_decimal decimal_check = {{0x4B82FA05, 0x4, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok472) {
  my_decimal decimal = {{0x0, 0xFFFFFFFF, 0x0, 0x80090000}};

  my_decimal decimal_check = {{0x4B82FA05, 0x4, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok473) {
  my_decimal decimal = {{0x0, 0xFFFFFFFF, 0x0, 0x110000}};

  my_decimal decimal_check = {{0xB8, 0x0, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok474) {
  my_decimal decimal = {{0x0, 0xFFFFFFFF, 0x0, 0x80110000}};

  my_decimal decimal_check = {{0xB8, 0x0, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok475) {
  my_decimal decimal = {{0x0, 0xFFFFFFFF, 0x0, 0x130000}};

  my_decimal decimal_check = {{0x2, 0x0, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok476) {
  my_decimal decimal = {{0x0, 0xFFFFFFFF, 0x0, 0x80130000}};

  my_decimal decimal_check = {{0x2, 0x0, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok477) {
  my_decimal decimal = {{0xFFFFFFFF, 0x0, 0x0, 0x0}};

  my_decimal decimal_check = {{0xFFFFFFFF, 0x0, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok478) {
  my_decimal decimal = {{0xFFFFFFFF, 0x0, 0x0, 0x80000000}};

  my_decimal decimal_check = {{0xFFFFFFFF, 0x0, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok479) {
  my_decimal decimal = {{0xFFFFFFFF, 0x0, 0x0, 0x10000}};

  my_decimal decimal_check = {{0x1999999A, 0x0, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok480) {
  my_decimal decimal = {{0xFFFFFFFF, 0x0, 0x0, 0x80010000}};

  my_decimal decimal_check = {{0x1999999A, 0x0, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok481) {
  my_decimal decimal = {{0xFFFFFFFF, 0x0, 0x0, 0x20000}};

  my_decimal decimal_check = {{0x28F5C29, 0x0, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok482) {
  my_decimal decimal = {{0xFFFFFFFF, 0x0, 0x0, 0x80020000}};

  my_decimal decimal_check = {{0x28F5C29, 0x0, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok483) {
  my_decimal decimal = {{0xFFFFFFFF, 0x0, 0x0, 0x50000}};

  my_decimal decimal_check = {{0xA7C6, 0x0, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok484) {
  my_decimal decimal = {{0xFFFFFFFF, 0x0, 0x0, 0x80050000}};

  my_decimal decimal_check = {{0xA7C6, 0x0, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok485) {
  my_decimal decimal = {{0xFFFFFFFF, 0x0, 0x0, 0x80000}};

  my_decimal decimal_check = {{0x2B, 0x0, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok486) {
  my_decimal decimal = {{0xFFFFFFFF, 0x0, 0x0, 0x80080000}};

  my_decimal decimal_check = {{0x2B, 0x0, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok487) {
  my_decimal decimal = {{0xFFFFFFFF, 0x0, 0x0, 0x90000}};

  my_decimal decimal_check = {{0x4, 0x0, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok488) {
  my_decimal decimal = {{0xFFFFFFFF, 0x0, 0x0, 0x80090000}};

  my_decimal decimal_check = {{0x4, 0x0, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok489) {
  my_decimal decimal = {{0xA, 0x0, 0x0, 0x10000}};

  my_decimal decimal_check = {{0x1, 0x0, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok490) {
  my_decimal decimal = {{0xA, 0x0, 0x0, 0x80010000}};

  my_decimal decimal_check = {{0x1, 0x0, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok491) {
  my_decimal decimal = {{0x64, 0x0, 0x0, 0x20000}};

  my_decimal decimal_check = {{0x1, 0x0, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok492) {
  my_decimal decimal = {{0x64, 0x0, 0x0, 0x80020000}};

  my_decimal decimal_check = {{0x1, 0x0, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok493) {
  my_decimal decimal = {{0x3E8, 0x0, 0x0, 0x30000}};

  my_decimal decimal_check = {{0x1, 0x0, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok494) {
  my_decimal decimal = {{0x3E8, 0x0, 0x0, 0x80030000}};

  my_decimal decimal_check = {{0x1, 0x0, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok495) {
  my_decimal decimal = {{0x540BE400, 0x2, 0x0, 0xA0000}};

  my_decimal decimal_check = {{0x1, 0x0, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok496) {
  my_decimal decimal = {{0x540BE400, 0x2, 0x0, 0x800A0000}};

  my_decimal decimal_check = {{0x1, 0x0, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok497) {
  my_decimal decimal = {{0x6FC10000, 0x2386F2, 0x0, 0x100000}};

  my_decimal decimal_check = {{0x1, 0x0, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok498) {
  my_decimal decimal = {{0x6FC10000, 0x2386F2, 0x0, 0x80100000}};

  my_decimal decimal_check = {{0x1, 0x0, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok499) {
  my_decimal decimal = {{0xF6800000, 0x2C7E14A, 0x152D, 0x170000}};

  my_decimal decimal_check = {{0x1, 0x0, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok500) {
  my_decimal decimal = {{0xF6800000, 0x2C7E14A, 0x152D, 0x80170000}};

  my_decimal decimal_check = {{0x1, 0x0, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok501) {
  my_decimal decimal = {{0xE8000000, 0x9FD0803C, 0x33B2E3C, 0x1B0000}};

  my_decimal decimal_check = {{0x1, 0x0, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok502) {
  my_decimal decimal = {{0xE8000000, 0x9FD0803C, 0x33B2E3C, 0x801B0000}};

  my_decimal decimal_check = {{0x1, 0x0, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok503) {
  my_decimal decimal = {{0x10000000, 0x3E250261, 0x204FCE5E, 0x1C0000}};

  my_decimal decimal_check = {{0x1, 0x0, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok504) {
  my_decimal decimal = {{0x10000000, 0x3E250261, 0x204FCE5E, 0x801C0000}};

  my_decimal decimal_check = {{0x1, 0x0, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok505) {
  my_decimal decimal = {{0xB, 0x0, 0x0, 0x10000}};

  my_decimal decimal_check = {{0x1, 0x0, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok506) {
  my_decimal decimal = {{0xB, 0x0, 0x0, 0x80010000}};

  my_decimal decimal_check = {{0x1, 0x0, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok507) {
  my_decimal decimal = {{0x4BC, 0x0, 0x0, 0x20000}};

  my_decimal decimal_check = {{0xC, 0x0, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok508) {
  my_decimal decimal = {{0x4BC, 0x0, 0x0, 0x80020000}};

  my_decimal decimal_check = {{0xC, 0x0, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok509) {
  my_decimal decimal = {{0x1E0F3, 0x0, 0x0, 0x30000}};

  my_decimal decimal_check = {{0x7B, 0x0, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok510) {
  my_decimal decimal = {{0x1E0F3, 0x0, 0x0, 0x80030000}};

  my_decimal decimal_check = {{0x7B, 0x0, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok511) {
  my_decimal decimal = {{0xBC4FF2, 0x0, 0x0, 0x40000}};

  my_decimal decimal_check = {{0x4D2, 0x0, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok512) {
  my_decimal decimal = {{0xBC4FF2, 0x0, 0x0, 0x80040000}};

  my_decimal decimal_check = {{0x4D2, 0x0, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok513) {
  my_decimal decimal = {{0x499529D9, 0x0, 0x0, 0x50000}};

  my_decimal decimal_check = {{0x3039, 0x0, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok514) {
  my_decimal decimal = {{0x499529D9, 0x0, 0x0, 0x80050000}};

  my_decimal decimal_check = {{0x3039, 0x0, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok515) {
  my_decimal decimal = {{0xBE8EF240, 0x1C, 0x0, 0x60000}};

  my_decimal decimal_check = {{0x1E240, 0x0, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok516) {
  my_decimal decimal = {{0xBE8EF240, 0x1C, 0x0, 0x80060000}};

  my_decimal decimal_check = {{0x1E240, 0x0, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok517) {
  my_decimal decimal = {{0x73593407, 0xB3A, 0x0, 0x70000}};

  my_decimal decimal_check = {{0x12D687, 0x0, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok518) {
  my_decimal decimal = {{0x73593407, 0xB3A, 0x0, 0x80070000}};

  my_decimal decimal_check = {{0x12D687, 0x0, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok519) {
  my_decimal decimal = {{0xEB1F0AD2, 0xAB54A98C, 0x0, 0xA0000}};

  my_decimal decimal_check = {{0x499602D2, 0x0, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok520) {
  my_decimal decimal = {{0xEB1F0AD2, 0xAB54A98C, 0x0, 0x800A0000}};

  my_decimal decimal_check = {{0x499602D2, 0x0, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok521) {
  my_decimal decimal = {{0xF91EAFF2, 0x6D795225, 0x3FD35EB, 0xE0000}};

  my_decimal decimal_check = {{0x73CE2FF2, 0xB3A, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok522) {
  my_decimal decimal = {{0xF91EAFF2, 0x6D795225, 0x3FD35EB, 0x800E0000}};

  my_decimal decimal_check = {{0x73CE2FF2, 0xB3A, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok523) {
  my_decimal decimal = {{0x63, 0x0, 0x0, 0x0}};

  my_decimal decimal_check = {{0x63, 0x0, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok524) {
  my_decimal decimal = {{0x63, 0x0, 0x0, 0x80000000}};

  my_decimal decimal_check = {{0x63, 0x0, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok525) {
  my_decimal decimal = {{0x63, 0x0, 0x0, 0x10000}};

  my_decimal decimal_check = {{0xA, 0x0, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok526) {
  my_decimal decimal = {{0x63, 0x0, 0x0, 0x80010000}};

  my_decimal decimal_check = {{0xA, 0x0, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok527) {
  my_decimal decimal = {{0x270F, 0x0, 0x0, 0x20000}};

  my_decimal decimal_check = {{0x64, 0x0, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok528) {
  my_decimal decimal = {{0x270F, 0x0, 0x0, 0x80020000}};

  my_decimal decimal_check = {{0x64, 0x0, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok529) {
  my_decimal decimal = {{0xF423F, 0x0, 0x0, 0x30000}};

  my_decimal decimal_check = {{0x3E8, 0x0, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok530) {
  my_decimal decimal = {{0xF423F, 0x0, 0x0, 0x80030000}};

  my_decimal decimal_check = {{0x3E8, 0x0, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok531) {
  my_decimal decimal = {{0x5F5E0FF, 0x0, 0x0, 0x40000}};

  my_decimal decimal_check = {{0x2710, 0x0, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok532) {
  my_decimal decimal = {{0x5F5E0FF, 0x0, 0x0, 0x80040000}};

  my_decimal decimal_check = {{0x2710, 0x0, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok533) {
  my_decimal decimal = {{0x540BE3FF, 0x2, 0x0, 0x50000}};

  my_decimal decimal_check = {{0x186A0, 0x0, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok534) {
  my_decimal decimal = {{0x540BE3FF, 0x2, 0x0, 0x80050000}};

  my_decimal decimal_check = {{0x186A0, 0x0, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok535) {
  my_decimal decimal = {{0xD4A50FFF, 0xE8, 0x0, 0x60000}};

  my_decimal decimal_check = {{0xF4240, 0x0, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok536) {
  my_decimal decimal = {{0xD4A50FFF, 0xE8, 0x0, 0x80060000}};

  my_decimal decimal_check = {{0xF4240, 0x0, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok537) {
  my_decimal decimal = {{0x107A3FFF, 0x5AF3, 0x0, 0x70000}};

  my_decimal decimal_check = {{0x989680, 0x0, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok538) {
  my_decimal decimal = {{0x107A3FFF, 0x5AF3, 0x0, 0x80070000}};

  my_decimal decimal_check = {{0x989680, 0x0, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok539) {
  my_decimal decimal = {{0x6FC0FFFF, 0x2386F2, 0x0, 0x80000}};

  my_decimal decimal_check = {{0x5F5E100, 0x0, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok540) {
  my_decimal decimal = {{0x6FC0FFFF, 0x2386F2, 0x0, 0x80080000}};

  my_decimal decimal_check = {{0x5F5E100, 0x0, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok541) {
  my_decimal decimal = {{0xA763FFFF, 0xDE0B6B3, 0x0, 0x90000}};

  my_decimal decimal_check = {{0x3B9ACA00, 0x0, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok542) {
  my_decimal decimal = {{0xA763FFFF, 0xDE0B6B3, 0x0, 0x80090000}};

  my_decimal decimal_check = {{0x3B9ACA00, 0x0, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok543) {
  my_decimal decimal = {{0x630FFFFF, 0x6BC75E2D, 0x5, 0xA0000}};

  my_decimal decimal_check = {{0x540BE400, 0x2, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok544) {
  my_decimal decimal = {{0x630FFFFF, 0x6BC75E2D, 0x5, 0x800A0000}};

  my_decimal decimal_check = {{0x540BE400, 0x2, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok545) {
  my_decimal decimal = {{0x9, 0x0, 0x0, 0x0}};

  my_decimal decimal_check = {{0x9, 0x0, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok546) {
  my_decimal decimal = {{0x9, 0x0, 0x0, 0x80000000}};

  my_decimal decimal_check = {{0x9, 0x0, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok547) {
  my_decimal decimal = {{0x9, 0x0, 0x0, 0x10000}};

  my_decimal decimal_check = {{0x1, 0x0, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok548) {
  my_decimal decimal = {{0x9, 0x0, 0x0, 0x80010000}};

  my_decimal decimal_check = {{0x1, 0x0, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok549) {
  my_decimal decimal = {{0x63, 0x0, 0x0, 0x20000}};

  my_decimal decimal_check = {{0x1, 0x0, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok550) {
  my_decimal decimal = {{0x63, 0x0, 0x0, 0x80020000}};

  my_decimal decimal_check = {{0x1, 0x0, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok551) {
  my_decimal decimal = {{0x3E7, 0x0, 0x0, 0x30000}};

  my_decimal decimal_check = {{0x1, 0x0, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok552) {
  my_decimal decimal = {{0x3E7, 0x0, 0x0, 0x80030000}};

  my_decimal decimal_check = {{0x1, 0x0, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok553) {
  my_decimal decimal = {{0x270F, 0x0, 0x0, 0x40000}};

  my_decimal decimal_check = {{0x1, 0x0, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok554) {
  my_decimal decimal = {{0x270F, 0x0, 0x0, 0x80040000}};

  my_decimal decimal_check = {{0x1, 0x0, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok555) {
  my_decimal decimal = {{0x1869F, 0x0, 0x0, 0x50000}};

  my_decimal decimal_check = {{0x1, 0x0, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok556) {
  my_decimal decimal = {{0x1869F, 0x0, 0x0, 0x80050000}};

  my_decimal decimal_check = {{0x1, 0x0, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok557) {
  my_decimal decimal = {{0xF423F, 0x0, 0x0, 0x60000}};

  my_decimal decimal_check = {{0x1, 0x0, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok558) {
  my_decimal decimal = {{0xF423F, 0x0, 0x0, 0x80060000}};

  my_decimal decimal_check = {{0x1, 0x0, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok559) {
  my_decimal decimal = {{0x98967F, 0x0, 0x0, 0x70000}};

  my_decimal decimal_check = {{0x1, 0x0, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok560) {
  my_decimal decimal = {{0x98967F, 0x0, 0x0, 0x80070000}};

  my_decimal decimal_check = {{0x1, 0x0, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok561) {
  my_decimal decimal = {{0x5F5E0FF, 0x0, 0x0, 0x80000}};

  my_decimal decimal_check = {{0x1, 0x0, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok562) {
  my_decimal decimal = {{0x5F5E0FF, 0x0, 0x0, 0x80080000}};

  my_decimal decimal_check = {{0x1, 0x0, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok563) {
  my_decimal decimal = {{0x3B9AC9FF, 0x0, 0x0, 0x90000}};

  my_decimal decimal_check = {{0x1, 0x0, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok564) {
  my_decimal decimal = {{0x3B9AC9FF, 0x0, 0x0, 0x80090000}};

  my_decimal decimal_check = {{0x1, 0x0, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok565) {
  my_decimal decimal = {{0x540BE3FF, 0x2, 0x0, 0xA0000}};

  my_decimal decimal_check = {{0x1, 0x0, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok566) {
  my_decimal decimal = {{0x540BE3FF, 0x2, 0x0, 0x800A0000}};

  my_decimal decimal_check = {{0x1, 0x0, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok567) {
  my_decimal decimal = {{0x630FFFFF, 0x6BC75E2D, 0x5, 0x140000}};

  my_decimal decimal_check = {{0x1, 0x0, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok568) {
  my_decimal decimal = {{0x630FFFFF, 0x6BC75E2D, 0x5, 0x80140000}};

  my_decimal decimal_check = {{0x1, 0x0, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok569) {
  my_decimal decimal = {{0x0, 0x0, 0x0, 0x80000000}};

  my_decimal decimal_check = {{0x0, 0x0, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok570) {
  my_decimal decimal = {{0x0, 0x0, 0x0, 0x0}};

  my_decimal decimal_check = {{0x0, 0x0, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok571) {
  my_decimal decimal = {{0x0, 0x0, 0x0, 0x80010000}};

  my_decimal decimal_check = {{0x0, 0x0, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok572) {
  my_decimal decimal = {{0x0, 0x0, 0x0, 0x10000}};

  my_decimal decimal_check = {{0x0, 0x0, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok573) {
  my_decimal decimal = {{0x0, 0x0, 0x0, 0x80020000}};

  my_decimal decimal_check = {{0x0, 0x0, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok574) {
  my_decimal decimal = {{0x0, 0x0, 0x0, 0x20000}};

  my_decimal decimal_check = {{0x0, 0x0, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok575) {
  my_decimal decimal = {{0x0, 0x0, 0x0, 0x800E0000}};

  my_decimal decimal_check = {{0x0, 0x0, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok576) {
  my_decimal decimal = {{0x0, 0x0, 0x0, 0xE0000}};

  my_decimal decimal_check = {{0x0, 0x0, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok577) {
  my_decimal decimal = {{0x0, 0x0, 0x0, 0x801B0000}};

  my_decimal decimal_check = {{0x0, 0x0, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok578) {
  my_decimal decimal = {{0x0, 0x0, 0x0, 0x1B0000}};

  my_decimal decimal_check = {{0x0, 0x0, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok579) {
  my_decimal decimal = {{0x0, 0x0, 0x0, 0x801C0000}};

  my_decimal decimal_check = {{0x0, 0x0, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok580) {
  my_decimal decimal = {{0x0, 0x0, 0x0, 0x1C0000}};

  my_decimal decimal_check = {{0x0, 0x0, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok581) {
  my_decimal decimal = {{0x5, 0x0, 0x0, 0x10000}};

  my_decimal decimal_check = {{0x0, 0x0, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok582) {
  my_decimal decimal = {{0x5, 0x0, 0x0, 0x80010000}};

  my_decimal decimal_check = {{0x0, 0x0, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok583) {
  my_decimal decimal = {{0x31, 0x0, 0x0, 0x20000}};

  my_decimal decimal_check = {{0x0, 0x0, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok584) {
  my_decimal decimal = {{0x31, 0x0, 0x0, 0x80020000}};

  my_decimal decimal_check = {{0x0, 0x0, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok585) {
  my_decimal decimal = {{0x33, 0x0, 0x0, 0x20000}};

  my_decimal decimal_check = {{0x1, 0x0, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok586) {
  my_decimal decimal = {{0x33, 0x0, 0x0, 0x80020000}};

  my_decimal decimal_check = {{0x1, 0x0, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok587) {
  my_decimal decimal = {{0x2FAF07F, 0x0, 0x0, 0x80000}};

  my_decimal decimal_check = {{0x0, 0x0, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok588) {
  my_decimal decimal = {{0x2FAF07F, 0x0, 0x0, 0x80080000}};

  my_decimal decimal_check = {{0x0, 0x0, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok589) {
  my_decimal decimal = {{0x87FFFFFF, 0x1F128130, 0x1027E72F, 0x1C0000}};

  my_decimal decimal_check = {{0x0, 0x0, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok590) {
  my_decimal decimal = {{0x87FFFFFF, 0x1F128130, 0x1027E72F, 0x801C0000}};

  my_decimal decimal_check = {{0x0, 0x0, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok591) {
  my_decimal decimal = {{0x88000001, 0x1F128130, 0x1027E72F, 0x1C0000}};

  my_decimal decimal_check = {{0x1, 0x0, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok592) {
  my_decimal decimal = {{0x88000001, 0x1F128130, 0x1027E72F, 0x801C0000}};

  my_decimal decimal_check = {{0x1, 0x0, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok593) {
  my_decimal decimal = {{0x88000000, 0x1F128130, 0x1027E72F, 0x1C0000}};

  my_decimal decimal_check = {{0x0, 0x0, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok594) {
  my_decimal decimal = {{0x88000000, 0x1F128130, 0x1027E72F, 0x801C0000}};

  my_decimal decimal_check = {{0x0, 0x0, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok595) {
  my_decimal decimal = {{0x63, 0x0, 0x0, 0x20000}};

  my_decimal decimal_check = {{0x1, 0x0, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok596) {
  my_decimal decimal = {{0x63, 0x0, 0x0, 0x80020000}};

  my_decimal decimal_check = {{0x1, 0x0, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok597) {
  my_decimal decimal = {{0x3B9AC9FF, 0x0, 0x0, 0x90000}};

  my_decimal decimal_check = {{0x1, 0x0, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok598) {
  my_decimal decimal = {{0x3B9AC9FF, 0x0, 0x0, 0x80090000}};

  my_decimal decimal_check = {{0x1, 0x0, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok599) {
  my_decimal decimal = {{0xFFFFFFF, 0x3E250261, 0x204FCE5E, 0x1C0000}};

  my_decimal decimal_check = {{0x1, 0x0, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok600) {
  my_decimal decimal = {{0xFFFFFFF, 0x3E250261, 0x204FCE5E, 0x801C0000}};

  my_decimal decimal_check = {{0x1, 0x0, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok601) {
  my_decimal decimal = {{0x10000001, 0x3E250261, 0x204FCE5E, 0x1C0000}};

  my_decimal decimal_check = {{0x1, 0x0, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok602) {
  my_decimal decimal = {{0x10000001, 0x3E250261, 0x204FCE5E, 0x801C0000}};

  my_decimal decimal_check = {{0x1, 0x0, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok603) {
  my_decimal decimal = {{0xF, 0x0, 0x0, 0x10000}};

  my_decimal decimal_check = {{0x2, 0x0, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok604) {
  my_decimal decimal = {{0xF, 0x0, 0x0, 0x80010000}};

  my_decimal decimal_check = {{0x2, 0x0, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok605) {
  my_decimal decimal = {{0x95, 0x0, 0x0, 0x20000}};

  my_decimal decimal_check = {{0x1, 0x0, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok606) {
  my_decimal decimal = {{0x95, 0x0, 0x0, 0x80020000}};

  my_decimal decimal_check = {{0x1, 0x0, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok607) {
  my_decimal decimal = {{0x97, 0x0, 0x0, 0x20000}};

  my_decimal decimal_check = {{0x2, 0x0, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok608) {
  my_decimal decimal = {{0x97, 0x0, 0x0, 0x80020000}};

  my_decimal decimal_check = {{0x2, 0x0, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok609) {
  my_decimal decimal = {{0x8F0D17F, 0x0, 0x0, 0x80000}};

  my_decimal decimal_check = {{0x1, 0x0, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok610) {
  my_decimal decimal = {{0x8F0D17F, 0x0, 0x0, 0x80080000}};

  my_decimal decimal_check = {{0x1, 0x0, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok611) {
  my_decimal decimal = {{0x97FFFFFF, 0x5D378391, 0x3077B58D, 0x1C0000}};

  my_decimal decimal_check = {{0x1, 0x0, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok612) {
  my_decimal decimal = {{0x97FFFFFF, 0x5D378391, 0x3077B58D, 0x801C0000}};

  my_decimal decimal_check = {{0x1, 0x0, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok613) {
  my_decimal decimal = {{0x98000001, 0x5D378391, 0x3077B58D, 0x1C0000}};

  my_decimal decimal_check = {{0x2, 0x0, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok614) {
  my_decimal decimal = {{0x98000001, 0x5D378391, 0x3077B58D, 0x801C0000}};

  my_decimal decimal_check = {{0x2, 0x0, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok615) {
  my_decimal decimal = {{0x98000000, 0x5D378391, 0x3077B58D, 0x1C0000}};

  my_decimal decimal_check = {{0x2, 0x0, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok616) {
  my_decimal decimal = {{0x98000000, 0x5D378391, 0x3077B58D, 0x801C0000}};

  my_decimal decimal_check = {{0x2, 0x0, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok617) {
  my_decimal decimal = {{0x1E847F, 0x0, 0x0, 0x60000}};

  my_decimal decimal_check = {{0x2, 0x0, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok618) {
  my_decimal decimal = {{0x1E847F, 0x0, 0x0, 0x80060000}};

  my_decimal decimal_check = {{0x2, 0x0, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok619) {
  my_decimal decimal = {{0x1FFFFFFF, 0x7C4A04C2, 0x409F9CBC, 0x1C0000}};

  my_decimal decimal_check = {{0x2, 0x0, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok620) {
  my_decimal decimal = {{0x1FFFFFFF, 0x7C4A04C2, 0x409F9CBC, 0x801C0000}};

  my_decimal decimal_check = {{0x2, 0x0, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok621) {
  my_decimal decimal = {{0xEC25EE11, 0x79F56552, 0xA03CF9AA, 0x120000}};

  my_decimal decimal_check = {{0x8BDF6EA7, 0xB, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok622) {
  my_decimal decimal = {{0xEC25EE11, 0x79F56552, 0xA03CF9AA, 0x80120000}};

  my_decimal decimal_check = {{0x8BDF6EA7, 0xB, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok623) {
  my_decimal decimal = {{0x9852FD0D, 0x74407160, 0x30AAF68A, 0xF0000}};

  my_decimal decimal_check = {{0xE2E6CF4D, 0xDB2, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok624) {
  my_decimal decimal = {{0x9852FD0D, 0x74407160, 0x30AAF68A, 0x800F0000}};

  my_decimal decimal_check = {{0xE2E6CF4D, 0xDB2, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok625) {
  my_decimal decimal = {{0x5FD8693A, 0xF38536E9, 0x2AD3F6DD, 0x80190000}};

  my_decimal decimal_check = {{0x52D, 0x0, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok626) {
  my_decimal decimal = {{0x5FD8693A, 0xF38536E9, 0x2AD3F6DD, 0x190000}};

  my_decimal decimal_check = {{0x52D, 0x0, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok627) {
  my_decimal decimal = {{0x256906D0, 0xA396C78B, 0x7E07AF5A, 0x130000}};

  my_decimal decimal_check = {{0xE87BFE74, 0x0, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok628) {
  my_decimal decimal = {{0x256906D0, 0xA396C78B, 0x7E07AF5A, 0x80130000}};

  my_decimal decimal_check = {{0xE87BFE74, 0x0, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok629) {
  my_decimal decimal = {{0xAC22247E, 0x7F6A00CF, 0xB53A1693, 0x80000000}};

  my_decimal decimal_check = {
      {0xAC22247E, 0x7F6A00CF, 0xB53A1693, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok630) {
  my_decimal decimal = {{0xAC22247E, 0x7F6A00CF, 0xB53A1693, 0x0}};

  my_decimal decimal_check = {{0xAC22247E, 0x7F6A00CF, 0xB53A1693, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok631) {
  my_decimal decimal = {{0x27B442B8, 0x3DC44477, 0x1C2C6924, 0xF0000}};

  my_decimal decimal_check = {{0x1CF6820B, 0x7EE, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok632) {
  my_decimal decimal = {{0x27B442B8, 0x3DC44477, 0x1C2C6924, 0x800F0000}};

  my_decimal decimal_check = {{0x1CF6820B, 0x7EE, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok633) {
  my_decimal decimal = {{0xE061BB9B, 0xBC593DAE, 0x1092AF59, 0x80150000}};

  my_decimal decimal_check = {{0x4E4383, 0x0, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok634) {
  my_decimal decimal = {{0xE061BB9B, 0xBC593DAE, 0x1092AF59, 0x150000}};

  my_decimal decimal_check = {{0x4E4383, 0x0, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok635) {
  my_decimal decimal = {{0x8981396C, 0xD4F24636, 0x51B70968, 0x140000}};

  my_decimal decimal_check = {{0xF12E195, 0x0, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok636) {
  my_decimal decimal = {{0x8981396C, 0xD4F24636, 0x51B70968, 0x80140000}};

  my_decimal decimal_check = {{0xF12E195, 0x0, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok637) {
  my_decimal decimal = {{0x2CC0910A, 0xEF2CEFEC, 0xD7E70A8B, 0x80050000}};

  my_decimal decimal_check = {{0xFE3A9AFE, 0x6DF799E0, 0x8D7E, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok638) {
  my_decimal decimal = {{0x2CC0910A, 0xEF2CEFEC, 0xD7E70A8B, 0x50000}};

  my_decimal decimal_check = {{0xFE3A9AFE, 0x6DF799E0, 0x8D7E, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok639) {
  my_decimal decimal = {{0xEC2175A6, 0x5FDD2041, 0xFA89E679, 0x1C0000}};

  my_decimal decimal_check = {{0x8, 0x0, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok640) {
  my_decimal decimal = {{0xEC2175A6, 0x5FDD2041, 0xFA89E679, 0x801C0000}};

  my_decimal decimal_check = {{0x8, 0x0, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok641) {
  my_decimal decimal = {{0x7972A4AD, 0x98D51824, 0xBCABFE52, 0x80020000}};

  my_decimal decimal_check = {{0x136E80C, 0xB4BA7371, 0x1E2FFFB, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok642) {
  my_decimal decimal = {{0x7972A4AD, 0x98D51824, 0xBCABFE52, 0x20000}};

  my_decimal decimal_check = {{0x136E80C, 0xB4BA7371, 0x1E2FFFB, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok643) {
  my_decimal decimal = {{0xE33D0894, 0xFD9BBCC5, 0x24D211E2, 0x80100000}};

  my_decimal decimal_check = {{0x51FDD9DC, 0x109, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok644) {
  my_decimal decimal = {{0xE33D0894, 0xFD9BBCC5, 0x24D211E2, 0x100000}};

  my_decimal decimal_check = {{0x51FDD9DC, 0x109, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok645) {
  my_decimal decimal = {{0x54CE59A0, 0x1F32D7E8, 0x503863E3, 0x80000}};

  my_decimal decimal_check = {{0x9F308364, 0x756F3E00, 0xD, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok646) {
  my_decimal decimal = {{0x54CE59A0, 0x1F32D7E8, 0x503863E3, 0x80080000}};

  my_decimal decimal_check = {{0x9F308364, 0x756F3E00, 0xD, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok647) {
  my_decimal decimal = {{0xDD3ACA68, 0x2F8264FE, 0x37201C87, 0x80000000}};

  my_decimal decimal_check = {
      {0xDD3ACA68, 0x2F8264FE, 0x37201C87, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok648) {
  my_decimal decimal = {{0xDD3ACA68, 0x2F8264FE, 0x37201C87, 0x0}};

  my_decimal decimal_check = {{0xDD3ACA68, 0x2F8264FE, 0x37201C87, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok649) {
  my_decimal decimal = {{0x1ADCBFEF, 0xA44D5CE9, 0x52DBEC39, 0x800B0000}};

  my_decimal decimal_check = {{0xA21BB894, 0x38F0B8E, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok650) {
  my_decimal decimal = {{0x1ADCBFEF, 0xA44D5CE9, 0x52DBEC39, 0xB0000}};

  my_decimal decimal_check = {{0xA21BB894, 0x38F0B8E, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok651) {
  my_decimal decimal = {{0x10C185C8, 0x4AE8D82C, 0x1DEB7623, 0x80100000}};

  my_decimal decimal_check = {{0x983C8F1F, 0xD7, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok652) {
  my_decimal decimal = {{0x10C185C8, 0x4AE8D82C, 0x1DEB7623, 0x100000}};

  my_decimal decimal_check = {{0x983C8F1F, 0xD7, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok653) {
  my_decimal decimal = {{0x5EE1F143, 0xA8DA6757, 0x333125E4, 0x80000}};

  my_decimal decimal_check = {{0x168992F6, 0x96ADD252, 0x8, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok654) {
  my_decimal decimal = {{0x5EE1F143, 0xA8DA6757, 0x333125E4, 0x80080000}};

  my_decimal decimal_check = {{0x168992F6, 0x96ADD252, 0x8, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok655) {
  my_decimal decimal = {{0x88C380C2, 0x3A8EF139, 0xDDABA305, 0x1C0000}};

  my_decimal decimal_check = {{0x7, 0x0, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok656) {
  my_decimal decimal = {{0x88C380C2, 0x3A8EF139, 0xDDABA305, 0x801C0000}};

  my_decimal decimal_check = {{0x7, 0x0, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok657) {
  my_decimal decimal = {{0x31F3DE17, 0x68FEFE5F, 0xB617AB8F, 0x80000000}};

  my_decimal decimal_check = {
      {0x31F3DE17, 0x68FEFE5F, 0xB617AB8F, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok658) {
  my_decimal decimal = {{0x31F3DE17, 0x68FEFE5F, 0xB617AB8F, 0x0}};

  my_decimal decimal_check = {{0x31F3DE17, 0x68FEFE5F, 0xB617AB8F, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok659) {
  my_decimal decimal = {{0x3E2C09E5, 0x40A21AE0, 0x92DA1BB0, 0x80080000}};

  my_decimal decimal_check = {{0xBAC7E237, 0xA33EA68E, 0x18, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok660) {
  my_decimal decimal = {{0x3E2C09E5, 0x40A21AE0, 0x92DA1BB0, 0x80000}};

  my_decimal decimal_check = {{0xBAC7E237, 0xA33EA68E, 0x18, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok661) {
  my_decimal decimal = {{0x449AEF8D, 0x886E6706, 0x1B1B4C40, 0x80130000}};

  my_decimal decimal_check = {{0x3200BEC3, 0x0, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok662) {
  my_decimal decimal = {{0x449AEF8D, 0x886E6706, 0x1B1B4C40, 0x130000}};

  my_decimal decimal_check = {{0x3200BEC3, 0x0, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok663) {
  my_decimal decimal = {{0x21CDA615, 0xC3AFF1, 0xEE64CA0, 0x40000}};

  my_decimal decimal_check = {{0x7CF4FCAA, 0x645A21AE, 0x61A5, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok664) {
  my_decimal decimal = {{0x21CDA615, 0xC3AFF1, 0xEE64CA0, 0x80040000}};

  my_decimal decimal_check = {{0x7CF4FCAA, 0x645A21AE, 0x61A5, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok665) {
  my_decimal decimal = {{0x65209726, 0x298560F1, 0x92C385B4, 0x80150000}};

  my_decimal decimal_check = {{0x2B5127F, 0x0, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok666) {
  my_decimal decimal = {{0x65209726, 0x298560F1, 0x92C385B4, 0x150000}};

  my_decimal decimal_check = {{0x2B5127F, 0x0, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok667) {
  my_decimal decimal = {{0xBA14F7C9, 0x2E90271A, 0xB5A119ED, 0x1C0000}};

  my_decimal decimal_check = {{0x6, 0x0, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok668) {
  my_decimal decimal = {{0xBA14F7C9, 0x2E90271A, 0xB5A119ED, 0x801C0000}};

  my_decimal decimal_check = {{0x6, 0x0, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok669) {
  my_decimal decimal = {{0x37FD65C2, 0x21C5DB4E, 0xE6CFE484, 0x801B0000}};

  my_decimal decimal_check = {{0x47, 0x0, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok670) {
  my_decimal decimal = {{0x37FD65C2, 0x21C5DB4E, 0xE6CFE484, 0x1B0000}};

  my_decimal decimal_check = {{0x47, 0x0, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok671) {
  my_decimal decimal = {{0x777E5AA2, 0xEE95FAFE, 0x79884F14, 0x1B0000}};

  my_decimal decimal_check = {{0x26, 0x0, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok672) {
  my_decimal decimal = {{0x777E5AA2, 0xEE95FAFE, 0x79884F14, 0x801B0000}};

  my_decimal decimal_check = {{0x26, 0x0, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok673) {
  my_decimal decimal = {{0xFE9AF8A4, 0x3F35FA5, 0x892702E1, 0x170000}};

  my_decimal decimal_check = {{0x67A12, 0x0, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok674) {
  my_decimal decimal = {{0xFE9AF8A4, 0x3F35FA5, 0x892702E1, 0x80170000}};

  my_decimal decimal_check = {{0x67A12, 0x0, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok675) {
  my_decimal decimal = {{0x267E7D31, 0xA840F1F3, 0xEA5D2737, 0x60000}};

  my_decimal decimal_check = {{0xBDB932BE, 0xF932D12C, 0xF5B, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok676) {
  my_decimal decimal = {{0x267E7D31, 0xA840F1F3, 0xEA5D2737, 0x80060000}};

  my_decimal decimal_check = {{0xBDB932BE, 0xF932D12C, 0xF5B, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok677) {
  my_decimal decimal = {{0xCE8704FA, 0x6015ED64, 0xF1865754, 0x100000}};

  my_decimal decimal_check = {{0x5E8FE23F, 0x6CC, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok678) {
  my_decimal decimal = {{0xCE8704FA, 0x6015ED64, 0xF1865754, 0x80100000}};

  my_decimal decimal_check = {{0x5E8FE23F, 0x6CC, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok679) {
  my_decimal decimal = {{0xECE14FAD, 0xA39D149F, 0xD3400472, 0x90000}};

  my_decimal decimal_check = {{0xEE17196E, 0x8B4FE7EE, 0x3, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok680) {
  my_decimal decimal = {{0xECE14FAD, 0xA39D149F, 0xD3400472, 0x80090000}};

  my_decimal decimal_check = {{0xEE17196E, 0x8B4FE7EE, 0x3, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok681) {
  my_decimal decimal = {{0x5707DE78, 0x35F2F9D9, 0x4B430740, 0x80010000}};

  my_decimal decimal_check = {{0xEF1A630C, 0xD231E5C8, 0x786B3EC, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok682) {
  my_decimal decimal = {{0x5707DE78, 0x35F2F9D9, 0x4B430740, 0x10000}};

  my_decimal decimal_check = {{0xEF1A630C, 0xD231E5C8, 0x786B3EC, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok683) {
  my_decimal decimal = {{0x64DF2F46, 0x95D78A48, 0xC5793F7, 0x80030000}};

  my_decimal decimal_check = {{0x4FF90E21, 0x1A84914A, 0x328DA, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok684) {
  my_decimal decimal = {{0x64DF2F46, 0x95D78A48, 0xC5793F7, 0x30000}};

  my_decimal decimal_check = {{0x4FF90E21, 0x1A84914A, 0x328DA, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok685) {
  my_decimal decimal = {{0x6071A833, 0x878DDF0E, 0xC1094C54, 0x170000}};

  my_decimal decimal_check = {{0x91DAA, 0x0, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok686) {
  my_decimal decimal = {{0x6071A833, 0x878DDF0E, 0xC1094C54, 0x80170000}};

  my_decimal decimal_check = {{0x91DAA, 0x0, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok687) {
  my_decimal decimal = {{0x6E5FA1D, 0x58777A73, 0xF56F2BB6, 0x80170000}};

  my_decimal decimal_check = {{0xB971E, 0x0, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok688) {
  my_decimal decimal = {{0x6E5FA1D, 0x58777A73, 0xF56F2BB6, 0x170000}};

  my_decimal decimal_check = {{0xB971E, 0x0, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok689) {
  my_decimal decimal = {{0xCBF9DBB3, 0xDBE3D9, 0xE5DAF062, 0x40000}};

  my_decimal decimal_check = {{0x3B3BB2D7, 0x15C294FD, 0x5E261, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok690) {
  my_decimal decimal = {{0xCBF9DBB3, 0xDBE3D9, 0xE5DAF062, 0x80040000}};

  my_decimal decimal_check = {{0x3B3BB2D7, 0x15C294FD, 0x5E261, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok691) {
  my_decimal decimal = {{0x34B070D1, 0x8AAA8097, 0x40E7365D, 0x80180000}};

  my_decimal decimal_check = {{0x4E77, 0x0, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok692) {
  my_decimal decimal = {{0x34B070D1, 0x8AAA8097, 0x40E7365D, 0x180000}};

  my_decimal decimal_check = {{0x4E77, 0x0, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok693) {
  my_decimal decimal = {{0xC3BFD7B, 0xC888E0A5, 0xF3749B45, 0x800E0000}};

  my_decimal decimal_check = {{0x2BF63130, 0x2AD44, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok694) {
  my_decimal decimal = {{0xC3BFD7B, 0xC888E0A5, 0xF3749B45, 0xE0000}};

  my_decimal decimal_check = {{0x2BF63130, 0x2AD44, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok695) {
  my_decimal decimal = {{0xDA1D9387, 0x1D4DFB2B, 0xCBD00457, 0x10000}};

  my_decimal decimal_check = {{0xC902F527, 0xB62165EA, 0x14619A08, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok696) {
  my_decimal decimal = {{0xDA1D9387, 0x1D4DFB2B, 0xCBD00457, 0x80010000}};

  my_decimal decimal_check = {
      {0xC902F527, 0xB62165EA, 0x14619A08, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok697) {
  my_decimal decimal = {{0x1B999A9E, 0x98B1A333, 0x5D824A47, 0x80000}};

  my_decimal decimal_check = {{0xA55D24CE, 0xB02DBBBE, 0xF, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok698) {
  my_decimal decimal = {{0x1B999A9E, 0x98B1A333, 0x5D824A47, 0x80080000}};

  my_decimal decimal_check = {{0xA55D24CE, 0xB02DBBBE, 0xF, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok699) {
  my_decimal decimal = {{0x5066B77F, 0x1A4A2F43, 0x2F87C0A4, 0x801B0000}};

  my_decimal decimal_check = {{0xF, 0x0, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok700) {
  my_decimal decimal = {{0x5066B77F, 0x1A4A2F43, 0x2F87C0A4, 0x1B0000}};

  my_decimal decimal_check = {{0xF, 0x0, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok701) {
  my_decimal decimal = {{0xB4AF8F6F, 0x75C34BE4, 0x8DF1AB58, 0x30000}};

  my_decimal decimal_check = {{0x9658D33, 0x7F1800D8, 0x245671, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok702) {
  my_decimal decimal = {{0xB4AF8F6F, 0x75C34BE4, 0x8DF1AB58, 0x80030000}};

  my_decimal decimal_check = {{0x9658D33, 0x7F1800D8, 0x245671, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok703) {
  my_decimal decimal = {{0x944B6960, 0xDDF6F8A0, 0x3D7C3274, 0x800A0000}};

  my_decimal decimal_check = {{0x184008B6, 0x1A685CF9, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok704) {
  my_decimal decimal = {{0x944B6960, 0xDDF6F8A0, 0x3D7C3274, 0xA0000}};

  my_decimal decimal_check = {{0x184008B6, 0x1A685CF9, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok705) {
  my_decimal decimal = {{0x27BA856F, 0x8B8162C4, 0x4680CA92, 0x30000}};

  my_decimal decimal_check = {{0xE87CDBC8, 0x9627CF33, 0x120C7D, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok706) {
  my_decimal decimal = {{0x27BA856F, 0x8B8162C4, 0x4680CA92, 0x80030000}};

  my_decimal decimal_check = {{0xE87CDBC8, 0x9627CF33, 0x120C7D, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok707) {
  my_decimal decimal = {{0x8AD5E7FE, 0xA565BE03, 0x83955803, 0x80120000}};

  my_decimal decimal_check = {{0x7B48EA8D, 0x9, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok708) {
  my_decimal decimal = {{0x8AD5E7FE, 0xA565BE03, 0x83955803, 0x120000}};

  my_decimal decimal_check = {{0x7B48EA8D, 0x9, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok709) {
  my_decimal decimal = {{0xA21F873C, 0x8E63620C, 0xDD29A9D8, 0x800E0000}};

  my_decimal decimal_check = {{0x8E1718FB, 0x26E84, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok710) {
  my_decimal decimal = {{0xA21F873C, 0x8E63620C, 0xDD29A9D8, 0xE0000}};

  my_decimal decimal_check = {{0x8E1718FB, 0x26E84, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok711) {
  my_decimal decimal = {{0x5F76B2C5, 0xB2588993, 0xA36DAAF9, 0x800A0000}};

  my_decimal decimal_check = {{0x1858CAA, 0x4631243B, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok712) {
  my_decimal decimal = {{0x5F76B2C5, 0xB2588993, 0xA36DAAF9, 0xA0000}};

  my_decimal decimal_check = {{0x1858CAA, 0x4631243B, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok713) {
  my_decimal decimal = {{0x78D19E78, 0x2CA8FB31, 0x7AF41B7C, 0x10000}};

  my_decimal decimal_check = {{0xF27B5CA6, 0x37AA7F84, 0xC4B9C59, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok714) {
  my_decimal decimal = {{0x78D19E78, 0x2CA8FB31, 0x7AF41B7C, 0x80010000}};

  my_decimal decimal_check = {{0xF27B5CA6, 0x37AA7F84, 0xC4B9C59, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok715) {
  my_decimal decimal = {{0xB808F3ED, 0xB3E3CAED, 0x8FC5C492, 0x80050000}};

  my_decimal decimal_check = {{0x2303D471, 0x72CC77C, 0x5E39, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok716) {
  my_decimal decimal = {{0xB808F3ED, 0xB3E3CAED, 0x8FC5C492, 0x50000}};

  my_decimal decimal_check = {{0x2303D471, 0x72CC77C, 0x5E39, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok717) {
  my_decimal decimal = {{0x9E67E6F6, 0x7D178206, 0xD3523E82, 0x800B0000}};

  my_decimal decimal_check = {{0x33DC90CF, 0x913807C, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok718) {
  my_decimal decimal = {{0x9E67E6F6, 0x7D178206, 0xD3523E82, 0xB0000}};

  my_decimal decimal_check = {{0x33DC90CF, 0x913807C, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok719) {
  my_decimal decimal = {{0xC9CC9900, 0xA1F6983A, 0x92BBC355, 0x800D0000}};

  my_decimal decimal_check = {{0xEEA98118, 0x10222D, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok720) {
  my_decimal decimal = {{0xC9CC9900, 0xA1F6983A, 0x92BBC355, 0xD0000}};

  my_decimal decimal_check = {{0xEEA98118, 0x10222D, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok721) {
  my_decimal decimal = {{0x482071F2, 0x8D6510BE, 0x9C6C0C78, 0x801A0000}};

  my_decimal decimal_check = {{0x1E4, 0x0, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok722) {
  my_decimal decimal = {{0x482071F2, 0x8D6510BE, 0x9C6C0C78, 0x1A0000}};

  my_decimal decimal_check = {{0x1E4, 0x0, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok723) {
  my_decimal decimal = {{0x83E0F45A, 0xDFCA9883, 0x83B1F0A7, 0x80010000}};

  my_decimal decimal_check = {{0x59FCE53C, 0x96610F40, 0xD2B64DD, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok724) {
  my_decimal decimal = {{0x83E0F45A, 0xDFCA9883, 0x83B1F0A7, 0x10000}};

  my_decimal decimal_check = {{0x59FCE53C, 0x96610F40, 0xD2B64DD, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok725) {
  my_decimal decimal = {{0xC2300EF1, 0x9124EC67, 0x993610F, 0x30000}};

  my_decimal decimal_check = {{0xB4298523, 0x9564A519, 0x2738D, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok726) {
  my_decimal decimal = {{0xC2300EF1, 0x9124EC67, 0x993610F, 0x80030000}};

  my_decimal decimal_check = {{0xB4298523, 0x9564A519, 0x2738D, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok727) {
  my_decimal decimal = {{0xFA34492B, 0x83317203, 0x73744319, 0x800F0000}};

  my_decimal decimal_check = {{0x5922E1EA, 0x207F, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok728) {
  my_decimal decimal = {{0xFA34492B, 0x83317203, 0x73744319, 0xF0000}};

  my_decimal decimal_check = {{0x5922E1EA, 0x207F, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok729) {
  my_decimal decimal = {{0x8F6964AC, 0x3ACDFE4F, 0x9046872D, 0x80150000}};

  my_decimal decimal_check = {{0x2A95261, 0x0, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok730) {
  my_decimal decimal = {{0x8F6964AC, 0x3ACDFE4F, 0x9046872D, 0x150000}};

  my_decimal decimal_check = {{0x2A95261, 0x0, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok731) {
  my_decimal decimal = {{0x1016A0E5, 0xCF47DB8A, 0x182E1E1C, 0x40000}};

  my_decimal decimal_check = {{0x1E288D7B, 0x8E0CADDF, 0x9E77, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok732) {
  my_decimal decimal = {{0x1016A0E5, 0xCF47DB8A, 0x182E1E1C, 0x80040000}};

  my_decimal decimal_check = {{0x1E288D7B, 0x8E0CADDF, 0x9E77, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok733) {
  my_decimal decimal = {{0xB8CF61F3, 0xA4D11E22, 0xC7C50C60, 0x40000}};

  my_decimal decimal_check = {{0x9E66BB6, 0xF9767F6A, 0x51D35, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok734) {
  my_decimal decimal = {{0xB8CF61F3, 0xA4D11E22, 0xC7C50C60, 0x80040000}};

  my_decimal decimal_check = {{0x9E66BB6, 0xF9767F6A, 0x51D35, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok735) {
  my_decimal decimal = {{0x9F274341, 0xC4A83315, 0x7CB84C62, 0x80150000}};

  my_decimal decimal_check = {{0x24CF920, 0x0, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok736) {
  my_decimal decimal = {{0x9F274341, 0xC4A83315, 0x7CB84C62, 0x150000}};

  my_decimal decimal_check = {{0x24CF920, 0x0, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok737) {
  my_decimal decimal = {{0x98BB6278, 0xAEE4A4FD, 0xDE5D6430, 0x80140000}};

  my_decimal decimal_check = {{0x2904E19A, 0x0, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok738) {
  my_decimal decimal = {{0x98BB6278, 0xAEE4A4FD, 0xDE5D6430, 0x140000}};

  my_decimal decimal_check = {{0x2904E19A, 0x0, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok739) {
  my_decimal decimal = {{0xD30040DC, 0x54D17A36, 0x496A4031, 0x80100000}};

  my_decimal decimal_check = {{0x2D95E89, 0x211, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok740) {
  my_decimal decimal = {{0xD30040DC, 0x54D17A36, 0x496A4031, 0x100000}};

  my_decimal decimal_check = {{0x2D95E89, 0x211, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok741) {
  my_decimal decimal = {{0x660ACE4C, 0x14C03EE0, 0x162BCF7B, 0xA0000}};

  my_decimal decimal_check = {{0x9728FB2, 0x985BDF6, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok742) {
  my_decimal decimal = {{0x660ACE4C, 0x14C03EE0, 0x162BCF7B, 0x800A0000}};

  my_decimal decimal_check = {{0x9728FB2, 0x985BDF6, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok743) {
  my_decimal decimal = {{0x67642D9F, 0xBDC26F1F, 0x21A2EAC7, 0x1A0000}};

  my_decimal decimal_check = {{0x68, 0x0, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok744) {
  my_decimal decimal = {{0x67642D9F, 0xBDC26F1F, 0x21A2EAC7, 0x801A0000}};

  my_decimal decimal_check = {{0x68, 0x0, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok745) {
  my_decimal decimal = {{0xB6B702AE, 0xD0FB38A6, 0xA9AB47C3, 0x80160000}};

  my_decimal decimal_check = {{0x501FBB, 0x0, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok746) {
  my_decimal decimal = {{0xB6B702AE, 0xD0FB38A6, 0xA9AB47C3, 0x160000}};

  my_decimal decimal_check = {{0x501FBB, 0x0, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok747) {
  my_decimal decimal = {{0xCEC3D4CE, 0x3B195526, 0x8855EB78, 0x80070000}};

  my_decimal decimal_check = {{0xDF54CFE9, 0xBBB4698B, 0xE4, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok748) {
  my_decimal decimal = {{0xCEC3D4CE, 0x3B195526, 0x8855EB78, 0x70000}};

  my_decimal decimal_check = {{0xDF54CFE9, 0xBBB4698B, 0xE4, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok749) {
  my_decimal decimal = {{0x224AB663, 0x289551F5, 0xFF45652, 0x60000}};

  my_decimal decimal_check = {{0x8027223F, 0xABCEA96A, 0x10B, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok750) {
  my_decimal decimal = {{0x224AB663, 0x289551F5, 0xFF45652, 0x80060000}};

  my_decimal decimal_check = {{0x8027223F, 0xABCEA96A, 0x10B, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok751) {
  my_decimal decimal = {{0xC5194FE4, 0x75F38AAF, 0x413420DC, 0x80110000}};

  my_decimal decimal_check = {{0xFBF23323, 0x2E, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok752) {
  my_decimal decimal = {{0xC5194FE4, 0x75F38AAF, 0x413420DC, 0x110000}};

  my_decimal decimal_check = {{0xFBF23323, 0x2E, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok753) {
  my_decimal decimal = {{0xD18063C6, 0x96A720D, 0xA36F7A7D, 0x80140000}};

  my_decimal decimal_check = {{0x1E260582, 0x0, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok754) {
  my_decimal decimal = {{0xD18063C6, 0x96A720D, 0xA36F7A7D, 0x140000}};

  my_decimal decimal_check = {{0x1E260582, 0x0, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok755) {
  my_decimal decimal = {{0x61E7D194, 0xA162A112, 0x997E4C83, 0x80010000}};

  my_decimal decimal_check = {{0x7030C828, 0x29BD101B, 0xF596E0D, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok756) {
  my_decimal decimal = {{0x61E7D194, 0xA162A112, 0x997E4C83, 0x10000}};

  my_decimal decimal_check = {{0x7030C828, 0x29BD101B, 0xF596E0D, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok757) {
  my_decimal decimal = {{0xAE7781DF, 0xF73F8138, 0x7BBF2766, 0x1A0000}};

  my_decimal decimal_check = {{0x17F, 0x0, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok758) {
  my_decimal decimal = {{0xAE7781DF, 0xF73F8138, 0x7BBF2766, 0x801A0000}};

  my_decimal decimal_check = {{0x17F, 0x0, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok759) {
  my_decimal decimal = {{0x662FCFD0, 0xE14A1696, 0x769A1466, 0x80160000}};

  my_decimal decimal_check = {{0x380216, 0x0, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok760) {
  my_decimal decimal = {{0x662FCFD0, 0xE14A1696, 0x769A1466, 0x160000}};

  my_decimal decimal_check = {{0x380216, 0x0, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok761) {
  my_decimal decimal = {{0x3041F71C, 0xBC8E976C, 0xC12EEACC, 0x80150000}};

  my_decimal decimal_check = {{0x390483E, 0x0, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok762) {
  my_decimal decimal = {{0x3041F71C, 0xBC8E976C, 0xC12EEACC, 0x150000}};

  my_decimal decimal_check = {{0x390483E, 0x0, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok763) {
  my_decimal decimal = {{0xD810AF13, 0xEDB9B1B1, 0xAB8CA1B7, 0x800D0000}};

  my_decimal decimal_check = {{0x49F27F44, 0x12DCAF, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok764) {
  my_decimal decimal = {{0xD810AF13, 0xEDB9B1B1, 0xAB8CA1B7, 0xD0000}};

  my_decimal decimal_check = {{0x49F27F44, 0x12DCAF, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok765) {
  my_decimal decimal = {{0xD3A27D46, 0x5584CDC8, 0x29EE7327, 0x80030000}};

  my_decimal decimal_check = {{0x14B10EF9, 0xE740E69B, 0xABC04, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok766) {
  my_decimal decimal = {{0xD3A27D46, 0x5584CDC8, 0x29EE7327, 0x30000}};

  my_decimal decimal_check = {{0x14B10EF9, 0xE740E69B, 0xABC04, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok767) {
  my_decimal decimal = {{0x1F0E7A5, 0x6A5A69FA, 0x4E153D93, 0xC0000}};

  my_decimal decimal_check = {{0x3485FEB, 0x55DA67, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok768) {
  my_decimal decimal = {{0x1F0E7A5, 0x6A5A69FA, 0x4E153D93, 0x800C0000}};

  my_decimal decimal_check = {{0x3485FEB, 0x55DA67, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok769) {
  my_decimal decimal = {{0x809FE1C5, 0x28A3F39F, 0xCF8B2B43, 0x80110000}};

  my_decimal decimal_check = {{0x8D0AC482, 0x95, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok770) {
  my_decimal decimal = {{0x809FE1C5, 0x28A3F39F, 0xCF8B2B43, 0x110000}};

  my_decimal decimal_check = {{0x8D0AC482, 0x95, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok771) {
  my_decimal decimal = {{0xC766B863, 0xC6534699, 0x13762AE1, 0x80030000}};

  my_decimal decimal_check = {{0xB6BA36F8, 0x546C1D82, 0x4FB6F, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok772) {
  my_decimal decimal = {{0xC766B863, 0xC6534699, 0x13762AE1, 0x30000}};

  my_decimal decimal_check = {{0xB6BA36F8, 0x546C1D82, 0x4FB6F, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok773) {
  my_decimal decimal = {{0xE490AFE4, 0x7F135D4C, 0x5AAEA054, 0x170000}};

  my_decimal decimal_check = {{0x44848, 0x0, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok774) {
  my_decimal decimal = {{0xE490AFE4, 0x7F135D4C, 0x5AAEA054, 0x80170000}};

  my_decimal decimal_check = {{0x44848, 0x0, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok775) {
  my_decimal decimal = {{0x7C6DF181, 0x7CFF8974, 0x8CD04E1B, 0x100000}};

  my_decimal decimal_check = {{0xAB69DC20, 0x3F6, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok776) {
  my_decimal decimal = {{0x7C6DF181, 0x7CFF8974, 0x8CD04E1B, 0x80100000}};

  my_decimal decimal_check = {{0xAB69DC20, 0x3F6, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok777) {
  my_decimal decimal = {{0x6F0F0150, 0xF4E7637E, 0x18F5669D, 0x801B0000}};

  my_decimal decimal_check = {{0x8, 0x0, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok778) {
  my_decimal decimal = {{0x6F0F0150, 0xF4E7637E, 0x18F5669D, 0x1B0000}};

  my_decimal decimal_check = {{0x8, 0x0, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok779) {
  my_decimal decimal = {{0x71D863A4, 0x83081641, 0x9F9EB44B, 0x170000}};

  my_decimal decimal_check = {{0x789B0, 0x0, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok780) {
  my_decimal decimal = {{0x71D863A4, 0x83081641, 0x9F9EB44B, 0x80170000}};

  my_decimal decimal_check = {{0x789B0, 0x0, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok781) {
  my_decimal decimal = {{0x2AF19417, 0x45CD6D2B, 0xE1D4AE6B, 0x110000}};

  my_decimal decimal_check = {{0xBA6D5DB6, 0xA2, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok782) {
  my_decimal decimal = {{0x2AF19417, 0x45CD6D2B, 0xE1D4AE6B, 0x80110000}};

  my_decimal decimal_check = {{0xBA6D5DB6, 0xA2, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok783) {
  my_decimal decimal = {{0x3487F1AC, 0xEF135D9D, 0x92CE8A55, 0x80170000}};

  my_decimal decimal_check = {{0x6EEC9, 0x0, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok784) {
  my_decimal decimal = {{0x3487F1AC, 0xEF135D9D, 0x92CE8A55, 0x170000}};

  my_decimal decimal_check = {{0x6EEC9, 0x0, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok785) {
  my_decimal decimal = {{0x663E0766, 0x9BA7E3C9, 0xF4DE07C2, 0x1C0000}};

  my_decimal decimal_check = {{0x8, 0x0, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok786) {
  my_decimal decimal = {{0x663E0766, 0x9BA7E3C9, 0xF4DE07C2, 0x801C0000}};

  my_decimal decimal_check = {{0x8, 0x0, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok787) {
  my_decimal decimal = {{0xDED2AF13, 0x18A058D4, 0xBDCDC1F3, 0x801C0000}};

  my_decimal decimal_check = {{0x6, 0x0, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok788) {
  my_decimal decimal = {{0xDED2AF13, 0x18A058D4, 0xBDCDC1F3, 0x1C0000}};

  my_decimal decimal_check = {{0x6, 0x0, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok789) {
  my_decimal decimal = {{0x662C304C, 0xABDA8930, 0x43C2E23A, 0x40000}};

  my_decimal decimal_check = {{0x8ADD578F, 0x897D3B40, 0x1BC14, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok790) {
  my_decimal decimal = {{0x662C304C, 0xABDA8930, 0x43C2E23A, 0x80040000}};

  my_decimal decimal_check = {{0x8ADD578F, 0x897D3B40, 0x1BC14, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok791) {
  my_decimal decimal = {{0x501ED51F, 0xC4084E21, 0x6B5BA353, 0x30000}};

  my_decimal decimal_check = {{0x87810E0A, 0xB323D92A, 0x1B7BCF, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok792) {
  my_decimal decimal = {{0x501ED51F, 0xC4084E21, 0x6B5BA353, 0x80030000}};

  my_decimal decimal_check = {{0x87810E0A, 0xB323D92A, 0x1B7BCF, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok793) {
  my_decimal decimal = {{0x85C8436E, 0xE8EDD35A, 0xB5837518, 0x30000}};

  my_decimal decimal_check = {{0x7F9F2D20, 0x49F5FF71, 0x2E77AB, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok794) {
  my_decimal decimal = {{0x85C8436E, 0xE8EDD35A, 0xB5837518, 0x80030000}};

  my_decimal decimal_check = {{0x7F9F2D20, 0x49F5FF71, 0x2E77AB, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok795) {
  my_decimal decimal = {{0xE78C71E, 0x358A851B, 0xE866677C, 0x80160000}};

  my_decimal decimal_check = {{0x6DBF70, 0x0, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok796) {
  my_decimal decimal = {{0xE78C71E, 0x358A851B, 0xE866677C, 0x160000}};

  my_decimal decimal_check = {{0x6DBF70, 0x0, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok797) {
  my_decimal decimal = {{0x46190315, 0xEBC4792F, 0xBD2FAEFD, 0x80150000}};

  my_decimal decimal_check = {{0x37D6829, 0x0, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok798) {
  my_decimal decimal = {{0x46190315, 0xEBC4792F, 0xBD2FAEFD, 0x150000}};

  my_decimal decimal_check = {{0x37D6829, 0x0, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok799) {
  my_decimal decimal = {{0x91925BEF, 0xF7132715, 0x4AF3F772, 0x80070000}};

  my_decimal decimal_check = {{0x1777393A, 0xC010E6C9, 0x7D, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok800) {
  my_decimal decimal = {{0x91925BEF, 0xF7132715, 0x4AF3F772, 0x70000}};

  my_decimal decimal_check = {{0x1777393A, 0xC010E6C9, 0x7D, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok801) {
  my_decimal decimal = {{0x995896B9, 0x1691886E, 0xEB6DD3B1, 0x150000}};

  my_decimal decimal_check = {{0x457C836, 0x0, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok802) {
  my_decimal decimal = {{0x995896B9, 0x1691886E, 0xEB6DD3B1, 0x80150000}};

  my_decimal decimal_check = {{0x457C836, 0x0, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok803) {
  my_decimal decimal = {{0x35354573, 0x4F4471EA, 0xDC55783C, 0x80110000}};

  my_decimal decimal_check = {{0xC46CA237, 0x9E, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok804) {
  my_decimal decimal = {{0x35354573, 0x4F4471EA, 0xDC55783C, 0x110000}};

  my_decimal decimal_check = {{0xC46CA237, 0x9E, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok805) {
  my_decimal decimal = {{0x42D654D, 0xBF06B619, 0x2C860FAE, 0x20000}};

  my_decimal decimal_check = {{0x35CD4103, 0x6D6E25A9, 0x71FB09, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok806) {
  my_decimal decimal = {{0x42D654D, 0xBF06B619, 0x2C860FAE, 0x80020000}};

  my_decimal decimal_check = {{0x35CD4103, 0x6D6E25A9, 0x71FB09, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok807) {
  my_decimal decimal = {{0xFC58F7C8, 0x36A16284, 0xDCF6478, 0xF0000}};

  my_decimal decimal_check = {{0x1FDFE5A4, 0x3E3, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok808) {
  my_decimal decimal = {{0xFC58F7C8, 0x36A16284, 0xDCF6478, 0x800F0000}};

  my_decimal decimal_check = {{0x1FDFE5A4, 0x3E3, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok809) {
  my_decimal decimal = {{0x97858D99, 0x8B31BA99, 0xC247E0, 0x20000}};

  my_decimal decimal_check = {{0x3746749E, 0xD86E93C9, 0x1F15B, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok810) {
  my_decimal decimal = {{0x97858D99, 0x8B31BA99, 0xC247E0, 0x80020000}};

  my_decimal decimal_check = {{0x3746749E, 0xD86E93C9, 0x1F15B, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok811) {
  my_decimal decimal = {{0xE6A3AC46, 0x85C5062E, 0xBFCBD84A, 0x80020000}};

  my_decimal decimal_check = {{0xAB44325D, 0x5860B0B3, 0x1EAFF9A, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok812) {
  my_decimal decimal = {{0xE6A3AC46, 0x85C5062E, 0xBFCBD84A, 0x20000}};

  my_decimal decimal_check = {{0xAB44325D, 0x5860B0B3, 0x1EAFF9A, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok813) {
  my_decimal decimal = {{0x7055400E, 0xF7463C3D, 0x619A609E, 0x801A0000}};

  my_decimal decimal_check = {{0x12E, 0x0, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok814) {
  my_decimal decimal = {{0x7055400E, 0xF7463C3D, 0x619A609E, 0x1A0000}};

  my_decimal decimal_check = {{0x12E, 0x0, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok815) {
  my_decimal decimal = {{0x18846D98, 0x2C3476BA, 0x4283DC17, 0x120000}};

  my_decimal decimal_check = {{0xCAFC920F, 0x4, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok816) {
  my_decimal decimal = {{0x18846D98, 0x2C3476BA, 0x4283DC17, 0x80120000}};

  my_decimal decimal_check = {{0xCAFC920F, 0x4, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok817) {
  my_decimal decimal = {{0x1DFA557F, 0x3E458FF3, 0x39CC4290, 0x80030000}};

  my_decimal decimal_check = {{0x3E3CEC1E, 0xB23CFF60, 0xECBD7, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok818) {
  my_decimal decimal = {{0x1DFA557F, 0x3E458FF3, 0x39CC4290, 0x30000}};

  my_decimal decimal_check = {{0x3E3CEC1E, 0xB23CFF60, 0xECBD7, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok819) {
  my_decimal decimal = {{0x95AE3E31, 0x8A95959A, 0x9B9535E1, 0x1C0000}};

  my_decimal decimal_check = {{0x5, 0x0, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok820) {
  my_decimal decimal = {{0x95AE3E31, 0x8A95959A, 0x9B9535E1, 0x801C0000}};

  my_decimal decimal_check = {{0x5, 0x0, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok821) {
  my_decimal decimal = {{0xC9AC1EDF, 0x6F14CC9C, 0x7303A65C, 0x1B0000}};

  my_decimal decimal_check = {{0x24, 0x0, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok822) {
  my_decimal decimal = {{0xC9AC1EDF, 0x6F14CC9C, 0x7303A65C, 0x801B0000}};

  my_decimal decimal_check = {{0x24, 0x0, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok823) {
  my_decimal decimal = {{0xC618392E, 0x12688D08, 0x8B665B3F, 0x80000000}};

  my_decimal decimal_check = {
      {0xC618392E, 0x12688D08, 0x8B665B3F, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok824) {
  my_decimal decimal = {{0xC618392E, 0x12688D08, 0x8B665B3F, 0x0}};

  my_decimal decimal_check = {{0xC618392E, 0x12688D08, 0x8B665B3F, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok825) {
  my_decimal decimal = {{0xAB08D878, 0x56466907, 0x643B4522, 0x80170000}};

  my_decimal decimal_check = {{0x4BBBA, 0x0, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok826) {
  my_decimal decimal = {{0xAB08D878, 0x56466907, 0x643B4522, 0x170000}};

  my_decimal decimal_check = {{0x4BBBA, 0x0, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok827) {
  my_decimal decimal = {{0xA364A2F6, 0xFF59D920, 0x99012D83, 0x170000}};

  my_decimal decimal_check = {{0x739B6, 0x0, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok828) {
  my_decimal decimal = {{0xA364A2F6, 0xFF59D920, 0x99012D83, 0x80170000}};

  my_decimal decimal_check = {{0x739B6, 0x0, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok829) {
  my_decimal decimal = {{0x13D973E5, 0xBABA5166, 0xDA98552C, 0x170000}};

  my_decimal decimal_check = {{0xA52A7, 0x0, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok830) {
  my_decimal decimal = {{0x13D973E5, 0xBABA5166, 0xDA98552C, 0x80170000}};

  my_decimal decimal_check = {{0xA52A7, 0x0, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok831) {
  my_decimal decimal = {{0x9ABDD50D, 0xE9474258, 0xB811C266, 0x801C0000}};

  my_decimal decimal_check = {{0x6, 0x0, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok832) {
  my_decimal decimal = {{0x9ABDD50D, 0xE9474258, 0xB811C266, 0x1C0000}};

  my_decimal decimal_check = {{0x6, 0x0, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok833) {
  my_decimal decimal = {{0x29969DC4, 0xCD6D0676, 0x222B0C77, 0x110000}};

  my_decimal decimal_check = {{0x9EE9B031, 0x18, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok834) {
  my_decimal decimal = {{0x29969DC4, 0xCD6D0676, 0x222B0C77, 0x80110000}};

  my_decimal decimal_check = {{0x9EE9B031, 0x18, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok835) {
  my_decimal decimal = {{0xB9E8E3B4, 0xC44217C8, 0x3B628F47, 0x800C0000}};

  my_decimal decimal_check = {{0x2264FDD4, 0x414B64, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok836) {
  my_decimal decimal = {{0xB9E8E3B4, 0xC44217C8, 0x3B628F47, 0xC0000}};

  my_decimal decimal_check = {{0x2264FDD4, 0x414B64, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok837) {
  my_decimal decimal = {{0xACB04879, 0xDA3E765B, 0xC1586F6, 0x80160000}};

  my_decimal decimal_check = {{0x5B4E0, 0x0, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok838) {
  my_decimal decimal = {{0xACB04879, 0xDA3E765B, 0xC1586F6, 0x160000}};

  my_decimal decimal_check = {{0x5B4E0, 0x0, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok839) {
  my_decimal decimal = {{0xCFD52394, 0x6059C746, 0xD4C2D09F, 0x60000}};

  my_decimal decimal_check = {{0x76AFFC0F, 0x8984D989, 0xDF1, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok840) {
  my_decimal decimal = {{0xCFD52394, 0x6059C746, 0xD4C2D09F, 0x80060000}};

  my_decimal decimal_check = {{0x76AFFC0F, 0x8984D989, 0xDF1, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok841) {
  my_decimal decimal = {{0x28F3A4BF, 0x5222C00C, 0xB22CE4EF, 0x80020000}};

  my_decimal decimal_check = {{0x710CAD2B, 0x64A94EB8, 0x1C82102, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok842) {
  my_decimal decimal = {{0x28F3A4BF, 0x5222C00C, 0xB22CE4EF, 0x20000}};

  my_decimal decimal_check = {{0x710CAD2B, 0x64A94EB8, 0x1C82102, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok843) {
  my_decimal decimal = {{0x850CF55A, 0x3C233AC0, 0x35DBEDC4, 0x800C0000}};

  my_decimal decimal_check = {{0xEE553CEF, 0x3B37FC, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok844) {
  my_decimal decimal = {{0x850CF55A, 0x3C233AC0, 0x35DBEDC4, 0xC0000}};

  my_decimal decimal_check = {{0xEE553CEF, 0x3B37FC, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok845) {
  my_decimal decimal = {{0x62582630, 0x1638B206, 0x9FDB604D, 0x80190000}};

  my_decimal decimal_check = {{0x1353, 0x0, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok846) {
  my_decimal decimal = {{0x62582630, 0x1638B206, 0x9FDB604D, 0x190000}};

  my_decimal decimal_check = {{0x1353, 0x0, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok847) {
  my_decimal decimal = {{0x6D11042F, 0x5DA62CAB, 0x15ED83F9, 0x80100000}};

  my_decimal decimal_check = {{0x1A46C0D, 0x9E, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok848) {
  my_decimal decimal = {{0x6D11042F, 0x5DA62CAB, 0x15ED83F9, 0x100000}};

  my_decimal decimal_check = {{0x1A46C0D, 0x9E, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok849) {
  my_decimal decimal = {{0x6416CDF7, 0x9B0AB7C9, 0x9002FAC3, 0x80110000}};

  my_decimal decimal_check = {{0xC5755D62, 0x67, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok850) {
  my_decimal decimal = {{0x6416CDF7, 0x9B0AB7C9, 0x9002FAC3, 0x110000}};

  my_decimal decimal_check = {{0xC5755D62, 0x67, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok851) {
  my_decimal decimal = {{0xAD514452, 0xCD52F369, 0xDFB6445F, 0x160000}};

  my_decimal decimal_check = {{0x69A51E, 0x0, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok852) {
  my_decimal decimal = {{0xAD514452, 0xCD52F369, 0xDFB6445F, 0x80160000}};

  my_decimal decimal_check = {{0x69A51E, 0x0, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok853) {
  my_decimal decimal = {{0xE7F79D82, 0x574B4D23, 0xE3D7E060, 0x110000}};

  my_decimal decimal_check = {{0x2DAA1897, 0xA4, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok854) {
  my_decimal decimal = {{0xE7F79D82, 0x574B4D23, 0xE3D7E060, 0x80110000}};

  my_decimal decimal_check = {{0x2DAA1897, 0xA4, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok855) {
  my_decimal decimal = {{0xA05815EB, 0x11724DD9, 0xCDE5F479, 0x100000}};

  my_decimal decimal_check = {{0xA740F380, 0x5CB, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok856) {
  my_decimal decimal = {{0xA05815EB, 0x11724DD9, 0xCDE5F479, 0x80100000}};

  my_decimal decimal_check = {{0xA740F380, 0x5CB, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok857) {
  my_decimal decimal = {{0x930B4488, 0x8CABA226, 0x8F22EBF9, 0xC0000}};

  my_decimal decimal_check = {{0x8DBD66FD, 0x9D6151, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok858) {
  my_decimal decimal = {{0x930B4488, 0x8CABA226, 0x8F22EBF9, 0x800C0000}};

  my_decimal decimal_check = {{0x8DBD66FD, 0x9D6151, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok859) {
  my_decimal decimal = {{0xE42E212A, 0x5D3BDD5, 0xCD1380BB, 0x1C0000}};

  my_decimal decimal_check = {{0x6, 0x0, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok860) {
  my_decimal decimal = {{0xE42E212A, 0x5D3BDD5, 0xCD1380BB, 0x801C0000}};

  my_decimal decimal_check = {{0x6, 0x0, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok861) {
  my_decimal decimal = {{0x44A4DC74, 0xF38A9019, 0xC5E2C927, 0x80140000}};

  my_decimal decimal_check = {{0x2480E585, 0x0, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok862) {
  my_decimal decimal = {{0x44A4DC74, 0xF38A9019, 0xC5E2C927, 0x140000}};

  my_decimal decimal_check = {{0x2480E585, 0x0, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok863) {
  my_decimal decimal = {{0xE17A7B3C, 0x506EA27C, 0x1A067B52, 0x90000}};

  my_decimal decimal_check = {{0x5037E418, 0x6FC72420, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok864) {
  my_decimal decimal = {{0xE17A7B3C, 0x506EA27C, 0x1A067B52, 0x80090000}};

  my_decimal decimal_check = {{0x5037E418, 0x6FC72420, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok865) {
  my_decimal decimal = {{0x7164B623, 0x2BB0AA6F, 0x9D9F9935, 0x80000000}};

  my_decimal decimal_check = {
      {0x7164B623, 0x2BB0AA6F, 0x9D9F9935, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok866) {
  my_decimal decimal = {{0x7164B623, 0x2BB0AA6F, 0x9D9F9935, 0x0}};

  my_decimal decimal_check = {{0x7164B623, 0x2BB0AA6F, 0x9D9F9935, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok867) {
  my_decimal decimal = {{0x8D6A9044, 0xCC179DE7, 0x2AC2F637, 0x1A0000}};

  my_decimal decimal_check = {{0x84, 0x0, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok868) {
  my_decimal decimal = {{0x8D6A9044, 0xCC179DE7, 0x2AC2F637, 0x801A0000}};

  my_decimal decimal_check = {{0x84, 0x0, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok869) {
  my_decimal decimal = {{0x3F803F6E, 0xDB66243E, 0x446DEE92, 0x80020000}};

  my_decimal decimal_check = {{0x1A3C2998, 0xDE5A9F15, 0xAF2DE7, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok870) {
  my_decimal decimal = {{0x3F803F6E, 0xDB66243E, 0x446DEE92, 0x20000}};

  my_decimal decimal_check = {{0x1A3C2998, 0xDE5A9F15, 0xAF2DE7, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok871) {
  my_decimal decimal = {{0x55F1E21, 0x5CB5C129, 0xF86FEDF6, 0x801A0000}};

  my_decimal decimal_check = {{0x301, 0x0, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok872) {
  my_decimal decimal = {{0x55F1E21, 0x5CB5C129, 0xF86FEDF6, 0x1A0000}};

  my_decimal decimal_check = {{0x301, 0x0, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok873) {
  my_decimal decimal = {{0x1566814E, 0xEC5BB3AD, 0xA2102FC5, 0x80000000}};

  my_decimal decimal_check = {
      {0x1566814E, 0xEC5BB3AD, 0xA2102FC5, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok874) {
  my_decimal decimal = {{0x1566814E, 0xEC5BB3AD, 0xA2102FC5, 0x0}};

  my_decimal decimal_check = {{0x1566814E, 0xEC5BB3AD, 0xA2102FC5, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok875) {
  my_decimal decimal = {{0x8B970473, 0xDD526EF8, 0x665E42DF, 0x80110000}};

  my_decimal decimal_check = {{0xC399F0AA, 0x49, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok876) {
  my_decimal decimal = {{0x8B970473, 0xDD526EF8, 0x665E42DF, 0x110000}};

  my_decimal decimal_check = {{0xC399F0AA, 0x49, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok877) {
  my_decimal decimal = {{0x8B0AFAD0, 0x928F97BF, 0x3E2DDDC7, 0x80020000}};

  my_decimal decimal_check = {{0xD5DED46E, 0xE02F8413, 0x9F2DBC, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok878) {
  my_decimal decimal = {{0x8B0AFAD0, 0x928F97BF, 0x3E2DDDC7, 0x20000}};

  my_decimal decimal_check = {{0xD5DED46E, 0xE02F8413, 0x9F2DBC, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok879) {
  my_decimal decimal = {{0xB483EE03, 0x3C0612B1, 0x7F73CCF7, 0xB0000}};

  my_decimal decimal_check = {{0x4614368B, 0x5795A76, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok880) {
  my_decimal decimal = {{0xB483EE03, 0x3C0612B1, 0x7F73CCF7, 0x800B0000}};

  my_decimal decimal_check = {{0x4614368B, 0x5795A76, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok881) {
  my_decimal decimal = {{0xFA589592, 0x94CDC492, 0xD1E8FDFA, 0x70000}};

  my_decimal decimal_check = {{0x65C49FCE, 0x2BB65E18, 0x160, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok882) {
  my_decimal decimal = {{0xFA589592, 0x94CDC492, 0xD1E8FDFA, 0x80070000}};

  my_decimal decimal_check = {{0x65C49FCE, 0x2BB65E18, 0x160, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok883) {
  my_decimal decimal = {{0x40E67866, 0x991B88AF, 0x903CA3DE, 0x70000}};

  my_decimal decimal_check = {{0x1AD33964, 0xFD442BD3, 0xF1, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok884) {
  my_decimal decimal = {{0x40E67866, 0x991B88AF, 0x903CA3DE, 0x80070000}};

  my_decimal decimal_check = {{0x1AD33964, 0xFD442BD3, 0xF1, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok885) {
  my_decimal decimal = {{0x1EFC6FB1, 0x23823AA3, 0x73425D16, 0xF0000}};

  my_decimal decimal_check = {{0x4D923A03, 0x2071, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok886) {
  my_decimal decimal = {{0x1EFC6FB1, 0x23823AA3, 0x73425D16, 0x800F0000}};

  my_decimal decimal_check = {{0x4D923A03, 0x2071, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok887) {
  my_decimal decimal = {{0x7E799305, 0x9F51D884, 0x623BCC65, 0x160000}};

  my_decimal decimal_check = {{0x2E63B6, 0x0, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok888) {
  my_decimal decimal = {{0x7E799305, 0x9F51D884, 0x623BCC65, 0x80160000}};

  my_decimal decimal_check = {{0x2E63B6, 0x0, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok889) {
  my_decimal decimal = {{0xB82E65E4, 0x84FCF0D0, 0xF87137E3, 0x130000}};

  my_decimal decimal_check = {{0xCA4B8A2A, 0x1, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok890) {
  my_decimal decimal = {{0xB82E65E4, 0x84FCF0D0, 0xF87137E3, 0x80130000}};

  my_decimal decimal_check = {{0xCA4B8A2A, 0x1, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok891) {
  my_decimal decimal = {{0x6B723679, 0x39A11949, 0x2D9A9EDE, 0x130000}};

  my_decimal decimal_check = {{0x541FDFB1, 0x0, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok892) {
  my_decimal decimal = {{0x6B723679, 0x39A11949, 0x2D9A9EDE, 0x80130000}};

  my_decimal decimal_check = {{0x541FDFB1, 0x0, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok893) {
  my_decimal decimal = {{0x62662B50, 0x3F5C8913, 0x13E6F87C, 0xA0000}};

  my_decimal decimal_check = {{0x63802A13, 0x88C45F2, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok894) {
  my_decimal decimal = {{0x62662B50, 0x3F5C8913, 0x13E6F87C, 0x800A0000}};

  my_decimal decimal_check = {{0x63802A13, 0x88C45F2, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok895) {
  my_decimal decimal = {{0x5AFD83E1, 0x70FC41FD, 0x11444AD6, 0x120000}};

  my_decimal decimal_check = {{0x3E84005E, 0x1, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok896) {
  my_decimal decimal = {{0x5AFD83E1, 0x70FC41FD, 0x11444AD6, 0x80120000}};

  my_decimal decimal_check = {{0x3E84005E, 0x1, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok897) {
  my_decimal decimal = {{0x29061B09, 0xBCE4F38C, 0xAD909A27, 0x150000}};

  my_decimal decimal_check = {{0x333A308, 0x0, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok898) {
  my_decimal decimal = {{0x29061B09, 0xBCE4F38C, 0xAD909A27, 0x80150000}};

  my_decimal decimal_check = {{0x333A308, 0x0, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok899) {
  my_decimal decimal = {{0x37E086F1, 0x63C88279, 0x7A26E774, 0x80030000}};

  my_decimal decimal_check = {{0xB27CE583, 0xF8EE8958, 0x1F4559, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok900) {
  my_decimal decimal = {{0x37E086F1, 0x63C88279, 0x7A26E774, 0x30000}};

  my_decimal decimal_check = {{0xB27CE583, 0xF8EE8958, 0x1F4559, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok901) {
  my_decimal decimal = {{0x932D391, 0xDB1C8923, 0x4B9079DA, 0x80060000}};

  my_decimal decimal_check = {{0xD76D014F, 0xC273C288, 0x4F3, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok902) {
  my_decimal decimal = {{0x932D391, 0xDB1C8923, 0x4B9079DA, 0x60000}};

  my_decimal decimal_check = {{0xD76D014F, 0xC273C288, 0x4F3, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok903) {
  my_decimal decimal = {{0x1723D5A3, 0x6D9645F3, 0x59F104A0, 0x30000}};

  my_decimal decimal_check = {{0xB71029F1, 0x959D1409, 0x170667, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok904) {
  my_decimal decimal = {{0x1723D5A3, 0x6D9645F3, 0x59F104A0, 0x80030000}};

  my_decimal decimal_check = {{0xB71029F1, 0x959D1409, 0x170667, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok905) {
  my_decimal decimal = {{0xED678F1C, 0x363EC27C, 0x6BBFD5D8, 0x80120000}};

  my_decimal decimal_check = {{0xC39FF36F, 0x7, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok906) {
  my_decimal decimal = {{0xED678F1C, 0x363EC27C, 0x6BBFD5D8, 0x120000}};

  my_decimal decimal_check = {{0xC39FF36F, 0x7, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok907) {
  my_decimal decimal = {{0xF0A89E8F, 0x7A550568, 0x963E4C0F, 0x801C0000}};

  my_decimal decimal_check = {{0x5, 0x0, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok908) {
  my_decimal decimal = {{0xF0A89E8F, 0x7A550568, 0x963E4C0F, 0x1C0000}};

  my_decimal decimal_check = {{0x5, 0x0, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok909) {
  my_decimal decimal = {{0x2446E975, 0x3DD6B6CE, 0x8C68C7AE, 0x800D0000}};

  my_decimal decimal_check = {{0x9C852076, 0xF702B, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok910) {
  my_decimal decimal = {{0x2446E975, 0x3DD6B6CE, 0x8C68C7AE, 0xD0000}};

  my_decimal decimal_check = {{0x9C852076, 0xF702B, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok911) {
  my_decimal decimal = {{0x324853F4, 0xA561AB58, 0xE61DAA42, 0x80160000}};

  my_decimal decimal_check = {{0x6CAB4E, 0x0, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok912) {
  my_decimal decimal = {{0x324853F4, 0xA561AB58, 0xE61DAA42, 0x160000}};

  my_decimal decimal_check = {{0x6CAB4E, 0x0, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok913) {
  my_decimal decimal = {{0xCF51B38E, 0x7FC83059, 0x59E96965, 0x80090000}};

  my_decimal decimal_check = {{0x9B092940, 0x822B07CF, 0x1, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok914) {
  my_decimal decimal = {{0xCF51B38E, 0x7FC83059, 0x59E96965, 0x90000}};

  my_decimal decimal_check = {{0x9B092940, 0x822B07CF, 0x1, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok915) {
  my_decimal decimal = {{0xAED5021E, 0xF1AA72D5, 0x2A361BDC, 0x800D0000}};

  my_decimal decimal_check = {{0xEC64934B, 0x4A424, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok916) {
  my_decimal decimal = {{0xAED5021E, 0xF1AA72D5, 0x2A361BDC, 0xD0000}};

  my_decimal decimal_check = {{0xEC64934B, 0x4A424, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok917) {
  my_decimal decimal = {{0xB7E9CD1E, 0x7C263F44, 0x56137B80, 0x10000}};

  my_decimal decimal_check = {{0x78CA9483, 0xA603D320, 0x89B8C59, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok918) {
  my_decimal decimal = {{0xB7E9CD1E, 0x7C263F44, 0x56137B80, 0x80010000}};

  my_decimal decimal_check = {{0x78CA9483, 0xA603D320, 0x89B8C59, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok919) {
  my_decimal decimal = {{0xBB246330, 0xC585D50E, 0x715F90B, 0x80060000}};

  my_decimal decimal_check = {{0x4218C9AA, 0xE16A0182, 0x76, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok920) {
  my_decimal decimal = {{0xBB246330, 0xC585D50E, 0x715F90B, 0x60000}};

  my_decimal decimal_check = {{0x4218C9AA, 0xE16A0182, 0x76, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok921) {
  my_decimal decimal = {{0x827F4834, 0x382DD630, 0x779AF0EC, 0x150000}};

  my_decimal decimal_check = {{0x234D1DC, 0x0, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok922) {
  my_decimal decimal = {{0x827F4834, 0x382DD630, 0x779AF0EC, 0x80150000}};

  my_decimal decimal_check = {{0x234D1DC, 0x0, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok923) {
  my_decimal decimal = {{0xC2502FE7, 0xD1BD4DA4, 0x7CF915B0, 0x170000}};

  my_decimal decimal_check = {{0x5E6D5, 0x0, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok924) {
  my_decimal decimal = {{0xC2502FE7, 0xD1BD4DA4, 0x7CF915B0, 0x80170000}};

  my_decimal decimal_check = {{0x5E6D5, 0x0, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok925) {
  my_decimal decimal = {{0xD3BA6B3F, 0xECD91DDD, 0xB671F79C, 0x800A0000}};

  my_decimal decimal_check = {{0x102C8F45, 0x4E5C0F68, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok926) {
  my_decimal decimal = {{0xD3BA6B3F, 0xECD91DDD, 0xB671F79C, 0xA0000}};

  my_decimal decimal_check = {{0x102C8F45, 0x4E5C0F68, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok927) {
  my_decimal decimal = {{0x94737E8C, 0x689CF821, 0xC42A2C2E, 0x150000}};

  my_decimal decimal_check = {{0x39E5C9D, 0x0, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok928) {
  my_decimal decimal = {{0x94737E8C, 0x689CF821, 0xC42A2C2E, 0x80150000}};

  my_decimal decimal_check = {{0x39E5C9D, 0x0, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok929) {
  my_decimal decimal = {{0xA212A2A2, 0xAD904C27, 0x2EA9DC4, 0x20000}};

  my_decimal decimal_check = {{0xB7617763, 0x726029B8, 0x77756, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok930) {
  my_decimal decimal = {{0xA212A2A2, 0xAD904C27, 0x2EA9DC4, 0x80020000}};

  my_decimal decimal_check = {{0xB7617763, 0x726029B8, 0x77756, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok931) {
  my_decimal decimal = {{0xC0C0A04F, 0xA85C6527, 0xA70BA7B1, 0xA0000}};

  my_decimal decimal_check = {{0xE2B27CF, 0x47BED999, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok932) {
  my_decimal decimal = {{0xC0C0A04F, 0xA85C6527, 0xA70BA7B1, 0x800A0000}};

  my_decimal decimal_check = {{0xE2B27CF, 0x47BED999, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok933) {
  my_decimal decimal = {{0xC91C6A61, 0x759F26D, 0xF1C4B797, 0x80130000}};

  my_decimal decimal_check = {{0xBDFBE94D, 0x1, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok934) {
  my_decimal decimal = {{0xC91C6A61, 0x759F26D, 0xF1C4B797, 0x130000}};

  my_decimal decimal_check = {{0xBDFBE94D, 0x1, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok935) {
  my_decimal decimal = {{0xD1554DA9, 0x15E89EB9, 0x8FBAA09C, 0x70000}};

  my_decimal decimal_check = {{0x7A83B4DD, 0x23242095, 0xF1, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok936) {
  my_decimal decimal = {{0xD1554DA9, 0x15E89EB9, 0x8FBAA09C, 0x80070000}};

  my_decimal decimal_check = {{0x7A83B4DD, 0x23242095, 0xF1, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok937) {
  my_decimal decimal = {{0xE3D48184, 0x8798E251, 0xF9322EA1, 0x80020000}};

  my_decimal decimal_check = {{0xDBE0D856, 0x371DB057, 0x27DF11B, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok938) {
  my_decimal decimal = {{0xE3D48184, 0x8798E251, 0xF9322EA1, 0x20000}};

  my_decimal decimal_check = {{0xDBE0D856, 0x371DB057, 0x27DF11B, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok939) {
  my_decimal decimal = {{0xFADA7E2E, 0xD15EE8DD, 0x45D7854F, 0x150000}};

  my_decimal decimal_check = {{0x149D1A6, 0x0, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok940) {
  my_decimal decimal = {{0xFADA7E2E, 0xD15EE8DD, 0x45D7854F, 0x80150000}};

  my_decimal decimal_check = {{0x149D1A6, 0x0, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok941) {
  my_decimal decimal = {{0xAFE2DE6B, 0xBB3853C5, 0x5801BBBC, 0x80130000}};

  my_decimal decimal_check = {{0xA25805C3, 0x0, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok942) {
  my_decimal decimal = {{0xAFE2DE6B, 0xBB3853C5, 0x5801BBBC, 0x130000}};

  my_decimal decimal_check = {{0xA25805C3, 0x0, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok943) {
  my_decimal decimal = {{0x84C3EFA, 0x202C4BB9, 0x2A19EC61, 0x800D0000}};

  my_decimal decimal_check = {{0x92954D02, 0x4A10B, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok944) {
  my_decimal decimal = {{0x84C3EFA, 0x202C4BB9, 0x2A19EC61, 0xD0000}};

  my_decimal decimal_check = {{0x92954D02, 0x4A10B, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok945) {
  my_decimal decimal = {{0x650FD6D7, 0x2425348, 0x486A9236, 0x80010000}};

  my_decimal decimal_check = {{0xA3B4C8AF, 0xCD06A1ED, 0x73DDB6B, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok946) {
  my_decimal decimal = {{0x650FD6D7, 0x2425348, 0x486A9236, 0x10000}};

  my_decimal decimal_check = {{0xA3B4C8AF, 0xCD06A1ED, 0x73DDB6B, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok947) {
  my_decimal decimal = {{0x8FAEFB0A, 0x5FBA53C2, 0xBE36CC90, 0x80160000}};

  my_decimal decimal_check = {{0x59D378, 0x0, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok948) {
  my_decimal decimal = {{0x8FAEFB0A, 0x5FBA53C2, 0xBE36CC90, 0x160000}};

  my_decimal decimal_check = {{0x59D378, 0x0, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok949) {
  my_decimal decimal = {{0x3E35F240, 0x8BDDD4A5, 0xC5C9DE86, 0x120000}};

  my_decimal decimal_check = {{0x408E0700, 0xE, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok950) {
  my_decimal decimal = {{0x3E35F240, 0x8BDDD4A5, 0xC5C9DE86, 0x80120000}};

  my_decimal decimal_check = {{0x408E0700, 0xE, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok951) {
  my_decimal decimal = {{0xAD0C59CE, 0xF876B665, 0x37834F7A, 0x800D0000}};

  my_decimal decimal_check = {{0xD40F7484, 0x61A8C, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok952) {
  my_decimal decimal = {{0xAD0C59CE, 0xF876B665, 0x37834F7A, 0xD0000}};

  my_decimal decimal_check = {{0xD40F7484, 0x61A8C, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok953) {
  my_decimal decimal = {{0x2A324102, 0x57B0E335, 0x805CD621, 0x800D0000}};

  my_decimal decimal_check = {{0x513D3B2C, 0xE1D16, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok954) {
  my_decimal decimal = {{0x2A324102, 0x57B0E335, 0x805CD621, 0xD0000}};

  my_decimal decimal_check = {{0x513D3B2C, 0xE1D16, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok955) {
  my_decimal decimal = {{0x3C7E8D42, 0xBA0FAE6A, 0xD31E318D, 0x80160000}};

  my_decimal decimal_check = {{0x63B298, 0x0, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok956) {
  my_decimal decimal = {{0x3C7E8D42, 0xBA0FAE6A, 0xD31E318D, 0x160000}};

  my_decimal decimal_check = {{0x63B298, 0x0, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok957) {
  my_decimal decimal = {{0x14CC8A99, 0x155637DA, 0x61A04E61, 0x80100000}};

  my_decimal decimal_check = {{0x788B9227, 0x2BF, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok958) {
  my_decimal decimal = {{0x14CC8A99, 0x155637DA, 0x61A04E61, 0x100000}};

  my_decimal decimal_check = {{0x788B9227, 0x2BF, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok959) {
  my_decimal decimal = {{0xD6E6D2C, 0xE50FC370, 0x6D9864CF, 0x170000}};

  my_decimal decimal_check = {{0x52CED, 0x0, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok960) {
  my_decimal decimal = {{0xD6E6D2C, 0xE50FC370, 0x6D9864CF, 0x80170000}};

  my_decimal decimal_check = {{0x52CED, 0x0, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok961) {
  my_decimal decimal = {{0x9A53C9CE, 0xA277E29A, 0x899A0FF6, 0xA0000}};

  my_decimal decimal_check = {{0x283C5444, 0x3B197A84, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok962) {
  my_decimal decimal = {{0x9A53C9CE, 0xA277E29A, 0x899A0FF6, 0x800A0000}};

  my_decimal decimal_check = {{0x283C5444, 0x3B197A84, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok963) {
  my_decimal decimal = {{0x8A91D045, 0x72268993, 0x4939A0DF, 0x80100000}};

  my_decimal decimal_check = {{0xA47CFA24, 0x20F, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok964) {
  my_decimal decimal = {{0x8A91D045, 0x72268993, 0x4939A0DF, 0x100000}};

  my_decimal decimal_check = {{0xA47CFA24, 0x20F, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok965) {
  my_decimal decimal = {{0x8675D982, 0xF0F4B94, 0x360C1305, 0x80000}};

  my_decimal decimal_check = {{0x2BAD45DF, 0x114EDDB6, 0x9, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok966) {
  my_decimal decimal = {{0x8675D982, 0xF0F4B94, 0x360C1305, 0x80080000}};

  my_decimal decimal_check = {{0x2BAD45DF, 0x114EDDB6, 0x9, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok967) {
  my_decimal decimal = {{0xC8A8CE18, 0x8AE147D6, 0xCAAF939E, 0x80050000}};

  my_decimal decimal_check = {{0x6F633A30, 0xACF4913, 0x84D5, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok968) {
  my_decimal decimal = {{0xC8A8CE18, 0x8AE147D6, 0xCAAF939E, 0x50000}};

  my_decimal decimal_check = {{0x6F633A30, 0xACF4913, 0x84D5, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok969) {
  my_decimal decimal = {{0x20C8C80C, 0x9A2FEF37, 0x11F12AC0, 0xD0000}};

  my_decimal decimal_check = {{0x285038EE, 0x1F906, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok970) {
  my_decimal decimal = {{0x20C8C80C, 0x9A2FEF37, 0x11F12AC0, 0x800D0000}};

  my_decimal decimal_check = {{0x285038EE, 0x1F906, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok971) {
  my_decimal decimal = {{0x5CE3395A, 0x1D3F5026, 0x9CF5CF3D, 0x800A0000}};

  my_decimal decimal_check = {{0xF6611A2, 0x4369F4AE, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok972) {
  my_decimal decimal = {{0x5CE3395A, 0x1D3F5026, 0x9CF5CF3D, 0xA0000}};

  my_decimal decimal_check = {{0xF6611A2, 0x4369F4AE, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok973) {
  my_decimal decimal = {{0xEC37E57C, 0x77B6D871, 0x62EF13F2, 0x800C0000}};

  my_decimal decimal_check = {{0xAAD1B33A, 0x6CC76A, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok974) {
  my_decimal decimal = {{0xEC37E57C, 0x77B6D871, 0x62EF13F2, 0xC0000}};

  my_decimal decimal_check = {{0xAAD1B33A, 0x6CC76A, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok975) {
  my_decimal decimal = {{0xAB2DC922, 0xA8AE8006, 0x56DBFD63, 0x40000}};

  my_decimal decimal_check = {{0x69701B63, 0xC863586F, 0x2393D, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok976) {
  my_decimal decimal = {{0xAB2DC922, 0xA8AE8006, 0x56DBFD63, 0x80040000}};

  my_decimal decimal_check = {{0x69701B63, 0xC863586F, 0x2393D, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok977) {
  my_decimal decimal = {{0xDB593398, 0x2CD9BFDE, 0x9AC9FB2E, 0x10000}};

  my_decimal decimal_check = {{0xAF88EB8F, 0x37AF5FFC, 0xF7A991E, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok978) {
  my_decimal decimal = {{0xDB593398, 0x2CD9BFDE, 0x9AC9FB2E, 0x80010000}};

  my_decimal decimal_check = {{0xAF88EB8F, 0x37AF5FFC, 0xF7A991E, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok979) {
  my_decimal decimal = {{0x1BF06A30, 0x68705518, 0xAD6783C3, 0x140000}};

  my_decimal decimal_check = {{0x1FFCCA03, 0x0, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok980) {
  my_decimal decimal = {{0x1BF06A30, 0x68705518, 0xAD6783C3, 0x80140000}};

  my_decimal decimal_check = {{0x1FFCCA03, 0x0, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok981) {
  my_decimal decimal = {{0xCB8B0617, 0xC42A85F, 0xF08C4A3B, 0xC0000}};

  my_decimal decimal_check = {{0xAEED7F3F, 0x1087C3E, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok982) {
  my_decimal decimal = {{0xCB8B0617, 0xC42A85F, 0xF08C4A3B, 0x800C0000}};

  my_decimal decimal_check = {{0xAEED7F3F, 0x1087C3E, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok983) {
  my_decimal decimal = {{0x31175F26, 0x64218805, 0x7232732E, 0x80180000}};

  my_decimal decimal_check = {{0x8A0E, 0x0, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok984) {
  my_decimal decimal = {{0x31175F26, 0x64218805, 0x7232732E, 0x180000}};

  my_decimal decimal_check = {{0x8A0E, 0x0, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok985) {
  my_decimal decimal = {{0x7BA67FE, 0xAA34265B, 0x5EE70C00, 0x90000}};

  my_decimal decimal_check = {{0x2E32F85D, 0x979A6E8C, 0x1, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok986) {
  my_decimal decimal = {{0x7BA67FE, 0xAA34265B, 0x5EE70C00, 0x80090000}};

  my_decimal decimal_check = {{0x2E32F85D, 0x979A6E8C, 0x1, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok987) {
  my_decimal decimal = {{0x90325C71, 0xBCFD090A, 0xC6346CD0, 0x40000}};

  my_decimal decimal_check = {{0x3C126FE2, 0x731DD2DE, 0x512F4, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok988) {
  my_decimal decimal = {{0x90325C71, 0xBCFD090A, 0xC6346CD0, 0x80040000}};

  my_decimal decimal_check = {{0x3C126FE2, 0x731DD2DE, 0x512F4, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok989) {
  my_decimal decimal = {{0xC295D71E, 0xDE99E789, 0x6D029C68, 0x80050000}};

  my_decimal decimal_check = {{0x439BE67F, 0xE066CE57, 0x4770, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok990) {
  my_decimal decimal = {{0xC295D71E, 0xDE99E789, 0x6D029C68, 0x50000}};

  my_decimal decimal_check = {{0x439BE67F, 0xE066CE57, 0x4770, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok991) {
  my_decimal decimal = {{0xCC4B3962, 0xDEE0DDAF, 0x5313EC23, 0x80170000}};

  my_decimal decimal_check = {{0x3EC59, 0x0, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok992) {
  my_decimal decimal = {{0xCC4B3962, 0xDEE0DDAF, 0x5313EC23, 0x170000}};

  my_decimal decimal_check = {{0x3EC59, 0x0, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok993) {
  my_decimal decimal = {{0x754711F2, 0xECE5E435, 0xDCAFD73, 0x80120000}};

  my_decimal decimal_check = {{0xFE6F4510, 0x0, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok994) {
  my_decimal decimal = {{0x754711F2, 0xECE5E435, 0xDCAFD73, 0x120000}};

  my_decimal decimal_check = {{0xFE6F4510, 0x0, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok995) {
  my_decimal decimal = {{0xAD2B1069, 0xC01B1C6A, 0x5A34559, 0x800B0000}};

  my_decimal decimal_check = {{0x6E847894, 0x3DFCEE, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok996) {
  my_decimal decimal = {{0xAD2B1069, 0xC01B1C6A, 0x5A34559, 0xB0000}};

  my_decimal decimal_check = {{0x6E847894, 0x3DFCEE, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok997) {
  my_decimal decimal = {{0xA9DC2F35, 0x59E57351, 0x4F37DD31, 0xE0000}};

  my_decimal decimal_check = {{0xBE18E6CB, 0xDEFA, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok998) {
  my_decimal decimal = {{0xA9DC2F35, 0x59E57351, 0x4F37DD31, 0x800E0000}};

  my_decimal decimal_check = {{0xBE18E6CB, 0xDEFA, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok999) {
  my_decimal decimal = {{0xE9C6C9AC, 0x7F868D8F, 0xE41050CA, 0x80010000}};

  my_decimal decimal_check = {
      {0x30FA475E, 0xA65A415B, 0x16CE6E7A, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok1000) {
  my_decimal decimal = {{0xE9C6C9AC, 0x7F868D8F, 0xE41050CA, 0x10000}};

  my_decimal decimal_check = {{0x30FA475E, 0xA65A415B, 0x16CE6E7A, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok1001) {
  my_decimal decimal = {{0xB2982904, 0xC903D12F, 0xDCC5E2B5, 0x70000}};

  my_decimal decimal_check = {{0x8EAFAAD2, 0x654705F2, 0x172, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok1002) {
  my_decimal decimal = {{0xB2982904, 0xC903D12F, 0xDCC5E2B5, 0x80070000}};

  my_decimal decimal_check = {{0x8EAFAAD2, 0x654705F2, 0x172, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok1003) {
  my_decimal decimal = {{0x6DB37C7, 0xE39D7F6D, 0x231B59E2, 0x80140000}};

  my_decimal decimal_check = {{0x679DFA8, 0x0, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok1004) {
  my_decimal decimal = {{0x6DB37C7, 0xE39D7F6D, 0x231B59E2, 0x140000}};

  my_decimal decimal_check = {{0x679DFA8, 0x0, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok1005) {
  my_decimal decimal = {{0x13B916CF, 0x2DB58186, 0xA2262799, 0x80180000}};

  my_decimal decimal_check = {{0xC407, 0x0, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok1006) {
  my_decimal decimal = {{0x13B916CF, 0x2DB58186, 0xA2262799, 0x180000}};

  my_decimal decimal_check = {{0xC407, 0x0, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok1007) {
  my_decimal decimal = {{0xB8817C71, 0x9A8C8BF0, 0x55E8058F, 0x801C0000}};

  my_decimal decimal_check = {{0x3, 0x0, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok1008) {
  my_decimal decimal = {{0xB8817C71, 0x9A8C8BF0, 0x55E8058F, 0x1C0000}};

  my_decimal decimal_check = {{0x3, 0x0, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok1009) {
  my_decimal decimal = {{0x66427FFD, 0x2C4F0BF, 0x124FB73E, 0x80130000}};

  my_decimal decimal_check = {{0x21C74F31, 0x0, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok1010) {
  my_decimal decimal = {{0x66427FFD, 0x2C4F0BF, 0x124FB73E, 0x130000}};

  my_decimal decimal_check = {{0x21C74F31, 0x0, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok1011) {
  my_decimal decimal = {{0x36A4E53, 0xD66364F4, 0x66E7B9DD, 0x0}};

  my_decimal decimal_check = {{0x36A4E53, 0xD66364F4, 0x66E7B9DD, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok1012) {
  my_decimal decimal = {{0x36A4E53, 0xD66364F4, 0x66E7B9DD, 0x80000000}};

  my_decimal decimal_check = {{0x36A4E53, 0xD66364F4, 0x66E7B9DD, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok1013) {
  my_decimal decimal = {{0x51A4A4C3, 0x968E990B, 0x3389D643, 0x1C0000}};

  my_decimal decimal_check = {{0x2, 0x0, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok1014) {
  my_decimal decimal = {{0x51A4A4C3, 0x968E990B, 0x3389D643, 0x801C0000}};

  my_decimal decimal_check = {{0x2, 0x0, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok1015) {
  my_decimal decimal = {{0x2AD8EF9A, 0x7593DBD5, 0xD75377D, 0x1B0000}};

  my_decimal decimal_check = {{0x4, 0x0, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok1016) {
  my_decimal decimal = {{0x2AD8EF9A, 0x7593DBD5, 0xD75377D, 0x801B0000}};

  my_decimal decimal_check = {{0x4, 0x0, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok1017) {
  my_decimal decimal = {{0xA79D5A80, 0xD4EC3EF1, 0xDA6A5651, 0x10000}};

  my_decimal decimal_check = {{0xC3F622A6, 0x2EE46CB1, 0x15D76F08, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok1018) {
  my_decimal decimal = {{0xA79D5A80, 0xD4EC3EF1, 0xDA6A5651, 0x80010000}};

  my_decimal decimal_check = {
      {0xC3F622A6, 0x2EE46CB1, 0x15D76F08, 0x80000000}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok1019) {
  my_decimal decimal = {{0xBF2EBEBB, 0x521A495B, 0x5113A937, 0x140000}};

  my_decimal decimal_check = {{0xEF4BE61, 0x0, 0x0, 0x0}};

  test_round(decimal, decimal_check);
}

START_TEST(test_round_ok1020) {
  my_decimal decimal = {{0xBF2EBEBB, 0x521A495B, 0x5113A937, 0x80140000}};

  my_decimal decimal_check = {{0xEF4BE61, 0x0, 0x0, 0x80000000}};

  test_round(decimal, decimal_check);
}

Suite *round_suite1(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("round_suite1");
  tc_core = tcase_create("Core");
  tcase_add_test(tc_core, test_round_ok1);
  tcase_add_test(tc_core, test_round_ok2);
  tcase_add_test(tc_core, test_round_ok3);
  tcase_add_test(tc_core, test_round_ok4);
  tcase_add_test(tc_core, test_round_ok5);
  tcase_add_test(tc_core, test_round_ok6);
  tcase_add_test(tc_core, test_round_ok7);
  tcase_add_test(tc_core, test_round_ok8);
  tcase_add_test(tc_core, test_round_ok9);
  tcase_add_test(tc_core, test_round_ok10);
  tcase_add_test(tc_core, test_round_ok11);
  tcase_add_test(tc_core, test_round_ok12);
  tcase_add_test(tc_core, test_round_ok13);
  tcase_add_test(tc_core, test_round_ok14);
  tcase_add_test(tc_core, test_round_ok15);
  tcase_add_test(tc_core, test_round_ok16);
  tcase_add_test(tc_core, test_round_ok17);
  tcase_add_test(tc_core, test_round_ok18);
  tcase_add_test(tc_core, test_round_ok19);
  tcase_add_test(tc_core, test_round_ok20);
  tcase_add_test(tc_core, test_round_ok21);
  tcase_add_test(tc_core, test_round_ok22);
  tcase_add_test(tc_core, test_round_ok23);
  tcase_add_test(tc_core, test_round_ok24);
  tcase_add_test(tc_core, test_round_ok25);
  tcase_add_test(tc_core, test_round_ok26);
  tcase_add_test(tc_core, test_round_ok27);
  tcase_add_test(tc_core, test_round_ok28);
  tcase_add_test(tc_core, test_round_ok29);
  tcase_add_test(tc_core, test_round_ok30);
  tcase_add_test(tc_core, test_round_ok31);
  tcase_add_test(tc_core, test_round_ok32);
  tcase_add_test(tc_core, test_round_ok33);
  tcase_add_test(tc_core, test_round_ok34);
  tcase_add_test(tc_core, test_round_ok35);
  tcase_add_test(tc_core, test_round_ok36);
  tcase_add_test(tc_core, test_round_ok37);
  tcase_add_test(tc_core, test_round_ok38);
  tcase_add_test(tc_core, test_round_ok39);
  tcase_add_test(tc_core, test_round_ok40);
  tcase_add_test(tc_core, test_round_ok41);
  tcase_add_test(tc_core, test_round_ok42);
  tcase_add_test(tc_core, test_round_ok43);
  tcase_add_test(tc_core, test_round_ok44);
  tcase_add_test(tc_core, test_round_ok45);
  tcase_add_test(tc_core, test_round_ok46);
  tcase_add_test(tc_core, test_round_ok47);
  tcase_add_test(tc_core, test_round_ok48);
  tcase_add_test(tc_core, test_round_ok49);
  tcase_add_test(tc_core, test_round_ok50);
  tcase_add_test(tc_core, test_round_ok51);
  tcase_add_test(tc_core, test_round_ok52);
  tcase_add_test(tc_core, test_round_ok53);
  tcase_add_test(tc_core, test_round_ok54);
  tcase_add_test(tc_core, test_round_ok55);
  tcase_add_test(tc_core, test_round_ok56);
  tcase_add_test(tc_core, test_round_ok57);
  tcase_add_test(tc_core, test_round_ok58);
  tcase_add_test(tc_core, test_round_ok59);
  tcase_add_test(tc_core, test_round_ok60);
  tcase_add_test(tc_core, test_round_ok61);
  tcase_add_test(tc_core, test_round_ok62);
  tcase_add_test(tc_core, test_round_ok63);
  tcase_add_test(tc_core, test_round_ok64);
  tcase_add_test(tc_core, test_round_ok65);
  tcase_add_test(tc_core, test_round_ok66);
  tcase_add_test(tc_core, test_round_ok67);
  tcase_add_test(tc_core, test_round_ok68);
  tcase_add_test(tc_core, test_round_ok69);
  tcase_add_test(tc_core, test_round_ok70);
  tcase_add_test(tc_core, test_round_ok71);
  tcase_add_test(tc_core, test_round_ok72);
  tcase_add_test(tc_core, test_round_ok73);
  tcase_add_test(tc_core, test_round_ok74);
  tcase_add_test(tc_core, test_round_ok75);
  tcase_add_test(tc_core, test_round_ok76);
  tcase_add_test(tc_core, test_round_ok77);
  tcase_add_test(tc_core, test_round_ok78);
  tcase_add_test(tc_core, test_round_ok79);
  tcase_add_test(tc_core, test_round_ok80);
  tcase_add_test(tc_core, test_round_ok81);
  tcase_add_test(tc_core, test_round_ok82);
  tcase_add_test(tc_core, test_round_ok83);
  tcase_add_test(tc_core, test_round_ok84);
  tcase_add_test(tc_core, test_round_ok85);
  tcase_add_test(tc_core, test_round_ok86);
  tcase_add_test(tc_core, test_round_ok87);
  tcase_add_test(tc_core, test_round_ok88);
  tcase_add_test(tc_core, test_round_ok89);
  tcase_add_test(tc_core, test_round_ok90);
  tcase_add_test(tc_core, test_round_ok91);
  tcase_add_test(tc_core, test_round_ok92);
  tcase_add_test(tc_core, test_round_ok93);
  tcase_add_test(tc_core, test_round_ok94);
  tcase_add_test(tc_core, test_round_ok95);
  tcase_add_test(tc_core, test_round_ok96);
  tcase_add_test(tc_core, test_round_ok97);
  tcase_add_test(tc_core, test_round_ok98);
  tcase_add_test(tc_core, test_round_ok99);
  tcase_add_test(tc_core, test_round_ok100);
  tcase_add_test(tc_core, test_round_ok101);
  tcase_add_test(tc_core, test_round_ok102);
  tcase_add_test(tc_core, test_round_ok103);
  tcase_add_test(tc_core, test_round_ok104);
  tcase_add_test(tc_core, test_round_ok105);
  tcase_add_test(tc_core, test_round_ok106);
  tcase_add_test(tc_core, test_round_ok107);
  tcase_add_test(tc_core, test_round_ok108);
  tcase_add_test(tc_core, test_round_ok109);
  tcase_add_test(tc_core, test_round_ok110);
  tcase_add_test(tc_core, test_round_ok111);
  tcase_add_test(tc_core, test_round_ok112);
  tcase_add_test(tc_core, test_round_ok113);
  tcase_add_test(tc_core, test_round_ok114);
  tcase_add_test(tc_core, test_round_ok115);
  tcase_add_test(tc_core, test_round_ok116);
  tcase_add_test(tc_core, test_round_ok117);
  tcase_add_test(tc_core, test_round_ok118);
  tcase_add_test(tc_core, test_round_ok119);
  tcase_add_test(tc_core, test_round_ok120);
  tcase_add_test(tc_core, test_round_ok121);
  tcase_add_test(tc_core, test_round_ok122);
  tcase_add_test(tc_core, test_round_ok123);
  tcase_add_test(tc_core, test_round_ok124);
  tcase_add_test(tc_core, test_round_ok125);
  tcase_add_test(tc_core, test_round_ok126);
  tcase_add_test(tc_core, test_round_ok127);
  tcase_add_test(tc_core, test_round_ok128);
  tcase_add_test(tc_core, test_round_ok129);
  tcase_add_test(tc_core, test_round_ok130);
  tcase_add_test(tc_core, test_round_ok131);
  tcase_add_test(tc_core, test_round_ok132);
  tcase_add_test(tc_core, test_round_ok133);
  tcase_add_test(tc_core, test_round_ok134);
  tcase_add_test(tc_core, test_round_ok135);
  tcase_add_test(tc_core, test_round_ok136);
  tcase_add_test(tc_core, test_round_ok137);
  tcase_add_test(tc_core, test_round_ok138);
  tcase_add_test(tc_core, test_round_ok139);
  tcase_add_test(tc_core, test_round_ok140);
  tcase_add_test(tc_core, test_round_ok141);
  tcase_add_test(tc_core, test_round_ok142);
  tcase_add_test(tc_core, test_round_ok143);
  tcase_add_test(tc_core, test_round_ok144);
  tcase_add_test(tc_core, test_round_ok145);
  tcase_add_test(tc_core, test_round_ok146);
  tcase_add_test(tc_core, test_round_ok147);
  tcase_add_test(tc_core, test_round_ok148);
  tcase_add_test(tc_core, test_round_ok149);
  tcase_add_test(tc_core, test_round_ok150);
  tcase_add_test(tc_core, test_round_ok151);
  tcase_add_test(tc_core, test_round_ok152);
  tcase_add_test(tc_core, test_round_ok153);
  tcase_add_test(tc_core, test_round_ok154);
  tcase_add_test(tc_core, test_round_ok155);
  tcase_add_test(tc_core, test_round_ok156);
  tcase_add_test(tc_core, test_round_ok157);
  tcase_add_test(tc_core, test_round_ok158);
  tcase_add_test(tc_core, test_round_ok159);
  tcase_add_test(tc_core, test_round_ok160);
  tcase_add_test(tc_core, test_round_ok161);
  tcase_add_test(tc_core, test_round_ok162);
  tcase_add_test(tc_core, test_round_ok163);
  tcase_add_test(tc_core, test_round_ok164);
  tcase_add_test(tc_core, test_round_ok165);
  tcase_add_test(tc_core, test_round_ok166);
  tcase_add_test(tc_core, test_round_ok167);
  tcase_add_test(tc_core, test_round_ok168);
  tcase_add_test(tc_core, test_round_ok169);
  tcase_add_test(tc_core, test_round_ok170);
  tcase_add_test(tc_core, test_round_ok171);
  tcase_add_test(tc_core, test_round_ok172);
  tcase_add_test(tc_core, test_round_ok173);
  tcase_add_test(tc_core, test_round_ok174);
  tcase_add_test(tc_core, test_round_ok175);
  tcase_add_test(tc_core, test_round_ok176);
  tcase_add_test(tc_core, test_round_ok177);
  tcase_add_test(tc_core, test_round_ok178);
  tcase_add_test(tc_core, test_round_ok179);
  tcase_add_test(tc_core, test_round_ok180);
  tcase_add_test(tc_core, test_round_ok181);
  tcase_add_test(tc_core, test_round_ok182);
  tcase_add_test(tc_core, test_round_ok183);
  tcase_add_test(tc_core, test_round_ok184);
  tcase_add_test(tc_core, test_round_ok185);
  tcase_add_test(tc_core, test_round_ok186);
  tcase_add_test(tc_core, test_round_ok187);
  tcase_add_test(tc_core, test_round_ok188);
  tcase_add_test(tc_core, test_round_ok189);
  tcase_add_test(tc_core, test_round_ok190);
  tcase_add_test(tc_core, test_round_ok191);
  tcase_add_test(tc_core, test_round_ok192);
  tcase_add_test(tc_core, test_round_ok193);
  tcase_add_test(tc_core, test_round_ok194);
  tcase_add_test(tc_core, test_round_ok195);
  tcase_add_test(tc_core, test_round_ok196);
  tcase_add_test(tc_core, test_round_ok197);
  tcase_add_test(tc_core, test_round_ok198);
  tcase_add_test(tc_core, test_round_ok199);
  tcase_add_test(tc_core, test_round_ok200);
  tcase_add_test(tc_core, test_round_ok201);
  tcase_add_test(tc_core, test_round_ok202);
  tcase_add_test(tc_core, test_round_ok203);
  tcase_add_test(tc_core, test_round_ok204);
  tcase_add_test(tc_core, test_round_ok205);
  tcase_add_test(tc_core, test_round_ok206);
  tcase_add_test(tc_core, test_round_ok207);
  tcase_add_test(tc_core, test_round_ok208);
  tcase_add_test(tc_core, test_round_ok209);
  tcase_add_test(tc_core, test_round_ok210);
  tcase_add_test(tc_core, test_round_ok211);
  tcase_add_test(tc_core, test_round_ok212);
  tcase_add_test(tc_core, test_round_ok213);
  tcase_add_test(tc_core, test_round_ok214);
  tcase_add_test(tc_core, test_round_ok215);
  tcase_add_test(tc_core, test_round_ok216);
  tcase_add_test(tc_core, test_round_ok217);
  tcase_add_test(tc_core, test_round_ok218);
  tcase_add_test(tc_core, test_round_ok219);
  tcase_add_test(tc_core, test_round_ok220);
  tcase_add_test(tc_core, test_round_ok221);
  tcase_add_test(tc_core, test_round_ok222);
  tcase_add_test(tc_core, test_round_ok223);
  tcase_add_test(tc_core, test_round_ok224);
  tcase_add_test(tc_core, test_round_ok225);
  tcase_add_test(tc_core, test_round_ok226);
  tcase_add_test(tc_core, test_round_ok227);
  tcase_add_test(tc_core, test_round_ok228);
  tcase_add_test(tc_core, test_round_ok229);
  tcase_add_test(tc_core, test_round_ok230);
  tcase_add_test(tc_core, test_round_ok231);
  tcase_add_test(tc_core, test_round_ok232);
  tcase_add_test(tc_core, test_round_ok233);
  tcase_add_test(tc_core, test_round_ok234);
  tcase_add_test(tc_core, test_round_ok235);
  tcase_add_test(tc_core, test_round_ok236);
  tcase_add_test(tc_core, test_round_ok237);
  tcase_add_test(tc_core, test_round_ok238);
  tcase_add_test(tc_core, test_round_ok239);
  tcase_add_test(tc_core, test_round_ok240);
  tcase_add_test(tc_core, test_round_ok241);
  tcase_add_test(tc_core, test_round_ok242);
  tcase_add_test(tc_core, test_round_ok243);
  tcase_add_test(tc_core, test_round_ok244);
  tcase_add_test(tc_core, test_round_ok245);
  tcase_add_test(tc_core, test_round_ok246);
  tcase_add_test(tc_core, test_round_ok247);
  tcase_add_test(tc_core, test_round_ok248);
  tcase_add_test(tc_core, test_round_ok249);
  tcase_add_test(tc_core, test_round_ok250);
  tcase_add_test(tc_core, test_round_ok251);
  tcase_add_test(tc_core, test_round_ok252);
  tcase_add_test(tc_core, test_round_ok253);
  tcase_add_test(tc_core, test_round_ok254);
  tcase_add_test(tc_core, test_round_ok255);
  tcase_add_test(tc_core, test_round_ok256);
  tcase_add_test(tc_core, test_round_ok257);
  tcase_add_test(tc_core, test_round_ok258);
  tcase_add_test(tc_core, test_round_ok259);
  tcase_add_test(tc_core, test_round_ok260);
  tcase_add_test(tc_core, test_round_ok261);
  tcase_add_test(tc_core, test_round_ok262);
  tcase_add_test(tc_core, test_round_ok263);
  tcase_add_test(tc_core, test_round_ok264);
  tcase_add_test(tc_core, test_round_ok265);
  tcase_add_test(tc_core, test_round_ok266);
  tcase_add_test(tc_core, test_round_ok267);
  tcase_add_test(tc_core, test_round_ok268);
  tcase_add_test(tc_core, test_round_ok269);
  tcase_add_test(tc_core, test_round_ok270);
  tcase_add_test(tc_core, test_round_ok271);
  tcase_add_test(tc_core, test_round_ok272);
  tcase_add_test(tc_core, test_round_ok273);
  tcase_add_test(tc_core, test_round_ok274);
  tcase_add_test(tc_core, test_round_ok275);
  tcase_add_test(tc_core, test_round_ok276);
  tcase_add_test(tc_core, test_round_ok277);
  tcase_add_test(tc_core, test_round_ok278);
  tcase_add_test(tc_core, test_round_ok279);
  tcase_add_test(tc_core, test_round_ok280);
  tcase_add_test(tc_core, test_round_ok281);
  tcase_add_test(tc_core, test_round_ok282);
  tcase_add_test(tc_core, test_round_ok283);
  tcase_add_test(tc_core, test_round_ok284);
  tcase_add_test(tc_core, test_round_ok285);
  tcase_add_test(tc_core, test_round_ok286);
  tcase_add_test(tc_core, test_round_ok287);
  tcase_add_test(tc_core, test_round_ok288);
  tcase_add_test(tc_core, test_round_ok289);
  tcase_add_test(tc_core, test_round_ok290);
  tcase_add_test(tc_core, test_round_ok291);
  tcase_add_test(tc_core, test_round_ok292);
  tcase_add_test(tc_core, test_round_ok293);
  tcase_add_test(tc_core, test_round_ok294);
  tcase_add_test(tc_core, test_round_ok295);
  tcase_add_test(tc_core, test_round_ok296);
  tcase_add_test(tc_core, test_round_ok297);
  tcase_add_test(tc_core, test_round_ok298);
  tcase_add_test(tc_core, test_round_ok299);
  tcase_add_test(tc_core, test_round_ok300);
  tcase_add_test(tc_core, test_round_ok301);
  tcase_add_test(tc_core, test_round_ok302);
  tcase_add_test(tc_core, test_round_ok303);
  tcase_add_test(tc_core, test_round_ok304);
  tcase_add_test(tc_core, test_round_ok305);
  tcase_add_test(tc_core, test_round_ok306);
  tcase_add_test(tc_core, test_round_ok307);
  tcase_add_test(tc_core, test_round_ok308);
  tcase_add_test(tc_core, test_round_ok309);
  tcase_add_test(tc_core, test_round_ok310);
  tcase_add_test(tc_core, test_round_ok311);
  tcase_add_test(tc_core, test_round_ok312);
  tcase_add_test(tc_core, test_round_ok313);
  tcase_add_test(tc_core, test_round_ok314);
  tcase_add_test(tc_core, test_round_ok315);
  tcase_add_test(tc_core, test_round_ok316);
  tcase_add_test(tc_core, test_round_ok317);
  tcase_add_test(tc_core, test_round_ok318);
  tcase_add_test(tc_core, test_round_ok319);
  tcase_add_test(tc_core, test_round_ok320);
  tcase_add_test(tc_core, test_round_ok321);
  tcase_add_test(tc_core, test_round_ok322);
  tcase_add_test(tc_core, test_round_ok323);
  tcase_add_test(tc_core, test_round_ok324);
  tcase_add_test(tc_core, test_round_ok325);
  tcase_add_test(tc_core, test_round_ok326);
  tcase_add_test(tc_core, test_round_ok327);
  tcase_add_test(tc_core, test_round_ok328);
  tcase_add_test(tc_core, test_round_ok329);
  tcase_add_test(tc_core, test_round_ok330);
  tcase_add_test(tc_core, test_round_ok331);
  tcase_add_test(tc_core, test_round_ok332);
  tcase_add_test(tc_core, test_round_ok333);
  tcase_add_test(tc_core, test_round_ok334);
  tcase_add_test(tc_core, test_round_ok335);
  tcase_add_test(tc_core, test_round_ok336);
  tcase_add_test(tc_core, test_round_ok337);
  tcase_add_test(tc_core, test_round_ok338);
  tcase_add_test(tc_core, test_round_ok339);
  tcase_add_test(tc_core, test_round_ok340);
  tcase_add_test(tc_core, test_round_ok341);
  tcase_add_test(tc_core, test_round_ok342);
  tcase_add_test(tc_core, test_round_ok343);
  tcase_add_test(tc_core, test_round_ok344);
  tcase_add_test(tc_core, test_round_ok345);
  tcase_add_test(tc_core, test_round_ok346);
  tcase_add_test(tc_core, test_round_ok347);
  tcase_add_test(tc_core, test_round_ok348);
  tcase_add_test(tc_core, test_round_ok349);
  tcase_add_test(tc_core, test_round_ok350);
  tcase_add_test(tc_core, test_round_ok351);
  tcase_add_test(tc_core, test_round_ok352);
  tcase_add_test(tc_core, test_round_ok353);
  tcase_add_test(tc_core, test_round_ok354);
  tcase_add_test(tc_core, test_round_ok355);
  tcase_add_test(tc_core, test_round_ok356);
  tcase_add_test(tc_core, test_round_ok357);
  tcase_add_test(tc_core, test_round_ok358);
  tcase_add_test(tc_core, test_round_ok359);
  tcase_add_test(tc_core, test_round_ok360);
  tcase_add_test(tc_core, test_round_ok361);
  tcase_add_test(tc_core, test_round_ok362);
  tcase_add_test(tc_core, test_round_ok363);
  tcase_add_test(tc_core, test_round_ok364);
  tcase_add_test(tc_core, test_round_ok365);
  tcase_add_test(tc_core, test_round_ok366);
  tcase_add_test(tc_core, test_round_ok367);
  tcase_add_test(tc_core, test_round_ok368);
  tcase_add_test(tc_core, test_round_ok369);
  tcase_add_test(tc_core, test_round_ok370);
  tcase_add_test(tc_core, test_round_ok371);
  tcase_add_test(tc_core, test_round_ok372);
  tcase_add_test(tc_core, test_round_ok373);
  tcase_add_test(tc_core, test_round_ok374);
  tcase_add_test(tc_core, test_round_ok375);
  tcase_add_test(tc_core, test_round_ok376);
  tcase_add_test(tc_core, test_round_ok377);
  tcase_add_test(tc_core, test_round_ok378);
  tcase_add_test(tc_core, test_round_ok379);
  tcase_add_test(tc_core, test_round_ok380);
  tcase_add_test(tc_core, test_round_ok381);
  tcase_add_test(tc_core, test_round_ok382);
  tcase_add_test(tc_core, test_round_ok383);
  tcase_add_test(tc_core, test_round_ok384);
  tcase_add_test(tc_core, test_round_ok385);
  tcase_add_test(tc_core, test_round_ok386);
  tcase_add_test(tc_core, test_round_ok387);
  tcase_add_test(tc_core, test_round_ok388);
  tcase_add_test(tc_core, test_round_ok389);
  tcase_add_test(tc_core, test_round_ok390);
  tcase_add_test(tc_core, test_round_ok391);
  tcase_add_test(tc_core, test_round_ok392);
  tcase_add_test(tc_core, test_round_ok393);
  tcase_add_test(tc_core, test_round_ok394);
  tcase_add_test(tc_core, test_round_ok395);
  tcase_add_test(tc_core, test_round_ok396);
  tcase_add_test(tc_core, test_round_ok397);
  tcase_add_test(tc_core, test_round_ok398);
  tcase_add_test(tc_core, test_round_ok399);
  tcase_add_test(tc_core, test_round_ok400);

  suite_add_tcase(s, tc_core);
  return s;
}

Suite *round_suite2(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("round_suite2");
  tc_core = tcase_create("Core");
  tcase_add_test(tc_core, test_round_ok401);
  tcase_add_test(tc_core, test_round_ok402);
  tcase_add_test(tc_core, test_round_ok403);
  tcase_add_test(tc_core, test_round_ok404);
  tcase_add_test(tc_core, test_round_ok405);
  tcase_add_test(tc_core, test_round_ok406);
  tcase_add_test(tc_core, test_round_ok407);
  tcase_add_test(tc_core, test_round_ok408);
  tcase_add_test(tc_core, test_round_ok409);
  tcase_add_test(tc_core, test_round_ok410);
  tcase_add_test(tc_core, test_round_ok411);
  tcase_add_test(tc_core, test_round_ok412);
  tcase_add_test(tc_core, test_round_ok413);
  tcase_add_test(tc_core, test_round_ok414);
  tcase_add_test(tc_core, test_round_ok415);
  tcase_add_test(tc_core, test_round_ok416);
  tcase_add_test(tc_core, test_round_ok417);
  tcase_add_test(tc_core, test_round_ok418);
  tcase_add_test(tc_core, test_round_ok419);
  tcase_add_test(tc_core, test_round_ok420);
  tcase_add_test(tc_core, test_round_ok421);
  tcase_add_test(tc_core, test_round_ok422);
  tcase_add_test(tc_core, test_round_ok423);
  tcase_add_test(tc_core, test_round_ok424);
  tcase_add_test(tc_core, test_round_ok425);
  tcase_add_test(tc_core, test_round_ok426);
  tcase_add_test(tc_core, test_round_ok427);
  tcase_add_test(tc_core, test_round_ok428);
  tcase_add_test(tc_core, test_round_ok429);
  tcase_add_test(tc_core, test_round_ok430);
  tcase_add_test(tc_core, test_round_ok431);
  tcase_add_test(tc_core, test_round_ok432);
  tcase_add_test(tc_core, test_round_ok433);
  tcase_add_test(tc_core, test_round_ok434);
  tcase_add_test(tc_core, test_round_ok435);
  tcase_add_test(tc_core, test_round_ok436);
  tcase_add_test(tc_core, test_round_ok437);
  tcase_add_test(tc_core, test_round_ok438);
  tcase_add_test(tc_core, test_round_ok439);
  tcase_add_test(tc_core, test_round_ok440);
  tcase_add_test(tc_core, test_round_ok441);
  tcase_add_test(tc_core, test_round_ok442);
  tcase_add_test(tc_core, test_round_ok443);
  tcase_add_test(tc_core, test_round_ok444);
  tcase_add_test(tc_core, test_round_ok445);
  tcase_add_test(tc_core, test_round_ok446);
  tcase_add_test(tc_core, test_round_ok447);
  tcase_add_test(tc_core, test_round_ok448);
  tcase_add_test(tc_core, test_round_ok449);
  tcase_add_test(tc_core, test_round_ok450);
  tcase_add_test(tc_core, test_round_ok451);
  tcase_add_test(tc_core, test_round_ok452);
  tcase_add_test(tc_core, test_round_ok453);
  tcase_add_test(tc_core, test_round_ok454);
  tcase_add_test(tc_core, test_round_ok455);
  tcase_add_test(tc_core, test_round_ok456);
  tcase_add_test(tc_core, test_round_ok457);
  tcase_add_test(tc_core, test_round_ok458);
  tcase_add_test(tc_core, test_round_ok459);
  tcase_add_test(tc_core, test_round_ok460);
  tcase_add_test(tc_core, test_round_ok461);
  tcase_add_test(tc_core, test_round_ok462);
  tcase_add_test(tc_core, test_round_ok463);
  tcase_add_test(tc_core, test_round_ok464);
  tcase_add_test(tc_core, test_round_ok465);
  tcase_add_test(tc_core, test_round_ok466);
  tcase_add_test(tc_core, test_round_ok467);
  tcase_add_test(tc_core, test_round_ok468);
  tcase_add_test(tc_core, test_round_ok469);
  tcase_add_test(tc_core, test_round_ok470);
  tcase_add_test(tc_core, test_round_ok471);
  tcase_add_test(tc_core, test_round_ok472);
  tcase_add_test(tc_core, test_round_ok473);
  tcase_add_test(tc_core, test_round_ok474);
  tcase_add_test(tc_core, test_round_ok475);
  tcase_add_test(tc_core, test_round_ok476);
  tcase_add_test(tc_core, test_round_ok477);
  tcase_add_test(tc_core, test_round_ok478);
  tcase_add_test(tc_core, test_round_ok479);
  tcase_add_test(tc_core, test_round_ok480);
  tcase_add_test(tc_core, test_round_ok481);
  tcase_add_test(tc_core, test_round_ok482);
  tcase_add_test(tc_core, test_round_ok483);
  tcase_add_test(tc_core, test_round_ok484);
  tcase_add_test(tc_core, test_round_ok485);
  tcase_add_test(tc_core, test_round_ok486);
  tcase_add_test(tc_core, test_round_ok487);
  tcase_add_test(tc_core, test_round_ok488);
  tcase_add_test(tc_core, test_round_ok489);
  tcase_add_test(tc_core, test_round_ok490);
  tcase_add_test(tc_core, test_round_ok491);
  tcase_add_test(tc_core, test_round_ok492);
  tcase_add_test(tc_core, test_round_ok493);
  tcase_add_test(tc_core, test_round_ok494);
  tcase_add_test(tc_core, test_round_ok495);
  tcase_add_test(tc_core, test_round_ok496);
  tcase_add_test(tc_core, test_round_ok497);
  tcase_add_test(tc_core, test_round_ok498);
  tcase_add_test(tc_core, test_round_ok499);
  tcase_add_test(tc_core, test_round_ok500);
  tcase_add_test(tc_core, test_round_ok501);
  tcase_add_test(tc_core, test_round_ok502);
  tcase_add_test(tc_core, test_round_ok503);
  tcase_add_test(tc_core, test_round_ok504);
  tcase_add_test(tc_core, test_round_ok505);
  tcase_add_test(tc_core, test_round_ok506);
  tcase_add_test(tc_core, test_round_ok507);
  tcase_add_test(tc_core, test_round_ok508);
  tcase_add_test(tc_core, test_round_ok509);
  tcase_add_test(tc_core, test_round_ok510);
  tcase_add_test(tc_core, test_round_ok511);
  tcase_add_test(tc_core, test_round_ok512);
  tcase_add_test(tc_core, test_round_ok513);
  tcase_add_test(tc_core, test_round_ok514);
  tcase_add_test(tc_core, test_round_ok515);
  tcase_add_test(tc_core, test_round_ok516);
  tcase_add_test(tc_core, test_round_ok517);
  tcase_add_test(tc_core, test_round_ok518);
  tcase_add_test(tc_core, test_round_ok519);
  tcase_add_test(tc_core, test_round_ok520);
  tcase_add_test(tc_core, test_round_ok521);
  tcase_add_test(tc_core, test_round_ok522);
  tcase_add_test(tc_core, test_round_ok523);
  tcase_add_test(tc_core, test_round_ok524);
  tcase_add_test(tc_core, test_round_ok525);
  tcase_add_test(tc_core, test_round_ok526);
  tcase_add_test(tc_core, test_round_ok527);
  tcase_add_test(tc_core, test_round_ok528);
  tcase_add_test(tc_core, test_round_ok529);
  tcase_add_test(tc_core, test_round_ok530);
  tcase_add_test(tc_core, test_round_ok531);
  tcase_add_test(tc_core, test_round_ok532);
  tcase_add_test(tc_core, test_round_ok533);
  tcase_add_test(tc_core, test_round_ok534);
  tcase_add_test(tc_core, test_round_ok535);
  tcase_add_test(tc_core, test_round_ok536);
  tcase_add_test(tc_core, test_round_ok537);
  tcase_add_test(tc_core, test_round_ok538);
  tcase_add_test(tc_core, test_round_ok539);
  tcase_add_test(tc_core, test_round_ok540);
  tcase_add_test(tc_core, test_round_ok541);
  tcase_add_test(tc_core, test_round_ok542);
  tcase_add_test(tc_core, test_round_ok543);
  tcase_add_test(tc_core, test_round_ok544);
  tcase_add_test(tc_core, test_round_ok545);
  tcase_add_test(tc_core, test_round_ok546);
  tcase_add_test(tc_core, test_round_ok547);
  tcase_add_test(tc_core, test_round_ok548);
  tcase_add_test(tc_core, test_round_ok549);
  tcase_add_test(tc_core, test_round_ok550);
  tcase_add_test(tc_core, test_round_ok551);
  tcase_add_test(tc_core, test_round_ok552);
  tcase_add_test(tc_core, test_round_ok553);
  tcase_add_test(tc_core, test_round_ok554);
  tcase_add_test(tc_core, test_round_ok555);
  tcase_add_test(tc_core, test_round_ok556);
  tcase_add_test(tc_core, test_round_ok557);
  tcase_add_test(tc_core, test_round_ok558);
  tcase_add_test(tc_core, test_round_ok559);
  tcase_add_test(tc_core, test_round_ok560);
  tcase_add_test(tc_core, test_round_ok561);
  tcase_add_test(tc_core, test_round_ok562);
  tcase_add_test(tc_core, test_round_ok563);
  tcase_add_test(tc_core, test_round_ok564);
  tcase_add_test(tc_core, test_round_ok565);
  tcase_add_test(tc_core, test_round_ok566);
  tcase_add_test(tc_core, test_round_ok567);
  tcase_add_test(tc_core, test_round_ok568);
  tcase_add_test(tc_core, test_round_ok569);
  tcase_add_test(tc_core, test_round_ok570);
  tcase_add_test(tc_core, test_round_ok571);
  tcase_add_test(tc_core, test_round_ok572);
  tcase_add_test(tc_core, test_round_ok573);
  tcase_add_test(tc_core, test_round_ok574);
  tcase_add_test(tc_core, test_round_ok575);
  tcase_add_test(tc_core, test_round_ok576);
  tcase_add_test(tc_core, test_round_ok577);
  tcase_add_test(tc_core, test_round_ok578);
  tcase_add_test(tc_core, test_round_ok579);
  tcase_add_test(tc_core, test_round_ok580);
  tcase_add_test(tc_core, test_round_ok581);
  tcase_add_test(tc_core, test_round_ok582);
  tcase_add_test(tc_core, test_round_ok583);
  tcase_add_test(tc_core, test_round_ok584);
  tcase_add_test(tc_core, test_round_ok585);
  tcase_add_test(tc_core, test_round_ok586);
  tcase_add_test(tc_core, test_round_ok587);
  tcase_add_test(tc_core, test_round_ok588);
  tcase_add_test(tc_core, test_round_ok589);
  tcase_add_test(tc_core, test_round_ok590);
  tcase_add_test(tc_core, test_round_ok591);
  tcase_add_test(tc_core, test_round_ok592);
  tcase_add_test(tc_core, test_round_ok593);
  tcase_add_test(tc_core, test_round_ok594);
  tcase_add_test(tc_core, test_round_ok595);
  tcase_add_test(tc_core, test_round_ok596);
  tcase_add_test(tc_core, test_round_ok597);
  tcase_add_test(tc_core, test_round_ok598);
  tcase_add_test(tc_core, test_round_ok599);
  tcase_add_test(tc_core, test_round_ok600);
  tcase_add_test(tc_core, test_round_ok601);
  tcase_add_test(tc_core, test_round_ok602);
  tcase_add_test(tc_core, test_round_ok603);
  tcase_add_test(tc_core, test_round_ok604);
  tcase_add_test(tc_core, test_round_ok605);
  tcase_add_test(tc_core, test_round_ok606);
  tcase_add_test(tc_core, test_round_ok607);
  tcase_add_test(tc_core, test_round_ok608);
  tcase_add_test(tc_core, test_round_ok609);
  tcase_add_test(tc_core, test_round_ok610);
  tcase_add_test(tc_core, test_round_ok611);
  tcase_add_test(tc_core, test_round_ok612);
  tcase_add_test(tc_core, test_round_ok613);
  tcase_add_test(tc_core, test_round_ok614);
  tcase_add_test(tc_core, test_round_ok615);
  tcase_add_test(tc_core, test_round_ok616);
  tcase_add_test(tc_core, test_round_ok617);
  tcase_add_test(tc_core, test_round_ok618);
  tcase_add_test(tc_core, test_round_ok619);
  tcase_add_test(tc_core, test_round_ok620);
  tcase_add_test(tc_core, test_round_ok621);
  tcase_add_test(tc_core, test_round_ok622);
  tcase_add_test(tc_core, test_round_ok623);
  tcase_add_test(tc_core, test_round_ok624);
  tcase_add_test(tc_core, test_round_ok625);
  tcase_add_test(tc_core, test_round_ok626);
  tcase_add_test(tc_core, test_round_ok627);
  tcase_add_test(tc_core, test_round_ok628);
  tcase_add_test(tc_core, test_round_ok629);
  tcase_add_test(tc_core, test_round_ok630);
  tcase_add_test(tc_core, test_round_ok631);
  tcase_add_test(tc_core, test_round_ok632);
  tcase_add_test(tc_core, test_round_ok633);
  tcase_add_test(tc_core, test_round_ok634);
  tcase_add_test(tc_core, test_round_ok635);
  tcase_add_test(tc_core, test_round_ok636);
  tcase_add_test(tc_core, test_round_ok637);
  tcase_add_test(tc_core, test_round_ok638);
  tcase_add_test(tc_core, test_round_ok639);
  tcase_add_test(tc_core, test_round_ok640);
  tcase_add_test(tc_core, test_round_ok641);
  tcase_add_test(tc_core, test_round_ok642);
  tcase_add_test(tc_core, test_round_ok643);
  tcase_add_test(tc_core, test_round_ok644);
  tcase_add_test(tc_core, test_round_ok645);
  tcase_add_test(tc_core, test_round_ok646);
  tcase_add_test(tc_core, test_round_ok647);
  tcase_add_test(tc_core, test_round_ok648);
  tcase_add_test(tc_core, test_round_ok649);
  tcase_add_test(tc_core, test_round_ok650);
  tcase_add_test(tc_core, test_round_ok651);
  tcase_add_test(tc_core, test_round_ok652);
  tcase_add_test(tc_core, test_round_ok653);
  tcase_add_test(tc_core, test_round_ok654);
  tcase_add_test(tc_core, test_round_ok655);
  tcase_add_test(tc_core, test_round_ok656);
  tcase_add_test(tc_core, test_round_ok657);
  tcase_add_test(tc_core, test_round_ok658);
  tcase_add_test(tc_core, test_round_ok659);
  tcase_add_test(tc_core, test_round_ok660);
  tcase_add_test(tc_core, test_round_ok661);
  tcase_add_test(tc_core, test_round_ok662);
  tcase_add_test(tc_core, test_round_ok663);
  tcase_add_test(tc_core, test_round_ok664);
  tcase_add_test(tc_core, test_round_ok665);
  tcase_add_test(tc_core, test_round_ok666);
  tcase_add_test(tc_core, test_round_ok667);
  tcase_add_test(tc_core, test_round_ok668);
  tcase_add_test(tc_core, test_round_ok669);
  tcase_add_test(tc_core, test_round_ok670);
  tcase_add_test(tc_core, test_round_ok671);
  tcase_add_test(tc_core, test_round_ok672);
  tcase_add_test(tc_core, test_round_ok673);
  tcase_add_test(tc_core, test_round_ok674);
  tcase_add_test(tc_core, test_round_ok675);
  tcase_add_test(tc_core, test_round_ok676);
  tcase_add_test(tc_core, test_round_ok677);
  tcase_add_test(tc_core, test_round_ok678);
  tcase_add_test(tc_core, test_round_ok679);
  tcase_add_test(tc_core, test_round_ok680);
  tcase_add_test(tc_core, test_round_ok681);
  tcase_add_test(tc_core, test_round_ok682);
  tcase_add_test(tc_core, test_round_ok683);
  tcase_add_test(tc_core, test_round_ok684);
  tcase_add_test(tc_core, test_round_ok685);
  tcase_add_test(tc_core, test_round_ok686);
  tcase_add_test(tc_core, test_round_ok687);
  tcase_add_test(tc_core, test_round_ok688);
  tcase_add_test(tc_core, test_round_ok689);
  tcase_add_test(tc_core, test_round_ok690);
  tcase_add_test(tc_core, test_round_ok691);
  tcase_add_test(tc_core, test_round_ok692);
  tcase_add_test(tc_core, test_round_ok693);
  tcase_add_test(tc_core, test_round_ok694);
  tcase_add_test(tc_core, test_round_ok695);
  tcase_add_test(tc_core, test_round_ok696);
  tcase_add_test(tc_core, test_round_ok697);
  tcase_add_test(tc_core, test_round_ok698);
  tcase_add_test(tc_core, test_round_ok699);
  tcase_add_test(tc_core, test_round_ok700);
  tcase_add_test(tc_core, test_round_ok701);
  tcase_add_test(tc_core, test_round_ok702);
  tcase_add_test(tc_core, test_round_ok703);
  tcase_add_test(tc_core, test_round_ok704);
  tcase_add_test(tc_core, test_round_ok705);
  tcase_add_test(tc_core, test_round_ok706);
  tcase_add_test(tc_core, test_round_ok707);
  tcase_add_test(tc_core, test_round_ok708);
  tcase_add_test(tc_core, test_round_ok709);
  tcase_add_test(tc_core, test_round_ok710);
  tcase_add_test(tc_core, test_round_ok711);
  tcase_add_test(tc_core, test_round_ok712);
  tcase_add_test(tc_core, test_round_ok713);
  tcase_add_test(tc_core, test_round_ok714);
  tcase_add_test(tc_core, test_round_ok715);
  tcase_add_test(tc_core, test_round_ok716);
  tcase_add_test(tc_core, test_round_ok717);
  tcase_add_test(tc_core, test_round_ok718);
  tcase_add_test(tc_core, test_round_ok719);
  tcase_add_test(tc_core, test_round_ok720);
  tcase_add_test(tc_core, test_round_ok721);
  tcase_add_test(tc_core, test_round_ok722);
  tcase_add_test(tc_core, test_round_ok723);
  tcase_add_test(tc_core, test_round_ok724);
  tcase_add_test(tc_core, test_round_ok725);
  tcase_add_test(tc_core, test_round_ok726);
  tcase_add_test(tc_core, test_round_ok727);
  tcase_add_test(tc_core, test_round_ok728);
  tcase_add_test(tc_core, test_round_ok729);
  tcase_add_test(tc_core, test_round_ok730);
  tcase_add_test(tc_core, test_round_ok731);
  tcase_add_test(tc_core, test_round_ok732);
  tcase_add_test(tc_core, test_round_ok733);
  tcase_add_test(tc_core, test_round_ok734);
  tcase_add_test(tc_core, test_round_ok735);
  tcase_add_test(tc_core, test_round_ok736);
  tcase_add_test(tc_core, test_round_ok737);
  tcase_add_test(tc_core, test_round_ok738);
  tcase_add_test(tc_core, test_round_ok739);
  tcase_add_test(tc_core, test_round_ok740);
  tcase_add_test(tc_core, test_round_ok741);
  tcase_add_test(tc_core, test_round_ok742);
  tcase_add_test(tc_core, test_round_ok743);
  tcase_add_test(tc_core, test_round_ok744);
  tcase_add_test(tc_core, test_round_ok745);
  tcase_add_test(tc_core, test_round_ok746);
  tcase_add_test(tc_core, test_round_ok747);
  tcase_add_test(tc_core, test_round_ok748);
  tcase_add_test(tc_core, test_round_ok749);
  tcase_add_test(tc_core, test_round_ok750);
  tcase_add_test(tc_core, test_round_ok751);
  tcase_add_test(tc_core, test_round_ok752);
  tcase_add_test(tc_core, test_round_ok753);
  tcase_add_test(tc_core, test_round_ok754);
  tcase_add_test(tc_core, test_round_ok755);
  tcase_add_test(tc_core, test_round_ok756);
  tcase_add_test(tc_core, test_round_ok757);
  tcase_add_test(tc_core, test_round_ok758);
  tcase_add_test(tc_core, test_round_ok759);
  tcase_add_test(tc_core, test_round_ok760);
  tcase_add_test(tc_core, test_round_ok761);
  tcase_add_test(tc_core, test_round_ok762);
  tcase_add_test(tc_core, test_round_ok763);
  tcase_add_test(tc_core, test_round_ok764);
  tcase_add_test(tc_core, test_round_ok765);
  tcase_add_test(tc_core, test_round_ok766);
  tcase_add_test(tc_core, test_round_ok767);
  tcase_add_test(tc_core, test_round_ok768);
  tcase_add_test(tc_core, test_round_ok769);
  tcase_add_test(tc_core, test_round_ok770);
  tcase_add_test(tc_core, test_round_ok771);
  tcase_add_test(tc_core, test_round_ok772);
  tcase_add_test(tc_core, test_round_ok773);
  tcase_add_test(tc_core, test_round_ok774);
  tcase_add_test(tc_core, test_round_ok775);
  tcase_add_test(tc_core, test_round_ok776);
  tcase_add_test(tc_core, test_round_ok777);
  tcase_add_test(tc_core, test_round_ok778);
  tcase_add_test(tc_core, test_round_ok779);
  tcase_add_test(tc_core, test_round_ok780);
  tcase_add_test(tc_core, test_round_ok781);
  tcase_add_test(tc_core, test_round_ok782);
  tcase_add_test(tc_core, test_round_ok783);
  tcase_add_test(tc_core, test_round_ok784);
  tcase_add_test(tc_core, test_round_ok785);
  tcase_add_test(tc_core, test_round_ok786);
  tcase_add_test(tc_core, test_round_ok787);
  tcase_add_test(tc_core, test_round_ok788);
  tcase_add_test(tc_core, test_round_ok789);
  tcase_add_test(tc_core, test_round_ok790);
  tcase_add_test(tc_core, test_round_ok791);
  tcase_add_test(tc_core, test_round_ok792);
  tcase_add_test(tc_core, test_round_ok793);
  tcase_add_test(tc_core, test_round_ok794);
  tcase_add_test(tc_core, test_round_ok795);
  tcase_add_test(tc_core, test_round_ok796);
  tcase_add_test(tc_core, test_round_ok797);
  tcase_add_test(tc_core, test_round_ok798);
  tcase_add_test(tc_core, test_round_ok799);
  tcase_add_test(tc_core, test_round_ok800);

  suite_add_tcase(s, tc_core);
  return s;
}

Suite *round_suite3(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("round_suite3");
  tc_core = tcase_create("Core");
  tcase_add_test(tc_core, test_round_ok801);
  tcase_add_test(tc_core, test_round_ok802);
  tcase_add_test(tc_core, test_round_ok803);
  tcase_add_test(tc_core, test_round_ok804);
  tcase_add_test(tc_core, test_round_ok805);
  tcase_add_test(tc_core, test_round_ok806);
  tcase_add_test(tc_core, test_round_ok807);
  tcase_add_test(tc_core, test_round_ok808);
  tcase_add_test(tc_core, test_round_ok809);
  tcase_add_test(tc_core, test_round_ok810);
  tcase_add_test(tc_core, test_round_ok811);
  tcase_add_test(tc_core, test_round_ok812);
  tcase_add_test(tc_core, test_round_ok813);
  tcase_add_test(tc_core, test_round_ok814);
  tcase_add_test(tc_core, test_round_ok815);
  tcase_add_test(tc_core, test_round_ok816);
  tcase_add_test(tc_core, test_round_ok817);
  tcase_add_test(tc_core, test_round_ok818);
  tcase_add_test(tc_core, test_round_ok819);
  tcase_add_test(tc_core, test_round_ok820);
  tcase_add_test(tc_core, test_round_ok821);
  tcase_add_test(tc_core, test_round_ok822);
  tcase_add_test(tc_core, test_round_ok823);
  tcase_add_test(tc_core, test_round_ok824);
  tcase_add_test(tc_core, test_round_ok825);
  tcase_add_test(tc_core, test_round_ok826);
  tcase_add_test(tc_core, test_round_ok827);
  tcase_add_test(tc_core, test_round_ok828);
  tcase_add_test(tc_core, test_round_ok829);
  tcase_add_test(tc_core, test_round_ok830);
  tcase_add_test(tc_core, test_round_ok831);
  tcase_add_test(tc_core, test_round_ok832);
  tcase_add_test(tc_core, test_round_ok833);
  tcase_add_test(tc_core, test_round_ok834);
  tcase_add_test(tc_core, test_round_ok835);
  tcase_add_test(tc_core, test_round_ok836);
  tcase_add_test(tc_core, test_round_ok837);
  tcase_add_test(tc_core, test_round_ok838);
  tcase_add_test(tc_core, test_round_ok839);
  tcase_add_test(tc_core, test_round_ok840);
  tcase_add_test(tc_core, test_round_ok841);
  tcase_add_test(tc_core, test_round_ok842);
  tcase_add_test(tc_core, test_round_ok843);
  tcase_add_test(tc_core, test_round_ok844);
  tcase_add_test(tc_core, test_round_ok845);
  tcase_add_test(tc_core, test_round_ok846);
  tcase_add_test(tc_core, test_round_ok847);
  tcase_add_test(tc_core, test_round_ok848);
  tcase_add_test(tc_core, test_round_ok849);
  tcase_add_test(tc_core, test_round_ok850);
  tcase_add_test(tc_core, test_round_ok851);
  tcase_add_test(tc_core, test_round_ok852);
  tcase_add_test(tc_core, test_round_ok853);
  tcase_add_test(tc_core, test_round_ok854);
  tcase_add_test(tc_core, test_round_ok855);
  tcase_add_test(tc_core, test_round_ok856);
  tcase_add_test(tc_core, test_round_ok857);
  tcase_add_test(tc_core, test_round_ok858);
  tcase_add_test(tc_core, test_round_ok859);
  tcase_add_test(tc_core, test_round_ok860);
  tcase_add_test(tc_core, test_round_ok861);
  tcase_add_test(tc_core, test_round_ok862);
  tcase_add_test(tc_core, test_round_ok863);
  tcase_add_test(tc_core, test_round_ok864);
  tcase_add_test(tc_core, test_round_ok865);
  tcase_add_test(tc_core, test_round_ok866);
  tcase_add_test(tc_core, test_round_ok867);
  tcase_add_test(tc_core, test_round_ok868);
  tcase_add_test(tc_core, test_round_ok869);
  tcase_add_test(tc_core, test_round_ok870);
  tcase_add_test(tc_core, test_round_ok871);
  tcase_add_test(tc_core, test_round_ok872);
  tcase_add_test(tc_core, test_round_ok873);
  tcase_add_test(tc_core, test_round_ok874);
  tcase_add_test(tc_core, test_round_ok875);
  tcase_add_test(tc_core, test_round_ok876);
  tcase_add_test(tc_core, test_round_ok877);
  tcase_add_test(tc_core, test_round_ok878);
  tcase_add_test(tc_core, test_round_ok879);
  tcase_add_test(tc_core, test_round_ok880);
  tcase_add_test(tc_core, test_round_ok881);
  tcase_add_test(tc_core, test_round_ok882);
  tcase_add_test(tc_core, test_round_ok883);
  tcase_add_test(tc_core, test_round_ok884);
  tcase_add_test(tc_core, test_round_ok885);
  tcase_add_test(tc_core, test_round_ok886);
  tcase_add_test(tc_core, test_round_ok887);
  tcase_add_test(tc_core, test_round_ok888);
  tcase_add_test(tc_core, test_round_ok889);
  tcase_add_test(tc_core, test_round_ok890);
  tcase_add_test(tc_core, test_round_ok891);
  tcase_add_test(tc_core, test_round_ok892);
  tcase_add_test(tc_core, test_round_ok893);
  tcase_add_test(tc_core, test_round_ok894);
  tcase_add_test(tc_core, test_round_ok895);
  tcase_add_test(tc_core, test_round_ok896);
  tcase_add_test(tc_core, test_round_ok897);
  tcase_add_test(tc_core, test_round_ok898);
  tcase_add_test(tc_core, test_round_ok899);
  tcase_add_test(tc_core, test_round_ok900);
  tcase_add_test(tc_core, test_round_ok901);
  tcase_add_test(tc_core, test_round_ok902);
  tcase_add_test(tc_core, test_round_ok903);
  tcase_add_test(tc_core, test_round_ok904);
  tcase_add_test(tc_core, test_round_ok905);
  tcase_add_test(tc_core, test_round_ok906);
  tcase_add_test(tc_core, test_round_ok907);
  tcase_add_test(tc_core, test_round_ok908);
  tcase_add_test(tc_core, test_round_ok909);
  tcase_add_test(tc_core, test_round_ok910);
  tcase_add_test(tc_core, test_round_ok911);
  tcase_add_test(tc_core, test_round_ok912);
  tcase_add_test(tc_core, test_round_ok913);
  tcase_add_test(tc_core, test_round_ok914);
  tcase_add_test(tc_core, test_round_ok915);
  tcase_add_test(tc_core, test_round_ok916);
  tcase_add_test(tc_core, test_round_ok917);
  tcase_add_test(tc_core, test_round_ok918);
  tcase_add_test(tc_core, test_round_ok919);
  tcase_add_test(tc_core, test_round_ok920);
  tcase_add_test(tc_core, test_round_ok921);
  tcase_add_test(tc_core, test_round_ok922);
  tcase_add_test(tc_core, test_round_ok923);
  tcase_add_test(tc_core, test_round_ok924);
  tcase_add_test(tc_core, test_round_ok925);
  tcase_add_test(tc_core, test_round_ok926);
  tcase_add_test(tc_core, test_round_ok927);
  tcase_add_test(tc_core, test_round_ok928);
  tcase_add_test(tc_core, test_round_ok929);
  tcase_add_test(tc_core, test_round_ok930);
  tcase_add_test(tc_core, test_round_ok931);
  tcase_add_test(tc_core, test_round_ok932);
  tcase_add_test(tc_core, test_round_ok933);
  tcase_add_test(tc_core, test_round_ok934);
  tcase_add_test(tc_core, test_round_ok935);
  tcase_add_test(tc_core, test_round_ok936);
  tcase_add_test(tc_core, test_round_ok937);
  tcase_add_test(tc_core, test_round_ok938);
  tcase_add_test(tc_core, test_round_ok939);
  tcase_add_test(tc_core, test_round_ok940);
  tcase_add_test(tc_core, test_round_ok941);
  tcase_add_test(tc_core, test_round_ok942);
  tcase_add_test(tc_core, test_round_ok943);
  tcase_add_test(tc_core, test_round_ok944);
  tcase_add_test(tc_core, test_round_ok945);
  tcase_add_test(tc_core, test_round_ok946);
  tcase_add_test(tc_core, test_round_ok947);
  tcase_add_test(tc_core, test_round_ok948);
  tcase_add_test(tc_core, test_round_ok949);
  tcase_add_test(tc_core, test_round_ok950);
  tcase_add_test(tc_core, test_round_ok951);
  tcase_add_test(tc_core, test_round_ok952);
  tcase_add_test(tc_core, test_round_ok953);
  tcase_add_test(tc_core, test_round_ok954);
  tcase_add_test(tc_core, test_round_ok955);
  tcase_add_test(tc_core, test_round_ok956);
  tcase_add_test(tc_core, test_round_ok957);
  tcase_add_test(tc_core, test_round_ok958);
  tcase_add_test(tc_core, test_round_ok959);
  tcase_add_test(tc_core, test_round_ok960);
  tcase_add_test(tc_core, test_round_ok961);
  tcase_add_test(tc_core, test_round_ok962);
  tcase_add_test(tc_core, test_round_ok963);
  tcase_add_test(tc_core, test_round_ok964);
  tcase_add_test(tc_core, test_round_ok965);
  tcase_add_test(tc_core, test_round_ok966);
  tcase_add_test(tc_core, test_round_ok967);
  tcase_add_test(tc_core, test_round_ok968);
  tcase_add_test(tc_core, test_round_ok969);
  tcase_add_test(tc_core, test_round_ok970);
  tcase_add_test(tc_core, test_round_ok971);
  tcase_add_test(tc_core, test_round_ok972);
  tcase_add_test(tc_core, test_round_ok973);
  tcase_add_test(tc_core, test_round_ok974);
  tcase_add_test(tc_core, test_round_ok975);
  tcase_add_test(tc_core, test_round_ok976);
  tcase_add_test(tc_core, test_round_ok977);
  tcase_add_test(tc_core, test_round_ok978);
  tcase_add_test(tc_core, test_round_ok979);
  tcase_add_test(tc_core, test_round_ok980);
  tcase_add_test(tc_core, test_round_ok981);
  tcase_add_test(tc_core, test_round_ok982);
  tcase_add_test(tc_core, test_round_ok983);
  tcase_add_test(tc_core, test_round_ok984);
  tcase_add_test(tc_core, test_round_ok985);
  tcase_add_test(tc_core, test_round_ok986);
  tcase_add_test(tc_core, test_round_ok987);
  tcase_add_test(tc_core, test_round_ok988);
  tcase_add_test(tc_core, test_round_ok989);
  tcase_add_test(tc_core, test_round_ok990);
  tcase_add_test(tc_core, test_round_ok991);
  tcase_add_test(tc_core, test_round_ok992);
  tcase_add_test(tc_core, test_round_ok993);
  tcase_add_test(tc_core, test_round_ok994);
  tcase_add_test(tc_core, test_round_ok995);
  tcase_add_test(tc_core, test_round_ok996);
  tcase_add_test(tc_core, test_round_ok997);
  tcase_add_test(tc_core, test_round_ok998);
  tcase_add_test(tc_core, test_round_ok999);
  tcase_add_test(tc_core, test_round_ok1000);
  tcase_add_test(tc_core, test_round_ok1001);
  tcase_add_test(tc_core, test_round_ok1002);
  tcase_add_test(tc_core, test_round_ok1003);
  tcase_add_test(tc_core, test_round_ok1004);
  tcase_add_test(tc_core, test_round_ok1005);
  tcase_add_test(tc_core, test_round_ok1006);
  tcase_add_test(tc_core, test_round_ok1007);
  tcase_add_test(tc_core, test_round_ok1008);
  tcase_add_test(tc_core, test_round_ok1009);
  tcase_add_test(tc_core, test_round_ok1010);
  tcase_add_test(tc_core, test_round_ok1011);
  tcase_add_test(tc_core, test_round_ok1012);
  tcase_add_test(tc_core, test_round_ok1013);
  tcase_add_test(tc_core, test_round_ok1014);
  tcase_add_test(tc_core, test_round_ok1015);
  tcase_add_test(tc_core, test_round_ok1016);
  tcase_add_test(tc_core, test_round_ok1017);
  tcase_add_test(tc_core, test_round_ok1018);
  tcase_add_test(tc_core, test_round_ok1019);
  tcase_add_test(tc_core, test_round_ok1020);

  suite_add_tcase(s, tc_core);
  return s;
}

Suite *round_suite0(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("round_suite0");
  tc_core = tcase_create("Core");
  tcase_add_test(tc_core, test_round_fail1);
  tcase_add_test(tc_core, test_round_fail2);
  tcase_add_test(tc_core, test_round_fail3);
  tcase_add_test(tc_core, test_round_fail4);
  tcase_add_test(tc_core, test_round_fail5);
  tcase_add_test(tc_core, test_round_fail6);
  tcase_add_test(tc_core, test_round_fail7);
  tcase_add_test(tc_core, test_round_fail8);
  tcase_add_test(tc_core, test_round_fail9);

  suite_add_tcase(s, tc_core);
  return s;
}

void test_round(my_decimal decimal, my_decimal decimal_check) {
  my_decimal result;

  int code = my_round(decimal, &result);
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
  ck_assert_int_eq(my_is_equal(result, decimal_check), 1);
  ck_assert_int_eq(sign_check, sign_result);
}
