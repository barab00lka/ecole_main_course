#include <check.h>
#include <stdio.h>
#include <stdlib.h>

#include "./../../my_decimal.h"
#include "./../test.h"

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * * * * * * * * * * * * * * Тесты на некорректные данные (ручные)
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * * * * * * * * * * * * * */
START_TEST(test_from_decimal_to_int_fail_manual1) {
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x140000}};
  int code = my_from_decimal_to_int(decimal, NULL);

  ck_assert_int_eq(code, TEST_CONVERSION_ERROR);
}

START_TEST(test_from_decimal_to_int_fail_manual2) {
  my_decimal decimal = {{0, 0, 0, 1000000000}};
  int result;
  int code = my_from_decimal_to_int(decimal, &result);

  ck_assert_int_eq(code, TEST_CONVERSION_ERROR);
}
END_TEST

START_TEST(test_from_decimal_to_int_fail_manual3) {
  my_decimal decimal = {{-1, 0, 0, 0x1D0000}};
  int result;
  int code = my_from_decimal_to_int(decimal, &result);

  ck_assert_int_eq(code, TEST_CONVERSION_ERROR);
}
END_TEST

START_TEST(test_from_decimal_to_int_fail_manual4) {
  my_decimal decimal = {{0, 0, 0, 0x1D0000}};
  int result;
  int code = my_from_decimal_to_int(decimal, &result);

  ck_assert_int_eq(code, TEST_CONVERSION_ERROR);
}
END_TEST

START_TEST(test_from_decimal_to_int_fail_manual5) {
  my_decimal decimal = {{-1, 0, 0, 0x1C0001}};
  int result;
  int code = my_from_decimal_to_int(decimal, &result);

  ck_assert_int_eq(code, TEST_CONVERSION_ERROR);
}
END_TEST

START_TEST(test_from_decimal_to_int_fail_manual6) {
  my_decimal decimal = {{-1, 0, 0, 0x1C8000}};
  int result;
  int code = my_from_decimal_to_int(decimal, &result);

  ck_assert_int_eq(code, TEST_CONVERSION_ERROR);
}
END_TEST

START_TEST(test_from_decimal_to_int_fail_manual7) {
  my_decimal decimal = {{-1, 0, 0, 0x11C0000}};
  int result;
  int code = my_from_decimal_to_int(decimal, &result);

  ck_assert_int_eq(code, TEST_CONVERSION_ERROR);
}
END_TEST

START_TEST(test_from_decimal_to_int_fail_manual8) {
  my_decimal decimal = {{-1, 0, 0, 0x401C0000}};
  int result;
  int code = my_from_decimal_to_int(decimal, &result);

  ck_assert_int_eq(code, TEST_CONVERSION_ERROR);
}
END_TEST

START_TEST(test_from_decimal_to_int_fail_manual9) {
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF}};
  int result;
  int code = my_from_decimal_to_int(decimal, &result);

  ck_assert_int_eq(code, TEST_CONVERSION_ERROR);
}
END_TEST

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * * * * * * * * * * * * * * Tests for correct data (automatic)
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * * * * * * * * * * * * * */

