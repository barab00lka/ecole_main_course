#include <check.h>
#include <stdio.h>
#include <stdlib.h>

#include "./../../my_decimal.h"
#include "./../test.h"

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * * * * * * * * * * * * * * Тесты на некорректные данные (ручные)
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * * * * * * * * * * * * * */

START_TEST(test_from_decimal_to_float_fail_manual1) {
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x140000}};
  int code = my_from_decimal_to_float(decimal, NULL);

  ck_assert_int_eq(code, TEST_CONVERSION_ERROR);
}

START_TEST(test_from_decimal_to_float_fail_manual2) {
  my_decimal decimal = {{0, 0, 0, 1000000000}};
  float result;
  int code = my_from_decimal_to_float(decimal, &result);

  ck_assert_int_eq(code, TEST_CONVERSION_ERROR);
}
END_TEST

START_TEST(test_from_decimal_to_float_fail_manual3) {
  my_decimal decimal = {{-1, 0, 0, 0x1D0000}};
  float result;
  int code = my_from_decimal_to_float(decimal, &result);

  ck_assert_int_eq(code, TEST_CONVERSION_ERROR);
}
END_TEST

START_TEST(test_from_decimal_to_float_fail_manual4) {
  my_decimal decimal = {{0, 0, 0, 0x1D0000}};
  float result;
  int code = my_from_decimal_to_float(decimal, &result);

  ck_assert_int_eq(code, TEST_CONVERSION_ERROR);
}
END_TEST

START_TEST(test_from_decimal_to_float_fail_manual5) {
  my_decimal decimal = {{-1, 0, 0, 0x1C0001}};
  float result;
  int code = my_from_decimal_to_float(decimal, &result);

  ck_assert_int_eq(code, TEST_CONVERSION_ERROR);
}
END_TEST

START_TEST(test_from_decimal_to_float_fail_manual6) {
  my_decimal decimal = {{-1, 0, 0, 0x1C8000}};
  float result;
  int code = my_from_decimal_to_float(decimal, &result);

  ck_assert_int_eq(code, TEST_CONVERSION_ERROR);
}
END_TEST

START_TEST(test_from_decimal_to_float_fail_manual7) {
  my_decimal decimal = {{-1, 0, 0, 0x11C0000}};
  float result;
  int code = my_from_decimal_to_float(decimal, &result);

  ck_assert_int_eq(code, TEST_CONVERSION_ERROR);
}
END_TEST

START_TEST(test_from_decimal_to_float_fail_manual8) {
  my_decimal decimal = {{-1, 0, 0, 0x401C0000}};
  float result;
  int code = my_from_decimal_to_float(decimal, &result);

  ck_assert_int_eq(code, TEST_CONVERSION_ERROR);
}
END_TEST

START_TEST(test_from_decimal_to_float_fail_manual9) {
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF}};
  float result;
  int code = my_from_decimal_to_float(decimal, &result);

  ck_assert_int_eq(code, TEST_CONVERSION_ERROR);
}
END_TEST

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * * * * * * * * * * * * * * Tests for correct data (automatic)
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * * * * * * * * * * * * * */

START_TEST(test_from_decimal_to_float_ok1) {
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  int check = 1870659584;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2) {
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  int check = -276824064;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok3) {
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};
  int check = 1842138317;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok4) {
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80010000}};
  int check = -305345331;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok5) {
  my_decimal decimal = {{0x3D70A3D7, 0x70A3D70A, 0x43D70A3D, 0x0}};
  int check = 1854385684;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok6) {
  my_decimal decimal = {{0x3D70A3D7, 0x70A3D70A, 0x43D70A3D, 0x80000000}};
  int check = -293097964;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok7) {
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x20000}};
  int check = 1814288138;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok8) {
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80020000}};
  int check = -333195510;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok9) {
  my_decimal decimal = {{0x3D70A3D7, 0x70A3D70A, 0x43D70A3D, 0x10000}};
  int check = 1826166407;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok10) {
  my_decimal decimal = {{0x3D70A3D7, 0x70A3D70A, 0x43D70A3D, 0x80010000}};
  int check = -321317241;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok11) {
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x30000}};
  int check = 1786974831;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok12) {
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80030000}};
  int check = -360508817;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok13) {
  my_decimal decimal = {{0x3D70A3D7, 0x70A3D70A, 0x43D70A3D, 0x20000}};
  int check = 1798155167;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok14) {
  my_decimal decimal = {{0x3D70A3D7, 0x70A3D70A, 0x43D70A3D, 0x80020000}};
  int check = -349328481;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok15) {
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x40000}};
  int check = 1758574359;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok16) {
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80040000}};
  int check = -388909289;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok17) {
  my_decimal decimal = {{0x3D70A3D7, 0x70A3D70A, 0x43D70A3D, 0x30000}};
  int check = 1770713011;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok18) {
  my_decimal decimal = {{0x3D70A3D7, 0x70A3D70A, 0x43D70A3D, 0x80030000}};
  int check = -376770637;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok19) {
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x50000}};
  int check = 1730659756;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok20) {
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80050000}};
  int check = -416823892;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok21) {
  my_decimal decimal = {{0x3D70A3D7, 0x70A3D70A, 0x43D70A3D, 0x40000}};
  int check = 1742621777;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok22) {
  my_decimal decimal = {{0x3D70A3D7, 0x70A3D70A, 0x43D70A3D, 0x80040000}};
  int check = -404861871;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok23) {
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x60000}};
  int check = 1703294909;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok24) {
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80060000}};
  int check = -444188739;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok25) {
  my_decimal decimal = {{0x3D70A3D7, 0x70A3D70A, 0x43D70A3D, 0x50000}};
  int check = 1714542247;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok26) {
  my_decimal decimal = {{0x3D70A3D7, 0x70A3D70A, 0x43D70A3D, 0x80050000}};
  int check = -432941401;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok27) {
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x70000}};
  int check = 1675018133;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok28) {
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80070000}};
  int check = -472465515;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok29) {
  my_decimal decimal = {{0x3D70A3D7, 0x70A3D70A, 0x43D70A3D, 0x60000}};
  int check = 1687045459;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok30) {
  my_decimal decimal = {{0x3D70A3D7, 0x70A3D70A, 0x43D70A3D, 0x80060000}};
  int check = -460438189;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok31) {
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000}};
  int check = 1647037559;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok32) {
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80080000}};
  int check = -500446089;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok33) {
  my_decimal decimal = {{0x3D70A3D7, 0x70A3D70A, 0x43D70A3D, 0x70000}};
  int check = 1659085342;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok34) {
  my_decimal decimal = {{0x3D70A3D7, 0x70A3D70A, 0x43D70A3D, 0x80070000}};
  int check = -488398306;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok35) {
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x90000}};
  int check = 1619619935;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok36) {
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80090000}};
  int check = -527863713;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok37) {
  my_decimal decimal = {{0x3D70A3D7, 0x70A3D70A, 0x43D70A3D, 0x80000}};
  int check = 1630935883;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok38) {
  my_decimal decimal = {{0x3D70A3D7, 0x70A3D70A, 0x43D70A3D, 0x80080000}};
  int check = -516547765;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok39) {
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xA0000}};
  int check = 1591469823;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok40) {
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x800A0000}};
  int check = -556013825;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok41) {
  my_decimal decimal = {{0x3D70A3D7, 0x70A3D70A, 0x43D70A3D, 0x90000}};
  int check = 1603383151;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok42) {
  my_decimal decimal = {{0x3D70A3D7, 0x70A3D70A, 0x43D70A3D, 0x80090000}};
  int check = -544100497;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok43) {
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xB0000}};
  int check = 1563421695;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok44) {
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x800B0000}};
  int check = -584061953;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok45) {
  my_decimal decimal = {{0x3D70A3D7, 0x70A3D70A, 0x43D70A3D, 0xA0000}};
  int check = 1575557298;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok46) {
  my_decimal decimal = {{0x3D70A3D7, 0x70A3D70A, 0x43D70A3D, 0x800A0000}};
  int check = -571926350;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok47) {
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xC0000}};
  int check = 1535950028;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok48) {
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x800C0000}};
  int check = -611533620;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok49) {
  my_decimal decimal = {{0x3D70A3D7, 0x70A3D70A, 0x43D70A3D, 0xB0000}};
  int check = 1547336232;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok50) {
  my_decimal decimal = {{0x3D70A3D7, 0x70A3D70A, 0x43D70A3D, 0x800B0000}};
  int check = -600147416;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok51) {
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xD0000}};
  int check = 1507929619;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok52) {
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x800D0000}};
  int check = -639554029;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok53) {
  my_decimal decimal = {{0x3D70A3D7, 0x70A3D70A, 0x43D70A3D, 0xC0000}};
  int check = 1519726214;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok54) {
  my_decimal decimal = {{0x3D70A3D7, 0x70A3D70A, 0x43D70A3D, 0x800C0000}};
  int check = -627757434;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok55) {
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xE0000}};
  int check = 1479812316;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok56) {
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x800E0000}};
  int check = -667671332;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok57) {
  my_decimal decimal = {{0x3D70A3D7, 0x70A3D70A, 0x43D70A3D, 0xD0000}};
  int check = 1492037847;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok58) {
  my_decimal decimal = {{0x3D70A3D7, 0x70A3D70A, 0x43D70A3D, 0x800D0000}};
  int check = -655445801;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok59) {
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0xF0000}};
  int check = 1452285309;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok60) {
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x800F0000}};
  int check = -695198339;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok61) {
  my_decimal decimal = {{0x3D70A3D7, 0x70A3D70A, 0x43D70A3D, 0xE0000}};
  int check = 1463743455;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok62) {
  my_decimal decimal = {{0x3D70A3D7, 0x70A3D70A, 0x43D70A3D, 0x800E0000}};
  int check = -683740193;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok63) {
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x100000}};
  int check = 1424397717;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok64) {
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80100000}};
  int check = -723085931;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok65) {
  my_decimal decimal = {{0x3D70A3D7, 0x70A3D70A, 0x43D70A3D, 0xF0000}};
  int check = 1436074777;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok66) {
  my_decimal decimal = {{0x3D70A3D7, 0x70A3D70A, 0x43D70A3D, 0x800F0000}};
  int check = -711408871;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok67) {
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x110000}};
  int check = 1396209578;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok68) {
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80110000}};
  int check = -751274070;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok69) {
  my_decimal decimal = {{0x3D70A3D7, 0x70A3D70A, 0x43D70A3D, 0x100000}};
  int check = 1408527195;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok70) {
  my_decimal decimal = {{0x3D70A3D7, 0x70A3D70A, 0x43D70A3D, 0x80100000}};
  int check = -738956453;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok71) {
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x120000}};
  int check = 1368625903;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok72) {
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80120000}};
  int check = -778857745;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok73) {
  my_decimal decimal = {{0x3D70A3D7, 0x70A3D70A, 0x43D70A3D, 0x110000}};
  int check = 1380157718;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok74) {
  my_decimal decimal = {{0x3D70A3D7, 0x70A3D70A, 0x43D70A3D, 0x80110000}};
  int check = -767325930;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok75) {
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x130000}};
  int check = 1340874314;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok76) {
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80130000}};
  int check = -806609334;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok77) {
  my_decimal decimal = {{0x3D70A3D7, 0x70A3D70A, 0x43D70A3D, 0x120000}};
  int check = 1352428971;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok78) {
  my_decimal decimal = {{0x3D70A3D7, 0x70A3D70A, 0x43D70A3D, 0x80120000}};
  int check = -795054677;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok79) {
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x140000}};
  int check = 1312613640;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok80) {
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80140000}};
  int check = -834870008;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok81) {
  my_decimal decimal = {{0x3D70A3D7, 0x70A3D70A, 0x43D70A3D, 0x130000}};
  int check = 1325025554;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok82) {
  my_decimal decimal = {{0x3D70A3D7, 0x70A3D70A, 0x43D70A3D, 0x80130000}};
  int check = -822458094;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok83) {
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x150000}};
  int check = 1284971936;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok84) {
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80150000}};
  int check = -862511712;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok85) {
  my_decimal decimal = {{0x3D70A3D7, 0x70A3D70A, 0x43D70A3D, 0x140000}};
  int check = 1296579188;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok86) {
  my_decimal decimal = {{0x3D70A3D7, 0x70A3D70A, 0x43D70A3D, 0x80140000}};
  int check = -850904460;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok87) {
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x160000}};
  int check = 1257359617;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok88) {
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80160000}};
  int check = -890124031;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok89) {
  my_decimal decimal = {{0x3D70A3D7, 0x70A3D70A, 0x43D70A3D, 0x150000}};
  int check = 1268788932;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok90) {
  my_decimal decimal = {{0x3D70A3D7, 0x70A3D70A, 0x43D70A3D, 0x80150000}};
  int check = -878694716;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok91) {
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x170000}};
  int check = 1229024666;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok92) {
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80170000}};
  int check = -918458982;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok93) {
  my_decimal decimal = {{0x3D70A3D7, 0x70A3D70A, 0x43D70A3D, 0x160000}};
  int check = 1241523561;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok94) {
  my_decimal decimal = {{0x3D70A3D7, 0x70A3D70A, 0x43D70A3D, 0x80160000}};
  int check = -905960087;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok95) {
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x180000}};
  int check = 1201323541;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok96) {
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80180000}};
  int check = -946160107;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok97) {
  my_decimal decimal = {{0x3D70A3D7, 0x70A3D70A, 0x43D70A3D, 0x170000}};
  int check = 1213008040;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok98) {
  my_decimal decimal = {{0x3D70A3D7, 0x70A3D70A, 0x43D70A3D, 0x80170000}};
  int check = -934475608;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok99) {
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x190000}};
  int check = 1173853832;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok100) {
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80190000}};
  int check = -973629816;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok101) {
  my_decimal decimal = {{0x3D70A3D7, 0x70A3D70A, 0x43D70A3D, 0x180000}};
  int check = 1185154797;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok102) {
  my_decimal decimal = {{0x3D70A3D7, 0x70A3D70A, 0x43D70A3D, 0x80180000}};
  int check = -962328851;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok103) {
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x1A0000}};
  int check = 1145442822;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok104) {
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x801A0000}};
  int check = -1002040826;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok105) {
  my_decimal decimal = {{0x3D70A3D7, 0x70A3D70A, 0x43D70A3D, 0x190000}};
  int check = 1157839038;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok106) {
  my_decimal decimal = {{0x3D70A3D7, 0x70A3D70A, 0x43D70A3D, 0x80190000}};
  int check = -989644610;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok107) {
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x1B0000}};
  int check = 1117680850;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok108) {
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x801B0000}};
  int check = -1029802798;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok109) {
  my_decimal decimal = {{0x3D70A3D7, 0x70A3D70A, 0x43D70A3D, 0x1A0000}};
  int check = 1129444451;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok110) {
  my_decimal decimal = {{0x3D70A3D7, 0x70A3D70A, 0x43D70A3D, 0x801A0000}};
  int check = -1018039197;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok111) {
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x1C0000}};
  int check = 1090357174;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok112) {
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x801C0000}};
  int check = -1057126474;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok113) {
  my_decimal decimal = {{0x3D70A3D7, 0x70A3D70A, 0x43D70A3D, 0x1B0000}};
  int check = 1101526709;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok114) {
  my_decimal decimal = {{0x3D70A3D7, 0x70A3D70A, 0x43D70A3D, 0x801B0000}};
  int check = -1045956939;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok115) {
  my_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  int check = 1870659584;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok116) {
  my_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  int check = -276824064;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok117) {
  my_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};
  int check = 1842138317;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok118) {
  my_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80010000}};
  int check = -305345331;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok119) {
  my_decimal decimal = {{0x3D70A3D7, 0x70A3D70A, 0x43D70A3D, 0x0}};
  int check = 1854385684;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok120) {
  my_decimal decimal = {{0x3D70A3D7, 0x70A3D70A, 0x43D70A3D, 0x80000000}};
  int check = -293097964;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok121) {
  my_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x20000}};
  int check = 1814288138;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok122) {
  my_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80020000}};
  int check = -333195510;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok123) {
  my_decimal decimal = {{0x3D70A3D7, 0x70A3D70A, 0x43D70A3D, 0x10000}};
  int check = 1826166407;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok124) {
  my_decimal decimal = {{0x3D70A3D7, 0x70A3D70A, 0x43D70A3D, 0x80010000}};
  int check = -321317241;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok125) {
  my_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x30000}};
  int check = 1786974831;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok126) {
  my_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80030000}};
  int check = -360508817;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok127) {
  my_decimal decimal = {{0x3D70A3D7, 0x70A3D70A, 0x43D70A3D, 0x20000}};
  int check = 1798155167;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok128) {
  my_decimal decimal = {{0x3D70A3D7, 0x70A3D70A, 0x43D70A3D, 0x80020000}};
  int check = -349328481;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok129) {
  my_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x40000}};
  int check = 1758574359;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok130) {
  my_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80040000}};
  int check = -388909289;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok131) {
  my_decimal decimal = {{0x3D70A3D7, 0x70A3D70A, 0x43D70A3D, 0x30000}};
  int check = 1770713011;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok132) {
  my_decimal decimal = {{0x3D70A3D7, 0x70A3D70A, 0x43D70A3D, 0x80030000}};
  int check = -376770637;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok133) {
  my_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x50000}};
  int check = 1730659756;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok134) {
  my_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80050000}};
  int check = -416823892;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok135) {
  my_decimal decimal = {{0x3D70A3D7, 0x70A3D70A, 0x43D70A3D, 0x40000}};
  int check = 1742621777;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok136) {
  my_decimal decimal = {{0x3D70A3D7, 0x70A3D70A, 0x43D70A3D, 0x80040000}};
  int check = -404861871;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok137) {
  my_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x60000}};
  int check = 1703294909;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok138) {
  my_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80060000}};
  int check = -444188739;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok139) {
  my_decimal decimal = {{0x3D70A3D7, 0x70A3D70A, 0x43D70A3D, 0x50000}};
  int check = 1714542247;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok140) {
  my_decimal decimal = {{0x3D70A3D7, 0x70A3D70A, 0x43D70A3D, 0x80050000}};
  int check = -432941401;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok141) {
  my_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x70000}};
  int check = 1675018133;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok142) {
  my_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80070000}};
  int check = -472465515;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok143) {
  my_decimal decimal = {{0x3D70A3D7, 0x70A3D70A, 0x43D70A3D, 0x60000}};
  int check = 1687045459;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok144) {
  my_decimal decimal = {{0x3D70A3D7, 0x70A3D70A, 0x43D70A3D, 0x80060000}};
  int check = -460438189;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok145) {
  my_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000}};
  int check = 1647037559;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok146) {
  my_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80080000}};
  int check = -500446089;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok147) {
  my_decimal decimal = {{0x3D70A3D7, 0x70A3D70A, 0x43D70A3D, 0x70000}};
  int check = 1659085342;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok148) {
  my_decimal decimal = {{0x3D70A3D7, 0x70A3D70A, 0x43D70A3D, 0x80070000}};
  int check = -488398306;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok149) {
  my_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x90000}};
  int check = 1619619935;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok150) {
  my_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80090000}};
  int check = -527863713;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok151) {
  my_decimal decimal = {{0x3D70A3D7, 0x70A3D70A, 0x43D70A3D, 0x80000}};
  int check = 1630935883;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok152) {
  my_decimal decimal = {{0x3D70A3D7, 0x70A3D70A, 0x43D70A3D, 0x80080000}};
  int check = -516547765;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok153) {
  my_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0xA0000}};
  int check = 1591469823;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok154) {
  my_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x800A0000}};
  int check = -556013825;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok155) {
  my_decimal decimal = {{0x3D70A3D7, 0x70A3D70A, 0x43D70A3D, 0x90000}};
  int check = 1603383151;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok156) {
  my_decimal decimal = {{0x3D70A3D7, 0x70A3D70A, 0x43D70A3D, 0x80090000}};
  int check = -544100497;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok157) {
  my_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0xB0000}};
  int check = 1563421695;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok158) {
  my_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x800B0000}};
  int check = -584061953;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok159) {
  my_decimal decimal = {{0x3D70A3D7, 0x70A3D70A, 0x43D70A3D, 0xA0000}};
  int check = 1575557298;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok160) {
  my_decimal decimal = {{0x3D70A3D7, 0x70A3D70A, 0x43D70A3D, 0x800A0000}};
  int check = -571926350;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok161) {
  my_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0xC0000}};
  int check = 1535950028;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok162) {
  my_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x800C0000}};
  int check = -611533620;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok163) {
  my_decimal decimal = {{0x3D70A3D7, 0x70A3D70A, 0x43D70A3D, 0xB0000}};
  int check = 1547336232;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok164) {
  my_decimal decimal = {{0x3D70A3D7, 0x70A3D70A, 0x43D70A3D, 0x800B0000}};
  int check = -600147416;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok165) {
  my_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0xD0000}};
  int check = 1507929619;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok166) {
  my_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x800D0000}};
  int check = -639554029;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok167) {
  my_decimal decimal = {{0x3D70A3D7, 0x70A3D70A, 0x43D70A3D, 0xC0000}};
  int check = 1519726214;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok168) {
  my_decimal decimal = {{0x3D70A3D7, 0x70A3D70A, 0x43D70A3D, 0x800C0000}};
  int check = -627757434;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok169) {
  my_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0xE0000}};
  int check = 1479812316;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok170) {
  my_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x800E0000}};
  int check = -667671332;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok171) {
  my_decimal decimal = {{0x3D70A3D7, 0x70A3D70A, 0x43D70A3D, 0xD0000}};
  int check = 1492037847;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok172) {
  my_decimal decimal = {{0x3D70A3D7, 0x70A3D70A, 0x43D70A3D, 0x800D0000}};
  int check = -655445801;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok173) {
  my_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0xF0000}};
  int check = 1452285309;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok174) {
  my_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x800F0000}};
  int check = -695198339;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok175) {
  my_decimal decimal = {{0x3D70A3D7, 0x70A3D70A, 0x43D70A3D, 0xE0000}};
  int check = 1463743455;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok176) {
  my_decimal decimal = {{0x3D70A3D7, 0x70A3D70A, 0x43D70A3D, 0x800E0000}};
  int check = -683740193;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok177) {
  my_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x100000}};
  int check = 1424397717;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok178) {
  my_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80100000}};
  int check = -723085931;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok179) {
  my_decimal decimal = {{0x3D70A3D7, 0x70A3D70A, 0x43D70A3D, 0xF0000}};
  int check = 1436074777;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok180) {
  my_decimal decimal = {{0x3D70A3D7, 0x70A3D70A, 0x43D70A3D, 0x800F0000}};
  int check = -711408871;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok181) {
  my_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x110000}};
  int check = 1396209578;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok182) {
  my_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80110000}};
  int check = -751274070;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok183) {
  my_decimal decimal = {{0x3D70A3D7, 0x70A3D70A, 0x43D70A3D, 0x100000}};
  int check = 1408527195;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok184) {
  my_decimal decimal = {{0x3D70A3D7, 0x70A3D70A, 0x43D70A3D, 0x80100000}};
  int check = -738956453;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok185) {
  my_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x120000}};
  int check = 1368625903;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok186) {
  my_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80120000}};
  int check = -778857745;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok187) {
  my_decimal decimal = {{0x3D70A3D7, 0x70A3D70A, 0x43D70A3D, 0x110000}};
  int check = 1380157718;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok188) {
  my_decimal decimal = {{0x3D70A3D7, 0x70A3D70A, 0x43D70A3D, 0x80110000}};
  int check = -767325930;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok189) {
  my_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x130000}};
  int check = 1340874314;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok190) {
  my_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80130000}};
  int check = -806609334;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok191) {
  my_decimal decimal = {{0x3D70A3D7, 0x70A3D70A, 0x43D70A3D, 0x120000}};
  int check = 1352428971;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok192) {
  my_decimal decimal = {{0x3D70A3D7, 0x70A3D70A, 0x43D70A3D, 0x80120000}};
  int check = -795054677;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok193) {
  my_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x140000}};
  int check = 1312613640;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok194) {
  my_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80140000}};
  int check = -834870008;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok195) {
  my_decimal decimal = {{0x3D70A3D7, 0x70A3D70A, 0x43D70A3D, 0x130000}};
  int check = 1325025554;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok196) {
  my_decimal decimal = {{0x3D70A3D7, 0x70A3D70A, 0x43D70A3D, 0x80130000}};
  int check = -822458094;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok197) {
  my_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x150000}};
  int check = 1284971936;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok198) {
  my_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80150000}};
  int check = -862511712;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok199) {
  my_decimal decimal = {{0x3D70A3D7, 0x70A3D70A, 0x43D70A3D, 0x140000}};
  int check = 1296579188;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok200) {
  my_decimal decimal = {{0x3D70A3D7, 0x70A3D70A, 0x43D70A3D, 0x80140000}};
  int check = -850904460;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok201) {
  my_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x160000}};
  int check = 1257359617;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok202) {
  my_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80160000}};
  int check = -890124031;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok203) {
  my_decimal decimal = {{0x3D70A3D7, 0x70A3D70A, 0x43D70A3D, 0x150000}};
  int check = 1268788932;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok204) {
  my_decimal decimal = {{0x3D70A3D7, 0x70A3D70A, 0x43D70A3D, 0x80150000}};
  int check = -878694716;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok205) {
  my_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x170000}};
  int check = 1229024666;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok206) {
  my_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80170000}};
  int check = -918458982;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok207) {
  my_decimal decimal = {{0x3D70A3D7, 0x70A3D70A, 0x43D70A3D, 0x160000}};
  int check = 1241523561;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok208) {
  my_decimal decimal = {{0x3D70A3D7, 0x70A3D70A, 0x43D70A3D, 0x80160000}};
  int check = -905960087;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok209) {
  my_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x180000}};
  int check = 1201323541;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok210) {
  my_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80180000}};
  int check = -946160107;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok211) {
  my_decimal decimal = {{0x3D70A3D7, 0x70A3D70A, 0x43D70A3D, 0x170000}};
  int check = 1213008040;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok212) {
  my_decimal decimal = {{0x3D70A3D7, 0x70A3D70A, 0x43D70A3D, 0x80170000}};
  int check = -934475608;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok213) {
  my_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x190000}};
  int check = 1173853832;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok214) {
  my_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x80190000}};
  int check = -973629816;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok215) {
  my_decimal decimal = {{0x3D70A3D7, 0x70A3D70A, 0x43D70A3D, 0x180000}};
  int check = 1185154797;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok216) {
  my_decimal decimal = {{0x3D70A3D7, 0x70A3D70A, 0x43D70A3D, 0x80180000}};
  int check = -962328851;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok217) {
  my_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x1A0000}};
  int check = 1145442822;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok218) {
  my_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x801A0000}};
  int check = -1002040826;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok219) {
  my_decimal decimal = {{0x3D70A3D7, 0x70A3D70A, 0x43D70A3D, 0x190000}};
  int check = 1157839038;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok220) {
  my_decimal decimal = {{0x3D70A3D7, 0x70A3D70A, 0x43D70A3D, 0x80190000}};
  int check = -989644610;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok221) {
  my_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x1B0000}};
  int check = 1117680850;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok222) {
  my_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x801B0000}};
  int check = -1029802798;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok223) {
  my_decimal decimal = {{0x3D70A3D7, 0x70A3D70A, 0x43D70A3D, 0x1A0000}};
  int check = 1129444451;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok224) {
  my_decimal decimal = {{0x3D70A3D7, 0x70A3D70A, 0x43D70A3D, 0x801A0000}};
  int check = -1018039197;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok225) {
  my_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x1C0000}};
  int check = 1090357174;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok226) {
  my_decimal decimal = {{0xFFFFFFFE, 0xFFFFFFFF, 0xFFFFFFFF, 0x801C0000}};
  int check = -1057126474;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok227) {
  my_decimal decimal = {{0x3D70A3D7, 0x70A3D70A, 0x43D70A3D, 0x1B0000}};
  int check = 1101526709;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok228) {
  my_decimal decimal = {{0x3D70A3D7, 0x70A3D70A, 0x43D70A3D, 0x801B0000}};
  int check = -1045956939;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok229) {
  my_decimal decimal = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x0}};
  int check = 1865067179;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok230) {
  my_decimal decimal = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x80000000}};
  int check = -282416469;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok231) {
  my_decimal decimal = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x10000}};
  int check = 1837664393;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok232) {
  my_decimal decimal = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x80010000}};
  int check = -309819255;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok233) {
  my_decimal decimal = {{0xD3A06D3A, 0xA06D3A06, 0x2D3A06D3, 0x0}};
  int check = 1848961051;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok234) {
  my_decimal decimal = {{0xD3A06D3A, 0xA06D3A06, 0x2D3A06D3, 0x80000000}};
  int check = -298522597;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok235) {
  my_decimal decimal = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x140000}};
  int check = 1308351499;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok236) {
  my_decimal decimal = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x80140000}};
  int check = -839132149;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok237) {
  my_decimal decimal = {{0xD3A06D3A, 0xA06D3A06, 0x2D3A06D3, 0x130000}};
  int check = 1319557985;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok238) {
  my_decimal decimal = {{0xD3A06D3A, 0xA06D3A06, 0x2D3A06D3, 0x80130000}};
  int check = -827925663;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok239) {
  my_decimal decimal = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x1C0000}};
  int check = 1084818724;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok240) {
  my_decimal decimal = {{0xAAAAAAAA, 0xAAAAAAAA, 0xAAAAAAAA, 0x801C0000}};
  int check = -1062664924;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok241) {
  my_decimal decimal = {{0xD3A06D3A, 0xA06D3A06, 0x2D3A06D3, 0x1B0000}};
  int check = 1096807324;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok242) {
  my_decimal decimal = {{0xD3A06D3A, 0xA06D3A06, 0x2D3A06D3, 0x801B0000}};
  int check = -1050676324;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok243) {
  my_decimal decimal = {{0x0, 0xAAAAAAAA, 0xAAAAAAAA, 0x0}};
  int check = 1865067179;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok244) {
  my_decimal decimal = {{0x0, 0xAAAAAAAA, 0xAAAAAAAA, 0x80000000}};
  int check = -282416469;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok245) {
  my_decimal decimal = {{0x0, 0xAAAAAAAA, 0xAAAAAAAA, 0x10000}};
  int check = 1837664393;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok246) {
  my_decimal decimal = {{0x0, 0xAAAAAAAA, 0xAAAAAAAA, 0x80010000}};
  int check = -309819255;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok247) {
  my_decimal decimal = {{0xA6666666, 0xA06D3A06, 0x2D3A06D3, 0x0}};
  int check = 1848961051;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok248) {
  my_decimal decimal = {{0xA6666666, 0xA06D3A06, 0x2D3A06D3, 0x80000000}};
  int check = -298522597;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok249) {
  my_decimal decimal = {{0x0, 0xAAAAAAAA, 0xAAAAAAAA, 0x140000}};
  int check = 1308351499;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok250) {
  my_decimal decimal = {{0x0, 0xAAAAAAAA, 0xAAAAAAAA, 0x80140000}};
  int check = -839132149;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok251) {
  my_decimal decimal = {{0xA6666666, 0xA06D3A06, 0x2D3A06D3, 0x130000}};
  int check = 1319557985;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok252) {
  my_decimal decimal = {{0xA6666666, 0xA06D3A06, 0x2D3A06D3, 0x80130000}};
  int check = -827925663;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok253) {
  my_decimal decimal = {{0x0, 0xAAAAAAAA, 0xAAAAAAAA, 0x1C0000}};
  int check = 1084818724;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok254) {
  my_decimal decimal = {{0x0, 0xAAAAAAAA, 0xAAAAAAAA, 0x801C0000}};
  int check = -1062664924;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok255) {
  my_decimal decimal = {{0xA6666666, 0xA06D3A06, 0x2D3A06D3, 0x1B0000}};
  int check = 1096807324;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok256) {
  my_decimal decimal = {{0xA6666666, 0xA06D3A06, 0x2D3A06D3, 0x801B0000}};
  int check = -1050676324;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok257) {
  my_decimal decimal = {{0xAAAAAAAA, 0x0, 0xAAAAAAAA, 0x0}};
  int check = 1865067179;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok258) {
  my_decimal decimal = {{0xAAAAAAAA, 0x0, 0xAAAAAAAA, 0x80000000}};
  int check = -282416469;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok259) {
  my_decimal decimal = {{0xAAAAAAAA, 0x0, 0xAAAAAAAA, 0x10000}};
  int check = 1837664393;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok260) {
  my_decimal decimal = {{0xAAAAAAAA, 0x0, 0xAAAAAAAA, 0x80010000}};
  int check = -309819255;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok261) {
  my_decimal decimal = {{0x606D3A07, 0x73333333, 0x2D3A06D3, 0x0}};
  int check = 1848961051;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok262) {
  my_decimal decimal = {{0x606D3A07, 0x73333333, 0x2D3A06D3, 0x80000000}};
  int check = -298522597;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok263) {
  my_decimal decimal = {{0xAAAAAAAA, 0x0, 0xAAAAAAAA, 0x140000}};
  int check = 1308351499;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok264) {
  my_decimal decimal = {{0xAAAAAAAA, 0x0, 0xAAAAAAAA, 0x80140000}};
  int check = -839132149;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok265) {
  my_decimal decimal = {{0x606D3A07, 0x73333333, 0x2D3A06D3, 0x130000}};
  int check = 1319557985;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok266) {
  my_decimal decimal = {{0x606D3A07, 0x73333333, 0x2D3A06D3, 0x80130000}};
  int check = -827925663;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok267) {
  my_decimal decimal = {{0xAAAAAAAA, 0x0, 0xAAAAAAAA, 0x1C0000}};
  int check = 1084818724;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok268) {
  my_decimal decimal = {{0xAAAAAAAA, 0x0, 0xAAAAAAAA, 0x801C0000}};
  int check = -1062664924;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok269) {
  my_decimal decimal = {{0x606D3A07, 0x73333333, 0x2D3A06D3, 0x1B0000}};
  int check = 1096807324;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok270) {
  my_decimal decimal = {{0x606D3A07, 0x73333333, 0x2D3A06D3, 0x801B0000}};
  int check = -1050676324;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok271) {
  my_decimal decimal = {{0x0, 0x0, 0xAAAAAAAA, 0x0}};
  int check = 1865067179;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok272) {
  my_decimal decimal = {{0x0, 0x0, 0xAAAAAAAA, 0x80000000}};
  int check = -282416469;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok273) {
  my_decimal decimal = {{0x0, 0x0, 0xAAAAAAAA, 0x10000}};
  int check = 1837664393;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok274) {
  my_decimal decimal = {{0x0, 0x0, 0xAAAAAAAA, 0x80010000}};
  int check = -309819255;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok275) {
  my_decimal decimal = {{0x33333333, 0x73333333, 0x2D3A06D3, 0x0}};
  int check = 1848961051;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok276) {
  my_decimal decimal = {{0x33333333, 0x73333333, 0x2D3A06D3, 0x80000000}};
  int check = -298522597;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok277) {
  my_decimal decimal = {{0x0, 0x0, 0xAAAAAAAA, 0x140000}};
  int check = 1308351499;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok278) {
  my_decimal decimal = {{0x0, 0x0, 0xAAAAAAAA, 0x80140000}};
  int check = -839132149;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok279) {
  my_decimal decimal = {{0x33333333, 0x73333333, 0x2D3A06D3, 0x130000}};
  int check = 1319557985;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok280) {
  my_decimal decimal = {{0x33333333, 0x73333333, 0x2D3A06D3, 0x80130000}};
  int check = -827925663;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok281) {
  my_decimal decimal = {{0x0, 0x0, 0xAAAAAAAA, 0x1C0000}};
  int check = 1084818724;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok282) {
  my_decimal decimal = {{0x0, 0x0, 0xAAAAAAAA, 0x801C0000}};
  int check = -1062664924;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok283) {
  my_decimal decimal = {{0x33333333, 0x73333333, 0x2D3A06D3, 0x1B0000}};
  int check = 1096807324;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok284) {
  my_decimal decimal = {{0x33333333, 0x73333333, 0x2D3A06D3, 0x801B0000}};
  int check = -1050676324;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok285) {
  my_decimal decimal = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x0}};
  int check = 1596631723;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok286) {
  my_decimal decimal = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x80000000}};
  int check = -550851925;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok287) {
  my_decimal decimal = {{0xAAAAA9FA, 0xAAAAAAAA, 0xB0, 0x20000}};
  int check = 1608655394;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok288) {
  my_decimal decimal = {{0xAAAAA9FA, 0xAAAAAAAA, 0xB0, 0x80020000}};
  int check = -538828254;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok289) {
  my_decimal decimal = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x10000}};
  int check = 1569228937;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok290) {
  my_decimal decimal = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x80010000}};
  int check = -578254711;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok291) {
  my_decimal decimal = {{0xAAAAA9FA, 0xAAAAAAAA, 0xB0, 0x30000}};
  int check = 1580525595;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok292) {
  my_decimal decimal = {{0xAAAAA9FA, 0xAAAAAAAA, 0xB0, 0x80030000}};
  int check = -566958053;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok293) {
  my_decimal decimal = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0xB0000}};
  int check = 1290440703;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok294) {
  my_decimal decimal = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x800B0000}};
  int check = -857042945;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok295) {
  my_decimal decimal = {{0xAAAAA9FA, 0xAAAAAAAA, 0xB0, 0xD0000}};
  int check = 1302029772;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok296) {
  my_decimal decimal = {{0xAAAAA9FA, 0xAAAAAAAA, 0xB0, 0x800D0000}};
  int check = -845453876;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok297) {
  my_decimal decimal = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x130000}};
  int check = 1067280775;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok298) {
  my_decimal decimal = {{0xAAAAAAAA, 0xAAAAAAAA, 0x0, 0x80130000}};
  int check = -1080202873;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok299) {
  my_decimal decimal = {{0xAAAAA9FA, 0xAAAAAAAA, 0xB0, 0x150000}};
  int check = 1079022137;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok300) {
  my_decimal decimal = {{0xAAAAA9FA, 0xAAAAAAAA, 0xB0, 0x80150000}};
  int check = -1068461511;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok301) {
  my_decimal decimal = {{0x0, 0xAAAAAAAA, 0x0, 0x0}};
  int check = 1596631723;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok302) {
  my_decimal decimal = {{0x0, 0xAAAAAAAA, 0x0, 0x80000000}};
  int check = -550851925;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok303) {
  my_decimal decimal = {{0x0, 0xAAAAA9FA, 0xB0, 0x20000}};
  int check = 1608655394;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok304) {
  my_decimal decimal = {{0x0, 0xAAAAA9FA, 0xB0, 0x80020000}};
  int check = -538828254;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok305) {
  my_decimal decimal = {{0x0, 0xAAAAAAAA, 0x0, 0x10000}};
  int check = 1569228937;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok306) {
  my_decimal decimal = {{0x0, 0xAAAAAAAA, 0x0, 0x80010000}};
  int check = -578254711;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok307) {
  my_decimal decimal = {{0x0, 0xAAAAA9FA, 0xB0, 0x30000}};
  int check = 1580525595;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok308) {
  my_decimal decimal = {{0x0, 0xAAAAA9FA, 0xB0, 0x80030000}};
  int check = -566958053;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok309) {
  my_decimal decimal = {{0x0, 0xAAAAAAAA, 0x0, 0xB0000}};
  int check = 1290440703;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok310) {
  my_decimal decimal = {{0x0, 0xAAAAAAAA, 0x0, 0x800B0000}};
  int check = -857042945;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok311) {
  my_decimal decimal = {{0x0, 0xAAAAA9FA, 0xB0, 0xD0000}};
  int check = 1302029772;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok312) {
  my_decimal decimal = {{0x0, 0xAAAAA9FA, 0xB0, 0x800D0000}};
  int check = -845453876;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok313) {
  my_decimal decimal = {{0x0, 0xAAAAAAAA, 0x0, 0x130000}};
  int check = 1067280775;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok314) {
  my_decimal decimal = {{0x0, 0xAAAAAAAA, 0x0, 0x80130000}};
  int check = -1080202873;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok315) {
  my_decimal decimal = {{0x0, 0xAAAAA9FA, 0xB0, 0x150000}};
  int check = 1079022137;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok316) {
  my_decimal decimal = {{0x0, 0xAAAAA9FA, 0xB0, 0x80150000}};
  int check = -1068461511;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok317) {
  my_decimal decimal = {{0xAAAAAAAA, 0x0, 0x0, 0x0}};
  int check = 1328196267;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok318) {
  my_decimal decimal = {{0xAAAAAAAA, 0x0, 0x0, 0x80000000}};
  int check = -819287381;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok319) {
  my_decimal decimal = {{0xAAAAA9FA, 0xB0, 0x0, 0x20000}};
  int check = 1340219938;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok320) {
  my_decimal decimal = {{0xAAAAA9FA, 0xB0, 0x0, 0x80020000}};
  int check = -807263710;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok321) {
  my_decimal decimal = {{0xAAAAAAAA, 0x0, 0x0, 0x10000}};
  int check = 1300793481;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok322) {
  my_decimal decimal = {{0xAAAAAAAA, 0x0, 0x0, 0x80010000}};
  int check = -846690167;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok323) {
  my_decimal decimal = {{0xAAAAA9FA, 0xB0, 0x0, 0x30000}};
  int check = 1312090139;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok324) {
  my_decimal decimal = {{0xAAAAA9FA, 0xB0, 0x0, 0x80030000}};
  int check = -835393509;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok325) {
  my_decimal decimal = {{0xAAAAAAAA, 0x0, 0x0, 0x40000}};
  int check = 1217122149;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok326) {
  my_decimal decimal = {{0xAAAAAAAA, 0x0, 0x0, 0x80040000}};
  int check = -930361499;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok327) {
  my_decimal decimal = {{0xAAAAA9FA, 0xB0, 0x0, 0x60000}};
  int check = 1228488601;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok328) {
  my_decimal decimal = {{0xAAAAA9FA, 0xB0, 0x0, 0x80060000}};
  int check = -918995047;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok329) {
  my_decimal decimal = {{0xAAAAAAAA, 0x0, 0x0, 0x90000}};
  int check = 1077362815;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok330) {
  my_decimal decimal = {{0xAAAAAAAA, 0x0, 0x0, 0x80090000}};
  int check = -1070120833;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok331) {
  my_decimal decimal = {{0xAAAAA9FA, 0xB0, 0x0, 0xB0000}};
  int check = 1089654543;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok332) {
  my_decimal decimal = {{0xAAAAA9FA, 0xB0, 0x0, 0x800B0000}};
  int check = -1057829105;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok333) {
  my_decimal decimal = {{0x55555555, 0x55555555, 0x55555555, 0x0}};
  int check = 1856678571;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok334) {
  my_decimal decimal = {{0x55555555, 0x55555555, 0x55555555, 0x80000000}};
  int check = -290805077;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok335) {
  my_decimal decimal = {{0x55555555, 0x55555555, 0x55555555, 0x10000}};
  int check = 1829275785;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok336) {
  my_decimal decimal = {{0x55555555, 0x55555555, 0x55555555, 0x80010000}};
  int check = -318207863;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok337) {
  my_decimal decimal = {{0x22222221, 0x22222222, 0xE2222222, 0x10000}};
  int check = 1840572443;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok338) {
  my_decimal decimal = {{0x22222221, 0x22222222, 0xE2222222, 0x80010000}};
  int check = -306911205;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok339) {
  my_decimal decimal = {{0x55555555, 0x55555555, 0x55555555, 0x140000}};
  int check = 1299962891;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok340) {
  my_decimal decimal = {{0x55555555, 0x55555555, 0x55555555, 0x80140000}};
  int check = -847520757;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok341) {
  my_decimal decimal = {{0x22222221, 0x22222222, 0xE2222222, 0x140000}};
  int check = 1311169377;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok342) {
  my_decimal decimal = {{0x22222221, 0x22222222, 0xE2222222, 0x80140000}};
  int check = -836314271;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok343) {
  my_decimal decimal = {{0x55555555, 0x55555555, 0x55555555, 0x1C0000}};
  int check = 1076430116;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok344) {
  my_decimal decimal = {{0x55555555, 0x55555555, 0x55555555, 0x801C0000}};
  int check = -1071053532;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok345) {
  my_decimal decimal = {{0x22222221, 0x22222222, 0xE2222222, 0x1C0000}};
  int check = 1088418716;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok346) {
  my_decimal decimal = {{0x22222221, 0x22222222, 0xE2222222, 0x801C0000}};
  int check = -1059064932;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok347) {
  my_decimal decimal = {{0x0, 0x55555555, 0x55555555, 0x0}};
  int check = 1856678571;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok348) {
  my_decimal decimal = {{0x0, 0x55555555, 0x55555555, 0x80000000}};
  int check = -290805077;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok349) {
  my_decimal decimal = {{0x40000000, 0x22222221, 0xE2222222, 0x0}};
  int check = 1868702242;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok350) {
  my_decimal decimal = {{0x40000000, 0x22222221, 0xE2222222, 0x80000000}};
  int check = -278781406;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok351) {
  my_decimal decimal = {{0x0, 0x55555555, 0x55555555, 0x10000}};
  int check = 1829275785;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok352) {
  my_decimal decimal = {{0x0, 0x55555555, 0x55555555, 0x80010000}};
  int check = -318207863;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok353) {
  my_decimal decimal = {{0x40000000, 0x22222221, 0xE2222222, 0x10000}};
  int check = 1840572443;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok354) {
  my_decimal decimal = {{0x40000000, 0x22222221, 0xE2222222, 0x80010000}};
  int check = -306911205;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok355) {
  my_decimal decimal = {{0x0, 0x55555555, 0x55555555, 0x140000}};
  int check = 1299962891;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok356) {
  my_decimal decimal = {{0x0, 0x55555555, 0x55555555, 0x80140000}};
  int check = -847520757;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok357) {
  my_decimal decimal = {{0x40000000, 0x22222221, 0xE2222222, 0x140000}};
  int check = 1311169377;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok358) {
  my_decimal decimal = {{0x40000000, 0x22222221, 0xE2222222, 0x80140000}};
  int check = -836314271;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok359) {
  my_decimal decimal = {{0x0, 0x55555555, 0x55555555, 0x1C0000}};
  int check = 1076430116;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok360) {
  my_decimal decimal = {{0x0, 0x55555555, 0x55555555, 0x801C0000}};
  int check = -1071053532;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok361) {
  my_decimal decimal = {{0x40000000, 0x22222221, 0xE2222222, 0x1C0000}};
  int check = 1088418716;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok362) {
  my_decimal decimal = {{0x40000000, 0x22222221, 0xE2222222, 0x801C0000}};
  int check = -1059064932;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok363) {
  my_decimal decimal = {{0x55555555, 0x0, 0x55555555, 0x0}};
  int check = 1856678571;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok364) {
  my_decimal decimal = {{0x55555555, 0x0, 0x55555555, 0x80000000}};
  int check = -290805077;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok365) {
  my_decimal decimal = {{0xE2222221, 0x40000000, 0xE2222221, 0x0}};
  int check = 1868702242;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok366) {
  my_decimal decimal = {{0xE2222221, 0x40000000, 0xE2222221, 0x80000000}};
  int check = -278781406;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok367) {
  my_decimal decimal = {{0x55555555, 0x0, 0x55555555, 0x10000}};
  int check = 1829275785;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok368) {
  my_decimal decimal = {{0x55555555, 0x0, 0x55555555, 0x80010000}};
  int check = -318207863;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok369) {
  my_decimal decimal = {{0xE2222221, 0x40000000, 0xE2222221, 0x10000}};
  int check = 1840572443;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok370) {
  my_decimal decimal = {{0xE2222221, 0x40000000, 0xE2222221, 0x80010000}};
  int check = -306911205;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok371) {
  my_decimal decimal = {{0x55555555, 0x0, 0x55555555, 0x140000}};
  int check = 1299962891;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok372) {
  my_decimal decimal = {{0x55555555, 0x0, 0x55555555, 0x80140000}};
  int check = -847520757;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok373) {
  my_decimal decimal = {{0xE2222221, 0x40000000, 0xE2222221, 0x140000}};
  int check = 1311169377;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok374) {
  my_decimal decimal = {{0xE2222221, 0x40000000, 0xE2222221, 0x80140000}};
  int check = -836314271;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok375) {
  my_decimal decimal = {{0x55555555, 0x0, 0x55555555, 0x1C0000}};
  int check = 1076430116;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok376) {
  my_decimal decimal = {{0x55555555, 0x0, 0x55555555, 0x801C0000}};
  int check = -1071053532;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok377) {
  my_decimal decimal = {{0xE2222221, 0x40000000, 0xE2222221, 0x1C0000}};
  int check = 1088418716;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok378) {
  my_decimal decimal = {{0xE2222221, 0x40000000, 0xE2222221, 0x801C0000}};
  int check = -1059064932;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok379) {
  my_decimal decimal = {{0x0, 0x0, 0x55555555, 0x0}};
  int check = 1856678571;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok380) {
  my_decimal decimal = {{0x0, 0x0, 0x55555555, 0x80000000}};
  int check = -290805077;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok381) {
  my_decimal decimal = {{0x0, 0x40000000, 0xE2222221, 0x0}};
  int check = 1868702242;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok382) {
  my_decimal decimal = {{0x0, 0x40000000, 0xE2222221, 0x80000000}};
  int check = -278781406;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok383) {
  my_decimal decimal = {{0x0, 0x0, 0x55555555, 0x10000}};
  int check = 1829275785;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok384) {
  my_decimal decimal = {{0x0, 0x0, 0x55555555, 0x80010000}};
  int check = -318207863;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok385) {
  my_decimal decimal = {{0x0, 0x40000000, 0xE2222221, 0x10000}};
  int check = 1840572443;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok386) {
  my_decimal decimal = {{0x0, 0x40000000, 0xE2222221, 0x80010000}};
  int check = -306911205;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok387) {
  my_decimal decimal = {{0x0, 0x0, 0x55555555, 0x140000}};
  int check = 1299962891;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok388) {
  my_decimal decimal = {{0x0, 0x0, 0x55555555, 0x80140000}};
  int check = -847520757;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok389) {
  my_decimal decimal = {{0x0, 0x40000000, 0xE2222221, 0x140000}};
  int check = 1311169377;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok390) {
  my_decimal decimal = {{0x0, 0x40000000, 0xE2222221, 0x80140000}};
  int check = -836314271;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok391) {
  my_decimal decimal = {{0x0, 0x0, 0x55555555, 0x1C0000}};
  int check = 1076430116;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok392) {
  my_decimal decimal = {{0x0, 0x0, 0x55555555, 0x801C0000}};
  int check = -1071053532;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok393) {
  my_decimal decimal = {{0x0, 0x40000000, 0xE2222221, 0x1C0000}};
  int check = 1088418716;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok394) {
  my_decimal decimal = {{0x0, 0x40000000, 0xE2222221, 0x801C0000}};
  int check = -1059064932;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok395) {
  my_decimal decimal = {{0x55555555, 0x55555555, 0x0, 0x0}};
  int check = 1588243115;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok396) {
  my_decimal decimal = {{0x55555555, 0x55555555, 0x0, 0x80000000}};
  int check = -559240533;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok397) {
  my_decimal decimal = {{0x555554FD, 0x55555555, 0x58, 0x20000}};
  int check = 1600266786;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok398) {
  my_decimal decimal = {{0x555554FD, 0x55555555, 0x58, 0x80020000}};
  int check = -547216862;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok399) {
  my_decimal decimal = {{0x55555555, 0x55555555, 0x0, 0x10000}};
  int check = 1560840329;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok400) {
  my_decimal decimal = {{0x55555555, 0x55555555, 0x0, 0x80010000}};
  int check = -586643319;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok401) {
  my_decimal decimal = {{0x555554FD, 0x55555555, 0x58, 0x30000}};
  int check = 1572136987;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok402) {
  my_decimal decimal = {{0x555554FD, 0x55555555, 0x58, 0x80030000}};
  int check = -575346661;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok403) {
  my_decimal decimal = {{0x55555555, 0x55555555, 0x0, 0xC0000}};
  int check = 1253811813;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok404) {
  my_decimal decimal = {{0x55555555, 0x55555555, 0x0, 0x800C0000}};
  int check = -893671835;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok405) {
  my_decimal decimal = {{0x555554FD, 0x55555555, 0x58, 0xE0000}};
  int check = 1266197216;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok406) {
  my_decimal decimal = {{0x555554FD, 0x55555555, 0x58, 0x800E0000}};
  int check = -881286432;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok407) {
  my_decimal decimal = {{0x55555555, 0x55555555, 0x0, 0x120000}};
  int check = 1086637033;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok408) {
  my_decimal decimal = {{0x55555555, 0x55555555, 0x0, 0x80120000}};
  int check = -1060846615;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok409) {
  my_decimal decimal = {{0x555554FD, 0x55555555, 0x58, 0x140000}};
  int check = 1099062116;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok410) {
  my_decimal decimal = {{0x555554FD, 0x55555555, 0x58, 0x80140000}};
  int check = -1048421532;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok411) {
  my_decimal decimal = {{0x0, 0x55555555, 0x0, 0x0}};
  int check = 1588243115;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok412) {
  my_decimal decimal = {{0x0, 0x55555555, 0x0, 0x80000000}};
  int check = -559240533;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok413) {
  my_decimal decimal = {{0x0, 0x555554FD, 0x58, 0x20000}};
  int check = 1600266786;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok414) {
  my_decimal decimal = {{0x0, 0x555554FD, 0x58, 0x80020000}};
  int check = -547216862;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok415) {
  my_decimal decimal = {{0x0, 0x55555555, 0x0, 0x10000}};
  int check = 1560840329;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok416) {
  my_decimal decimal = {{0x0, 0x55555555, 0x0, 0x80010000}};
  int check = -586643319;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok417) {
  my_decimal decimal = {{0x0, 0x555554FD, 0x58, 0x30000}};
  int check = 1572136987;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok418) {
  my_decimal decimal = {{0x0, 0x555554FD, 0x58, 0x80030000}};
  int check = -575346661;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok419) {
  my_decimal decimal = {{0x0, 0x55555555, 0x0, 0xC0000}};
  int check = 1253811813;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok420) {
  my_decimal decimal = {{0x0, 0x55555555, 0x0, 0x800C0000}};
  int check = -893671835;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok421) {
  my_decimal decimal = {{0x0, 0x555554FD, 0x58, 0xE0000}};
  int check = 1266197216;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok422) {
  my_decimal decimal = {{0x0, 0x555554FD, 0x58, 0x800E0000}};
  int check = -881286432;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok423) {
  my_decimal decimal = {{0x0, 0x55555555, 0x0, 0x120000}};
  int check = 1086637033;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok424) {
  my_decimal decimal = {{0x0, 0x55555555, 0x0, 0x80120000}};
  int check = -1060846615;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok425) {
  my_decimal decimal = {{0x0, 0x555554FD, 0x58, 0x140000}};
  int check = 1099062116;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok426) {
  my_decimal decimal = {{0x0, 0x555554FD, 0x58, 0x80140000}};
  int check = -1048421532;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok427) {
  my_decimal decimal = {{0x55555555, 0x0, 0x0, 0x0}};
  int check = 1319807659;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok428) {
  my_decimal decimal = {{0x55555555, 0x0, 0x0, 0x80000000}};
  int check = -827675989;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok429) {
  my_decimal decimal = {{0x555554FD, 0x58, 0x0, 0x20000}};
  int check = 1331831330;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok430) {
  my_decimal decimal = {{0x555554FD, 0x58, 0x0, 0x80020000}};
  int check = -815652318;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok431) {
  my_decimal decimal = {{0x55555555, 0x0, 0x0, 0x10000}};
  int check = 1292404873;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok432) {
  my_decimal decimal = {{0x55555555, 0x0, 0x0, 0x80010000}};
  int check = -855078775;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok433) {
  my_decimal decimal = {{0x555554FD, 0x58, 0x0, 0x30000}};
  int check = 1303701531;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok434) {
  my_decimal decimal = {{0x555554FD, 0x58, 0x0, 0x80030000}};
  int check = -843782117;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok435) {
  my_decimal decimal = {{0x55555555, 0x0, 0x0, 0x40000}};
  int check = 1208733541;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok436) {
  my_decimal decimal = {{0x55555555, 0x0, 0x0, 0x80040000}};
  int check = -938750107;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok437) {
  my_decimal decimal = {{0x555554FD, 0x58, 0x0, 0x60000}};
  int check = 1220099993;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok438) {
  my_decimal decimal = {{0x555554FD, 0x58, 0x0, 0x80060000}};
  int check = -927383655;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok439) {
  my_decimal decimal = {{0x55555555, 0x0, 0x0, 0x90000}};
  int check = 1068974207;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok440) {
  my_decimal decimal = {{0x55555555, 0x0, 0x0, 0x80090000}};
  int check = -1078509441;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok441) {
  my_decimal decimal = {{0x555554FD, 0x58, 0x0, 0xB0000}};
  int check = 1081265935;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok442) {
  my_decimal decimal = {{0x555554FD, 0x58, 0x0, 0x800B0000}};
  int check = -1066217713;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok443) {
  my_decimal decimal = {{0x1, 0x1, 0x1, 0x0}};
  int check = 1602224128;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok444) {
  my_decimal decimal = {{0x1, 0x1, 0x1, 0x80000000}};
  int check = -545259520;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok445) {
  my_decimal decimal = {{0x109, 0x109, 0x109, 0x20000}};
  int check = 1613339034;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok446) {
  my_decimal decimal = {{0x109, 0x109, 0x109, 0x80020000}};
  int check = -534144614;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok447) {
  my_decimal decimal = {{0x1, 0x1, 0x1, 0x10000}};
  int check = 1573702861;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok448) {
  my_decimal decimal = {{0x1, 0x1, 0x1, 0x80010000}};
  int check = -573780787;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok449) {
  my_decimal decimal = {{0x109, 0x109, 0x109, 0x30000}};
  int check = 1585950228;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok450) {
  my_decimal decimal = {{0x109, 0x109, 0x109, 0x80030000}};
  int check = -561533420;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok451) {
  my_decimal decimal = {{0x1, 0x1, 0x1, 0xB0000}};
  int check = 1294986239;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok452) {
  my_decimal decimal = {{0x1, 0x1, 0x1, 0x800B0000}};
  int check = -852497409;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok453) {
  my_decimal decimal = {{0x109, 0x109, 0x109, 0xD0000}};
  int check = 1307121842;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok454) {
  my_decimal decimal = {{0x109, 0x109, 0x109, 0x800D0000}};
  int check = -840361806;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok455) {
  my_decimal decimal = {{0x1, 0x1, 0x1, 0x130000}};
  int check = 1072438858;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok456) {
  my_decimal decimal = {{0x1, 0x1, 0x1, 0x80130000}};
  int check = -1075044790;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok457) {
  my_decimal decimal = {{0x109, 0x109, 0x109, 0x150000}};
  int check = 1083993515;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok458) {
  my_decimal decimal = {{0x109, 0x109, 0x109, 0x80150000}};
  int check = -1063490133;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok459) {
  my_decimal decimal = {{0x0, 0x1, 0x1, 0x0}};
  int check = 1602224128;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok460) {
  my_decimal decimal = {{0x0, 0x1, 0x1, 0x80000000}};
  int check = -545259520;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok461) {
  my_decimal decimal = {{0x0, 0x109, 0x109, 0x20000}};
  int check = 1613339034;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok462) {
  my_decimal decimal = {{0x0, 0x109, 0x109, 0x80020000}};
  int check = -534144614;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok463) {
  my_decimal decimal = {{0x0, 0x1, 0x1, 0x10000}};
  int check = 1573702861;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok464) {
  my_decimal decimal = {{0x0, 0x1, 0x1, 0x80010000}};
  int check = -573780787;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok465) {
  my_decimal decimal = {{0x0, 0x109, 0x109, 0x30000}};
  int check = 1585950228;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok466) {
  my_decimal decimal = {{0x0, 0x109, 0x109, 0x80030000}};
  int check = -561533420;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok467) {
  my_decimal decimal = {{0x0, 0x1, 0x1, 0xC0000}};
  int check = 1267514572;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok468) {
  my_decimal decimal = {{0x0, 0x1, 0x1, 0x800C0000}};
  int check = -879969076;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok469) {
  my_decimal decimal = {{0x0, 0x109, 0x109, 0xE0000}};
  int check = 1278900776;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok470) {
  my_decimal decimal = {{0x0, 0x109, 0x109, 0x800E0000}};
  int check = -868582872;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok471) {
  my_decimal decimal = {{0x0, 0x1, 0x1, 0x130000}};
  int check = 1072438858;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok472) {
  my_decimal decimal = {{0x0, 0x1, 0x1, 0x80130000}};
  int check = -1075044790;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok473) {
  my_decimal decimal = {{0x0, 0x109, 0x109, 0x150000}};
  int check = 1083993515;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok474) {
  my_decimal decimal = {{0x0, 0x109, 0x109, 0x80150000}};
  int check = -1063490133;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok475) {
  my_decimal decimal = {{0x1, 0x0, 0x1, 0x0}};
  int check = 1602224128;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok476) {
  my_decimal decimal = {{0x1, 0x0, 0x1, 0x80000000}};
  int check = -545259520;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok477) {
  my_decimal decimal = {{0x109, 0x0, 0x109, 0x20000}};
  int check = 1613339034;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok478) {
  my_decimal decimal = {{0x109, 0x0, 0x109, 0x80020000}};
  int check = -534144614;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok479) {
  my_decimal decimal = {{0x1, 0x0, 0x1, 0x10000}};
  int check = 1573702861;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok480) {
  my_decimal decimal = {{0x1, 0x0, 0x1, 0x80010000}};
  int check = -573780787;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok481) {
  my_decimal decimal = {{0x109, 0x0, 0x109, 0x30000}};
  int check = 1585950228;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok482) {
  my_decimal decimal = {{0x109, 0x0, 0x109, 0x80030000}};
  int check = -561533420;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok483) {
  my_decimal decimal = {{0x1, 0x0, 0x1, 0xD0000}};
  int check = 1239494163;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok484) {
  my_decimal decimal = {{0x1, 0x0, 0x1, 0x800D0000}};
  int check = -907989485;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok485) {
  my_decimal decimal = {{0x109, 0x0, 0x109, 0xF0000}};
  int check = 1251290758;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok486) {
  my_decimal decimal = {{0x109, 0x0, 0x109, 0x800F0000}};
  int check = -896192890;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok487) {
  my_decimal decimal = {{0x1, 0x0, 0x1, 0x130000}};
  int check = 1072438858;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok488) {
  my_decimal decimal = {{0x1, 0x0, 0x1, 0x80130000}};
  int check = -1075044790;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok489) {
  my_decimal decimal = {{0x109, 0x0, 0x109, 0x150000}};
  int check = 1083993515;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok490) {
  my_decimal decimal = {{0x109, 0x0, 0x109, 0x80150000}};
  int check = -1063490133;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok491) {
  my_decimal decimal = {{0x0, 0x0, 0x1, 0x0}};
  int check = 1602224128;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok492) {
  my_decimal decimal = {{0x0, 0x0, 0x1, 0x80000000}};
  int check = -545259520;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok493) {
  my_decimal decimal = {{0x0, 0x0, 0x109, 0x20000}};
  int check = 1613339034;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok494) {
  my_decimal decimal = {{0x0, 0x0, 0x109, 0x80020000}};
  int check = -534144614;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok495) {
  my_decimal decimal = {{0x0, 0x0, 0x1, 0x10000}};
  int check = 1573702861;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok496) {
  my_decimal decimal = {{0x0, 0x0, 0x1, 0x80010000}};
  int check = -573780787;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok497) {
  my_decimal decimal = {{0x0, 0x0, 0x109, 0x30000}};
  int check = 1585950228;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok498) {
  my_decimal decimal = {{0x0, 0x0, 0x109, 0x80030000}};
  int check = -561533420;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok499) {
  my_decimal decimal = {{0x0, 0x0, 0x1, 0xE0000}};
  int check = 1211376860;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok500) {
  my_decimal decimal = {{0x0, 0x0, 0x1, 0x800E0000}};
  int check = -936106788;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok501) {
  my_decimal decimal = {{0x0, 0x0, 0x109, 0x100000}};
  int check = 1223602391;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok502) {
  my_decimal decimal = {{0x0, 0x0, 0x109, 0x80100000}};
  int check = -923881257;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok503) {
  my_decimal decimal = {{0x0, 0x0, 0x1, 0x130000}};
  int check = 1072438858;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok504) {
  my_decimal decimal = {{0x0, 0x0, 0x1, 0x80130000}};
  int check = -1075044790;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok505) {
  my_decimal decimal = {{0x0, 0x0, 0x109, 0x150000}};
  int check = 1083993515;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok506) {
  my_decimal decimal = {{0x0, 0x0, 0x109, 0x80150000}};
  int check = -1063490133;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok507) {
  my_decimal decimal = {{0x1, 0x1, 0x0, 0x0}};
  int check = 1333788672;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok508) {
  my_decimal decimal = {{0x1, 0x1, 0x0, 0x80000000}};
  int check = -813694976;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok509) {
  my_decimal decimal = {{0x109, 0x109, 0x0, 0x20000}};
  int check = 1344903578;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok510) {
  my_decimal decimal = {{0x109, 0x109, 0x0, 0x80020000}};
  int check = -802580070;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok511) {
  my_decimal decimal = {{0x1, 0x1, 0x0, 0x10000}};
  int check = 1305267405;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok512) {
  my_decimal decimal = {{0x1, 0x1, 0x0, 0x80010000}};
  int check = -842216243;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok513) {
  my_decimal decimal = {{0x109, 0x109, 0x0, 0x30000}};
  int check = 1317514772;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok514) {
  my_decimal decimal = {{0x109, 0x109, 0x0, 0x80030000}};
  int check = -829968876;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok515) {
  my_decimal decimal = {{0x1, 0x1, 0x0, 0x20000}};
  int check = 1277417226;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok516) {
  my_decimal decimal = {{0x1, 0x1, 0x0, 0x80020000}};
  int check = -870066422;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok517) {
  my_decimal decimal = {{0x109, 0x109, 0x0, 0x40000}};
  int check = 1289295495;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok518) {
  my_decimal decimal = {{0x109, 0x109, 0x0, 0x80040000}};
  int check = -858188153;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok519) {
  my_decimal decimal = {{0x1, 0x1, 0x0, 0x40000}};
  int check = 1221703447;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok520) {
  my_decimal decimal = {{0x1, 0x1, 0x0, 0x80040000}};
  int check = -925780201;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok521) {
  my_decimal decimal = {{0x109, 0x109, 0x0, 0x60000}};
  int check = 1233842099;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok522) {
  my_decimal decimal = {{0x109, 0x109, 0x0, 0x80060000}};
  int check = -913641549;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok523) {
  my_decimal decimal = {{0x1, 0x1, 0x0, 0x90000}};
  int check = 1082749023;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok524) {
  my_decimal decimal = {{0x1, 0x1, 0x0, 0x80090000}};
  int check = -1064734625;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok525) {
  my_decimal decimal = {{0x109, 0x109, 0x0, 0xB0000}};
  int check = 1094064971;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok526) {
  my_decimal decimal = {{0x109, 0x109, 0x0, 0x800B0000}};
  int check = -1053418677;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok527) {
  my_decimal decimal = {{0x1, 0x1, 0x0, 0x80000}};
  int check = 1110166647;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok528) {
  my_decimal decimal = {{0x1, 0x1, 0x0, 0x80080000}};
  int check = -1037317001;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok529) {
  my_decimal decimal = {{0x109, 0x109, 0x0, 0xA0000}};
  int check = 1122214430;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok530) {
  my_decimal decimal = {{0x109, 0x109, 0x0, 0x800A0000}};
  int check = -1025269218;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok531) {
  my_decimal decimal = {{0x0, 0x1, 0x0, 0x0}};
  int check = 1333788672;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok532) {
  my_decimal decimal = {{0x0, 0x1, 0x0, 0x80000000}};
  int check = -813694976;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok533) {
  my_decimal decimal = {{0x0, 0x109, 0x0, 0x20000}};
  int check = 1344903578;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok534) {
  my_decimal decimal = {{0x0, 0x109, 0x0, 0x80020000}};
  int check = -802580070;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok535) {
  my_decimal decimal = {{0x0, 0x1, 0x0, 0x10000}};
  int check = 1305267405;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok536) {
  my_decimal decimal = {{0x0, 0x1, 0x0, 0x80010000}};
  int check = -842216243;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok537) {
  my_decimal decimal = {{0x0, 0x109, 0x0, 0x30000}};
  int check = 1317514772;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok538) {
  my_decimal decimal = {{0x0, 0x109, 0x0, 0x80030000}};
  int check = -829968876;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok539) {
  my_decimal decimal = {{0x0, 0x1, 0x0, 0x20000}};
  int check = 1277417226;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok540) {
  my_decimal decimal = {{0x0, 0x1, 0x0, 0x80020000}};
  int check = -870066422;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok541) {
  my_decimal decimal = {{0x0, 0x109, 0x0, 0x40000}};
  int check = 1289295495;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok542) {
  my_decimal decimal = {{0x0, 0x109, 0x0, 0x80040000}};
  int check = -858188153;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok543) {
  my_decimal decimal = {{0x0, 0x1, 0x0, 0x30000}};
  int check = 1250103919;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok544) {
  my_decimal decimal = {{0x0, 0x1, 0x0, 0x80030000}};
  int check = -897379729;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok545) {
  my_decimal decimal = {{0x0, 0x109, 0x0, 0x50000}};
  int check = 1261284255;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok546) {
  my_decimal decimal = {{0x0, 0x109, 0x0, 0x80050000}};
  int check = -886199393;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok547) {
  my_decimal decimal = {{0x0, 0x1, 0x0, 0x90000}};
  int check = 1082749023;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok548) {
  my_decimal decimal = {{0x0, 0x1, 0x0, 0x80090000}};
  int check = -1064734625;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok549) {
  my_decimal decimal = {{0x0, 0x109, 0x0, 0xB0000}};
  int check = 1094064971;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok550) {
  my_decimal decimal = {{0x0, 0x109, 0x0, 0x800B0000}};
  int check = -1053418677;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok551) {
  my_decimal decimal = {{0x0, 0x1, 0x0, 0x80000}};
  int check = 1110166647;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok552) {
  my_decimal decimal = {{0x0, 0x1, 0x0, 0x80080000}};
  int check = -1037317001;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok553) {
  my_decimal decimal = {{0x0, 0x109, 0x0, 0xA0000}};
  int check = 1122214430;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok554) {
  my_decimal decimal = {{0x0, 0x109, 0x0, 0x800A0000}};
  int check = -1025269218;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok555) {
  my_decimal decimal = {{0x1, 0x0, 0x0, 0x10000}};
  int check = 1036831949;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok556) {
  my_decimal decimal = {{0x1, 0x0, 0x0, 0x80010000}};
  int check = -1110651699;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok557) {
  my_decimal decimal = {{0x109, 0x0, 0x0, 0x30000}};
  int check = 1049079316;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok558) {
  my_decimal decimal = {{0x109, 0x0, 0x0, 0x80030000}};
  int check = -1098404332;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok559) {
  my_decimal decimal = {{0x1, 0x0, 0x0, 0xD0000}};
  int check = 702623251;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok560) {
  my_decimal decimal = {{0x1, 0x0, 0x0, 0x800D0000}};
  int check = -1444860397;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok561) {
  my_decimal decimal = {{0x109, 0x0, 0x0, 0xF0000}};
  int check = 714419846;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok562) {
  my_decimal decimal = {{0x109, 0x0, 0x0, 0x800F0000}};
  int check = -1433063802;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok563) {
  my_decimal decimal = {{0x1, 0x0, 0x0, 0xE0000}};
  int check = 674505948;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok564) {
  my_decimal decimal = {{0x1, 0x0, 0x0, 0x800E0000}};
  int check = -1472977700;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok565) {
  my_decimal decimal = {{0x109, 0x0, 0x0, 0x100000}};
  int check = 686731479;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok566) {
  my_decimal decimal = {{0x109, 0x0, 0x0, 0x80100000}};
  int check = -1460752169;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok567) {
  my_decimal decimal = {{0x1, 0x0, 0x0, 0x1B0000}};
  int check = 312374482;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok568) {
  my_decimal decimal = {{0x1, 0x0, 0x0, 0x801B0000}};
  int check = -1835109166;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok569) {
  my_decimal decimal = {{0x1A, 0x0, 0x0, 0x1C0000}};
  int check = 323878468;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok570) {
  my_decimal decimal = {{0x1A, 0x0, 0x0, 0x801C0000}};
  int check = -1823605180;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok571) {
  my_decimal decimal = {{0x1, 0x0, 0x0, 0x1C0000}};
  int check = 285050806;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok572) {
  my_decimal decimal = {{0x1, 0x0, 0x0, 0x801C0000}};
  int check = -1862432842;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok573) {
  my_decimal decimal = {{0x3, 0x0, 0x0, 0x1C0000}};
  int check = 297674184;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok574) {
  my_decimal decimal = {{0x3, 0x0, 0x0, 0x801C0000}};
  int check = -1849809464;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok575) {
  my_decimal decimal = {{0x80000000, 0x80000000, 0x80000000, 0x0}};
  int check = 1862270976;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok576) {
  my_decimal decimal = {{0x80000000, 0x80000000, 0x80000000, 0x80000000}};
  int check = -285212672;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok577) {
  my_decimal decimal = {{0x80000000, 0x80000000, 0x80000000, 0x10000}};
  int check = 1833749709;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok578) {
  my_decimal decimal = {{0x80000000, 0x80000000, 0x80000000, 0x80010000}};
  int check = -313733939;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok579) {
  my_decimal decimal = {{0xF8F5C28F, 0xDA3D70A3, 0x21EB851E, 0x0}};
  int check = 1845997076;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok580) {
  my_decimal decimal = {{0xF8F5C28F, 0xDA3D70A3, 0x21EB851E, 0x80000000}};
  int check = -301486572;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok581) {
  my_decimal decimal = {{0x80000000, 0x80000000, 0x80000000, 0x140000}};
  int check = 1304225032;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok582) {
  my_decimal decimal = {{0x80000000, 0x80000000, 0x80000000, 0x80140000}};
  int check = -843258616;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok583) {
  my_decimal decimal = {{0xF8F5C28F, 0xDA3D70A3, 0x21EB851E, 0x130000}};
  int check = 1316636946;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok584) {
  my_decimal decimal = {{0xF8F5C28F, 0xDA3D70A3, 0x21EB851E, 0x80130000}};
  int check = -830846702;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok585) {
  my_decimal decimal = {{0x80000000, 0x80000000, 0x80000000, 0x1C0000}};
  int check = 1081968566;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok586) {
  my_decimal decimal = {{0x80000000, 0x80000000, 0x80000000, 0x801C0000}};
  int check = -1065515082;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok587) {
  my_decimal decimal = {{0xF8F5C28F, 0xDA3D70A3, 0x21EB851E, 0x1B0000}};
  int check = 1093138101;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok588) {
  my_decimal decimal = {{0xF8F5C28F, 0xDA3D70A3, 0x21EB851E, 0x801B0000}};
  int check = -1054345547;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok589) {
  my_decimal decimal = {{0x0, 0x80000000, 0x80000000, 0x0}};
  int check = 1862270976;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok590) {
  my_decimal decimal = {{0x0, 0x80000000, 0x80000000, 0x80000000}};
  int check = -285212672;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok591) {
  my_decimal decimal = {{0x0, 0x80000000, 0x80000000, 0x10000}};
  int check = 1833749709;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok592) {
  my_decimal decimal = {{0x0, 0x80000000, 0x80000000, 0x80010000}};
  int check = -313733939;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok593) {
  my_decimal decimal = {{0xD70A3D71, 0xDA3D70A3, 0x21EB851E, 0x0}};
  int check = 1845997076;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok594) {
  my_decimal decimal = {{0xD70A3D71, 0xDA3D70A3, 0x21EB851E, 0x80000000}};
  int check = -301486572;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok595) {
  my_decimal decimal = {{0x0, 0x80000000, 0x80000000, 0x150000}};
  int check = 1276583328;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok596) {
  my_decimal decimal = {{0x0, 0x80000000, 0x80000000, 0x80150000}};
  int check = -870900320;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok597) {
  my_decimal decimal = {{0xD70A3D71, 0xDA3D70A3, 0x21EB851E, 0x140000}};
  int check = 1288190580;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok598) {
  my_decimal decimal = {{0xD70A3D71, 0xDA3D70A3, 0x21EB851E, 0x80140000}};
  int check = -859293068;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok599) {
  my_decimal decimal = {{0x0, 0x80000000, 0x80000000, 0x1C0000}};
  int check = 1081968566;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok600) {
  my_decimal decimal = {{0x0, 0x80000000, 0x80000000, 0x801C0000}};
  int check = -1065515082;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok601) {
  my_decimal decimal = {{0xD70A3D71, 0xDA3D70A3, 0x21EB851E, 0x1B0000}};
  int check = 1093138101;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok602) {
  my_decimal decimal = {{0xD70A3D71, 0xDA3D70A3, 0x21EB851E, 0x801B0000}};
  int check = -1054345547;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok603) {
  my_decimal decimal = {{0x80000000, 0x0, 0x80000000, 0x0}};
  int check = 1862270976;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok604) {
  my_decimal decimal = {{0x80000000, 0x0, 0x80000000, 0x80000000}};
  int check = -285212672;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok605) {
  my_decimal decimal = {{0x80000000, 0x0, 0x80000000, 0x10000}};
  int check = 1833749709;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok606) {
  my_decimal decimal = {{0x80000000, 0x0, 0x80000000, 0x80010000}};
  int check = -313733939;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok607) {
  my_decimal decimal = {{0x40A3D70A, 0xB851EB85, 0x21EB851E, 0x0}};
  int check = 1845997076;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok608) {
  my_decimal decimal = {{0x40A3D70A, 0xB851EB85, 0x21EB851E, 0x80000000}};
  int check = -301486572;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok609) {
  my_decimal decimal = {{0x80000000, 0x0, 0x80000000, 0x160000}};
  int check = 1248971009;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok610) {
  my_decimal decimal = {{0x80000000, 0x0, 0x80000000, 0x80160000}};
  int check = -898512639;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok611) {
  my_decimal decimal = {{0x40A3D70A, 0xB851EB85, 0x21EB851E, 0x150000}};
  int check = 1260400324;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok612) {
  my_decimal decimal = {{0x40A3D70A, 0xB851EB85, 0x21EB851E, 0x80150000}};
  int check = -887083324;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok613) {
  my_decimal decimal = {{0x80000000, 0x0, 0x80000000, 0x1C0000}};
  int check = 1081968566;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok614) {
  my_decimal decimal = {{0x80000000, 0x0, 0x80000000, 0x801C0000}};
  int check = -1065515082;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok615) {
  my_decimal decimal = {{0x40A3D70A, 0xB851EB85, 0x21EB851E, 0x1B0000}};
  int check = 1093138101;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok616) {
  my_decimal decimal = {{0x40A3D70A, 0xB851EB85, 0x21EB851E, 0x801B0000}};
  int check = -1054345547;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok617) {
  my_decimal decimal = {{0x0, 0x0, 0x80000000, 0x0}};
  int check = 1862270976;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok618) {
  my_decimal decimal = {{0x0, 0x0, 0x80000000, 0x80000000}};
  int check = -285212672;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok619) {
  my_decimal decimal = {{0x0, 0x0, 0x80000000, 0x10000}};
  int check = 1833749709;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok620) {
  my_decimal decimal = {{0x0, 0x0, 0x80000000, 0x80010000}};
  int check = -313733939;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok621) {
  my_decimal decimal = {{0x1EB851EC, 0xB851EB85, 0x21EB851E, 0x0}};
  int check = 1845997076;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok622) {
  my_decimal decimal = {{0x1EB851EC, 0xB851EB85, 0x21EB851E, 0x80000000}};
  int check = -301486572;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok623) {
  my_decimal decimal = {{0x0, 0x0, 0x80000000, 0x170000}};
  int check = 1220636058;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok624) {
  my_decimal decimal = {{0x0, 0x0, 0x80000000, 0x80170000}};
  int check = -926847590;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok625) {
  my_decimal decimal = {{0x1EB851EC, 0xB851EB85, 0x21EB851E, 0x160000}};
  int check = 1233134953;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok626) {
  my_decimal decimal = {{0x1EB851EC, 0xB851EB85, 0x21EB851E, 0x80160000}};
  int check = -914348695;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok627) {
  my_decimal decimal = {{0x0, 0x0, 0x80000000, 0x1C0000}};
  int check = 1081968566;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok628) {
  my_decimal decimal = {{0x0, 0x0, 0x80000000, 0x801C0000}};
  int check = -1065515082;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok629) {
  my_decimal decimal = {{0x1EB851EC, 0xB851EB85, 0x21EB851E, 0x1B0000}};
  int check = 1093138101;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok630) {
  my_decimal decimal = {{0x1EB851EC, 0xB851EB85, 0x21EB851E, 0x801B0000}};
  int check = -1054345547;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok631) {
  my_decimal decimal = {{0x80000000, 0x80000000, 0x0, 0x0}};
  int check = 1593835520;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok632) {
  my_decimal decimal = {{0x80000000, 0x80000000, 0x0, 0x80000000}};
  int check = -553648128;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok633) {
  my_decimal decimal = {{0x80000000, 0x80000084, 0x84, 0x20000}};
  int check = 1604950426;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok634) {
  my_decimal decimal = {{0x80000000, 0x80000084, 0x84, 0x80020000}};
  int check = -542533222;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok635) {
  my_decimal decimal = {{0x80000000, 0x80000000, 0x0, 0x10000}};
  int check = 1565314253;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok636) {
  my_decimal decimal = {{0x80000000, 0x80000000, 0x0, 0x80010000}};
  int check = -582169395;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok637) {
  my_decimal decimal = {{0x80000000, 0x80000084, 0x84, 0x30000}};
  int check = 1577561620;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok638) {
  my_decimal decimal = {{0x80000000, 0x80000084, 0x84, 0x80030000}};
  int check = -569922028;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok639) {
  my_decimal decimal = {{0x80000000, 0x80000000, 0x0, 0xA0000}};
  int check = 1314645759;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok640) {
  my_decimal decimal = {{0x80000000, 0x80000000, 0x0, 0x800A0000}};
  int check = -832837889;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok641) {
  my_decimal decimal = {{0x80000000, 0x80000084, 0x84, 0xC0000}};
  int check = 1326559087;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok642) {
  my_decimal decimal = {{0x80000000, 0x80000084, 0x84, 0x800C0000}};
  int check = -820924561;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok643) {
  my_decimal decimal = {{0x80000000, 0x80000000, 0x0, 0x120000}};
  int check = 1091801839;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok644) {
  my_decimal decimal = {{0x80000000, 0x80000000, 0x0, 0x80120000}};
  int check = -1055681809;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok645) {
  my_decimal decimal = {{0x80000000, 0x80000084, 0x84, 0x140000}};
  int check = 1103333654;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok646) {
  my_decimal decimal = {{0x80000000, 0x80000084, 0x84, 0x80140000}};
  int check = -1044149994;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok647) {
  my_decimal decimal = {{0x0, 0x80000000, 0x0, 0x0}};
  int check = 1593835520;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok648) {
  my_decimal decimal = {{0x0, 0x80000000, 0x0, 0x80000000}};
  int check = -553648128;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok649) {
  my_decimal decimal = {{0x0, 0x80000000, 0x84, 0x20000}};
  int check = 1604950426;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok650) {
  my_decimal decimal = {{0x0, 0x80000000, 0x84, 0x80020000}};
  int check = -542533222;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok651) {
  my_decimal decimal = {{0x0, 0x80000000, 0x0, 0x10000}};
  int check = 1565314253;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok652) {
  my_decimal decimal = {{0x0, 0x80000000, 0x0, 0x80010000}};
  int check = -582169395;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok653) {
  my_decimal decimal = {{0x0, 0x80000000, 0x84, 0x30000}};
  int check = 1577561620;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok654) {
  my_decimal decimal = {{0x0, 0x80000000, 0x84, 0x80030000}};
  int check = -569922028;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok655) {
  my_decimal decimal = {{0x0, 0x80000000, 0x0, 0xB0000}};
  int check = 1286597631;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok656) {
  my_decimal decimal = {{0x0, 0x80000000, 0x0, 0x800B0000}};
  int check = -860886017;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok657) {
  my_decimal decimal = {{0x0, 0x80000000, 0x84, 0xD0000}};
  int check = 1298733234;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok658) {
  my_decimal decimal = {{0x0, 0x80000000, 0x84, 0x800D0000}};
  int check = -848750414;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok659) {
  my_decimal decimal = {{0x0, 0x80000000, 0x0, 0x120000}};
  int check = 1091801839;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok660) {
  my_decimal decimal = {{0x0, 0x80000000, 0x0, 0x80120000}};
  int check = -1055681809;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok661) {
  my_decimal decimal = {{0x0, 0x80000000, 0x84, 0x140000}};
  int check = 1103333654;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok662) {
  my_decimal decimal = {{0x0, 0x80000000, 0x84, 0x80140000}};
  int check = -1044149994;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok663) {
  my_decimal decimal = {{0x80000000, 0x0, 0x0, 0x0}};
  int check = 1325400064;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok664) {
  my_decimal decimal = {{0x80000000, 0x0, 0x0, 0x80000000}};
  int check = -822083584;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok665) {
  my_decimal decimal = {{0x80000000, 0x84, 0x0, 0x20000}};
  int check = 1336514970;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok666) {
  my_decimal decimal = {{0x80000000, 0x84, 0x0, 0x80020000}};
  int check = -810968678;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok667) {
  my_decimal decimal = {{0x80000000, 0x0, 0x0, 0x10000}};
  int check = 1296878797;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok668) {
  my_decimal decimal = {{0x80000000, 0x0, 0x0, 0x80010000}};
  int check = -850604851;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok669) {
  my_decimal decimal = {{0x80000000, 0x84, 0x0, 0x30000}};
  int check = 1309126164;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok670) {
  my_decimal decimal = {{0x80000000, 0x84, 0x0, 0x80030000}};
  int check = -838357484;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok671) {
  my_decimal decimal = {{0x80000000, 0x0, 0x0, 0x20000}};
  int check = 1269028618;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok672) {
  my_decimal decimal = {{0x80000000, 0x0, 0x0, 0x80020000}};
  int check = -878455030;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok673) {
  my_decimal decimal = {{0x80000000, 0x84, 0x0, 0x40000}};
  int check = 1280906887;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok674) {
  my_decimal decimal = {{0x80000000, 0x84, 0x0, 0x80040000}};
  int check = -866576761;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok675) {
  my_decimal decimal = {{0x80000000, 0x0, 0x0, 0x40000}};
  int check = 1213314839;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok676) {
  my_decimal decimal = {{0x80000000, 0x0, 0x0, 0x80040000}};
  int check = -934168809;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok677) {
  my_decimal decimal = {{0x80000000, 0x84, 0x0, 0x60000}};
  int check = 1225453491;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok678) {
  my_decimal decimal = {{0x80000000, 0x84, 0x0, 0x80060000}};
  int check = -922030157;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok679) {
  my_decimal decimal = {{0x80000000, 0x0, 0x0, 0x80000}};
  int check = 1101778039;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok680) {
  my_decimal decimal = {{0x80000000, 0x0, 0x0, 0x80080000}};
  int check = -1045705609;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok681) {
  my_decimal decimal = {{0x80000000, 0x84, 0x0, 0xA0000}};
  int check = 1113825822;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok682) {
  my_decimal decimal = {{0x80000000, 0x84, 0x0, 0x800A0000}};
  int check = -1033657826;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok683) {
  my_decimal decimal = {{0x80000000, 0x0, 0x0, 0x90000}};
  int check = 1074360415;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok684) {
  my_decimal decimal = {{0x80000000, 0x0, 0x0, 0x80090000}};
  int check = -1073123233;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok685) {
  my_decimal decimal = {{0x80000000, 0x84, 0x0, 0xB0000}};
  int check = 1085676363;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok686) {
  my_decimal decimal = {{0x80000000, 0x84, 0x0, 0x800B0000}};
  int check = -1061807285;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok687) {
  my_decimal decimal = {{0x811800, 0x811800, 0x811800, 0x0}};
  int check = 1795233792;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok688) {
  my_decimal decimal = {{0x811800, 0x811800, 0x811800, 0x80000000}};
  int check = -352249856;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok689) {
  my_decimal decimal = {{0x85A1D800, 0x85A1D800, 0x85A1D800, 0x20000}};
  int check = 1806371994;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok690) {
  my_decimal decimal = {{0x85A1D800, 0x85A1D800, 0x85A1D800, 0x80020000}};
  int check = -341111654;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok691) {
  my_decimal decimal = {{0x811800, 0x811800, 0x811800, 0x10000}};
  int check = 1766755533;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok692) {
  my_decimal decimal = {{0x811800, 0x811800, 0x811800, 0x80010000}};
  int check = -380728115;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok693) {
  my_decimal decimal = {{0x85A1D800, 0x85A1D800, 0x85A1D800, 0x30000}};
  int check = 1778964193;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok694) {
  my_decimal decimal = {{0x85A1D800, 0x85A1D800, 0x85A1D800, 0x80030000}};
  int check = -368519455;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok695) {
  my_decimal decimal = {{0x811800, 0x811800, 0x811800, 0x140000}};
  int check = 1237221949;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok696) {
  my_decimal decimal = {{0x811800, 0x811800, 0x811800, 0x80140000}};
  int check = -910261699;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok697) {
  my_decimal decimal = {{0x85A1D800, 0x85A1D800, 0x85A1D800, 0x160000}};
  int check = 1249668241;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok698) {
  my_decimal decimal = {{0x85A1D800, 0x85A1D800, 0x85A1D800, 0x80160000}};
  int check = -897815407;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok699) {
  my_decimal decimal = {{0x811800, 0x811800, 0x811800, 0x1A0000}};
  int check = 1070056270;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok700) {
  my_decimal decimal = {{0x811800, 0x811800, 0x811800, 0x801A0000}};
  int check = -1077427378;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok701) {
  my_decimal decimal = {{0x85A1D800, 0x85A1D800, 0x85A1D800, 0x1C0000}};
  int check = 1082415050;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok702) {
  my_decimal decimal = {{0x85A1D800, 0x85A1D800, 0x85A1D800, 0x801C0000}};
  int check = -1065068598;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok703) {
  my_decimal decimal = {{0x0, 0x811800, 0x811800, 0x0}};
  int check = 1795233792;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok704) {
  my_decimal decimal = {{0x0, 0x811800, 0x811800, 0x80000000}};
  int check = -352249856;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok705) {
  my_decimal decimal = {{0x0, 0x85A1D800, 0x85A1D800, 0x20000}};
  int check = 1806371994;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok706) {
  my_decimal decimal = {{0x0, 0x85A1D800, 0x85A1D800, 0x80020000}};
  int check = -341111654;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok707) {
  my_decimal decimal = {{0x0, 0x811800, 0x811800, 0x10000}};
  int check = 1766755533;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok708) {
  my_decimal decimal = {{0x0, 0x811800, 0x811800, 0x80010000}};
  int check = -380728115;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok709) {
  my_decimal decimal = {{0x0, 0x85A1D800, 0x85A1D800, 0x30000}};
  int check = 1778964193;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok710) {
  my_decimal decimal = {{0x0, 0x85A1D800, 0x85A1D800, 0x80030000}};
  int check = -368519455;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok711) {
  my_decimal decimal = {{0x0, 0x811800, 0x811800, 0x130000}};
  int check = 1265509069;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok712) {
  my_decimal decimal = {{0x0, 0x811800, 0x811800, 0x80130000}};
  int check = -881974579;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok713) {
  my_decimal decimal = {{0x0, 0x85A1D800, 0x85A1D800, 0x150000}};
  int check = 1277019099;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok714) {
  my_decimal decimal = {{0x0, 0x85A1D800, 0x85A1D800, 0x80150000}};
  int check = -870464549;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok715) {
  my_decimal decimal = {{0x0, 0x811800, 0x811800, 0x1A0000}};
  int check = 1070056270;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok716) {
  my_decimal decimal = {{0x0, 0x811800, 0x811800, 0x801A0000}};
  int check = -1077427378;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok717) {
  my_decimal decimal = {{0x0, 0x85A1D800, 0x85A1D800, 0x1C0000}};
  int check = 1082415050;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok718) {
  my_decimal decimal = {{0x0, 0x85A1D800, 0x85A1D800, 0x801C0000}};
  int check = -1065068598;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok719) {
  my_decimal decimal = {{0x811800, 0x0, 0x811800, 0x0}};
  int check = 1795233792;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok720) {
  my_decimal decimal = {{0x811800, 0x0, 0x811800, 0x80000000}};
  int check = -352249856;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok721) {
  my_decimal decimal = {{0x85A1D800, 0x0, 0x85A1D800, 0x20000}};
  int check = 1806371994;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok722) {
  my_decimal decimal = {{0x85A1D800, 0x0, 0x85A1D800, 0x80020000}};
  int check = -341111654;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok723) {
  my_decimal decimal = {{0x811800, 0x0, 0x811800, 0x10000}};
  int check = 1766755533;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok724) {
  my_decimal decimal = {{0x811800, 0x0, 0x811800, 0x80010000}};
  int check = -380728115;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok725) {
  my_decimal decimal = {{0x85A1D800, 0x0, 0x85A1D800, 0x30000}};
  int check = 1778964193;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok726) {
  my_decimal decimal = {{0x85A1D800, 0x0, 0x85A1D800, 0x80030000}};
  int check = -368519455;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok727) {
  my_decimal decimal = {{0x811800, 0x0, 0x811800, 0x150000}};
  int check = 1209559089;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok728) {
  my_decimal decimal = {{0x811800, 0x0, 0x811800, 0x80150000}};
  int check = -937924559;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok729) {
  my_decimal decimal = {{0x85A1D800, 0x0, 0x85A1D800, 0x170000}};
  int check = 1221193844;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok730) {
  my_decimal decimal = {{0x85A1D800, 0x0, 0x85A1D800, 0x80170000}};
  int check = -926289804;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok731) {
  my_decimal decimal = {{0x811800, 0x0, 0x811800, 0x1A0000}};
  int check = 1070056270;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok732) {
  my_decimal decimal = {{0x811800, 0x0, 0x811800, 0x801A0000}};
  int check = -1077427378;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok733) {
  my_decimal decimal = {{0x85A1D800, 0x0, 0x85A1D800, 0x1C0000}};
  int check = 1082415050;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok734) {
  my_decimal decimal = {{0x85A1D800, 0x0, 0x85A1D800, 0x801C0000}};
  int check = -1065068598;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok735) {
  my_decimal decimal = {{0x0, 0x0, 0x811800, 0x0}};
  int check = 1795233792;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok736) {
  my_decimal decimal = {{0x0, 0x0, 0x811800, 0x80000000}};
  int check = -352249856;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok737) {
  my_decimal decimal = {{0x0, 0x0, 0x85A1D800, 0x20000}};
  int check = 1806371994;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok738) {
  my_decimal decimal = {{0x0, 0x0, 0x85A1D800, 0x80020000}};
  int check = -341111654;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok739) {
  my_decimal decimal = {{0x0, 0x0, 0x811800, 0x10000}};
  int check = 1766755533;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok740) {
  my_decimal decimal = {{0x0, 0x0, 0x811800, 0x80010000}};
  int check = -380728115;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok741) {
  my_decimal decimal = {{0x0, 0x0, 0x85A1D800, 0x30000}};
  int check = 1778964193;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok742) {
  my_decimal decimal = {{0x0, 0x0, 0x85A1D800, 0x80030000}};
  int check = -368519455;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok743) {
  my_decimal decimal = {{0x0, 0x0, 0x811800, 0x160000}};
  int check = 1181997544;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok744) {
  my_decimal decimal = {{0x0, 0x0, 0x811800, 0x80160000}};
  int check = -965486104;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok745) {
  my_decimal decimal = {{0x0, 0x0, 0x85A1D800, 0x180000}};
  int check = 1193381162;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok746) {
  my_decimal decimal = {{0x0, 0x0, 0x85A1D800, 0x80180000}};
  int check = -954102486;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok747) {
  my_decimal decimal = {{0x0, 0x0, 0x811800, 0x1A0000}};
  int check = 1070056270;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok748) {
  my_decimal decimal = {{0x0, 0x0, 0x811800, 0x801A0000}};
  int check = -1077427378;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok749) {
  my_decimal decimal = {{0x0, 0x0, 0x85A1D800, 0x1C0000}};
  int check = 1082415050;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok750) {
  my_decimal decimal = {{0x0, 0x0, 0x85A1D800, 0x801C0000}};
  int check = -1065068598;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok751) {
  my_decimal decimal = {{0x811800, 0x811800, 0x0, 0x0}};
  int check = 1526798336;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok752) {
  my_decimal decimal = {{0x811800, 0x811800, 0x0, 0x80000000}};
  int check = -620685312;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok753) {
  my_decimal decimal = {{0x85A1D800, 0x85A1D800, 0x0, 0x20000}};
  int check = 1537936538;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok754) {
  my_decimal decimal = {{0x85A1D800, 0x85A1D800, 0x0, 0x80020000}};
  int check = -609547110;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok755) {
  my_decimal decimal = {{0x811800, 0x811800, 0x0, 0x10000}};
  int check = 1498320077;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok756) {
  my_decimal decimal = {{0x811800, 0x811800, 0x0, 0x80010000}};
  int check = -649163571;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok757) {
  my_decimal decimal = {{0x85A1D800, 0x85A1D800, 0x0, 0x30000}};
  int check = 1510528737;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok758) {
  my_decimal decimal = {{0x85A1D800, 0x85A1D800, 0x0, 0x80030000}};
  int check = -636954911;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok759) {
  my_decimal decimal = {{0x811800, 0x811800, 0x0, 0x80000}};
  int check = 1303200838;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok760) {
  my_decimal decimal = {{0x811800, 0x811800, 0x0, 0x80080000}};
  int check = -844282810;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok761) {
  my_decimal decimal = {{0x85A1D800, 0x85A1D800, 0x0, 0xA0000}};
  int check = 1315279888;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok762) {
  my_decimal decimal = {{0x85A1D800, 0x85A1D800, 0x0, 0x800A0000}};
  int check = -832203760;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok763) {
  my_decimal decimal = {{0x811800, 0x811800, 0x0, 0x100000}};
  int check = 1080593916;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok764) {
  my_decimal decimal = {{0x811800, 0x811800, 0x0, 0x80100000}};
  int check = -1066889732;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok765) {
  my_decimal decimal = {{0x85A1D800, 0x85A1D800, 0x0, 0x120000}};
  int check = 1092227396;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok766) {
  my_decimal decimal = {{0x85A1D800, 0x85A1D800, 0x0, 0x80120000}};
  int check = -1055256252;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok767) {
  my_decimal decimal = {{0x0, 0x811800, 0x0, 0x0}};
  int check = 1526798336;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok768) {
  my_decimal decimal = {{0x0, 0x811800, 0x0, 0x80000000}};
  int check = -620685312;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok769) {
  my_decimal decimal = {{0x0, 0x85A1D800, 0x0, 0x20000}};
  int check = 1537936538;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok770) {
  my_decimal decimal = {{0x0, 0x85A1D800, 0x0, 0x80020000}};
  int check = -609547110;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok771) {
  my_decimal decimal = {{0x0, 0x811800, 0x0, 0x10000}};
  int check = 1498320077;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok772) {
  my_decimal decimal = {{0x0, 0x811800, 0x0, 0x80010000}};
  int check = -649163571;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok773) {
  my_decimal decimal = {{0x0, 0x85A1D800, 0x0, 0x30000}};
  int check = 1510528737;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok774) {
  my_decimal decimal = {{0x0, 0x85A1D800, 0x0, 0x80030000}};
  int check = -636954911;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok775) {
  my_decimal decimal = {{0x0, 0x811800, 0x0, 0xA0000}};
  int check = 1247660040;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok776) {
  my_decimal decimal = {{0x0, 0x811800, 0x0, 0x800A0000}};
  int check = -899823608;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok777) {
  my_decimal decimal = {{0x0, 0x85A1D800, 0x0, 0xC0000}};
  int check = 1259531807;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok778) {
  my_decimal decimal = {{0x0, 0x85A1D800, 0x0, 0x800C0000}};
  int check = -887951841;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok779) {
  my_decimal decimal = {{0x0, 0x811800, 0x0, 0x80000}};
  int check = 1303200838;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok780) {
  my_decimal decimal = {{0x0, 0x811800, 0x0, 0x80080000}};
  int check = -844282810;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok781) {
  my_decimal decimal = {{0x0, 0x85A1D800, 0x0, 0xA0000}};
  int check = 1315279888;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok782) {
  my_decimal decimal = {{0x0, 0x85A1D800, 0x0, 0x800A0000}};
  int check = -832203760;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok783) {
  my_decimal decimal = {{0x0, 0x811800, 0x0, 0xF0000}};
  int check = 1108433085;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok784) {
  my_decimal decimal = {{0x0, 0x811800, 0x0, 0x800F0000}};
  int check = -1039050563;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok785) {
  my_decimal decimal = {{0x0, 0x85A1D800, 0x0, 0x110000}};
  int check = 1119917461;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok786) {
  my_decimal decimal = {{0x0, 0x85A1D800, 0x0, 0x80110000}};
  int check = -1027566187;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok787) {
  my_decimal decimal = {{0x0, 0x811800, 0x0, 0x100000}};
  int check = 1080593916;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok788) {
  my_decimal decimal = {{0x0, 0x811800, 0x0, 0x80100000}};
  int check = -1066889732;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok789) {
  my_decimal decimal = {{0x0, 0x85A1D800, 0x0, 0x120000}};
  int check = 1092227396;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok790) {
  my_decimal decimal = {{0x0, 0x85A1D800, 0x0, 0x80120000}};
  int check = -1055256252;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok791) {
  my_decimal decimal = {{0x811800, 0x0, 0x0, 0x0}};
  int check = 1258362880;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok792) {
  my_decimal decimal = {{0x811800, 0x0, 0x0, 0x80000000}};
  int check = -889120768;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok793) {
  my_decimal decimal = {{0x85A1D800, 0x0, 0x0, 0x20000}};
  int check = 1269501082;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok794) {
  my_decimal decimal = {{0x85A1D800, 0x0, 0x0, 0x80020000}};
  int check = -877982566;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok795) {
  my_decimal decimal = {{0x811800, 0x0, 0x0, 0x10000}};
  int check = 1229884621;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok796) {
  my_decimal decimal = {{0x811800, 0x0, 0x0, 0x80010000}};
  int check = -917599027;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok797) {
  my_decimal decimal = {{0x85A1D800, 0x0, 0x0, 0x30000}};
  int check = 1242093281;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok798) {
  my_decimal decimal = {{0x85A1D800, 0x0, 0x0, 0x80030000}};
  int check = -905390367;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok799) {
  my_decimal decimal = {{0x811800, 0x0, 0x0, 0x20000}};
  int check = 1202011505;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok800) {
  my_decimal decimal = {{0x811800, 0x0, 0x0, 0x80020000}};
  int check = -945472143;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok801) {
  my_decimal decimal = {{0x85A1D800, 0x0, 0x0, 0x40000}};
  int check = 1213919592;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok802) {
  my_decimal decimal = {{0x85A1D800, 0x0, 0x0, 0x80040000}};
  int check = -933564056;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok803) {
  my_decimal decimal = {{0x811800, 0x0, 0x0, 0x30000}};
  int check = 1174679847;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok804) {
  my_decimal decimal = {{0x811800, 0x0, 0x0, 0x80030000}};
  int check = -972803801;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok805) {
  my_decimal decimal = {{0x85A1D800, 0x0, 0x0, 0x50000}};
  int check = 1185884039;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok806) {
  my_decimal decimal = {{0x85A1D800, 0x0, 0x0, 0x80050000}};
  int check = -961599609;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok807) {
  my_decimal decimal = {{0x811800, 0x0, 0x0, 0x50000}};
  int check = 1118385325;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok808) {
  my_decimal decimal = {{0x811800, 0x0, 0x0, 0x80050000}};
  int check = -1029098323;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok809) {
  my_decimal decimal = {{0x85A1D800, 0x0, 0x0, 0x70000}};
  int check = 1130377880;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok810) {
  my_decimal decimal = {{0x85A1D800, 0x0, 0x0, 0x80070000}};
  int check = -1017105768;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok811) {
  my_decimal decimal = {{0x811800, 0x0, 0x0, 0x60000}};
  int check = 1091001687;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok812) {
  my_decimal decimal = {{0x811800, 0x0, 0x0, 0x80060000}};
  int check = -1056481961;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok813) {
  my_decimal decimal = {{0x85A1D800, 0x0, 0x0, 0x80000}};
  int check = 1102273453;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok814) {
  my_decimal decimal = {{0x85A1D800, 0x0, 0x0, 0x80080000}};
  int check = -1045210195;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok815) {
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  int check = 1870659584;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok816) {
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  int check = -276824064;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok817) {
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};
  int check = 1842138317;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok818) {
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80010000}};
  int check = -305345331;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok819) {
  my_decimal decimal = {{0x3D70A3D7, 0x70A3D70A, 0x43D70A3D, 0x0}};
  int check = 1854385684;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok820) {
  my_decimal decimal = {{0x3D70A3D7, 0x70A3D70A, 0x43D70A3D, 0x80000000}};
  int check = -293097964;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok821) {
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x140000}};
  int check = 1312613640;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok822) {
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x80140000}};
  int check = -834870008;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok823) {
  my_decimal decimal = {{0x3D70A3D7, 0x70A3D70A, 0x43D70A3D, 0x130000}};
  int check = 1325025554;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok824) {
  my_decimal decimal = {{0x3D70A3D7, 0x70A3D70A, 0x43D70A3D, 0x80130000}};
  int check = -822458094;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok825) {
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x1C0000}};
  int check = 1090357174;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok826) {
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFFFF, 0x801C0000}};
  int check = -1057126474;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok827) {
  my_decimal decimal = {{0x3D70A3D7, 0x70A3D70A, 0x43D70A3D, 0x1B0000}};
  int check = 1101526709;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok828) {
  my_decimal decimal = {{0x3D70A3D7, 0x70A3D70A, 0x43D70A3D, 0x801B0000}};
  int check = -1045956939;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok829) {
  my_decimal decimal = {{0x0, 0xFFFFFFFF, 0xFFFFFFFF, 0x0}};
  int check = 1870659584;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok830) {
  my_decimal decimal = {{0x0, 0xFFFFFFFF, 0xFFFFFFFF, 0x80000000}};
  int check = -276824064;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok831) {
  my_decimal decimal = {{0x0, 0xFFFFFFFF, 0xFFFFFFFF, 0x10000}};
  int check = 1842138317;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok832) {
  my_decimal decimal = {{0x0, 0xFFFFFFFF, 0xFFFFFFFF, 0x80010000}};
  int check = -305345331;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok833) {
  my_decimal decimal = {{0xF999999A, 0x70A3D709, 0x43D70A3D, 0x0}};
  int check = 1854385684;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok834) {
  my_decimal decimal = {{0xF999999A, 0x70A3D709, 0x43D70A3D, 0x80000000}};
  int check = -293097964;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok835) {
  my_decimal decimal = {{0x0, 0xFFFFFFFF, 0xFFFFFFFF, 0x150000}};
  int check = 1284971936;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok836) {
  my_decimal decimal = {{0x0, 0xFFFFFFFF, 0xFFFFFFFF, 0x80150000}};
  int check = -862511712;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok837) {
  my_decimal decimal = {{0xF999999A, 0x70A3D709, 0x43D70A3D, 0x140000}};
  int check = 1296579188;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok838) {
  my_decimal decimal = {{0xF999999A, 0x70A3D709, 0x43D70A3D, 0x80140000}};
  int check = -850904460;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok839) {
  my_decimal decimal = {{0x0, 0xFFFFFFFF, 0xFFFFFFFF, 0x1C0000}};
  int check = 1090357174;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok840) {
  my_decimal decimal = {{0x0, 0xFFFFFFFF, 0xFFFFFFFF, 0x801C0000}};
  int check = -1057126474;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok841) {
  my_decimal decimal = {{0xF999999A, 0x70A3D709, 0x43D70A3D, 0x1B0000}};
  int check = 1101526709;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok842) {
  my_decimal decimal = {{0xF999999A, 0x70A3D709, 0x43D70A3D, 0x801B0000}};
  int check = -1045956939;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok843) {
  my_decimal decimal = {{0xFFFFFFFF, 0x0, 0xFFFFFFFF, 0x0}};
  int check = 1870659584;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok844) {
  my_decimal decimal = {{0xFFFFFFFF, 0x0, 0xFFFFFFFF, 0x80000000}};
  int check = -276824064;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok845) {
  my_decimal decimal = {{0xFFFFFFFF, 0x0, 0xFFFFFFFF, 0x10000}};
  int check = 1842138317;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok846) {
  my_decimal decimal = {{0xFFFFFFFF, 0x0, 0xFFFFFFFF, 0x80010000}};
  int check = -305345331;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok847) {
  my_decimal decimal = {{0x10A3D70A, 0x2CCCCCCD, 0x43D70A3D, 0x0}};
  int check = 1854385684;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok848) {
  my_decimal decimal = {{0x10A3D70A, 0x2CCCCCCD, 0x43D70A3D, 0x80000000}};
  int check = -293097964;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok849) {
  my_decimal decimal = {{0xFFFFFFFF, 0x0, 0xFFFFFFFF, 0x160000}};
  int check = 1257359616;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok850) {
  my_decimal decimal = {{0xFFFFFFFF, 0x0, 0xFFFFFFFF, 0x80160000}};
  int check = -890124032;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok851) {
  my_decimal decimal = {{0x10A3D70A, 0x2CCCCCCD, 0x43D70A3D, 0x150000}};
  int check = 1268788932;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok852) {
  my_decimal decimal = {{0x10A3D70A, 0x2CCCCCCD, 0x43D70A3D, 0x80150000}};
  int check = -878694716;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok853) {
  my_decimal decimal = {{0xFFFFFFFF, 0x0, 0xFFFFFFFF, 0x1C0000}};
  int check = 1090357174;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok854) {
  my_decimal decimal = {{0xFFFFFFFF, 0x0, 0xFFFFFFFF, 0x801C0000}};
  int check = -1057126474;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok855) {
  my_decimal decimal = {{0x10A3D70A, 0x2CCCCCCD, 0x43D70A3D, 0x1B0000}};
  int check = 1101526709;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok856) {
  my_decimal decimal = {{0x10A3D70A, 0x2CCCCCCD, 0x43D70A3D, 0x801B0000}};
  int check = -1045956939;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok857) {
  my_decimal decimal = {{0x0, 0x0, 0xFFFFFFFF, 0x0}};
  int check = 1870659584;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok858) {
  my_decimal decimal = {{0x0, 0x0, 0xFFFFFFFF, 0x80000000}};
  int check = -276824064;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok859) {
  my_decimal decimal = {{0x0, 0x0, 0xFFFFFFFF, 0x10000}};
  int check = 1842138317;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok860) {
  my_decimal decimal = {{0x0, 0x0, 0xFFFFFFFF, 0x80010000}};
  int check = -305345331;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok861) {
  my_decimal decimal = {{0xCCCCCCCD, 0x2CCCCCCC, 0x43D70A3D, 0x0}};
  int check = 1854385684;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok862) {
  my_decimal decimal = {{0xCCCCCCCD, 0x2CCCCCCC, 0x43D70A3D, 0x80000000}};
  int check = -293097964;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok863) {
  my_decimal decimal = {{0x0, 0x0, 0xFFFFFFFF, 0x170000}};
  int check = 1229024666;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok864) {
  my_decimal decimal = {{0x0, 0x0, 0xFFFFFFFF, 0x80170000}};
  int check = -918458982;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok865) {
  my_decimal decimal = {{0xCCCCCCCD, 0x2CCCCCCC, 0x43D70A3D, 0x160000}};
  int check = 1241523561;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok866) {
  my_decimal decimal = {{0xCCCCCCCD, 0x2CCCCCCC, 0x43D70A3D, 0x80160000}};
  int check = -905960087;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok867) {
  my_decimal decimal = {{0x0, 0x0, 0xFFFFFFFF, 0x1C0000}};
  int check = 1090357174;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok868) {
  my_decimal decimal = {{0x0, 0x0, 0xFFFFFFFF, 0x801C0000}};
  int check = -1057126474;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok869) {
  my_decimal decimal = {{0xCCCCCCCD, 0x2CCCCCCC, 0x43D70A3D, 0x1B0000}};
  int check = 1101526709;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok870) {
  my_decimal decimal = {{0xCCCCCCCD, 0x2CCCCCCC, 0x43D70A3D, 0x801B0000}};
  int check = -1045956939;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok871) {
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0x0, 0x0}};
  int check = 1602224128;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok872) {
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0x0, 0x80000000}};
  int check = -545259520;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok873) {
  my_decimal decimal = {{0xFFFFFEF7, 0xFFFFFFFF, 0x108, 0x20000}};
  int check = 1613339034;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok874) {
  my_decimal decimal = {{0xFFFFFEF7, 0xFFFFFFFF, 0x108, 0x80020000}};
  int check = -534144614;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok875) {
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0x0, 0x10000}};
  int check = 1573702861;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok876) {
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0x0, 0x80010000}};
  int check = -573780787;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok877) {
  my_decimal decimal = {{0xFFFFFEF7, 0xFFFFFFFF, 0x108, 0x30000}};
  int check = 1585950228;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok878) {
  my_decimal decimal = {{0xFFFFFEF7, 0xFFFFFFFF, 0x108, 0x80030000}};
  int check = -561533420;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok879) {
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0x0, 0x30000}};
  int check = 1518539375;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok880) {
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0x0, 0x80030000}};
  int check = -628944273;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok881) {
  my_decimal decimal = {{0xFFFFFEF7, 0xFFFFFFFF, 0x108, 0x50000}};
  int check = 1529719711;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok882) {
  my_decimal decimal = {{0xFFFFFEF7, 0xFFFFFFFF, 0x108, 0x80050000}};
  int check = -617763937;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok883) {
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0x0, 0xB0000}};
  int check = 1294986239;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok884) {
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0x0, 0x800B0000}};
  int check = -852497409;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok885) {
  my_decimal decimal = {{0xFFFFFEF7, 0xFFFFFFFF, 0x108, 0xD0000}};
  int check = 1307121842;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok886) {
  my_decimal decimal = {{0xFFFFFEF7, 0xFFFFFFFF, 0x108, 0x800D0000}};
  int check = -840361806;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok887) {
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0x0, 0x110000}};
  int check = 1127774122;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok888) {
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0x0, 0x80110000}};
  int check = -1019709526;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok889) {
  my_decimal decimal = {{0xFFFFFEF7, 0xFFFFFFFF, 0x108, 0x130000}};
  int check = 1140091739;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok890) {
  my_decimal decimal = {{0xFFFFFEF7, 0xFFFFFFFF, 0x108, 0x80130000}};
  int check = -1007391909;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok891) {
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0x0, 0x130000}};
  int check = 1072438858;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok892) {
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0x0, 0x80130000}};
  int check = -1075044790;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok893) {
  my_decimal decimal = {{0xFFFFFEF7, 0xFFFFFFFF, 0x108, 0x150000}};
  int check = 1083993515;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok894) {
  my_decimal decimal = {{0xFFFFFEF7, 0xFFFFFFFF, 0x108, 0x80150000}};
  int check = -1063490133;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok895) {
  my_decimal decimal = {{0x0, 0xFFFFFFFF, 0x0, 0x0}};
  int check = 1602224128;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok896) {
  my_decimal decimal = {{0x0, 0xFFFFFFFF, 0x0, 0x80000000}};
  int check = -545259520;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok897) {
  my_decimal decimal = {{0x0, 0xFFFFFEF7, 0x108, 0x20000}};
  int check = 1613339034;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok898) {
  my_decimal decimal = {{0x0, 0xFFFFFEF7, 0x108, 0x80020000}};
  int check = -534144614;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok899) {
  my_decimal decimal = {{0x0, 0xFFFFFFFF, 0x0, 0x10000}};
  int check = 1573702861;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok900) {
  my_decimal decimal = {{0x0, 0xFFFFFFFF, 0x0, 0x80010000}};
  int check = -573780787;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok901) {
  my_decimal decimal = {{0x0, 0xFFFFFEF7, 0x108, 0x30000}};
  int check = 1585950228;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok902) {
  my_decimal decimal = {{0x0, 0xFFFFFEF7, 0x108, 0x80030000}};
  int check = -561533420;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok903) {
  my_decimal decimal = {{0x0, 0xFFFFFFFF, 0x0, 0x30000}};
  int check = 1518539375;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok904) {
  my_decimal decimal = {{0x0, 0xFFFFFFFF, 0x0, 0x80030000}};
  int check = -628944273;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok905) {
  my_decimal decimal = {{0x0, 0xFFFFFEF7, 0x108, 0x50000}};
  int check = 1529719711;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok906) {
  my_decimal decimal = {{0x0, 0xFFFFFEF7, 0x108, 0x80050000}};
  int check = -617763937;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok907) {
  my_decimal decimal = {{0x0, 0xFFFFFFFF, 0x0, 0xC0000}};
  int check = 1267514572;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok908) {
  my_decimal decimal = {{0x0, 0xFFFFFFFF, 0x0, 0x800C0000}};
  int check = -879969076;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok909) {
  my_decimal decimal = {{0x0, 0xFFFFFEF7, 0x108, 0xE0000}};
  int check = 1278900776;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok910) {
  my_decimal decimal = {{0x0, 0xFFFFFEF7, 0x108, 0x800E0000}};
  int check = -868582872;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok911) {
  my_decimal decimal = {{0x0, 0xFFFFFFFF, 0x0, 0x110000}};
  int check = 1127774122;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok912) {
  my_decimal decimal = {{0x0, 0xFFFFFFFF, 0x0, 0x80110000}};
  int check = -1019709526;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok913) {
  my_decimal decimal = {{0x0, 0xFFFFFEF7, 0x108, 0x130000}};
  int check = 1140091739;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok914) {
  my_decimal decimal = {{0x0, 0xFFFFFEF7, 0x108, 0x80130000}};
  int check = -1007391909;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok915) {
  my_decimal decimal = {{0x0, 0xFFFFFFFF, 0x0, 0x130000}};
  int check = 1072438858;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok916) {
  my_decimal decimal = {{0x0, 0xFFFFFFFF, 0x0, 0x80130000}};
  int check = -1075044790;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok917) {
  my_decimal decimal = {{0x0, 0xFFFFFEF7, 0x108, 0x150000}};
  int check = 1083993515;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok918) {
  my_decimal decimal = {{0x0, 0xFFFFFEF7, 0x108, 0x80150000}};
  int check = -1063490133;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok919) {
  my_decimal decimal = {{0xFFFFFFFF, 0x0, 0x0, 0x0}};
  int check = 1333788672;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok920) {
  my_decimal decimal = {{0xFFFFFFFF, 0x0, 0x0, 0x80000000}};
  int check = -813694976;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok921) {
  my_decimal decimal = {{0xFFFFFEF7, 0x108, 0x0, 0x20000}};
  int check = 1344903578;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok922) {
  my_decimal decimal = {{0xFFFFFEF7, 0x108, 0x0, 0x80020000}};
  int check = -802580070;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok923) {
  my_decimal decimal = {{0xFFFFFFFF, 0x0, 0x0, 0x10000}};
  int check = 1305267405;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok924) {
  my_decimal decimal = {{0xFFFFFFFF, 0x0, 0x0, 0x80010000}};
  int check = -842216243;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok925) {
  my_decimal decimal = {{0xFFFFFEF7, 0x108, 0x0, 0x30000}};
  int check = 1317514772;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok926) {
  my_decimal decimal = {{0xFFFFFEF7, 0x108, 0x0, 0x80030000}};
  int check = -829968876;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok927) {
  my_decimal decimal = {{0xFFFFFFFF, 0x0, 0x0, 0x20000}};
  int check = 1277417226;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok928) {
  my_decimal decimal = {{0xFFFFFFFF, 0x0, 0x0, 0x80020000}};
  int check = -870066422;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok929) {
  my_decimal decimal = {{0xFFFFFEF7, 0x108, 0x0, 0x40000}};
  int check = 1289295495;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok930) {
  my_decimal decimal = {{0xFFFFFEF7, 0x108, 0x0, 0x80040000}};
  int check = -858188153;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok931) {
  my_decimal decimal = {{0xFFFFFFFF, 0x0, 0x0, 0x50000}};
  int check = 1193788844;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok932) {
  my_decimal decimal = {{0xFFFFFFFF, 0x0, 0x0, 0x80050000}};
  int check = -953694804;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok933) {
  my_decimal decimal = {{0xFFFFFEF7, 0x108, 0x0, 0x70000}};
  int check = 1205750865;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok934) {
  my_decimal decimal = {{0xFFFFFEF7, 0x108, 0x0, 0x80070000}};
  int check = -941732783;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok935) {
  my_decimal decimal = {{0xFFFFFFFF, 0x0, 0x0, 0x80000}};
  int check = 1110166647;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok936) {
  my_decimal decimal = {{0xFFFFFFFF, 0x0, 0x0, 0x80080000}};
  int check = -1037317001;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok937) {
  my_decimal decimal = {{0xFFFFFEF7, 0x108, 0x0, 0xA0000}};
  int check = 1122214430;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok938) {
  my_decimal decimal = {{0xFFFFFEF7, 0x108, 0x0, 0x800A0000}};
  int check = -1025269218;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok939) {
  my_decimal decimal = {{0xFFFFFFFF, 0x0, 0x0, 0x90000}};
  int check = 1082749023;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok940) {
  my_decimal decimal = {{0xFFFFFFFF, 0x0, 0x0, 0x80090000}};
  int check = -1064734625;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok941) {
  my_decimal decimal = {{0xFFFFFEF7, 0x108, 0x0, 0xB0000}};
  int check = 1094064971;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok942) {
  my_decimal decimal = {{0xFFFFFEF7, 0x108, 0x0, 0x800B0000}};
  int check = -1053418677;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok943) {
  my_decimal decimal = {{0x1, 0x0, 0x0, 0x0}};
  int check = 1065353216;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok944) {
  my_decimal decimal = {{0x1, 0x0, 0x0, 0x80000000}};
  int check = -1082130432;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok945) {
  my_decimal decimal = {{0x109, 0x0, 0x0, 0x20000}};
  int check = 1076468122;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok946) {
  my_decimal decimal = {{0x109, 0x0, 0x0, 0x80020000}};
  int check = -1071015526;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok947) {
  my_decimal decimal = {{0xA, 0x0, 0x0, 0x10000}};
  int check = 1065353216;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok948) {
  my_decimal decimal = {{0xA, 0x0, 0x0, 0x80010000}};
  int check = -1082130432;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok949) {
  my_decimal decimal = {{0xA5A, 0x0, 0x0, 0x30000}};
  int check = 1076468122;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok950) {
  my_decimal decimal = {{0xA5A, 0x0, 0x0, 0x80030000}};
  int check = -1071015526;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok951) {
  my_decimal decimal = {{0x64, 0x0, 0x0, 0x20000}};
  int check = 1065353216;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok952) {
  my_decimal decimal = {{0x64, 0x0, 0x0, 0x80020000}};
  int check = -1082130432;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok953) {
  my_decimal decimal = {{0x6784, 0x0, 0x0, 0x40000}};
  int check = 1076468122;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok954) {
  my_decimal decimal = {{0x6784, 0x0, 0x0, 0x80040000}};
  int check = -1071015526;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok955) {
  my_decimal decimal = {{0x3E8, 0x0, 0x0, 0x30000}};
  int check = 1065353216;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok956) {
  my_decimal decimal = {{0x3E8, 0x0, 0x0, 0x80030000}};
  int check = -1082130432;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok957) {
  my_decimal decimal = {{0x40B28, 0x0, 0x0, 0x50000}};
  int check = 1076468122;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok958) {
  my_decimal decimal = {{0x40B28, 0x0, 0x0, 0x80050000}};
  int check = -1071015526;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok959) {
  my_decimal decimal = {{0x540BE400, 0x2, 0x0, 0xA0000}};
  int check = 1065353216;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok960) {
  my_decimal decimal = {{0x540BE400, 0x2, 0x0, 0x800A0000}};
  int check = -1082130432;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok961) {
  my_decimal decimal = {{0x4F0400, 0x269, 0x0, 0xC0000}};
  int check = 1076468122;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok962) {
  my_decimal decimal = {{0x4F0400, 0x269, 0x0, 0x800C0000}};
  int check = -1071015526;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok963) {
  my_decimal decimal = {{0x6FC10000, 0x2386F2, 0x0, 0x100000}};
  int check = 1065353216;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok964) {
  my_decimal decimal = {{0x6FC10000, 0x2386F2, 0x0, 0x80100000}};
  int check = -1082130432;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok965) {
  my_decimal decimal = {{0xAEC90000, 0x24C6B0F5, 0x0, 0x120000}};
  int check = 1076468122;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok966) {
  my_decimal decimal = {{0xAEC90000, 0x24C6B0F5, 0x0, 0x80120000}};
  int check = -1071015526;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok967) {
  my_decimal decimal = {{0xF6800000, 0x2C7E14A, 0x152D, 0x170000}};
  int check = 1065353216;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok968) {
  my_decimal decimal = {{0xF6800000, 0x2C7E14A, 0x152D, 0x80170000}};
  int check = -1082130432;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok969) {
  my_decimal decimal = {{0x2A800000, 0xE0E83699, 0x15EB97, 0x190000}};
  int check = 1076468122;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok970) {
  my_decimal decimal = {{0x2A800000, 0xE0E83699, 0x15EB97, 0x80190000}};
  int check = -1071015526;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok971) {
  my_decimal decimal = {{0xE8000000, 0x9FD0803C, 0x33B2E3C, 0x1B0000}};
  int check = 1065353216;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok972) {
  my_decimal decimal = {{0xE8000000, 0x9FD0803C, 0x33B2E3C, 0x801B0000}};
  int check = -1082130432;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok973) {
  my_decimal decimal = {{0x4000000, 0x8B15464E, 0x55A04946, 0x1C0000}};
  int check = 1076468122;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok974) {
  my_decimal decimal = {{0x4000000, 0x8B15464E, 0x55A04946, 0x801C0000}};
  int check = -1071015526;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok975) {
  my_decimal decimal = {{0x10000000, 0x3E250261, 0x204FCE5E, 0x1C0000}};
  int check = 1065353216;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok976) {
  my_decimal decimal = {{0x10000000, 0x3E250261, 0x204FCE5E, 0x801C0000}};
  int check = -1082130432;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok977) {
  my_decimal decimal = {{0x4000000, 0x8B15464E, 0x55A04946, 0x1C0000}};
  int check = 1076468122;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok978) {
  my_decimal decimal = {{0x4000000, 0x8B15464E, 0x55A04946, 0x801C0000}};
  int check = -1071015526;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok979) {
  my_decimal decimal = {{0xB, 0x0, 0x0, 0x10000}};
  int check = 1066192077;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok980) {
  my_decimal decimal = {{0xB, 0x0, 0x0, 0x80010000}};
  int check = -1081291571;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok981) {
  my_decimal decimal = {{0xB63, 0x0, 0x0, 0x30000}};
  int check = 1077579612;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok982) {
  my_decimal decimal = {{0xB63, 0x0, 0x0, 0x80030000}};
  int check = -1069904036;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok983) {
  my_decimal decimal = {{0x4BC, 0x0, 0x0, 0x20000}};
  int check = 1094839173;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok984) {
  my_decimal decimal = {{0x4BC, 0x0, 0x0, 0x80020000}};
  int check = -1052644475;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok985) {
  my_decimal decimal = {{0x4E69C, 0x0, 0x0, 0x40000}};
  int check = 1107327189;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok986) {
  my_decimal decimal = {{0x4E69C, 0x0, 0x0, 0x80040000}};
  int check = -1040156459;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok987) {
  my_decimal decimal = {{0x1E0F3, 0x0, 0x0, 0x30000}};
  int check = 1123434234;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok988) {
  my_decimal decimal = {{0x1E0F3, 0x0, 0x0, 0x80030000}};
  int check = -1024049414;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok989) {
  my_decimal decimal = {{0x1F1DB8B, 0x0, 0x0, 0x50000}};
  int check = 1134764882;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok990) {
  my_decimal decimal = {{0x1F1DB8B, 0x0, 0x0, 0x80050000}};
  int check = -1012718766;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok991) {
  my_decimal decimal = {{0xBC4FF2, 0x0, 0x0, 0x40000}};
  int check = 1150960627;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok992) {
  my_decimal decimal = {{0xBC4FF2, 0x0, 0x0, 0x80040000}};
  int check = -996523021;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok993) {
  my_decimal decimal = {{0xC2EEC182, 0x0, 0x0, 0x60000}};
  int check = 1162634965;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok994) {
  my_decimal decimal = {{0xC2EEC182, 0x0, 0x0, 0x80060000}};
  int check = -984848683;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok995) {
  my_decimal decimal = {{0x499529D9, 0x0, 0x0, 0x50000}};
  int check = 1178657918;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok996) {
  my_decimal decimal = {{0x499529D9, 0x0, 0x0, 0x80050000}};
  int check = -968825730;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok997) {
  my_decimal decimal = {{0x2B6851A1, 0x4C, 0x0, 0x70000}};
  int check = 1191154983;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok998) {
  my_decimal decimal = {{0x2B6851A1, 0x4C, 0x0, 0x80070000}};
  int check = -956328665;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok999) {
  my_decimal decimal = {{0xBE8EF240, 0x1C, 0x0, 0x60000}};
  int check = 1206984720;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1000) {
  my_decimal decimal = {{0xBE8EF240, 0x1C, 0x0, 0x80060000}};
  int check = -940498928;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1001) {
  my_decimal decimal = {{0x41F8C440, 0x1DC1, 0x0, 0x80000}};
  int check = 1218428631;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1002) {
  my_decimal decimal = {{0x41F8C440, 0x1DC1, 0x0, 0x80080000}};
  int check = -929055017;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1003) {
  my_decimal decimal = {{0x73593407, 0xB3A, 0x0, 0x70000}};
  int check = 1234613305;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1004) {
  my_decimal decimal = {{0x73593407, 0xB3A, 0x0, 0x80070000}};
  int check = -912870343;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1005) {
  my_decimal decimal = {{0x6756DB3F, 0xB9F81, 0x0, 0x90000}};
  int check = 1246211788;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1006) {
  my_decimal decimal = {{0x6756DB3F, 0xB9F81, 0x0, 0x80090000}};
  int check = -901271860;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1007) {
  my_decimal decimal = {{0xEB1F0AD2, 0xAB54A98C, 0x0, 0xA0000}};
  int check = 1318267910;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1008) {
  my_decimal decimal = {{0xEB1F0AD2, 0xAB54A98C, 0x0, 0x800A0000}};
  int check = -829215738;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1009) {
  my_decimal decimal = {{0x63223362, 0x5AA382DF, 0xB1, 0xC0000}};
  int check = 1329791163;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1010) {
  my_decimal decimal = {{0x63223362, 0x5AA382DF, 0xB1, 0x800C0000}};
  int check = -817692485;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1011) {
  my_decimal decimal = {{0xF91EAFF2, 0x6D795225, 0x3FD35EB, 0xE0000}};
  int check = 1429448509;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1012) {
  my_decimal decimal = {{0xF91EAFF2, 0x6D795225, 0x3FD35EB, 0x800E0000}};
  int check = -718035139;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1013) {
  my_decimal decimal = {{0x49AD368D, 0xD50F00EE, 0x69B614DE, 0xF0000}};
  int check = 1441663588;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1014) {
  my_decimal decimal = {{0x49AD368D, 0xD50F00EE, 0x69B614DE, 0x800F0000}};
  int check = -705820060;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1015) {
  my_decimal decimal = {{0x63, 0x0, 0x0, 0x0}};
  int check = 1120272384;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1016) {
  my_decimal decimal = {{0x63, 0x0, 0x0, 0x80000000}};
  int check = -1027211264;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1017) {
  my_decimal decimal = {{0x667B, 0x0, 0x0, 0x20000}};
  int check = 1132670157;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1018) {
  my_decimal decimal = {{0x667B, 0x0, 0x0, 0x80020000}};
  int check = -1014813491;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1019) {
  my_decimal decimal = {{0x63, 0x0, 0x0, 0x10000}};
  int check = 1092511334;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1020) {
  my_decimal decimal = {{0x63, 0x0, 0x0, 0x80010000}};
  int check = -1054972314;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1021) {
  my_decimal decimal = {{0x667B, 0x0, 0x0, 0x30000}};
  int check = 1104273736;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1022) {
  my_decimal decimal = {{0x667B, 0x0, 0x0, 0x80030000}};
  int check = -1043209912;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1023) {
  my_decimal decimal = {{0x270F, 0x0, 0x0, 0x20000}};
  int check = 1120402145;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1024) {
  my_decimal decimal = {{0x270F, 0x0, 0x0, 0x80020000}};
  int check = -1027081503;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1025) {
  my_decimal decimal = {{0x286E87, 0x0, 0x0, 0x40000}};
  int check = 1132756124;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1026) {
  my_decimal decimal = {{0x286E87, 0x0, 0x0, 0x80040000}};
  int check = -1014727524;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1027) {
  my_decimal decimal = {{0xF423F, 0x0, 0x0, 0x30000}};
  int check = 1148846064;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1028) {
  my_decimal decimal = {{0xF423F, 0x0, 0x0, 0x80030000}};
  int check = -998637584;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1029) {
  my_decimal decimal = {{0xFCB9337, 0x0, 0x0, 0x50000}};
  int check = 1160093685;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1030) {
  my_decimal decimal = {{0xFCB9337, 0x0, 0x0, 0x80050000}};
  int check = -987389963;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1031) {
  my_decimal decimal = {{0x5F5E0FF, 0x0, 0x0, 0x40000}};
  int check = 1176256512;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1032) {
  my_decimal decimal = {{0x5F5E0FF, 0x0, 0x0, 0x80040000}};
  int check = -971227136;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1033) {
  my_decimal decimal = {{0x2B85E7F7, 0x6, 0x0, 0x60000}};
  int check = 1187973120;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1034) {
  my_decimal decimal = {{0x2B85E7F7, 0x6, 0x0, 0x80060000}};
  int check = -959510528;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1035) {
  my_decimal decimal = {{0x540BE3FF, 0x2, 0x0, 0x50000}};
  int check = 1203982336;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1036) {
  my_decimal decimal = {{0x540BE3FF, 0x2, 0x0, 0x80050000}};
  int check = -943501312;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1037) {
  my_decimal decimal = {{0x4F02F7, 0x269, 0x0, 0x70000}};
  int check = 1216439552;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1038) {
  my_decimal decimal = {{0x4F02F7, 0x269, 0x0, 0x80070000}};
  int check = -931044096;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1039) {
  my_decimal decimal = {{0xD4A50FFF, 0xE8, 0x0, 0x60000}};
  int check = 1232348160;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1040) {
  my_decimal decimal = {{0xD4A50FFF, 0xE8, 0x0, 0x80060000}};
  int check = -915135488;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1041) {
  my_decimal decimal = {{0x1EDD8EF7, 0xF104, 0x0, 0x80000}};
  int check = 1243725376;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1042) {
  my_decimal decimal = {{0x1EDD8EF7, 0xF104, 0x0, 0x80080000}};
  int check = -903758272;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1043) {
  my_decimal decimal = {{0x107A3FFF, 0x5AF3, 0x0, 0x70000}};
  int check = 1259902592;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1044) {
  my_decimal decimal = {{0x107A3FFF, 0x5AF3, 0x0, 0x80070000}};
  int check = -887581056;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1045) {
  my_decimal decimal = {{0xE8C3EF7, 0x5E259C, 0x0, 0x90000}};
  int check = 1271541200;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1046) {
  my_decimal decimal = {{0xE8C3EF7, 0x5E259C, 0x0, 0x80090000}};
  int check = -875942448;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1047) {
  my_decimal decimal = {{0x6FC0FFFF, 0x2386F2, 0x0, 0x80000}};
  int check = 1287568416;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1048) {
  my_decimal decimal = {{0x6FC0FFFF, 0x2386F2, 0x0, 0x80080000}};
  int check = -859915232;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1049) {
  my_decimal decimal = {{0xAEC8FEF7, 0x24C6B0F5, 0x0, 0xA0000}};
  int check = 1300019524;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1050) {
  my_decimal decimal = {{0xAEC8FEF7, 0x24C6B0F5, 0x0, 0x800A0000}};
  int check = -847464124;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1051) {
  my_decimal decimal = {{0xA763FFFF, 0xDE0B6B3, 0x0, 0x90000}};
  int check = 1315859240;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1052) {
  my_decimal decimal = {{0xA763FFFF, 0xDE0B6B3, 0x0, 0x80090000}};
  int check = -831624408;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1053) {
  my_decimal decimal = {{0x4683FEF7, 0x5D9D1FF8, 0xE, 0xB0000}};
  int check = 1327363018;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1054) {
  my_decimal decimal = {{0x4683FEF7, 0x5D9D1FF8, 0xE, 0x800B0000}};
  int check = -820120630;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1055) {
  my_decimal decimal = {{0x630FFFFF, 0x6BC75E2D, 0x5, 0xA0000}};
  int check = 1343554297;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1056) {
  my_decimal decimal = {{0x630FFFFF, 0x6BC75E2D, 0x5, 0x800A0000}};
  int check = -803929351;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1057) {
  my_decimal decimal = {{0x8B8FFEF7, 0x91607CFB, 0x59C, 0xC0000}};
  int check = 1355116733;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1058) {
  my_decimal decimal = {{0x8B8FFEF7, 0x91607CFB, 0x59C, 0x800C0000}};
  int check = -792366915;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1059) {
  my_decimal decimal = {{0x9, 0x0, 0x0, 0x0}};
  int check = 1091567616;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1060) {
  my_decimal decimal = {{0x9, 0x0, 0x0, 0x80000000}};
  int check = -1055916032;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1061) {
  my_decimal decimal = {{0x951, 0x0, 0x0, 0x20000}};
  int check = 1103023309;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1062) {
  my_decimal decimal = {{0x951, 0x0, 0x0, 0x80020000}};
  int check = -1044460339;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1063) {
  my_decimal decimal = {{0x9, 0x0, 0x0, 0x10000}};
  int check = 1063675494;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1064) {
  my_decimal decimal = {{0x9, 0x0, 0x0, 0x80010000}};
  int check = -1083808154;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1065) {
  my_decimal decimal = {{0x951, 0x0, 0x0, 0x30000}};
  int check = 1075356631;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1066) {
  my_decimal decimal = {{0x951, 0x0, 0x0, 0x80030000}};
  int check = -1072127017;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1067) {
  my_decimal decimal = {{0x63, 0x0, 0x0, 0x20000}};
  int check = 1065185444;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1068) {
  my_decimal decimal = {{0x63, 0x0, 0x0, 0x80020000}};
  int check = -1082298204;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1069) {
  my_decimal decimal = {{0x667B, 0x0, 0x0, 0x40000}};
  int check = 1076356973;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1070) {
  my_decimal decimal = {{0x667B, 0x0, 0x0, 0x80040000}};
  int check = -1071126675;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1071) {
  my_decimal decimal = {{0x3E7, 0x0, 0x0, 0x30000}};
  int check = 1065336439;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1072) {
  my_decimal decimal = {{0x3E7, 0x0, 0x0, 0x80030000}};
  int check = -1082147209;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1073) {
  my_decimal decimal = {{0x40A1F, 0x0, 0x0, 0x50000}};
  int check = 1076457007;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1074) {
  my_decimal decimal = {{0x40A1F, 0x0, 0x0, 0x80050000}};
  int check = -1071026641;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1075) {
  my_decimal decimal = {{0x270F, 0x0, 0x0, 0x40000}};
  int check = 1065351538;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1076) {
  my_decimal decimal = {{0x270F, 0x0, 0x0, 0x80040000}};
  int check = -1082132110;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1077) {
  my_decimal decimal = {{0x286E87, 0x0, 0x0, 0x60000}};
  int check = 1076467010;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1078) {
  my_decimal decimal = {{0x286E87, 0x0, 0x0, 0x80060000}};
  int check = -1071016638;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1079) {
  my_decimal decimal = {{0x1869F, 0x0, 0x0, 0x50000}};
  int check = 1065353048;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1080) {
  my_decimal decimal = {{0x1869F, 0x0, 0x0, 0x80050000}};
  int check = -1082130600;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1081) {
  my_decimal decimal = {{0x1945A97, 0x0, 0x0, 0x70000}};
  int check = 1076468010;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1082) {
  my_decimal decimal = {{0x1945A97, 0x0, 0x0, 0x80070000}};
  int check = -1071015638;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1083) {
  my_decimal decimal = {{0xF423F, 0x0, 0x0, 0x60000}};
  int check = 1065353199;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1084) {
  my_decimal decimal = {{0xF423F, 0x0, 0x0, 0x80060000}};
  int check = -1082130449;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1085) {
  my_decimal decimal = {{0xFCB9337, 0x0, 0x0, 0x80000}};
  int check = 1076468110;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1086) {
  my_decimal decimal = {{0xFCB9337, 0x0, 0x0, 0x80080000}};
  int check = -1071015538;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1087) {
  my_decimal decimal = {{0x98967F, 0x0, 0x0, 0x70000}};
  int check = 1065353214;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1088) {
  my_decimal decimal = {{0x98967F, 0x0, 0x0, 0x80070000}};
  int check = -1082130434;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1089) {
  my_decimal decimal = {{0x9DF3C977, 0x0, 0x0, 0x90000}};
  int check = 1076468120;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1090) {
  my_decimal decimal = {{0x9DF3C977, 0x0, 0x0, 0x80090000}};
  int check = -1071015528;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1091) {
  my_decimal decimal = {{0x5F5E0FF, 0x0, 0x0, 0x80000}};
  int check = 1065353216;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1092) {
  my_decimal decimal = {{0x5F5E0FF, 0x0, 0x0, 0x80080000}};
  int check = -1082130432;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1093) {
  my_decimal decimal = {{0x2B85E7F7, 0x6, 0x0, 0xA0000}};
  int check = 1076468121;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1094) {
  my_decimal decimal = {{0x2B85E7F7, 0x6, 0x0, 0x800A0000}};
  int check = -1071015527;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1095) {
  my_decimal decimal = {{0x3B9AC9FF, 0x0, 0x0, 0x90000}};
  int check = 1065353216;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1096) {
  my_decimal decimal = {{0x3B9AC9FF, 0x0, 0x0, 0x80090000}};
  int check = -1082130432;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1097) {
  my_decimal decimal = {{0xB33B18F7, 0x3D, 0x0, 0xB0000}};
  int check = 1076468122;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1098) {
  my_decimal decimal = {{0xB33B18F7, 0x3D, 0x0, 0x800B0000}};
  int check = -1071015526;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1099) {
  my_decimal decimal = {{0x540BE3FF, 0x2, 0x0, 0xA0000}};
  int check = 1065353216;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1100) {
  my_decimal decimal = {{0x540BE3FF, 0x2, 0x0, 0x800A0000}};
  int check = -1082130432;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1101) {
  my_decimal decimal = {{0x4F02F7, 0x269, 0x0, 0xC0000}};
  int check = 1076468122;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1102) {
  my_decimal decimal = {{0x4F02F7, 0x269, 0x0, 0x800C0000}};
  int check = -1071015526;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1103) {
  my_decimal decimal = {{0x630FFFFF, 0x6BC75E2D, 0x5, 0x140000}};
  int check = 1065353216;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1104) {
  my_decimal decimal = {{0x630FFFFF, 0x6BC75E2D, 0x5, 0x80140000}};
  int check = -1082130432;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1105) {
  my_decimal decimal = {{0x8B8FFEF7, 0x91607CFB, 0x59C, 0x160000}};
  int check = 1076468122;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1106) {
  my_decimal decimal = {{0x8B8FFEF7, 0x91607CFB, 0x59C, 0x80160000}};
  int check = -1071015526;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1107) {
  my_decimal decimal = {{0x0, 0x0, 0x0, 0x80000000}};
  int check = -2147483648;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1108) {
  my_decimal decimal = {{0x0, 0x0, 0x0, 0x0}};
  int check = 0;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1109) {
  my_decimal decimal = {{0x0, 0x0, 0x0, 0x80010000}};
  int check = -2147483648;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1110) {
  my_decimal decimal = {{0x0, 0x0, 0x0, 0x10000}};
  int check = 0;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1111) {
  my_decimal decimal = {{0x0, 0x0, 0x0, 0x80020000}};
  int check = -2147483648;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1112) {
  my_decimal decimal = {{0x0, 0x0, 0x0, 0x20000}};
  int check = 0;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1113) {
  my_decimal decimal = {{0x0, 0x0, 0x0, 0x800E0000}};
  int check = -2147483648;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1114) {
  my_decimal decimal = {{0x0, 0x0, 0x0, 0xE0000}};
  int check = 0;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1115) {
  my_decimal decimal = {{0x0, 0x0, 0x0, 0x801B0000}};
  int check = -2147483648;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1116) {
  my_decimal decimal = {{0x0, 0x0, 0x0, 0x1B0000}};
  int check = 0;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1117) {
  my_decimal decimal = {{0x0, 0x0, 0x0, 0x801C0000}};
  int check = -2147483648;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1118) {
  my_decimal decimal = {{0x0, 0x0, 0x0, 0x1C0000}};
  int check = 0;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1119) {
  my_decimal decimal = {{0x7FFFFFFE, 0x0, 0x0, 0x0}};
  int check = 1325400064;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1120) {
  my_decimal decimal = {{0x7FFFFFFE, 0x0, 0x0, 0x80000000}};
  int check = -822083584;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1121) {
  my_decimal decimal = {{0x7FFFFDEE, 0x84, 0x0, 0x20000}};
  int check = 1336514970;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1122) {
  my_decimal decimal = {{0x7FFFFDEE, 0x84, 0x0, 0x80020000}};
  int check = -810968678;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1123) {
  my_decimal decimal = {{0xFFFFFF38, 0x31, 0x0, 0x20000}};
  int check = 1325400064;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1124) {
  my_decimal decimal = {{0xFFFFFF38, 0x31, 0x0, 0x80020000}};
  int check = -822083584;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1125) {
  my_decimal decimal = {{0xFFFF30F8, 0x33C1, 0x0, 0x40000}};
  int check = 1336514970;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1126) {
  my_decimal decimal = {{0xFFFF30F8, 0x33C1, 0x0, 0x80040000}};
  int check = -810968678;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1127) {
  my_decimal decimal = {{0xFFFFFF9B, 0x31, 0x0, 0x20000}};
  int check = 1325400064;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1128) {
  my_decimal decimal = {{0xFFFFFF9B, 0x31, 0x0, 0x80020000}};
  int check = -822083584;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1129) {
  my_decimal decimal = {{0xFFFF9773, 0x33C1, 0x0, 0x40000}};
  int check = 1336514970;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1130) {
  my_decimal decimal = {{0xFFFF9773, 0x33C1, 0x0, 0x80040000}};
  int check = -810968678;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1131) {
  my_decimal decimal = {{0x589BFFFF, 0xC5D1494C, 0x6F05B59, 0x120000}};
  int check = 1325400064;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1132) {
  my_decimal decimal = {{0x589BFFFF, 0xC5D1494C, 0x6F05B59, 0x80120000}};
  int check = -822083584;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1133) {
  my_decimal decimal = {{0x2C25FFE6, 0xFA2A1667, 0xB7E174CA, 0x130000}};
  int check = 1336514970;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1134) {
  my_decimal decimal = {{0x2C25FFE6, 0xFA2A1667, 0xB7E174CA, 0x80130000}};
  int check = -810968678;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1135) {
  my_decimal decimal = {{0x7FFFFFFE, 0x0, 0x0, 0x20000}};
  int check = 1269028618;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1136) {
  my_decimal decimal = {{0x7FFFFFFE, 0x0, 0x0, 0x80020000}};
  int check = -878455030;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1137) {
  my_decimal decimal = {{0x7FFFFDEE, 0x84, 0x0, 0x40000}};
  int check = 1280906887;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1138) {
  my_decimal decimal = {{0x7FFFFDEE, 0x84, 0x0, 0x80040000}};
  int check = -866576761;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1139) {
  my_decimal decimal = {{0x7FFFFFFE, 0x0, 0x0, 0x70000}};
  int check = 1129758613;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1140) {
  my_decimal decimal = {{0x7FFFFFFE, 0x0, 0x0, 0x80070000}};
  int check = -1017725035;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1141) {
  my_decimal decimal = {{0x7FFFFDEE, 0x84, 0x0, 0x90000}};
  int check = 1141785939;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1142) {
  my_decimal decimal = {{0x7FFFFDEE, 0x84, 0x0, 0x80090000}};
  int check = -1005697709;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1143) {
  my_decimal decimal = {{0x7FFFFFFE, 0x0, 0x0, 0x90000}};
  int check = 1074360415;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1144) {
  my_decimal decimal = {{0x7FFFFFFE, 0x0, 0x0, 0x80090000}};
  int check = -1073123233;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1145) {
  my_decimal decimal = {{0x7FFFFDEE, 0x84, 0x0, 0xB0000}};
  int check = 1085676363;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1146) {
  my_decimal decimal = {{0x7FFFFDEE, 0x84, 0x0, 0x800B0000}};
  int check = -1061807285;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1147) {
  my_decimal decimal = {{0x7FFFFFFE, 0x0, 0x0, 0xA0000}};
  int check = 1046210303;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1148) {
  my_decimal decimal = {{0x7FFFFFFE, 0x0, 0x0, 0x800A0000}};
  int check = -1101273345;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1149) {
  my_decimal decimal = {{0x7FFFFDEE, 0x84, 0x0, 0xC0000}};
  int check = 1058123631;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1150) {
  my_decimal decimal = {{0x7FFFFDEE, 0x84, 0x0, 0x800C0000}};
  int check = -1089360017;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1151) {
  my_decimal decimal = {{0x7FFFFFFE, 0x0, 0x0, 0x1C0000}};
  int check = 545097654;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1152) {
  my_decimal decimal = {{0x7FFFFFFE, 0x0, 0x0, 0x801C0000}};
  int check = -1602385994;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1153) {
  my_decimal decimal = {{0x5333332E, 0x1, 0x0, 0x1C0000}};
  int check = 556267189;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1154) {
  my_decimal decimal = {{0x5333332E, 0x1, 0x0, 0x801C0000}};
  int check = -1591216459;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1155) {
  my_decimal decimal = {{0x7FFFFFFF, 0x0, 0x0, 0x0}};
  int check = 1325400064;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1156) {
  my_decimal decimal = {{0x7FFFFFFF, 0x0, 0x0, 0x80000000}};
  int check = -822083584;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1157) {
  my_decimal decimal = {{0x7FFFFEF7, 0x84, 0x0, 0x20000}};
  int check = 1336514970;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1158) {
  my_decimal decimal = {{0x7FFFFEF7, 0x84, 0x0, 0x80020000}};
  int check = -810968678;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1159) {
  my_decimal decimal = {{0xFFFFFF9C, 0x31, 0x0, 0x20000}};
  int check = 1325400064;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1160) {
  my_decimal decimal = {{0xFFFFFF9C, 0x31, 0x0, 0x80020000}};
  int check = -822083584;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1161) {
  my_decimal decimal = {{0xFFFF987C, 0x33C1, 0x0, 0x40000}};
  int check = 1336514970;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1162) {
  my_decimal decimal = {{0xFFFF987C, 0x33C1, 0x0, 0x80040000}};
  int check = -810968678;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1163) {
  my_decimal decimal = {{0xFFFFFFFF, 0x31, 0x0, 0x20000}};
  int check = 1325400064;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1164) {
  my_decimal decimal = {{0xFFFFFFFF, 0x31, 0x0, 0x80020000}};
  int check = -822083584;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1165) {
  my_decimal decimal = {{0xFFFFFEF7, 0x33C1, 0x0, 0x40000}};
  int check = 1336514970;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1166) {
  my_decimal decimal = {{0xFFFFFEF7, 0x33C1, 0x0, 0x80040000}};
  int check = -810968678;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1167) {
  my_decimal decimal = {{0xFFFFFFFF, 0xD3B1FFFF, 0x6F05B59, 0x120000}};
  int check = 1325400064;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1168) {
  my_decimal decimal = {{0xFFFFFFFF, 0xD3B1FFFF, 0x6F05B59, 0x80120000}};
  int check = -822083584;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1169) {
  my_decimal decimal = {{0xFFFFFFE6, 0x69ECFFFF, 0xB7E174CC, 0x130000}};
  int check = 1336514970;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1170) {
  my_decimal decimal = {{0xFFFFFFE6, 0x69ECFFFF, 0xB7E174CC, 0x80130000}};
  int check = -810968678;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1171) {
  my_decimal decimal = {{0x7FFFFFFF, 0x0, 0x0, 0x20000}};
  int check = 1269028618;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1172) {
  my_decimal decimal = {{0x7FFFFFFF, 0x0, 0x0, 0x80020000}};
  int check = -878455030;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1173) {
  my_decimal decimal = {{0x7FFFFEF7, 0x84, 0x0, 0x40000}};
  int check = 1280906887;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1174) {
  my_decimal decimal = {{0x7FFFFEF7, 0x84, 0x0, 0x80040000}};
  int check = -866576761;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1175) {
  my_decimal decimal = {{0x7FFFFFFF, 0x0, 0x0, 0x70000}};
  int check = 1129758613;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1176) {
  my_decimal decimal = {{0x7FFFFFFF, 0x0, 0x0, 0x80070000}};
  int check = -1017725035;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1177) {
  my_decimal decimal = {{0x7FFFFEF7, 0x84, 0x0, 0x90000}};
  int check = 1141785939;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1178) {
  my_decimal decimal = {{0x7FFFFEF7, 0x84, 0x0, 0x80090000}};
  int check = -1005697709;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1179) {
  my_decimal decimal = {{0x7FFFFFFF, 0x0, 0x0, 0x90000}};
  int check = 1074360415;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1180) {
  my_decimal decimal = {{0x7FFFFFFF, 0x0, 0x0, 0x80090000}};
  int check = -1073123233;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1181) {
  my_decimal decimal = {{0x7FFFFEF7, 0x84, 0x0, 0xB0000}};
  int check = 1085676363;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1182) {
  my_decimal decimal = {{0x7FFFFEF7, 0x84, 0x0, 0x800B0000}};
  int check = -1061807285;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1183) {
  my_decimal decimal = {{0x7FFFFFFF, 0x0, 0x0, 0xA0000}};
  int check = 1046210303;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1184) {
  my_decimal decimal = {{0x7FFFFFFF, 0x0, 0x0, 0x800A0000}};
  int check = -1101273345;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1185) {
  my_decimal decimal = {{0x7FFFFEF7, 0x84, 0x0, 0xC0000}};
  int check = 1058123631;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1186) {
  my_decimal decimal = {{0x7FFFFEF7, 0x84, 0x0, 0x800C0000}};
  int check = -1089360017;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1187) {
  my_decimal decimal = {{0x7FFFFFFF, 0x0, 0x0, 0x1C0000}};
  int check = 545097654;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1188) {
  my_decimal decimal = {{0x7FFFFFFF, 0x0, 0x0, 0x801C0000}};
  int check = -1602385994;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1189) {
  my_decimal decimal = {{0x53333331, 0x1, 0x0, 0x1C0000}};
  int check = 556267189;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1190) {
  my_decimal decimal = {{0x53333331, 0x1, 0x0, 0x801C0000}};
  int check = -1591216459;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1191) {
  my_decimal decimal = {{0x80000000, 0x0, 0x0, 0x0}};
  int check = 1325400064;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1192) {
  my_decimal decimal = {{0x80000000, 0x0, 0x0, 0x80000000}};
  int check = -822083584;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1193) {
  my_decimal decimal = {{0x80000000, 0x84, 0x0, 0x20000}};
  int check = 1336514970;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1194) {
  my_decimal decimal = {{0x80000000, 0x84, 0x0, 0x80020000}};
  int check = -810968678;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1195) {
  my_decimal decimal = {{0x0, 0x32, 0x0, 0x20000}};
  int check = 1325400064;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1196) {
  my_decimal decimal = {{0x0, 0x32, 0x0, 0x80020000}};
  int check = -822083584;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1197) {
  my_decimal decimal = {{0x0, 0x33C2, 0x0, 0x40000}};
  int check = 1336514970;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1198) {
  my_decimal decimal = {{0x0, 0x33C2, 0x0, 0x80040000}};
  int check = -810968678;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1199) {
  my_decimal decimal = {{0x63, 0x32, 0x0, 0x20000}};
  int check = 1325400064;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1200) {
  my_decimal decimal = {{0x63, 0x32, 0x0, 0x80020000}};
  int check = -822083584;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1201) {
  my_decimal decimal = {{0x667B, 0x33C2, 0x0, 0x40000}};
  int check = 1336514970;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1202) {
  my_decimal decimal = {{0x667B, 0x33C2, 0x0, 0x80040000}};
  int check = -810968678;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1203) {
  my_decimal decimal = {{0xA763FFFF, 0xE192B6B3, 0x6F05B59, 0x120000}};
  int check = 1325400064;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1204) {
  my_decimal decimal = {{0xA763FFFF, 0xE192B6B3, 0x6F05B59, 0x80120000}};
  int check = -822083584;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1205) {
  my_decimal decimal = {{0xD3D9FFE6, 0xD9AFE998, 0xB7E174CD, 0x130000}};
  int check = 1336514970;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1206) {
  my_decimal decimal = {{0xD3D9FFE6, 0xD9AFE998, 0xB7E174CD, 0x80130000}};
  int check = -810968678;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1207) {
  my_decimal decimal = {{0x80000000, 0x0, 0x0, 0x20000}};
  int check = 1269028618;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1208) {
  my_decimal decimal = {{0x80000000, 0x0, 0x0, 0x80020000}};
  int check = -878455030;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1209) {
  my_decimal decimal = {{0x80000000, 0x84, 0x0, 0x40000}};
  int check = 1280906887;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1210) {
  my_decimal decimal = {{0x80000000, 0x84, 0x0, 0x80040000}};
  int check = -866576761;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1211) {
  my_decimal decimal = {{0x80000000, 0x0, 0x0, 0x70000}};
  int check = 1129758613;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1212) {
  my_decimal decimal = {{0x80000000, 0x0, 0x0, 0x80070000}};
  int check = -1017725035;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1213) {
  my_decimal decimal = {{0x80000000, 0x84, 0x0, 0x90000}};
  int check = 1141785939;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1214) {
  my_decimal decimal = {{0x80000000, 0x84, 0x0, 0x80090000}};
  int check = -1005697709;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1215) {
  my_decimal decimal = {{0x80000000, 0x0, 0x0, 0x90000}};
  int check = 1074360415;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1216) {
  my_decimal decimal = {{0x80000000, 0x0, 0x0, 0x80090000}};
  int check = -1073123233;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1217) {
  my_decimal decimal = {{0x80000000, 0x84, 0x0, 0xB0000}};
  int check = 1085676363;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1218) {
  my_decimal decimal = {{0x80000000, 0x84, 0x0, 0x800B0000}};
  int check = -1061807285;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1219) {
  my_decimal decimal = {{0x80000000, 0x0, 0x0, 0xA0000}};
  int check = 1046210303;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1220) {
  my_decimal decimal = {{0x80000000, 0x0, 0x0, 0x800A0000}};
  int check = -1101273345;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1221) {
  my_decimal decimal = {{0x80000000, 0x84, 0x0, 0xC0000}};
  int check = 1058123631;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1222) {
  my_decimal decimal = {{0x80000000, 0x84, 0x0, 0x800C0000}};
  int check = -1089360017;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1223) {
  my_decimal decimal = {{0x80000000, 0x0, 0x0, 0x1C0000}};
  int check = 545097654;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1224) {
  my_decimal decimal = {{0x80000000, 0x0, 0x0, 0x801C0000}};
  int check = -1602385994;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1225) {
  my_decimal decimal = {{0x53333333, 0x1, 0x0, 0x1C0000}};
  int check = 556267189;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1226) {
  my_decimal decimal = {{0x53333333, 0x1, 0x0, 0x801C0000}};
  int check = -1591216459;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1227) {
  my_decimal decimal = {{0x66A422EB, 0x8DF3404F, 0x204FCE7E, 0x1C0000}};
  int check = 1065353216;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1228) {
  my_decimal decimal = {{0x66A422EB, 0x8DF3404F, 0x204FCE7E, 0x801C0000}};
  int check = -1082130432;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1229) {
  my_decimal decimal = {{0xCFFFC2EF, 0x2B5E3738, 0x55A0499C, 0x1C0000}};
  int check = 1076468122;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1230) {
  my_decimal decimal = {{0xCFFFC2EF, 0x2B5E3738, 0x55A0499C, 0x801C0000}};
  int check = -1071015526;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1231) {
  my_decimal decimal = {{0xB0A8E50B, 0x2D8FFCCB, 0x204FCEBF, 0x1C0000}};
  int check = 1065353217;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1232) {
  my_decimal decimal = {{0xB0A8E50B, 0x2D8FFCCB, 0x204FCEBF, 0x801C0000}};
  int check = -1082130431;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1233) {
  my_decimal decimal = {{0xFA8C5EF7, 0x6BF0C44E, 0x55A04A47, 0x1C0000}};
  int check = 1076468124;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1234) {
  my_decimal decimal = {{0xFA8C5EF7, 0x6BF0C44E, 0x55A04A47, 0x801C0000}};
  int check = -1071015524;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1235) {
  my_decimal decimal = {{0x12397676, 0x8DF35077, 0x204FCE7E, 0x1C0000}};
  int check = 1065353216;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1236) {
  my_decimal decimal = {{0x12397676, 0x8DF35077, 0x204FCE7E, 0x801C0000}};
  int check = -1082130432;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1237) {
  my_decimal decimal = {{0x56B1E052, 0x2B5E6208, 0x55A0499C, 0x1C0000}};
  int check = 1076468122;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1238) {
  my_decimal decimal = {{0x56B1E052, 0x2B5E6208, 0x55A0499C, 0x801C0000}};
  int check = -1071015526;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1239) {
  my_decimal decimal = {{0x5C3E3896, 0x2D900CF3, 0x204FCEBF, 0x1C0000}};
  int check = 1065353217;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1240) {
  my_decimal decimal = {{0x5C3E3896, 0x2D900CF3, 0x204FCEBF, 0x801C0000}};
  int check = -1082130431;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1241) {
  my_decimal decimal = {{0x813E7C5A, 0x6BF0EF1E, 0x55A04A47, 0x1C0000}};
  int check = 1076468124;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1242) {
  my_decimal decimal = {{0x813E7C5A, 0x6BF0EF1E, 0x55A04A47, 0x801C0000}};
  int check = -1071015524;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1243) {
  my_decimal decimal = {{0x59475B56, 0x8DF35077, 0x204FCE7E, 0x1C0000}};
  int check = 1065353216;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1244) {
  my_decimal decimal = {{0x59475B56, 0x8DF35077, 0x204FCE7E, 0x801C0000}};
  int check = -1082130432;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1245) {
  my_decimal decimal = {{0x12FD1871, 0x2B5E6209, 0x55A0499C, 0x1C0000}};
  int check = 1076468122;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1246) {
  my_decimal decimal = {{0x12FD1871, 0x2B5E6209, 0x55A0499C, 0x801C0000}};
  int check = -1071015526;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1247) {
  my_decimal decimal = {{0xA34C1D76, 0x2D900CF3, 0x204FCEBF, 0x1C0000}};
  int check = 1065353217;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1248) {
  my_decimal decimal = {{0xA34C1D76, 0x2D900CF3, 0x204FCEBF, 0x801C0000}};
  int check = -1082130431;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1249) {
  my_decimal decimal = {{0x3D89B479, 0x6BF0EF1F, 0x55A04A47, 0x1C0000}};
  int check = 1076468124;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1250) {
  my_decimal decimal = {{0x3D89B479, 0x6BF0EF1F, 0x55A04A47, 0x801C0000}};
  int check = -1071015524;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1251) {
  my_decimal decimal = {{0x6FCCEDA1, 0x1CA28F09, 0xD3C2, 0x180000}};
  int check = 1065353216;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1252) {
  my_decimal decimal = {{0x6FCCEDA1, 0x1CA28F09, 0xD3C2, 0x80180000}};
  int check = -1082130432;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1253) {
  my_decimal decimal = {{0xBB21FBA9, 0xA44610C4, 0xDB33EF, 0x1A0000}};
  int check = 1076468122;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1254) {
  my_decimal decimal = {{0xBB21FBA9, 0xA44610C4, 0xDB33EF, 0x801A0000}};
  int check = -1071015526;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1255) {
  my_decimal decimal = {{0xD66C8E3, 0x1E4A1341, 0xD3C2, 0x180000}};
  int check = 1065353218;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1256) {
  my_decimal decimal = {{0xD66C8E3, 0x1E4A1341, 0xD3C2, 0x80180000}};
  int check = -1082130430;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1257) {
  my_decimal decimal = {{0xDF65F2FB, 0x5AADEE56, 0xDB33F1, 0x1A0000}};
  int check = 1076468124;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1258) {
  my_decimal decimal = {{0xDF65F2FB, 0x5AADEE56, 0xDB33F1, 0x801A0000}};
  int check = -1071015524;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1259) {
  my_decimal decimal = {{0xEC786C84, 0x8DF380EE, 0x204FCE7E, 0x1C0000}};
  int check = 1065353217;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1260) {
  my_decimal decimal = {{0xEC786C84, 0x8DF380EE, 0x204FCE7E, 0x801C0000}};
  int check = -1082130431;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1261) {
  my_decimal decimal = {{0x25D8B92B, 0x2B5EE279, 0x55A0499C, 0x1C0000}};
  int check = 1076468122;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1262) {
  my_decimal decimal = {{0x25D8B92B, 0x2B5EE279, 0x55A0499C, 0x801C0000}};
  int check = -1071015526;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1263) {
  my_decimal decimal = {{0x367D2EA4, 0x2D903D6B, 0x204FCEBF, 0x1C0000}};
  int check = 1065353218;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1264) {
  my_decimal decimal = {{0x367D2EA4, 0x2D903D6B, 0x204FCEBF, 0x801C0000}};
  int check = -1082130430;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1265) {
  my_decimal decimal = {{0x50655533, 0x6BF16F8F, 0x55A04A47, 0x1C0000}};
  int check = 1076468124;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1266) {
  my_decimal decimal = {{0x50655533, 0x6BF16F8F, 0x55A04A47, 0x801C0000}};
  int check = -1071015524;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1267) {
  my_decimal decimal = {{0x14F97C89, 0xDAFEC353, 0x33B2E3F, 0x1B0000}};
  int check = 1065353217;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1268) {
  my_decimal decimal = {{0x14F97C89, 0xDAFEC353, 0x33B2E3F, 0x801B0000}};
  int check = -1082130431;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1269) {
  my_decimal decimal = {{0xABD3642E, 0x2B5F3819, 0x55A0499C, 0x1C0000}};
  int check = 1076468122;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1270) {
  my_decimal decimal = {{0xABD3642E, 0x2B5F3819, 0x55A0499C, 0x801C0000}};
  int check = -1071015526;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1271) {
  my_decimal decimal = {{0xB5F9F659, 0x515B3C92, 0x33B2E46, 0x1B0000}};
  int check = 1065353218;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1272) {
  my_decimal decimal = {{0xB5F9F659, 0x515B3C92, 0x33B2E46, 0x801B0000}};
  int check = -1082130430;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1273) {
  my_decimal decimal = {{0xD6600036, 0x6BF1C52F, 0x55A04A47, 0x1C0000}};
  int check = 1076468124;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1274) {
  my_decimal decimal = {{0xD6600036, 0x6BF1C52F, 0x55A04A47, 0x801C0000}};
  int check = -1071015524;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1275) {
  my_decimal decimal = {{0x33865164, 0x8DF380EF, 0x204FCE7E, 0x1C0000}};
  int check = 1065353217;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1276) {
  my_decimal decimal = {{0x33865164, 0x8DF380EF, 0x204FCE7E, 0x801C0000}};
  int check = -1082130431;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1277) {
  my_decimal decimal = {{0xE223F149, 0x2B5EE279, 0x55A0499C, 0x1C0000}};
  int check = 1076468122;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1278) {
  my_decimal decimal = {{0xE223F149, 0x2B5EE279, 0x55A0499C, 0x801C0000}};
  int check = -1071015526;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1279) {
  my_decimal decimal = {{0x7D8B1384, 0x2D903D6B, 0x204FCEBF, 0x1C0000}};
  int check = 1065353218;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1280) {
  my_decimal decimal = {{0x7D8B1384, 0x2D903D6B, 0x204FCEBF, 0x801C0000}};
  int check = -1082130430;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1281) {
  my_decimal decimal = {{0xCB08D51, 0x6BF16F90, 0x55A04A47, 0x1C0000}};
  int check = 1076468124;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1282) {
  my_decimal decimal = {{0xCB08D51, 0x6BF16F90, 0x55A04A47, 0x801C0000}};
  int check = -1071015524;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1283) {
  my_decimal decimal = {{0x8603D8DE, 0x2EE4C08A, 0x84595, 0x190000}};
  int check = 1065353218;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1284) {
  my_decimal decimal = {{0x8603D8DE, 0x2EE4C08A, 0x84595, 0x80190000}};
  int check = -1082130430;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1285) {
  my_decimal decimal = {{0xB9FB7DCE, 0x8ACB4F64, 0x890076D, 0x1B0000}};
  int check = 1076468124;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1286) {
  my_decimal decimal = {{0xB9FB7DCE, 0x8ACB4F64, 0x890076D, 0x801B0000}};
  int check = -1071015524;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1287) {
  my_decimal decimal = {{0x0, 0x80000200, 0x1, 0x0}};
  int check = 1606418433;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1288) {
  my_decimal decimal = {{0x0, 0x80000200, 0x1, 0x80000000}};
  int check = -541065215;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1289) {
  my_decimal decimal = {{0x0, 0x80021200, 0x18D, 0x20000}};
  int check = 1618896488;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1290) {
  my_decimal decimal = {{0x0, 0x80021200, 0x18D, 0x80020000}};
  int check = -528587160;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1291) {
  my_decimal decimal = {{0x801, 0x80000100, 0x1, 0x0}};
  int check = 1606418432;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1292) {
  my_decimal decimal = {{0x801, 0x80000100, 0x1, 0x80000000}};
  int check = -541065216;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1293) {
  my_decimal decimal = {{0x84909, 0x80010900, 0x18D, 0x20000}};
  int check = 1618896487;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1294) {
  my_decimal decimal = {{0x84909, 0x80010900, 0x18D, 0x80020000}};
  int check = -528587161;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1295) {
  my_decimal decimal = {{0x800, 0x80000100, 0x1, 0x0}};
  int check = 1606418432;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1296) {
  my_decimal decimal = {{0x800, 0x80000100, 0x1, 0x80000000}};
  int check = -541065216;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1297) {
  my_decimal decimal = {{0x84800, 0x80010900, 0x18D, 0x20000}};
  int check = 1618896487;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1298) {
  my_decimal decimal = {{0x84800, 0x80010900, 0x18D, 0x80020000}};
  int check = -528587161;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1299) {
  my_decimal decimal = {{0x0, 0x80000000, 0x1, 0x0}};
  int check = 1606418432;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1300) {
  my_decimal decimal = {{0x0, 0x80000000, 0x1, 0x80000000}};
  int check = -541065216;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1301) {
  my_decimal decimal = {{0x0, 0x80000000, 0x18D, 0x20000}};
  int check = 1618896486;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1302) {
  my_decimal decimal = {{0x0, 0x80000000, 0x18D, 0x80020000}};
  int check = -528587162;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1303) {
  my_decimal decimal = {{0x7355BB0F, 0xCB, 0x0, 0x70000}};
  int check = 1202367147;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1304) {
  my_decimal decimal = {{0x7355BB0F, 0xCB, 0x0, 0x80070000}};
  int check = -945116501;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1305) {
  my_decimal decimal = {{0x63BEA287, 0xD29A, 0x0, 0x90000}};
  int check = 1214390819;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1306) {
  my_decimal decimal = {{0x63BEA287, 0xD29A, 0x0, 0x80090000}};
  int check = -933092829;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1307) {
  my_decimal decimal = {{0x815358B6, 0x7F2, 0x0, 0x80000}};
  int check = 1202367147;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1308) {
  my_decimal decimal = {{0x815358B6, 0x7F2, 0x0, 0x80080000}};
  int check = -945116501;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1309) {
  my_decimal decimal = {{0xDF46D466, 0x83A07, 0x0, 0xA0000}};
  int check = 1214390818;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1310) {
  my_decimal decimal = {{0xDF46D466, 0x83A07, 0x0, 0x800A0000}};
  int check = -933092830;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1311) {
  my_decimal decimal = {{0x815358B5, 0x7F2, 0x0, 0x80000}};
  int check = 1202367146;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1312) {
  my_decimal decimal = {{0x815358B5, 0x7F2, 0x0, 0x80080000}};
  int check = -945116502;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1313) {
  my_decimal decimal = {{0xDF46D35D, 0x83A07, 0x0, 0xA0000}};
  int check = 1214390818;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1314) {
  my_decimal decimal = {{0xDF46D35D, 0x83A07, 0x0, 0x800A0000}};
  int check = -933092830;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1315) {
  my_decimal decimal = {{0x585540FD, 0x14, 0x0, 0x60000}};
  int check = 1202367146;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1316) {
  my_decimal decimal = {{0x585540FD, 0x14, 0x0, 0x80060000}};
  int check = -945116502;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1317) {
  my_decimal decimal = {{0x704045E5, 0x150F, 0x0, 0x80000}};
  int check = 1214390817;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1318) {
  my_decimal decimal = {{0x704045E5, 0x150F, 0x0, 0x80080000}};
  int check = -933092831;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1319) {
  my_decimal decimal = {{0x1A2CE9D9, 0xBC16D9ED, 0x1, 0x120000}};
  int check = 1107296257;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1320) {
  my_decimal decimal = {{0x1A2CE9D9, 0xBC16D9ED, 0x1, 0x80120000}};
  int check = -1040187391;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1321) {
  my_decimal decimal = {{0x187E11A1, 0xB3A79670, 0x1CB, 0x140000}};
  int check = 1118411163;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1322) {
  my_decimal decimal = {{0x187E11A1, 0xB3A79670, 0x1CB, 0x80140000}};
  int check = -1029072485;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1323) {
  my_decimal decimal = {{0x817CCA82, 0x4A, 0x0, 0xA0000}};
  int check = 1107296257;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1324) {
  my_decimal decimal = {{0x817CCA82, 0x4A, 0x0, 0x800A0000}};
  int check = -1040187391;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1325) {
  my_decimal decimal = {{0xA2DA092, 0x4D20, 0x0, 0xC0000}};
  int check = 1118411162;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1326) {
  my_decimal decimal = {{0xA2DA092, 0x4D20, 0x0, 0x800C0000}};
  int check = -1029072486;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1327) {
  my_decimal decimal = {{0x3E443CD1, 0x5FD79ED2, 0x6765C7FB, 0x1B0000}};
  int check = 1107296257;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1328) {
  my_decimal decimal = {{0x3E443CD1, 0x5FD79ED2, 0x6765C7FB, 0x801B0000}};
  int check = -1040187391;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1329) {
  my_decimal decimal = {{0x982E3E32, 0x88C21972, 0x1B667DF4, 0x1A0000}};
  int check = 1118411162;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1330) {
  my_decimal decimal = {{0x982E3E32, 0x88C21972, 0x1B667DF4, 0x801A0000}};
  int check = -1029072486;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1331) {
  my_decimal decimal = {{0x3E443CD0, 0x5FD79ED2, 0x6765C7FB, 0x1B0000}};
  int check = 1107296257;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1332) {
  my_decimal decimal = {{0x3E443CD0, 0x5FD79ED2, 0x6765C7FB, 0x801B0000}};
  int check = -1040187391;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1333) {
  my_decimal decimal = {{0x982E3E32, 0x88C21972, 0x1B667DF4, 0x1A0000}};
  int check = 1118411162;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1334) {
  my_decimal decimal = {{0x982E3E32, 0x88C21972, 0x1B667DF4, 0x801A0000}};
  int check = -1029072486;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1335) {
  my_decimal decimal = {{0x817CCA81, 0x4A, 0x0, 0xA0000}};
  int check = 1107296256;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1336) {
  my_decimal decimal = {{0x817CCA81, 0x4A, 0x0, 0x800A0000}};
  int check = -1040187392;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1337) {
  my_decimal decimal = {{0xA2D9F89, 0x4D20, 0x0, 0xC0000}};
  int check = 1118411162;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1338) {
  my_decimal decimal = {{0xA2D9F89, 0x4D20, 0x0, 0x800C0000}};
  int check = -1029072486;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1339) {
  my_decimal decimal = {{0x817C8000, 0x4A, 0x0, 0xA0000}};
  int check = 1107296256;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1340) {
  my_decimal decimal = {{0x817C8000, 0x4A, 0x0, 0x800A0000}};
  int check = -1040187392;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1341) {
  my_decimal decimal = {{0x9E08000, 0x4D20, 0x0, 0xC0000}};
  int check = 1118411162;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1342) {
  my_decimal decimal = {{0x9E08000, 0x4D20, 0x0, 0x800C0000}};
  int check = -1029072486;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1343) {
  my_decimal decimal = {{0x1, 0x0, 0xFFFFFF80, 0x0}};
  int check = 1870659584;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1344) {
  my_decimal decimal = {{0x1, 0x0, 0xFFFFFF80, 0x80000000}};
  int check = -276824064;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1345) {
  my_decimal decimal = {{0x0, 0x0, 0xFFFFFF80, 0x0}};
  int check = 1870659584;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1346) {
  my_decimal decimal = {{0x0, 0x0, 0xFFFFFF80, 0x80000000}};
  int check = -276824064;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1347) {
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFF7F, 0x0}};
  int check = 1870659584;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1348) {
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFFFF, 0xFFFFFF7F, 0x80000000}};
  int check = -276824064;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1349) {
  my_decimal decimal = {{0x0, 0xFFFFFC00, 0xFFFFFF7F, 0x0}};
  int check = 1870659584;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1350) {
  my_decimal decimal = {{0x0, 0xFFFFFC00, 0xFFFFFF7F, 0x80000000}};
  int check = -276824064;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1351) {
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFBFF, 0xFFFFFF7F, 0x0}};
  int check = 1870659584;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1352) {
  my_decimal decimal = {{0xFFFFFFFF, 0xFFFFFBFF, 0xFFFFFF7F, 0x80000000}};
  int check = -276824064;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1353) {
  my_decimal decimal = {{0x3B, 0x0, 0xFFFFFF00, 0x0}};
  int check = 1870659583;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1354) {
  my_decimal decimal = {{0x3B, 0x0, 0xFFFFFF00, 0x80000000}};
  int check = -276824065;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1355) {
  my_decimal decimal = {{0x1, 0x0, 0xFFFFFF00, 0x0}};
  int check = 1870659583;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1356) {
  my_decimal decimal = {{0x1, 0x0, 0xFFFFFF00, 0x80000000}};
  int check = -276824065;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1357) {
  my_decimal decimal = {{0x0, 0x0, 0xFFFFFF00, 0x0}};
  int check = 1870659583;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1358) {
  my_decimal decimal = {{0x0, 0x0, 0xFFFFFF00, 0x80000000}};
  int check = -276824065;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1359) {
  my_decimal decimal = {{0x0, 0x0, 0xFFFFFE00, 0x0}};
  int check = 1870659582;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1360) {
  my_decimal decimal = {{0x0, 0x0, 0xFFFFFE00, 0x80000000}};
  int check = -276824066;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1361) {
  my_decimal decimal = {{0x0, 0x0, 0xFFFFFD00, 0x0}};
  int check = 1870659581;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1362) {
  my_decimal decimal = {{0x0, 0x0, 0xFFFFFD00, 0x80000000}};
  int check = -276824067;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1363) {
  my_decimal decimal = {{0x0, 0x0, 0xFFFFFC00, 0x0}};
  int check = 1870659580;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1364) {
  my_decimal decimal = {{0x0, 0x0, 0xFFFFFC00, 0x80000000}};
  int check = -276824068;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1365) {
  my_decimal decimal = {{0x0, 0x0, 0xFFFFFB00, 0x0}};
  int check = 1870659579;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1366) {
  my_decimal decimal = {{0x0, 0x0, 0xFFFFFB00, 0x80000000}};
  int check = -276824069;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1367) {
  my_decimal decimal = {{0x0, 0x0, 0xFFFFFA00, 0x0}};
  int check = 1870659578;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1368) {
  my_decimal decimal = {{0x0, 0x0, 0xFFFFFA00, 0x80000000}};
  int check = -276824070;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1369) {
  my_decimal decimal = {{0x0, 0x0, 0xFFFFF900, 0x0}};
  int check = 1870659577;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1370) {
  my_decimal decimal = {{0x0, 0x0, 0xFFFFF900, 0x80000000}};
  int check = -276824071;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1371) {
  my_decimal decimal = {{0x0, 0x0, 0xFFFFF800, 0x0}};
  int check = 1870659576;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1372) {
  my_decimal decimal = {{0x0, 0x0, 0xFFFFF800, 0x80000000}};
  int check = -276824072;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1373) {
  my_decimal decimal = {{0x0, 0x0, 0xFFFFF000, 0x0}};
  int check = 1870659568;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1374) {
  my_decimal decimal = {{0x0, 0x0, 0xFFFFF000, 0x80000000}};
  int check = -276824080;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1375) {
  my_decimal decimal = {{0x0, 0x0, 0xFFFFE000, 0x0}};
  int check = 1870659552;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1376) {
  my_decimal decimal = {{0x0, 0x0, 0xFFFFE000, 0x80000000}};
  int check = -276824096;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1377) {
  my_decimal decimal = {{0x0, 0x0, 0xFFFFC000, 0x0}};
  int check = 1870659520;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1378) {
  my_decimal decimal = {{0x0, 0x0, 0xFFFFC000, 0x80000000}};
  int check = -276824128;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1379) {
  my_decimal decimal = {{0x0, 0x0, 0xD5555500, 0x0}};
  int check = 1867863381;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1380) {
  my_decimal decimal = {{0x0, 0x0, 0xD5555500, 0x80000000}};
  int check = -279620267;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1381) {
  my_decimal decimal = {{0x0, 0x0, 0xC0000000, 0x0}};
  int check = 1866465280;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1382) {
  my_decimal decimal = {{0x0, 0x0, 0xC0000000, 0x80000000}};
  int check = -281018368;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1383) {
  my_decimal decimal = {{0x0, 0x0, 0xAAAAAA00, 0x0}};
  int check = 1865067178;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1384) {
  my_decimal decimal = {{0x0, 0x0, 0xAAAAAA00, 0x80000000}};
  int check = -282416470;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1385) {
  my_decimal decimal = {{0x0, 0x0, 0x80000000, 0x0}};
  int check = 1862270976;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1386) {
  my_decimal decimal = {{0x0, 0x0, 0x80000000, 0x80000000}};
  int check = -285212672;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1387) {
  my_decimal decimal = {{0x0, 0x0, 0x35555540, 0x0}};
  int check = 1851086165;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1388) {
  my_decimal decimal = {{0x0, 0x0, 0x35555540, 0x80000000}};
  int check = -296397483;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1389) {
  my_decimal decimal = {{0xCCCCCCCD, 0xCCCCCCCC, 0x8D55551C, 0x0}};
  int check = 1863144789;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1390) {
  my_decimal decimal = {{0xCCCCCCCD, 0xCCCCCCCC, 0x8D55551C, 0x80000000}};
  int check = -284338859;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1391) {
  my_decimal decimal = {{0x0, 0x0, 0x2AAAAA80, 0x0}};
  int check = 1848289962;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1392) {
  my_decimal decimal = {{0x0, 0x0, 0x2AAAAA80, 0x80000000}};
  int check = -299193686;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1393) {
  my_decimal decimal = {{0x0, 0x0, 0x711110A0, 0x0}};
  int check = 1860313633;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1394) {
  my_decimal decimal = {{0x0, 0x0, 0x711110A0, 0x80000000}};
  int check = -287170015;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1395) {
  my_decimal decimal = {{0x0, 0x0, 0x21555548, 0x10000}};
  int check = 1817531733;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1396) {
  my_decimal decimal = {{0x0, 0x0, 0x21555548, 0x80010000}};
  int check = -329951915;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1397) {
  my_decimal decimal = {{0x0, 0x0, 0x58555532, 0x10000}};
  int check = 1829590357;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1398) {
  my_decimal decimal = {{0x0, 0x0, 0x58555532, 0x80010000}};
  int check = -317893291;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1399) {
  my_decimal decimal = {{0x0, 0x0, 0x3555554, 0x0}};
  int check = 1817531733;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1400) {
  my_decimal decimal = {{0x0, 0x0, 0x3555554, 0x80000000}};
  int check = -329951915;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1401) {
  my_decimal decimal = {{0x0, 0x0, 0x58555532, 0x10000}};
  int check = 1829590357;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1402) {
  my_decimal decimal = {{0x0, 0x0, 0x58555532, 0x80010000}};
  int check = -317893291;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1403) {
  my_decimal decimal = {{0x0, 0x0, 0x1AAAAA90, 0x10000}};
  int check = 1814735530;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1404) {
  my_decimal decimal = {{0x0, 0x0, 0x1AAAAA90, 0x80010000}};
  int check = -332748118;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1405) {
  my_decimal decimal = {{0x0, 0x0, 0x46AAAA64, 0x10000}};
  int check = 1826759201;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1406) {
  my_decimal decimal = {{0x0, 0x0, 0x46AAAA64, 0x80010000}};
  int check = -320724447;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1407) {
  my_decimal decimal = {{0x0, 0x0, 0x2AAAAA8, 0x0}};
  int check = 1814735530;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1408) {
  my_decimal decimal = {{0x0, 0x0, 0x2AAAAA8, 0x80000000}};
  int check = -332748118;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1409) {
  my_decimal decimal = {{0x0, 0x0, 0x46AAAA64, 0x10000}};
  int check = 1826759201;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1410) {
  my_decimal decimal = {{0x0, 0x0, 0x46AAAA64, 0x80010000}};
  int check = -320724447;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1411) {
  my_decimal decimal = {{0x0, 0x40000000, 0x82355521, 0x40000}};
  int check = 1750422869;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1412) {
  my_decimal decimal = {{0x0, 0x40000000, 0x82355521, 0x80040000}};
  int check = -397060779;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1413) {
  my_decimal decimal = {{0x0, 0x88000000, 0x22815547, 0x30000}};
  int check = 1762481493;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1414) {
  my_decimal decimal = {{0x0, 0x88000000, 0x22815547, 0x80030000}};
  int check = -385002155;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1415) {
  my_decimal decimal = {{0x0, 0x54000000, 0x35555, 0x0}};
  int check = 1750422869;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1416) {
  my_decimal decimal = {{0x0, 0x54000000, 0x35555, 0x80000000}};
  int check = -397060779;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1417) {
  my_decimal decimal = {{0x0, 0xF4000000, 0x3735553, 0x20000}};
  int check = 1762481493;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1418) {
  my_decimal decimal = {{0x0, 0xF4000000, 0x3735553, 0x80020000}};
  int check = -385002155;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1419) {
  my_decimal decimal = {{0x0, 0x0, 0x20000, 0x0}};
  int check = 1744830464;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1420) {
  my_decimal decimal = {{0x0, 0x0, 0x20000, 0x80000000}};
  int check = -402653184;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1421) {
  my_decimal decimal = {{0x0, 0x0, 0x2120000, 0x20000}};
  int check = 1755945370;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1422) {
  my_decimal decimal = {{0x0, 0x0, 0x2120000, 0x80020000}};
  int check = -391538278;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1423) {
  my_decimal decimal = {{0x0, 0xE0000000, 0x4E1FFFB1, 0x40000}};
  int check = 1744830463;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1424) {
  my_decimal decimal = {{0x0, 0xE0000000, 0x4E1FFFB1, 0x80040000}};
  int check = -402653185;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1425) {
  my_decimal decimal = {{0x0, 0xF8000000, 0xCF07FF30, 0x40000}};
  int check = 1755945369;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1426) {
  my_decimal decimal = {{0x0, 0xF8000000, 0xCF07FF30, 0x80040000}};
  int check = -391538279;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1427) {
  my_decimal decimal = {{0x0, 0xFE000000, 0x1FFFF, 0x0}};
  int check = 1744830463;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1428) {
  my_decimal decimal = {{0x0, 0xFE000000, 0x1FFFF, 0x80000000}};
  int check = -402653185;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1429) {
  my_decimal decimal = {{0x0, 0xEE000000, 0x211FFFD, 0x20000}};
  int check = 1755945369;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1430) {
  my_decimal decimal = {{0x0, 0xEE000000, 0x211FFFD, 0x80020000}};
  int check = -391538279;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1431) {
  my_decimal decimal = {{0x0, 0xC0000000, 0x4E1FFF63, 0x40000}};
  int check = 1744830462;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1432) {
  my_decimal decimal = {{0x0, 0xC0000000, 0x4E1FFF63, 0x80040000}};
  int check = -402653186;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1433) {
  my_decimal decimal = {{0x0, 0xF0000000, 0xCF07FE61, 0x40000}};
  int check = 1755945368;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1434) {
  my_decimal decimal = {{0x0, 0xF0000000, 0xCF07FE61, 0x80040000}};
  int check = -391538280;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1435) {
  my_decimal decimal = {{0x0, 0xFC000000, 0x1FFFF, 0x0}};
  int check = 1744830462;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1436) {
  my_decimal decimal = {{0x0, 0xFC000000, 0x1FFFF, 0x80000000}};
  int check = -402653186;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1437) {
  my_decimal decimal = {{0x0, 0xDC000000, 0x211FFFB, 0x20000}};
  int check = 1755945368;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1438) {
  my_decimal decimal = {{0x0, 0xDC000000, 0x211FFFB, 0x80020000}};
  int check = -391538280;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1439) {
  my_decimal decimal = {{0x0, 0x80000000, 0x682AAA42, 0x40000}};
  int check = 1747626666;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1440) {
  my_decimal decimal = {{0x0, 0x80000000, 0x682AAA42, 0x80040000}};
  int check = -399856982;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1441) {
  my_decimal decimal = {{0x0, 0x10000000, 0x1B9AAA8F, 0x30000}};
  int check = 1759650337;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1442) {
  my_decimal decimal = {{0x0, 0x10000000, 0x1B9AAA8F, 0x80030000}};
  int check = -387833311;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1443) {
  my_decimal decimal = {{0x0, 0xA8000000, 0x2AAAA, 0x0}};
  int check = 1747626666;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1444) {
  my_decimal decimal = {{0x0, 0xA8000000, 0x2AAAA, 0x80000000}};
  int check = -399856982;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1445) {
  my_decimal decimal = {{0x0, 0xE8000000, 0x2C2AAA7, 0x20000}};
  int check = 1759650337;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1446) {
  my_decimal decimal = {{0x0, 0xE8000000, 0x2C2AAA7, 0x80020000}};
  int check = -387833311;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1447) {
  my_decimal decimal = {{0x0, 0xA0000000, 0x411AAA90, 0x40000}};
  int check = 1742034261;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1448) {
  my_decimal decimal = {{0x0, 0xA0000000, 0x411AAA90, 0x80040000}};
  int check = -405449387;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1449) {
  my_decimal decimal = {{0x0, 0xA8000000, 0xAC86AA65, 0x40000}};
  int check = 1754092885;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1450) {
  my_decimal decimal = {{0x0, 0xA8000000, 0xAC86AA65, 0x80040000}};
  int check = -393390763;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1451) {
  my_decimal decimal = {{0x0, 0xAA000000, 0x1AAAA, 0x0}};
  int check = 1742034261;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1452) {
  my_decimal decimal = {{0x0, 0xAA000000, 0x1AAAA, 0x80000000}};
  int check = -405449387;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1453) {
  my_decimal decimal = {{0x0, 0xFA000000, 0x1B9AAA9, 0x20000}};
  int check = 1754092885;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1454) {
  my_decimal decimal = {{0x0, 0xFA000000, 0x1B9AAA9, 0x80020000}};
  int check = -393390763;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1455) {
  my_decimal decimal = {{0x0, 0x40000000, 0x34155521, 0x40000}};
  int check = 1739238058;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1456) {
  my_decimal decimal = {{0x0, 0x40000000, 0x34155521, 0x80040000}};
  int check = -408245590;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1457) {
  my_decimal decimal = {{0x0, 0x50000000, 0x8A0554CB, 0x40000}};
  int check = 1751261729;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1458) {
  my_decimal decimal = {{0x0, 0x50000000, 0x8A0554CB, 0x80040000}};
  int check = -396221919;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1459) {
  my_decimal decimal = {{0x0, 0x54000000, 0x15555, 0x0}};
  int check = 1739238058;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1460) {
  my_decimal decimal = {{0x0, 0x54000000, 0x15555, 0x80000000}};
  int check = -408245590;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1461) {
  my_decimal decimal = {{0x0, 0xF4000000, 0x1615553, 0x20000}};
  int check = 1751261729;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1462) {
  my_decimal decimal = {{0x0, 0xF4000000, 0x1615553, 0x80020000}};
  int check = -396221919;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1463) {
  my_decimal decimal = {{0x0, 0x0, 0x200, 0x0}};
  int check = 1677721600;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1464) {
  my_decimal decimal = {{0x0, 0x0, 0x200, 0x80000000}};
  int check = -469762048;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1465) {
  my_decimal decimal = {{0x0, 0x0, 0x21200, 0x20000}};
  int check = 1688836506;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1466) {
  my_decimal decimal = {{0x0, 0x0, 0x21200, 0x80020000}};
  int check = -458647142;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1467) {
  my_decimal decimal = {{0x0, 0x7B800000, 0x1E847FE1, 0x60000}};
  int check = 1677721599;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1468) {
  my_decimal decimal = {{0x0, 0x7B800000, 0x1E847FE1, 0x80060000}};
  int check = -469762049;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1469) {
  my_decimal decimal = {{0x0, 0x20E00000, 0x50DF1FAF, 0x60000}};
  int check = 1688836505;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1470) {
  my_decimal decimal = {{0x0, 0x20E00000, 0x50DF1FAF, 0x80060000}};
  int check = -458647143;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1471) {
  my_decimal decimal = {{0x0, 0xFFFE0000, 0x1FF, 0x0}};
  int check = 1677721599;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1472) {
  my_decimal decimal = {{0x0, 0xFFFE0000, 0x1FF, 0x80000000}};
  int check = -469762049;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1473) {
  my_decimal decimal = {{0x0, 0xFDEE0000, 0x211FF, 0x20000}};
  int check = 1688836505;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1474) {
  my_decimal decimal = {{0x0, 0xFDEE0000, 0x211FF, 0x80020000}};
  int check = -458647143;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1475) {
  my_decimal decimal = {{0x0, 0xF7000000, 0x1E847FC2, 0x60000}};
  int check = 1677721598;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1476) {
  my_decimal decimal = {{0x0, 0xF7000000, 0x1E847FC2, 0x80060000}};
  int check = -469762050;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1477) {
  my_decimal decimal = {{0x0, 0x41C00000, 0x50DF1F5E, 0x60000}};
  int check = 1688836504;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1478) {
  my_decimal decimal = {{0x0, 0x41C00000, 0x50DF1F5E, 0x80060000}};
  int check = -458647144;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1479) {
  my_decimal decimal = {{0x0, 0xFFFC0000, 0x1FF, 0x0}};
  int check = 1677721598;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1480) {
  my_decimal decimal = {{0x0, 0xFFFC0000, 0x1FF, 0x80000000}};
  int check = -469762050;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1481) {
  my_decimal decimal = {{0x0, 0xFBDC0000, 0x211FF, 0x20000}};
  int check = 1688836504;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1482) {
  my_decimal decimal = {{0x0, 0xFBDC0000, 0x211FF, 0x80020000}};
  int check = -458647144;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1483) {
  my_decimal decimal = {{0x0, 0xF1000000, 0xFE502A44, 0x70000}};
  int check = 1674925397;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1484) {
  my_decimal decimal = {{0x0, 0xF1000000, 0xFE502A44, 0x80070000}};
  int check = -472558251;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1485) {
  my_decimal decimal = {{0x0, 0xB5A00000, 0x43649A8F, 0x60000}};
  int check = 1686984021;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1486) {
  my_decimal decimal = {{0x0, 0xB5A00000, 0x43649A8F, 0x80060000}};
  int check = -460499627;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1487) {
  my_decimal decimal = {{0x0, 0xAAAA0000, 0x1AA, 0x0}};
  int check = 1674925397;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1488) {
  my_decimal decimal = {{0x0, 0xAAAA0000, 0x1AA, 0x80000000}};
  int check = -472558251;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1489) {
  my_decimal decimal = {{0x0, 0xA9FA0000, 0x1B9AA, 0x20000}};
  int check = 1686984021;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1490) {
  my_decimal decimal = {{0x0, 0xA9FA0000, 0x1B9AA, 0x80020000}};
  int check = -460499627;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1491) {
  my_decimal decimal = {{0x0, 0xE2000000, 0xCB735489, 0x70000}};
  int check = 1672129194;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1492) {
  my_decimal decimal = {{0x0, 0xE2000000, 0xCB735489, 0x80070000}};
  int check = -475354454;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1493) {
  my_decimal decimal = {{0x0, 0x6B400000, 0x35EA151F, 0x60000}};
  int check = 1684152865;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1494) {
  my_decimal decimal = {{0x0, 0x6B400000, 0x35EA151F, 0x80060000}};
  int check = -463330783;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1495) {
  my_decimal decimal = {{0x0, 0x55540000, 0x155, 0x0}};
  int check = 1672129194;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1496) {
  my_decimal decimal = {{0x0, 0x55540000, 0x155, 0x80000000}};
  int check = -475354454;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1497) {
  my_decimal decimal = {{0x0, 0x53F40000, 0x16155, 0x20000}};
  int check = 1684152865;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1498) {
  my_decimal decimal = {{0x0, 0x53F40000, 0x16155, 0x80020000}};
  int check = -463330783;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1499) {
  my_decimal decimal = {{0x0, 0x0, 0x20, 0x0}};
  int check = 1644167168;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1500) {
  my_decimal decimal = {{0x0, 0x0, 0x20, 0x80000000}};
  int check = -503316480;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1501) {
  my_decimal decimal = {{0x0, 0x0, 0x2120, 0x20000}};
  int check = 1655282074;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1502) {
  my_decimal decimal = {{0x0, 0x0, 0x2120, 0x80020000}};
  int check = -492201574;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1503) {
  my_decimal decimal = {{0x0, 0x43E00000, 0xBEBC1F41, 0x80000}};
  int check = 1644167167;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1504) {
  my_decimal decimal = {{0x0, 0x43E00000, 0xBEBC1F41, 0x80080000}};
  int check = -503316481;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1505) {
  my_decimal decimal = {{0x0, 0x748C0000, 0x328B73CD, 0x70000}};
  int check = 1655282073;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1506) {
  my_decimal decimal = {{0x0, 0x748C0000, 0x328B73CD, 0x80070000}};
  int check = -492201575;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1507) {
  my_decimal decimal = {{0x0, 0xFFFFE000, 0x1F, 0x0}};
  int check = 1644167167;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1508) {
  my_decimal decimal = {{0x0, 0xFFFFE000, 0x1F, 0x80000000}};
  int check = -503316481;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1509) {
  my_decimal decimal = {{0x0, 0xFFDEE000, 0x211F, 0x20000}};
  int check = 1655282073;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1510) {
  my_decimal decimal = {{0x0, 0xFFDEE000, 0x211F, 0x80020000}};
  int check = -492201575;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1511) {
  my_decimal decimal = {{0x0, 0x87C00000, 0xBEBC1E82, 0x80000}};
  int check = 1644167166;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1512) {
  my_decimal decimal = {{0x0, 0x87C00000, 0xBEBC1E82, 0x80080000}};
  int check = -503316482;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1513) {
  my_decimal decimal = {{0x0, 0xE9180000, 0x328B739A, 0x70000}};
  int check = 1655282072;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1514) {
  my_decimal decimal = {{0x0, 0xE9180000, 0x328B739A, 0x80070000}};
  int check = -492201576;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1515) {
  my_decimal decimal = {{0x0, 0xFFFFC000, 0x1F, 0x0}};
  int check = 1644167166;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1516) {
  my_decimal decimal = {{0x0, 0xFFFFC000, 0x1F, 0x80000000}};
  int check = -503316482;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1517) {
  my_decimal decimal = {{0x0, 0xFFBDC000, 0x211F, 0x20000}};
  int check = 1655282072;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1518) {
  my_decimal decimal = {{0x0, 0xFFBDC000, 0x211F, 0x80020000}};
  int check = -492201576;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1519) {
  my_decimal decimal = {{0x0, 0x16A00000, 0x9EF21A6B, 0x80000}};
  int check = 1641370965;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1520) {
  my_decimal decimal = {{0x0, 0x16A00000, 0x9EF21A6B, 0x80080000}};
  int check = -506112683;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1521) {
  my_decimal decimal = {{0x0, 0xD1840000, 0x2A1EE099, 0x70000}};
  int check = 1653429589;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1522) {
  my_decimal decimal = {{0x0, 0xD1840000, 0x2A1EE099, 0x80070000}};
  int check = -494054059;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1523) {
  my_decimal decimal = {{0x0, 0xAAAAA000, 0x1A, 0x0}};
  int check = 1641370965;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1524) {
  my_decimal decimal = {{0x0, 0xAAAAA000, 0x1A, 0x80000000}};
  int check = -506112683;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1525) {
  my_decimal decimal = {{0x0, 0xAA9FA000, 0x1B9A, 0x20000}};
  int check = 1653429589;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1526) {
  my_decimal decimal = {{0x0, 0xAA9FA000, 0x1B9A, 0x80020000}};
  int check = -494054059;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1527) {
  my_decimal decimal = {{0x0, 0x2D400000, 0x7F2814D6, 0x80000}};
  int check = 1638574762;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1528) {
  my_decimal decimal = {{0x0, 0x2D400000, 0x7F2814D6, 0x80080000}};
  int check = -508908886;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1529) {
  my_decimal decimal = {{0x0, 0xA3080000, 0x21B24D33, 0x70000}};
  int check = 1650598433;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1530) {
  my_decimal decimal = {{0x0, 0xA3080000, 0x21B24D33, 0x80070000}};
  int check = -496885215;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1531) {
  my_decimal decimal = {{0x0, 0x55554000, 0x15, 0x0}};
  int check = 1638574762;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1532) {
  my_decimal decimal = {{0x0, 0x55554000, 0x15, 0x80000000}};
  int check = -508908886;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1533) {
  my_decimal decimal = {{0x0, 0x553F4000, 0x1615, 0x20000}};
  int check = 1650598433;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1534) {
  my_decimal decimal = {{0x0, 0x553F4000, 0x1615, 0x80020000}};
  int check = -496885215;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1535) {
  my_decimal decimal = {{0x0, 0x0, 0x8, 0x0}};
  int check = 1627389952;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1536) {
  my_decimal decimal = {{0x0, 0x0, 0x8, 0x80000000}};
  int check = -520093696;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1537) {
  my_decimal decimal = {{0x0, 0x0, 0x848, 0x20000}};
  int check = 1638504858;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1538) {
  my_decimal decimal = {{0x0, 0x0, 0x848, 0x80020000}};
  int check = -508978790;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1539) {
  my_decimal decimal = {{0x0, 0x50F80000, 0x2FAF07D0, 0x80000}};
  int check = 1627389951;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1540) {
  my_decimal decimal = {{0x0, 0x50F80000, 0x2FAF07D0, 0x80080000}};
  int check = -520093697;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1541) {
  my_decimal decimal = {{0x0, 0xA35E0000, 0x7E5CA181, 0x80000}};
  int check = 1638504857;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1542) {
  my_decimal decimal = {{0x0, 0xA35E0000, 0x7E5CA181, 0x80080000}};
  int check = -508978791;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1543) {
  my_decimal decimal = {{0x0, 0xFFFFF800, 0x7, 0x0}};
  int check = 1627389951;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1544) {
  my_decimal decimal = {{0x0, 0xFFFFF800, 0x7, 0x80000000}};
  int check = -520093697;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1545) {
  my_decimal decimal = {{0x0, 0xFFF7B800, 0x847, 0x20000}};
  int check = 1638504857;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1546) {
  my_decimal decimal = {{0x0, 0xFFF7B800, 0x847, 0x80020000}};
  int check = -508978791;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1547) {
  my_decimal decimal = {{0x0, 0xA1F00000, 0x2FAF07A0, 0x80000}};
  int check = 1627389950;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1548) {
  my_decimal decimal = {{0x0, 0xA1F00000, 0x2FAF07A0, 0x80080000}};
  int check = -520093698;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1549) {
  my_decimal decimal = {{0x0, 0x46BC0000, 0x7E5CA103, 0x80000}};
  int check = 1638504856;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1550) {
  my_decimal decimal = {{0x0, 0x46BC0000, 0x7E5CA103, 0x80080000}};
  int check = -508978792;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1551) {
  my_decimal decimal = {{0x0, 0xFFFFF000, 0x7, 0x0}};
  int check = 1627389950;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1552) {
  my_decimal decimal = {{0x0, 0xFFFFF000, 0x7, 0x80000000}};
  int check = -520093698;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1553) {
  my_decimal decimal = {{0x0, 0xFFEF7000, 0x847, 0x20000}};
  int check = 1638504856;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1554) {
  my_decimal decimal = {{0x0, 0xFFEF7000, 0x847, 0x80020000}};
  int check = -508978792;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1555) {
  my_decimal decimal = {{0x0, 0xC5A80000, 0x27BC869A, 0x80000}};
  int check = 1624593749;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1556) {
  my_decimal decimal = {{0x0, 0xC5A80000, 0x27BC869A, 0x80080000}};
  int check = -522889899;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1557) {
  my_decimal decimal = {{0x0, 0x8BCA0000, 0x694D3180, 0x80000}};
  int check = 1636652373;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1558) {
  my_decimal decimal = {{0x0, 0x8BCA0000, 0x694D3180, 0x80080000}};
  int check = -510831275;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1559) {
  my_decimal decimal = {{0x0, 0xAAAAA800, 0x6, 0x0}};
  int check = 1624593749;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1560) {
  my_decimal decimal = {{0x0, 0xAAAAA800, 0x6, 0x80000000}};
  int check = -522889899;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1561) {
  my_decimal decimal = {{0x0, 0xAAA7E800, 0x6E6, 0x20000}};
  int check = 1636652373;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1562) {
  my_decimal decimal = {{0x0, 0xAAA7E800, 0x6E6, 0x80020000}};
  int check = -510831275;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1563) {
  my_decimal decimal = {{0x0, 0x8B500000, 0x1FCA0535, 0x80000}};
  int check = 1621797546;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1564) {
  my_decimal decimal = {{0x0, 0x8B500000, 0x1FCA0535, 0x80080000}};
  int check = -525686102;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1565) {
  my_decimal decimal = {{0x0, 0x17940000, 0x543DC101, 0x80000}};
  int check = 1633821217;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1566) {
  my_decimal decimal = {{0x0, 0x17940000, 0x543DC101, 0x80080000}};
  int check = -513662431;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1567) {
  my_decimal decimal = {{0x0, 0x55555000, 0x5, 0x0}};
  int check = 1621797546;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1568) {
  my_decimal decimal = {{0x0, 0x55555000, 0x5, 0x80000000}};
  int check = -525686102;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1569) {
  my_decimal decimal = {{0x0, 0x554FD000, 0x585, 0x20000}};
  int check = 1633821217;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1570) {
  my_decimal decimal = {{0x0, 0x554FD000, 0x585, 0x80020000}};
  int check = -513662431;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1571) {
  my_decimal decimal = {{0x0, 0xDC480000, 0xC6AEA105, 0x90000}};
  int check = 1616205141;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1572) {
  my_decimal decimal = {{0x0, 0xDC480000, 0xC6AEA105, 0x80090000}};
  int check = -531278507;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1573) {
  my_decimal decimal = {{0x0, 0x45E50000, 0x34A698C0, 0x80000}};
  int check = 1628263765;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1574) {
  my_decimal decimal = {{0x0, 0x45E50000, 0x34A698C0, 0x80080000}};
  int check = -519219883;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1575) {
  my_decimal decimal = {{0x0, 0x55555400, 0x3, 0x0}};
  int check = 1616205141;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1576) {
  my_decimal decimal = {{0x0, 0x55555400, 0x3, 0x80000000}};
  int check = -531278507;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1577) {
  my_decimal decimal = {{0x0, 0x5553F400, 0x373, 0x20000}};
  int check = 1628263765;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1578) {
  my_decimal decimal = {{0x0, 0x5553F400, 0x373, 0x80020000}};
  int check = -519219883;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1579) {
  my_decimal decimal = {{0x0, 0x0, 0x2, 0x0}};
  int check = 1610612736;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1580) {
  my_decimal decimal = {{0x0, 0x0, 0x2, 0x80000000}};
  int check = -536870912;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1581) {
  my_decimal decimal = {{0x0, 0x0, 0x212, 0x20000}};
  int check = 1621727642;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1582) {
  my_decimal decimal = {{0x0, 0x0, 0x212, 0x80020000}};
  int check = -525756006;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1583) {
  my_decimal decimal = {{0x0, 0xCA6C0000, 0x77359388, 0x90000}};
  int check = 1610612735;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1584) {
  my_decimal decimal = {{0x0, 0xCA6C0000, 0x77359388, 0x80090000}};
  int check = -536870913;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1585) {
  my_decimal decimal = {{0x0, 0x68D78000, 0x1F972860, 0x80000}};
  int check = 1621727641;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1586) {
  my_decimal decimal = {{0x0, 0x68D78000, 0x1F972860, 0x80080000}};
  int check = -525756007;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1587) {
  my_decimal decimal = {{0x0, 0xFFFFFE00, 0x1, 0x0}};
  int check = 1610612735;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1588) {
  my_decimal decimal = {{0x0, 0xFFFFFE00, 0x1, 0x80000000}};
  int check = -536870913;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1589) {
  my_decimal decimal = {{0x0, 0xFFFDEE00, 0x211, 0x20000}};
  int check = 1621727641;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1590) {
  my_decimal decimal = {{0x0, 0xFFFDEE00, 0x211, 0x80020000}};
  int check = -525756007;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1591) {
  my_decimal decimal = {{0x0, 0x94D80000, 0x77359311, 0x90000}};
  int check = 1610612734;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1592) {
  my_decimal decimal = {{0x0, 0x94D80000, 0x77359311, 0x80090000}};
  int check = -536870914;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1593) {
  my_decimal decimal = {{0x0, 0xD1AF0000, 0x1F972840, 0x80000}};
  int check = 1621727640;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1594) {
  my_decimal decimal = {{0x0, 0xD1AF0000, 0x1F972840, 0x80080000}};
  int check = -525756008;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1595) {
  my_decimal decimal = {{0x0, 0xFFFFFC00, 0x1, 0x0}};
  int check = 1610612734;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1596) {
  my_decimal decimal = {{0x0, 0xFFFFFC00, 0x1, 0x80000000}};
  int check = -536870914;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1597) {
  my_decimal decimal = {{0x0, 0xFFFBDC00, 0x211, 0x20000}};
  int check = 1621727640;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1598) {
  my_decimal decimal = {{0x0, 0xFFFBDC00, 0x211, 0x80020000}};
  int check = -525756008;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1599) {
  my_decimal decimal = {{0x0, 0xEE240000, 0x63575082, 0x90000}};
  int check = 1607816533;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1600) {
  my_decimal decimal = {{0x0, 0xEE240000, 0x63575082, 0x80090000}};
  int check = -539667115;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1601) {
  my_decimal decimal = {{0x0, 0x22F28000, 0x1A534C60, 0x80000}};
  int check = 1619875157;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1602) {
  my_decimal decimal = {{0x0, 0x22F28000, 0x1A534C60, 0x80080000}};
  int check = -527608491;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1603) {
  my_decimal decimal = {{0x0, 0xAAAAAA00, 0x1, 0x0}};
  int check = 1607816533;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1604) {
  my_decimal decimal = {{0x0, 0xAAAAAA00, 0x1, 0x80000000}};
  int check = -539667115;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1605) {
  my_decimal decimal = {{0x0, 0xAAA9FA00, 0x1B9, 0x20000}};
  int check = 1619875157;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1606) {
  my_decimal decimal = {{0x0, 0xAAA9FA00, 0x1B9, 0x80020000}};
  int check = -527608491;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1607) {
  my_decimal decimal = {{0x0, 0x0, 0xF, 0x10000}};
  int check = 1606418432;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1608) {
  my_decimal decimal = {{0x0, 0x0, 0xF, 0x80010000}};
  int check = -541065216;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1609) {
  my_decimal decimal = {{0x0, 0x0, 0xF87, 0x30000}};
  int check = 1618896486;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1610) {
  my_decimal decimal = {{0x0, 0x0, 0xF87, 0x80030000}};
  int check = -528587162;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1611) {
  my_decimal decimal = {{0x0, 0x80000000, 0x1, 0x0}};
  int check = 1606418432;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1612) {
  my_decimal decimal = {{0x0, 0x80000000, 0x1, 0x80000000}};
  int check = -541065216;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1613) {
  my_decimal decimal = {{0x0, 0x80000000, 0x18D, 0x20000}};
  int check = 1618896486;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1614) {
  my_decimal decimal = {{0x0, 0x80000000, 0x18D, 0x80020000}};
  int check = -528587162;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1615) {
  my_decimal decimal = {{0x0, 0xDC480000, 0x4F790D05, 0x90000}};
  int check = 1605020330;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1616) {
  my_decimal decimal = {{0x0, 0xDC480000, 0x4F790D05, 0x80090000}};
  int check = -542463318;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1617) {
  my_decimal decimal = {{0x0, 0xBAF20000, 0xD29A6282, 0x90000}};
  int check = 1617044001;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1618) {
  my_decimal decimal = {{0x0, 0xBAF20000, 0xD29A6282, 0x80090000}};
  int check = -530439647;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1619) {
  my_decimal decimal = {{0x0, 0x55555400, 0x1, 0x0}};
  int check = 1605020330;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1620) {
  my_decimal decimal = {{0x0, 0x55555400, 0x1, 0x80000000}};
  int check = -542463318;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1621) {
  my_decimal decimal = {{0x0, 0x5553F400, 0x161, 0x20000}};
  int check = 1617044001;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1622) {
  my_decimal decimal = {{0x0, 0x5553F400, 0x161, 0x80020000}};
  int check = -530439647;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1623) {
  my_decimal decimal = {{0x0, 0x2, 0x0, 0x0}};
  int check = 1342177280;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1624) {
  my_decimal decimal = {{0x0, 0x2, 0x0, 0x80000000}};
  int check = -805306368;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1625) {
  my_decimal decimal = {{0x0, 0x212, 0x0, 0x20000}};
  int check = 1353292186;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1626) {
  my_decimal decimal = {{0x0, 0x212, 0x0, 0x80020000}};
  int check = -794191462;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1627) {
  my_decimal decimal = {{0x38000000, 0x8D5A98B1, 0x1BC16D4B, 0x120000}};
  int check = 1342177279;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1628) {
  my_decimal decimal = {{0x38000000, 0x8D5A98B1, 0x1BC16D4B, 0x80120000}};
  int check = -805306369;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1629) {
  my_decimal decimal = {{0x6E000000, 0xD03014A2, 0x498D61A1, 0x120000}};
  int check = 1353292185;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1630) {
  my_decimal decimal = {{0x6E000000, 0xD03014A2, 0x498D61A1, 0x80120000}};
  int check = -794191463;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1631) {
  my_decimal decimal = {{0xFFFFFE00, 0x1, 0x0, 0x0}};
  int check = 1342177279;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1632) {
  my_decimal decimal = {{0xFFFFFE00, 0x1, 0x0, 0x80000000}};
  int check = -805306369;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1633) {
  my_decimal decimal = {{0xFFFDEE00, 0x211, 0x0, 0x20000}};
  int check = 1353292185;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1634) {
  my_decimal decimal = {{0xFFFDEE00, 0x211, 0x0, 0x80020000}};
  int check = -794191463;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1635) {
  my_decimal decimal = {{0x70000000, 0xCBED3162, 0x1BC16D2F, 0x120000}};
  int check = 1342177278;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1636) {
  my_decimal decimal = {{0x70000000, 0xCBED3162, 0x1BC16D2F, 0x80120000}};
  int check = -805306370;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1637) {
  my_decimal decimal = {{0xDC000000, 0x42CE2944, 0x498D6158, 0x120000}};
  int check = 1353292184;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1638) {
  my_decimal decimal = {{0xDC000000, 0x42CE2944, 0x498D6158, 0x80120000}};
  int check = -794191464;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1639) {
  my_decimal decimal = {{0xFFFFFC00, 0x1, 0x0, 0x0}};
  int check = 1342177278;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1640) {
  my_decimal decimal = {{0xFFFFFC00, 0x1, 0x0, 0x80000000}};
  int check = -805306370;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1641) {
  my_decimal decimal = {{0xFFFBDC00, 0x211, 0x0, 0x20000}};
  int check = 1353292184;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1642) {
  my_decimal decimal = {{0xFFFBDC00, 0x211, 0x0, 0x80020000}};
  int check = -794191464;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1643) {
  my_decimal decimal = {{0x10000000, 0xBC0A7A4, 0xE74BE4AB, 0x130000}};
  int check = 1339381077;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1644) {
  my_decimal decimal = {{0x10000000, 0xBC0A7A4, 0xE74BE4AB, 0x80130000}};
  int check = -808102571;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1645) {
  my_decimal decimal = {{0x7A000000, 0x4983B18B, 0x3D4B26D6, 0x120000}};
  int check = 1351439701;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1646) {
  my_decimal decimal = {{0x7A000000, 0x4983B18B, 0x3D4B26D6, 0x80120000}};
  int check = -796043947;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1647) {
  my_decimal decimal = {{0xAAAAAA00, 0x1, 0x0, 0x0}};
  int check = 1339381077;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1648) {
  my_decimal decimal = {{0xAAAAAA00, 0x1, 0x0, 0x80000000}};
  int check = -808102571;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1649) {
  my_decimal decimal = {{0xAAA9FA00, 0x1B9, 0x0, 0x20000}};
  int check = 1351439701;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1650) {
  my_decimal decimal = {{0xAAA9FA00, 0x1B9, 0x0, 0x80020000}};
  int check = -796043947;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1651) {
  my_decimal decimal = {{0x0, 0xF, 0x0, 0x10000}};
  int check = 1337982976;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1652) {
  my_decimal decimal = {{0x0, 0xF, 0x0, 0x80010000}};
  int check = -809500672;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1653) {
  my_decimal decimal = {{0x0, 0xF87, 0x0, 0x30000}};
  int check = 1350461030;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1654) {
  my_decimal decimal = {{0x0, 0xF87, 0x0, 0x80030000}};
  int check = -797022618;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1655) {
  my_decimal decimal = {{0x80000000, 0x1, 0x0, 0x0}};
  int check = 1337982976;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1656) {
  my_decimal decimal = {{0x80000000, 0x1, 0x0, 0x80000000}};
  int check = -809500672;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1657) {
  my_decimal decimal = {{0x80000000, 0x18D, 0x0, 0x20000}};
  int check = 1350461030;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1658) {
  my_decimal decimal = {{0x80000000, 0x18D, 0x0, 0x80020000}};
  int check = -797022618;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1659) {
  my_decimal decimal = {{0x20000000, 0x3B14F48, 0xB909834D, 0x130000}};
  int check = 1336584874;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1660) {
  my_decimal decimal = {{0x20000000, 0x3B14F48, 0xB909834D, 0x80130000}};
  int check = -810898774;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1661) {
  my_decimal decimal = {{0xF4000000, 0x35756316, 0x3108EBC1, 0x120000}};
  int check = 1348608545;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1662) {
  my_decimal decimal = {{0xF4000000, 0x35756316, 0x3108EBC1, 0x80120000}};
  int check = -798875103;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1663) {
  my_decimal decimal = {{0x55555400, 0x1, 0x0, 0x0}};
  int check = 1336584874;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1664) {
  my_decimal decimal = {{0x55555400, 0x1, 0x0, 0x80000000}};
  int check = -810898774;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1665) {
  my_decimal decimal = {{0x5553F400, 0x161, 0x0, 0x20000}};
  int check = 1348608545;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1666) {
  my_decimal decimal = {{0x5553F400, 0x161, 0x0, 0x80020000}};
  int check = -798875103;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1667) {
  my_decimal decimal = {{0x2DE00000, 0x55BAE49D, 0xA5CB3211, 0x160000}};
  int check = 1251776119;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1668) {
  my_decimal decimal = {{0x2DE00000, 0x55BAE49D, 0xA5CB3211, 0x80160000}};
  int check = -895707529;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1669) {
  my_decimal decimal = {{0x9CCC0000, 0x505186D2, 0x2BEF7263, 0x150000}};
  int check = 1263499921;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1670) {
  my_decimal decimal = {{0x9CCC0000, 0x505186D2, 0x2BEF7263, 0x80150000}};
  int check = -883983727;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1671) {
  my_decimal decimal = {{0x30EF053, 0x0, 0x0, 0x10000}};
  int check = 1251776119;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1672) {
  my_decimal decimal = {{0x30EF053, 0x0, 0x0, 0x80010000}};
  int check = -895707529;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1673) {
  my_decimal decimal = {{0x2A76C5EB, 0x3, 0x0, 0x30000}};
  int check = 1263499921;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1674) {
  my_decimal decimal = {{0x2A76C5EB, 0x3, 0x0, 0x80030000}};
  int check = -883983727;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1675) {
  my_decimal decimal = {{0xD4C00000, 0x48CA7FBF, 0xA5CB3102, 0x160000}};
  int check = 1251776118;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1676) {
  my_decimal decimal = {{0xD4C00000, 0x48CA7FBF, 0xA5CB3102, 0x80160000}};
  int check = -895707530;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1677) {
  my_decimal decimal = {{0x3C380000, 0x7C3FE6F9, 0x2BEF721B, 0x150000}};
  int check = 1263499920;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1678) {
  my_decimal decimal = {{0x3C380000, 0x7C3FE6F9, 0x2BEF721B, 0x80150000}};
  int check = -883983728;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1679) {
  my_decimal decimal = {{0x4E4B3B, 0x0, 0x0, 0x0}};
  int check = 1251776118;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1680) {
  my_decimal decimal = {{0x4E4B3B, 0x0, 0x0, 0x80000000}};
  int check = -895707530;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1681) {
  my_decimal decimal = {{0x510BE013, 0x0, 0x0, 0x20000}};
  int check = 1263499920;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1682) {
  my_decimal decimal = {{0x510BE013, 0x0, 0x0, 0x80020000}};
  int check = -883983728;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1683) {
  my_decimal decimal = {{0x7BA00000, 0x3BDA1AE2, 0xA5CB2FF3, 0x160000}};
  int check = 1251776117;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1684) {
  my_decimal decimal = {{0x7BA00000, 0x3BDA1AE2, 0xA5CB2FF3, 0x80160000}};
  int check = -895707531;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1685) {
  my_decimal decimal = {{0xDBA40000, 0xA82E471F, 0x2BEF71D3, 0x150000}};
  int check = 1263499918;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1686) {
  my_decimal decimal = {{0xDBA40000, 0xA82E471F, 0x2BEF71D3, 0x80150000}};
  int check = -883983730;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1687) {
  my_decimal decimal = {{0x30EF049, 0x0, 0x0, 0x10000}};
  int check = 1251776117;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1688) {
  my_decimal decimal = {{0x30EF049, 0x0, 0x0, 0x80010000}};
  int check = -895707531;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1689) {
  my_decimal decimal = {{0x2A76BB91, 0x3, 0x0, 0x30000}};
  int check = 1263499918;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1690) {
  my_decimal decimal = {{0x2A76BB91, 0x3, 0x0, 0x80030000}};
  int check = -883983730;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1691) {
  my_decimal decimal = {{0xB4080000, 0x7AF5B65D, 0x248C0045, 0x160000}};
  int check = 1233785337;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1692) {
  my_decimal decimal = {{0xB4080000, 0x7AF5B65D, 0x248C0045, 0x80160000}};
  int check = -913698311;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1693) {
  my_decimal decimal = {{0xE9E20000, 0x85D7F011, 0x60D9671E, 0x160000}};
  int check = 1245114730;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1694) {
  my_decimal decimal = {{0xE9E20000, 0x85D7F011, 0x60D9671E, 0x80160000}};
  int check = -902368918;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1695) {
  my_decimal decimal = {{0x436AC695, 0x0, 0x0, 0x30000}};
  int check = 1233785337;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1696) {
  my_decimal decimal = {{0x436AC695, 0x0, 0x0, 0x80030000}};
  int check = -913698311;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1697) {
  my_decimal decimal = {{0xC987903D, 0x45, 0x0, 0x50000}};
  int check = 1245114730;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1698) {
  my_decimal decimal = {{0xC987903D, 0x45, 0x0, 0x80050000}};
  int check = -902368918;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1699) {
  my_decimal decimal = {{0x80F00000, 0x2D5B74C5, 0x5D8F5C, 0x140000}};
  int check = 1233785336;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1700) {
  my_decimal decimal = {{0x80F00000, 0x2D5B74C5, 0x5D8F5C, 0x80140000}};
  int check = -913698312;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1701) {
  my_decimal decimal = {{0x78700000, 0xF3ABE072, 0x60D9666A, 0x160000}};
  int check = 1245114729;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1702) {
  my_decimal decimal = {{0x78700000, 0xF3ABE072, 0x60D9666A, 0x80160000}};
  int check = -902368919;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1703) {
  my_decimal decimal = {{0x11423F, 0x0, 0x0, 0x0}};
  int check = 1233785336;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1704) {
  my_decimal decimal = {{0x11423F, 0x0, 0x0, 0x80000000}};
  int check = -913698312;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1705) {
  my_decimal decimal = {{0x11DD9337, 0x0, 0x0, 0x20000}};
  int check = 1245114729;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1706) {
  my_decimal decimal = {{0x11DD9337, 0x0, 0x0, 0x80020000}};
  int check = -902368919;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1707) {
  my_decimal decimal = {{0x7780000, 0xF47D83EF, 0x248BFFBD, 0x160000}};
  int check = 1233785335;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1708) {
  my_decimal decimal = {{0x7780000, 0xF47D83EF, 0x248BFFBD, 0x80160000}};
  int check = -913698313;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1709) {
  my_decimal decimal = {{0x6FE0000, 0x617FD0D3, 0x60D965B7, 0x160000}};
  int check = 1245114727;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1710) {
  my_decimal decimal = {{0x6FE0000, 0x617FD0D3, 0x60D965B7, 0x80160000}};
  int check = -902368921;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1711) {
  my_decimal decimal = {{0x436AC59B, 0x0, 0x0, 0x30000}};
  int check = 1233785335;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1712) {
  my_decimal decimal = {{0x436AC59B, 0x0, 0x0, 0x80030000}};
  int check = -913698313;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1713) {
  my_decimal decimal = {{0xC9868D73, 0x45, 0x0, 0x50000}};
  int check = 1245114727;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1714) {
  my_decimal decimal = {{0xC9868D73, 0x45, 0x0, 0x80050000}};
  int check = -902368921;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1715) {
  my_decimal decimal = {{0x6A130000, 0x68905D3D, 0x2A5A0565, 0x170000}};
  int check = 1207959551;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1716) {
  my_decimal decimal = {{0x6A130000, 0x68905D3D, 0x2A5A0565, 0x80170000}};
  int check = -939524097;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1717) {
  my_decimal decimal = {{0x5918C000, 0x884B5D7C, 0x703B5B19, 0x170000}};
  int check = 1219074457;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1718) {
  my_decimal decimal = {{0x5918C000, 0x884B5D7C, 0x703B5B19, 0x80170000}};
  int check = -928409191;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1719) {
  my_decimal decimal = {{0x2CFECED3, 0x131, 0x0, 0x70000}};
  int check = 1207959551;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1720) {
  my_decimal decimal = {{0x2CFECED3, 0x131, 0x0, 0x80070000}};
  int check = -939524097;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1721) {
  my_decimal decimal = {{0x93C4186B, 0x13BE7, 0x0, 0x90000}};
  int check = 1219074457;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1722) {
  my_decimal decimal = {{0x93C4186B, 0x13BE7, 0x0, 0x80090000}};
  int check = -928409191;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1723) {
  my_decimal decimal = {{0x9F6D0000, 0x19D39B77, 0x2A59F08D, 0x170000}};
  int check = 1207959425;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1724) {
  my_decimal decimal = {{0x9F6D0000, 0x19D39B77, 0x2A59F08D, 0x80170000}};
  int check = -939524223;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1725) {
  my_decimal decimal = {{0x33474000, 0x513D8F30, 0x703B23DC, 0x170000}};
  int check = 1219074373;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1726) {
  my_decimal decimal = {{0x33474000, 0x513D8F30, 0x703B23DC, 0x80170000}};
  int check = -928409275;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1727) {
  my_decimal decimal = {{0x2C689AAD, 0x131, 0x0, 0x70000}};
  int check = 1207959425;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1728) {
  my_decimal decimal = {{0x2C689AAD, 0x131, 0x0, 0x80070000}};
  int check = -939524223;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1729) {
  my_decimal decimal = {{0xF8481D15, 0x13BE6, 0x0, 0x90000}};
  int check = 1219074373;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1730) {
  my_decimal decimal = {{0xF8481D15, 0x13BE6, 0x0, 0x80090000}};
  int check = -928409275;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1731) {
  my_decimal decimal = {{0x903F0000, 0xDC1588F, 0x47, 0x100000}};
  int check = 1207959424;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1732) {
  my_decimal decimal = {{0x903F0000, 0xDC1588F, 0x47, 0x80100000}};
  int check = -939524224;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1733) {
  my_decimal decimal = {{0x51370000, 0x3D24AC9C, 0x498D, 0x120000}};
  int check = 1219074373;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1734) {
  my_decimal decimal = {{0x51370000, 0x3D24AC9C, 0x498D, 0x80120000}};
  int check = -928409275;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1735) {
  my_decimal decimal = {{0x1FFFF, 0x0, 0x0, 0x0}};
  int check = 1207959424;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1736) {
  my_decimal decimal = {{0x1FFFF, 0x0, 0x0, 0x80000000}};
  int check = -939524224;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1737) {
  my_decimal decimal = {{0x211FEF7, 0x0, 0x0, 0x20000}};
  int check = 1219074373;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1738) {
  my_decimal decimal = {{0x211FEF7, 0x0, 0x0, 0x80020000}};
  int check = -928409275;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1739) {
  my_decimal decimal = {{0x73930000, 0x65C87BF2, 0x2A59F038, 0x170000}};
  int check = 1207959423;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1740) {
  my_decimal decimal = {{0x73930000, 0x65C87BF2, 0x2A59F038, 0x80170000}};
  int check = -939524225;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1741) {
  my_decimal decimal = {{0xE578C000, 0xDA867BA8, 0x703B22FB, 0x170000}};
  int check = 1219074372;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1742) {
  my_decimal decimal = {{0xE578C000, 0xDA867BA8, 0x703B22FB, 0x80170000}};
  int check = -928409276;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1743) {
  my_decimal decimal = {{0x2C663853, 0x131, 0x0, 0x70000}};
  int check = 1207959423;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1744) {
  my_decimal decimal = {{0x2C663853, 0x131, 0x0, 0x80070000}};
  int check = -939524225;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1745) {
  my_decimal decimal = {{0xF5D04DEB, 0x13BE6, 0x0, 0x90000}};
  int check = 1219074372;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1746) {
  my_decimal decimal = {{0xF5D04DEB, 0x13BE6, 0x0, 0x80090000}};
  int check = -928409276;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1747) {
  my_decimal decimal = {{0x78B10000, 0x597B1594, 0x234B0494, 0x170000}};
  int check = 1205163349;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1748) {
  my_decimal decimal = {{0x78B10000, 0x597B1594, 0x234B0494, 0x80170000}};
  int check = -942320299;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1749) {
  my_decimal decimal = {{0x73084000, 0xB9EC92C9, 0x5D86CC22, 0x170000}};
  int check = 1217221973;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1750) {
  my_decimal decimal = {{0x73084000, 0xB9EC92C9, 0x5D86CC22, 0x80170000}};
  int check = -930261675;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1751) {
  my_decimal decimal = {{0x502A44F1, 0xFE, 0x0, 0x70000}};
  int check = 1205163349;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1752) {
  my_decimal decimal = {{0x502A44F1, 0xFE, 0x0, 0x80070000}};
  int check = -942320299;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1753) {
  my_decimal decimal = {{0xFBC15D79, 0x10740, 0x0, 0x90000}};
  int check = 1217221973;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1754) {
  my_decimal decimal = {{0xFBC15D79, 0x10740, 0x0, 0x80090000}};
  int check = -930261675;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1755) {
  my_decimal decimal = {{0x95ED0000, 0x2BF60182, 0x1FC38456, 0x170000}};
  int check = 1203765249;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1756) {
  my_decimal decimal = {{0x95ED0000, 0x2BF60182, 0x1FC38456, 0x80170000}};
  int check = -943718399;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1757) {
  my_decimal decimal = {{0xA6E74000, 0x8E18B733, 0x542C8517, 0x170000}};
  int check = 1216243304;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1758) {
  my_decimal decimal = {{0xA6E74000, 0x8E18B733, 0x542C8517, 0x80170000}};
  int check = -931240344;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1759) {
  my_decimal decimal = {{0xE1C1312D, 0xE4, 0x0, 0x70000}};
  int check = 1203765249;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1760) {
  my_decimal decimal = {{0xE1C1312D, 0xE4, 0x0, 0x80070000}};
  int check = -943718399;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1761) {
  my_decimal decimal = {{0xB0FBE795, 0xECED, 0x0, 0x90000}};
  int check = 1216243304;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1762) {
  my_decimal decimal = {{0xB0FBE795, 0xECED, 0x0, 0x80090000}};
  int check = -931240344;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1763) {
  my_decimal decimal = {{0xF0000, 0x0, 0x0, 0x10000}};
  int check = 1203765248;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1764) {
  my_decimal decimal = {{0xF0000, 0x0, 0x0, 0x80010000}};
  int check = -943718400;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1765) {
  my_decimal decimal = {{0xF870000, 0x0, 0x0, 0x30000}};
  int check = 1216243302;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1766) {
  my_decimal decimal = {{0xF870000, 0x0, 0x0, 0x80030000}};
  int check = -931240346;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1767) {
  my_decimal decimal = {{0x18000, 0x0, 0x0, 0x0}};
  int check = 1203765248;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1768) {
  my_decimal decimal = {{0x18000, 0x0, 0x0, 0x80000000}};
  int check = -943718400;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1769) {
  my_decimal decimal = {{0x18D8000, 0x0, 0x0, 0x20000}};
  int check = 1216243302;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1770) {
  my_decimal decimal = {{0x18D8000, 0x0, 0x0, 0x80020000}};
  int check = -931240346;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1771) {
  my_decimal decimal = {{0x6A130000, 0x77EAE1FD, 0x1FC38401, 0x170000}};
  int check = 1203765247;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1772) {
  my_decimal decimal = {{0x6A130000, 0x77EAE1FD, 0x1FC38401, 0x80170000}};
  int check = -943718401;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1773) {
  my_decimal decimal = {{0x5918C000, 0x1761A3AC, 0x542C8437, 0x170000}};
  int check = 1216243301;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1774) {
  my_decimal decimal = {{0x5918C000, 0x1761A3AC, 0x542C8437, 0x80170000}};
  int check = -931240347;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1775) {
  my_decimal decimal = {{0xE1BECED3, 0xE4, 0x0, 0x70000}};
  int check = 1203765247;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1776) {
  my_decimal decimal = {{0xE1BECED3, 0xE4, 0x0, 0x80070000}};
  int check = -943718401;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1777) {
  my_decimal decimal = {{0xAE84186B, 0xECED, 0x0, 0x90000}};
  int check = 1216243301;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1778) {
  my_decimal decimal = {{0xAE84186B, 0xECED, 0x0, 0x80090000}};
  int check = -931240347;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1779) {
  my_decimal decimal = {{0xB1BD0000, 0xE4D66C9D, 0x2D2CD28, 0x160000}};
  int check = 1202367146;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1780) {
  my_decimal decimal = {{0xB1BD0000, 0xE4D66C9D, 0x2D2CD28, 0x80160000}};
  int check = -945116502;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1781) {
  my_decimal decimal = {{0xE6108000, 0xB0323E52, 0x4AD23CBB, 0x170000}};
  int check = 1214390817;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1782) {
  my_decimal decimal = {{0xE6108000, 0xB0323E52, 0x4AD23CBB, 0x80170000}};
  int check = -933092831;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1783) {
  my_decimal decimal = {{0xEE6D0000, 0x857C37FE, 0x1C3BFCD0, 0x170000}};
  int check = 1202367105;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1784) {
  my_decimal decimal = {{0xEE6D0000, 0x857C37FE, 0x1C3BFCD0, 0x80170000}};
  int check = -945116543;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1785) {
  my_decimal decimal = {{0x2B074000, 0x2E892DFD, 0x4AD22AC2, 0x170000}};
  int check = 1214390763;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1786) {
  my_decimal decimal = {{0x2B074000, 0x2E892DFD, 0x4AD22AC2, 0x80170000}};
  int check = -933092885;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1787) {
  my_decimal decimal = {{0x7323A9AD, 0xCB, 0x0, 0x70000}};
  int check = 1202367105;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1788) {
  my_decimal decimal = {{0x7323A9AD, 0xCB, 0x0, 0x80070000}};
  int check = -945116543;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1789) {
  my_decimal decimal = {{0x2FEAA415, 0xD29A, 0x0, 0x90000}};
  int check = 1214390763;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1790) {
  my_decimal decimal = {{0x2FEAA415, 0xD29A, 0x0, 0x80090000}};
  int check = -933092885;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1791) {
  my_decimal decimal = {{0x30150000, 0x5E8CBD5B, 0x2F, 0x100000}};
  int check = 1202367104;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1792) {
  my_decimal decimal = {{0x30150000, 0x5E8CBD5B, 0x2F, 0x80100000}};
  int check = -945116544;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1793) {
  my_decimal decimal = {{0xC5BD0000, 0xDFB00364, 0x3108, 0x120000}};
  int check = 1214390762;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1794) {
  my_decimal decimal = {{0xC5BD0000, 0xDFB00364, 0x3108, 0x80120000}};
  int check = -933092886;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1795) {
  my_decimal decimal = {{0x15555, 0x0, 0x0, 0x0}};
  int check = 1202367104;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1796) {
  my_decimal decimal = {{0x15555, 0x0, 0x0, 0x80000000}};
  int check = -945116544;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1797) {
  my_decimal decimal = {{0x16154FD, 0x0, 0x0, 0x20000}};
  int check = 1214390762;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1798) {
  my_decimal decimal = {{0x16154FD, 0x0, 0x0, 0x80020000}};
  int check = -933092886;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1799) {
  my_decimal decimal = {{0xC2930000, 0xD1711879, 0x1C3BFC7B, 0x170000}};
  int check = 1202367103;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1800) {
  my_decimal decimal = {{0xC2930000, 0xD1711879, 0x1C3BFC7B, 0x80170000}};
  int check = -945116545;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1801) {
  my_decimal decimal = {{0xDD38C000, 0xB7D21A75, 0x4AD229E1, 0x170000}};
  int check = 1214390760;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1802) {
  my_decimal decimal = {{0xDD38C000, 0xB7D21A75, 0x4AD229E1, 0x80170000}};
  int check = -933092888;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1803) {
  my_decimal decimal = {{0x73214753, 0xCB, 0x0, 0x70000}};
  int check = 1202367103;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1804) {
  my_decimal decimal = {{0x73214753, 0xCB, 0x0, 0x80070000}};
  int check = -945116545;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1805) {
  my_decimal decimal = {{0x2D72D4EB, 0xD29A, 0x0, 0x90000}};
  int check = 1214390760;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1806) {
  my_decimal decimal = {{0x2D72D4EB, 0xD29A, 0x0, 0x80090000}};
  int check = -933092888;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1807) {
  my_decimal decimal = {{0xD2F68000, 0x4C154911, 0x1027E744, 0x170000}};
  int check = 1195593729;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1808) {
  my_decimal decimal = {{0xD2F68000, 0x4C154911, 0x1027E744, 0x80170000}};
  int check = -951889919;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1809) {
  my_decimal decimal = {{0xD573A000, 0x63386808, 0x2AD024DB, 0x170000}};
  int check = 1208050945;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1810) {
  my_decimal decimal = {{0xD573A000, 0x63386808, 0x2AD024DB, 0x80170000}};
  int check = -939432703;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1811) {
  my_decimal decimal = {{0x273F45E1, 0x48C, 0x0, 0x80000}};
  int check = 1195593729;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1812) {
  my_decimal decimal = {{0x273F45E1, 0x48C, 0x0, 0x80080000}};
  int check = -951889919;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1813) {
  my_decimal decimal = {{0xA07F55E9, 0x4B514, 0x0, 0xA0000}};
  int check = 1208050945;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1814) {
  my_decimal decimal = {{0xA07F55E9, 0x4B514, 0x0, 0x800A0000}};
  int check = -939432703;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1815) {
  my_decimal decimal = {{0x37E08000, 0x11C379, 0x0, 0xB0000}};
  int check = 1195593728;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1816) {
  my_decimal decimal = {{0x37E08000, 0x11C379, 0x0, 0x800B0000}};
  int check = -951889920;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1817) {
  my_decimal decimal = {{0xD7648000, 0x1263587A, 0x0, 0xD0000}};
  int check = 1208050944;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1818) {
  my_decimal decimal = {{0xD7648000, 0x1263587A, 0x0, 0x800D0000}};
  int check = -939432704;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1819) {
  my_decimal decimal = {{0xC350, 0x0, 0x0, 0x0}};
  int check = 1195593728;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1820) {
  my_decimal decimal = {{0xC350, 0x0, 0x0, 0x80000000}};
  int check = -951889920;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1821) {
  my_decimal decimal = {{0xCA2DD0, 0x0, 0x0, 0x20000}};
  int check = 1208050944;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1822) {
  my_decimal decimal = {{0xCA2DD0, 0x0, 0x0, 0x80020000}};
  int check = -939432704;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1823) {
  my_decimal decimal = {{0x3D098000, 0xF20FB94F, 0x1027E719, 0x170000}};
  int check = 1195593727;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1824) {
  my_decimal decimal = {{0x3D098000, 0xF20FB94F, 0x1027E719, 0x80170000}};
  int check = -951889921;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1825) {
  my_decimal decimal = {{0x2E8C6000, 0x27DCDE45, 0x2AD0246B, 0x170000}};
  int check = 1208050943;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1826) {
  my_decimal decimal = {{0x2E8C6000, 0x27DCDE45, 0x2AD0246B, 0x80170000}};
  int check = -939432705;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1827) {
  my_decimal decimal = {{0x27335A1F, 0x48C, 0x0, 0x80000}};
  int check = 1195593727;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1828) {
  my_decimal decimal = {{0x27335A1F, 0x48C, 0x0, 0x80080000}};
  int check = -951889921;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1829) {
  my_decimal decimal = {{0x94284A17, 0x4B514, 0x0, 0xA0000}};
  int check = 1208050943;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1830) {
  my_decimal decimal = {{0x94284A17, 0x4B514, 0x0, 0x800A0000}};
  int check = -939432705;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1831) {
  my_decimal decimal = {{0x257B4000, 0x2F82FE4D, 0xA56FA66, 0x170000}};
  int check = 1190789121;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1832) {
  my_decimal decimal = {{0x257B4000, 0x2F82FE4D, 0xA56FA66, 0x80170000}};
  int check = -956694527;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1833) {
  my_decimal decimal = {{0x9B9D000, 0x311B21E6, 0x1B667DF5, 0x170000}};
  int check = 1202036737;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1834) {
  my_decimal decimal = {{0x9B9D000, 0x311B21E6, 0x1B667DF5, 0x80170000}};
  int check = -945446911;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1835) {
  my_decimal decimal = {{0x94BFCD65, 0x1D1A, 0x0, 0x90000}};
  int check = 1190789121;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1836) {
  my_decimal decimal = {{0x94BFCD65, 0x1D1A, 0x0, 0x80090000}};
  int check = -956694527;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1837) {
  my_decimal decimal = {{0xFA8B9D8D, 0x1E2083, 0x0, 0xB0000}};
  int check = 1202036737;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1838) {
  my_decimal decimal = {{0xFA8B9D8D, 0x1E2083, 0x0, 0x800B0000}};
  int check = -945446911;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1839) {
  my_decimal decimal = {{0x73594000, 0x7, 0x0, 0x60000}};
  int check = 1190789120;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1840) {
  my_decimal decimal = {{0x73594000, 0x7, 0x0, 0x80060000}};
  int check = -956694528;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1841) {
  my_decimal decimal = {{0x67634000, 0x7B6, 0x0, 0x80000}};
  int check = 1202036736;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1842) {
  my_decimal decimal = {{0x67634000, 0x7B6, 0x0, 0x80080000}};
  int check = -945446912;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1843) {
  my_decimal decimal = {{0x7D00, 0x0, 0x0, 0x0}};
  int check = 1190789120;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1844) {
  my_decimal decimal = {{0x7D00, 0x0, 0x0, 0x80000000}};
  int check = -956694528;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1845) {
  my_decimal decimal = {{0x816500, 0x0, 0x0, 0x20000}};
  int check = 1202036736;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1846) {
  my_decimal decimal = {{0x816500, 0x0, 0x0, 0x80020000}};
  int check = -945446912;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1847) {
  my_decimal decimal = {{0xDA84C000, 0x280366B, 0xA56FA51, 0x170000}};
  int check = 1190789119;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1848) {
  my_decimal decimal = {{0xDA84C000, 0x280366B, 0xA56FA51, 0x80170000}};
  int check = -956694529;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1849) {
  my_decimal decimal = {{0x36463000, 0x136D5D04, 0x1B667DBD, 0x170000}};
  int check = 1202036735;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1850) {
  my_decimal decimal = {{0x36463000, 0x136D5D04, 0x1B667DBD, 0x80170000}};
  int check = -945446913;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1851) {
  my_decimal decimal = {{0x9484329B, 0x1D1A, 0x0, 0x90000}};
  int check = 1190789119;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1852) {
  my_decimal decimal = {{0x9484329B, 0x1D1A, 0x0, 0x80090000}};
  int check = -956694529;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1853) {
  my_decimal decimal = {{0xBCD86273, 0x1E2083, 0x0, 0xB0000}};
  int check = 1202036735;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1854) {
  my_decimal decimal = {{0xBCD86273, 0x1E2083, 0x0, 0x800B0000}};
  int check = -945446913;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1855) {
  my_decimal decimal = {{0xA57B400, 0xC8ED4219, 0x54B40B, 0x170000}};
  int check = 1149239297;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1856) {
  my_decimal decimal = {{0xA57B400, 0xC8ED4219, 0x54B40B, 0x80170000}};
  int check = -998244351;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1857) {
  my_decimal decimal = {{0xB4C95400, 0xFD996BEB, 0x57AE6032, 0x190000}};
  int check = 1160354203;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1858) {
  my_decimal decimal = {{0xB4C95400, 0xFD996BEB, 0x57AE6032, 0x80190000}};
  int check = -987129445;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1859) {
  my_decimal decimal = {{0x13427395, 0x24613A, 0x0, 0xD0000}};
  int check = 1149239297;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1860) {
  my_decimal decimal = {{0x13427395, 0x24613A, 0x0, 0x800D0000}};
  int check = -998244351;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1861) {
  my_decimal decimal = {{0xEFC9A53D, 0x25A8A51D, 0x0, 0xF0000}};
  int check = 1160354203;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1862) {
  my_decimal decimal = {{0xEFC9A53D, 0x25A8A51D, 0x0, 0x800F0000}};
  int check = -987129445;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1863) {
  my_decimal decimal = {{0x400, 0x0, 0x0, 0x0}};
  int check = 1149239296;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1864) {
  my_decimal decimal = {{0x400, 0x0, 0x0, 0x80000000}};
  int check = -998244352;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1865) {
  my_decimal decimal = {{0x42400, 0x0, 0x0, 0x20000}};
  int check = 1160354202;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1866) {
  my_decimal decimal = {{0x42400, 0x0, 0x0, 0x80020000}};
  int check = -987129446;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1867) {
  my_decimal decimal = {{0x7AD42600, 0xCAD120BA, 0x54B40A, 0x170000}};
  int check = 1149239295;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1868) {
  my_decimal decimal = {{0x7AD42600, 0xCAD120BA, 0x54B40A, 0x80170000}};
  int check = -998244353;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1869) {
  my_decimal decimal = {{0x259B5600, 0xF27AE109, 0x57AE5F2B, 0x190000}};
  int check = 1160354201;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1870) {
  my_decimal decimal = {{0x259B5600, 0xF27AE109, 0x57AE5F2B, 0x80190000}};
  int check = -987129447;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1871) {
  my_decimal decimal = {{0x7D33BE17, 0x16BCC40, 0x0, 0xE0000}};
  int check = 1149239295;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1872) {
  my_decimal decimal = {{0x7D33BE17, 0x16BCC40, 0x0, 0x800E0000}};
  int check = -998244353;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1873) {
  my_decimal decimal = {{0x9A8FC5CF, 0x78966EC1, 0x1, 0x100000}};
  int check = 1160354201;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1874) {
  my_decimal decimal = {{0x9A8FC5CF, 0x78966EC1, 0x1, 0x80100000}};
  int check = -987129447;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1875) {
  my_decimal decimal = {{0x852BDA00, 0xE476A10C, 0x2A5A05, 0x170000}};
  int check = 1140850689;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1876) {
  my_decimal decimal = {{0x852BDA00, 0xE476A10C, 0x2A5A05, 0x80170000}};
  int check = -1006632959;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1877) {
  my_decimal decimal = {{0xDA64AA00, 0x7ECCB5F5, 0x2BD73019, 0x190000}};
  int check = 1151965595;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1878) {
  my_decimal decimal = {{0xDA64AA00, 0x7ECCB5F5, 0x2BD73019, 0x80190000}};
  int check = -995518053;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1879) {
  my_decimal decimal = {{0x604C41E9, 0xB5E622, 0x0, 0xE0000}};
  int check = 1140850689;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1880) {
  my_decimal decimal = {{0x604C41E9, 0xB5E622, 0x0, 0x800E0000}};
  int check = -1006632959;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1881) {
  my_decimal decimal = {{0xAEF03A31, 0xBC4B3995, 0x0, 0x100000}};
  int check = 1151965595;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1882) {
  my_decimal decimal = {{0xAEF03A31, 0xBC4B3995, 0x0, 0x80100000}};
  int check = -995518053;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1883) {
  my_decimal decimal = {{0x200, 0x0, 0x0, 0x0}};
  int check = 1140850688;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1884) {
  my_decimal decimal = {{0x200, 0x0, 0x0, 0x80000000}};
  int check = -1006632960;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1885) {
  my_decimal decimal = {{0x21200, 0x0, 0x0, 0x20000}};
  int check = 1151965594;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1886) {
  my_decimal decimal = {{0x21200, 0x0, 0x0, 0x80020000}};
  int check = -995518054;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1887) {
  my_decimal decimal = {{0x3D6A1300, 0x6568905D, 0x2A5A05, 0x170000}};
  int check = 1140850687;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1888) {
  my_decimal decimal = {{0x3D6A1300, 0x6568905D, 0x2A5A05, 0x80170000}};
  int check = -1006632961;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1889) {
  my_decimal decimal = {{0x92CDAB00, 0xF93D7084, 0x2BD72F95, 0x190000}};
  int check = 1151965593;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1890) {
  my_decimal decimal = {{0x92CDAB00, 0xF93D7084, 0x2BD72F95, 0x80190000}};
  int check = -995518055;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1891) {
  my_decimal decimal = {{0x7202B673, 0x71AFD42, 0x0, 0xF0000}};
  int check = 1140850687;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1892) {
  my_decimal decimal = {{0x7202B673, 0x71AFD42, 0x0, 0x800F0000}};
  int check = -1006632961;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1893) {
  my_decimal decimal = {{0x4CEDD0B, 0x5AF029C8, 0x7, 0x110000}};
  int check = 1151965593;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1894) {
  my_decimal decimal = {{0x4CEDD0B, 0x5AF029C8, 0x7, 0x80110000}};
  int check = -995518055;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1895) {
  my_decimal decimal = {{0x59153700, 0xB91B0DE1, 0x43C33, 0x160000}};
  int check = 1140850686;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1896) {
  my_decimal decimal = {{0x59153700, 0xB91B0DE1, 0x43C33, 0x80160000}};
  int check = -1006632962;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1897) {
  my_decimal decimal = {{0x36F5EF00, 0x9D015E45, 0x462518A, 0x180000}};
  int check = 1151965592;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1898) {
  my_decimal decimal = {{0x36F5EF00, 0x9D015E45, 0x462518A, 0x80180000}};
  int check = -995518056;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1899) {
  my_decimal decimal = {{0x88B3BE17, 0xB5E61F, 0x0, 0xE0000}};
  int check = 1140850686;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1900) {
  my_decimal decimal = {{0x88B3BE17, 0xB5E61F, 0x0, 0x800E0000}};
  int check = -1006632962;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1901) {
  my_decimal decimal = {{0x820FC5CF, 0xBC4B36A4, 0x0, 0x100000}};
  int check = 1151965592;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1902) {
  my_decimal decimal = {{0x820FC5CF, 0xBC4B36A4, 0x0, 0x80100000}};
  int check = -995518056;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1903) {
  my_decimal decimal = {{0x9478B100, 0x94597B15, 0x234B04, 0x170000}};
  int check = 1138054485;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1904) {
  my_decimal decimal = {{0x9478B100, 0x94597B15, 0x234B04, 0x80170000}};
  int check = -1009429163;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1905) {
  my_decimal decimal = {{0xB0EF3900, 0x90A06956, 0x2488A7BD, 0x190000}};
  int check = 1150113109;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1906) {
  my_decimal decimal = {{0xB0EF3900, 0x90A06956, 0x2488A7BD, 0x80190000}};
  int check = -997370539;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1907) {
  my_decimal decimal = {{0x41D63CD1, 0x5EBD310, 0x0, 0xF0000}};
  int check = 1138054485;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1908) {
  my_decimal decimal = {{0x41D63CD1, 0x5EBD310, 0x0, 0x800F0000}};
  int check = -1009429163;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1909) {
  my_decimal decimal = {{0x26C4F459, 0x211D7BD4, 0x6, 0x110000}};
  int check = 1150113109;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1910) {
  my_decimal decimal = {{0x26C4F459, 0x211D7BD4, 0x6, 0x80110000}};
  int check = -997370539;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1911) {
  my_decimal decimal = {{0xF00, 0x0, 0x0, 0x10000}};
  int check = 1136656384;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1912) {
  my_decimal decimal = {{0xF00, 0x0, 0x0, 0x80010000}};
  int check = -1010827264;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1913) {
  my_decimal decimal = {{0xF8700, 0x0, 0x0, 0x30000}};
  int check = 1149134438;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1914) {
  my_decimal decimal = {{0xF8700, 0x0, 0x0, 0x80030000}};
  int check = -998349210;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1915) {
  my_decimal decimal = {{0x180, 0x0, 0x0, 0x0}};
  int check = 1136656384;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1916) {
  my_decimal decimal = {{0x180, 0x0, 0x0, 0x80000000}};
  int check = -1010827264;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1917) {
  my_decimal decimal = {{0x18D80, 0x0, 0x0, 0x20000}};
  int check = 1149134438;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1918) {
  my_decimal decimal = {{0x18D80, 0x0, 0x0, 0x80020000}};
  int check = -998349210;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1919) {
  my_decimal decimal = {{0x9DB1BD00, 0x28E4D66C, 0x2D2CD, 0x160000}};
  int check = 1135258282;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1920) {
  my_decimal decimal = {{0x9DB1BD00, 0x28E4D66C, 0x2D2CD, 0x80160000}};
  int check = -1012225366;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1921) {
  my_decimal decimal = {{0x3CFCA500, 0x54E1F66F, 0x2EC365F, 0x180000}};
  int check = 1147281953;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1922) {
  my_decimal decimal = {{0x3CFCA500, 0x54E1F66F, 0x2EC365F, 0x80180000}};
  int check = -1000201695;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1923) {
  my_decimal decimal = {{0x7F113F5D, 0x794415, 0x0, 0xE0000}};
  int check = 1135258282;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1924) {
  my_decimal decimal = {{0x7F113F5D, 0x794415, 0x0, 0x800E0000}};
  int check = -1012225366;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1925) {
  my_decimal decimal = {{0x88DA9745, 0x7D877A40, 0x0, 0x100000}};
  int check = 1147281953;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1926) {
  my_decimal decimal = {{0x88DA9745, 0x7D877A40, 0x0, 0x80100000}};
  int check = -1000201695;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1927) {
  my_decimal decimal = {{0x90A57B40, 0xBC8ED421, 0x54B40, 0x170000}};
  int check = 1115684865;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1928) {
  my_decimal decimal = {{0x90A57B40, 0xBC8ED421, 0x54B40, 0x80170000}};
  int check = -1031798783;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1929) {
  my_decimal decimal = {{0xBB4C9540, 0x2FD996BE, 0x57AE603, 0x190000}};
  int check = 1126799771;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1930) {
  my_decimal decimal = {{0xBB4C9540, 0x2FD996BE, 0x57AE603, 0x80190000}};
  int check = -1020683877;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1931) {
  my_decimal decimal = {{0x53C2EC5, 0x58D15EC9, 0x0, 0x110000}};
  int check = 1115684865;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1932) {
  my_decimal decimal = {{0x53C2EC5, 0x58D15EC9, 0x0, 0x80110000}};
  int check = -1031798783;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1933) {
  my_decimal decimal = {{0x6B4C69ED, 0xF0BB1E16, 0x5B, 0x130000}};
  int check = 1126799771;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1934) {
  my_decimal decimal = {{0x6B4C69ED, 0xF0BB1E16, 0x5B, 0x80130000}};
  int check = -1020683877;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1935) {
  my_decimal decimal = {{0x40, 0x0, 0x0, 0x0}};
  int check = 1115684864;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1936) {
  my_decimal decimal = {{0x40, 0x0, 0x0, 0x80000000}};
  int check = -1031798784;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1937) {
  my_decimal decimal = {{0x4240, 0x0, 0x0, 0x20000}};
  int check = 1126799770;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1938) {
  my_decimal decimal = {{0x4240, 0x0, 0x0, 0x80020000}};
  int check = -1020683878;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1939) {
  my_decimal decimal = {{0xA7AD4260, 0xACAD120B, 0x54B40, 0x170000}};
  int check = 1115684863;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1940) {
  my_decimal decimal = {{0xA7AD4260, 0xACAD120B, 0x54B40, 0x80170000}};
  int check = -1031798785;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1941) {
  my_decimal decimal = {{0x9259B560, 0xBF27AE10, 0x57AE5F2, 0x190000}};
  int check = 1126799769;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1942) {
  my_decimal decimal = {{0x9259B560, 0xBF27AE10, 0x57AE5F2, 0x80190000}};
  int check = -1020683879;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1943) {
  my_decimal decimal = {{0xAB531627, 0x782DA971, 0x3, 0x120000}};
  int check = 1115684863;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1944) {
  my_decimal decimal = {{0xAB531627, 0x782DA971, 0x3, 0x80120000}};
  int check = -1031798785;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1945) {
  my_decimal decimal = {{0x5901EE5F, 0x674466AA, 0x397, 0x140000}};
  int check = 1126799769;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1946) {
  my_decimal decimal = {{0x5901EE5F, 0x674466AA, 0x397, 0x80140000}};
  int check = -1020683879;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1947) {
  my_decimal decimal = {{0x20, 0x0, 0x0, 0x0}};
  int check = 1107296256;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1948) {
  my_decimal decimal = {{0x20, 0x0, 0x0, 0x80000000}};
  int check = -1040187392;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1949) {
  my_decimal decimal = {{0x2120, 0x0, 0x0, 0x20000}};
  int check = 1118411162;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1950) {
  my_decimal decimal = {{0x2120, 0x0, 0x0, 0x80020000}};
  int check = -1029072486;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1951) {
  my_decimal decimal = {{0xD3D6A130, 0x56568905, 0x2A5A0, 0x170000}};
  int check = 1107296255;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1952) {
  my_decimal decimal = {{0xD3D6A130, 0x56568905, 0x2A5A0, 0x80170000}};
  int check = -1040187393;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1953) {
  my_decimal decimal = {{0x492CDAB0, 0x5F93D708, 0x2BD72F9, 0x190000}};
  int check = 1118411161;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1954) {
  my_decimal decimal = {{0x492CDAB0, 0x5F93D708, 0x2BD72F9, 0x80190000}};
  int check = -1029072487;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1955) {
  my_decimal decimal = {{0x589F6EC3, 0x58E44F38, 0x11, 0x130000}};
  int check = 1107296255;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1956) {
  my_decimal decimal = {{0x589F6EC3, 0x58E44F38, 0x11, 0x80130000}};
  int check = -1040187393;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1957) {
  my_decimal decimal = {{0xBD09A7DB, 0x4560153, 0x11F5, 0x150000}};
  int check = 1118411161;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1958) {
  my_decimal decimal = {{0xBD09A7DB, 0x4560153, 0x11F5, 0x80150000}};
  int check = -1029072487;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1959) {
  my_decimal decimal = {{0x15915370, 0x3B91B0DE, 0x43C3, 0x160000}};
  int check = 1107296254;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1960) {
  my_decimal decimal = {{0x15915370, 0x3B91B0DE, 0x43C3, 0x80160000}};
  int check = -1040187394;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1961) {
  my_decimal decimal = {{0x536F5EF0, 0xA9D015E4, 0x462518, 0x180000}};
  int check = 1118411160;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1962) {
  my_decimal decimal = {{0x536F5EF0, 0xA9D015E4, 0x462518, 0x80180000}};
  int check = -1029072488;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1963) {
  my_decimal decimal = {{0xBED31627, 0xBC16D2FC, 0x1, 0x120000}};
  int check = 1107296254;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1964) {
  my_decimal decimal = {{0xBED31627, 0xBC16D2FC, 0x1, 0x80120000}};
  int check = -1040187394;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1965) {
  my_decimal decimal = {{0x8881EE5F, 0xB3A067A1, 0x1CB, 0x140000}};
  int check = 1118411160;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1966) {
  my_decimal decimal = {{0x8881EE5F, 0xB3A067A1, 0x1CB, 0x80140000}};
  int check = -1029072488;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1967) {
  my_decimal decimal = {{0x59478B10, 0x494597B1, 0x234B0, 0x170000}};
  int check = 1104500053;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1968) {
  my_decimal decimal = {{0x59478B10, 0x494597B1, 0x234B0, 0x80170000}};
  int check = -1042983595;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1969) {
  my_decimal decimal = {{0x6B0EF390, 0xD90A0695, 0x2488A7B, 0x190000}};
  int check = 1116558677;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1970) {
  my_decimal decimal = {{0x6B0EF390, 0xD90A0695, 0x2488A7B, 0x80190000}};
  int check = -1030924971;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1971) {
  my_decimal decimal = {{0xBC0A7A41, 0x74BE4AB0, 0xE, 0x130000}};
  int check = 1104500053;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1972) {
  my_decimal decimal = {{0xBC0A7A41, 0x74BE4AB0, 0xE, 0x80130000}};
  int check = -1042983595;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1973) {
  my_decimal decimal = {{0xA6D88D49, 0xD8FB50F2, 0xEF6, 0x150000}};
  int check = 1116558677;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1974) {
  my_decimal decimal = {{0xA6D88D49, 0xD8FB50F2, 0xEF6, 0x80150000}};
  int check = -1030924971;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1975) {
  my_decimal decimal = {{0xF0, 0x0, 0x0, 0x10000}};
  int check = 1103101952;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1976) {
  my_decimal decimal = {{0xF0, 0x0, 0x0, 0x80010000}};
  int check = -1044381696;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1977) {
  my_decimal decimal = {{0xF870, 0x0, 0x0, 0x30000}};
  int check = 1115580006;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1978) {
  my_decimal decimal = {{0xF870, 0x0, 0x0, 0x80030000}};
  int check = -1031903642;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1979) {
  my_decimal decimal = {{0x18, 0x0, 0x0, 0x0}};
  int check = 1103101952;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1980) {
  my_decimal decimal = {{0x18, 0x0, 0x0, 0x80000000}};
  int check = -1044381696;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1981) {
  my_decimal decimal = {{0x18D8, 0x0, 0x0, 0x20000}};
  int check = 1115580006;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1982) {
  my_decimal decimal = {{0x18D8, 0x0, 0x0, 0x80020000}};
  int check = -1031903642;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1983) {
  my_decimal decimal = {{0xC9DB1BD0, 0xD28E4D66, 0x2D2C, 0x160000}};
  int check = 1101703850;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1984) {
  my_decimal decimal = {{0xC9DB1BD0, 0xD28E4D66, 0x2D2C, 0x80160000}};
  int check = -1045779798;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1985) {
  my_decimal decimal = {{0xF3CFCA50, 0xF54E1F66, 0x2EC365, 0x180000}};
  int check = 1113727521;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1986) {
  my_decimal decimal = {{0xF3CFCA50, 0xF54E1F66, 0x2EC365, 0x80180000}};
  int check = -1033756127;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1987) {
  my_decimal decimal = {{0x391BB20D, 0x280F387B, 0x1, 0x120000}};
  int check = 1101703850;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1988) {
  my_decimal decimal = {{0x391BB20D, 0x280F387B, 0x1, 0x80120000}};
  int check = -1045779798;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1989) {
  my_decimal decimal = {{0x1DAB4F75, 0x77C1778E, 0x132, 0x140000}};
  int check = 1113727521;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1990) {
  my_decimal decimal = {{0x1DAB4F75, 0x77C1778E, 0x132, 0x80140000}};
  int check = -1033756127;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1991) {
  my_decimal decimal = {{0x64295ED0, 0x2F23B508, 0x152D0, 0x170000}};
  int check = 1098907649;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1992) {
  my_decimal decimal = {{0x64295ED0, 0x2F23B508, 0x152D0, 0x80170000}};
  int check = -1048575999;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1993) {
  my_decimal decimal = {{0xAED32550, 0xCBF665AF, 0x15EB980, 0x190000}};
  int check = 1110022555;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1994) {
  my_decimal decimal = {{0xAED32550, 0xCBF665AF, 0x15EB980, 0x80190000}};
  int check = -1037461093;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1995) {
  my_decimal decimal = {{0x82E0913D, 0xAC7241A1, 0x8, 0x130000}};
  int check = 1098907649;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1996) {
  my_decimal decimal = {{0x82E0913D, 0xAC7241A1, 0x8, 0x80130000}};
  int check = -1048575999;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1997) {
  my_decimal decimal = {{0x7A765825, 0x8245F030, 0x8FA, 0x150000}};
  int check = 1110022555;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1998) {
  my_decimal decimal = {{0x7A765825, 0x8245F030, 0x8FA, 0x80150000}};
  int check = -1037461093;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok1999) {
  my_decimal decimal = {{0x10, 0x0, 0x0, 0x0}};
  int check = 1098907648;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2000) {
  my_decimal decimal = {{0x10, 0x0, 0x0, 0x80000000}};
  int check = -1048576000;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2001) {
  my_decimal decimal = {{0x1090, 0x0, 0x0, 0x20000}};
  int check = 1110022554;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2002) {
  my_decimal decimal = {{0x1090, 0x0, 0x0, 0x80020000}};
  int check = -1037461094;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2003) {
  my_decimal decimal = {{0xE9EB5098, 0x2B2B4482, 0x152D0, 0x170000}};
  int check = 1098907647;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2004) {
  my_decimal decimal = {{0xE9EB5098, 0x2B2B4482, 0x152D0, 0x80170000}};
  int check = -1048576001;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2005) {
  my_decimal decimal = {{0x24966D58, 0xAFC9EB84, 0x15EB97C, 0x190000}};
  int check = 1110022553;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2006) {
  my_decimal decimal = {{0x24966D58, 0xAFC9EB84, 0x15EB97C, 0x80190000}};
  int check = -1037461095;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2007) {
  my_decimal decimal = {{0xBB1D29CF, 0xBC758C19, 0x56, 0x140000}};
  int check = 1098907647;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2008) {
  my_decimal decimal = {{0xBB1D29CF, 0xBC758C19, 0x56, 0x80140000}};
  int check = -1048576001;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2009) {
  my_decimal decimal = {{0xB1304747, 0x15AE06A2, 0x59C9, 0x160000}};
  int check = 1110022553;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2010) {
  my_decimal decimal = {{0xB1304747, 0x15AE06A2, 0x59C9, 0x80160000}};
  int check = -1037461095;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2011) {
  my_decimal decimal = {{0x8511F6A8, 0xA00A0223, 0xE884, 0x170000}};
  int check = 1093644169;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2012) {
  my_decimal decimal = {{0x8511F6A8, 0xA00A0223, 0xE884, 0x80170000}};
  int check = -1053839479;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2013) {
  my_decimal decimal = {{0xBF9853E8, 0xAA5C36C4, 0xF0B149, 0x190000}};
  int check = 1105774742;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2014) {
  my_decimal decimal = {{0xBF9853E8, 0xAA5C36C4, 0xF0B149, 0x80190000}};
  int check = -1041708906;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2015) {
  my_decimal decimal = {{0x924F1F39, 0x864DD581, 0x3B, 0x140000}};
  int check = 1093644169;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2016) {
  my_decimal decimal = {{0x924F1F39, 0x864DD581, 0x3B, 0x80140000}};
  int check = -1053839479;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2017) {
  my_decimal decimal = {{0x73E75201, 0x6920320, 0x3D9E, 0x160000}};
  int check = 1105774742;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2018) {
  my_decimal decimal = {{0x73E75201, 0x6920320, 0x3D9E, 0x80160000}};
  int check = -1041708906;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2019) {
  my_decimal decimal = {{0x2894AF68, 0x1A59BBCF, 0xBE95, 0x170000}};
  int check = 1091567617;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2020) {
  my_decimal decimal = {{0x2894AF68, 0x1A59BBCF, 0xBE95, 0x80170000}};
  int check = -1055916031;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2021) {
  my_decimal decimal = {{0x1E992A8, 0x46E36971, 0xC54858, 0x190000}};
  int check = 1103023310;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2022) {
  my_decimal decimal = {{0x1E992A8, 0x46E36971, 0xC54858, 0x80190000}};
  int check = -1044460338;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2023) {
  my_decimal decimal = {{0xF172D631, 0xCA02A654, 0x30, 0x140000}};
  int check = 1091567617;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2024) {
  my_decimal decimal = {{0xF172D631, 0xCA02A654, 0x30, 0x80140000}};
  int check = -1055916031;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2025) {
  my_decimal decimal = {{0xEFDFB8B9, 0x1CBE2DED, 0x3281, 0x160000}};
  int check = 1103023310;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2026) {
  my_decimal decimal = {{0xEFDFB8B9, 0x1CBE2DED, 0x3281, 0x80160000}};
  int check = -1044460338;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2027) {
  my_decimal decimal = {{0x2328, 0x0, 0x0, 0x30000}};
  int check = 1091567616;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2028) {
  my_decimal decimal = {{0x2328, 0x0, 0x0, 0x80030000}};
  int check = -1055916032;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2029) {
  my_decimal decimal = {{0x246468, 0x0, 0x0, 0x50000}};
  int check = 1103023309;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2030) {
  my_decimal decimal = {{0x246468, 0x0, 0x0, 0x80050000}};
  int check = -1044460339;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2031) {
  my_decimal decimal = {{0x9, 0x0, 0x0, 0x0}};
  int check = 1091567616;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2032) {
  my_decimal decimal = {{0x9, 0x0, 0x0, 0x80000000}};
  int check = -1055916032;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2033) {
  my_decimal decimal = {{0x951, 0x0, 0x0, 0x20000}};
  int check = 1103023309;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2034) {
  my_decimal decimal = {{0x951, 0x0, 0x0, 0x80020000}};
  int check = -1044460339;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2035) {
  my_decimal decimal = {{0x2C6B5098, 0x17B41B76, 0xBE95, 0x170000}};
  int check = 1091567615;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2036) {
  my_decimal decimal = {{0x2C6B5098, 0x17B41B76, 0xBE95, 0x80170000}};
  int check = -1055916033;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2037) {
  my_decimal decimal = {{0xFB166D58, 0x89706D53, 0xC54855, 0x190000}};
  int check = 1103023307;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2038) {
  my_decimal decimal = {{0xFB166D58, 0x89706D53, 0xC54855, 0x80190000}};
  int check = -1044460341;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2039) {
  my_decimal decimal = {{0x5AD29CF, 0xCA01F8DC, 0x30, 0x140000}};
  int check = 1091567615;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2040) {
  my_decimal decimal = {{0x5AD29CF, 0xCA01F8DC, 0x30, 0x80140000}};
  int check = -1055916033;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2041) {
  my_decimal decimal = {{0xE0404747, 0x1C0A9BC1, 0x3281, 0x160000}};
  int check = 1103023307;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2042) {
  my_decimal decimal = {{0xE0404747, 0x1C0A9BC1, 0x3281, 0x80160000}};
  int check = -1044460341;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2043) {
  my_decimal decimal = {{0x8, 0x0, 0x0, 0x0}};
  int check = 1090519040;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2044) {
  my_decimal decimal = {{0x8, 0x0, 0x0, 0x80000000}};
  int check = -1056964608;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2045) {
  my_decimal decimal = {{0x848, 0x0, 0x0, 0x20000}};
  int check = 1101633946;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2046) {
  my_decimal decimal = {{0x848, 0x0, 0x0, 0x80020000}};
  int check = -1045849702;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2047) {
  my_decimal decimal = {{0x74F5A84C, 0x1595A241, 0xA968, 0x170000}};
  int check = 1090519039;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2048) {
  my_decimal decimal = {{0x74F5A84C, 0x1595A241, 0xA968, 0x80170000}};
  int check = -1056964609;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2049) {
  my_decimal decimal = {{0x124B36AC, 0x57E4F5C2, 0xAF5CBE, 0x190000}};
  int check = 1101633945;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2050) {
  my_decimal decimal = {{0x124B36AC, 0x57E4F5C2, 0xAF5CBE, 0x80190000}};
  int check = -1045849703;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2051) {
  my_decimal decimal = {{0xA791D10B, 0xAE4BBC80, 0x1B1, 0x150000}};
  int check = 1090519039;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2052) {
  my_decimal decimal = {{0xA791D10B, 0xAE4BBC80, 0x1B1, 0x80150000}};
  int check = -1056964609;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2053) {
  my_decimal decimal = {{0x75F16463, 0x6C66212D, 0x1C0ED, 0x170000}};
  int check = 1101633945;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2054) {
  my_decimal decimal = {{0x75F16463, 0x6C66212D, 0x1C0ED, 0x80170000}};
  int check = -1045849703;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2055) {
  my_decimal decimal = {{0x5651E2C4, 0x125165EC, 0x8D2C, 0x170000}};
  int check = 1087722837;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2056) {
  my_decimal decimal = {{0x5651E2C4, 0x125165EC, 0x8D2C, 0x80170000}};
  int check = -1059760811;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2057) {
  my_decimal decimal = {{0x5AC3BCE4, 0xF64281A5, 0x92229E, 0x190000}};
  int check = 1099781461;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2058) {
  my_decimal decimal = {{0x5AC3BCE4, 0xF64281A5, 0x92229E, 0x80190000}};
  int check = -1047702187;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2059) {
  my_decimal decimal = {{0x5D05F059, 0x66954B42, 0x169, 0x150000}};
  int check = 1087722837;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2060) {
  my_decimal decimal = {{0x5D05F059, 0x66954B42, 0x169, 0x80150000}};
  int check = -1059760811;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2061) {
  my_decimal decimal = {{0x4B25CC21, 0x308AE7B2, 0x1761B, 0x170000}};
  int check = 1099781461;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2062) {
  my_decimal decimal = {{0x4B25CC21, 0x308AE7B2, 0x1761B, 0x80170000}};
  int check = -1047702187;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2063) {
  my_decimal decimal = {{0x3C, 0x0, 0x0, 0x10000}};
  int check = 1086324736;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2064) {
  my_decimal decimal = {{0x3C, 0x0, 0x0, 0x80010000}};
  int check = -1061158912;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2065) {
  my_decimal decimal = {{0x3E1C, 0x0, 0x0, 0x30000}};
  int check = 1098802790;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2066) {
  my_decimal decimal = {{0x3E1C, 0x0, 0x0, 0x80030000}};
  int check = -1048680858;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2067) {
  my_decimal decimal = {{0x6, 0x0, 0x0, 0x0}};
  int check = 1086324736;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2068) {
  my_decimal decimal = {{0x6, 0x0, 0x0, 0x80000000}};
  int check = -1061158912;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2069) {
  my_decimal decimal = {{0x636, 0x0, 0x0, 0x20000}};
  int check = 1098802790;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2070) {
  my_decimal decimal = {{0x636, 0x0, 0x0, 0x80020000}};
  int check = -1048680858;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2071) {
  my_decimal decimal = {{0xB276C6F4, 0x34A39359, 0xB4B, 0x160000}};
  int check = 1084926634;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2072) {
  my_decimal decimal = {{0xB276C6F4, 0x34A39359, 0xB4B, 0x80160000}};
  int check = -1062557014;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2073) {
  my_decimal decimal = {{0xBCF3F294, 0x7D5387D9, 0xBB0D9, 0x180000}};
  int check = 1096950305;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2074) {
  my_decimal decimal = {{0xBCF3F294, 0x7D5387D9, 0xBB0D9, 0x80180000}};
  int check = -1050533343;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2075) {
  my_decimal decimal = {{0x93B46345, 0xE97C8408, 0x1C, 0x140000}};
  int check = 1084926634;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2076) {
  my_decimal decimal = {{0x93B46345, 0xE97C8408, 0x1C, 0x80140000}};
  int check = -1062557014;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2077) {
  my_decimal decimal = {{0xE5BAC26D, 0xB1E4ACE0, 0x1DED, 0x160000}};
  int check = 1096950305;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2078) {
  my_decimal decimal = {{0xE5BAC26D, 0xB1E4ACE0, 0x1DED, 0x80160000}};
  int check = -1050533343;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2079) {
  my_decimal decimal = {{0x4, 0x0, 0x0, 0x0}};
  int check = 1082130432;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2080) {
  my_decimal decimal = {{0x4, 0x0, 0x0, 0x80000000}};
  int check = -1065353216;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2081) {
  my_decimal decimal = {{0x424, 0x0, 0x0, 0x20000}};
  int check = 1093245338;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2082) {
  my_decimal decimal = {{0x424, 0x0, 0x0, 0x80020000}};
  int check = -1054238310;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2083) {
  my_decimal decimal = {{0xBA7AD426, 0xACAD120, 0x54B4, 0x170000}};
  int check = 1082130431;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2084) {
  my_decimal decimal = {{0xBA7AD426, 0xACAD120, 0x54B4, 0x80170000}};
  int check = -1065353217;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2085) {
  my_decimal decimal = {{0x9259B56, 0x2BF27AE1, 0x57AE5F, 0x190000}};
  int check = 1093245337;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2086) {
  my_decimal decimal = {{0x9259B56, 0x2BF27AE1, 0x57AE5F, 0x80190000}};
  int check = -1054238311;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2087) {
  my_decimal decimal = {{0x45D91537, 0x677AAE83, 0x878, 0x160000}};
  int check = 1082130431;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2088) {
  my_decimal decimal = {{0x45D91537, 0x677AAE83, 0x878, 0x80160000}};
  int check = -1065353217;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2089) {
  my_decimal decimal = {{0x4DB6F5EF, 0x1DFEA5E3, 0x8C4A3, 0x180000}};
  int check = 1093245337;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2090) {
  my_decimal decimal = {{0x4DB6F5EF, 0x1DFEA5E3, 0x8C4A3, 0x80180000}};
  int check = -1054238311;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2091) {
  my_decimal decimal = {{0xC2B22A6E, 0x6772361B, 0x878, 0x160000}};
  int check = 1082130430;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2092) {
  my_decimal decimal = {{0xC2B22A6E, 0x6772361B, 0x878, 0x80160000}};
  int check = -1065353218;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2093) {
  my_decimal decimal = {{0x8A6DEBDE, 0x153A02BC, 0x8C4A3, 0x180000}};
  int check = 1093245336;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2094) {
  my_decimal decimal = {{0x8A6DEBDE, 0x153A02BC, 0x8C4A3, 0x80180000}};
  int check = -1054238312;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2095) {
  my_decimal decimal = {{0x2D11D10B, 0xD7250569, 0xD8, 0x150000}};
  int check = 1082130430;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2096) {
  my_decimal decimal = {{0x2D11D10B, 0xD7250569, 0xD8, 0x80150000}};
  int check = -1065353218;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2097) {
  my_decimal decimal = {{0xA7716463, 0xB55299DF, 0xE076, 0x170000}};
  int check = 1093245336;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2098) {
  my_decimal decimal = {{0xA7716463, 0xB55299DF, 0xE076, 0x80170000}};
  int check = -1054238312;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2099) {
  my_decimal decimal = {{0x2B28F162, 0x928B2F6, 0x4696, 0x170000}};
  int check = 1079334229;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2100) {
  my_decimal decimal = {{0x2B28F162, 0x928B2F6, 0x4696, 0x80170000}};
  int check = -1068149419;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2101) {
  my_decimal decimal = {{0xAD61DE72, 0x7B2140D2, 0x49114F, 0x190000}};
  int check = 1091392853;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2102) {
  my_decimal decimal = {{0xAD61DE72, 0x7B2140D2, 0x49114F, 0x80190000}};
  int check = -1056090795;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2103) {
  my_decimal decimal = {{0xD11DB1BD, 0xEA784B, 0x70F, 0x160000}};
  int check = 1079334229;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2104) {
  my_decimal decimal = {{0xD11DB1BD, 0xEA784B, 0x70F, 0x80160000}};
  int check = -1068149419;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2105) {
  my_decimal decimal = {{0x77BCFCA5, 0xF2B6867B, 0x74E87, 0x180000}};
  int check = 1091392853;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2106) {
  my_decimal decimal = {{0x77BCFCA5, 0xF2B6867B, 0x74E87, 0x80180000}};
  int check = -1056090795;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2107) {
  my_decimal decimal = {{0x1E, 0x0, 0x0, 0x10000}};
  int check = 1077936128;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2108) {
  my_decimal decimal = {{0x1E, 0x0, 0x0, 0x80010000}};
  int check = -1069547520;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2109) {
  my_decimal decimal = {{0x1F0E, 0x0, 0x0, 0x30000}};
  int check = 1090414182;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2110) {
  my_decimal decimal = {{0x1F0E, 0x0, 0x0, 0x80030000}};
  int check = -1057069466;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2111) {
  my_decimal decimal = {{0x3, 0x0, 0x0, 0x0}};
  int check = 1077936128;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2112) {
  my_decimal decimal = {{0x3, 0x0, 0x0, 0x80000000}};
  int check = -1069547520;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2113) {
  my_decimal decimal = {{0x31B, 0x0, 0x0, 0x20000}};
  int check = 1090414182;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2114) {
  my_decimal decimal = {{0x31B, 0x0, 0x0, 0x80020000}};
  int check = -1057069466;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2115) {
  my_decimal decimal = {{0xD93B637A, 0x9A51C9AC, 0x5A5, 0x160000}};
  int check = 1076538026;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2116) {
  my_decimal decimal = {{0xD93B637A, 0x9A51C9AC, 0x5A5, 0x80160000}};
  int check = -1070945622;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2117) {
  my_decimal decimal = {{0xDE79F94A, 0xBEA9C3EC, 0x5D86C, 0x180000}};
  int check = 1088561697;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2118) {
  my_decimal decimal = {{0xDE79F94A, 0xBEA9C3EC, 0x5D86C, 0x80180000}};
  int check = -1058921951;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2119) {
  my_decimal decimal = {{0xE285F059, 0x8F6E942A, 0x90, 0x150000}};
  int check = 1076538026;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2120) {
  my_decimal decimal = {{0xE285F059, 0x8F6E942A, 0x90, 0x80150000}};
  int check = -1070945622;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2121) {
  my_decimal decimal = {{0x7CA5CC21, 0x79776064, 0x95A4, 0x170000}};
  int check = 1088561697;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2122) {
  my_decimal decimal = {{0x7CA5CC21, 0x79776064, 0x95A4, 0x80170000}};
  int check = -1058921951;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2123) {
  my_decimal decimal = {{0xC852BDA, 0x5E476A1, 0x2A5A, 0x170000}};
  int check = 1073741825;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2124) {
  my_decimal decimal = {{0xC852BDA, 0x5E476A1, 0x2A5A, 0x80170000}};
  int check = -1073741823;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2125) {
  my_decimal decimal = {{0xF5DA64AA, 0x197ECCB5, 0x2BD730, 0x190000}};
  int check = 1084856731;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2126) {
  my_decimal decimal = {{0xF5DA64AA, 0x197ECCB5, 0x2BD730, 0x80190000}};
  int check = -1062626917;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2127) {
  my_decimal decimal = {{0xE7A6EAC9, 0x33CA0BDC, 0x43C, 0x160000}};
  int check = 1073741825;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2128) {
  my_decimal decimal = {{0xE7A6EAC9, 0x33CA0BDC, 0x43C, 0x80160000}};
  int check = -1073741823;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2129) {
  my_decimal decimal = {{0xCBC90A11, 0x9C2647AB, 0x46251, 0x180000}};
  int check = 1084856731;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2130) {
  my_decimal decimal = {{0xCBC90A11, 0x9C2647AB, 0x46251, 0x80180000}};
  int check = -1062626917;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2131) {
  my_decimal decimal = {{0x2, 0x0, 0x0, 0x0}};
  int check = 1073741824;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2132) {
  my_decimal decimal = {{0x2, 0x0, 0x0, 0x80000000}};
  int check = -1073741824;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2133) {
  my_decimal decimal = {{0x212, 0x0, 0x0, 0x20000}};
  int check = 1084856730;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2134) {
  my_decimal decimal = {{0x212, 0x0, 0x0, 0x80020000}};
  int check = -1062626918;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2135) {
  my_decimal decimal = {{0x5D3D6A13, 0x5656890, 0x2A5A, 0x170000}};
  int check = 1073741823;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2136) {
  my_decimal decimal = {{0x5D3D6A13, 0x5656890, 0x2A5A, 0x80170000}};
  int check = -1073741825;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2137) {
  my_decimal decimal = {{0x8492CDAB, 0x95F93D70, 0x2BD72F, 0x190000}};
  int check = 1084856729;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2138) {
  my_decimal decimal = {{0x8492CDAB, 0x95F93D70, 0x2BD72F, 0x80190000}};
  int check = -1062626919;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2139) {
  my_decimal decimal = {{0x18295ED, 0x84562BF6, 0x1FC3, 0x170000}};
  int check = 1069547521;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2140) {
  my_decimal decimal = {{0x18295ED, 0x84562BF6, 0x1FC3, 0x80170000}};
  int check = -1077936127;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2141) {
  my_decimal decimal = {{0x902D3255, 0xFD3381A7, 0x20E163, 0x190000}};
  int check = 1082025576;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2142) {
  my_decimal decimal = {{0x902D3255, 0xFD3381A7, 0x20E163, 0x80190000}};
  int check = -1065458072;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2143) {
  my_decimal decimal = {{0xF, 0x0, 0x0, 0x10000}};
  int check = 1069547520;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2144) {
  my_decimal decimal = {{0xF, 0x0, 0x0, 0x80010000}};
  int check = -1077936128;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2145) {
  my_decimal decimal = {{0xF87, 0x0, 0x0, 0x30000}};
  int check = 1082025574;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2146) {
  my_decimal decimal = {{0xF87, 0x0, 0x0, 0x80030000}};
  int check = -1065458074;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2147) {
  my_decimal decimal = {{0xE1FD6A13, 0x840177EA, 0x1FC3, 0x170000}};
  int check = 1069547519;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2148) {
  my_decimal decimal = {{0xE1FD6A13, 0x840177EA, 0x1FC3, 0x80170000}};
  int check = -1077936129;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2149) {
  my_decimal decimal = {{0xEF52CDAB, 0xA5852223, 0x20E163, 0x190000}};
  int check = 1082025573;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2150) {
  my_decimal decimal = {{0xEF52CDAB, 0xA5852223, 0x20E163, 0x80190000}};
  int check = -1065458075;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2151) {
  my_decimal decimal = {{0x1, 0x0, 0x0, 0x0}};
  int check = 1065353216;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2152) {
  my_decimal decimal = {{0x1, 0x0, 0x0, 0x80000000}};
  int check = -1082130432;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2153) {
  my_decimal decimal = {{0x109, 0x0, 0x0, 0x20000}};
  int check = 1076468122;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2154) {
  my_decimal decimal = {{0x109, 0x0, 0x0, 0x80020000}};
  int check = -1071015526;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2155) {
  my_decimal decimal = {{0x3D09, 0x0, 0x0, 0x50000}};
  int check = 1042284544;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2156) {
  my_decimal decimal = {{0x3D09, 0x0, 0x0, 0x80050000}};
  int check = -1105199104;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2157) {
  my_decimal decimal = {{0x3F2E51, 0x0, 0x0, 0x70000}};
  int check = 1054081024;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2158) {
  my_decimal decimal = {{0x3F2E51, 0x0, 0x0, 0x80070000}};
  int check = -1093402624;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2159) {
  my_decimal decimal = {{0xD233125F, 0x1AFB0AD1, 0xD3C2, 0x180000}};
  int check = 1065353215;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2160) {
  my_decimal decimal = {{0xD233125F, 0x1AFB0AD1, 0xD3C2, 0x80180000}};
  int check = -1082130433;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2161) {
  my_decimal decimal = {{0x96DE0457, 0xEDDE3332, 0xDB33ED, 0x1A0000}};
  int check = 1076468121;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2162) {
  my_decimal decimal = {{0x96DE0457, 0xEDDE3332, 0xDB33ED, 0x801A0000}};
  int check = -1071015527;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2163) {
  my_decimal decimal = {{0x86FCCB47, 0xA2840E7D, 0x14ADF4, 0x1A0000}};
  int check = 1048575999;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2164) {
  my_decimal decimal = {{0x86FCCB47, 0xA2840E7D, 0x14ADF4, 0x801A0000}};
  int check = -1098907649;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2165) {
  my_decimal decimal = {{0xBBAE6C7F, 0x3AB2FFF0, 0x1568123C, 0x1C0000}};
  int check = 1059690905;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2166) {
  my_decimal decimal = {{0xBBAE6C7F, 0x3AB2FFF0, 0x1568123C, 0x801C0000}};
  int check = -1087792743;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2167) {
  my_decimal decimal = {{0x8BABF67C, 0xF7B95A90, 0x813F38, 0x1C0000}};
  int check = 1015021567;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2168) {
  my_decimal decimal = {{0x8BABF67C, 0xF7B95A90, 0x813F38, 0x801C0000}};
  int check = -1132462081;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2169) {
  my_decimal decimal = {{0xBBAE6C9, 0xC3AB2FFF, 0x1568123, 0x1C0000}};
  int check = 1026136473;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2170) {
  my_decimal decimal = {{0xBBAE6C9, 0xC3AB2FFF, 0x1568123, 0x801C0000}};
  int check = -1121347175;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2171) {
  my_decimal decimal = {{0x908BABF6, 0x38F7B95A, 0x813F, 0x1C0000}};
  int check = 947912703;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2172) {
  my_decimal decimal = {{0x908BABF6, 0x38F7B95A, 0x813F, 0x801C0000}};
  int check = -1199570945;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2173) {
  my_decimal decimal = {{0xFF0BBAE6, 0x23C3AB2F, 0x15681, 0x1C0000}};
  int check = 959027609;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2174) {
  my_decimal decimal = {{0xFF0BBAE6, 0x23C3AB2F, 0x15681, 0x801C0000}};
  int check = -1188456039;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2175) {
  my_decimal decimal = {{0xE745DFF, 0xB8E59289, 0xCEC, 0x1B0000}};
  int check = 947912703;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2176) {
  my_decimal decimal = {{0xE745DFF, 0xB8E59289, 0xCEC, 0x801B0000}};
  int check = -1199570945;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2177) {
  my_decimal decimal = {{0xFF0BBAE6, 0x23C3AB2F, 0x15681, 0x1C0000}};
  int check = 959027609;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2178) {
  my_decimal decimal = {{0xFF0BBAE6, 0x23C3AB2F, 0x15681, 0x801C0000}};
  int check = -1188456039;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2179) {
  my_decimal decimal = {{0xB95A908C, 0x813F38F7, 0x0, 0x1C0000}};
  int check = 813694975;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2180) {
  my_decimal decimal = {{0xB95A908C, 0x813F38F7, 0x0, 0x801C0000}};
  int check = -1333788673;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2181) {
  my_decimal decimal = {{0xAB2FFF0D, 0x568123C3, 0x1, 0x1C0000}};
  int check = 824809881;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2182) {
  my_decimal decimal = {{0xAB2FFF0D, 0x568123C3, 0x1, 0x801C0000}};
  int check = -1322673767;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2183) {
  my_decimal decimal = {{0x813F38F8, 0x0, 0x0, 0x1C0000}};
  int check = 545259519;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2184) {
  my_decimal decimal = {{0x813F38F8, 0x0, 0x0, 0x801C0000}};
  int check = -1602224129;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2185) {
  my_decimal decimal = {{0x568123C4, 0x1, 0x0, 0x1C0000}};
  int check = 556374425;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2186) {
  my_decimal decimal = {{0x568123C4, 0x1, 0x0, 0x801C0000}};
  int check = -1591109223;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2187) {
  my_decimal decimal = {{0x409F9C7C, 0x0, 0x0, 0x1C0000}};
  int check = 536870911;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2188) {
  my_decimal decimal = {{0x409F9C7C, 0x0, 0x0, 0x801C0000}};
  int check = -1610612737;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2189) {
  my_decimal decimal = {{0xAB4091E2, 0x0, 0x0, 0x1C0000}};
  int check = 547985817;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2190) {
  my_decimal decimal = {{0xAB4091E2, 0x0, 0x0, 0x801C0000}};
  int check = -1599497831;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2191) {
  my_decimal decimal = {{0x204FCE3E, 0x0, 0x0, 0x1C0000}};
  int check = 528482303;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2192) {
  my_decimal decimal = {{0x204FCE3E, 0x0, 0x0, 0x801C0000}};
  int check = -1619001345;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2193) {
  my_decimal decimal = {{0x55A048F1, 0x0, 0x0, 0x1C0000}};
  int check = 539597209;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2194) {
  my_decimal decimal = {{0x55A048F1, 0x0, 0x0, 0x801C0000}};
  int check = -1607886439;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2195) {
  my_decimal decimal = {{0x813F38F, 0x0, 0x0, 0x1C0000}};
  int check = 511705087;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2196) {
  my_decimal decimal = {{0x813F38F, 0x0, 0x0, 0x801C0000}};
  int check = -1635778561;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2197) {
  my_decimal decimal = {{0x1568123B, 0x0, 0x0, 0x1C0000}};
  int check = 522819993;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2198) {
  my_decimal decimal = {{0x1568123B, 0x0, 0x0, 0x801C0000}};
  int check = -1624663655;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2199) {
  my_decimal decimal = {{0x813F39, 0x0, 0x0, 0x1C0000}};
  int check = 478150655;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2200) {
  my_decimal decimal = {{0x813F39, 0x0, 0x0, 0x801C0000}};
  int check = -1669332993;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2201) {
  my_decimal decimal = {{0x1568124, 0x0, 0x0, 0x1C0000}};
  int check = 489265561;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2202) {
  my_decimal decimal = {{0x1568124, 0x0, 0x0, 0x801C0000}};
  int check = -1658218087;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2203) {
  my_decimal decimal = {{0x813F, 0x0, 0x0, 0x1C0000}};
  int check = 411041678;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2204) {
  my_decimal decimal = {{0x813F, 0x0, 0x0, 0x801C0000}};
  int check = -1736441970;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2205) {
  my_decimal decimal = {{0x15681, 0x0, 0x0, 0x1C0000}};
  int check = 422156679;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2206) {
  my_decimal decimal = {{0x15681, 0x0, 0x0, 0x801C0000}};
  int check = -1725326969;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2207) {
  my_decimal decimal = {{0x1, 0x0, 0x0, 0x1C0000}};
  int check = 285050806;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2208) {
  my_decimal decimal = {{0x1, 0x0, 0x0, 0x801C0000}};
  int check = -1862432842;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2209) {
  my_decimal decimal = {{0x3, 0x0, 0x0, 0x1C0000}};
  int check = 297674184;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2210) {
  my_decimal decimal = {{0x3, 0x0, 0x0, 0x801C0000}};
  int check = -1849809464;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2211) {
  my_decimal decimal = {{0x4, 0x0, 0x0, 0x1C0000}};
  int check = 301828022;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2212) {
  my_decimal decimal = {{0x4, 0x0, 0x0, 0x801C0000}};
  int check = -1845655626;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2213) {
  my_decimal decimal = {{0xB, 0x0, 0x0, 0x1C0000}};
  int check = 313412941;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2214) {
  my_decimal decimal = {{0xB, 0x0, 0x0, 0x801C0000}};
  int check = -1834070707;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2215) {
  my_decimal decimal = {{0x41, 0x0, 0x0, 0x1C0000}};
  int check = 335593194;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2216) {
  my_decimal decimal = {{0x41, 0x0, 0x0, 0x801C0000}};
  int check = -1811890454;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2217) {
  my_decimal decimal = {{0xAC, 0x0, 0x0, 0x1C0000}};
  int check = 346707758;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2218) {
  my_decimal decimal = {{0xAC, 0x0, 0x0, 0x801C0000}};
  int check = -1800775890;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2219) {
  my_decimal decimal = {{0x40A0, 0x0, 0x0, 0x1C0000}};
  int check = 402653381;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2220) {
  my_decimal decimal = {{0x40A0, 0x0, 0x0, 0x801C0000}};
  int check = -1744830267;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2221) {
  my_decimal decimal = {{0xAB42, 0x0, 0x0, 0x1C0000}};
  int check = 413768452;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2222) {
  my_decimal decimal = {{0xAB42, 0x0, 0x0, 0x801C0000}};
  int check = -1733715196;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2223) {
  my_decimal decimal = {{0x6C9DB1BD, 0xCD28E4D6, 0x2D2, 0x160000}};
  int check = 1068149418;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2224) {
  my_decimal decimal = {{0x6C9DB1BD, 0xCD28E4D6, 0x2D2, 0x80160000}};
  int check = -1079334230;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2225) {
  my_decimal decimal = {{0x6F3CFCA5, 0x5F54E1F6, 0x2EC36, 0x180000}};
  int check = 1080173089;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2226) {
  my_decimal decimal = {{0x6F3CFCA5, 0x5F54E1F6, 0x2EC36, 0x80180000}};
  int check = -1067310559;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2227) {
  my_decimal decimal = {{0x1F1478B1, 0x1CC7830, 0xE1E, 0x170000}};
  int check = 1059760810;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2228) {
  my_decimal decimal = {{0x1F1478B1, 0x1CC7830, 0xE1E, 0x80170000}};
  int check = -1087722838;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2229) {
  my_decimal decimal = {{0x2C30EF39, 0xDCA869D0, 0xE9D0F, 0x190000}};
  int check = 1071784481;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2230) {
  my_decimal decimal = {{0x2C30EF39, 0xDCA869D0, 0xE9D0F, 0x80190000}};
  int check = -1075699167;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2231) {
  my_decimal decimal = {{0x8FFC949, 0x2CF7BCB3, 0x160EE, 0x190000}};
  int check = 1042983594;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2232) {
  my_decimal decimal = {{0x8FFC949, 0x2CF7BCB3, 0x160EE, 0x80190000}};
  int check = -1104500054;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2233) {
  my_decimal decimal = {{0x50C75C91, 0x8C725554, 0x16D568C, 0x1B0000}};
  int check = 1055007265;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2234) {
  my_decimal decimal = {{0x50C75C91, 0x8C725554, 0x16D568C, 0x801B0000}};
  int check = -1092476383;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2235) {
  my_decimal decimal = {{0xB272A452, 0xFA7B91B5, 0x562A25, 0x1C0000}};
  int check = 1009429162;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2236) {
  my_decimal decimal = {{0xB272A452, 0xFA7B91B5, 0x562A25, 0x801C0000}};
  int check = -1138054486;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2237) {
  my_decimal decimal = {{0xB27C99D9, 0xD7C77554, 0xE45617, 0x1C0000}};
  int check = 1021452833;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2238) {
  my_decimal decimal = {{0xB27C99D9, 0xD7C77554, 0xE45617, 0x801C0000}};
  int check = -1126030815;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2239) {
  my_decimal decimal = {{0xB5B272A4, 0x25FA7B91, 0x562A, 0x1C0000}};
  int check = 942320298;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2240) {
  my_decimal decimal = {{0xB5B272A4, 0x25FA7B91, 0x562A, 0x801C0000}};
  int check = -1205163350;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2241) {
  my_decimal decimal = {{0x54B27C99, 0x17D7C775, 0xE456, 0x1C0000}};
  int check = 954343969;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2242) {
  my_decimal decimal = {{0x54B27C99, 0x17D7C775, 0xE456, 0x801C0000}};
  int check = -1193139679;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2243) {
  my_decimal decimal = {{0x5EF83EAA, 0xD0990C5B, 0x89D, 0x1B0000}};
  int check = 942320298;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2244) {
  my_decimal decimal = {{0x5EF83EAA, 0xD0990C5B, 0x89D, 0x801B0000}};
  int check = -1205163350;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2245) {
  my_decimal decimal = {{0x54B27C99, 0x17D7C775, 0xE456, 0x1C0000}};
  int check = 954343969;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2246) {
  my_decimal decimal = {{0x54B27C99, 0x17D7C775, 0xE456, 0x801C0000}};
  int check = -1193139679;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2247) {
  my_decimal decimal = {{0x7B91B5B2, 0x562A25FA, 0x0, 0x1C0000}};
  int check = 808102570;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2248) {
  my_decimal decimal = {{0x7B91B5B2, 0x562A25FA, 0x0, 0x801C0000}};
  int check = -1339381078;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2249) {
  my_decimal decimal = {{0xC77554B1, 0xE45617D7, 0x0, 0x1C0000}};
  int check = 820126241;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2250) {
  my_decimal decimal = {{0xC77554B1, 0xE45617D7, 0x0, 0x801C0000}};
  int check = -1327357407;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2251) {
  my_decimal decimal = {{0x9EE46D6D, 0x158A897E, 0x0, 0x1C0000}};
  int check = 791325354;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2252) {
  my_decimal decimal = {{0x9EE46D6D, 0x158A897E, 0x0, 0x801C0000}};
  int check = -1356158294;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2253) {
  my_decimal decimal = {{0xF1DD552E, 0x391585F5, 0x0, 0x1C0000}};
  int check = 803349025;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2254) {
  my_decimal decimal = {{0xF1DD552E, 0x391585F5, 0x0, 0x801C0000}};
  int check = -1344134623;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2255) {
  my_decimal decimal = {{0xA7B91B5B, 0x562A25F, 0x0, 0x1C0000}};
  int check = 774548138;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2256) {
  my_decimal decimal = {{0xA7B91B5B, 0x562A25F, 0x0, 0x801C0000}};
  int check = -1372935510;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2257) {
  my_decimal decimal = {{0x7C77554B, 0xE45617D, 0x0, 0x1C0000}};
  int check = 786571809;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2258) {
  my_decimal decimal = {{0x7C77554B, 0xE45617D, 0x0, 0x801C0000}};
  int check = -1360911839;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2259) {
  my_decimal decimal = {{0xFA7B91B6, 0x562A25, 0x0, 0x1C0000}};
  int check = 740993706;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2260) {
  my_decimal decimal = {{0xFA7B91B6, 0x562A25, 0x0, 0x801C0000}};
  int check = -1406489942;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2261) {
  my_decimal decimal = {{0xD7C77556, 0xE45617, 0x0, 0x1C0000}};
  int check = 753017377;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2262) {
  my_decimal decimal = {{0xD7C77556, 0xE45617, 0x0, 0x801C0000}};
  int check = -1394466271;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2263) {
  my_decimal decimal = {{0x990C5B5F, 0x89DD0, 0x0, 0x1B0000}};
  int check = 740993706;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2264) {
  my_decimal decimal = {{0x990C5B5F, 0x89DD0, 0x0, 0x801B0000}};
  int check = -1406489942;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2265) {
  my_decimal decimal = {{0xD7C77556, 0xE45617, 0x0, 0x1C0000}};
  int check = 753017377;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2266) {
  my_decimal decimal = {{0xD7C77556, 0xE45617, 0x0, 0x801C0000}};
  int check = -1394466271;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2267) {
  my_decimal decimal = {{0x25FA7B92, 0x562A, 0x0, 0x1C0000}};
  int check = 673884842;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2268) {
  my_decimal decimal = {{0x25FA7B92, 0x562A, 0x0, 0x801C0000}};
  int check = -1473598806;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2269) {
  my_decimal decimal = {{0x17D7C776, 0xE456, 0x0, 0x1C0000}};
  int check = 685908513;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2270) {
  my_decimal decimal = {{0x17D7C776, 0xE456, 0x0, 0x801C0000}};
  int check = -1461575135;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2271) {
  my_decimal decimal = {{0x12FD3DC9, 0x2B15, 0x0, 0x1C0000}};
  int check = 665496234;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2272) {
  my_decimal decimal = {{0x12FD3DC9, 0x2B15, 0x0, 0x801C0000}};
  int check = -1481987414;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2273) {
  my_decimal decimal = {{0xBEBE3BB, 0x722B, 0x0, 0x1C0000}};
  int check = 677519905;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2274) {
  my_decimal decimal = {{0xBEBE3BB, 0x722B, 0x0, 0x801C0000}};
  int check = -1469963743;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2275) {
  my_decimal decimal = {{0x1512FD3E, 0x2B, 0x0, 0x1C0000}};
  int check = 598387370;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2276) {
  my_decimal decimal = {{0x1512FD3E, 0x2B, 0x0, 0x801C0000}};
  int check = -1549096278;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2277) {
  my_decimal decimal = {{0x2B0BEBE4, 0x72, 0x0, 0x1C0000}};
  int check = 610411041;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2278) {
  my_decimal decimal = {{0x2B0BEBE4, 0x72, 0x0, 0x801C0000}};
  int check = -1537072607;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2279) {
  my_decimal decimal = {{0xB1512FD4, 0x2, 0x0, 0x1C0000}};
  int check = 564832938;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2280) {
  my_decimal decimal = {{0xB1512FD4, 0x2, 0x0, 0x801C0000}};
  int check = -1582650710;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2281) {
  my_decimal decimal = {{0x22B0BEBF, 0x7, 0x0, 0x1C0000}};
  int check = 576856609;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2282) {
  my_decimal decimal = {{0x22B0BEBF, 0x7, 0x0, 0x801C0000}};
  int check = -1570627039;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2283) {
  my_decimal decimal = {{0x562A25FA, 0x0, 0x0, 0x1C0000}};
  int check = 539667114;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2284) {
  my_decimal decimal = {{0x562A25FA, 0x0, 0x0, 0x801C0000}};
  int check = -1607816534;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2285) {
  my_decimal decimal = {{0xE45617D6, 0x0, 0x0, 0x1C0000}};
  int check = 551690785;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2286) {
  my_decimal decimal = {{0xE45617D6, 0x0, 0x0, 0x801C0000}};
  int check = -1595792863;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2287) {
  my_decimal decimal = {{0x89DD099, 0x0, 0x0, 0x1B0000}};
  int check = 539667114;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2288) {
  my_decimal decimal = {{0x89DD099, 0x0, 0x0, 0x801B0000}};
  int check = -1607816534;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2289) {
  my_decimal decimal = {{0xE45617D6, 0x0, 0x0, 0x1C0000}};
  int check = 551690785;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2290) {
  my_decimal decimal = {{0xE45617D6, 0x0, 0x0, 0x801C0000}};
  int check = -1595792863;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2291) {
  my_decimal decimal = {{0x2B1512FD, 0x0, 0x0, 0x1C0000}};
  int check = 531278506;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2292) {
  my_decimal decimal = {{0x2B1512FD, 0x0, 0x0, 0x801C0000}};
  int check = -1616205142;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2293) {
  my_decimal decimal = {{0x722B0BEB, 0x0, 0x0, 0x1C0000}};
  int check = 543302177;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2294) {
  my_decimal decimal = {{0x722B0BEB, 0x0, 0x0, 0x801C0000}};
  int check = -1604181471;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2295) {
  my_decimal decimal = {{0x158A897F, 0x0, 0x0, 0x1C0000}};
  int check = 522889898;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2296) {
  my_decimal decimal = {{0x158A897F, 0x0, 0x0, 0x801C0000}};
  int check = -1624593750;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2297) {
  my_decimal decimal = {{0x391585F7, 0x0, 0x0, 0x1C0000}};
  int check = 534913569;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2298) {
  my_decimal decimal = {{0x391585F7, 0x0, 0x0, 0x801C0000}};
  int check = -1612570079;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2299) {
  my_decimal decimal = {{0x562A260, 0x0, 0x0, 0x1C0000}};
  int check = 506112682;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2300) {
  my_decimal decimal = {{0x562A260, 0x0, 0x0, 0x801C0000}};
  int check = -1641370966;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2301) {
  my_decimal decimal = {{0xE45617E, 0x0, 0x0, 0x1C0000}};
  int check = 518136353;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2302) {
  my_decimal decimal = {{0xE45617E, 0x0, 0x0, 0x801C0000}};
  int check = -1629347295;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2303) {
  my_decimal decimal = {{0x562A26, 0x0, 0x0, 0x1C0000}};
  int check = 472558250;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2304) {
  my_decimal decimal = {{0x562A26, 0x0, 0x0, 0x801C0000}};
  int check = -1674925398;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2305) {
  my_decimal decimal = {{0xE45618, 0x0, 0x0, 0x1C0000}};
  int check = 484581921;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2306) {
  my_decimal decimal = {{0xE45618, 0x0, 0x0, 0x801C0000}};
  int check = -1662901727;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2307) {
  my_decimal decimal = {{0x562A, 0x0, 0x0, 0x1C0000}};
  int check = 405449311;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2308) {
  my_decimal decimal = {{0x562A, 0x0, 0x0, 0x801C0000}};
  int check = -1742034337;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2309) {
  my_decimal decimal = {{0xE456, 0x0, 0x0, 0x1C0000}};
  int check = 417473034;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2310) {
  my_decimal decimal = {{0xE456, 0x0, 0x0, 0x801C0000}};
  int check = -1730010614;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2311) {
  my_decimal decimal = {{0x158B, 0x0, 0x0, 0x1C0000}};
  int check = 388673109;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2312) {
  my_decimal decimal = {{0x158B, 0x0, 0x0, 0x801C0000}};
  int check = -1758810539;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2313) {
  my_decimal decimal = {{0x3917, 0x0, 0x0, 0x1C0000}};
  int check = 400697339;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2314) {
  my_decimal decimal = {{0x3917, 0x0, 0x0, 0x801C0000}};
  int check = -1746786309;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2315) {
  my_decimal decimal = {{0xAC, 0x0, 0x0, 0x1C0000}};
  int check = 346707758;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2316) {
  my_decimal decimal = {{0xAC, 0x0, 0x0, 0x801C0000}};
  int check = -1800775890;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2317) {
  my_decimal decimal = {{0x1C8, 0x0, 0x0, 0x1C0000}};
  int check = 358730974;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2318) {
  my_decimal decimal = {{0x1C8, 0x0, 0x0, 0x801C0000}};
  int check = -1788752674;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2319) {
  my_decimal decimal = {{0x2B, 0x0, 0x0, 0x1C0000}};
  int check = 329930542;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2320) {
  my_decimal decimal = {{0x2B, 0x0, 0x0, 0x801C0000}};
  int check = -1817553106;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2321) {
  my_decimal decimal = {{0x72, 0x0, 0x0, 0x1C0000}};
  int check = 341953758;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2322) {
  my_decimal decimal = {{0x72, 0x0, 0x0, 0x801C0000}};
  int check = -1805529890;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2323) {
  my_decimal decimal = {{0x3, 0x0, 0x0, 0x1C0000}};
  int check = 297674184;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2324) {
  my_decimal decimal = {{0x3, 0x0, 0x0, 0x801C0000}};
  int check = -1849809464;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2325) {
  my_decimal decimal = {{0x8, 0x0, 0x0, 0x1C0000}};
  int check = 310216630;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2326) {
  my_decimal decimal = {{0x8, 0x0, 0x0, 0x801C0000}};
  int check = -1837267018;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2327) {
  my_decimal decimal = {{0x159478B1, 0x494597B, 0x234B, 0x170000}};
  int check = 1070945621;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2328) {
  my_decimal decimal = {{0x159478B1, 0x494597B, 0x234B, 0x80170000}};
  int check = -1076538027;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2329) {
  my_decimal decimal = {{0x56B0EF39, 0xBD90A069, 0x2488A7, 0x190000}};
  int check = 1083004245;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2330) {
  my_decimal decimal = {{0x56B0EF39, 0xBD90A069, 0x2488A7, 0x80190000}};
  int check = -1064479403;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2331) {
  my_decimal decimal = {{0x6BE65B75, 0x16E5BF67, 0xB077, 0x180000}};
  int check = 1062557013;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2332) {
  my_decimal decimal = {{0x6BE65B75, 0x16E5BF67, 0xB077, 0x80180000}};
  int check = -1084926635;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2333) {
  my_decimal decimal = {{0xB174AC1D, 0xB3D3220E, 0xB6AB46, 0x1A0000}};
  int check = 1074615637;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2334) {
  my_decimal decimal = {{0xB174AC1D, 0xB3D3220E, 0xB6AB46, 0x801A0000}};
  int check = -1072868011;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2335) {
  my_decimal decimal = {{0x897EEE6D, 0x3C6FB119, 0x113BA1, 0x1A0000}};
  int check = 1045779797;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2336) {
  my_decimal decimal = {{0x897EEE6D, 0x3C6FB119, 0x113BA1, 0x801A0000}};
  int check = -1101703851;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2337) {
  my_decimal decimal = {{0x5464CED5, 0x8F9E536F, 0x11D6B9E7, 0x1C0000}};
  int check = 1057838421;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2338) {
  my_decimal decimal = {{0x5464CED5, 0x8F9E536F, 0x11D6B9E7, 0x801C0000}};
  int check = -1089645227;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2339) {
  my_decimal decimal = {{0x9B595229, 0xB9BA12DF, 0x6BB4AF, 0x1C0000}};
  int check = 1012225365;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2340) {
  my_decimal decimal = {{0x9B595229, 0xB9BA12DF, 0x6BB4AF, 0x801C0000}};
  int check = -1135258283;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2341) {
  my_decimal decimal = {{0xF5464CED, 0x78F9E536, 0x11D6B9E, 0x1C0000}};
  int check = 1024283989;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2342) {
  my_decimal decimal = {{0xF5464CED, 0x78F9E536, 0x11D6B9E, 0x801C0000}};
  int check = -1123199659;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2343) {
  my_decimal decimal = {{0xDF9B5952, 0xAFB9BA12, 0x6BB4, 0x1C0000}};
  int check = 945116501;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2344) {
  my_decimal decimal = {{0xDF9B5952, 0xAFB9BA12, 0x6BB4, 0x801C0000}};
  int check = -1202367147;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2345) {
  my_decimal decimal = {{0x36F5464C, 0x9E78F9E5, 0x11D6B, 0x1C0000}};
  int check = 957175125;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2346) {
  my_decimal decimal = {{0x36F5464C, 0x9E78F9E5, 0x11D6B, 0x801C0000}};
  int check = -1190308523;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2347) {
  my_decimal decimal = {{0xAFF5EF55, 0x44C5C5CE, 0xAC5, 0x1B0000}};
  int check = 945116501;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2348) {
  my_decimal decimal = {{0xAFF5EF55, 0x44C5C5CE, 0xAC5, 0x801B0000}};
  int check = -1202367147;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2349) {
  my_decimal decimal = {{0x36F5464C, 0x9E78F9E5, 0x11D6B, 0x1C0000}};
  int check = 957175125;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2350) {
  my_decimal decimal = {{0x36F5464C, 0x9E78F9E5, 0x11D6B, 0x801C0000}};
  int check = -1190308523;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2351) {
  my_decimal decimal = {{0xBA12DF9B, 0x6BB4AFB9, 0x0, 0x1C0000}};
  int check = 810898773;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2352) {
  my_decimal decimal = {{0xBA12DF9B, 0x6BB4AFB9, 0x0, 0x801C0000}};
  int check = -1336584875;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2353) {
  my_decimal decimal = {{0xF9E536F4, 0x1D6B9E78, 0x1, 0x1C0000}};
  int check = 822957397;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2354) {
  my_decimal decimal = {{0xF9E536F4, 0x1D6B9E78, 0x1, 0x801C0000}};
  int check = -1324526251;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2355) {
  my_decimal decimal = {{0x6E84B7E7, 0x1AED2BEE, 0x0, 0x1C0000}};
  int check = 794121557;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2356) {
  my_decimal decimal = {{0x6E84B7E7, 0x1AED2BEE, 0x0, 0x801C0000}};
  int check = -1353362091;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2357) {
  my_decimal decimal = {{0x3E794DBE, 0x475AE79E, 0x0, 0x1C0000}};
  int check = 806180181;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2358) {
  my_decimal decimal = {{0x3E794DBE, 0x475AE79E, 0x0, 0x801C0000}};
  int check = -1341303467;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2359) {
  my_decimal decimal = {{0x9BA12DFA, 0x6BB4AFB, 0x0, 0x1C0000}};
  int check = 777344341;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2360) {
  my_decimal decimal = {{0x9BA12DFA, 0x6BB4AFB, 0x0, 0x801C0000}};
  int check = -1370139307;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2361) {
  my_decimal decimal = {{0x8F9E5370, 0x11D6B9E7, 0x0, 0x1C0000}};
  int check = 789402965;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2362) {
  my_decimal decimal = {{0x8F9E5370, 0x11D6B9E7, 0x0, 0x801C0000}};
  int check = -1358080683;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2363) {
  my_decimal decimal = {{0xB9BA12E0, 0x6BB4AF, 0x0, 0x1C0000}};
  int check = 743789909;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2364) {
  my_decimal decimal = {{0xB9BA12E0, 0x6BB4AF, 0x0, 0x801C0000}};
  int check = -1403693739;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2365) {
  my_decimal decimal = {{0x78F9E538, 0x11D6B9E, 0x0, 0x1C0000}};
  int check = 755848533;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2366) {
  my_decimal decimal = {{0x78F9E538, 0x11D6B9E, 0x0, 0x801C0000}};
  int check = -1391635115;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2367) {
  my_decimal decimal = {{0xC5C5CEB0, 0xAC544, 0x0, 0x1B0000}};
  int check = 743789909;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2368) {
  my_decimal decimal = {{0xC5C5CEB0, 0xAC544, 0x0, 0x801B0000}};
  int check = -1403693739;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2369) {
  my_decimal decimal = {{0x78F9E538, 0x11D6B9E, 0x0, 0x1C0000}};
  int check = 755848533;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2370) {
  my_decimal decimal = {{0x78F9E538, 0x11D6B9E, 0x0, 0x801C0000}};
  int check = -1391635115;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2371) {
  my_decimal decimal = {{0xAFB9BA13, 0x6BB4, 0x0, 0x1C0000}};
  int check = 676681045;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2372) {
  my_decimal decimal = {{0xAFB9BA13, 0x6BB4, 0x0, 0x801C0000}};
  int check = -1470802603;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2373) {
  my_decimal decimal = {{0x9E78F9E6, 0x11D6B, 0x0, 0x1C0000}};
  int check = 688739669;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2374) {
  my_decimal decimal = {{0x9E78F9E6, 0x11D6B, 0x0, 0x801C0000}};
  int check = -1458743979;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2375) {
  my_decimal decimal = {{0x57DCDD09, 0x35DA, 0x0, 0x1C0000}};
  int check = 668292437;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2376) {
  my_decimal decimal = {{0x57DCDD09, 0x35DA, 0x0, 0x801C0000}};
  int check = -1479191211;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2377) {
  my_decimal decimal = {{0xCF3C7CF1, 0x8EB5, 0x0, 0x1C0000}};
  int check = 680351061;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2378) {
  my_decimal decimal = {{0xCF3C7CF1, 0x8EB5, 0x0, 0x801C0000}};
  int check = -1467132587;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2379) {
  my_decimal decimal = {{0x4AFB9BA1, 0x6BB, 0x0, 0x1C0000}};
  int check = 643126613;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2380) {
  my_decimal decimal = {{0x4AFB9BA1, 0x6BB, 0x0, 0x801C0000}};
  int check = -1504357035;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2381) {
  my_decimal decimal = {{0xB9E78F9E, 0x11D6, 0x0, 0x1C0000}};
  int check = 655185237;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2382) {
  my_decimal decimal = {{0xB9E78F9E, 0x11D6, 0x0, 0x801C0000}};
  int check = -1492298411;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2383) {
  my_decimal decimal = {{0xDA57DCDD, 0x35, 0x0, 0x1C0000}};
  int check = 601183573;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2384) {
  my_decimal decimal = {{0xDA57DCDD, 0x35, 0x0, 0x801C0000}};
  int check = -1546300075;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2385) {
  my_decimal decimal = {{0xB5CF3C7D, 0x8E, 0x0, 0x1C0000}};
  int check = 613242197;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2386) {
  my_decimal decimal = {{0xB5CF3C7D, 0x8E, 0x0, 0x801C0000}};
  int check = -1534241451;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2387) {
  my_decimal decimal = {{0x5DA57DCE, 0x3, 0x0, 0x1C0000}};
  int check = 567629141;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2388) {
  my_decimal decimal = {{0x5DA57DCE, 0x3, 0x0, 0x801C0000}};
  int check = -1579854507;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2389) {
  my_decimal decimal = {{0xEB5CF3C8, 0x8, 0x0, 0x1C0000}};
  int check = 579687765;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2390) {
  my_decimal decimal = {{0xEB5CF3C8, 0x8, 0x0, 0x801C0000}};
  int check = -1567795883;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2391) {
  my_decimal decimal = {{0xD7695F73, 0x0, 0x0, 0x1C0000}};
  int check = 550851925;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2392) {
  my_decimal decimal = {{0xD7695F73, 0x0, 0x0, 0x801C0000}};
  int check = -1596631723;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2393) {
  my_decimal decimal = {{0x3AD73CF1, 0x2, 0x0, 0x1C0000}};
  int check = 562910549;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2394) {
  my_decimal decimal = {{0x3AD73CF1, 0x2, 0x0, 0x801C0000}};
  int check = -1584573099;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2395) {
  my_decimal decimal = {{0x6BB4AFBA, 0x0, 0x0, 0x1C0000}};
  int check = 542463317;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2396) {
  my_decimal decimal = {{0x6BB4AFBA, 0x0, 0x0, 0x801C0000}};
  int check = -1605020331;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2397) {
  my_decimal decimal = {{0x1D6B9E7A, 0x1, 0x0, 0x1C0000}};
  int check = 554521941;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2398) {
  my_decimal decimal = {{0x1D6B9E7A, 0x1, 0x0, 0x801C0000}};
  int check = -1592961707;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2399) {
  my_decimal decimal = {{0x35DA57DD, 0x0, 0x0, 0x1C0000}};
  int check = 534074709;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2400) {
  my_decimal decimal = {{0x35DA57DD, 0x0, 0x0, 0x801C0000}};
  int check = -1613408939;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2401) {
  my_decimal decimal = {{0x8EB5CF3D, 0x0, 0x0, 0x1C0000}};
  int check = 546133333;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2402) {
  my_decimal decimal = {{0x8EB5CF3D, 0x0, 0x0, 0x801C0000}};
  int check = -1601350315;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2403) {
  my_decimal decimal = {{0x1AED2BEE, 0x0, 0x0, 0x1C0000}};
  int check = 525686101;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2404) {
  my_decimal decimal = {{0x1AED2BEE, 0x0, 0x0, 0x801C0000}};
  int check = -1621797547;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2405) {
  my_decimal decimal = {{0x475AE79D, 0x0, 0x0, 0x1C0000}};
  int check = 537744725;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2406) {
  my_decimal decimal = {{0x475AE79D, 0x0, 0x0, 0x801C0000}};
  int check = -1609738923;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2407) {
  my_decimal decimal = {{0x6BB4AFC, 0x0, 0x0, 0x1C0000}};
  int check = 508908885;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2408) {
  my_decimal decimal = {{0x6BB4AFC, 0x0, 0x0, 0x801C0000}};
  int check = -1638574763;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2409) {
  my_decimal decimal = {{0x11D6B9E9, 0x0, 0x0, 0x1C0000}};
  int check = 520967509;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2410) {
  my_decimal decimal = {{0x11D6B9E9, 0x0, 0x0, 0x801C0000}};
  int check = -1626516139;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2411) {
  my_decimal decimal = {{0x6BB4B0, 0x0, 0x0, 0x1C0000}};
  int check = 475354454;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2412) {
  my_decimal decimal = {{0x6BB4B0, 0x0, 0x0, 0x801C0000}};
  int check = -1672129194;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2413) {
  my_decimal decimal = {{0x11D6B9F, 0x0, 0x0, 0x1C0000}};
  int check = 487413077;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2414) {
  my_decimal decimal = {{0x11D6B9F, 0x0, 0x0, 0x801C0000}};
  int check = -1660070571;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2415) {
  my_decimal decimal = {{0x6BB5, 0x0, 0x0, 0x1C0000}};
  int check = 408245748;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2416) {
  my_decimal decimal = {{0x6BB5, 0x0, 0x0, 0x801C0000}};
  int check = -1739237900;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2417) {
  my_decimal decimal = {{0x11D6C, 0x0, 0x0, 0x1C0000}};
  int check = 420304261;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2418) {
  my_decimal decimal = {{0x11D6C, 0x0, 0x0, 0x801C0000}};
  int check = -1727179387;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2419) {
  my_decimal decimal = {{0x35DA, 0x0, 0x0, 0x1C0000}};
  int check = 399856633;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2420) {
  my_decimal decimal = {{0x35DA, 0x0, 0x0, 0x801C0000}};
  int check = -1747627015;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2421) {
  my_decimal decimal = {{0x8EB5, 0x0, 0x0, 0x1C0000}};
  int check = 411915400;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2422) {
  my_decimal decimal = {{0x8EB5, 0x0, 0x0, 0x801C0000}};
  int check = -1735568248;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2423) {
  my_decimal decimal = {{0x1AED, 0x0, 0x0, 0x1C0000}};
  int check = 391468025;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2424) {
  my_decimal decimal = {{0x1AED, 0x0, 0x0, 0x801C0000}};
  int check = -1756015623;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2425) {
  my_decimal decimal = {{0x475A, 0x0, 0x0, 0x1C0000}};
  int check = 403526538;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2426) {
  my_decimal decimal = {{0x475A, 0x0, 0x0, 0x801C0000}};
  int check = -1743957110;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2427) {
  my_decimal decimal = {{0x6BB, 0x0, 0x0, 0x1C0000}};
  int check = 374688781;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2428) {
  my_decimal decimal = {{0x6BB, 0x0, 0x0, 0x801C0000}};
  int check = -1772794867;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2429) {
  my_decimal decimal = {{0x11D6, 0x0, 0x0, 0x1C0000}};
  int check = 386748308;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2430) {
  my_decimal decimal = {{0x11D6, 0x0, 0x0, 0x801C0000}};
  int check = -1760735340;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2431) {
  my_decimal decimal = {{0x36, 0x0, 0x0, 0x1C0000}};
  int check = 332786306;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2432) {
  my_decimal decimal = {{0x36, 0x0, 0x0, 0x801C0000}};
  int check = -1814697342;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2433) {
  my_decimal decimal = {{0x8F, 0x0, 0x0, 0x1C0000}};
  int check = 344825551;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2434) {
  my_decimal decimal = {{0x8F, 0x0, 0x0, 0x801C0000}};
  int check = -1802658097;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2435) {
  my_decimal decimal = {{0x4B, 0x0, 0x0, 0x20000}};
  int check = 1061158912;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2436) {
  my_decimal decimal = {{0x4B, 0x0, 0x0, 0x80020000}};
  int check = -1086324736;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2437) {
  my_decimal decimal = {{0x4DA3, 0x0, 0x0, 0x40000}};
  int check = 1073636966;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2438) {
  my_decimal decimal = {{0x4DA3, 0x0, 0x0, 0x80040000}};
  int check = -1073846682;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2439) {
  my_decimal decimal = {{0x5, 0x0, 0x0, 0x10000}};
  int check = 1056964608;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2440) {
  my_decimal decimal = {{0x5, 0x0, 0x0, 0x80010000}};
  int check = -1090519040;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2441) {
  my_decimal decimal = {{0x52D, 0x0, 0x0, 0x30000}};
  int check = 1068079514;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2442) {
  my_decimal decimal = {{0x52D, 0x0, 0x0, 0x80030000}};
  int check = -1079404134;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2443) {
  my_decimal decimal = {{0x753, 0x0, 0x0, 0x40000}};
  int check = 1044381696;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2444) {
  my_decimal decimal = {{0x753, 0x0, 0x0, 0x80040000}};
  int check = -1103101952;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2445) {
  my_decimal decimal = {{0x794EB, 0x0, 0x0, 0x60000}};
  int check = 1056859750;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2446) {
  my_decimal decimal = {{0x794EB, 0x0, 0x0, 0x80060000}};
  int check = -1090623898;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2447) {
  my_decimal decimal = {{0x7D, 0x0, 0x0, 0x30000}};
  int check = 1040187392;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2448) {
  my_decimal decimal = {{0x7D, 0x0, 0x0, 0x80030000}};
  int check = -1107296256;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2449) {
  my_decimal decimal = {{0x8165, 0x0, 0x0, 0x50000}};
  int check = 1051302298;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2450) {
  my_decimal decimal = {{0x8165, 0x0, 0x0, 0x80050000}};
  int check = -1096181350;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2451) {
  my_decimal decimal = {{0x271, 0x0, 0x0, 0x40000}};
  int check = 1031798784;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2452) {
  my_decimal decimal = {{0x271, 0x0, 0x0, 0x80040000}};
  int check = -1115684864;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2453) {
  my_decimal decimal = {{0x286F9, 0x0, 0x0, 0x60000}};
  int check = 1042913690;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2454) {
  my_decimal decimal = {{0x286F9, 0x0, 0x0, 0x80060000}};
  int check = -1104569958;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2455) {
  my_decimal decimal = {{0x3D09, 0x0, 0x0, 0x60000}};
  int check = 1015021568;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2456) {
  my_decimal decimal = {{0x3D09, 0x0, 0x0, 0x80060000}};
  int check = -1132462080;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2457) {
  my_decimal decimal = {{0x3F2E51, 0x0, 0x0, 0x80000}};
  int check = 1026136474;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2458) {
  my_decimal decimal = {{0x3F2E51, 0x0, 0x0, 0x80080000}};
  int check = -1121347174;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2459) {
  my_decimal decimal = {{0x11E1A3, 0x0, 0x0, 0x80000}};
  int check = 1010827264;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2460) {
  my_decimal decimal = {{0x11E1A3, 0x0, 0x0, 0x80080000}};
  int check = -1136656384;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2461) {
  my_decimal decimal = {{0x128291BB, 0x0, 0x0, 0xA0000}};
  int check = 1023305318;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2462) {
  my_decimal decimal = {{0x128291BB, 0x0, 0x0, 0x800A0000}};
  int check = -1124178330;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2463) {
  my_decimal decimal = {{0x1312D, 0x0, 0x0, 0x70000}};
  int check = 1006632960;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2464) {
  my_decimal decimal = {{0x1312D, 0x0, 0x0, 0x80070000}};
  int check = -1140850688;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2465) {
  my_decimal decimal = {{0x13BE795, 0x0, 0x0, 0x90000}};
  int check = 1017747866;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2466) {
  my_decimal decimal = {{0x13BE795, 0x0, 0x0, 0x80090000}};
  int check = -1129735782;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2467) {
  my_decimal decimal = {{0x5F5E1, 0x0, 0x0, 0x80000}};
  int check = 998244352;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2468) {
  my_decimal decimal = {{0x5F5E1, 0x0, 0x0, 0x80080000}};
  int check = -1149239296;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2469) {
  my_decimal decimal = {{0x62B85E9, 0x0, 0x0, 0xA0000}};
  int check = 1009359258;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2470) {
  my_decimal decimal = {{0x62B85E9, 0x0, 0x0, 0x800A0000}};
  int check = -1138124390;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2471) {
  my_decimal decimal = {{0xE8D4A51, 0x0, 0x0, 0xC0000}};
  int check = 964689920;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2472) {
  my_decimal decimal = {{0xE8D4A51, 0x0, 0x0, 0x800C0000}};
  int check = -1182793728;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2473) {
  my_decimal decimal = {{0x1041EDD9, 0xF, 0x0, 0xE0000}};
  int check = 975804826;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2474) {
  my_decimal decimal = {{0x1041EDD9, 0xF, 0x0, 0x800E0000}};
  int check = -1171678822;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2475) {
  my_decimal decimal = {{0x94D74F43, 0x6A, 0x0, 0x100000}};
  int check = 943718400;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2476) {
  my_decimal decimal = {{0x94D74F43, 0x6A, 0x0, 0x80100000}};
  int check = -1203765248;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2477) {
  my_decimal decimal = {{0x12E10C5B, 0x6E54, 0x0, 0x120000}};
  int check = 956196454;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2478) {
  my_decimal decimal = {{0x12E10C5B, 0x6E54, 0x0, 0x80120000}};
  int check = -1191287194;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2479) {
  my_decimal decimal = {{0x1AFD498D, 0x7, 0x0, 0xF0000}};
  int check = 939524096;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2480) {
  my_decimal decimal = {{0x1AFD498D, 0x7, 0x0, 0x800F0000}};
  int check = -1207959552;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2481) {
  my_decimal decimal = {{0xF03122F5, 0x75A, 0x0, 0x110000}};
  int check = 950639002;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2482) {
  my_decimal decimal = {{0xF03122F5, 0x75A, 0x0, 0x80110000}};
  int check = -1196844646;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2483) {
  my_decimal decimal = {{0x86F26FC1, 0x23, 0x0, 0x100000}};
  int check = 931135488;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2484) {
  my_decimal decimal = {{0x86F26FC1, 0x23, 0x0, 0x80100000}};
  int check = -1216348160;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2485) {
  my_decimal decimal = {{0xB0F5AEC9, 0x24C6, 0x0, 0x120000}};
  int check = 942250394;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2486) {
  my_decimal decimal = {{0xB0F5AEC9, 0x24C6, 0x0, 0x80120000}};
  int check = -1205233254;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2487) {
  my_decimal decimal = {{0x7C4A04C2, 0x409F9CBC, 0x0, 0x1C0000}};
  int check = 805306368;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2488) {
  my_decimal decimal = {{0x7C4A04C2, 0x409F9CBC, 0x0, 0x801C0000}};
  int check = -1342177280;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2489) {
  my_decimal decimal = {{0x162A8C9C, 0xAB40928D, 0x0, 0x1C0000}};
  int check = 816421274;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2490) {
  my_decimal decimal = {{0x162A8C9C, 0xAB40928D, 0x0, 0x801C0000}};
  int check = -1331062374;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2491) {
  my_decimal decimal = {{0xBA6F0723, 0x60EF6B1A, 0x0, 0x1C0000}};
  int check = 809500672;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2492) {
  my_decimal decimal = {{0xBA6F0723, 0x60EF6B1A, 0x0, 0x801C0000}};
  int check = -1337982976;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2493) {
  my_decimal decimal = {{0xA13FD2EA, 0xE0DBD3, 0x1, 0x1C0000}};
  int check = 821978726;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2494) {
  my_decimal decimal = {{0xA13FD2EA, 0xE0DBD3, 0x1, 0x801C0000}};
  int check = -1325504922;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2495) {
  my_decimal decimal = {{0x409F9CBC, 0x0, 0x0, 0x1C0000}};
  int check = 536870912;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2496) {
  my_decimal decimal = {{0x409F9CBC, 0x0, 0x0, 0x801C0000}};
  int check = -1610612736;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2497) {
  my_decimal decimal = {{0xAB40928C, 0x0, 0x0, 0x1C0000}};
  int check = 547985818;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2498) {
  my_decimal decimal = {{0xAB40928C, 0x0, 0x0, 0x801C0000}};
  int check = -1599497830;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2499) {
  my_decimal decimal = {{0x160334B9, 0xF176018A, 0x52B7D2, 0x1B0000}};
  int check = 1036831949;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2500) {
  my_decimal decimal = {{0x160334B9, 0xF176018A, 0x52B7D2, 0x801B0000}};
  int check = -1110651699;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2501) {
  my_decimal decimal = {{0x4754F526, 0xFEB728CB, 0x8900755, 0x1C0000}};
  int check = 1049079317;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2502) {
  my_decimal decimal = {{0x4754F526, 0xFEB728CB, 0x8900755, 0x801C0000}};
  int check = -1098404331;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2503) {
  my_decimal decimal = {{0xECFEF3D7, 0xE632DC89, 0xD38B, 0x180000}};
  int check = 1065336439;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2504) {
  my_decimal decimal = {{0xECFEF3D7, 0xE632DC89, 0xD38B, 0x80180000}};
  int check = -1082147209;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2505) {
  my_decimal decimal = {{0x53EA698F, 0x4AA64AC6, 0xDAFBD1, 0x1A0000}};
  int check = 1076457007;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2506) {
  my_decimal decimal = {{0x53EA698F, 0x4AA64AC6, 0xDAFBD1, 0x801A0000}};
  int check = -1071026641;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2507) {
  my_decimal decimal = {{0xC1191537, 0xE8DE9F28, 0x130E, 0x170000}};
  int check = 1063675494;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2508) {
  my_decimal decimal = {{0xC1191537, 0xE8DE9F28, 0x130E, 0x80170000}};
  int check = -1083808154;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2509) {
  my_decimal decimal = {{0xE2F6F5EF, 0xE72C12F, 0x13BA6F, 0x190000}};
  int check = 1075356631;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2510) {
  my_decimal decimal = {{0xE2F6F5EF, 0xE72C12F, 0x13BA6F, 0x80190000}};
  int check = -1072127017;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2511) {
  my_decimal decimal = {{0x61940B43, 0xD7303129, 0x52A2A5, 0x1B0000}};
  int check = 1036818527;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2512) {
  my_decimal decimal = {{0x61940B43, 0xD7303129, 0x52A2A5, 0x801B0000}};
  int check = -1110665121;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2513) {
  my_decimal decimal = {{0x99D32A70, 0xC67D16C8, 0x88DD62A, 0x1C0000}};
  int check = 1049070425;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2514) {
  my_decimal decimal = {{0x99D32A70, 0xC67D16C8, 0x88DD62A, 0x801C0000}};
  int check = -1098413223;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2515) {
  my_decimal decimal = {{0x60180D2A, 0xF109A30E, 0x52A2A5, 0x1C0000}};
  int check = 1008971033;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2516) {
  my_decimal decimal = {{0x60180D2A, 0xF109A30E, 0x52A2A5, 0x801C0000}};
  int check = -1138512615;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2517) {
  my_decimal decimal = {{0xE50C8949, 0x585989B2, 0xDAFBD1, 0x1C0000}};
  int check = 1020845812;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2518) {
  my_decimal decimal = {{0xE50C8949, 0x585989B2, 0xDAFBD1, 0x801C0000}};
  int check = -1126637836;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2519) {
  my_decimal decimal = {{0x43061B28, 0x1BC24F1, 0x84377, 0x1C0000}};
  int check = 981659873;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2520) {
  my_decimal decimal = {{0x43061B28, 0x1BC24F1, 0x84377, 0x801C0000}};
  int check = -1165823775;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2521) {
  my_decimal decimal = {{0xF19CFB2A, 0x5E329518, 0x15E5FB, 0x1C0000}};
  int check = 992837418;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2522) {
  my_decimal decimal = {{0xF19CFB2A, 0x5E329518, 0x15E5FB, 0x801C0000}};
  int check = -1154646230;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2523) {
  my_decimal decimal = {{0x86B3CF84, 0xE692D07E, 0xD38B, 0x1B0000}};
  int check = 981659873;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2524) {
  my_decimal decimal = {{0x86B3CF84, 0xE692D07E, 0xD38B, 0x801B0000}};
  int check = -1165823775;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2525) {
  my_decimal decimal = {{0xF19CFB2A, 0x5E329518, 0x15E5FB, 0x1C0000}};
  int check = 992837418;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2526) {
  my_decimal decimal = {{0xF19CFB2A, 0x5E329518, 0x15E5FB, 0x801C0000}};
  int check = -1154646230;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2527) {
  my_decimal decimal = {{0x94C2A771, 0xE590520B, 0xD38B, 0x1C0000}};
  int check = 953254247;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2528) {
  my_decimal decimal = {{0x94C2A771, 0xE590520B, 0xD38B, 0x801C0000}};
  int check = -1194229401;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2529) {
  my_decimal decimal = {{0xB09D6EEB, 0x20580C9E, 0x23099, 0x1C0000}};
  int check = 965397537;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2530) {
  my_decimal decimal = {{0xB09D6EEB, 0x20580C9E, 0x23099, 0x801C0000}};
  int check = -1182086111;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2531) {
  my_decimal decimal = {{0xA1B97E8C, 0x96FB4B5D, 0x1527, 0x1C0000}};
  int check = 925342393;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2532) {
  my_decimal decimal = {{0xA1B97E8C, 0x96FB4B5D, 0x1527, 0x801C0000}};
  int check = -1222141255;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2533) {
  my_decimal decimal = {{0x862B8F59, 0x5019EE1E, 0x380F, 0x1C0000}};
  int check = 937300840;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2534) {
  my_decimal decimal = {{0x862B8F59, 0x5019EE1E, 0x380F, 0x801C0000}};
  int check = -1210182808;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2535) {
  my_decimal decimal = {{0x85BA80C8, 0x8F19EFEE, 0x21D, 0x1C0000}};
  int check = 897979745;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2536) {
  my_decimal decimal = {{0x85BA80C8, 0x8F19EFEE, 0x21D, 0x801C0000}};
  int check = -1249503903;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2537) {
  my_decimal decimal = {{0x48C7D545, 0x219E556B, 0x59B, 0x1C0000}};
  int check = 909224225;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2538) {
  my_decimal decimal = {{0x48C7D545, 0x219E556B, 0x59B, 0x801C0000}};
  int check = -1238259423;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2539) {
  my_decimal decimal = {{0xEE068D9F, 0x27E8F177, 0x36, 0x1C0000}};
  int check = 869697691;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2540) {
  my_decimal decimal = {{0xEE068D9F, 0x27E8F177, 0x36, 0x801C0000}};
  int check = -1277785957;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2541) {
  my_decimal decimal = {{0x36C490E5, 0x835C7FE4, 0x8F, 0x1C0000}};
  int check = 881729767;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2542) {
  my_decimal decimal = {{0x36C490E5, 0x835C7FE4, 0x8F, 0x801C0000}};
  int check = -1265753881;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2543) {
  my_decimal decimal = {{0x97CD7490, 0x6A641825, 0x5, 0x1C0000}};
  int check = 841719932;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2544) {
  my_decimal decimal = {{0x97CD7490, 0x6A641825, 0x5, 0x801C0000}};
  int check = -1305763716;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2545) {
  my_decimal decimal = {{0x9F13A817, 0x59EFA663, 0xE, 0x1C0000}};
  int check = 853764056;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2546) {
  my_decimal decimal = {{0x9F13A817, 0x59EFA663, 0xE, 0x801C0000}};
  int check = -1293719592;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2547) {
  my_decimal decimal = {{0xC2615875, 0x8AA39C03, 0x0, 0x1C0000}};
  int check = 814304560;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2548) {
  my_decimal decimal = {{0xC2615875, 0x8AA39C03, 0x0, 0x801C0000}};
  int check = -1333179088;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2549) {
  my_decimal decimal = {{0xC31B90D0, 0x6F64C3D6, 0x1, 0x1C0000}};
  int check = 825617580;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2550) {
  my_decimal decimal = {{0xC31B90D0, 0x6F64C3D6, 0x1, 0x801C0000}};
  int check = -1321866068;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2551) {
  my_decimal decimal = {{0x5841E5D2, 0xDDD2930, 0x0, 0x1C0000}};
  int check = 786149043;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2552) {
  my_decimal decimal = {{0x5841E5D2, 0xDDD2930, 0x0, 0x801C0000}};
  int check = -1361334605;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2553) {
  my_decimal decimal = {{0x1D15076C, 0x24BD46C0, 0x0, 0x1C0000}};
  int check = 798067235;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2554) {
  my_decimal decimal = {{0x1D15076C, 0x24BD46C0, 0x0, 0x801C0000}};
  int check = -1349416413;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2555) {
  my_decimal decimal = {{0xD5A03095, 0x162EA84, 0x0, 0x1B0000}};
  int check = 786149043;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2556) {
  my_decimal decimal = {{0xD5A03095, 0x162EA84, 0x0, 0x801B0000}};
  int check = -1361334605;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2557) {
  my_decimal decimal = {{0x1D15076C, 0x24BD46C0, 0x0, 0x1C0000}};
  int check = 798067235;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2558) {
  my_decimal decimal = {{0x1D15076C, 0x24BD46C0, 0x0, 0x801C0000}};
  int check = -1349416413;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2559) {
  my_decimal decimal = {{0xA46BBFBD, 0x162EA85, 0x0, 0x1C0000}};
  int check = 758103798;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2560) {
  my_decimal decimal = {{0xA46BBFBD, 0x162EA85, 0x0, 0x801C0000}};
  int check = -1389379850;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2561) {
  my_decimal decimal = {{0x5A1D88E8, 0x3AC8715, 0x0, 0x1C0000}};
  int check = 770235654;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2562) {
  my_decimal decimal = {{0x5A1D88E8, 0x3AC8715, 0x0, 0x801C0000}};
  int check = -1377247994;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2563) {
  my_decimal decimal = {{0x36F77F52, 0x237DDA, 0x0, 0x1C0000}};
  int check = 730634437;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2564) {
  my_decimal decimal = {{0x36F77F52, 0x237DDA, 0x0, 0x801C0000}};
  int check = -1416849211;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2565) {
  my_decimal decimal = {{0x44DCAB00, 0x5E0D82, 0x0, 0x1C0000}};
  int check = 742017643;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2566) {
  my_decimal decimal = {{0x44DCAB00, 0x5E0D82, 0x0, 0x801C0000}};
  int check = -1405466005;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2567) {
  my_decimal decimal = {{0xD0AE5C04, 0x38C95, 0x0, 0x1C0000}};
  int check = 702608494;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2568) {
  my_decimal decimal = {{0xD0AE5C04, 0x38C95, 0x0, 0x801C0000}};
  int check = -1444875154;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2569) {
  my_decimal decimal = {{0x35CE0D71, 0x967C0, 0x0, 0x1C0000}};
  int check = 714410070;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2570) {
  my_decimal decimal = {{0x35CE0D71, 0x967C0, 0x0, 0x801C0000}};
  int check = -1433073578;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2571) {
  my_decimal decimal = {{0xC8116F9A, 0x5ADB, 0x0, 0x1B0000}};
  int check = 702608494;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2572) {
  my_decimal decimal = {{0xC8116F9A, 0x5ADB, 0x0, 0x801B0000}};
  int check = -1444875154;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2573) {
  my_decimal decimal = {{0x35CE0D71, 0x967C0, 0x0, 0x1C0000}};
  int check = 714410070;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2574) {
  my_decimal decimal = {{0x35CE0D71, 0x967C0, 0x0, 0x801C0000}};
  int check = -1433073578;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2575) {
  my_decimal decimal = {{0x8290A94, 0x5340, 0x0, 0x1C0000}};
  int check = 673506516;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2576) {
  my_decimal decimal = {{0x8290A94, 0x5340, 0x0, 0x801C0000}};
  int check = -1473977132;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2577) {
  my_decimal decimal = {{0xE26CC26F, 0xDC9C, 0x0, 0x1C0000}};
  int check = 685407231;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2578) {
  my_decimal decimal = {{0xE26CC26F, 0xDC9C, 0x0, 0x801C0000}};
  int check = -1462076417;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2579) {
  my_decimal decimal = {{0x8EE06978, 0x10C, 0x0, 0x1C0000}};
  int check = 621083593;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2580) {
  my_decimal decimal = {{0x8EE06978, 0x10C, 0x0, 0x801C0000}};
  int check = -1526400055;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2581) {
  my_decimal decimal = {{0xADD2B118, 0x2C7, 0x0, 0x1C0000}};
  int check = 632304644;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2582) {
  my_decimal decimal = {{0xADD2B118, 0x2C7, 0x0, 0x801C0000}};
  int check = -1515179004;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2583) {
  my_decimal decimal = {{0xDB166406, 0x1A, 0x0, 0x1C0000}};
  int check = 592758286;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2584) {
  my_decimal decimal = {{0xDB166406, 0x1A, 0x0, 0x801C0000}};
  int check = -1554725362;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2585) {
  my_decimal decimal = {{0x2AFB55DD, 0x47, 0x0, 0x1C0000}};
  int check = 604829289;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2586) {
  my_decimal decimal = {{0x2AFB55DD, 0x47, 0x0, 0x801C0000}};
  int check = -1542654359;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2587) {
  my_decimal decimal = {{0xAF823C65, 0x2, 0x0, 0x1C0000}};
  int check = 564803595;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2588) {
  my_decimal decimal = {{0xAF823C65, 0x2, 0x0, 0x801C0000}};
  int check = -1582680053;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2589) {
  my_decimal decimal = {{0x1DE5ECD8, 0x7, 0x0, 0x1C0000}};
  int check = 576817730;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2590) {
  my_decimal decimal = {{0x1DE5ECD8, 0x7, 0x0, 0x801C0000}};
  int check = -1570665918;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2591) {
  my_decimal decimal = {{0x60EF6B1B, 0x0, 0x0, 0x1C0000}};
  int check = 541065216;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2592) {
  my_decimal decimal = {{0x60EF6B1B, 0x0, 0x0, 0x801C0000}};
  int check = -1606418432;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2593) {
  my_decimal decimal = {{0xE0DBD4, 0x1, 0x0, 0x1C0000}};
  int check = 553543270;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2594) {
  my_decimal decimal = {{0xE0DBD4, 0x1, 0x0, 0x801C0000}};
  int check = -1593940378;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2595) {
  my_decimal decimal = {{0x44C03971, 0x0, 0x0, 0x1C0000}};
  int check = 537406678;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2596) {
  my_decimal decimal = {{0x44C03971, 0x0, 0x0, 0x801C0000}};
  int check = -1610076970;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2597) {
  my_decimal decimal = {{0xB6309838, 0x0, 0x0, 0x1C0000}};
  int check = 548695708;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2598) {
  my_decimal decimal = {{0xB6309838, 0x0, 0x0, 0x801C0000}};
  int check = -1598787940;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2599) {
  my_decimal decimal = {{0x6E005BB, 0x0, 0x0, 0x1C0000}};
  int check = 509206870;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2600) {
  my_decimal decimal = {{0x6E005BB, 0x0, 0x0, 0x801C0000}};
  int check = -1638276778;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2601) {
  my_decimal decimal = {{0x12380F30, 0x0, 0x0, 0x1C0000}};
  int check = 521164924;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2602) {
  my_decimal decimal = {{0x12380F30, 0x0, 0x0, 0x801C0000}};
  int check = -1626318724;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2603) {
  my_decimal decimal = {{0x4438792, 0x0, 0x0, 0x1C0000}};
  int check = 503783412;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2604) {
  my_decimal decimal = {{0x4438792, 0x0, 0x0, 0x801C0000}};
  int check = -1643700236;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2605) {
  my_decimal decimal = {{0xB4C8DA9, 0x0, 0x0, 0x1C0000}};
  int check = 515050070;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2606) {
  my_decimal decimal = {{0xB4C8DA9, 0x0, 0x0, 0x801C0000}};
  int check = -1632433578;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2607) {
  my_decimal decimal = {{0x443878A, 0x0, 0x0, 0x1C0000}};
  int check = 503783411;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2608) {
  my_decimal decimal = {{0x443878A, 0x0, 0x0, 0x801C0000}};
  int check = -1643700237;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2609) {
  my_decimal decimal = {{0xB4C8D94, 0x0, 0x0, 0x1C0000}};
  int check = 515050069;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2610) {
  my_decimal decimal = {{0xB4C8D94, 0x0, 0x0, 0x801C0000}};
  int check = -1632433579;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2611) {
  my_decimal decimal = {{0x72F78B, 0x0, 0x0, 0x1C0000}};
  int check = 476297005;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2612) {
  my_decimal decimal = {{0x72F78B, 0x0, 0x0, 0x801C0000}};
  int check = -1671186643;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2613) {
  my_decimal decimal = {{0x130A997, 0x0, 0x0, 0x1C0000}};
  int check = 488037518;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2614) {
  my_decimal decimal = {{0x130A997, 0x0, 0x0, 0x801C0000}};
  int check = -1659446130;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2615) {
  my_decimal decimal = {{0x72F78A, 0x0, 0x0, 0x1C0000}};
  int check = 476297003;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2616) {
  my_decimal decimal = {{0x72F78A, 0x0, 0x0, 0x801C0000}};
  int check = -1671186645;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2617) {
  my_decimal decimal = {{0x130A994, 0x0, 0x0, 0x1C0000}};
  int check = 488037517;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2618) {
  my_decimal decimal = {{0x130A994, 0x0, 0x0, 0x801C0000}};
  int check = -1659446131;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2619) {
  my_decimal decimal = {{0xB832B, 0x0, 0x0, 0x1C0000}};
  int check = 448162750;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2620) {
  my_decimal decimal = {{0xB832B, 0x0, 0x0, 0x801C0000}};
  int check = -1699320898;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2621) {
  my_decimal decimal = {{0x1E81FF, 0x0, 0x0, 0x1C0000}};
  int check = 460436778;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2622) {
  my_decimal decimal = {{0x1E81FF, 0x0, 0x0, 0x801C0000}};
  int check = -1687046870;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2623) {
  my_decimal decimal = {{0xB832A, 0x0, 0x0, 0x1C0000}};
  int check = 448162734;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2624) {
  my_decimal decimal = {{0xB832A, 0x0, 0x0, 0x801C0000}};
  int check = -1699320914;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2625) {
  my_decimal decimal = {{0x1E81FC, 0x0, 0x0, 0x1C0000}};
  int check = 460436754;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2626) {
  my_decimal decimal = {{0x1E81FC, 0x0, 0x0, 0x801C0000}};
  int check = -1687046894;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2627) {
  my_decimal decimal = {{0x174D8, 0x0, 0x0, 0x1C0000}};
  int check = 423141263;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2628) {
  my_decimal decimal = {{0x174D8, 0x0, 0x0, 0x801C0000}};
  int check = -1724342385;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2629) {
  my_decimal decimal = {{0x3DC09, 0x0, 0x0, 0x1C0000}};
  int check = 435462187;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2630) {
  my_decimal decimal = {{0x3DC09, 0x0, 0x0, 0x801C0000}};
  int check = -1712021461;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2631) {
  my_decimal decimal = {{0x174D7, 0x0, 0x0, 0x1C0000}};
  int check = 423141137;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2632) {
  my_decimal decimal = {{0x174D7, 0x0, 0x0, 0x801C0000}};
  int check = -1724342511;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2633) {
  my_decimal decimal = {{0x3DC07, 0x0, 0x0, 0x1C0000}};
  int check = 435462060;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2634) {
  my_decimal decimal = {{0x3DC07, 0x0, 0x0, 0x801C0000}};
  int check = -1712021588;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2635) {
  my_decimal decimal = {{0x221, 0x0, 0x0, 0x1C0000}};
  int check = 361164667;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2636) {
  my_decimal decimal = {{0x221, 0x0, 0x0, 0x801C0000}};
  int check = -1786318981;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2637) {
  my_decimal decimal = {{0x5A4, 0x0, 0x0, 0x1C0000}};
  int check = 372425264;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2638) {
  my_decimal decimal = {{0x5A4, 0x0, 0x0, 0x801C0000}};
  int check = -1775058384;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2639) {
  my_decimal decimal = {{0x220, 0x0, 0x0, 0x1C0000}};
  int check = 361148441;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2640) {
  my_decimal decimal = {{0x220, 0x0, 0x0, 0x801C0000}};
  int check = -1786335207;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2641) {
  my_decimal decimal = {{0x5A2, 0x0, 0x0, 0x1C0000}};
  int check = 372409038;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2642) {
  my_decimal decimal = {{0x5A2, 0x0, 0x0, 0x801C0000}};
  int check = -1775074610;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2643) {
  my_decimal decimal = {{0x91, 0x0, 0x0, 0x1C0000}};
  int check = 344955358;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2644) {
  my_decimal decimal = {{0x91, 0x0, 0x0, 0x801C0000}};
  int check = -1802528290;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2645) {
  my_decimal decimal = {{0x180, 0x0, 0x0, 0x1C0000}};
  int check = 356394440;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2646) {
  my_decimal decimal = {{0x180, 0x0, 0x0, 0x801C0000}};
  int check = -1791089208;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2647) {
  my_decimal decimal = {{0x90, 0x0, 0x0, 0x1C0000}};
  int check = 344890454;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2648) {
  my_decimal decimal = {{0x90, 0x0, 0x0, 0x801C0000}};
  int check = -1802593194;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2649) {
  my_decimal decimal = {{0x17E, 0x0, 0x0, 0x1C0000}};
  int check = 356329537;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2650) {
  my_decimal decimal = {{0x17E, 0x0, 0x0, 0x801C0000}};
  int check = -1791154111;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2651) {
  my_decimal decimal = {{0xF, 0x0, 0x0, 0x1C0000}};
  int check = 317566779;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2652) {
  my_decimal decimal = {{0xF, 0x0, 0x0, 0x801C0000}};
  int check = -1829916869;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2653) {
  my_decimal decimal = {{0x28, 0x0, 0x0, 0x1C0000}};
  int check = 329151698;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2654) {
  my_decimal decimal = {{0x28, 0x0, 0x0, 0x801C0000}};
  int check = -1818331950;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2655) {
  my_decimal decimal = {{0xE, 0x0, 0x0, 0x1C0000}};
  int check = 316528319;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2656) {
  my_decimal decimal = {{0xE, 0x0, 0x0, 0x801C0000}};
  int check = -1830955329;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2657) {
  my_decimal decimal = {{0x25, 0x0, 0x0, 0x1C0000}};
  int check = 328372853;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2658) {
  my_decimal decimal = {{0x25, 0x0, 0x0, 0x801C0000}};
  int check = -1819110795;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2659) {
  my_decimal decimal = {{0xC, 0x0, 0x0, 0x1C0000}};
  int check = 314451400;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2660) {
  my_decimal decimal = {{0xC, 0x0, 0x0, 0x801C0000}};
  int check = -1833032248;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2661) {
  my_decimal decimal = {{0x20, 0x0, 0x0, 0x1C0000}};
  int check = 326993846;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2662) {
  my_decimal decimal = {{0x20, 0x0, 0x0, 0x801C0000}};
  int check = -1820489802;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2663) {
  my_decimal decimal = {{0xB, 0x0, 0x0, 0x1C0000}};
  int check = 313412941;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2664) {
  my_decimal decimal = {{0xB, 0x0, 0x0, 0x801C0000}};
  int check = -1834070707;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2665) {
  my_decimal decimal = {{0x1D, 0x0, 0x0, 0x1C0000}};
  int check = 325436157;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2666) {
  my_decimal decimal = {{0x1D, 0x0, 0x0, 0x801C0000}};
  int check = -1822047491;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2667) {
  my_decimal decimal = {{0xA, 0x0, 0x0, 0x1C0000}};
  int check = 312374482;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2668) {
  my_decimal decimal = {{0xA, 0x0, 0x0, 0x801C0000}};
  int check = -1835109166;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2669) {
  my_decimal decimal = {{0x1A, 0x0, 0x0, 0x1C0000}};
  int check = 323878468;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2670) {
  my_decimal decimal = {{0x1A, 0x0, 0x0, 0x801C0000}};
  int check = -1823605180;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2671) {
  my_decimal decimal = {{0x1, 0x0, 0x0, 0x1B0000}};
  int check = 312374482;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2672) {
  my_decimal decimal = {{0x1, 0x0, 0x0, 0x801B0000}};
  int check = -1835109166;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2673) {
  my_decimal decimal = {{0x1A, 0x0, 0x0, 0x1C0000}};
  int check = 323878468;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2674) {
  my_decimal decimal = {{0x1A, 0x0, 0x0, 0x801C0000}};
  int check = -1823605180;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2675) {
  my_decimal decimal = {{0x9, 0x0, 0x0, 0x1C0000}};
  int check = 311336022;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2676) {
  my_decimal decimal = {{0x9, 0x0, 0x0, 0x801C0000}};
  int check = -1836147626;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2677) {
  my_decimal decimal = {{0x18, 0x0, 0x0, 0x1C0000}};
  int check = 322840008;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2678) {
  my_decimal decimal = {{0x18, 0x0, 0x0, 0x801C0000}};
  int check = -1824643640;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2679) {
  my_decimal decimal = {{0x8, 0x0, 0x0, 0x1C0000}};
  int check = 310216630;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2680) {
  my_decimal decimal = {{0x8, 0x0, 0x0, 0x801C0000}};
  int check = -1837267018;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2681) {
  my_decimal decimal = {{0x15, 0x0, 0x0, 0x1C0000}};
  int check = 321282319;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2682) {
  my_decimal decimal = {{0x15, 0x0, 0x0, 0x801C0000}};
  int check = -1826201329;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2683) {
  my_decimal decimal = {{0x7, 0x0, 0x0, 0x1C0000}};
  int check = 308139711;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2684) {
  my_decimal decimal = {{0x7, 0x0, 0x0, 0x801C0000}};
  int check = -1839343937;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2685) {
  my_decimal decimal = {{0x13, 0x0, 0x0, 0x1C0000}};
  int check = 320243860;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2686) {
  my_decimal decimal = {{0x13, 0x0, 0x0, 0x801C0000}};
  int check = -1827239788;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2687) {
  my_decimal decimal = {{0x6, 0x0, 0x0, 0x1C0000}};
  int check = 306062792;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2688) {
  my_decimal decimal = {{0x6, 0x0, 0x0, 0x801C0000}};
  int check = -1841420856;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2689) {
  my_decimal decimal = {{0x10, 0x0, 0x0, 0x1C0000}};
  int check = 318605238;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2690) {
  my_decimal decimal = {{0x10, 0x0, 0x0, 0x801C0000}};
  int check = -1828878410;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2691) {
  my_decimal decimal = {{0x5, 0x0, 0x0, 0x1C0000}};
  int check = 303985874;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2692) {
  my_decimal decimal = {{0x5, 0x0, 0x0, 0x801C0000}};
  int check = -1843497774;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2693) {
  my_decimal decimal = {{0xD, 0x0, 0x0, 0x1C0000}};
  int check = 315489860;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2694) {
  my_decimal decimal = {{0xD, 0x0, 0x0, 0x801C0000}};
  int check = -1831993788;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2695) {
  my_decimal decimal = {{0x2, 0x0, 0x0, 0x1C0000}};
  int check = 293439414;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2696) {
  my_decimal decimal = {{0x2, 0x0, 0x0, 0x801C0000}};
  int check = -1854044234;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2697) {
  my_decimal decimal = {{0x5, 0x0, 0x0, 0x1C0000}};
  int check = 303985874;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2698) {
  my_decimal decimal = {{0x5, 0x0, 0x0, 0x801C0000}};
  int check = -1843497774;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2699) {
  my_decimal decimal = {{0xBFD65D8D, 0xF0185F95, 0xF0A88694, 0x801B0000}};
  int check = -1030425131;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2700) {
  my_decimal decimal = {{0xBFD65D8D, 0xF0185F95, 0xF0A88694, 0x1B0000}};
  int check = 1117058517;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2701) {
  my_decimal decimal = {{0x73C9C637, 0xE59A0333, 0xE48390D2, 0x800E0000}};
  int check = -668938903;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2702) {
  my_decimal decimal = {{0x73C9C637, 0xE59A0333, 0xE48390D2, 0xE0000}};
  int check = 1478544745;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2703) {
  my_decimal decimal = {{0x4C16CCAF, 0xFB5FF1EF, 0x614D4D92, 0x80060000}};
  int check = -456388968;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2704) {
  my_decimal decimal = {{0x4C16CCAF, 0xFB5FF1EF, 0x614D4D92, 0x60000}};
  int check = 1691094680;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2705) {
  my_decimal decimal = {{0xF4792CF7, 0x1D8B9FFA, 0x79BEA393, 0xD0000}};
  int check = 1498819822;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2706) {
  my_decimal decimal = {{0xF4792CF7, 0x1D8B9FFA, 0x79BEA393, 0x800D0000}};
  int check = -648663826;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2707) {
  my_decimal decimal = {{0x5E7CAA3, 0x8BAB668E, 0x204328C9, 0xC0000}};
  int check = 1510859819;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2708) {
  my_decimal decimal = {{0x5E7CAA3, 0x8BAB668E, 0x204328C9, 0x800C0000}};
  int check = -636623829;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2709) {
  my_decimal decimal = {{0xAFB4FCF8, 0x204104C9, 0x3356AFFF, 0x80010000}};
  int check = -324777830;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2710) {
  my_decimal decimal = {{0xAFB4FCF8, 0x204104C9, 0x3356AFFF, 0x10000}};
  int check = 1822705818;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2711) {
  my_decimal decimal = {{0x486290C, 0x1A2B40C5, 0xF51C7281, 0x1B0000}};
  int check = 1117239144;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2712) {
  my_decimal decimal = {{0x486290C, 0x1A2B40C5, 0xF51C7281, 0x801B0000}};
  int check = -1030244504;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2713) {
  my_decimal decimal = {{0xF83D270A, 0xE45FF129, 0x40F456A9, 0x1A0000}};
  int check = 1128859191;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2714) {
  my_decimal decimal = {{0xF83D270A, 0xE45FF129, 0x40F456A9, 0x801A0000}};
  int check = -1018624457;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2715) {
  my_decimal decimal = {{0xDAB89985, 0x4F98BCD7, 0xD383FD08, 0x80040000}};
  int check = -391297528;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2716) {
  my_decimal decimal = {{0xDAB89985, 0x4F98BCD7, 0xD383FD08, 0x40000}};
  int check = 1756186120;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2717) {
  my_decimal decimal = {{0x6881BD66, 0xB95B57A4, 0xC7B4FD5E, 0x170000}};
  int check = 1226237171;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2718) {
  my_decimal decimal = {{0x6881BD66, 0xB95B57A4, 0xC7B4FD5E, 0x80170000}};
  int check = -921246477;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2719) {
  my_decimal decimal = {{0x20D07608, 0x94F5A54E, 0x34EC1F4D, 0x160000}};
  int check = 1237839708;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2720) {
  my_decimal decimal = {{0x20D07608, 0x94F5A54E, 0x34EC1F4D, 0x80160000}};
  int check = -909643940;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2721) {
  my_decimal decimal = {{0x1FE660D, 0x40D54C05, 0x3A6F450D, 0x80170000}};
  int check = -936338530;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2722) {
  my_decimal decimal = {{0x1FE660D, 0x40D54C05, 0x3A6F450D, 0x170000}};
  int check = 1211145118;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2723) {
  my_decimal decimal = {{0x1FD64BBC, 0xD43C17D7, 0x2E9955AD, 0x80030000}};
  int check = -381755762;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2724) {
  my_decimal decimal = {{0x1FD64BBC, 0xD43C17D7, 0x2E9955AD, 0x30000}};
  int check = 1765727886;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2725) {
  my_decimal decimal = {{0x26304983, 0x3BFBA90C, 0x1435004F, 0x180000}};
  int check = 1170435635;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2726) {
  my_decimal decimal = {{0x26304983, 0x3BFBA90C, 0x1435004F, 0x80180000}};
  int check = -977048013;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2727) {
  my_decimal decimal = {{0x98665C68, 0x2BC14CC6, 0x358C7405, 0x180000}};
  int check = 1182890242;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2728) {
  my_decimal decimal = {{0x98665C68, 0x2BC14CC6, 0x358C7405, 0x80180000}};
  int check = -964593406;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2729) {
  my_decimal decimal = {{0x41DB8276, 0x360093A4, 0xE4D68DC0, 0x80070000}};
  int check = -473958756;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2730) {
  my_decimal decimal = {{0x41DB8276, 0x360093A4, 0xE4D68DC0, 0x70000}};
  int check = 1673524892;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2731) {
  my_decimal decimal = {{0x4D71A74E, 0x831D079D, 0x9DD88FB8, 0x80170000}};
  int check = -923891791;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2732) {
  my_decimal decimal = {{0x4D71A74E, 0x831D079D, 0x9DD88FB8, 0x170000}};
  int check = 1223591857;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2733) {
  my_decimal decimal = {{0x4C7E51AA, 0x324F2E0C, 0x37E25EDD, 0x50000}};
  int check = 1712488267;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2734) {
  my_decimal decimal = {{0x4C7E51AA, 0x324F2E0C, 0x37E25EDD, 0x80050000}};
  int check = -434995381;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2735) {
  my_decimal decimal = {{0xFDE85869, 0x2BB83A06, 0x9417E1CA, 0x50000}};
  int check = 1723997149;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2736) {
  my_decimal decimal = {{0xFDE85869, 0x2BB83A06, 0x9417E1CA, 0x80050000}};
  int check = -423486499;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2737) {
  my_decimal decimal = {{0xC80FB0D4, 0xDB6FB902, 0x7A5E29D4, 0x40000}};
  int check = 1749581001;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2738) {
  my_decimal decimal = {{0xC80FB0D4, 0xDB6FB902, 0x7A5E29D4, 0x80040000}};
  int check = -397902647;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2739) {
  my_decimal decimal = {{0x7F419919, 0xE31C5396, 0x206D6EEC, 0x30000}};
  int check = 1761923756;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2740) {
  my_decimal decimal = {{0x7F419919, 0xE31C5396, 0x206D6EEC, 0x80030000}};
  int check = -385559892;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2741) {
  my_decimal decimal = {{0xCF29C9EC, 0x34617B34, 0x483B69C4, 0x80020000}};
  int check = -348591611;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2742) {
  my_decimal decimal = {{0xCF29C9EC, 0x34617B34, 0x483B69C4, 0x20000}};
  int check = 1798892037;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2743) {
  my_decimal decimal = {{0xF0BEB852, 0x61A175C0, 0xD289C734, 0x1C0000}};
  int check = 1087406534;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2744) {
  my_decimal decimal = {{0xF0BEB852, 0x61A175C0, 0xD289C734, 0x801C0000}};
  int check = -1060077114;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2745) {
  my_decimal decimal = {{0xD965BDA5, 0xEBCAC971, 0x37CAE944, 0x1B0000}};
  int check = 1099571910;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2746) {
  my_decimal decimal = {{0xD965BDA5, 0xEBCAC971, 0x37CAE944, 0x801B0000}};
  int check = -1047911738;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2747) {
  my_decimal decimal = {{0x90301EAE, 0x34A6BF50, 0x8DFDEF4B, 0x10000}};
  int check = 1835216869;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2748) {
  my_decimal decimal = {{0x90301EAE, 0x34A6BF50, 0x8DFDEF4B, 0x80010000}};
  int check = -312266779;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2749) {
  my_decimal decimal = {{0x77D644A, 0xA645C9BD, 0x25A0BB92, 0x0}};
  int check = 1846969070;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2750) {
  my_decimal decimal = {{0x77D644A, 0xA645C9BD, 0x25A0BB92, 0x80000000}};
  int check = -300514578;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2751) {
  my_decimal decimal = {{0xCEBB72DD, 0xD31309BC, 0xC601EAD4, 0xF0000}};
  int check = 1449062342;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2752) {
  my_decimal decimal = {{0xCEBB72DD, 0xD31309BC, 0xC601EAD4, 0x800F0000}};
  int check = -698421306;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2753) {
  my_decimal decimal = {{0xCB43980A, 0x84BC15C7, 0x3478D3FD, 0xE0000}};
  int check = 1460908557;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2754) {
  my_decimal decimal = {{0xCB43980A, 0x84BC15C7, 0x3478D3FD, 0x800E0000}};
  int check = -686575091;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2755) {
  my_decimal decimal = {{0xA30A0437, 0xE341CCE, 0x4D84D29E, 0x800A0000}};
  int check = -570086107;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2756) {
  my_decimal decimal = {{0xA30A0437, 0xE341CCE, 0x4D84D29E, 0xA0000}};
  int check = 1577397541;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2757) {
  my_decimal decimal = {{0x17D5F2D8, 0xA3A6E831, 0xDCD7F5D3, 0x30000}};
  int check = 1784816851;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2758) {
  my_decimal decimal = {{0x17D5F2D8, 0xA3A6E831, 0xDCD7F5D3, 0x80030000}};
  int check = -362666797;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2759) {
  my_decimal decimal = {{0xB08E74D5, 0x48CECA54, 0x3A86078B, 0x20000}};
  int check = 1796592127;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2760) {
  my_decimal decimal = {{0xB08E74D5, 0x48CECA54, 0x3A86078B, 0x80020000}};
  int check = -350891521;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2761) {
  my_decimal decimal = {{0xC8968BAD, 0x61E8D6F0, 0x2D550DAA, 0x80040000}};
  int check = -409695376;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2762) {
  my_decimal decimal = {{0xC8968BAD, 0x61E8D6F0, 0x2D550DAA, 0x40000}};
  int check = 1737788272;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2763) {
  my_decimal decimal = {{0xD606B0E9, 0x84C42845, 0xE72FBAF1, 0x80170000}};
  int check = -919687690;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2764) {
  my_decimal decimal = {{0xD606B0E9, 0x84C42845, 0xE72FBAF1, 0x170000}};
  int check = 1227795958;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2765) {
  my_decimal decimal = {{0x26F1B1C5, 0xEA684C4E, 0xB4163DA, 0x80020000}};
  int check = -370769186;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2766) {
  my_decimal decimal = {{0x26F1B1C5, 0xEA684C4E, 0xB4163DA, 0x20000}};
  int check = 1776714462;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2767) {
  my_decimal decimal = {{0xA0D40309, 0x81798B44, 0x605124E3, 0x801A0000}};
  int check = -1013642475;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2768) {
  my_decimal decimal = {{0xA0D40309, 0x81798B44, 0x605124E3, 0x1A0000}};
  int check = 1133841173;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2769) {
  my_decimal decimal = {{0x108A9031, 0x3132ACCE, 0x9D47DAB, 0x80180000}};
  int check = -985783293;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2770) {
  my_decimal decimal = {{0x108A9031, 0x3132ACCE, 0x9D47DAB, 0x180000}};
  int check = 1161700355;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2771) {
  my_decimal decimal = {{0xC232DC12, 0xD25FAA98, 0x1383B13, 0x800A0000}};
  int check = -620357085;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2772) {
  my_decimal decimal = {{0xC232DC12, 0xD25FAA98, 0x1383B13, 0xA0000}};
  int check = 1527126563;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2773) {
  my_decimal decimal = {{0x296106F9, 0x5F57DEDD, 0x7CC8A012, 0xB0000}};
  int check = 1554743388;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2774) {
  my_decimal decimal = {{0x296106F9, 0x5F57DEDD, 0x7CC8A012, 0x800B0000}};
  int check = -592740260;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2775) {
  my_decimal decimal = {{0xA5D86EA6, 0x75890D1, 0x21115361, 0xA0000}};
  int check = 1566784838;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2776) {
  my_decimal decimal = {{0xA5D86EA6, 0x75890D1, 0x21115361, 0x800A0000}};
  int check = -580698810;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2777) {
  my_decimal decimal = {{0x4AFEAA25, 0xC5A623F3, 0x96829E0A, 0xC0000}};
  int check = 1529183453;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2778) {
  my_decimal decimal = {{0x4AFEAA25, 0xC5A623F3, 0x96829E0A, 0x800C0000}};
  int check = -618300195;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2779) {
  my_decimal decimal = {{0x833BCE5E, 0xC64C06F7, 0x27E29D14, 0xB0000}};
  int check = 1541096817;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2780) {
  my_decimal decimal = {{0x833BCE5E, 0xC64C06F7, 0x27E29D14, 0x800B0000}};
  int check = -606386831;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2781) {
  my_decimal decimal = {{0x249D4923, 0x62D6B3FB, 0x344C70E0, 0x800F0000}};
  int check = -714373075;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2782) {
  my_decimal decimal = {{0x249D4923, 0x62D6B3FB, 0x344C70E0, 0xF0000}};
  int check = 1433110573;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2783) {
  my_decimal decimal = {{0xF1602BD7, 0x2DA8F33, 0x57C4B78B, 0x150000}};
  int check = 1271872706;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2784) {
  my_decimal decimal = {{0xF1602BD7, 0x2DA8F33, 0x57C4B78B, 0x80150000}};
  int check = -875610942;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2785) {
  my_decimal decimal = {{0xD93EDA93, 0xC78FFB7C, 0xE8961996, 0x150000}};
  int check = 1284066164;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2786) {
  my_decimal decimal = {{0xD93EDA93, 0xC78FFB7C, 0xE8961996, 0x80150000}};
  int check = -863417484;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2787) {
  my_decimal decimal = {{0x1A8AC820, 0x49975C91, 0x1EAEBADE, 0x800F0000}};
  int check = -720753009;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2788) {
  my_decimal decimal = {{0x1A8AC820, 0x49975C91, 0x1EAEBADE, 0xF0000}};
  int check = 1426730639;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2789) {
  my_decimal decimal = {{0x94E569A3, 0xE4331C86, 0xA1DE0479, 0x80020000}};
  int check = -338743126;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2790) {
  my_decimal decimal = {{0x94E569A3, 0xE4331C86, 0xA1DE0479, 0x20000}};
  int check = 1808740522;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2791) {
  my_decimal decimal = {{0x6AF6BBAC, 0x6D4AC5E9, 0xE54FD32, 0x801A0000}};
  int check = -1036948510;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2792) {
  my_decimal decimal = {{0x6AF6BBAC, 0x6D4AC5E9, 0xE54FD32, 0x1A0000}};
  int check = 1110535138;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2793) {
  my_decimal decimal = {{0x56E62E47, 0xC40D0DD5, 0x8D59613A, 0x80060000}};
  int check = -451660001;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2794) {
  my_decimal decimal = {{0x56E62E47, 0xC40D0DD5, 0x8D59613A, 0x60000}};
  int check = 1695823647;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2795) {
  my_decimal decimal = {{0x1DC45F9E, 0xB3E9C5BB, 0x2075B88B, 0x80050000}};
  int check = -441831713;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2796) {
  my_decimal decimal = {{0x1DC45F9E, 0xB3E9C5BB, 0x2075B88B, 0x50000}};
  int check = 1705651935;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2797) {
  my_decimal decimal = {{0xC50F4BF4, 0x2D5426EB, 0x638F7017, 0x60000}};
  int check = 1691405064;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2798) {
  my_decimal decimal = {{0xC50F4BF4, 0x2D5426EB, 0x638F7017, 0x80060000}};
  int check = -456078584;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2799) {
  my_decimal decimal = {{0x70617E5E, 0xB3B12E27, 0x1A622BC8, 0x50000}};
  int check = 1703564111;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2800) {
  my_decimal decimal = {{0x70617E5E, 0xB3B12E27, 0x1A622BC8, 0x80050000}};
  int check = -443919537;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2801) {
  my_decimal decimal = {{0xF97205, 0xDFBE821F, 0x27590CAE, 0x1A0000}};
  int check = 1123257640;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2802) {
  my_decimal decimal = {{0xF97205, 0xDFBE821F, 0x27590CAE, 0x801A0000}};
  int check = -1024226008;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2803) {
  my_decimal decimal = {{0xF5C83AF4, 0x6A85A59E, 0x684594CF, 0x1A0000}};
  int check = 1134647889;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2804) {
  my_decimal decimal = {{0xF5C83AF4, 0x6A85A59E, 0x684594CF, 0x801A0000}};
  int check = -1012835759;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2805) {
  my_decimal decimal = {{0x1A40DE26, 0xD17B4381, 0x59016861, 0x80140000}};
  int check = -847029932;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2806) {
  my_decimal decimal = {{0x1A40DE26, 0xD17B4381, 0x59016861, 0x140000}};
  int check = 1300453716;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2807) {
  my_decimal decimal = {{0x9681B903, 0xFE688742, 0x7867A760, 0x80130000}};
  int check = -815916133;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2808) {
  my_decimal decimal = {{0x9681B903, 0xFE688742, 0x7867A760, 0x130000}};
  int check = 1331567515;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2809) {
  my_decimal decimal = {{0x70C4B37B, 0x2CE51484, 0x5EAD65CE, 0xA0000}};
  int check = 1579329416;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2810) {
  my_decimal decimal = {{0x70C4B37B, 0x2CE51484, 0x5EAD65CE, 0x800A0000}};
  int check = -568154232;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2811) {
  my_decimal decimal = {{0xC46FA86C, 0x9092432B, 0xFAE51A95, 0xA0000}};
  int check = 1591182433;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2812) {
  my_decimal decimal = {{0xC46FA86C, 0x9092432B, 0xFAE51A95, 0x800A0000}};
  int check = -556301215;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2813) {
  my_decimal decimal = {{0x6A8D9E25, 0x5B38271F, 0xC90C5FDC, 0x80040000}};
  int check = -391859484;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2814) {
  my_decimal decimal = {{0x6A8D9E25, 0x5B38271F, 0xC90C5FDC, 0x40000}};
  int check = 1755624164;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2815) {
  my_decimal decimal = {{0x8464EA81, 0xBFDF5800, 0x4EC43AF6, 0x80130000}};
  int check = -820949903;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2816) {
  my_decimal decimal = {{0x8464EA81, 0xBFDF5800, 0x4EC43AF6, 0x130000}};
  int check = 1326533745;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2817) {
  my_decimal decimal = {{0x92911682, 0x3E158FCA, 0xEB390946, 0x180000}};
  int check = 1200500471;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2818) {
  my_decimal decimal = {{0x92911682, 0x3E158FCA, 0xEB390946, 0x80180000}};
  int check = -946983177;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2819) {
  my_decimal decimal = {{0x5C99A5F7, 0xDAB13BDD, 0x3E5583BC, 0x170000}};
  int check = 1211917473;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2820) {
  my_decimal decimal = {{0x5C99A5F7, 0xDAB13BDD, 0x3E5583BC, 0x80170000}};
  int check = -935566175;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2821) {
  my_decimal decimal = {{0x9F789A69, 0xE115E57F, 0xC08431F7, 0x130000}};
  int check = 1337036966;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2822) {
  my_decimal decimal = {{0x9F789A69, 0xE115E57F, 0xC08431F7, 0x80130000}};
  int check = -810446682;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2823) {
  my_decimal decimal = {{0x9EBD665C, 0x353F670E, 0x33044FCD, 0x120000}};
  int check = 1349207567;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2824) {
  my_decimal decimal = {{0x9EBD665C, 0x353F670E, 0x33044FCD, 0x80120000}};
  int check = -798276081;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2825) {
  my_decimal decimal = {{0x931BB03B, 0xCD632D0C, 0x4D813C0D, 0x80120000}};
  int check = -793594170;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2826) {
  my_decimal decimal = {{0x931BB03B, 0xCD632D0C, 0x4D813C0D, 0x120000}};
  int check = 1353889478;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2827) {
  my_decimal decimal = {{0x79EDD398, 0x73E0B56A, 0x81772250, 0x40000}};
  int check = 1750343094;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2828) {
  my_decimal decimal = {{0x79EDD398, 0x73E0B56A, 0x81772250, 0x80040000}};
  int check = -397140554;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2829) {
  my_decimal decimal = {{0xE56E6250, 0x99966D83, 0x224EEE36, 0x30000}};
  int check = 1762428642;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2830) {
  my_decimal decimal = {{0xE56E6250, 0x99966D83, 0x224EEE36, 0x80030000}};
  int check = -385055006;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2831) {
  my_decimal decimal = {{0xB15D2149, 0xF0A4FC34, 0xBA491489, 0xB0000}};
  int check = 1560282032;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2832) {
  my_decimal decimal = {{0xB15D2149, 0xF0A4FC34, 0xBA491489, 0x800B0000}};
  int check = -587201616;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2833) {
  my_decimal decimal = {{0xA4C2EB61, 0xEA02C2D5, 0x315D9B33, 0xA0000}};
  int check = 1571397244;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2834) {
  my_decimal decimal = {{0xA4C2EB61, 0xEA02C2D5, 0x315D9B33, 0x800A0000}};
  int check = -576086404;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2835) {
  my_decimal decimal = {{0x8B92A36, 0x14BDE1B9, 0xFF99B51D, 0xA0000}};
  int check = 1591447328;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2836) {
  my_decimal decimal = {{0x8B92A36, 0x14BDE1B9, 0xFF99B51D, 0x800A0000}};
  int check = -556036320;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2837) {
  my_decimal decimal = {{0xB6CAAB30, 0x11043D18, 0x43BBEEB7, 0x90000}};
  int check = 1603368249;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2838) {
  my_decimal decimal = {{0xB6CAAB30, 0x11043D18, 0x43BBEEB7, 0x80090000}};
  int check = -544115399;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2839) {
  my_decimal decimal = {{0x125023AF, 0xEB47CE17, 0x7648BB6A, 0x80190000}};
  int check = -983250060;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2840) {
  my_decimal decimal = {{0x125023AF, 0xEB47CE17, 0x7648BB6A, 0x190000}};
  int check = 1164233588;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2841) {
  my_decimal decimal = {{0x215B8AD0, 0x85DB8BDB, 0x470E2AD3, 0xC0000}};
  int check = 1520189594;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2842) {
  my_decimal decimal = {{0x215B8AD0, 0x85DB8BDB, 0x470E2AD3, 0x800C0000}};
  int check = -627294054;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2843) {
  my_decimal decimal = {{0x4B98FCA7, 0x55EC329E, 0xBC4BF17D, 0xC0000}};
  int check = 1531906252;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2844) {
  my_decimal decimal = {{0x4B98FCA7, 0x55EC329E, 0xBC4BF17D, 0x800C0000}};
  int check = -615577396;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2845) {
  my_decimal decimal = {{0x5E0E0AE9, 0xC6C8D161, 0x593C00F, 0x190000}};
  int check = 1126996667;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2846) {
  my_decimal decimal = {{0x5E0E0AE9, 0xC6C8D161, 0x593C00F, 0x80190000}};
  int check = -1020486981;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2847) {
  my_decimal decimal = {{0x3C74211E, 0x13C9AC94, 0x93CB61A2, 0x1A0000}};
  int check = 1139061611;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2848) {
  my_decimal decimal = {{0x3C74211E, 0x13C9AC94, 0x93CB61A2, 0x801A0000}};
  int check = -1008422037;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2849) {
  my_decimal decimal = {{0xA355FDFC, 0x1B8B0244, 0xE85EEE17, 0x80100000}};
  int check = -724480752;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2850) {
  my_decimal decimal = {{0xA355FDFC, 0x1B8B0244, 0xE85EEE17, 0x100000}};
  int check = 1423002896;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2851) {
  my_decimal decimal = {{0xEAF8190C, 0x8B31062B, 0x5FA756C8, 0x40000}};
  int check = 1746712590;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2852) {
  my_decimal decimal = {{0xEAF8190C, 0x8B31062B, 0x5FA756C8, 0x80040000}};
  int check = -400771058;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2853) {
  my_decimal decimal = {{0x2EAB0F2D, 0xA40EB6C1, 0xFD7B72C6, 0x40000}};
  int check = 1758439187;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2854) {
  my_decimal decimal = {{0x2EAB0F2D, 0xA40EB6C1, 0xFD7B72C6, 0x80040000}};
  int check = -389044461;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2855) {
  my_decimal decimal = {{0xAC779C38, 0x99867E4A, 0x35679E5D, 0x0}};
  int check = 1851104889;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2856) {
  my_decimal decimal = {{0xAC779C38, 0x99867E4A, 0x35679E5D, 0x80000000}};
  int check = -296378759;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2857) {
  my_decimal decimal = {{0xE2A35DFB, 0xA3A46845, 0x8D85CA11, 0x0}};
  int check = 1863157194;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2858) {
  my_decimal decimal = {{0xE2A35DFB, 0xA3A46845, 0x8D85CA11, 0x80000000}};
  int check = -284326454;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2859) {
  my_decimal decimal = {{0x96D4C891, 0x3F90E7B0, 0x967E4A75, 0x80060000}};
  int check = -451031618;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2860) {
  my_decimal decimal = {{0x96D4C891, 0x3F90E7B0, 0x967E4A75, 0x60000}};
  int check = 1696452030;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2861) {
  my_decimal decimal = {{0xB2AA0737, 0xE64693F2, 0xD1FE989A, 0x10000}};
  int check = 1839726304;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2862) {
  my_decimal decimal = {{0xB2AA0737, 0xE64693F2, 0xD1FE989A, 0x80010000}};
  int check = -307757344;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2863) {
  my_decimal decimal = {{0x8E10E5C0, 0xC62102A, 0x37A60729, 0x0}};
  int check = 1851693085;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2864) {
  my_decimal decimal = {{0x8E10E5C0, 0xC62102A, 0x37A60729, 0x80000000}};
  int check = -295790563;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2865) {
  my_decimal decimal = {{0xB8F9E6E, 0xFA59BE2B, 0xA54DC9F0, 0x130000}};
  int check = 1335392069;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2866) {
  my_decimal decimal = {{0xB8F9E6E, 0xFA59BE2B, 0xA54DC9F0, 0x80130000}};
  int check = -812091579;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2867) {
  my_decimal decimal = {{0x16437FBE, 0x61101A13, 0x2BCE36CB, 0x120000}};
  int check = 1347028079;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2868) {
  my_decimal decimal = {{0x16437FBE, 0x61101A13, 0x2BCE36CB, 0x80120000}};
  int check = -800455569;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2869) {
  my_decimal decimal = {{0x27E0EDD6, 0x56AD0D23, 0x36029DE7, 0x20000}};
  int check = 1795834916;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2870) {
  my_decimal decimal = {{0x27E0EDD6, 0x56AD0D23, 0x36029DE7, 0x80020000}};
  int check = -351648732;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2871) {
  my_decimal decimal = {{0x90140FDE, 0x3F4A9603, 0x8F2088D8, 0x20000}};
  int check = 1807168482;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2872) {
  my_decimal decimal = {{0x90140FDE, 0x3F4A9603, 0x8F2088D8, 0x80020000}};
  int check = -340315166;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2873) {
  my_decimal decimal = {{0x3368C5FA, 0xFC672208, 0xD140641D, 0x80120000}};
  int check = -781107162;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2874) {
  my_decimal decimal = {{0x3368C5FA, 0xFC672208, 0xD140641D, 0x120000}};
  int check = 1366376486;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2875) {
  my_decimal decimal = {{0x1B60B91C, 0xA54BD3F4, 0x504D01B2, 0x0}};
  int check = 1856018947;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2876) {
  my_decimal decimal = {{0x1B60B91C, 0xA54BD3F4, 0x504D01B2, 0x80000000}};
  int check = -291464701;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2877) {
  my_decimal decimal = {{0xAEF38424, 0x9C6F5813, 0xD4CC114C, 0x0}};
  int check = 1867828241;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2878) {
  my_decimal decimal = {{0xAEF38424, 0x9C6F5813, 0xD4CC114C, 0x80000000}};
  int check = -279655407;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2879) {
  my_decimal decimal = {{0xD559D1DE, 0xF4DD4105, 0xD7AD157A, 0x50000}};
  int check = 1728927858;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2880) {
  my_decimal decimal = {{0xD559D1DE, 0xF4DD4105, 0xD7AD157A, 0x80050000}};
  int check = -418555790;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2881) {
  my_decimal decimal = {{0x95FA5CBC, 0xBE543B78, 0x3927779C, 0x40000}};
  int check = 1740327012;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2882) {
  my_decimal decimal = {{0x95FA5CBC, 0xBE543B78, 0x3927779C, 0x80040000}};
  int check = -407156636;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2883) {
  my_decimal decimal = {{0x722A4EB2, 0x3C382EAD, 0xCE8F3665, 0x130000}};
  int check = 1337885815;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2884) {
  my_decimal decimal = {{0x722A4EB2, 0x3C382EAD, 0xCE8F3665, 0x80130000}};
  int check = -809597833;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2885) {
  my_decimal decimal = {{0x9A69EE74, 0x58EB0C5E, 0x36BCFDC6, 0x120000}};
  int check = 1350332292;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2886) {
  my_decimal decimal = {{0x9A69EE74, 0x58EB0C5E, 0x36BCFDC6, 0x80120000}};
  int check = -797151356;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2887) {
  my_decimal decimal = {{0x72F3F37C, 0x7F9BD2B0, 0x5D29E3C5, 0xA0000}};
  int check = 1579158988;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2888) {
  my_decimal decimal = {{0x72F3F37C, 0x7F9BD2B0, 0x5D29E3C5, 0x800A0000}};
  int check = -568324660;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2889) {
  my_decimal decimal = {{0x9706786F, 0xC55CEE53, 0xF6E23531, 0xA0000}};
  int check = 1590956616;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2890) {
  my_decimal decimal = {{0x9706786F, 0xC55CEE53, 0xF6E23531, 0x800A0000}};
  int check = -556527032;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2891) {
  my_decimal decimal = {{0xBC710527, 0xB34E3C86, 0x8979A50, 0x801A0000}};
  int check = -1043022969;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2892) {
  my_decimal decimal = {{0xBC710527, 0xB34E3C86, 0x8979A50, 0x1A0000}};
  int check = 1104460679;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2893) {
  my_decimal decimal = {{0xA1DDFC88, 0x87C08B46, 0x3AC33770, 0x80000}};
  int check = 1629338964;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2894) {
  my_decimal decimal = {{0xA1DDFC88, 0x87C08B46, 0x3AC33770, 0x80080000}};
  int check = -518144684;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2895) {
  my_decimal decimal = {{0x93591068, 0x67BE3DE1, 0x9BB8861D, 0x80000}};
  int check = 1641087298;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2896) {
  my_decimal decimal = {{0x93591068, 0x67BE3DE1, 0x9BB8861D, 0x80080000}};
  int check = -506396350;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2897) {
  my_decimal decimal = {{0x3350FC16, 0x342E21C6, 0x7B26D31, 0xA0000}};
  int check = 1548980908;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2898) {
  my_decimal decimal = {{0x3350FC16, 0x342E21C6, 0x7B26D31, 0x800A0000}};
  int check = -598502740;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2899) {
  my_decimal decimal = {{0x4FE21847, 0xE6C67F04, 0xCBF84D97, 0xB0000}};
  int check = 1561078469;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2900) {
  my_decimal decimal = {{0x4FE21847, 0xE6C67F04, 0xCBF84D97, 0x800B0000}};
  int check = -586405179;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2901) {
  my_decimal decimal = {{0x2422C06, 0x52673268, 0xFA2047F8, 0x20000}};
  int check = 1814041769;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2902) {
  my_decimal decimal = {{0x2422C06, 0x52673268, 0xFA2047F8, 0x80020000}};
  int check = -333441879;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2903) {
  my_decimal decimal = {{0xCD6603FC, 0xB9AD4465, 0x42488DF3, 0x10000}};
  int check = 1825839968;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2904) {
  my_decimal decimal = {{0xCD6603FC, 0xB9AD4465, 0x42488DF3, 0x80010000}};
  int check = -321643680;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2905) {
  my_decimal decimal = {{0x7559DDEE, 0x82429C25, 0x4573B720, 0x170000}};
  int check = 1213327332;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2906) {
  my_decimal decimal = {{0x7559DDEE, 0x82429C25, 0x4573B720, 0x80170000}};
  int check = -934156316;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2907) {
  my_decimal decimal = {{0xAA2E25B7, 0xF2CA1DC9, 0xB80C3EE2, 0x170000}};
  int check = 1225461767;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2908) {
  my_decimal decimal = {{0xAA2E25B7, 0xF2CA1DC9, 0xB80C3EE2, 0x80170000}};
  int check = -922021881;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2909) {
  my_decimal decimal = {{0x9C57A9BF, 0xE0AC2B71, 0x288DA3F1, 0x801A0000}};
  int check = -1023737026;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2910) {
  my_decimal decimal = {{0x9C57A9BF, 0xE0AC2B71, 0x288DA3F1, 0x1A0000}};
  int check = 1123746622;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2911) {
  my_decimal decimal = {{0xCBAD4239, 0x54767490, 0x85D06D99, 0x130000}};
  int check = 1333188597;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2912) {
  my_decimal decimal = {{0xCBAD4239, 0x54767490, 0x85D06D99, 0x80130000}};
  int check = -814295051;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2913) {
  my_decimal decimal = {{0xCF930897, 0x6EB3DEE3, 0x2375F415, 0x120000}};
  int check = 1344506028;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2914) {
  my_decimal decimal = {{0xCF930897, 0x6EB3DEE3, 0x2375F415, 0x80120000}};
  int check = -802977620;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2915) {
  my_decimal decimal = {{0xE8DE4B87, 0x1C84248B, 0xAB646058, 0x80160000}};
  int check = -895361007;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2916) {
  my_decimal decimal = {{0xE8DE4B87, 0x1C84248B, 0xAB646058, 0x160000}};
  int check = 1252122641;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2917) {
  my_decimal decimal = {{0xB696ED1F, 0x5437FAC7, 0xCAF6A6BB, 0x90000}};
  int check = 1616506413;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2918) {
  my_decimal decimal = {{0xB696ED1F, 0x5437FAC7, 0xCAF6A6BB, 0x80090000}};
  int check = -530977235;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2919) {
  my_decimal decimal = {{0x86256F7A, 0x66F53C0E, 0x35C90AE7, 0x80000}};
  int check = 1628463358;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2920) {
  my_decimal decimal = {{0x86256F7A, 0x66F53C0E, 0x35C90AE7, 0x80080000}};
  int check = -519020290;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2921) {
  my_decimal decimal = {{0x90E34B79, 0x7978ED25, 0x7B6E8D32, 0x170000}};
  int check = 1220183650;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2922) {
  my_decimal decimal = {{0x90E34B79, 0x7978ED25, 0x7B6E8D32, 0x80170000}};
  int check = -927299998;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2923) {
  my_decimal decimal = {{0x6F5AF400, 0xBC59A53E, 0x20B59DBC, 0x160000}};
  int check = 1232545089;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2924) {
  my_decimal decimal = {{0x6F5AF400, 0xBC59A53E, 0x20B59DBC, 0x80160000}};
  int check = -914938559;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2925) {
  my_decimal decimal = {{0x279C6045, 0x9750C1E1, 0xECA8AA71, 0x10000}};
  int check = 1841124284;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2926) {
  my_decimal decimal = {{0x279C6045, 0x9750C1E1, 0xECA8AA71, 0x80010000}};
  int check = -306359364;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2927) {
  my_decimal decimal = {{0x4E563D5A, 0x42FA854C, 0x3EB6EFBA, 0x0}};
  int check = 1853545407;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2928) {
  my_decimal decimal = {{0x4E563D5A, 0x42FA854C, 0x3EB6EFBA, 0x80000000}};
  int check = -293938241;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2929) {
  my_decimal decimal = {{0xBA3E9795, 0x43620991, 0xE56D7F87, 0x190000}};
  int check = 1172169614;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2930) {
  my_decimal decimal = {{0xBA3E9795, 0x43620991, 0xE56D7F87, 0x80190000}};
  int check = -975314034;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2931) {
  my_decimal decimal = {{0x93EA2FD9, 0xD841A8EF, 0x3CCC6083, 0x180000}};
  int check = 1184039003;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2932) {
  my_decimal decimal = {{0x93EA2FD9, 0xD841A8EF, 0x3CCC6083, 0x80180000}};
  int check = -963444645;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2933) {
  my_decimal decimal = {{0xFF2BAA77, 0x1E7EBC34, 0x7D974EF9, 0x80170000}};
  int check = -927086161;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2934) {
  my_decimal decimal = {{0xFF2BAA77, 0x1E7EBC34, 0x7D974EF9, 0x170000}};
  int check = 1220397487;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2935) {
  my_decimal decimal = {{0xE73BDF51, 0x6BA0EF28, 0xBF9A80E3, 0x80180000}};
  int check = -949509524;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2936) {
  my_decimal decimal = {{0xE73BDF51, 0x6BA0EF28, 0xBF9A80E3, 0x180000}};
  int check = 1197974124;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2937) {
  my_decimal decimal = {{0x57D45C56, 0x4ACAD41D, 0x641BC41, 0x100000}};
  int check = 1379161825;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2938) {
  my_decimal decimal = {{0x57D45C56, 0x4ACAD41D, 0x641BC41, 0x80100000}};
  int check = -768321823;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2939) {
  my_decimal decimal = {{0x977B8EE7, 0x3DFEF509, 0xA5CDFCC2, 0x110000}};
  int check = 1391391517;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2940) {
  my_decimal decimal = {{0x977B8EE7, 0x3DFEF509, 0xA5CDFCC2, 0x80110000}};
  int check = -756092131;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2941) {
  my_decimal decimal = {{0xBF03E16D, 0x6B6BC7AF, 0x4A457BCC, 0x120000}};
  int check = 1353400860;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2942) {
  my_decimal decimal = {{0xBF03E16D, 0x6B6BC7AF, 0x4A457BCC, 0x80120000}};
  int check = -794082788;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2943) {
  my_decimal decimal = {{0xED63E22E, 0x1CAA6AC4, 0xC4D1BB44, 0x120000}};
  int check = 1365437131;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2944) {
  my_decimal decimal = {{0xED63E22E, 0x1CAA6AC4, 0xC4D1BB44, 0x80120000}};
  int check = -782046517;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2945) {
  my_decimal decimal = {{0x45DD852F, 0x6F6D520B, 0x47DBA64D, 0x80070000}};
  int check = -487514737;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2946) {
  my_decimal decimal = {{0x45DD852F, 0x6F6D520B, 0x47DBA64D, 0x70000}};
  int check = 1659968911;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2947) {
  my_decimal decimal = {{0x44844F6E, 0x7A05BE84, 0x8954B63A, 0x140000}};
  int check = 1305127462;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2948) {
  my_decimal decimal = {{0x44844F6E, 0x7A05BE84, 0x8954B63A, 0x80140000}};
  int check = -842356186;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2949) {
  my_decimal decimal = {{0x2BC1C840, 0x9DC6A468, 0x24648754, 0x130000}};
  int check = 1317422061;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2950) {
  my_decimal decimal = {{0x2BC1C840, 0x9DC6A468, 0x24648754, 0x80130000}};
  int check = -830061587;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2951) {
  my_decimal decimal = {{0xC3E7D2B4, 0xB1D38949, 0x24141BDA, 0x80100000}};
  int check = -746455913;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2952) {
  my_decimal decimal = {{0xC3E7D2B4, 0xB1D38949, 0x24141BDA, 0x100000}};
  int check = 1401027735;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2953) {
  my_decimal decimal = {{0xC11744C1, 0x8761F3D9, 0x7DB5B620, 0x80030000}};
  int check = -369051117;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2954) {
  my_decimal decimal = {{0xC11744C1, 0x8761F3D9, 0x7DB5B620, 0x30000}};
  int check = 1778432531;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2955) {
  my_decimal decimal = {{0x2C1CB8CA, 0x660D514F, 0x4A534CCC, 0x90000}};
  int check = 1604295889;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2956) {
  my_decimal decimal = {{0x2C1CB8CA, 0x660D514F, 0x4A534CCC, 0x80090000}};
  int check = -543187759;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2957) {
  my_decimal decimal = {{0x1B2834A, 0xDB3CE445, 0xC4F65850, 0x90000}};
  int check = 1616084117;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2958) {
  my_decimal decimal = {{0x1B2834A, 0xDB3CE445, 0xC4F65850, 0x80090000}};
  int check = -531399531;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2959) {
  my_decimal decimal = {{0x5C009952, 0xBAB30902, 0x2B30C357, 0x800D0000}};
  int check = -661129593;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2960) {
  my_decimal decimal = {{0x5C009952, 0xBAB30902, 0x2B30C357, 0xD0000}};
  int check = 1486354055;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2961) {
  my_decimal decimal = {{0x41B13DA5, 0xF31CD04, 0x926DB4A0, 0xE0000}};
  int check = 1473123441;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2962) {
  my_decimal decimal = {{0x41B13DA5, 0xF31CD04, 0x926DB4A0, 0x800E0000}};
  int check = -674360207;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2963) {
  my_decimal decimal = {{0xE35416BC, 0x406CC16, 0x26CDB644, 0xD0000}};
  int check = 1485342500;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2964) {
  my_decimal decimal = {{0xE35416BC, 0x406CC16, 0x26CDB644, 0x800D0000}};
  int check = -662141148;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2965) {
  my_decimal decimal = {{0x204AF4A5, 0x1E07053A, 0x5EC3D3EC, 0x50000}};
  int check = 1719167919;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2966) {
  my_decimal decimal = {{0x204AF4A5, 0x1E07053A, 0x5EC3D3EC, 0x80050000}};
  int check = -428315729;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2967) {
  my_decimal decimal = {{0x3BF9D51C, 0xB5F9010D, 0xFB208B31, 0x50000}};
  int check = 1730450468;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2968) {
  my_decimal decimal = {{0x3BF9D51C, 0xB5F9010D, 0xFB208B31, 0x80050000}};
  int check = -417033180;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2969) {
  my_decimal decimal = {{0xA1F09D6, 0xD5DBD2E6, 0xB575B26C, 0x100000}};
  int check = 1419997637;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2970) {
  my_decimal decimal = {{0xA1F09D6, 0xD5DBD2E6, 0xB575B26C, 0x80100000}};
  int check = -727486011;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2971) {
  my_decimal decimal = {{0x33527716, 0x7B3B8887, 0x30163ACD, 0xF0000}};
  int check = 1431867481;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2972) {
  my_decimal decimal = {{0x33527716, 0x7B3B8887, 0x30163ACD, 0x800F0000}};
  int check = -715616167;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2973) {
  my_decimal decimal = {{0xB89A2705, 0x27634E48, 0x4566545E, 0xE0000}};
  int check = 1464031174;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2974) {
  my_decimal decimal = {{0xB89A2705, 0x27634E48, 0x4566545E, 0x800E0000}};
  int check = -683452474;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2975) {
  my_decimal decimal = {{0xB5FEE767, 0x81FA5C40, 0xB7E8C5F9, 0xE0000}};
  int check = 1476487718;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2976) {
  my_decimal decimal = {{0xB5FEE767, 0x81FA5C40, 0xB7E8C5F9, 0x800E0000}};
  int check = -670995930;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2977) {
  my_decimal decimal = {{0x423DC9BC, 0x71B65E31, 0x96F10C25, 0x40000}};
  int check = 1752649086;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2978) {
  my_decimal decimal = {{0x423DC9BC, 0x71B65E31, 0x96F10C25, 0x80040000}};
  int check = -394834562;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2979) {
  my_decimal decimal = {{0xD0462242, 0xA488A5C2, 0x27FFE0A8, 0x30000}};
  int check = 1763956362;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2980) {
  my_decimal decimal = {{0xD0462242, 0xA488A5C2, 0x27FFE0A8, 0x80030000}};
  int check = -383527286;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2981) {
  my_decimal decimal = {{0xF4A0970F, 0xBA939905, 0x74D51C78, 0x80040000}};
  int check = -398497002;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2982) {
  my_decimal decimal = {{0xF4A0970F, 0xBA939905, 0x74D51C78, 0x40000}};
  int check = 1748986646;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2983) {
  my_decimal decimal = {{0x8A28E1BE, 0x8DF6839A, 0xAB7256B1, 0x180000}};
  int check = 1196377130;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2984) {
  my_decimal decimal = {{0x8A28E1BE, 0x8DF6839A, 0xAB7256B1, 0x80180000}};
  int check = -951106518;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2985) {
  my_decimal decimal = {{0x31698DBE, 0xE4571613, 0x2D6EF092, 0x170000}};
  int check = 1208569948;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2986) {
  my_decimal decimal = {{0x31698DBE, 0xE4571613, 0x2D6EF092, 0x80170000}};
  int check = -938913700;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2987) {
  my_decimal decimal = {{0xDE2C3EA3, 0x7FE5EC79, 0x24F3C5BB, 0x800A0000}};
  int check = -578949360;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2988) {
  my_decimal decimal = {{0xDE2C3EA3, 0x7FE5EC79, 0x24F3C5BB, 0xA0000}};
  int check = 1568534288;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2989) {
  my_decimal decimal = {{0xE1505275, 0xFCE5A857, 0xE6807B1C, 0xE0000}};
  int check = 1478636423;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2990) {
  my_decimal decimal = {{0xE1505275, 0xFCE5A857, 0xE6807B1C, 0x800E0000}};
  int check = -668847225;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2991) {
  my_decimal decimal = {{0xCEE87C40, 0x5260B302, 0x3D153F58, 0xD0000}};
  int check = 1490479788;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2992) {
  my_decimal decimal = {{0xCEE87C40, 0x5260B302, 0x3D153F58, 0x800D0000}};
  int check = -657003860;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2993) {
  my_decimal decimal = {{0x94ABCDA4, 0x333C3EDE, 0x45BD83A5, 0x80040000}};
  int check = -404453787;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2994) {
  my_decimal decimal = {{0x94ABCDA4, 0x333C3EDE, 0x45BD83A5, 0x40000}};
  int check = 1743029861;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2995) {
  my_decimal decimal = {{0x1023791F, 0x67E38343, 0x750F658A, 0x50000}};
  int check = 1721331422;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2996) {
  my_decimal decimal = {{0x1023791F, 0x67E38343, 0x750F658A, 0x80050000}};
  int check = -426152226;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2997) {
  my_decimal decimal = {{0x406FCCE6, 0x32920D06, 0x1F055C30, 0x40000}};
  int check = 1732988031;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2998) {
  my_decimal decimal = {{0x406FCCE6, 0x32920D06, 0x1F055C30, 0x80040000}};
  int check = -414495617;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok2999) {
  my_decimal decimal = {{0x8F00052E, 0x22E47096, 0x49D89924, 0x800F0000}};
  int check = -710522529;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok3000) {
  my_decimal decimal = {{0x8F00052E, 0x22E47096, 0x49D89924, 0xF0000}};
  int check = 1436961119;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok3001) {
  my_decimal decimal = {{0xEDBAC0B3, 0xC52D60D9, 0xF2494D19, 0x80030000}};
  int check = -361227799;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok3002) {
  my_decimal decimal = {{0xEDBAC0B3, 0xC52D60D9, 0xF2494D19, 0x30000}};
  int check = 1786255849;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok3003) {
  my_decimal decimal = {{0xD0D5C09E, 0xF5C86D50, 0xC07CEE69, 0x800D0000}};
  int check = -643215246;

  test_from_decimal_to_float(decimal, check);
}

START_TEST(test_from_decimal_to_float_ok3004) {
  my_decimal decimal = {{0xD0D5C09E, 0xF5C86D50, 0xC07CEE69, 0xD0000}};
  int check = 1504268402;

  test_from_decimal_to_float(decimal, check);
}

Suite *from_decimal_to_float_suite1(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("from_decimal_to_float1");
  tc_core = tcase_create("Core");
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok3);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok4);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok5);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok6);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok7);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok8);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok9);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok10);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok11);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok12);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok13);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok14);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok15);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok16);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok17);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok18);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok19);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok20);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok21);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok22);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok23);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok24);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok25);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok26);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok27);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok28);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok29);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok30);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok31);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok32);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok33);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok34);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok35);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok36);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok37);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok38);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok39);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok40);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok41);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok42);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok43);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok44);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok45);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok46);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok47);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok48);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok49);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok50);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok51);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok52);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok53);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok54);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok55);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok56);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok57);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok58);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok59);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok60);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok61);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok62);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok63);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok64);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok65);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok66);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok67);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok68);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok69);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok70);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok71);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok72);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok73);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok74);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok75);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok76);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok77);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok78);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok79);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok80);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok81);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok82);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok83);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok84);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok85);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok86);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok87);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok88);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok89);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok90);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok91);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok92);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok93);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok94);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok95);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok96);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok97);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok98);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok99);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok100);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok101);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok102);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok103);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok104);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok105);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok106);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok107);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok108);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok109);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok110);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok111);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok112);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok113);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok114);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok115);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok116);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok117);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok118);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok119);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok120);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok121);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok122);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok123);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok124);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok125);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok126);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok127);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok128);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok129);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok130);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok131);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok132);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok133);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok134);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok135);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok136);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok137);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok138);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok139);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok140);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok141);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok142);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok143);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok144);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok145);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok146);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok147);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok148);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok149);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok150);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok151);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok152);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok153);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok154);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok155);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok156);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok157);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok158);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok159);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok160);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok161);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok162);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok163);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok164);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok165);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok166);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok167);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok168);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok169);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok170);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok171);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok172);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok173);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok174);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok175);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok176);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok177);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok178);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok179);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok180);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok181);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok182);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok183);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok184);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok185);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok186);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok187);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok188);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok189);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok190);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok191);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok192);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok193);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok194);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok195);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok196);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok197);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok198);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok199);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok200);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok201);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok202);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok203);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok204);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok205);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok206);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok207);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok208);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok209);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok210);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok211);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok212);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok213);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok214);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok215);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok216);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok217);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok218);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok219);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok220);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok221);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok222);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok223);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok224);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok225);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok226);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok227);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok228);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok229);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok230);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok231);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok232);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok233);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok234);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok235);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok236);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok237);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok238);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok239);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok240);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok241);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok242);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok243);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok244);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok245);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok246);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok247);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok248);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok249);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok250);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok251);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok252);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok253);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok254);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok255);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok256);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok257);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok258);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok259);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok260);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok261);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok262);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok263);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok264);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok265);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok266);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok267);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok268);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok269);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok270);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok271);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok272);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok273);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok274);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok275);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok276);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok277);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok278);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok279);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok280);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok281);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok282);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok283);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok284);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok285);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok286);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok287);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok288);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok289);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok290);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok291);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok292);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok293);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok294);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok295);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok296);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok297);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok298);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok299);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok300);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok301);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok302);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok303);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok304);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok305);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok306);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok307);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok308);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok309);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok310);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok311);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok312);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok313);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok314);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok315);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok316);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok317);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok318);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok319);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok320);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok321);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok322);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok323);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok324);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok325);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok326);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok327);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok328);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok329);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok330);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok331);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok332);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok333);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok334);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok335);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok336);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok337);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok338);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok339);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok340);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok341);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok342);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok343);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok344);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok345);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok346);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok347);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok348);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok349);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok350);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok351);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok352);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok353);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok354);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok355);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok356);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok357);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok358);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok359);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok360);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok361);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok362);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok363);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok364);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok365);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok366);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok367);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok368);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok369);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok370);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok371);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok372);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok373);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok374);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok375);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok376);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok377);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok378);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok379);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok380);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok381);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok382);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok383);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok384);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok385);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok386);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok387);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok388);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok389);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok390);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok391);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok392);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok393);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok394);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok395);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok396);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok397);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok398);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok399);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok400);

  suite_add_tcase(s, tc_core);
  return s;
}

Suite *from_decimal_to_float_suite2(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("from_decimal_to_float2");
  tc_core = tcase_create("Core");
  tcase_add_test(tc_core, test_from_decimal_to_float_ok401);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok402);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok403);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok404);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok405);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok406);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok407);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok408);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok409);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok410);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok411);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok412);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok413);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok414);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok415);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok416);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok417);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok418);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok419);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok420);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok421);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok422);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok423);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok424);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok425);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok426);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok427);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok428);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok429);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok430);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok431);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok432);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok433);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok434);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok435);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok436);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok437);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok438);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok439);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok440);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok441);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok442);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok443);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok444);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok445);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok446);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok447);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok448);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok449);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok450);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok451);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok452);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok453);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok454);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok455);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok456);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok457);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok458);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok459);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok460);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok461);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok462);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok463);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok464);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok465);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok466);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok467);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok468);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok469);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok470);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok471);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok472);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok473);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok474);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok475);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok476);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok477);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok478);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok479);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok480);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok481);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok482);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok483);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok484);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok485);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok486);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok487);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok488);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok489);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok490);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok491);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok492);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok493);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok494);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok495);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok496);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok497);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok498);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok499);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok500);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok501);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok502);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok503);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok504);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok505);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok506);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok507);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok508);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok509);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok510);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok511);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok512);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok513);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok514);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok515);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok516);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok517);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok518);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok519);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok520);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok521);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok522);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok523);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok524);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok525);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok526);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok527);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok528);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok529);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok530);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok531);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok532);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok533);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok534);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok535);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok536);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok537);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok538);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok539);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok540);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok541);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok542);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok543);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok544);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok545);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok546);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok547);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok548);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok549);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok550);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok551);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok552);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok553);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok554);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok555);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok556);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok557);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok558);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok559);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok560);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok561);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok562);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok563);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok564);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok565);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok566);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok567);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok568);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok569);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok570);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok571);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok572);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok573);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok574);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok575);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok576);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok577);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok578);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok579);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok580);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok581);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok582);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok583);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok584);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok585);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok586);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok587);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok588);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok589);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok590);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok591);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok592);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok593);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok594);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok595);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok596);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok597);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok598);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok599);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok600);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok601);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok602);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok603);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok604);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok605);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok606);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok607);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok608);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok609);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok610);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok611);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok612);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok613);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok614);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok615);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok616);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok617);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok618);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok619);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok620);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok621);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok622);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok623);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok624);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok625);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok626);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok627);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok628);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok629);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok630);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok631);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok632);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok633);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok634);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok635);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok636);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok637);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok638);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok639);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok640);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok641);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok642);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok643);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok644);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok645);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok646);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok647);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok648);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok649);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok650);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok651);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok652);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok653);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok654);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok655);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok656);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok657);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok658);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok659);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok660);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok661);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok662);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok663);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok664);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok665);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok666);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok667);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok668);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok669);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok670);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok671);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok672);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok673);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok674);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok675);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok676);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok677);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok678);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok679);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok680);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok681);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok682);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok683);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok684);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok685);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok686);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok687);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok688);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok689);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok690);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok691);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok692);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok693);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok694);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok695);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok696);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok697);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok698);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok699);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok700);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok701);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok702);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok703);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok704);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok705);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok706);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok707);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok708);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok709);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok710);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok711);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok712);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok713);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok714);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok715);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok716);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok717);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok718);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok719);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok720);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok721);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok722);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok723);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok724);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok725);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok726);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok727);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok728);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok729);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok730);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok731);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok732);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok733);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok734);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok735);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok736);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok737);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok738);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok739);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok740);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok741);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok742);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok743);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok744);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok745);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok746);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok747);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok748);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok749);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok750);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok751);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok752);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok753);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok754);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok755);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok756);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok757);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok758);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok759);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok760);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok761);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok762);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok763);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok764);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok765);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok766);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok767);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok768);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok769);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok770);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok771);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok772);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok773);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok774);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok775);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok776);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok777);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok778);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok779);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok780);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok781);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok782);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok783);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok784);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok785);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok786);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok787);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok788);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok789);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok790);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok791);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok792);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok793);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok794);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok795);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok796);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok797);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok798);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok799);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok800);

  suite_add_tcase(s, tc_core);
  return s;
}

Suite *from_decimal_to_float_suite3(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("from_decimal_to_float3");
  tc_core = tcase_create("Core");
  tcase_add_test(tc_core, test_from_decimal_to_float_ok801);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok802);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok803);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok804);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok805);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok806);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok807);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok808);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok809);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok810);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok811);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok812);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok813);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok814);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok815);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok816);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok817);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok818);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok819);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok820);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok821);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok822);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok823);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok824);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok825);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok826);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok827);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok828);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok829);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok830);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok831);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok832);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok833);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok834);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok835);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok836);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok837);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok838);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok839);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok840);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok841);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok842);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok843);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok844);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok845);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok846);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok847);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok848);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok849);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok850);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok851);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok852);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok853);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok854);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok855);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok856);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok857);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok858);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok859);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok860);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok861);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok862);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok863);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok864);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok865);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok866);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok867);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok868);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok869);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok870);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok871);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok872);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok873);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok874);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok875);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok876);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok877);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok878);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok879);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok880);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok881);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok882);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok883);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok884);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok885);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok886);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok887);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok888);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok889);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok890);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok891);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok892);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok893);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok894);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok895);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok896);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok897);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok898);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok899);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok900);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok901);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok902);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok903);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok904);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok905);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok906);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok907);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok908);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok909);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok910);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok911);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok912);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok913);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok914);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok915);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok916);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok917);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok918);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok919);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok920);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok921);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok922);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok923);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok924);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok925);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok926);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok927);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok928);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok929);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok930);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok931);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok932);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok933);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok934);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok935);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok936);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok937);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok938);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok939);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok940);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok941);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok942);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok943);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok944);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok945);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok946);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok947);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok948);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok949);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok950);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok951);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok952);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok953);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok954);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok955);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok956);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok957);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok958);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok959);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok960);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok961);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok962);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok963);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok964);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok965);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok966);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok967);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok968);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok969);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok970);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok971);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok972);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok973);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok974);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok975);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok976);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok977);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok978);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok979);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok980);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok981);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok982);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok983);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok984);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok985);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok986);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok987);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok988);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok989);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok990);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok991);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok992);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok993);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok994);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok995);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok996);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok997);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok998);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok999);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1000);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1001);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1002);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1003);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1004);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1005);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1006);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1007);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1008);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1009);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1010);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1011);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1012);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1013);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1014);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1015);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1016);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1017);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1018);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1019);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1020);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1021);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1022);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1023);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1024);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1025);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1026);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1027);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1028);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1029);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1030);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1031);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1032);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1033);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1034);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1035);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1036);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1037);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1038);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1039);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1040);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1041);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1042);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1043);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1044);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1045);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1046);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1047);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1048);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1049);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1050);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1051);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1052);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1053);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1054);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1055);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1056);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1057);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1058);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1059);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1060);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1061);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1062);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1063);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1064);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1065);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1066);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1067);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1068);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1069);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1070);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1071);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1072);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1073);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1074);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1075);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1076);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1077);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1078);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1079);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1080);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1081);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1082);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1083);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1084);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1085);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1086);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1087);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1088);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1089);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1090);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1091);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1092);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1093);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1094);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1095);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1096);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1097);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1098);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1099);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1100);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1101);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1102);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1103);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1104);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1105);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1106);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1107);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1108);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1109);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1110);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1111);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1112);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1113);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1114);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1115);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1116);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1117);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1118);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1119);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1120);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1121);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1122);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1123);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1124);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1125);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1126);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1127);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1128);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1129);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1130);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1131);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1132);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1133);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1134);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1135);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1136);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1137);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1138);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1139);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1140);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1141);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1142);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1143);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1144);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1145);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1146);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1147);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1148);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1149);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1150);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1151);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1152);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1153);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1154);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1155);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1156);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1157);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1158);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1159);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1160);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1161);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1162);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1163);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1164);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1165);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1166);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1167);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1168);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1169);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1170);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1171);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1172);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1173);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1174);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1175);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1176);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1177);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1178);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1179);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1180);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1181);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1182);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1183);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1184);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1185);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1186);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1187);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1188);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1189);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1190);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1191);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1192);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1193);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1194);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1195);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1196);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1197);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1198);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1199);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1200);

  suite_add_tcase(s, tc_core);
  return s;
}

Suite *from_decimal_to_float_suite4(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("from_decimal_to_float4");
  tc_core = tcase_create("Core");
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1201);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1202);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1203);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1204);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1205);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1206);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1207);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1208);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1209);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1210);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1211);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1212);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1213);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1214);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1215);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1216);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1217);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1218);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1219);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1220);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1221);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1222);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1223);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1224);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1225);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1226);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1227);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1228);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1229);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1230);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1231);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1232);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1233);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1234);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1235);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1236);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1237);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1238);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1239);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1240);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1241);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1242);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1243);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1244);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1245);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1246);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1247);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1248);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1249);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1250);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1251);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1252);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1253);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1254);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1255);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1256);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1257);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1258);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1259);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1260);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1261);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1262);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1263);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1264);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1265);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1266);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1267);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1268);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1269);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1270);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1271);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1272);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1273);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1274);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1275);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1276);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1277);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1278);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1279);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1280);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1281);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1282);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1283);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1284);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1285);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1286);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1287);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1288);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1289);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1290);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1291);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1292);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1293);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1294);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1295);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1296);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1297);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1298);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1299);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1300);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1301);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1302);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1303);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1304);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1305);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1306);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1307);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1308);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1309);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1310);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1311);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1312);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1313);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1314);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1315);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1316);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1317);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1318);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1319);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1320);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1321);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1322);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1323);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1324);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1325);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1326);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1327);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1328);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1329);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1330);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1331);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1332);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1333);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1334);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1335);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1336);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1337);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1338);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1339);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1340);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1341);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1342);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1343);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1344);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1345);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1346);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1347);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1348);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1349);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1350);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1351);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1352);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1353);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1354);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1355);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1356);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1357);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1358);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1359);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1360);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1361);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1362);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1363);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1364);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1365);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1366);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1367);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1368);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1369);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1370);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1371);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1372);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1373);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1374);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1375);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1376);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1377);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1378);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1379);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1380);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1381);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1382);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1383);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1384);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1385);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1386);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1387);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1388);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1389);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1390);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1391);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1392);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1393);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1394);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1395);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1396);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1397);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1398);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1399);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1400);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1401);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1402);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1403);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1404);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1405);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1406);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1407);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1408);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1409);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1410);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1411);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1412);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1413);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1414);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1415);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1416);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1417);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1418);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1419);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1420);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1421);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1422);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1423);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1424);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1425);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1426);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1427);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1428);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1429);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1430);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1431);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1432);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1433);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1434);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1435);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1436);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1437);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1438);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1439);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1440);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1441);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1442);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1443);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1444);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1445);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1446);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1447);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1448);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1449);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1450);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1451);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1452);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1453);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1454);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1455);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1456);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1457);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1458);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1459);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1460);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1461);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1462);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1463);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1464);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1465);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1466);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1467);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1468);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1469);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1470);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1471);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1472);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1473);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1474);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1475);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1476);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1477);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1478);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1479);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1480);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1481);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1482);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1483);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1484);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1485);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1486);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1487);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1488);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1489);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1490);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1491);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1492);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1493);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1494);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1495);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1496);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1497);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1498);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1499);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1500);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1501);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1502);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1503);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1504);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1505);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1506);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1507);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1508);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1509);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1510);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1511);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1512);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1513);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1514);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1515);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1516);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1517);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1518);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1519);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1520);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1521);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1522);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1523);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1524);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1525);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1526);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1527);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1528);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1529);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1530);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1531);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1532);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1533);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1534);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1535);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1536);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1537);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1538);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1539);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1540);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1541);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1542);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1543);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1544);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1545);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1546);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1547);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1548);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1549);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1550);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1551);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1552);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1553);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1554);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1555);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1556);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1557);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1558);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1559);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1560);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1561);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1562);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1563);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1564);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1565);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1566);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1567);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1568);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1569);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1570);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1571);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1572);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1573);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1574);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1575);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1576);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1577);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1578);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1579);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1580);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1581);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1582);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1583);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1584);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1585);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1586);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1587);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1588);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1589);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1590);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1591);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1592);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1593);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1594);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1595);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1596);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1597);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1598);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1599);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1600);

  suite_add_tcase(s, tc_core);
  return s;
}

Suite *from_decimal_to_float_suite5(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("from_decimal_to_float5");
  tc_core = tcase_create("Core");
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1601);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1602);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1603);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1604);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1605);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1606);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1607);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1608);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1609);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1610);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1611);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1612);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1613);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1614);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1615);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1616);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1617);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1618);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1619);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1620);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1621);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1622);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1623);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1624);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1625);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1626);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1627);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1628);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1629);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1630);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1631);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1632);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1633);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1634);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1635);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1636);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1637);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1638);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1639);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1640);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1641);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1642);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1643);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1644);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1645);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1646);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1647);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1648);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1649);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1650);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1651);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1652);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1653);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1654);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1655);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1656);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1657);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1658);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1659);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1660);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1661);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1662);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1663);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1664);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1665);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1666);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1667);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1668);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1669);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1670);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1671);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1672);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1673);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1674);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1675);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1676);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1677);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1678);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1679);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1680);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1681);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1682);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1683);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1684);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1685);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1686);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1687);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1688);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1689);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1690);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1691);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1692);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1693);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1694);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1695);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1696);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1697);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1698);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1699);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1700);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1701);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1702);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1703);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1704);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1705);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1706);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1707);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1708);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1709);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1710);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1711);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1712);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1713);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1714);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1715);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1716);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1717);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1718);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1719);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1720);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1721);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1722);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1723);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1724);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1725);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1726);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1727);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1728);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1729);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1730);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1731);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1732);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1733);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1734);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1735);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1736);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1737);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1738);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1739);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1740);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1741);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1742);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1743);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1744);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1745);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1746);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1747);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1748);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1749);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1750);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1751);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1752);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1753);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1754);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1755);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1756);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1757);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1758);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1759);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1760);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1761);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1762);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1763);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1764);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1765);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1766);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1767);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1768);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1769);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1770);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1771);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1772);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1773);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1774);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1775);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1776);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1777);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1778);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1779);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1780);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1781);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1782);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1783);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1784);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1785);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1786);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1787);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1788);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1789);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1790);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1791);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1792);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1793);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1794);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1795);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1796);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1797);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1798);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1799);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1800);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1801);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1802);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1803);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1804);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1805);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1806);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1807);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1808);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1809);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1810);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1811);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1812);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1813);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1814);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1815);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1816);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1817);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1818);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1819);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1820);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1821);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1822);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1823);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1824);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1825);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1826);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1827);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1828);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1829);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1830);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1831);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1832);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1833);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1834);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1835);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1836);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1837);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1838);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1839);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1840);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1841);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1842);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1843);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1844);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1845);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1846);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1847);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1848);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1849);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1850);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1851);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1852);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1853);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1854);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1855);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1856);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1857);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1858);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1859);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1860);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1861);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1862);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1863);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1864);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1865);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1866);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1867);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1868);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1869);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1870);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1871);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1872);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1873);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1874);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1875);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1876);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1877);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1878);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1879);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1880);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1881);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1882);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1883);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1884);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1885);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1886);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1887);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1888);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1889);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1890);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1891);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1892);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1893);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1894);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1895);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1896);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1897);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1898);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1899);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1900);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1901);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1902);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1903);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1904);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1905);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1906);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1907);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1908);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1909);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1910);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1911);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1912);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1913);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1914);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1915);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1916);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1917);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1918);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1919);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1920);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1921);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1922);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1923);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1924);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1925);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1926);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1927);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1928);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1929);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1930);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1931);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1932);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1933);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1934);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1935);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1936);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1937);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1938);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1939);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1940);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1941);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1942);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1943);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1944);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1945);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1946);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1947);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1948);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1949);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1950);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1951);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1952);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1953);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1954);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1955);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1956);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1957);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1958);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1959);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1960);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1961);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1962);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1963);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1964);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1965);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1966);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1967);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1968);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1969);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1970);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1971);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1972);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1973);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1974);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1975);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1976);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1977);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1978);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1979);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1980);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1981);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1982);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1983);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1984);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1985);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1986);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1987);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1988);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1989);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1990);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1991);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1992);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1993);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1994);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1995);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1996);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1997);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1998);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok1999);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2000);

  suite_add_tcase(s, tc_core);
  return s;
}

Suite *from_decimal_to_float_suite6(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("from_decimal_to_float6");
  tc_core = tcase_create("Core");
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2001);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2002);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2003);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2004);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2005);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2006);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2007);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2008);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2009);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2010);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2011);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2012);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2013);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2014);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2015);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2016);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2017);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2018);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2019);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2020);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2021);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2022);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2023);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2024);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2025);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2026);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2027);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2028);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2029);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2030);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2031);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2032);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2033);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2034);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2035);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2036);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2037);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2038);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2039);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2040);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2041);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2042);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2043);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2044);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2045);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2046);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2047);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2048);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2049);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2050);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2051);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2052);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2053);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2054);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2055);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2056);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2057);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2058);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2059);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2060);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2061);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2062);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2063);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2064);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2065);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2066);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2067);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2068);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2069);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2070);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2071);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2072);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2073);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2074);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2075);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2076);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2077);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2078);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2079);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2080);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2081);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2082);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2083);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2084);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2085);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2086);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2087);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2088);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2089);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2090);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2091);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2092);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2093);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2094);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2095);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2096);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2097);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2098);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2099);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2100);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2101);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2102);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2103);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2104);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2105);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2106);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2107);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2108);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2109);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2110);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2111);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2112);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2113);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2114);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2115);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2116);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2117);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2118);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2119);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2120);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2121);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2122);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2123);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2124);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2125);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2126);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2127);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2128);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2129);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2130);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2131);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2132);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2133);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2134);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2135);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2136);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2137);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2138);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2139);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2140);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2141);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2142);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2143);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2144);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2145);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2146);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2147);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2148);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2149);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2150);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2151);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2152);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2153);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2154);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2155);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2156);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2157);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2158);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2159);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2160);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2161);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2162);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2163);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2164);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2165);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2166);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2167);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2168);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2169);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2170);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2171);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2172);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2173);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2174);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2175);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2176);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2177);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2178);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2179);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2180);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2181);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2182);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2183);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2184);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2185);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2186);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2187);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2188);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2189);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2190);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2191);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2192);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2193);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2194);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2195);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2196);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2197);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2198);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2199);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2200);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2201);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2202);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2203);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2204);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2205);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2206);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2207);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2208);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2209);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2210);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2211);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2212);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2213);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2214);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2215);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2216);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2217);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2218);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2219);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2220);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2221);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2222);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2223);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2224);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2225);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2226);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2227);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2228);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2229);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2230);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2231);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2232);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2233);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2234);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2235);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2236);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2237);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2238);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2239);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2240);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2241);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2242);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2243);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2244);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2245);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2246);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2247);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2248);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2249);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2250);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2251);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2252);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2253);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2254);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2255);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2256);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2257);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2258);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2259);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2260);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2261);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2262);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2263);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2264);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2265);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2266);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2267);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2268);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2269);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2270);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2271);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2272);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2273);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2274);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2275);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2276);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2277);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2278);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2279);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2280);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2281);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2282);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2283);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2284);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2285);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2286);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2287);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2288);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2289);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2290);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2291);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2292);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2293);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2294);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2295);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2296);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2297);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2298);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2299);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2300);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2301);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2302);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2303);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2304);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2305);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2306);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2307);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2308);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2309);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2310);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2311);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2312);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2313);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2314);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2315);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2316);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2317);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2318);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2319);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2320);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2321);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2322);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2323);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2324);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2325);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2326);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2327);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2328);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2329);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2330);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2331);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2332);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2333);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2334);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2335);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2336);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2337);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2338);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2339);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2340);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2341);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2342);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2343);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2344);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2345);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2346);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2347);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2348);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2349);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2350);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2351);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2352);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2353);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2354);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2355);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2356);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2357);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2358);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2359);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2360);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2361);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2362);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2363);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2364);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2365);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2366);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2367);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2368);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2369);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2370);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2371);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2372);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2373);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2374);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2375);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2376);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2377);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2378);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2379);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2380);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2381);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2382);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2383);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2384);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2385);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2386);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2387);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2388);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2389);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2390);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2391);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2392);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2393);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2394);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2395);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2396);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2397);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2398);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2399);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2400);

  suite_add_tcase(s, tc_core);
  return s;
}

Suite *from_decimal_to_float_suite7(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("from_decimal_to_float7");
  tc_core = tcase_create("Core");
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2401);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2402);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2403);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2404);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2405);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2406);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2407);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2408);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2409);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2410);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2411);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2412);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2413);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2414);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2415);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2416);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2417);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2418);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2419);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2420);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2421);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2422);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2423);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2424);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2425);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2426);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2427);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2428);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2429);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2430);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2431);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2432);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2433);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2434);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2435);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2436);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2437);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2438);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2439);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2440);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2441);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2442);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2443);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2444);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2445);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2446);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2447);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2448);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2449);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2450);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2451);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2452);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2453);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2454);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2455);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2456);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2457);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2458);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2459);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2460);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2461);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2462);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2463);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2464);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2465);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2466);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2467);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2468);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2469);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2470);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2471);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2472);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2473);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2474);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2475);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2476);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2477);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2478);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2479);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2480);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2481);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2482);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2483);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2484);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2485);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2486);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2487);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2488);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2489);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2490);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2491);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2492);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2493);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2494);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2495);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2496);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2497);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2498);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2499);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2500);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2501);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2502);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2503);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2504);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2505);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2506);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2507);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2508);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2509);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2510);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2511);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2512);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2513);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2514);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2515);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2516);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2517);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2518);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2519);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2520);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2521);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2522);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2523);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2524);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2525);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2526);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2527);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2528);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2529);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2530);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2531);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2532);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2533);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2534);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2535);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2536);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2537);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2538);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2539);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2540);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2541);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2542);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2543);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2544);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2545);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2546);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2547);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2548);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2549);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2550);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2551);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2552);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2553);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2554);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2555);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2556);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2557);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2558);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2559);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2560);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2561);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2562);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2563);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2564);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2565);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2566);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2567);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2568);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2569);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2570);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2571);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2572);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2573);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2574);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2575);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2576);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2577);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2578);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2579);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2580);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2581);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2582);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2583);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2584);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2585);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2586);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2587);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2588);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2589);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2590);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2591);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2592);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2593);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2594);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2595);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2596);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2597);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2598);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2599);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2600);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2601);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2602);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2603);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2604);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2605);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2606);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2607);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2608);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2609);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2610);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2611);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2612);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2613);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2614);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2615);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2616);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2617);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2618);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2619);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2620);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2621);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2622);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2623);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2624);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2625);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2626);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2627);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2628);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2629);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2630);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2631);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2632);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2633);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2634);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2635);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2636);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2637);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2638);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2639);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2640);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2641);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2642);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2643);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2644);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2645);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2646);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2647);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2648);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2649);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2650);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2651);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2652);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2653);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2654);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2655);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2656);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2657);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2658);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2659);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2660);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2661);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2662);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2663);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2664);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2665);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2666);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2667);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2668);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2669);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2670);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2671);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2672);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2673);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2674);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2675);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2676);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2677);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2678);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2679);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2680);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2681);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2682);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2683);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2684);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2685);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2686);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2687);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2688);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2689);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2690);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2691);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2692);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2693);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2694);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2695);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2696);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2697);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2698);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2699);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2700);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2701);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2702);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2703);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2704);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2705);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2706);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2707);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2708);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2709);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2710);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2711);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2712);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2713);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2714);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2715);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2716);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2717);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2718);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2719);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2720);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2721);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2722);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2723);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2724);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2725);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2726);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2727);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2728);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2729);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2730);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2731);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2732);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2733);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2734);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2735);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2736);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2737);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2738);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2739);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2740);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2741);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2742);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2743);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2744);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2745);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2746);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2747);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2748);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2749);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2750);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2751);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2752);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2753);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2754);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2755);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2756);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2757);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2758);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2759);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2760);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2761);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2762);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2763);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2764);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2765);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2766);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2767);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2768);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2769);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2770);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2771);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2772);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2773);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2774);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2775);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2776);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2777);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2778);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2779);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2780);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2781);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2782);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2783);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2784);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2785);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2786);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2787);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2788);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2789);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2790);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2791);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2792);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2793);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2794);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2795);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2796);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2797);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2798);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2799);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2800);

  suite_add_tcase(s, tc_core);
  return s;
}

Suite *from_decimal_to_float_suite8(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("from_decimal_to_float8");
  tc_core = tcase_create("Core");
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2801);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2802);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2803);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2804);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2805);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2806);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2807);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2808);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2809);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2810);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2811);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2812);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2813);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2814);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2815);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2816);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2817);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2818);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2819);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2820);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2821);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2822);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2823);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2824);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2825);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2826);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2827);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2828);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2829);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2830);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2831);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2832);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2833);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2834);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2835);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2836);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2837);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2838);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2839);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2840);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2841);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2842);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2843);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2844);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2845);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2846);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2847);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2848);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2849);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2850);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2851);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2852);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2853);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2854);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2855);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2856);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2857);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2858);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2859);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2860);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2861);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2862);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2863);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2864);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2865);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2866);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2867);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2868);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2869);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2870);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2871);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2872);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2873);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2874);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2875);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2876);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2877);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2878);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2879);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2880);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2881);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2882);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2883);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2884);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2885);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2886);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2887);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2888);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2889);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2890);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2891);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2892);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2893);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2894);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2895);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2896);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2897);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2898);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2899);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2900);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2901);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2902);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2903);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2904);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2905);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2906);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2907);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2908);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2909);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2910);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2911);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2912);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2913);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2914);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2915);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2916);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2917);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2918);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2919);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2920);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2921);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2922);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2923);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2924);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2925);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2926);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2927);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2928);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2929);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2930);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2931);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2932);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2933);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2934);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2935);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2936);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2937);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2938);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2939);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2940);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2941);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2942);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2943);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2944);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2945);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2946);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2947);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2948);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2949);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2950);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2951);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2952);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2953);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2954);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2955);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2956);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2957);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2958);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2959);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2960);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2961);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2962);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2963);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2964);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2965);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2966);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2967);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2968);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2969);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2970);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2971);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2972);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2973);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2974);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2975);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2976);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2977);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2978);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2979);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2980);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2981);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2982);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2983);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2984);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2985);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2986);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2987);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2988);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2989);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2990);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2991);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2992);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2993);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2994);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2995);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2996);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2997);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2998);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok2999);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok3000);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok3001);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok3002);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok3003);
  tcase_add_test(tc_core, test_from_decimal_to_float_ok3004);

  suite_add_tcase(s, tc_core);
  return s;
}

Suite *from_decimal_to_float_suite0(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("from_decimal_to_float0");
  tc_core = tcase_create("Core");

  tcase_add_test(tc_core, test_from_decimal_to_float_fail_manual1);
  tcase_add_test(tc_core, test_from_decimal_to_float_fail_manual2);
  tcase_add_test(tc_core, test_from_decimal_to_float_fail_manual3);
  tcase_add_test(tc_core, test_from_decimal_to_float_fail_manual4);
  tcase_add_test(tc_core, test_from_decimal_to_float_fail_manual5);
  tcase_add_test(tc_core, test_from_decimal_to_float_fail_manual6);
  tcase_add_test(tc_core, test_from_decimal_to_float_fail_manual7);
  tcase_add_test(tc_core, test_from_decimal_to_float_fail_manual8);
  tcase_add_test(tc_core, test_from_decimal_to_float_fail_manual9);

  suite_add_tcase(s, tc_core);
  return s;
}

void test_from_decimal_to_float(my_decimal decimal, int check) {
  float result;
  int code = my_from_decimal_to_float(decimal, &result);

  float_cast_test cast_result;
  cast_result.f = result;

#if defined(__DEBUG)
  float_cast_test cast_check;
  cast_check.int32_bytes = check;
  printf("---------------------------------\n");
  printf("Test:\n");
  my_print_decimal_bits(decimal);
  my_print_decimal_string(decimal);
  printf("Check:\n");
  my_print_bit(cast_check.bytes, 0);
  printf("\n");
  printf("%.80f\n", cast_check.f);
  printf("Result:\n");
  my_print_bit(cast_result.bytes, 0);
  printf("\n");
  printf("%.80f\n", cast_result.f);
  printf("---------------------------------\n");
#endif

  ck_assert_int_eq(cast_result.int32_bytes, check);
  ck_assert_int_eq(code, TEST_CONVERSION_OK);
}
