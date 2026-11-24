#include <stdio.h>
#include <stdlib.h>

#include "./../../my_decimal.h"
#include "./../test.h"

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * * * * * * * * * * * * * * Тесты на некорректные данные (ручные)
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * * * * * * * * * * * * * */

START_TEST(test_negate_fail1) {
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x140000}};

  int code = my_negate(decimal, NULL);

  ck_assert_int_eq(code, TEST_OTHER_ERROR);
}

START_TEST(test_negate_fail2) {
  my_decimal decimal = {{0, 0, 0, 1000000000}};
  my_decimal result;

  int code = my_negate(decimal, &result);

  ck_assert_int_eq(code, TEST_OTHER_ERROR);
}
END_TEST

START_TEST(test_negate_fail3) {
  my_decimal decimal = {{-1, 0, 0, 0x1D0000}};
  my_decimal result;

  int code = my_negate(decimal, &result);

  ck_assert_int_eq(code, TEST_OTHER_ERROR);
}
END_TEST

START_TEST(test_negate_fail4) {
  my_decimal decimal = {{0, 0, 0, 0x1D0000}};
  my_decimal result;

  int code = my_negate(decimal, &result);

  ck_assert_int_eq(code, TEST_OTHER_ERROR);
}
END_TEST

START_TEST(test_negate_fail5) {
  my_decimal decimal = {{-1, 0, 0, 0x1C0001}};
  my_decimal result;

  int code = my_negate(decimal, &result);

  ck_assert_int_eq(code, TEST_OTHER_ERROR);
}
END_TEST

START_TEST(test_negate_fail6) {
  my_decimal decimal = {{-1, 0, 0, 0x1C8000}};
  my_decimal result;

  int code = my_negate(decimal, &result);

  ck_assert_int_eq(code, TEST_OTHER_ERROR);
}
END_TEST

START_TEST(test_negate_fail7) {
  my_decimal decimal = {{-1, 0, 0, 0x11C0000}};
  my_decimal result;

  int code = my_negate(decimal, &result);

  ck_assert_int_eq(code, TEST_OTHER_ERROR);
}
END_TEST

START_TEST(test_negate_fail8) {
  my_decimal decimal = {{-1, 0, 0, 0x401C0000}};
  my_decimal result;

  int code = my_negate(decimal, &result);

  ck_assert_int_eq(code, TEST_OTHER_ERROR);
}
END_TEST

START_TEST(test_negate_fail9) {
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF}};
  my_decimal result;

  int code = my_negate(decimal, &result);

  ck_assert_int_eq(code, TEST_OTHER_ERROR);
}
END_TEST

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * * * * * * * * * * * * * * * Tests for correct data (automatic)
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * * * * * * * * * * * * * * */

START_TEST(test_negate_ok1) {
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};

  my_decimal decimal_check = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok2) {
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};

  my_decimal decimal_check = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok3) {
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};

  my_decimal decimal_check = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80010000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok4) {
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80010000}};

  my_decimal decimal_check = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok5) {
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x20000}};

  my_decimal decimal_check = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80020000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok6) {
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80020000}};

  my_decimal decimal_check = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x20000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok7) {
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x30000}};

  my_decimal decimal_check = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80030000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok8) {
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80030000}};

  my_decimal decimal_check = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x30000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok9) {
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x40000}};

  my_decimal decimal_check = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80040000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok10) {
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80040000}};

  my_decimal decimal_check = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x40000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok11) {
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x50000}};

  my_decimal decimal_check = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80050000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok12) {
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80050000}};

  my_decimal decimal_check = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x50000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok13) {
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x60000}};

  my_decimal decimal_check = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80060000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok14) {
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80060000}};

  my_decimal decimal_check = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x60000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok15) {
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x70000}};

  my_decimal decimal_check = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80070000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok16) {
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80070000}};

  my_decimal decimal_check = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x70000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok17) {
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000}};

  my_decimal decimal_check = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80080000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok18) {
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80080000}};

  my_decimal decimal_check = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok19) {
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x90000}};

  my_decimal decimal_check = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80090000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok20) {
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80090000}};

  my_decimal decimal_check = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x90000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok21) {
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xA0000}};

  my_decimal decimal_check = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x800A0000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok22) {
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x800A0000}};

  my_decimal decimal_check = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xA0000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok23) {
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xB0000}};

  my_decimal decimal_check = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x800B0000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok24) {
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x800B0000}};

  my_decimal decimal_check = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xB0000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok25) {
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xC0000}};

  my_decimal decimal_check = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x800C0000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok26) {
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x800C0000}};

  my_decimal decimal_check = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xC0000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok27) {
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xD0000}};

  my_decimal decimal_check = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x800D0000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok28) {
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x800D0000}};

  my_decimal decimal_check = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xD0000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok29) {
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xE0000}};

  my_decimal decimal_check = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x800E0000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok30) {
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x800E0000}};

  my_decimal decimal_check = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xE0000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok31) {
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xF0000}};

  my_decimal decimal_check = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x800F0000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok32) {
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x800F0000}};

  my_decimal decimal_check = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xF0000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok33) {
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x100000}};

  my_decimal decimal_check = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80100000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok34) {
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80100000}};

  my_decimal decimal_check = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x100000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok35) {
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x110000}};

  my_decimal decimal_check = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80110000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok36) {
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80110000}};

  my_decimal decimal_check = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x110000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok37) {
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x120000}};

  my_decimal decimal_check = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80120000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok38) {
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80120000}};

  my_decimal decimal_check = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x120000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok39) {
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x130000}};

  my_decimal decimal_check = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80130000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok40) {
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80130000}};

  my_decimal decimal_check = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x130000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok41) {
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x140000}};

  my_decimal decimal_check = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80140000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok42) {
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80140000}};

  my_decimal decimal_check = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x140000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok43) {
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x150000}};

  my_decimal decimal_check = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80150000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok44) {
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80150000}};

  my_decimal decimal_check = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x150000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok45) {
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x160000}};

  my_decimal decimal_check = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80160000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok46) {
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80160000}};

  my_decimal decimal_check = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x160000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok47) {
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x170000}};

  my_decimal decimal_check = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80170000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok48) {
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80170000}};

  my_decimal decimal_check = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x170000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok49) {
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x180000}};

  my_decimal decimal_check = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80180000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok50) {
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80180000}};

  my_decimal decimal_check = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x180000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok51) {
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x190000}};

  my_decimal decimal_check = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80190000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok52) {
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80190000}};

  my_decimal decimal_check = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x190000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok53) {
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x1A0000}};

  my_decimal decimal_check = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x801A0000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok54) {
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x801A0000}};

  my_decimal decimal_check = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x1A0000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok55) {
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x1B0000}};

  my_decimal decimal_check = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x801B0000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok56) {
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x801B0000}};

  my_decimal decimal_check = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x1B0000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok57) {
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x1C0000}};

  my_decimal decimal_check = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x801C0000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok58) {
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x801C0000}};

  my_decimal decimal_check = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x1C0000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok59) {
  my_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};

  my_decimal decimal_check = {
      {0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok60) {
  my_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};

  my_decimal decimal_check = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok61) {
  my_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};

  my_decimal decimal_check = {
      {0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80010000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok62) {
  my_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80010000}};

  my_decimal decimal_check = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok63) {
  my_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x20000}};

  my_decimal decimal_check = {
      {0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80020000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok64) {
  my_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80020000}};

  my_decimal decimal_check = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x20000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok65) {
  my_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x30000}};

  my_decimal decimal_check = {
      {0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80030000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok66) {
  my_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80030000}};

  my_decimal decimal_check = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x30000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok67) {
  my_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x40000}};

  my_decimal decimal_check = {
      {0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80040000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok68) {
  my_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80040000}};

  my_decimal decimal_check = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x40000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok69) {
  my_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x50000}};

  my_decimal decimal_check = {
      {0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80050000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok70) {
  my_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80050000}};

  my_decimal decimal_check = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x50000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok71) {
  my_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x60000}};

  my_decimal decimal_check = {
      {0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80060000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok72) {
  my_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80060000}};

  my_decimal decimal_check = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x60000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok73) {
  my_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x70000}};

  my_decimal decimal_check = {
      {0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80070000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok74) {
  my_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80070000}};

  my_decimal decimal_check = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x70000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok75) {
  my_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000}};

  my_decimal decimal_check = {
      {0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80080000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok76) {
  my_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80080000}};

  my_decimal decimal_check = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok77) {
  my_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x90000}};

  my_decimal decimal_check = {
      {0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80090000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok78) {
  my_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80090000}};

  my_decimal decimal_check = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x90000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok79) {
  my_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0xA0000}};

  my_decimal decimal_check = {
      {0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x800A0000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok80) {
  my_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x800A0000}};

  my_decimal decimal_check = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0xA0000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok81) {
  my_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0xB0000}};

  my_decimal decimal_check = {
      {0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x800B0000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok82) {
  my_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x800B0000}};

  my_decimal decimal_check = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0xB0000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok83) {
  my_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0xC0000}};

  my_decimal decimal_check = {
      {0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x800C0000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok84) {
  my_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x800C0000}};

  my_decimal decimal_check = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0xC0000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok85) {
  my_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0xD0000}};

  my_decimal decimal_check = {
      {0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x800D0000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok86) {
  my_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x800D0000}};

  my_decimal decimal_check = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0xD0000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok87) {
  my_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0xE0000}};

  my_decimal decimal_check = {
      {0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x800E0000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok88) {
  my_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x800E0000}};

  my_decimal decimal_check = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0xE0000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok89) {
  my_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0xF0000}};

  my_decimal decimal_check = {
      {0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x800F0000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok90) {
  my_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x800F0000}};

  my_decimal decimal_check = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0xF0000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok91) {
  my_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x100000}};

  my_decimal decimal_check = {
      {0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80100000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok92) {
  my_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80100000}};

  my_decimal decimal_check = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x100000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok93) {
  my_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x110000}};

  my_decimal decimal_check = {
      {0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80110000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok94) {
  my_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80110000}};

  my_decimal decimal_check = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x110000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok95) {
  my_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x120000}};

  my_decimal decimal_check = {
      {0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80120000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok96) {
  my_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80120000}};

  my_decimal decimal_check = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x120000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok97) {
  my_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x130000}};

  my_decimal decimal_check = {
      {0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80130000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok98) {
  my_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80130000}};

  my_decimal decimal_check = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x130000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok99) {
  my_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x140000}};

  my_decimal decimal_check = {
      {0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80140000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok100) {
  my_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80140000}};

  my_decimal decimal_check = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x140000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok101) {
  my_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x150000}};

  my_decimal decimal_check = {
      {0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80150000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok102) {
  my_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80150000}};

  my_decimal decimal_check = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x150000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok103) {
  my_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x160000}};

  my_decimal decimal_check = {
      {0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80160000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok104) {
  my_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80160000}};

  my_decimal decimal_check = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x160000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok105) {
  my_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x170000}};

  my_decimal decimal_check = {
      {0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80170000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok106) {
  my_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80170000}};

  my_decimal decimal_check = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x170000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok107) {
  my_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x180000}};

  my_decimal decimal_check = {
      {0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80180000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok108) {
  my_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80180000}};

  my_decimal decimal_check = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x180000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok109) {
  my_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x190000}};

  my_decimal decimal_check = {
      {0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80190000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok110) {
  my_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80190000}};

  my_decimal decimal_check = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x190000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok111) {
  my_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x1A0000}};

  my_decimal decimal_check = {
      {0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x801A0000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok112) {
  my_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x801A0000}};

  my_decimal decimal_check = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x1A0000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok113) {
  my_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x1B0000}};

  my_decimal decimal_check = {
      {0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x801B0000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok114) {
  my_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x801B0000}};

  my_decimal decimal_check = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x1B0000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok115) {
  my_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x1C0000}};

  my_decimal decimal_check = {
      {0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x801C0000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok116) {
  my_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x801C0000}};

  my_decimal decimal_check = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x1C0000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok117) {
  my_decimal decimal = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x0}};

  my_decimal decimal_check = {
      {0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x80000000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok118) {
  my_decimal decimal = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x80000000}};

  my_decimal decimal_check = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x0}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok119) {
  my_decimal decimal = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x10000}};

  my_decimal decimal_check = {
      {0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x80010000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok120) {
  my_decimal decimal = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x80010000}};

  my_decimal decimal_check = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x10000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok121) {
  my_decimal decimal = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0xD0000}};

  my_decimal decimal_check = {
      {0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x800D0000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok122) {
  my_decimal decimal = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x800D0000}};

  my_decimal decimal_check = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0xD0000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok123) {
  my_decimal decimal = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x1C0000}};

  my_decimal decimal_check = {
      {0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x801C0000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok124) {
  my_decimal decimal = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x801C0000}};

  my_decimal decimal_check = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x1C0000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok125) {
  my_decimal decimal = {{0x0, 0xAAAAAAAA, 0xAAAAAAAA, 0x0}};

  my_decimal decimal_check = {{0x0, 0xAAAAAAAA, 0xAAAAAAAA, 0x80000000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok126) {
  my_decimal decimal = {{0x0, 0xAAAAAAAA, 0xAAAAAAAA, 0x80000000}};

  my_decimal decimal_check = {{0x0, 0xAAAAAAAA, 0xAAAAAAAA, 0x0}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok127) {
  my_decimal decimal = {{0x0, 0xAAAAAAAA, 0xAAAAAAAA, 0x10000}};

  my_decimal decimal_check = {{0x0, 0xAAAAAAAA, 0xAAAAAAAA, 0x80010000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok128) {
  my_decimal decimal = {{0x0, 0xAAAAAAAA, 0xAAAAAAAA, 0x80010000}};

  my_decimal decimal_check = {{0x0, 0xAAAAAAAA, 0xAAAAAAAA, 0x10000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok129) {
  my_decimal decimal = {{0x0, 0xAAAAAAAA, 0xAAAAAAAA, 0xD0000}};

  my_decimal decimal_check = {{0x0, 0xAAAAAAAA, 0xAAAAAAAA, 0x800D0000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok130) {
  my_decimal decimal = {{0x0, 0xAAAAAAAA, 0xAAAAAAAA, 0x800D0000}};

  my_decimal decimal_check = {{0x0, 0xAAAAAAAA, 0xAAAAAAAA, 0xD0000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok131) {
  my_decimal decimal = {{0x0, 0xAAAAAAAA, 0xAAAAAAAA, 0x1C0000}};

  my_decimal decimal_check = {{0x0, 0xAAAAAAAA, 0xAAAAAAAA, 0x801C0000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok132) {
  my_decimal decimal = {{0x0, 0xAAAAAAAA, 0xAAAAAAAA, 0x801C0000}};

  my_decimal decimal_check = {{0x0, 0xAAAAAAAA, 0xAAAAAAAA, 0x1C0000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok133) {
  my_decimal decimal = {{0xAAAAAAAA, 0x0, 0xAAAAAAAA, 0x0}};

  my_decimal decimal_check = {{0xAAAAAAAA, 0x0, 0xAAAAAAAA, 0x80000000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok134) {
  my_decimal decimal = {{0xAAAAAAAA, 0x0, 0xAAAAAAAA, 0x80000000}};

  my_decimal decimal_check = {{0xAAAAAAAA, 0x0, 0xAAAAAAAA, 0x0}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok135) {
  my_decimal decimal = {{0xAAAAAAAA, 0x0, 0xAAAAAAAA, 0x10000}};

  my_decimal decimal_check = {{0xAAAAAAAA, 0x0, 0xAAAAAAAA, 0x80010000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok136) {
  my_decimal decimal = {{0xAAAAAAAA, 0x0, 0xAAAAAAAA, 0x80010000}};

  my_decimal decimal_check = {{0xAAAAAAAA, 0x0, 0xAAAAAAAA, 0x10000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok137) {
  my_decimal decimal = {{0xAAAAAAAA, 0x0, 0xAAAAAAAA, 0xD0000}};

  my_decimal decimal_check = {{0xAAAAAAAA, 0x0, 0xAAAAAAAA, 0x800D0000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok138) {
  my_decimal decimal = {{0xAAAAAAAA, 0x0, 0xAAAAAAAA, 0x800D0000}};

  my_decimal decimal_check = {{0xAAAAAAAA, 0x0, 0xAAAAAAAA, 0xD0000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok139) {
  my_decimal decimal = {{0xAAAAAAAA, 0x0, 0xAAAAAAAA, 0x1C0000}};

  my_decimal decimal_check = {{0xAAAAAAAA, 0x0, 0xAAAAAAAA, 0x801C0000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok140) {
  my_decimal decimal = {{0xAAAAAAAA, 0x0, 0xAAAAAAAA, 0x801C0000}};

  my_decimal decimal_check = {{0xAAAAAAAA, 0x0, 0xAAAAAAAA, 0x1C0000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok141) {
  my_decimal decimal = {{0x0, 0x0, 0xAAAAAAAA, 0x0}};

  my_decimal decimal_check = {{0x0, 0x0, 0xAAAAAAAA, 0x80000000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok142) {
  my_decimal decimal = {{0x0, 0x0, 0xAAAAAAAA, 0x80000000}};

  my_decimal decimal_check = {{0x0, 0x0, 0xAAAAAAAA, 0x0}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok143) {
  my_decimal decimal = {{0x0, 0x0, 0xAAAAAAAA, 0x10000}};

  my_decimal decimal_check = {{0x0, 0x0, 0xAAAAAAAA, 0x80010000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok144) {
  my_decimal decimal = {{0x0, 0x0, 0xAAAAAAAA, 0x80010000}};

  my_decimal decimal_check = {{0x0, 0x0, 0xAAAAAAAA, 0x10000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok145) {
  my_decimal decimal = {{0x0, 0x0, 0xAAAAAAAA, 0xD0000}};

  my_decimal decimal_check = {{0x0, 0x0, 0xAAAAAAAA, 0x800D0000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok146) {
  my_decimal decimal = {{0x0, 0x0, 0xAAAAAAAA, 0x800D0000}};

  my_decimal decimal_check = {{0x0, 0x0, 0xAAAAAAAA, 0xD0000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok147) {
  my_decimal decimal = {{0x0, 0x0, 0xAAAAAAAA, 0x1C0000}};

  my_decimal decimal_check = {{0x0, 0x0, 0xAAAAAAAA, 0x801C0000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok148) {
  my_decimal decimal = {{0x0, 0x0, 0xAAAAAAAA, 0x801C0000}};

  my_decimal decimal_check = {{0x0, 0x0, 0xAAAAAAAA, 0x1C0000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok149) {
  my_decimal decimal = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x0}};

  my_decimal decimal_check = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x80000000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok150) {
  my_decimal decimal = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x80000000}};

  my_decimal decimal_check = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x0}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok151) {
  my_decimal decimal = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x10000}};

  my_decimal decimal_check = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x80010000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok152) {
  my_decimal decimal = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x80010000}};

  my_decimal decimal_check = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x10000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok153) {
  my_decimal decimal = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0xB0000}};

  my_decimal decimal_check = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x800B0000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok154) {
  my_decimal decimal = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x800B0000}};

  my_decimal decimal_check = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0xB0000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok155) {
  my_decimal decimal = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x130000}};

  my_decimal decimal_check = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x80130000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok156) {
  my_decimal decimal = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x80130000}};

  my_decimal decimal_check = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x130000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok157) {
  my_decimal decimal = {{0x0, 0xAAAAAAAA, 0x0, 0x0}};

  my_decimal decimal_check = {{0x0, 0xAAAAAAAA, 0x0, 0x80000000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok158) {
  my_decimal decimal = {{0x0, 0xAAAAAAAA, 0x0, 0x80000000}};

  my_decimal decimal_check = {{0x0, 0xAAAAAAAA, 0x0, 0x0}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok159) {
  my_decimal decimal = {{0x0, 0xAAAAAAAA, 0x0, 0x10000}};

  my_decimal decimal_check = {{0x0, 0xAAAAAAAA, 0x0, 0x80010000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok160) {
  my_decimal decimal = {{0x0, 0xAAAAAAAA, 0x0, 0x80010000}};

  my_decimal decimal_check = {{0x0, 0xAAAAAAAA, 0x0, 0x10000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok161) {
  my_decimal decimal = {{0x0, 0xAAAAAAAA, 0x0, 0xB0000}};

  my_decimal decimal_check = {{0x0, 0xAAAAAAAA, 0x0, 0x800B0000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok162) {
  my_decimal decimal = {{0x0, 0xAAAAAAAA, 0x0, 0x800B0000}};

  my_decimal decimal_check = {{0x0, 0xAAAAAAAA, 0x0, 0xB0000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok163) {
  my_decimal decimal = {{0x0, 0xAAAAAAAA, 0x0, 0x130000}};

  my_decimal decimal_check = {{0x0, 0xAAAAAAAA, 0x0, 0x80130000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok164) {
  my_decimal decimal = {{0x0, 0xAAAAAAAA, 0x0, 0x80130000}};

  my_decimal decimal_check = {{0x0, 0xAAAAAAAA, 0x0, 0x130000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok165) {
  my_decimal decimal = {{0xAAAAAAAA, 0x0, 0x0, 0x0}};

  my_decimal decimal_check = {{0xAAAAAAAA, 0x0, 0x0, 0x80000000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok166) {
  my_decimal decimal = {{0xAAAAAAAA, 0x0, 0x0, 0x80000000}};

  my_decimal decimal_check = {{0xAAAAAAAA, 0x0, 0x0, 0x0}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok167) {
  my_decimal decimal = {{0xAAAAAAAA, 0x0, 0x0, 0x10000}};

  my_decimal decimal_check = {{0xAAAAAAAA, 0x0, 0x0, 0x80010000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok168) {
  my_decimal decimal = {{0xAAAAAAAA, 0x0, 0x0, 0x80010000}};

  my_decimal decimal_check = {{0xAAAAAAAA, 0x0, 0x0, 0x10000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok169) {
  my_decimal decimal = {{0xAAAAAAAA, 0x0, 0x0, 0x40000}};

  my_decimal decimal_check = {{0xAAAAAAAA, 0x0, 0x0, 0x80040000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok170) {
  my_decimal decimal = {{0xAAAAAAAA, 0x0, 0x0, 0x80040000}};

  my_decimal decimal_check = {{0xAAAAAAAA, 0x0, 0x0, 0x40000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok171) {
  my_decimal decimal = {{0xAAAAAAAA, 0x0, 0x0, 0x90000}};

  my_decimal decimal_check = {{0xAAAAAAAA, 0x0, 0x0, 0x80090000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok172) {
  my_decimal decimal = {{0xAAAAAAAA, 0x0, 0x0, 0x80090000}};

  my_decimal decimal_check = {{0xAAAAAAAA, 0x0, 0x0, 0x90000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok173) {
  my_decimal decimal = {{0x55555555, 0x55555555, 0x55555555, 0x0}};

  my_decimal decimal_check = {
      {0x55555555, 0x55555555, 0x55555555, 0x80000000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok174) {
  my_decimal decimal = {{0x55555555, 0x55555555, 0x55555555, 0x80000000}};

  my_decimal decimal_check = {{0x55555555, 0x55555555, 0x55555555, 0x0}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok175) {
  my_decimal decimal = {{0x55555555, 0x55555555, 0x55555555, 0x10000}};

  my_decimal decimal_check = {
      {0x55555555, 0x55555555, 0x55555555, 0x80010000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok176) {
  my_decimal decimal = {{0x55555555, 0x55555555, 0x55555555, 0x80010000}};

  my_decimal decimal_check = {{0x55555555, 0x55555555, 0x55555555, 0x10000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok177) {
  my_decimal decimal = {{0x55555555, 0x55555555, 0x55555555, 0xD0000}};

  my_decimal decimal_check = {
      {0x55555555, 0x55555555, 0x55555555, 0x800D0000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok178) {
  my_decimal decimal = {{0x55555555, 0x55555555, 0x55555555, 0x800D0000}};

  my_decimal decimal_check = {{0x55555555, 0x55555555, 0x55555555, 0xD0000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok179) {
  my_decimal decimal = {{0x55555555, 0x55555555, 0x55555555, 0x1C0000}};

  my_decimal decimal_check = {
      {0x55555555, 0x55555555, 0x55555555, 0x801C0000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok180) {
  my_decimal decimal = {{0x55555555, 0x55555555, 0x55555555, 0x801C0000}};

  my_decimal decimal_check = {{0x55555555, 0x55555555, 0x55555555, 0x1C0000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok181) {
  my_decimal decimal = {{0x0, 0x55555555, 0x55555555, 0x0}};

  my_decimal decimal_check = {{0x0, 0x55555555, 0x55555555, 0x80000000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok182) {
  my_decimal decimal = {{0x0, 0x55555555, 0x55555555, 0x80000000}};

  my_decimal decimal_check = {{0x0, 0x55555555, 0x55555555, 0x0}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok183) {
  my_decimal decimal = {{0x0, 0x55555555, 0x55555555, 0x10000}};

  my_decimal decimal_check = {{0x0, 0x55555555, 0x55555555, 0x80010000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok184) {
  my_decimal decimal = {{0x0, 0x55555555, 0x55555555, 0x80010000}};

  my_decimal decimal_check = {{0x0, 0x55555555, 0x55555555, 0x10000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok185) {
  my_decimal decimal = {{0x0, 0x55555555, 0x55555555, 0xD0000}};

  my_decimal decimal_check = {{0x0, 0x55555555, 0x55555555, 0x800D0000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok186) {
  my_decimal decimal = {{0x0, 0x55555555, 0x55555555, 0x800D0000}};

  my_decimal decimal_check = {{0x0, 0x55555555, 0x55555555, 0xD0000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok187) {
  my_decimal decimal = {{0x0, 0x55555555, 0x55555555, 0x1C0000}};

  my_decimal decimal_check = {{0x0, 0x55555555, 0x55555555, 0x801C0000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok188) {
  my_decimal decimal = {{0x0, 0x55555555, 0x55555555, 0x801C0000}};

  my_decimal decimal_check = {{0x0, 0x55555555, 0x55555555, 0x1C0000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok189) {
  my_decimal decimal = {{0x55555555, 0x0, 0x55555555, 0x0}};

  my_decimal decimal_check = {{0x55555555, 0x0, 0x55555555, 0x80000000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok190) {
  my_decimal decimal = {{0x55555555, 0x0, 0x55555555, 0x80000000}};

  my_decimal decimal_check = {{0x55555555, 0x0, 0x55555555, 0x0}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok191) {
  my_decimal decimal = {{0x55555555, 0x0, 0x55555555, 0x10000}};

  my_decimal decimal_check = {{0x55555555, 0x0, 0x55555555, 0x80010000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok192) {
  my_decimal decimal = {{0x55555555, 0x0, 0x55555555, 0x80010000}};

  my_decimal decimal_check = {{0x55555555, 0x0, 0x55555555, 0x10000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok193) {
  my_decimal decimal = {{0x55555555, 0x0, 0x55555555, 0xD0000}};

  my_decimal decimal_check = {{0x55555555, 0x0, 0x55555555, 0x800D0000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok194) {
  my_decimal decimal = {{0x55555555, 0x0, 0x55555555, 0x800D0000}};

  my_decimal decimal_check = {{0x55555555, 0x0, 0x55555555, 0xD0000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok195) {
  my_decimal decimal = {{0x55555555, 0x0, 0x55555555, 0x1C0000}};

  my_decimal decimal_check = {{0x55555555, 0x0, 0x55555555, 0x801C0000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok196) {
  my_decimal decimal = {{0x55555555, 0x0, 0x55555555, 0x801C0000}};

  my_decimal decimal_check = {{0x55555555, 0x0, 0x55555555, 0x1C0000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok197) {
  my_decimal decimal = {{0x0, 0x0, 0x55555555, 0x0}};

  my_decimal decimal_check = {{0x0, 0x0, 0x55555555, 0x80000000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok198) {
  my_decimal decimal = {{0x0, 0x0, 0x55555555, 0x80000000}};

  my_decimal decimal_check = {{0x0, 0x0, 0x55555555, 0x0}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok199) {
  my_decimal decimal = {{0x0, 0x0, 0x55555555, 0x10000}};

  my_decimal decimal_check = {{0x0, 0x0, 0x55555555, 0x80010000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok200) {
  my_decimal decimal = {{0x0, 0x0, 0x55555555, 0x80010000}};

  my_decimal decimal_check = {{0x0, 0x0, 0x55555555, 0x10000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok201) {
  my_decimal decimal = {{0x0, 0x0, 0x55555555, 0xD0000}};

  my_decimal decimal_check = {{0x0, 0x0, 0x55555555, 0x800D0000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok202) {
  my_decimal decimal = {{0x0, 0x0, 0x55555555, 0x800D0000}};

  my_decimal decimal_check = {{0x0, 0x0, 0x55555555, 0xD0000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok203) {
  my_decimal decimal = {{0x0, 0x0, 0x55555555, 0x1C0000}};

  my_decimal decimal_check = {{0x0, 0x0, 0x55555555, 0x801C0000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok204) {
  my_decimal decimal = {{0x0, 0x0, 0x55555555, 0x801C0000}};

  my_decimal decimal_check = {{0x0, 0x0, 0x55555555, 0x1C0000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok205) {
  my_decimal decimal = {{0x55555555, 0x55555555, 0x0, 0x0}};

  my_decimal decimal_check = {{0x55555555, 0x55555555, 0x0, 0x80000000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok206) {
  my_decimal decimal = {{0x55555555, 0x55555555, 0x0, 0x80000000}};

  my_decimal decimal_check = {{0x55555555, 0x55555555, 0x0, 0x0}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok207) {
  my_decimal decimal = {{0x55555555, 0x55555555, 0x0, 0x10000}};

  my_decimal decimal_check = {{0x55555555, 0x55555555, 0x0, 0x80010000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok208) {
  my_decimal decimal = {{0x55555555, 0x55555555, 0x0, 0x80010000}};

  my_decimal decimal_check = {{0x55555555, 0x55555555, 0x0, 0x10000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok209) {
  my_decimal decimal = {{0x55555555, 0x55555555, 0x0, 0xC0000}};

  my_decimal decimal_check = {{0x55555555, 0x55555555, 0x0, 0x800C0000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok210) {
  my_decimal decimal = {{0x55555555, 0x55555555, 0x0, 0x800C0000}};

  my_decimal decimal_check = {{0x55555555, 0x55555555, 0x0, 0xC0000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok211) {
  my_decimal decimal = {{0x55555555, 0x55555555, 0x0, 0x120000}};

  my_decimal decimal_check = {{0x55555555, 0x55555555, 0x0, 0x80120000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok212) {
  my_decimal decimal = {{0x55555555, 0x55555555, 0x0, 0x80120000}};

  my_decimal decimal_check = {{0x55555555, 0x55555555, 0x0, 0x120000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok213) {
  my_decimal decimal = {{0x0, 0x55555555, 0x0, 0x0}};

  my_decimal decimal_check = {{0x0, 0x55555555, 0x0, 0x80000000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok214) {
  my_decimal decimal = {{0x0, 0x55555555, 0x0, 0x80000000}};

  my_decimal decimal_check = {{0x0, 0x55555555, 0x0, 0x0}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok215) {
  my_decimal decimal = {{0x0, 0x55555555, 0x0, 0x10000}};

  my_decimal decimal_check = {{0x0, 0x55555555, 0x0, 0x80010000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok216) {
  my_decimal decimal = {{0x0, 0x55555555, 0x0, 0x80010000}};

  my_decimal decimal_check = {{0x0, 0x55555555, 0x0, 0x10000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok217) {
  my_decimal decimal = {{0x0, 0x55555555, 0x0, 0xC0000}};

  my_decimal decimal_check = {{0x0, 0x55555555, 0x0, 0x800C0000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok218) {
  my_decimal decimal = {{0x0, 0x55555555, 0x0, 0x800C0000}};

  my_decimal decimal_check = {{0x0, 0x55555555, 0x0, 0xC0000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok219) {
  my_decimal decimal = {{0x0, 0x55555555, 0x0, 0x120000}};

  my_decimal decimal_check = {{0x0, 0x55555555, 0x0, 0x80120000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok220) {
  my_decimal decimal = {{0x0, 0x55555555, 0x0, 0x80120000}};

  my_decimal decimal_check = {{0x0, 0x55555555, 0x0, 0x120000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok221) {
  my_decimal decimal = {{0x55555555, 0x0, 0x0, 0x0}};

  my_decimal decimal_check = {{0x55555555, 0x0, 0x0, 0x80000000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok222) {
  my_decimal decimal = {{0x55555555, 0x0, 0x0, 0x80000000}};

  my_decimal decimal_check = {{0x55555555, 0x0, 0x0, 0x0}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok223) {
  my_decimal decimal = {{0x55555555, 0x0, 0x0, 0x10000}};

  my_decimal decimal_check = {{0x55555555, 0x0, 0x0, 0x80010000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok224) {
  my_decimal decimal = {{0x55555555, 0x0, 0x0, 0x80010000}};

  my_decimal decimal_check = {{0x55555555, 0x0, 0x0, 0x10000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok225) {
  my_decimal decimal = {{0x55555555, 0x0, 0x0, 0x40000}};

  my_decimal decimal_check = {{0x55555555, 0x0, 0x0, 0x80040000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok226) {
  my_decimal decimal = {{0x55555555, 0x0, 0x0, 0x80040000}};

  my_decimal decimal_check = {{0x55555555, 0x0, 0x0, 0x40000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok227) {
  my_decimal decimal = {{0x55555555, 0x0, 0x0, 0x90000}};

  my_decimal decimal_check = {{0x55555555, 0x0, 0x0, 0x80090000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok228) {
  my_decimal decimal = {{0x55555555, 0x0, 0x0, 0x80090000}};

  my_decimal decimal_check = {{0x55555555, 0x0, 0x0, 0x90000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok229) {
  my_decimal decimal = {{0x1, 0x1, 0x1, 0x0}};

  my_decimal decimal_check = {{0x1, 0x1, 0x1, 0x80000000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok230) {
  my_decimal decimal = {{0x1, 0x1, 0x1, 0x80000000}};

  my_decimal decimal_check = {{0x1, 0x1, 0x1, 0x0}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok231) {
  my_decimal decimal = {{0x1, 0x1, 0x1, 0x10000}};

  my_decimal decimal_check = {{0x1, 0x1, 0x1, 0x80010000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok232) {
  my_decimal decimal = {{0x1, 0x1, 0x1, 0x80010000}};

  my_decimal decimal_check = {{0x1, 0x1, 0x1, 0x10000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok233) {
  my_decimal decimal = {{0x1, 0x1, 0x1, 0x80000}};

  my_decimal decimal_check = {{0x1, 0x1, 0x1, 0x80080000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok234) {
  my_decimal decimal = {{0x1, 0x1, 0x1, 0x80080000}};

  my_decimal decimal_check = {{0x1, 0x1, 0x1, 0x80000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok235) {
  my_decimal decimal = {{0x1, 0x1, 0x1, 0x130000}};

  my_decimal decimal_check = {{0x1, 0x1, 0x1, 0x80130000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok236) {
  my_decimal decimal = {{0x1, 0x1, 0x1, 0x80130000}};

  my_decimal decimal_check = {{0x1, 0x1, 0x1, 0x130000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok237) {
  my_decimal decimal = {{0x0, 0x1, 0x1, 0x0}};

  my_decimal decimal_check = {{0x0, 0x1, 0x1, 0x80000000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok238) {
  my_decimal decimal = {{0x0, 0x1, 0x1, 0x80000000}};

  my_decimal decimal_check = {{0x0, 0x1, 0x1, 0x0}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok239) {
  my_decimal decimal = {{0x0, 0x1, 0x1, 0x10000}};

  my_decimal decimal_check = {{0x0, 0x1, 0x1, 0x80010000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok240) {
  my_decimal decimal = {{0x0, 0x1, 0x1, 0x80010000}};

  my_decimal decimal_check = {{0x0, 0x1, 0x1, 0x10000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok241) {
  my_decimal decimal = {{0x0, 0x1, 0x1, 0x90000}};

  my_decimal decimal_check = {{0x0, 0x1, 0x1, 0x80090000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok242) {
  my_decimal decimal = {{0x0, 0x1, 0x1, 0x80090000}};

  my_decimal decimal_check = {{0x0, 0x1, 0x1, 0x90000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok243) {
  my_decimal decimal = {{0x0, 0x1, 0x1, 0x130000}};

  my_decimal decimal_check = {{0x0, 0x1, 0x1, 0x80130000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok244) {
  my_decimal decimal = {{0x0, 0x1, 0x1, 0x80130000}};

  my_decimal decimal_check = {{0x0, 0x1, 0x1, 0x130000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok245) {
  my_decimal decimal = {{0x1, 0x0, 0x1, 0x0}};

  my_decimal decimal_check = {{0x1, 0x0, 0x1, 0x80000000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok246) {
  my_decimal decimal = {{0x1, 0x0, 0x1, 0x80000000}};

  my_decimal decimal_check = {{0x1, 0x0, 0x1, 0x0}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok247) {
  my_decimal decimal = {{0x1, 0x0, 0x1, 0x10000}};

  my_decimal decimal_check = {{0x1, 0x0, 0x1, 0x80010000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok248) {
  my_decimal decimal = {{0x1, 0x0, 0x1, 0x80010000}};

  my_decimal decimal_check = {{0x1, 0x0, 0x1, 0x10000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok249) {
  my_decimal decimal = {{0x1, 0x0, 0x1, 0xA0000}};

  my_decimal decimal_check = {{0x1, 0x0, 0x1, 0x800A0000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok250) {
  my_decimal decimal = {{0x1, 0x0, 0x1, 0x800A0000}};

  my_decimal decimal_check = {{0x1, 0x0, 0x1, 0xA0000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok251) {
  my_decimal decimal = {{0x1, 0x0, 0x1, 0x130000}};

  my_decimal decimal_check = {{0x1, 0x0, 0x1, 0x80130000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok252) {
  my_decimal decimal = {{0x1, 0x0, 0x1, 0x80130000}};

  my_decimal decimal_check = {{0x1, 0x0, 0x1, 0x130000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok253) {
  my_decimal decimal = {{0x0, 0x0, 0x1, 0x0}};

  my_decimal decimal_check = {{0x0, 0x0, 0x1, 0x80000000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok254) {
  my_decimal decimal = {{0x0, 0x0, 0x1, 0x80000000}};

  my_decimal decimal_check = {{0x0, 0x0, 0x1, 0x0}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok255) {
  my_decimal decimal = {{0x0, 0x0, 0x1, 0x10000}};

  my_decimal decimal_check = {{0x0, 0x0, 0x1, 0x80010000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok256) {
  my_decimal decimal = {{0x0, 0x0, 0x1, 0x80010000}};

  my_decimal decimal_check = {{0x0, 0x0, 0x1, 0x10000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok257) {
  my_decimal decimal = {{0x0, 0x0, 0x1, 0xB0000}};

  my_decimal decimal_check = {{0x0, 0x0, 0x1, 0x800B0000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok258) {
  my_decimal decimal = {{0x0, 0x0, 0x1, 0x800B0000}};

  my_decimal decimal_check = {{0x0, 0x0, 0x1, 0xB0000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok259) {
  my_decimal decimal = {{0x0, 0x0, 0x1, 0x130000}};

  my_decimal decimal_check = {{0x0, 0x0, 0x1, 0x80130000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok260) {
  my_decimal decimal = {{0x0, 0x0, 0x1, 0x80130000}};

  my_decimal decimal_check = {{0x0, 0x0, 0x1, 0x130000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok261) {
  my_decimal decimal = {{0x1, 0x1, 0x0, 0x0}};

  my_decimal decimal_check = {{0x1, 0x1, 0x0, 0x80000000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok262) {
  my_decimal decimal = {{0x1, 0x1, 0x0, 0x80000000}};

  my_decimal decimal_check = {{0x1, 0x1, 0x0, 0x0}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok263) {
  my_decimal decimal = {{0x1, 0x1, 0x0, 0x10000}};

  my_decimal decimal_check = {{0x1, 0x1, 0x0, 0x80010000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok264) {
  my_decimal decimal = {{0x1, 0x1, 0x0, 0x80010000}};

  my_decimal decimal_check = {{0x1, 0x1, 0x0, 0x10000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok265) {
  my_decimal decimal = {{0x1, 0x1, 0x0, 0x20000}};

  my_decimal decimal_check = {{0x1, 0x1, 0x0, 0x80020000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok266) {
  my_decimal decimal = {{0x1, 0x1, 0x0, 0x80020000}};

  my_decimal decimal_check = {{0x1, 0x1, 0x0, 0x20000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok267) {
  my_decimal decimal = {{0x1, 0x1, 0x0, 0x40000}};

  my_decimal decimal_check = {{0x1, 0x1, 0x0, 0x80040000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok268) {
  my_decimal decimal = {{0x1, 0x1, 0x0, 0x80040000}};

  my_decimal decimal_check = {{0x1, 0x1, 0x0, 0x40000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok269) {
  my_decimal decimal = {{0x1, 0x1, 0x0, 0x90000}};

  my_decimal decimal_check = {{0x1, 0x1, 0x0, 0x80090000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok270) {
  my_decimal decimal = {{0x1, 0x1, 0x0, 0x80090000}};

  my_decimal decimal_check = {{0x1, 0x1, 0x0, 0x90000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok271) {
  my_decimal decimal = {{0x1, 0x1, 0x0, 0x80000}};

  my_decimal decimal_check = {{0x1, 0x1, 0x0, 0x80080000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok272) {
  my_decimal decimal = {{0x1, 0x1, 0x0, 0x80080000}};

  my_decimal decimal_check = {{0x1, 0x1, 0x0, 0x80000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok273) {
  my_decimal decimal = {{0x0, 0x1, 0x0, 0x0}};

  my_decimal decimal_check = {{0x0, 0x1, 0x0, 0x80000000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok274) {
  my_decimal decimal = {{0x0, 0x1, 0x0, 0x80000000}};

  my_decimal decimal_check = {{0x0, 0x1, 0x0, 0x0}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok275) {
  my_decimal decimal = {{0x0, 0x1, 0x0, 0x10000}};

  my_decimal decimal_check = {{0x0, 0x1, 0x0, 0x80010000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok276) {
  my_decimal decimal = {{0x0, 0x1, 0x0, 0x80010000}};

  my_decimal decimal_check = {{0x0, 0x1, 0x0, 0x10000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok277) {
  my_decimal decimal = {{0x0, 0x1, 0x0, 0x20000}};

  my_decimal decimal_check = {{0x0, 0x1, 0x0, 0x80020000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok278) {
  my_decimal decimal = {{0x0, 0x1, 0x0, 0x80020000}};

  my_decimal decimal_check = {{0x0, 0x1, 0x0, 0x20000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok279) {
  my_decimal decimal = {{0x0, 0x1, 0x0, 0x30000}};

  my_decimal decimal_check = {{0x0, 0x1, 0x0, 0x80030000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok280) {
  my_decimal decimal = {{0x0, 0x1, 0x0, 0x80030000}};

  my_decimal decimal_check = {{0x0, 0x1, 0x0, 0x30000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok281) {
  my_decimal decimal = {{0x0, 0x1, 0x0, 0x90000}};

  my_decimal decimal_check = {{0x0, 0x1, 0x0, 0x80090000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok282) {
  my_decimal decimal = {{0x0, 0x1, 0x0, 0x80090000}};

  my_decimal decimal_check = {{0x0, 0x1, 0x0, 0x90000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok283) {
  my_decimal decimal = {{0x0, 0x1, 0x0, 0x80000}};

  my_decimal decimal_check = {{0x0, 0x1, 0x0, 0x80080000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok284) {
  my_decimal decimal = {{0x0, 0x1, 0x0, 0x80080000}};

  my_decimal decimal_check = {{0x0, 0x1, 0x0, 0x80000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok285) {
  my_decimal decimal = {{0x1, 0x0, 0x0, 0x0}};

  my_decimal decimal_check = {{0x1, 0x0, 0x0, 0x80000000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok286) {
  my_decimal decimal = {{0x1, 0x0, 0x0, 0x80000000}};

  my_decimal decimal_check = {{0x1, 0x0, 0x0, 0x0}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok287) {
  my_decimal decimal = {{0x1, 0x0, 0x0, 0x10000}};

  my_decimal decimal_check = {{0x1, 0x0, 0x0, 0x80010000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok288) {
  my_decimal decimal = {{0x1, 0x0, 0x0, 0x80010000}};

  my_decimal decimal_check = {{0x1, 0x0, 0x0, 0x10000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok289) {
  my_decimal decimal = {{0x1, 0x0, 0x0, 0xD0000}};

  my_decimal decimal_check = {{0x1, 0x0, 0x0, 0x800D0000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok290) {
  my_decimal decimal = {{0x1, 0x0, 0x0, 0x800D0000}};

  my_decimal decimal_check = {{0x1, 0x0, 0x0, 0xD0000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok291) {
  my_decimal decimal = {{0x1, 0x0, 0x0, 0xE0000}};

  my_decimal decimal_check = {{0x1, 0x0, 0x0, 0x800E0000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok292) {
  my_decimal decimal = {{0x1, 0x0, 0x0, 0x800E0000}};

  my_decimal decimal_check = {{0x1, 0x0, 0x0, 0xE0000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok293) {
  my_decimal decimal = {{0x1, 0x0, 0x0, 0x1B0000}};

  my_decimal decimal_check = {{0x1, 0x0, 0x0, 0x801B0000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok294) {
  my_decimal decimal = {{0x1, 0x0, 0x0, 0x801B0000}};

  my_decimal decimal_check = {{0x1, 0x0, 0x0, 0x1B0000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok295) {
  my_decimal decimal = {{0x1, 0x0, 0x0, 0x1C0000}};

  my_decimal decimal_check = {{0x1, 0x0, 0x0, 0x801C0000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok296) {
  my_decimal decimal = {{0x1, 0x0, 0x0, 0x801C0000}};

  my_decimal decimal_check = {{0x1, 0x0, 0x0, 0x1C0000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok297) {
  my_decimal decimal = {{0x80000000, 0x80000000, 0x80000000, 0x0}};

  my_decimal decimal_check = {
      {0x80000000, 0x80000000, 0x80000000, 0x80000000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok298) {
  my_decimal decimal = {{0x80000000, 0x80000000, 0x80000000, 0x80000000}};

  my_decimal decimal_check = {{0x80000000, 0x80000000, 0x80000000, 0x0}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok299) {
  my_decimal decimal = {{0x80000000, 0x80000000, 0x80000000, 0x10000}};

  my_decimal decimal_check = {
      {0x80000000, 0x80000000, 0x80000000, 0x80010000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok300) {
  my_decimal decimal = {{0x80000000, 0x80000000, 0x80000000, 0x80010000}};

  my_decimal decimal_check = {{0x80000000, 0x80000000, 0x80000000, 0x10000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok301) {
  my_decimal decimal = {{0x80000000, 0x80000000, 0x80000000, 0xF0000}};

  my_decimal decimal_check = {
      {0x80000000, 0x80000000, 0x80000000, 0x800F0000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok302) {
  my_decimal decimal = {{0x80000000, 0x80000000, 0x80000000, 0x800F0000}};

  my_decimal decimal_check = {{0x80000000, 0x80000000, 0x80000000, 0xF0000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok303) {
  my_decimal decimal = {{0x80000000, 0x80000000, 0x80000000, 0x1C0000}};

  my_decimal decimal_check = {
      {0x80000000, 0x80000000, 0x80000000, 0x801C0000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok304) {
  my_decimal decimal = {{0x80000000, 0x80000000, 0x80000000, 0x801C0000}};

  my_decimal decimal_check = {{0x80000000, 0x80000000, 0x80000000, 0x1C0000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok305) {
  my_decimal decimal = {{0x0, 0x80000000, 0x80000000, 0x0}};

  my_decimal decimal_check = {{0x0, 0x80000000, 0x80000000, 0x80000000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok306) {
  my_decimal decimal = {{0x0, 0x80000000, 0x80000000, 0x80000000}};

  my_decimal decimal_check = {{0x0, 0x80000000, 0x80000000, 0x0}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok307) {
  my_decimal decimal = {{0x0, 0x80000000, 0x80000000, 0x10000}};

  my_decimal decimal_check = {{0x0, 0x80000000, 0x80000000, 0x80010000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok308) {
  my_decimal decimal = {{0x0, 0x80000000, 0x80000000, 0x80010000}};

  my_decimal decimal_check = {{0x0, 0x80000000, 0x80000000, 0x10000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok309) {
  my_decimal decimal = {{0x0, 0x80000000, 0x80000000, 0xD0000}};

  my_decimal decimal_check = {{0x0, 0x80000000, 0x80000000, 0x800D0000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok310) {
  my_decimal decimal = {{0x0, 0x80000000, 0x80000000, 0x800D0000}};

  my_decimal decimal_check = {{0x0, 0x80000000, 0x80000000, 0xD0000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok311) {
  my_decimal decimal = {{0x0, 0x80000000, 0x80000000, 0x1C0000}};

  my_decimal decimal_check = {{0x0, 0x80000000, 0x80000000, 0x801C0000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok312) {
  my_decimal decimal = {{0x0, 0x80000000, 0x80000000, 0x801C0000}};

  my_decimal decimal_check = {{0x0, 0x80000000, 0x80000000, 0x1C0000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok313) {
  my_decimal decimal = {{0x80000000, 0x0, 0x80000000, 0x0}};

  my_decimal decimal_check = {{0x80000000, 0x0, 0x80000000, 0x80000000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok314) {
  my_decimal decimal = {{0x80000000, 0x0, 0x80000000, 0x80000000}};

  my_decimal decimal_check = {{0x80000000, 0x0, 0x80000000, 0x0}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok315) {
  my_decimal decimal = {{0x80000000, 0x0, 0x80000000, 0x10000}};

  my_decimal decimal_check = {{0x80000000, 0x0, 0x80000000, 0x80010000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok316) {
  my_decimal decimal = {{0x80000000, 0x0, 0x80000000, 0x80010000}};

  my_decimal decimal_check = {{0x80000000, 0x0, 0x80000000, 0x10000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok317) {
  my_decimal decimal = {{0x80000000, 0x0, 0x80000000, 0xC0000}};

  my_decimal decimal_check = {{0x80000000, 0x0, 0x80000000, 0x800C0000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok318) {
  my_decimal decimal = {{0x80000000, 0x0, 0x80000000, 0x800C0000}};

  my_decimal decimal_check = {{0x80000000, 0x0, 0x80000000, 0xC0000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok319) {
  my_decimal decimal = {{0x80000000, 0x0, 0x80000000, 0x1C0000}};

  my_decimal decimal_check = {{0x80000000, 0x0, 0x80000000, 0x801C0000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok320) {
  my_decimal decimal = {{0x80000000, 0x0, 0x80000000, 0x801C0000}};

  my_decimal decimal_check = {{0x80000000, 0x0, 0x80000000, 0x1C0000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok321) {
  my_decimal decimal = {{0x0, 0x0, 0x80000000, 0x0}};

  my_decimal decimal_check = {{0x0, 0x0, 0x80000000, 0x80000000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok322) {
  my_decimal decimal = {{0x0, 0x0, 0x80000000, 0x80000000}};

  my_decimal decimal_check = {{0x0, 0x0, 0x80000000, 0x0}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok323) {
  my_decimal decimal = {{0x0, 0x0, 0x80000000, 0x10000}};

  my_decimal decimal_check = {{0x0, 0x0, 0x80000000, 0x80010000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok324) {
  my_decimal decimal = {{0x0, 0x0, 0x80000000, 0x80010000}};

  my_decimal decimal_check = {{0x0, 0x0, 0x80000000, 0x10000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok325) {
  my_decimal decimal = {{0x0, 0x0, 0x80000000, 0xB0000}};

  my_decimal decimal_check = {{0x0, 0x0, 0x80000000, 0x800B0000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok326) {
  my_decimal decimal = {{0x0, 0x0, 0x80000000, 0x800B0000}};

  my_decimal decimal_check = {{0x0, 0x0, 0x80000000, 0xB0000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok327) {
  my_decimal decimal = {{0x0, 0x0, 0x80000000, 0x1C0000}};

  my_decimal decimal_check = {{0x0, 0x0, 0x80000000, 0x801C0000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok328) {
  my_decimal decimal = {{0x0, 0x0, 0x80000000, 0x801C0000}};

  my_decimal decimal_check = {{0x0, 0x0, 0x80000000, 0x1C0000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok329) {
  my_decimal decimal = {{0x80000000, 0x80000000, 0x0, 0x0}};

  my_decimal decimal_check = {{0x80000000, 0x80000000, 0x0, 0x80000000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok330) {
  my_decimal decimal = {{0x80000000, 0x80000000, 0x0, 0x80000000}};

  my_decimal decimal_check = {{0x80000000, 0x80000000, 0x0, 0x0}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok331) {
  my_decimal decimal = {{0x80000000, 0x80000000, 0x0, 0x10000}};

  my_decimal decimal_check = {{0x80000000, 0x80000000, 0x0, 0x80010000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok332) {
  my_decimal decimal = {{0x80000000, 0x80000000, 0x0, 0x80010000}};

  my_decimal decimal_check = {{0x80000000, 0x80000000, 0x0, 0x10000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok333) {
  my_decimal decimal = {{0x80000000, 0x80000000, 0x0, 0x70000}};

  my_decimal decimal_check = {{0x80000000, 0x80000000, 0x0, 0x80070000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok334) {
  my_decimal decimal = {{0x80000000, 0x80000000, 0x0, 0x80070000}};

  my_decimal decimal_check = {{0x80000000, 0x80000000, 0x0, 0x70000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok335) {
  my_decimal decimal = {{0x80000000, 0x80000000, 0x0, 0x120000}};

  my_decimal decimal_check = {{0x80000000, 0x80000000, 0x0, 0x80120000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok336) {
  my_decimal decimal = {{0x80000000, 0x80000000, 0x0, 0x80120000}};

  my_decimal decimal_check = {{0x80000000, 0x80000000, 0x0, 0x120000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok337) {
  my_decimal decimal = {{0x0, 0x80000000, 0x0, 0x0}};

  my_decimal decimal_check = {{0x0, 0x80000000, 0x0, 0x80000000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok338) {
  my_decimal decimal = {{0x0, 0x80000000, 0x0, 0x80000000}};

  my_decimal decimal_check = {{0x0, 0x80000000, 0x0, 0x0}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok339) {
  my_decimal decimal = {{0x0, 0x80000000, 0x0, 0x10000}};

  my_decimal decimal_check = {{0x0, 0x80000000, 0x0, 0x80010000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok340) {
  my_decimal decimal = {{0x0, 0x80000000, 0x0, 0x80010000}};

  my_decimal decimal_check = {{0x0, 0x80000000, 0x0, 0x10000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok341) {
  my_decimal decimal = {{0x0, 0x80000000, 0x0, 0x80000}};

  my_decimal decimal_check = {{0x0, 0x80000000, 0x0, 0x80080000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok342) {
  my_decimal decimal = {{0x0, 0x80000000, 0x0, 0x80080000}};

  my_decimal decimal_check = {{0x0, 0x80000000, 0x0, 0x80000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok343) {
  my_decimal decimal = {{0x0, 0x80000000, 0x0, 0x120000}};

  my_decimal decimal_check = {{0x0, 0x80000000, 0x0, 0x80120000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok344) {
  my_decimal decimal = {{0x0, 0x80000000, 0x0, 0x80120000}};

  my_decimal decimal_check = {{0x0, 0x80000000, 0x0, 0x120000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok345) {
  my_decimal decimal = {{0x80000000, 0x0, 0x0, 0x0}};

  my_decimal decimal_check = {{0x80000000, 0x0, 0x0, 0x80000000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok346) {
  my_decimal decimal = {{0x80000000, 0x0, 0x0, 0x80000000}};

  my_decimal decimal_check = {{0x80000000, 0x0, 0x0, 0x0}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok347) {
  my_decimal decimal = {{0x80000000, 0x0, 0x0, 0x10000}};

  my_decimal decimal_check = {{0x80000000, 0x0, 0x0, 0x80010000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok348) {
  my_decimal decimal = {{0x80000000, 0x0, 0x0, 0x80010000}};

  my_decimal decimal_check = {{0x80000000, 0x0, 0x0, 0x10000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok349) {
  my_decimal decimal = {{0x80000000, 0x0, 0x0, 0x20000}};

  my_decimal decimal_check = {{0x80000000, 0x0, 0x0, 0x80020000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok350) {
  my_decimal decimal = {{0x80000000, 0x0, 0x0, 0x80020000}};

  my_decimal decimal_check = {{0x80000000, 0x0, 0x0, 0x20000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok351) {
  my_decimal decimal = {{0x80000000, 0x0, 0x0, 0x40000}};

  my_decimal decimal_check = {{0x80000000, 0x0, 0x0, 0x80040000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok352) {
  my_decimal decimal = {{0x80000000, 0x0, 0x0, 0x80040000}};

  my_decimal decimal_check = {{0x80000000, 0x0, 0x0, 0x40000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok353) {
  my_decimal decimal = {{0x80000000, 0x0, 0x0, 0x80000}};

  my_decimal decimal_check = {{0x80000000, 0x0, 0x0, 0x80080000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok354) {
  my_decimal decimal = {{0x80000000, 0x0, 0x0, 0x80080000}};

  my_decimal decimal_check = {{0x80000000, 0x0, 0x0, 0x80000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok355) {
  my_decimal decimal = {{0x80000000, 0x0, 0x0, 0x90000}};

  my_decimal decimal_check = {{0x80000000, 0x0, 0x0, 0x80090000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok356) {
  my_decimal decimal = {{0x80000000, 0x0, 0x0, 0x80090000}};

  my_decimal decimal_check = {{0x80000000, 0x0, 0x0, 0x90000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok357) {
  my_decimal decimal = {{0x811800, 0x811800, 0x811800, 0x0}};

  my_decimal decimal_check = {{0x811800, 0x811800, 0x811800, 0x80000000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok358) {
  my_decimal decimal = {{0x811800, 0x811800, 0x811800, 0x80000000}};

  my_decimal decimal_check = {{0x811800, 0x811800, 0x811800, 0x0}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok359) {
  my_decimal decimal = {{0x811800, 0x811800, 0x811800, 0x10000}};

  my_decimal decimal_check = {{0x811800, 0x811800, 0x811800, 0x80010000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok360) {
  my_decimal decimal = {{0x811800, 0x811800, 0x811800, 0x80010000}};

  my_decimal decimal_check = {{0x811800, 0x811800, 0x811800, 0x10000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok361) {
  my_decimal decimal = {{0x811800, 0x811800, 0x811800, 0x140000}};

  my_decimal decimal_check = {{0x811800, 0x811800, 0x811800, 0x80140000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok362) {
  my_decimal decimal = {{0x811800, 0x811800, 0x811800, 0x80140000}};

  my_decimal decimal_check = {{0x811800, 0x811800, 0x811800, 0x140000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok363) {
  my_decimal decimal = {{0x811800, 0x811800, 0x811800, 0x1A0000}};

  my_decimal decimal_check = {{0x811800, 0x811800, 0x811800, 0x801A0000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok364) {
  my_decimal decimal = {{0x811800, 0x811800, 0x811800, 0x801A0000}};

  my_decimal decimal_check = {{0x811800, 0x811800, 0x811800, 0x1A0000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok365) {
  my_decimal decimal = {{0x0, 0x811800, 0x811800, 0x0}};

  my_decimal decimal_check = {{0x0, 0x811800, 0x811800, 0x80000000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok366) {
  my_decimal decimal = {{0x0, 0x811800, 0x811800, 0x80000000}};

  my_decimal decimal_check = {{0x0, 0x811800, 0x811800, 0x0}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok367) {
  my_decimal decimal = {{0x0, 0x811800, 0x811800, 0x10000}};

  my_decimal decimal_check = {{0x0, 0x811800, 0x811800, 0x80010000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok368) {
  my_decimal decimal = {{0x0, 0x811800, 0x811800, 0x80010000}};

  my_decimal decimal_check = {{0x0, 0x811800, 0x811800, 0x10000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok369) {
  my_decimal decimal = {{0x0, 0x811800, 0x811800, 0x40000}};

  my_decimal decimal_check = {{0x0, 0x811800, 0x811800, 0x80040000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok370) {
  my_decimal decimal = {{0x0, 0x811800, 0x811800, 0x80040000}};

  my_decimal decimal_check = {{0x0, 0x811800, 0x811800, 0x40000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok371) {
  my_decimal decimal = {{0x0, 0x811800, 0x811800, 0x1A0000}};

  my_decimal decimal_check = {{0x0, 0x811800, 0x811800, 0x801A0000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok372) {
  my_decimal decimal = {{0x0, 0x811800, 0x811800, 0x801A0000}};

  my_decimal decimal_check = {{0x0, 0x811800, 0x811800, 0x1A0000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok373) {
  my_decimal decimal = {{0x811800, 0x0, 0x811800, 0x0}};

  my_decimal decimal_check = {{0x811800, 0x0, 0x811800, 0x80000000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok374) {
  my_decimal decimal = {{0x811800, 0x0, 0x811800, 0x80000000}};

  my_decimal decimal_check = {{0x811800, 0x0, 0x811800, 0x0}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok375) {
  my_decimal decimal = {{0x811800, 0x0, 0x811800, 0x10000}};

  my_decimal decimal_check = {{0x811800, 0x0, 0x811800, 0x80010000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok376) {
  my_decimal decimal = {{0x811800, 0x0, 0x811800, 0x80010000}};

  my_decimal decimal_check = {{0x811800, 0x0, 0x811800, 0x10000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok377) {
  my_decimal decimal = {{0x811800, 0x0, 0x811800, 0xB0000}};

  my_decimal decimal_check = {{0x811800, 0x0, 0x811800, 0x800B0000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok378) {
  my_decimal decimal = {{0x811800, 0x0, 0x811800, 0x800B0000}};

  my_decimal decimal_check = {{0x811800, 0x0, 0x811800, 0xB0000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok379) {
  my_decimal decimal = {{0x811800, 0x0, 0x811800, 0x1A0000}};

  my_decimal decimal_check = {{0x811800, 0x0, 0x811800, 0x801A0000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok380) {
  my_decimal decimal = {{0x811800, 0x0, 0x811800, 0x801A0000}};

  my_decimal decimal_check = {{0x811800, 0x0, 0x811800, 0x1A0000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok381) {
  my_decimal decimal = {{0x0, 0x0, 0x811800, 0x0}};

  my_decimal decimal_check = {{0x0, 0x0, 0x811800, 0x80000000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok382) {
  my_decimal decimal = {{0x0, 0x0, 0x811800, 0x80000000}};

  my_decimal decimal_check = {{0x0, 0x0, 0x811800, 0x0}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok383) {
  my_decimal decimal = {{0x0, 0x0, 0x811800, 0x10000}};

  my_decimal decimal_check = {{0x0, 0x0, 0x811800, 0x80010000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok384) {
  my_decimal decimal = {{0x0, 0x0, 0x811800, 0x80010000}};

  my_decimal decimal_check = {{0x0, 0x0, 0x811800, 0x10000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok385) {
  my_decimal decimal = {{0x0, 0x0, 0x811800, 0x130000}};

  my_decimal decimal_check = {{0x0, 0x0, 0x811800, 0x80130000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok386) {
  my_decimal decimal = {{0x0, 0x0, 0x811800, 0x80130000}};

  my_decimal decimal_check = {{0x0, 0x0, 0x811800, 0x130000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok387) {
  my_decimal decimal = {{0x0, 0x0, 0x811800, 0x1A0000}};

  my_decimal decimal_check = {{0x0, 0x0, 0x811800, 0x801A0000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok388) {
  my_decimal decimal = {{0x0, 0x0, 0x811800, 0x801A0000}};

  my_decimal decimal_check = {{0x0, 0x0, 0x811800, 0x1A0000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok389) {
  my_decimal decimal = {{0x811800, 0x811800, 0x0, 0x0}};

  my_decimal decimal_check = {{0x811800, 0x811800, 0x0, 0x80000000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok390) {
  my_decimal decimal = {{0x811800, 0x811800, 0x0, 0x80000000}};

  my_decimal decimal_check = {{0x811800, 0x811800, 0x0, 0x0}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok391) {
  my_decimal decimal = {{0x811800, 0x811800, 0x0, 0x10000}};

  my_decimal decimal_check = {{0x811800, 0x811800, 0x0, 0x80010000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok392) {
  my_decimal decimal = {{0x811800, 0x811800, 0x0, 0x80010000}};

  my_decimal decimal_check = {{0x811800, 0x811800, 0x0, 0x10000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok393) {
  my_decimal decimal = {{0x811800, 0x811800, 0x0, 0x80000}};

  my_decimal decimal_check = {{0x811800, 0x811800, 0x0, 0x80080000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok394) {
  my_decimal decimal = {{0x811800, 0x811800, 0x0, 0x80080000}};

  my_decimal decimal_check = {{0x811800, 0x811800, 0x0, 0x80000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok395) {
  my_decimal decimal = {{0x811800, 0x811800, 0x0, 0x100000}};

  my_decimal decimal_check = {{0x811800, 0x811800, 0x0, 0x80100000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok396) {
  my_decimal decimal = {{0x811800, 0x811800, 0x0, 0x80100000}};

  my_decimal decimal_check = {{0x811800, 0x811800, 0x0, 0x100000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok397) {
  my_decimal decimal = {{0x0, 0x811800, 0x0, 0x0}};

  my_decimal decimal_check = {{0x0, 0x811800, 0x0, 0x80000000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok398) {
  my_decimal decimal = {{0x0, 0x811800, 0x0, 0x80000000}};

  my_decimal decimal_check = {{0x0, 0x811800, 0x0, 0x0}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok399) {
  my_decimal decimal = {{0x0, 0x811800, 0x0, 0x10000}};

  my_decimal decimal_check = {{0x0, 0x811800, 0x0, 0x80010000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok400) {
  my_decimal decimal = {{0x0, 0x811800, 0x0, 0x80010000}};

  my_decimal decimal_check = {{0x0, 0x811800, 0x0, 0x10000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok401) {
  my_decimal decimal = {{0x0, 0x811800, 0x0, 0x20000}};

  my_decimal decimal_check = {{0x0, 0x811800, 0x0, 0x80020000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok402) {
  my_decimal decimal = {{0x0, 0x811800, 0x0, 0x80020000}};

  my_decimal decimal_check = {{0x0, 0x811800, 0x0, 0x20000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok403) {
  my_decimal decimal = {{0x0, 0x811800, 0x0, 0x80000}};

  my_decimal decimal_check = {{0x0, 0x811800, 0x0, 0x80080000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok404) {
  my_decimal decimal = {{0x0, 0x811800, 0x0, 0x80080000}};

  my_decimal decimal_check = {{0x0, 0x811800, 0x0, 0x80000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok405) {
  my_decimal decimal = {{0x0, 0x811800, 0x0, 0xF0000}};

  my_decimal decimal_check = {{0x0, 0x811800, 0x0, 0x800F0000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok406) {
  my_decimal decimal = {{0x0, 0x811800, 0x0, 0x800F0000}};

  my_decimal decimal_check = {{0x0, 0x811800, 0x0, 0xF0000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok407) {
  my_decimal decimal = {{0x0, 0x811800, 0x0, 0x100000}};

  my_decimal decimal_check = {{0x0, 0x811800, 0x0, 0x80100000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok408) {
  my_decimal decimal = {{0x0, 0x811800, 0x0, 0x80100000}};

  my_decimal decimal_check = {{0x0, 0x811800, 0x0, 0x100000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok409) {
  my_decimal decimal = {{0x811800, 0x0, 0x0, 0x0}};

  my_decimal decimal_check = {{0x811800, 0x0, 0x0, 0x80000000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok410) {
  my_decimal decimal = {{0x811800, 0x0, 0x0, 0x80000000}};

  my_decimal decimal_check = {{0x811800, 0x0, 0x0, 0x0}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok411) {
  my_decimal decimal = {{0x811800, 0x0, 0x0, 0x10000}};

  my_decimal decimal_check = {{0x811800, 0x0, 0x0, 0x80010000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok412) {
  my_decimal decimal = {{0x811800, 0x0, 0x0, 0x80010000}};

  my_decimal decimal_check = {{0x811800, 0x0, 0x0, 0x10000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok413) {
  my_decimal decimal = {{0x811800, 0x0, 0x0, 0x20000}};

  my_decimal decimal_check = {{0x811800, 0x0, 0x0, 0x80020000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok414) {
  my_decimal decimal = {{0x811800, 0x0, 0x0, 0x80020000}};

  my_decimal decimal_check = {{0x811800, 0x0, 0x0, 0x20000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok415) {
  my_decimal decimal = {{0x811800, 0x0, 0x0, 0x30000}};

  my_decimal decimal_check = {{0x811800, 0x0, 0x0, 0x80030000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok416) {
  my_decimal decimal = {{0x811800, 0x0, 0x0, 0x80030000}};

  my_decimal decimal_check = {{0x811800, 0x0, 0x0, 0x30000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok417) {
  my_decimal decimal = {{0x811800, 0x0, 0x0, 0x50000}};

  my_decimal decimal_check = {{0x811800, 0x0, 0x0, 0x80050000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok418) {
  my_decimal decimal = {{0x811800, 0x0, 0x0, 0x80050000}};

  my_decimal decimal_check = {{0x811800, 0x0, 0x0, 0x50000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok419) {
  my_decimal decimal = {{0x811800, 0x0, 0x0, 0x60000}};

  my_decimal decimal_check = {{0x811800, 0x0, 0x0, 0x80060000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok420) {
  my_decimal decimal = {{0x811800, 0x0, 0x0, 0x80060000}};

  my_decimal decimal_check = {{0x811800, 0x0, 0x0, 0x60000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok421) {
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};

  my_decimal decimal_check = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok422) {
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};

  my_decimal decimal_check = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok423) {
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};

  my_decimal decimal_check = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80010000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok424) {
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80010000}};

  my_decimal decimal_check = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok425) {
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x110000}};

  my_decimal decimal_check = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80110000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok426) {
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80110000}};

  my_decimal decimal_check = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x110000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok427) {
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x1C0000}};

  my_decimal decimal_check = {
      {0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x801C0000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok428) {
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x801C0000}};

  my_decimal decimal_check = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x1C0000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok429) {
  my_decimal decimal = {{0x0, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};

  my_decimal decimal_check = {{0x0, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok430) {
  my_decimal decimal = {{0x0, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};

  my_decimal decimal_check = {{0x0, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok431) {
  my_decimal decimal = {{0x0, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};

  my_decimal decimal_check = {{0x0, 0xFFFFFFFF, 0xFFFFFFFF, 0x80010000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok432) {
  my_decimal decimal = {{0x0, 0xFFFFFFFF, 0xFFFFFFFF, 0x80010000}};

  my_decimal decimal_check = {{0x0, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok433) {
  my_decimal decimal = {{0x0, 0xFFFFFFFF, 0xFFFFFFFF, 0xF0000}};

  my_decimal decimal_check = {{0x0, 0xFFFFFFFF, 0xFFFFFFFF, 0x800F0000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok434) {
  my_decimal decimal = {{0x0, 0xFFFFFFFF, 0xFFFFFFFF, 0x800F0000}};

  my_decimal decimal_check = {{0x0, 0xFFFFFFFF, 0xFFFFFFFF, 0xF0000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok435) {
  my_decimal decimal = {{0x0, 0xFFFFFFFF, 0xFFFFFFFF, 0x1C0000}};

  my_decimal decimal_check = {{0x0, 0xFFFFFFFF, 0xFFFFFFFF, 0x801C0000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok436) {
  my_decimal decimal = {{0x0, 0xFFFFFFFF, 0xFFFFFFFF, 0x801C0000}};

  my_decimal decimal_check = {{0x0, 0xFFFFFFFF, 0xFFFFFFFF, 0x1C0000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok437) {
  my_decimal decimal = {{0xFFFFFFFF, 0x0, 0xFFFFFFFF, 0x0}};

  my_decimal decimal_check = {{0xFFFFFFFF, 0x0, 0xFFFFFFFF, 0x80000000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok438) {
  my_decimal decimal = {{0xFFFFFFFF, 0x0, 0xFFFFFFFF, 0x80000000}};

  my_decimal decimal_check = {{0xFFFFFFFF, 0x0, 0xFFFFFFFF, 0x0}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok439) {
  my_decimal decimal = {{0xFFFFFFFF, 0x0, 0xFFFFFFFF, 0x10000}};

  my_decimal decimal_check = {{0xFFFFFFFF, 0x0, 0xFFFFFFFF, 0x80010000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok440) {
  my_decimal decimal = {{0xFFFFFFFF, 0x0, 0xFFFFFFFF, 0x80010000}};

  my_decimal decimal_check = {{0xFFFFFFFF, 0x0, 0xFFFFFFFF, 0x10000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok441) {
  my_decimal decimal = {{0xFFFFFFFF, 0x0, 0xFFFFFFFF, 0x110000}};

  my_decimal decimal_check = {{0xFFFFFFFF, 0x0, 0xFFFFFFFF, 0x80110000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok442) {
  my_decimal decimal = {{0xFFFFFFFF, 0x0, 0xFFFFFFFF, 0x80110000}};

  my_decimal decimal_check = {{0xFFFFFFFF, 0x0, 0xFFFFFFFF, 0x110000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok443) {
  my_decimal decimal = {{0xFFFFFFFF, 0x0, 0xFFFFFFFF, 0x1C0000}};

  my_decimal decimal_check = {{0xFFFFFFFF, 0x0, 0xFFFFFFFF, 0x801C0000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok444) {
  my_decimal decimal = {{0xFFFFFFFF, 0x0, 0xFFFFFFFF, 0x801C0000}};

  my_decimal decimal_check = {{0xFFFFFFFF, 0x0, 0xFFFFFFFF, 0x1C0000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok445) {
  my_decimal decimal = {{0x0, 0x0, 0xFFFFFFFF, 0x0}};

  my_decimal decimal_check = {{0x0, 0x0, 0xFFFFFFFF, 0x80000000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok446) {
  my_decimal decimal = {{0x0, 0x0, 0xFFFFFFFF, 0x80000000}};

  my_decimal decimal_check = {{0x0, 0x0, 0xFFFFFFFF, 0x0}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok447) {
  my_decimal decimal = {{0x0, 0x0, 0xFFFFFFFF, 0x10000}};

  my_decimal decimal_check = {{0x0, 0x0, 0xFFFFFFFF, 0x80010000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok448) {
  my_decimal decimal = {{0x0, 0x0, 0xFFFFFFFF, 0x80010000}};

  my_decimal decimal_check = {{0x0, 0x0, 0xFFFFFFFF, 0x10000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok449) {
  my_decimal decimal = {{0x0, 0x0, 0xFFFFFFFF, 0x120000}};

  my_decimal decimal_check = {{0x0, 0x0, 0xFFFFFFFF, 0x80120000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok450) {
  my_decimal decimal = {{0x0, 0x0, 0xFFFFFFFF, 0x80120000}};

  my_decimal decimal_check = {{0x0, 0x0, 0xFFFFFFFF, 0x120000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok451) {
  my_decimal decimal = {{0x0, 0x0, 0xFFFFFFFF, 0x1C0000}};

  my_decimal decimal_check = {{0x0, 0x0, 0xFFFFFFFF, 0x801C0000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok452) {
  my_decimal decimal = {{0x0, 0x0, 0xFFFFFFFF, 0x801C0000}};

  my_decimal decimal_check = {{0x0, 0x0, 0xFFFFFFFF, 0x1C0000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok453) {
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0x0, 0x0}};

  my_decimal decimal_check = {{0xFFFFFFFF, 0xFFFFFFFF, 0x0, 0x80000000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok454) {
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0x0, 0x80000000}};

  my_decimal decimal_check = {{0xFFFFFFFF, 0xFFFFFFFF, 0x0, 0x0}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok455) {
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0x0, 0x10000}};

  my_decimal decimal_check = {{0xFFFFFFFF, 0xFFFFFFFF, 0x0, 0x80010000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok456) {
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0x0, 0x80010000}};

  my_decimal decimal_check = {{0xFFFFFFFF, 0xFFFFFFFF, 0x0, 0x10000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok457) {
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0x0, 0x30000}};

  my_decimal decimal_check = {{0xFFFFFFFF, 0xFFFFFFFF, 0x0, 0x80030000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok458) {
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0x0, 0x80030000}};

  my_decimal decimal_check = {{0xFFFFFFFF, 0xFFFFFFFF, 0x0, 0x30000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok459) {
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0x0, 0xB0000}};

  my_decimal decimal_check = {{0xFFFFFFFF, 0xFFFFFFFF, 0x0, 0x800B0000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok460) {
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0x0, 0x800B0000}};

  my_decimal decimal_check = {{0xFFFFFFFF, 0xFFFFFFFF, 0x0, 0xB0000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok461) {
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0x0, 0x110000}};

  my_decimal decimal_check = {{0xFFFFFFFF, 0xFFFFFFFF, 0x0, 0x80110000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok462) {
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0x0, 0x80110000}};

  my_decimal decimal_check = {{0xFFFFFFFF, 0xFFFFFFFF, 0x0, 0x110000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok463) {
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0x0, 0x130000}};

  my_decimal decimal_check = {{0xFFFFFFFF, 0xFFFFFFFF, 0x0, 0x80130000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok464) {
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0x0, 0x80130000}};

  my_decimal decimal_check = {{0xFFFFFFFF, 0xFFFFFFFF, 0x0, 0x130000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok465) {
  my_decimal decimal = {{0x0, 0xFFFFFFFF, 0x0, 0x0}};

  my_decimal decimal_check = {{0x0, 0xFFFFFFFF, 0x0, 0x80000000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok466) {
  my_decimal decimal = {{0x0, 0xFFFFFFFF, 0x0, 0x80000000}};

  my_decimal decimal_check = {{0x0, 0xFFFFFFFF, 0x0, 0x0}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok467) {
  my_decimal decimal = {{0x0, 0xFFFFFFFF, 0x0, 0x10000}};

  my_decimal decimal_check = {{0x0, 0xFFFFFFFF, 0x0, 0x80010000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok468) {
  my_decimal decimal = {{0x0, 0xFFFFFFFF, 0x0, 0x80010000}};

  my_decimal decimal_check = {{0x0, 0xFFFFFFFF, 0x0, 0x10000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok469) {
  my_decimal decimal = {{0x0, 0xFFFFFFFF, 0x0, 0x30000}};

  my_decimal decimal_check = {{0x0, 0xFFFFFFFF, 0x0, 0x80030000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok470) {
  my_decimal decimal = {{0x0, 0xFFFFFFFF, 0x0, 0x80030000}};

  my_decimal decimal_check = {{0x0, 0xFFFFFFFF, 0x0, 0x30000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok471) {
  my_decimal decimal = {{0x0, 0xFFFFFFFF, 0x0, 0x90000}};

  my_decimal decimal_check = {{0x0, 0xFFFFFFFF, 0x0, 0x80090000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok472) {
  my_decimal decimal = {{0x0, 0xFFFFFFFF, 0x0, 0x80090000}};

  my_decimal decimal_check = {{0x0, 0xFFFFFFFF, 0x0, 0x90000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok473) {
  my_decimal decimal = {{0x0, 0xFFFFFFFF, 0x0, 0x110000}};

  my_decimal decimal_check = {{0x0, 0xFFFFFFFF, 0x0, 0x80110000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok474) {
  my_decimal decimal = {{0x0, 0xFFFFFFFF, 0x0, 0x80110000}};

  my_decimal decimal_check = {{0x0, 0xFFFFFFFF, 0x0, 0x110000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok475) {
  my_decimal decimal = {{0x0, 0xFFFFFFFF, 0x0, 0x130000}};

  my_decimal decimal_check = {{0x0, 0xFFFFFFFF, 0x0, 0x80130000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok476) {
  my_decimal decimal = {{0x0, 0xFFFFFFFF, 0x0, 0x80130000}};

  my_decimal decimal_check = {{0x0, 0xFFFFFFFF, 0x0, 0x130000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok477) {
  my_decimal decimal = {{0xFFFFFFFF, 0x0, 0x0, 0x0}};

  my_decimal decimal_check = {{0xFFFFFFFF, 0x0, 0x0, 0x80000000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok478) {
  my_decimal decimal = {{0xFFFFFFFF, 0x0, 0x0, 0x80000000}};

  my_decimal decimal_check = {{0xFFFFFFFF, 0x0, 0x0, 0x0}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok479) {
  my_decimal decimal = {{0xFFFFFFFF, 0x0, 0x0, 0x10000}};

  my_decimal decimal_check = {{0xFFFFFFFF, 0x0, 0x0, 0x80010000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok480) {
  my_decimal decimal = {{0xFFFFFFFF, 0x0, 0x0, 0x80010000}};

  my_decimal decimal_check = {{0xFFFFFFFF, 0x0, 0x0, 0x10000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok481) {
  my_decimal decimal = {{0xFFFFFFFF, 0x0, 0x0, 0x20000}};

  my_decimal decimal_check = {{0xFFFFFFFF, 0x0, 0x0, 0x80020000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok482) {
  my_decimal decimal = {{0xFFFFFFFF, 0x0, 0x0, 0x80020000}};

  my_decimal decimal_check = {{0xFFFFFFFF, 0x0, 0x0, 0x20000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok483) {
  my_decimal decimal = {{0xFFFFFFFF, 0x0, 0x0, 0x50000}};

  my_decimal decimal_check = {{0xFFFFFFFF, 0x0, 0x0, 0x80050000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok484) {
  my_decimal decimal = {{0xFFFFFFFF, 0x0, 0x0, 0x80050000}};

  my_decimal decimal_check = {{0xFFFFFFFF, 0x0, 0x0, 0x50000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok485) {
  my_decimal decimal = {{0xFFFFFFFF, 0x0, 0x0, 0x80000}};

  my_decimal decimal_check = {{0xFFFFFFFF, 0x0, 0x0, 0x80080000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok486) {
  my_decimal decimal = {{0xFFFFFFFF, 0x0, 0x0, 0x80080000}};

  my_decimal decimal_check = {{0xFFFFFFFF, 0x0, 0x0, 0x80000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok487) {
  my_decimal decimal = {{0xFFFFFFFF, 0x0, 0x0, 0x90000}};

  my_decimal decimal_check = {{0xFFFFFFFF, 0x0, 0x0, 0x80090000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok488) {
  my_decimal decimal = {{0xFFFFFFFF, 0x0, 0x0, 0x80090000}};

  my_decimal decimal_check = {{0xFFFFFFFF, 0x0, 0x0, 0x90000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok489) {
  my_decimal decimal = {{0xA, 0x0, 0x0, 0x10000}};

  my_decimal decimal_check = {{0xA, 0x0, 0x0, 0x80010000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok490) {
  my_decimal decimal = {{0xA, 0x0, 0x0, 0x80010000}};

  my_decimal decimal_check = {{0xA, 0x0, 0x0, 0x10000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok491) {
  my_decimal decimal = {{0x64, 0x0, 0x0, 0x20000}};

  my_decimal decimal_check = {{0x64, 0x0, 0x0, 0x80020000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok492) {
  my_decimal decimal = {{0x64, 0x0, 0x0, 0x80020000}};

  my_decimal decimal_check = {{0x64, 0x0, 0x0, 0x20000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok493) {
  my_decimal decimal = {{0x3E8, 0x0, 0x0, 0x30000}};

  my_decimal decimal_check = {{0x3E8, 0x0, 0x0, 0x80030000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok494) {
  my_decimal decimal = {{0x3E8, 0x0, 0x0, 0x80030000}};

  my_decimal decimal_check = {{0x3E8, 0x0, 0x0, 0x30000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok495) {
  my_decimal decimal = {{0x540BE400, 0x2, 0x0, 0xA0000}};

  my_decimal decimal_check = {{0x540BE400, 0x2, 0x0, 0x800A0000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok496) {
  my_decimal decimal = {{0x540BE400, 0x2, 0x0, 0x800A0000}};

  my_decimal decimal_check = {{0x540BE400, 0x2, 0x0, 0xA0000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok497) {
  my_decimal decimal = {{0x6FC10000, 0x2386F2, 0x0, 0x100000}};

  my_decimal decimal_check = {{0x6FC10000, 0x2386F2, 0x0, 0x80100000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok498) {
  my_decimal decimal = {{0x6FC10000, 0x2386F2, 0x0, 0x80100000}};

  my_decimal decimal_check = {{0x6FC10000, 0x2386F2, 0x0, 0x100000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok499) {
  my_decimal decimal = {{0xF6800000, 0x2C7E14A, 0x152D, 0x170000}};

  my_decimal decimal_check = {{0xF6800000, 0x2C7E14A, 0x152D, 0x80170000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok500) {
  my_decimal decimal = {{0xF6800000, 0x2C7E14A, 0x152D, 0x80170000}};

  my_decimal decimal_check = {{0xF6800000, 0x2C7E14A, 0x152D, 0x170000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok501) {
  my_decimal decimal = {{0xE8000000, 0x9FD0803C, 0x33B2E3C, 0x1B0000}};

  my_decimal decimal_check = {{0xE8000000, 0x9FD0803C, 0x33B2E3C, 0x801B0000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok502) {
  my_decimal decimal = {{0xE8000000, 0x9FD0803C, 0x33B2E3C, 0x801B0000}};

  my_decimal decimal_check = {{0xE8000000, 0x9FD0803C, 0x33B2E3C, 0x1B0000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok503) {
  my_decimal decimal = {{0x10000000, 0x3E250261, 0x204FCE5E, 0x1C0000}};

  my_decimal decimal_check = {
      {0x10000000, 0x3E250261, 0x204FCE5E, 0x801C0000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok504) {
  my_decimal decimal = {{0x10000000, 0x3E250261, 0x204FCE5E, 0x801C0000}};

  my_decimal decimal_check = {{0x10000000, 0x3E250261, 0x204FCE5E, 0x1C0000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok505) {
  my_decimal decimal = {{0xB, 0x0, 0x0, 0x10000}};

  my_decimal decimal_check = {{0xB, 0x0, 0x0, 0x80010000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok506) {
  my_decimal decimal = {{0xB, 0x0, 0x0, 0x80010000}};

  my_decimal decimal_check = {{0xB, 0x0, 0x0, 0x10000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok507) {
  my_decimal decimal = {{0x4BC, 0x0, 0x0, 0x20000}};

  my_decimal decimal_check = {{0x4BC, 0x0, 0x0, 0x80020000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok508) {
  my_decimal decimal = {{0x4BC, 0x0, 0x0, 0x80020000}};

  my_decimal decimal_check = {{0x4BC, 0x0, 0x0, 0x20000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok509) {
  my_decimal decimal = {{0x1E0F3, 0x0, 0x0, 0x30000}};

  my_decimal decimal_check = {{0x1E0F3, 0x0, 0x0, 0x80030000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok510) {
  my_decimal decimal = {{0x1E0F3, 0x0, 0x0, 0x80030000}};

  my_decimal decimal_check = {{0x1E0F3, 0x0, 0x0, 0x30000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok511) {
  my_decimal decimal = {{0xBC4FF2, 0x0, 0x0, 0x40000}};

  my_decimal decimal_check = {{0xBC4FF2, 0x0, 0x0, 0x80040000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok512) {
  my_decimal decimal = {{0xBC4FF2, 0x0, 0x0, 0x80040000}};

  my_decimal decimal_check = {{0xBC4FF2, 0x0, 0x0, 0x40000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok513) {
  my_decimal decimal = {{0x499529D9, 0x0, 0x0, 0x50000}};

  my_decimal decimal_check = {{0x499529D9, 0x0, 0x0, 0x80050000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok514) {
  my_decimal decimal = {{0x499529D9, 0x0, 0x0, 0x80050000}};

  my_decimal decimal_check = {{0x499529D9, 0x0, 0x0, 0x50000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok515) {
  my_decimal decimal = {{0xBE8EF240, 0x1C, 0x0, 0x60000}};

  my_decimal decimal_check = {{0xBE8EF240, 0x1C, 0x0, 0x80060000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok516) {
  my_decimal decimal = {{0xBE8EF240, 0x1C, 0x0, 0x80060000}};

  my_decimal decimal_check = {{0xBE8EF240, 0x1C, 0x0, 0x60000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok517) {
  my_decimal decimal = {{0x73593407, 0xB3A, 0x0, 0x70000}};

  my_decimal decimal_check = {{0x73593407, 0xB3A, 0x0, 0x80070000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok518) {
  my_decimal decimal = {{0x73593407, 0xB3A, 0x0, 0x80070000}};

  my_decimal decimal_check = {{0x73593407, 0xB3A, 0x0, 0x70000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok519) {
  my_decimal decimal = {{0xEB1F0AD2, 0xAB54A98C, 0x0, 0xA0000}};

  my_decimal decimal_check = {{0xEB1F0AD2, 0xAB54A98C, 0x0, 0x800A0000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok520) {
  my_decimal decimal = {{0xEB1F0AD2, 0xAB54A98C, 0x0, 0x800A0000}};

  my_decimal decimal_check = {{0xEB1F0AD2, 0xAB54A98C, 0x0, 0xA0000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok521) {
  my_decimal decimal = {{0xF91EAFF2, 0x6D795225, 0x3FD35EB, 0xE0000}};

  my_decimal decimal_check = {{0xF91EAFF2, 0x6D795225, 0x3FD35EB, 0x800E0000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok522) {
  my_decimal decimal = {{0xF91EAFF2, 0x6D795225, 0x3FD35EB, 0x800E0000}};

  my_decimal decimal_check = {{0xF91EAFF2, 0x6D795225, 0x3FD35EB, 0xE0000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok523) {
  my_decimal decimal = {{0x63, 0x0, 0x0, 0x0}};

  my_decimal decimal_check = {{0x63, 0x0, 0x0, 0x80000000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok524) {
  my_decimal decimal = {{0x63, 0x0, 0x0, 0x80000000}};

  my_decimal decimal_check = {{0x63, 0x0, 0x0, 0x0}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok525) {
  my_decimal decimal = {{0x63, 0x0, 0x0, 0x10000}};

  my_decimal decimal_check = {{0x63, 0x0, 0x0, 0x80010000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok526) {
  my_decimal decimal = {{0x63, 0x0, 0x0, 0x80010000}};

  my_decimal decimal_check = {{0x63, 0x0, 0x0, 0x10000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok527) {
  my_decimal decimal = {{0x270F, 0x0, 0x0, 0x20000}};

  my_decimal decimal_check = {{0x270F, 0x0, 0x0, 0x80020000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok528) {
  my_decimal decimal = {{0x270F, 0x0, 0x0, 0x80020000}};

  my_decimal decimal_check = {{0x270F, 0x0, 0x0, 0x20000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok529) {
  my_decimal decimal = {{0xF423F, 0x0, 0x0, 0x30000}};

  my_decimal decimal_check = {{0xF423F, 0x0, 0x0, 0x80030000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok530) {
  my_decimal decimal = {{0xF423F, 0x0, 0x0, 0x80030000}};

  my_decimal decimal_check = {{0xF423F, 0x0, 0x0, 0x30000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok531) {
  my_decimal decimal = {{0x5F5E0FF, 0x0, 0x0, 0x40000}};

  my_decimal decimal_check = {{0x5F5E0FF, 0x0, 0x0, 0x80040000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok532) {
  my_decimal decimal = {{0x5F5E0FF, 0x0, 0x0, 0x80040000}};

  my_decimal decimal_check = {{0x5F5E0FF, 0x0, 0x0, 0x40000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok533) {
  my_decimal decimal = {{0x540BE3FF, 0x2, 0x0, 0x50000}};

  my_decimal decimal_check = {{0x540BE3FF, 0x2, 0x0, 0x80050000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok534) {
  my_decimal decimal = {{0x540BE3FF, 0x2, 0x0, 0x80050000}};

  my_decimal decimal_check = {{0x540BE3FF, 0x2, 0x0, 0x50000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok535) {
  my_decimal decimal = {{0xD4A50FFF, 0xE8, 0x0, 0x60000}};

  my_decimal decimal_check = {{0xD4A50FFF, 0xE8, 0x0, 0x80060000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok536) {
  my_decimal decimal = {{0xD4A50FFF, 0xE8, 0x0, 0x80060000}};

  my_decimal decimal_check = {{0xD4A50FFF, 0xE8, 0x0, 0x60000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok537) {
  my_decimal decimal = {{0x107A3FFF, 0x5AF3, 0x0, 0x70000}};

  my_decimal decimal_check = {{0x107A3FFF, 0x5AF3, 0x0, 0x80070000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok538) {
  my_decimal decimal = {{0x107A3FFF, 0x5AF3, 0x0, 0x80070000}};

  my_decimal decimal_check = {{0x107A3FFF, 0x5AF3, 0x0, 0x70000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok539) {
  my_decimal decimal = {{0x6FC0FFFF, 0x2386F2, 0x0, 0x80000}};

  my_decimal decimal_check = {{0x6FC0FFFF, 0x2386F2, 0x0, 0x80080000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok540) {
  my_decimal decimal = {{0x6FC0FFFF, 0x2386F2, 0x0, 0x80080000}};

  my_decimal decimal_check = {{0x6FC0FFFF, 0x2386F2, 0x0, 0x80000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok541) {
  my_decimal decimal = {{0xA763FFFF, 0xDE0B6B3, 0x0, 0x90000}};

  my_decimal decimal_check = {{0xA763FFFF, 0xDE0B6B3, 0x0, 0x80090000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok542) {
  my_decimal decimal = {{0xA763FFFF, 0xDE0B6B3, 0x0, 0x80090000}};

  my_decimal decimal_check = {{0xA763FFFF, 0xDE0B6B3, 0x0, 0x90000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok543) {
  my_decimal decimal = {{0x630FFFFF, 0x6BC75E2D, 0x5, 0xA0000}};

  my_decimal decimal_check = {{0x630FFFFF, 0x6BC75E2D, 0x5, 0x800A0000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok544) {
  my_decimal decimal = {{0x630FFFFF, 0x6BC75E2D, 0x5, 0x800A0000}};

  my_decimal decimal_check = {{0x630FFFFF, 0x6BC75E2D, 0x5, 0xA0000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok545) {
  my_decimal decimal = {{0x9, 0x0, 0x0, 0x0}};

  my_decimal decimal_check = {{0x9, 0x0, 0x0, 0x80000000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok546) {
  my_decimal decimal = {{0x9, 0x0, 0x0, 0x80000000}};

  my_decimal decimal_check = {{0x9, 0x0, 0x0, 0x0}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok547) {
  my_decimal decimal = {{0x9, 0x0, 0x0, 0x10000}};

  my_decimal decimal_check = {{0x9, 0x0, 0x0, 0x80010000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok548) {
  my_decimal decimal = {{0x9, 0x0, 0x0, 0x80010000}};

  my_decimal decimal_check = {{0x9, 0x0, 0x0, 0x10000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok549) {
  my_decimal decimal = {{0x63, 0x0, 0x0, 0x20000}};

  my_decimal decimal_check = {{0x63, 0x0, 0x0, 0x80020000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok550) {
  my_decimal decimal = {{0x63, 0x0, 0x0, 0x80020000}};

  my_decimal decimal_check = {{0x63, 0x0, 0x0, 0x20000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok551) {
  my_decimal decimal = {{0x3E7, 0x0, 0x0, 0x30000}};

  my_decimal decimal_check = {{0x3E7, 0x0, 0x0, 0x80030000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok552) {
  my_decimal decimal = {{0x3E7, 0x0, 0x0, 0x80030000}};

  my_decimal decimal_check = {{0x3E7, 0x0, 0x0, 0x30000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok553) {
  my_decimal decimal = {{0x270F, 0x0, 0x0, 0x40000}};

  my_decimal decimal_check = {{0x270F, 0x0, 0x0, 0x80040000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok554) {
  my_decimal decimal = {{0x270F, 0x0, 0x0, 0x80040000}};

  my_decimal decimal_check = {{0x270F, 0x0, 0x0, 0x40000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok555) {
  my_decimal decimal = {{0x1869F, 0x0, 0x0, 0x50000}};

  my_decimal decimal_check = {{0x1869F, 0x0, 0x0, 0x80050000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok556) {
  my_decimal decimal = {{0x1869F, 0x0, 0x0, 0x80050000}};

  my_decimal decimal_check = {{0x1869F, 0x0, 0x0, 0x50000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok557) {
  my_decimal decimal = {{0xF423F, 0x0, 0x0, 0x60000}};

  my_decimal decimal_check = {{0xF423F, 0x0, 0x0, 0x80060000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok558) {
  my_decimal decimal = {{0xF423F, 0x0, 0x0, 0x80060000}};

  my_decimal decimal_check = {{0xF423F, 0x0, 0x0, 0x60000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok559) {
  my_decimal decimal = {{0x98967F, 0x0, 0x0, 0x70000}};

  my_decimal decimal_check = {{0x98967F, 0x0, 0x0, 0x80070000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok560) {
  my_decimal decimal = {{0x98967F, 0x0, 0x0, 0x80070000}};

  my_decimal decimal_check = {{0x98967F, 0x0, 0x0, 0x70000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok561) {
  my_decimal decimal = {{0x5F5E0FF, 0x0, 0x0, 0x80000}};

  my_decimal decimal_check = {{0x5F5E0FF, 0x0, 0x0, 0x80080000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok562) {
  my_decimal decimal = {{0x5F5E0FF, 0x0, 0x0, 0x80080000}};

  my_decimal decimal_check = {{0x5F5E0FF, 0x0, 0x0, 0x80000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok563) {
  my_decimal decimal = {{0x3B9AC9FF, 0x0, 0x0, 0x90000}};

  my_decimal decimal_check = {{0x3B9AC9FF, 0x0, 0x0, 0x80090000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok564) {
  my_decimal decimal = {{0x3B9AC9FF, 0x0, 0x0, 0x80090000}};

  my_decimal decimal_check = {{0x3B9AC9FF, 0x0, 0x0, 0x90000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok565) {
  my_decimal decimal = {{0x540BE3FF, 0x2, 0x0, 0xA0000}};

  my_decimal decimal_check = {{0x540BE3FF, 0x2, 0x0, 0x800A0000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok566) {
  my_decimal decimal = {{0x540BE3FF, 0x2, 0x0, 0x800A0000}};

  my_decimal decimal_check = {{0x540BE3FF, 0x2, 0x0, 0xA0000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok567) {
  my_decimal decimal = {{0x630FFFFF, 0x6BC75E2D, 0x5, 0x140000}};

  my_decimal decimal_check = {{0x630FFFFF, 0x6BC75E2D, 0x5, 0x80140000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok568) {
  my_decimal decimal = {{0x630FFFFF, 0x6BC75E2D, 0x5, 0x80140000}};

  my_decimal decimal_check = {{0x630FFFFF, 0x6BC75E2D, 0x5, 0x140000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok569) {
  my_decimal decimal = {{0x0, 0x0, 0x0, 0x80000000}};

  my_decimal decimal_check = {{0x0, 0x0, 0x0, 0x0}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok570) {
  my_decimal decimal = {{0x0, 0x0, 0x0, 0x0}};

  my_decimal decimal_check = {{0x0, 0x0, 0x0, 0x80000000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok571) {
  my_decimal decimal = {{0x0, 0x0, 0x0, 0x80010000}};

  my_decimal decimal_check = {{0x0, 0x0, 0x0, 0x10000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok572) {
  my_decimal decimal = {{0x0, 0x0, 0x0, 0x10000}};

  my_decimal decimal_check = {{0x0, 0x0, 0x0, 0x80010000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok573) {
  my_decimal decimal = {{0x0, 0x0, 0x0, 0x80020000}};

  my_decimal decimal_check = {{0x0, 0x0, 0x0, 0x20000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok574) {
  my_decimal decimal = {{0x0, 0x0, 0x0, 0x20000}};

  my_decimal decimal_check = {{0x0, 0x0, 0x0, 0x80020000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok575) {
  my_decimal decimal = {{0x0, 0x0, 0x0, 0x800E0000}};

  my_decimal decimal_check = {{0x0, 0x0, 0x0, 0xE0000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok576) {
  my_decimal decimal = {{0x0, 0x0, 0x0, 0xE0000}};

  my_decimal decimal_check = {{0x0, 0x0, 0x0, 0x800E0000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok577) {
  my_decimal decimal = {{0x0, 0x0, 0x0, 0x801B0000}};

  my_decimal decimal_check = {{0x0, 0x0, 0x0, 0x1B0000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok578) {
  my_decimal decimal = {{0x0, 0x0, 0x0, 0x1B0000}};

  my_decimal decimal_check = {{0x0, 0x0, 0x0, 0x801B0000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok579) {
  my_decimal decimal = {{0x0, 0x0, 0x0, 0x801C0000}};

  my_decimal decimal_check = {{0x0, 0x0, 0x0, 0x1C0000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok580) {
  my_decimal decimal = {{0x0, 0x0, 0x0, 0x1C0000}};

  my_decimal decimal_check = {{0x0, 0x0, 0x0, 0x801C0000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok581) {
  my_decimal decimal = {{0x5, 0x0, 0x0, 0x10000}};

  my_decimal decimal_check = {{0x5, 0x0, 0x0, 0x80010000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok582) {
  my_decimal decimal = {{0x5, 0x0, 0x0, 0x80010000}};

  my_decimal decimal_check = {{0x5, 0x0, 0x0, 0x10000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok583) {
  my_decimal decimal = {{0x31, 0x0, 0x0, 0x20000}};

  my_decimal decimal_check = {{0x31, 0x0, 0x0, 0x80020000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok584) {
  my_decimal decimal = {{0x31, 0x0, 0x0, 0x80020000}};

  my_decimal decimal_check = {{0x31, 0x0, 0x0, 0x20000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok585) {
  my_decimal decimal = {{0x33, 0x0, 0x0, 0x20000}};

  my_decimal decimal_check = {{0x33, 0x0, 0x0, 0x80020000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok586) {
  my_decimal decimal = {{0x33, 0x0, 0x0, 0x80020000}};

  my_decimal decimal_check = {{0x33, 0x0, 0x0, 0x20000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok587) {
  my_decimal decimal = {{0x2FAF07F, 0x0, 0x0, 0x80000}};

  my_decimal decimal_check = {{0x2FAF07F, 0x0, 0x0, 0x80080000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok588) {
  my_decimal decimal = {{0x2FAF07F, 0x0, 0x0, 0x80080000}};

  my_decimal decimal_check = {{0x2FAF07F, 0x0, 0x0, 0x80000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok589) {
  my_decimal decimal = {{0x87FFFFFF, 0x1F128130, 0x1027E72F, 0x1C0000}};

  my_decimal decimal_check = {
      {0x87FFFFFF, 0x1F128130, 0x1027E72F, 0x801C0000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok590) {
  my_decimal decimal = {{0x87FFFFFF, 0x1F128130, 0x1027E72F, 0x801C0000}};

  my_decimal decimal_check = {{0x87FFFFFF, 0x1F128130, 0x1027E72F, 0x1C0000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok591) {
  my_decimal decimal = {{0x88000001, 0x1F128130, 0x1027E72F, 0x1C0000}};

  my_decimal decimal_check = {
      {0x88000001, 0x1F128130, 0x1027E72F, 0x801C0000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok592) {
  my_decimal decimal = {{0x88000001, 0x1F128130, 0x1027E72F, 0x801C0000}};

  my_decimal decimal_check = {{0x88000001, 0x1F128130, 0x1027E72F, 0x1C0000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok593) {
  my_decimal decimal = {{0x88000000, 0x1F128130, 0x1027E72F, 0x1C0000}};

  my_decimal decimal_check = {
      {0x88000000, 0x1F128130, 0x1027E72F, 0x801C0000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok594) {
  my_decimal decimal = {{0x88000000, 0x1F128130, 0x1027E72F, 0x801C0000}};

  my_decimal decimal_check = {{0x88000000, 0x1F128130, 0x1027E72F, 0x1C0000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok595) {
  my_decimal decimal = {{0x63, 0x0, 0x0, 0x20000}};

  my_decimal decimal_check = {{0x63, 0x0, 0x0, 0x80020000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok596) {
  my_decimal decimal = {{0x63, 0x0, 0x0, 0x80020000}};

  my_decimal decimal_check = {{0x63, 0x0, 0x0, 0x20000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok597) {
  my_decimal decimal = {{0x3B9AC9FF, 0x0, 0x0, 0x90000}};

  my_decimal decimal_check = {{0x3B9AC9FF, 0x0, 0x0, 0x80090000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok598) {
  my_decimal decimal = {{0x3B9AC9FF, 0x0, 0x0, 0x80090000}};

  my_decimal decimal_check = {{0x3B9AC9FF, 0x0, 0x0, 0x90000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok599) {
  my_decimal decimal = {{0xFFFFFFF, 0x3E250261, 0x204FCE5E, 0x1C0000}};

  my_decimal decimal_check = {{0xFFFFFFF, 0x3E250261, 0x204FCE5E, 0x801C0000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok600) {
  my_decimal decimal = {{0xFFFFFFF, 0x3E250261, 0x204FCE5E, 0x801C0000}};

  my_decimal decimal_check = {{0xFFFFFFF, 0x3E250261, 0x204FCE5E, 0x1C0000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok601) {
  my_decimal decimal = {{0x10000001, 0x3E250261, 0x204FCE5E, 0x1C0000}};

  my_decimal decimal_check = {
      {0x10000001, 0x3E250261, 0x204FCE5E, 0x801C0000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok602) {
  my_decimal decimal = {{0x10000001, 0x3E250261, 0x204FCE5E, 0x801C0000}};

  my_decimal decimal_check = {{0x10000001, 0x3E250261, 0x204FCE5E, 0x1C0000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok603) {
  my_decimal decimal = {{0xF, 0x0, 0x0, 0x10000}};

  my_decimal decimal_check = {{0xF, 0x0, 0x0, 0x80010000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok604) {
  my_decimal decimal = {{0xF, 0x0, 0x0, 0x80010000}};

  my_decimal decimal_check = {{0xF, 0x0, 0x0, 0x10000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok605) {
  my_decimal decimal = {{0x95, 0x0, 0x0, 0x20000}};

  my_decimal decimal_check = {{0x95, 0x0, 0x0, 0x80020000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok606) {
  my_decimal decimal = {{0x95, 0x0, 0x0, 0x80020000}};

  my_decimal decimal_check = {{0x95, 0x0, 0x0, 0x20000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok607) {
  my_decimal decimal = {{0x97, 0x0, 0x0, 0x20000}};

  my_decimal decimal_check = {{0x97, 0x0, 0x0, 0x80020000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok608) {
  my_decimal decimal = {{0x97, 0x0, 0x0, 0x80020000}};

  my_decimal decimal_check = {{0x97, 0x0, 0x0, 0x20000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok609) {
  my_decimal decimal = {{0x8F0D17F, 0x0, 0x0, 0x80000}};

  my_decimal decimal_check = {{0x8F0D17F, 0x0, 0x0, 0x80080000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok610) {
  my_decimal decimal = {{0x8F0D17F, 0x0, 0x0, 0x80080000}};

  my_decimal decimal_check = {{0x8F0D17F, 0x0, 0x0, 0x80000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok611) {
  my_decimal decimal = {{0x97FFFFFF, 0x5D378391, 0x3077B58D, 0x1C0000}};

  my_decimal decimal_check = {
      {0x97FFFFFF, 0x5D378391, 0x3077B58D, 0x801C0000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok612) {
  my_decimal decimal = {{0x97FFFFFF, 0x5D378391, 0x3077B58D, 0x801C0000}};

  my_decimal decimal_check = {{0x97FFFFFF, 0x5D378391, 0x3077B58D, 0x1C0000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok613) {
  my_decimal decimal = {{0x98000001, 0x5D378391, 0x3077B58D, 0x1C0000}};

  my_decimal decimal_check = {
      {0x98000001, 0x5D378391, 0x3077B58D, 0x801C0000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok614) {
  my_decimal decimal = {{0x98000001, 0x5D378391, 0x3077B58D, 0x801C0000}};

  my_decimal decimal_check = {{0x98000001, 0x5D378391, 0x3077B58D, 0x1C0000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok615) {
  my_decimal decimal = {{0x98000000, 0x5D378391, 0x3077B58D, 0x1C0000}};

  my_decimal decimal_check = {
      {0x98000000, 0x5D378391, 0x3077B58D, 0x801C0000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok616) {
  my_decimal decimal = {{0x98000000, 0x5D378391, 0x3077B58D, 0x801C0000}};

  my_decimal decimal_check = {{0x98000000, 0x5D378391, 0x3077B58D, 0x1C0000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok617) {
  my_decimal decimal = {{0x1E847F, 0x0, 0x0, 0x60000}};

  my_decimal decimal_check = {{0x1E847F, 0x0, 0x0, 0x80060000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok618) {
  my_decimal decimal = {{0x1E847F, 0x0, 0x0, 0x80060000}};

  my_decimal decimal_check = {{0x1E847F, 0x0, 0x0, 0x60000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok619) {
  my_decimal decimal = {{0x1FFFFFFF, 0x7C4A04C2, 0x409F9CBC, 0x1C0000}};

  my_decimal decimal_check = {
      {0x1FFFFFFF, 0x7C4A04C2, 0x409F9CBC, 0x801C0000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok620) {
  my_decimal decimal = {{0x1FFFFFFF, 0x7C4A04C2, 0x409F9CBC, 0x801C0000}};

  my_decimal decimal_check = {{0x1FFFFFFF, 0x7C4A04C2, 0x409F9CBC, 0x1C0000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok621) {
  my_decimal decimal = {{0x873F544D, 0x720EF6CF, 0x6761E70D, 0x80030000}};

  my_decimal decimal_check = {{0x873F544D, 0x720EF6CF, 0x6761E70D, 0x30000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok622) {
  my_decimal decimal = {{0x873F544D, 0x720EF6CF, 0x6761E70D, 0x30000}};

  my_decimal decimal_check = {
      {0x873F544D, 0x720EF6CF, 0x6761E70D, 0x80030000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok623) {
  my_decimal decimal = {{0x2C27F11B, 0xAB7A362C, 0xA376B177, 0x140000}};

  my_decimal decimal_check = {
      {0x2C27F11B, 0xAB7A362C, 0xA376B177, 0x80140000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok624) {
  my_decimal decimal = {{0x2C27F11B, 0xAB7A362C, 0xA376B177, 0x80140000}};

  my_decimal decimal_check = {{0x2C27F11B, 0xAB7A362C, 0xA376B177, 0x140000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok625) {
  my_decimal decimal = {{0x63E31694, 0xF61EB7CD, 0x6EC08C6, 0x30000}};

  my_decimal decimal_check = {{0x63E31694, 0xF61EB7CD, 0x6EC08C6, 0x80030000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok626) {
  my_decimal decimal = {{0x63E31694, 0xF61EB7CD, 0x6EC08C6, 0x80030000}};

  my_decimal decimal_check = {{0x63E31694, 0xF61EB7CD, 0x6EC08C6, 0x30000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok627) {
  my_decimal decimal = {{0x9C8A00C8, 0x934CB014, 0xAED3FF85, 0xF0000}};

  my_decimal decimal_check = {
      {0x9C8A00C8, 0x934CB014, 0xAED3FF85, 0x800F0000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok628) {
  my_decimal decimal = {{0x9C8A00C8, 0x934CB014, 0xAED3FF85, 0x800F0000}};

  my_decimal decimal_check = {{0x9C8A00C8, 0x934CB014, 0xAED3FF85, 0xF0000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok629) {
  my_decimal decimal = {{0x6335CE63, 0xF0D0163D, 0xE63C2573, 0x80190000}};

  my_decimal decimal_check = {{0x6335CE63, 0xF0D0163D, 0xE63C2573, 0x190000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok630) {
  my_decimal decimal = {{0x6335CE63, 0xF0D0163D, 0xE63C2573, 0x190000}};

  my_decimal decimal_check = {
      {0x6335CE63, 0xF0D0163D, 0xE63C2573, 0x80190000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok631) {
  my_decimal decimal = {{0x8D233748, 0x29D6FE5, 0x7192A8D1, 0x800B0000}};

  my_decimal decimal_check = {{0x8D233748, 0x29D6FE5, 0x7192A8D1, 0xB0000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok632) {
  my_decimal decimal = {{0x8D233748, 0x29D6FE5, 0x7192A8D1, 0xB0000}};

  my_decimal decimal_check = {{0x8D233748, 0x29D6FE5, 0x7192A8D1, 0x800B0000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok633) {
  my_decimal decimal = {{0xE9A5F27C, 0x9103102B, 0x82B08B35, 0x800D0000}};

  my_decimal decimal_check = {{0xE9A5F27C, 0x9103102B, 0x82B08B35, 0xD0000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok634) {
  my_decimal decimal = {{0xE9A5F27C, 0x9103102B, 0x82B08B35, 0xD0000}};

  my_decimal decimal_check = {
      {0xE9A5F27C, 0x9103102B, 0x82B08B35, 0x800D0000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok635) {
  my_decimal decimal = {{0xD3F79105, 0xD79DCCA, 0xFE7A16A8, 0x20000}};

  my_decimal decimal_check = {{0xD3F79105, 0xD79DCCA, 0xFE7A16A8, 0x80020000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok636) {
  my_decimal decimal = {{0xD3F79105, 0xD79DCCA, 0xFE7A16A8, 0x80020000}};

  my_decimal decimal_check = {{0xD3F79105, 0xD79DCCA, 0xFE7A16A8, 0x20000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok637) {
  my_decimal decimal = {{0x3B780F48, 0x203F2D8C, 0x3354B892, 0x80190000}};

  my_decimal decimal_check = {{0x3B780F48, 0x203F2D8C, 0x3354B892, 0x190000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok638) {
  my_decimal decimal = {{0x3B780F48, 0x203F2D8C, 0x3354B892, 0x190000}};

  my_decimal decimal_check = {
      {0x3B780F48, 0x203F2D8C, 0x3354B892, 0x80190000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok639) {
  my_decimal decimal = {{0xE0E30AFD, 0xDFB7B835, 0x247947E5, 0x801C0000}};

  my_decimal decimal_check = {{0xE0E30AFD, 0xDFB7B835, 0x247947E5, 0x1C0000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok640) {
  my_decimal decimal = {{0xE0E30AFD, 0xDFB7B835, 0x247947E5, 0x1C0000}};

  my_decimal decimal_check = {
      {0xE0E30AFD, 0xDFB7B835, 0x247947E5, 0x801C0000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok641) {
  my_decimal decimal = {{0x9A7544C6, 0xA0AA802F, 0xF781B99, 0x110000}};

  my_decimal decimal_check = {{0x9A7544C6, 0xA0AA802F, 0xF781B99, 0x80110000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok642) {
  my_decimal decimal = {{0x9A7544C6, 0xA0AA802F, 0xF781B99, 0x80110000}};

  my_decimal decimal_check = {{0x9A7544C6, 0xA0AA802F, 0xF781B99, 0x110000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok643) {
  my_decimal decimal = {{0x8AD7CC8, 0x89CEB74E, 0xECAFDABE, 0x10000}};

  my_decimal decimal_check = {{0x8AD7CC8, 0x89CEB74E, 0xECAFDABE, 0x80010000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok644) {
  my_decimal decimal = {{0x8AD7CC8, 0x89CEB74E, 0xECAFDABE, 0x80010000}};

  my_decimal decimal_check = {{0x8AD7CC8, 0x89CEB74E, 0xECAFDABE, 0x10000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok645) {
  my_decimal decimal = {{0x7D47B3D6, 0x55DF7B4B, 0xE910DF23, 0x80180000}};

  my_decimal decimal_check = {{0x7D47B3D6, 0x55DF7B4B, 0xE910DF23, 0x180000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok646) {
  my_decimal decimal = {{0x7D47B3D6, 0x55DF7B4B, 0xE910DF23, 0x180000}};

  my_decimal decimal_check = {
      {0x7D47B3D6, 0x55DF7B4B, 0xE910DF23, 0x80180000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok647) {
  my_decimal decimal = {{0xD426CA40, 0xA712AF2C, 0x4B9CF89B, 0x1A0000}};

  my_decimal decimal_check = {
      {0xD426CA40, 0xA712AF2C, 0x4B9CF89B, 0x801A0000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok648) {
  my_decimal decimal = {{0xD426CA40, 0xA712AF2C, 0x4B9CF89B, 0x801A0000}};

  my_decimal decimal_check = {{0xD426CA40, 0xA712AF2C, 0x4B9CF89B, 0x1A0000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok649) {
  my_decimal decimal = {{0xBD9011BF, 0xA81025E1, 0x83EFB7AC, 0x60000}};

  my_decimal decimal_check = {
      {0xBD9011BF, 0xA81025E1, 0x83EFB7AC, 0x80060000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok650) {
  my_decimal decimal = {{0xBD9011BF, 0xA81025E1, 0x83EFB7AC, 0x80060000}};

  my_decimal decimal_check = {{0xBD9011BF, 0xA81025E1, 0x83EFB7AC, 0x60000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok651) {
  my_decimal decimal = {{0xD5DD6EB8, 0x4F67C0FA, 0xFD435037, 0x80070000}};

  my_decimal decimal_check = {{0xD5DD6EB8, 0x4F67C0FA, 0xFD435037, 0x70000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok652) {
  my_decimal decimal = {{0xD5DD6EB8, 0x4F67C0FA, 0xFD435037, 0x70000}};

  my_decimal decimal_check = {
      {0xD5DD6EB8, 0x4F67C0FA, 0xFD435037, 0x80070000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok653) {
  my_decimal decimal = {{0xB4B864E6, 0xE577A195, 0x164CDC47, 0x20000}};

  my_decimal decimal_check = {
      {0xB4B864E6, 0xE577A195, 0x164CDC47, 0x80020000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok654) {
  my_decimal decimal = {{0xB4B864E6, 0xE577A195, 0x164CDC47, 0x80020000}};

  my_decimal decimal_check = {{0xB4B864E6, 0xE577A195, 0x164CDC47, 0x20000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok655) {
  my_decimal decimal = {{0x1D0BBB43, 0x615E4A12, 0xB4769447, 0x80030000}};

  my_decimal decimal_check = {{0x1D0BBB43, 0x615E4A12, 0xB4769447, 0x30000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok656) {
  my_decimal decimal = {{0x1D0BBB43, 0x615E4A12, 0xB4769447, 0x30000}};

  my_decimal decimal_check = {
      {0x1D0BBB43, 0x615E4A12, 0xB4769447, 0x80030000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok657) {
  my_decimal decimal = {{0x896A9219, 0xCCCBF8, 0x8EAC18B5, 0x80000}};

  my_decimal decimal_check = {{0x896A9219, 0xCCCBF8, 0x8EAC18B5, 0x80080000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok658) {
  my_decimal decimal = {{0x896A9219, 0xCCCBF8, 0x8EAC18B5, 0x80080000}};

  my_decimal decimal_check = {{0x896A9219, 0xCCCBF8, 0x8EAC18B5, 0x80000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok659) {
  my_decimal decimal = {{0xC039180E, 0x17BEB589, 0x30CBCBE7, 0x80110000}};

  my_decimal decimal_check = {{0xC039180E, 0x17BEB589, 0x30CBCBE7, 0x110000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok660) {
  my_decimal decimal = {{0xC039180E, 0x17BEB589, 0x30CBCBE7, 0x110000}};

  my_decimal decimal_check = {
      {0xC039180E, 0x17BEB589, 0x30CBCBE7, 0x80110000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok661) {
  my_decimal decimal = {{0x7166F92F, 0x636702FE, 0x50EEC429, 0x80010000}};

  my_decimal decimal_check = {{0x7166F92F, 0x636702FE, 0x50EEC429, 0x10000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok662) {
  my_decimal decimal = {{0x7166F92F, 0x636702FE, 0x50EEC429, 0x10000}};

  my_decimal decimal_check = {
      {0x7166F92F, 0x636702FE, 0x50EEC429, 0x80010000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok663) {
  my_decimal decimal = {{0xD17CC169, 0xC8328AFD, 0xC7752474, 0x80060000}};

  my_decimal decimal_check = {{0xD17CC169, 0xC8328AFD, 0xC7752474, 0x60000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok664) {
  my_decimal decimal = {{0xD17CC169, 0xC8328AFD, 0xC7752474, 0x60000}};

  my_decimal decimal_check = {
      {0xD17CC169, 0xC8328AFD, 0xC7752474, 0x80060000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok665) {
  my_decimal decimal = {{0x91B5F8B3, 0xCEB2D42A, 0xA0D2B36, 0x70000}};

  my_decimal decimal_check = {{0x91B5F8B3, 0xCEB2D42A, 0xA0D2B36, 0x80070000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok666) {
  my_decimal decimal = {{0x91B5F8B3, 0xCEB2D42A, 0xA0D2B36, 0x80070000}};

  my_decimal decimal_check = {{0x91B5F8B3, 0xCEB2D42A, 0xA0D2B36, 0x70000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok667) {
  my_decimal decimal = {{0x8DBC44A, 0x995466F5, 0x79B97245, 0x1C0000}};

  my_decimal decimal_check = {{0x8DBC44A, 0x995466F5, 0x79B97245, 0x801C0000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok668) {
  my_decimal decimal = {{0x8DBC44A, 0x995466F5, 0x79B97245, 0x801C0000}};

  my_decimal decimal_check = {{0x8DBC44A, 0x995466F5, 0x79B97245, 0x1C0000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok669) {
  my_decimal decimal = {{0x607AF3B9, 0xA90EE1CF, 0x1F4315E4, 0x80010000}};

  my_decimal decimal_check = {{0x607AF3B9, 0xA90EE1CF, 0x1F4315E4, 0x10000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok670) {
  my_decimal decimal = {{0x607AF3B9, 0xA90EE1CF, 0x1F4315E4, 0x10000}};

  my_decimal decimal_check = {
      {0x607AF3B9, 0xA90EE1CF, 0x1F4315E4, 0x80010000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok671) {
  my_decimal decimal = {{0x30959EC8, 0x80650782, 0x7C655477, 0x180000}};

  my_decimal decimal_check = {
      {0x30959EC8, 0x80650782, 0x7C655477, 0x80180000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok672) {
  my_decimal decimal = {{0x30959EC8, 0x80650782, 0x7C655477, 0x80180000}};

  my_decimal decimal_check = {{0x30959EC8, 0x80650782, 0x7C655477, 0x180000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok673) {
  my_decimal decimal = {{0x5E7CAAC6, 0x5592C8F4, 0x17048114, 0x80170000}};

  my_decimal decimal_check = {{0x5E7CAAC6, 0x5592C8F4, 0x17048114, 0x170000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok674) {
  my_decimal decimal = {{0x5E7CAAC6, 0x5592C8F4, 0x17048114, 0x170000}};

  my_decimal decimal_check = {
      {0x5E7CAAC6, 0x5592C8F4, 0x17048114, 0x80170000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok675) {
  my_decimal decimal = {{0xE57A5A38, 0x6F244181, 0x3E9053DC, 0xE0000}};

  my_decimal decimal_check = {
      {0xE57A5A38, 0x6F244181, 0x3E9053DC, 0x800E0000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok676) {
  my_decimal decimal = {{0xE57A5A38, 0x6F244181, 0x3E9053DC, 0x800E0000}};

  my_decimal decimal_check = {{0xE57A5A38, 0x6F244181, 0x3E9053DC, 0xE0000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok677) {
  my_decimal decimal = {{0x24581DBB, 0x34187C7E, 0x83E56F43, 0x80000}};

  my_decimal decimal_check = {
      {0x24581DBB, 0x34187C7E, 0x83E56F43, 0x80080000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok678) {
  my_decimal decimal = {{0x24581DBB, 0x34187C7E, 0x83E56F43, 0x80080000}};

  my_decimal decimal_check = {{0x24581DBB, 0x34187C7E, 0x83E56F43, 0x80000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok679) {
  my_decimal decimal = {{0xBB8CC092, 0x7F2B3A7E, 0xFF13FFE3, 0x80050000}};

  my_decimal decimal_check = {{0xBB8CC092, 0x7F2B3A7E, 0xFF13FFE3, 0x50000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok680) {
  my_decimal decimal = {{0xBB8CC092, 0x7F2B3A7E, 0xFF13FFE3, 0x50000}};

  my_decimal decimal_check = {
      {0xBB8CC092, 0x7F2B3A7E, 0xFF13FFE3, 0x80050000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok681) {
  my_decimal decimal = {{0xDB1640E2, 0x81E77C2B, 0x34BC620C, 0x80120000}};

  my_decimal decimal_check = {{0xDB1640E2, 0x81E77C2B, 0x34BC620C, 0x120000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok682) {
  my_decimal decimal = {{0xDB1640E2, 0x81E77C2B, 0x34BC620C, 0x120000}};

  my_decimal decimal_check = {
      {0xDB1640E2, 0x81E77C2B, 0x34BC620C, 0x80120000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok683) {
  my_decimal decimal = {{0x2464E29E, 0x7BA3AF2B, 0xF4C9D966, 0x80010000}};

  my_decimal decimal_check = {{0x2464E29E, 0x7BA3AF2B, 0xF4C9D966, 0x10000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok684) {
  my_decimal decimal = {{0x2464E29E, 0x7BA3AF2B, 0xF4C9D966, 0x10000}};

  my_decimal decimal_check = {
      {0x2464E29E, 0x7BA3AF2B, 0xF4C9D966, 0x80010000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok685) {
  my_decimal decimal = {{0x44271D74, 0x239E94EA, 0xE6254AE3, 0x80130000}};

  my_decimal decimal_check = {{0x44271D74, 0x239E94EA, 0xE6254AE3, 0x130000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok686) {
  my_decimal decimal = {{0x44271D74, 0x239E94EA, 0xE6254AE3, 0x130000}};

  my_decimal decimal_check = {
      {0x44271D74, 0x239E94EA, 0xE6254AE3, 0x80130000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok687) {
  my_decimal decimal = {{0xC58F6366, 0x1D95F0B4, 0x996923E7, 0x180000}};

  my_decimal decimal_check = {
      {0xC58F6366, 0x1D95F0B4, 0x996923E7, 0x80180000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok688) {
  my_decimal decimal = {{0xC58F6366, 0x1D95F0B4, 0x996923E7, 0x80180000}};

  my_decimal decimal_check = {{0xC58F6366, 0x1D95F0B4, 0x996923E7, 0x180000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok689) {
  my_decimal decimal = {{0xA4157248, 0x45055A66, 0x99C2F276, 0x80130000}};

  my_decimal decimal_check = {{0xA4157248, 0x45055A66, 0x99C2F276, 0x130000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok690) {
  my_decimal decimal = {{0xA4157248, 0x45055A66, 0x99C2F276, 0x130000}};

  my_decimal decimal_check = {
      {0xA4157248, 0x45055A66, 0x99C2F276, 0x80130000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok691) {
  my_decimal decimal = {{0x6E41CDAA, 0xF41B262C, 0x19128D66, 0x80060000}};

  my_decimal decimal_check = {{0x6E41CDAA, 0xF41B262C, 0x19128D66, 0x60000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok692) {
  my_decimal decimal = {{0x6E41CDAA, 0xF41B262C, 0x19128D66, 0x60000}};

  my_decimal decimal_check = {
      {0x6E41CDAA, 0xF41B262C, 0x19128D66, 0x80060000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok693) {
  my_decimal decimal = {{0x4D36440F, 0x643BCEFF, 0x9EA24EE3, 0x801A0000}};

  my_decimal decimal_check = {{0x4D36440F, 0x643BCEFF, 0x9EA24EE3, 0x1A0000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok694) {
  my_decimal decimal = {{0x4D36440F, 0x643BCEFF, 0x9EA24EE3, 0x1A0000}};

  my_decimal decimal_check = {
      {0x4D36440F, 0x643BCEFF, 0x9EA24EE3, 0x801A0000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok695) {
  my_decimal decimal = {{0xC282BB74, 0x743068B, 0x19A84ABB, 0xF0000}};

  my_decimal decimal_check = {{0xC282BB74, 0x743068B, 0x19A84ABB, 0x800F0000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok696) {
  my_decimal decimal = {{0xC282BB74, 0x743068B, 0x19A84ABB, 0x800F0000}};

  my_decimal decimal_check = {{0xC282BB74, 0x743068B, 0x19A84ABB, 0xF0000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok697) {
  my_decimal decimal = {{0x670EA5AD, 0x32BD3BFC, 0xB24721D3, 0x80130000}};

  my_decimal decimal_check = {{0x670EA5AD, 0x32BD3BFC, 0xB24721D3, 0x130000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok698) {
  my_decimal decimal = {{0x670EA5AD, 0x32BD3BFC, 0xB24721D3, 0x130000}};

  my_decimal decimal_check = {
      {0x670EA5AD, 0x32BD3BFC, 0xB24721D3, 0x80130000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok699) {
  my_decimal decimal = {{0x8BC6937, 0x2E0C6D5F, 0x61AC0EA8, 0x800A0000}};

  my_decimal decimal_check = {{0x8BC6937, 0x2E0C6D5F, 0x61AC0EA8, 0xA0000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok700) {
  my_decimal decimal = {{0x8BC6937, 0x2E0C6D5F, 0x61AC0EA8, 0xA0000}};

  my_decimal decimal_check = {{0x8BC6937, 0x2E0C6D5F, 0x61AC0EA8, 0x800A0000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok701) {
  my_decimal decimal = {{0x1DDCB34F, 0x26EE55F0, 0xE95A6855, 0x80110000}};

  my_decimal decimal_check = {{0x1DDCB34F, 0x26EE55F0, 0xE95A6855, 0x110000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok702) {
  my_decimal decimal = {{0x1DDCB34F, 0x26EE55F0, 0xE95A6855, 0x110000}};

  my_decimal decimal_check = {
      {0x1DDCB34F, 0x26EE55F0, 0xE95A6855, 0x80110000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok703) {
  my_decimal decimal = {{0x3612BA60, 0x17661D9D, 0x4A698053, 0x800C0000}};

  my_decimal decimal_check = {{0x3612BA60, 0x17661D9D, 0x4A698053, 0xC0000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok704) {
  my_decimal decimal = {{0x3612BA60, 0x17661D9D, 0x4A698053, 0xC0000}};

  my_decimal decimal_check = {
      {0x3612BA60, 0x17661D9D, 0x4A698053, 0x800C0000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok705) {
  my_decimal decimal = {{0x57C31C58, 0x92E37D96, 0x388880F5, 0x170000}};

  my_decimal decimal_check = {
      {0x57C31C58, 0x92E37D96, 0x388880F5, 0x80170000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok706) {
  my_decimal decimal = {{0x57C31C58, 0x92E37D96, 0x388880F5, 0x80170000}};

  my_decimal decimal_check = {{0x57C31C58, 0x92E37D96, 0x388880F5, 0x170000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok707) {
  my_decimal decimal = {{0x927C0BC9, 0x732A076F, 0xF86B93C0, 0x40000}};

  my_decimal decimal_check = {
      {0x927C0BC9, 0x732A076F, 0xF86B93C0, 0x80040000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok708) {
  my_decimal decimal = {{0x927C0BC9, 0x732A076F, 0xF86B93C0, 0x80040000}};

  my_decimal decimal_check = {{0x927C0BC9, 0x732A076F, 0xF86B93C0, 0x40000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok709) {
  my_decimal decimal = {{0x35E8B286, 0x22AAADB, 0x7B4A2A8B, 0x100000}};

  my_decimal decimal_check = {{0x35E8B286, 0x22AAADB, 0x7B4A2A8B, 0x80100000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok710) {
  my_decimal decimal = {{0x35E8B286, 0x22AAADB, 0x7B4A2A8B, 0x80100000}};

  my_decimal decimal_check = {{0x35E8B286, 0x22AAADB, 0x7B4A2A8B, 0x100000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok711) {
  my_decimal decimal = {{0xAA152409, 0x2006919A, 0x97BAF732, 0x800C0000}};

  my_decimal decimal_check = {{0xAA152409, 0x2006919A, 0x97BAF732, 0xC0000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok712) {
  my_decimal decimal = {{0xAA152409, 0x2006919A, 0x97BAF732, 0xC0000}};

  my_decimal decimal_check = {
      {0xAA152409, 0x2006919A, 0x97BAF732, 0x800C0000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok713) {
  my_decimal decimal = {{0xD70A0DF0, 0xF4D591A7, 0x2A431815, 0x80000000}};

  my_decimal decimal_check = {{0xD70A0DF0, 0xF4D591A7, 0x2A431815, 0x0}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok714) {
  my_decimal decimal = {{0xD70A0DF0, 0xF4D591A7, 0x2A431815, 0x0}};

  my_decimal decimal_check = {
      {0xD70A0DF0, 0xF4D591A7, 0x2A431815, 0x80000000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok715) {
  my_decimal decimal = {{0x186292A2, 0xFABB014A, 0x626D0FF8, 0x80080000}};

  my_decimal decimal_check = {{0x186292A2, 0xFABB014A, 0x626D0FF8, 0x80000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok716) {
  my_decimal decimal = {{0x186292A2, 0xFABB014A, 0x626D0FF8, 0x80000}};

  my_decimal decimal_check = {
      {0x186292A2, 0xFABB014A, 0x626D0FF8, 0x80080000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok717) {
  my_decimal decimal = {{0x906D0F7F, 0xB6E9F6DB, 0xE834CCA7, 0x60000}};

  my_decimal decimal_check = {
      {0x906D0F7F, 0xB6E9F6DB, 0xE834CCA7, 0x80060000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok718) {
  my_decimal decimal = {{0x906D0F7F, 0xB6E9F6DB, 0xE834CCA7, 0x80060000}};

  my_decimal decimal_check = {{0x906D0F7F, 0xB6E9F6DB, 0xE834CCA7, 0x60000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok719) {
  my_decimal decimal = {{0xC7D48198, 0x5736C818, 0x66A68454, 0x1C0000}};

  my_decimal decimal_check = {
      {0xC7D48198, 0x5736C818, 0x66A68454, 0x801C0000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok720) {
  my_decimal decimal = {{0xC7D48198, 0x5736C818, 0x66A68454, 0x801C0000}};

  my_decimal decimal_check = {{0xC7D48198, 0x5736C818, 0x66A68454, 0x1C0000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok721) {
  my_decimal decimal = {{0xE6E6126E, 0x77E021DC, 0xE727B2F6, 0x1A0000}};

  my_decimal decimal_check = {
      {0xE6E6126E, 0x77E021DC, 0xE727B2F6, 0x801A0000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok722) {
  my_decimal decimal = {{0xE6E6126E, 0x77E021DC, 0xE727B2F6, 0x801A0000}};

  my_decimal decimal_check = {{0xE6E6126E, 0x77E021DC, 0xE727B2F6, 0x1A0000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok723) {
  my_decimal decimal = {{0x8BCE4957, 0xA320E48E, 0xD8FB34F5, 0x801B0000}};

  my_decimal decimal_check = {{0x8BCE4957, 0xA320E48E, 0xD8FB34F5, 0x1B0000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok724) {
  my_decimal decimal = {{0x8BCE4957, 0xA320E48E, 0xD8FB34F5, 0x1B0000}};

  my_decimal decimal_check = {
      {0x8BCE4957, 0xA320E48E, 0xD8FB34F5, 0x801B0000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok725) {
  my_decimal decimal = {{0xF7656BFD, 0xEB4C071D, 0xE2ECF79A, 0x140000}};

  my_decimal decimal_check = {
      {0xF7656BFD, 0xEB4C071D, 0xE2ECF79A, 0x80140000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok726) {
  my_decimal decimal = {{0xF7656BFD, 0xEB4C071D, 0xE2ECF79A, 0x80140000}};

  my_decimal decimal_check = {{0xF7656BFD, 0xEB4C071D, 0xE2ECF79A, 0x140000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok727) {
  my_decimal decimal = {{0x6FD60694, 0xB182FB09, 0xB2EB5F14, 0x140000}};

  my_decimal decimal_check = {
      {0x6FD60694, 0xB182FB09, 0xB2EB5F14, 0x80140000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok728) {
  my_decimal decimal = {{0x6FD60694, 0xB182FB09, 0xB2EB5F14, 0x80140000}};

  my_decimal decimal_check = {{0x6FD60694, 0xB182FB09, 0xB2EB5F14, 0x140000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok729) {
  my_decimal decimal = {{0x4C47227F, 0xAC76516C, 0x54F93EE0, 0x80130000}};

  my_decimal decimal_check = {{0x4C47227F, 0xAC76516C, 0x54F93EE0, 0x130000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok730) {
  my_decimal decimal = {{0x4C47227F, 0xAC76516C, 0x54F93EE0, 0x130000}};

  my_decimal decimal_check = {
      {0x4C47227F, 0xAC76516C, 0x54F93EE0, 0x80130000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok731) {
  my_decimal decimal = {{0xAA36C94A, 0xB79758E9, 0x788721E7, 0x80000000}};

  my_decimal decimal_check = {{0xAA36C94A, 0xB79758E9, 0x788721E7, 0x0}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok732) {
  my_decimal decimal = {{0xAA36C94A, 0xB79758E9, 0x788721E7, 0x0}};

  my_decimal decimal_check = {
      {0xAA36C94A, 0xB79758E9, 0x788721E7, 0x80000000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok733) {
  my_decimal decimal = {{0xED8A315F, 0xB27F7C0C, 0x4041DE30, 0x80030000}};

  my_decimal decimal_check = {{0xED8A315F, 0xB27F7C0C, 0x4041DE30, 0x30000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok734) {
  my_decimal decimal = {{0xED8A315F, 0xB27F7C0C, 0x4041DE30, 0x30000}};

  my_decimal decimal_check = {
      {0xED8A315F, 0xB27F7C0C, 0x4041DE30, 0x80030000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok735) {
  my_decimal decimal = {{0x4808FE88, 0xA1181C06, 0x794E20A0, 0x80100000}};

  my_decimal decimal_check = {{0x4808FE88, 0xA1181C06, 0x794E20A0, 0x100000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok736) {
  my_decimal decimal = {{0x4808FE88, 0xA1181C06, 0x794E20A0, 0x100000}};

  my_decimal decimal_check = {
      {0x4808FE88, 0xA1181C06, 0x794E20A0, 0x80100000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok737) {
  my_decimal decimal = {{0x5897EA48, 0x457A041A, 0x436A88B3, 0x800F0000}};

  my_decimal decimal_check = {{0x5897EA48, 0x457A041A, 0x436A88B3, 0xF0000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok738) {
  my_decimal decimal = {{0x5897EA48, 0x457A041A, 0x436A88B3, 0xF0000}};

  my_decimal decimal_check = {
      {0x5897EA48, 0x457A041A, 0x436A88B3, 0x800F0000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok739) {
  my_decimal decimal = {{0xF5F2A265, 0x681BB955, 0x3B3D5515, 0x80180000}};

  my_decimal decimal_check = {{0xF5F2A265, 0x681BB955, 0x3B3D5515, 0x180000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok740) {
  my_decimal decimal = {{0xF5F2A265, 0x681BB955, 0x3B3D5515, 0x180000}};

  my_decimal decimal_check = {
      {0xF5F2A265, 0x681BB955, 0x3B3D5515, 0x80180000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok741) {
  my_decimal decimal = {{0xD8EE2074, 0x265E79D6, 0x59442EF, 0x1A0000}};

  my_decimal decimal_check = {{0xD8EE2074, 0x265E79D6, 0x59442EF, 0x801A0000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok742) {
  my_decimal decimal = {{0xD8EE2074, 0x265E79D6, 0x59442EF, 0x801A0000}};

  my_decimal decimal_check = {{0xD8EE2074, 0x265E79D6, 0x59442EF, 0x1A0000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok743) {
  my_decimal decimal = {{0xC4E1CD72, 0x6BDB519C, 0x905A85D7, 0x80190000}};

  my_decimal decimal_check = {{0xC4E1CD72, 0x6BDB519C, 0x905A85D7, 0x190000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok744) {
  my_decimal decimal = {{0xC4E1CD72, 0x6BDB519C, 0x905A85D7, 0x190000}};

  my_decimal decimal_check = {
      {0xC4E1CD72, 0x6BDB519C, 0x905A85D7, 0x80190000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok745) {
  my_decimal decimal = {{0xC1125B87, 0xFA5EAAF2, 0x7533DCBE, 0x80110000}};

  my_decimal decimal_check = {{0xC1125B87, 0xFA5EAAF2, 0x7533DCBE, 0x110000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok746) {
  my_decimal decimal = {{0xC1125B87, 0xFA5EAAF2, 0x7533DCBE, 0x110000}};

  my_decimal decimal_check = {
      {0xC1125B87, 0xFA5EAAF2, 0x7533DCBE, 0x80110000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok747) {
  my_decimal decimal = {{0xCF514CFA, 0x25695B9B, 0xF5C0E4AA, 0x80190000}};

  my_decimal decimal_check = {{0xCF514CFA, 0x25695B9B, 0xF5C0E4AA, 0x190000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok748) {
  my_decimal decimal = {{0xCF514CFA, 0x25695B9B, 0xF5C0E4AA, 0x190000}};

  my_decimal decimal_check = {
      {0xCF514CFA, 0x25695B9B, 0xF5C0E4AA, 0x80190000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok749) {
  my_decimal decimal = {{0xCC6CC3B6, 0x8A1F97E8, 0xCC3C9401, 0x80190000}};

  my_decimal decimal_check = {{0xCC6CC3B6, 0x8A1F97E8, 0xCC3C9401, 0x190000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok750) {
  my_decimal decimal = {{0xCC6CC3B6, 0x8A1F97E8, 0xCC3C9401, 0x190000}};

  my_decimal decimal_check = {
      {0xCC6CC3B6, 0x8A1F97E8, 0xCC3C9401, 0x80190000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok751) {
  my_decimal decimal = {{0x1FF2CA1F, 0xFD692006, 0x26032738, 0xE0000}};

  my_decimal decimal_check = {
      {0x1FF2CA1F, 0xFD692006, 0x26032738, 0x800E0000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok752) {
  my_decimal decimal = {{0x1FF2CA1F, 0xFD692006, 0x26032738, 0x800E0000}};

  my_decimal decimal_check = {{0x1FF2CA1F, 0xFD692006, 0x26032738, 0xE0000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok753) {
  my_decimal decimal = {{0x2F11AA3E, 0x143B0D2C, 0x28215B96, 0x10000}};

  my_decimal decimal_check = {
      {0x2F11AA3E, 0x143B0D2C, 0x28215B96, 0x80010000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok754) {
  my_decimal decimal = {{0x2F11AA3E, 0x143B0D2C, 0x28215B96, 0x80010000}};

  my_decimal decimal_check = {{0x2F11AA3E, 0x143B0D2C, 0x28215B96, 0x10000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok755) {
  my_decimal decimal = {{0x2B2C3617, 0x90B65CE7, 0x620B06D3, 0x180000}};

  my_decimal decimal_check = {
      {0x2B2C3617, 0x90B65CE7, 0x620B06D3, 0x80180000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok756) {
  my_decimal decimal = {{0x2B2C3617, 0x90B65CE7, 0x620B06D3, 0x80180000}};

  my_decimal decimal_check = {{0x2B2C3617, 0x90B65CE7, 0x620B06D3, 0x180000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok757) {
  my_decimal decimal = {{0x2E4CC018, 0x2110157E, 0xE2768FC7, 0x120000}};

  my_decimal decimal_check = {
      {0x2E4CC018, 0x2110157E, 0xE2768FC7, 0x80120000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok758) {
  my_decimal decimal = {{0x2E4CC018, 0x2110157E, 0xE2768FC7, 0x80120000}};

  my_decimal decimal_check = {{0x2E4CC018, 0x2110157E, 0xE2768FC7, 0x120000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok759) {
  my_decimal decimal = {{0x6F16D9BB, 0x4B709662, 0x124DD51F, 0x70000}};

  my_decimal decimal_check = {
      {0x6F16D9BB, 0x4B709662, 0x124DD51F, 0x80070000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok760) {
  my_decimal decimal = {{0x6F16D9BB, 0x4B709662, 0x124DD51F, 0x80070000}};

  my_decimal decimal_check = {{0x6F16D9BB, 0x4B709662, 0x124DD51F, 0x70000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok761) {
  my_decimal decimal = {{0xEF38B9F5, 0x6157C9BB, 0x84A740E9, 0x80060000}};

  my_decimal decimal_check = {{0xEF38B9F5, 0x6157C9BB, 0x84A740E9, 0x60000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok762) {
  my_decimal decimal = {{0xEF38B9F5, 0x6157C9BB, 0x84A740E9, 0x60000}};

  my_decimal decimal_check = {
      {0xEF38B9F5, 0x6157C9BB, 0x84A740E9, 0x80060000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok763) {
  my_decimal decimal = {{0xF8F8030A, 0x5DEFF074, 0x898824F6, 0x80020000}};

  my_decimal decimal_check = {{0xF8F8030A, 0x5DEFF074, 0x898824F6, 0x20000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok764) {
  my_decimal decimal = {{0xF8F8030A, 0x5DEFF074, 0x898824F6, 0x20000}};

  my_decimal decimal_check = {
      {0xF8F8030A, 0x5DEFF074, 0x898824F6, 0x80020000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok765) {
  my_decimal decimal = {{0xCCCE331, 0x141BCF2F, 0xDFEFC5FA, 0x190000}};

  my_decimal decimal_check = {{0xCCCE331, 0x141BCF2F, 0xDFEFC5FA, 0x80190000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok766) {
  my_decimal decimal = {{0xCCCE331, 0x141BCF2F, 0xDFEFC5FA, 0x80190000}};

  my_decimal decimal_check = {{0xCCCE331, 0x141BCF2F, 0xDFEFC5FA, 0x190000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok767) {
  my_decimal decimal = {{0x58F2E915, 0x71EE87C9, 0x9E1DE6C5, 0x80040000}};

  my_decimal decimal_check = {{0x58F2E915, 0x71EE87C9, 0x9E1DE6C5, 0x40000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok768) {
  my_decimal decimal = {{0x58F2E915, 0x71EE87C9, 0x9E1DE6C5, 0x40000}};

  my_decimal decimal_check = {
      {0x58F2E915, 0x71EE87C9, 0x9E1DE6C5, 0x80040000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok769) {
  my_decimal decimal = {{0xCD6F165F, 0xBF46F2F9, 0x782C68C9, 0x80100000}};

  my_decimal decimal_check = {{0xCD6F165F, 0xBF46F2F9, 0x782C68C9, 0x100000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok770) {
  my_decimal decimal = {{0xCD6F165F, 0xBF46F2F9, 0x782C68C9, 0x100000}};

  my_decimal decimal_check = {
      {0xCD6F165F, 0xBF46F2F9, 0x782C68C9, 0x80100000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok771) {
  my_decimal decimal = {{0xF0CDB9C7, 0x75FE835D, 0x3DE565E0, 0x800C0000}};

  my_decimal decimal_check = {{0xF0CDB9C7, 0x75FE835D, 0x3DE565E0, 0xC0000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok772) {
  my_decimal decimal = {{0xF0CDB9C7, 0x75FE835D, 0x3DE565E0, 0xC0000}};

  my_decimal decimal_check = {
      {0xF0CDB9C7, 0x75FE835D, 0x3DE565E0, 0x800C0000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok773) {
  my_decimal decimal = {{0x356767E0, 0x81087394, 0x7738F796, 0x801A0000}};

  my_decimal decimal_check = {{0x356767E0, 0x81087394, 0x7738F796, 0x1A0000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok774) {
  my_decimal decimal = {{0x356767E0, 0x81087394, 0x7738F796, 0x1A0000}};

  my_decimal decimal_check = {
      {0x356767E0, 0x81087394, 0x7738F796, 0x801A0000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok775) {
  my_decimal decimal = {{0xF0068F96, 0x71E89536, 0x3A5F674C, 0x80090000}};

  my_decimal decimal_check = {{0xF0068F96, 0x71E89536, 0x3A5F674C, 0x90000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok776) {
  my_decimal decimal = {{0xF0068F96, 0x71E89536, 0x3A5F674C, 0x90000}};

  my_decimal decimal_check = {
      {0xF0068F96, 0x71E89536, 0x3A5F674C, 0x80090000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok777) {
  my_decimal decimal = {{0x24E5868A, 0x4A8DB43E, 0x543D9AD8, 0x80050000}};

  my_decimal decimal_check = {{0x24E5868A, 0x4A8DB43E, 0x543D9AD8, 0x50000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok778) {
  my_decimal decimal = {{0x24E5868A, 0x4A8DB43E, 0x543D9AD8, 0x50000}};

  my_decimal decimal_check = {
      {0x24E5868A, 0x4A8DB43E, 0x543D9AD8, 0x80050000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok779) {
  my_decimal decimal = {{0x35D5A2DE, 0xC858D3A2, 0xC77CD46F, 0x800B0000}};

  my_decimal decimal_check = {{0x35D5A2DE, 0xC858D3A2, 0xC77CD46F, 0xB0000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok780) {
  my_decimal decimal = {{0x35D5A2DE, 0xC858D3A2, 0xC77CD46F, 0xB0000}};

  my_decimal decimal_check = {
      {0x35D5A2DE, 0xC858D3A2, 0xC77CD46F, 0x800B0000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok781) {
  my_decimal decimal = {{0x47C6ABF7, 0xF4F2CCE9, 0x87B6A6CB, 0x800E0000}};

  my_decimal decimal_check = {{0x47C6ABF7, 0xF4F2CCE9, 0x87B6A6CB, 0xE0000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok782) {
  my_decimal decimal = {{0x47C6ABF7, 0xF4F2CCE9, 0x87B6A6CB, 0xE0000}};

  my_decimal decimal_check = {
      {0x47C6ABF7, 0xF4F2CCE9, 0x87B6A6CB, 0x800E0000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok783) {
  my_decimal decimal = {{0x7DDA5AAE, 0xF637FC56, 0x5600797, 0x150000}};

  my_decimal decimal_check = {{0x7DDA5AAE, 0xF637FC56, 0x5600797, 0x80150000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok784) {
  my_decimal decimal = {{0x7DDA5AAE, 0xF637FC56, 0x5600797, 0x80150000}};

  my_decimal decimal_check = {{0x7DDA5AAE, 0xF637FC56, 0x5600797, 0x150000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok785) {
  my_decimal decimal = {{0x4005F27A, 0x6F18F59, 0x3090C096, 0x800C0000}};

  my_decimal decimal_check = {{0x4005F27A, 0x6F18F59, 0x3090C096, 0xC0000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok786) {
  my_decimal decimal = {{0x4005F27A, 0x6F18F59, 0x3090C096, 0xC0000}};

  my_decimal decimal_check = {{0x4005F27A, 0x6F18F59, 0x3090C096, 0x800C0000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok787) {
  my_decimal decimal = {{0x8057F15A, 0x61A714D9, 0xFB08AD7E, 0x800B0000}};

  my_decimal decimal_check = {{0x8057F15A, 0x61A714D9, 0xFB08AD7E, 0xB0000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok788) {
  my_decimal decimal = {{0x8057F15A, 0x61A714D9, 0xFB08AD7E, 0xB0000}};

  my_decimal decimal_check = {
      {0x8057F15A, 0x61A714D9, 0xFB08AD7E, 0x800B0000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok789) {
  my_decimal decimal = {{0xF086279C, 0x544B4249, 0x926A7339, 0x40000}};

  my_decimal decimal_check = {
      {0xF086279C, 0x544B4249, 0x926A7339, 0x80040000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok790) {
  my_decimal decimal = {{0xF086279C, 0x544B4249, 0x926A7339, 0x80040000}};

  my_decimal decimal_check = {{0xF086279C, 0x544B4249, 0x926A7339, 0x40000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok791) {
  my_decimal decimal = {{0x93CABC9F, 0xEB46ED7B, 0xAD4F869A, 0x30000}};

  my_decimal decimal_check = {
      {0x93CABC9F, 0xEB46ED7B, 0xAD4F869A, 0x80030000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok792) {
  my_decimal decimal = {{0x93CABC9F, 0xEB46ED7B, 0xAD4F869A, 0x80030000}};

  my_decimal decimal_check = {{0x93CABC9F, 0xEB46ED7B, 0xAD4F869A, 0x30000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok793) {
  my_decimal decimal = {{0x96D02BA4, 0x5EF398A6, 0xB1150B75, 0x90000}};

  my_decimal decimal_check = {
      {0x96D02BA4, 0x5EF398A6, 0xB1150B75, 0x80090000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok794) {
  my_decimal decimal = {{0x96D02BA4, 0x5EF398A6, 0xB1150B75, 0x80090000}};

  my_decimal decimal_check = {{0x96D02BA4, 0x5EF398A6, 0xB1150B75, 0x90000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok795) {
  my_decimal decimal = {{0xDAC4B0B2, 0xEF82E661, 0x1FD6E512, 0x80160000}};

  my_decimal decimal_check = {{0xDAC4B0B2, 0xEF82E661, 0x1FD6E512, 0x160000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok796) {
  my_decimal decimal = {{0xDAC4B0B2, 0xEF82E661, 0x1FD6E512, 0x160000}};

  my_decimal decimal_check = {
      {0xDAC4B0B2, 0xEF82E661, 0x1FD6E512, 0x80160000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok797) {
  my_decimal decimal = {{0xA4DDE24B, 0xB70AAEFE, 0xD3079BD1, 0x140000}};

  my_decimal decimal_check = {
      {0xA4DDE24B, 0xB70AAEFE, 0xD3079BD1, 0x80140000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok798) {
  my_decimal decimal = {{0xA4DDE24B, 0xB70AAEFE, 0xD3079BD1, 0x80140000}};

  my_decimal decimal_check = {{0xA4DDE24B, 0xB70AAEFE, 0xD3079BD1, 0x140000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok799) {
  my_decimal decimal = {{0xAB5BA053, 0x26D4FEF7, 0x2CA92B75, 0x80150000}};

  my_decimal decimal_check = {{0xAB5BA053, 0x26D4FEF7, 0x2CA92B75, 0x150000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok800) {
  my_decimal decimal = {{0xAB5BA053, 0x26D4FEF7, 0x2CA92B75, 0x150000}};

  my_decimal decimal_check = {
      {0xAB5BA053, 0x26D4FEF7, 0x2CA92B75, 0x80150000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok801) {
  my_decimal decimal = {{0x48BC2FBD, 0xCADABF47, 0xC862CC84, 0x801C0000}};

  my_decimal decimal_check = {{0x48BC2FBD, 0xCADABF47, 0xC862CC84, 0x1C0000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok802) {
  my_decimal decimal = {{0x48BC2FBD, 0xCADABF47, 0xC862CC84, 0x1C0000}};

  my_decimal decimal_check = {
      {0x48BC2FBD, 0xCADABF47, 0xC862CC84, 0x801C0000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok803) {
  my_decimal decimal = {{0xFE6B9861, 0x8A8F808A, 0x6ACBC37C, 0x120000}};

  my_decimal decimal_check = {
      {0xFE6B9861, 0x8A8F808A, 0x6ACBC37C, 0x80120000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok804) {
  my_decimal decimal = {{0xFE6B9861, 0x8A8F808A, 0x6ACBC37C, 0x80120000}};

  my_decimal decimal_check = {{0xFE6B9861, 0x8A8F808A, 0x6ACBC37C, 0x120000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok805) {
  my_decimal decimal = {{0xC98CA81, 0xFB036440, 0x283C604B, 0xF0000}};

  my_decimal decimal_check = {{0xC98CA81, 0xFB036440, 0x283C604B, 0x800F0000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok806) {
  my_decimal decimal = {{0xC98CA81, 0xFB036440, 0x283C604B, 0x800F0000}};

  my_decimal decimal_check = {{0xC98CA81, 0xFB036440, 0x283C604B, 0xF0000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok807) {
  my_decimal decimal = {{0xE302242A, 0x6F8D44F8, 0xA77E84AE, 0x80100000}};

  my_decimal decimal_check = {{0xE302242A, 0x6F8D44F8, 0xA77E84AE, 0x100000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok808) {
  my_decimal decimal = {{0xE302242A, 0x6F8D44F8, 0xA77E84AE, 0x100000}};

  my_decimal decimal_check = {
      {0xE302242A, 0x6F8D44F8, 0xA77E84AE, 0x80100000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok809) {
  my_decimal decimal = {{0x4B70A11, 0xECD258D0, 0xDA67C2C7, 0x80030000}};

  my_decimal decimal_check = {{0x4B70A11, 0xECD258D0, 0xDA67C2C7, 0x30000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok810) {
  my_decimal decimal = {{0x4B70A11, 0xECD258D0, 0xDA67C2C7, 0x30000}};

  my_decimal decimal_check = {{0x4B70A11, 0xECD258D0, 0xDA67C2C7, 0x80030000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok811) {
  my_decimal decimal = {{0xF236B4A2, 0xF6FAD2C1, 0x5BC10F1F, 0x80180000}};

  my_decimal decimal_check = {{0xF236B4A2, 0xF6FAD2C1, 0x5BC10F1F, 0x180000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok812) {
  my_decimal decimal = {{0xF236B4A2, 0xF6FAD2C1, 0x5BC10F1F, 0x180000}};

  my_decimal decimal_check = {
      {0xF236B4A2, 0xF6FAD2C1, 0x5BC10F1F, 0x80180000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok813) {
  my_decimal decimal = {{0xA42E6E08, 0x4B7A7DD8, 0x75198BF9, 0x80030000}};

  my_decimal decimal_check = {{0xA42E6E08, 0x4B7A7DD8, 0x75198BF9, 0x30000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok814) {
  my_decimal decimal = {{0xA42E6E08, 0x4B7A7DD8, 0x75198BF9, 0x30000}};

  my_decimal decimal_check = {
      {0xA42E6E08, 0x4B7A7DD8, 0x75198BF9, 0x80030000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok815) {
  my_decimal decimal = {{0x3BB33CC9, 0xEF2DC0A1, 0x38061DC8, 0xF0000}};

  my_decimal decimal_check = {
      {0x3BB33CC9, 0xEF2DC0A1, 0x38061DC8, 0x800F0000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok816) {
  my_decimal decimal = {{0x3BB33CC9, 0xEF2DC0A1, 0x38061DC8, 0x800F0000}};

  my_decimal decimal_check = {{0x3BB33CC9, 0xEF2DC0A1, 0x38061DC8, 0xF0000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok817) {
  my_decimal decimal = {{0xE4B5DA95, 0x533B07AE, 0x995AE73B, 0xE0000}};

  my_decimal decimal_check = {
      {0xE4B5DA95, 0x533B07AE, 0x995AE73B, 0x800E0000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok818) {
  my_decimal decimal = {{0xE4B5DA95, 0x533B07AE, 0x995AE73B, 0x800E0000}};

  my_decimal decimal_check = {{0xE4B5DA95, 0x533B07AE, 0x995AE73B, 0xE0000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok819) {
  my_decimal decimal = {{0xDFF7E4B8, 0xB43A865D, 0x16A03D1C, 0x100000}};

  my_decimal decimal_check = {
      {0xDFF7E4B8, 0xB43A865D, 0x16A03D1C, 0x80100000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok820) {
  my_decimal decimal = {{0xDFF7E4B8, 0xB43A865D, 0x16A03D1C, 0x80100000}};

  my_decimal decimal_check = {{0xDFF7E4B8, 0xB43A865D, 0x16A03D1C, 0x100000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok821) {
  my_decimal decimal = {{0xA13B98EC, 0xEDD699C3, 0x7BF3F1D7, 0x80160000}};

  my_decimal decimal_check = {{0xA13B98EC, 0xEDD699C3, 0x7BF3F1D7, 0x160000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok822) {
  my_decimal decimal = {{0xA13B98EC, 0xEDD699C3, 0x7BF3F1D7, 0x160000}};

  my_decimal decimal_check = {
      {0xA13B98EC, 0xEDD699C3, 0x7BF3F1D7, 0x80160000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok823) {
  my_decimal decimal = {{0x745A49D7, 0x4E4C847D, 0x7C3BA616, 0x80110000}};

  my_decimal decimal_check = {{0x745A49D7, 0x4E4C847D, 0x7C3BA616, 0x110000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok824) {
  my_decimal decimal = {{0x745A49D7, 0x4E4C847D, 0x7C3BA616, 0x110000}};

  my_decimal decimal_check = {
      {0x745A49D7, 0x4E4C847D, 0x7C3BA616, 0x80110000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok825) {
  my_decimal decimal = {{0xCC9FEE11, 0x7687DD55, 0x714B6A4F, 0x1C0000}};

  my_decimal decimal_check = {
      {0xCC9FEE11, 0x7687DD55, 0x714B6A4F, 0x801C0000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok826) {
  my_decimal decimal = {{0xCC9FEE11, 0x7687DD55, 0x714B6A4F, 0x801C0000}};

  my_decimal decimal_check = {{0xCC9FEE11, 0x7687DD55, 0x714B6A4F, 0x1C0000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok827) {
  my_decimal decimal = {{0x980FFF1, 0xDC2696D, 0xB7203E6A, 0x800D0000}};

  my_decimal decimal_check = {{0x980FFF1, 0xDC2696D, 0xB7203E6A, 0xD0000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok828) {
  my_decimal decimal = {{0x980FFF1, 0xDC2696D, 0xB7203E6A, 0xD0000}};

  my_decimal decimal_check = {{0x980FFF1, 0xDC2696D, 0xB7203E6A, 0x800D0000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok829) {
  my_decimal decimal = {{0x2C2D73E9, 0x57DFC06B, 0xBF0E19B7, 0x80000000}};

  my_decimal decimal_check = {{0x2C2D73E9, 0x57DFC06B, 0xBF0E19B7, 0x0}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok830) {
  my_decimal decimal = {{0x2C2D73E9, 0x57DFC06B, 0xBF0E19B7, 0x0}};

  my_decimal decimal_check = {
      {0x2C2D73E9, 0x57DFC06B, 0xBF0E19B7, 0x80000000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok831) {
  my_decimal decimal = {{0xD289B852, 0x917E811F, 0x1B2BC6B, 0xC0000}};

  my_decimal decimal_check = {{0xD289B852, 0x917E811F, 0x1B2BC6B, 0x800C0000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok832) {
  my_decimal decimal = {{0xD289B852, 0x917E811F, 0x1B2BC6B, 0x800C0000}};

  my_decimal decimal_check = {{0xD289B852, 0x917E811F, 0x1B2BC6B, 0xC0000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok833) {
  my_decimal decimal = {{0x70110A39, 0x6E8B37A6, 0x66FC0D82, 0x80180000}};

  my_decimal decimal_check = {{0x70110A39, 0x6E8B37A6, 0x66FC0D82, 0x180000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok834) {
  my_decimal decimal = {{0x70110A39, 0x6E8B37A6, 0x66FC0D82, 0x180000}};

  my_decimal decimal_check = {
      {0x70110A39, 0x6E8B37A6, 0x66FC0D82, 0x80180000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok835) {
  my_decimal decimal = {{0x8346217E, 0xCE8E8756, 0xF6AF6146, 0x80090000}};

  my_decimal decimal_check = {{0x8346217E, 0xCE8E8756, 0xF6AF6146, 0x90000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok836) {
  my_decimal decimal = {{0x8346217E, 0xCE8E8756, 0xF6AF6146, 0x90000}};

  my_decimal decimal_check = {
      {0x8346217E, 0xCE8E8756, 0xF6AF6146, 0x80090000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok837) {
  my_decimal decimal = {{0x9345DF75, 0xCE2717AD, 0xE7D2B09E, 0x80010000}};

  my_decimal decimal_check = {{0x9345DF75, 0xCE2717AD, 0xE7D2B09E, 0x10000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok838) {
  my_decimal decimal = {{0x9345DF75, 0xCE2717AD, 0xE7D2B09E, 0x10000}};

  my_decimal decimal_check = {
      {0x9345DF75, 0xCE2717AD, 0xE7D2B09E, 0x80010000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok839) {
  my_decimal decimal = {{0x381AA4AB, 0x7BFFC2AD, 0x665049C4, 0x160000}};

  my_decimal decimal_check = {
      {0x381AA4AB, 0x7BFFC2AD, 0x665049C4, 0x80160000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok840) {
  my_decimal decimal = {{0x381AA4AB, 0x7BFFC2AD, 0x665049C4, 0x80160000}};

  my_decimal decimal_check = {{0x381AA4AB, 0x7BFFC2AD, 0x665049C4, 0x160000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok841) {
  my_decimal decimal = {{0x7C529B83, 0x3FC8EEA6, 0x76D4DBCD, 0x30000}};

  my_decimal decimal_check = {
      {0x7C529B83, 0x3FC8EEA6, 0x76D4DBCD, 0x80030000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok842) {
  my_decimal decimal = {{0x7C529B83, 0x3FC8EEA6, 0x76D4DBCD, 0x80030000}};

  my_decimal decimal_check = {{0x7C529B83, 0x3FC8EEA6, 0x76D4DBCD, 0x30000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok843) {
  my_decimal decimal = {{0x3AF61A13, 0x797CD646, 0x2A57B036, 0xE0000}};

  my_decimal decimal_check = {
      {0x3AF61A13, 0x797CD646, 0x2A57B036, 0x800E0000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok844) {
  my_decimal decimal = {{0x3AF61A13, 0x797CD646, 0x2A57B036, 0x800E0000}};

  my_decimal decimal_check = {{0x3AF61A13, 0x797CD646, 0x2A57B036, 0xE0000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok845) {
  my_decimal decimal = {{0x592E8D05, 0x47998A3F, 0x26EA10F2, 0x110000}};

  my_decimal decimal_check = {
      {0x592E8D05, 0x47998A3F, 0x26EA10F2, 0x80110000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok846) {
  my_decimal decimal = {{0x592E8D05, 0x47998A3F, 0x26EA10F2, 0x80110000}};

  my_decimal decimal_check = {{0x592E8D05, 0x47998A3F, 0x26EA10F2, 0x110000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok847) {
  my_decimal decimal = {{0xC2403067, 0x53AF2293, 0xB3DE7A4A, 0x60000}};

  my_decimal decimal_check = {
      {0xC2403067, 0x53AF2293, 0xB3DE7A4A, 0x80060000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok848) {
  my_decimal decimal = {{0xC2403067, 0x53AF2293, 0xB3DE7A4A, 0x80060000}};

  my_decimal decimal_check = {{0xC2403067, 0x53AF2293, 0xB3DE7A4A, 0x60000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok849) {
  my_decimal decimal = {{0xA937A119, 0x5E88E7F7, 0xD9D7C9BB, 0x80160000}};

  my_decimal decimal_check = {{0xA937A119, 0x5E88E7F7, 0xD9D7C9BB, 0x160000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok850) {
  my_decimal decimal = {{0xA937A119, 0x5E88E7F7, 0xD9D7C9BB, 0x160000}};

  my_decimal decimal_check = {
      {0xA937A119, 0x5E88E7F7, 0xD9D7C9BB, 0x80160000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok851) {
  my_decimal decimal = {{0x94643ABC, 0xDC74899A, 0x2C320357, 0x170000}};

  my_decimal decimal_check = {
      {0x94643ABC, 0xDC74899A, 0x2C320357, 0x80170000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok852) {
  my_decimal decimal = {{0x94643ABC, 0xDC74899A, 0x2C320357, 0x80170000}};

  my_decimal decimal_check = {{0x94643ABC, 0xDC74899A, 0x2C320357, 0x170000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok853) {
  my_decimal decimal = {{0x3CEC3FD0, 0x20CEE69B, 0x956AEF8F, 0x80150000}};

  my_decimal decimal_check = {{0x3CEC3FD0, 0x20CEE69B, 0x956AEF8F, 0x150000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok854) {
  my_decimal decimal = {{0x3CEC3FD0, 0x20CEE69B, 0x956AEF8F, 0x150000}};

  my_decimal decimal_check = {
      {0x3CEC3FD0, 0x20CEE69B, 0x956AEF8F, 0x80150000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok855) {
  my_decimal decimal = {{0xD3037C91, 0xA2C0238B, 0x83CE3FD4, 0x801B0000}};

  my_decimal decimal_check = {{0xD3037C91, 0xA2C0238B, 0x83CE3FD4, 0x1B0000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok856) {
  my_decimal decimal = {{0xD3037C91, 0xA2C0238B, 0x83CE3FD4, 0x1B0000}};

  my_decimal decimal_check = {
      {0xD3037C91, 0xA2C0238B, 0x83CE3FD4, 0x801B0000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok857) {
  my_decimal decimal = {{0xBEA33A68, 0x492C302B, 0xA0C60688, 0x800C0000}};

  my_decimal decimal_check = {{0xBEA33A68, 0x492C302B, 0xA0C60688, 0xC0000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok858) {
  my_decimal decimal = {{0xBEA33A68, 0x492C302B, 0xA0C60688, 0xC0000}};

  my_decimal decimal_check = {
      {0xBEA33A68, 0x492C302B, 0xA0C60688, 0x800C0000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok859) {
  my_decimal decimal = {{0xE7BD6913, 0x4C875CF8, 0x5C9C7750, 0x80090000}};

  my_decimal decimal_check = {{0xE7BD6913, 0x4C875CF8, 0x5C9C7750, 0x90000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok860) {
  my_decimal decimal = {{0xE7BD6913, 0x4C875CF8, 0x5C9C7750, 0x90000}};

  my_decimal decimal_check = {
      {0xE7BD6913, 0x4C875CF8, 0x5C9C7750, 0x80090000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok861) {
  my_decimal decimal = {{0xF1474B31, 0x80089C5A, 0xB0C016F9, 0x150000}};

  my_decimal decimal_check = {
      {0xF1474B31, 0x80089C5A, 0xB0C016F9, 0x80150000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok862) {
  my_decimal decimal = {{0xF1474B31, 0x80089C5A, 0xB0C016F9, 0x80150000}};

  my_decimal decimal_check = {{0xF1474B31, 0x80089C5A, 0xB0C016F9, 0x150000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok863) {
  my_decimal decimal = {{0x64B83A26, 0x7E973CF9, 0x863DACF, 0x801B0000}};

  my_decimal decimal_check = {{0x64B83A26, 0x7E973CF9, 0x863DACF, 0x1B0000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok864) {
  my_decimal decimal = {{0x64B83A26, 0x7E973CF9, 0x863DACF, 0x1B0000}};

  my_decimal decimal_check = {{0x64B83A26, 0x7E973CF9, 0x863DACF, 0x801B0000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok865) {
  my_decimal decimal = {{0xD75C6124, 0xE81598D1, 0xD5500148, 0x801A0000}};

  my_decimal decimal_check = {{0xD75C6124, 0xE81598D1, 0xD5500148, 0x1A0000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok866) {
  my_decimal decimal = {{0xD75C6124, 0xE81598D1, 0xD5500148, 0x1A0000}};

  my_decimal decimal_check = {
      {0xD75C6124, 0xE81598D1, 0xD5500148, 0x801A0000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok867) {
  my_decimal decimal = {{0x5F3BBCB3, 0x40813793, 0x4BA53652, 0x100000}};

  my_decimal decimal_check = {
      {0x5F3BBCB3, 0x40813793, 0x4BA53652, 0x80100000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok868) {
  my_decimal decimal = {{0x5F3BBCB3, 0x40813793, 0x4BA53652, 0x80100000}};

  my_decimal decimal_check = {{0x5F3BBCB3, 0x40813793, 0x4BA53652, 0x100000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok869) {
  my_decimal decimal = {{0xC0AAAF10, 0x68C37512, 0xF266A725, 0x800A0000}};

  my_decimal decimal_check = {{0xC0AAAF10, 0x68C37512, 0xF266A725, 0xA0000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok870) {
  my_decimal decimal = {{0xC0AAAF10, 0x68C37512, 0xF266A725, 0xA0000}};

  my_decimal decimal_check = {
      {0xC0AAAF10, 0x68C37512, 0xF266A725, 0x800A0000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok871) {
  my_decimal decimal = {{0x8125AA78, 0xFEFDC7F2, 0x8E177C19, 0x170000}};

  my_decimal decimal_check = {
      {0x8125AA78, 0xFEFDC7F2, 0x8E177C19, 0x80170000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok872) {
  my_decimal decimal = {{0x8125AA78, 0xFEFDC7F2, 0x8E177C19, 0x80170000}};

  my_decimal decimal_check = {{0x8125AA78, 0xFEFDC7F2, 0x8E177C19, 0x170000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok873) {
  my_decimal decimal = {{0x70DF0E2C, 0x76BC5FB6, 0x439C7168, 0xC0000}};

  my_decimal decimal_check = {
      {0x70DF0E2C, 0x76BC5FB6, 0x439C7168, 0x800C0000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok874) {
  my_decimal decimal = {{0x70DF0E2C, 0x76BC5FB6, 0x439C7168, 0x800C0000}};

  my_decimal decimal_check = {{0x70DF0E2C, 0x76BC5FB6, 0x439C7168, 0xC0000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok875) {
  my_decimal decimal = {{0x6FFCDFCD, 0x111DB09E, 0x9227363C, 0x50000}};

  my_decimal decimal_check = {
      {0x6FFCDFCD, 0x111DB09E, 0x9227363C, 0x80050000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok876) {
  my_decimal decimal = {{0x6FFCDFCD, 0x111DB09E, 0x9227363C, 0x80050000}};

  my_decimal decimal_check = {{0x6FFCDFCD, 0x111DB09E, 0x9227363C, 0x50000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok877) {
  my_decimal decimal = {{0xBF003468, 0xD34395C8, 0x9EAF4E82, 0x80030000}};

  my_decimal decimal_check = {{0xBF003468, 0xD34395C8, 0x9EAF4E82, 0x30000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok878) {
  my_decimal decimal = {{0xBF003468, 0xD34395C8, 0x9EAF4E82, 0x30000}};

  my_decimal decimal_check = {
      {0xBF003468, 0xD34395C8, 0x9EAF4E82, 0x80030000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok879) {
  my_decimal decimal = {{0xE8C83662, 0xF0856C18, 0x1380B418, 0x180000}};

  my_decimal decimal_check = {
      {0xE8C83662, 0xF0856C18, 0x1380B418, 0x80180000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok880) {
  my_decimal decimal = {{0xE8C83662, 0xF0856C18, 0x1380B418, 0x80180000}};

  my_decimal decimal_check = {{0xE8C83662, 0xF0856C18, 0x1380B418, 0x180000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok881) {
  my_decimal decimal = {{0xD57ECF8D, 0x65D432AD, 0xDE250EA3, 0x800E0000}};

  my_decimal decimal_check = {{0xD57ECF8D, 0x65D432AD, 0xDE250EA3, 0xE0000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok882) {
  my_decimal decimal = {{0xD57ECF8D, 0x65D432AD, 0xDE250EA3, 0xE0000}};

  my_decimal decimal_check = {
      {0xD57ECF8D, 0x65D432AD, 0xDE250EA3, 0x800E0000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok883) {
  my_decimal decimal = {{0x7A83E604, 0xBA3C8320, 0xCB197C0B, 0x80120000}};

  my_decimal decimal_check = {{0x7A83E604, 0xBA3C8320, 0xCB197C0B, 0x120000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok884) {
  my_decimal decimal = {{0x7A83E604, 0xBA3C8320, 0xCB197C0B, 0x120000}};

  my_decimal decimal_check = {
      {0x7A83E604, 0xBA3C8320, 0xCB197C0B, 0x80120000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok885) {
  my_decimal decimal = {{0xCA9ABD9B, 0xE7F49E, 0x4C3DA21F, 0x80030000}};

  my_decimal decimal_check = {{0xCA9ABD9B, 0xE7F49E, 0x4C3DA21F, 0x30000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok886) {
  my_decimal decimal = {{0xCA9ABD9B, 0xE7F49E, 0x4C3DA21F, 0x30000}};

  my_decimal decimal_check = {{0xCA9ABD9B, 0xE7F49E, 0x4C3DA21F, 0x80030000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok887) {
  my_decimal decimal = {{0xF7347993, 0x427543D8, 0xEF9610FE, 0x80050000}};

  my_decimal decimal_check = {{0xF7347993, 0x427543D8, 0xEF9610FE, 0x50000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok888) {
  my_decimal decimal = {{0xF7347993, 0x427543D8, 0xEF9610FE, 0x50000}};

  my_decimal decimal_check = {
      {0xF7347993, 0x427543D8, 0xEF9610FE, 0x80050000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok889) {
  my_decimal decimal = {{0xBF04E402, 0xA51AD7E, 0x34F51095, 0x80140000}};

  my_decimal decimal_check = {{0xBF04E402, 0xA51AD7E, 0x34F51095, 0x140000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok890) {
  my_decimal decimal = {{0xBF04E402, 0xA51AD7E, 0x34F51095, 0x140000}};

  my_decimal decimal_check = {{0xBF04E402, 0xA51AD7E, 0x34F51095, 0x80140000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok891) {
  my_decimal decimal = {{0xE80E8F53, 0x8F4FDA93, 0x39C16497, 0x80130000}};

  my_decimal decimal_check = {{0xE80E8F53, 0x8F4FDA93, 0x39C16497, 0x130000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok892) {
  my_decimal decimal = {{0xE80E8F53, 0x8F4FDA93, 0x39C16497, 0x130000}};

  my_decimal decimal_check = {
      {0xE80E8F53, 0x8F4FDA93, 0x39C16497, 0x80130000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok893) {
  my_decimal decimal = {{0x3022656, 0x789FBD26, 0x84B90FCD, 0xD0000}};

  my_decimal decimal_check = {{0x3022656, 0x789FBD26, 0x84B90FCD, 0x800D0000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok894) {
  my_decimal decimal = {{0x3022656, 0x789FBD26, 0x84B90FCD, 0x800D0000}};

  my_decimal decimal_check = {{0x3022656, 0x789FBD26, 0x84B90FCD, 0xD0000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok895) {
  my_decimal decimal = {{0x7EE5ACD1, 0x274997F0, 0x313D6309, 0x80060000}};

  my_decimal decimal_check = {{0x7EE5ACD1, 0x274997F0, 0x313D6309, 0x60000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok896) {
  my_decimal decimal = {{0x7EE5ACD1, 0x274997F0, 0x313D6309, 0x60000}};

  my_decimal decimal_check = {
      {0x7EE5ACD1, 0x274997F0, 0x313D6309, 0x80060000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok897) {
  my_decimal decimal = {{0x125684BC, 0x3411A44F, 0xAECFEB6D, 0x800F0000}};

  my_decimal decimal_check = {{0x125684BC, 0x3411A44F, 0xAECFEB6D, 0xF0000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok898) {
  my_decimal decimal = {{0x125684BC, 0x3411A44F, 0xAECFEB6D, 0xF0000}};

  my_decimal decimal_check = {
      {0x125684BC, 0x3411A44F, 0xAECFEB6D, 0x800F0000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok899) {
  my_decimal decimal = {{0xCDEC7D10, 0x93299859, 0xA6120AF9, 0x80180000}};

  my_decimal decimal_check = {{0xCDEC7D10, 0x93299859, 0xA6120AF9, 0x180000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok900) {
  my_decimal decimal = {{0xCDEC7D10, 0x93299859, 0xA6120AF9, 0x180000}};

  my_decimal decimal_check = {
      {0xCDEC7D10, 0x93299859, 0xA6120AF9, 0x80180000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok901) {
  my_decimal decimal = {{0x58B6A76C, 0xD57A6E93, 0x28A0CA24, 0xD0000}};

  my_decimal decimal_check = {
      {0x58B6A76C, 0xD57A6E93, 0x28A0CA24, 0x800D0000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok902) {
  my_decimal decimal = {{0x58B6A76C, 0xD57A6E93, 0x28A0CA24, 0x800D0000}};

  my_decimal decimal_check = {{0x58B6A76C, 0xD57A6E93, 0x28A0CA24, 0xD0000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok903) {
  my_decimal decimal = {{0x81F3D241, 0x232D423B, 0xDFA35211, 0x80030000}};

  my_decimal decimal_check = {{0x81F3D241, 0x232D423B, 0xDFA35211, 0x30000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok904) {
  my_decimal decimal = {{0x81F3D241, 0x232D423B, 0xDFA35211, 0x30000}};

  my_decimal decimal_check = {
      {0x81F3D241, 0x232D423B, 0xDFA35211, 0x80030000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok905) {
  my_decimal decimal = {{0xA0C1488B, 0x9C65CB43, 0xDF7E41E2, 0x80050000}};

  my_decimal decimal_check = {{0xA0C1488B, 0x9C65CB43, 0xDF7E41E2, 0x50000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok906) {
  my_decimal decimal = {{0xA0C1488B, 0x9C65CB43, 0xDF7E41E2, 0x50000}};

  my_decimal decimal_check = {
      {0xA0C1488B, 0x9C65CB43, 0xDF7E41E2, 0x80050000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok907) {
  my_decimal decimal = {{0x78A41F44, 0x2584D9A8, 0x406DFB06, 0x80110000}};

  my_decimal decimal_check = {{0x78A41F44, 0x2584D9A8, 0x406DFB06, 0x110000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok908) {
  my_decimal decimal = {{0x78A41F44, 0x2584D9A8, 0x406DFB06, 0x110000}};

  my_decimal decimal_check = {
      {0x78A41F44, 0x2584D9A8, 0x406DFB06, 0x80110000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok909) {
  my_decimal decimal = {{0xE92691D7, 0x27E65E1D, 0x521344EC, 0x10000}};

  my_decimal decimal_check = {
      {0xE92691D7, 0x27E65E1D, 0x521344EC, 0x80010000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok910) {
  my_decimal decimal = {{0xE92691D7, 0x27E65E1D, 0x521344EC, 0x80010000}};

  my_decimal decimal_check = {{0xE92691D7, 0x27E65E1D, 0x521344EC, 0x10000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok911) {
  my_decimal decimal = {{0xE2973714, 0x4F215521, 0x6963DD86, 0x80150000}};

  my_decimal decimal_check = {{0xE2973714, 0x4F215521, 0x6963DD86, 0x150000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok912) {
  my_decimal decimal = {{0xE2973714, 0x4F215521, 0x6963DD86, 0x150000}};

  my_decimal decimal_check = {
      {0xE2973714, 0x4F215521, 0x6963DD86, 0x80150000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok913) {
  my_decimal decimal = {{0x9CBE5556, 0x7C185F27, 0xD6CAF6C8, 0x90000}};

  my_decimal decimal_check = {
      {0x9CBE5556, 0x7C185F27, 0xD6CAF6C8, 0x80090000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok914) {
  my_decimal decimal = {{0x9CBE5556, 0x7C185F27, 0xD6CAF6C8, 0x80090000}};

  my_decimal decimal_check = {{0x9CBE5556, 0x7C185F27, 0xD6CAF6C8, 0x90000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok915) {
  my_decimal decimal = {{0x50B91C2C, 0xC4449934, 0xAE848DB1, 0xF0000}};

  my_decimal decimal_check = {
      {0x50B91C2C, 0xC4449934, 0xAE848DB1, 0x800F0000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok916) {
  my_decimal decimal = {{0x50B91C2C, 0xC4449934, 0xAE848DB1, 0x800F0000}};

  my_decimal decimal_check = {{0x50B91C2C, 0xC4449934, 0xAE848DB1, 0xF0000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok917) {
  my_decimal decimal = {{0x11536647, 0x7E528589, 0xF6CBA86, 0x80190000}};

  my_decimal decimal_check = {{0x11536647, 0x7E528589, 0xF6CBA86, 0x190000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok918) {
  my_decimal decimal = {{0x11536647, 0x7E528589, 0xF6CBA86, 0x190000}};

  my_decimal decimal_check = {{0x11536647, 0x7E528589, 0xF6CBA86, 0x80190000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok919) {
  my_decimal decimal = {{0x13C2D430, 0xDAAC7969, 0xAE7265C7, 0x80170000}};

  my_decimal decimal_check = {{0x13C2D430, 0xDAAC7969, 0xAE7265C7, 0x170000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok920) {
  my_decimal decimal = {{0x13C2D430, 0xDAAC7969, 0xAE7265C7, 0x170000}};

  my_decimal decimal_check = {
      {0x13C2D430, 0xDAAC7969, 0xAE7265C7, 0x80170000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok921) {
  my_decimal decimal = {{0x56102ED6, 0x182E1F3D, 0x555E65E2, 0x80110000}};

  my_decimal decimal_check = {{0x56102ED6, 0x182E1F3D, 0x555E65E2, 0x110000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok922) {
  my_decimal decimal = {{0x56102ED6, 0x182E1F3D, 0x555E65E2, 0x110000}};

  my_decimal decimal_check = {
      {0x56102ED6, 0x182E1F3D, 0x555E65E2, 0x80110000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok923) {
  my_decimal decimal = {{0x4DF19CF, 0x52C6DA25, 0xC1A8AB36, 0x80110000}};

  my_decimal decimal_check = {{0x4DF19CF, 0x52C6DA25, 0xC1A8AB36, 0x110000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok924) {
  my_decimal decimal = {{0x4DF19CF, 0x52C6DA25, 0xC1A8AB36, 0x110000}};

  my_decimal decimal_check = {{0x4DF19CF, 0x52C6DA25, 0xC1A8AB36, 0x80110000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok925) {
  my_decimal decimal = {{0xA0B76D0A, 0x58A0F672, 0xAC526D76, 0x80130000}};

  my_decimal decimal_check = {{0xA0B76D0A, 0x58A0F672, 0xAC526D76, 0x130000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok926) {
  my_decimal decimal = {{0xA0B76D0A, 0x58A0F672, 0xAC526D76, 0x130000}};

  my_decimal decimal_check = {
      {0xA0B76D0A, 0x58A0F672, 0xAC526D76, 0x80130000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok927) {
  my_decimal decimal = {{0xFE2A172F, 0xA42DE21B, 0x4E32DB7A, 0xB0000}};

  my_decimal decimal_check = {
      {0xFE2A172F, 0xA42DE21B, 0x4E32DB7A, 0x800B0000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok928) {
  my_decimal decimal = {{0xFE2A172F, 0xA42DE21B, 0x4E32DB7A, 0x800B0000}};

  my_decimal decimal_check = {{0xFE2A172F, 0xA42DE21B, 0x4E32DB7A, 0xB0000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok929) {
  my_decimal decimal = {{0x392A54CE, 0x854FA479, 0x4C7E1D5B, 0x160000}};

  my_decimal decimal_check = {
      {0x392A54CE, 0x854FA479, 0x4C7E1D5B, 0x80160000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok930) {
  my_decimal decimal = {{0x392A54CE, 0x854FA479, 0x4C7E1D5B, 0x80160000}};

  my_decimal decimal_check = {{0x392A54CE, 0x854FA479, 0x4C7E1D5B, 0x160000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok931) {
  my_decimal decimal = {{0x9760F34, 0xC807CCC, 0x95F95BE7, 0x170000}};

  my_decimal decimal_check = {{0x9760F34, 0xC807CCC, 0x95F95BE7, 0x80170000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok932) {
  my_decimal decimal = {{0x9760F34, 0xC807CCC, 0x95F95BE7, 0x80170000}};

  my_decimal decimal_check = {{0x9760F34, 0xC807CCC, 0x95F95BE7, 0x170000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok933) {
  my_decimal decimal = {{0xAAF50153, 0xA3A2F639, 0x374AAA1F, 0x80100000}};

  my_decimal decimal_check = {{0xAAF50153, 0xA3A2F639, 0x374AAA1F, 0x100000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok934) {
  my_decimal decimal = {{0xAAF50153, 0xA3A2F639, 0x374AAA1F, 0x100000}};

  my_decimal decimal_check = {
      {0xAAF50153, 0xA3A2F639, 0x374AAA1F, 0x80100000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok935) {
  my_decimal decimal = {{0xD32BE2E3, 0x3DD9DA46, 0xAC93A84C, 0x150000}};

  my_decimal decimal_check = {
      {0xD32BE2E3, 0x3DD9DA46, 0xAC93A84C, 0x80150000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok936) {
  my_decimal decimal = {{0xD32BE2E3, 0x3DD9DA46, 0xAC93A84C, 0x80150000}};

  my_decimal decimal_check = {{0xD32BE2E3, 0x3DD9DA46, 0xAC93A84C, 0x150000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok937) {
  my_decimal decimal = {{0x3687BC17, 0x723E60D0, 0x15FB818A, 0x80170000}};

  my_decimal decimal_check = {{0x3687BC17, 0x723E60D0, 0x15FB818A, 0x170000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok938) {
  my_decimal decimal = {{0x3687BC17, 0x723E60D0, 0x15FB818A, 0x170000}};

  my_decimal decimal_check = {
      {0x3687BC17, 0x723E60D0, 0x15FB818A, 0x80170000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok939) {
  my_decimal decimal = {{0xB6D6B300, 0x86E3FBF7, 0x899935D, 0xF0000}};

  my_decimal decimal_check = {{0xB6D6B300, 0x86E3FBF7, 0x899935D, 0x800F0000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok940) {
  my_decimal decimal = {{0xB6D6B300, 0x86E3FBF7, 0x899935D, 0x800F0000}};

  my_decimal decimal_check = {{0xB6D6B300, 0x86E3FBF7, 0x899935D, 0xF0000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok941) {
  my_decimal decimal = {{0x678377B2, 0xD9F94BB4, 0x9C92EFBD, 0x1C0000}};

  my_decimal decimal_check = {
      {0x678377B2, 0xD9F94BB4, 0x9C92EFBD, 0x801C0000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok942) {
  my_decimal decimal = {{0x678377B2, 0xD9F94BB4, 0x9C92EFBD, 0x801C0000}};

  my_decimal decimal_check = {{0x678377B2, 0xD9F94BB4, 0x9C92EFBD, 0x1C0000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok943) {
  my_decimal decimal = {{0xD505EF7F, 0xF87E6EBE, 0xA7D8BBFC, 0x140000}};

  my_decimal decimal_check = {
      {0xD505EF7F, 0xF87E6EBE, 0xA7D8BBFC, 0x80140000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok944) {
  my_decimal decimal = {{0xD505EF7F, 0xF87E6EBE, 0xA7D8BBFC, 0x80140000}};

  my_decimal decimal_check = {{0xD505EF7F, 0xF87E6EBE, 0xA7D8BBFC, 0x140000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok945) {
  my_decimal decimal = {{0xED336DD0, 0xF5D7683C, 0x53915374, 0x80040000}};

  my_decimal decimal_check = {{0xED336DD0, 0xF5D7683C, 0x53915374, 0x40000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok946) {
  my_decimal decimal = {{0xED336DD0, 0xF5D7683C, 0x53915374, 0x40000}};

  my_decimal decimal_check = {
      {0xED336DD0, 0xF5D7683C, 0x53915374, 0x80040000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok947) {
  my_decimal decimal = {{0x4B421FCF, 0x8896F2AE, 0x40865C6A, 0x80080000}};

  my_decimal decimal_check = {{0x4B421FCF, 0x8896F2AE, 0x40865C6A, 0x80000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok948) {
  my_decimal decimal = {{0x4B421FCF, 0x8896F2AE, 0x40865C6A, 0x80000}};

  my_decimal decimal_check = {
      {0x4B421FCF, 0x8896F2AE, 0x40865C6A, 0x80080000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok949) {
  my_decimal decimal = {{0x3F488717, 0x78E1B68A, 0xA1B267BE, 0x0}};

  my_decimal decimal_check = {
      {0x3F488717, 0x78E1B68A, 0xA1B267BE, 0x80000000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok950) {
  my_decimal decimal = {{0x3F488717, 0x78E1B68A, 0xA1B267BE, 0x80000000}};

  my_decimal decimal_check = {{0x3F488717, 0x78E1B68A, 0xA1B267BE, 0x0}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok951) {
  my_decimal decimal = {{0xC88FF3C7, 0xC757117B, 0x93CD4FB3, 0x80020000}};

  my_decimal decimal_check = {{0xC88FF3C7, 0xC757117B, 0x93CD4FB3, 0x20000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok952) {
  my_decimal decimal = {{0xC88FF3C7, 0xC757117B, 0x93CD4FB3, 0x20000}};

  my_decimal decimal_check = {
      {0xC88FF3C7, 0xC757117B, 0x93CD4FB3, 0x80020000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok953) {
  my_decimal decimal = {{0x692111E7, 0x9DD85508, 0xE9A5EA5E, 0x80030000}};

  my_decimal decimal_check = {{0x692111E7, 0x9DD85508, 0xE9A5EA5E, 0x30000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok954) {
  my_decimal decimal = {{0x692111E7, 0x9DD85508, 0xE9A5EA5E, 0x30000}};

  my_decimal decimal_check = {
      {0x692111E7, 0x9DD85508, 0xE9A5EA5E, 0x80030000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok955) {
  my_decimal decimal = {{0x4B462452, 0x73C9C3A3, 0xCCE626CD, 0x80060000}};

  my_decimal decimal_check = {{0x4B462452, 0x73C9C3A3, 0xCCE626CD, 0x60000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok956) {
  my_decimal decimal = {{0x4B462452, 0x73C9C3A3, 0xCCE626CD, 0x60000}};

  my_decimal decimal_check = {
      {0x4B462452, 0x73C9C3A3, 0xCCE626CD, 0x80060000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok957) {
  my_decimal decimal = {{0x39C9D4DD, 0x286A22A, 0x287F82EA, 0x800B0000}};

  my_decimal decimal_check = {{0x39C9D4DD, 0x286A22A, 0x287F82EA, 0xB0000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok958) {
  my_decimal decimal = {{0x39C9D4DD, 0x286A22A, 0x287F82EA, 0xB0000}};

  my_decimal decimal_check = {{0x39C9D4DD, 0x286A22A, 0x287F82EA, 0x800B0000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok959) {
  my_decimal decimal = {{0x2D0150D0, 0x9DE1362D, 0x619E475B, 0x801A0000}};

  my_decimal decimal_check = {{0x2D0150D0, 0x9DE1362D, 0x619E475B, 0x1A0000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok960) {
  my_decimal decimal = {{0x2D0150D0, 0x9DE1362D, 0x619E475B, 0x1A0000}};

  my_decimal decimal_check = {
      {0x2D0150D0, 0x9DE1362D, 0x619E475B, 0x801A0000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok961) {
  my_decimal decimal = {{0xC8DDFDFE, 0xDA2525F3, 0x9745B36D, 0x800C0000}};

  my_decimal decimal_check = {{0xC8DDFDFE, 0xDA2525F3, 0x9745B36D, 0xC0000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok962) {
  my_decimal decimal = {{0xC8DDFDFE, 0xDA2525F3, 0x9745B36D, 0xC0000}};

  my_decimal decimal_check = {
      {0xC8DDFDFE, 0xDA2525F3, 0x9745B36D, 0x800C0000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok963) {
  my_decimal decimal = {{0xA75C4A93, 0x1E207895, 0x3D5F8021, 0x80100000}};

  my_decimal decimal_check = {{0xA75C4A93, 0x1E207895, 0x3D5F8021, 0x100000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok964) {
  my_decimal decimal = {{0xA75C4A93, 0x1E207895, 0x3D5F8021, 0x100000}};

  my_decimal decimal_check = {
      {0xA75C4A93, 0x1E207895, 0x3D5F8021, 0x80100000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok965) {
  my_decimal decimal = {{0xEECBC827, 0xCC6BCF7F, 0x5481842, 0x800B0000}};

  my_decimal decimal_check = {{0xEECBC827, 0xCC6BCF7F, 0x5481842, 0xB0000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok966) {
  my_decimal decimal = {{0xEECBC827, 0xCC6BCF7F, 0x5481842, 0xB0000}};

  my_decimal decimal_check = {{0xEECBC827, 0xCC6BCF7F, 0x5481842, 0x800B0000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok967) {
  my_decimal decimal = {{0x924557FB, 0xA75D6FC7, 0xEB8F0EED, 0x801B0000}};

  my_decimal decimal_check = {{0x924557FB, 0xA75D6FC7, 0xEB8F0EED, 0x1B0000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok968) {
  my_decimal decimal = {{0x924557FB, 0xA75D6FC7, 0xEB8F0EED, 0x1B0000}};

  my_decimal decimal_check = {
      {0x924557FB, 0xA75D6FC7, 0xEB8F0EED, 0x801B0000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok969) {
  my_decimal decimal = {{0x33FBFC2, 0x39B55CFA, 0x91E9B54, 0x800A0000}};

  my_decimal decimal_check = {{0x33FBFC2, 0x39B55CFA, 0x91E9B54, 0xA0000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok970) {
  my_decimal decimal = {{0x33FBFC2, 0x39B55CFA, 0x91E9B54, 0xA0000}};

  my_decimal decimal_check = {{0x33FBFC2, 0x39B55CFA, 0x91E9B54, 0x800A0000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok971) {
  my_decimal decimal = {{0xCBEC4821, 0x2BED059E, 0x9C06E75D, 0x0}};

  my_decimal decimal_check = {
      {0xCBEC4821, 0x2BED059E, 0x9C06E75D, 0x80000000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok972) {
  my_decimal decimal = {{0xCBEC4821, 0x2BED059E, 0x9C06E75D, 0x80000000}};

  my_decimal decimal_check = {{0xCBEC4821, 0x2BED059E, 0x9C06E75D, 0x0}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok973) {
  my_decimal decimal = {{0xE6050530, 0xA14AFA9D, 0xCED0E25C, 0x30000}};

  my_decimal decimal_check = {
      {0xE6050530, 0xA14AFA9D, 0xCED0E25C, 0x80030000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok974) {
  my_decimal decimal = {{0xE6050530, 0xA14AFA9D, 0xCED0E25C, 0x80030000}};

  my_decimal decimal_check = {{0xE6050530, 0xA14AFA9D, 0xCED0E25C, 0x30000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok975) {
  my_decimal decimal = {{0x1D2B3385, 0x110998EA, 0x96B5E8BD, 0x0}};

  my_decimal decimal_check = {
      {0x1D2B3385, 0x110998EA, 0x96B5E8BD, 0x80000000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok976) {
  my_decimal decimal = {{0x1D2B3385, 0x110998EA, 0x96B5E8BD, 0x80000000}};

  my_decimal decimal_check = {{0x1D2B3385, 0x110998EA, 0x96B5E8BD, 0x0}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok977) {
  my_decimal decimal = {{0xC45732F1, 0xFF3BD529, 0x285AD1B, 0x800A0000}};

  my_decimal decimal_check = {{0xC45732F1, 0xFF3BD529, 0x285AD1B, 0xA0000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok978) {
  my_decimal decimal = {{0xC45732F1, 0xFF3BD529, 0x285AD1B, 0xA0000}};

  my_decimal decimal_check = {{0xC45732F1, 0xFF3BD529, 0x285AD1B, 0x800A0000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok979) {
  my_decimal decimal = {{0xED2521CF, 0xB678D50C, 0x35A8CFB3, 0x80140000}};

  my_decimal decimal_check = {{0xED2521CF, 0xB678D50C, 0x35A8CFB3, 0x140000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok980) {
  my_decimal decimal = {{0xED2521CF, 0xB678D50C, 0x35A8CFB3, 0x140000}};

  my_decimal decimal_check = {
      {0xED2521CF, 0xB678D50C, 0x35A8CFB3, 0x80140000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok981) {
  my_decimal decimal = {{0xD8C98A8, 0x3BB520F5, 0x74775BA, 0x80000000}};

  my_decimal decimal_check = {{0xD8C98A8, 0x3BB520F5, 0x74775BA, 0x0}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok982) {
  my_decimal decimal = {{0xD8C98A8, 0x3BB520F5, 0x74775BA, 0x0}};

  my_decimal decimal_check = {{0xD8C98A8, 0x3BB520F5, 0x74775BA, 0x80000000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok983) {
  my_decimal decimal = {{0x2B956F22, 0x9EF12A57, 0x8A28885E, 0x80050000}};

  my_decimal decimal_check = {{0x2B956F22, 0x9EF12A57, 0x8A28885E, 0x50000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok984) {
  my_decimal decimal = {{0x2B956F22, 0x9EF12A57, 0x8A28885E, 0x50000}};

  my_decimal decimal_check = {
      {0x2B956F22, 0x9EF12A57, 0x8A28885E, 0x80050000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok985) {
  my_decimal decimal = {{0xD40B56FE, 0x88531CB2, 0x96648B40, 0x80080000}};

  my_decimal decimal_check = {{0xD40B56FE, 0x88531CB2, 0x96648B40, 0x80000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok986) {
  my_decimal decimal = {{0xD40B56FE, 0x88531CB2, 0x96648B40, 0x80000}};

  my_decimal decimal_check = {
      {0xD40B56FE, 0x88531CB2, 0x96648B40, 0x80080000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok987) {
  my_decimal decimal = {{0x41D65E9A, 0x2A70ACE4, 0x60B1D1F6, 0x130000}};

  my_decimal decimal_check = {
      {0x41D65E9A, 0x2A70ACE4, 0x60B1D1F6, 0x80130000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok988) {
  my_decimal decimal = {{0x41D65E9A, 0x2A70ACE4, 0x60B1D1F6, 0x80130000}};

  my_decimal decimal_check = {{0x41D65E9A, 0x2A70ACE4, 0x60B1D1F6, 0x130000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok989) {
  my_decimal decimal = {{0xFB320257, 0x3DDC0940, 0x6176FCFA, 0x800A0000}};

  my_decimal decimal_check = {{0xFB320257, 0x3DDC0940, 0x6176FCFA, 0xA0000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok990) {
  my_decimal decimal = {{0xFB320257, 0x3DDC0940, 0x6176FCFA, 0xA0000}};

  my_decimal decimal_check = {
      {0xFB320257, 0x3DDC0940, 0x6176FCFA, 0x800A0000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok991) {
  my_decimal decimal = {{0x1C6359FA, 0xF4A4027C, 0xAED1D66, 0x140000}};

  my_decimal decimal_check = {{0x1C6359FA, 0xF4A4027C, 0xAED1D66, 0x80140000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok992) {
  my_decimal decimal = {{0x1C6359FA, 0xF4A4027C, 0xAED1D66, 0x80140000}};

  my_decimal decimal_check = {{0x1C6359FA, 0xF4A4027C, 0xAED1D66, 0x140000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok993) {
  my_decimal decimal = {{0xE2C9AA84, 0x63E0C758, 0xD3C55107, 0x800E0000}};

  my_decimal decimal_check = {{0xE2C9AA84, 0x63E0C758, 0xD3C55107, 0xE0000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok994) {
  my_decimal decimal = {{0xE2C9AA84, 0x63E0C758, 0xD3C55107, 0xE0000}};

  my_decimal decimal_check = {
      {0xE2C9AA84, 0x63E0C758, 0xD3C55107, 0x800E0000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok995) {
  my_decimal decimal = {{0x51EB866E, 0xED244119, 0x3D2ECBEA, 0xA0000}};

  my_decimal decimal_check = {
      {0x51EB866E, 0xED244119, 0x3D2ECBEA, 0x800A0000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok996) {
  my_decimal decimal = {{0x51EB866E, 0xED244119, 0x3D2ECBEA, 0x800A0000}};

  my_decimal decimal_check = {{0x51EB866E, 0xED244119, 0x3D2ECBEA, 0xA0000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok997) {
  my_decimal decimal = {{0xB1205108, 0xCE1E0202, 0xA3C88951, 0x80000000}};

  my_decimal decimal_check = {{0xB1205108, 0xCE1E0202, 0xA3C88951, 0x0}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok998) {
  my_decimal decimal = {{0xB1205108, 0xCE1E0202, 0xA3C88951, 0x0}};

  my_decimal decimal_check = {
      {0xB1205108, 0xCE1E0202, 0xA3C88951, 0x80000000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok999) {
  my_decimal decimal = {{0xD1B953A5, 0x2D2C928A, 0xB7FBC28E, 0x80070000}};

  my_decimal decimal_check = {{0xD1B953A5, 0x2D2C928A, 0xB7FBC28E, 0x70000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok1000) {
  my_decimal decimal = {{0xD1B953A5, 0x2D2C928A, 0xB7FBC28E, 0x70000}};

  my_decimal decimal_check = {
      {0xD1B953A5, 0x2D2C928A, 0xB7FBC28E, 0x80070000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok1001) {
  my_decimal decimal = {{0xD4363600, 0x3C647D46, 0xEED7AE29, 0x10000}};

  my_decimal decimal_check = {
      {0xD4363600, 0x3C647D46, 0xEED7AE29, 0x80010000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok1002) {
  my_decimal decimal = {{0xD4363600, 0x3C647D46, 0xEED7AE29, 0x80010000}};

  my_decimal decimal_check = {{0xD4363600, 0x3C647D46, 0xEED7AE29, 0x10000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok1003) {
  my_decimal decimal = {{0x37B8D16B, 0xA369F4E6, 0xD9B879D2, 0x90000}};

  my_decimal decimal_check = {
      {0x37B8D16B, 0xA369F4E6, 0xD9B879D2, 0x80090000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok1004) {
  my_decimal decimal = {{0x37B8D16B, 0xA369F4E6, 0xD9B879D2, 0x80090000}};

  my_decimal decimal_check = {{0x37B8D16B, 0xA369F4E6, 0xD9B879D2, 0x90000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok1005) {
  my_decimal decimal = {{0x4B9DC6F4, 0x6594B4BA, 0x7D6052FE, 0xA0000}};

  my_decimal decimal_check = {
      {0x4B9DC6F4, 0x6594B4BA, 0x7D6052FE, 0x800A0000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok1006) {
  my_decimal decimal = {{0x4B9DC6F4, 0x6594B4BA, 0x7D6052FE, 0x800A0000}};

  my_decimal decimal_check = {{0x4B9DC6F4, 0x6594B4BA, 0x7D6052FE, 0xA0000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok1007) {
  my_decimal decimal = {{0x12159BD3, 0x3F977FBD, 0xA8C4C6DB, 0x800C0000}};

  my_decimal decimal_check = {{0x12159BD3, 0x3F977FBD, 0xA8C4C6DB, 0xC0000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok1008) {
  my_decimal decimal = {{0x12159BD3, 0x3F977FBD, 0xA8C4C6DB, 0xC0000}};

  my_decimal decimal_check = {
      {0x12159BD3, 0x3F977FBD, 0xA8C4C6DB, 0x800C0000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok1009) {
  my_decimal decimal = {{0xFDDBC750, 0x4985467C, 0xF63831D1, 0x170000}};

  my_decimal decimal_check = {
      {0xFDDBC750, 0x4985467C, 0xF63831D1, 0x80170000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok1010) {
  my_decimal decimal = {{0xFDDBC750, 0x4985467C, 0xF63831D1, 0x80170000}};

  my_decimal decimal_check = {{0xFDDBC750, 0x4985467C, 0xF63831D1, 0x170000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok1011) {
  my_decimal decimal = {{0x783F9D11, 0xE71F058C, 0xAAA8662B, 0xE0000}};

  my_decimal decimal_check = {
      {0x783F9D11, 0xE71F058C, 0xAAA8662B, 0x800E0000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok1012) {
  my_decimal decimal = {{0x783F9D11, 0xE71F058C, 0xAAA8662B, 0x800E0000}};

  my_decimal decimal_check = {{0x783F9D11, 0xE71F058C, 0xAAA8662B, 0xE0000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok1013) {
  my_decimal decimal = {{0x8381489, 0x599DA089, 0xAC532A50, 0x120000}};

  my_decimal decimal_check = {{0x8381489, 0x599DA089, 0xAC532A50, 0x80120000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok1014) {
  my_decimal decimal = {{0x8381489, 0x599DA089, 0xAC532A50, 0x80120000}};

  my_decimal decimal_check = {{0x8381489, 0x599DA089, 0xAC532A50, 0x120000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok1015) {
  my_decimal decimal = {{0x23BBE754, 0xD07AAACA, 0x455F2C3D, 0x60000}};

  my_decimal decimal_check = {
      {0x23BBE754, 0xD07AAACA, 0x455F2C3D, 0x80060000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok1016) {
  my_decimal decimal = {{0x23BBE754, 0xD07AAACA, 0x455F2C3D, 0x80060000}};

  my_decimal decimal_check = {{0x23BBE754, 0xD07AAACA, 0x455F2C3D, 0x60000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok1017) {
  my_decimal decimal = {{0x32F40A73, 0xA632221, 0x9C02A178, 0x800F0000}};

  my_decimal decimal_check = {{0x32F40A73, 0xA632221, 0x9C02A178, 0xF0000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok1018) {
  my_decimal decimal = {{0x32F40A73, 0xA632221, 0x9C02A178, 0xF0000}};

  my_decimal decimal_check = {{0x32F40A73, 0xA632221, 0x9C02A178, 0x800F0000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok1019) {
  my_decimal decimal = {{0xC2E01814, 0x66150693, 0xF030E554, 0x80110000}};

  my_decimal decimal_check = {{0xC2E01814, 0x66150693, 0xF030E554, 0x110000}};

  test_negate(decimal, decimal_check);
}

START_TEST(test_negate_ok1020) {
  my_decimal decimal = {{0xC2E01814, 0x66150693, 0xF030E554, 0x110000}};

  my_decimal decimal_check = {
      {0xC2E01814, 0x66150693, 0xF030E554, 0x80110000}};

  test_negate(decimal, decimal_check);
}

Suite *negate_suite1(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("negate_suite1");
  tc_core = tcase_create("Core");
  tcase_add_test(tc_core, test_negate_ok1);
  tcase_add_test(tc_core, test_negate_ok2);
  tcase_add_test(tc_core, test_negate_ok3);
  tcase_add_test(tc_core, test_negate_ok4);
  tcase_add_test(tc_core, test_negate_ok5);
  tcase_add_test(tc_core, test_negate_ok6);
  tcase_add_test(tc_core, test_negate_ok7);
  tcase_add_test(tc_core, test_negate_ok8);
  tcase_add_test(tc_core, test_negate_ok9);
  tcase_add_test(tc_core, test_negate_ok10);
  tcase_add_test(tc_core, test_negate_ok11);
  tcase_add_test(tc_core, test_negate_ok12);
  tcase_add_test(tc_core, test_negate_ok13);
  tcase_add_test(tc_core, test_negate_ok14);
  tcase_add_test(tc_core, test_negate_ok15);
  tcase_add_test(tc_core, test_negate_ok16);
  tcase_add_test(tc_core, test_negate_ok17);
  tcase_add_test(tc_core, test_negate_ok18);
  tcase_add_test(tc_core, test_negate_ok19);
  tcase_add_test(tc_core, test_negate_ok20);
  tcase_add_test(tc_core, test_negate_ok21);
  tcase_add_test(tc_core, test_negate_ok22);
  tcase_add_test(tc_core, test_negate_ok23);
  tcase_add_test(tc_core, test_negate_ok24);
  tcase_add_test(tc_core, test_negate_ok25);
  tcase_add_test(tc_core, test_negate_ok26);
  tcase_add_test(tc_core, test_negate_ok27);
  tcase_add_test(tc_core, test_negate_ok28);
  tcase_add_test(tc_core, test_negate_ok29);
  tcase_add_test(tc_core, test_negate_ok30);
  tcase_add_test(tc_core, test_negate_ok31);
  tcase_add_test(tc_core, test_negate_ok32);
  tcase_add_test(tc_core, test_negate_ok33);
  tcase_add_test(tc_core, test_negate_ok34);
  tcase_add_test(tc_core, test_negate_ok35);
  tcase_add_test(tc_core, test_negate_ok36);
  tcase_add_test(tc_core, test_negate_ok37);
  tcase_add_test(tc_core, test_negate_ok38);
  tcase_add_test(tc_core, test_negate_ok39);
  tcase_add_test(tc_core, test_negate_ok40);
  tcase_add_test(tc_core, test_negate_ok41);
  tcase_add_test(tc_core, test_negate_ok42);
  tcase_add_test(tc_core, test_negate_ok43);
  tcase_add_test(tc_core, test_negate_ok44);
  tcase_add_test(tc_core, test_negate_ok45);
  tcase_add_test(tc_core, test_negate_ok46);
  tcase_add_test(tc_core, test_negate_ok47);
  tcase_add_test(tc_core, test_negate_ok48);
  tcase_add_test(tc_core, test_negate_ok49);
  tcase_add_test(tc_core, test_negate_ok50);
  tcase_add_test(tc_core, test_negate_ok51);
  tcase_add_test(tc_core, test_negate_ok52);
  tcase_add_test(tc_core, test_negate_ok53);
  tcase_add_test(tc_core, test_negate_ok54);
  tcase_add_test(tc_core, test_negate_ok55);
  tcase_add_test(tc_core, test_negate_ok56);
  tcase_add_test(tc_core, test_negate_ok57);
  tcase_add_test(tc_core, test_negate_ok58);
  tcase_add_test(tc_core, test_negate_ok59);
  tcase_add_test(tc_core, test_negate_ok60);
  tcase_add_test(tc_core, test_negate_ok61);
  tcase_add_test(tc_core, test_negate_ok62);
  tcase_add_test(tc_core, test_negate_ok63);
  tcase_add_test(tc_core, test_negate_ok64);
  tcase_add_test(tc_core, test_negate_ok65);
  tcase_add_test(tc_core, test_negate_ok66);
  tcase_add_test(tc_core, test_negate_ok67);
  tcase_add_test(tc_core, test_negate_ok68);
  tcase_add_test(tc_core, test_negate_ok69);
  tcase_add_test(tc_core, test_negate_ok70);
  tcase_add_test(tc_core, test_negate_ok71);
  tcase_add_test(tc_core, test_negate_ok72);
  tcase_add_test(tc_core, test_negate_ok73);
  tcase_add_test(tc_core, test_negate_ok74);
  tcase_add_test(tc_core, test_negate_ok75);
  tcase_add_test(tc_core, test_negate_ok76);
  tcase_add_test(tc_core, test_negate_ok77);
  tcase_add_test(tc_core, test_negate_ok78);
  tcase_add_test(tc_core, test_negate_ok79);
  tcase_add_test(tc_core, test_negate_ok80);
  tcase_add_test(tc_core, test_negate_ok81);
  tcase_add_test(tc_core, test_negate_ok82);
  tcase_add_test(tc_core, test_negate_ok83);
  tcase_add_test(tc_core, test_negate_ok84);
  tcase_add_test(tc_core, test_negate_ok85);
  tcase_add_test(tc_core, test_negate_ok86);
  tcase_add_test(tc_core, test_negate_ok87);
  tcase_add_test(tc_core, test_negate_ok88);
  tcase_add_test(tc_core, test_negate_ok89);
  tcase_add_test(tc_core, test_negate_ok90);
  tcase_add_test(tc_core, test_negate_ok91);
  tcase_add_test(tc_core, test_negate_ok92);
  tcase_add_test(tc_core, test_negate_ok93);
  tcase_add_test(tc_core, test_negate_ok94);
  tcase_add_test(tc_core, test_negate_ok95);
  tcase_add_test(tc_core, test_negate_ok96);
  tcase_add_test(tc_core, test_negate_ok97);
  tcase_add_test(tc_core, test_negate_ok98);
  tcase_add_test(tc_core, test_negate_ok99);
  tcase_add_test(tc_core, test_negate_ok100);
  tcase_add_test(tc_core, test_negate_ok101);
  tcase_add_test(tc_core, test_negate_ok102);
  tcase_add_test(tc_core, test_negate_ok103);
  tcase_add_test(tc_core, test_negate_ok104);
  tcase_add_test(tc_core, test_negate_ok105);
  tcase_add_test(tc_core, test_negate_ok106);
  tcase_add_test(tc_core, test_negate_ok107);
  tcase_add_test(tc_core, test_negate_ok108);
  tcase_add_test(tc_core, test_negate_ok109);
  tcase_add_test(tc_core, test_negate_ok110);
  tcase_add_test(tc_core, test_negate_ok111);
  tcase_add_test(tc_core, test_negate_ok112);
  tcase_add_test(tc_core, test_negate_ok113);
  tcase_add_test(tc_core, test_negate_ok114);
  tcase_add_test(tc_core, test_negate_ok115);
  tcase_add_test(tc_core, test_negate_ok116);
  tcase_add_test(tc_core, test_negate_ok117);
  tcase_add_test(tc_core, test_negate_ok118);
  tcase_add_test(tc_core, test_negate_ok119);
  tcase_add_test(tc_core, test_negate_ok120);
  tcase_add_test(tc_core, test_negate_ok121);
  tcase_add_test(tc_core, test_negate_ok122);
  tcase_add_test(tc_core, test_negate_ok123);
  tcase_add_test(tc_core, test_negate_ok124);
  tcase_add_test(tc_core, test_negate_ok125);
  tcase_add_test(tc_core, test_negate_ok126);
  tcase_add_test(tc_core, test_negate_ok127);
  tcase_add_test(tc_core, test_negate_ok128);
  tcase_add_test(tc_core, test_negate_ok129);
  tcase_add_test(tc_core, test_negate_ok130);
  tcase_add_test(tc_core, test_negate_ok131);
  tcase_add_test(tc_core, test_negate_ok132);
  tcase_add_test(tc_core, test_negate_ok133);
  tcase_add_test(tc_core, test_negate_ok134);
  tcase_add_test(tc_core, test_negate_ok135);
  tcase_add_test(tc_core, test_negate_ok136);
  tcase_add_test(tc_core, test_negate_ok137);
  tcase_add_test(tc_core, test_negate_ok138);
  tcase_add_test(tc_core, test_negate_ok139);
  tcase_add_test(tc_core, test_negate_ok140);
  tcase_add_test(tc_core, test_negate_ok141);
  tcase_add_test(tc_core, test_negate_ok142);
  tcase_add_test(tc_core, test_negate_ok143);
  tcase_add_test(tc_core, test_negate_ok144);
  tcase_add_test(tc_core, test_negate_ok145);
  tcase_add_test(tc_core, test_negate_ok146);
  tcase_add_test(tc_core, test_negate_ok147);
  tcase_add_test(tc_core, test_negate_ok148);
  tcase_add_test(tc_core, test_negate_ok149);
  tcase_add_test(tc_core, test_negate_ok150);
  tcase_add_test(tc_core, test_negate_ok151);
  tcase_add_test(tc_core, test_negate_ok152);
  tcase_add_test(tc_core, test_negate_ok153);
  tcase_add_test(tc_core, test_negate_ok154);
  tcase_add_test(tc_core, test_negate_ok155);
  tcase_add_test(tc_core, test_negate_ok156);
  tcase_add_test(tc_core, test_negate_ok157);
  tcase_add_test(tc_core, test_negate_ok158);
  tcase_add_test(tc_core, test_negate_ok159);
  tcase_add_test(tc_core, test_negate_ok160);
  tcase_add_test(tc_core, test_negate_ok161);
  tcase_add_test(tc_core, test_negate_ok162);
  tcase_add_test(tc_core, test_negate_ok163);
  tcase_add_test(tc_core, test_negate_ok164);
  tcase_add_test(tc_core, test_negate_ok165);
  tcase_add_test(tc_core, test_negate_ok166);
  tcase_add_test(tc_core, test_negate_ok167);
  tcase_add_test(tc_core, test_negate_ok168);
  tcase_add_test(tc_core, test_negate_ok169);
  tcase_add_test(tc_core, test_negate_ok170);
  tcase_add_test(tc_core, test_negate_ok171);
  tcase_add_test(tc_core, test_negate_ok172);
  tcase_add_test(tc_core, test_negate_ok173);
  tcase_add_test(tc_core, test_negate_ok174);
  tcase_add_test(tc_core, test_negate_ok175);
  tcase_add_test(tc_core, test_negate_ok176);
  tcase_add_test(tc_core, test_negate_ok177);
  tcase_add_test(tc_core, test_negate_ok178);
  tcase_add_test(tc_core, test_negate_ok179);
  tcase_add_test(tc_core, test_negate_ok180);
  tcase_add_test(tc_core, test_negate_ok181);
  tcase_add_test(tc_core, test_negate_ok182);
  tcase_add_test(tc_core, test_negate_ok183);
  tcase_add_test(tc_core, test_negate_ok184);
  tcase_add_test(tc_core, test_negate_ok185);
  tcase_add_test(tc_core, test_negate_ok186);
  tcase_add_test(tc_core, test_negate_ok187);
  tcase_add_test(tc_core, test_negate_ok188);
  tcase_add_test(tc_core, test_negate_ok189);
  tcase_add_test(tc_core, test_negate_ok190);
  tcase_add_test(tc_core, test_negate_ok191);
  tcase_add_test(tc_core, test_negate_ok192);
  tcase_add_test(tc_core, test_negate_ok193);
  tcase_add_test(tc_core, test_negate_ok194);
  tcase_add_test(tc_core, test_negate_ok195);
  tcase_add_test(tc_core, test_negate_ok196);
  tcase_add_test(tc_core, test_negate_ok197);
  tcase_add_test(tc_core, test_negate_ok198);
  tcase_add_test(tc_core, test_negate_ok199);
  tcase_add_test(tc_core, test_negate_ok200);
  tcase_add_test(tc_core, test_negate_ok201);
  tcase_add_test(tc_core, test_negate_ok202);
  tcase_add_test(tc_core, test_negate_ok203);
  tcase_add_test(tc_core, test_negate_ok204);
  tcase_add_test(tc_core, test_negate_ok205);
  tcase_add_test(tc_core, test_negate_ok206);
  tcase_add_test(tc_core, test_negate_ok207);
  tcase_add_test(tc_core, test_negate_ok208);
  tcase_add_test(tc_core, test_negate_ok209);
  tcase_add_test(tc_core, test_negate_ok210);
  tcase_add_test(tc_core, test_negate_ok211);
  tcase_add_test(tc_core, test_negate_ok212);
  tcase_add_test(tc_core, test_negate_ok213);
  tcase_add_test(tc_core, test_negate_ok214);
  tcase_add_test(tc_core, test_negate_ok215);
  tcase_add_test(tc_core, test_negate_ok216);
  tcase_add_test(tc_core, test_negate_ok217);
  tcase_add_test(tc_core, test_negate_ok218);
  tcase_add_test(tc_core, test_negate_ok219);
  tcase_add_test(tc_core, test_negate_ok220);
  tcase_add_test(tc_core, test_negate_ok221);
  tcase_add_test(tc_core, test_negate_ok222);
  tcase_add_test(tc_core, test_negate_ok223);
  tcase_add_test(tc_core, test_negate_ok224);
  tcase_add_test(tc_core, test_negate_ok225);
  tcase_add_test(tc_core, test_negate_ok226);
  tcase_add_test(tc_core, test_negate_ok227);
  tcase_add_test(tc_core, test_negate_ok228);
  tcase_add_test(tc_core, test_negate_ok229);
  tcase_add_test(tc_core, test_negate_ok230);
  tcase_add_test(tc_core, test_negate_ok231);
  tcase_add_test(tc_core, test_negate_ok232);
  tcase_add_test(tc_core, test_negate_ok233);
  tcase_add_test(tc_core, test_negate_ok234);
  tcase_add_test(tc_core, test_negate_ok235);
  tcase_add_test(tc_core, test_negate_ok236);
  tcase_add_test(tc_core, test_negate_ok237);
  tcase_add_test(tc_core, test_negate_ok238);
  tcase_add_test(tc_core, test_negate_ok239);
  tcase_add_test(tc_core, test_negate_ok240);
  tcase_add_test(tc_core, test_negate_ok241);
  tcase_add_test(tc_core, test_negate_ok242);
  tcase_add_test(tc_core, test_negate_ok243);
  tcase_add_test(tc_core, test_negate_ok244);
  tcase_add_test(tc_core, test_negate_ok245);
  tcase_add_test(tc_core, test_negate_ok246);
  tcase_add_test(tc_core, test_negate_ok247);
  tcase_add_test(tc_core, test_negate_ok248);
  tcase_add_test(tc_core, test_negate_ok249);
  tcase_add_test(tc_core, test_negate_ok250);
  tcase_add_test(tc_core, test_negate_ok251);
  tcase_add_test(tc_core, test_negate_ok252);
  tcase_add_test(tc_core, test_negate_ok253);
  tcase_add_test(tc_core, test_negate_ok254);
  tcase_add_test(tc_core, test_negate_ok255);
  tcase_add_test(tc_core, test_negate_ok256);
  tcase_add_test(tc_core, test_negate_ok257);
  tcase_add_test(tc_core, test_negate_ok258);
  tcase_add_test(tc_core, test_negate_ok259);
  tcase_add_test(tc_core, test_negate_ok260);
  tcase_add_test(tc_core, test_negate_ok261);
  tcase_add_test(tc_core, test_negate_ok262);
  tcase_add_test(tc_core, test_negate_ok263);
  tcase_add_test(tc_core, test_negate_ok264);
  tcase_add_test(tc_core, test_negate_ok265);
  tcase_add_test(tc_core, test_negate_ok266);
  tcase_add_test(tc_core, test_negate_ok267);
  tcase_add_test(tc_core, test_negate_ok268);
  tcase_add_test(tc_core, test_negate_ok269);
  tcase_add_test(tc_core, test_negate_ok270);
  tcase_add_test(tc_core, test_negate_ok271);
  tcase_add_test(tc_core, test_negate_ok272);
  tcase_add_test(tc_core, test_negate_ok273);
  tcase_add_test(tc_core, test_negate_ok274);
  tcase_add_test(tc_core, test_negate_ok275);
  tcase_add_test(tc_core, test_negate_ok276);
  tcase_add_test(tc_core, test_negate_ok277);
  tcase_add_test(tc_core, test_negate_ok278);
  tcase_add_test(tc_core, test_negate_ok279);
  tcase_add_test(tc_core, test_negate_ok280);
  tcase_add_test(tc_core, test_negate_ok281);
  tcase_add_test(tc_core, test_negate_ok282);
  tcase_add_test(tc_core, test_negate_ok283);
  tcase_add_test(tc_core, test_negate_ok284);
  tcase_add_test(tc_core, test_negate_ok285);
  tcase_add_test(tc_core, test_negate_ok286);
  tcase_add_test(tc_core, test_negate_ok287);
  tcase_add_test(tc_core, test_negate_ok288);
  tcase_add_test(tc_core, test_negate_ok289);
  tcase_add_test(tc_core, test_negate_ok290);
  tcase_add_test(tc_core, test_negate_ok291);
  tcase_add_test(tc_core, test_negate_ok292);
  tcase_add_test(tc_core, test_negate_ok293);
  tcase_add_test(tc_core, test_negate_ok294);
  tcase_add_test(tc_core, test_negate_ok295);
  tcase_add_test(tc_core, test_negate_ok296);
  tcase_add_test(tc_core, test_negate_ok297);
  tcase_add_test(tc_core, test_negate_ok298);
  tcase_add_test(tc_core, test_negate_ok299);
  tcase_add_test(tc_core, test_negate_ok300);
  tcase_add_test(tc_core, test_negate_ok301);
  tcase_add_test(tc_core, test_negate_ok302);
  tcase_add_test(tc_core, test_negate_ok303);
  tcase_add_test(tc_core, test_negate_ok304);
  tcase_add_test(tc_core, test_negate_ok305);
  tcase_add_test(tc_core, test_negate_ok306);
  tcase_add_test(tc_core, test_negate_ok307);
  tcase_add_test(tc_core, test_negate_ok308);
  tcase_add_test(tc_core, test_negate_ok309);
  tcase_add_test(tc_core, test_negate_ok310);
  tcase_add_test(tc_core, test_negate_ok311);
  tcase_add_test(tc_core, test_negate_ok312);
  tcase_add_test(tc_core, test_negate_ok313);
  tcase_add_test(tc_core, test_negate_ok314);
  tcase_add_test(tc_core, test_negate_ok315);
  tcase_add_test(tc_core, test_negate_ok316);
  tcase_add_test(tc_core, test_negate_ok317);
  tcase_add_test(tc_core, test_negate_ok318);
  tcase_add_test(tc_core, test_negate_ok319);
  tcase_add_test(tc_core, test_negate_ok320);
  tcase_add_test(tc_core, test_negate_ok321);
  tcase_add_test(tc_core, test_negate_ok322);
  tcase_add_test(tc_core, test_negate_ok323);
  tcase_add_test(tc_core, test_negate_ok324);
  tcase_add_test(tc_core, test_negate_ok325);
  tcase_add_test(tc_core, test_negate_ok326);
  tcase_add_test(tc_core, test_negate_ok327);
  tcase_add_test(tc_core, test_negate_ok328);
  tcase_add_test(tc_core, test_negate_ok329);
  tcase_add_test(tc_core, test_negate_ok330);
  tcase_add_test(tc_core, test_negate_ok331);
  tcase_add_test(tc_core, test_negate_ok332);
  tcase_add_test(tc_core, test_negate_ok333);
  tcase_add_test(tc_core, test_negate_ok334);
  tcase_add_test(tc_core, test_negate_ok335);
  tcase_add_test(tc_core, test_negate_ok336);
  tcase_add_test(tc_core, test_negate_ok337);
  tcase_add_test(tc_core, test_negate_ok338);
  tcase_add_test(tc_core, test_negate_ok339);
  tcase_add_test(tc_core, test_negate_ok340);
  tcase_add_test(tc_core, test_negate_ok341);
  tcase_add_test(tc_core, test_negate_ok342);
  tcase_add_test(tc_core, test_negate_ok343);
  tcase_add_test(tc_core, test_negate_ok344);
  tcase_add_test(tc_core, test_negate_ok345);
  tcase_add_test(tc_core, test_negate_ok346);
  tcase_add_test(tc_core, test_negate_ok347);
  tcase_add_test(tc_core, test_negate_ok348);
  tcase_add_test(tc_core, test_negate_ok349);
  tcase_add_test(tc_core, test_negate_ok350);
  tcase_add_test(tc_core, test_negate_ok351);
  tcase_add_test(tc_core, test_negate_ok352);
  tcase_add_test(tc_core, test_negate_ok353);
  tcase_add_test(tc_core, test_negate_ok354);
  tcase_add_test(tc_core, test_negate_ok355);
  tcase_add_test(tc_core, test_negate_ok356);
  tcase_add_test(tc_core, test_negate_ok357);
  tcase_add_test(tc_core, test_negate_ok358);
  tcase_add_test(tc_core, test_negate_ok359);
  tcase_add_test(tc_core, test_negate_ok360);
  tcase_add_test(tc_core, test_negate_ok361);
  tcase_add_test(tc_core, test_negate_ok362);
  tcase_add_test(tc_core, test_negate_ok363);
  tcase_add_test(tc_core, test_negate_ok364);
  tcase_add_test(tc_core, test_negate_ok365);
  tcase_add_test(tc_core, test_negate_ok366);
  tcase_add_test(tc_core, test_negate_ok367);
  tcase_add_test(tc_core, test_negate_ok368);
  tcase_add_test(tc_core, test_negate_ok369);
  tcase_add_test(tc_core, test_negate_ok370);
  tcase_add_test(tc_core, test_negate_ok371);
  tcase_add_test(tc_core, test_negate_ok372);
  tcase_add_test(tc_core, test_negate_ok373);
  tcase_add_test(tc_core, test_negate_ok374);
  tcase_add_test(tc_core, test_negate_ok375);
  tcase_add_test(tc_core, test_negate_ok376);
  tcase_add_test(tc_core, test_negate_ok377);
  tcase_add_test(tc_core, test_negate_ok378);
  tcase_add_test(tc_core, test_negate_ok379);
  tcase_add_test(tc_core, test_negate_ok380);
  tcase_add_test(tc_core, test_negate_ok381);
  tcase_add_test(tc_core, test_negate_ok382);
  tcase_add_test(tc_core, test_negate_ok383);
  tcase_add_test(tc_core, test_negate_ok384);
  tcase_add_test(tc_core, test_negate_ok385);
  tcase_add_test(tc_core, test_negate_ok386);
  tcase_add_test(tc_core, test_negate_ok387);
  tcase_add_test(tc_core, test_negate_ok388);
  tcase_add_test(tc_core, test_negate_ok389);
  tcase_add_test(tc_core, test_negate_ok390);
  tcase_add_test(tc_core, test_negate_ok391);
  tcase_add_test(tc_core, test_negate_ok392);
  tcase_add_test(tc_core, test_negate_ok393);
  tcase_add_test(tc_core, test_negate_ok394);
  tcase_add_test(tc_core, test_negate_ok395);
  tcase_add_test(tc_core, test_negate_ok396);
  tcase_add_test(tc_core, test_negate_ok397);
  tcase_add_test(tc_core, test_negate_ok398);
  tcase_add_test(tc_core, test_negate_ok399);
  tcase_add_test(tc_core, test_negate_ok400);

  suite_add_tcase(s, tc_core);
  return s;
}

Suite *negate_suite2(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("negate_suite2");
  tc_core = tcase_create("Core");
  tcase_add_test(tc_core, test_negate_ok401);
  tcase_add_test(tc_core, test_negate_ok402);
  tcase_add_test(tc_core, test_negate_ok403);
  tcase_add_test(tc_core, test_negate_ok404);
  tcase_add_test(tc_core, test_negate_ok405);
  tcase_add_test(tc_core, test_negate_ok406);
  tcase_add_test(tc_core, test_negate_ok407);
  tcase_add_test(tc_core, test_negate_ok408);
  tcase_add_test(tc_core, test_negate_ok409);
  tcase_add_test(tc_core, test_negate_ok410);
  tcase_add_test(tc_core, test_negate_ok411);
  tcase_add_test(tc_core, test_negate_ok412);
  tcase_add_test(tc_core, test_negate_ok413);
  tcase_add_test(tc_core, test_negate_ok414);
  tcase_add_test(tc_core, test_negate_ok415);
  tcase_add_test(tc_core, test_negate_ok416);
  tcase_add_test(tc_core, test_negate_ok417);
  tcase_add_test(tc_core, test_negate_ok418);
  tcase_add_test(tc_core, test_negate_ok419);
  tcase_add_test(tc_core, test_negate_ok420);
  tcase_add_test(tc_core, test_negate_ok421);
  tcase_add_test(tc_core, test_negate_ok422);
  tcase_add_test(tc_core, test_negate_ok423);
  tcase_add_test(tc_core, test_negate_ok424);
  tcase_add_test(tc_core, test_negate_ok425);
  tcase_add_test(tc_core, test_negate_ok426);
  tcase_add_test(tc_core, test_negate_ok427);
  tcase_add_test(tc_core, test_negate_ok428);
  tcase_add_test(tc_core, test_negate_ok429);
  tcase_add_test(tc_core, test_negate_ok430);
  tcase_add_test(tc_core, test_negate_ok431);
  tcase_add_test(tc_core, test_negate_ok432);
  tcase_add_test(tc_core, test_negate_ok433);
  tcase_add_test(tc_core, test_negate_ok434);
  tcase_add_test(tc_core, test_negate_ok435);
  tcase_add_test(tc_core, test_negate_ok436);
  tcase_add_test(tc_core, test_negate_ok437);
  tcase_add_test(tc_core, test_negate_ok438);
  tcase_add_test(tc_core, test_negate_ok439);
  tcase_add_test(tc_core, test_negate_ok440);
  tcase_add_test(tc_core, test_negate_ok441);
  tcase_add_test(tc_core, test_negate_ok442);
  tcase_add_test(tc_core, test_negate_ok443);
  tcase_add_test(tc_core, test_negate_ok444);
  tcase_add_test(tc_core, test_negate_ok445);
  tcase_add_test(tc_core, test_negate_ok446);
  tcase_add_test(tc_core, test_negate_ok447);
  tcase_add_test(tc_core, test_negate_ok448);
  tcase_add_test(tc_core, test_negate_ok449);
  tcase_add_test(tc_core, test_negate_ok450);
  tcase_add_test(tc_core, test_negate_ok451);
  tcase_add_test(tc_core, test_negate_ok452);
  tcase_add_test(tc_core, test_negate_ok453);
  tcase_add_test(tc_core, test_negate_ok454);
  tcase_add_test(tc_core, test_negate_ok455);
  tcase_add_test(tc_core, test_negate_ok456);
  tcase_add_test(tc_core, test_negate_ok457);
  tcase_add_test(tc_core, test_negate_ok458);
  tcase_add_test(tc_core, test_negate_ok459);
  tcase_add_test(tc_core, test_negate_ok460);
  tcase_add_test(tc_core, test_negate_ok461);
  tcase_add_test(tc_core, test_negate_ok462);
  tcase_add_test(tc_core, test_negate_ok463);
  tcase_add_test(tc_core, test_negate_ok464);
  tcase_add_test(tc_core, test_negate_ok465);
  tcase_add_test(tc_core, test_negate_ok466);
  tcase_add_test(tc_core, test_negate_ok467);
  tcase_add_test(tc_core, test_negate_ok468);
  tcase_add_test(tc_core, test_negate_ok469);
  tcase_add_test(tc_core, test_negate_ok470);
  tcase_add_test(tc_core, test_negate_ok471);
  tcase_add_test(tc_core, test_negate_ok472);
  tcase_add_test(tc_core, test_negate_ok473);
  tcase_add_test(tc_core, test_negate_ok474);
  tcase_add_test(tc_core, test_negate_ok475);
  tcase_add_test(tc_core, test_negate_ok476);
  tcase_add_test(tc_core, test_negate_ok477);
  tcase_add_test(tc_core, test_negate_ok478);
  tcase_add_test(tc_core, test_negate_ok479);
  tcase_add_test(tc_core, test_negate_ok480);
  tcase_add_test(tc_core, test_negate_ok481);
  tcase_add_test(tc_core, test_negate_ok482);
  tcase_add_test(tc_core, test_negate_ok483);
  tcase_add_test(tc_core, test_negate_ok484);
  tcase_add_test(tc_core, test_negate_ok485);
  tcase_add_test(tc_core, test_negate_ok486);
  tcase_add_test(tc_core, test_negate_ok487);
  tcase_add_test(tc_core, test_negate_ok488);
  tcase_add_test(tc_core, test_negate_ok489);
  tcase_add_test(tc_core, test_negate_ok490);
  tcase_add_test(tc_core, test_negate_ok491);
  tcase_add_test(tc_core, test_negate_ok492);
  tcase_add_test(tc_core, test_negate_ok493);
  tcase_add_test(tc_core, test_negate_ok494);
  tcase_add_test(tc_core, test_negate_ok495);
  tcase_add_test(tc_core, test_negate_ok496);
  tcase_add_test(tc_core, test_negate_ok497);
  tcase_add_test(tc_core, test_negate_ok498);
  tcase_add_test(tc_core, test_negate_ok499);
  tcase_add_test(tc_core, test_negate_ok500);
  tcase_add_test(tc_core, test_negate_ok501);
  tcase_add_test(tc_core, test_negate_ok502);
  tcase_add_test(tc_core, test_negate_ok503);
  tcase_add_test(tc_core, test_negate_ok504);
  tcase_add_test(tc_core, test_negate_ok505);
  tcase_add_test(tc_core, test_negate_ok506);
  tcase_add_test(tc_core, test_negate_ok507);
  tcase_add_test(tc_core, test_negate_ok508);
  tcase_add_test(tc_core, test_negate_ok509);
  tcase_add_test(tc_core, test_negate_ok510);
  tcase_add_test(tc_core, test_negate_ok511);
  tcase_add_test(tc_core, test_negate_ok512);
  tcase_add_test(tc_core, test_negate_ok513);
  tcase_add_test(tc_core, test_negate_ok514);
  tcase_add_test(tc_core, test_negate_ok515);
  tcase_add_test(tc_core, test_negate_ok516);
  tcase_add_test(tc_core, test_negate_ok517);
  tcase_add_test(tc_core, test_negate_ok518);
  tcase_add_test(tc_core, test_negate_ok519);
  tcase_add_test(tc_core, test_negate_ok520);
  tcase_add_test(tc_core, test_negate_ok521);
  tcase_add_test(tc_core, test_negate_ok522);
  tcase_add_test(tc_core, test_negate_ok523);
  tcase_add_test(tc_core, test_negate_ok524);
  tcase_add_test(tc_core, test_negate_ok525);
  tcase_add_test(tc_core, test_negate_ok526);
  tcase_add_test(tc_core, test_negate_ok527);
  tcase_add_test(tc_core, test_negate_ok528);
  tcase_add_test(tc_core, test_negate_ok529);
  tcase_add_test(tc_core, test_negate_ok530);
  tcase_add_test(tc_core, test_negate_ok531);
  tcase_add_test(tc_core, test_negate_ok532);
  tcase_add_test(tc_core, test_negate_ok533);
  tcase_add_test(tc_core, test_negate_ok534);
  tcase_add_test(tc_core, test_negate_ok535);
  tcase_add_test(tc_core, test_negate_ok536);
  tcase_add_test(tc_core, test_negate_ok537);
  tcase_add_test(tc_core, test_negate_ok538);
  tcase_add_test(tc_core, test_negate_ok539);
  tcase_add_test(tc_core, test_negate_ok540);
  tcase_add_test(tc_core, test_negate_ok541);
  tcase_add_test(tc_core, test_negate_ok542);
  tcase_add_test(tc_core, test_negate_ok543);
  tcase_add_test(tc_core, test_negate_ok544);
  tcase_add_test(tc_core, test_negate_ok545);
  tcase_add_test(tc_core, test_negate_ok546);
  tcase_add_test(tc_core, test_negate_ok547);
  tcase_add_test(tc_core, test_negate_ok548);
  tcase_add_test(tc_core, test_negate_ok549);
  tcase_add_test(tc_core, test_negate_ok550);
  tcase_add_test(tc_core, test_negate_ok551);
  tcase_add_test(tc_core, test_negate_ok552);
  tcase_add_test(tc_core, test_negate_ok553);
  tcase_add_test(tc_core, test_negate_ok554);
  tcase_add_test(tc_core, test_negate_ok555);
  tcase_add_test(tc_core, test_negate_ok556);
  tcase_add_test(tc_core, test_negate_ok557);
  tcase_add_test(tc_core, test_negate_ok558);
  tcase_add_test(tc_core, test_negate_ok559);
  tcase_add_test(tc_core, test_negate_ok560);
  tcase_add_test(tc_core, test_negate_ok561);
  tcase_add_test(tc_core, test_negate_ok562);
  tcase_add_test(tc_core, test_negate_ok563);
  tcase_add_test(tc_core, test_negate_ok564);
  tcase_add_test(tc_core, test_negate_ok565);
  tcase_add_test(tc_core, test_negate_ok566);
  tcase_add_test(tc_core, test_negate_ok567);
  tcase_add_test(tc_core, test_negate_ok568);
  tcase_add_test(tc_core, test_negate_ok569);
  tcase_add_test(tc_core, test_negate_ok570);
  tcase_add_test(tc_core, test_negate_ok571);
  tcase_add_test(tc_core, test_negate_ok572);
  tcase_add_test(tc_core, test_negate_ok573);
  tcase_add_test(tc_core, test_negate_ok574);
  tcase_add_test(tc_core, test_negate_ok575);
  tcase_add_test(tc_core, test_negate_ok576);
  tcase_add_test(tc_core, test_negate_ok577);
  tcase_add_test(tc_core, test_negate_ok578);
  tcase_add_test(tc_core, test_negate_ok579);
  tcase_add_test(tc_core, test_negate_ok580);
  tcase_add_test(tc_core, test_negate_ok581);
  tcase_add_test(tc_core, test_negate_ok582);
  tcase_add_test(tc_core, test_negate_ok583);
  tcase_add_test(tc_core, test_negate_ok584);
  tcase_add_test(tc_core, test_negate_ok585);
  tcase_add_test(tc_core, test_negate_ok586);
  tcase_add_test(tc_core, test_negate_ok587);
  tcase_add_test(tc_core, test_negate_ok588);
  tcase_add_test(tc_core, test_negate_ok589);
  tcase_add_test(tc_core, test_negate_ok590);
  tcase_add_test(tc_core, test_negate_ok591);
  tcase_add_test(tc_core, test_negate_ok592);
  tcase_add_test(tc_core, test_negate_ok593);
  tcase_add_test(tc_core, test_negate_ok594);
  tcase_add_test(tc_core, test_negate_ok595);
  tcase_add_test(tc_core, test_negate_ok596);
  tcase_add_test(tc_core, test_negate_ok597);
  tcase_add_test(tc_core, test_negate_ok598);
  tcase_add_test(tc_core, test_negate_ok599);
  tcase_add_test(tc_core, test_negate_ok600);
  tcase_add_test(tc_core, test_negate_ok601);
  tcase_add_test(tc_core, test_negate_ok602);
  tcase_add_test(tc_core, test_negate_ok603);
  tcase_add_test(tc_core, test_negate_ok604);
  tcase_add_test(tc_core, test_negate_ok605);
  tcase_add_test(tc_core, test_negate_ok606);
  tcase_add_test(tc_core, test_negate_ok607);
  tcase_add_test(tc_core, test_negate_ok608);
  tcase_add_test(tc_core, test_negate_ok609);
  tcase_add_test(tc_core, test_negate_ok610);
  tcase_add_test(tc_core, test_negate_ok611);
  tcase_add_test(tc_core, test_negate_ok612);
  tcase_add_test(tc_core, test_negate_ok613);
  tcase_add_test(tc_core, test_negate_ok614);
  tcase_add_test(tc_core, test_negate_ok615);
  tcase_add_test(tc_core, test_negate_ok616);
  tcase_add_test(tc_core, test_negate_ok617);
  tcase_add_test(tc_core, test_negate_ok618);
  tcase_add_test(tc_core, test_negate_ok619);
  tcase_add_test(tc_core, test_negate_ok620);
  tcase_add_test(tc_core, test_negate_ok621);
  tcase_add_test(tc_core, test_negate_ok622);
  tcase_add_test(tc_core, test_negate_ok623);
  tcase_add_test(tc_core, test_negate_ok624);
  tcase_add_test(tc_core, test_negate_ok625);
  tcase_add_test(tc_core, test_negate_ok626);
  tcase_add_test(tc_core, test_negate_ok627);
  tcase_add_test(tc_core, test_negate_ok628);
  tcase_add_test(tc_core, test_negate_ok629);
  tcase_add_test(tc_core, test_negate_ok630);
  tcase_add_test(tc_core, test_negate_ok631);
  tcase_add_test(tc_core, test_negate_ok632);
  tcase_add_test(tc_core, test_negate_ok633);
  tcase_add_test(tc_core, test_negate_ok634);
  tcase_add_test(tc_core, test_negate_ok635);
  tcase_add_test(tc_core, test_negate_ok636);
  tcase_add_test(tc_core, test_negate_ok637);
  tcase_add_test(tc_core, test_negate_ok638);
  tcase_add_test(tc_core, test_negate_ok639);
  tcase_add_test(tc_core, test_negate_ok640);
  tcase_add_test(tc_core, test_negate_ok641);
  tcase_add_test(tc_core, test_negate_ok642);
  tcase_add_test(tc_core, test_negate_ok643);
  tcase_add_test(tc_core, test_negate_ok644);
  tcase_add_test(tc_core, test_negate_ok645);
  tcase_add_test(tc_core, test_negate_ok646);
  tcase_add_test(tc_core, test_negate_ok647);
  tcase_add_test(tc_core, test_negate_ok648);
  tcase_add_test(tc_core, test_negate_ok649);
  tcase_add_test(tc_core, test_negate_ok650);
  tcase_add_test(tc_core, test_negate_ok651);
  tcase_add_test(tc_core, test_negate_ok652);
  tcase_add_test(tc_core, test_negate_ok653);
  tcase_add_test(tc_core, test_negate_ok654);
  tcase_add_test(tc_core, test_negate_ok655);
  tcase_add_test(tc_core, test_negate_ok656);
  tcase_add_test(tc_core, test_negate_ok657);
  tcase_add_test(tc_core, test_negate_ok658);
  tcase_add_test(tc_core, test_negate_ok659);
  tcase_add_test(tc_core, test_negate_ok660);
  tcase_add_test(tc_core, test_negate_ok661);
  tcase_add_test(tc_core, test_negate_ok662);
  tcase_add_test(tc_core, test_negate_ok663);
  tcase_add_test(tc_core, test_negate_ok664);
  tcase_add_test(tc_core, test_negate_ok665);
  tcase_add_test(tc_core, test_negate_ok666);
  tcase_add_test(tc_core, test_negate_ok667);
  tcase_add_test(tc_core, test_negate_ok668);
  tcase_add_test(tc_core, test_negate_ok669);
  tcase_add_test(tc_core, test_negate_ok670);
  tcase_add_test(tc_core, test_negate_ok671);
  tcase_add_test(tc_core, test_negate_ok672);
  tcase_add_test(tc_core, test_negate_ok673);
  tcase_add_test(tc_core, test_negate_ok674);
  tcase_add_test(tc_core, test_negate_ok675);
  tcase_add_test(tc_core, test_negate_ok676);
  tcase_add_test(tc_core, test_negate_ok677);
  tcase_add_test(tc_core, test_negate_ok678);
  tcase_add_test(tc_core, test_negate_ok679);
  tcase_add_test(tc_core, test_negate_ok680);
  tcase_add_test(tc_core, test_negate_ok681);
  tcase_add_test(tc_core, test_negate_ok682);
  tcase_add_test(tc_core, test_negate_ok683);
  tcase_add_test(tc_core, test_negate_ok684);
  tcase_add_test(tc_core, test_negate_ok685);
  tcase_add_test(tc_core, test_negate_ok686);
  tcase_add_test(tc_core, test_negate_ok687);
  tcase_add_test(tc_core, test_negate_ok688);
  tcase_add_test(tc_core, test_negate_ok689);
  tcase_add_test(tc_core, test_negate_ok690);
  tcase_add_test(tc_core, test_negate_ok691);
  tcase_add_test(tc_core, test_negate_ok692);
  tcase_add_test(tc_core, test_negate_ok693);
  tcase_add_test(tc_core, test_negate_ok694);
  tcase_add_test(tc_core, test_negate_ok695);
  tcase_add_test(tc_core, test_negate_ok696);
  tcase_add_test(tc_core, test_negate_ok697);
  tcase_add_test(tc_core, test_negate_ok698);
  tcase_add_test(tc_core, test_negate_ok699);
  tcase_add_test(tc_core, test_negate_ok700);
  tcase_add_test(tc_core, test_negate_ok701);
  tcase_add_test(tc_core, test_negate_ok702);
  tcase_add_test(tc_core, test_negate_ok703);
  tcase_add_test(tc_core, test_negate_ok704);
  tcase_add_test(tc_core, test_negate_ok705);
  tcase_add_test(tc_core, test_negate_ok706);
  tcase_add_test(tc_core, test_negate_ok707);
  tcase_add_test(tc_core, test_negate_ok708);
  tcase_add_test(tc_core, test_negate_ok709);
  tcase_add_test(tc_core, test_negate_ok710);
  tcase_add_test(tc_core, test_negate_ok711);
  tcase_add_test(tc_core, test_negate_ok712);
  tcase_add_test(tc_core, test_negate_ok713);
  tcase_add_test(tc_core, test_negate_ok714);
  tcase_add_test(tc_core, test_negate_ok715);
  tcase_add_test(tc_core, test_negate_ok716);
  tcase_add_test(tc_core, test_negate_ok717);
  tcase_add_test(tc_core, test_negate_ok718);
  tcase_add_test(tc_core, test_negate_ok719);
  tcase_add_test(tc_core, test_negate_ok720);
  tcase_add_test(tc_core, test_negate_ok721);
  tcase_add_test(tc_core, test_negate_ok722);
  tcase_add_test(tc_core, test_negate_ok723);
  tcase_add_test(tc_core, test_negate_ok724);
  tcase_add_test(tc_core, test_negate_ok725);
  tcase_add_test(tc_core, test_negate_ok726);
  tcase_add_test(tc_core, test_negate_ok727);
  tcase_add_test(tc_core, test_negate_ok728);
  tcase_add_test(tc_core, test_negate_ok729);
  tcase_add_test(tc_core, test_negate_ok730);
  tcase_add_test(tc_core, test_negate_ok731);
  tcase_add_test(tc_core, test_negate_ok732);
  tcase_add_test(tc_core, test_negate_ok733);
  tcase_add_test(tc_core, test_negate_ok734);
  tcase_add_test(tc_core, test_negate_ok735);
  tcase_add_test(tc_core, test_negate_ok736);
  tcase_add_test(tc_core, test_negate_ok737);
  tcase_add_test(tc_core, test_negate_ok738);
  tcase_add_test(tc_core, test_negate_ok739);
  tcase_add_test(tc_core, test_negate_ok740);
  tcase_add_test(tc_core, test_negate_ok741);
  tcase_add_test(tc_core, test_negate_ok742);
  tcase_add_test(tc_core, test_negate_ok743);
  tcase_add_test(tc_core, test_negate_ok744);
  tcase_add_test(tc_core, test_negate_ok745);
  tcase_add_test(tc_core, test_negate_ok746);
  tcase_add_test(tc_core, test_negate_ok747);
  tcase_add_test(tc_core, test_negate_ok748);
  tcase_add_test(tc_core, test_negate_ok749);
  tcase_add_test(tc_core, test_negate_ok750);
  tcase_add_test(tc_core, test_negate_ok751);
  tcase_add_test(tc_core, test_negate_ok752);
  tcase_add_test(tc_core, test_negate_ok753);
  tcase_add_test(tc_core, test_negate_ok754);
  tcase_add_test(tc_core, test_negate_ok755);
  tcase_add_test(tc_core, test_negate_ok756);
  tcase_add_test(tc_core, test_negate_ok757);
  tcase_add_test(tc_core, test_negate_ok758);
  tcase_add_test(tc_core, test_negate_ok759);
  tcase_add_test(tc_core, test_negate_ok760);
  tcase_add_test(tc_core, test_negate_ok761);
  tcase_add_test(tc_core, test_negate_ok762);
  tcase_add_test(tc_core, test_negate_ok763);
  tcase_add_test(tc_core, test_negate_ok764);
  tcase_add_test(tc_core, test_negate_ok765);
  tcase_add_test(tc_core, test_negate_ok766);
  tcase_add_test(tc_core, test_negate_ok767);
  tcase_add_test(tc_core, test_negate_ok768);
  tcase_add_test(tc_core, test_negate_ok769);
  tcase_add_test(tc_core, test_negate_ok770);
  tcase_add_test(tc_core, test_negate_ok771);
  tcase_add_test(tc_core, test_negate_ok772);
  tcase_add_test(tc_core, test_negate_ok773);
  tcase_add_test(tc_core, test_negate_ok774);
  tcase_add_test(tc_core, test_negate_ok775);
  tcase_add_test(tc_core, test_negate_ok776);
  tcase_add_test(tc_core, test_negate_ok777);
  tcase_add_test(tc_core, test_negate_ok778);
  tcase_add_test(tc_core, test_negate_ok779);
  tcase_add_test(tc_core, test_negate_ok780);
  tcase_add_test(tc_core, test_negate_ok781);
  tcase_add_test(tc_core, test_negate_ok782);
  tcase_add_test(tc_core, test_negate_ok783);
  tcase_add_test(tc_core, test_negate_ok784);
  tcase_add_test(tc_core, test_negate_ok785);
  tcase_add_test(tc_core, test_negate_ok786);
  tcase_add_test(tc_core, test_negate_ok787);
  tcase_add_test(tc_core, test_negate_ok788);
  tcase_add_test(tc_core, test_negate_ok789);
  tcase_add_test(tc_core, test_negate_ok790);
  tcase_add_test(tc_core, test_negate_ok791);
  tcase_add_test(tc_core, test_negate_ok792);
  tcase_add_test(tc_core, test_negate_ok793);
  tcase_add_test(tc_core, test_negate_ok794);
  tcase_add_test(tc_core, test_negate_ok795);
  tcase_add_test(tc_core, test_negate_ok796);
  tcase_add_test(tc_core, test_negate_ok797);
  tcase_add_test(tc_core, test_negate_ok798);
  tcase_add_test(tc_core, test_negate_ok799);
  tcase_add_test(tc_core, test_negate_ok800);

  suite_add_tcase(s, tc_core);
  return s;
}

Suite *negate_suite3(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("negate_suite3");
  tc_core = tcase_create("Core");
  tcase_add_test(tc_core, test_negate_ok801);
  tcase_add_test(tc_core, test_negate_ok802);
  tcase_add_test(tc_core, test_negate_ok803);
  tcase_add_test(tc_core, test_negate_ok804);
  tcase_add_test(tc_core, test_negate_ok805);
  tcase_add_test(tc_core, test_negate_ok806);
  tcase_add_test(tc_core, test_negate_ok807);
  tcase_add_test(tc_core, test_negate_ok808);
  tcase_add_test(tc_core, test_negate_ok809);
  tcase_add_test(tc_core, test_negate_ok810);
  tcase_add_test(tc_core, test_negate_ok811);
  tcase_add_test(tc_core, test_negate_ok812);
  tcase_add_test(tc_core, test_negate_ok813);
  tcase_add_test(tc_core, test_negate_ok814);
  tcase_add_test(tc_core, test_negate_ok815);
  tcase_add_test(tc_core, test_negate_ok816);
  tcase_add_test(tc_core, test_negate_ok817);
  tcase_add_test(tc_core, test_negate_ok818);
  tcase_add_test(tc_core, test_negate_ok819);
  tcase_add_test(tc_core, test_negate_ok820);
  tcase_add_test(tc_core, test_negate_ok821);
  tcase_add_test(tc_core, test_negate_ok822);
  tcase_add_test(tc_core, test_negate_ok823);
  tcase_add_test(tc_core, test_negate_ok824);
  tcase_add_test(tc_core, test_negate_ok825);
  tcase_add_test(tc_core, test_negate_ok826);
  tcase_add_test(tc_core, test_negate_ok827);
  tcase_add_test(tc_core, test_negate_ok828);
  tcase_add_test(tc_core, test_negate_ok829);
  tcase_add_test(tc_core, test_negate_ok830);
  tcase_add_test(tc_core, test_negate_ok831);
  tcase_add_test(tc_core, test_negate_ok832);
  tcase_add_test(tc_core, test_negate_ok833);
  tcase_add_test(tc_core, test_negate_ok834);
  tcase_add_test(tc_core, test_negate_ok835);
  tcase_add_test(tc_core, test_negate_ok836);
  tcase_add_test(tc_core, test_negate_ok837);
  tcase_add_test(tc_core, test_negate_ok838);
  tcase_add_test(tc_core, test_negate_ok839);
  tcase_add_test(tc_core, test_negate_ok840);
  tcase_add_test(tc_core, test_negate_ok841);
  tcase_add_test(tc_core, test_negate_ok842);
  tcase_add_test(tc_core, test_negate_ok843);
  tcase_add_test(tc_core, test_negate_ok844);
  tcase_add_test(tc_core, test_negate_ok845);
  tcase_add_test(tc_core, test_negate_ok846);
  tcase_add_test(tc_core, test_negate_ok847);
  tcase_add_test(tc_core, test_negate_ok848);
  tcase_add_test(tc_core, test_negate_ok849);
  tcase_add_test(tc_core, test_negate_ok850);
  tcase_add_test(tc_core, test_negate_ok851);
  tcase_add_test(tc_core, test_negate_ok852);
  tcase_add_test(tc_core, test_negate_ok853);
  tcase_add_test(tc_core, test_negate_ok854);
  tcase_add_test(tc_core, test_negate_ok855);
  tcase_add_test(tc_core, test_negate_ok856);
  tcase_add_test(tc_core, test_negate_ok857);
  tcase_add_test(tc_core, test_negate_ok858);
  tcase_add_test(tc_core, test_negate_ok859);
  tcase_add_test(tc_core, test_negate_ok860);
  tcase_add_test(tc_core, test_negate_ok861);
  tcase_add_test(tc_core, test_negate_ok862);
  tcase_add_test(tc_core, test_negate_ok863);
  tcase_add_test(tc_core, test_negate_ok864);
  tcase_add_test(tc_core, test_negate_ok865);
  tcase_add_test(tc_core, test_negate_ok866);
  tcase_add_test(tc_core, test_negate_ok867);
  tcase_add_test(tc_core, test_negate_ok868);
  tcase_add_test(tc_core, test_negate_ok869);
  tcase_add_test(tc_core, test_negate_ok870);
  tcase_add_test(tc_core, test_negate_ok871);
  tcase_add_test(tc_core, test_negate_ok872);
  tcase_add_test(tc_core, test_negate_ok873);
  tcase_add_test(tc_core, test_negate_ok874);
  tcase_add_test(tc_core, test_negate_ok875);
  tcase_add_test(tc_core, test_negate_ok876);
  tcase_add_test(tc_core, test_negate_ok877);
  tcase_add_test(tc_core, test_negate_ok878);
  tcase_add_test(tc_core, test_negate_ok879);
  tcase_add_test(tc_core, test_negate_ok880);
  tcase_add_test(tc_core, test_negate_ok881);
  tcase_add_test(tc_core, test_negate_ok882);
  tcase_add_test(tc_core, test_negate_ok883);
  tcase_add_test(tc_core, test_negate_ok884);
  tcase_add_test(tc_core, test_negate_ok885);
  tcase_add_test(tc_core, test_negate_ok886);
  tcase_add_test(tc_core, test_negate_ok887);
  tcase_add_test(tc_core, test_negate_ok888);
  tcase_add_test(tc_core, test_negate_ok889);
  tcase_add_test(tc_core, test_negate_ok890);
  tcase_add_test(tc_core, test_negate_ok891);
  tcase_add_test(tc_core, test_negate_ok892);
  tcase_add_test(tc_core, test_negate_ok893);
  tcase_add_test(tc_core, test_negate_ok894);
  tcase_add_test(tc_core, test_negate_ok895);
  tcase_add_test(tc_core, test_negate_ok896);
  tcase_add_test(tc_core, test_negate_ok897);
  tcase_add_test(tc_core, test_negate_ok898);
  tcase_add_test(tc_core, test_negate_ok899);
  tcase_add_test(tc_core, test_negate_ok900);
  tcase_add_test(tc_core, test_negate_ok901);
  tcase_add_test(tc_core, test_negate_ok902);
  tcase_add_test(tc_core, test_negate_ok903);
  tcase_add_test(tc_core, test_negate_ok904);
  tcase_add_test(tc_core, test_negate_ok905);
  tcase_add_test(tc_core, test_negate_ok906);
  tcase_add_test(tc_core, test_negate_ok907);
  tcase_add_test(tc_core, test_negate_ok908);
  tcase_add_test(tc_core, test_negate_ok909);
  tcase_add_test(tc_core, test_negate_ok910);
  tcase_add_test(tc_core, test_negate_ok911);
  tcase_add_test(tc_core, test_negate_ok912);
  tcase_add_test(tc_core, test_negate_ok913);
  tcase_add_test(tc_core, test_negate_ok914);
  tcase_add_test(tc_core, test_negate_ok915);
  tcase_add_test(tc_core, test_negate_ok916);
  tcase_add_test(tc_core, test_negate_ok917);
  tcase_add_test(tc_core, test_negate_ok918);
  tcase_add_test(tc_core, test_negate_ok919);
  tcase_add_test(tc_core, test_negate_ok920);
  tcase_add_test(tc_core, test_negate_ok921);
  tcase_add_test(tc_core, test_negate_ok922);
  tcase_add_test(tc_core, test_negate_ok923);
  tcase_add_test(tc_core, test_negate_ok924);
  tcase_add_test(tc_core, test_negate_ok925);
  tcase_add_test(tc_core, test_negate_ok926);
  tcase_add_test(tc_core, test_negate_ok927);
  tcase_add_test(tc_core, test_negate_ok928);
  tcase_add_test(tc_core, test_negate_ok929);
  tcase_add_test(tc_core, test_negate_ok930);
  tcase_add_test(tc_core, test_negate_ok931);
  tcase_add_test(tc_core, test_negate_ok932);
  tcase_add_test(tc_core, test_negate_ok933);
  tcase_add_test(tc_core, test_negate_ok934);
  tcase_add_test(tc_core, test_negate_ok935);
  tcase_add_test(tc_core, test_negate_ok936);
  tcase_add_test(tc_core, test_negate_ok937);
  tcase_add_test(tc_core, test_negate_ok938);
  tcase_add_test(tc_core, test_negate_ok939);
  tcase_add_test(tc_core, test_negate_ok940);
  tcase_add_test(tc_core, test_negate_ok941);
  tcase_add_test(tc_core, test_negate_ok942);
  tcase_add_test(tc_core, test_negate_ok943);
  tcase_add_test(tc_core, test_negate_ok944);
  tcase_add_test(tc_core, test_negate_ok945);
  tcase_add_test(tc_core, test_negate_ok946);
  tcase_add_test(tc_core, test_negate_ok947);
  tcase_add_test(tc_core, test_negate_ok948);
  tcase_add_test(tc_core, test_negate_ok949);
  tcase_add_test(tc_core, test_negate_ok950);
  tcase_add_test(tc_core, test_negate_ok951);
  tcase_add_test(tc_core, test_negate_ok952);
  tcase_add_test(tc_core, test_negate_ok953);
  tcase_add_test(tc_core, test_negate_ok954);
  tcase_add_test(tc_core, test_negate_ok955);
  tcase_add_test(tc_core, test_negate_ok956);
  tcase_add_test(tc_core, test_negate_ok957);
  tcase_add_test(tc_core, test_negate_ok958);
  tcase_add_test(tc_core, test_negate_ok959);
  tcase_add_test(tc_core, test_negate_ok960);
  tcase_add_test(tc_core, test_negate_ok961);
  tcase_add_test(tc_core, test_negate_ok962);
  tcase_add_test(tc_core, test_negate_ok963);
  tcase_add_test(tc_core, test_negate_ok964);
  tcase_add_test(tc_core, test_negate_ok965);
  tcase_add_test(tc_core, test_negate_ok966);
  tcase_add_test(tc_core, test_negate_ok967);
  tcase_add_test(tc_core, test_negate_ok968);
  tcase_add_test(tc_core, test_negate_ok969);
  tcase_add_test(tc_core, test_negate_ok970);
  tcase_add_test(tc_core, test_negate_ok971);
  tcase_add_test(tc_core, test_negate_ok972);
  tcase_add_test(tc_core, test_negate_ok973);
  tcase_add_test(tc_core, test_negate_ok974);
  tcase_add_test(tc_core, test_negate_ok975);
  tcase_add_test(tc_core, test_negate_ok976);
  tcase_add_test(tc_core, test_negate_ok977);
  tcase_add_test(tc_core, test_negate_ok978);
  tcase_add_test(tc_core, test_negate_ok979);
  tcase_add_test(tc_core, test_negate_ok980);
  tcase_add_test(tc_core, test_negate_ok981);
  tcase_add_test(tc_core, test_negate_ok982);
  tcase_add_test(tc_core, test_negate_ok983);
  tcase_add_test(tc_core, test_negate_ok984);
  tcase_add_test(tc_core, test_negate_ok985);
  tcase_add_test(tc_core, test_negate_ok986);
  tcase_add_test(tc_core, test_negate_ok987);
  tcase_add_test(tc_core, test_negate_ok988);
  tcase_add_test(tc_core, test_negate_ok989);
  tcase_add_test(tc_core, test_negate_ok990);
  tcase_add_test(tc_core, test_negate_ok991);
  tcase_add_test(tc_core, test_negate_ok992);
  tcase_add_test(tc_core, test_negate_ok993);
  tcase_add_test(tc_core, test_negate_ok994);
  tcase_add_test(tc_core, test_negate_ok995);
  tcase_add_test(tc_core, test_negate_ok996);
  tcase_add_test(tc_core, test_negate_ok997);
  tcase_add_test(tc_core, test_negate_ok998);
  tcase_add_test(tc_core, test_negate_ok999);
  tcase_add_test(tc_core, test_negate_ok1000);
  tcase_add_test(tc_core, test_negate_ok1001);
  tcase_add_test(tc_core, test_negate_ok1002);
  tcase_add_test(tc_core, test_negate_ok1003);
  tcase_add_test(tc_core, test_negate_ok1004);
  tcase_add_test(tc_core, test_negate_ok1005);
  tcase_add_test(tc_core, test_negate_ok1006);
  tcase_add_test(tc_core, test_negate_ok1007);
  tcase_add_test(tc_core, test_negate_ok1008);
  tcase_add_test(tc_core, test_negate_ok1009);
  tcase_add_test(tc_core, test_negate_ok1010);
  tcase_add_test(tc_core, test_negate_ok1011);
  tcase_add_test(tc_core, test_negate_ok1012);
  tcase_add_test(tc_core, test_negate_ok1013);
  tcase_add_test(tc_core, test_negate_ok1014);
  tcase_add_test(tc_core, test_negate_ok1015);
  tcase_add_test(tc_core, test_negate_ok1016);
  tcase_add_test(tc_core, test_negate_ok1017);
  tcase_add_test(tc_core, test_negate_ok1018);
  tcase_add_test(tc_core, test_negate_ok1019);
  tcase_add_test(tc_core, test_negate_ok1020);

  suite_add_tcase(s, tc_core);
  return s;
}

Suite *negate_suite0(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("negate_suite0");
  tc_core = tcase_create("Core");
  tcase_add_test(tc_core, test_negate_fail1);
  tcase_add_test(tc_core, test_negate_fail2);
  tcase_add_test(tc_core, test_negate_fail3);
  tcase_add_test(tc_core, test_negate_fail4);
  tcase_add_test(tc_core, test_negate_fail5);
  tcase_add_test(tc_core, test_negate_fail6);
  tcase_add_test(tc_core, test_negate_fail7);
  tcase_add_test(tc_core, test_negate_fail8);
  tcase_add_test(tc_core, test_negate_fail9);

  suite_add_tcase(s, tc_core);
  return s;
}

void test_negate(my_decimal decimal, my_decimal decimal_check) {
  my_decimal result;

  int code = my_negate(decimal, &result);
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