START_TEST(test_from_decimal_to_int_ok1) {
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x140000}};
  int check = 792281625;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok2) {
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80140000}};
  int check = -792281625;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok3) {
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x150000}};
  int check = 79228162;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok4) {
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80150000}};
  int check = -79228162;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok5) {
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x160000}};
  int check = 7922816;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok6) {
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80160000}};
  int check = -7922816;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok7) {
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x170000}};
  int check = 792281;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok8) {
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80170000}};
  int check = -792281;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok9) {
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x180000}};
  int check = 79228;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok10) {
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80180000}};
  int check = -79228;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok11) {
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x190000}};
  int check = 7922;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok12) {
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80190000}};
  int check = -7922;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok13) {
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x1A0000}};
  int check = 792;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok14) {
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x801A0000}};
  int check = -792;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok15) {
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x1B0000}};
  int check = 79;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok16) {
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x801B0000}};
  int check = -79;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok17) {
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x1C0000}};
  int check = 7;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok18) {
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x801C0000}};
  int check = -7;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok19) {
  my_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x140000}};
  int check = 792281625;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok20) {
  my_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80140000}};
  int check = -792281625;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok21) {
  my_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x150000}};
  int check = 79228162;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok22) {
  my_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80150000}};
  int check = -79228162;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok23) {
  my_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x160000}};
  int check = 7922816;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok24) {
  my_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80160000}};
  int check = -7922816;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok25) {
  my_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x170000}};
  int check = 792281;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok26) {
  my_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80170000}};
  int check = -792281;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok27) {
  my_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x180000}};
  int check = 79228;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok28) {
  my_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80180000}};
  int check = -79228;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok29) {
  my_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x190000}};
  int check = 7922;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok30) {
  my_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80190000}};
  int check = -7922;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok31) {
  my_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x1A0000}};
  int check = 792;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok32) {
  my_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x801A0000}};
  int check = -792;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok33) {
  my_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x1B0000}};
  int check = 79;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok34) {
  my_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x801B0000}};
  int check = -79;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok35) {
  my_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x1C0000}};
  int check = 7;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok36) {
  my_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x801C0000}};
  int check = -7;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok37) {
  my_decimal decimal = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x140000}};
  int check = 528187750;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok38) {
  my_decimal decimal = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x80140000}};
  int check = -528187750;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok39) {
  my_decimal decimal = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x1C0000}};
  int check = 5;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok40) {
  my_decimal decimal = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x801C0000}};
  int check = -5;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok41) {
  my_decimal decimal = {{0x0, 0xAAAAAAAA, 0xAAAAAAAA, 0x140000}};
  int check = 528187750;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok42) {
  my_decimal decimal = {{0x0, 0xAAAAAAAA, 0xAAAAAAAA, 0x80140000}};
  int check = -528187750;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok43) {
  my_decimal decimal = {{0x0, 0xAAAAAAAA, 0xAAAAAAAA, 0x1C0000}};
  int check = 5;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok44) {
  my_decimal decimal = {{0x0, 0xAAAAAAAA, 0xAAAAAAAA, 0x801C0000}};
  int check = -5;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok45) {
  my_decimal decimal = {{0xAAAAAAAA, 0x0, 0xAAAAAAAA, 0x140000}};
  int check = 528187749;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok46) {
  my_decimal decimal = {{0xAAAAAAAA, 0x0, 0xAAAAAAAA, 0x80140000}};
  int check = -528187749;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok47) {
  my_decimal decimal = {{0xAAAAAAAA, 0x0, 0xAAAAAAAA, 0x1C0000}};
  int check = 5;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok48) {
  my_decimal decimal = {{0xAAAAAAAA, 0x0, 0xAAAAAAAA, 0x801C0000}};
  int check = -5;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok49) {
  my_decimal decimal = {{0x0, 0x0, 0xAAAAAAAA, 0x140000}};
  int check = 528187749;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok50) {
  my_decimal decimal = {{0x0, 0x0, 0xAAAAAAAA, 0x80140000}};
  int check = -528187749;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok51) {
  my_decimal decimal = {{0x0, 0x0, 0xAAAAAAAA, 0x1C0000}};
  int check = 5;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok52) {
  my_decimal decimal = {{0x0, 0x0, 0xAAAAAAAA, 0x801C0000}};
  int check = -5;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok53) {
  my_decimal decimal = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0xB0000}};
  int check = 122978293;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok54) {
  my_decimal decimal = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x800B0000}};
  int check = -122978293;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok55) {
  my_decimal decimal = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x130000}};
  int check = 1;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok56) {
  my_decimal decimal = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x80130000}};
  int check = -1;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok57) {
  my_decimal decimal = {{0x0, 0xAAAAAAAA, 0x0, 0xB0000}};
  int check = 122978293;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok58) {
  my_decimal decimal = {{0x0, 0xAAAAAAAA, 0x0, 0x800B0000}};
  int check = -122978293;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok59) {
  my_decimal decimal = {{0x0, 0xAAAAAAAA, 0x0, 0x130000}};
  int check = 1;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok60) {
  my_decimal decimal = {{0x0, 0xAAAAAAAA, 0x0, 0x80130000}};
  int check = -1;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok61) {
  my_decimal decimal = {{0xAAAAAAAA, 0x0, 0x0, 0x10000}};
  int check = 286331153;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok62) {
  my_decimal decimal = {{0xAAAAAAAA, 0x0, 0x0, 0x80010000}};
  int check = -286331153;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok63) {
  my_decimal decimal = {{0xAAAAAAAA, 0x0, 0x0, 0x40000}};
  int check = 286331;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok64) {
  my_decimal decimal = {{0xAAAAAAAA, 0x0, 0x0, 0x80040000}};
  int check = -286331;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok65) {
  my_decimal decimal = {{0xAAAAAAAA, 0x0, 0x0, 0x90000}};
  int check = 2;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok66) {
  my_decimal decimal = {{0xAAAAAAAA, 0x0, 0x0, 0x80090000}};
  int check = -2;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok67) {
  my_decimal decimal = {{0x55555555, 0x55555555, 0x55555555, 0x140000}};
  int check = 264093875;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok68) {
  my_decimal decimal = {{0x55555555, 0x55555555, 0x55555555, 0x80140000}};
  int check = -264093875;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok69) {
  my_decimal decimal = {{0x55555555, 0x55555555, 0x55555555, 0x1C0000}};
  int check = 2;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok70) {
  my_decimal decimal = {{0x55555555, 0x55555555, 0x55555555, 0x801C0000}};
  int check = -2;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok71) {
  my_decimal decimal = {{0x0, 0x55555555, 0x55555555, 0x140000}};
  int check = 264093875;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok72) {
  my_decimal decimal = {{0x0, 0x55555555, 0x55555555, 0x80140000}};
  int check = -264093875;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok73) {
  my_decimal decimal = {{0x0, 0x55555555, 0x55555555, 0x1C0000}};
  int check = 2;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok74) {
  my_decimal decimal = {{0x0, 0x55555555, 0x55555555, 0x801C0000}};
  int check = -2;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok75) {
  my_decimal decimal = {{0x55555555, 0x0, 0x55555555, 0x140000}};
  int check = 264093874;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok76) {
  my_decimal decimal = {{0x55555555, 0x0, 0x55555555, 0x80140000}};
  int check = -264093874;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok77) {
  my_decimal decimal = {{0x55555555, 0x0, 0x55555555, 0x1C0000}};
  int check = 2;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok78) {
  my_decimal decimal = {{0x55555555, 0x0, 0x55555555, 0x801C0000}};
  int check = -2;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok79) {
  my_decimal decimal = {{0x0, 0x0, 0x55555555, 0x140000}};
  int check = 264093874;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok80) {
  my_decimal decimal = {{0x0, 0x0, 0x55555555, 0x80140000}};
  int check = -264093874;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok81) {
  my_decimal decimal = {{0x0, 0x0, 0x55555555, 0x1C0000}};
  int check = 2;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok82) {
  my_decimal decimal = {{0x0, 0x0, 0x55555555, 0x801C0000}};
  int check = -2;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok83) {
  my_decimal decimal = {{0x55555555, 0x55555555, 0x0, 0xC0000}};
  int check = 6148914;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok84) {
  my_decimal decimal = {{0x55555555, 0x55555555, 0x0, 0x800C0000}};
  int check = -6148914;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok85) {
  my_decimal decimal = {{0x55555555, 0x55555555, 0x0, 0x120000}};
  int check = 6;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok86) {
  my_decimal decimal = {{0x55555555, 0x55555555, 0x0, 0x80120000}};
  int check = -6;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok87) {
  my_decimal decimal = {{0x0, 0x55555555, 0x0, 0xC0000}};
  int check = 6148914;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok88) {
  my_decimal decimal = {{0x0, 0x55555555, 0x0, 0x800C0000}};
  int check = -6148914;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok89) {
  my_decimal decimal = {{0x0, 0x55555555, 0x0, 0x120000}};
  int check = 6;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok90) {
  my_decimal decimal = {{0x0, 0x55555555, 0x0, 0x80120000}};
  int check = -6;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok91) {
  my_decimal decimal = {{0x55555555, 0x0, 0x0, 0x0}};
  int check = 1431655765;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok92) {
  my_decimal decimal = {{0x55555555, 0x0, 0x0, 0x80000000}};
  int check = -1431655765;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok93) {
  my_decimal decimal = {{0x55555555, 0x0, 0x0, 0x10000}};
  int check = 143165576;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok94) {
  my_decimal decimal = {{0x55555555, 0x0, 0x0, 0x80010000}};
  int check = -143165576;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok95) {
  my_decimal decimal = {{0x55555555, 0x0, 0x0, 0x40000}};
  int check = 143165;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok96) {
  my_decimal decimal = {{0x55555555, 0x0, 0x0, 0x80040000}};
  int check = -143165;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok97) {
  my_decimal decimal = {{0x55555555, 0x0, 0x0, 0x90000}};
  int check = 1;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok98) {
  my_decimal decimal = {{0x55555555, 0x0, 0x0, 0x80090000}};
  int check = -1;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok99) {
  my_decimal decimal = {{0x1, 0x1, 0x1, 0xB0000}};
  int check = 184467440;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok100) {
  my_decimal decimal = {{0x1, 0x1, 0x1, 0x800B0000}};
  int check = -184467440;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok101) {
  my_decimal decimal = {{0x1, 0x1, 0x1, 0x130000}};
  int check = 1;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok102) {
  my_decimal decimal = {{0x1, 0x1, 0x1, 0x80130000}};
  int check = -1;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok103) {
  my_decimal decimal = {{0x0, 0x1, 0x1, 0xC0000}};
  int check = 18446744;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok104) {
  my_decimal decimal = {{0x0, 0x1, 0x1, 0x800C0000}};
  int check = -18446744;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok105) {
  my_decimal decimal = {{0x0, 0x1, 0x1, 0x130000}};
  int check = 1;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok106) {
  my_decimal decimal = {{0x0, 0x1, 0x1, 0x80130000}};
  int check = -1;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok107) {
  my_decimal decimal = {{0x1, 0x0, 0x1, 0xD0000}};
  int check = 1844674;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok108) {
  my_decimal decimal = {{0x1, 0x0, 0x1, 0x800D0000}};
  int check = -1844674;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok109) {
  my_decimal decimal = {{0x1, 0x0, 0x1, 0x130000}};
  int check = 1;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok110) {
  my_decimal decimal = {{0x1, 0x0, 0x1, 0x80130000}};
  int check = -1;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok111) {
  my_decimal decimal = {{0x0, 0x0, 0x1, 0xE0000}};
  int check = 184467;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok112) {
  my_decimal decimal = {{0x0, 0x0, 0x1, 0x800E0000}};
  int check = -184467;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok113) {
  my_decimal decimal = {{0x0, 0x0, 0x1, 0x130000}};
  int check = 1;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok114) {
  my_decimal decimal = {{0x0, 0x0, 0x1, 0x80130000}};
  int check = -1;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok115) {
  my_decimal decimal = {{0x1, 0x1, 0x0, 0x10000}};
  int check = 429496729;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok116) {
  my_decimal decimal = {{0x1, 0x1, 0x0, 0x80010000}};
  int check = -429496729;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok117) {
  my_decimal decimal = {{0x1, 0x1, 0x0, 0x20000}};
  int check = 42949672;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok118) {
  my_decimal decimal = {{0x1, 0x1, 0x0, 0x80020000}};
  int check = -42949672;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok119) {
  my_decimal decimal = {{0x1, 0x1, 0x0, 0x40000}};
  int check = 429496;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok120) {
  my_decimal decimal = {{0x1, 0x1, 0x0, 0x80040000}};
  int check = -429496;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok121) {
  my_decimal decimal = {{0x1, 0x1, 0x0, 0x90000}};
  int check = 4;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok122) {
  my_decimal decimal = {{0x1, 0x1, 0x0, 0x80090000}};
  int check = -4;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok123) {
  my_decimal decimal = {{0x1, 0x1, 0x0, 0x80000}};
  int check = 42;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok124) {
  my_decimal decimal = {{0x1, 0x1, 0x0, 0x80080000}};
  int check = -42;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok125) {
  my_decimal decimal = {{0x0, 0x1, 0x0, 0x10000}};
  int check = 429496729;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok126) {
  my_decimal decimal = {{0x0, 0x1, 0x0, 0x80010000}};
  int check = -429496729;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok127) {
  my_decimal decimal = {{0x0, 0x1, 0x0, 0x20000}};
  int check = 42949672;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok128) {
  my_decimal decimal = {{0x0, 0x1, 0x0, 0x80020000}};
  int check = -42949672;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok129) {
  my_decimal decimal = {{0x0, 0x1, 0x0, 0x30000}};
  int check = 4294967;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok130) {
  my_decimal decimal = {{0x0, 0x1, 0x0, 0x80030000}};
  int check = -4294967;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok131) {
  my_decimal decimal = {{0x0, 0x1, 0x0, 0x90000}};
  int check = 4;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok132) {
  my_decimal decimal = {{0x0, 0x1, 0x0, 0x80090000}};
  int check = -4;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok133) {
  my_decimal decimal = {{0x0, 0x1, 0x0, 0x80000}};
  int check = 42;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok134) {
  my_decimal decimal = {{0x0, 0x1, 0x0, 0x80080000}};
  int check = -42;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok135) {
  my_decimal decimal = {{0x1, 0x0, 0x0, 0x0}};
  int check = 1;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok136) {
  my_decimal decimal = {{0x1, 0x0, 0x0, 0x80000000}};
  int check = -1;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok137) {
  my_decimal decimal = {{0x1, 0x0, 0x0, 0x10000}};
  int check = 0;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok138) {
  my_decimal decimal = {{0x1, 0x0, 0x0, 0x80010000}};
  int check = 0;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok139) {
  my_decimal decimal = {{0x1, 0x0, 0x0, 0xD0000}};
  int check = 0;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok140) {
  my_decimal decimal = {{0x1, 0x0, 0x0, 0x800D0000}};
  int check = 0;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok141) {
  my_decimal decimal = {{0x1, 0x0, 0x0, 0xE0000}};
  int check = 0;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok142) {
  my_decimal decimal = {{0x1, 0x0, 0x0, 0x800E0000}};
  int check = 0;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok143) {
  my_decimal decimal = {{0x1, 0x0, 0x0, 0x1B0000}};
  int check = 0;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok144) {
  my_decimal decimal = {{0x1, 0x0, 0x0, 0x801B0000}};
  int check = 0;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok145) {
  my_decimal decimal = {{0x1, 0x0, 0x0, 0x1C0000}};
  int check = 0;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok146) {
  my_decimal decimal = {{0x1, 0x0, 0x0, 0x801C0000}};
  int check = 0;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok147) {
  my_decimal decimal = {{0x80000000, 0x80000000, 0x80000000, 0x140000}};
  int check = 396140812;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok148) {
  my_decimal decimal = {{0x80000000, 0x80000000, 0x80000000, 0x80140000}};
  int check = -396140812;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok149) {
  my_decimal decimal = {{0x80000000, 0x80000000, 0x80000000, 0x1C0000}};
  int check = 3;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok150) {
  my_decimal decimal = {{0x80000000, 0x80000000, 0x80000000, 0x801C0000}};
  int check = -3;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok151) {
  my_decimal decimal = {{0x0, 0x80000000, 0x80000000, 0x150000}};
  int check = 39614081;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok152) {
  my_decimal decimal = {{0x0, 0x80000000, 0x80000000, 0x80150000}};
  int check = -39614081;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok153) {
  my_decimal decimal = {{0x0, 0x80000000, 0x80000000, 0x1C0000}};
  int check = 3;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok154) {
  my_decimal decimal = {{0x0, 0x80000000, 0x80000000, 0x801C0000}};
  int check = -3;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok155) {
  my_decimal decimal = {{0x80000000, 0x0, 0x80000000, 0x160000}};
  int check = 3961408;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok156) {
  my_decimal decimal = {{0x80000000, 0x0, 0x80000000, 0x80160000}};
  int check = -3961408;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok157) {
  my_decimal decimal = {{0x80000000, 0x0, 0x80000000, 0x1C0000}};
  int check = 3;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok158) {
  my_decimal decimal = {{0x80000000, 0x0, 0x80000000, 0x801C0000}};
  int check = -3;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok159) {
  my_decimal decimal = {{0x0, 0x0, 0x80000000, 0x170000}};
  int check = 396140;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok160) {
  my_decimal decimal = {{0x0, 0x0, 0x80000000, 0x80170000}};
  int check = -396140;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok161) {
  my_decimal decimal = {{0x0, 0x0, 0x80000000, 0x1C0000}};
  int check = 3;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok162) {
  my_decimal decimal = {{0x0, 0x0, 0x80000000, 0x801C0000}};
  int check = -3;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok163) {
  my_decimal decimal = {{0x80000000, 0x80000000, 0x0, 0xA0000}};
  int check = 922337203;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok164) {
  my_decimal decimal = {{0x80000000, 0x80000000, 0x0, 0x800A0000}};
  int check = -922337203;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok165) {
  my_decimal decimal = {{0x80000000, 0x80000000, 0x0, 0x120000}};
  int check = 9;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok166) {
  my_decimal decimal = {{0x80000000, 0x80000000, 0x0, 0x80120000}};
  int check = -9;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok167) {
  my_decimal decimal = {{0x0, 0x80000000, 0x0, 0xB0000}};
  int check = 92233720;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok168) {
  my_decimal decimal = {{0x0, 0x80000000, 0x0, 0x800B0000}};
  int check = -92233720;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok169) {
  my_decimal decimal = {{0x0, 0x80000000, 0x0, 0x120000}};
  int check = 9;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok170) {
  my_decimal decimal = {{0x0, 0x80000000, 0x0, 0x80120000}};
  int check = -9;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok171) {
  my_decimal decimal = {{0x80000000, 0x0, 0x0, 0x80000000}};
  int check = -2147483648;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok172) {
  my_decimal decimal = {{0x80000000, 0x0, 0x0, 0x10000}};
  int check = 214748364;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok173) {
  my_decimal decimal = {{0x80000000, 0x0, 0x0, 0x80010000}};
  int check = -214748364;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok174) {
  my_decimal decimal = {{0x80000000, 0x0, 0x0, 0x20000}};
  int check = 21474836;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok175) {
  my_decimal decimal = {{0x80000000, 0x0, 0x0, 0x80020000}};
  int check = -21474836;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok176) {
  my_decimal decimal = {{0x80000000, 0x0, 0x0, 0x40000}};
  int check = 214748;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok177) {
  my_decimal decimal = {{0x80000000, 0x0, 0x0, 0x80040000}};
  int check = -214748;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok178) {
  my_decimal decimal = {{0x80000000, 0x0, 0x0, 0x80000}};
  int check = 21;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok179) {
  my_decimal decimal = {{0x80000000, 0x0, 0x0, 0x80080000}};
  int check = -21;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok180) {
  my_decimal decimal = {{0x80000000, 0x0, 0x0, 0x90000}};
  int check = 2;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok181) {
  my_decimal decimal = {{0x80000000, 0x0, 0x0, 0x80090000}};
  int check = -2;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok182) {
  my_decimal decimal = {{0x811800, 0x811800, 0x811800, 0x140000}};
  int check = 1560647;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok183) {
  my_decimal decimal = {{0x811800, 0x811800, 0x811800, 0x80140000}};
  int check = -1560647;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok184) {
  my_decimal decimal = {{0x811800, 0x811800, 0x811800, 0x1A0000}};
  int check = 1;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok185) {
  my_decimal decimal = {{0x811800, 0x811800, 0x811800, 0x801A0000}};
  int check = -1;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok186) {
  my_decimal decimal = {{0x0, 0x811800, 0x811800, 0x130000}};
  int check = 15606476;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok187) {
  my_decimal decimal = {{0x0, 0x811800, 0x811800, 0x80130000}};
  int check = -15606476;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok188) {
  my_decimal decimal = {{0x0, 0x811800, 0x811800, 0x1A0000}};
  int check = 1;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok189) {
  my_decimal decimal = {{0x0, 0x811800, 0x811800, 0x801A0000}};
  int check = -1;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok190) {
  my_decimal decimal = {{0x811800, 0x0, 0x811800, 0x150000}};
  int check = 156064;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok191) {
  my_decimal decimal = {{0x811800, 0x0, 0x811800, 0x80150000}};
  int check = -156064;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok192) {
  my_decimal decimal = {{0x811800, 0x0, 0x811800, 0x1A0000}};
  int check = 1;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok193) {
  my_decimal decimal = {{0x811800, 0x0, 0x811800, 0x801A0000}};
  int check = -1;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok194) {
  my_decimal decimal = {{0x0, 0x0, 0x811800, 0x160000}};
  int check = 15606;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok195) {
  my_decimal decimal = {{0x0, 0x0, 0x811800, 0x80160000}};
  int check = -15606;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok196) {
  my_decimal decimal = {{0x0, 0x0, 0x811800, 0x1A0000}};
  int check = 1;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok197) {
  my_decimal decimal = {{0x0, 0x0, 0x811800, 0x801A0000}};
  int check = -1;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok198) {
  my_decimal decimal = {{0x811800, 0x811800, 0x0, 0x80000}};
  int check = 363366602;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok199) {
  my_decimal decimal = {{0x811800, 0x811800, 0x0, 0x80080000}};
  int check = -363366602;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok200) {
  my_decimal decimal = {{0x811800, 0x811800, 0x0, 0x100000}};
  int check = 3;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok201) {
  my_decimal decimal = {{0x811800, 0x811800, 0x0, 0x80100000}};
  int check = -3;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok202) {
  my_decimal decimal = {{0x0, 0x811800, 0x0, 0xA0000}};
  int check = 3633666;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok203) {
  my_decimal decimal = {{0x0, 0x811800, 0x0, 0x800A0000}};
  int check = -3633666;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok204) {
  my_decimal decimal = {{0x0, 0x811800, 0x0, 0x80000}};
  int check = 363366602;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok205) {
  my_decimal decimal = {{0x0, 0x811800, 0x0, 0x80080000}};
  int check = -363366602;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok206) {
  my_decimal decimal = {{0x0, 0x811800, 0x0, 0xF0000}};
  int check = 36;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok207) {
  my_decimal decimal = {{0x0, 0x811800, 0x0, 0x800F0000}};
  int check = -36;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok208) {
  my_decimal decimal = {{0x0, 0x811800, 0x0, 0x100000}};
  int check = 3;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok209) {
  my_decimal decimal = {{0x0, 0x811800, 0x0, 0x80100000}};
  int check = -3;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok210) {
  my_decimal decimal = {{0x811800, 0x0, 0x0, 0x0}};
  int check = 8460288;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok211) {
  my_decimal decimal = {{0x811800, 0x0, 0x0, 0x80000000}};
  int check = -8460288;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok212) {
  my_decimal decimal = {{0x811800, 0x0, 0x0, 0x10000}};
  int check = 846028;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok213) {
  my_decimal decimal = {{0x811800, 0x0, 0x0, 0x80010000}};
  int check = -846028;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok214) {
  my_decimal decimal = {{0x811800, 0x0, 0x0, 0x20000}};
  int check = 84602;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok215) {
  my_decimal decimal = {{0x811800, 0x0, 0x0, 0x80020000}};
  int check = -84602;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok216) {
  my_decimal decimal = {{0x811800, 0x0, 0x0, 0x30000}};
  int check = 8460;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok217) {
  my_decimal decimal = {{0x811800, 0x0, 0x0, 0x80030000}};
  int check = -8460;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok218) {
  my_decimal decimal = {{0x811800, 0x0, 0x0, 0x50000}};
  int check = 84;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok219) {
  my_decimal decimal = {{0x811800, 0x0, 0x0, 0x80050000}};
  int check = -84;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok220) {
  my_decimal decimal = {{0x811800, 0x0, 0x0, 0x60000}};
  int check = 8;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok221) {
  my_decimal decimal = {{0x811800, 0x0, 0x0, 0x80060000}};
  int check = -8;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok222) {
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x140000}};
  int check = 792281625;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok223) {
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80140000}};
  int check = -792281625;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok224) {
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x1C0000}};
  int check = 7;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok225) {
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x801C0000}};
  int check = -7;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok226) {
  my_decimal decimal = {{0x0, 0xFFFFFFFF, 0xFFFFFFFF, 0x150000}};
  int check = 79228162;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok227) {
  my_decimal decimal = {{0x0, 0xFFFFFFFF, 0xFFFFFFFF, 0x80150000}};
  int check = -79228162;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok228) {
  my_decimal decimal = {{0x0, 0xFFFFFFFF, 0xFFFFFFFF, 0x1C0000}};
  int check = 7;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok229) {
  my_decimal decimal = {{0x0, 0xFFFFFFFF, 0xFFFFFFFF, 0x801C0000}};
  int check = -7;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok230) {
  my_decimal decimal = {{0xFFFFFFFF, 0x0, 0xFFFFFFFF, 0x160000}};
  int check = 7922816;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok231) {
  my_decimal decimal = {{0xFFFFFFFF, 0x0, 0xFFFFFFFF, 0x80160000}};
  int check = -7922816;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok232) {
  my_decimal decimal = {{0xFFFFFFFF, 0x0, 0xFFFFFFFF, 0x1C0000}};
  int check = 7;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok233) {
  my_decimal decimal = {{0xFFFFFFFF, 0x0, 0xFFFFFFFF, 0x801C0000}};
  int check = -7;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok234) {
  my_decimal decimal = {{0x0, 0x0, 0xFFFFFFFF, 0x170000}};
  int check = 792281;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok235) {
  my_decimal decimal = {{0x0, 0x0, 0xFFFFFFFF, 0x80170000}};
  int check = -792281;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok236) {
  my_decimal decimal = {{0x0, 0x0, 0xFFFFFFFF, 0x1C0000}};
  int check = 7;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok237) {
  my_decimal decimal = {{0x0, 0x0, 0xFFFFFFFF, 0x801C0000}};
  int check = -7;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok238) {
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0x0, 0xB0000}};
  int check = 184467440;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok239) {
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0x0, 0x800B0000}};
  int check = -184467440;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok240) {
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0x0, 0x110000}};
  int check = 184;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok241) {
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0x0, 0x80110000}};
  int check = -184;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok242) {
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0x0, 0x130000}};
  int check = 1;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok243) {
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0x0, 0x80130000}};
  int check = -1;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok244) {
  my_decimal decimal = {{0x0, 0xFFFFFFFF, 0x0, 0xC0000}};
  int check = 18446744;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok245) {
  my_decimal decimal = {{0x0, 0xFFFFFFFF, 0x0, 0x800C0000}};
  int check = -18446744;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok246) {
  my_decimal decimal = {{0x0, 0xFFFFFFFF, 0x0, 0x110000}};
  int check = 184;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok247) {
  my_decimal decimal = {{0x0, 0xFFFFFFFF, 0x0, 0x80110000}};
  int check = -184;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok248) {
  my_decimal decimal = {{0x0, 0xFFFFFFFF, 0x0, 0x130000}};
  int check = 1;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok249) {
  my_decimal decimal = {{0x0, 0xFFFFFFFF, 0x0, 0x80130000}};
  int check = -1;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok250) {
  my_decimal decimal = {{0xFFFFFFFF, 0x0, 0x0, 0x10000}};
  int check = 429496729;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok251) {
  my_decimal decimal = {{0xFFFFFFFF, 0x0, 0x0, 0x80010000}};
  int check = -429496729;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok252) {
  my_decimal decimal = {{0xFFFFFFFF, 0x0, 0x0, 0x20000}};
  int check = 42949672;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok253) {
  my_decimal decimal = {{0xFFFFFFFF, 0x0, 0x0, 0x80020000}};
  int check = -42949672;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok254) {
  my_decimal decimal = {{0xFFFFFFFF, 0x0, 0x0, 0x50000}};
  int check = 42949;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok255) {
  my_decimal decimal = {{0xFFFFFFFF, 0x0, 0x0, 0x80050000}};
  int check = -42949;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok256) {
  my_decimal decimal = {{0xFFFFFFFF, 0x0, 0x0, 0x80000}};
  int check = 42;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok257) {
  my_decimal decimal = {{0xFFFFFFFF, 0x0, 0x0, 0x80080000}};
  int check = -42;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok258) {
  my_decimal decimal = {{0xFFFFFFFF, 0x0, 0x0, 0x90000}};
  int check = 4;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok259) {
  my_decimal decimal = {{0xFFFFFFFF, 0x0, 0x0, 0x80090000}};
  int check = -4;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok260) {
  my_decimal decimal = {{0xA, 0x0, 0x0, 0x10000}};
  int check = 1;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok261) {
  my_decimal decimal = {{0xA, 0x0, 0x0, 0x80010000}};
  int check = -1;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok262) {
  my_decimal decimal = {{0x64, 0x0, 0x0, 0x20000}};
  int check = 1;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok263) {
  my_decimal decimal = {{0x64, 0x0, 0x0, 0x80020000}};
  int check = -1;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok264) {
  my_decimal decimal = {{0x3E8, 0x0, 0x0, 0x30000}};
  int check = 1;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok265) {
  my_decimal decimal = {{0x3E8, 0x0, 0x0, 0x80030000}};
  int check = -1;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok266) {
  my_decimal decimal = {{0x540BE400, 0x2, 0x0, 0xA0000}};
  int check = 1;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok267) {
  my_decimal decimal = {{0x540BE400, 0x2, 0x0, 0x800A0000}};
  int check = -1;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok268) {
  my_decimal decimal = {{0x6FC10000, 0x2386F2, 0x0, 0x100000}};
  int check = 1;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok269) {
  my_decimal decimal = {{0x6FC10000, 0x2386F2, 0x0, 0x80100000}};
  int check = -1;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok270) {
  my_decimal decimal = {{0xF6800000, 0x2C7E14A, 0x152D, 0x170000}};
  int check = 1;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok271) {
  my_decimal decimal = {{0xF6800000, 0x2C7E14A, 0x152D, 0x80170000}};
  int check = -1;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok272) {
  my_decimal decimal = {{0xE8000000, 0x9FD0803C, 0x33B2E3C, 0x1B0000}};
  int check = 1;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok273) {
  my_decimal decimal = {{0xE8000000, 0x9FD0803C, 0x33B2E3C, 0x801B0000}};
  int check = -1;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok274) {
  my_decimal decimal = {{0x10000000, 0x3E250261, 0x204FCE5E, 0x1C0000}};
  int check = 1;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok275) {
  my_decimal decimal = {{0x10000000, 0x3E250261, 0x204FCE5E, 0x801C0000}};
  int check = -1;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok276) {
  my_decimal decimal = {{0xB, 0x0, 0x0, 0x10000}};
  int check = 1;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok277) {
  my_decimal decimal = {{0xB, 0x0, 0x0, 0x80010000}};
  int check = -1;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok278) {
  my_decimal decimal = {{0x4BC, 0x0, 0x0, 0x20000}};
  int check = 12;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok279) {
  my_decimal decimal = {{0x4BC, 0x0, 0x0, 0x80020000}};
  int check = -12;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok280) {
  my_decimal decimal = {{0x1E0F3, 0x0, 0x0, 0x30000}};
  int check = 123;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok281) {
  my_decimal decimal = {{0x1E0F3, 0x0, 0x0, 0x80030000}};
  int check = -123;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok282) {
  my_decimal decimal = {{0xBC4FF2, 0x0, 0x0, 0x40000}};
  int check = 1234;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok283) {
  my_decimal decimal = {{0xBC4FF2, 0x0, 0x0, 0x80040000}};
  int check = -1234;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok284) {
  my_decimal decimal = {{0x499529D9, 0x0, 0x0, 0x50000}};
  int check = 12345;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok285) {
  my_decimal decimal = {{0x499529D9, 0x0, 0x0, 0x80050000}};
  int check = -12345;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok286) {
  my_decimal decimal = {{0xBE8EF240, 0x1C, 0x0, 0x60000}};
  int check = 123456;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok287) {
  my_decimal decimal = {{0xBE8EF240, 0x1C, 0x0, 0x80060000}};
  int check = -123456;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok288) {
  my_decimal decimal = {{0x73593407, 0xB3A, 0x0, 0x70000}};
  int check = 1234567;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok289) {
  my_decimal decimal = {{0x73593407, 0xB3A, 0x0, 0x80070000}};
  int check = -1234567;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok290) {
  my_decimal decimal = {{0xEB1F0AD2, 0xAB54A98C, 0x0, 0xA0000}};
  int check = 1234567890;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok291) {
  my_decimal decimal = {{0xEB1F0AD2, 0xAB54A98C, 0x0, 0x800A0000}};
  int check = -1234567890;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok292) {
  my_decimal decimal = {{0x63, 0x0, 0x0, 0x0}};
  int check = 99;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok293) {
  my_decimal decimal = {{0x63, 0x0, 0x0, 0x80000000}};
  int check = -99;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok294) {
  my_decimal decimal = {{0x63, 0x0, 0x0, 0x10000}};
  int check = 9;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok295) {
  my_decimal decimal = {{0x63, 0x0, 0x0, 0x80010000}};
  int check = -9;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok296) {
  my_decimal decimal = {{0x270F, 0x0, 0x0, 0x20000}};
  int check = 99;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok297) {
  my_decimal decimal = {{0x270F, 0x0, 0x0, 0x80020000}};
  int check = -99;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok298) {
  my_decimal decimal = {{0xF423F, 0x0, 0x0, 0x30000}};
  int check = 999;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok299) {
  my_decimal decimal = {{0xF423F, 0x0, 0x0, 0x80030000}};
  int check = -999;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok300) {
  my_decimal decimal = {{0x5F5E0FF, 0x0, 0x0, 0x40000}};
  int check = 9999;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok301) {
  my_decimal decimal = {{0x5F5E0FF, 0x0, 0x0, 0x80040000}};
  int check = -9999;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok302) {
  my_decimal decimal = {{0x540BE3FF, 0x2, 0x0, 0x50000}};
  int check = 99999;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok303) {
  my_decimal decimal = {{0x540BE3FF, 0x2, 0x0, 0x80050000}};
  int check = -99999;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok304) {
  my_decimal decimal = {{0xD4A50FFF, 0xE8, 0x0, 0x60000}};
  int check = 999999;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok305) {
  my_decimal decimal = {{0xD4A50FFF, 0xE8, 0x0, 0x80060000}};
  int check = -999999;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok306) {
  my_decimal decimal = {{0x107A3FFF, 0x5AF3, 0x0, 0x70000}};
  int check = 9999999;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok307) {
  my_decimal decimal = {{0x107A3FFF, 0x5AF3, 0x0, 0x80070000}};
  int check = -9999999;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok308) {
  my_decimal decimal = {{0x6FC0FFFF, 0x2386F2, 0x0, 0x80000}};
  int check = 99999999;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok309) {
  my_decimal decimal = {{0x6FC0FFFF, 0x2386F2, 0x0, 0x80080000}};
  int check = -99999999;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok310) {
  my_decimal decimal = {{0xA763FFFF, 0xDE0B6B3, 0x0, 0x90000}};
  int check = 999999999;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok311) {
  my_decimal decimal = {{0xA763FFFF, 0xDE0B6B3, 0x0, 0x80090000}};
  int check = -999999999;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok312) {
  my_decimal decimal = {{0x9, 0x0, 0x0, 0x0}};
  int check = 9;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok313) {
  my_decimal decimal = {{0x9, 0x0, 0x0, 0x80000000}};
  int check = -9;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok314) {
  my_decimal decimal = {{0x9, 0x0, 0x0, 0x10000}};
  int check = 0;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok315) {
  my_decimal decimal = {{0x9, 0x0, 0x0, 0x80010000}};
  int check = 0;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok316) {
  my_decimal decimal = {{0x63, 0x0, 0x0, 0x20000}};
  int check = 0;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok317) {
  my_decimal decimal = {{0x63, 0x0, 0x0, 0x80020000}};
  int check = 0;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok318) {
  my_decimal decimal = {{0x3E7, 0x0, 0x0, 0x30000}};
  int check = 0;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok319) {
  my_decimal decimal = {{0x3E7, 0x0, 0x0, 0x80030000}};
  int check = 0;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok320) {
  my_decimal decimal = {{0x270F, 0x0, 0x0, 0x40000}};
  int check = 0;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok321) {
  my_decimal decimal = {{0x270F, 0x0, 0x0, 0x80040000}};
  int check = 0;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok322) {
  my_decimal decimal = {{0x1869F, 0x0, 0x0, 0x50000}};
  int check = 0;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok323) {
  my_decimal decimal = {{0x1869F, 0x0, 0x0, 0x80050000}};
  int check = 0;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok324) {
  my_decimal decimal = {{0xF423F, 0x0, 0x0, 0x60000}};
  int check = 0;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok325) {
  my_decimal decimal = {{0xF423F, 0x0, 0x0, 0x80060000}};
  int check = 0;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok326) {
  my_decimal decimal = {{0x98967F, 0x0, 0x0, 0x70000}};
  int check = 0;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok327) {
  my_decimal decimal = {{0x98967F, 0x0, 0x0, 0x80070000}};
  int check = 0;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok328) {
  my_decimal decimal = {{0x5F5E0FF, 0x0, 0x0, 0x80000}};
  int check = 0;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok329) {
  my_decimal decimal = {{0x5F5E0FF, 0x0, 0x0, 0x80080000}};
  int check = 0;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok330) {
  my_decimal decimal = {{0x3B9AC9FF, 0x0, 0x0, 0x90000}};
  int check = 0;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok331) {
  my_decimal decimal = {{0x3B9AC9FF, 0x0, 0x0, 0x80090000}};
  int check = 0;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok332) {
  my_decimal decimal = {{0x540BE3FF, 0x2, 0x0, 0xA0000}};
  int check = 0;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok333) {
  my_decimal decimal = {{0x540BE3FF, 0x2, 0x0, 0x800A0000}};
  int check = 0;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok334) {
  my_decimal decimal = {{0x630FFFFF, 0x6BC75E2D, 0x5, 0x140000}};
  int check = 0;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok335) {
  my_decimal decimal = {{0x630FFFFF, 0x6BC75E2D, 0x5, 0x80140000}};
  int check = 0;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok336) {
  my_decimal decimal = {{0x0, 0x0, 0x0, 0x80000000}};
  int check = 0;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok337) {
  my_decimal decimal = {{0x0, 0x0, 0x0, 0x0}};
  int check = 0;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok338) {
  my_decimal decimal = {{0x0, 0x0, 0x0, 0x80010000}};
  int check = 0;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok339) {
  my_decimal decimal = {{0x0, 0x0, 0x0, 0x10000}};
  int check = 0;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok340) {
  my_decimal decimal = {{0x0, 0x0, 0x0, 0x80020000}};
  int check = 0;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok341) {
  my_decimal decimal = {{0x0, 0x0, 0x0, 0x20000}};
  int check = 0;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok342) {
  my_decimal decimal = {{0x0, 0x0, 0x0, 0x800E0000}};
  int check = 0;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok343) {
  my_decimal decimal = {{0x0, 0x0, 0x0, 0xE0000}};
  int check = 0;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok344) {
  my_decimal decimal = {{0x0, 0x0, 0x0, 0x801B0000}};
  int check = 0;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok345) {
  my_decimal decimal = {{0x0, 0x0, 0x0, 0x1B0000}};
  int check = 0;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok346) {
  my_decimal decimal = {{0x0, 0x0, 0x0, 0x801C0000}};
  int check = 0;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok347) {
  my_decimal decimal = {{0x0, 0x0, 0x0, 0x1C0000}};
  int check = 0;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok348) {
  my_decimal decimal = {{0x7FFFFFFE, 0x0, 0x0, 0x0}};
  int check = 2147483646;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok349) {
  my_decimal decimal = {{0x7FFFFFFE, 0x0, 0x0, 0x80000000}};
  int check = -2147483646;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok350) {
  my_decimal decimal = {{0xFFFFFF38, 0x31, 0x0, 0x20000}};
  int check = 2147483646;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok351) {
  my_decimal decimal = {{0xFFFFFF38, 0x31, 0x0, 0x80020000}};
  int check = -2147483646;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok352) {
  my_decimal decimal = {{0xFFFFFF9B, 0x31, 0x0, 0x20000}};
  int check = 2147483646;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok353) {
  my_decimal decimal = {{0xFFFFFF9B, 0x31, 0x0, 0x80020000}};
  int check = -2147483646;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok354) {
  my_decimal decimal = {{0x589BFFFF, 0xC5D1494C, 0x6F05B59, 0x120000}};
  int check = 2147483646;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok355) {
  my_decimal decimal = {{0x589BFFFF, 0xC5D1494C, 0x6F05B59, 0x80120000}};
  int check = -2147483646;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok356) {
  my_decimal decimal = {{0x7FFFFFFE, 0x0, 0x0, 0x20000}};
  int check = 21474836;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok357) {
  my_decimal decimal = {{0x7FFFFFFE, 0x0, 0x0, 0x80020000}};
  int check = -21474836;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok358) {
  my_decimal decimal = {{0x7FFFFFFE, 0x0, 0x0, 0x70000}};
  int check = 214;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok359) {
  my_decimal decimal = {{0x7FFFFFFE, 0x0, 0x0, 0x80070000}};
  int check = -214;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok360) {
  my_decimal decimal = {{0x7FFFFFFE, 0x0, 0x0, 0x90000}};
  int check = 2;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok361) {
  my_decimal decimal = {{0x7FFFFFFE, 0x0, 0x0, 0x80090000}};
  int check = -2;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok362) {
  my_decimal decimal = {{0x7FFFFFFE, 0x0, 0x0, 0xA0000}};
  int check = 0;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok363) {
  my_decimal decimal = {{0x7FFFFFFE, 0x0, 0x0, 0x800A0000}};
  int check = 0;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok364) {
  my_decimal decimal = {{0x7FFFFFFE, 0x0, 0x0, 0x1C0000}};
  int check = 0;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok365) {
  my_decimal decimal = {{0x7FFFFFFE, 0x0, 0x0, 0x801C0000}};
  int check = 0;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok366) {
  my_decimal decimal = {{0x7FFFFFFF, 0x0, 0x0, 0x0}};
  int check = 2147483647;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok367) {
  my_decimal decimal = {{0x7FFFFFFF, 0x0, 0x0, 0x80000000}};
  int check = -2147483647;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok368) {
  my_decimal decimal = {{0xFFFFFF9C, 0x31, 0x0, 0x20000}};
  int check = 2147483647;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok369) {
  my_decimal decimal = {{0xFFFFFF9C, 0x31, 0x0, 0x80020000}};
  int check = -2147483647;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok370) {
  my_decimal decimal = {{0xFFFFFFFF, 0x31, 0x0, 0x20000}};
  int check = 2147483647;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok371) {
  my_decimal decimal = {{0xFFFFFFFF, 0x31, 0x0, 0x80020000}};
  int check = -2147483647;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok372) {
  my_decimal decimal = {{0xFFFFFFFF, 0xD3B1FFFF, 0x6F05B59, 0x120000}};
  int check = 2147483647;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok373) {
  my_decimal decimal = {{0xFFFFFFFF, 0xD3B1FFFF, 0x6F05B59, 0x80120000}};
  int check = -2147483647;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok374) {
  my_decimal decimal = {{0x7FFFFFFF, 0x0, 0x0, 0x20000}};
  int check = 21474836;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok375) {
  my_decimal decimal = {{0x7FFFFFFF, 0x0, 0x0, 0x80020000}};
  int check = -21474836;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok376) {
  my_decimal decimal = {{0x7FFFFFFF, 0x0, 0x0, 0x70000}};
  int check = 214;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok377) {
  my_decimal decimal = {{0x7FFFFFFF, 0x0, 0x0, 0x80070000}};
  int check = -214;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok378) {
  my_decimal decimal = {{0x7FFFFFFF, 0x0, 0x0, 0x90000}};
  int check = 2;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok379) {
  my_decimal decimal = {{0x7FFFFFFF, 0x0, 0x0, 0x80090000}};
  int check = -2;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok380) {
  my_decimal decimal = {{0x7FFFFFFF, 0x0, 0x0, 0xA0000}};
  int check = 0;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok381) {
  my_decimal decimal = {{0x7FFFFFFF, 0x0, 0x0, 0x800A0000}};
  int check = 0;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok382) {
  my_decimal decimal = {{0x7FFFFFFF, 0x0, 0x0, 0x1C0000}};
  int check = 0;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok383) {
  my_decimal decimal = {{0x7FFFFFFF, 0x0, 0x0, 0x801C0000}};
  int check = 0;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok384) {
  my_decimal decimal = {{0x80000000, 0x0, 0x0, 0x80000000}};
  int check = -2147483648;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok385) {
  my_decimal decimal = {{0x0, 0x32, 0x0, 0x80020000}};
  int check = -2147483648;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok386) {
  my_decimal decimal = {{0x63, 0x32, 0x0, 0x80020000}};
  int check = -2147483648;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok387) {
  my_decimal decimal = {{0xA763FFFF, 0xE192B6B3, 0x6F05B59, 0x80120000}};
  int check = -2147483648;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok388) {
  my_decimal decimal = {{0x80000000, 0x0, 0x0, 0x20000}};
  int check = 21474836;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok389) {
  my_decimal decimal = {{0x80000000, 0x0, 0x0, 0x80020000}};
  int check = -21474836;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok390) {
  my_decimal decimal = {{0x80000000, 0x0, 0x0, 0x70000}};
  int check = 214;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok391) {
  my_decimal decimal = {{0x80000000, 0x0, 0x0, 0x80070000}};
  int check = -214;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok392) {
  my_decimal decimal = {{0x80000000, 0x0, 0x0, 0x90000}};
  int check = 2;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok393) {
  my_decimal decimal = {{0x80000000, 0x0, 0x0, 0x80090000}};
  int check = -2;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok394) {
  my_decimal decimal = {{0x80000000, 0x0, 0x0, 0xA0000}};
  int check = 0;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok395) {
  my_decimal decimal = {{0x80000000, 0x0, 0x0, 0x800A0000}};
  int check = 0;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok396) {
  my_decimal decimal = {{0x80000000, 0x0, 0x0, 0x1C0000}};
  int check = 0;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok397) {
  my_decimal decimal = {{0x80000000, 0x0, 0x0, 0x801C0000}};
  int check = 0;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok398) {
  my_decimal decimal = {{0x78A08920, 0x0, 0x0, 0x80040000}};
  int check = -202378;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok399) {
  my_decimal decimal = {{0x78A08920, 0x0, 0x0, 0x40000}};
  int check = 202378;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok400) {
  my_decimal decimal = {{0x44F975DB, 0x0, 0x0, 0x0}};
  int check = 1157199323;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok401) {
  my_decimal decimal = {{0x44F975DB, 0x0, 0x0, 0x80000000}};
  int check = -1157199323;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok402) {
  my_decimal decimal = {{0x3E76C533, 0x0, 0x0, 0x80000000}};
  int check = -1047971123;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok403) {
  my_decimal decimal = {{0x3E76C533, 0x0, 0x0, 0x0}};
  int check = 1047971123;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok404) {
  my_decimal decimal = {{0x6182FB5E, 0x0, 0x0, 0x0}};
  int check = 1635973982;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok405) {
  my_decimal decimal = {{0x6182FB5E, 0x0, 0x0, 0x80000000}};
  int check = -1635973982;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok406) {
  my_decimal decimal = {{0x633CB386, 0x0, 0x0, 0x0}};
  int check = 1664922502;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok407) {
  my_decimal decimal = {{0x633CB386, 0x0, 0x0, 0x80000000}};
  int check = -1664922502;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok408) {
  my_decimal decimal = {{0x5D20BE98, 0x0, 0x0, 0x80000000}};
  int check = -1562427032;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok409) {
  my_decimal decimal = {{0x5D20BE98, 0x0, 0x0, 0x0}};
  int check = 1562427032;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok410) {
  my_decimal decimal = {{0x118FF56, 0x0, 0x0, 0x0}};
  int check = 18415446;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok411) {
  my_decimal decimal = {{0x118FF56, 0x0, 0x0, 0x80000000}};
  int check = -18415446;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok412) {
  my_decimal decimal = {{0x79D1E655, 0x0, 0x0, 0x0}};
  int check = 2043799125;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok413) {
  my_decimal decimal = {{0x79D1E655, 0x0, 0x0, 0x80000000}};
  int check = -2043799125;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok414) {
  my_decimal decimal = {{0x29AB2385, 0x0, 0x0, 0x80000000}};
  int check = -699081605;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok415) {
  my_decimal decimal = {{0x29AB2385, 0x0, 0x0, 0x0}};
  int check = 699081605;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok416) {
  my_decimal decimal = {{0x2AF38E6C, 0x0, 0x0, 0x20000}};
  int check = 7206047;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok417) {
  my_decimal decimal = {{0x2AF38E6C, 0x0, 0x0, 0x80020000}};
  int check = -7206047;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok418) {
  my_decimal decimal = {{0xF167D90A, 0x0, 0x0, 0x80040000}};
  int check = -405011;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok419) {
  my_decimal decimal = {{0xF167D90A, 0x0, 0x0, 0x40000}};
  int check = 405011;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok420) {
  my_decimal decimal = {{0xACD5B600, 0x0, 0x0, 0x130000}};
  int check = 0;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok421) {
  my_decimal decimal = {{0xACD5B600, 0x0, 0x0, 0x80130000}};
  int check = 0;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok422) {
  my_decimal decimal = {{0x300E6CF1, 0x0, 0x0, 0x80000000}};
  int check = -806251761;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok423) {
  my_decimal decimal = {{0x300E6CF1, 0x0, 0x0, 0x0}};
  int check = 806251761;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok424) {
  my_decimal decimal = {{0x394E0855, 0x0, 0x0, 0x80000000}};
  int check = -961415253;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok425) {
  my_decimal decimal = {{0x394E0855, 0x0, 0x0, 0x0}};
  int check = 961415253;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok426) {
  my_decimal decimal = {{0x513ADEE4, 0x0, 0x0, 0x0}};
  int check = 1362812644;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok427) {
  my_decimal decimal = {{0x513ADEE4, 0x0, 0x0, 0x80000000}};
  int check = -1362812644;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok428) {
  my_decimal decimal = {{0x2C58D067, 0x0, 0x0, 0x0}};
  int check = 744018023;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok429) {
  my_decimal decimal = {{0x2C58D067, 0x0, 0x0, 0x80000000}};
  int check = -744018023;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok430) {
  my_decimal decimal = {{0x27E22E98, 0x0, 0x0, 0x80000000}};
  int check = -669134488;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok431) {
  my_decimal decimal = {{0x27E22E98, 0x0, 0x0, 0x0}};
  int check = 669134488;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok432) {
  my_decimal decimal = {{0x43B24203, 0x0, 0x0, 0x0}};
  int check = 1135755779;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok433) {
  my_decimal decimal = {{0x43B24203, 0x0, 0x0, 0x80000000}};
  int check = -1135755779;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok434) {
  my_decimal decimal = {{0x3F945BE4, 0x0, 0x0, 0x80000000}};
  int check = -1066687460;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok435) {
  my_decimal decimal = {{0x3F945BE4, 0x0, 0x0, 0x0}};
  int check = 1066687460;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok436) {
  my_decimal decimal = {{0x69CF69F7, 0x0, 0x0, 0x60000}};
  int check = 1775;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok437) {
  my_decimal decimal = {{0x69CF69F7, 0x0, 0x0, 0x80060000}};
  int check = -1775;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok438) {
  my_decimal decimal = {{0x7A27030F, 0x0, 0x0, 0x0}};
  int check = 2049377039;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok439) {
  my_decimal decimal = {{0x7A27030F, 0x0, 0x0, 0x80000000}};
  int check = -2049377039;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok440) {
  my_decimal decimal = {{0x26650DC8, 0x0, 0x0, 0x0}};
  int check = 644156872;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok441) {
  my_decimal decimal = {{0x26650DC8, 0x0, 0x0, 0x80000000}};
  int check = -644156872;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok442) {
  my_decimal decimal = {{0x188D1578, 0x0, 0x0, 0x0}};
  int check = 411899256;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok443) {
  my_decimal decimal = {{0x188D1578, 0x0, 0x0, 0x80000000}};
  int check = -411899256;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok444) {
  my_decimal decimal = {{0x1322BEF9, 0x0, 0x0, 0x80190000}};
  int check = 0;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok445) {
  my_decimal decimal = {{0x1322BEF9, 0x0, 0x0, 0x190000}};
  int check = 0;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok446) {
  my_decimal decimal = {{0xE30E36BC, 0x0, 0x0, 0x1B0000}};
  int check = 0;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok447) {
  my_decimal decimal = {{0xE30E36BC, 0x0, 0x0, 0x801B0000}};
  int check = 0;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok448) {
  my_decimal decimal = {{0xA751A0D7, 0x0, 0x0, 0x80150000}};
  int check = 0;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok449) {
  my_decimal decimal = {{0xA751A0D7, 0x0, 0x0, 0x150000}};
  int check = 0;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok450) {
  my_decimal decimal = {{0x6B71AD2C, 0x0, 0x0, 0x0}};
  int check = 1802612012;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok451) {
  my_decimal decimal = {{0x6B71AD2C, 0x0, 0x0, 0x80000000}};
  int check = -1802612012;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok452) {
  my_decimal decimal = {{0x59513D08, 0x0, 0x0, 0x0}};
  int check = 1498496264;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok453) {
  my_decimal decimal = {{0x59513D08, 0x0, 0x0, 0x80000000}};
  int check = -1498496264;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok454) {
  my_decimal decimal = {{0x3F314C6A, 0x0, 0x0, 0x120000}};
  int check = 0;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok455) {
  my_decimal decimal = {{0x3F314C6A, 0x0, 0x0, 0x80120000}};
  int check = 0;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok456) {
  my_decimal decimal = {{0xCE782725, 0x0, 0x0, 0x80070000}};
  int check = -346;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok457) {
  my_decimal decimal = {{0xCE782725, 0x0, 0x0, 0x70000}};
  int check = 346;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok458) {
  my_decimal decimal = {{0x2F29FE9B, 0x0, 0x0, 0x801C0000}};
  int check = 0;

  test_from_decimal_to_int(decimal, check);
}

START_TEST(test_from_decimal_to_int_ok459) {
  my_decimal decimal = {{0x2F29FE9B, 0x0, 0x0, 0x1C0000}};
  int check = 0;

  test_from_decimal_to_int(decimal, check);
}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * * * * * * * * * * * * * * Tests for incorrect data (auto)
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * * * * * * * * * * * * * */

START_TEST(test_from_decimal_to_int_fail1) {
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};

  test_from_decimal_to_int_fail(decimal);
}

START_TEST(test_from_decimal_to_int_fail2) {
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};

  test_from_decimal_to_int_fail(decimal);
}

START_TEST(test_from_decimal_to_int_fail3) {
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};

  test_from_decimal_to_int_fail(decimal);
}

START_TEST(test_from_decimal_to_int_fail4) {
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80010000}};

  test_from_decimal_to_int_fail(decimal);
}

START_TEST(test_from_decimal_to_int_fail5) {
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x20000}};

  test_from_decimal_to_int_fail(decimal);
}

START_TEST(test_from_decimal_to_int_fail6) {
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80020000}};

  test_from_decimal_to_int_fail(decimal);
}

START_TEST(test_from_decimal_to_int_fail7) {
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x30000}};

  test_from_decimal_to_int_fail(decimal);
}

START_TEST(test_from_decimal_to_int_fail8) {
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80030000}};

  test_from_decimal_to_int_fail(decimal);
}

START_TEST(test_from_decimal_to_int_fail9) {
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x40000}};

  test_from_decimal_to_int_fail(decimal);
}

START_TEST(test_from_decimal_to_int_fail10) {
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80040000}};

  test_from_decimal_to_int_fail(decimal);
}

START_TEST(test_from_decimal_to_int_fail11) {
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x50000}};

  test_from_decimal_to_int_fail(decimal);
}

START_TEST(test_from_decimal_to_int_fail12) {
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80050000}};

  test_from_decimal_to_int_fail(decimal);
}

START_TEST(test_from_decimal_to_int_fail13) {
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x60000}};

  test_from_decimal_to_int_fail(decimal);
}

START_TEST(test_from_decimal_to_int_fail14) {
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80060000}};

  test_from_decimal_to_int_fail(decimal);
}

START_TEST(test_from_decimal_to_int_fail15) {
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x70000}};

  test_from_decimal_to_int_fail(decimal);
}

START_TEST(test_from_decimal_to_int_fail16) {
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80070000}};

  test_from_decimal_to_int_fail(decimal);
}

START_TEST(test_from_decimal_to_int_fail17) {
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000}};

  test_from_decimal_to_int_fail(decimal);
}

START_TEST(test_from_decimal_to_int_fail18) {
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80080000}};

  test_from_decimal_to_int_fail(decimal);
}

START_TEST(test_from_decimal_to_int_fail19) {
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x90000}};

  test_from_decimal_to_int_fail(decimal);
}

START_TEST(test_from_decimal_to_int_fail20) {
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80090000}};

  test_from_decimal_to_int_fail(decimal);
}

START_TEST(test_from_decimal_to_int_fail21) {
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xA0000}};

  test_from_decimal_to_int_fail(decimal);
}

START_TEST(test_from_decimal_to_int_fail22) {
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x800A0000}};

  test_from_decimal_to_int_fail(decimal);
}

START_TEST(test_from_decimal_to_int_fail23) {
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xB0000}};

  test_from_decimal_to_int_fail(decimal);
}

START_TEST(test_from_decimal_to_int_fail24) {
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x800B0000}};

  test_from_decimal_to_int_fail(decimal);
}

START_TEST(test_from_decimal_to_int_fail25) {
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xC0000}};

  test_from_decimal_to_int_fail(decimal);
}

START_TEST(test_from_decimal_to_int_fail26) {
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x800C0000}};

  test_from_decimal_to_int_fail(decimal);
}

START_TEST(test_from_decimal_to_int_fail27) {
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xD0000}};

  test_from_decimal_to_int_fail(decimal);
}

START_TEST(test_from_decimal_to_int_fail28) {
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x800D0000}};

  test_from_decimal_to_int_fail(decimal);
}

START_TEST(test_from_decimal_to_int_fail29) {
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xE0000}};

  test_from_decimal_to_int_fail(decimal);
}

START_TEST(test_from_decimal_to_int_fail30) {
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x800E0000}};

  test_from_decimal_to_int_fail(decimal);
}

START_TEST(test_from_decimal_to_int_fail31) {
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xF0000}};

  test_from_decimal_to_int_fail(decimal);
}

START_TEST(test_from_decimal_to_int_fail32) {
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x800F0000}};

  test_from_decimal_to_int_fail(decimal);
}

START_TEST(test_from_decimal_to_int_fail33) {
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x100000}};

  test_from_decimal_to_int_fail(decimal);
}

START_TEST(test_from_decimal_to_int_fail34) {
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80100000}};

  test_from_decimal_to_int_fail(decimal);
}

START_TEST(test_from_decimal_to_int_fail35) {
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x110000}};

  test_from_decimal_to_int_fail(decimal);
}

START_TEST(test_from_decimal_to_int_fail36) {
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80110000}};

  test_from_decimal_to_int_fail(decimal);
}

START_TEST(test_from_decimal_to_int_fail37) {
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x120000}};

  test_from_decimal_to_int_fail(decimal);
}

START_TEST(test_from_decimal_to_int_fail38) {
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80120000}};

  test_from_decimal_to_int_fail(decimal);
}

START_TEST(test_from_decimal_to_int_fail39) {
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x130000}};

  test_from_decimal_to_int_fail(decimal);
}

START_TEST(test_from_decimal_to_int_fail40) {
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80130000}};

  test_from_decimal_to_int_fail(decimal);
}

START_TEST(test_from_decimal_to_int_fail41) {
  my_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};

  test_from_decimal_to_int_fail(decimal);
}

START_TEST(test_from_decimal_to_int_fail42) {
  my_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};

  test_from_decimal_to_int_fail(decimal);
}

START_TEST(test_from_decimal_to_int_fail43) {
  my_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};

  test_from_decimal_to_int_fail(decimal);
}

START_TEST(test_from_decimal_to_int_fail44) {
  my_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80010000}};

  test_from_decimal_to_int_fail(decimal);
}

START_TEST(test_from_decimal_to_int_fail45) {
  my_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x20000}};

  test_from_decimal_to_int_fail(decimal);
}

START_TEST(test_from_decimal_to_int_fail46) {
  my_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80020000}};

  test_from_decimal_to_int_fail(decimal);
}

START_TEST(test_from_decimal_to_int_fail47) {
  my_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x30000}};

  test_from_decimal_to_int_fail(decimal);
}

START_TEST(test_from_decimal_to_int_fail48) {
  my_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80030000}};

  test_from_decimal_to_int_fail(decimal);
}

START_TEST(test_from_decimal_to_int_fail49) {
  my_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x40000}};

  test_from_decimal_to_int_fail(decimal);
}

START_TEST(test_from_decimal_to_int_fail50) {
  my_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80040000}};

  test_from_decimal_to_int_fail(decimal);
}

START_TEST(test_from_decimal_to_int_fail51) {
  my_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x50000}};

  test_from_decimal_to_int_fail(decimal);
}

START_TEST(test_from_decimal_to_int_fail52) {
  my_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80050000}};

  test_from_decimal_to_int_fail(decimal);
}

START_TEST(test_from_decimal_to_int_fail53) {
  my_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x60000}};

  test_from_decimal_to_int_fail(decimal);
}

START_TEST(test_from_decimal_to_int_fail54) {
  my_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80060000}};

  test_from_decimal_to_int_fail(decimal);
}

START_TEST(test_from_decimal_to_int_fail55) {
  my_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x70000}};

  test_from_decimal_to_int_fail(decimal);
}

START_TEST(test_from_decimal_to_int_fail56) {
  my_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80070000}};

  test_from_decimal_to_int_fail(decimal);
}

START_TEST(test_from_decimal_to_int_fail57) {
  my_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000}};

  test_from_decimal_to_int_fail(decimal);
}

START_TEST(test_from_decimal_to_int_fail58) {
  my_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80080000}};

  test_from_decimal_to_int_fail(decimal);
}

START_TEST(test_from_decimal_to_int_fail59) {
  my_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x90000}};

  test_from_decimal_to_int_fail(decimal);
}

START_TEST(test_from_decimal_to_int_fail60) {
  my_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80090000}};

  test_from_decimal_to_int_fail(decimal);
}

START_TEST(test_from_decimal_to_int_fail61) {
  my_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0xA0000}};

  test_from_decimal_to_int_fail(decimal);
}

START_TEST(test_from_decimal_to_int_fail62) {
  my_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x800A0000}};

  test_from_decimal_to_int_fail(decimal);
}

START_TEST(test_from_decimal_to_int_fail63) {
  my_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0xB0000}};

  test_from_decimal_to_int_fail(decimal);
}

START_TEST(test_from_decimal_to_int_fail64) {
  my_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x800B0000}};

  test_from_decimal_to_int_fail(decimal);
}

START_TEST(test_from_decimal_to_int_fail65) {
  my_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0xC0000}};

  test_from_decimal_to_int_fail(decimal);
}

START_TEST(test_from_decimal_to_int_fail66) {
  my_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x800C0000}};

  test_from_decimal_to_int_fail(decimal);
}

START_TEST(test_from_decimal_to_int_fail67) {
  my_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0xD0000}};

  test_from_decimal_to_int_fail(decimal);
}

START_TEST(test_from_decimal_to_int_fail68) {
  my_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x800D0000}};

  test_from_decimal_to_int_fail(decimal);
}

START_TEST(test_from_decimal_to_int_fail69) {
  my_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0xE0000}};

  test_from_decimal_to_int_fail(decimal);
}

START_TEST(test_from_decimal_to_int_fail70) {
  my_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x800E0000}};

  test_from_decimal_to_int_fail(decimal);
}

START_TEST(test_from_decimal_to_int_fail71) {
  my_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0xF0000}};

  test_from_decimal_to_int_fail(decimal);
}

START_TEST(test_from_decimal_to_int_fail72) {
  my_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x800F0000}};

  test_from_decimal_to_int_fail(decimal);
}

START_TEST(test_from_decimal_to_int_fail73) {
  my_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x100000}};

  test_from_decimal_to_int_fail(decimal);
}

START_TEST(test_from_decimal_to_int_fail74) {
  my_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80100000}};

  test_from_decimal_to_int_fail(decimal);
}

START_TEST(test_from_decimal_to_int_fail75) {
  my_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x110000}};

  test_from_decimal_to_int_fail(decimal);
}

START_TEST(test_from_decimal_to_int_fail76) {
  my_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80110000}};

  test_from_decimal_to_int_fail(decimal);
}

START_TEST(test_from_decimal_to_int_fail77) {
  my_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x120000}};

  test_from_decimal_to_int_fail(decimal);
}

START_TEST(test_from_decimal_to_int_fail78) {
  my_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80120000}};

  test_from_decimal_to_int_fail(decimal);
}

START_TEST(test_from_decimal_to_int_fail79) {
  my_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x130000}};

  test_from_decimal_to_int_fail(decimal);
}

START_TEST(test_from_decimal_to_int_fail80) {
  my_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80130000}};

  test_from_decimal_to_int_fail(decimal);
}

START_TEST(test_from_decimal_to_int_fail81) {
  my_decimal decimal = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x0}};

  test_from_decimal_to_int_fail(decimal);
}

START_TEST(test_from_decimal_to_int_fail82) {
  my_decimal decimal = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x80000000}};

  test_from_decimal_to_int_fail(decimal);
}

START_TEST(test_from_decimal_to_int_fail83) {
  my_decimal decimal = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x10000}};

  test_from_decimal_to_int_fail(decimal);
}

START_TEST(test_from_decimal_to_int_fail84) {
  my_decimal decimal = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x80010000}};

  test_from_decimal_to_int_fail(decimal);
}

START_TEST(test_from_decimal_to_int_fail85) {
  my_decimal decimal = {{0x0, 0xAAAAAAAA, 0xAAAAAAAA, 0x0}};

  test_from_decimal_to_int_fail(decimal);
}

START_TEST(test_from_decimal_to_int_fail86) {
  my_decimal decimal = {{0x0, 0xAAAAAAAA, 0xAAAAAAAA, 0x80000000}};

  test_from_decimal_to_int_fail(decimal);
}

START_TEST(test_from_decimal_to_int_fail87) {
  my_decimal decimal = {{0x0, 0xAAAAAAAA, 0xAAAAAAAA, 0x10000}};

  test_from_decimal_to_int_fail(decimal);
}

START_TEST(test_from_decimal_to_int_fail88) {
  my_decimal decimal = {{0x0, 0xAAAAAAAA, 0xAAAAAAAA, 0x80010000}};

  test_from_decimal_to_int_fail(decimal);
}

START_TEST(test_from_decimal_to_int_fail89) {
  my_decimal decimal = {{0xAAAAAAAA, 0x0, 0xAAAAAAAA, 0x0}};

  test_from_decimal_to_int_fail(decimal);
}

START_TEST(test_from_decimal_to_int_fail90) {
  my_decimal decimal = {{0xAAAAAAAA, 0x0, 0xAAAAAAAA, 0x80000000}};

  test_from_decimal_to_int_fail(decimal);
}

START_TEST(test_from_decimal_to_int_fail91) {
  my_decimal decimal = {{0xAAAAAAAA, 0x0, 0xAAAAAAAA, 0x10000}};

  test_from_decimal_to_int_fail(decimal);
}

START_TEST(test_from_decimal_to_int_fail92) {
  my_decimal decimal = {{0xAAAAAAAA, 0x0, 0xAAAAAAAA, 0x80010000}};

  test_from_decimal_to_int_fail(decimal);
}

START_TEST(test_from_decimal_to_int_fail93) {
  my_decimal decimal = {{0x0, 0x0, 0xAAAAAAAA, 0x0}};

  test_from_decimal_to_int_fail(decimal);
}

START_TEST(test_from_decimal_to_int_fail94) {
  my_decimal decimal = {{0x0, 0x0, 0xAAAAAAAA, 0x80000000}};

  test_from_decimal_to_int_fail(decimal);
}

START_TEST(test_from_decimal_to_int_fail95) {
  my_decimal decimal = {{0x0, 0x0, 0xAAAAAAAA, 0x10000}};

  test_from_decimal_to_int_fail(decimal);
}

START_TEST(test_from_decimal_to_int_fail96) {
  my_decimal decimal = {{0x0, 0x0, 0xAAAAAAAA, 0x80010000}};

  test_from_decimal_to_int_fail(decimal);
}

START_TEST(test_from_decimal_to_int_fail97) {
  my_decimal decimal = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x0}};

  test_from_decimal_to_int_fail(decimal);
}

START_TEST(test_from_decimal_to_int_fail98) {
  my_decimal decimal = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x80000000}};

  test_from_decimal_to_int_fail(decimal);
}

START_TEST(test_from_decimal_to_int_fail99) {
  my_decimal decimal = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x10000}};

  test_from_decimal_to_int_fail(decimal);
}

START_TEST(test_from_decimal_to_int_fail100) {
  my_decimal decimal = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x80010000}};

  test_from_decimal_to_int_fail(decimal);
}

START_TEST(test_from_decimal_to_int_fail101) {
  my_decimal decimal = {{0x0, 0xAAAAAAAA, 0x0, 0x0}};

  test_from_decimal_to_int_fail(decimal);
}

START_TEST(test_from_decimal_to_int_fail102) {
  my_decimal decimal = {{0x0, 0xAAAAAAAA, 0x0, 0x80000000}};

  test_from_decimal_to_int_fail(decimal);
}

START_TEST(test_from_decimal_to_int_fail103) {
  my_decimal decimal = {{0x0, 0xAAAAAAAA, 0x0, 0x10000}};

  test_from_decimal_to_int_fail(decimal);
}

START_TEST(test_from_decimal_to_int_fail104) {
  my_decimal decimal = {{0x0, 0xAAAAAAAA, 0x0, 0x80010000}};

  test_from_decimal_to_int_fail(decimal);
}

START_TEST(test_from_decimal_to_int_fail105) {
  my_decimal decimal = {{0xAAAAAAAA, 0x0, 0x0, 0x0}};

  test_from_decimal_to_int_fail(decimal);
}

START_TEST(test_from_decimal_to_int_fail106) {
  my_decimal decimal = {{0xAAAAAAAA, 0x0, 0x0, 0x80000000}};

  test_from_decimal_to_int_fail(decimal);
}

START_TEST(test_from_decimal_to_int_fail107) {
  my_decimal decimal = {{0x55555555, 0x55555555, 0x55555555, 0x0}};

  test_from_decimal_to_int_fail(decimal);
}

START_TEST(test_from_decimal_to_int_fail108) {
  my_decimal decimal = {{0x55555555, 0x55555555, 0x55555555, 0x80000000}};

  test_from_decimal_to_int_fail(decimal);
}

START_TEST(test_from_decimal_to_int_fail109) {
  my_decimal decimal = {{0x55555555, 0x55555555, 0x55555555, 0x10000}};

  test_from_decimal_to_int_fail(decimal);
}

START_TEST(test_from_decimal_to_int_fail110) {
  my_decimal decimal = {{0x55555555, 0x55555555, 0x55555555, 0x80010000}};

  test_from_decimal_to_int_fail(decimal);
}

START_TEST(test_from_decimal_to_int_fail111) {
  my_decimal decimal = {{0x0, 0x55555555, 0x55555555, 0x0}};

  test_from_decimal_to_int_fail(decimal);
}

START_TEST(test_from_decimal_to_int_fail112) {
  my_decimal decimal = {{0x0, 0x55555555, 0x55555555, 0x80000000}};

  test_from_decimal_to_int_fail(decimal);
}

START_TEST(test_from_decimal_to_int_fail113) {
  my_decimal decimal = {{0x0, 0x55555555, 0x55555555, 0x10000}};

  test_from_decimal_to_int_fail(decimal);
}

START_TEST(test_from_decimal_to_int_fail114) {
  my_decimal decimal = {{0x0, 0x55555555, 0x55555555, 0x80010000}};

  test_from_decimal_to_int_fail(decimal);
}

START_TEST(test_from_decimal_to_int_fail115) {
  my_decimal decimal = {{0x55555555, 0x0, 0x55555555, 0x0}};

  test_from_decimal_to_int_fail(decimal);
}

START_TEST(test_from_decimal_to_int_fail116) {
  my_decimal decimal = {{0x55555555, 0x0, 0x55555555, 0x80000000}};

  test_from_decimal_to_int_fail(decimal);
}

START_TEST(test_from_decimal_to_int_fail117) {
  my_decimal decimal = {{0x55555555, 0x0, 0x55555555, 0x10000}};

  test_from_decimal_to_int_fail(decimal);
}

START_TEST(test_from_decimal_to_int_fail118) {
  my_decimal decimal = {{0x55555555, 0x0, 0x55555555, 0x80010000}};

  test_from_decimal_to_int_fail(decimal);
}

START_TEST(test_from_decimal_to_int_fail119) {
  my_decimal decimal = {{0x0, 0x0, 0x55555555, 0x0}};

  test_from_decimal_to_int_fail(decimal);
}

START_TEST(test_from_decimal_to_int_fail120) {
  my_decimal decimal = {{0x0, 0x0, 0x55555555, 0x80000000}};

  test_from_decimal_to_int_fail(decimal);
}

START_TEST(test_from_decimal_to_int_fail121) {
  my_decimal decimal = {{0x0, 0x0, 0x55555555, 0x10000}};

  test_from_decimal_to_int_fail(decimal);
}

START_TEST(test_from_decimal_to_int_fail122) {
  my_decimal decimal = {{0x0, 0x0, 0x55555555, 0x80010000}};

  test_from_decimal_to_int_fail(decimal);
}

START_TEST(test_from_decimal_to_int_fail123) {
  my_decimal decimal = {{0x55555555, 0x55555555, 0x0, 0x0}};

  test_from_decimal_to_int_fail(decimal);
}

START_TEST(test_from_decimal_to_int_fail124) {
  my_decimal decimal = {{0x55555555, 0x55555555, 0x0, 0x80000000}};

  test_from_decimal_to_int_fail(decimal);
}

START_TEST(test_from_decimal_to_int_fail125) {
  my_decimal decimal = {{0x55555555, 0x55555555, 0x0, 0x10000}};

  test_from_decimal_to_int_fail(decimal);
}

START_TEST(test_from_decimal_to_int_fail126) {
  my_decimal decimal = {{0x55555555, 0x55555555, 0x0, 0x80010000}};

  test_from_decimal_to_int_fail(decimal);
}

START_TEST(test_from_decimal_to_int_fail127) {
  my_decimal decimal = {{0x0, 0x55555555, 0x0, 0x0}};

  test_from_decimal_to_int_fail(decimal);
}

START_TEST(test_from_decimal_to_int_fail128) {
  my_decimal decimal = {{0x0, 0x55555555, 0x0, 0x80000000}};

  test_from_decimal_to_int_fail(decimal);
}

START_TEST(test_from_decimal_to_int_fail129) {
  my_decimal decimal = {{0x0, 0x55555555, 0x0, 0x10000}};

  test_from_decimal_to_int_fail(decimal);
}

START_TEST(test_from_decimal_to_int_fail130) {
  my_decimal decimal = {{0x0, 0x55555555, 0x0, 0x80010000}};

  test_from_decimal_to_int_fail(decimal);
}

START_TEST(test_from_decimal_to_int_fail131) {
  my_decimal decimal = {{0x1, 0x1, 0x1, 0x0}};

  test_from_decimal_to_int_fail(decimal);
}

START_TEST(test_from_decimal_to_int_fail132) {
  my_decimal decimal = {{0x1, 0x1, 0x1, 0x80000000}};

  test_from_decimal_to_int_fail(decimal);
}

START_TEST(test_from_decimal_to_int_fail133) {
  my_decimal decimal = {{0x1, 0x1, 0x1, 0x10000}};

  test_from_decimal_to_int_fail(decimal);
}

START_TEST(test_from_decimal_to_int_fail134) {
  my_decimal decimal = {{0x1, 0x1, 0x1, 0x80010000}};

  test_from_decimal_to_int_fail(decimal);
}

START_TEST(test_from_decimal_to_int_fail135) {
  my_decimal decimal = {{0x0, 0x1, 0x1, 0x0}};

  test_from_decimal_to_int_fail(decimal);
}

START_TEST(test_from_decimal_to_int_fail136) {
  my_decimal decimal = {{0x0, 0x1, 0x1, 0x80000000}};

  test_from_decimal_to_int_fail(decimal);
}

START_TEST(test_from_decimal_to_int_fail137) {
  my_decimal decimal = {{0x0, 0x1, 0x1, 0x10000}};

  test_from_decimal_to_int_fail(decimal);
}

START_TEST(test_from_decimal_to_int_fail138) {
  my_decimal decimal = {{0x0, 0x1, 0x1, 0x80010000}};

  test_from_decimal_to_int_fail(decimal);
}

START_TEST(test_from_decimal_to_int_fail139) {
  my_decimal decimal = {{0x1, 0x0, 0x1, 0x0}};

  test_from_decimal_to_int_fail(decimal);
}

START_TEST(test_from_decimal_to_int_fail140) {
  my_decimal decimal = {{0x1, 0x0, 0x1, 0x80000000}};

  test_from_decimal_to_int_fail(decimal);
}

START_TEST(test_from_decimal_to_int_fail141) {
  my_decimal decimal = {{0x1, 0x0, 0x1, 0x10000}};

  test_from_decimal_to_int_fail(decimal);
}

START_TEST(test_from_decimal_to_int_fail142) {
  my_decimal decimal = {{0x1, 0x0, 0x1, 0x80010000}};

  test_from_decimal_to_int_fail(decimal);
}

START_TEST(test_from_decimal_to_int_fail143) {
  my_decimal decimal = {{0x0, 0x0, 0x1, 0x0}};

  test_from_decimal_to_int_fail(decimal);
}

START_TEST(test_from_decimal_to_int_fail144) {
  my_decimal decimal = {{0x0, 0x0, 0x1, 0x80000000}};

  test_from_decimal_to_int_fail(decimal);
}

START_TEST(test_from_decimal_to_int_fail145) {
  my_decimal decimal = {{0x0, 0x0, 0x1, 0x10000}};

  test_from_decimal_to_int_fail(decimal);
}

START_TEST(test_from_decimal_to_int_fail146) {
  my_decimal decimal = {{0x0, 0x0, 0x1, 0x80010000}};

  test_from_decimal_to_int_fail(decimal);
}

START_TEST(test_from_decimal_to_int_fail147) {
  my_decimal decimal = {{0x1, 0x1, 0x0, 0x0}};

  test_from_decimal_to_int_fail(decimal);
}

START_TEST(test_from_decimal_to_int_fail148) {
  my_decimal decimal = {{0x1, 0x1, 0x0, 0x80000000}};

  test_from_decimal_to_int_fail(decimal);
}

START_TEST(test_from_decimal_to_int_fail149) {
  my_decimal decimal = {{0x0, 0x1, 0x0, 0x0}};

  test_from_decimal_to_int_fail(decimal);
}

START_TEST(test_from_decimal_to_int_fail150) {
  my_decimal decimal = {{0x0, 0x1, 0x0, 0x80000000}};

  test_from_decimal_to_int_fail(decimal);
}

START_TEST(test_from_decimal_to_int_fail151) {
  my_decimal decimal = {{0x80000000, 0x80000000, 0x80000000, 0x0}};

  test_from_decimal_to_int_fail(decimal);
}

START_TEST(test_from_decimal_to_int_fail152) {
  my_decimal decimal = {{0x80000000, 0x80000000, 0x80000000, 0x80000000}};

  test_from_decimal_to_int_fail(decimal);
}

START_TEST(test_from_decimal_to_int_fail153) {
  my_decimal decimal = {{0x80000000, 0x80000000, 0x80000000, 0x10000}};

  test_from_decimal_to_int_fail(decimal);
}

START_TEST(test_from_decimal_to_int_fail154) {
  my_decimal decimal = {{0x80000000, 0x80000000, 0x80000000, 0x80010000}};

  test_from_decimal_to_int_fail(decimal);
}

START_TEST(test_from_decimal_to_int_fail155) {
  my_decimal decimal = {{0x0, 0x80000000, 0x80000000, 0x0}};

  test_from_decimal_to_int_fail(decimal);
}

START_TEST(test_from_decimal_to_int_fail156) {
  my_decimal decimal = {{0x0, 0x80000000, 0x80000000, 0x80000000}};

  test_from_decimal_to_int_fail(decimal);
}

START_TEST(test_from_decimal_to_int_fail157) {
  my_decimal decimal = {{0x0, 0x80000000, 0x80000000, 0x10000}};

  test_from_decimal_to_int_fail(decimal);
}

START_TEST(test_from_decimal_to_int_fail158) {
  my_decimal decimal = {{0x0, 0x80000000, 0x80000000, 0x80010000}};

  test_from_decimal_to_int_fail(decimal);
}

START_TEST(test_from_decimal_to_int_fail159) {
  my_decimal decimal = {{0x80000000, 0x0, 0x80000000, 0x0}};

  test_from_decimal_to_int_fail(decimal);
}

START_TEST(test_from_decimal_to_int_fail160) {
  my_decimal decimal = {{0x80000000, 0x0, 0x80000000, 0x80000000}};

  test_from_decimal_to_int_fail(decimal);
}

START_TEST(test_from_decimal_to_int_fail161) {
  my_decimal decimal = {{0x80000000, 0x0, 0x80000000, 0x10000}};

  test_from_decimal_to_int_fail(decimal);
}

START_TEST(test_from_decimal_to_int_fail162) {
  my_decimal decimal = {{0x80000000, 0x0, 0x80000000, 0x80010000}};

  test_from_decimal_to_int_fail(decimal);
}

START_TEST(test_from_decimal_to_int_fail163) {
  my_decimal decimal = {{0x0, 0x0, 0x80000000, 0x0}};

  test_from_decimal_to_int_fail(decimal);
}

START_TEST(test_from_decimal_to_int_fail164) {
  my_decimal decimal = {{0x0, 0x0, 0x80000000, 0x80000000}};

  test_from_decimal_to_int_fail(decimal);
}

START_TEST(test_from_decimal_to_int_fail165) {
  my_decimal decimal = {{0x0, 0x0, 0x80000000, 0x10000}};

  test_from_decimal_to_int_fail(decimal);
}

START_TEST(test_from_decimal_to_int_fail166) {
  my_decimal decimal = {{0x0, 0x0, 0x80000000, 0x80010000}};

  test_from_decimal_to_int_fail(decimal);
}

START_TEST(test_from_decimal_to_int_fail167) {
  my_decimal decimal = {{0x80000000, 0x80000000, 0x0, 0x0}};

  test_from_decimal_to_int_fail(decimal);
}

START_TEST(test_from_decimal_to_int_fail168) {
  my_decimal decimal = {{0x80000000, 0x80000000, 0x0, 0x80000000}};

  test_from_decimal_to_int_fail(decimal);
}

START_TEST(test_from_decimal_to_int_fail169) {
  my_decimal decimal = {{0x80000000, 0x80000000, 0x0, 0x10000}};

  test_from_decimal_to_int_fail(decimal);
}

START_TEST(test_from_decimal_to_int_fail170) {
  my_decimal decimal = {{0x80000000, 0x80000000, 0x0, 0x80010000}};

  test_from_decimal_to_int_fail(decimal);
}

START_TEST(test_from_decimal_to_int_fail171) {
  my_decimal decimal = {{0x0, 0x80000000, 0x0, 0x0}};

  test_from_decimal_to_int_fail(decimal);
}

START_TEST(test_from_decimal_to_int_fail172) {
  my_decimal decimal = {{0x0, 0x80000000, 0x0, 0x80000000}};

  test_from_decimal_to_int_fail(decimal);
}

START_TEST(test_from_decimal_to_int_fail173) {
  my_decimal decimal = {{0x0, 0x80000000, 0x0, 0x10000}};

  test_from_decimal_to_int_fail(decimal);
}

START_TEST(test_from_decimal_to_int_fail174) {
  my_decimal decimal = {{0x0, 0x80000000, 0x0, 0x80010000}};

  test_from_decimal_to_int_fail(decimal);
}

START_TEST(test_from_decimal_to_int_fail175) {
  my_decimal decimal = {{0x80000000, 0x0, 0x0, 0x0}};

  test_from_decimal_to_int_fail(decimal);
}

START_TEST(test_from_decimal_to_int_fail176) {
  my_decimal decimal = {{0x811800, 0x811800, 0x811800, 0x0}};

  test_from_decimal_to_int_fail(decimal);
}

START_TEST(test_from_decimal_to_int_fail177) {
  my_decimal decimal = {{0x811800, 0x811800, 0x811800, 0x80000000}};

  test_from_decimal_to_int_fail(decimal);
}

START_TEST(test_from_decimal_to_int_fail178) {
  my_decimal decimal = {{0x811800, 0x811800, 0x811800, 0x10000}};

  test_from_decimal_to_int_fail(decimal);
}

START_TEST(test_from_decimal_to_int_fail179) {
  my_decimal decimal = {{0x811800, 0x811800, 0x811800, 0x80010000}};

  test_from_decimal_to_int_fail(decimal);
}

START_TEST(test_from_decimal_to_int_fail180) {
  my_decimal decimal = {{0x0, 0x811800, 0x811800, 0x0}};

  test_from_decimal_to_int_fail(decimal);
}

START_TEST(test_from_decimal_to_int_fail181) {
  my_decimal decimal = {{0x0, 0x811800, 0x811800, 0x80000000}};

  test_from_decimal_to_int_fail(decimal);
}

START_TEST(test_from_decimal_to_int_fail182) {
  my_decimal decimal = {{0x0, 0x811800, 0x811800, 0x10000}};

  test_from_decimal_to_int_fail(decimal);
}

START_TEST(test_from_decimal_to_int_fail183) {
  my_decimal decimal = {{0x0, 0x811800, 0x811800, 0x80010000}};

  test_from_decimal_to_int_fail(decimal);
}

START_TEST(test_from_decimal_to_int_fail184) {
  my_decimal decimal = {{0x811800, 0x0, 0x811800, 0x0}};

  test_from_decimal_to_int_fail(decimal);
}

START_TEST(test_from_decimal_to_int_fail185) {
  my_decimal decimal = {{0x811800, 0x0, 0x811800, 0x80000000}};

  test_from_decimal_to_int_fail(decimal);
}

START_TEST(test_from_decimal_to_int_fail186) {
  my_decimal decimal = {{0x811800, 0x0, 0x811800, 0x10000}};

  test_from_decimal_to_int_fail(decimal);
}

START_TEST(test_from_decimal_to_int_fail187) {
  my_decimal decimal = {{0x811800, 0x0, 0x811800, 0x80010000}};

  test_from_decimal_to_int_fail(decimal);
}

START_TEST(test_from_decimal_to_int_fail188) {
  my_decimal decimal = {{0x0, 0x0, 0x811800, 0x0}};

  test_from_decimal_to_int_fail(decimal);
}

START_TEST(test_from_decimal_to_int_fail189) {
  my_decimal decimal = {{0x0, 0x0, 0x811800, 0x80000000}};

  test_from_decimal_to_int_fail(decimal);
}

START_TEST(test_from_decimal_to_int_fail190) {
  my_decimal decimal = {{0x0, 0x0, 0x811800, 0x10000}};

  test_from_decimal_to_int_fail(decimal);
}

START_TEST(test_from_decimal_to_int_fail191) {
  my_decimal decimal = {{0x0, 0x0, 0x811800, 0x80010000}};

  test_from_decimal_to_int_fail(decimal);
}

START_TEST(test_from_decimal_to_int_fail192) {
  my_decimal decimal = {{0x811800, 0x811800, 0x0, 0x0}};

  test_from_decimal_to_int_fail(decimal);
}

START_TEST(test_from_decimal_to_int_fail193) {
  my_decimal decimal = {{0x811800, 0x811800, 0x0, 0x80000000}};

  test_from_decimal_to_int_fail(decimal);
}

START_TEST(test_from_decimal_to_int_fail194) {
  my_decimal decimal = {{0x811800, 0x811800, 0x0, 0x10000}};

  test_from_decimal_to_int_fail(decimal);
}

START_TEST(test_from_decimal_to_int_fail195) {
  my_decimal decimal = {{0x811800, 0x811800, 0x0, 0x80010000}};

  test_from_decimal_to_int_fail(decimal);
}

START_TEST(test_from_decimal_to_int_fail196) {
  my_decimal decimal = {{0x0, 0x811800, 0x0, 0x0}};

  test_from_decimal_to_int_fail(decimal);
}

START_TEST(test_from_decimal_to_int_fail197) {
  my_decimal decimal = {{0x0, 0x811800, 0x0, 0x80000000}};

  test_from_decimal_to_int_fail(decimal);
}

START_TEST(test_from_decimal_to_int_fail198) {
  my_decimal decimal = {{0x0, 0x811800, 0x0, 0x10000}};

  test_from_decimal_to_int_fail(decimal);
}

START_TEST(test_from_decimal_to_int_fail199) {
  my_decimal decimal = {{0x0, 0x811800, 0x0, 0x80010000}};

  test_from_decimal_to_int_fail(decimal);
}

START_TEST(test_from_decimal_to_int_fail200) {
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};

  test_from_decimal_to_int_fail(decimal);
}

START_TEST(test_from_decimal_to_int_fail201) {
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};

  test_from_decimal_to_int_fail(decimal);
}

START_TEST(test_from_decimal_to_int_fail202) {
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};

  test_from_decimal_to_int_fail(decimal);
}

START_TEST(test_from_decimal_to_int_fail203) {
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80010000}};

  test_from_decimal_to_int_fail(decimal);
}

START_TEST(test_from_decimal_to_int_fail204) {
  my_decimal decimal = {{0x0, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};

  test_from_decimal_to_int_fail(decimal);
}

START_TEST(test_from_decimal_to_int_fail205) {
  my_decimal decimal = {{0x0, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};

  test_from_decimal_to_int_fail(decimal);
}

START_TEST(test_from_decimal_to_int_fail206) {
  my_decimal decimal = {{0x0, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};

  test_from_decimal_to_int_fail(decimal);
}

START_TEST(test_from_decimal_to_int_fail207) {
  my_decimal decimal = {{0x0, 0xFFFFFFFF, 0xFFFFFFFF, 0x80010000}};

  test_from_decimal_to_int_fail(decimal);
}

START_TEST(test_from_decimal_to_int_fail208) {
  my_decimal decimal = {{0xFFFFFFFF, 0x0, 0xFFFFFFFF, 0x0}};

  test_from_decimal_to_int_fail(decimal);
}

START_TEST(test_from_decimal_to_int_fail209) {
  my_decimal decimal = {{0xFFFFFFFF, 0x0, 0xFFFFFFFF, 0x80000000}};

  test_from_decimal_to_int_fail(decimal);
}

START_TEST(test_from_decimal_to_int_fail210) {
  my_decimal decimal = {{0xFFFFFFFF, 0x0, 0xFFFFFFFF, 0x10000}};

  test_from_decimal_to_int_fail(decimal);
}

START_TEST(test_from_decimal_to_int_fail211) {
  my_decimal decimal = {{0xFFFFFFFF, 0x0, 0xFFFFFFFF, 0x80010000}};

  test_from_decimal_to_int_fail(decimal);
}

START_TEST(test_from_decimal_to_int_fail212) {
  my_decimal decimal = {{0x0, 0x0, 0xFFFFFFFF, 0x0}};

  test_from_decimal_to_int_fail(decimal);
}

START_TEST(test_from_decimal_to_int_fail213) {
  my_decimal decimal = {{0x0, 0x0, 0xFFFFFFFF, 0x80000000}};

  test_from_decimal_to_int_fail(decimal);
}

START_TEST(test_from_decimal_to_int_fail214) {
  my_decimal decimal = {{0x0, 0x0, 0xFFFFFFFF, 0x10000}};

  test_from_decimal_to_int_fail(decimal);
}

START_TEST(test_from_decimal_to_int_fail215) {
  my_decimal decimal = {{0x0, 0x0, 0xFFFFFFFF, 0x80010000}};

  test_from_decimal_to_int_fail(decimal);
}

START_TEST(test_from_decimal_to_int_fail216) {
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0x0, 0x0}};

  test_from_decimal_to_int_fail(decimal);
}

START_TEST(test_from_decimal_to_int_fail217) {
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0x0, 0x80000000}};

  test_from_decimal_to_int_fail(decimal);
}

START_TEST(test_from_decimal_to_int_fail218) {
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0x0, 0x10000}};

  test_from_decimal_to_int_fail(decimal);
}

START_TEST(test_from_decimal_to_int_fail219) {
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0x0, 0x80010000}};

  test_from_decimal_to_int_fail(decimal);
}

START_TEST(test_from_decimal_to_int_fail220) {
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0x0, 0x30000}};

  test_from_decimal_to_int_fail(decimal);
}

START_TEST(test_from_decimal_to_int_fail221) {
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0x0, 0x80030000}};

  test_from_decimal_to_int_fail(decimal);
}

START_TEST(test_from_decimal_to_int_fail222) {
  my_decimal decimal = {{0x0, 0xFFFFFFFF, 0x0, 0x0}};

  test_from_decimal_to_int_fail(decimal);
}

START_TEST(test_from_decimal_to_int_fail223) {
  my_decimal decimal = {{0x0, 0xFFFFFFFF, 0x0, 0x80000000}};

  test_from_decimal_to_int_fail(decimal);
}

START_TEST(test_from_decimal_to_int_fail224) {
  my_decimal decimal = {{0x0, 0xFFFFFFFF, 0x0, 0x10000}};

  test_from_decimal_to_int_fail(decimal);
}

START_TEST(test_from_decimal_to_int_fail225) {
  my_decimal decimal = {{0x0, 0xFFFFFFFF, 0x0, 0x80010000}};

  test_from_decimal_to_int_fail(decimal);
}

START_TEST(test_from_decimal_to_int_fail226) {
  my_decimal decimal = {{0x0, 0xFFFFFFFF, 0x0, 0x30000}};

  test_from_decimal_to_int_fail(decimal);
}

START_TEST(test_from_decimal_to_int_fail227) {
  my_decimal decimal = {{0x0, 0xFFFFFFFF, 0x0, 0x80030000}};

  test_from_decimal_to_int_fail(decimal);
}

START_TEST(test_from_decimal_to_int_fail228) {
  my_decimal decimal = {{0xFFFFFFFF, 0x0, 0x0, 0x0}};

  test_from_decimal_to_int_fail(decimal);
}

START_TEST(test_from_decimal_to_int_fail229) {
  my_decimal decimal = {{0xFFFFFFFF, 0x0, 0x0, 0x80000000}};

  test_from_decimal_to_int_fail(decimal);
}

START_TEST(test_from_decimal_to_int_fail230) {
  my_decimal decimal = {{0xF91EAFF2, 0x6D795225, 0x3FD35EB, 0xE0000}};

  test_from_decimal_to_int_fail(decimal);
}

START_TEST(test_from_decimal_to_int_fail231) {
  my_decimal decimal = {{0xF91EAFF2, 0x6D795225, 0x3FD35EB, 0x800E0000}};

  test_from_decimal_to_int_fail(decimal);
}

START_TEST(test_from_decimal_to_int_fail232) {
  my_decimal decimal = {{0x630FFFFF, 0x6BC75E2D, 0x5, 0xA0000}};

  test_from_decimal_to_int_fail(decimal);
}

START_TEST(test_from_decimal_to_int_fail233) {
  my_decimal decimal = {{0x630FFFFF, 0x6BC75E2D, 0x5, 0x800A0000}};

  test_from_decimal_to_int_fail(decimal);
}

START_TEST(test_from_decimal_to_int_fail234) {
  my_decimal decimal = {{0x80000000, 0x0, 0x0, 0x0}};

  test_from_decimal_to_int_fail(decimal);
}

START_TEST(test_from_decimal_to_int_fail235) {
  my_decimal decimal = {{0x0, 0x32, 0x0, 0x20000}};

  test_from_decimal_to_int_fail(decimal);
}

START_TEST(test_from_decimal_to_int_fail236) {
  my_decimal decimal = {{0x63, 0x32, 0x0, 0x20000}};

  test_from_decimal_to_int_fail(decimal);
}

START_TEST(test_from_decimal_to_int_fail237) {
  my_decimal decimal = {{0xA763FFFF, 0xE192B6B3, 0x6F05B59, 0x120000}};

  test_from_decimal_to_int_fail(decimal);
}

START_TEST(test_from_decimal_to_int_fail238) {
  my_decimal decimal = {{0xCCD28D22, 0x0, 0x0, 0x0}};

  test_from_decimal_to_int_fail(decimal);
}

START_TEST(test_from_decimal_to_int_fail239) {
  my_decimal decimal = {{0xCCD28D22, 0x0, 0x0, 0x80000000}};

  test_from_decimal_to_int_fail(decimal);
}

START_TEST(test_from_decimal_to_int_fail240) {
  my_decimal decimal = {{0x930E0B67, 0x0, 0x0, 0x80000000}};

  test_from_decimal_to_int_fail(decimal);
}

START_TEST(test_from_decimal_to_int_fail241) {
  my_decimal decimal = {{0x930E0B67, 0x0, 0x0, 0x0}};

  test_from_decimal_to_int_fail(decimal);
}

START_TEST(test_from_decimal_to_int_fail242) {
  my_decimal decimal = {{0x88DB35C8, 0x0, 0x0, 0x80000000}};

  test_from_decimal_to_int_fail(decimal);
}

START_TEST(test_from_decimal_to_int_fail243) {
  my_decimal decimal = {{0x88DB35C8, 0x0, 0x0, 0x0}};

  test_from_decimal_to_int_fail(decimal);
}

START_TEST(test_from_decimal_to_int_fail244) {
  my_decimal decimal = {{0xE56A8955, 0x0, 0x0, 0x0}};

  test_from_decimal_to_int_fail(decimal);
}

START_TEST(test_from_decimal_to_int_fail245) {
  my_decimal decimal = {{0xE56A8955, 0x0, 0x0, 0x80000000}};

  test_from_decimal_to_int_fail(decimal);
}

START_TEST(test_from_decimal_to_int_fail246) {
  my_decimal decimal = {{0xBDB6A466, 0x0, 0x0, 0x80000000}};

  test_from_decimal_to_int_fail(decimal);
}

START_TEST(test_from_decimal_to_int_fail247) {
  my_decimal decimal = {{0xBDB6A466, 0x0, 0x0, 0x0}};

  test_from_decimal_to_int_fail(decimal);
}

START_TEST(test_from_decimal_to_int_fail248) {
  my_decimal decimal = {{0x26532417, 0x149403E0, 0x9DD561CC, 0x80000000}};

  test_from_decimal_to_int_fail(decimal);
}

START_TEST(test_from_decimal_to_int_fail249) {
  my_decimal decimal = {{0x26532417, 0x149403E0, 0x9DD561CC, 0x0}};

  test_from_decimal_to_int_fail(decimal);
}

START_TEST(test_from_decimal_to_int_fail250) {
  my_decimal decimal = {{0xC5D19575, 0x0, 0x0, 0x80000000}};

  test_from_decimal_to_int_fail(decimal);
}

START_TEST(test_from_decimal_to_int_fail251) {
  my_decimal decimal = {{0xC5D19575, 0x0, 0x0, 0x0}};

  test_from_decimal_to_int_fail(decimal);
}

START_TEST(test_from_decimal_to_int_fail252) {
  my_decimal decimal = {{0x89E2A546, 0x0, 0x0, 0x80000000}};

  test_from_decimal_to_int_fail(decimal);
}

START_TEST(test_from_decimal_to_int_fail253) {
  my_decimal decimal = {{0x89E2A546, 0x0, 0x0, 0x0}};

  test_from_decimal_to_int_fail(decimal);
}

START_TEST(test_from_decimal_to_int_fail254) {
  my_decimal decimal = {{0xC925BB40, 0x0, 0x0, 0x0}};

  test_from_decimal_to_int_fail(decimal);
}

START_TEST(test_from_decimal_to_int_fail255) {
  my_decimal decimal = {{0xC925BB40, 0x0, 0x0, 0x80000000}};

  test_from_decimal_to_int_fail(decimal);
}

START_TEST(test_from_decimal_to_int_fail256) {
  my_decimal decimal = {{0xEFA42150, 0x0, 0x0, 0x0}};

  test_from_decimal_to_int_fail(decimal);
}

START_TEST(test_from_decimal_to_int_fail257) {
  my_decimal decimal = {{0xEFA42150, 0x0, 0x0, 0x80000000}};

  test_from_decimal_to_int_fail(decimal);
}

START_TEST(test_from_decimal_to_int_fail258) {
  my_decimal decimal = {{0xB31C3C08, 0x0, 0x0, 0x0}};

  test_from_decimal_to_int_fail(decimal);
}

START_TEST(test_from_decimal_to_int_fail259) {
  my_decimal decimal = {{0xB31C3C08, 0x0, 0x0, 0x80000000}};

  test_from_decimal_to_int_fail(decimal);
}

START_TEST(test_from_decimal_to_int_fail260) {
  my_decimal decimal = {{0xAA6DA88F, 0x0, 0x0, 0x80000000}};

  test_from_decimal_to_int_fail(decimal);
}

START_TEST(test_from_decimal_to_int_fail261) {
  my_decimal decimal = {{0xAA6DA88F, 0x0, 0x0, 0x0}};

  test_from_decimal_to_int_fail(decimal);
}

START_TEST(test_from_decimal_to_int_fail262) {
  my_decimal decimal = {{0xD42B55B5, 0x0, 0x0, 0x0}};

  test_from_decimal_to_int_fail(decimal);
}

START_TEST(test_from_decimal_to_int_fail263) {
  my_decimal decimal = {{0xD42B55B5, 0x0, 0x0, 0x80000000}};

  test_from_decimal_to_int_fail(decimal);
}

START_TEST(test_from_decimal_to_int_fail264) {
  my_decimal decimal = {{0x9CFB9D90, 0x0, 0x0, 0x80000000}};

  test_from_decimal_to_int_fail(decimal);
}

START_TEST(test_from_decimal_to_int_fail265) {
  my_decimal decimal = {{0x9CFB9D90, 0x0, 0x0, 0x0}};

  test_from_decimal_to_int_fail(decimal);
}

START_TEST(test_from_decimal_to_int_fail266) {
  my_decimal decimal = {{0xE56F9F84, 0x0, 0x0, 0x0}};

  test_from_decimal_to_int_fail(decimal);
}

START_TEST(test_from_decimal_to_int_fail267) {
  my_decimal decimal = {{0xE56F9F84, 0x0, 0x0, 0x80000000}};

  test_from_decimal_to_int_fail(decimal);
}

START_TEST(test_from_decimal_to_int_fail268) {
  my_decimal decimal = {{0x75E13DF1, 0x206039BC, 0xD6103589, 0x80000000}};

  test_from_decimal_to_int_fail(decimal);
}

START_TEST(test_from_decimal_to_int_fail269) {
  my_decimal decimal = {{0x75E13DF1, 0x206039BC, 0xD6103589, 0x0}};

  test_from_decimal_to_int_fail(decimal);
}

START_TEST(test_from_decimal_to_int_fail270) {
  my_decimal decimal = {{0xEE6F1E6C, 0x0, 0x0, 0x0}};

  test_from_decimal_to_int_fail(decimal);
}

START_TEST(test_from_decimal_to_int_fail271) {
  my_decimal decimal = {{0xEE6F1E6C, 0x0, 0x0, 0x80000000}};

  test_from_decimal_to_int_fail(decimal);
}

START_TEST(test_from_decimal_to_int_fail272) {
  my_decimal decimal = {{0xA9C59909, 0x3FD3888, 0x60ECF955, 0x20000}};

  test_from_decimal_to_int_fail(decimal);
}

START_TEST(test_from_decimal_to_int_fail273) {
  my_decimal decimal = {{0xA9C59909, 0x3FD3888, 0x60ECF955, 0x80020000}};

  test_from_decimal_to_int_fail(decimal);
}

START_TEST(test_from_decimal_to_int_fail274) {
  my_decimal decimal = {{0xC100599E, 0x0, 0x0, 0x80000000}};

  test_from_decimal_to_int_fail(decimal);
}

START_TEST(test_from_decimal_to_int_fail275) {
  my_decimal decimal = {{0xC100599E, 0x0, 0x0, 0x0}};

  test_from_decimal_to_int_fail(decimal);
}

Suite *from_decimal_to_int_suite1(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("from_decimal_to_int1");
  tc_core = tcase_create("Core");
  tcase_add_test(tc_core, test_from_decimal_to_int_ok1);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok2);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok3);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok4);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok5);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok6);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok7);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok8);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok9);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok10);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok11);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok12);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok13);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok14);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok15);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok16);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok17);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok18);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok19);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok20);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok21);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok22);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok23);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok24);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok25);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok26);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok27);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok28);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok29);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok30);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok31);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok32);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok33);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok34);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok35);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok36);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok37);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok38);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok39);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok40);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok41);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok42);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok43);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok44);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok45);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok46);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok47);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok48);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok49);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok50);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok51);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok52);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok53);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok54);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok55);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok56);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok57);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok58);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok59);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok60);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok61);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok62);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok63);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok64);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok65);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok66);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok67);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok68);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok69);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok70);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok71);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok72);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok73);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok74);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok75);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok76);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok77);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok78);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok79);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok80);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok81);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok82);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok83);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok84);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok85);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok86);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok87);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok88);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok89);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok90);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok91);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok92);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok93);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok94);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok95);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok96);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok97);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok98);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok99);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok100);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok101);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok102);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok103);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok104);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok105);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok106);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok107);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok108);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok109);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok110);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok111);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok112);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok113);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok114);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok115);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok116);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok117);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok118);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok119);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok120);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok121);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok122);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok123);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok124);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok125);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok126);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok127);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok128);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok129);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok130);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok131);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok132);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok133);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok134);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok135);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok136);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok137);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok138);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok139);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok140);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok141);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok142);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok143);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok144);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok145);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok146);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok147);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok148);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok149);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok150);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok151);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok152);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok153);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok154);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok155);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok156);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok157);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok158);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok159);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok160);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok161);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok162);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok163);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok164);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok165);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok166);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok167);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok168);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok169);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok170);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok171);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok172);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok173);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok174);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok175);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok176);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok177);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok178);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok179);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok180);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok181);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok182);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok183);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok184);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok185);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok186);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok187);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok188);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok189);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok190);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok191);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok192);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok193);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok194);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok195);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok196);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok197);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok198);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok199);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok200);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok201);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok202);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok203);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok204);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok205);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok206);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok207);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok208);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok209);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok210);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok211);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok212);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok213);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok214);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok215);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok216);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok217);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok218);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok219);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok220);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok221);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok222);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok223);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok224);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok225);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok226);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok227);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok228);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok229);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok230);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok231);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok232);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok233);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok234);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok235);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok236);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok237);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok238);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok239);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok240);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok241);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok242);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok243);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok244);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok245);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok246);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok247);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok248);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok249);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok250);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok251);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok252);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok253);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok254);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok255);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok256);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok257);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok258);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok259);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok260);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok261);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok262);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok263);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok264);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok265);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok266);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok267);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok268);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok269);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok270);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok271);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok272);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok273);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok274);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok275);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok276);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok277);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok278);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok279);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok280);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok281);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok282);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok283);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok284);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok285);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok286);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok287);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok288);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok289);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok290);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok291);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok292);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok293);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok294);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok295);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok296);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok297);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok298);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok299);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok300);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok301);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok302);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok303);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok304);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok305);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok306);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok307);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok308);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok309);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok310);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok311);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok312);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok313);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok314);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok315);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok316);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok317);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok318);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok319);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok320);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok321);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok322);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok323);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok324);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok325);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok326);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok327);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok328);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok329);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok330);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok331);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok332);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok333);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok334);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok335);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok336);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok337);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok338);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok339);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok340);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok341);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok342);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok343);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok344);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok345);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok346);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok347);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok348);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok349);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok350);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok351);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok352);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok353);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok354);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok355);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok356);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok357);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok358);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok359);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok360);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok361);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok362);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok363);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok364);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok365);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok366);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok367);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok368);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok369);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok370);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok371);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok372);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok373);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok374);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok375);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok376);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok377);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok378);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok379);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok380);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok381);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok382);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok383);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok384);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok385);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok386);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok387);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok388);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok389);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok390);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok391);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok392);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok393);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok394);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok395);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok396);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok397);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok398);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok399);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok400);

  suite_add_tcase(s, tc_core);
  return s;
}

Suite *from_decimal_to_int_suite2(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("from_decimal_to_int2");
  tc_core = tcase_create("Core");
  tcase_add_test(tc_core, test_from_decimal_to_int_ok401);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok402);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok403);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok404);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok405);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok406);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok407);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok408);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok409);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok410);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok411);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok412);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok413);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok414);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok415);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok416);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok417);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok418);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok419);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok420);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok421);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok422);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok423);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok424);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok425);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok426);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok427);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok428);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok429);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok430);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok431);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok432);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok433);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok434);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok435);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok436);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok437);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok438);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok439);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok440);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok441);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok442);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok443);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok444);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok445);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok446);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok447);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok448);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok449);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok450);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok451);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok452);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok453);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok454);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok455);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok456);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok457);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok458);
  tcase_add_test(tc_core, test_from_decimal_to_int_ok459);

  suite_add_tcase(s, tc_core);
  return s;
}

Suite *from_decimal_to_int_suite3(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("from_decimal_to_int3");
  tc_core = tcase_create("Core");
  tcase_add_test(tc_core, test_from_decimal_to_int_fail1);
  tcase_add_test(tc_core, test_from_decimal_to_int_fail2);
  tcase_add_test(tc_core, test_from_decimal_to_int_fail3);
  tcase_add_test(tc_core, test_from_decimal_to_int_fail4);
  tcase_add_test(tc_core, test_from_decimal_to_int_fail5);
  tcase_add_test(tc_core, test_from_decimal_to_int_fail6);
  tcase_add_test(tc_core, test_from_decimal_to_int_fail7);
  tcase_add_test(tc_core, test_from_decimal_to_int_fail8);
  tcase_add_test(tc_core, test_from_decimal_to_int_fail9);
  tcase_add_test(tc_core, test_from_decimal_to_int_fail10);
  tcase_add_test(tc_core, test_from_decimal_to_int_fail11);
  tcase_add_test(tc_core, test_from_decimal_to_int_fail12);
  tcase_add_test(tc_core, test_from_decimal_to_int_fail13);
  tcase_add_test(tc_core, test_from_decimal_to_int_fail14);
  tcase_add_test(tc_core, test_from_decimal_to_int_fail15);
  tcase_add_test(tc_core, test_from_decimal_to_int_fail16);
  tcase_add_test(tc_core, test_from_decimal_to_int_fail17);
  tcase_add_test(tc_core, test_from_decimal_to_int_fail18);
  tcase_add_test(tc_core, test_from_decimal_to_int_fail19);
  tcase_add_test(tc_core, test_from_decimal_to_int_fail20);
  tcase_add_test(tc_core, test_from_decimal_to_int_fail21);
  tcase_add_test(tc_core, test_from_decimal_to_int_fail22);
  tcase_add_test(tc_core, test_from_decimal_to_int_fail23);
  tcase_add_test(tc_core, test_from_decimal_to_int_fail24);
  tcase_add_test(tc_core, test_from_decimal_to_int_fail25);
  tcase_add_test(tc_core, test_from_decimal_to_int_fail26);
  tcase_add_test(tc_core, test_from_decimal_to_int_fail27);
  tcase_add_test(tc_core, test_from_decimal_to_int_fail28);
  tcase_add_test(tc_core, test_from_decimal_to_int_fail29);
  tcase_add_test(tc_core, test_from_decimal_to_int_fail30);
  tcase_add_test(tc_core, test_from_decimal_to_int_fail31);
  tcase_add_test(tc_core, test_from_decimal_to_int_fail32);
  tcase_add_test(tc_core, test_from_decimal_to_int_fail33);
  tcase_add_test(tc_core, test_from_decimal_to_int_fail34);
  tcase_add_test(tc_core, test_from_decimal_to_int_fail35);
  tcase_add_test(tc_core, test_from_decimal_to_int_fail36);
  tcase_add_test(tc_core, test_from_decimal_to_int_fail37);
  tcase_add_test(tc_core, test_from_decimal_to_int_fail38);
  tcase_add_test(tc_core, test_from_decimal_to_int_fail39);
  tcase_add_test(tc_core, test_from_decimal_to_int_fail40);
  tcase_add_test(tc_core, test_from_decimal_to_int_fail41);
  tcase_add_test(tc_core, test_from_decimal_to_int_fail42);
  tcase_add_test(tc_core, test_from_decimal_to_int_fail43);
  tcase_add_test(tc_core, test_from_decimal_to_int_fail44);
  tcase_add_test(tc_core, test_from_decimal_to_int_fail45);
  tcase_add_test(tc_core, test_from_decimal_to_int_fail46);
  tcase_add_test(tc_core, test_from_decimal_to_int_fail47);
  tcase_add_test(tc_core, test_from_decimal_to_int_fail48);
  tcase_add_test(tc_core, test_from_decimal_to_int_fail49);
  tcase_add_test(tc_core, test_from_decimal_to_int_fail50);
  tcase_add_test(tc_core, test_from_decimal_to_int_fail51);
  tcase_add_test(tc_core, test_from_decimal_to_int_fail52);
  tcase_add_test(tc_core, test_from_decimal_to_int_fail53);
  tcase_add_test(tc_core, test_from_decimal_to_int_fail54);
  tcase_add_test(tc_core, test_from_decimal_to_int_fail55);
  tcase_add_test(tc_core, test_from_decimal_to_int_fail56);
  tcase_add_test(tc_core, test_from_decimal_to_int_fail57);
  tcase_add_test(tc_core, test_from_decimal_to_int_fail58);
  tcase_add_test(tc_core, test_from_decimal_to_int_fail59);
  tcase_add_test(tc_core, test_from_decimal_to_int_fail60);
  tcase_add_test(tc_core, test_from_decimal_to_int_fail61);
  tcase_add_test(tc_core, test_from_decimal_to_int_fail62);
  tcase_add_test(tc_core, test_from_decimal_to_int_fail63);
  tcase_add_test(tc_core, test_from_decimal_to_int_fail64);
  tcase_add_test(tc_core, test_from_decimal_to_int_fail65);
  tcase_add_test(tc_core, test_from_decimal_to_int_fail66);
  tcase_add_test(tc_core, test_from_decimal_to_int_fail67);
  tcase_add_test(tc_core, test_from_decimal_to_int_fail68);
  tcase_add_test(tc_core, test_from_decimal_to_int_fail69);
  tcase_add_test(tc_core, test_from_decimal_to_int_fail70);
  tcase_add_test(tc_core, test_from_decimal_to_int_fail71);
  tcase_add_test(tc_core, test_from_decimal_to_int_fail72);
  tcase_add_test(tc_core, test_from_decimal_to_int_fail73);
  tcase_add_test(tc_core, test_from_decimal_to_int_fail74);
  tcase_add_test(tc_core, test_from_decimal_to_int_fail75);
  tcase_add_test(tc_core, test_from_decimal_to_int_fail76);
  tcase_add_test(tc_core, test_from_decimal_to_int_fail77);
  tcase_add_test(tc_core, test_from_decimal_to_int_fail78);
  tcase_add_test(tc_core, test_from_decimal_to_int_fail79);
  tcase_add_test(tc_core, test_from_decimal_to_int_fail80);
  tcase_add_test(tc_core, test_from_decimal_to_int_fail81);
  tcase_add_test(tc_core, test_from_decimal_to_int_fail82);
  tcase_add_test(tc_core, test_from_decimal_to_int_fail83);
  tcase_add_test(tc_core, test_from_decimal_to_int_fail84);
  tcase_add_test(tc_core, test_from_decimal_to_int_fail85);
  tcase_add_test(tc_core, test_from_decimal_to_int_fail86);
  tcase_add_test(tc_core, test_from_decimal_to_int_fail87);
  tcase_add_test(tc_core, test_from_decimal_to_int_fail88);
  tcase_add_test(tc_core, test_from_decimal_to_int_fail89);
  tcase_add_test(tc_core, test_from_decimal_to_int_fail90);
  tcase_add_test(tc_core, test_from_decimal_to_int_fail91);
  tcase_add_test(tc_core, test_from_decimal_to_int_fail92);
  tcase_add_test(tc_core, test_from_decimal_to_int_fail93);
  tcase_add_test(tc_core, test_from_decimal_to_int_fail94);
  tcase_add_test(tc_core, test_from_decimal_to_int_fail95);
  tcase_add_test(tc_core, test_from_decimal_to_int_fail96);
  tcase_add_test(tc_core, test_from_decimal_to_int_fail97);
  tcase_add_test(tc_core, test_from_decimal_to_int_fail98);
  tcase_add_test(tc_core, test_from_decimal_to_int_fail99);
  tcase_add_test(tc_core, test_from_decimal_to_int_fail100);
  tcase_add_test(tc_core, test_from_decimal_to_int_fail101);
  tcase_add_test(tc_core, test_from_decimal_to_int_fail102);
  tcase_add_test(tc_core, test_from_decimal_to_int_fail103);
  tcase_add_test(tc_core, test_from_decimal_to_int_fail104);
  tcase_add_test(tc_core, test_from_decimal_to_int_fail105);
  tcase_add_test(tc_core, test_from_decimal_to_int_fail106);
  tcase_add_test(tc_core, test_from_decimal_to_int_fail107);
  tcase_add_test(tc_core, test_from_decimal_to_int_fail108);
  tcase_add_test(tc_core, test_from_decimal_to_int_fail109);
  tcase_add_test(tc_core, test_from_decimal_to_int_fail110);
  tcase_add_test(tc_core, test_from_decimal_to_int_fail111);
  tcase_add_test(tc_core, test_from_decimal_to_int_fail112);
  tcase_add_test(tc_core, test_from_decimal_to_int_fail113);
  tcase_add_test(tc_core, test_from_decimal_to_int_fail114);
  tcase_add_test(tc_core, test_from_decimal_to_int_fail115);
  tcase_add_test(tc_core, test_from_decimal_to_int_fail116);
  tcase_add_test(tc_core, test_from_decimal_to_int_fail117);
  tcase_add_test(tc_core, test_from_decimal_to_int_fail118);
  tcase_add_test(tc_core, test_from_decimal_to_int_fail119);
  tcase_add_test(tc_core, test_from_decimal_to_int_fail120);
  tcase_add_test(tc_core, test_from_decimal_to_int_fail121);
  tcase_add_test(tc_core, test_from_decimal_to_int_fail122);
  tcase_add_test(tc_core, test_from_decimal_to_int_fail123);
  tcase_add_test(tc_core, test_from_decimal_to_int_fail124);
  tcase_add_test(tc_core, test_from_decimal_to_int_fail125);
  tcase_add_test(tc_core, test_from_decimal_to_int_fail126);
  tcase_add_test(tc_core, test_from_decimal_to_int_fail127);
  tcase_add_test(tc_core, test_from_decimal_to_int_fail128);
  tcase_add_test(tc_core, test_from_decimal_to_int_fail129);
  tcase_add_test(tc_core, test_from_decimal_to_int_fail130);
  tcase_add_test(tc_core, test_from_decimal_to_int_fail131);
  tcase_add_test(tc_core, test_from_decimal_to_int_fail132);
  tcase_add_test(tc_core, test_from_decimal_to_int_fail133);
  tcase_add_test(tc_core, test_from_decimal_to_int_fail134);
  tcase_add_test(tc_core, test_from_decimal_to_int_fail135);
  tcase_add_test(tc_core, test_from_decimal_to_int_fail136);
  tcase_add_test(tc_core, test_from_decimal_to_int_fail137);
  tcase_add_test(tc_core, test_from_decimal_to_int_fail138);
  tcase_add_test(tc_core, test_from_decimal_to_int_fail139);
  tcase_add_test(tc_core, test_from_decimal_to_int_fail140);
  tcase_add_test(tc_core, test_from_decimal_to_int_fail141);
  tcase_add_test(tc_core, test_from_decimal_to_int_fail142);
  tcase_add_test(tc_core, test_from_decimal_to_int_fail143);
  tcase_add_test(tc_core, test_from_decimal_to_int_fail144);
  tcase_add_test(tc_core, test_from_decimal_to_int_fail145);
  tcase_add_test(tc_core, test_from_decimal_to_int_fail146);
  tcase_add_test(tc_core, test_from_decimal_to_int_fail147);
  tcase_add_test(tc_core, test_from_decimal_to_int_fail148);
  tcase_add_test(tc_core, test_from_decimal_to_int_fail149);
  tcase_add_test(tc_core, test_from_decimal_to_int_fail150);
  tcase_add_test(tc_core, test_from_decimal_to_int_fail151);
  tcase_add_test(tc_core, test_from_decimal_to_int_fail152);
  tcase_add_test(tc_core, test_from_decimal_to_int_fail153);
  tcase_add_test(tc_core, test_from_decimal_to_int_fail154);
  tcase_add_test(tc_core, test_from_decimal_to_int_fail155);
  tcase_add_test(tc_core, test_from_decimal_to_int_fail156);
  tcase_add_test(tc_core, test_from_decimal_to_int_fail157);
  tcase_add_test(tc_core, test_from_decimal_to_int_fail158);
  tcase_add_test(tc_core, test_from_decimal_to_int_fail159);
  tcase_add_test(tc_core, test_from_decimal_to_int_fail160);
  tcase_add_test(tc_core, test_from_decimal_to_int_fail161);
  tcase_add_test(tc_core, test_from_decimal_to_int_fail162);
  tcase_add_test(tc_core, test_from_decimal_to_int_fail163);
  tcase_add_test(tc_core, test_from_decimal_to_int_fail164);
  tcase_add_test(tc_core, test_from_decimal_to_int_fail165);
  tcase_add_test(tc_core, test_from_decimal_to_int_fail166);
  tcase_add_test(tc_core, test_from_decimal_to_int_fail167);
  tcase_add_test(tc_core, test_from_decimal_to_int_fail168);
  tcase_add_test(tc_core, test_from_decimal_to_int_fail169);
  tcase_add_test(tc_core, test_from_decimal_to_int_fail170);
  tcase_add_test(tc_core, test_from_decimal_to_int_fail171);
  tcase_add_test(tc_core, test_from_decimal_to_int_fail172);
  tcase_add_test(tc_core, test_from_decimal_to_int_fail173);
  tcase_add_test(tc_core, test_from_decimal_to_int_fail174);
  tcase_add_test(tc_core, test_from_decimal_to_int_fail175);
  tcase_add_test(tc_core, test_from_decimal_to_int_fail176);
  tcase_add_test(tc_core, test_from_decimal_to_int_fail177);
  tcase_add_test(tc_core, test_from_decimal_to_int_fail178);
  tcase_add_test(tc_core, test_from_decimal_to_int_fail179);
  tcase_add_test(tc_core, test_from_decimal_to_int_fail180);
  tcase_add_test(tc_core, test_from_decimal_to_int_fail181);
  tcase_add_test(tc_core, test_from_decimal_to_int_fail182);
  tcase_add_test(tc_core, test_from_decimal_to_int_fail183);
  tcase_add_test(tc_core, test_from_decimal_to_int_fail184);
  tcase_add_test(tc_core, test_from_decimal_to_int_fail185);
  tcase_add_test(tc_core, test_from_decimal_to_int_fail186);
  tcase_add_test(tc_core, test_from_decimal_to_int_fail187);
  tcase_add_test(tc_core, test_from_decimal_to_int_fail188);
  tcase_add_test(tc_core, test_from_decimal_to_int_fail189);
  tcase_add_test(tc_core, test_from_decimal_to_int_fail190);
  tcase_add_test(tc_core, test_from_decimal_to_int_fail191);
  tcase_add_test(tc_core, test_from_decimal_to_int_fail192);
  tcase_add_test(tc_core, test_from_decimal_to_int_fail193);
  tcase_add_test(tc_core, test_from_decimal_to_int_fail194);
  tcase_add_test(tc_core, test_from_decimal_to_int_fail195);
  tcase_add_test(tc_core, test_from_decimal_to_int_fail196);
  tcase_add_test(tc_core, test_from_decimal_to_int_fail197);
  tcase_add_test(tc_core, test_from_decimal_to_int_fail198);
  tcase_add_test(tc_core, test_from_decimal_to_int_fail199);
  tcase_add_test(tc_core, test_from_decimal_to_int_fail200);
  tcase_add_test(tc_core, test_from_decimal_to_int_fail201);
  tcase_add_test(tc_core, test_from_decimal_to_int_fail202);
  tcase_add_test(tc_core, test_from_decimal_to_int_fail203);
  tcase_add_test(tc_core, test_from_decimal_to_int_fail204);
  tcase_add_test(tc_core, test_from_decimal_to_int_fail205);
  tcase_add_test(tc_core, test_from_decimal_to_int_fail206);
  tcase_add_test(tc_core, test_from_decimal_to_int_fail207);
  tcase_add_test(tc_core, test_from_decimal_to_int_fail208);
  tcase_add_test(tc_core, test_from_decimal_to_int_fail209);
  tcase_add_test(tc_core, test_from_decimal_to_int_fail210);
  tcase_add_test(tc_core, test_from_decimal_to_int_fail211);
  tcase_add_test(tc_core, test_from_decimal_to_int_fail212);
  tcase_add_test(tc_core, test_from_decimal_to_int_fail213);
  tcase_add_test(tc_core, test_from_decimal_to_int_fail214);
  tcase_add_test(tc_core, test_from_decimal_to_int_fail215);
  tcase_add_test(tc_core, test_from_decimal_to_int_fail216);
  tcase_add_test(tc_core, test_from_decimal_to_int_fail217);
  tcase_add_test(tc_core, test_from_decimal_to_int_fail218);
  tcase_add_test(tc_core, test_from_decimal_to_int_fail219);
  tcase_add_test(tc_core, test_from_decimal_to_int_fail220);
  tcase_add_test(tc_core, test_from_decimal_to_int_fail221);
  tcase_add_test(tc_core, test_from_decimal_to_int_fail222);
  tcase_add_test(tc_core, test_from_decimal_to_int_fail223);
  tcase_add_test(tc_core, test_from_decimal_to_int_fail224);
  tcase_add_test(tc_core, test_from_decimal_to_int_fail225);
  tcase_add_test(tc_core, test_from_decimal_to_int_fail226);
  tcase_add_test(tc_core, test_from_decimal_to_int_fail227);
  tcase_add_test(tc_core, test_from_decimal_to_int_fail228);
  tcase_add_test(tc_core, test_from_decimal_to_int_fail229);
  tcase_add_test(tc_core, test_from_decimal_to_int_fail230);
  tcase_add_test(tc_core, test_from_decimal_to_int_fail231);
  tcase_add_test(tc_core, test_from_decimal_to_int_fail232);
  tcase_add_test(tc_core, test_from_decimal_to_int_fail233);
  tcase_add_test(tc_core, test_from_decimal_to_int_fail234);
  tcase_add_test(tc_core, test_from_decimal_to_int_fail235);
  tcase_add_test(tc_core, test_from_decimal_to_int_fail236);
  tcase_add_test(tc_core, test_from_decimal_to_int_fail237);
  tcase_add_test(tc_core, test_from_decimal_to_int_fail238);
  tcase_add_test(tc_core, test_from_decimal_to_int_fail239);
  tcase_add_test(tc_core, test_from_decimal_to_int_fail240);
  tcase_add_test(tc_core, test_from_decimal_to_int_fail241);
  tcase_add_test(tc_core, test_from_decimal_to_int_fail242);
  tcase_add_test(tc_core, test_from_decimal_to_int_fail243);
  tcase_add_test(tc_core, test_from_decimal_to_int_fail244);
  tcase_add_test(tc_core, test_from_decimal_to_int_fail245);
  tcase_add_test(tc_core, test_from_decimal_to_int_fail246);
  tcase_add_test(tc_core, test_from_decimal_to_int_fail247);
  tcase_add_test(tc_core, test_from_decimal_to_int_fail248);
  tcase_add_test(tc_core, test_from_decimal_to_int_fail249);
  tcase_add_test(tc_core, test_from_decimal_to_int_fail250);
  tcase_add_test(tc_core, test_from_decimal_to_int_fail251);
  tcase_add_test(tc_core, test_from_decimal_to_int_fail252);
  tcase_add_test(tc_core, test_from_decimal_to_int_fail253);
  tcase_add_test(tc_core, test_from_decimal_to_int_fail254);
  tcase_add_test(tc_core, test_from_decimal_to_int_fail255);
  tcase_add_test(tc_core, test_from_decimal_to_int_fail256);
  tcase_add_test(tc_core, test_from_decimal_to_int_fail257);
  tcase_add_test(tc_core, test_from_decimal_to_int_fail258);
  tcase_add_test(tc_core, test_from_decimal_to_int_fail259);
  tcase_add_test(tc_core, test_from_decimal_to_int_fail260);
  tcase_add_test(tc_core, test_from_decimal_to_int_fail261);
  tcase_add_test(tc_core, test_from_decimal_to_int_fail262);
  tcase_add_test(tc_core, test_from_decimal_to_int_fail263);
  tcase_add_test(tc_core, test_from_decimal_to_int_fail264);
  tcase_add_test(tc_core, test_from_decimal_to_int_fail265);
  tcase_add_test(tc_core, test_from_decimal_to_int_fail266);
  tcase_add_test(tc_core, test_from_decimal_to_int_fail267);
  tcase_add_test(tc_core, test_from_decimal_to_int_fail268);
  tcase_add_test(tc_core, test_from_decimal_to_int_fail269);
  tcase_add_test(tc_core, test_from_decimal_to_int_fail270);
  tcase_add_test(tc_core, test_from_decimal_to_int_fail271);
  tcase_add_test(tc_core, test_from_decimal_to_int_fail272);
  tcase_add_test(tc_core, test_from_decimal_to_int_fail273);
  tcase_add_test(tc_core, test_from_decimal_to_int_fail274);
  tcase_add_test(tc_core, test_from_decimal_to_int_fail275);

  suite_add_tcase(s, tc_core);
  return s;
}

Suite *from_decimal_to_int_suite0(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("from_decimal_to_int0");
  tc_core = tcase_create("Core");

  tcase_add_test(tc_core, test_from_decimal_to_int_fail_manual1);
  tcase_add_test(tc_core, test_from_decimal_to_int_fail_manual2);
  tcase_add_test(tc_core, test_from_decimal_to_int_fail_manual3);
  tcase_add_test(tc_core, test_from_decimal_to_int_fail_manual4);
  tcase_add_test(tc_core, test_from_decimal_to_int_fail_manual5);
  tcase_add_test(tc_core, test_from_decimal_to_int_fail_manual6);
  tcase_add_test(tc_core, test_from_decimal_to_int_fail_manual7);
  tcase_add_test(tc_core, test_from_decimal_to_int_fail_manual8);
  tcase_add_test(tc_core, test_from_decimal_to_int_fail_manual9);

  suite_add_tcase(s, tc_core);
  return s;
}

void test_from_decimal_to_int(my_decimal decimal, int check) {
  int result;
  int code = my_from_decimal_to_int(decimal, &result);

  ck_assert_int_eq(result, check);
  ck_assert_int_eq(code, TEST_CONVERSION_OK);
}

void test_from_decimal_to_int_fail(my_decimal decimal) {
  int result;
  int code = my_from_decimal_to_int(decimal, &result);

  ck_assert_int_eq(code, TEST_CONVERSION_ERROR);
}
