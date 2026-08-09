#include "./test_from_float_to_decimal.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "./../../my_decimal.h"
#include "./../test.h"

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * * * * * * * * * * * * * * Тесты на ненормальные float
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * * * * * * * * * * * * * */

START_TEST(test_from_float_to_decimal_unnormal1) {
  float f = 0.0;
  my_decimal result;
  my_decimal check = {{0x0, 0x0, 0x0, 0x0}};

  int code = my_from_float_to_decimal(f, &result);
  ck_assert_int_eq(code, TEST_CONVERSION_OK);
  ck_assert_int_eq(my_is_equal(result, check), 1);
}
END_TEST

START_TEST(test_from_float_to_decimal_unnormal2) {
  float f = -0.0;
  my_decimal result;
  my_decimal check = {{0x0, 0x0, 0x0, 0x80000000}};

  int code = my_from_float_to_decimal(f, &result);

  int sign_check = test_decimal_get_sign(check);
  int sign_result = test_decimal_get_sign(result);

  ck_assert_int_eq(code, TEST_CONVERSION_OK);
  ck_assert_int_eq(my_is_equal(result, check), 1);
  ck_assert_int_eq(sign_check, sign_result);
}
END_TEST

START_TEST(test_from_float_to_decimal_unnormal3) {
  float f = INFINITY;
  my_decimal result;

  int code = my_from_float_to_decimal(f, &result);
  ck_assert_int_eq(code, TEST_CONVERSION_ERROR);
}
END_TEST

START_TEST(test_from_float_to_decimal_unnormal4) {
  float f = -INFINITY;
  my_decimal result;

  int code = my_from_float_to_decimal(f, &result);
  ck_assert_int_eq(code, TEST_CONVERSION_ERROR);
}
END_TEST

START_TEST(test_from_float_to_decimal_unnormal5) {
  float f = NAN;
  my_decimal result;

  int code = my_from_float_to_decimal(f, &result);
  ck_assert_int_eq(code, TEST_CONVERSION_ERROR);
}
END_TEST

START_TEST(test_from_float_to_decimal_unnormal6) {
  float f = -NAN;
  my_decimal result;

  int code = my_from_float_to_decimal(f, &result);
  ck_assert_int_eq(code, TEST_CONVERSION_ERROR);
}
END_TEST

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * * * * * * * * * * * * * * Тесты на некорректные данные
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * * * * * * * * * * * * * */

START_TEST(test_from_float_to_decimal_incorrect1) {
  float f = 1.0f;
  int code = my_from_float_to_decimal(f, NULL);

  ck_assert_int_eq(code, TEST_CONVERSION_ERROR);
}
END_TEST

START_TEST(test_from_float_to_decimal_fail_big) {
  float f = fails_big[_i];
  my_decimal result;

  int code = my_from_float_to_decimal(f, &result);
  ck_assert_int_eq(code, TEST_CONVERSION_ERROR);
}
END_TEST

START_TEST(test_from_float_to_decimal_fail_big_negate) {
  float f = -fails_big[_i];
  my_decimal result;

  int code = my_from_float_to_decimal(f, &result);
  ck_assert_int_eq(code, TEST_CONVERSION_ERROR);
}
END_TEST

START_TEST(test_from_float_to_decimal_fail_small) {
  float f = fails_small[_i];
  my_decimal result;
  my_decimal check = {{0x0, 0x0, 0x0, 0x0}};

  int code = my_from_float_to_decimal(f, &result);
  ck_assert_int_eq(code, TEST_CONVERSION_ERROR);
  ck_assert_int_eq(my_is_equal(result, check), 1);
}
END_TEST

START_TEST(test_from_float_to_decimal_fail_small_negate) {
  float f = -fails_small[_i];
  my_decimal result;
  my_decimal check = {{0x0, 0x0, 0x0, 0x0}};

  int code = my_from_float_to_decimal(f, &result);
  ck_assert_int_eq(code, TEST_CONVERSION_ERROR);
  ck_assert_int_eq(my_is_equal(result, check), 1);
}
END_TEST

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * * * * * * * * * * * * * * * Tests for correct data (automatic)
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * *
 * * * * * * * * * * * * * * */

START_TEST(test_from_float_to_decimal_ok1) {
  int f = 545706772;

  my_decimal decimal_check = {{0x22D9F0, 0x0, 0x0, 0x190000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2) {
  int f = -1601776876;

  my_decimal decimal_check = {{0x22D9F0, 0x0, 0x0, 0x80190000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok3) {
  int f = 1727711253;

  my_decimal decimal_check = {{0xBF280000, 0x9ED0576, 0x7D64, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok4) {
  int f = -419772395;

  my_decimal decimal_check = {{0xBF280000, 0x9ED0576, 0x7D64, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok5) {
  int f = 572360491;

  my_decimal decimal_check = {{0x209376, 0x0, 0x0, 0x180000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok6) {
  int f = -1575123157;

  my_decimal decimal_check = {{0x209376, 0x0, 0x0, 0x80180000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok7) {
  int f = 852291818;

  my_decimal decimal_check = {{0x2467A4, 0x0, 0x0, 0xE0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok8) {
  int f = -1295191830;

  my_decimal decimal_check = {{0x2467A4, 0x0, 0x0, 0x800E0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok9) {
  int f = 1396199450;

  my_decimal decimal_check = {{0x501A8DE0, 0xB8, 0x0, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok10) {
  int f = -751284198;

  my_decimal decimal_check = {{0x501A8DE0, 0xB8, 0x0, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok11) {
  int f = 1658314220;

  my_decimal decimal_check = {{0x5F048000, 0xEEF78A9E, 0x6B, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok12) {
  int f = -489169428;

  my_decimal decimal_check = {{0x5F048000, 0xEEF78A9E, 0x6B, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok13) {
  int f = 1760949678;

  my_decimal decimal_check = {{0xE380000, 0x6CD28004, 0x7AFAD, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok14) {
  int f = -386533970;

  my_decimal decimal_check = {{0xE380000, 0x6CD28004, 0x7AFAD, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok15) {
  int f = 955395702;

  my_decimal decimal_check = {{0x119EFB, 0x0, 0x0, 0xA0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok16) {
  int f = -1192087946;

  my_decimal decimal_check = {{0x119EFB, 0x0, 0x0, 0x800A0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok17) {
  int f = 449944209;

  my_decimal decimal_check = {{0xD3A55, 0x0, 0x0, 0x1C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok18) {
  int f = -1697539439;

  my_decimal decimal_check = {{0xD3A55, 0x0, 0x0, 0x801C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok19) {
  int f = 1387676487;

  my_decimal decimal_check = {{0x21A3B200, 0x5B, 0x0, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok20) {
  int f = -759807161;

  my_decimal decimal_check = {{0x21A3B200, 0x5B, 0x0, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok21) {
  int f = 624052425;

  my_decimal decimal_check = {{0x25C0D, 0x0, 0x0, 0x150000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok22) {
  int f = -1523431223;

  my_decimal decimal_check = {{0x25C0D, 0x0, 0x0, 0x80150000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok23) {
  int f = 703447194;

  my_decimal decimal_check = {{0x101C59, 0x0, 0x0, 0x130000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok24) {
  int f = -1444036454;

  my_decimal decimal_check = {{0x101C59, 0x0, 0x0, 0x80130000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok25) {
  int f = 1167627706;

  my_decimal decimal_check = {{0x4A811C, 0x0, 0x0, 0x30000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok26) {
  int f = -979855942;

  my_decimal decimal_check = {{0x4A811C, 0x0, 0x0, 0x80030000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok27) {
  int f = 348479575;

  my_decimal decimal_check = {{0xC7, 0x0, 0x0, 0x1C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok28) {
  int f = -1799004073;

  my_decimal decimal_check = {{0xC7, 0x0, 0x0, 0x801C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok29) {
  int f = 1163878845;

  my_decimal decimal_check = {{0x36895D, 0x0, 0x0, 0x30000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok30) {
  int f = -983604803;

  my_decimal decimal_check = {{0x36895D, 0x0, 0x0, 0x80030000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok31) {
  int f = 718032851;

  my_decimal decimal_check = {{0x3760FB, 0x0, 0x0, 0x130000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok32) {
  int f = -1429450797;

  my_decimal decimal_check = {{0x3760FB, 0x0, 0x0, 0x80130000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok33) {
  int f = 545047011;

  my_decimal decimal_check = {{0x20AB0A, 0x0, 0x0, 0x190000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok34) {
  int f = -1602436637;

  my_decimal decimal_check = {{0x20AB0A, 0x0, 0x0, 0x80190000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok35) {
  int f = 1131495064;

  my_decimal decimal_check = {{0x24CF9D, 0x0, 0x0, 0x40000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok36) {
  int f = -1015988584;

  my_decimal decimal_check = {{0x24CF9D, 0x0, 0x0, 0x80040000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok37) {
  int f = 1229189441;

  my_decimal decimal_check = {{0x7A76C9, 0x0, 0x0, 0x10000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok38) {
  int f = -918294207;

  my_decimal decimal_check = {{0x7A76C9, 0x0, 0x0, 0x80010000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok39) {
  int f = 1536490184;

  my_decimal decimal_check = {{0xB858FC00, 0x129F590, 0x0, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok40) {
  int f = -610993464;

  my_decimal decimal_check = {{0xB858FC00, 0x129F590, 0x0, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok41) {
  int f = 607485242;

  my_decimal decimal_check = {{0x3C0CBB, 0x0, 0x0, 0x170000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok42) {
  int f = -1539998406;

  my_decimal decimal_check = {{0x3C0CBB, 0x0, 0x0, 0x80170000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok43) {
  int f = 512338845;

  my_decimal decimal_check = {{0x163DEA, 0x0, 0x0, 0x1A0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok44) {
  int f = -1635144803;

  my_decimal decimal_check = {{0x163DEA, 0x0, 0x0, 0x801A0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok45) {
  int f = 1625920341;

  my_decimal decimal_check = {{0x207FC000, 0x4C9A980F, 0x7, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok46) {
  int f = -521563307;

  my_decimal decimal_check = {{0x207FC000, 0x4C9A980F, 0x7, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok47) {
  int f = 516993130;

  my_decimal decimal_check = {{0x21B72E, 0x0, 0x0, 0x1A0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok48) {
  int f = -1630490518;

  my_decimal decimal_check = {{0x21B72E, 0x0, 0x0, 0x801A0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok49) {
  int f = 834167265;

  my_decimal decimal_check = {{0x51E1D8, 0x0, 0x0, 0xF0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok50) {
  int f = -1313316383;

  my_decimal decimal_check = {{0x51E1D8, 0x0, 0x0, 0x800F0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok51) {
  int f = 1557212038;

  my_decimal decimal_check = {{0xA3031000, 0x6895C30, 0x0, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok52) {
  int f = -590271610;

  my_decimal decimal_check = {{0xA3031000, 0x6895C30, 0x0, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok53) {
  int f = 768600146;

  my_decimal decimal_check = {{0x2410F3, 0x0, 0x0, 0x110000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok54) {
  int f = -1378883502;

  my_decimal decimal_check = {{0x2410F3, 0x0, 0x0, 0x80110000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok55) {
  int f = 1020334292;

  my_decimal decimal_check = {{0x26F108, 0x0, 0x0, 0x80000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok56) {
  int f = -1127149356;

  my_decimal decimal_check = {{0x26F108, 0x0, 0x0, 0x80080000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok57) {
  int f = 412686710;

  my_decimal decimal_check = {{0x9A97, 0x0, 0x0, 0x1C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok58) {
  int f = -1734796938;

  my_decimal decimal_check = {{0x9A97, 0x0, 0x0, 0x801C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok59) {
  int f = 998427162;

  my_decimal decimal_check = {{0x3CE752, 0x0, 0x0, 0x90000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok60) {
  int f = -1149056486;

  my_decimal decimal_check = {{0x3CE752, 0x0, 0x0, 0x80090000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok61) {
  int f = 933474121;

  my_decimal decimal_check = {{0x1DC62A, 0x0, 0x0, 0xB0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok62) {
  int f = -1214009527;

  my_decimal decimal_check = {{0x1DC62A, 0x0, 0x0, 0x800B0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok63) {
  int f = 510618173;

  my_decimal decimal_check = {{0x1356FC, 0x0, 0x0, 0x1A0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok64) {
  int f = -1636865475;

  my_decimal decimal_check = {{0x1356FC, 0x0, 0x0, 0x801A0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok65) {
  int f = 1033669270;

  my_decimal decimal_check = {{0x74A1E5, 0x0, 0x0, 0x80000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok66) {
  int f = -1113814378;

  my_decimal decimal_check = {{0x74A1E5, 0x0, 0x0, 0x80080000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok67) {
  int f = 565197904;

  my_decimal decimal_check = {{0x1238EB, 0x0, 0x0, 0x180000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok68) {
  int f = -1582285744;

  my_decimal decimal_check = {{0x1238EB, 0x0, 0x0, 0x80180000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok69) {
  int f = 644141985;

  my_decimal decimal_check = {{0xC1D2E, 0x0, 0x0, 0x150000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok70) {
  int f = -1503341663;

  my_decimal decimal_check = {{0xC1D2E, 0x0, 0x0, 0x80150000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok71) {
  int f = 668155680;

  my_decimal decimal_check = {{0x8F257, 0x0, 0x0, 0x140000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok72) {
  int f = -1479327968;

  my_decimal decimal_check = {{0x8F257, 0x0, 0x0, 0x80140000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok73) {
  int f = 784033658;

  my_decimal decimal_check = {{0x8209AD, 0x0, 0x0, 0x110000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok74) {
  int f = -1363449990;

  my_decimal decimal_check = {{0x8209AD, 0x0, 0x0, 0x80110000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok75) {
  int f = 311976189;

  my_decimal decimal_check = {{0x1, 0x0, 0x0, 0x1B0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok76) {
  int f = -1835507459;

  my_decimal decimal_check = {{0x1, 0x0, 0x0, 0x801B0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok77) {
  int f = 1278250448;

  my_decimal decimal_check = {{0x2C23740, 0x0, 0x0, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok78) {
  int f = -869233200;

  my_decimal decimal_check = {{0x2C23740, 0x0, 0x0, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok79) {
  int f = 732037276;

  my_decimal decimal_check = {{0x119078, 0x0, 0x0, 0x120000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok80) {
  int f = -1415446372;

  my_decimal decimal_check = {{0x119078, 0x0, 0x0, 0x80120000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok81) {
  int f = 771334370;

  my_decimal decimal_check = {{0x2B4DBB, 0x0, 0x0, 0x110000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok82) {
  int f = -1376149278;

  my_decimal decimal_check = {{0x2B4DBB, 0x0, 0x0, 0x80110000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok83) {
  int f = 812107280;

  my_decimal decimal_check = {{0x80A905, 0x0, 0x0, 0x100000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok84) {
  int f = -1335376368;

  my_decimal decimal_check = {{0x80A905, 0x0, 0x0, 0x80100000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok85) {
  int f = 1566199356;

  my_decimal decimal_check = {{0x72049000, 0xDA4E3B8, 0x0, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok86) {
  int f = -581284292;

  my_decimal decimal_check = {{0x72049000, 0xDA4E3B8, 0x0, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok87) {
  int f = 1167888755;

  my_decimal decimal_check = {{0x4C7305, 0x0, 0x0, 0x30000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok88) {
  int f = -979594893;

  my_decimal decimal_check = {{0x4C7305, 0x0, 0x0, 0x80030000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok89) {
  int f = 389306006;

  my_decimal decimal_check = {{0x16C3, 0x0, 0x0, 0x1C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok90) {
  int f = -1758177642;

  my_decimal decimal_check = {{0x16C3, 0x0, 0x0, 0x801C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok91) {
  int f = 1530148745;

  my_decimal decimal_check = {{0x9D7A4000, 0xB43789, 0x0, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok92) {
  int f = -617334903;

  my_decimal decimal_check = {{0x9D7A4000, 0xB43789, 0x0, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok93) {
  int f = 1597783252;

  my_decimal decimal_check = {{0xFD28E000, 0xBC3CD4A8, 0x0, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok94) {
  int f = -549700396;

  my_decimal decimal_check = {{0xFD28E000, 0xBC3CD4A8, 0x0, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok95) {
  int f = 1820658757;

  my_decimal decimal_check = {{0x8FA00000, 0x955F02E9, 0x428623D, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok96) {
  int f = -326824891;

  my_decimal decimal_check = {{0x8FA00000, 0x955F02E9, 0x428623D, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok97) {
  int f = 1648681745;

  my_decimal decimal_check = {{0x6B7A4000, 0x38C429DC, 0x31, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok98) {
  int f = -498801903;

  my_decimal decimal_check = {{0x6B7A4000, 0x38C429DC, 0x31, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok99) {
  int f = 1265275158;

  my_decimal decimal_check = {{0xEA911A, 0x0, 0x0, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok100) {
  int f = -882208490;

  my_decimal decimal_check = {{0xEA911A, 0x0, 0x0, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok101) {
  int f = 451815583;

  my_decimal decimal_check = {{0xF07A9, 0x0, 0x0, 0x1C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok102) {
  int f = -1695668065;

  my_decimal decimal_check = {{0xF07A9, 0x0, 0x0, 0x801C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok103) {
  int f = 748762995;

  my_decimal decimal_check = {{0x45EAA3, 0x0, 0x0, 0x120000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok104) {
  int f = -1398720653;

  my_decimal decimal_check = {{0x45EAA3, 0x0, 0x0, 0x80120000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok105) {
  int f = 754081612;

  my_decimal decimal_check = {{0x691CBA, 0x0, 0x0, 0x120000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok106) {
  int f = -1393402036;

  my_decimal decimal_check = {{0x691CBA, 0x0, 0x0, 0x80120000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok107) {
  int f = 1351687559;

  my_decimal decimal_check = {{0x88EC3290, 0x4, 0x0, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok108) {
  int f = -795796089;

  my_decimal decimal_check = {{0x88EC3290, 0x4, 0x0, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok109) {
  int f = 977497236;

  my_decimal decimal_check = {{0x71C077, 0x0, 0x0, 0xA0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok110) {
  int f = -1169986412;

  my_decimal decimal_check = {{0x71C077, 0x0, 0x0, 0x800A0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok111) {
  int f = 1591352577;

  my_decimal decimal_check = {{0xDD238000, 0x6D0E80C8, 0x0, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok112) {
  int f = -556131071;

  my_decimal decimal_check = {{0xDD238000, 0x6D0E80C8, 0x0, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok113) {
  int f = 1668164171;

  my_decimal decimal_check = {{0x883C8000, 0x2A4C5A69, 0xEE, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok114) {
  int f = -479319477;

  my_decimal decimal_check = {{0x883C8000, 0x2A4C5A69, 0xEE, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok115) {
  int f = 1613352011;

  my_decimal decimal_check = {{0x88276000, 0xA7312EB9, 0x2, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok116) {
  int f = -534131637;

  my_decimal decimal_check = {{0x88276000, 0xA7312EB9, 0x2, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok117) {
  int f = 1576109204;

  my_decimal decimal_check = {{0x34628000, 0x1E3092C6, 0x0, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok118) {
  int f = -571374444;

  my_decimal decimal_check = {{0x34628000, 0x1E3092C6, 0x0, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok119) {
  int f = 1396972063;

  my_decimal decimal_check = {{0x1A1E8DC0, 0xC4, 0x0, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok120) {
  int f = -750511585;

  my_decimal decimal_check = {{0x1A1E8DC0, 0xC4, 0x0, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok121) {
  int f = 887417636;

  my_decimal decimal_check = {{0x6819A, 0x0, 0x0, 0xC0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok122) {
  int f = -1260066012;

  my_decimal decimal_check = {{0x6819A, 0x0, 0x0, 0x800C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok123) {
  int f = 738318948;

  my_decimal decimal_check = {{0x1C284B, 0x0, 0x0, 0x120000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok124) {
  int f = -1409164700;

  my_decimal decimal_check = {{0x1C284B, 0x0, 0x0, 0x80120000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok125) {
  int f = 532023947;

  my_decimal decimal_check = {{0x75A430, 0x0, 0x0, 0x1A0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok126) {
  int f = -1615459701;

  my_decimal decimal_check = {{0x75A430, 0x0, 0x0, 0x801A0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok127) {
  int f = 1009501697;

  my_decimal decimal_check = {{0xFFF66, 0x0, 0x0, 0x80000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok128) {
  int f = -1137981951;

  my_decimal decimal_check = {{0xFFF66, 0x0, 0x0, 0x80080000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok129) {
  int f = 460294537;

  my_decimal decimal_check = {{0x1E3BDE, 0x0, 0x0, 0x1C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok130) {
  int f = -1687189111;

  my_decimal decimal_check = {{0x1E3BDE, 0x0, 0x0, 0x801C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok131) {
  int f = 1679807510;

  my_decimal decimal_check = {{0x6F3E0000, 0x505C1EA1, 0x27F, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok132) {
  int f = -467676138;

  my_decimal decimal_check = {{0x6F3E0000, 0x505C1EA1, 0x27F, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok133) {
  int f = 1219373966;

  my_decimal decimal_check = {{0x366D9C, 0x0, 0x0, 0x10000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok134) {
  int f = -928109682;

  my_decimal decimal_check = {{0x366D9C, 0x0, 0x0, 0x80010000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok135) {
  int f = 608521972;

  my_decimal decimal_check = {{0x4148AC, 0x0, 0x0, 0x170000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok136) {
  int f = -1538961676;

  my_decimal decimal_check = {{0x4148AC, 0x0, 0x0, 0x80170000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok137) {
  int f = 1262322241;

  my_decimal decimal_check = {{0xBD8242, 0x0, 0x0, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok138) {
  int f = -885161407;

  my_decimal decimal_check = {{0xBD8242, 0x0, 0x0, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok139) {
  int f = 493426727;

  my_decimal decimal_check = {{0x2F12B2, 0x0, 0x0, 0x1B0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok140) {
  int f = -1654056921;

  my_decimal decimal_check = {{0x2F12B2, 0x0, 0x0, 0x801B0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok141) {
  int f = 1500372451;

  my_decimal decimal_check = {{0x2E1BC800, 0xEDDDE, 0x0, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok142) {
  int f = -647111197;

  my_decimal decimal_check = {{0x2E1BC800, 0xEDDDE, 0x0, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok143) {
  int f = 1791055472;

  my_decimal decimal_check = {{0xBAE00000, 0x7467DF7, 0x60AB36, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok144) {
  int f = -356428176;

  my_decimal decimal_check = {{0xBAE00000, 0x7467DF7, 0x60AB36, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok145) {
  int f = 1411229266;

  my_decimal decimal_check = {{0x99478E40, 0x276, 0x0, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok146) {
  int f = -736254382;

  my_decimal decimal_check = {{0x99478E40, 0x276, 0x0, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok147) {
  int f = 503244335;

  my_decimal decimal_check = {{0x66F3F4, 0x0, 0x0, 0x1B0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok148) {
  int f = -1644239313;

  my_decimal decimal_check = {{0x66F3F4, 0x0, 0x0, 0x801B0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok149) {
  int f = 779636593;

  my_decimal decimal_check = {{0x562663, 0x0, 0x0, 0x110000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok150) {
  int f = -1367847055;

  my_decimal decimal_check = {{0x562663, 0x0, 0x0, 0x80110000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok151) {
  int f = 1361751220;

  my_decimal decimal_check = {{0xAACB4080, 0xA, 0x0, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok152) {
  int f = -785732428;

  my_decimal decimal_check = {{0xAACB4080, 0xA, 0x0, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok153) {
  int f = 512512747;

  my_decimal decimal_check = {{0x16ABA9, 0x0, 0x0, 0x1A0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok154) {
  int f = -1634970901;

  my_decimal decimal_check = {{0x16ABA9, 0x0, 0x0, 0x801A0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok155) {
  int f = 455735147;

  my_decimal decimal_check = {{0x22531, 0x0, 0x0, 0x1B0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok156) {
  int f = -1691748501;

  my_decimal decimal_check = {{0x22531, 0x0, 0x0, 0x801B0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok157) {
  int f = 1685671774;

  my_decimal decimal_check = {{0x2A1F0000, 0x3D6CDFB7, 0x3E5, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok158) {
  int f = -461811874;

  my_decimal decimal_check = {{0x2A1F0000, 0x3D6CDFB7, 0x3E5, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok159) {
  int f = 870391778;

  my_decimal decimal_check = {{0xFFEFE, 0x0, 0x0, 0xD0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok160) {
  int f = -1277091870;

  my_decimal decimal_check = {{0xFFEFE, 0x0, 0x0, 0x800D0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok161) {
  int f = 1525802043;

  my_decimal decimal_check = {{0x7F106400, 0x78F21E, 0x0, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok162) {
  int f = -621681605;

  my_decimal decimal_check = {{0x7F106400, 0x78F21E, 0x0, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok163) {
  int f = 497537431;

  my_decimal decimal_check = {{0x43C80C, 0x0, 0x0, 0x1B0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok164) {
  int f = -1649946217;

  my_decimal decimal_check = {{0x43C80C, 0x0, 0x0, 0x801B0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok165) {
  int f = 938025806;

  my_decimal decimal_check = {{0x43DA2, 0x0, 0x0, 0xA0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok166) {
  int f = -1209457842;

  my_decimal decimal_check = {{0x43DA2, 0x0, 0x0, 0x800A0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok167) {
  int f = 713784810;

  my_decimal decimal_check = {{0x25CF31, 0x0, 0x0, 0x130000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok168) {
  int f = -1433698838;

  my_decimal decimal_check = {{0x25CF31, 0x0, 0x0, 0x80130000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok169) {
  int f = 561092358;

  my_decimal decimal_check = {{0x7CE629, 0x0, 0x0, 0x190000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok170) {
  int f = -1586391290;

  my_decimal decimal_check = {{0x7CE629, 0x0, 0x0, 0x80190000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok171) {
  int f = 1742695776;

  my_decimal decimal_check = {{0xE22C0000, 0xC47CDAF3, 0x1BEDA, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok172) {
  int f = -404787872;

  my_decimal decimal_check = {{0xE22C0000, 0xC47CDAF3, 0x1BEDA, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok173) {
  int f = 1322909819;

  my_decimal decimal_check = {{0x6D003C60, 0x0, 0x0, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok174) {
  int f = -824573829;

  my_decimal decimal_check = {{0x6D003C60, 0x0, 0x0, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok175) {
  int f = 1248354969;

  my_decimal decimal_check = {{0x3A18A6, 0x0, 0x0, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok176) {
  int f = -899128679;

  my_decimal decimal_check = {{0x3A18A6, 0x0, 0x0, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok177) {
  int f = 1145685318;

  my_decimal decimal_check = {{0x7B26A8, 0x0, 0x0, 0x40000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok178) {
  int f = -1001798330;

  my_decimal decimal_check = {{0x7B26A8, 0x0, 0x0, 0x80040000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok179) {
  int f = 619162666;

  my_decimal decimal_check = {{0xF54AF, 0x0, 0x0, 0x160000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok180) {
  int f = -1528320982;

  my_decimal decimal_check = {{0xF54AF, 0x0, 0x0, 0x80160000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok181) {
  int f = 566364767;

  my_decimal decimal_check = {{0x2019F, 0x0, 0x0, 0x170000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok182) {
  int f = -1581118881;

  my_decimal decimal_check = {{0x2019F, 0x0, 0x0, 0x80170000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok183) {
  int f = 728666297;

  my_decimal decimal_check = {{0x815397, 0x0, 0x0, 0x130000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok184) {
  int f = -1418817351;

  my_decimal decimal_check = {{0x815397, 0x0, 0x0, 0x80130000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok185) {
  int f = 293851635;

  my_decimal decimal_check = {{0x2, 0x0, 0x0, 0x1C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok186) {
  int f = -1853632013;

  my_decimal decimal_check = {{0x2, 0x0, 0x0, 0x801C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok187) {
  int f = 1439263036;

  my_decimal decimal_check = {{0x27AEF480, 0x192D, 0x0, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok188) {
  int f = -708220612;

  my_decimal decimal_check = {{0x27AEF480, 0x192D, 0x0, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok189) {
  int f = 1410992898;

  my_decimal decimal_check = {{0x2C0E77C0, 0x268, 0x0, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok190) {
  int f = -736490750;

  my_decimal decimal_check = {{0x2C0E77C0, 0x268, 0x0, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok191) {
  int f = 1591000072;

  my_decimal decimal_check = {{0xC4D38000, 0x6A5E03FC, 0x0, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok192) {
  int f = -556483576;

  my_decimal decimal_check = {{0xC4D38000, 0x6A5E03FC, 0x0, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok193) {
  int f = 1829679376;

  my_decimal decimal_check = {{0x38400000, 0xFD42C0C4, 0x8EB1103, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok194) {
  int f = -317804272;

  my_decimal decimal_check = {{0x38400000, 0xFD42C0C4, 0x8EB1103, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok195) {
  int f = 554401221;

  my_decimal decimal_check = {{0x481D85, 0x0, 0x0, 0x190000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok196) {
  int f = -1593082427;

  my_decimal decimal_check = {{0x481D85, 0x0, 0x0, 0x80190000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok197) {
  int f = 705297781;

  my_decimal decimal_check = {{0x12B37E, 0x0, 0x0, 0x130000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok198) {
  int f = -1442185867;

  my_decimal decimal_check = {{0x12B37E, 0x0, 0x0, 0x80130000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok199) {
  int f = 1836152841;

  my_decimal decimal_check = {{0x4C000000, 0xD4815AA5, 0xF1780A7, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok200) {
  int f = -311330807;

  my_decimal decimal_check = {{0x4C000000, 0xD4815AA5, 0xF1780A7, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok201) {
  int f = 316866950;

  my_decimal decimal_check = {{0xE, 0x0, 0x0, 0x1C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok202) {
  int f = -1830616698;

  my_decimal decimal_check = {{0xE, 0x0, 0x0, 0x801C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok203) {
  int f = 986964842;

  my_decimal decimal_check = {{0x2777A, 0x0, 0x0, 0x80000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok204) {
  int f = -1160518806;

  my_decimal decimal_check = {{0x2777A, 0x0, 0x0, 0x80080000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok205) {
  int f = 564428687;

  my_decimal decimal_check = {{0x11023C, 0x0, 0x0, 0x180000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok206) {
  int f = -1583054961;

  my_decimal decimal_check = {{0x11023C, 0x0, 0x0, 0x80180000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok207) {
  int f = 1152958580;

  my_decimal decimal_check = {{0x168D7E, 0x0, 0x0, 0x30000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok208) {
  int f = -994525068;

  my_decimal decimal_check = {{0x168D7E, 0x0, 0x0, 0x80030000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok209) {
  int f = 1331275965;

  my_decimal decimal_check = {{0xD9A8BBD0, 0x0, 0x0, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok210) {
  int f = -816207683;

  my_decimal decimal_check = {{0xD9A8BBD0, 0x0, 0x0, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok211) {
  int f = 1770637240;

  my_decimal decimal_check = {{0x13780000, 0x1E7FE2B2, 0x1138F7, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok212) {
  int f = -376846408;

  my_decimal decimal_check = {{0x13780000, 0x1E7FE2B2, 0x1138F7, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok213) {
  int f = 903906988;

  my_decimal decimal_check = {{0x28D75, 0x0, 0x0, 0xB0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok214) {
  int f = -1243576660;

  my_decimal decimal_check = {{0x28D75, 0x0, 0x0, 0x800B0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok215) {
  int f = 1817210535;

  my_decimal decimal_check = {{0xE3800000, 0xD819E2BC, 0x341BA83, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok216) {
  int f = -330273113;

  my_decimal decimal_check = {{0xE3800000, 0xD819E2BC, 0x341BA83, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok217) {
  int f = 586531744;

  my_decimal decimal_check = {{0x65A54B, 0x0, 0x0, 0x180000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok218) {
  int f = -1560951904;

  my_decimal decimal_check = {{0x65A54B, 0x0, 0x0, 0x80180000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok219) {
  int f = 1182119275;

  my_decimal decimal_check = {{0x17FEB7, 0x0, 0x0, 0x20000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok220) {
  int f = -965364373;

  my_decimal decimal_check = {{0x17FEB7, 0x0, 0x0, 0x80020000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok221) {
  int f = 1068154784;

  my_decimal decimal_check = {{0x145AD5, 0x0, 0x0, 0x60000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok222) {
  int f = -1079328864;

  my_decimal decimal_check = {{0x145AD5, 0x0, 0x0, 0x80060000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok223) {
  int f = 1210132585;

  my_decimal decimal_check = {{0x192E50, 0x0, 0x0, 0x10000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok224) {
  int f = -937351063;

  my_decimal decimal_check = {{0x192E50, 0x0, 0x0, 0x80010000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok225) {
  int f = 1485664887;

  my_decimal decimal_check = {{0xB2255C00, 0x46B93, 0x0, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok226) {
  int f = -661818761;

  my_decimal decimal_check = {{0xB2255C00, 0x46B93, 0x0, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok227) {
  int f = 711809596;

  my_decimal decimal_check = {{0x202AD1, 0x0, 0x0, 0x130000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok228) {
  int f = -1435674052;

  my_decimal decimal_check = {{0x202AD1, 0x0, 0x0, 0x80130000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok229) {
  int f = 1437543277;

  my_decimal decimal_check = {{0x6D925280, 0x15E5, 0x0, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok230) {
  int f = -709940371;

  my_decimal decimal_check = {{0x6D925280, 0x15E5, 0x0, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok231) {
  int f = 379195158;

  my_decimal decimal_check = {{0x9B9, 0x0, 0x0, 0x1C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok232) {
  int f = -1768288490;

  my_decimal decimal_check = {{0x9B9, 0x0, 0x0, 0x801C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok233) {
  int f = 1375055009;

  my_decimal decimal_check = {{0xB5941640, 0x1E, 0x0, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok234) {
  int f = -772428639;

  my_decimal decimal_check = {{0xB5941640, 0x1E, 0x0, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok235) {
  int f = 1376223787;

  my_decimal decimal_check = {{0xE08A97E0, 0x21, 0x0, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok236) {
  int f = -771259861;

  my_decimal decimal_check = {{0xE08A97E0, 0x21, 0x0, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok237) {
  int f = 446112901;

  my_decimal decimal_check = {{0x989D7, 0x0, 0x0, 0x1C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok238) {
  int f = -1701370747;

  my_decimal decimal_check = {{0x989D7, 0x0, 0x0, 0x801C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok239) {
  int f = 1835864499;

  my_decimal decimal_check = {{0x66000000, 0xBEE8B75C, 0xED11B2E, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok240) {
  int f = -311619149;

  my_decimal decimal_check = {{0x66000000, 0xBEE8B75C, 0xED11B2E, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok241) {
  int f = 354601253;

  my_decimal decimal_check = {{0x149, 0x0, 0x0, 0x1C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok242) {
  int f = -1792882395;

  my_decimal decimal_check = {{0x149, 0x0, 0x0, 0x801C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok243) {
  int f = 1537392255;

  my_decimal decimal_check = {{0x83754000, 0x1457CFE, 0x0, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok244) {
  int f = -610091393;

  my_decimal decimal_check = {{0x83754000, 0x1457CFE, 0x0, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok245) {
  int f = 1020821305;

  my_decimal decimal_check = {{0x285361, 0x0, 0x0, 0x80000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok246) {
  int f = -1126662343;

  my_decimal decimal_check = {{0x285361, 0x0, 0x0, 0x80080000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok247) {
  int f = 649251745;

  my_decimal decimal_check = {{0x12EE42, 0x0, 0x0, 0x150000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok248) {
  int f = -1498231903;

  my_decimal decimal_check = {{0x12EE42, 0x0, 0x0, 0x80150000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok249) {
  int f = 1485046610;

  my_decimal decimal_check = {{0x7A4DCC00, 0x4201A, 0x0, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok250) {
  int f = -662437038;

  my_decimal decimal_check = {{0x7A4DCC00, 0x4201A, 0x0, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok251) {
  int f = 769409716;

  my_decimal decimal_check = {{0x263589, 0x0, 0x0, 0x110000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok252) {
  int f = -1378073932;

  my_decimal decimal_check = {{0x263589, 0x0, 0x0, 0x80110000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok253) {
  int f = 1494907400;

  my_decimal decimal_check = {{0x995CD600, 0x9A7A0, 0x0, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok254) {
  int f = -652576248;

  my_decimal decimal_check = {{0x995CD600, 0x9A7A0, 0x0, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok255) {
  int f = 1538339488;

  my_decimal decimal_check = {{0xA0766C00, 0x1626540, 0x0, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok256) {
  int f = -609144160;

  my_decimal decimal_check = {{0xA0766C00, 0x1626540, 0x0, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok257) {
  int f = 650236087;

  my_decimal decimal_check = {{0x148560, 0x0, 0x0, 0x150000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok258) {
  int f = -1497247561;

  my_decimal decimal_check = {{0x148560, 0x0, 0x0, 0x80150000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok259) {
  int f = 738232563;

  my_decimal decimal_check = {{0x1BDF20, 0x0, 0x0, 0x120000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok260) {
  int f = -1409251085;

  my_decimal decimal_check = {{0x1BDF20, 0x0, 0x0, 0x80120000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok261) {
  int f = 1090056494;

  my_decimal decimal_check = {{0x76B471, 0x0, 0x0, 0x60000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok262) {
  int f = -1057427154;

  my_decimal decimal_check = {{0x76B471, 0x0, 0x0, 0x80060000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok263) {
  int f = 1524484784;

  my_decimal decimal_check = {{0x2BEC6400, 0x6EE557, 0x0, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok264) {
  int f = -622998864;

  my_decimal decimal_check = {{0x2BEC6400, 0x6EE557, 0x0, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok265) {
  int f = 1308422017;

  my_decimal decimal_check = {{0x1F9DF00C, 0x0, 0x0, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok266) {
  int f = -839061631;

  my_decimal decimal_check = {{0x1F9DF00C, 0x0, 0x0, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok267) {
  int f = 1415892191;

  my_decimal decimal_check = {{0x337E6FC0, 0x393, 0x0, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok268) {
  int f = -731591457;

  my_decimal decimal_check = {{0x337E6FC0, 0x393, 0x0, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok269) {
  int f = 559616998;

  my_decimal decimal_check = {{0x7142B2, 0x0, 0x0, 0x190000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok270) {
  int f = -1587866650;

  my_decimal decimal_check = {{0x7142B2, 0x0, 0x0, 0x80190000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok271) {
  int f = 536540764;

  my_decimal decimal_check = {{0x1037D3, 0x0, 0x0, 0x190000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok272) {
  int f = -1610942884;

  my_decimal decimal_check = {{0x1037D3, 0x0, 0x0, 0x80190000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok273) {
  int f = 1499482003;

  my_decimal decimal_check = {{0x2313C000, 0xE0479, 0x0, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok274) {
  int f = -648001645;

  my_decimal decimal_check = {{0x2313C000, 0xE0479, 0x0, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok275) {
  int f = 1334663268;

  my_decimal decimal_check = {{0x1AB0C640, 0x1, 0x0, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok276) {
  int f = -812820380;

  my_decimal decimal_check = {{0x1AB0C640, 0x1, 0x0, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok277) {
  int f = 948882102;

  my_decimal decimal_check = {{0x67E50E, 0x0, 0x0, 0xB0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok278) {
  int f = -1198601546;

  my_decimal decimal_check = {{0x67E50E, 0x0, 0x0, 0x800B0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok279) {
  int f = 340051160;

  my_decimal decimal_check = {{0x63, 0x0, 0x0, 0x1C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok280) {
  int f = -1807432488;

  my_decimal decimal_check = {{0x63, 0x0, 0x0, 0x801C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok281) {
  int f = 844880958;

  my_decimal decimal_check = {{0x13870C, 0x0, 0x0, 0xE0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok282) {
  int f = -1302602690;

  my_decimal decimal_check = {{0x13870C, 0x0, 0x0, 0x800E0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok283) {
  int f = 1072072542;

  my_decimal decimal_check = {{0x1B7B2E, 0x0, 0x0, 0x60000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok284) {
  int f = -1075411106;

  my_decimal decimal_check = {{0x1B7B2E, 0x0, 0x0, 0x80060000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok285) {
  int f = 659526787;

  my_decimal decimal_check = {{0x2BF4F1, 0x0, 0x0, 0x150000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok286) {
  int f = -1487956861;

  my_decimal decimal_check = {{0x2BF4F1, 0x0, 0x0, 0x80150000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok287) {
  int f = 1529939301;

  my_decimal decimal_check = {{0x7B393000, 0xB10564, 0x0, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok288) {
  int f = -617544347;

  my_decimal decimal_check = {{0x7B393000, 0xB10564, 0x0, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok289) {
  int f = 1100603924;

  my_decimal decimal_check = {{0x1D59D3, 0x0, 0x0, 0x50000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok290) {
  int f = -1046879724;

  my_decimal decimal_check = {{0x1D59D3, 0x0, 0x0, 0x80050000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok291) {
  int f = 922605440;

  my_decimal decimal_check = {{0x736F13, 0x0, 0x0, 0xC0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok292) {
  int f = -1224878208;

  my_decimal decimal_check = {{0x736F13, 0x0, 0x0, 0x800C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok293) {
  int f = 792597452;

  my_decimal decimal_check = {{0x1A60E7, 0x0, 0x0, 0x100000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok294) {
  int f = -1354886196;

  my_decimal decimal_check = {{0x1A60E7, 0x0, 0x0, 0x80100000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok295) {
  int f = 1148415297;

  my_decimal decimal_check = {{0x94936F, 0x0, 0x0, 0x40000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok296) {
  int f = -999068351;

  my_decimal decimal_check = {{0x94936F, 0x0, 0x0, 0x80040000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok297) {
  int f = 1559704409;

  my_decimal decimal_check = {{0x8923000, 0x7B99AC5, 0x0, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok298) {
  int f = -587779239;

  my_decimal decimal_check = {{0x8923000, 0x7B99AC5, 0x0, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok299) {
  int f = 1029501302;

  my_decimal decimal_check = {{0x524EC9, 0x0, 0x0, 0x80000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok300) {
  int f = -1117982346;

  my_decimal decimal_check = {{0x524EC9, 0x0, 0x0, 0x80080000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok301) {
  int f = 1782318321;

  my_decimal decimal_check = {{0x84580000, 0x6567A044, 0x2F013C, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok302) {
  int f = -365165327;

  my_decimal decimal_check = {{0x84580000, 0x6567A044, 0x2F013C, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok303) {
  int f = 459547759;

  my_decimal decimal_check = {{0x1CCBAD, 0x0, 0x0, 0x1C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok304) {
  int f = -1687935889;

  my_decimal decimal_check = {{0x1CCBAD, 0x0, 0x0, 0x801C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok305) {
  int f = 1666272970;

  my_decimal decimal_check = {{0xD7A58000, 0x4ECA7DCB, 0xD1, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok306) {
  int f = -481210678;

  my_decimal decimal_check = {{0xD7A58000, 0x4ECA7DCB, 0xD1, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok307) {
  int f = 435806540;

  my_decimal decimal_check = {{0x64ED, 0x0, 0x0, 0x1B0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok308) {
  int f = -1711677108;

  my_decimal decimal_check = {{0x64ED, 0x0, 0x0, 0x801B0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok309) {
  int f = 1470866542;

  my_decimal decimal_check = {{0xDAFD3600, 0x15748, 0x0, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok310) {
  int f = -676617106;

  my_decimal decimal_check = {{0xDAFD3600, 0x15748, 0x0, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok311) {
  int f = 329070737;

  my_decimal decimal_check = {{0x4, 0x0, 0x0, 0x1B0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok312) {
  int f = -1818412911;

  my_decimal decimal_check = {{0x4, 0x0, 0x0, 0x801B0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok313) {
  int f = 1532516795;

  my_decimal decimal_check = {{0xEA0C5400, 0xD859B9, 0x0, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok314) {
  int f = -614966853;

  my_decimal decimal_check = {{0xEA0C5400, 0xD859B9, 0x0, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok315) {
  int f = 1473161592;

  my_decimal decimal_check = {{0xEF0A0100, 0x19D52, 0x0, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok316) {
  int f = -674322056;

  my_decimal decimal_check = {{0xEF0A0100, 0x19D52, 0x0, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok317) {
  int f = 1217508012;

  my_decimal decimal_check = {{0x2D87D6, 0x0, 0x0, 0x10000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok318) {
  int f = -929975636;

  my_decimal decimal_check = {{0x2D87D6, 0x0, 0x0, 0x80010000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok319) {
  int f = 559569812;

  my_decimal decimal_check = {{0x70E368, 0x0, 0x0, 0x190000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok320) {
  int f = -1587913836;

  my_decimal decimal_check = {{0x70E368, 0x0, 0x0, 0x80190000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok321) {
  int f = 1842103099;

  my_decimal decimal_check = {{0x18E00000, 0x59EE2CE, 0x1988674E, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok322) {
  int f = -305380549;

  my_decimal decimal_check = {{0x18E00000, 0x59EE2CE, 0x1988674E, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok323) {
  int f = 923552150;

  my_decimal decimal_check = {{0x7F9737, 0x0, 0x0, 0xC0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok324) {
  int f = -1223931498;

  my_decimal decimal_check = {{0x7F9737, 0x0, 0x0, 0x800C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok325) {
  int f = 1164678010;

  my_decimal decimal_check = {{0x398381, 0x0, 0x0, 0x30000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok326) {
  int f = -982805638;

  my_decimal decimal_check = {{0x398381, 0x0, 0x0, 0x80030000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok327) {
  int f = 1406283831;

  my_decimal decimal_check = {{0x606CB000, 0x1A4, 0x0, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok328) {
  int f = -741199817;

  my_decimal decimal_check = {{0x606CB000, 0x1A4, 0x0, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok329) {
  int f = 1658436039;

  my_decimal decimal_check = {{0x2C508000, 0xDCE343C9, 0x6C, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok330) {
  int f = -489047609;

  my_decimal decimal_check = {{0x2C508000, 0xDCE343C9, 0x6C, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok331) {
  int f = 1110043257;

  my_decimal decimal_check = {{0x40D15A, 0x0, 0x0, 0x50000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok332) {
  int f = -1037440391;

  my_decimal decimal_check = {{0x40D15A, 0x0, 0x0, 0x80050000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok333) {
  int f = 1459695219;

  my_decimal decimal_check = {{0x7320AD00, 0x812E, 0x0, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok334) {
  int f = -687788429;

  my_decimal decimal_check = {{0x7320AD00, 0x812E, 0x0, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok335) {
  int f = 1636145954;

  my_decimal decimal_check = {{0x479A0000, 0xB364228D, 0x10, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok336) {
  int f = -511337694;

  my_decimal decimal_check = {{0x479A0000, 0xB364228D, 0x10, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok337) {
  int f = 1718565856;

  my_decimal decimal_check = {{0xCDA60000, 0xF7B1A7FD, 0x3BCE, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok338) {
  int f = -428917792;

  my_decimal decimal_check = {{0xCDA60000, 0xF7B1A7FD, 0x3BCE, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok339) {
  int f = 907094684;

  my_decimal decimal_check = {{0x2101CD, 0x0, 0x0, 0xC0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok340) {
  int f = -1240388964;

  my_decimal decimal_check = {{0x2101CD, 0x0, 0x0, 0x800C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok341) {
  int f = 437697806;

  my_decimal decimal_check = {{0x79C4, 0x0, 0x0, 0x1B0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok342) {
  int f = -1709785842;

  my_decimal decimal_check = {{0x79C4, 0x0, 0x0, 0x801B0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok343) {
  int f = 1589987783;

  my_decimal decimal_check = {{0x9B958000, 0x62A4E345, 0x0, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok344) {
  int f = -557495865;

  my_decimal decimal_check = {{0x9B958000, 0x62A4E345, 0x0, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok345) {
  int f = 425045247;

  my_decimal decimal_check = {{0x1AF84, 0x0, 0x0, 0x1C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok346) {
  int f = -1722438401;

  my_decimal decimal_check = {{0x1AF84, 0x0, 0x0, 0x801C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok347) {
  int f = 1672435000;

  my_decimal decimal_check = {{0x745D0000, 0xAA70EAAA, 0x15E, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok348) {
  int f = -475048648;

  my_decimal decimal_check = {{0x745D0000, 0xAA70EAAA, 0x15E, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok349) {
  int f = 997075711;

  my_decimal decimal_check = {{0x3773EB, 0x0, 0x0, 0x90000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok350) {
  int f = -1150407937;

  my_decimal decimal_check = {{0x3773EB, 0x0, 0x0, 0x80090000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok351) {
  int f = 848901969;

  my_decimal decimal_check = {{0x2B8BF, 0x0, 0x0, 0xD0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok352) {
  int f = -1298581679;

  my_decimal decimal_check = {{0x2B8BF, 0x0, 0x0, 0x800D0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok353) {
  int f = 883957638;

  my_decimal decimal_check = {{0x320EA5, 0x0, 0x0, 0xD0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok354) {
  int f = -1263526010;

  my_decimal decimal_check = {{0x320EA5, 0x0, 0x0, 0x800D0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok355) {
  int f = 1040478046;

  my_decimal decimal_check = {{0x13BBFF, 0x0, 0x0, 0x70000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok356) {
  int f = -1107005602;

  my_decimal decimal_check = {{0x13BBFF, 0x0, 0x0, 0x80070000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok357) {
  int f = 1106632470;

  my_decimal decimal_check = {{0x2EE571, 0x0, 0x0, 0x50000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok358) {
  int f = -1040851178;

  my_decimal decimal_check = {{0x2EE571, 0x0, 0x0, 0x80050000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok359) {
  int f = 576921948;

  my_decimal decimal_check = {{0x4B26B, 0x0, 0x0, 0x170000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok360) {
  int f = -1570561700;

  my_decimal decimal_check = {{0x4B26B, 0x0, 0x0, 0x80170000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok361) {
  int f = 1543185522;

  my_decimal decimal_check = {{0x1921B000, 0x1F648E8, 0x0, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok362) {
  int f = -604298126;

  my_decimal decimal_check = {{0x1921B000, 0x1F648E8, 0x0, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok363) {
  int f = 344195665;

  my_decimal decimal_check = {{0x85, 0x0, 0x0, 0x1C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok364) {
  int f = -1803287983;

  my_decimal decimal_check = {{0x85, 0x0, 0x0, 0x801C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok365) {
  int f = 1536619729;

  my_decimal decimal_check = {{0xF5F400, 0x12DE9A2, 0x0, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok366) {
  int f = -610863919;

  my_decimal decimal_check = {{0xF5F400, 0x12DE9A2, 0x0, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok367) {
  int f = 1178719435;

  my_decimal decimal_check = {{0x1E494, 0x0, 0x0, 0x10000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok368) {
  int f = -968764213;

  my_decimal decimal_check = {{0x1E494, 0x0, 0x0, 0x80010000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok369) {
  int f = 513898892;

  my_decimal decimal_check = {{0x1A1671, 0x0, 0x0, 0x1A0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok370) {
  int f = -1633584756;

  my_decimal decimal_check = {{0x1A1671, 0x0, 0x0, 0x801A0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok371) {
  int f = 628212297;

  my_decimal decimal_check = {{0x1FFF1C, 0x0, 0x0, 0x160000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok372) {
  int f = -1519271351;

  my_decimal decimal_check = {{0x1FFF1C, 0x0, 0x0, 0x80160000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok373) {
  int f = 1424585073;

  my_decimal decimal_check = {{0x8B89B740, 0x74B, 0x0, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok374) {
  int f = -722898575;

  my_decimal decimal_check = {{0x8B89B740, 0x74B, 0x0, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok375) {
  int f = 870319039;

  my_decimal decimal_check = {{0xFEACD, 0x0, 0x0, 0xD0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok376) {
  int f = -1277164609;

  my_decimal decimal_check = {{0xFEACD, 0x0, 0x0, 0x800D0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok377) {
  int f = 1494621691;

  my_decimal decimal_check = {{0xA721B000, 0x961DF, 0x0, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok378) {
  int f = -652861957;

  my_decimal decimal_check = {{0xA721B000, 0x961DF, 0x0, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok379) {
  int f = 1780142304;

  my_decimal decimal_check = {{0xDD800000, 0xFE325BBC, 0x26B437, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok380) {
  int f = -367341344;

  my_decimal decimal_check = {{0xDD800000, 0xFE325BBC, 0x26B437, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok381) {
  int f = 570397227;

  my_decimal decimal_check = {{0x1A6CE8, 0x0, 0x0, 0x180000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok382) {
  int f = -1577086421;

  my_decimal decimal_check = {{0x1A6CE8, 0x0, 0x0, 0x80180000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok383) {
  int f = 1584305061;

  my_decimal decimal_check = {{0x95FD8000, 0x3BA4E8E1, 0x0, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok384) {
  int f = -563178587;

  my_decimal decimal_check = {{0x95FD8000, 0x3BA4E8E1, 0x0, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok385) {
  int f = 1675139906;

  my_decimal decimal_check = {{0xEFD40000, 0x368267EA, 0x1B1, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok386) {
  int f = -472343742;

  my_decimal decimal_check = {{0xEFD40000, 0x368267EA, 0x1B1, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok387) {
  int f = 387015853;

  my_decimal decimal_check = {{0x125A, 0x0, 0x0, 0x1C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok388) {
  int f = -1760467795;

  my_decimal decimal_check = {{0x125A, 0x0, 0x0, 0x801C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok389) {
  int f = 1624602407;

  my_decimal decimal_check = {{0x70D40000, 0xABB90CD4, 0x6, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok390) {
  int f = -522881241;

  my_decimal decimal_check = {{0x70D40000, 0xABB90CD4, 0x6, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok391) {
  int f = 1479313458;

  my_decimal decimal_check = {{0xC6F40600, 0x2B220, 0x0, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok392) {
  int f = -668170190;

  my_decimal decimal_check = {{0xC6F40600, 0x2B220, 0x0, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok393) {
  int f = 1465379182;

  my_decimal decimal_check = {{0x6F9E5800, 0xD7E9, 0x0, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok394) {
  int f = -682104466;

  my_decimal decimal_check = {{0x6F9E5800, 0xD7E9, 0x0, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok395) {
  int f = 811227606;

  my_decimal decimal_check = {{0xC1EF4, 0x0, 0x0, 0xF0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok396) {
  int f = -1336256042;

  my_decimal decimal_check = {{0xC1EF4, 0x0, 0x0, 0x800F0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok397) {
  int f = 1437876521;

  my_decimal decimal_check = {{0x24DFA580, 0x1688, 0x0, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok398) {
  int f = -709607127;

  my_decimal decimal_check = {{0x24DFA580, 0x1688, 0x0, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok399) {
  int f = 1556933925;

  my_decimal decimal_check = {{0x4A00B800, 0x6676926, 0x0, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok400) {
  int f = -590549723;

  my_decimal decimal_check = {{0x4A00B800, 0x6676926, 0x0, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok401) {
  int f = 1012506263;

  my_decimal decimal_check = {{0x144474, 0x0, 0x0, 0x80000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok402) {
  int f = -1134977385;

  my_decimal decimal_check = {{0x144474, 0x0, 0x0, 0x80080000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok403) {
  int f = 714436148;

  my_decimal decimal_check = {{0x2880D3, 0x0, 0x0, 0x130000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok404) {
  int f = -1433047500;

  my_decimal decimal_check = {{0x2880D3, 0x0, 0x0, 0x80130000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok405) {
  int f = 996222699;

  my_decimal decimal_check = {{0x346C1B, 0x0, 0x0, 0x90000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok406) {
  int f = -1151260949;

  my_decimal decimal_check = {{0x346C1B, 0x0, 0x0, 0x80090000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok407) {
  int f = 650313287;

  my_decimal decimal_check = {{0x14A54E, 0x0, 0x0, 0x150000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok408) {
  int f = -1497170361;

  my_decimal decimal_check = {{0x14A54E, 0x0, 0x0, 0x80150000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok409) {
  int f = 581118450;

  my_decimal decimal_check = {{0x437BA5, 0x0, 0x0, 0x180000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok410) {
  int f = -1566365198;

  my_decimal decimal_check = {{0x437BA5, 0x0, 0x0, 0x80180000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok411) {
  int f = 1750315188;

  my_decimal decimal_check = {{0xF2700000, 0xD426D6A2, 0x34EC2, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok412) {
  int f = -397168460;

  my_decimal decimal_check = {{0xF2700000, 0xD426D6A2, 0x34EC2, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok413) {
  int f = 1600875770;

  my_decimal decimal_check = {{0x61212000, 0xEB6CFB1D, 0x0, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok414) {
  int f = -546607878;

  my_decimal decimal_check = {{0x61212000, 0xEB6CFB1D, 0x0, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok415) {
  int f = 1551822620;

  my_decimal decimal_check = {{0x36CF3000, 0x3FBBC72, 0x0, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok416) {
  int f = -595661028;

  my_decimal decimal_check = {{0x36CF3000, 0x3FBBC72, 0x0, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok417) {
  int f = 1005104087;

  my_decimal decimal_check = {{0x6C5893, 0x0, 0x0, 0x90000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok418) {
  int f = -1142379561;

  my_decimal decimal_check = {{0x6C5893, 0x0, 0x0, 0x80090000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok419) {
  int f = 628056743;

  my_decimal decimal_check = {{0x1FAEB1, 0x0, 0x0, 0x160000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok420) {
  int f = -1519426905;

  my_decimal decimal_check = {{0x1FAEB1, 0x0, 0x0, 0x80160000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok421) {
  int f = 1011486357;

  my_decimal decimal_check = {{0x12D16A, 0x0, 0x0, 0x80000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok422) {
  int f = -1135997291;

  my_decimal decimal_check = {{0x12D16A, 0x0, 0x0, 0x80080000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok423) {
  int f = 481353703;

  my_decimal decimal_check = {{0x11DC1A, 0x0, 0x0, 0x1B0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok424) {
  int f = -1666129945;

  my_decimal decimal_check = {{0x11DC1A, 0x0, 0x0, 0x801B0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok425) {
  int f = 364232684;

  my_decimal decimal_check = {{0x2DE, 0x0, 0x0, 0x1C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok426) {
  int f = -1783250964;

  my_decimal decimal_check = {{0x2DE, 0x0, 0x0, 0x801C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok427) {
  int f = 646678234;

  my_decimal decimal_check = {{0x93BACE, 0x0, 0x0, 0x160000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok428) {
  int f = -1500805414;

  my_decimal decimal_check = {{0x93BACE, 0x0, 0x0, 0x80160000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok429) {
  int f = 582757548;

  my_decimal decimal_check = {{0x7C860, 0x0, 0x0, 0x170000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok430) {
  int f = -1564726100;

  my_decimal decimal_check = {{0x7C860, 0x0, 0x0, 0x80170000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok431) {
  int f = 1487222388;

  my_decimal decimal_check = {{0x8B822400, 0x529B3, 0x0, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok432) {
  int f = -660261260;

  my_decimal decimal_check = {{0x8B822400, 0x529B3, 0x0, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok433) {
  int f = 944917071;

  my_decimal decimal_check = {{0x4C80CF, 0x0, 0x0, 0xB0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok434) {
  int f = -1202566577;

  my_decimal decimal_check = {{0x4C80CF, 0x0, 0x0, 0x800B0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok435) {
  int f = 1543943225;

  my_decimal decimal_check = {{0x797FC000, 0x21AD0E0, 0x0, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok436) {
  int f = -603540423;

  my_decimal decimal_check = {{0x797FC000, 0x21AD0E0, 0x0, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok437) {
  int f = 881699893;

  my_decimal decimal_check = {{0x28440B, 0x0, 0x0, 0xD0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok438) {
  int f = -1265783755;

  my_decimal decimal_check = {{0x28440B, 0x0, 0x0, 0x800D0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok439) {
  int f = 1036315911;

  my_decimal decimal_check = {{0x92B8A2, 0x0, 0x0, 0x80000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok440) {
  int f = -1111167737;

  my_decimal decimal_check = {{0x92B8A2, 0x0, 0x0, 0x80080000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok441) {
  int f = 1251831443;

  my_decimal decimal_check = {{0x4EB74A, 0x0, 0x0, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok442) {
  int f = -895652205;

  my_decimal decimal_check = {{0x4EB74A, 0x0, 0x0, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok443) {
  int f = 603856958;

  my_decimal decimal_check = {{0x2A0AA7, 0x0, 0x0, 0x170000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok444) {
  int f = -1543626690;

  my_decimal decimal_check = {{0x2A0AA7, 0x0, 0x0, 0x80170000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok445) {
  int f = 1699508913;

  my_decimal decimal_check = {{0x43400000, 0x2B05E443, 0xCC7, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok446) {
  int f = -447974735;

  my_decimal decimal_check = {{0x43400000, 0x2B05E443, 0xCC7, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok447) {
  int f = 1496408203;

  my_decimal decimal_check = {{0x9D64DE00, 0xB1608, 0x0, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok448) {
  int f = -651075445;

  my_decimal decimal_check = {{0x9D64DE00, 0xB1608, 0x0, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok449) {
  int f = 342789627;

  my_decimal decimal_check = {{0xC, 0x0, 0x0, 0x1B0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok450) {
  int f = -1804694021;

  my_decimal decimal_check = {{0xC, 0x0, 0x0, 0x801B0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok451) {
  int f = 419766003;

  my_decimal decimal_check = {{0x10CD6, 0x0, 0x0, 0x1C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok452) {
  int f = -1727717645;

  my_decimal decimal_check = {{0x10CD6, 0x0, 0x0, 0x801C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok453) {
  int f = 1481221136;

  my_decimal decimal_check = {{0x3EBF4300, 0x32690, 0x0, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok454) {
  int f = -666262512;

  my_decimal decimal_check = {{0x3EBF4300, 0x32690, 0x0, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok455) {
  int f = 1596014044;

  my_decimal decimal_check = {{0xCEEF8000, 0xA13DD7E6, 0x0, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok456) {
  int f = -551469604;

  my_decimal decimal_check = {{0xCEEF8000, 0xA13DD7E6, 0x0, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok457) {
  int f = 1614205851;

  my_decimal decimal_check = {{0x800B4000, 0xDB4E7083, 0x2, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok458) {
  int f = -533277797;

  my_decimal decimal_check = {{0x800B4000, 0xDB4E7083, 0x2, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok459) {
  int f = 1067358295;

  my_decimal decimal_check = {{0x12E7F0, 0x0, 0x0, 0x60000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok460) {
  int f = -1080125353;

  my_decimal decimal_check = {{0x12E7F0, 0x0, 0x0, 0x80060000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok461) {
  int f = 949896045;

  my_decimal decimal_check = {{0x7326DA, 0x0, 0x0, 0xB0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok462) {
  int f = -1197587603;

  my_decimal decimal_check = {{0x7326DA, 0x0, 0x0, 0x800B0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok463) {
  int f = 1630714683;

  my_decimal decimal_check = {{0x60460000, 0x2BB38CA1, 0xB, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok464) {
  int f = -516768965;

  my_decimal decimal_check = {{0x60460000, 0x2BB38CA1, 0xB, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok465) {
  int f = 1168974783;

  my_decimal decimal_check = {{0x548A74, 0x0, 0x0, 0x30000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok466) {
  int f = -978508865;

  my_decimal decimal_check = {{0x548A74, 0x0, 0x0, 0x80030000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok467) {
  int f = 1107683195;

  my_decimal decimal_check = {{0x331496, 0x0, 0x0, 0x50000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok468) {
  int f = -1039800453;

  my_decimal decimal_check = {{0x331496, 0x0, 0x0, 0x80050000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok469) {
  int f = 1130788944;

  my_decimal decimal_check = {{0x5A07, 0x0, 0x0, 0x20000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok470) {
  int f = -1016694704;

  my_decimal decimal_check = {{0x5A07, 0x0, 0x0, 0x80020000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok471) {
  int f = 826452936;

  my_decimal decimal_check = {{0x2B39C4, 0x0, 0x0, 0xF0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok472) {
  int f = -1321030712;

  my_decimal decimal_check = {{0x2B39C4, 0x0, 0x0, 0x800F0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok473) {
  int f = 914346224;

  my_decimal decimal_check = {{0x3A2A76, 0x0, 0x0, 0xC0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok474) {
  int f = -1233137424;

  my_decimal decimal_check = {{0x3A2A76, 0x0, 0x0, 0x800C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok475) {
  int f = 884010004;

  my_decimal decimal_check = {{0x3248C8, 0x0, 0x0, 0xD0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok476) {
  int f = -1263473644;

  my_decimal decimal_check = {{0x3248C8, 0x0, 0x0, 0x800D0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok477) {
  int f = 603693155;

  my_decimal decimal_check = {{0x429AE, 0x0, 0x0, 0x160000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok478) {
  int f = -1543790493;

  my_decimal decimal_check = {{0x429AE, 0x0, 0x0, 0x80160000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok479) {
  int f = 329956963;

  my_decimal decimal_check = {{0x2B, 0x0, 0x0, 0x1C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok480) {
  int f = -1817526685;

  my_decimal decimal_check = {{0x2B, 0x0, 0x0, 0x801C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok481) {
  int f = 585321177;

  my_decimal decimal_check = {{0x5E0184, 0x0, 0x0, 0x180000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok482) {
  int f = -1562162471;

  my_decimal decimal_check = {{0x5E0184, 0x0, 0x0, 0x80180000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok483) {
  int f = 1430747103;

  my_decimal decimal_check = {{0x7DBA4180, 0xC77, 0x0, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok484) {
  int f = -716736545;

  my_decimal decimal_check = {{0x7DBA4180, 0xC77, 0x0, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok485) {
  int f = 1431588210;

  my_decimal decimal_check = {{0xD73C7200, 0xD44, 0x0, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok486) {
  int f = -715895438;

  my_decimal decimal_check = {{0xD73C7200, 0xD44, 0x0, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok487) {
  int f = 872657118;

  my_decimal decimal_check = {{0x12B6E3, 0x0, 0x0, 0xD0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok488) {
  int f = -1274826530;

  my_decimal decimal_check = {{0x12B6E3, 0x0, 0x0, 0x800D0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok489) {
  int f = 766359509;

  my_decimal decimal_check = {{0x1E22A2, 0x0, 0x0, 0x110000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok490) {
  int f = -1381124139;

  my_decimal decimal_check = {{0x1E22A2, 0x0, 0x0, 0x80110000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok491) {
  int f = 1647028174;

  my_decimal decimal_check = {{0xC750000, 0xE9F37736, 0x2A, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok492) {
  int f = -500455474;

  my_decimal decimal_check = {{0xC750000, 0xE9F37736, 0x2A, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok493) {
  int f = 1209387331;

  my_decimal decimal_check = {{0x25725, 0x0, 0x0, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok494) {
  int f = -938096317;

  my_decimal decimal_check = {{0x25725, 0x0, 0x0, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok495) {
  int f = 1026165234;

  my_decimal decimal_check = {{0x3F582B, 0x0, 0x0, 0x80000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok496) {
  int f = -1121318414;

  my_decimal decimal_check = {{0x3F582B, 0x0, 0x0, 0x80080000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok497) {
  int f = 1370631563;

  my_decimal decimal_check = {{0x45B154D0, 0x16, 0x0, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok498) {
  int f = -776852085;

  my_decimal decimal_check = {{0x45B154D0, 0x16, 0x0, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok499) {
  int f = 1686976061;

  my_decimal decimal_check = {{0x488F0000, 0xB1DB5E3D, 0x469, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok500) {
  int f = -460507587;

  my_decimal decimal_check = {{0x488F0000, 0xB1DB5E3D, 0x469, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok501) {
  int f = 532099950;

  my_decimal decimal_check = {{0xBD6CE, 0x0, 0x0, 0x190000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok502) {
  int f = -1615383698;

  my_decimal decimal_check = {{0xBD6CE, 0x0, 0x0, 0x80190000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok503) {
  int f = 1479420607;

  my_decimal decimal_check = {{0xFE128900, 0x2B8AA, 0x0, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok504) {
  int f = -668063041;

  my_decimal decimal_check = {{0xFE128900, 0x2B8AA, 0x0, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok505) {
  int f = 1487512363;

  my_decimal decimal_check = {{0x50487400, 0x54D19, 0x0, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok506) {
  int f = -659971285;

  my_decimal decimal_check = {{0x50487400, 0x54D19, 0x0, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok507) {
  int f = 407652779;

  my_decimal decimal_check = {{0x6724, 0x0, 0x0, 0x1C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok508) {
  int f = -1739830869;

  my_decimal decimal_check = {{0x6724, 0x0, 0x0, 0x801C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok509) {
  int f = 302806045;

  my_decimal decimal_check = {{0x4, 0x0, 0x0, 0x1C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok510) {
  int f = -1844677603;

  my_decimal decimal_check = {{0x4, 0x0, 0x0, 0x801C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok511) {
  int f = 414741475;

  my_decimal decimal_check = {{0x12A0, 0x0, 0x0, 0x1B0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok512) {
  int f = -1732742173;

  my_decimal decimal_check = {{0x12A0, 0x0, 0x0, 0x801B0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok513) {
  int f = 572911885;

  my_decimal decimal_check = {{0x2250E0, 0x0, 0x0, 0x180000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok514) {
  int f = -1574571763;

  my_decimal decimal_check = {{0x2250E0, 0x0, 0x0, 0x80180000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok515) {
  int f = 1057799146;

  my_decimal decimal_check = {{0x53E24F, 0x0, 0x0, 0x70000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok516) {
  int f = -1089684502;

  my_decimal decimal_check = {{0x53E24F, 0x0, 0x0, 0x80070000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok517) {
  int f = 313615830;

  my_decimal decimal_check = {{0xB, 0x0, 0x0, 0x1C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok518) {
  int f = -1833867818;

  my_decimal decimal_check = {{0xB, 0x0, 0x0, 0x801C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok519) {
  int f = 1727725705;

  my_decimal decimal_check = {{0x510E0000, 0x441708AD, 0x7D80, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok520) {
  int f = -419757943;

  my_decimal decimal_check = {{0x510E0000, 0x441708AD, 0x7D80, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok521) {
  int f = 1835467310;

  my_decimal decimal_check = {{0xABE00000, 0xEBFC9CC1, 0xE7022F9, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok522) {
  int f = -312016338;

  my_decimal decimal_check = {{0xABE00000, 0xEBFC9CC1, 0xE7022F9, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok523) {
  int f = 1562846377;

  my_decimal decimal_check = {{0xF88F8800, 0xA724A96, 0x0, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok524) {
  int f = -584637271;

  my_decimal decimal_check = {{0xF88F8800, 0xA724A96, 0x0, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok525) {
  int f = 1495601419;

  my_decimal decimal_check = {{0xB7146400, 0xA5110, 0x0, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok526) {
  int f = -651882229;

  my_decimal decimal_check = {{0xB7146400, 0xA5110, 0x0, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok527) {
  int f = 1487341834;

  my_decimal decimal_check = {{0x492C6400, 0x53848, 0x0, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok528) {
  int f = -660141814;

  my_decimal decimal_check = {{0x492C6400, 0x53848, 0x0, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok529) {
  int f = 1227756740;

  my_decimal decimal_check = {{0x6CCCFA, 0x0, 0x0, 0x10000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok530) {
  int f = -919726908;

  my_decimal decimal_check = {{0x6CCCFA, 0x0, 0x0, 0x80010000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok531) {
  int f = 947144932;

  my_decimal decimal_check = {{0x58DECA, 0x0, 0x0, 0xB0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok532) {
  int f = -1200338716;

  my_decimal decimal_check = {{0x58DECA, 0x0, 0x0, 0x800B0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok533) {
  int f = 870363570;

  my_decimal decimal_check = {{0xFF72A, 0x0, 0x0, 0xD0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok534) {
  int f = -1277120078;

  my_decimal decimal_check = {{0xFF72A, 0x0, 0x0, 0x800D0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok535) {
  int f = 814534138;

  my_decimal decimal_check = {{0xFA1E8, 0x0, 0x0, 0xF0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok536) {
  int f = -1332949510;

  my_decimal decimal_check = {{0xFA1E8, 0x0, 0x0, 0x800F0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok537) {
  int f = 1082262548;

  my_decimal decimal_check = {{0x3DFF16, 0x0, 0x0, 0x60000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok538) {
  int f = -1065221100;

  my_decimal decimal_check = {{0x3DFF16, 0x0, 0x0, 0x80060000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok539) {
  int f = 1322677870;

  my_decimal decimal_check = {{0x6B3B37B8, 0x0, 0x0, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok540) {
  int f = -824805778;

  my_decimal decimal_check = {{0x6B3B37B8, 0x0, 0x0, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok541) {
  int f = 570579725;

  my_decimal decimal_check = {{0x1AF4F9, 0x0, 0x0, 0x180000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok542) {
  int f = -1576903923;

  my_decimal decimal_check = {{0x1AF4F9, 0x0, 0x0, 0x80180000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok543) {
  int f = 1618891716;

  my_decimal decimal_check = {{0xD665E000, 0xF94F127F, 0x3, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok544) {
  int f = -528591932;

  my_decimal decimal_check = {{0xD665E000, 0xF94F127F, 0x3, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok545) {
  int f = 954730848;

  my_decimal decimal_check = {{0x10E205, 0x0, 0x0, 0xA0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok546) {
  int f = -1192752800;

  my_decimal decimal_check = {{0x10E205, 0x0, 0x0, 0x800A0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok547) {
  int f = 557835101;

  my_decimal decimal_check = {{0x63342F, 0x0, 0x0, 0x190000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok548) {
  int f = -1589648547;

  my_decimal decimal_check = {{0x63342F, 0x0, 0x0, 0x80190000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok549) {
  int f = 448698296;

  my_decimal decimal_check = {{0xC0731, 0x0, 0x0, 0x1C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok550) {
  int f = -1698785352;

  my_decimal decimal_check = {{0xC0731, 0x0, 0x0, 0x801C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok551) {
  int f = 1379068990;

  my_decimal decimal_check = {{0xBB0F40A0, 0x2C, 0x0, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok552) {
  int f = -768414658;

  my_decimal decimal_check = {{0xBB0F40A0, 0x2C, 0x0, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok553) {
  int f = 730253398;

  my_decimal decimal_check = {{0x9221AD, 0x0, 0x0, 0x130000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok554) {
  int f = -1417230250;

  my_decimal decimal_check = {{0x9221AD, 0x0, 0x0, 0x80130000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok555) {
  int f = 824555358;

  my_decimal decimal_check = {{0x24CBE1, 0x0, 0x0, 0xF0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok556) {
  int f = -1322928290;

  my_decimal decimal_check = {{0x24CBE1, 0x0, 0x0, 0x800F0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok557) {
  int f = 727752256;

  my_decimal decimal_check = {{0xC2D34, 0x0, 0x0, 0x120000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok558) {
  int f = -1419731392;

  my_decimal decimal_check = {{0xC2D34, 0x0, 0x0, 0x80120000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok559) {
  int f = 1814027192;

  my_decimal decimal_check = {{0x66000000, 0x7B44D9C0, 0x27F6EE0, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok560) {
  int f = -333456456;

  my_decimal decimal_check = {{0x66000000, 0x7B44D9C0, 0x27F6EE0, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok561) {
  int f = 768363322;

  my_decimal decimal_check = {{0x237078, 0x0, 0x0, 0x110000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok562) {
  int f = -1379120326;

  my_decimal decimal_check = {{0x237078, 0x0, 0x0, 0x80110000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok563) {
  int f = 461148072;

  my_decimal decimal_check = {{0x1FE0B1, 0x0, 0x0, 0x1C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok564) {
  int f = -1686335576;

  my_decimal decimal_check = {{0x1FE0B1, 0x0, 0x0, 0x801C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok565) {
  int f = 1791755739;

  my_decimal decimal_check = {{0x46B00000, 0xB2F27F22, 0x6602EF, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok566) {
  int f = -355727909;

  my_decimal decimal_check = {{0x46B00000, 0xB2F27F22, 0x6602EF, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok567) {
  int f = 1485214440;

  my_decimal decimal_check = {{0x38883800, 0x43497, 0x0, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok568) {
  int f = -662269208;

  my_decimal decimal_check = {{0x38883800, 0x43497, 0x0, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok569) {
  int f = 541350515;

  my_decimal decimal_check = {{0x1960C9, 0x0, 0x0, 0x190000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok570) {
  int f = -1606133133;

  my_decimal decimal_check = {{0x1960C9, 0x0, 0x0, 0x80190000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok571) {
  int f = 1036848696;

  my_decimal decimal_check = {{0xF4720, 0x0, 0x0, 0x70000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok572) {
  int f = -1110634952;

  my_decimal decimal_check = {{0xF4720, 0x0, 0x0, 0x80070000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok573) {
  int f = 1709575578;

  my_decimal decimal_check = {{0x4DA40000, 0xB341F3F1, 0x1CC1, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok574) {
  int f = -437908070;

  my_decimal decimal_check = {{0x4DA40000, 0xB341F3F1, 0x1CC1, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok575) {
  int f = 759025566;

  my_decimal decimal_check = {{0x1076A7, 0x0, 0x0, 0x110000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok576) {
  int f = -1388458082;

  my_decimal decimal_check = {{0x1076A7, 0x0, 0x0, 0x80110000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok577) {
  int f = 810969321;

  my_decimal decimal_check = {{0x770577, 0x0, 0x0, 0x100000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok578) {
  int f = -1336514327;

  my_decimal decimal_check = {{0x770577, 0x0, 0x0, 0x80100000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok579) {
  int f = 705362423;

  my_decimal decimal_check = {{0x12D5B7, 0x0, 0x0, 0x130000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok580) {
  int f = -1442121225;

  my_decimal decimal_check = {{0x12D5B7, 0x0, 0x0, 0x80130000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok581) {
  int f = 1811525701;

  my_decimal decimal_check = {{0x47B00000, 0x41AD4854, 0x1F3608B, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok582) {
  int f = -335957947;

  my_decimal decimal_check = {{0x47B00000, 0x41AD4854, 0x1F3608B, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok583) {
  int f = 1414531729;

  my_decimal decimal_check = {{0x2A45AE80, 0x340, 0x0, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok584) {
  int f = -732951919;

  my_decimal decimal_check = {{0x2A45AE80, 0x340, 0x0, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok585) {
  int f = 576486344;

  my_decimal decimal_check = {{0x2D984D, 0x0, 0x0, 0x180000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok586) {
  int f = -1570997304;

  my_decimal decimal_check = {{0x2D984D, 0x0, 0x0, 0x80180000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok587) {
  int f = 433952100;

  my_decimal decimal_check = {{0x37EF8, 0x0, 0x0, 0x1C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok588) {
  int f = -1713531548;

  my_decimal decimal_check = {{0x37EF8, 0x0, 0x0, 0x801C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok589) {
  int f = 1612755390;

  my_decimal decimal_check = {{0x80DF4000, 0x82C6F7E9, 0x2, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok590) {
  int f = -534728258;

  my_decimal decimal_check = {{0x80DF4000, 0x82C6F7E9, 0x2, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok591) {
  int f = 580459451;

  my_decimal decimal_check = {{0x3F52F9, 0x0, 0x0, 0x180000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok592) {
  int f = -1567024197;

  my_decimal decimal_check = {{0x3F52F9, 0x0, 0x0, 0x80180000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok593) {
  int f = 1501518942;

  my_decimal decimal_check = {{0xE7FADE00, 0xFF5C5, 0x0, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok594) {
  int f = -645964706;

  my_decimal decimal_check = {{0xE7FADE00, 0xFF5C5, 0x0, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok595) {
  int f = 1493842418;

  my_decimal decimal_check = {{0x351E7000, 0x8A39F, 0x0, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok596) {
  int f = -653641230;

  my_decimal decimal_check = {{0x351E7000, 0x8A39F, 0x0, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok597) {
  int f = 1202885028;

  my_decimal decimal_check = {{0x8B81C8, 0x0, 0x0, 0x20000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok598) {
  int f = -944598620;

  my_decimal decimal_check = {{0x8B81C8, 0x0, 0x0, 0x80020000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok599) {
  int f = 1377199227;

  my_decimal decimal_check = {{0x991E74E0, 0x25, 0x0, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok600) {
  int f = -770284421;

  my_decimal decimal_check = {{0x991E74E0, 0x25, 0x0, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok601) {
  int f = 774368166;

  my_decimal decimal_check = {{0x5D36F, 0x0, 0x0, 0x100000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok602) {
  int f = -1373115482;

  my_decimal decimal_check = {{0x5D36F, 0x0, 0x0, 0x80100000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok603) {
  int f = 400945363;

  my_decimal decimal_check = {{0x5CE, 0x0, 0x0, 0x1B0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok604) {
  int f = -1746538285;

  my_decimal decimal_check = {{0x5CE, 0x0, 0x0, 0x801B0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok605) {
  int f = 1493498728;

  my_decimal decimal_check = {{0x7C325200, 0x84FB6, 0x0, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok606) {
  int f = -653984920;

  my_decimal decimal_check = {{0x7C325200, 0x84FB6, 0x0, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok607) {
  int f = 1605938344;

  my_decimal decimal_check = {{0x27B56000, 0x71594EB2, 0x1, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok608) {
  int f = -541545304;

  my_decimal decimal_check = {{0x27B56000, 0x71594EB2, 0x1, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok609) {
  int f = 1114099898;

  my_decimal decimal_check = {{0x586E37, 0x0, 0x0, 0x50000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok610) {
  int f = -1033383750;

  my_decimal decimal_check = {{0x586E37, 0x0, 0x0, 0x80050000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok611) {
  int f = 471192883;

  my_decimal decimal_check = {{0x4BA570, 0x0, 0x0, 0x1C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok612) {
  int f = -1676290765;

  my_decimal decimal_check = {{0x4BA570, 0x0, 0x0, 0x801C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok613) {
  int f = 522393321;

  my_decimal decimal_check = {{0x34B272, 0x0, 0x0, 0x1A0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok614) {
  int f = -1625090327;

  my_decimal decimal_check = {{0x34B272, 0x0, 0x0, 0x801A0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok615) {
  int f = 927380824;

  my_decimal decimal_check = {{0x12128A, 0x0, 0x0, 0xB0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok616) {
  int f = -1220102824;

  my_decimal decimal_check = {{0x12128A, 0x0, 0x0, 0x800B0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok617) {
  int f = 1525327741;

  my_decimal decimal_check = {{0x8414E400, 0x7553BE, 0x0, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok618) {
  int f = -622155907;

  my_decimal decimal_check = {{0x8414E400, 0x7553BE, 0x0, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok619) {
  int f = 481721705;

  my_decimal decimal_check = {{0x126D41, 0x0, 0x0, 0x1B0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok620) {
  int f = -1665761943;

  my_decimal decimal_check = {{0x126D41, 0x0, 0x0, 0x801B0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok621) {
  int f = 1242472727;

  my_decimal decimal_check = {{0x23A846, 0x0, 0x0, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok622) {
  int f = -905010921;

  my_decimal decimal_check = {{0x23A846, 0x0, 0x0, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok623) {
  int f = 1306341177;

  my_decimal decimal_check = {{0x1BA5E6F8, 0x0, 0x0, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok624) {
  int f = -841142471;

  my_decimal decimal_check = {{0x1BA5E6F8, 0x0, 0x0, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok625) {
  int f = 327750452;

  my_decimal decimal_check = {{0x23, 0x0, 0x0, 0x1C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok626) {
  int f = -1819733196;

  my_decimal decimal_check = {{0x23, 0x0, 0x0, 0x801C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok627) {
  int f = 1626242985;

  my_decimal decimal_check = {{0xD10EC000, 0x73FD3205, 0x7, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok628) {
  int f = -521240663;

  my_decimal decimal_check = {{0xD10EC000, 0x73FD3205, 0x7, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok629) {
  int f = 957065945;

  my_decimal decimal_check = {{0x145304, 0x0, 0x0, 0xA0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok630) {
  int f = -1190417703;

  my_decimal decimal_check = {{0x145304, 0x0, 0x0, 0x800A0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok631) {
  int f = 1380411409;

  my_decimal decimal_check = {{0xDA041C60, 0x31, 0x0, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok632) {
  int f = -767072239;

  my_decimal decimal_check = {{0xDA041C60, 0x31, 0x0, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok633) {
  int f = 1329075288;

  my_decimal decimal_check = {{0xB8145808, 0x0, 0x0, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok634) {
  int f = -818408360;

  my_decimal decimal_check = {{0xB8145808, 0x0, 0x0, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok635) {
  int f = 1568371630;

  my_decimal decimal_check = {{0x44CC7000, 0xFB73B45, 0x0, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok636) {
  int f = -579112018;

  my_decimal decimal_check = {{0x44CC7000, 0xFB73B45, 0x0, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok637) {
  int f = 952083489;

  my_decimal decimal_check = {{0x8B6FF1, 0x0, 0x0, 0xB0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok638) {
  int f = -1195400159;

  my_decimal decimal_check = {{0x8B6FF1, 0x0, 0x0, 0x800B0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok639) {
  int f = 1757281303;

  my_decimal decimal_check = {{0xF3B00000, 0xB7C47F0C, 0x5EFE0, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok640) {
  int f = -390202345;

  my_decimal decimal_check = {{0xF3B00000, 0xB7C47F0C, 0x5EFE0, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok641) {
  int f = 803942612;

  my_decimal decimal_check = {{0x41474F, 0x0, 0x0, 0x100000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok642) {
  int f = -1343541036;

  my_decimal decimal_check = {{0x41474F, 0x0, 0x0, 0x80100000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok643) {
  int f = 1677711262;

  my_decimal decimal_check = {{0xE0A68000, 0xAF3B53FE, 0x1FF, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok644) {
  int f = -469772386;

  my_decimal decimal_check = {{0xE0A68000, 0xAF3B53FE, 0x1FF, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok645) {
  int f = 1561549468;

  my_decimal decimal_check = {{0xCCB54000, 0x935A9C8, 0x0, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok646) {
  int f = -585934180;

  my_decimal decimal_check = {{0xCCB54000, 0x935A9C8, 0x0, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok647) {
  int f = 374603688;

  my_decimal decimal_check = {{0x6B1, 0x0, 0x0, 0x1C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok648) {
  int f = -1772879960;

  my_decimal decimal_check = {{0x6B1, 0x0, 0x0, 0x801C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok649) {
  int f = 1069136819;

  my_decimal decimal_check = {{0x162421, 0x0, 0x0, 0x60000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok650) {
  int f = -1078346829;

  my_decimal decimal_check = {{0x162421, 0x0, 0x0, 0x80060000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok651) {
  int f = 722421255;

  my_decimal decimal_check = {{0x4DAB33, 0x0, 0x0, 0x130000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok652) {
  int f = -1425062393;

  my_decimal decimal_check = {{0x4DAB33, 0x0, 0x0, 0x80130000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok653) {
  int f = 1048497542;

  my_decimal decimal_check = {{0x25F7F5, 0x0, 0x0, 0x70000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok654) {
  int f = -1098986106;

  my_decimal decimal_check = {{0x25F7F5, 0x0, 0x0, 0x80070000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok655) {
  int f = 518482310;

  my_decimal decimal_check = {{0x2562FC, 0x0, 0x0, 0x1A0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok656) {
  int f = -1629001338;

  my_decimal decimal_check = {{0x2562FC, 0x0, 0x0, 0x801A0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok657) {
  int f = 503064360;

  my_decimal decimal_check = {{0x65D801, 0x0, 0x0, 0x1B0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok658) {
  int f = -1644419288;

  my_decimal decimal_check = {{0x65D801, 0x0, 0x0, 0x801B0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok659) {
  int f = 1417834888;

  my_decimal decimal_check = {{0x8C419D00, 0x413, 0x0, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok660) {
  int f = -729648760;

  my_decimal decimal_check = {{0x8C419D00, 0x413, 0x0, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok661) {
  int f = 1435534698;

  my_decimal decimal_check = {{0xAD85BE00, 0x1210, 0x0, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok662) {
  int f = -711948950;

  my_decimal decimal_check = {{0xAD85BE00, 0x1210, 0x0, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok663) {
  int f = 794395630;

  my_decimal decimal_check = {{0x1E2FB3, 0x0, 0x0, 0x100000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok664) {
  int f = -1353088018;

  my_decimal decimal_check = {{0x1E2FB3, 0x0, 0x0, 0x80100000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok665) {
  int f = 1179654980;

  my_decimal decimal_check = {{0x1452AA, 0x0, 0x0, 0x20000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok666) {
  int f = -967828668;

  my_decimal decimal_check = {{0x1452AA, 0x0, 0x0, 0x80020000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok667) {
  int f = 900149071;

  my_decimal decimal_check = {{0x1301B8, 0x0, 0x0, 0xC0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok668) {
  int f = -1247334577;

  my_decimal decimal_check = {{0x1301B8, 0x0, 0x0, 0x800C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok669) {
  int f = 1037362588;

  my_decimal decimal_check = {{0xFDCB0, 0x0, 0x0, 0x70000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok670) {
  int f = -1110121060;

  my_decimal decimal_check = {{0xFDCB0, 0x0, 0x0, 0x80070000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok671) {
  int f = 365121521;

  my_decimal decimal_check = {{0x315, 0x0, 0x0, 0x1C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok672) {
  int f = -1782362127;

  my_decimal decimal_check = {{0x315, 0x0, 0x0, 0x801C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok673) {
  int f = 517245386;

  my_decimal decimal_check = {{0x225660, 0x0, 0x0, 0x1A0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok674) {
  int f = -1630238262;

  my_decimal decimal_check = {{0x225660, 0x0, 0x0, 0x801A0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok675) {
  int f = 1743802045;

  my_decimal decimal_check = {{0x51840000, 0x7C32AA9C, 0x1E09D, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok676) {
  int f = -403681603;

  my_decimal decimal_check = {{0x51840000, 0x7C32AA9C, 0x1E09D, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok677) {
  int f = 377206712;

  my_decimal decimal_check = {{0x7F1, 0x0, 0x0, 0x1C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok678) {
  int f = -1770276936;

  my_decimal decimal_check = {{0x7F1, 0x0, 0x0, 0x801C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok679) {
  int f = 1619753674;

  my_decimal decimal_check = {{0xE4AFC000, 0x5BD64F20, 0x4, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok680) {
  int f = -527729974;

  my_decimal decimal_check = {{0xE4AFC000, 0x5BD64F20, 0x4, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok681) {
  int f = 503770329;

  my_decimal decimal_check = {{0xAE630, 0x0, 0x0, 0x1A0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok682) {
  int f = -1643713319;

  my_decimal decimal_check = {{0xAE630, 0x0, 0x0, 0x801A0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok683) {
  int f = 779898316;

  my_decimal decimal_check = {{0x578916, 0x0, 0x0, 0x110000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok684) {
  int f = -1367585332;

  my_decimal decimal_check = {{0x578916, 0x0, 0x0, 0x80110000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok685) {
  int f = 800071083;

  my_decimal decimal_check = {{0x30E1C9, 0x0, 0x0, 0x100000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok686) {
  int f = -1347412565;

  my_decimal decimal_check = {{0x30E1C9, 0x0, 0x0, 0x80100000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok687) {
  int f = 326951178;

  my_decimal decimal_check = {{0x20, 0x0, 0x0, 0x1C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok688) {
  int f = -1820532470;

  my_decimal decimal_check = {{0x20, 0x0, 0x0, 0x801C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok689) {
  int f = 1029262954;

  my_decimal decimal_check = {{0x81865, 0x0, 0x0, 0x70000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok690) {
  int f = -1118220694;

  my_decimal decimal_check = {{0x81865, 0x0, 0x0, 0x80070000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok691) {
  int f = 511276694;

  my_decimal decimal_check = {{0x1426C7, 0x0, 0x0, 0x1A0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok692) {
  int f = -1636206954;

  my_decimal decimal_check = {{0x1426C7, 0x0, 0x0, 0x801A0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok693) {
  int f = 1076096230;

  my_decimal decimal_check = {{0x271536, 0x0, 0x0, 0x60000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok694) {
  int f = -1071387418;

  my_decimal decimal_check = {{0x271536, 0x0, 0x0, 0x80060000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok695) {
  int f = 516616618;

  my_decimal decimal_check = {{0x20C991, 0x0, 0x0, 0x1A0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok696) {
  int f = -1630867030;

  my_decimal decimal_check = {{0x20C991, 0x0, 0x0, 0x801A0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok697) {
  int f = 1034870805;

  my_decimal decimal_check = {{0x824AD2, 0x0, 0x0, 0x80000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok698) {
  int f = -1112612843;

  my_decimal decimal_check = {{0x824AD2, 0x0, 0x0, 0x80080000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok699) {
  int f = 1790328632;

  my_decimal decimal_check = {{0x1FF00000, 0xE1972E6F, 0x5B1F9A, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok700) {
  int f = -357155016;

  my_decimal decimal_check = {{0x1FF00000, 0xE1972E6F, 0x5B1F9A, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok701) {
  int f = 809368813;

  my_decimal decimal_check = {{0x6976EB, 0x0, 0x0, 0x100000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok702) {
  int f = -1338114835;

  my_decimal decimal_check = {{0x6976EB, 0x0, 0x0, 0x80100000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok703) {
  int f = 1491131963;

  my_decimal decimal_check = {{0xEEC8DA00, 0x706F1, 0x0, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok704) {
  int f = -656351685;

  my_decimal decimal_check = {{0xEEC8DA00, 0x706F1, 0x0, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok705) {
  int f = 539462492;

  my_decimal decimal_check = {{0x15A794, 0x0, 0x0, 0x190000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok706) {
  int f = -1608021156;

  my_decimal decimal_check = {{0x15A794, 0x0, 0x0, 0x80190000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok707) {
  int f = 1003588375;

  my_decimal decimal_check = {{0x619383, 0x0, 0x0, 0x90000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok708) {
  int f = -1143895273;

  my_decimal decimal_check = {{0x619383, 0x0, 0x0, 0x80090000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok709) {
  int f = 579348785;

  my_decimal decimal_check = {{0x385099, 0x0, 0x0, 0x180000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok710) {
  int f = -1568134863;

  my_decimal decimal_check = {{0x385099, 0x0, 0x0, 0x80180000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok711) {
  int f = 663030162;

  my_decimal decimal_check = {{0x3857F1, 0x0, 0x0, 0x150000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok712) {
  int f = -1484453486;

  my_decimal decimal_check = {{0x3857F1, 0x0, 0x0, 0x80150000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok713) {
  int f = 388991937;

  my_decimal decimal_check = {{0x1628, 0x0, 0x0, 0x1C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok714) {
  int f = -1758491711;

  my_decimal decimal_check = {{0x1628, 0x0, 0x0, 0x801C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok715) {
  int f = 1124987210;

  my_decimal decimal_check = {{0x15A8A1, 0x0, 0x0, 0x40000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok716) {
  int f = -1022496438;

  my_decimal decimal_check = {{0x15A8A1, 0x0, 0x0, 0x80040000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok717) {
  int f = 534505087;

  my_decimal decimal_check = {{0x8E1B77, 0x0, 0x0, 0x1A0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok718) {
  int f = -1612978561;

  my_decimal decimal_check = {{0x8E1B77, 0x0, 0x0, 0x801A0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok719) {
  int f = 389382205;

  my_decimal decimal_check = {{0x16E9, 0x0, 0x0, 0x1C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok720) {
  int f = -1758101443;

  my_decimal decimal_check = {{0x16E9, 0x0, 0x0, 0x801C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok721) {
  int f = 997457207;

  my_decimal decimal_check = {{0x38CEE3, 0x0, 0x0, 0x90000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok722) {
  int f = -1150026441;

  my_decimal decimal_check = {{0x38CEE3, 0x0, 0x0, 0x80090000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok723) {
  int f = 1570284269;

  my_decimal decimal_check = {{0x529DB000, 0x13145DDF, 0x0, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok724) {
  int f = -577199379;

  my_decimal decimal_check = {{0x529DB000, 0x13145DDF, 0x0, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok725) {
  int f = 422020026;

  my_decimal decimal_check = {{0x1524B, 0x0, 0x0, 0x1C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok726) {
  int f = -1725463622;

  my_decimal decimal_check = {{0x1524B, 0x0, 0x0, 0x801C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok727) {
  int f = 1665477504;

  my_decimal decimal_check = {{0x2A958000, 0x2B7FB017, 0xC5, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok728) {
  int f = -482006144;

  my_decimal decimal_check = {{0x2A958000, 0x2B7FB017, 0xC5, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok729) {
  int f = 595783049;

  my_decimal decimal_check = {{0x15A903, 0x0, 0x0, 0x170000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok730) {
  int f = -1551700599;

  my_decimal decimal_check = {{0x15A903, 0x0, 0x0, 0x80170000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok731) {
  int f = 445780659;

  my_decimal decimal_check = {{0x937F0, 0x0, 0x0, 0x1C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok732) {
  int f = -1701702989;

  my_decimal decimal_check = {{0x937F0, 0x0, 0x0, 0x801C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok733) {
  int f = 1684670847;

  my_decimal decimal_check = {{0xDF690000, 0x25FDB87F, 0x3A8, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok734) {
  int f = -462812801;

  my_decimal decimal_check = {{0xDF690000, 0x25FDB87F, 0x3A8, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok735) {
  int f = 993974639;

  my_decimal decimal_check = {{0x4718D, 0x0, 0x0, 0x80000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok736) {
  int f = -1153509009;

  my_decimal decimal_check = {{0x4718D, 0x0, 0x0, 0x80080000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok737) {
  int f = 586583959;

  my_decimal decimal_check = {{0x65F9A7, 0x0, 0x0, 0x180000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok738) {
  int f = -1560899689;

  my_decimal decimal_check = {{0x65F9A7, 0x0, 0x0, 0x80180000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok739) {
  int f = 589647986;

  my_decimal decimal_check = {{0x88BEA7, 0x0, 0x0, 0x180000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok740) {
  int f = -1557835662;

  my_decimal decimal_check = {{0x88BEA7, 0x0, 0x0, 0x80180000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok741) {
  int f = 869258193;

  my_decimal decimal_check = {{0x93AB96, 0x0, 0x0, 0xE0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok742) {
  int f = -1278225455;

  my_decimal decimal_check = {{0x93AB96, 0x0, 0x0, 0x800E0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok743) {
  int f = 1151646501;

  my_decimal decimal_check = {{0x141BD8, 0x0, 0x0, 0x30000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok744) {
  int f = -995837147;

  my_decimal decimal_check = {{0x141BD8, 0x0, 0x0, 0x80030000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok745) {
  int f = 1197257088;

  my_decimal decimal_check = {{0x89EEF, 0x0, 0x0, 0x10000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok746) {
  int f = -950226560;

  my_decimal decimal_check = {{0x89EEF, 0x0, 0x0, 0x80010000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok747) {
  int f = 890314465;

  my_decimal decimal_check = {{0x527DD4, 0x0, 0x0, 0xD0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok748) {
  int f = -1257169183;

  my_decimal decimal_check = {{0x527DD4, 0x0, 0x0, 0x800D0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok749) {
  int f = 1251214536;

  my_decimal decimal_check = {{0x4A0264, 0x0, 0x0, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok750) {
  int f = -896269112;

  my_decimal decimal_check = {{0x4A0264, 0x0, 0x0, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok751) {
  int f = 1590417554;

  my_decimal decimal_check = {{0xF4055000, 0x65EC48AC, 0x0, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok752) {
  int f = -557066094;

  my_decimal decimal_check = {{0xF4055000, 0x65EC48AC, 0x0, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok753) {
  int f = 866955133;

  my_decimal decimal_check = {{0x7AB34F, 0x0, 0x0, 0xE0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok754) {
  int f = -1280528515;

  my_decimal decimal_check = {{0x7AB34F, 0x0, 0x0, 0x800E0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok755) {
  int f = 1240690460;

  my_decimal decimal_check = {{0x1E6DE4, 0x0, 0x0, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok756) {
  int f = -906793188;

  my_decimal decimal_check = {{0x1E6DE4, 0x0, 0x0, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok757) {
  int f = 911713992;

  my_decimal decimal_check = {{0x310892, 0x0, 0x0, 0xC0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok758) {
  int f = -1235769656;

  my_decimal decimal_check = {{0x310892, 0x0, 0x0, 0x800C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok759) {
  int f = 563952295;

  my_decimal decimal_check = {{0x1041D2, 0x0, 0x0, 0x180000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok760) {
  int f = -1583531353;

  my_decimal decimal_check = {{0x1041D2, 0x0, 0x0, 0x80180000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok761) {
  int f = 1212698283;

  my_decimal decimal_check = {{0x1F4C4B, 0x0, 0x0, 0x10000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok762) {
  int f = -934785365;

  my_decimal decimal_check = {{0x1F4C4B, 0x0, 0x0, 0x80010000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok763) {
  int f = 529584486;

  my_decimal decimal_check = {{0x5D961F, 0x0, 0x0, 0x1A0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok764) {
  int f = -1617899162;

  my_decimal decimal_check = {{0x5D961F, 0x0, 0x0, 0x801A0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok765) {
  int f = 1041596156;

  my_decimal decimal_check = {{0x1646D2, 0x0, 0x0, 0x70000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok766) {
  int f = -1105887492;

  my_decimal decimal_check = {{0x1646D2, 0x0, 0x0, 0x80070000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok767) {
  int f = 1831001467;

  my_decimal decimal_check = {{0xDAC00000, 0xE552DAA3, 0xA2DD79E, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok768) {
  int f = -316482181;

  my_decimal decimal_check = {{0xDAC00000, 0xE552DAA3, 0xA2DD79E, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok769) {
  int f = 606169637;

  my_decimal decimal_check = {{0x35685A, 0x0, 0x0, 0x170000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok770) {
  int f = -1541314011;

  my_decimal decimal_check = {{0x35685A, 0x0, 0x0, 0x80170000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok771) {
  int f = 1510775993;

  my_decimal decimal_check = {{0x4D13E000, 0x23272E, 0x0, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok772) {
  int f = -636707655;

  my_decimal decimal_check = {{0x4D13E000, 0x23272E, 0x0, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok773) {
  int f = 1804529180;

  my_decimal decimal_check = {{0xFE00000, 0x5637DB47, 0x11DDC37, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok774) {
  int f = -342954468;

  my_decimal decimal_check = {{0xFE00000, 0x5637DB47, 0x11DDC37, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok775) {
  int f = 1742439863;

  my_decimal decimal_check = {{0x84880000, 0x71CBAADD, 0x1B70B, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok776) {
  int f = -405043785;

  my_decimal decimal_check = {{0x84880000, 0x71CBAADD, 0x1B70B, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok777) {
  int f = 326892456;

  my_decimal decimal_check = {{0x20, 0x0, 0x0, 0x1C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok778) {
  int f = -1820591192;

  my_decimal decimal_check = {{0x20, 0x0, 0x0, 0x801C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok779) {
  int f = 372035988;

  my_decimal decimal_check = {{0x574, 0x0, 0x0, 0x1C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok780) {
  int f = -1775447660;

  my_decimal decimal_check = {{0x574, 0x0, 0x0, 0x801C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok781) {
  int f = 1534114234;

  my_decimal decimal_check = {{0x519EB000, 0xF0B9B9, 0x0, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok782) {
  int f = -613369414;

  my_decimal decimal_check = {{0x519EB000, 0xF0B9B9, 0x0, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok783) {
  int f = 950242826;

  my_decimal decimal_check = {{0x770077, 0x0, 0x0, 0xB0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok784) {
  int f = -1197240822;

  my_decimal decimal_check = {{0x770077, 0x0, 0x0, 0x800B0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok785) {
  int f = 1207000521;

  my_decimal decimal_check = {{0x12DB54, 0x0, 0x0, 0x10000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok786) {
  int f = -940483127;

  my_decimal decimal_check = {{0x12DB54, 0x0, 0x0, 0x80010000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok787) {
  int f = 1545809157;

  my_decimal decimal_check = {{0xBDC800, 0x28CB418, 0x0, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok788) {
  int f = -601674491;

  my_decimal decimal_check = {{0xBDC800, 0x28CB418, 0x0, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok789) {
  int f = 628388637;

  my_decimal decimal_check = {{0x205A47, 0x0, 0x0, 0x160000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok790) {
  int f = -1519095011;

  my_decimal decimal_check = {{0x205A47, 0x0, 0x0, 0x80160000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok791) {
  int f = 499859318;

  my_decimal decimal_check = {{0x521757, 0x0, 0x0, 0x1B0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok792) {
  int f = -1647624330;

  my_decimal decimal_check = {{0x521757, 0x0, 0x0, 0x801B0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok793) {
  int f = 347193244;

  my_decimal decimal_check = {{0xB3, 0x0, 0x0, 0x1C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok794) {
  int f = -1800290404;

  my_decimal decimal_check = {{0xB3, 0x0, 0x0, 0x801C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok795) {
  int f = 692578229;

  my_decimal decimal_check = {{0x43BB01, 0x0, 0x0, 0x140000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok796) {
  int f = -1454905419;

  my_decimal decimal_check = {{0x43BB01, 0x0, 0x0, 0x80140000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok797) {
  int f = 1289152779;

  my_decimal decimal_check = {{0x6B74854, 0x0, 0x0, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok798) {
  int f = -858330869;

  my_decimal decimal_check = {{0x6B74854, 0x0, 0x0, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok799) {
  int f = 572797249;

  my_decimal decimal_check = {{0x21F446, 0x0, 0x0, 0x180000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok800) {
  int f = -1574686399;

  my_decimal decimal_check = {{0x21F446, 0x0, 0x0, 0x80180000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok801) {
  int f = 384590497;

  my_decimal decimal_check = {{0xEEB, 0x0, 0x0, 0x1C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok802) {
  int f = -1762893151;

  my_decimal decimal_check = {{0xEEB, 0x0, 0x0, 0x801C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok803) {
  int f = 1648494849;

  my_decimal decimal_check = {{0x57734000, 0x82404B57, 0x30, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok804) {
  int f = -498988799;

  my_decimal decimal_check = {{0x57734000, 0x82404B57, 0x30, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok805) {
  int f = 1488017309;

  my_decimal decimal_check = {{0xF1DF9600, 0x58ABC, 0x0, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok806) {
  int f = -659466339;

  my_decimal decimal_check = {{0xF1DF9600, 0x58ABC, 0x0, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok807) {
  int f = 442926381;

  my_decimal decimal_check = {{0x74621, 0x0, 0x0, 0x1C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok808) {
  int f = -1704557267;

  my_decimal decimal_check = {{0x74621, 0x0, 0x0, 0x801C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok809) {
  int f = 927162609;

  my_decimal decimal_check = {{0x11C504, 0x0, 0x0, 0xB0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok810) {
  int f = -1220321039;

  my_decimal decimal_check = {{0x11C504, 0x0, 0x0, 0x800B0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok811) {
  int f = 1224095570;

  my_decimal decimal_check = {{0x4CF14A, 0x0, 0x0, 0x10000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok812) {
  int f = -923388078;

  my_decimal decimal_check = {{0x4CF14A, 0x0, 0x0, 0x80010000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok813) {
  int f = 299967045;

  my_decimal decimal_check = {{0x4, 0x0, 0x0, 0x1C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok814) {
  int f = -1847516603;

  my_decimal decimal_check = {{0x4, 0x0, 0x0, 0x801C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok815) {
  int f = 1215521285;

  my_decimal decimal_check = {{0x260751, 0x0, 0x0, 0x10000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok816) {
  int f = -931962363;

  my_decimal decimal_check = {{0x260751, 0x0, 0x0, 0x80010000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok817) {
  int f = 1310358489;

  my_decimal decimal_check = {{0x269EF61C, 0x0, 0x0, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok818) {
  int f = -837125159;

  my_decimal decimal_check = {{0x269EF61C, 0x0, 0x0, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok819) {
  int f = 555304489;

  my_decimal decimal_check = {{0x4F3DA7, 0x0, 0x0, 0x190000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok820) {
  int f = -1592179159;

  my_decimal decimal_check = {{0x4F3DA7, 0x0, 0x0, 0x80190000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok821) {
  int f = 1354059678;

  my_decimal decimal_check = {{0xAA7CEBB0, 0x5, 0x0, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok822) {
  int f = -793423970;

  my_decimal decimal_check = {{0xAA7CEBB0, 0x5, 0x0, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok823) {
  int f = 714674736;

  my_decimal decimal_check = {{0x297D70, 0x0, 0x0, 0x130000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok824) {
  int f = -1432808912;

  my_decimal decimal_check = {{0x297D70, 0x0, 0x0, 0x80130000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok825) {
  int f = 1771257868;

  my_decimal decimal_check = {{0x49300000, 0x944C34E1, 0x126801, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok826) {
  int f = -376225780;

  my_decimal decimal_check = {{0x49300000, 0x944C34E1, 0x126801, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok827) {
  int f = 1528537442;

  my_decimal decimal_check = {{0x254F3800, 0x9BA161, 0x0, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok828) {
  int f = -618946206;

  my_decimal decimal_check = {{0x254F3800, 0x9BA161, 0x0, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok829) {
  int f = 743057180;

  my_decimal decimal_check = {{0x2BD5BC, 0x0, 0x0, 0x120000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok830) {
  int f = -1404426468;

  my_decimal decimal_check = {{0x2BD5BC, 0x0, 0x0, 0x80120000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok831) {
  int f = 465576283;

  my_decimal decimal_check = {{0x308021, 0x0, 0x0, 0x1C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok832) {
  int f = -1681907365;

  my_decimal decimal_check = {{0x308021, 0x0, 0x0, 0x801C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok833) {
  int f = 526391675;

  my_decimal decimal_check = {{0x486914, 0x0, 0x0, 0x1A0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok834) {
  int f = -1621091973;

  my_decimal decimal_check = {{0x486914, 0x0, 0x0, 0x801A0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok835) {
  int f = 1717672905;

  my_decimal decimal_check = {{0xA80E0000, 0xF1996B45, 0x3866, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok836) {
  int f = -429810743;

  my_decimal decimal_check = {{0xA80E0000, 0xF1996B45, 0x3866, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok837) {
  int f = 1048622821;

  my_decimal decimal_check = {{0x265C22, 0x0, 0x0, 0x70000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok838) {
  int f = -1098860827;

  my_decimal decimal_check = {{0x265C22, 0x0, 0x0, 0x80070000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok839) {
  int f = 651380314;

  my_decimal decimal_check = {{0x165E9D, 0x0, 0x0, 0x150000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok840) {
  int f = -1496103334;

  my_decimal decimal_check = {{0x165E9D, 0x0, 0x0, 0x80150000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok841) {
  int f = 1767905825;

  my_decimal decimal_check = {{0xA6380000, 0xE1479D68, 0xE01A1, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok842) {
  int f = -379577823;

  my_decimal decimal_check = {{0xA6380000, 0xE1479D68, 0xE01A1, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok843) {
  int f = 1508604242;

  my_decimal decimal_check = {{0x592C6400, 0x1D6F2A, 0x0, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok844) {
  int f = -638879406;

  my_decimal decimal_check = {{0x592C6400, 0x1D6F2A, 0x0, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok845) {
  int f = 664785745;

  my_decimal decimal_check = {{0x43B04F, 0x0, 0x0, 0x150000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok846) {
  int f = -1482697903;

  my_decimal decimal_check = {{0x43B04F, 0x0, 0x0, 0x80150000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok847) {
  int f = 1772532620;

  my_decimal decimal_check = {{0x98800000, 0xB0396630, 0x14D671, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok848) {
  int f = -374951028;

  my_decimal decimal_check = {{0x98800000, 0xB0396630, 0x14D671, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok849) {
  int f = 613518402;

  my_decimal decimal_check = {{0x6050C5, 0x0, 0x0, 0x170000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok850) {
  int f = -1533965246;

  my_decimal decimal_check = {{0x6050C5, 0x0, 0x0, 0x80170000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok851) {
  int f = 1468611409;

  my_decimal decimal_check = {{0xA1667D00, 0x11276, 0x0, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok852) {
  int f = -678872239;

  my_decimal decimal_check = {{0xA1667D00, 0x11276, 0x0, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok853) {
  int f = 1502630631;

  my_decimal decimal_check = {{0xF84F3000, 0x120A5C, 0x0, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok854) {
  int f = -644853017;

  my_decimal decimal_check = {{0xF84F3000, 0x120A5C, 0x0, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok855) {
  int f = 1201043973;

  my_decimal decimal_check = {{0x758F54, 0x0, 0x0, 0x20000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok856) {
  int f = -946439675;

  my_decimal decimal_check = {{0x758F54, 0x0, 0x0, 0x80020000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok857) {
  int f = 1828299086;

  my_decimal decimal_check = {{0x75400000, 0xC9EC668C, 0x7CD0A67, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok858) {
  int f = -319184562;

  my_decimal decimal_check = {{0x75400000, 0xC9EC668C, 0x7CD0A67, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok859) {
  int f = 757447389;

  my_decimal decimal_check = {{0x8FBF70, 0x0, 0x0, 0x120000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok860) {
  int f = -1390036259;

  my_decimal decimal_check = {{0x8FBF70, 0x0, 0x0, 0x80120000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok861) {
  int f = 1240927872;

  my_decimal decimal_check = {{0x1EE1D0, 0x0, 0x0, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok862) {
  int f = -906555776;

  my_decimal decimal_check = {{0x1EE1D0, 0x0, 0x0, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok863) {
  int f = 1732361555;

  my_decimal decimal_check = {{0x92DE0000, 0x525A6DD6, 0xC1BD, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok864) {
  int f = -415122093;

  my_decimal decimal_check = {{0x92DE0000, 0x525A6DD6, 0xC1BD, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok865) {
  int f = 1517910939;

  my_decimal decimal_check = {{0xE2B38C00, 0x3E5EE5, 0x0, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok866) {
  int f = -629572709;

  my_decimal decimal_check = {{0xE2B38C00, 0x3E5EE5, 0x0, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok867) {
  int f = 328231698;

  my_decimal decimal_check = {{0x24, 0x0, 0x0, 0x1C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok868) {
  int f = -1819251950;

  my_decimal decimal_check = {{0x24, 0x0, 0x0, 0x801C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok869) {
  int f = 1745735057;

  my_decimal decimal_check = {{0x127C0000, 0x467FE709, 0x23736, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok870) {
  int f = -401748591;

  my_decimal decimal_check = {{0x127C0000, 0x467FE709, 0x23736, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok871) {
  int f = 1122188084;

  my_decimal decimal_check = {{0x11561C, 0x0, 0x0, 0x40000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok872) {
  int f = -1025295564;

  my_decimal decimal_check = {{0x11561C, 0x0, 0x0, 0x80040000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok873) {
  int f = 599551827;

  my_decimal decimal_check = {{0x1F2C87, 0x0, 0x0, 0x170000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok874) {
  int f = -1547931821;

  my_decimal decimal_check = {{0x1F2C87, 0x0, 0x0, 0x80170000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok875) {
  int f = 596373337;

  my_decimal decimal_check = {{0x17267A, 0x0, 0x0, 0x170000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok876) {
  int f = -1551110311;

  my_decimal decimal_check = {{0x17267A, 0x0, 0x0, 0x80170000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok877) {
  int f = 901542420;

  my_decimal decimal_check = {{0x156C7D, 0x0, 0x0, 0xC0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok878) {
  int f = -1245941228;

  my_decimal decimal_check = {{0x156C7D, 0x0, 0x0, 0x800C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok879) {
  int f = 940058718;

  my_decimal decimal_check = {{0x3188AC, 0x0, 0x0, 0xB0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok880) {
  int f = -1207424930;

  my_decimal decimal_check = {{0x3188AC, 0x0, 0x0, 0x800B0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok881) {
  int f = 1208512510;

  my_decimal decimal_check = {{0x221C0, 0x0, 0x0, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok882) {
  int f = -938971138;

  my_decimal decimal_check = {{0x221C0, 0x0, 0x0, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok883) {
  int f = 603488673;

  my_decimal decimal_check = {{0x291CA7, 0x0, 0x0, 0x170000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok884) {
  int f = -1543994975;

  my_decimal decimal_check = {{0x291CA7, 0x0, 0x0, 0x80170000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok885) {
  int f = 429784937;

  my_decimal decimal_check = {{0x27E26, 0x0, 0x0, 0x1C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok886) {
  int f = -1717698711;

  my_decimal decimal_check = {{0x27E26, 0x0, 0x0, 0x801C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok887) {
  int f = 1329572618;

  my_decimal decimal_check = {{0xBFAB0828, 0x0, 0x0, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok888) {
  int f = -817911030;

  my_decimal decimal_check = {{0xBFAB0828, 0x0, 0x0, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok889) {
  int f = 575960960;

  my_decimal decimal_check = {{0x2BEFE6, 0x0, 0x0, 0x180000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok890) {
  int f = -1571522688;

  my_decimal decimal_check = {{0x2BEFE6, 0x0, 0x0, 0x80180000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok891) {
  int f = 817143061;

  my_decimal decimal_check = {{0x140D59, 0x0, 0x0, 0xF0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok892) {
  int f = -1330340587;

  my_decimal decimal_check = {{0x140D59, 0x0, 0x0, 0x800F0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok893) {
  int f = 736969608;

  my_decimal decimal_check = {{0x19B965, 0x0, 0x0, 0x120000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok894) {
  int f = -1410514040;

  my_decimal decimal_check = {{0x19B965, 0x0, 0x0, 0x80120000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok895) {
  int f = 1236447729;

  my_decimal decimal_check = {{0x16563E, 0x0, 0x0, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok896) {
  int f = -911035919;

  my_decimal decimal_check = {{0x16563E, 0x0, 0x0, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok897) {
  int f = 808844147;

  my_decimal decimal_check = {{0x65053B, 0x0, 0x0, 0x100000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok898) {
  int f = -1338639501;

  my_decimal decimal_check = {{0x65053B, 0x0, 0x0, 0x80100000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok899) {
  int f = 1720797004;

  my_decimal decimal_check = {{0xF9C80000, 0xA6731167, 0x48A3, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok900) {
  int f = -426686644;

  my_decimal decimal_check = {{0xF9C80000, 0xA6731167, 0x48A3, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok901) {
  int f = 1531452293;

  my_decimal decimal_check = {{0x36229400, 0xC81B84, 0x0, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok902) {
  int f = -616031355;

  my_decimal decimal_check = {{0x36229400, 0xC81B84, 0x0, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok903) {
  int f = 1747786078;

  my_decimal decimal_check = {{0x90B40000, 0x72CE8B54, 0x2B465, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok904) {
  int f = -399697570;

  my_decimal decimal_check = {{0x90B40000, 0x72CE8B54, 0x2B465, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok905) {
  int f = 1193551450;

  my_decimal decimal_check = {{0x401EFB, 0x0, 0x0, 0x20000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok906) {
  int f = -953932198;

  my_decimal decimal_check = {{0x401EFB, 0x0, 0x0, 0x80020000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok907) {
  int f = 635476026;

  my_decimal decimal_check = {{0x3B7320, 0x0, 0x0, 0x160000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok908) {
  int f = -1512007622;

  my_decimal decimal_check = {{0x3B7320, 0x0, 0x0, 0x80160000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok909) {
  int f = 371264681;

  my_decimal decimal_check = {{0x515, 0x0, 0x0, 0x1C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok910) {
  int f = -1776218967;

  my_decimal decimal_check = {{0x515, 0x0, 0x0, 0x801C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok911) {
  int f = 433970905;

  my_decimal decimal_check = {{0x38021, 0x0, 0x0, 0x1C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok912) {
  int f = -1713512743;

  my_decimal decimal_check = {{0x38021, 0x0, 0x0, 0x801C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok913) {
  int f = 981412666;

  my_decimal decimal_check = {{0x94871F, 0x0, 0x0, 0xA0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok914) {
  int f = -1166070982;

  my_decimal decimal_check = {{0x94871F, 0x0, 0x0, 0x800A0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok915) {
  int f = 1281857947;

  my_decimal decimal_check = {{0x39E6670, 0x0, 0x0, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok916) {
  int f = -865625701;

  my_decimal decimal_check = {{0x39E6670, 0x0, 0x0, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok917) {
  int f = 1387392629;

  my_decimal decimal_check = {{0xF73A11A0, 0x58, 0x0, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok918) {
  int f = -760091019;

  my_decimal decimal_check = {{0xF73A11A0, 0x58, 0x0, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok919) {
  int f = 1008147241;

  my_decimal decimal_check = {{0x8CBA80, 0x0, 0x0, 0x90000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok920) {
  int f = -1139336407;

  my_decimal decimal_check = {{0x8CBA80, 0x0, 0x0, 0x80090000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok921) {
  int f = 1279449589;

  my_decimal decimal_check = {{0x30B67D0, 0x0, 0x0, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok922) {
  int f = -868034059;

  my_decimal decimal_check = {{0x30B67D0, 0x0, 0x0, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok923) {
  int f = 648519114;

  my_decimal decimal_check = {{0x11BF40, 0x0, 0x0, 0x150000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok924) {
  int f = -1498964534;

  my_decimal decimal_check = {{0x11BF40, 0x0, 0x0, 0x80150000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok925) {
  int f = 945206849;

  my_decimal decimal_check = {{0x4E1C9B, 0x0, 0x0, 0xB0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok926) {
  int f = -1202276799;

  my_decimal decimal_check = {{0x4E1C9B, 0x0, 0x0, 0x800B0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok927) {
  int f = 550614662;

  my_decimal decimal_check = {{0x3635A4, 0x0, 0x0, 0x190000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok928) {
  int f = -1596868986;

  my_decimal decimal_check = {{0x3635A4, 0x0, 0x0, 0x80190000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok929) {
  int f = 880749875;

  my_decimal decimal_check = {{0x244345, 0x0, 0x0, 0xD0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok930) {
  int f = -1266733773;

  my_decimal decimal_check = {{0x244345, 0x0, 0x0, 0x800D0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok931) {
  int f = 1179682774;

  my_decimal decimal_check = {{0x145D44, 0x0, 0x0, 0x20000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok932) {
  int f = -967800874;

  my_decimal decimal_check = {{0x145D44, 0x0, 0x0, 0x80020000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok933) {
  int f = 763137054;

  my_decimal decimal_check = {{0x15E7AD, 0x0, 0x0, 0x110000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok934) {
  int f = -1384346594;

  my_decimal decimal_check = {{0x15E7AD, 0x0, 0x0, 0x80110000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok935) {
  int f = 1449118341;

  my_decimal decimal_check = {{0xA16EB380, 0x37F2, 0x0, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok936) {
  int f = -698365307;

  my_decimal decimal_check = {{0xA16EB380, 0x37F2, 0x0, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok937) {
  int f = 1349175643;

  my_decimal decimal_check = {{0xAB2572A0, 0x3, 0x0, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok938) {
  int f = -798308005;

  my_decimal decimal_check = {{0xAB2572A0, 0x3, 0x0, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok939) {
  int f = 1178853747;

  my_decimal decimal_check = {{0x132104, 0x0, 0x0, 0x20000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok940) {
  int f = -968629901;

  my_decimal decimal_check = {{0x132104, 0x0, 0x0, 0x80020000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok941) {
  int f = 1424009107;

  my_decimal decimal_check = {{0x3C9AAA40, 0x705, 0x0, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok942) {
  int f = -723474541;

  my_decimal decimal_check = {{0x3C9AAA40, 0x705, 0x0, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok943) {
  int f = 1488002988;

  my_decimal decimal_check = {{0x71BF0200, 0x588FD, 0x0, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok944) {
  int f = -659480660;

  my_decimal decimal_check = {{0x71BF0200, 0x588FD, 0x0, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok945) {
  int f = 813834047;

  my_decimal decimal_check = {{0x9076EA, 0x0, 0x0, 0x100000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok946) {
  int f = -1333649601;

  my_decimal decimal_check = {{0x9076EA, 0x0, 0x0, 0x80100000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok947) {
  int f = 1674937361;

  my_decimal decimal_check = {{0x3C3D0000, 0x822E308, 0x1AB, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok948) {
  int f = -472546287;

  my_decimal decimal_check = {{0x3C3D0000, 0x822E308, 0x1AB, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok949) {
  int f = 992463846;

  my_decimal decimal_check = {{0x271173, 0x0, 0x0, 0x90000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok950) {
  int f = -1155019802;

  my_decimal decimal_check = {{0x271173, 0x0, 0x0, 0x80090000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok951) {
  int f = 1162120714;

  my_decimal decimal_check = {{0x2FFCAD, 0x0, 0x0, 0x30000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok952) {
  int f = -985362934;

  my_decimal decimal_check = {{0x2FFCAD, 0x0, 0x0, 0x80030000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok953) {
  int f = 1076522867;

  my_decimal decimal_check = {{0x28A28C, 0x0, 0x0, 0x60000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok954) {
  int f = -1070960781;

  my_decimal decimal_check = {{0x28A28C, 0x0, 0x0, 0x80060000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok955) {
  int f = 901586386;

  my_decimal decimal_check = {{0x158004, 0x0, 0x0, 0xC0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok956) {
  int f = -1245897262;

  my_decimal decimal_check = {{0x158004, 0x0, 0x0, 0x800C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok957) {
  int f = 1202663830;

  my_decimal decimal_check = {{0x88DEBD, 0x0, 0x0, 0x20000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok958) {
  int f = -944819818;

  my_decimal decimal_check = {{0x88DEBD, 0x0, 0x0, 0x80020000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok959) {
  int f = 1362748599;

  my_decimal decimal_check = {{0x9E4B5F60, 0xB, 0x0, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok960) {
  int f = -784735049;

  my_decimal decimal_check = {{0x9E4B5F60, 0xB, 0x0, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok961) {
  int f = 746122579;

  my_decimal decimal_check = {{0x35FA3A, 0x0, 0x0, 0x120000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok962) {
  int f = -1401361069;

  my_decimal decimal_check = {{0x35FA3A, 0x0, 0x0, 0x80120000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok963) {
  int f = 1832556160;

  my_decimal decimal_check = {{0x1F600000, 0x63C1A55B, 0xBA96810, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok964) {
  int f = -314927488;

  my_decimal decimal_check = {{0x1F600000, 0x63C1A55B, 0xBA96810, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok965) {
  int f = 398291996;

  my_decimal decimal_check = {{0x2FD3, 0x0, 0x0, 0x1C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok966) {
  int f = -1749191652;

  my_decimal decimal_check = {{0x2FD3, 0x0, 0x0, 0x801C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok967) {
  int f = 1665486732;

  my_decimal decimal_check = {{0x610C8000, 0x4F8DA353, 0xC5, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok968) {
  int f = -481996916;

  my_decimal decimal_check = {{0x610C8000, 0x4F8DA353, 0xC5, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok969) {
  int f = 792368354;

  my_decimal decimal_check = {{0x296DF, 0x0, 0x0, 0xF0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok970) {
  int f = -1355115294;

  my_decimal decimal_check = {{0x296DF, 0x0, 0x0, 0x800F0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok971) {
  int f = 1051126444;

  my_decimal decimal_check = {{0x31BEBC, 0x0, 0x0, 0x70000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok972) {
  int f = -1096357204;

  my_decimal decimal_check = {{0x31BEBC, 0x0, 0x0, 0x80070000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok973) {
  int f = 536513666;

  my_decimal decimal_check = {{0x1030FC, 0x0, 0x0, 0x190000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok974) {
  int f = -1610969982;

  my_decimal decimal_check = {{0x1030FC, 0x0, 0x0, 0x80190000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok975) {
  int f = 880138475;

  my_decimal decimal_check = {{0x22EFE0, 0x0, 0x0, 0xD0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok976) {
  int f = -1267345173;

  my_decimal decimal_check = {{0x22EFE0, 0x0, 0x0, 0x800D0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok977) {
  int f = 1514951666;

  my_decimal decimal_check = {{0xD7F95800, 0x3314FC, 0x0, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok978) {
  int f = -632531982;

  my_decimal decimal_check = {{0xD7F95800, 0x3314FC, 0x0, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok979) {
  int f = 1309467714;

  my_decimal decimal_check = {{0x2339105C, 0x0, 0x0, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok980) {
  int f = -838015934;

  my_decimal decimal_check = {{0x2339105C, 0x0, 0x0, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok981) {
  int f = 1698760068;

  my_decimal decimal_check = {{0x965E0000, 0x582F0288, 0xC10, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok982) {
  int f = -448723580;

  my_decimal decimal_check = {{0x965E0000, 0x582F0288, 0xC10, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok983) {
  int f = 884067138;

  my_decimal decimal_check = {{0x328837, 0x0, 0x0, 0xD0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok984) {
  int f = -1263416510;

  my_decimal decimal_check = {{0x328837, 0x0, 0x0, 0x800D0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok985) {
  int f = 775353966;

  my_decimal decimal_check = {{0x3F7A58, 0x0, 0x0, 0x110000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok986) {
  int f = -1372129682;

  my_decimal decimal_check = {{0x3F7A58, 0x0, 0x0, 0x80110000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok987) {
  int f = 1442991221;

  my_decimal decimal_check = {{0x1D11FF00, 0x2093, 0x0, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok988) {
  int f = -704492427;

  my_decimal decimal_check = {{0x1D11FF00, 0x2093, 0x0, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok989) {
  int f = 1226982387;

  my_decimal decimal_check = {{0x656A78, 0x0, 0x0, 0x10000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok990) {
  int f = -920501261;

  my_decimal decimal_check = {{0x656A78, 0x0, 0x0, 0x80010000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok991) {
  int f = 566085566;

  my_decimal decimal_check = {{0x139F71, 0x0, 0x0, 0x180000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok992) {
  int f = -1581398082;

  my_decimal decimal_check = {{0x139F71, 0x0, 0x0, 0x80180000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok993) {
  int f = 1216266474;

  my_decimal decimal_check = {{0x27CE25, 0x0, 0x0, 0x10000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok994) {
  int f = -931217174;

  my_decimal decimal_check = {{0x27CE25, 0x0, 0x0, 0x80010000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok995) {
  int f = 1437154925;

  my_decimal decimal_check = {{0xCDC2BF00, 0x1527, 0x0, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok996) {
  int f = -710328723;

  my_decimal decimal_check = {{0xCDC2BF00, 0x1527, 0x0, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok997) {
  int f = 454914913;

  my_decimal decimal_check = {{0x13DF82, 0x0, 0x0, 0x1C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok998) {
  int f = -1692568735;

  my_decimal decimal_check = {{0x13DF82, 0x0, 0x0, 0x801C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok999) {
  int f = 954262836;

  my_decimal decimal_check = {{0x105D00, 0x0, 0x0, 0xA0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1000) {
  int f = -1193220812;

  my_decimal decimal_check = {{0x105D00, 0x0, 0x0, 0x800A0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1001) {
  int f = 1620379264;

  my_decimal decimal_check = {{0x4277A000, 0xA8340119, 0x4, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1002) {
  int f = -527104384;

  my_decimal decimal_check = {{0x4277A000, 0xA8340119, 0x4, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1003) {
  int f = 845835917;

  my_decimal decimal_check = {{0x14D25D, 0x0, 0x0, 0xE0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1004) {
  int f = -1301647731;

  my_decimal decimal_check = {{0x14D25D, 0x0, 0x0, 0x800E0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1005) {
  int f = 1453645344;

  my_decimal decimal_check = {{0xFCDE800, 0x526F, 0x0, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1006) {
  int f = -693838304;

  my_decimal decimal_check = {{0xFCDE800, 0x526F, 0x0, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1007) {
  int f = 1196363658;

  my_decimal decimal_check = {{0x50E212, 0x0, 0x0, 0x20000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1008) {
  int f = -951119990;

  my_decimal decimal_check = {{0x50E212, 0x0, 0x0, 0x80020000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1009) {
  int f = 294491459;

  my_decimal decimal_check = {{0x2, 0x0, 0x0, 0x1C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1010) {
  int f = -1852992189;

  my_decimal decimal_check = {{0x2, 0x0, 0x0, 0x801C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1011) {
  int f = 1601433954;

  my_decimal decimal_check = {{0x4F214000, 0xF3F1634C, 0x0, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1012) {
  int f = -546049694;

  my_decimal decimal_check = {{0x4F214000, 0xF3F1634C, 0x0, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1013) {
  int f = 931655593;

  my_decimal decimal_check = {{0x18BA05, 0x0, 0x0, 0xB0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1014) {
  int f = -1215828055;

  my_decimal decimal_check = {{0x18BA05, 0x0, 0x0, 0x800B0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1015) {
  int f = 1084987347;

  my_decimal decimal_check = {{0x51D26B, 0x0, 0x0, 0x60000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1016) {
  int f = -1062496301;

  my_decimal decimal_check = {{0x51D26B, 0x0, 0x0, 0x80060000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1017) {
  int f = 1200996830;

  my_decimal decimal_check = {{0x74FF75, 0x0, 0x0, 0x20000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1018) {
  int f = -946486818;

  my_decimal decimal_check = {{0x74FF75, 0x0, 0x0, 0x80020000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1019) {
  int f = 775517225;

  my_decimal decimal_check = {{0x66F29, 0x0, 0x0, 0x100000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1020) {
  int f = -1371966423;

  my_decimal decimal_check = {{0x66F29, 0x0, 0x0, 0x80100000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1021) {
  int f = 907044080;

  my_decimal decimal_check = {{0x20D4DB, 0x0, 0x0, 0xC0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1022) {
  int f = -1240439568;

  my_decimal decimal_check = {{0x20D4DB, 0x0, 0x0, 0x800C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1023) {
  int f = 1637810930;

  my_decimal decimal_check = {{0x4BB70000, 0xE05E5D93, 0x13, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1024) {
  int f = -509672718;

  my_decimal decimal_check = {{0x4BB70000, 0xE05E5D93, 0x13, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1025) {
  int f = 1637178767;

  my_decimal decimal_check = {{0xF40B4000, 0xABB1D791, 0x12, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1026) {
  int f = -510304881;

  my_decimal decimal_check = {{0xF40B4000, 0xABB1D791, 0x12, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1027) {
  int f = 1591017288;

  my_decimal decimal_check = {{0xCFA01000, 0x6A7FA45A, 0x0, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1028) {
  int f = -556466360;

  my_decimal decimal_check = {{0xCFA01000, 0x6A7FA45A, 0x0, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1029) {
  int f = 1836786528;

  my_decimal decimal_check = {{0xDC600000, 0xA7FD172F, 0xFB23602, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1030) {
  int f = -310697120;

  my_decimal decimal_check = {{0xDC600000, 0xA7FD172F, 0xFB23602, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1031) {
  int f = 1013266687;

  my_decimal decimal_check = {{0x155918, 0x0, 0x0, 0x80000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1032) {
  int f = -1134216961;

  my_decimal decimal_check = {{0x155918, 0x0, 0x0, 0x80080000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1033) {
  int f = 1816600376;

  my_decimal decimal_check = {{0x2A300000, 0x47DE8134, 0x31C7CE2, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1034) {
  int f = -330883272;

  my_decimal decimal_check = {{0x2A300000, 0x47DE8134, 0x31C7CE2, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1035) {
  int f = 846093375;

  my_decimal decimal_check = {{0x21DF8, 0x0, 0x0, 0xD0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1036) {
  int f = -1301390273;

  my_decimal decimal_check = {{0x21DF8, 0x0, 0x0, 0x800D0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1037) {
  int f = 1316230958;

  my_decimal decimal_check = {{0x3D05CBB0, 0x0, 0x0, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1038) {
  int f = -831252690;

  my_decimal decimal_check = {{0x3D05CBB0, 0x0, 0x0, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1039) {
  int f = 1379219472;

  my_decimal decimal_check = {{0x4E03CC00, 0x2D, 0x0, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1040) {
  int f = -768264176;

  my_decimal decimal_check = {{0x4E03CC00, 0x2D, 0x0, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1041) {
  int f = 640872670;

  my_decimal decimal_check = {{0x5EBB03, 0x0, 0x0, 0x160000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1042) {
  int f = -1506610978;

  my_decimal decimal_check = {{0x5EBB03, 0x0, 0x0, 0x80160000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1043) {
  int f = 1449371837;

  my_decimal decimal_check = {{0x2F799580, 0x38EA, 0x0, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1044) {
  int f = -698111811;

  my_decimal decimal_check = {{0x2F799580, 0x38EA, 0x0, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1045) {
  int f = 1500539932;

  my_decimal decimal_check = {{0xC7BA7400, 0xF06C1, 0x0, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1046) {
  int f = -646943716;

  my_decimal decimal_check = {{0xC7BA7400, 0xF06C1, 0x0, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1047) {
  int f = 1589303972;

  my_decimal decimal_check = {{0x91D0F000, 0x5D6D51D6, 0x0, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1048) {
  int f = -558179676;

  my_decimal decimal_check = {{0x91D0F000, 0x5D6D51D6, 0x0, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1049) {
  int f = 1038078329;

  my_decimal decimal_check = {{0x10ACFF, 0x0, 0x0, 0x70000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1050) {
  int f = -1109405319;

  my_decimal decimal_check = {{0x10ACFF, 0x0, 0x0, 0x80070000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1051) {
  int f = 537645531;

  my_decimal decimal_check = {{0x12123F, 0x0, 0x0, 0x190000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1052) {
  int f = -1609838117;

  my_decimal decimal_check = {{0x12123F, 0x0, 0x0, 0x80190000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1053) {
  int f = 718741192;

  my_decimal decimal_check = {{0x3A4EF7, 0x0, 0x0, 0x130000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1054) {
  int f = -1428742456;

  my_decimal decimal_check = {{0x3A4EF7, 0x0, 0x0, 0x80130000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1055) {
  int f = 937216084;

  my_decimal decimal_check = {{0x2828FD, 0x0, 0x0, 0xB0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1056) {
  int f = -1210267564;

  my_decimal decimal_check = {{0x2828FD, 0x0, 0x0, 0x800B0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1057) {
  int f = 437269929;

  my_decimal decimal_check = {{0x48CEA, 0x0, 0x0, 0x1C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1058) {
  int f = -1710213719;

  my_decimal decimal_check = {{0x48CEA, 0x0, 0x0, 0x801C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1059) {
  int f = 432470450;

  my_decimal decimal_check = {{0x323A8, 0x0, 0x0, 0x1C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1060) {
  int f = -1715013198;

  my_decimal decimal_check = {{0x323A8, 0x0, 0x0, 0x801C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1061) {
  int f = 1512227499;

  my_decimal decimal_check = {{0x91C61400, 0x28B0AB, 0x0, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1062) {
  int f = -635256149;

  my_decimal decimal_check = {{0x91C61400, 0x28B0AB, 0x0, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1063) {
  int f = 1205741200;

  my_decimal decimal_check = {{0x115B03, 0x0, 0x0, 0x10000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1064) {
  int f = -941742448;

  my_decimal decimal_check = {{0x115B03, 0x0, 0x0, 0x80010000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1065) {
  int f = 452763643;

  my_decimal decimal_check = {{0xFF160, 0x0, 0x0, 0x1C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1066) {
  int f = -1694720005;

  my_decimal decimal_check = {{0xFF160, 0x0, 0x0, 0x801C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1067) {
  int f = 1806385644;

  my_decimal decimal_check = {{0x5D000000, 0x92140D9D, 0x15683D5, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1068) {
  int f = -341098004;

  my_decimal decimal_check = {{0x5D000000, 0x92140D9D, 0x15683D5, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1069) {
  int f = 1300353985;

  my_decimal decimal_check = {{0x103A7824, 0x0, 0x0, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1070) {
  int f = -847129663;

  my_decimal decimal_check = {{0x103A7824, 0x0, 0x0, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1071) {
  int f = 1458271312;

  my_decimal decimal_check = {{0x28455800, 0x75BA, 0x0, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1072) {
  int f = -689212336;

  my_decimal decimal_check = {{0x28455800, 0x75BA, 0x0, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1073) {
  int f = 376614378;

  my_decimal decimal_check = {{0xC4, 0x0, 0x0, 0x1B0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1074) {
  int f = -1770869270;

  my_decimal decimal_check = {{0xC4, 0x0, 0x0, 0x801B0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1075) {
  int f = 759912989;

  my_decimal decimal_check = {{0x11A352, 0x0, 0x0, 0x110000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1076) {
  int f = -1387570659;

  my_decimal decimal_check = {{0x11A352, 0x0, 0x0, 0x80110000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1077) {
  int f = 1360310227;

  my_decimal decimal_check = {{0x4AFD2610, 0x9, 0x0, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1078) {
  int f = -787173421;

  my_decimal decimal_check = {{0x4AFD2610, 0x9, 0x0, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1079) {
  int f = 757307658;

  my_decimal decimal_check = {{0x8DE603, 0x0, 0x0, 0x120000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1080) {
  int f = -1390175990;

  my_decimal decimal_check = {{0x8DE603, 0x0, 0x0, 0x80120000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1081) {
  int f = 1685844109;

  my_decimal decimal_check = {{0xC2EB0000, 0xC2456FA5, 0x3EF, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1082) {
  int f = -461639539;

  my_decimal decimal_check = {{0xC2EB0000, 0xC2456FA5, 0x3EF, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1083) {
  int f = 1009510969;

  my_decimal decimal_check = {{0x1002C5, 0x0, 0x0, 0x80000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1084) {
  int f = -1137972679;

  my_decimal decimal_check = {{0x1002C5, 0x0, 0x0, 0x80080000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1085) {
  int f = 1237126295;

  my_decimal decimal_check = {{0x17A193, 0x0, 0x0, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1086) {
  int f = -910357353;

  my_decimal decimal_check = {{0x17A193, 0x0, 0x0, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1087) {
  int f = 745526611;

  my_decimal decimal_check = {{0x34016C, 0x0, 0x0, 0x120000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1088) {
  int f = -1401957037;

  my_decimal decimal_check = {{0x34016C, 0x0, 0x0, 0x80120000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1089) {
  int f = 408515804;

  my_decimal decimal_check = {{0x6DCA, 0x0, 0x0, 0x1C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1090) {
  int f = -1738967844;

  my_decimal decimal_check = {{0x6DCA, 0x0, 0x0, 0x801C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1091) {
  int f = 1627322396;

  my_decimal decimal_check = {{0xD7B4000, 0xF7C0CA6B, 0x7, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1092) {
  int f = -520161252;

  my_decimal decimal_check = {{0xD7B4000, 0xF7C0CA6B, 0x7, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1093) {
  int f = 804873021;

  my_decimal decimal_check = {{0x45380F, 0x0, 0x0, 0x100000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1094) {
  int f = -1342610627;

  my_decimal decimal_check = {{0x45380F, 0x0, 0x0, 0x80100000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1095) {
  int f = 742321329;

  my_decimal decimal_check = {{0x296671, 0x0, 0x0, 0x120000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1096) {
  int f = -1405162319;

  my_decimal decimal_check = {{0x296671, 0x0, 0x0, 0x80120000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1097) {
  int f = 1172577951;

  my_decimal decimal_check = {{0x6F62F4, 0x0, 0x0, 0x30000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1098) {
  int f = -974905697;

  my_decimal decimal_check = {{0x6F62F4, 0x0, 0x0, 0x80030000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1099) {
  int f = 1780088958;

  my_decimal decimal_check = {{0x65D80000, 0xC39E3C94, 0x26801F, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1100) {
  int f = -367394690;

  my_decimal decimal_check = {{0x65D80000, 0xC39E3C94, 0x26801F, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1101) {
  int f = 307469840;

  my_decimal decimal_check = {{0x7, 0x0, 0x0, 0x1C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1102) {
  int f = -1840013808;

  my_decimal decimal_check = {{0x7, 0x0, 0x0, 0x801C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1103) {
  int f = 376265269;

  my_decimal decimal_check = {{0x77D, 0x0, 0x0, 0x1C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1104) {
  int f = -1771218379;

  my_decimal decimal_check = {{0x77D, 0x0, 0x0, 0x801C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1105) {
  int f = 1678908617;

  my_decimal decimal_check = {{0x19680000, 0x7334B6C1, 0x248, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1106) {
  int f = -468575031;

  my_decimal decimal_check = {{0x19680000, 0x7334B6C1, 0x248, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1107) {
  int f = 633680091;

  my_decimal decimal_check = {{0x34322C, 0x0, 0x0, 0x160000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1108) {
  int f = -1513803557;

  my_decimal decimal_check = {{0x34322C, 0x0, 0x0, 0x80160000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1109) {
  int f = 302705120;

  my_decimal decimal_check = {{0x4, 0x0, 0x0, 0x1C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1110) {
  int f = -1844778528;

  my_decimal decimal_check = {{0x4, 0x0, 0x0, 0x801C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1111) {
  int f = 1728992077;

  my_decimal decimal_check = {{0x2E860000, 0x4D6EFC4C, 0x8E53, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1112) {
  int f = -418491571;

  my_decimal decimal_check = {{0x2E860000, 0x4D6EFC4C, 0x8E53, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1113) {
  int f = 911669243;

  my_decimal decimal_check = {{0x30E0D3, 0x0, 0x0, 0xC0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1114) {
  int f = -1235814405;

  my_decimal decimal_check = {{0x30E0D3, 0x0, 0x0, 0x800C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1115) {
  int f = 1422326022;

  my_decimal decimal_check = {{0xC836C300, 0x637, 0x0, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1116) {
  int f = -725157626;

  my_decimal decimal_check = {{0xC836C300, 0x637, 0x0, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1117) {
  int f = 1716269979;

  my_decimal decimal_check = {{0x23DE0000, 0xE70B284E, 0x330C, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1118) {
  int f = -431213669;

  my_decimal decimal_check = {{0x23DE0000, 0xE70B284E, 0x330C, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1119) {
  int f = 1323219186;

  my_decimal decimal_check = {{0x6F5C77F8, 0x0, 0x0, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1120) {
  int f = -824264462;

  my_decimal decimal_check = {{0x6F5C77F8, 0x0, 0x0, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1121) {
  int f = 888784932;

  my_decimal decimal_check = {{0x46FE05, 0x0, 0x0, 0xD0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1122) {
  int f = -1258698716;

  my_decimal decimal_check = {{0x46FE05, 0x0, 0x0, 0x800D0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1123) {
  int f = 1552424159;

  my_decimal decimal_check = {{0x999E7800, 0x440E6F1, 0x0, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1124) {
  int f = -595059489;

  my_decimal decimal_check = {{0x999E7800, 0x440E6F1, 0x0, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1125) {
  int f = 653809589;

  my_decimal decimal_check = {{0x1A4B57, 0x0, 0x0, 0x150000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1126) {
  int f = -1493674059;

  my_decimal decimal_check = {{0x1A4B57, 0x0, 0x0, 0x80150000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1127) {
  int f = 774618550;

  my_decimal decimal_check = {{0x5F55E, 0x0, 0x0, 0x100000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1128) {
  int f = -1372865098;

  my_decimal decimal_check = {{0x5F55E, 0x0, 0x0, 0x80100000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1129) {
  int f = 821274377;

  my_decimal decimal_check = {{0x1B0D05, 0x0, 0x0, 0xF0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1130) {
  int f = -1326209271;

  my_decimal decimal_check = {{0x1B0D05, 0x0, 0x0, 0x800F0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1131) {
  int f = 1267676138;

  my_decimal decimal_check = {{0x11E67D8, 0x0, 0x0, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1132) {
  int f = -879807510;

  my_decimal decimal_check = {{0x11E67D8, 0x0, 0x0, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1133) {
  int f = 1199528066;

  my_decimal decimal_check = {{0x63BE93, 0x0, 0x0, 0x20000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1134) {
  int f = -947955582;

  my_decimal decimal_check = {{0x63BE93, 0x0, 0x0, 0x80020000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1135) {
  int f = 1388777773;

  my_decimal decimal_check = {{0x88961720, 0x63, 0x0, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1136) {
  int f = -758705875;

  my_decimal decimal_check = {{0x88961720, 0x63, 0x0, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1137) {
  int f = 288366865;

  my_decimal decimal_check = {{0x1, 0x0, 0x0, 0x1C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1138) {
  int f = -1859116783;

  my_decimal decimal_check = {{0x1, 0x0, 0x0, 0x801C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1139) {
  int f = 376218778;

  my_decimal decimal_check = {{0x778, 0x0, 0x0, 0x1C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1140) {
  int f = -1771264870;

  my_decimal decimal_check = {{0x778, 0x0, 0x0, 0x801C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1141) {
  int f = 634355871;

  my_decimal decimal_check = {{0x36ECE9, 0x0, 0x0, 0x160000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1142) {
  int f = -1513127777;

  my_decimal decimal_check = {{0x36ECE9, 0x0, 0x0, 0x80160000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1143) {
  int f = 1054390949;

  my_decimal decimal_check = {{0x67583, 0x0, 0x0, 0x60000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1144) {
  int f = -1093092699;

  my_decimal decimal_check = {{0x67583, 0x0, 0x0, 0x80060000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1145) {
  int f = 1035379191;

  my_decimal decimal_check = {{0x88126B, 0x0, 0x0, 0x80000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1146) {
  int f = -1112104457;

  my_decimal decimal_check = {{0x88126B, 0x0, 0x0, 0x80080000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1147) {
  int f = 556626862;

  my_decimal decimal_check = {{0x59AC2A, 0x0, 0x0, 0x190000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1148) {
  int f = -1590856786;

  my_decimal decimal_check = {{0x59AC2A, 0x0, 0x0, 0x80190000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1149) {
  int f = 1259748621;

  my_decimal decimal_check = {{0x963D0D, 0x0, 0x0, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1150) {
  int f = -887735027;

  my_decimal decimal_check = {{0x963D0D, 0x0, 0x0, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1151) {
  int f = 1197734959;

  my_decimal decimal_check = {{0x590E82, 0x0, 0x0, 0x20000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1152) {
  int f = -949748689;

  my_decimal decimal_check = {{0x590E82, 0x0, 0x0, 0x80020000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1153) {
  int f = 1770230192;

  my_decimal decimal_check = {{0x94C00000, 0xDA419A4, 0x107236, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1154) {
  int f = -377253456;

  my_decimal decimal_check = {{0x94C00000, 0xDA419A4, 0x107236, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1155) {
  int f = 752716883;

  my_decimal decimal_check = {{0x6014C9, 0x0, 0x0, 0x120000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1156) {
  int f = -1394766765;

  my_decimal decimal_check = {{0x6014C9, 0x0, 0x0, 0x80120000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1157) {
  int f = 1186880338;

  my_decimal decimal_check = {{0x252DD6, 0x0, 0x0, 0x20000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1158) {
  int f = -960603310;

  my_decimal decimal_check = {{0x252DD6, 0x0, 0x0, 0x80020000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1159) {
  int f = 977129191;

  my_decimal decimal_check = {{0x6E7BA1, 0x0, 0x0, 0xA0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1160) {
  int f = -1170354457;

  my_decimal decimal_check = {{0x6E7BA1, 0x0, 0x0, 0x800A0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1161) {
  int f = 1307534376;

  my_decimal decimal_check = {{0x1DEC84F8, 0x0, 0x0, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1162) {
  int f = -839949272;

  my_decimal decimal_check = {{0x1DEC84F8, 0x0, 0x0, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1163) {
  int f = 1534404514;

  my_decimal decimal_check = {{0xEC7E5C00, 0xF527A2, 0x0, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1164) {
  int f = -613079134;

  my_decimal decimal_check = {{0xEC7E5C00, 0xF527A2, 0x0, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1165) {
  int f = 1322622783;

  my_decimal decimal_check = {{0x6ACFA0C0, 0x0, 0x0, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1166) {
  int f = -824860865;

  my_decimal decimal_check = {{0x6ACFA0C0, 0x0, 0x0, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1167) {
  int f = 1783835317;

  my_decimal decimal_check = {{0x97B00000, 0x6FE84883, 0x34CAAD, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1168) {
  int f = -363648331;

  my_decimal decimal_check = {{0x97B00000, 0x6FE84883, 0x34CAAD, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1169) {
  int f = 1682985260;

  my_decimal decimal_check = {{0x8F150000, 0x44B9B379, 0x341, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1170) {
  int f = -464498388;

  my_decimal decimal_check = {{0x8F150000, 0x44B9B379, 0x341, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1171) {
  int f = 1133665792;

  my_decimal decimal_check = {{0x2CAAF0, 0x0, 0x0, 0x40000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1172) {
  int f = -1013817856;

  my_decimal decimal_check = {{0x2CAAF0, 0x0, 0x0, 0x80040000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1173) {
  int f = 1076428625;

  my_decimal decimal_check = {{0x284AC7, 0x0, 0x0, 0x60000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1174) {
  int f = -1071055023;

  my_decimal decimal_check = {{0x284AC7, 0x0, 0x0, 0x80060000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1175) {
  int f = 1377068202;

  my_decimal decimal_check = {{0x192A6A00, 0x25, 0x0, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1176) {
  int f = -770415446;

  my_decimal decimal_check = {{0x192A6A00, 0x25, 0x0, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1177) {
  int f = 1501384086;

  my_decimal decimal_check = {{0x6FD6CE00, 0xFD4D9, 0x0, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1178) {
  int f = -646099562;

  my_decimal decimal_check = {{0x6FD6CE00, 0xFD4D9, 0x0, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1179) {
  int f = 1129346558;

  my_decimal decimal_check = {{0x1FCF01, 0x0, 0x0, 0x40000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1180) {
  int f = -1018137090;

  my_decimal decimal_check = {{0x1FCF01, 0x0, 0x0, 0x80040000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1181) {
  int f = 552694239;

  my_decimal decimal_check = {{0x3E697A, 0x0, 0x0, 0x190000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1182) {
  int f = -1594789409;

  my_decimal decimal_check = {{0x3E697A, 0x0, 0x0, 0x80190000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1183) {
  int f = 503884399;

  my_decimal decimal_check = {{0x6E65D1, 0x0, 0x0, 0x1B0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1184) {
  int f = -1643599249;

  my_decimal decimal_check = {{0x6E65D1, 0x0, 0x0, 0x801B0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1185) {
  int f = 610016268;

  my_decimal decimal_check = {{0x48D401, 0x0, 0x0, 0x170000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1186) {
  int f = -1537467380;

  my_decimal decimal_check = {{0x48D401, 0x0, 0x0, 0x80170000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1187) {
  int f = 1603464299;

  my_decimal decimal_check = {{0xF8176000, 0x25D8D6F5, 0x1, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1188) {
  int f = -544019349;

  my_decimal decimal_check = {{0xF8176000, 0x25D8D6F5, 0x1, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1189) {
  int f = 1434895983;

  my_decimal decimal_check = {{0xCDB26180, 0x10D8, 0x0, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1190) {
  int f = -712587665;

  my_decimal decimal_check = {{0xCDB26180, 0x10D8, 0x0, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1191) {
  int f = 1683015992;

  my_decimal decimal_check = {{0xFB990000, 0x24E59827, 0x343, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1192) {
  int f = -464467656;

  my_decimal decimal_check = {{0xFB990000, 0x24E59827, 0x343, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1193) {
  int f = 361793550;

  my_decimal decimal_check = {{0x248, 0x0, 0x0, 0x1C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1194) {
  int f = -1785690098;

  my_decimal decimal_check = {{0x248, 0x0, 0x0, 0x801C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1195) {
  int f = 460211307;

  my_decimal decimal_check = {{0x1E12D5, 0x0, 0x0, 0x1C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1196) {
  int f = -1687272341;

  my_decimal decimal_check = {{0x1E12D5, 0x0, 0x0, 0x801C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1197) {
  int f = 1482236884;

  my_decimal decimal_check = {{0x4F14DC00, 0x3648F, 0x0, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1198) {
  int f = -665246764;

  my_decimal decimal_check = {{0x4F14DC00, 0x3648F, 0x0, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1199) {
  int f = 690435708;

  my_decimal decimal_check = {{0x38A767, 0x0, 0x0, 0x140000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1200) {
  int f = -1457047940;

  my_decimal decimal_check = {{0x38A767, 0x0, 0x0, 0x80140000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1201) {
  int f = 425497893;

  my_decimal decimal_check = {{0x1BD77, 0x0, 0x0, 0x1C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1202) {
  int f = -1721985755;

  my_decimal decimal_check = {{0x1BD77, 0x0, 0x0, 0x801C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1203) {
  int f = 965691290;

  my_decimal decimal_check = {{0x29B32B, 0x0, 0x0, 0xA0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1204) {
  int f = -1181792358;

  my_decimal decimal_check = {{0x29B32B, 0x0, 0x0, 0x800A0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1205) {
  int f = 460046634;

  my_decimal decimal_check = {{0x1DC1A4, 0x0, 0x0, 0x1C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1206) {
  int f = -1687437014;

  my_decimal decimal_check = {{0x1DC1A4, 0x0, 0x0, 0x801C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1207) {
  int f = 802451343;

  my_decimal decimal_check = {{0x3AF678, 0x0, 0x0, 0x100000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1208) {
  int f = -1345032305;

  my_decimal decimal_check = {{0x3AF678, 0x0, 0x0, 0x80100000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1209) {
  int f = 1151825257;

  my_decimal decimal_check = {{0x147115, 0x0, 0x0, 0x30000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1210) {
  int f = -995658391;

  my_decimal decimal_check = {{0x147115, 0x0, 0x0, 0x80030000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1211) {
  int f = 819452149;

  my_decimal decimal_check = {{0x17F6C1, 0x0, 0x0, 0xF0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1212) {
  int f = -1328031499;

  my_decimal decimal_check = {{0x17F6C1, 0x0, 0x0, 0x800F0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1213) {
  int f = 890482120;

  my_decimal decimal_check = {{0x53F219, 0x0, 0x0, 0xD0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1214) {
  int f = -1257001528;

  my_decimal decimal_check = {{0x53F219, 0x0, 0x0, 0x800D0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1215) {
  int f = 1128373925;

  my_decimal decimal_check = {{0x1D8B45, 0x0, 0x0, 0x40000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1216) {
  int f = -1019109723;

  my_decimal decimal_check = {{0x1D8B45, 0x0, 0x0, 0x80040000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1217) {
  int f = 923527512;

  my_decimal decimal_check = {{0x7F3FAF, 0x0, 0x0, 0xC0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1218) {
  int f = -1223956136;

  my_decimal decimal_check = {{0x7F3FAF, 0x0, 0x0, 0x800C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1219) {
  int f = 671343419;

  my_decimal decimal_check = {{0x6FB692, 0x0, 0x0, 0x150000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1220) {
  int f = -1476140229;

  my_decimal decimal_check = {{0x6FB692, 0x0, 0x0, 0x80150000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1221) {
  int f = 1525135143;

  my_decimal decimal_check = {{0xC300A400, 0x73DB93, 0x0, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1222) {
  int f = -622348505;

  my_decimal decimal_check = {{0xC300A400, 0x73DB93, 0x0, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1223) {
  int f = 1716937010;

  my_decimal decimal_check = {{0x67280000, 0x4BEDFE47, 0x3598, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1224) {
  int f = -430546638;

  my_decimal decimal_check = {{0x67280000, 0x4BEDFE47, 0x3598, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1225) {
  int f = 1801818942;

  my_decimal decimal_check = {{0x19100000, 0x99BAB743, 0xE5933B, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1226) {
  int f = -345664706;

  my_decimal decimal_check = {{0x19100000, 0x99BAB743, 0xE5933B, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1227) {
  int f = 736844350;

  my_decimal decimal_check = {{0x28D3C, 0x0, 0x0, 0x110000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1228) {
  int f = -1410639298;

  my_decimal decimal_check = {{0x28D3C, 0x0, 0x0, 0x80110000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1229) {
  int f = 1582058068;

  my_decimal decimal_check = {{0x31C28000, 0x3312954C, 0x0, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1230) {
  int f = -565425580;

  my_decimal decimal_check = {{0x31C28000, 0x3312954C, 0x0, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1231) {
  int f = 912365069;

  my_decimal decimal_check = {{0x334AD7, 0x0, 0x0, 0xC0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1232) {
  int f = -1235118579;

  my_decimal decimal_check = {{0x334AD7, 0x0, 0x0, 0x800C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1233) {
  int f = 1796174635;

  my_decimal decimal_check = {{0x34B00000, 0x4CF7AFBF, 0x8F732D, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1234) {
  int f = -351309013;

  my_decimal decimal_check = {{0x34B00000, 0x4CF7AFBF, 0x8F732D, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1235) {
  int f = 427958922;

  my_decimal decimal_check = {{0x20D9C, 0x0, 0x0, 0x1C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1236) {
  int f = -1719524726;

  my_decimal decimal_check = {{0x20D9C, 0x0, 0x0, 0x801C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1237) {
  int f = 658006548;

  my_decimal decimal_check = {{0x3E78B, 0x0, 0x0, 0x140000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1238) {
  int f = -1489477100;

  my_decimal decimal_check = {{0x3E78B, 0x0, 0x0, 0x80140000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1239) {
  int f = 1245593235;

  my_decimal decimal_check = {{0x2F8FA5, 0x0, 0x0, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1240) {
  int f = -901890413;

  my_decimal decimal_check = {{0x2F8FA5, 0x0, 0x0, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1241) {
  int f = 1757620771;

  my_decimal decimal_check = {{0xB3180000, 0x18104CFE, 0x61951, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1242) {
  int f = -389862877;

  my_decimal decimal_check = {{0xB3180000, 0x18104CFE, 0x61951, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1243) {
  int f = 1380444513;

  my_decimal decimal_check = {{0xFA587A60, 0x31, 0x0, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1244) {
  int f = -767039135;

  my_decimal decimal_check = {{0xFA587A60, 0x31, 0x0, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1245) {
  int f = 1453766945;

  my_decimal decimal_check = {{0x90B6DD80, 0x535C, 0x0, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1246) {
  int f = -693716703;

  my_decimal decimal_check = {{0x90B6DD80, 0x535C, 0x0, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1247) {
  int f = 725393565;

  my_decimal decimal_check = {{0x66414F, 0x0, 0x0, 0x130000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1248) {
  int f = -1422090083;

  my_decimal decimal_check = {{0x66414F, 0x0, 0x0, 0x80130000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1249) {
  int f = 1389897798;

  my_decimal decimal_check = {{0x1422E860, 0x6C, 0x0, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1250) {
  int f = -757585850;

  my_decimal decimal_check = {{0x1422E860, 0x6C, 0x0, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1251) {
  int f = 1680067514;

  my_decimal decimal_check = {{0xAB180000, 0x2EF185A0, 0x28F, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1252) {
  int f = -467416134;

  my_decimal decimal_check = {{0xAB180000, 0x2EF185A0, 0x28F, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1253) {
  int f = 450466852;

  my_decimal decimal_check = {{0xDBB2C, 0x0, 0x0, 0x1C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1254) {
  int f = -1697016796;

  my_decimal decimal_check = {{0xDBB2C, 0x0, 0x0, 0x801C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1255) {
  int f = 989899542;

  my_decimal decimal_check = {{0x1DF53B, 0x0, 0x0, 0x90000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1256) {
  int f = -1157584106;

  my_decimal decimal_check = {{0x1DF53B, 0x0, 0x0, 0x80090000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1257) {
  int f = 679715529;

  my_decimal decimal_check = {{0x164CCC, 0x0, 0x0, 0x140000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1258) {
  int f = -1467768119;

  my_decimal decimal_check = {{0x164CCC, 0x0, 0x0, 0x80140000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1259) {
  int f = 1134717279;

  my_decimal decimal_check = {{0x319068, 0x0, 0x0, 0x40000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1260) {
  int f = -1012766369;

  my_decimal decimal_check = {{0x319068, 0x0, 0x0, 0x80040000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1261) {
  int f = 833644971;

  my_decimal decimal_check = {{0x4E57CF, 0x0, 0x0, 0xF0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1262) {
  int f = -1313838677;

  my_decimal decimal_check = {{0x4E57CF, 0x0, 0x0, 0x800F0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1263) {
  int f = 1316111055;

  my_decimal decimal_check = {{0x3C90B320, 0x0, 0x0, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1264) {
  int f = -831372593;

  my_decimal decimal_check = {{0x3C90B320, 0x0, 0x0, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1265) {
  int f = 836853257;

  my_decimal decimal_check = {{0x64154C, 0x0, 0x0, 0xF0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1266) {
  int f = -1310630391;

  my_decimal decimal_check = {{0x64154C, 0x0, 0x0, 0x800F0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1267) {
  int f = 494148192;

  my_decimal decimal_check = {{0x314BD5, 0x0, 0x0, 0x1B0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1268) {
  int f = -1653335456;

  my_decimal decimal_check = {{0x314BD5, 0x0, 0x0, 0x801B0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1269) {
  int f = 549334860;

  my_decimal decimal_check = {{0x31295F, 0x0, 0x0, 0x190000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1270) {
  int f = -1598148788;

  my_decimal decimal_check = {{0x31295F, 0x0, 0x0, 0x80190000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1271) {
  int f = 331158040;

  my_decimal decimal_check = {{0x30, 0x0, 0x0, 0x1C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1272) {
  int f = -1816325608;

  my_decimal decimal_check = {{0x30, 0x0, 0x0, 0x801C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1273) {
  int f = 1072061442;

  my_decimal decimal_check = {{0x1B7603, 0x0, 0x0, 0x60000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1274) {
  int f = -1075422206;

  my_decimal decimal_check = {{0x1B7603, 0x0, 0x0, 0x80060000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1275) {
  int f = 526263610;

  my_decimal decimal_check = {{0x47C770, 0x0, 0x0, 0x1A0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1276) {
  int f = -1621220038;

  my_decimal decimal_check = {{0x47C770, 0x0, 0x0, 0x801A0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1277) {
  int f = 621325014;

  my_decimal decimal_check = {{0x2E4E, 0x0, 0x0, 0x140000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1278) {
  int f = -1526158634;

  my_decimal decimal_check = {{0x2E4E, 0x0, 0x0, 0x80140000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1279) {
  int f = 861236673;

  my_decimal decimal_check = {{0x4BD33B, 0x0, 0x0, 0xE0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1280) {
  int f = -1286246975;

  my_decimal decimal_check = {{0x4BD33B, 0x0, 0x0, 0x800E0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1281) {
  int f = 1809556930;

  my_decimal decimal_check = {{0x2BE00000, 0x7008F9DD, 0x1B74B81, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1282) {
  int f = -337926718;

  my_decimal decimal_check = {{0x2BE00000, 0x7008F9DD, 0x1B74B81, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1283) {
  int f = 1506039350;

  my_decimal decimal_check = {{0xD3A4B400, 0x188AC6, 0x0, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1284) {
  int f = -641444298;

  my_decimal decimal_check = {{0xD3A4B400, 0x188AC6, 0x0, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1285) {
  int f = 451244253;

  my_decimal decimal_check = {{0xE7AD1, 0x0, 0x0, 0x1C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1286) {
  int f = -1696239395;

  my_decimal decimal_check = {{0xE7AD1, 0x0, 0x0, 0x801C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1287) {
  int f = 827744229;

  my_decimal decimal_check = {{0x2F99C9, 0x0, 0x0, 0xF0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1288) {
  int f = -1319739419;

  my_decimal decimal_check = {{0x2F99C9, 0x0, 0x0, 0x800F0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1289) {
  int f = 1162196065;

  my_decimal decimal_check = {{0x30448A, 0x0, 0x0, 0x30000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1290) {
  int f = -985287583;

  my_decimal decimal_check = {{0x30448A, 0x0, 0x0, 0x80030000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1291) {
  int f = 393741879;

  my_decimal decimal_check = {{0x1F4E, 0x0, 0x0, 0x1C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1292) {
  int f = -1753741769;

  my_decimal decimal_check = {{0x1F4E, 0x0, 0x0, 0x801C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1293) {
  int f = 1828719802;

  my_decimal decimal_check = {{0x66400000, 0xDD7B971F, 0x800CBB1, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1294) {
  int f = -318763846;

  my_decimal decimal_check = {{0x66400000, 0xDD7B971F, 0x800CBB1, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1295) {
  int f = 1431156567;

  my_decimal decimal_check = {{0x7593ED80, 0xCDB, 0x0, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1296) {
  int f = -716327081;

  my_decimal decimal_check = {{0x7593ED80, 0xCDB, 0x0, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1297) {
  int f = 1587779489;

  my_decimal decimal_check = {{0xF0132000, 0x51CBD0B1, 0x0, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1298) {
  int f = -559704159;

  my_decimal decimal_check = {{0xF0132000, 0x51CBD0B1, 0x0, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1299) {
  int f = 520234477;

  my_decimal decimal_check = {{0x2A0D9A, 0x0, 0x0, 0x1A0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1300) {
  int f = -1627249171;

  my_decimal decimal_check = {{0x2A0D9A, 0x0, 0x0, 0x801A0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1301) {
  int f = 1436437400;

  my_decimal decimal_check = {{0x73135100, 0x13C9, 0x0, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1302) {
  int f = -711046248;

  my_decimal decimal_check = {{0x73135100, 0x13C9, 0x0, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1303) {
  int f = 1491819278;

  my_decimal decimal_check = {{0x53A91400, 0x75AD8, 0x0, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1304) {
  int f = -655664370;

  my_decimal decimal_check = {{0x53A91400, 0x75AD8, 0x0, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1305) {
  int f = 1360189410;

  my_decimal decimal_check = {{0x2D7E2F30, 0x9, 0x0, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1306) {
  int f = -787294238;

  my_decimal decimal_check = {{0x2D7E2F30, 0x9, 0x0, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1307) {
  int f = 1803016908;

  my_decimal decimal_check = {{0x7AB00000, 0x1B610E7E, 0xF7DACB, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1308) {
  int f = -344466740;

  my_decimal decimal_check = {{0x7AB00000, 0x1B610E7E, 0xF7DACB, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1309) {
  int f = 499188195;

  my_decimal decimal_check = {{0x4DF47F, 0x0, 0x0, 0x1B0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1310) {
  int f = -1648295453;

  my_decimal decimal_check = {{0x4DF47F, 0x0, 0x0, 0x801B0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1311) {
  int f = 611426637;

  my_decimal decimal_check = {{0x4FF2DD, 0x0, 0x0, 0x170000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1312) {
  int f = -1536057011;

  my_decimal decimal_check = {{0x4FF2DD, 0x0, 0x0, 0x80170000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1313) {
  int f = 1078297604;

  my_decimal decimal_check = {{0x2F1767, 0x0, 0x0, 0x60000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1314) {
  int f = -1069186044;

  my_decimal decimal_check = {{0x2F1767, 0x0, 0x0, 0x80060000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1315) {
  int f = 1292637718;

  my_decimal decimal_check = {{0x8C1615C, 0x0, 0x0, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1316) {
  int f = -854845930;

  my_decimal decimal_check = {{0x8C1615C, 0x0, 0x0, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1317) {
  int f = 970538195;

  my_decimal decimal_check = {{0x3F3976, 0x0, 0x0, 0xA0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1318) {
  int f = -1176945453;

  my_decimal decimal_check = {{0x3F3976, 0x0, 0x0, 0x800A0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1319) {
  int f = 1029742392;

  my_decimal decimal_check = {{0x53AD9E, 0x0, 0x0, 0x80000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1320) {
  int f = -1117741256;

  my_decimal decimal_check = {{0x53AD9E, 0x0, 0x0, 0x80080000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1321) {
  int f = 375077468;

  my_decimal decimal_check = {{0x6EB, 0x0, 0x0, 0x1C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1322) {
  int f = -1772406180;

  my_decimal decimal_check = {{0x6EB, 0x0, 0x0, 0x801C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1323) {
  int f = 1458567228;

  my_decimal decimal_check = {{0x1CE16F00, 0x77FC, 0x0, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1324) {
  int f = -688916420;

  my_decimal decimal_check = {{0x1CE16F00, 0x77FC, 0x0, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1325) {
  int f = 437973350;

  my_decimal decimal_check = {{0x4E39F, 0x0, 0x0, 0x1C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1326) {
  int f = -1709510298;

  my_decimal decimal_check = {{0x4E39F, 0x0, 0x0, 0x801C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1327) {
  int f = 1346794883;

  my_decimal decimal_check = {{0x19D60BC0, 0x3, 0x0, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1328) {
  int f = -800688765;

  my_decimal decimal_check = {{0x19D60BC0, 0x3, 0x0, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1329) {
  int f = 1395683098;

  my_decimal decimal_check = {{0x6F19B5C0, 0xB0, 0x0, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1330) {
  int f = -751800550;

  my_decimal decimal_check = {{0x6F19B5C0, 0xB0, 0x0, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1331) {
  int f = 1775397346;

  my_decimal decimal_check = {{0xD1000000, 0xFB5E1571, 0x1A4D3B, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1332) {
  int f = -372086302;

  my_decimal decimal_check = {{0xD1000000, 0xFB5E1571, 0x1A4D3B, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1333) {
  int f = 886175923;

  my_decimal decimal_check = {{0x3BAD70, 0x0, 0x0, 0xD0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1334) {
  int f = -1261307725;

  my_decimal decimal_check = {{0x3BAD70, 0x0, 0x0, 0x800D0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1335) {
  int f = 1313762920;

  my_decimal decimal_check = {{0x339B99EC, 0x0, 0x0, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1336) {
  int f = -833720728;

  my_decimal decimal_check = {{0x339B99EC, 0x0, 0x0, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1337) {
  int f = 1745494140;

  my_decimal decimal_check = {{0x5D7C0000, 0xECEA0BEC, 0x22881, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1338) {
  int f = -401989508;

  my_decimal decimal_check = {{0x5D7C0000, 0xECEA0BEC, 0x22881, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1339) {
  int f = 1256992198;

  my_decimal decimal_check = {{0x7616E3, 0x0, 0x0, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1340) {
  int f = -890491450;

  my_decimal decimal_check = {{0x7616E3, 0x0, 0x0, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1341) {
  int f = 1398288277;

  my_decimal decimal_check = {{0x2F948B00, 0xD8, 0x0, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1342) {
  int f = -749195371;

  my_decimal decimal_check = {{0x2F948B00, 0xD8, 0x0, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1343) {
  int f = 1276003194;

  my_decimal decimal_check = {{0x2390DE4, 0x0, 0x0, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1344) {
  int f = -871480454;

  my_decimal decimal_check = {{0x2390DE4, 0x0, 0x0, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1345) {
  int f = 1364618558;

  my_decimal decimal_check = {{0x66D3EE60, 0xD, 0x0, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1346) {
  int f = -782865090;

  my_decimal decimal_check = {{0x66D3EE60, 0xD, 0x0, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1347) {
  int f = 1354754525;

  my_decimal decimal_check = {{0xFF4EF0C0, 0x5, 0x0, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1348) {
  int f = -792729123;

  my_decimal decimal_check = {{0xFF4EF0C0, 0x5, 0x0, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1349) {
  int f = 994020955;

  my_decimal decimal_check = {{0x2C99A2, 0x0, 0x0, 0x90000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1350) {
  int f = -1153462693;

  my_decimal decimal_check = {{0x2C99A2, 0x0, 0x0, 0x80090000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1351) {
  int f = 1809566071;

  my_decimal decimal_check = {{0x65B00000, 0x81DCD5DF, 0x1B792EE, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1352) {
  int f = -337917577;

  my_decimal decimal_check = {{0x65B00000, 0x81DCD5DF, 0x1B792EE, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1353) {
  int f = 935292431;

  my_decimal decimal_check = {{0x22D226, 0x0, 0x0, 0xB0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1354) {
  int f = -1212191217;

  my_decimal decimal_check = {{0x22D226, 0x0, 0x0, 0x800B0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1355) {
  int f = 623726278;

  my_decimal decimal_check = {{0x16EFE5, 0x0, 0x0, 0x160000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1356) {
  int f = -1523757370;

  my_decimal decimal_check = {{0x16EFE5, 0x0, 0x0, 0x80160000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1357) {
  int f = 1121182151;

  my_decimal decimal_check = {{0x19DD5, 0x0, 0x0, 0x30000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1358) {
  int f = -1026301497;

  my_decimal decimal_check = {{0x19DD5, 0x0, 0x0, 0x80030000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1359) {
  int f = 993859481;

  my_decimal decimal_check = {{0x2C06C6, 0x0, 0x0, 0x90000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1360) {
  int f = -1153624167;

  my_decimal decimal_check = {{0x2C06C6, 0x0, 0x0, 0x80090000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1361) {
  int f = 1409332362;

  my_decimal decimal_check = {{0xD22796C0, 0x202, 0x0, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1362) {
  int f = -738151286;

  my_decimal decimal_check = {{0xD22796C0, 0x202, 0x0, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1363) {
  int f = 577294934;

  my_decimal decimal_check = {{0x302579, 0x0, 0x0, 0x180000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1364) {
  int f = -1570188714;

  my_decimal decimal_check = {{0x302579, 0x0, 0x0, 0x80180000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1365) {
  int f = 968493311;

  my_decimal decimal_check = {{0x3624B3, 0x0, 0x0, 0xA0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1366) {
  int f = -1178990337;

  my_decimal decimal_check = {{0x3624B3, 0x0, 0x0, 0x800A0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1367) {
  int f = 1717465703;

  my_decimal decimal_check = {{0x39020000, 0x995E576F, 0x379C, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1368) {
  int f = -430017945;

  my_decimal decimal_check = {{0x39020000, 0x995E576F, 0x379C, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1369) {
  int f = 1264653138;

  my_decimal decimal_check = {{0xE11356, 0x0, 0x0, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1370) {
  int f = -882830510;

  my_decimal decimal_check = {{0xE11356, 0x0, 0x0, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1371) {
  int f = 899810343;

  my_decimal decimal_check = {{0x126B4B, 0x0, 0x0, 0xC0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1372) {
  int f = -1247673305;

  my_decimal decimal_check = {{0x126B4B, 0x0, 0x0, 0x800C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1373) {
  int f = 1513906295;

  my_decimal decimal_check = {{0xC2664000, 0x2F181D, 0x0, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1374) {
  int f = -633577353;

  my_decimal decimal_check = {{0xC2664000, 0x2F181D, 0x0, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1375) {
  int f = 600209608;

  my_decimal decimal_check = {{0x20D59C, 0x0, 0x0, 0x170000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1376) {
  int f = -1547274040;

  my_decimal decimal_check = {{0x20D59C, 0x0, 0x0, 0x80170000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1377) {
  int f = 1544556039;

  my_decimal decimal_check = {{0xC628A800, 0x2403820, 0x0, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1378) {
  int f = -602927609;

  my_decimal decimal_check = {{0xC628A800, 0x2403820, 0x0, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1379) {
  int f = 1504281481;

  my_decimal decimal_check = {{0x23BDC200, 0x153071, 0x0, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1380) {
  int f = -643202167;

  my_decimal decimal_check = {{0x23BDC200, 0x153071, 0x0, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1381) {
  int f = 810845087;

  my_decimal decimal_check = {{0xBCC02, 0x0, 0x0, 0xF0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1382) {
  int f = -1336638561;

  my_decimal decimal_check = {{0xBCC02, 0x0, 0x0, 0x800F0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1383) {
  int f = 1337408374;

  my_decimal decimal_check = {{0x6E76ED18, 0x1, 0x0, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1384) {
  int f = -810075274;

  my_decimal decimal_check = {{0x6E76ED18, 0x1, 0x0, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1385) {
  int f = 1113710066;

  my_decimal decimal_check = {{0x562952, 0x0, 0x0, 0x50000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1386) {
  int f = -1033773582;

  my_decimal decimal_check = {{0x562952, 0x0, 0x0, 0x80050000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1387) {
  int f = 1157955880;

  my_decimal decimal_check = {{0x2078C8, 0x0, 0x0, 0x30000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1388) {
  int f = -989527768;

  my_decimal decimal_check = {{0x2078C8, 0x0, 0x0, 0x80030000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1389) {
  int f = 492251376;

  my_decimal decimal_check = {{0x2B7382, 0x0, 0x0, 0x1B0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1390) {
  int f = -1655232272;

  my_decimal decimal_check = {{0x2B7382, 0x0, 0x0, 0x801B0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1391) {
  int f = 348693264;

  my_decimal decimal_check = {{0xCB, 0x0, 0x0, 0x1C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1392) {
  int f = -1798790384;

  my_decimal decimal_check = {{0xCB, 0x0, 0x0, 0x801C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1393) {
  int f = 1057380954;

  my_decimal decimal_check = {{0x5014A2, 0x0, 0x0, 0x70000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1394) {
  int f = -1090102694;

  my_decimal decimal_check = {{0x5014A2, 0x0, 0x0, 0x80070000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1395) {
  int f = 662434020;

  my_decimal decimal_check = {{0x3559BF, 0x0, 0x0, 0x150000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1396) {
  int f = -1485049628;

  my_decimal decimal_check = {{0x3559BF, 0x0, 0x0, 0x80150000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1397) {
  int f = 981657173;

  my_decimal decimal_check = {{0x986329, 0x0, 0x0, 0xA0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1398) {
  int f = -1165826475;

  my_decimal decimal_check = {{0x986329, 0x0, 0x0, 0x800A0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1399) {
  int f = 953171976;

  my_decimal decimal_check = {{0xF26F6, 0x0, 0x0, 0xA0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1400) {
  int f = -1194311672;

  my_decimal decimal_check = {{0xF26F6, 0x0, 0x0, 0x800A0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1401) {
  int f = 1065550606;

  my_decimal decimal_check = {{0xF9E2B, 0x0, 0x0, 0x60000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1402) {
  int f = -1081933042;

  my_decimal decimal_check = {{0xF9E2B, 0x0, 0x0, 0x80060000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1403) {
  int f = 512660444;

  my_decimal decimal_check = {{0x1708DF, 0x0, 0x0, 0x1A0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1404) {
  int f = -1634823204;

  my_decimal decimal_check = {{0x1708DF, 0x0, 0x0, 0x801A0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1405) {
  int f = 1243647077;

  my_decimal decimal_check = {{0x282319, 0x0, 0x0, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1406) {
  int f = -903836571;

  my_decimal decimal_check = {{0x282319, 0x0, 0x0, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1407) {
  int f = 336879461;

  my_decimal decimal_check = {{0x4B, 0x0, 0x0, 0x1C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1408) {
  int f = -1810604187;

  my_decimal decimal_check = {{0x4B, 0x0, 0x0, 0x801C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1409) {
  int f = 679930850;

  my_decimal decimal_check = {{0x16DB49, 0x0, 0x0, 0x140000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1410) {
  int f = -1467552798;

  my_decimal decimal_check = {{0x16DB49, 0x0, 0x0, 0x80140000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1411) {
  int f = 1726807463;

  my_decimal decimal_check = {{0xFB780000, 0xD3D92073, 0x767E, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1412) {
  int f = -420676185;

  my_decimal decimal_check = {{0xFB780000, 0xD3D92073, 0x767E, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1413) {
  int f = 1693573979;

  my_decimal decimal_check = {{0x1E660000, 0x1AC98279, 0x78F, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1414) {
  int f = -453909669;

  my_decimal decimal_check = {{0x1E660000, 0x1AC98279, 0x78F, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1415) {
  int f = 1563419535;

  my_decimal decimal_check = {{0xD0CB2000, 0xAFE38F2, 0x0, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1416) {
  int f = -584064113;

  my_decimal decimal_check = {{0xD0CB2000, 0xAFE38F2, 0x0, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1417) {
  int f = 798310907;

  my_decimal decimal_check = {{0x296D66, 0x0, 0x0, 0x100000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1418) {
  int f = -1349172741;

  my_decimal decimal_check = {{0x296D66, 0x0, 0x0, 0x80100000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1419) {
  int f = 1816276470;

  my_decimal decimal_check = {{0xA5A00000, 0x437BCE0A, 0x308B7D7, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1420) {
  int f = -331207178;

  my_decimal decimal_check = {{0xA5A00000, 0x437BCE0A, 0x308B7D7, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1421) {
  int f = 1234118856;

  my_decimal decimal_check = {{0x11E519, 0x0, 0x0, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1422) {
  int f = -913364792;

  my_decimal decimal_check = {{0x11E519, 0x0, 0x0, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1423) {
  int f = 460663496;

  my_decimal decimal_check = {{0x1EF1C7, 0x0, 0x0, 0x1C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1424) {
  int f = -1686820152;

  my_decimal decimal_check = {{0x1EF1C7, 0x0, 0x0, 0x801C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1425) {
  int f = 1737828826;

  my_decimal decimal_check = {{0x6B040000, 0xB05D1E04, 0x12A53, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1426) {
  int f = -409654822;

  my_decimal decimal_check = {{0x6B040000, 0xB05D1E04, 0x12A53, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1427) {
  int f = 1543051972;

  my_decimal decimal_check = {{0xC8A53000, 0x1F23588, 0x0, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1428) {
  int f = -604431676;

  my_decimal decimal_check = {{0xC8A53000, 0x1F23588, 0x0, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1429) {
  int f = 1178394680;

  my_decimal decimal_check = {{0x1271E5, 0x0, 0x0, 0x20000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1430) {
  int f = -969088968;

  my_decimal decimal_check = {{0x1271E5, 0x0, 0x0, 0x80020000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1431) {
  int f = 1355767183;

  my_decimal decimal_check = {{0x7AEC72C0, 0x6, 0x0, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1432) {
  int f = -791716465;

  my_decimal decimal_check = {{0x7AEC72C0, 0x6, 0x0, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1433) {
  int f = 487777479;

  my_decimal decimal_check = {{0x1DAA39, 0x0, 0x0, 0x1B0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1434) {
  int f = -1659706169;

  my_decimal decimal_check = {{0x1DAA39, 0x0, 0x0, 0x801B0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1435) {
  int f = 286880906;

  my_decimal decimal_check = {{0x1, 0x0, 0x0, 0x1C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1436) {
  int f = -1860602742;

  my_decimal decimal_check = {{0x1, 0x0, 0x0, 0x801C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1437) {
  int f = 1648515003;

  my_decimal decimal_check = {{0x2BE8C000, 0x95EEC0BA, 0x30, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1438) {
  int f = -498968645;

  my_decimal decimal_check = {{0x2BE8C000, 0x95EEC0BA, 0x30, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1439) {
  int f = 501964925;

  my_decimal decimal_check = {{0x5F1167, 0x0, 0x0, 0x1B0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1440) {
  int f = -1645518723;

  my_decimal decimal_check = {{0x5F1167, 0x0, 0x0, 0x801B0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1441) {
  int f = 1819475701;

  my_decimal decimal_check = {{0xAA000000, 0x664C99F6, 0x3CBFBC9, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1442) {
  int f = -328007947;

  my_decimal decimal_check = {{0xAA000000, 0x664C99F6, 0x3CBFBC9, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1443) {
  int f = 1843950966;

  my_decimal decimal_check = {{0xDF600000, 0xFCEE53A6, 0x1D0EAEA5, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1444) {
  int f = -303532682;

  my_decimal decimal_check = {
      {0xDF600000, 0xFCEE53A6, 0x1D0EAEA5, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1445) {
  int f = 1318802923;

  my_decimal decimal_check = {{0x4DAAF710, 0x0, 0x0, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1446) {
  int f = -828680725;

  my_decimal decimal_check = {{0x4DAAF710, 0x0, 0x0, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1447) {
  int f = 1799197309;

  my_decimal decimal_check = {{0xE8C00000, 0xA4731590, 0xBD927F, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1448) {
  int f = -348286339;

  my_decimal decimal_check = {{0xE8C00000, 0xA4731590, 0xBD927F, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1449) {
  int f = 443850673;

  my_decimal decimal_check = {{0xC59B, 0x0, 0x0, 0x1B0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1450) {
  int f = -1703632975;

  my_decimal decimal_check = {{0xC59B, 0x0, 0x0, 0x801B0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1451) {
  int f = 1627253162;

  my_decimal decimal_check = {{0x1144C000, 0xEF4D3025, 0x7, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1452) {
  int f = -520230486;

  my_decimal decimal_check = {{0x1144C000, 0xEF4D3025, 0x7, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1453) {
  int f = 1728666387;

  my_decimal decimal_check = {{0x57A40000, 0x129203BD, 0x895B, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1454) {
  int f = -418817261;

  my_decimal decimal_check = {{0x57A40000, 0x129203BD, 0x895B, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1455) {
  int f = 1764647327;

  my_decimal decimal_check = {{0xC4200000, 0xE2D23BE3, 0xAE619, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1456) {
  int f = -382836321;

  my_decimal decimal_check = {{0xC4200000, 0xE2D23BE3, 0xAE619, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1457) {
  int f = 868595319;

  my_decimal decimal_check = {{0x8C7BBE, 0x0, 0x0, 0xE0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1458) {
  int f = -1278888329;

  my_decimal decimal_check = {{0x8C7BBE, 0x0, 0x0, 0x800E0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1459) {
  int f = 651419861;

  my_decimal decimal_check = {{0x166EF9, 0x0, 0x0, 0x150000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1460) {
  int f = -1496063787;

  my_decimal decimal_check = {{0x166EF9, 0x0, 0x0, 0x80150000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1461) {
  int f = 741500072;

  my_decimal decimal_check = {{0x3DE48, 0x0, 0x0, 0x110000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1462) {
  int f = -1405983576;

  my_decimal decimal_check = {{0x3DE48, 0x0, 0x0, 0x80110000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1463) {
  int f = 1830843061;

  my_decimal decimal_check = {{0x18200000, 0xAFF1E4ED, 0xA072B49, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1464) {
  int f = -316640587;

  my_decimal decimal_check = {{0x18200000, 0xAFF1E4ED, 0xA072B49, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1465) {
  int f = 1191665147;

  my_decimal decimal_check = {{0x34E0B6, 0x0, 0x0, 0x20000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1466) {
  int f = -955818501;

  my_decimal decimal_check = {{0x34E0B6, 0x0, 0x0, 0x80020000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1467) {
  int f = 1734383433;

  my_decimal decimal_check = {{0xC8440000, 0x4BA07311, 0xE097, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1468) {
  int f = -413100215;

  my_decimal decimal_check = {{0xC8440000, 0x4BA07311, 0xE097, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1469) {
  int f = 1477904917;

  my_decimal decimal_check = {{0x52249E00, 0x25C28, 0x0, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1470) {
  int f = -669578731;

  my_decimal decimal_check = {{0x52249E00, 0x25C28, 0x0, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1471) {
  int f = 894375480;

  my_decimal decimal_check = {{0x75B718, 0x0, 0x0, 0xD0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1472) {
  int f = -1253108168;

  my_decimal decimal_check = {{0x75B718, 0x0, 0x0, 0x800D0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1473) {
  int f = 891632507;

  my_decimal decimal_check = {{0x5DEC79, 0x0, 0x0, 0xD0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1474) {
  int f = -1255851141;

  my_decimal decimal_check = {{0x5DEC79, 0x0, 0x0, 0x800D0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1475) {
  int f = 629317413;

  my_decimal decimal_check = {{0x229345, 0x0, 0x0, 0x160000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1476) {
  int f = -1518166235;

  my_decimal decimal_check = {{0x229345, 0x0, 0x0, 0x80160000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1477) {
  int f = 1035238415;

  my_decimal decimal_check = {{0x8678B5, 0x0, 0x0, 0x80000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1478) {
  int f = -1112245233;

  my_decimal decimal_check = {{0x8678B5, 0x0, 0x0, 0x80080000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1479) {
  int f = 1095830324;

  my_decimal decimal_check = {{0x13EF9C, 0x0, 0x0, 0x50000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1480) {
  int f = -1051653324;

  my_decimal decimal_check = {{0x13EF9C, 0x0, 0x0, 0x80050000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1481) {
  int f = 764221014;

  my_decimal decimal_check = {{0x187988, 0x0, 0x0, 0x110000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1482) {
  int f = -1383262634;

  my_decimal decimal_check = {{0x187988, 0x0, 0x0, 0x80110000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1483) {
  int f = 1516860018;

  my_decimal decimal_check = {{0x757D8800, 0x3A5C9D, 0x0, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1484) {
  int f = -630623630;

  my_decimal decimal_check = {{0x757D8800, 0x3A5C9D, 0x0, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1485) {
  int f = 1359883351;

  my_decimal decimal_check = {{0xE2C57610, 0x8, 0x0, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1486) {
  int f = -787600297;

  my_decimal decimal_check = {{0xE2C57610, 0x8, 0x0, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1487) {
  int f = 1294652828;

  my_decimal decimal_check = {{0xAAD59E4, 0x0, 0x0, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1488) {
  int f = -852830820;

  my_decimal decimal_check = {{0xAAD59E4, 0x0, 0x0, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1489) {
  int f = 1836535883;

  my_decimal decimal_check = {{0x52C00000, 0x73547746, 0xF7504C5, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1490) {
  int f = -310947765;

  my_decimal decimal_check = {{0x52C00000, 0x73547746, 0xF7504C5, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1491) {
  int f = 347885152;

  my_decimal decimal_check = {{0x13, 0x0, 0x0, 0x1B0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1492) {
  int f = -1799598496;

  my_decimal decimal_check = {{0x13, 0x0, 0x0, 0x801B0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1493) {
  int f = 1165952806;

  my_decimal decimal_check = {{0x3E433F, 0x0, 0x0, 0x30000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1494) {
  int f = -981530842;

  my_decimal decimal_check = {{0x3E433F, 0x0, 0x0, 0x80030000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1495) {
  int f = 1137031352;

  my_decimal decimal_check = {{0x3C56FF, 0x0, 0x0, 0x40000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1496) {
  int f = -1010452296;

  my_decimal decimal_check = {{0x3C56FF, 0x0, 0x0, 0x80040000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1497) {
  int f = 1537545850;

  my_decimal decimal_check = {{0x47A2A400, 0x14A2CF4, 0x0, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1498) {
  int f = -609937798;

  my_decimal decimal_check = {{0x47A2A400, 0x14A2CF4, 0x0, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1499) {
  int f = 694468843;

  my_decimal decimal_check = {{0x7C01F, 0x0, 0x0, 0x130000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1500) {
  int f = -1453014805;

  my_decimal decimal_check = {{0x7C01F, 0x0, 0x0, 0x80130000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1501) {
  int f = 1418900435;

  my_decimal decimal_check = {{0x9E91E640, 0x495, 0x0, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1502) {
  int f = -728583213;

  my_decimal decimal_check = {{0x9E91E640, 0x495, 0x0, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1503) {
  int f = 776592218;

  my_decimal decimal_check = {{0x46087D, 0x0, 0x0, 0x110000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1504) {
  int f = -1370891430;

  my_decimal decimal_check = {{0x46087D, 0x0, 0x0, 0x80110000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1505) {
  int f = 563515059;

  my_decimal decimal_check = {{0xF9139, 0x0, 0x0, 0x180000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1506) {
  int f = -1583968589;

  my_decimal decimal_check = {{0xF9139, 0x0, 0x0, 0x80180000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1507) {
  int f = 494173026;

  my_decimal decimal_check = {{0x315F6C, 0x0, 0x0, 0x1B0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1508) {
  int f = -1653310622;

  my_decimal decimal_check = {{0x315F6C, 0x0, 0x0, 0x801B0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1509) {
  int f = 691680925;

  my_decimal decimal_check = {{0x3F176F, 0x0, 0x0, 0x140000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1510) {
  int f = -1455802723;

  my_decimal decimal_check = {{0x3F176F, 0x0, 0x0, 0x80140000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1511) {
  int f = 796361507;

  my_decimal decimal_check = {{0x225967, 0x0, 0x0, 0x100000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1512) {
  int f = -1351122141;

  my_decimal decimal_check = {{0x225967, 0x0, 0x0, 0x80100000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1513) {
  int f = 760230779;

  my_decimal decimal_check = {{0x120EFE, 0x0, 0x0, 0x110000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1514) {
  int f = -1387252869;

  my_decimal decimal_check = {{0x120EFE, 0x0, 0x0, 0x80110000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1515) {
  int f = 1002434418;

  my_decimal decimal_check = {{0x59607A, 0x0, 0x0, 0x90000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1516) {
  int f = -1145049230;

  my_decimal decimal_check = {{0x59607A, 0x0, 0x0, 0x80090000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1517) {
  int f = 1459402045;

  my_decimal decimal_check = {{0xA0353D00, 0x7E5A, 0x0, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1518) {
  int f = -688081603;

  my_decimal decimal_check = {{0xA0353D00, 0x7E5A, 0x0, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1519) {
  int f = 627439554;

  my_decimal decimal_check = {{0x1E6F9D, 0x0, 0x0, 0x160000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1520) {
  int f = -1520044094;

  my_decimal decimal_check = {{0x1E6F9D, 0x0, 0x0, 0x80160000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1521) {
  int f = 1556125727;

  my_decimal decimal_check = {{0xBAE9A000, 0x604C0EF, 0x0, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1522) {
  int f = -591357921;

  my_decimal decimal_check = {{0xBAE9A000, 0x604C0EF, 0x0, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1523) {
  int f = 1486911301;

  my_decimal decimal_check = {{0x2AC66A00, 0x503BA, 0x0, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1524) {
  int f = -660572347;

  my_decimal decimal_check = {{0x2AC66A00, 0x503BA, 0x0, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1525) {
  int f = 692527778;

  my_decimal decimal_check = {{0x43783C, 0x0, 0x0, 0x140000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1526) {
  int f = -1454955870;

  my_decimal decimal_check = {{0x43783C, 0x0, 0x0, 0x80140000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1527) {
  int f = 1704875696;

  my_decimal decimal_check = {{0x14A70000, 0xD60EE992, 0x13CA, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1528) {
  int f = -442607952;

  my_decimal decimal_check = {{0x14A70000, 0xD60EE992, 0x13CA, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1529) {
  int f = 1080868568;

  my_decimal decimal_check = {{0x3871CC, 0x0, 0x0, 0x60000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1530) {
  int f = -1066615080;

  my_decimal decimal_check = {{0x3871CC, 0x0, 0x0, 0x80060000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1531) {
  int f = 961260445;

  my_decimal decimal_check = {{0x1DA350, 0x0, 0x0, 0xA0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1532) {
  int f = -1186223203;

  my_decimal decimal_check = {{0x1DA350, 0x0, 0x0, 0x800A0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1533) {
  int f = 818594392;

  my_decimal decimal_check = {{0x1682C3, 0x0, 0x0, 0xF0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1534) {
  int f = -1328889256;

  my_decimal decimal_check = {{0x1682C3, 0x0, 0x0, 0x800F0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1535) {
  int f = 1561430043;

  my_decimal decimal_check = {{0xFD803800, 0x91881A6, 0x0, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1536) {
  int f = -586053605;

  my_decimal decimal_check = {{0xFD803800, 0x91881A6, 0x0, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1537) {
  int f = 1614743097;

  my_decimal decimal_check = {{0x3EAE2000, 0xFC18E5E1, 0x2, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1538) {
  int f = -532740551;

  my_decimal decimal_check = {{0x3EAE2000, 0xFC18E5E1, 0x2, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1539) {
  int f = 1842003850;

  my_decimal decimal_check = {{0x4A00000, 0x991CAE08, 0x1957F13C, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1540) {
  int f = -305479798;

  my_decimal decimal_check = {{0x4A00000, 0x991CAE08, 0x1957F13C, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1541) {
  int f = 461838238;

  my_decimal decimal_check = {{0x221A22, 0x0, 0x0, 0x1C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1542) {
  int f = -1685645410;

  my_decimal decimal_check = {{0x221A22, 0x0, 0x0, 0x801C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1543) {
  int f = 1416444716;

  my_decimal decimal_check = {{0xECB0B400, 0x3B4, 0x0, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1544) {
  int f = -731038932;

  my_decimal decimal_check = {{0xECB0B400, 0x3B4, 0x0, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1545) {
  int f = 818015749;

  my_decimal decimal_check = {{0x1587D1, 0x0, 0x0, 0xF0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1546) {
  int f = -1329467899;

  my_decimal decimal_check = {{0x1587D1, 0x0, 0x0, 0x800F0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1547) {
  int f = 550388241;

  my_decimal decimal_check = {{0x355104, 0x0, 0x0, 0x190000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1548) {
  int f = -1597095407;

  my_decimal decimal_check = {{0x355104, 0x0, 0x0, 0x80190000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1549) {
  int f = 1287339953;

  my_decimal decimal_check = {{0x5D9FD8C, 0x0, 0x0, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1550) {
  int f = -860143695;

  my_decimal decimal_check = {{0x5D9FD8C, 0x0, 0x0, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1551) {
  int f = 308707853;

  my_decimal decimal_check = {{0x7, 0x0, 0x0, 0x1C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1552) {
  int f = -1838775795;

  my_decimal decimal_check = {{0x7, 0x0, 0x0, 0x801C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1553) {
  int f = 481771177;

  my_decimal decimal_check = {{0x1280C4, 0x0, 0x0, 0x1B0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1554) {
  int f = -1665712471;

  my_decimal decimal_check = {{0x1280C4, 0x0, 0x0, 0x801B0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1555) {
  int f = 1590523354;

  my_decimal decimal_check = {{0x5761A000, 0x66BAED6F, 0x0, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1556) {
  int f = -556960294;

  my_decimal decimal_check = {{0x5761A000, 0x66BAED6F, 0x0, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1557) {
  int f = 1529034684;

  my_decimal decimal_check = {{0x94E0A800, 0xA337BB, 0x0, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1558) {
  int f = -618448964;

  my_decimal decimal_check = {{0x94E0A800, 0xA337BB, 0x0, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1559) {
  int f = 1645561563;

  my_decimal decimal_check = {{0xA6F40000, 0x51B69FCE, 0x25, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1560) {
  int f = -501922085;

  my_decimal decimal_check = {{0xA6F40000, 0x51B69FCE, 0x25, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1561) {
  int f = 467392526;

  my_decimal decimal_check = {{0x377F15, 0x0, 0x0, 0x1C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1562) {
  int f = -1680091122;

  my_decimal decimal_check = {{0x377F15, 0x0, 0x0, 0x801C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1563) {
  int f = 589338597;

  my_decimal decimal_check = {{0x84D6F6, 0x0, 0x0, 0x180000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1564) {
  int f = -1558145051;

  my_decimal decimal_check = {{0x84D6F6, 0x0, 0x0, 0x80180000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1565) {
  int f = 1785086128;

  my_decimal decimal_check = {{0xED800000, 0xC66E415D, 0x39902B, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1566) {
  int f = -362397520;

  my_decimal decimal_check = {{0xED800000, 0xC66E415D, 0x39902B, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1567) {
  int f = 1740499735;

  my_decimal decimal_check = {{0x43000000, 0x3091A5C0, 0x17BD6, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1568) {
  int f = -406983913;

  my_decimal decimal_check = {{0x43000000, 0x3091A5C0, 0x17BD6, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1569) {
  int f = 790504076;

  my_decimal decimal_check = {{0x15F215, 0x0, 0x0, 0x100000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1570) {
  int f = -1356979572;

  my_decimal decimal_check = {{0x15F215, 0x0, 0x0, 0x80100000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1571) {
  int f = 1522892503;

  my_decimal decimal_check = {{0x659FF800, 0x62BF6C, 0x0, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1572) {
  int f = -624591145;

  my_decimal decimal_check = {{0x659FF800, 0x62BF6C, 0x0, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1573) {
  int f = 1273420173;

  my_decimal decimal_check = {{0x1CDB31E, 0x0, 0x0, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1574) {
  int f = -874063475;

  my_decimal decimal_check = {{0x1CDB31E, 0x0, 0x0, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1575) {
  int f = 703584291;

  my_decimal decimal_check = {{0x1040A3, 0x0, 0x0, 0x130000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1576) {
  int f = -1443899357;

  my_decimal decimal_check = {{0x1040A3, 0x0, 0x0, 0x80130000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1577) {
  int f = 1032017462;

  my_decimal decimal_check = {{0x61DA80, 0x0, 0x0, 0x80000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1578) {
  int f = -1115466186;

  my_decimal decimal_check = {{0x61DA80, 0x0, 0x0, 0x80080000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1579) {
  int f = 696024188;

  my_decimal decimal_check = {{0x558BB1, 0x0, 0x0, 0x140000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1580) {
  int f = -1451459460;

  my_decimal decimal_check = {{0x558BB1, 0x0, 0x0, 0x80140000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1581) {
  int f = 1700517959;

  my_decimal decimal_check = {{0x49E20000, 0x8468C551, 0xDBD, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1582) {
  int f = -446965689;

  my_decimal decimal_check = {{0x49E20000, 0x8468C551, 0xDBD, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1583) {
  int f = 1447182739;

  my_decimal decimal_check = {{0x64871C00, 0x3090, 0x0, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1584) {
  int f = -700300909;

  my_decimal decimal_check = {{0x64871C00, 0x3090, 0x0, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1585) {
  int f = 744677234;

  my_decimal decimal_check = {{0x3131F9, 0x0, 0x0, 0x120000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1586) {
  int f = -1402806414;

  my_decimal decimal_check = {{0x3131F9, 0x0, 0x0, 0x80120000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1587) {
  int f = 405502423;

  my_decimal decimal_check = {{0x5693, 0x0, 0x0, 0x1C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1588) {
  int f = -1741981225;

  my_decimal decimal_check = {{0x5693, 0x0, 0x0, 0x801C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1589) {
  int f = 1106077856;

  my_decimal decimal_check = {{0x2D4839, 0x0, 0x0, 0x50000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1590) {
  int f = -1041405792;

  my_decimal decimal_check = {{0x2D4839, 0x0, 0x0, 0x80050000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1591) {
  int f = 843682971;

  my_decimal decimal_check = {{0x11E769, 0x0, 0x0, 0xE0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1592) {
  int f = -1303800677;

  my_decimal decimal_check = {{0x11E769, 0x0, 0x0, 0x800E0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1593) {
  int f = 822035802;

  my_decimal decimal_check = {{0x2D586, 0x0, 0x0, 0xE0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1594) {
  int f = -1325447846;

  my_decimal decimal_check = {{0x2D586, 0x0, 0x0, 0x800E0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1595) {
  int f = 1212992305;

  my_decimal decimal_check = {{0x1FFFC0, 0x0, 0x0, 0x10000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1596) {
  int f = -934491343;

  my_decimal decimal_check = {{0x1FFFC0, 0x0, 0x0, 0x80010000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1597) {
  int f = 1771768910;

  my_decimal decimal_check = {{0x2DE00000, 0xAFE50810, 0x136189, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1598) {
  int f = -375714738;

  my_decimal decimal_check = {{0x2DE00000, 0xAFE50810, 0x136189, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1599) {
  int f = 872979000;

  my_decimal decimal_check = {{0x136991, 0x0, 0x0, 0xD0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1600) {
  int f = -1274504648;

  my_decimal decimal_check = {{0x136991, 0x0, 0x0, 0x800D0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1601) {
  int f = 1087275411;

  my_decimal decimal_check = {{0x627845, 0x0, 0x0, 0x60000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1602) {
  int f = -1060208237;

  my_decimal decimal_check = {{0x627845, 0x0, 0x0, 0x80060000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1603) {
  int f = 1154118805;

  my_decimal decimal_check = {{0x18B6BB, 0x0, 0x0, 0x30000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1604) {
  int f = -993364843;

  my_decimal decimal_check = {{0x18B6BB, 0x0, 0x0, 0x80030000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1605) {
  int f = 1088661513;

  my_decimal decimal_check = {{0x6C8E16, 0x0, 0x0, 0x60000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1606) {
  int f = -1058822135;

  my_decimal decimal_check = {{0x6C8E16, 0x0, 0x0, 0x80060000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1607) {
  int f = 1261915258;

  my_decimal decimal_check = {{0xB74C7E, 0x0, 0x0, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1608) {
  int f = -885568390;

  my_decimal decimal_check = {{0xB74C7E, 0x0, 0x0, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1609) {
  int f = 1782226647;

  my_decimal decimal_check = {{0xDD00000, 0xFD0DA3BA, 0x2EA7B5, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1610) {
  int f = -365257001;

  my_decimal decimal_check = {{0xDD00000, 0xFD0DA3BA, 0x2EA7B5, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1611) {
  int f = 1560440369;

  my_decimal decimal_check = {{0x7B416800, 0x826E319, 0x0, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1612) {
  int f = -587043279;

  my_decimal decimal_check = {{0x7B416800, 0x826E319, 0x0, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1613) {
  int f = 1524949727;

  my_decimal decimal_check = {{0x418BBC00, 0x72716F, 0x0, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1614) {
  int f = -622533921;

  my_decimal decimal_check = {{0x418BBC00, 0x72716F, 0x0, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1615) {
  int f = 1571111468;

  my_decimal decimal_check = {{0x5E7C4000, 0x14A8456A, 0x0, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1616) {
  int f = -576372180;

  my_decimal decimal_check = {{0x5E7C4000, 0x14A8456A, 0x0, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1617) {
  int f = 764817723;

  my_decimal decimal_check = {{0x1A0DE1, 0x0, 0x0, 0x110000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1618) {
  int f = -1382665925;

  my_decimal decimal_check = {{0x1A0DE1, 0x0, 0x0, 0x80110000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1619) {
  int f = 380676634;

  my_decimal decimal_check = {{0xB26, 0x0, 0x0, 0x1C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1620) {
  int f = -1766807014;

  my_decimal decimal_check = {{0xB26, 0x0, 0x0, 0x801C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1621) {
  int f = 303905284;

  my_decimal decimal_check = {{0x5, 0x0, 0x0, 0x1C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1622) {
  int f = -1843578364;

  my_decimal decimal_check = {{0x5, 0x0, 0x0, 0x801C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1623) {
  int f = 727692076;

  my_decimal decimal_check = {{0x794499, 0x0, 0x0, 0x130000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1624) {
  int f = -1419791572;

  my_decimal decimal_check = {{0x794499, 0x0, 0x0, 0x80130000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1625) {
  int f = 1039772992;

  my_decimal decimal_check = {{0x129A35, 0x0, 0x0, 0x70000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1626) {
  int f = -1107710656;

  my_decimal decimal_check = {{0x129A35, 0x0, 0x0, 0x80070000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1627) {
  int f = 1363436524;

  my_decimal decimal_check = {{0x463ED350, 0xC, 0x0, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1628) {
  int f = -784047124;

  my_decimal decimal_check = {{0x463ED350, 0xC, 0x0, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1629) {
  int f = 1718031679;

  my_decimal decimal_check = {{0xFB340000, 0x4F21324C, 0x39C5, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1630) {
  int f = -429451969;

  my_decimal decimal_check = {{0xFB340000, 0x4F21324C, 0x39C5, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1631) {
  int f = 964490692;

  my_decimal decimal_check = {{0x24CF7F, 0x0, 0x0, 0xA0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1632) {
  int f = -1182992956;

  my_decimal decimal_check = {{0x24CF7F, 0x0, 0x0, 0x800A0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1633) {
  int f = 1259809824;

  my_decimal decimal_check = {{0x972C20, 0x0, 0x0, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1634) {
  int f = -887673824;

  my_decimal decimal_check = {{0x972C20, 0x0, 0x0, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1635) {
  int f = 518401301;

  my_decimal decimal_check = {{0x252FDC, 0x0, 0x0, 0x1A0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1636) {
  int f = -1629082347;

  my_decimal decimal_check = {{0x252FDC, 0x0, 0x0, 0x801A0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1637) {
  int f = 920463789;

  my_decimal decimal_check = {{0x6492BD, 0x0, 0x0, 0xC0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1638) {
  int f = -1227019859;

  my_decimal decimal_check = {{0x6492BD, 0x0, 0x0, 0x800C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1639) {
  int f = 1115960715;

  my_decimal decimal_check = {{0x64DE1A, 0x0, 0x0, 0x50000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1640) {
  int f = -1031522933;

  my_decimal decimal_check = {{0x64DE1A, 0x0, 0x0, 0x80050000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1641) {
  int f = 1245824923;

  my_decimal decimal_check = {{0x3071E7, 0x0, 0x0, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1642) {
  int f = -901658725;

  my_decimal decimal_check = {{0x3071E7, 0x0, 0x0, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1643) {
  int f = 1681383359;

  my_decimal decimal_check = {{0x500F0000, 0x7F065D40, 0x2DF, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1644) {
  int f = -466100289;

  my_decimal decimal_check = {{0x500F0000, 0x7F065D40, 0x2DF, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1645) {
  int f = 527116144;

  my_decimal decimal_check = {{0x4BFB7D, 0x0, 0x0, 0x1A0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1646) {
  int f = -1620367504;

  my_decimal decimal_check = {{0x4BFB7D, 0x0, 0x0, 0x801A0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1647) {
  int f = 916422471;

  my_decimal decimal_check = {{0x4887EA, 0x0, 0x0, 0xC0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1648) {
  int f = -1231061177;

  my_decimal decimal_check = {{0x4887EA, 0x0, 0x0, 0x800C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1649) {
  int f = 1707859150;

  my_decimal decimal_check = {{0xBF800000, 0x99E1EF97, 0x197B, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1650) {
  int f = -439624498;

  my_decimal decimal_check = {{0xBF800000, 0x99E1EF97, 0x197B, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1651) {
  int f = 581028757;

  my_decimal decimal_check = {{0x42EABD, 0x0, 0x0, 0x180000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1652) {
  int f = -1566454891;

  my_decimal decimal_check = {{0x42EABD, 0x0, 0x0, 0x80180000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1653) {
  int f = 677859653;

  my_decimal decimal_check = {{0x1F597, 0x0, 0x0, 0x130000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1654) {
  int f = -1469623995;

  my_decimal decimal_check = {{0x1F597, 0x0, 0x0, 0x80130000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1655) {
  int f = 410216888;

  my_decimal decimal_check = {{0xC4A, 0x0, 0x0, 0x1B0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1656) {
  int f = -1737266760;

  my_decimal decimal_check = {{0xC4A, 0x0, 0x0, 0x801B0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1657) {
  int f = 1010683643;

  my_decimal decimal_check = {{0x11AD63, 0x0, 0x0, 0x80000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1658) {
  int f = -1136800005;

  my_decimal decimal_check = {{0x11AD63, 0x0, 0x0, 0x80080000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1659) {
  int f = 441360544;

  my_decimal decimal_check = {{0x68520, 0x0, 0x0, 0x1C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1660) {
  int f = -1706123104;

  my_decimal decimal_check = {{0x68520, 0x0, 0x0, 0x801C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1661) {
  int f = 1053045309;

  my_decimal decimal_check = {{0x3A7896, 0x0, 0x0, 0x70000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1662) {
  int f = -1094438339;

  my_decimal decimal_check = {{0x3A7896, 0x0, 0x0, 0x80070000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1663) {
  int f = 835152129;

  my_decimal decimal_check = {{0xE2B4, 0x0, 0x0, 0xD0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1664) {
  int f = -1312331519;

  my_decimal decimal_check = {{0xE2B4, 0x0, 0x0, 0x800D0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1665) {
  int f = 1368350486;

  my_decimal decimal_check = {{0xEBE2BFB0, 0x11, 0x0, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1666) {
  int f = -779133162;

  my_decimal decimal_check = {{0xEBE2BFB0, 0x11, 0x0, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1667) {
  int f = 662147854;

  my_decimal decimal_check = {{0x346D09, 0x0, 0x0, 0x150000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1668) {
  int f = -1485335794;

  my_decimal decimal_check = {{0x346D09, 0x0, 0x0, 0x80150000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1669) {
  int f = 564378323;

  my_decimal decimal_check = {{0x10EDE4, 0x0, 0x0, 0x180000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1670) {
  int f = -1583105325;

  my_decimal decimal_check = {{0x10EDE4, 0x0, 0x0, 0x80180000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1671) {
  int f = 879646979;

  my_decimal decimal_check = {{0x21DF0A, 0x0, 0x0, 0xD0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1672) {
  int f = -1267836669;

  my_decimal decimal_check = {{0x21DF0A, 0x0, 0x0, 0x800D0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1673) {
  int f = 1067050343;

  my_decimal decimal_check = {{0x125889, 0x0, 0x0, 0x60000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1674) {
  int f = -1080433305;

  my_decimal decimal_check = {{0x125889, 0x0, 0x0, 0x80060000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1675) {
  int f = 520874432;

  my_decimal decimal_check = {{0x2D3557, 0x0, 0x0, 0x1A0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1676) {
  int f = -1626609216;

  my_decimal decimal_check = {{0x2D3557, 0x0, 0x0, 0x801A0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1677) {
  int f = 1524646346;

  my_decimal decimal_check = {{0x17798400, 0x7020E6, 0x0, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1678) {
  int f = -622837302;

  my_decimal decimal_check = {{0x17798400, 0x7020E6, 0x0, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1679) {
  int f = 796436966;

  my_decimal decimal_check = {{0x22824F, 0x0, 0x0, 0x100000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1680) {
  int f = -1351046682;

  my_decimal decimal_check = {{0x22824F, 0x0, 0x0, 0x80100000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1681) {
  int f = 1555927426;

  my_decimal decimal_check = {{0x23BC4800, 0x5EC8C18, 0x0, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1682) {
  int f = -591556222;

  my_decimal decimal_check = {{0x23BC4800, 0x5EC8C18, 0x0, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1683) {
  int f = 1251904747;

  my_decimal decimal_check = {{0x4F4676, 0x0, 0x0, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1684) {
  int f = -895578901;

  my_decimal decimal_check = {{0x4F4676, 0x0, 0x0, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1685) {
  int f = 1496751218;

  my_decimal decimal_check = {{0x31E02A00, 0xB69C7, 0x0, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1686) {
  int f = -650732430;

  my_decimal decimal_check = {{0x31E02A00, 0xB69C7, 0x0, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1687) {
  int f = 657432998;

  my_decimal decimal_check = {{0x253100, 0x0, 0x0, 0x150000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1688) {
  int f = -1490050650;

  my_decimal decimal_check = {{0x253100, 0x0, 0x0, 0x80150000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1689) {
  int f = 389822467;

  my_decimal decimal_check = {{0x17C2, 0x0, 0x0, 0x1C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1690) {
  int f = -1757661181;

  my_decimal decimal_check = {{0x17C2, 0x0, 0x0, 0x801C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1691) {
  int f = 970529445;

  my_decimal decimal_check = {{0x3F2F84, 0x0, 0x0, 0xA0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1692) {
  int f = -1176954203;

  my_decimal decimal_check = {{0x3F2F84, 0x0, 0x0, 0x800A0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1693) {
  int f = 405113309;

  my_decimal decimal_check = {{0x5393, 0x0, 0x0, 0x1C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1694) {
  int f = -1742370339;

  my_decimal decimal_check = {{0x5393, 0x0, 0x0, 0x801C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1695) {
  int f = 939225359;

  my_decimal decimal_check = {{0x2DBCAA, 0x0, 0x0, 0xB0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1696) {
  int f = -1208258289;

  my_decimal decimal_check = {{0x2DBCAA, 0x0, 0x0, 0x800B0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1697) {
  int f = 1814125090;

  my_decimal decimal_check = {{0xCC00000, 0x9F4708AD, 0x2856888, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1698) {
  int f = -333358558;

  my_decimal decimal_check = {{0xCC00000, 0x9F4708AD, 0x2856888, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1699) {
  int f = 1707960422;

  my_decimal decimal_check = {{0xCED40000, 0xD335A8C, 0x19AD, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1700) {
  int f = -439523226;

  my_decimal decimal_check = {{0xCED40000, 0xD335A8C, 0x19AD, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1701) {
  int f = 1133469189;

  my_decimal decimal_check = {{0x2BC091, 0x0, 0x0, 0x40000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1702) {
  int f = -1014014459;

  my_decimal decimal_check = {{0x2BC091, 0x0, 0x0, 0x80040000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1703) {
  int f = 309726671;

  my_decimal decimal_check = {{0x8, 0x0, 0x0, 0x1C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1704) {
  int f = -1837756977;

  my_decimal decimal_check = {{0x8, 0x0, 0x0, 0x801C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1705) {
  int f = 290232078;

  my_decimal decimal_check = {{0x2, 0x0, 0x0, 0x1C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1706) {
  int f = -1857251570;

  my_decimal decimal_check = {{0x2, 0x0, 0x0, 0x801C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1707) {
  int f = 661900365;

  my_decimal decimal_check = {{0x33A052, 0x0, 0x0, 0x150000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1708) {
  int f = -1485583283;

  my_decimal decimal_check = {{0x33A052, 0x0, 0x0, 0x80150000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1709) {
  int f = 1185138727;

  my_decimal decimal_check = {{0x1FFD18, 0x0, 0x0, 0x20000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1710) {
  int f = -962344921;

  my_decimal decimal_check = {{0x1FFD18, 0x0, 0x0, 0x80020000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1711) {
  int f = 972265310;

  my_decimal decimal_check = {{0x46E4F7, 0x0, 0x0, 0xA0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1712) {
  int f = -1175218338;

  my_decimal decimal_check = {{0x46E4F7, 0x0, 0x0, 0x800A0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1713) {
  int f = 624706223;

  my_decimal decimal_check = {{0x18EA83, 0x0, 0x0, 0x160000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1714) {
  int f = -1522777425;

  my_decimal decimal_check = {{0x18EA83, 0x0, 0x0, 0x80160000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1715) {
  int f = 1721835084;

  my_decimal decimal_check = {{0x41EE0000, 0x256D8E01, 0x508F, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1716) {
  int f = -425648564;

  my_decimal decimal_check = {{0x41EE0000, 0x256D8E01, 0x508F, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1717) {
  int f = 1120429366;

  my_decimal decimal_check = {{0xF49F9, 0x0, 0x0, 0x40000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1718) {
  int f = -1027054282;

  my_decimal decimal_check = {{0xF49F9, 0x0, 0x0, 0x80040000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1719) {
  int f = 1198901452;

  my_decimal decimal_check = {{0x999D8, 0x0, 0x0, 0x10000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1720) {
  int f = -948582196;

  my_decimal decimal_check = {{0x999D8, 0x0, 0x0, 0x80010000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1721) {
  int f = 888672886;

  my_decimal decimal_check = {{0x46819F, 0x0, 0x0, 0xD0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1722) {
  int f = -1258810762;

  my_decimal decimal_check = {{0x46819F, 0x0, 0x0, 0x800D0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1723) {
  int f = 1120825010;

  my_decimal decimal_check = {{0xFBFE2, 0x0, 0x0, 0x40000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1724) {
  int f = -1026658638;

  my_decimal decimal_check = {{0xFBFE2, 0x0, 0x0, 0x80040000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1725) {
  int f = 566519995;

  my_decimal decimal_check = {{0x207E4, 0x0, 0x0, 0x170000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1726) {
  int f = -1580963653;

  my_decimal decimal_check = {{0x207E4, 0x0, 0x0, 0x80170000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1727) {
  int f = 321160741;

  my_decimal decimal_check = {{0x15, 0x0, 0x0, 0x1C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1728) {
  int f = -1826322907;

  my_decimal decimal_check = {{0x15, 0x0, 0x0, 0x801C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1729) {
  int f = 894004583;

  my_decimal decimal_check = {{0x727F8A, 0x0, 0x0, 0xD0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1730) {
  int f = -1253479065;

  my_decimal decimal_check = {{0x727F8A, 0x0, 0x0, 0x800D0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1731) {
  int f = 1026737805;

  my_decimal decimal_check = {{0x42995E, 0x0, 0x0, 0x80000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1732) {
  int f = -1120745843;

  my_decimal decimal_check = {{0x42995E, 0x0, 0x0, 0x80080000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1733) {
  int f = 908937632;

  my_decimal decimal_check = {{0x2766AA, 0x0, 0x0, 0xC0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1734) {
  int f = -1238546016;

  my_decimal decimal_check = {{0x2766AA, 0x0, 0x0, 0x800C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1735) {
  int f = 383717308;

  my_decimal decimal_check = {{0xE14, 0x0, 0x0, 0x1C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1736) {
  int f = -1763766340;

  my_decimal decimal_check = {{0xE14, 0x0, 0x0, 0x801C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1737) {
  int f = 805150372;

  my_decimal decimal_check = {{0x4664C3, 0x0, 0x0, 0x100000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1738) {
  int f = -1342333276;

  my_decimal decimal_check = {{0x4664C3, 0x0, 0x0, 0x80100000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1739) {
  int f = 844476870;

  my_decimal decimal_check = {{0x12FAD9, 0x0, 0x0, 0xE0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1740) {
  int f = -1303006778;

  my_decimal decimal_check = {{0x12FAD9, 0x0, 0x0, 0x800E0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1741) {
  int f = 1455424999;

  my_decimal decimal_check = {{0xF4026A00, 0x6002, 0x0, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1742) {
  int f = -692058649;

  my_decimal decimal_check = {{0xF4026A00, 0x6002, 0x0, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1743) {
  int f = 745027562;

  my_decimal decimal_check = {{0x325AB6, 0x0, 0x0, 0x120000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1744) {
  int f = -1402456086;

  my_decimal decimal_check = {{0x325AB6, 0x0, 0x0, 0x80120000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1745) {
  int f = 560128214;

  my_decimal decimal_check = {{0x754B17, 0x0, 0x0, 0x190000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1746) {
  int f = -1587355434;

  my_decimal decimal_check = {{0x754B17, 0x0, 0x0, 0x80190000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1747) {
  int f = 1690400082;

  my_decimal decimal_check = {{0xC91C0000, 0xAA83E6CB, 0x60B, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1748) {
  int f = -457083566;

  my_decimal decimal_check = {{0xC91C0000, 0xAA83E6CB, 0x60B, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1749) {
  int f = 1118017939;

  my_decimal decimal_check = {{0x7CD11B, 0x0, 0x0, 0x50000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1750) {
  int f = -1029465709;

  my_decimal decimal_check = {{0x7CD11B, 0x0, 0x0, 0x80050000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1751) {
  int f = 1551904826;

  my_decimal decimal_check = {{0x4FC85000, 0x40181D4, 0x0, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1752) {
  int f = -595578822;

  my_decimal decimal_check = {{0x4FC85000, 0x40181D4, 0x0, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1753) {
  int f = 1742616791;

  my_decimal decimal_check = {{0xE2B00000, 0xB1A10CAB, 0x1BC71, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1754) {
  int f = -404866857;

  my_decimal decimal_check = {{0xE2B00000, 0xB1A10CAB, 0x1BC71, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1755) {
  int f = 1427667796;

  my_decimal decimal_check = {{0xB57B6D80, 0x987, 0x0, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1756) {
  int f = -719815852;

  my_decimal decimal_check = {{0xB57B6D80, 0x987, 0x0, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1757) {
  int f = 532692175;

  my_decimal decimal_check = {{0x7C3B08, 0x0, 0x0, 0x1A0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1758) {
  int f = -1614791473;

  my_decimal decimal_check = {{0x7C3B08, 0x0, 0x0, 0x801A0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1759) {
  int f = 735033266;

  my_decimal decimal_check = {{0x168552, 0x0, 0x0, 0x120000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1760) {
  int f = -1412450382;

  my_decimal decimal_check = {{0x168552, 0x0, 0x0, 0x80120000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1761) {
  int f = 1742288706;

  my_decimal decimal_check = {{0x9F280000, 0x8810E371, 0x1B26E, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1762) {
  int f = -405194942;

  my_decimal decimal_check = {{0x9F280000, 0x8810E371, 0x1B26E, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1763) {
  int f = 1305007551;

  my_decimal decimal_check = {{0x191AB7D8, 0x0, 0x0, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1764) {
  int f = -842476097;

  my_decimal decimal_check = {{0x191AB7D8, 0x0, 0x0, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1765) {
  int f = 1714357536;

  my_decimal decimal_check = {{0xD9C00000, 0x486FDA2C, 0x2BC1, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1766) {
  int f = -433126112;

  my_decimal decimal_check = {{0xD9C00000, 0x486FDA2C, 0x2BC1, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1767) {
  int f = 860707872;

  my_decimal decimal_check = {{0x48F55F, 0x0, 0x0, 0xE0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1768) {
  int f = -1286775776;

  my_decimal decimal_check = {{0x48F55F, 0x0, 0x0, 0x800E0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1769) {
  int f = 857487397;

  my_decimal decimal_check = {{0x378010, 0x0, 0x0, 0xE0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1770) {
  int f = -1289996251;

  my_decimal decimal_check = {{0x378010, 0x0, 0x0, 0x800E0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1771) {
  int f = 749410808;

  my_decimal decimal_check = {{0x4A3413, 0x0, 0x0, 0x120000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1772) {
  int f = -1398072840;

  my_decimal decimal_check = {{0x4A3413, 0x0, 0x0, 0x80120000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1773) {
  int f = 542623613;

  my_decimal decimal_check = {{0x1BE389, 0x0, 0x0, 0x190000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1774) {
  int f = -1604860035;

  my_decimal decimal_check = {{0x1BE389, 0x0, 0x0, 0x80190000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1775) {
  int f = 720930900;

  my_decimal decimal_check = {{0x435D69, 0x0, 0x0, 0x130000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1776) {
  int f = -1426552748;

  my_decimal decimal_check = {{0x435D69, 0x0, 0x0, 0x80130000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1777) {
  int f = 1034993777;

  my_decimal decimal_check = {{0x83B0B7, 0x0, 0x0, 0x80000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1778) {
  int f = -1112489871;

  my_decimal decimal_check = {{0x83B0B7, 0x0, 0x0, 0x80080000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1779) {
  int f = 1150097663;

  my_decimal decimal_check = {{0x11394D, 0x0, 0x0, 0x30000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1780) {
  int f = -997385985;

  my_decimal decimal_check = {{0x11394D, 0x0, 0x0, 0x80030000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1781) {
  int f = 1804536798;

  my_decimal decimal_check = {{0xD0900000, 0xCC5EF7A5, 0x11E17BD, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1782) {
  int f = -342946850;

  my_decimal decimal_check = {{0xD0900000, 0xCC5EF7A5, 0x11E17BD, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1783) {
  int f = 903199909;

  my_decimal decimal_check = {{0x184C90, 0x0, 0x0, 0xC0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1784) {
  int f = -1244283739;

  my_decimal decimal_check = {{0x184C90, 0x0, 0x0, 0x800C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1785) {
  int f = 966818324;

  my_decimal decimal_check = {{0x2EB475, 0x0, 0x0, 0xA0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1786) {
  int f = -1180665324;

  my_decimal decimal_check = {{0x2EB475, 0x0, 0x0, 0x800A0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1787) {
  int f = 323448456;

  my_decimal decimal_check = {{0x19, 0x0, 0x0, 0x1C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1788) {
  int f = -1824035192;

  my_decimal decimal_check = {{0x19, 0x0, 0x0, 0x801C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1789) {
  int f = 1465748730;

  my_decimal decimal_check = {{0xFC6A8800, 0xDD8C, 0x0, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1790) {
  int f = -681734918;

  my_decimal decimal_check = {{0xFC6A8800, 0xDD8C, 0x0, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1791) {
  int f = 441194587;

  my_decimal decimal_check = {{0x670AB, 0x0, 0x0, 0x1C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1792) {
  int f = -1706289061;

  my_decimal decimal_check = {{0x670AB, 0x0, 0x0, 0x801C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1793) {
  int f = 691476922;

  my_decimal decimal_check = {{0x3E0970, 0x0, 0x0, 0x140000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1794) {
  int f = -1456006726;

  my_decimal decimal_check = {{0x3E0970, 0x0, 0x0, 0x80140000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1795) {
  int f = 1181682648;

  my_decimal decimal_check = {{0x175828, 0x0, 0x0, 0x20000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1796) {
  int f = -965801000;

  my_decimal decimal_check = {{0x175828, 0x0, 0x0, 0x80020000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1797) {
  int f = 1321413064;

  my_decimal decimal_check = {{0x6194E560, 0x0, 0x0, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1798) {
  int f = -826070584;

  my_decimal decimal_check = {{0x6194E560, 0x0, 0x0, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1799) {
  int f = 921069312;

  my_decimal decimal_check = {{0x68C65D, 0x0, 0x0, 0xC0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1800) {
  int f = -1226414336;

  my_decimal decimal_check = {{0x68C65D, 0x0, 0x0, 0x800C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1801) {
  int f = 1619576464;

  my_decimal decimal_check = {{0x190BE000, 0x46348443, 0x4, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1802) {
  int f = -527907184;

  my_decimal decimal_check = {{0x190BE000, 0x46348443, 0x4, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1803) {
  int f = 1587769259;

  my_decimal decimal_check = {{0x65DBA000, 0x51B7D5B2, 0x0, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1804) {
  int f = -559714389;

  my_decimal decimal_check = {{0x65DBA000, 0x51B7D5B2, 0x0, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1805) {
  int f = 1700448246;

  my_decimal decimal_check = {{0xB83E0000, 0x7F56C8BF, 0xDAC, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1806) {
  int f = -447035402;

  my_decimal decimal_check = {{0xB83E0000, 0x7F56C8BF, 0xDAC, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1807) {
  int f = 967351783;

  my_decimal decimal_check = {{0x4E84B, 0x0, 0x0, 0x90000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1808) {
  int f = -1180131865;

  my_decimal decimal_check = {{0x4E84B, 0x0, 0x0, 0x80090000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1809) {
  int f = 1810520073;

  my_decimal decimal_check = {{0xCA800000, 0x9870BCBD, 0x1D4B014, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1810) {
  int f = -336963575;

  my_decimal decimal_check = {{0xCA800000, 0x9870BCBD, 0x1D4B014, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1811) {
  int f = 394533797;

  my_decimal decimal_check = {{0x2159, 0x0, 0x0, 0x1C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1812) {
  int f = -1752949851;

  my_decimal decimal_check = {{0x2159, 0x0, 0x0, 0x801C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1813) {
  int f = 1315971716;

  my_decimal decimal_check = {{0x3C089F30, 0x0, 0x0, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1814) {
  int f = -831511932;

  my_decimal decimal_check = {{0x3C089F30, 0x0, 0x0, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1815) {
  int f = 1726486343;

  my_decimal decimal_check = {{0x2C180000, 0xA364F2D2, 0x740B, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1816) {
  int f = -420997305;

  my_decimal decimal_check = {{0x2C180000, 0xA364F2D2, 0x740B, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1817) {
  int f = 1101867076;

  my_decimal decimal_check = {{0x2106F2, 0x0, 0x0, 0x50000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1818) {
  int f = -1045616572;

  my_decimal decimal_check = {{0x2106F2, 0x0, 0x0, 0x80050000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1819) {
  int f = 1182829944;

  my_decimal decimal_check = {{0x191BA1, 0x0, 0x0, 0x20000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1820) {
  int f = -964653704;

  my_decimal decimal_check = {{0x191BA1, 0x0, 0x0, 0x80020000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1821) {
  int f = 796021777;

  my_decimal decimal_check = {{0x21A13C, 0x0, 0x0, 0x100000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1822) {
  int f = -1351461871;

  my_decimal decimal_check = {{0x21A13C, 0x0, 0x0, 0x80100000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1823) {
  int f = 746634469;

  my_decimal decimal_check = {{0x59547, 0x0, 0x0, 0x110000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1824) {
  int f = -1400849179;

  my_decimal decimal_check = {{0x59547, 0x0, 0x0, 0x80110000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1825) {
  int f = 1195235079;

  my_decimal decimal_check = {{0x4A27FF, 0x0, 0x0, 0x20000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1826) {
  int f = -952248569;

  my_decimal decimal_check = {{0x4A27FF, 0x0, 0x0, 0x80020000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1827) {
  int f = 383099662;

  my_decimal decimal_check = {{0xD7B, 0x0, 0x0, 0x1C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1828) {
  int f = -1764383986;

  my_decimal decimal_check = {{0xD7B, 0x0, 0x0, 0x801C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1829) {
  int f = 1022986004;

  my_decimal decimal_check = {{0x2E7A68, 0x0, 0x0, 0x80000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1830) {
  int f = -1124497644;

  my_decimal decimal_check = {{0x2E7A68, 0x0, 0x0, 0x80080000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1831) {
  int f = 1141649985;

  my_decimal decimal_check = {{0x5591AC, 0x0, 0x0, 0x40000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1832) {
  int f = -1005833663;

  my_decimal decimal_check = {{0x5591AC, 0x0, 0x0, 0x80040000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1833) {
  int f = 972840732;

  my_decimal decimal_check = {{0x497325, 0x0, 0x0, 0xA0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1834) {
  int f = -1174642916;

  my_decimal decimal_check = {{0x497325, 0x0, 0x0, 0x800A0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1835) {
  int f = 1263796773;

  my_decimal decimal_check = {{0xD40224, 0x0, 0x0, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1836) {
  int f = -883686875;

  my_decimal decimal_check = {{0xD40224, 0x0, 0x0, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1837) {
  int f = 1021657994;

  my_decimal decimal_check = {{0x2AB427, 0x0, 0x0, 0x80000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1838) {
  int f = -1125825654;

  my_decimal decimal_check = {{0x2AB427, 0x0, 0x0, 0x80080000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1839) {
  int f = 1710967034;

  my_decimal decimal_check = {{0x9DE20000, 0x1EF5C2BB, 0x1F69, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1840) {
  int f = -436516614;

  my_decimal decimal_check = {{0x9DE20000, 0x1EF5C2BB, 0x1F69, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1841) {
  int f = 490206362;

  my_decimal decimal_check = {{0x3B707, 0x0, 0x0, 0x1A0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1842) {
  int f = -1657277286;

  my_decimal decimal_check = {{0x3B707, 0x0, 0x0, 0x801A0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1843) {
  int f = 1754379990;

  my_decimal decimal_check = {{0x931C0000, 0xB0CDB2BD, 0x48DB6, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1844) {
  int f = -393103658;

  my_decimal decimal_check = {{0x931C0000, 0xB0CDB2BD, 0x48DB6, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1845) {
  int f = 906708181;

  my_decimal decimal_check = {{0x1FAA84, 0x0, 0x0, 0xC0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1846) {
  int f = -1240775467;

  my_decimal decimal_check = {{0x1FAA84, 0x0, 0x0, 0x800C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1847) {
  int f = 1213037359;

  my_decimal decimal_check = {{0x201B3F, 0x0, 0x0, 0x10000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1848) {
  int f = -934446289;

  my_decimal decimal_check = {{0x201B3F, 0x0, 0x0, 0x80010000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1849) {
  int f = 597924722;

  my_decimal decimal_check = {{0x1B1109, 0x0, 0x0, 0x170000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1850) {
  int f = -1549558926;

  my_decimal decimal_check = {{0x1B1109, 0x0, 0x0, 0x80170000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1851) {
  int f = 549928652;

  my_decimal decimal_check = {{0x3380F3, 0x0, 0x0, 0x190000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1852) {
  int f = -1597554996;

  my_decimal decimal_check = {{0x3380F3, 0x0, 0x0, 0x80190000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1853) {
  int f = 1336193889;

  my_decimal decimal_check = {{0x4966C070, 0x1, 0x0, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1854) {
  int f = -811289759;

  my_decimal decimal_check = {{0x4966C070, 0x1, 0x0, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1855) {
  int f = 1794664408;

  my_decimal decimal_check = {{0x85000000, 0x3AEB40B8, 0x7C33EC, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1856) {
  int f = -352819240;

  my_decimal decimal_check = {{0x85000000, 0x3AEB40B8, 0x7C33EC, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1857) {
  int f = 1782636002;

  my_decimal decimal_check = {{0xAD980000, 0x5FA79DAD, 0x303778, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1858) {
  int f = -364847646;

  my_decimal decimal_check = {{0xAD980000, 0x5FA79DAD, 0x303778, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1859) {
  int f = 682915523;

  my_decimal decimal_check = {{0x1E9260, 0x0, 0x0, 0x140000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1860) {
  int f = -1464568125;

  my_decimal decimal_check = {{0x1E9260, 0x0, 0x0, 0x80140000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1861) {
  int f = 866520074;

  my_decimal decimal_check = {{0x75FBC7, 0x0, 0x0, 0xE0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1862) {
  int f = -1280963574;

  my_decimal decimal_check = {{0x75FBC7, 0x0, 0x0, 0x800E0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1863) {
  int f = 567026313;

  my_decimal decimal_check = {{0x151B68, 0x0, 0x0, 0x180000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1864) {
  int f = -1580457335;

  my_decimal decimal_check = {{0x151B68, 0x0, 0x0, 0x80180000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1865) {
  int f = 1672627990;

  my_decimal decimal_check = {{0xF1208000, 0x8E2A638C, 0x164, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1866) {
  int f = -474855658;

  my_decimal decimal_check = {{0xF1208000, 0x8E2A638C, 0x164, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1867) {
  int f = 1169607513;

  my_decimal decimal_check = {{0x59414A, 0x0, 0x0, 0x30000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1868) {
  int f = -977876135;

  my_decimal decimal_check = {{0x59414A, 0x0, 0x0, 0x80030000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1869) {
  int f = 673441453;

  my_decimal decimal_check = {{0x8AD461, 0x0, 0x0, 0x150000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1870) {
  int f = -1474042195;

  my_decimal decimal_check = {{0x8AD461, 0x0, 0x0, 0x80150000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1871) {
  int f = 1704115489;

  my_decimal decimal_check = {{0x31690000, 0xA4206E55, 0x1257, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1872) {
  int f = -443368159;

  my_decimal decimal_check = {{0x31690000, 0xA4206E55, 0x1257, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1873) {
  int f = 1162543956;

  my_decimal decimal_check = {{0x319050, 0x0, 0x0, 0x30000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1874) {
  int f = -984939692;

  my_decimal decimal_check = {{0x319050, 0x0, 0x0, 0x80030000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1875) {
  int f = 744709315;

  my_decimal decimal_check = {{0x314D25, 0x0, 0x0, 0x120000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1876) {
  int f = -1402774333;

  my_decimal decimal_check = {{0x314D25, 0x0, 0x0, 0x80120000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1877) {
  int f = 608172449;

  my_decimal decimal_check = {{0x3F84ED, 0x0, 0x0, 0x170000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1878) {
  int f = -1539311199;

  my_decimal decimal_check = {{0x3F84ED, 0x0, 0x0, 0x80170000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1879) {
  int f = 469045770;

  my_decimal decimal_check = {{0x3DDD4F, 0x0, 0x0, 0x1C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1880) {
  int f = -1678437878;

  my_decimal decimal_check = {{0x3DDD4F, 0x0, 0x0, 0x801C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1881) {
  int f = 999812350;

  my_decimal decimal_check = {{0x46BEF6, 0x0, 0x0, 0x90000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1882) {
  int f = -1147671298;

  my_decimal decimal_check = {{0x46BEF6, 0x0, 0x0, 0x80090000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1883) {
  int f = 382510528;

  my_decimal decimal_check = {{0xCEA, 0x0, 0x0, 0x1C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1884) {
  int f = -1764973120;

  my_decimal decimal_check = {{0xCEA, 0x0, 0x0, 0x801C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1885) {
  int f = 1177048474;

  my_decimal decimal_check = {{0x1A4D6, 0x0, 0x0, 0x10000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1886) {
  int f = -970435174;

  my_decimal decimal_check = {{0x1A4D6, 0x0, 0x0, 0x80010000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1887) {
  int f = 1401759875;

  my_decimal decimal_check = {{0x51041700, 0x11A, 0x0, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1888) {
  int f = -745723773;

  my_decimal decimal_check = {{0x51041700, 0x11A, 0x0, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1889) {
  int f = 368556664;

  my_decimal decimal_check = {{0x3E9, 0x0, 0x0, 0x1C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1890) {
  int f = -1778926984;

  my_decimal decimal_check = {{0x3E9, 0x0, 0x0, 0x801C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1891) {
  int f = 1055605891;

  my_decimal decimal_check = {{0x461D7F, 0x0, 0x0, 0x70000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1892) {
  int f = -1091877757;

  my_decimal decimal_check = {{0x461D7F, 0x0, 0x0, 0x80070000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1893) {
  int f = 1274338088;

  my_decimal decimal_check = {{0x1E9B654, 0x0, 0x0, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1894) {
  int f = -873145560;

  my_decimal decimal_check = {{0x1E9B654, 0x0, 0x0, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1895) {
  int f = 581422224;

  my_decimal decimal_check = {{0x45666B, 0x0, 0x0, 0x180000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1896) {
  int f = -1566061424;

  my_decimal decimal_check = {{0x45666B, 0x0, 0x0, 0x80180000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1897) {
  int f = 858447101;

  my_decimal decimal_check = {{0x611FE, 0x0, 0x0, 0xD0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1898) {
  int f = -1289036547;

  my_decimal decimal_check = {{0x611FE, 0x0, 0x0, 0x800D0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1899) {
  int f = 321802307;

  my_decimal decimal_check = {{0x16, 0x0, 0x0, 0x1C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1900) {
  int f = -1825681341;

  my_decimal decimal_check = {{0x16, 0x0, 0x0, 0x801C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1901) {
  int f = 1034727113;

  my_decimal decimal_check = {{0x80A89F, 0x0, 0x0, 0x80000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1902) {
  int f = -1112756535;

  my_decimal decimal_check = {{0x80A89F, 0x0, 0x0, 0x80080000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1903) {
  int f = 985664799;

  my_decimal decimal_check = {{0x165B93, 0x0, 0x0, 0x90000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1904) {
  int f = -1161818849;

  my_decimal decimal_check = {{0x165B93, 0x0, 0x0, 0x80090000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1905) {
  int f = 1718009304;

  my_decimal decimal_check = {{0x78C80000, 0x7661957C, 0x39AF, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1906) {
  int f = -429474344;

  my_decimal decimal_check = {{0x78C80000, 0x7661957C, 0x39AF, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1907) {
  int f = 1176819289;

  my_decimal decimal_check = {{0x1018EF, 0x0, 0x0, 0x20000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1908) {
  int f = -970664359;

  my_decimal decimal_check = {{0x1018EF, 0x0, 0x0, 0x80020000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1909) {
  int f = 428566513;

  my_decimal decimal_check = {{0x2330E, 0x0, 0x0, 0x1C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1910) {
  int f = -1718917135;

  my_decimal decimal_check = {{0x2330E, 0x0, 0x0, 0x801C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1911) {
  int f = 1423181124;

  my_decimal decimal_check = {{0x2A1BD0C0, 0x6A0, 0x0, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1912) {
  int f = -724302524;

  my_decimal decimal_check = {{0x2A1BD0C0, 0x6A0, 0x0, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1913) {
  int f = 687153248;

  my_decimal decimal_check = {{0x42711, 0x0, 0x0, 0x130000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1914) {
  int f = -1460330400;

  my_decimal decimal_check = {{0x42711, 0x0, 0x0, 0x80130000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1915) {
  int f = 493503057;

  my_decimal decimal_check = {{0x2F4EE9, 0x0, 0x0, 0x1B0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1916) {
  int f = -1653980591;

  my_decimal decimal_check = {{0x2F4EE9, 0x0, 0x0, 0x801B0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1917) {
  int f = 375519231;

  my_decimal decimal_check = {{0x721, 0x0, 0x0, 0x1C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1918) {
  int f = -1771964417;

  my_decimal decimal_check = {{0x721, 0x0, 0x0, 0x801C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1919) {
  int f = 1258294983;

  my_decimal decimal_check = {{0x800EC7, 0x0, 0x0, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1920) {
  int f = -889188665;

  my_decimal decimal_check = {{0x800EC7, 0x0, 0x0, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1921) {
  int f = 616324559;

  my_decimal decimal_check = {{0x7CA684, 0x0, 0x0, 0x170000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1922) {
  int f = -1531159089;

  my_decimal decimal_check = {{0x7CA684, 0x0, 0x0, 0x80170000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1923) {
  int f = 1079291958;

  my_decimal decimal_check = {{0x32B577, 0x0, 0x0, 0x60000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1924) {
  int f = -1068191690;

  my_decimal decimal_check = {{0x32B577, 0x0, 0x0, 0x80060000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1925) {
  int f = 1493446383;

  my_decimal decimal_check = {{0xFB553400, 0x842EE, 0x0, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1926) {
  int f = -654037265;

  my_decimal decimal_check = {{0xFB553400, 0x842EE, 0x0, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1927) {
  int f = 416655115;

  my_decimal decimal_check = {{0xD7BC, 0x0, 0x0, 0x1C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1928) {
  int f = -1730828533;

  my_decimal decimal_check = {{0xD7BC, 0x0, 0x0, 0x801C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1929) {
  int f = 322402040;

  my_decimal decimal_check = {{0x17, 0x0, 0x0, 0x1C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1930) {
  int f = -1825081608;

  my_decimal decimal_check = {{0x17, 0x0, 0x0, 0x801C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1931) {
  int f = 1778591506;

  my_decimal decimal_check = {{0x97880000, 0xAE217320, 0x20C9C4, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1932) {
  int f = -368892142;

  my_decimal decimal_check = {{0x97880000, 0xAE217320, 0x20C9C4, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1933) {
  int f = 640379737;

  my_decimal decimal_check = {{0x5ABFA7, 0x0, 0x0, 0x160000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1934) {
  int f = -1507103911;

  my_decimal decimal_check = {{0x5ABFA7, 0x0, 0x0, 0x80160000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1935) {
  int f = 1583612217;

  my_decimal decimal_check = {{0xFE739000, 0x39004E57, 0x0, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1936) {
  int f = -563871431;

  my_decimal decimal_check = {{0xFE739000, 0x39004E57, 0x0, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1937) {
  int f = 1267642859;

  my_decimal decimal_check = {{0x11D63D8, 0x0, 0x0, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1938) {
  int f = -879840789;

  my_decimal decimal_check = {{0x11D63D8, 0x0, 0x0, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1939) {
  int f = 868466558;

  my_decimal decimal_check = {{0x8B165B, 0x0, 0x0, 0xE0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1940) {
  int f = -1279017090;

  my_decimal decimal_check = {{0x8B165B, 0x0, 0x0, 0x800E0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1941) {
  int f = 1537090679;

  my_decimal decimal_check = {{0x13131000, 0x13C48EE, 0x0, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1942) {
  int f = -610392969;

  my_decimal decimal_check = {{0x13131000, 0x13C48EE, 0x0, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1943) {
  int f = 1786116067;

  my_decimal decimal_check = {{0xBC800000, 0xC7D94659, 0x3D7DF8, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1944) {
  int f = -361367581;

  my_decimal decimal_check = {{0xBC800000, 0xC7D94659, 0x3D7DF8, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1945) {
  int f = 653327887;

  my_decimal decimal_check = {{0x19841D, 0x0, 0x0, 0x150000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1946) {
  int f = -1494155761;

  my_decimal decimal_check = {{0x19841D, 0x0, 0x0, 0x80150000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1947) {
  int f = 550315785;

  my_decimal decimal_check = {{0x3507DA, 0x0, 0x0, 0x190000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1948) {
  int f = -1597167863;

  my_decimal decimal_check = {{0x3507DA, 0x0, 0x0, 0x80190000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1949) {
  int f = 708858246;

  my_decimal decimal_check = {{0x1A1063, 0x0, 0x0, 0x130000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1950) {
  int f = -1438625402;

  my_decimal decimal_check = {{0x1A1063, 0x0, 0x0, 0x80130000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1951) {
  int f = 1674069092;

  my_decimal decimal_check = {{0x5F810000, 0x88C8DCC3, 0x190, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1952) {
  int f = -473414556;

  my_decimal decimal_check = {{0x5F810000, 0x88C8DCC3, 0x190, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1953) {
  int f = 583423686;

  my_decimal decimal_check = {{0x5207F4, 0x0, 0x0, 0x180000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1954) {
  int f = -1564059962;

  my_decimal decimal_check = {{0x5207F4, 0x0, 0x0, 0x80180000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1955) {
  int f = 1062932956;

  my_decimal decimal_check = {{0x829365, 0x0, 0x0, 0x70000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1956) {
  int f = -1084550692;

  my_decimal decimal_check = {{0x829365, 0x0, 0x0, 0x80070000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1957) {
  int f = 842184257;

  my_decimal decimal_check = {{0x19658, 0x0, 0x0, 0xD0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1958) {
  int f = -1305299391;

  my_decimal decimal_check = {{0x19658, 0x0, 0x0, 0x800D0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1959) {
  int f = 1100303481;

  my_decimal decimal_check = {{0x1C79FA, 0x0, 0x0, 0x50000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1960) {
  int f = -1047180167;

  my_decimal decimal_check = {{0x1C79FA, 0x0, 0x0, 0x80050000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1961) {
  int f = 841963822;

  my_decimal decimal_check = {{0xF92F6, 0x0, 0x0, 0xE0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1962) {
  int f = -1305519826;

  my_decimal decimal_check = {{0xF92F6, 0x0, 0x0, 0x800E0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1963) {
  int f = 760863835;

  my_decimal decimal_check = {{0x12E57B, 0x0, 0x0, 0x110000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1964) {
  int f = -1386619813;

  my_decimal decimal_check = {{0x12E57B, 0x0, 0x0, 0x80110000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1965) {
  int f = 925532261;

  my_decimal decimal_check = {{0xF81CC, 0x0, 0x0, 0xB0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1966) {
  int f = -1221951387;

  my_decimal decimal_check = {{0xF81CC, 0x0, 0x0, 0x800B0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1967) {
  int f = 1466925866;

  my_decimal decimal_check = {{0x288BBA00, 0xEF83, 0x0, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1968) {
  int f = -680557782;

  my_decimal decimal_check = {{0x288BBA00, 0xEF83, 0x0, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1969) {
  int f = 1214561668;

  my_decimal decimal_check = {{0x23BD9D, 0x0, 0x0, 0x10000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1970) {
  int f = -932921980;

  my_decimal decimal_check = {{0x23BD9D, 0x0, 0x0, 0x80010000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1971) {
  int f = 1438839925;

  my_decimal decimal_check = {{0x8EB1A800, 0x185E, 0x0, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1972) {
  int f = -708643723;

  my_decimal decimal_check = {{0x8EB1A800, 0x185E, 0x0, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1973) {
  int f = 415390267;

  my_decimal decimal_check = {{0xC43F, 0x0, 0x0, 0x1C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1974) {
  int f = -1732093381;

  my_decimal decimal_check = {{0xC43F, 0x0, 0x0, 0x801C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1975) {
  int f = 493512263;

  my_decimal decimal_check = {{0x2F562C, 0x0, 0x0, 0x1B0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1976) {
  int f = -1653971385;

  my_decimal decimal_check = {{0x2F562C, 0x0, 0x0, 0x801B0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1977) {
  int f = 738744562;

  my_decimal decimal_check = {{0x1D90CE, 0x0, 0x0, 0x120000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1978) {
  int f = -1408739086;

  my_decimal decimal_check = {{0x1D90CE, 0x0, 0x0, 0x80120000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1979) {
  int f = 808244979;

  my_decimal decimal_check = {{0x99833, 0x0, 0x0, 0xF0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1980) {
  int f = -1339238669;

  my_decimal decimal_check = {{0x99833, 0x0, 0x0, 0x800F0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1981) {
  int f = 1031443019;

  my_decimal decimal_check = {{0x5D585B, 0x0, 0x0, 0x80000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1982) {
  int f = -1116040629;

  my_decimal decimal_check = {{0x5D585B, 0x0, 0x0, 0x80080000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1983) {
  int f = 675133069;

  my_decimal decimal_check = {{0x1011BF, 0x0, 0x0, 0x140000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1984) {
  int f = -1472350579;

  my_decimal decimal_check = {{0x1011BF, 0x0, 0x0, 0x80140000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1985) {
  int f = 375282254;

  my_decimal decimal_check = {{0x704, 0x0, 0x0, 0x1C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1986) {
  int f = -1772201394;

  my_decimal decimal_check = {{0x704, 0x0, 0x0, 0x801C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1987) {
  int f = 907862116;

  my_decimal decimal_check = {{0x23AB6A, 0x0, 0x0, 0xC0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1988) {
  int f = -1239621532;

  my_decimal decimal_check = {{0x23AB6A, 0x0, 0x0, 0x800C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1989) {
  int f = 1410705862;

  my_decimal decimal_check = {{0xA71AE280, 0x256, 0x0, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1990) {
  int f = -736777786;

  my_decimal decimal_check = {{0xA71AE280, 0x256, 0x0, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1991) {
  int f = 1478505042;

  my_decimal decimal_check = {{0x45B9AF00, 0x280C9, 0x0, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1992) {
  int f = -668978606;

  my_decimal decimal_check = {{0x45B9AF00, 0x280C9, 0x0, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1993) {
  int f = 438660187;

  my_decimal decimal_check = {{0x53847, 0x0, 0x0, 0x1C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1994) {
  int f = -1708823461;

  my_decimal decimal_check = {{0x53847, 0x0, 0x0, 0x801C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1995) {
  int f = 758096921;

  my_decimal decimal_check = {{0x985823, 0x0, 0x0, 0x120000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1996) {
  int f = -1389386727;

  my_decimal decimal_check = {{0x985823, 0x0, 0x0, 0x80120000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1997) {
  int f = 1077061398;

  my_decimal decimal_check = {{0x2A9818, 0x0, 0x0, 0x60000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1998) {
  int f = -1070422250;

  my_decimal decimal_check = {{0x2A9818, 0x0, 0x0, 0x80060000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok1999) {
  int f = 1699842287;

  my_decimal decimal_check = {{0xBEFB0000, 0x8EFEAE8E, 0xD18, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2000) {
  int f = -447641361;

  my_decimal decimal_check = {{0xBEFB0000, 0x8EFEAE8E, 0xD18, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2001) {
  int f = 1870659583;

  my_decimal decimal_check = {{0x20000000, 0xB392B21A, 0xFFFFFF77, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2002) {
  int f = -276824065;

  my_decimal decimal_check = {
      {0x20000000, 0xB392B21A, 0xFFFFFF77, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2003) {
  int f = 1870659582;

  my_decimal decimal_check = {{0x6DC00000, 0x99B1E85F, 0xFFFFFD59, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2004) {
  int f = -276824066;

  my_decimal decimal_check = {
      {0x6DC00000, 0x99B1E85F, 0xFFFFFD59, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2005) {
  int f = 1870659581;

  my_decimal decimal_check = {{0x6DC00000, 0x99B1E85F, 0xFFFFFD59, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2006) {
  int f = -276824067;

  my_decimal decimal_check = {
      {0x6DC00000, 0x99B1E85F, 0xFFFFFD59, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2007) {
  int f = 1870659580;

  my_decimal decimal_check = {{0xBB800000, 0x7FD11EA4, 0xFFFFFB3B, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2008) {
  int f = -276824068;

  my_decimal decimal_check = {
      {0xBB800000, 0x7FD11EA4, 0xFFFFFB3B, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2009) {
  int f = 1870659579;

  my_decimal decimal_check = {{0xBB800000, 0x7FD11EA4, 0xFFFFFB3B, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2010) {
  int f = -276824069;

  my_decimal decimal_check = {
      {0xBB800000, 0x7FD11EA4, 0xFFFFFB3B, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2011) {
  int f = 1870659578;

  my_decimal decimal_check = {{0x9400000, 0x65F054EA, 0xFFFFF91D, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2012) {
  int f = -276824070;

  my_decimal decimal_check = {{0x9400000, 0x65F054EA, 0xFFFFF91D, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2013) {
  int f = 1870659577;

  my_decimal decimal_check = {{0x9400000, 0x65F054EA, 0xFFFFF91D, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2014) {
  int f = -276824071;

  my_decimal decimal_check = {{0x9400000, 0x65F054EA, 0xFFFFF91D, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2015) {
  int f = 1870659576;

  my_decimal decimal_check = {{0x57000000, 0x4C0F8B2F, 0xFFFFF6FF, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2016) {
  int f = -276824072;

  my_decimal decimal_check = {
      {0x57000000, 0x4C0F8B2F, 0xFFFFF6FF, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2017) {
  int f = 1870659568;

  my_decimal decimal_check = {{0x40400000, 0xFE6D2DFF, 0xFFFFF0A4, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2018) {
  int f = -276824080;

  my_decimal decimal_check = {
      {0x40400000, 0xFE6D2DFF, 0xFFFFF0A4, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2019) {
  int f = 1870659552;

  my_decimal decimal_check = {{0xAE400000, 0x2F66E029, 0xFFFFDFB4, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2020) {
  int f = -276824096;

  my_decimal decimal_check = {
      {0xAE400000, 0x2F66E029, 0xFFFFDFB4, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2021) {
  int f = 1870659520;

  my_decimal decimal_check = {{0x3C800000, 0xAB3B0E39, 0xFFFFBFF0, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2022) {
  int f = -276824128;

  my_decimal decimal_check = {
      {0x3C800000, 0xAB3B0E39, 0xFFFFBFF0, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2023) {
  int f = 1867863381;

  my_decimal decimal_check = {{0xC00000, 0x739A8254, 0xD5555598, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2024) {
  int f = -279620267;

  my_decimal decimal_check = {{0xC00000, 0x739A8254, 0xD5555598, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2025) {
  int f = 1866465280;

  my_decimal decimal_check = {{0x98000000, 0xC6AE0593, 0xBFFFFF99, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2026) {
  int f = -281018368;

  my_decimal decimal_check = {
      {0x98000000, 0xC6AE0593, 0xBFFFFF99, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2027) {
  int f = 1865067178;

  my_decimal decimal_check = {{0x2F400000, 0x19C188D3, 0xAAAAA99B, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2028) {
  int f = -282416470;

  my_decimal decimal_check = {
      {0x2F400000, 0x19C188D3, 0xAAAAA99B, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2029) {
  int f = 1862270976;

  my_decimal decimal_check = {{0x10000000, 0xD9C9590D, 0x7FFFFFBB, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2030) {
  int f = -285212672;

  my_decimal decimal_check = {
      {0x10000000, 0xD9C9590D, 0x7FFFFFBB, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2031) {
  int f = 1851086165;

  my_decimal decimal_check = {{0xACC00000, 0xA35ED303, 0x355555ED, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2032) {
  int f = -296397483;

  my_decimal decimal_check = {
      {0xACC00000, 0xA35ED303, 0x355555ED, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2033) {
  int f = 1848289962;

  my_decimal decimal_check = {{0x1F400000, 0x3FF82FC6, 0x2AAAA9DF, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2034) {
  int f = -299193686;

  my_decimal decimal_check = {
      {0x1F400000, 0x3FF82FC6, 0x2AAAA9DF, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2035) {
  int f = 1817531733;

  my_decimal decimal_check = {{0xF6A00000, 0xA0EF22E8, 0x3555565, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2036) {
  int f = -329951915;

  my_decimal decimal_check = {{0xF6A00000, 0xA0EF22E8, 0x3555565, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2037) {
  int f = 1814735530;

  my_decimal decimal_check = {{0xCF500000, 0x709C67CB, 0x2AAAAA7, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2038) {
  int f = -332748118;

  my_decimal decimal_check = {{0xCF500000, 0x709C67CB, 0x2AAAAA7, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2039) {
  int f = 1750422869;

  my_decimal decimal_check = {{0x19440000, 0x590D4990, 0x35555, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2040) {
  int f = -397060779;

  my_decimal decimal_check = {{0x19440000, 0x590D4990, 0x35555, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2041) {
  int f = 1744830464;

  my_decimal decimal_check = {{0xFD700000, 0x501B713, 0x20000, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2042) {
  int f = -402653184;

  my_decimal decimal_check = {{0xFD700000, 0x501B713, 0x20000, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2043) {
  int f = 1744830463;

  my_decimal decimal_check = {{0x560C0000, 0xF7210060, 0x1FFFF, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2044) {
  int f = -402653185;

  my_decimal decimal_check = {{0x560C0000, 0xF7210060, 0x1FFFF, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2045) {
  int f = 1744830462;

  my_decimal decimal_check = {{0x560C0000, 0xF7210060, 0x1FFFF, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2046) {
  int f = -402653186;

  my_decimal decimal_check = {{0x560C0000, 0xF7210060, 0x1FFFF, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2047) {
  int f = 1747626666;

  my_decimal decimal_check = {{0x37A80000, 0xA81724F8, 0x2AAAA, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2048) {
  int f = -399856982;

  my_decimal decimal_check = {{0x37A80000, 0xA81724F8, 0x2AAAA, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2049) {
  int f = 1742034261;

  my_decimal decimal_check = {{0x38F00000, 0xA596496E, 0x1AAAA, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2050) {
  int f = -405449387;

  my_decimal decimal_check = {{0x38F00000, 0xA596496E, 0x1AAAA, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2051) {
  int f = 1739238058;

  my_decimal decimal_check = {{0x1BD40000, 0x540B927C, 0x15555, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2052) {
  int f = -408245590;

  my_decimal decimal_check = {{0x1BD40000, 0x540B927C, 0x15555, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2053) {
  int f = 1677721600;

  my_decimal decimal_check = {{0xF16C8000, 0x1F28, 0x200, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2054) {
  int f = -469762048;

  my_decimal decimal_check = {{0xF16C8000, 0x1F28, 0x200, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2055) {
  int f = 1677721599;

  my_decimal decimal_check = {{0x4CA60000, 0xFFFC91AA, 0x1FF, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2056) {
  int f = -469762049;

  my_decimal decimal_check = {{0x4CA60000, 0xFFFC91AA, 0x1FF, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2057) {
  int f = 1677721598;

  my_decimal decimal_check = {{0x4CA60000, 0xFFFC91AA, 0x1FF, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2058) {
  int f = -469762050;

  my_decimal decimal_check = {{0x4CA60000, 0xFFFC91AA, 0x1FF, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2059) {
  int f = 1674925397;

  my_decimal decimal_check = {{0x39FB8000, 0xAAAB5C37, 0x1AA, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2060) {
  int f = -472558251;

  my_decimal decimal_check = {{0x39FB8000, 0xAAAB5C37, 0x1AA, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2061) {
  int f = 1672129194;

  my_decimal decimal_check = {{0xDDC40000, 0x55530BC6, 0x155, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2062) {
  int f = -475354454;

  my_decimal decimal_check = {{0xDDC40000, 0x55530BC6, 0x155, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2063) {
  int f = 1644167168;

  my_decimal decimal_check = {{0x2D078000, 0xFFFFF694, 0x1F, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2064) {
  int f = -503316480;

  my_decimal decimal_check = {{0x2D078000, 0xFFFFF694, 0x1F, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2065) {
  int f = 1644167167;

  my_decimal decimal_check = {{0x2D078000, 0xFFFFF694, 0x1F, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2066) {
  int f = -503316481;

  my_decimal decimal_check = {{0x2D078000, 0xFFFFF694, 0x1F, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2067) {
  int f = 1644167166;

  my_decimal decimal_check = {{0x1C8D4000, 0xFFFF9BA1, 0x1F, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2068) {
  int f = -503316482;

  my_decimal decimal_check = {{0x1C8D4000, 0xFFFF9BA1, 0x1F, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2069) {
  int f = 1641370965;

  my_decimal decimal_check = {{0xD5AF0000, 0xAAAAC121, 0x1A, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2070) {
  int f = -506112683;

  my_decimal decimal_check = {{0xD5AF0000, 0xAAAAC121, 0x1A, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2071) {
  int f = 1638574762;

  my_decimal decimal_check = {{0x6DDC4000, 0x555530BC, 0x15, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2072) {
  int f = -508908886;

  my_decimal decimal_check = {{0x6DDC4000, 0x555530BC, 0x15, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2073) {
  int f = 1627389952;

  my_decimal decimal_check = {{0x937F0000, 0x2B1E, 0x8, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2074) {
  int f = -520093696;

  my_decimal decimal_check = {{0x937F0000, 0x2B1E, 0x8, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2075) {
  int f = 1627389951;

  my_decimal decimal_check = {{0x8304C000, 0xFFFFD02B, 0x7, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2076) {
  int f = -520093697;

  my_decimal decimal_check = {{0x8304C000, 0xFFFFD02B, 0x7, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2077) {
  int f = 1627389950;

  my_decimal decimal_check = {{0x8304C000, 0xFFFFD02B, 0x7, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2078) {
  int f = -520093698;

  my_decimal decimal_check = {{0x8304C000, 0xFFFFD02B, 0x7, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2079) {
  int f = 1624593749;

  my_decimal decimal_check = {{0x756BC000, 0xAAAAB048, 0x6, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2080) {
  int f = -522889899;

  my_decimal decimal_check = {{0x756BC000, 0xAAAAB048, 0x6, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2081) {
  int f = 1621797546;

  my_decimal decimal_check = {{0x42B06000, 0x555550BB, 0x5, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2082) {
  int f = -525686102;

  my_decimal decimal_check = {{0x42B06000, 0x555550BB, 0x5, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2083) {
  int f = 1616205141;

  my_decimal decimal_check = {{0x3AB5E000, 0x55555824, 0x3, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2084) {
  int f = -531278507;

  my_decimal decimal_check = {{0x3AB5E000, 0x55555824, 0x3, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2085) {
  int f = 1610612736;

  my_decimal decimal_check = {{0x566D2000, 0x1AF, 0x2, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2086) {
  int f = -536870912;

  my_decimal decimal_check = {{0x566D2000, 0x1AF, 0x2, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2087) {
  int f = 1610612735;

  my_decimal decimal_check = {{0x566D2000, 0x1AF, 0x2, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2088) {
  int f = -536870913;

  my_decimal decimal_check = {{0x566D2000, 0x1AF, 0x2, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2089) {
  int f = 1610612734;

  my_decimal decimal_check = {{0x7FA8000, 0xFFFFF897, 0x1, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2090) {
  int f = -536870914;

  my_decimal decimal_check = {{0x7FA8000, 0xFFFFF897, 0x1, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2091) {
  int f = 1607816533;

  my_decimal decimal_check = {{0xF621A000, 0xAAAAA785, 0x1, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2092) {
  int f = -539667115;

  my_decimal decimal_check = {{0xF621A000, 0xAAAAA785, 0x1, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2093) {
  int f = 1606418432;

  my_decimal decimal_check = {{0x946E8000, 0x80000389, 0x1, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2094) {
  int f = -541065216;

  my_decimal decimal_check = {{0x946E8000, 0x80000389, 0x1, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2095) {
  int f = 1605020330;

  my_decimal decimal_check = {{0xE448C000, 0x55555674, 0x1, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2096) {
  int f = -542463318;

  my_decimal decimal_check = {{0xE448C000, 0x55555674, 0x1, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2097) {
  int f = 1342177280;

  my_decimal decimal_check = {{0x198, 0x2, 0x0, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2098) {
  int f = -805306368;

  my_decimal decimal_check = {{0x198, 0x2, 0x0, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2099) {
  int f = 1342177279;

  my_decimal decimal_check = {{0xFFFFFDB0, 0x1, 0x0, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2100) {
  int f = -805306369;

  my_decimal decimal_check = {{0xFFFFFDB0, 0x1, 0x0, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2101) {
  int f = 1342177278;

  my_decimal decimal_check = {{0xFFFFFDB0, 0x1, 0x0, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2102) {
  int f = -805306370;

  my_decimal decimal_check = {{0xFFFFFDB0, 0x1, 0x0, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2103) {
  int f = 1339381077;

  my_decimal decimal_check = {{0xAAAAAB58, 0x1, 0x0, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2104) {
  int f = -808102571;

  my_decimal decimal_check = {{0xAAAAAB58, 0x1, 0x0, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2105) {
  int f = 1337982976;

  my_decimal decimal_check = {{0x80000038, 0x1, 0x0, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2106) {
  int f = -809500672;

  my_decimal decimal_check = {{0x80000038, 0x1, 0x0, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2107) {
  int f = 1336584874;

  my_decimal decimal_check = {{0x55555518, 0x1, 0x0, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2108) {
  int f = -810898774;

  my_decimal decimal_check = {{0x55555518, 0x1, 0x0, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2109) {
  int f = 1251776119;

  my_decimal decimal_check = {{0x4E4B3C, 0x0, 0x0, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2110) {
  int f = -895707529;

  my_decimal decimal_check = {{0x4E4B3C, 0x0, 0x0, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2111) {
  int f = 1251776118;

  my_decimal decimal_check = {{0x4E4B3B, 0x0, 0x0, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2112) {
  int f = -895707530;

  my_decimal decimal_check = {{0x4E4B3B, 0x0, 0x0, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2113) {
  int f = 1251776117;

  my_decimal decimal_check = {{0x4E4B3A, 0x0, 0x0, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2114) {
  int f = -895707531;

  my_decimal decimal_check = {{0x4E4B3A, 0x0, 0x0, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2115) {
  int f = 1233785337;

  my_decimal decimal_check = {{0x11423F, 0x0, 0x0, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2116) {
  int f = -913698311;

  my_decimal decimal_check = {{0x11423F, 0x0, 0x0, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2117) {
  int f = 1233785336;

  my_decimal decimal_check = {{0x11423F, 0x0, 0x0, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2118) {
  int f = -913698312;

  my_decimal decimal_check = {{0x11423F, 0x0, 0x0, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2119) {
  int f = 1233785335;

  my_decimal decimal_check = {{0x11423F, 0x0, 0x0, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2120) {
  int f = -913698313;

  my_decimal decimal_check = {{0x11423F, 0x0, 0x0, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2121) {
  int f = 1207959551;

  my_decimal decimal_check = {{0x20000, 0x0, 0x0, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2122) {
  int f = -939524097;

  my_decimal decimal_check = {{0x20000, 0x0, 0x0, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2123) {
  int f = 1207959425;

  my_decimal decimal_check = {{0x1FFFF, 0x0, 0x0, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2124) {
  int f = -939524223;

  my_decimal decimal_check = {{0x1FFFF, 0x0, 0x0, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2125) {
  int f = 1207959424;

  my_decimal decimal_check = {{0x1FFFF, 0x0, 0x0, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2126) {
  int f = -939524224;

  my_decimal decimal_check = {{0x1FFFF, 0x0, 0x0, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2127) {
  int f = 1207959423;

  my_decimal decimal_check = {{0x1FFFF, 0x0, 0x0, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2128) {
  int f = -939524225;

  my_decimal decimal_check = {{0x1FFFF, 0x0, 0x0, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2129) {
  int f = 1205163349;

  my_decimal decimal_check = {{0x10AAAB, 0x0, 0x0, 0x10000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2130) {
  int f = -942320299;

  my_decimal decimal_check = {{0x10AAAB, 0x0, 0x0, 0x80010000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2131) {
  int f = 1203765249;

  my_decimal decimal_check = {{0x960001, 0x0, 0x0, 0x20000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2132) {
  int f = -943718399;

  my_decimal decimal_check = {{0x960001, 0x0, 0x0, 0x80020000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2133) {
  int f = 1203765248;

  my_decimal decimal_check = {{0x18000, 0x0, 0x0, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2134) {
  int f = -943718400;

  my_decimal decimal_check = {{0x18000, 0x0, 0x0, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2135) {
  int f = 1203765247;

  my_decimal decimal_check = {{0x95FFFF, 0x0, 0x0, 0x20000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2136) {
  int f = -943718401;

  my_decimal decimal_check = {{0x95FFFF, 0x0, 0x0, 0x80020000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2137) {
  int f = 1202367146;

  my_decimal decimal_check = {{0x855555, 0x0, 0x0, 0x20000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2138) {
  int f = -945116502;

  my_decimal decimal_check = {{0x855555, 0x0, 0x0, 0x80020000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2139) {
  int f = 1202367105;

  my_decimal decimal_check = {{0x855535, 0x0, 0x0, 0x20000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2140) {
  int f = -945116543;

  my_decimal decimal_check = {{0x855535, 0x0, 0x0, 0x80020000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2141) {
  int f = 1202367104;

  my_decimal decimal_check = {{0x15555, 0x0, 0x0, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2142) {
  int f = -945116544;

  my_decimal decimal_check = {{0x15555, 0x0, 0x0, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2143) {
  int f = 1202367103;

  my_decimal decimal_check = {{0x855533, 0x0, 0x0, 0x20000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2144) {
  int f = -945116545;

  my_decimal decimal_check = {{0x855533, 0x0, 0x0, 0x80020000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2145) {
  int f = 1195593729;

  my_decimal decimal_check = {{0xC350, 0x0, 0x0, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2146) {
  int f = -951889919;

  my_decimal decimal_check = {{0xC350, 0x0, 0x0, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2147) {
  int f = 1195593728;

  my_decimal decimal_check = {{0xC350, 0x0, 0x0, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2148) {
  int f = -951889920;

  my_decimal decimal_check = {{0xC350, 0x0, 0x0, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2149) {
  int f = 1195593727;

  my_decimal decimal_check = {{0xC350, 0x0, 0x0, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2150) {
  int f = -951889921;

  my_decimal decimal_check = {{0xC350, 0x0, 0x0, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2151) {
  int f = 1190789121;

  my_decimal decimal_check = {{0x7D00, 0x0, 0x0, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2152) {
  int f = -956694527;

  my_decimal decimal_check = {{0x7D00, 0x0, 0x0, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2153) {
  int f = 1190789120;

  my_decimal decimal_check = {{0x7D00, 0x0, 0x0, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2154) {
  int f = -956694528;

  my_decimal decimal_check = {{0x7D00, 0x0, 0x0, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2155) {
  int f = 1190789119;

  my_decimal decimal_check = {{0x7D00, 0x0, 0x0, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2156) {
  int f = -956694529;

  my_decimal decimal_check = {{0x7D00, 0x0, 0x0, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2157) {
  int f = 1149239297;

  my_decimal decimal_check = {{0x400, 0x0, 0x0, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2158) {
  int f = -998244351;

  my_decimal decimal_check = {{0x400, 0x0, 0x0, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2159) {
  int f = 1149239296;

  my_decimal decimal_check = {{0x400, 0x0, 0x0, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2160) {
  int f = -998244352;

  my_decimal decimal_check = {{0x400, 0x0, 0x0, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2161) {
  int f = 1149239295;

  my_decimal decimal_check = {{0x400, 0x0, 0x0, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2162) {
  int f = -998244353;

  my_decimal decimal_check = {{0x400, 0x0, 0x0, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2163) {
  int f = 1140850689;

  my_decimal decimal_check = {{0x4E2001, 0x0, 0x0, 0x40000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2164) {
  int f = -1006632959;

  my_decimal decimal_check = {{0x4E2001, 0x0, 0x0, 0x80040000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2165) {
  int f = 1140850688;

  my_decimal decimal_check = {{0x200, 0x0, 0x0, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2166) {
  int f = -1006632960;

  my_decimal decimal_check = {{0x200, 0x0, 0x0, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2167) {
  int f = 1140850687;

  my_decimal decimal_check = {{0x200, 0x0, 0x0, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2168) {
  int f = -1006632961;

  my_decimal decimal_check = {{0x200, 0x0, 0x0, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2169) {
  int f = 1140850686;

  my_decimal decimal_check = {{0x4E1FFF, 0x0, 0x0, 0x40000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2170) {
  int f = -1006632962;

  my_decimal decimal_check = {{0x4E1FFF, 0x0, 0x0, 0x80040000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2171) {
  int f = 1138054485;

  my_decimal decimal_check = {{0x411AAB, 0x0, 0x0, 0x40000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2172) {
  int f = -1009429163;

  my_decimal decimal_check = {{0x411AAB, 0x0, 0x0, 0x80040000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2173) {
  int f = 1136656384;

  my_decimal decimal_check = {{0x180, 0x0, 0x0, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2174) {
  int f = -1010827264;

  my_decimal decimal_check = {{0x180, 0x0, 0x0, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2175) {
  int f = 1135258282;

  my_decimal decimal_check = {{0x341555, 0x0, 0x0, 0x40000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2176) {
  int f = -1012225366;

  my_decimal decimal_check = {{0x341555, 0x0, 0x0, 0x80040000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2177) {
  int f = 1115684865;

  my_decimal decimal_check = {{0x61A801, 0x0, 0x0, 0x50000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2178) {
  int f = -1031798783;

  my_decimal decimal_check = {{0x61A801, 0x0, 0x0, 0x80050000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2179) {
  int f = 1115684864;

  my_decimal decimal_check = {{0x40, 0x0, 0x0, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2180) {
  int f = -1031798784;

  my_decimal decimal_check = {{0x40, 0x0, 0x0, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2181) {
  int f = 1115684863;

  my_decimal decimal_check = {{0x40, 0x0, 0x0, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2182) {
  int f = -1031798785;

  my_decimal decimal_check = {{0x40, 0x0, 0x0, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2183) {
  int f = 1107296256;

  my_decimal decimal_check = {{0x20, 0x0, 0x0, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2184) {
  int f = -1040187392;

  my_decimal decimal_check = {{0x20, 0x0, 0x0, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2185) {
  int f = 1107296255;

  my_decimal decimal_check = {{0x20, 0x0, 0x0, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2186) {
  int f = -1040187393;

  my_decimal decimal_check = {{0x20, 0x0, 0x0, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2187) {
  int f = 1107296254;

  my_decimal decimal_check = {{0x20, 0x0, 0x0, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2188) {
  int f = -1040187394;

  my_decimal decimal_check = {{0x20, 0x0, 0x0, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2189) {
  int f = 1104500053;

  my_decimal decimal_check = {{0x28B0AB, 0x0, 0x0, 0x50000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2190) {
  int f = -1042983595;

  my_decimal decimal_check = {{0x28B0AB, 0x0, 0x0, 0x80050000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2191) {
  int f = 1103101952;

  my_decimal decimal_check = {{0x18, 0x0, 0x0, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2192) {
  int f = -1044381696;

  my_decimal decimal_check = {{0x18, 0x0, 0x0, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2193) {
  int f = 1101703850;

  my_decimal decimal_check = {{0x208D55, 0x0, 0x0, 0x50000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2194) {
  int f = -1045779798;

  my_decimal decimal_check = {{0x208D55, 0x0, 0x0, 0x80050000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2195) {
  int f = 1098907649;

  my_decimal decimal_check = {{0x10, 0x0, 0x0, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2196) {
  int f = -1048575999;

  my_decimal decimal_check = {{0x10, 0x0, 0x0, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2197) {
  int f = 1098907648;

  my_decimal decimal_check = {{0x10, 0x0, 0x0, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2198) {
  int f = -1048576000;

  my_decimal decimal_check = {{0x10, 0x0, 0x0, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2199) {
  int f = 1098907647;

  my_decimal decimal_check = {{0x10, 0x0, 0x0, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2200) {
  int f = -1048576001;

  my_decimal decimal_check = {{0x10, 0x0, 0x0, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2201) {
  int f = 1093644169;

  my_decimal decimal_check = {{0x10C134, 0x0, 0x0, 0x50000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2202) {
  int f = -1053839479;

  my_decimal decimal_check = {{0x10C134, 0x0, 0x0, 0x80050000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2203) {
  int f = 1091567617;

  my_decimal decimal_check = {{0x895441, 0x0, 0x0, 0x60000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2204) {
  int f = -1055916031;

  my_decimal decimal_check = {{0x895441, 0x0, 0x0, 0x80060000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2205) {
  int f = 1091567616;

  my_decimal decimal_check = {{0x9, 0x0, 0x0, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2206) {
  int f = -1055916032;

  my_decimal decimal_check = {{0x9, 0x0, 0x0, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2207) {
  int f = 1091567615;

  my_decimal decimal_check = {{0x89543F, 0x0, 0x0, 0x60000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2208) {
  int f = -1055916033;

  my_decimal decimal_check = {{0x89543F, 0x0, 0x0, 0x80060000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2209) {
  int f = 1090519040;

  my_decimal decimal_check = {{0x8, 0x0, 0x0, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2210) {
  int f = -1056964608;

  my_decimal decimal_check = {{0x8, 0x0, 0x0, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2211) {
  int f = 1090519039;

  my_decimal decimal_check = {{0x8, 0x0, 0x0, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2212) {
  int f = -1056964609;

  my_decimal decimal_check = {{0x8, 0x0, 0x0, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2213) {
  int f = 1087722837;

  my_decimal decimal_check = {{0x65B9AB, 0x0, 0x0, 0x60000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2214) {
  int f = -1059760811;

  my_decimal decimal_check = {{0x65B9AB, 0x0, 0x0, 0x80060000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2215) {
  int f = 1086324736;

  my_decimal decimal_check = {{0x6, 0x0, 0x0, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2216) {
  int f = -1061158912;

  my_decimal decimal_check = {{0x6, 0x0, 0x0, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2217) {
  int f = 1084926634;

  my_decimal decimal_check = {{0x516155, 0x0, 0x0, 0x60000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2218) {
  int f = -1062557014;

  my_decimal decimal_check = {{0x516155, 0x0, 0x0, 0x80060000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2219) {
  int f = 1082130432;

  my_decimal decimal_check = {{0x4, 0x0, 0x0, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2220) {
  int f = -1065353216;

  my_decimal decimal_check = {{0x4, 0x0, 0x0, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2221) {
  int f = 1082130431;

  my_decimal decimal_check = {{0x4, 0x0, 0x0, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2222) {
  int f = -1065353217;

  my_decimal decimal_check = {{0x4, 0x0, 0x0, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2223) {
  int f = 1082130430;

  my_decimal decimal_check = {{0x4, 0x0, 0x0, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2224) {
  int f = -1065353218;

  my_decimal decimal_check = {{0x4, 0x0, 0x0, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2225) {
  int f = 1079334229;

  my_decimal decimal_check = {{0x32DCD5, 0x0, 0x0, 0x60000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2226) {
  int f = -1068149419;

  my_decimal decimal_check = {{0x32DCD5, 0x0, 0x0, 0x80060000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2227) {
  int f = 1077936128;

  my_decimal decimal_check = {{0x3, 0x0, 0x0, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2228) {
  int f = -1069547520;

  my_decimal decimal_check = {{0x3, 0x0, 0x0, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2229) {
  int f = 1076538026;

  my_decimal decimal_check = {{0x28B0AB, 0x0, 0x0, 0x60000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2230) {
  int f = -1070945622;

  my_decimal decimal_check = {{0x28B0AB, 0x0, 0x0, 0x80060000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2231) {
  int f = 1073741825;

  my_decimal decimal_check = {{0x2, 0x0, 0x0, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2232) {
  int f = -1073741823;

  my_decimal decimal_check = {{0x2, 0x0, 0x0, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2233) {
  int f = 1073741824;

  my_decimal decimal_check = {{0x2, 0x0, 0x0, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2234) {
  int f = -1073741824;

  my_decimal decimal_check = {{0x2, 0x0, 0x0, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2235) {
  int f = 1073741823;

  my_decimal decimal_check = {{0x2, 0x0, 0x0, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2236) {
  int f = -1073741825;

  my_decimal decimal_check = {{0x2, 0x0, 0x0, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2237) {
  int f = 1069547521;

  my_decimal decimal_check = {{0xF, 0x0, 0x0, 0x10000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2238) {
  int f = -1077936127;

  my_decimal decimal_check = {{0xF, 0x0, 0x0, 0x80010000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2239) {
  int f = 1069547520;

  my_decimal decimal_check = {{0xF, 0x0, 0x0, 0x10000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2240) {
  int f = -1077936128;

  my_decimal decimal_check = {{0xF, 0x0, 0x0, 0x80010000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2241) {
  int f = 1069547519;

  my_decimal decimal_check = {{0xF, 0x0, 0x0, 0x10000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2242) {
  int f = -1077936129;

  my_decimal decimal_check = {{0xF, 0x0, 0x0, 0x80010000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2243) {
  int f = 1065353216;

  my_decimal decimal_check = {{0x1, 0x0, 0x0, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2244) {
  int f = -1082130432;

  my_decimal decimal_check = {{0x1, 0x0, 0x0, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2245) {
  int f = 1065353216;

  my_decimal decimal_check = {{0x1, 0x0, 0x0, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2246) {
  int f = -1082130432;

  my_decimal decimal_check = {{0x1, 0x0, 0x0, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2247) {
  int f = 1065353217;

  my_decimal decimal_check = {{0x1, 0x0, 0x0, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2248) {
  int f = -1082130431;

  my_decimal decimal_check = {{0x1, 0x0, 0x0, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2249) {
  int f = 1065353216;

  my_decimal decimal_check = {{0x1, 0x0, 0x0, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2250) {
  int f = -1082130432;

  my_decimal decimal_check = {{0x1, 0x0, 0x0, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2251) {
  int f = 1065353217;

  my_decimal decimal_check = {{0x1, 0x0, 0x0, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2252) {
  int f = -1082130431;

  my_decimal decimal_check = {{0x1, 0x0, 0x0, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2253) {
  int f = 1065353216;

  my_decimal decimal_check = {{0x1, 0x0, 0x0, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2254) {
  int f = -1082130432;

  my_decimal decimal_check = {{0x1, 0x0, 0x0, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2255) {
  int f = 1065353217;

  my_decimal decimal_check = {{0x1, 0x0, 0x0, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2256) {
  int f = -1082130431;

  my_decimal decimal_check = {{0x1, 0x0, 0x0, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2257) {
  int f = 1065353216;

  my_decimal decimal_check = {{0x1, 0x0, 0x0, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2258) {
  int f = -1082130432;

  my_decimal decimal_check = {{0x1, 0x0, 0x0, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2259) {
  int f = 1065353218;

  my_decimal decimal_check = {{0x1, 0x0, 0x0, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2260) {
  int f = -1082130430;

  my_decimal decimal_check = {{0x1, 0x0, 0x0, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2261) {
  int f = 1065353217;

  my_decimal decimal_check = {{0x1, 0x0, 0x0, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2262) {
  int f = -1082130431;

  my_decimal decimal_check = {{0x1, 0x0, 0x0, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2263) {
  int f = 1065353218;

  my_decimal decimal_check = {{0x1, 0x0, 0x0, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2264) {
  int f = -1082130430;

  my_decimal decimal_check = {{0x1, 0x0, 0x0, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2265) {
  int f = 1065353217;

  my_decimal decimal_check = {{0x1, 0x0, 0x0, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2266) {
  int f = -1082130431;

  my_decimal decimal_check = {{0x1, 0x0, 0x0, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2267) {
  int f = 1065353218;

  my_decimal decimal_check = {{0x1, 0x0, 0x0, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2268) {
  int f = -1082130430;

  my_decimal decimal_check = {{0x1, 0x0, 0x0, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2269) {
  int f = 1065353217;

  my_decimal decimal_check = {{0x1, 0x0, 0x0, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2270) {
  int f = -1082130431;

  my_decimal decimal_check = {{0x1, 0x0, 0x0, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2271) {
  int f = 1065353218;

  my_decimal decimal_check = {{0x1, 0x0, 0x0, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2272) {
  int f = -1082130430;

  my_decimal decimal_check = {{0x1, 0x0, 0x0, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2273) {
  int f = 1065353218;

  my_decimal decimal_check = {{0x1, 0x0, 0x0, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2274) {
  int f = -1082130430;

  my_decimal decimal_check = {{0x1, 0x0, 0x0, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2275) {
  int f = 1606418433;

  my_decimal decimal_check = {{0x946E8000, 0x80000389, 0x1, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2276) {
  int f = -541065215;

  my_decimal decimal_check = {{0x946E8000, 0x80000389, 0x1, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2277) {
  int f = 1606418432;

  my_decimal decimal_check = {{0x946E8000, 0x80000389, 0x1, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2278) {
  int f = -541065216;

  my_decimal decimal_check = {{0x946E8000, 0x80000389, 0x1, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2279) {
  int f = 1606418432;

  my_decimal decimal_check = {{0x946E8000, 0x80000389, 0x1, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2280) {
  int f = -541065216;

  my_decimal decimal_check = {{0x946E8000, 0x80000389, 0x1, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2281) {
  int f = 1606418432;

  my_decimal decimal_check = {{0x946E8000, 0x80000389, 0x1, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2282) {
  int f = -541065216;

  my_decimal decimal_check = {{0x946E8000, 0x80000389, 0x1, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2283) {
  int f = 1202367147;

  my_decimal decimal_check = {{0x855556, 0x0, 0x0, 0x20000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2284) {
  int f = -945116501;

  my_decimal decimal_check = {{0x855556, 0x0, 0x0, 0x80020000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2285) {
  int f = 1202367147;

  my_decimal decimal_check = {{0x855556, 0x0, 0x0, 0x20000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2286) {
  int f = -945116501;

  my_decimal decimal_check = {{0x855556, 0x0, 0x0, 0x80020000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2287) {
  int f = 1202367146;

  my_decimal decimal_check = {{0x855555, 0x0, 0x0, 0x20000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2288) {
  int f = -945116502;

  my_decimal decimal_check = {{0x855555, 0x0, 0x0, 0x80020000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2289) {
  int f = 1202367146;

  my_decimal decimal_check = {{0x855555, 0x0, 0x0, 0x20000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2290) {
  int f = -945116502;

  my_decimal decimal_check = {{0x855555, 0x0, 0x0, 0x80020000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2291) {
  int f = 1107296257;

  my_decimal decimal_check = {{0x20, 0x0, 0x0, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2292) {
  int f = -1040187391;

  my_decimal decimal_check = {{0x20, 0x0, 0x0, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2293) {
  int f = 1107296257;

  my_decimal decimal_check = {{0x20, 0x0, 0x0, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2294) {
  int f = -1040187391;

  my_decimal decimal_check = {{0x20, 0x0, 0x0, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2295) {
  int f = 1107296256;

  my_decimal decimal_check = {{0x20, 0x0, 0x0, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2296) {
  int f = -1040187392;

  my_decimal decimal_check = {{0x20, 0x0, 0x0, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2297) {
  int f = 1107296256;

  my_decimal decimal_check = {{0x20, 0x0, 0x0, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2298) {
  int f = -1040187392;

  my_decimal decimal_check = {{0x20, 0x0, 0x0, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2299) {
  int f = 1107296256;

  my_decimal decimal_check = {{0x20, 0x0, 0x0, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2300) {
  int f = -1040187392;

  my_decimal decimal_check = {{0x20, 0x0, 0x0, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2301) {
  int f = 1107296256;

  my_decimal decimal_check = {{0x20, 0x0, 0x0, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2302) {
  int f = -1040187392;

  my_decimal decimal_check = {{0x20, 0x0, 0x0, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2303) {
  int f = 1042284544;

  my_decimal decimal_check = {{0x3D09, 0x0, 0x0, 0x50000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2304) {
  int f = -1105199104;

  my_decimal decimal_check = {{0x3D09, 0x0, 0x0, 0x80050000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2305) {
  int f = 1065353215;

  my_decimal decimal_check = {{0x98967F, 0x0, 0x0, 0x70000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2306) {
  int f = -1082130433;

  my_decimal decimal_check = {{0x98967F, 0x0, 0x0, 0x80070000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2307) {
  int f = 1048575999;

  my_decimal decimal_check = {{0x19, 0x0, 0x0, 0x20000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2308) {
  int f = -1098907649;

  my_decimal decimal_check = {{0x19, 0x0, 0x0, 0x80020000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2309) {
  int f = 1015021567;

  my_decimal decimal_check = {{0x3D09, 0x0, 0x0, 0x60000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2310) {
  int f = -1132462081;

  my_decimal decimal_check = {{0x3D09, 0x0, 0x0, 0x80060000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2311) {
  int f = 947912703;

  my_decimal decimal_check = {{0x5D21DB, 0x0, 0x0, 0xB0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2312) {
  int f = -1199570945;

  my_decimal decimal_check = {{0x5D21DB, 0x0, 0x0, 0x800B0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2313) {
  int f = 813694975;

  my_decimal decimal_check = {{0x8E1BC9, 0x0, 0x0, 0x100000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2314) {
  int f = -1333788673;

  my_decimal decimal_check = {{0x8E1BC9, 0x0, 0x0, 0x80100000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2315) {
  int f = 545259519;

  my_decimal decimal_check = {{0x211654, 0x0, 0x0, 0x190000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2316) {
  int f = -1602224129;

  my_decimal decimal_check = {{0x211654, 0x0, 0x0, 0x80190000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2317) {
  int f = 536870911;

  my_decimal decimal_check = {{0x108B2A, 0x0, 0x0, 0x190000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2318) {
  int f = -1610612737;

  my_decimal decimal_check = {{0x108B2A, 0x0, 0x0, 0x80190000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2319) {
  int f = 528482303;

  my_decimal decimal_check = {{0x52B7D3, 0x0, 0x0, 0x1A0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2320) {
  int f = -1619001345;

  my_decimal decimal_check = {{0x52B7D3, 0x0, 0x0, 0x801A0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2321) {
  int f = 511705087;

  my_decimal decimal_check = {{0x14ADF5, 0x0, 0x0, 0x1A0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2322) {
  int f = -1635778561;

  my_decimal decimal_check = {{0x14ADF5, 0x0, 0x0, 0x801A0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2323) {
  int f = 478150655;

  my_decimal decimal_check = {{0x813F39, 0x0, 0x0, 0x1C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2324) {
  int f = -1669332993;

  my_decimal decimal_check = {{0x813F39, 0x0, 0x0, 0x801C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2325) {
  int f = 411041791;

  my_decimal decimal_check = {{0x813F, 0x0, 0x0, 0x1C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2326) {
  int f = -1736441857;

  my_decimal decimal_check = {{0x813F, 0x0, 0x0, 0x801C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2327) {
  int f = 285212671;

  my_decimal decimal_check = {{0x1, 0x0, 0x0, 0x1C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2328) {
  int f = -1862270977;

  my_decimal decimal_check = {{0x1, 0x0, 0x0, 0x801C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2329) {
  int f = 301989887;

  my_decimal decimal_check = {{0x4, 0x0, 0x0, 0x1C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2330) {
  int f = -1845493761;

  my_decimal decimal_check = {{0x4, 0x0, 0x0, 0x801C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2331) {
  int f = 335544319;

  my_decimal decimal_check = {{0x41, 0x0, 0x0, 0x1C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2332) {
  int f = -1811939329;

  my_decimal decimal_check = {{0x41, 0x0, 0x0, 0x801C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2333) {
  int f = 402653183;

  my_decimal decimal_check = {{0x40A0, 0x0, 0x0, 0x1C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2334) {
  int f = -1744830465;

  my_decimal decimal_check = {{0x40A0, 0x0, 0x0, 0x801C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2335) {
  int f = 1068149418;

  my_decimal decimal_check = {{0x145855, 0x0, 0x0, 0x60000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2336) {
  int f = -1079334230;

  my_decimal decimal_check = {{0x145855, 0x0, 0x0, 0x80060000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2337) {
  int f = 1059760810;

  my_decimal decimal_check = {{0x65B9AA, 0x0, 0x0, 0x70000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2338) {
  int f = -1087722838;

  my_decimal decimal_check = {{0x65B9AA, 0x0, 0x0, 0x80070000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2339) {
  int f = 1042983594;

  my_decimal decimal_check = {{0x196E6B, 0x0, 0x0, 0x70000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2340) {
  int f = -1104500054;

  my_decimal decimal_check = {{0x196E6B, 0x0, 0x0, 0x80070000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2341) {
  int f = 1009429162;

  my_decimal decimal_check = {{0xFE503, 0x0, 0x0, 0x80000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2342) {
  int f = -1138054486;

  my_decimal decimal_check = {{0xFE503, 0x0, 0x0, 0x80080000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2343) {
  int f = 942320298;

  my_decimal decimal_check = {{0x63575, 0x0, 0x0, 0xA0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2344) {
  int f = -1205163350;

  my_decimal decimal_check = {{0x63575, 0x0, 0x0, 0x800A0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2345) {
  int f = 808102570;

  my_decimal decimal_check = {{0x5EBD31, 0x0, 0x0, 0x100000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2346) {
  int f = -1339381078;

  my_decimal decimal_check = {{0x5EBD31, 0x0, 0x0, 0x80100000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2347) {
  int f = 791325354;

  my_decimal decimal_check = {{0x17AF4C, 0x0, 0x0, 0x100000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2348) {
  int f = -1356158294;

  my_decimal decimal_check = {{0x17AF4C, 0x0, 0x0, 0x80100000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2349) {
  int f = 774548138;

  my_decimal decimal_check = {{0x5EBD3, 0x0, 0x0, 0x100000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2350) {
  int f = -1372935510;

  my_decimal decimal_check = {{0x5EBD3, 0x0, 0x0, 0x80100000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2351) {
  int f = 740993706;

  my_decimal decimal_check = {{0x2501E7, 0x0, 0x0, 0x120000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2352) {
  int f = -1406489942;

  my_decimal decimal_check = {{0x2501E7, 0x0, 0x0, 0x80120000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2353) {
  int f = 673884842;

  my_decimal decimal_check = {{0x908F6F, 0x0, 0x0, 0x150000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2354) {
  int f = -1473598806;

  my_decimal decimal_check = {{0x908F6F, 0x0, 0x0, 0x80150000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2355) {
  int f = 665496234;

  my_decimal decimal_check = {{0x4847B7, 0x0, 0x0, 0x150000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2356) {
  int f = -1481987414;

  my_decimal decimal_check = {{0x4847B7, 0x0, 0x0, 0x80150000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2357) {
  int f = 598387370;

  my_decimal decimal_check = {{0x1C3C04, 0x0, 0x0, 0x170000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2358) {
  int f = -1549096278;

  my_decimal decimal_check = {{0x1C3C04, 0x0, 0x0, 0x80170000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2359) {
  int f = 564832938;

  my_decimal decimal_check = {{0x11A582, 0x0, 0x0, 0x180000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2360) {
  int f = -1582650710;

  my_decimal decimal_check = {{0x11A582, 0x0, 0x0, 0x80180000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2361) {
  int f = 539667114;

  my_decimal decimal_check = {{0x160EE3, 0x0, 0x0, 0x190000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2362) {
  int f = -1607816534;

  my_decimal decimal_check = {{0x160EE3, 0x0, 0x0, 0x80190000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2363) {
  int f = 531278506;

  my_decimal decimal_check = {{0x6E4A6E, 0x0, 0x0, 0x1A0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2364) {
  int f = -1616205142;

  my_decimal decimal_check = {{0x6E4A6E, 0x0, 0x0, 0x801A0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2365) {
  int f = 522889898;

  my_decimal decimal_check = {{0x372537, 0x0, 0x0, 0x1A0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2366) {
  int f = -1624593750;

  my_decimal decimal_check = {{0x372537, 0x0, 0x0, 0x801A0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2367) {
  int f = 506112682;

  my_decimal decimal_check = {{0x89DD0A, 0x0, 0x0, 0x1B0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2368) {
  int f = -1641370966;

  my_decimal decimal_check = {{0x89DD0A, 0x0, 0x0, 0x801B0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2369) {
  int f = 472558250;

  my_decimal decimal_check = {{0x562A26, 0x0, 0x0, 0x1C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2370) {
  int f = -1674925398;

  my_decimal decimal_check = {{0x562A26, 0x0, 0x0, 0x801C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2371) {
  int f = 405449386;

  my_decimal decimal_check = {{0x562A, 0x0, 0x0, 0x1C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2372) {
  int f = -1742034262;

  my_decimal decimal_check = {{0x562A, 0x0, 0x0, 0x801C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2373) {
  int f = 388672170;

  my_decimal decimal_check = {{0x158B, 0x0, 0x0, 0x1C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2374) {
  int f = -1758811478;

  my_decimal decimal_check = {{0x158B, 0x0, 0x0, 0x801C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2375) {
  int f = 346729130;

  my_decimal decimal_check = {{0xAC, 0x0, 0x0, 0x1C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2376) {
  int f = -1800754518;

  my_decimal decimal_check = {{0xAC, 0x0, 0x0, 0x801C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2377) {
  int f = 329951914;

  my_decimal decimal_check = {{0x2B, 0x0, 0x0, 0x1C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2378) {
  int f = -1817531734;

  my_decimal decimal_check = {{0x2B, 0x0, 0x0, 0x801C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2379) {
  int f = 296397482;

  my_decimal decimal_check = {{0x3, 0x0, 0x0, 0x1C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2380) {
  int f = -1851086166;

  my_decimal decimal_check = {{0x3, 0x0, 0x0, 0x801C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2381) {
  int f = 1070945621;

  my_decimal decimal_check = {{0x196E6B, 0x0, 0x0, 0x60000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2382) {
  int f = -1076538027;

  my_decimal decimal_check = {{0x196E6B, 0x0, 0x0, 0x80060000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2383) {
  int f = 1062557013;

  my_decimal decimal_check = {{0x7F2815, 0x0, 0x0, 0x70000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2384) {
  int f = -1084926635;

  my_decimal decimal_check = {{0x7F2815, 0x0, 0x0, 0x80070000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2385) {
  int f = 1045779797;

  my_decimal decimal_check = {{0x1FCA05, 0x0, 0x0, 0x70000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2386) {
  int f = -1101703851;

  my_decimal decimal_check = {{0x1FCA05, 0x0, 0x0, 0x80070000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2387) {
  int f = 1012225365;

  my_decimal decimal_check = {{0x13DE43, 0x0, 0x0, 0x80000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2388) {
  int f = -1135258283;

  my_decimal decimal_check = {{0x13DE43, 0x0, 0x0, 0x80080000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2389) {
  int f = 945116501;

  my_decimal decimal_check = {{0x4D9C37, 0x0, 0x0, 0xB0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2390) {
  int f = -1202367147;

  my_decimal decimal_check = {{0x4D9C37, 0x0, 0x0, 0x800B0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2391) {
  int f = 810898773;

  my_decimal decimal_check = {{0x766C7D, 0x0, 0x0, 0x100000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2392) {
  int f = -1336584875;

  my_decimal decimal_check = {{0x766C7D, 0x0, 0x0, 0x80100000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2393) {
  int f = 794121557;

  my_decimal decimal_check = {{0x1D9B1F, 0x0, 0x0, 0x100000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2394) {
  int f = -1353362091;

  my_decimal decimal_check = {{0x1D9B1F, 0x0, 0x0, 0x80100000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2395) {
  int f = 777344341;

  my_decimal decimal_check = {{0x4A03CE, 0x0, 0x0, 0x110000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2396) {
  int f = -1370139307;

  my_decimal decimal_check = {{0x4A03CE, 0x0, 0x0, 0x80110000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2397) {
  int f = 743789909;

  my_decimal decimal_check = {{0x2E4261, 0x0, 0x0, 0x120000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2398) {
  int f = -1403693739;

  my_decimal decimal_check = {{0x2E4261, 0x0, 0x0, 0x80120000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2399) {
  int f = 676681045;

  my_decimal decimal_check = {{0x1211EE, 0x0, 0x0, 0x140000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2400) {
  int f = -1470802603;

  my_decimal decimal_check = {{0x1211EE, 0x0, 0x0, 0x80140000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2401) {
  int f = 668292437;

  my_decimal decimal_check = {{0x5A59A5, 0x0, 0x0, 0x150000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2402) {
  int f = -1479191211;

  my_decimal decimal_check = {{0x5A59A5, 0x0, 0x0, 0x80150000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2403) {
  int f = 643126613;

  my_decimal decimal_check = {{0x70F00F, 0x0, 0x0, 0x160000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2404) {
  int f = -1504357035;

  my_decimal decimal_check = {{0x70F00F, 0x0, 0x0, 0x80160000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2405) {
  int f = 601183573;

  my_decimal decimal_check = {{0x234B05, 0x0, 0x0, 0x170000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2406) {
  int f = -1546300075;

  my_decimal decimal_check = {{0x234B05, 0x0, 0x0, 0x80170000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2407) {
  int f = 567629141;

  my_decimal decimal_check = {{0x160EE3, 0x0, 0x0, 0x180000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2408) {
  int f = -1579854507;

  my_decimal decimal_check = {{0x160EE3, 0x0, 0x0, 0x80180000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2409) {
  int f = 550851925;

  my_decimal decimal_check = {{0x372537, 0x0, 0x0, 0x190000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2410) {
  int f = -1596631723;

  my_decimal decimal_check = {{0x372537, 0x0, 0x0, 0x80190000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2411) {
  int f = 542463317;

  my_decimal decimal_check = {{0x1B929C, 0x0, 0x0, 0x190000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2412) {
  int f = -1605020331;

  my_decimal decimal_check = {{0x1B929C, 0x0, 0x0, 0x80190000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2413) {
  int f = 534074709;

  my_decimal decimal_check = {{0x89DD0A, 0x0, 0x0, 0x1A0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2414) {
  int f = -1613408939;

  my_decimal decimal_check = {{0x89DD0A, 0x0, 0x0, 0x801A0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2415) {
  int f = 525686101;

  my_decimal decimal_check = {{0x44EE85, 0x0, 0x0, 0x1A0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2416) {
  int f = -1621797547;

  my_decimal decimal_check = {{0x44EE85, 0x0, 0x0, 0x801A0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2417) {
  int f = 508908885;

  my_decimal decimal_check = {{0x113BA1, 0x0, 0x0, 0x1A0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2418) {
  int f = -1638574763;

  my_decimal decimal_check = {{0x113BA1, 0x0, 0x0, 0x801A0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2419) {
  int f = 475354453;

  my_decimal decimal_check = {{0x6BB4B0, 0x0, 0x0, 0x1C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2420) {
  int f = -1672129195;

  my_decimal decimal_check = {{0x6BB4B0, 0x0, 0x0, 0x801C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2421) {
  int f = 408245589;

  my_decimal decimal_check = {{0x6BB5, 0x0, 0x0, 0x1C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2422) {
  int f = -1739238059;

  my_decimal decimal_check = {{0x6BB5, 0x0, 0x0, 0x801C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2423) {
  int f = 399856981;

  my_decimal decimal_check = {{0x35DA, 0x0, 0x0, 0x1C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2424) {
  int f = -1747626667;

  my_decimal decimal_check = {{0x35DA, 0x0, 0x0, 0x801C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2425) {
  int f = 391468373;

  my_decimal decimal_check = {{0x1AED, 0x0, 0x0, 0x1C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2426) {
  int f = -1756015275;

  my_decimal decimal_check = {{0x1AED, 0x0, 0x0, 0x801C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2427) {
  int f = 374691157;

  my_decimal decimal_check = {{0x6BB, 0x0, 0x0, 0x1C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2428) {
  int f = -1772792491;

  my_decimal decimal_check = {{0x6BB, 0x0, 0x0, 0x801C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2429) {
  int f = 332748117;

  my_decimal decimal_check = {{0x36, 0x0, 0x0, 0x1C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2430) {
  int f = -1814735531;

  my_decimal decimal_check = {{0x36, 0x0, 0x0, 0x801C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2431) {
  int f = 299193685;

  my_decimal decimal_check = {{0x3, 0x0, 0x0, 0x1C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2432) {
  int f = -1848289963;

  my_decimal decimal_check = {{0x3, 0x0, 0x0, 0x801C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2433) {
  int f = 1061158912;

  my_decimal decimal_check = {{0x4B, 0x0, 0x0, 0x20000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2434) {
  int f = -1086324736;

  my_decimal decimal_check = {{0x4B, 0x0, 0x0, 0x80020000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2435) {
  int f = 1056964608;

  my_decimal decimal_check = {{0x5, 0x0, 0x0, 0x10000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2436) {
  int f = -1090519040;

  my_decimal decimal_check = {{0x5, 0x0, 0x0, 0x80010000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2437) {
  int f = 1044381696;

  my_decimal decimal_check = {{0x753, 0x0, 0x0, 0x40000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2438) {
  int f = -1103101952;

  my_decimal decimal_check = {{0x753, 0x0, 0x0, 0x80040000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2439) {
  int f = 1040187392;

  my_decimal decimal_check = {{0x7D, 0x0, 0x0, 0x30000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2440) {
  int f = -1107296256;

  my_decimal decimal_check = {{0x7D, 0x0, 0x0, 0x80030000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2441) {
  int f = 1031798784;

  my_decimal decimal_check = {{0x271, 0x0, 0x0, 0x40000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2442) {
  int f = -1115684864;

  my_decimal decimal_check = {{0x271, 0x0, 0x0, 0x80040000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2443) {
  int f = 1015021568;

  my_decimal decimal_check = {{0x3D09, 0x0, 0x0, 0x60000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2444) {
  int f = -1132462080;

  my_decimal decimal_check = {{0x3D09, 0x0, 0x0, 0x80060000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2445) {
  int f = 1010827264;

  my_decimal decimal_check = {{0x11E1A3, 0x0, 0x0, 0x80000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2446) {
  int f = -1136656384;

  my_decimal decimal_check = {{0x11E1A3, 0x0, 0x0, 0x80080000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2447) {
  int f = 1006632960;

  my_decimal decimal_check = {{0x1312D, 0x0, 0x0, 0x70000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2448) {
  int f = -1140850688;

  my_decimal decimal_check = {{0x1312D, 0x0, 0x0, 0x80070000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2449) {
  int f = 998244352;

  my_decimal decimal_check = {{0x5F5E1, 0x0, 0x0, 0x80000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2450) {
  int f = -1149239296;

  my_decimal decimal_check = {{0x5F5E1, 0x0, 0x0, 0x80080000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2451) {
  int f = 964689920;

  my_decimal decimal_check = {{0x2540BE, 0x0, 0x0, 0xA0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2452) {
  int f = -1182793728;

  my_decimal decimal_check = {{0x2540BE, 0x0, 0x0, 0x800A0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2453) {
  int f = 943718400;

  my_decimal decimal_check = {{0x45D965, 0x0, 0x0, 0xB0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2454) {
  int f = -1203765248;

  my_decimal decimal_check = {{0x45D965, 0x0, 0x0, 0x800B0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2455) {
  int f = 939524096;

  my_decimal decimal_check = {{0x2E90EE, 0x0, 0x0, 0xB0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2456) {
  int f = -1207959552;

  my_decimal decimal_check = {{0x2E90EE, 0x0, 0x0, 0x800B0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2457) {
  int f = 931135488;

  my_decimal decimal_check = {{0x174877, 0x0, 0x0, 0xB0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2458) {
  int f = -1216348160;

  my_decimal decimal_check = {{0x174877, 0x0, 0x0, 0x800B0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2459) {
  int f = 805306368;

  my_decimal decimal_check = {{0x470DE5, 0x0, 0x0, 0x100000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2460) {
  int f = -1342177280;

  my_decimal decimal_check = {{0x470DE5, 0x0, 0x0, 0x80100000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2461) {
  int f = 809500672;

  my_decimal decimal_check = {{0x6A94D7, 0x0, 0x0, 0x100000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2462) {
  int f = -1337982976;

  my_decimal decimal_check = {{0x6A94D7, 0x0, 0x0, 0x80100000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2463) {
  int f = 536870912;

  my_decimal decimal_check = {{0x108B2A, 0x0, 0x0, 0x190000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2464) {
  int f = -1610612736;

  my_decimal decimal_check = {{0x108B2A, 0x0, 0x0, 0x80190000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2465) {
  int f = 1036831949;

  my_decimal decimal_check = {{0x1, 0x0, 0x0, 0x10000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2466) {
  int f = -1110651699;

  my_decimal decimal_check = {{0x1, 0x0, 0x0, 0x80010000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2467) {
  int f = 1065336439;

  my_decimal decimal_check = {{0x3E7, 0x0, 0x0, 0x30000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2468) {
  int f = -1082147209;

  my_decimal decimal_check = {{0x3E7, 0x0, 0x0, 0x80030000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2469) {
  int f = 1063675494;

  my_decimal decimal_check = {{0x9, 0x0, 0x0, 0x10000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2470) {
  int f = -1083808154;

  my_decimal decimal_check = {{0x9, 0x0, 0x0, 0x80010000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2471) {
  int f = 1036818527;

  my_decimal decimal_check = {{0x3E7, 0x0, 0x0, 0x40000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2472) {
  int f = -1110665121;

  my_decimal decimal_check = {{0x3E7, 0x0, 0x0, 0x80040000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2473) {
  int f = 1008971033;

  my_decimal decimal_check = {{0x3E7, 0x0, 0x0, 0x50000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2474) {
  int f = -1138512615;

  my_decimal decimal_check = {{0x3E7, 0x0, 0x0, 0x80050000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2475) {
  int f = 981659873;

  my_decimal decimal_check = {{0x3E7, 0x0, 0x0, 0x60000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2476) {
  int f = -1165823775;

  my_decimal decimal_check = {{0x3E7, 0x0, 0x0, 0x80060000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2477) {
  int f = 953254247;

  my_decimal decimal_check = {{0x3E7, 0x0, 0x0, 0x70000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2478) {
  int f = -1194229401;

  my_decimal decimal_check = {{0x3E7, 0x0, 0x0, 0x80070000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2479) {
  int f = 925342393;

  my_decimal decimal_check = {{0x3E7, 0x0, 0x0, 0x80000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2480) {
  int f = -1222141255;

  my_decimal decimal_check = {{0x3E7, 0x0, 0x0, 0x80080000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2481) {
  int f = 897979745;

  my_decimal decimal_check = {{0x3E7, 0x0, 0x0, 0x90000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2482) {
  int f = -1249503903;

  my_decimal decimal_check = {{0x3E7, 0x0, 0x0, 0x80090000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2483) {
  int f = 869697691;

  my_decimal decimal_check = {{0x3E7, 0x0, 0x0, 0xA0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2484) {
  int f = -1277785957;

  my_decimal decimal_check = {{0x3E7, 0x0, 0x0, 0x800A0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2485) {
  int f = 841719932;

  my_decimal decimal_check = {{0x3E7, 0x0, 0x0, 0xB0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2486) {
  int f = -1305763716;

  my_decimal decimal_check = {{0x3E7, 0x0, 0x0, 0x800B0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2487) {
  int f = 814304560;

  my_decimal decimal_check = {{0x3E7, 0x0, 0x0, 0xC0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2488) {
  int f = -1333179088;

  my_decimal decimal_check = {{0x3E7, 0x0, 0x0, 0x800C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2489) {
  int f = 786149043;

  my_decimal decimal_check = {{0x3E7, 0x0, 0x0, 0xD0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2490) {
  int f = -1361334605;

  my_decimal decimal_check = {{0x3E7, 0x0, 0x0, 0x800D0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2491) {
  int f = 758103798;

  my_decimal decimal_check = {{0x3E7, 0x0, 0x0, 0xE0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2492) {
  int f = -1389379850;

  my_decimal decimal_check = {{0x3E7, 0x0, 0x0, 0x800E0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2493) {
  int f = 730634437;

  my_decimal decimal_check = {{0x3E7, 0x0, 0x0, 0xF0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2494) {
  int f = -1416849211;

  my_decimal decimal_check = {{0x3E7, 0x0, 0x0, 0x800F0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2495) {
  int f = 702608494;

  my_decimal decimal_check = {{0x3E7, 0x0, 0x0, 0x100000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2496) {
  int f = -1444875154;

  my_decimal decimal_check = {{0x3E7, 0x0, 0x0, 0x80100000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2497) {
  int f = 673506516;

  my_decimal decimal_check = {{0x8BABA8, 0x0, 0x0, 0x150000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2498) {
  int f = -1473977132;

  my_decimal decimal_check = {{0x8BABA8, 0x0, 0x0, 0x80150000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2499) {
  int f = 621083593;

  my_decimal decimal_check = {{0x1199A8, 0x0, 0x0, 0x160000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2500) {
  int f = -1526400055;

  my_decimal decimal_check = {{0x1199A8, 0x0, 0x0, 0x80160000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2501) {
  int f = 592758286;

  my_decimal decimal_check = {{0x1199A8, 0x0, 0x0, 0x170000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2502) {
  int f = -1554725362;

  my_decimal decimal_check = {{0x1199A8, 0x0, 0x0, 0x80170000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2503) {
  int f = 564803595;

  my_decimal decimal_check = {{0x1199A8, 0x0, 0x0, 0x180000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2504) {
  int f = -1582680053;

  my_decimal decimal_check = {{0x1199A8, 0x0, 0x0, 0x80180000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2505) {
  int f = 541065216;

  my_decimal decimal_check = {{0x18D0BF, 0x0, 0x0, 0x190000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2506) {
  int f = -1606418432;

  my_decimal decimal_check = {{0x18D0BF, 0x0, 0x0, 0x80190000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2507) {
  int f = 537406678;

  my_decimal decimal_check = {{0x1199A8, 0x0, 0x0, 0x190000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2508) {
  int f = -1610076970;

  my_decimal decimal_check = {{0x1199A8, 0x0, 0x0, 0x80190000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2509) {
  int f = 509206870;

  my_decimal decimal_check = {{0x1199A8, 0x0, 0x0, 0x1A0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2510) {
  int f = -1638276778;

  my_decimal decimal_check = {{0x1199A8, 0x0, 0x0, 0x801A0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2511) {
  int f = 503783412;

  my_decimal decimal_check = {{0x6D2728, 0x0, 0x0, 0x1B0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2512) {
  int f = -1643700236;

  my_decimal decimal_check = {{0x6D2728, 0x0, 0x0, 0x801B0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2513) {
  int f = 503783411;

  my_decimal decimal_check = {{0x6D2727, 0x0, 0x0, 0x1B0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2514) {
  int f = -1643700237;

  my_decimal decimal_check = {{0x6D2727, 0x0, 0x0, 0x801B0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2515) {
  int f = 476297005;

  my_decimal decimal_check = {{0x72F78B, 0x0, 0x0, 0x1C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2516) {
  int f = -1671186643;

  my_decimal decimal_check = {{0x72F78B, 0x0, 0x0, 0x801C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2517) {
  int f = 476297004;

  my_decimal decimal_check = {{0x72F78A, 0x0, 0x0, 0x1C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2518) {
  int f = -1671186644;

  my_decimal decimal_check = {{0x72F78A, 0x0, 0x0, 0x801C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2519) {
  int f = 448162742;

  my_decimal decimal_check = {{0xB832B, 0x0, 0x0, 0x1C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2520) {
  int f = -1699320906;

  my_decimal decimal_check = {{0xB832B, 0x0, 0x0, 0x801C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2521) {
  int f = 448162741;

  my_decimal decimal_check = {{0xB832A, 0x0, 0x0, 0x1C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2522) {
  int f = -1699320907;

  my_decimal decimal_check = {{0xB832A, 0x0, 0x0, 0x801C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2523) {
  int f = 423141201;

  my_decimal decimal_check = {{0x174D8, 0x0, 0x0, 0x1C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2524) {
  int f = -1724342447;

  my_decimal decimal_check = {{0x174D8, 0x0, 0x0, 0x801C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2525) {
  int f = 423141200;

  my_decimal decimal_check = {{0x174D7, 0x0, 0x0, 0x1C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2526) {
  int f = -1724342448;

  my_decimal decimal_check = {{0x174D7, 0x0, 0x0, 0x801C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2527) {
  int f = 361156554;

  my_decimal decimal_check = {{0x221, 0x0, 0x0, 0x1C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2528) {
  int f = -1786327094;

  my_decimal decimal_check = {{0x221, 0x0, 0x0, 0x801C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2529) {
  int f = 361156553;

  my_decimal decimal_check = {{0x220, 0x0, 0x0, 0x1C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2530) {
  int f = -1786327095;

  my_decimal decimal_check = {{0x220, 0x0, 0x0, 0x801C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2531) {
  int f = 344922907;

  my_decimal decimal_check = {{0x91, 0x0, 0x0, 0x1C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2532) {
  int f = -1802560741;

  my_decimal decimal_check = {{0x91, 0x0, 0x0, 0x801C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2533) {
  int f = 344922906;

  my_decimal decimal_check = {{0x90, 0x0, 0x0, 0x1C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2534) {
  int f = -1802560742;

  my_decimal decimal_check = {{0x90, 0x0, 0x0, 0x801C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2535) {
  int f = 317566779;

  my_decimal decimal_check = {{0xF, 0x0, 0x0, 0x1C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2536) {
  int f = -1829916869;

  my_decimal decimal_check = {{0xF, 0x0, 0x0, 0x801C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2537) {
  int f = 317566778;

  my_decimal decimal_check = {{0xF, 0x0, 0x0, 0x1C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2538) {
  int f = -1829916870;

  my_decimal decimal_check = {{0xF, 0x0, 0x0, 0x801C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2539) {
  int f = 317047549;

  my_decimal decimal_check = {{0xF, 0x0, 0x0, 0x1C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2540) {
  int f = -1830436099;

  my_decimal decimal_check = {{0xF, 0x0, 0x0, 0x801C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2541) {
  int f = 317047548;

  my_decimal decimal_check = {{0xE, 0x0, 0x0, 0x1C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2542) {
  int f = -1830436100;

  my_decimal decimal_check = {{0xE, 0x0, 0x0, 0x801C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2543) {
  int f = 314451401;

  my_decimal decimal_check = {{0xC, 0x0, 0x0, 0x1C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2544) {
  int f = -1833032247;

  my_decimal decimal_check = {{0xC, 0x0, 0x0, 0x801C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2545) {
  int f = 314451400;

  my_decimal decimal_check = {{0xC, 0x0, 0x0, 0x1C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2546) {
  int f = -1833032248;

  my_decimal decimal_check = {{0xC, 0x0, 0x0, 0x801C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2547) {
  int f = 313932171;

  my_decimal decimal_check = {{0xC, 0x0, 0x0, 0x1C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2548) {
  int f = -1833551477;

  my_decimal decimal_check = {{0xC, 0x0, 0x0, 0x801C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2549) {
  int f = 313932170;

  my_decimal decimal_check = {{0xB, 0x0, 0x0, 0x1C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2550) {
  int f = -1833551478;

  my_decimal decimal_check = {{0xB, 0x0, 0x0, 0x801C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2551) {
  int f = 313412942;

  my_decimal decimal_check = {{0xB, 0x0, 0x0, 0x1C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2552) {
  int f = -1834070706;

  my_decimal decimal_check = {{0xB, 0x0, 0x0, 0x801C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2553) {
  int f = 313412941;

  my_decimal decimal_check = {{0xB, 0x0, 0x0, 0x1C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2554) {
  int f = -1834070707;

  my_decimal decimal_check = {{0xB, 0x0, 0x0, 0x801C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2555) {
  int f = 312893712;

  my_decimal decimal_check = {{0xB, 0x0, 0x0, 0x1C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2556) {
  int f = -1834589936;

  my_decimal decimal_check = {{0xB, 0x0, 0x0, 0x801C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2557) {
  int f = 312893711;

  my_decimal decimal_check = {{0x1, 0x0, 0x0, 0x1B0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2558) {
  int f = -1834589937;

  my_decimal decimal_check = {{0x1, 0x0, 0x0, 0x801B0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2559) {
  int f = 312374482;

  my_decimal decimal_check = {{0x1, 0x0, 0x0, 0x1B0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2560) {
  int f = -1835109166;

  my_decimal decimal_check = {{0x1, 0x0, 0x0, 0x801B0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2561) {
  int f = 312374481;

  my_decimal decimal_check = {{0x1, 0x0, 0x0, 0x1B0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2562) {
  int f = -1835109167;

  my_decimal decimal_check = {{0x1, 0x0, 0x0, 0x801B0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2563) {
  int f = 311855253;

  my_decimal decimal_check = {{0x1, 0x0, 0x0, 0x1B0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2564) {
  int f = -1835628395;

  my_decimal decimal_check = {{0x1, 0x0, 0x0, 0x801B0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2565) {
  int f = 311855252;

  my_decimal decimal_check = {{0x9, 0x0, 0x0, 0x1C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2566) {
  int f = -1835628396;

  my_decimal decimal_check = {{0x9, 0x0, 0x0, 0x801C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2567) {
  int f = 311336023;

  my_decimal decimal_check = {{0x9, 0x0, 0x0, 0x1C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2568) {
  int f = -1836147625;

  my_decimal decimal_check = {{0x9, 0x0, 0x0, 0x801C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2569) {
  int f = 311336022;

  my_decimal decimal_check = {{0x9, 0x0, 0x0, 0x1C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2570) {
  int f = -1836147626;

  my_decimal decimal_check = {{0x9, 0x0, 0x0, 0x801C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2571) {
  int f = 310816793;

  my_decimal decimal_check = {{0x9, 0x0, 0x0, 0x1C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2572) {
  int f = -1836666855;

  my_decimal decimal_check = {{0x9, 0x0, 0x0, 0x801C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2573) {
  int f = 310816792;

  my_decimal decimal_check = {{0x8, 0x0, 0x0, 0x1C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2574) {
  int f = -1836666856;

  my_decimal decimal_check = {{0x8, 0x0, 0x0, 0x801C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2575) {
  int f = 310216630;

  my_decimal decimal_check = {{0x8, 0x0, 0x0, 0x1C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2576) {
  int f = -1837267018;

  my_decimal decimal_check = {{0x8, 0x0, 0x0, 0x801C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2577) {
  int f = 310216629;

  my_decimal decimal_check = {{0x8, 0x0, 0x0, 0x1C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2578) {
  int f = -1837267019;

  my_decimal decimal_check = {{0x8, 0x0, 0x0, 0x801C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2579) {
  int f = 309178171;

  my_decimal decimal_check = {{0x8, 0x0, 0x0, 0x1C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2580) {
  int f = -1838305477;

  my_decimal decimal_check = {{0x8, 0x0, 0x0, 0x801C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2581) {
  int f = 309178170;

  my_decimal decimal_check = {{0x7, 0x0, 0x0, 0x1C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2582) {
  int f = -1838305478;

  my_decimal decimal_check = {{0x7, 0x0, 0x0, 0x801C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2583) {
  int f = 308139712;

  my_decimal decimal_check = {{0x7, 0x0, 0x0, 0x1C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2584) {
  int f = -1839343936;

  my_decimal decimal_check = {{0x7, 0x0, 0x0, 0x801C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2585) {
  int f = 308139711;

  my_decimal decimal_check = {{0x7, 0x0, 0x0, 0x1C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2586) {
  int f = -1839343937;

  my_decimal decimal_check = {{0x7, 0x0, 0x0, 0x801C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2587) {
  int f = 307101252;

  my_decimal decimal_check = {{0x7, 0x0, 0x0, 0x1C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2588) {
  int f = -1840382396;

  my_decimal decimal_check = {{0x7, 0x0, 0x0, 0x801C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2589) {
  int f = 307101251;

  my_decimal decimal_check = {{0x6, 0x0, 0x0, 0x1C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2590) {
  int f = -1840382397;

  my_decimal decimal_check = {{0x6, 0x0, 0x0, 0x801C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2591) {
  int f = 306062793;

  my_decimal decimal_check = {{0x6, 0x0, 0x0, 0x1C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2592) {
  int f = -1841420855;

  my_decimal decimal_check = {{0x6, 0x0, 0x0, 0x801C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2593) {
  int f = 306062792;

  my_decimal decimal_check = {{0x6, 0x0, 0x0, 0x1C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2594) {
  int f = -1841420856;

  my_decimal decimal_check = {{0x6, 0x0, 0x0, 0x801C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2595) {
  int f = 305024334;

  my_decimal decimal_check = {{0x6, 0x0, 0x0, 0x1C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2596) {
  int f = -1842459314;

  my_decimal decimal_check = {{0x6, 0x0, 0x0, 0x801C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2597) {
  int f = 305024333;

  my_decimal decimal_check = {{0x5, 0x0, 0x0, 0x1C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2598) {
  int f = -1842459315;

  my_decimal decimal_check = {{0x5, 0x0, 0x0, 0x801C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2599) {
  int f = 303985874;

  my_decimal decimal_check = {{0x5, 0x0, 0x0, 0x1C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2600) {
  int f = -1843497774;

  my_decimal decimal_check = {{0x5, 0x0, 0x0, 0x801C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2601) {
  int f = 303985873;

  my_decimal decimal_check = {{0x5, 0x0, 0x0, 0x1C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2602) {
  int f = -1843497775;

  my_decimal decimal_check = {{0x5, 0x0, 0x0, 0x801C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2603) {
  int f = 302947415;

  my_decimal decimal_check = {{0x5, 0x0, 0x0, 0x1C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2604) {
  int f = -1844536233;

  my_decimal decimal_check = {{0x5, 0x0, 0x0, 0x801C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2605) {
  int f = 302947414;

  my_decimal decimal_check = {{0x4, 0x0, 0x0, 0x1C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2606) {
  int f = -1844536234;

  my_decimal decimal_check = {{0x4, 0x0, 0x0, 0x801C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2607) {
  int f = 301828022;

  my_decimal decimal_check = {{0x4, 0x0, 0x0, 0x1C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2608) {
  int f = -1845655626;

  my_decimal decimal_check = {{0x4, 0x0, 0x0, 0x801C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2609) {
  int f = 301828021;

  my_decimal decimal_check = {{0x4, 0x0, 0x0, 0x1C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2610) {
  int f = -1845655627;

  my_decimal decimal_check = {{0x4, 0x0, 0x0, 0x801C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2611) {
  int f = 299751105;

  my_decimal decimal_check = {{0x4, 0x0, 0x0, 0x1C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2612) {
  int f = -1847732543;

  my_decimal decimal_check = {{0x4, 0x0, 0x0, 0x801C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2613) {
  int f = 299751104;

  my_decimal decimal_check = {{0x4, 0x0, 0x0, 0x1C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2614) {
  int f = -1847732544;

  my_decimal decimal_check = {{0x4, 0x0, 0x0, 0x801C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2615) {
  int f = 299751103;

  my_decimal decimal_check = {{0x3, 0x0, 0x0, 0x1C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2616) {
  int f = -1847732545;

  my_decimal decimal_check = {{0x3, 0x0, 0x0, 0x801C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2617) {
  int f = 299751102;

  my_decimal decimal_check = {{0x3, 0x0, 0x0, 0x1C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2618) {
  int f = -1847732546;

  my_decimal decimal_check = {{0x3, 0x0, 0x0, 0x801C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2619) {
  int f = 297674185;

  my_decimal decimal_check = {{0x3, 0x0, 0x0, 0x1C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2620) {
  int f = -1849809463;

  my_decimal decimal_check = {{0x3, 0x0, 0x0, 0x801C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2621) {
  int f = 297674184;

  my_decimal decimal_check = {{0x3, 0x0, 0x0, 0x1C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2622) {
  int f = -1849809464;

  my_decimal decimal_check = {{0x3, 0x0, 0x0, 0x801C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2623) {
  int f = 297674183;

  my_decimal decimal_check = {{0x3, 0x0, 0x0, 0x1C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2624) {
  int f = -1849809465;

  my_decimal decimal_check = {{0x3, 0x0, 0x0, 0x801C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2625) {
  int f = 295597267;

  my_decimal decimal_check = {{0x3, 0x0, 0x0, 0x1C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2626) {
  int f = -1851886381;

  my_decimal decimal_check = {{0x3, 0x0, 0x0, 0x801C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2627) {
  int f = 295597266;

  my_decimal decimal_check = {{0x3, 0x0, 0x0, 0x1C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2628) {
  int f = -1851886382;

  my_decimal decimal_check = {{0x3, 0x0, 0x0, 0x801C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2629) {
  int f = 295597265;

  my_decimal decimal_check = {{0x2, 0x0, 0x0, 0x1C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2630) {
  int f = -1851886383;

  my_decimal decimal_check = {{0x2, 0x0, 0x0, 0x801C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2631) {
  int f = 293439415;

  my_decimal decimal_check = {{0x2, 0x0, 0x0, 0x1C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2632) {
  int f = -1854044233;

  my_decimal decimal_check = {{0x2, 0x0, 0x0, 0x801C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2633) {
  int f = 293439414;

  my_decimal decimal_check = {{0x2, 0x0, 0x0, 0x1C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2634) {
  int f = -1854044234;

  my_decimal decimal_check = {{0x2, 0x0, 0x0, 0x801C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2635) {
  int f = 293439413;

  my_decimal decimal_check = {{0x2, 0x0, 0x0, 0x1C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2636) {
  int f = -1854044235;

  my_decimal decimal_check = {{0x2, 0x0, 0x0, 0x801C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2637) {
  int f = 289285578;

  my_decimal decimal_check = {{0x2, 0x0, 0x0, 0x1C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2638) {
  int f = -1858198070;

  my_decimal decimal_check = {{0x2, 0x0, 0x0, 0x801C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2639) {
  int f = 289285577;

  my_decimal decimal_check = {{0x2, 0x0, 0x0, 0x1C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2640) {
  int f = -1858198071;

  my_decimal decimal_check = {{0x2, 0x0, 0x0, 0x801C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2641) {
  int f = 289285576;

  my_decimal decimal_check = {{0x1, 0x0, 0x0, 0x1C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2642) {
  int f = -1858198072;

  my_decimal decimal_check = {{0x1, 0x0, 0x0, 0x801C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2643) {
  int f = 289285561;

  my_decimal decimal_check = {{0x1, 0x0, 0x0, 0x1C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2644) {
  int f = -1858198087;

  my_decimal decimal_check = {{0x1, 0x0, 0x0, 0x801C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2645) {
  int f = 285050809;

  my_decimal decimal_check = {{0x1, 0x0, 0x0, 0x1C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2646) {
  int f = -1862432839;

  my_decimal decimal_check = {{0x1, 0x0, 0x0, 0x801C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2647) {
  int f = 285050808;

  my_decimal decimal_check = {{0x1, 0x0, 0x0, 0x1C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2648) {
  int f = -1862432840;

  my_decimal decimal_check = {{0x1, 0x0, 0x0, 0x801C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2649) {
  int f = 285050807;

  my_decimal decimal_check = {{0x1, 0x0, 0x0, 0x1C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2650) {
  int f = -1862432841;

  my_decimal decimal_check = {{0x1, 0x0, 0x0, 0x801C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2651) {
  int f = 285050806;

  my_decimal decimal_check = {{0x1, 0x0, 0x0, 0x1C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2652) {
  int f = -1862432842;

  my_decimal decimal_check = {{0x1, 0x0, 0x0, 0x801C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2653) {
  int f = 1259902597;

  my_decimal decimal_check = {{0x989680, 0x0, 0x0, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2654) {
  int f = -887581051;

  my_decimal decimal_check = {{0x989680, 0x0, 0x0, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2655) {
  int f = 1259902594;

  my_decimal decimal_check = {{0x989680, 0x0, 0x0, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2656) {
  int f = -887581054;

  my_decimal decimal_check = {{0x989680, 0x0, 0x0, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2657) {
  int f = 1259902593;

  my_decimal decimal_check = {{0x989680, 0x0, 0x0, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2658) {
  int f = -887581055;

  my_decimal decimal_check = {{0x989680, 0x0, 0x0, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2659) {
  int f = 1259902592;

  my_decimal decimal_check = {{0x989680, 0x0, 0x0, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2660) {
  int f = -887581056;

  my_decimal decimal_check = {{0x989680, 0x0, 0x0, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2661) {
  int f = 1259902591;

  my_decimal decimal_check = {{0x98967F, 0x0, 0x0, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2662) {
  int f = -887581057;

  my_decimal decimal_check = {{0x98967F, 0x0, 0x0, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2663) {
  int f = 1259902590;

  my_decimal decimal_check = {{0x98967E, 0x0, 0x0, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2664) {
  int f = -887581058;

  my_decimal decimal_check = {{0x98967E, 0x0, 0x0, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2665) {
  int f = 1232348185;

  my_decimal decimal_check = {{0xF4242, 0x0, 0x0, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2666) {
  int f = -915135463;

  my_decimal decimal_check = {{0xF4242, 0x0, 0x0, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2667) {
  int f = 1232348184;

  my_decimal decimal_check = {{0xF4242, 0x0, 0x0, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2668) {
  int f = -915135464;

  my_decimal decimal_check = {{0xF4242, 0x0, 0x0, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2669) {
  int f = 1232348183;

  my_decimal decimal_check = {{0xF4241, 0x0, 0x0, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2670) {
  int f = -915135465;

  my_decimal decimal_check = {{0xF4241, 0x0, 0x0, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2671) {
  int f = 1232348169;

  my_decimal decimal_check = {{0xF4241, 0x0, 0x0, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2672) {
  int f = -915135479;

  my_decimal decimal_check = {{0xF4241, 0x0, 0x0, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2673) {
  int f = 1232348168;

  my_decimal decimal_check = {{0xF4240, 0x0, 0x0, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2674) {
  int f = -915135480;

  my_decimal decimal_check = {{0xF4240, 0x0, 0x0, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2675) {
  int f = 1232348167;

  my_decimal decimal_check = {{0xF4240, 0x0, 0x0, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2676) {
  int f = -915135481;

  my_decimal decimal_check = {{0xF4240, 0x0, 0x0, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2677) {
  int f = 1232348161;

  my_decimal decimal_check = {{0xF4240, 0x0, 0x0, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2678) {
  int f = -915135487;

  my_decimal decimal_check = {{0xF4240, 0x0, 0x0, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2679) {
  int f = 1232348160;

  my_decimal decimal_check = {{0xF4240, 0x0, 0x0, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2680) {
  int f = -915135488;

  my_decimal decimal_check = {{0xF4240, 0x0, 0x0, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2681) {
  int f = 1232348159;

  my_decimal decimal_check = {{0x98967F, 0x0, 0x0, 0x10000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2682) {
  int f = -915135489;

  my_decimal decimal_check = {{0x98967F, 0x0, 0x0, 0x80010000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2683) {
  int f = 1232348152;

  my_decimal decimal_check = {{0x98967B, 0x0, 0x0, 0x10000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2684) {
  int f = -915135496;

  my_decimal decimal_check = {{0x98967B, 0x0, 0x0, 0x80010000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2685) {
  int f = 1232348151;

  my_decimal decimal_check = {{0x98967A, 0x0, 0x0, 0x10000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2686) {
  int f = -915135497;

  my_decimal decimal_check = {{0x98967A, 0x0, 0x0, 0x80010000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2687) {
  int f = 1232348137;

  my_decimal decimal_check = {{0x989672, 0x0, 0x0, 0x10000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2688) {
  int f = -915135511;

  my_decimal decimal_check = {{0x989672, 0x0, 0x0, 0x80010000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2689) {
  int f = 1232348136;

  my_decimal decimal_check = {{0x989671, 0x0, 0x0, 0x10000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2690) {
  int f = -915135512;

  my_decimal decimal_check = {{0x989671, 0x0, 0x0, 0x80010000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2691) {
  int f = 1232348135;

  my_decimal decimal_check = {{0x989670, 0x0, 0x0, 0x10000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2692) {
  int f = -915135513;

  my_decimal decimal_check = {{0x989670, 0x0, 0x0, 0x80010000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2693) {
  int f = 490896311;

  my_decimal decimal_check = {{0x27468D, 0x0, 0x0, 0x1B0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2694) {
  int f = -1656587337;

  my_decimal decimal_check = {{0x27468D, 0x0, 0x0, 0x801B0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2695) {
  int f = 490896311;

  my_decimal decimal_check = {{0x27468D, 0x0, 0x0, 0x1B0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2696) {
  int f = -1656587337;

  my_decimal decimal_check = {{0x27468D, 0x0, 0x0, 0x801B0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2697) {
  int f = 1076149206;

  my_decimal decimal_check = {{0x27468D, 0x0, 0x0, 0x60000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2698) {
  int f = -1071334442;

  my_decimal decimal_check = {{0x27468D, 0x0, 0x0, 0x80060000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2699) {
  int f = 989855744;

  my_decimal decimal_check = {{0x1DCD65, 0x0, 0x0, 0x90000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2700) {
  int f = -1157627904;

  my_decimal decimal_check = {{0x1DCD65, 0x0, 0x0, 0x80090000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2701) {
  int f = 1265458147;

  my_decimal decimal_check = {{0xED5BE8, 0x0, 0x0, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2702) {
  int f = -882025501;

  my_decimal decimal_check = {{0xED5BE8, 0x0, 0x0, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2703) {
  int f = 1265458157;

  my_decimal decimal_check = {{0xED5BE8, 0x0, 0x0, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2704) {
  int f = -882025491;

  my_decimal decimal_check = {{0xED5BE8, 0x0, 0x0, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2705) {
  int f = 1248730914;

  my_decimal decimal_check = {{0x3B87C8, 0x0, 0x0, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2706) {
  int f = -898752734;

  my_decimal decimal_check = {{0x3B87C8, 0x0, 0x0, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2707) {
  int f = 1248730918;

  my_decimal decimal_check = {{0x3B87CA, 0x0, 0x0, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2708) {
  int f = -898752730;

  my_decimal decimal_check = {{0x3B87CA, 0x0, 0x0, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2709) {
  int f = 1061868279;

  my_decimal decimal_check = {{0x78E480, 0x0, 0x0, 0x70000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2710) {
  int f = -1085615369;

  my_decimal decimal_check = {{0x78E480, 0x0, 0x0, 0x80070000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2711) {
  int f = 1061868280;

  my_decimal decimal_check = {{0x78E480, 0x0, 0x0, 0x70000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2712) {
  int f = -1085615368;

  my_decimal decimal_check = {{0x78E480, 0x0, 0x0, 0x80070000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2713) {
  int f = 1061868281;

  my_decimal decimal_check = {{0x78E481, 0x0, 0x0, 0x70000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2714) {
  int f = -1085615367;

  my_decimal decimal_check = {{0x78E481, 0x0, 0x0, 0x80070000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2715) {
  int f = 1090357173;

  my_decimal decimal_check = {{0x78E480, 0x0, 0x0, 0x60000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2716) {
  int f = -1057126475;

  my_decimal decimal_check = {{0x78E480, 0x0, 0x0, 0x80060000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2717) {
  int f = 1090357174;

  my_decimal decimal_check = {{0x78E480, 0x0, 0x0, 0x60000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2718) {
  int f = -1057126474;

  my_decimal decimal_check = {{0x78E480, 0x0, 0x0, 0x80060000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2719) {
  int f = 1090357175;

  my_decimal decimal_check = {{0x78E481, 0x0, 0x0, 0x60000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2720) {
  int f = -1057126473;

  my_decimal decimal_check = {{0x78E481, 0x0, 0x0, 0x80060000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2721) {
  int f = 973078528;

  my_decimal decimal_check = {{0x4A817C, 0x0, 0x0, 0xA0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2722) {
  int f = -1174405120;

  my_decimal decimal_check = {{0x4A817C, 0x0, 0x0, 0x800A0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2723) {
  int f = 445010747;

  my_decimal decimal_check = {{0x87A24, 0x0, 0x0, 0x1C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2724) {
  int f = -1702472901;

  my_decimal decimal_check = {{0x87A24, 0x0, 0x0, 0x801C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2725) {
  int f = 472377354;

  my_decimal decimal_check = {{0x54C565, 0x0, 0x0, 0x1C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2726) {
  int f = -1675106294;

  my_decimal decimal_check = {{0x54C565, 0x0, 0x0, 0x801C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2727) {
  int f = 416738194;

  my_decimal decimal_check = {{0xD904, 0x0, 0x0, 0x1C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2728) {
  int f = -1730745454;

  my_decimal decimal_check = {{0xD904, 0x0, 0x0, 0x801C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2729) {
  int f = 388755368;

  my_decimal decimal_check = {{0x15B4, 0x0, 0x0, 0x1C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2730) {
  int f = -1758728280;

  my_decimal decimal_check = {{0x15B4, 0x0, 0x0, 0x801C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2731) {
  int f = 361335942;

  my_decimal decimal_check = {{0x22C, 0x0, 0x0, 0x1C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2732) {
  int f = -1786147706;

  my_decimal decimal_check = {{0x22C, 0x0, 0x0, 0x801C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2733) {
  int f = 333190154;

  my_decimal decimal_check = {{0x38, 0x0, 0x0, 0x1C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2734) {
  int f = -1814293494;

  my_decimal decimal_check = {{0x38, 0x0, 0x0, 0x801C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2735) {
  int f = 305139720;

  my_decimal decimal_check = {{0x6, 0x0, 0x0, 0x1C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2736) {
  int f = -1842343928;

  my_decimal decimal_check = {{0x6, 0x0, 0x0, 0x801C0000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2737) {
  int f = 1022739087;

  my_decimal decimal_check = {{0x3, 0x0, 0x0, 0x20000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2738) {
  int f = -1124744561;

  my_decimal decimal_check = {{0x3, 0x0, 0x0, 0x80020000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2739) {
  int f = 1036831949;

  my_decimal decimal_check = {{0x1, 0x0, 0x0, 0x10000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2740) {
  int f = -1110651699;

  my_decimal decimal_check = {{0x1, 0x0, 0x0, 0x80010000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2741) {
  int f = 1063675494;

  my_decimal decimal_check = {{0x9, 0x0, 0x0, 0x10000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2742) {
  int f = -1083808154;

  my_decimal decimal_check = {{0x9, 0x0, 0x0, 0x80010000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2743) {
  int f = 1065353215;

  my_decimal decimal_check = {{0x98967F, 0x0, 0x0, 0x70000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2744) {
  int f = -1082130433;

  my_decimal decimal_check = {{0x98967F, 0x0, 0x0, 0x80070000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2745) {
  int f = 1065353216;

  my_decimal decimal_check = {{0x1, 0x0, 0x0, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2746) {
  int f = -1082130432;

  my_decimal decimal_check = {{0x1, 0x0, 0x0, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2747) {
  int f = 1065353217;

  my_decimal decimal_check = {{0x1, 0x0, 0x0, 0x0}};

  test_from_float_to_decimal(f, decimal_check);
}

START_TEST(test_from_float_to_decimal_ok2748) {
  int f = -1082130431;

  my_decimal decimal_check = {{0x1, 0x0, 0x0, 0x80000000}};

  test_from_float_to_decimal(f, decimal_check);
}

Suite *from_float_to_decimal_suite1(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("from_float_to_decimal_suite1");
  tc_core = tcase_create("Core");
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok3);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok4);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok5);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok6);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok7);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok8);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok9);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok10);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok11);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok12);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok13);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok14);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok15);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok16);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok17);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok18);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok19);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok20);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok21);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok22);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok23);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok24);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok25);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok26);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok27);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok28);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok29);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok30);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok31);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok32);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok33);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok34);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok35);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok36);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok37);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok38);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok39);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok40);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok41);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok42);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok43);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok44);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok45);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok46);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok47);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok48);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok49);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok50);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok51);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok52);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok53);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok54);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok55);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok56);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok57);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok58);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok59);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok60);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok61);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok62);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok63);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok64);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok65);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok66);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok67);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok68);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok69);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok70);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok71);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok72);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok73);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok74);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok75);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok76);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok77);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok78);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok79);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok80);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok81);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok82);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok83);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok84);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok85);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok86);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok87);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok88);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok89);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok90);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok91);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok92);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok93);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok94);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok95);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok96);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok97);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok98);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok99);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok100);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok101);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok102);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok103);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok104);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok105);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok106);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok107);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok108);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok109);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok110);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok111);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok112);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok113);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok114);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok115);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok116);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok117);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok118);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok119);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok120);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok121);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok122);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok123);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok124);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok125);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok126);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok127);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok128);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok129);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok130);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok131);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok132);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok133);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok134);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok135);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok136);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok137);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok138);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok139);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok140);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok141);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok142);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok143);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok144);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok145);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok146);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok147);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok148);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok149);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok150);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok151);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok152);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok153);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok154);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok155);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok156);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok157);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok158);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok159);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok160);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok161);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok162);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok163);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok164);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok165);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok166);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok167);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok168);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok169);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok170);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok171);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok172);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok173);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok174);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok175);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok176);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok177);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok178);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok179);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok180);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok181);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok182);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok183);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok184);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok185);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok186);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok187);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok188);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok189);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok190);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok191);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok192);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok193);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok194);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok195);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok196);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok197);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok198);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok199);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok200);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok201);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok202);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok203);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok204);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok205);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok206);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok207);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok208);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok209);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok210);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok211);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok212);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok213);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok214);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok215);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok216);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok217);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok218);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok219);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok220);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok221);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok222);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok223);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok224);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok225);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok226);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok227);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok228);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok229);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok230);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok231);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok232);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok233);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok234);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok235);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok236);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok237);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok238);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok239);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok240);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok241);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok242);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok243);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok244);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok245);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok246);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok247);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok248);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok249);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok250);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok251);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok252);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok253);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok254);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok255);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok256);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok257);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok258);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok259);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok260);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok261);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok262);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok263);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok264);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok265);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok266);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok267);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok268);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok269);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok270);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok271);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok272);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok273);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok274);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok275);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok276);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok277);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok278);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok279);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok280);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok281);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok282);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok283);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok284);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok285);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok286);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok287);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok288);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok289);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok290);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok291);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok292);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok293);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok294);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok295);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok296);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok297);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok298);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok299);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok300);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok301);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok302);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok303);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok304);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok305);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok306);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok307);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok308);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok309);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok310);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok311);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok312);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok313);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok314);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok315);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok316);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok317);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok318);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok319);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok320);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok321);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok322);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok323);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok324);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok325);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok326);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok327);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok328);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok329);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok330);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok331);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok332);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok333);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok334);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok335);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok336);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok337);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok338);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok339);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok340);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok341);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok342);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok343);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok344);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok345);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok346);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok347);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok348);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok349);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok350);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok351);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok352);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok353);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok354);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok355);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok356);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok357);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok358);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok359);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok360);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok361);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok362);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok363);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok364);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok365);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok366);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok367);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok368);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok369);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok370);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok371);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok372);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok373);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok374);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok375);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok376);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok377);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok378);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok379);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok380);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok381);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok382);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok383);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok384);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok385);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok386);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok387);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok388);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok389);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok390);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok391);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok392);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok393);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok394);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok395);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok396);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok397);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok398);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok399);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok400);

  suite_add_tcase(s, tc_core);
  return s;
}

Suite *from_float_to_decimal_suite2(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("from_float_to_decimal_suite2");
  tc_core = tcase_create("Core");
  tcase_add_test(tc_core, test_from_float_to_decimal_ok401);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok402);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok403);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok404);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok405);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok406);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok407);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok408);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok409);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok410);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok411);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok412);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok413);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok414);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok415);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok416);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok417);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok418);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok419);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok420);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok421);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok422);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok423);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok424);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok425);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok426);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok427);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok428);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok429);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok430);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok431);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok432);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok433);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok434);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok435);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok436);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok437);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok438);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok439);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok440);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok441);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok442);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok443);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok444);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok445);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok446);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok447);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok448);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok449);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok450);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok451);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok452);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok453);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok454);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok455);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok456);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok457);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok458);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok459);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok460);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok461);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok462);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok463);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok464);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok465);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok466);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok467);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok468);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok469);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok470);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok471);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok472);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok473);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok474);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok475);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok476);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok477);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok478);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok479);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok480);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok481);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok482);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok483);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok484);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok485);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok486);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok487);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok488);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok489);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok490);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok491);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok492);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok493);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok494);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok495);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok496);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok497);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok498);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok499);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok500);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok501);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok502);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok503);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok504);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok505);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok506);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok507);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok508);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok509);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok510);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok511);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok512);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok513);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok514);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok515);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok516);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok517);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok518);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok519);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok520);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok521);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok522);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok523);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok524);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok525);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok526);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok527);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok528);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok529);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok530);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok531);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok532);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok533);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok534);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok535);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok536);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok537);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok538);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok539);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok540);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok541);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok542);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok543);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok544);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok545);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok546);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok547);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok548);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok549);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok550);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok551);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok552);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok553);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok554);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok555);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok556);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok557);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok558);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok559);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok560);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok561);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok562);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok563);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok564);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok565);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok566);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok567);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok568);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok569);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok570);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok571);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok572);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok573);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok574);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok575);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok576);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok577);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok578);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok579);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok580);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok581);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok582);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok583);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok584);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok585);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok586);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok587);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok588);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok589);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok590);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok591);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok592);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok593);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok594);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok595);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok596);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok597);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok598);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok599);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok600);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok601);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok602);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok603);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok604);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok605);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok606);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok607);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok608);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok609);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok610);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok611);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok612);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok613);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok614);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok615);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok616);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok617);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok618);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok619);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok620);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok621);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok622);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok623);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok624);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok625);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok626);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok627);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok628);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok629);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok630);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok631);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok632);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok633);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok634);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok635);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok636);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok637);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok638);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok639);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok640);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok641);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok642);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok643);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok644);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok645);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok646);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok647);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok648);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok649);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok650);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok651);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok652);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok653);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok654);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok655);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok656);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok657);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok658);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok659);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok660);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok661);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok662);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok663);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok664);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok665);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok666);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok667);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok668);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok669);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok670);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok671);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok672);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok673);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok674);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok675);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok676);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok677);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok678);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok679);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok680);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok681);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok682);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok683);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok684);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok685);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok686);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok687);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok688);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok689);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok690);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok691);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok692);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok693);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok694);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok695);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok696);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok697);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok698);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok699);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok700);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok701);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok702);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok703);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok704);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok705);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok706);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok707);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok708);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok709);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok710);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok711);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok712);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok713);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok714);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok715);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok716);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok717);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok718);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok719);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok720);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok721);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok722);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok723);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok724);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok725);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok726);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok727);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok728);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok729);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok730);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok731);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok732);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok733);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok734);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok735);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok736);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok737);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok738);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok739);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok740);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok741);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok742);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok743);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok744);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok745);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok746);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok747);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok748);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok749);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok750);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok751);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok752);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok753);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok754);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok755);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok756);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok757);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok758);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok759);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok760);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok761);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok762);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok763);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok764);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok765);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok766);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok767);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok768);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok769);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok770);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok771);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok772);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok773);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok774);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok775);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok776);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok777);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok778);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok779);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok780);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok781);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok782);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok783);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok784);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok785);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok786);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok787);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok788);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok789);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok790);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok791);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok792);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok793);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok794);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok795);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok796);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok797);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok798);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok799);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok800);

  suite_add_tcase(s, tc_core);
  return s;
}

Suite *from_float_to_decimal_suite3(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("from_float_to_decimal_suite3");
  tc_core = tcase_create("Core");
  tcase_add_test(tc_core, test_from_float_to_decimal_ok801);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok802);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok803);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok804);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok805);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok806);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok807);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok808);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok809);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok810);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok811);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok812);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok813);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok814);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok815);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok816);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok817);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok818);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok819);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok820);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok821);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok822);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok823);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok824);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok825);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok826);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok827);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok828);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok829);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok830);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok831);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok832);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok833);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok834);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok835);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok836);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok837);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok838);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok839);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok840);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok841);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok842);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok843);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok844);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok845);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok846);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok847);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok848);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok849);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok850);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok851);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok852);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok853);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok854);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok855);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok856);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok857);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok858);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok859);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok860);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok861);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok862);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok863);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok864);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok865);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok866);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok867);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok868);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok869);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok870);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok871);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok872);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok873);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok874);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok875);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok876);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok877);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok878);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok879);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok880);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok881);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok882);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok883);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok884);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok885);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok886);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok887);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok888);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok889);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok890);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok891);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok892);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok893);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok894);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok895);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok896);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok897);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok898);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok899);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok900);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok901);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok902);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok903);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok904);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok905);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok906);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok907);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok908);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok909);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok910);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok911);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok912);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok913);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok914);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok915);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok916);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok917);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok918);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok919);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok920);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok921);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok922);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok923);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok924);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok925);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok926);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok927);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok928);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok929);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok930);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok931);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok932);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok933);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok934);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok935);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok936);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok937);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok938);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok939);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok940);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok941);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok942);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok943);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok944);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok945);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok946);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok947);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok948);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok949);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok950);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok951);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok952);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok953);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok954);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok955);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok956);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok957);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok958);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok959);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok960);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok961);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok962);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok963);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok964);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok965);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok966);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok967);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok968);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok969);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok970);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok971);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok972);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok973);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok974);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok975);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok976);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok977);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok978);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok979);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok980);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok981);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok982);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok983);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok984);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok985);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok986);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok987);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok988);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok989);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok990);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok991);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok992);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok993);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok994);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok995);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok996);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok997);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok998);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok999);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1000);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1001);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1002);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1003);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1004);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1005);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1006);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1007);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1008);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1009);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1010);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1011);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1012);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1013);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1014);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1015);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1016);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1017);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1018);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1019);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1020);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1021);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1022);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1023);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1024);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1025);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1026);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1027);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1028);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1029);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1030);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1031);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1032);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1033);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1034);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1035);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1036);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1037);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1038);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1039);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1040);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1041);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1042);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1043);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1044);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1045);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1046);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1047);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1048);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1049);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1050);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1051);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1052);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1053);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1054);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1055);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1056);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1057);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1058);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1059);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1060);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1061);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1062);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1063);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1064);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1065);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1066);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1067);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1068);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1069);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1070);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1071);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1072);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1073);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1074);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1075);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1076);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1077);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1078);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1079);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1080);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1081);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1082);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1083);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1084);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1085);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1086);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1087);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1088);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1089);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1090);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1091);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1092);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1093);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1094);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1095);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1096);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1097);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1098);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1099);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1100);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1101);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1102);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1103);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1104);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1105);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1106);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1107);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1108);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1109);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1110);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1111);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1112);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1113);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1114);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1115);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1116);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1117);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1118);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1119);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1120);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1121);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1122);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1123);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1124);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1125);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1126);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1127);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1128);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1129);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1130);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1131);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1132);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1133);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1134);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1135);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1136);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1137);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1138);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1139);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1140);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1141);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1142);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1143);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1144);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1145);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1146);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1147);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1148);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1149);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1150);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1151);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1152);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1153);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1154);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1155);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1156);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1157);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1158);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1159);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1160);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1161);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1162);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1163);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1164);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1165);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1166);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1167);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1168);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1169);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1170);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1171);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1172);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1173);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1174);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1175);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1176);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1177);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1178);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1179);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1180);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1181);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1182);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1183);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1184);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1185);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1186);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1187);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1188);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1189);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1190);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1191);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1192);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1193);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1194);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1195);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1196);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1197);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1198);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1199);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1200);

  suite_add_tcase(s, tc_core);
  return s;
}

Suite *from_float_to_decimal_suite4(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("from_float_to_decimal_suite4");
  tc_core = tcase_create("Core");
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1201);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1202);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1203);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1204);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1205);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1206);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1207);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1208);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1209);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1210);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1211);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1212);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1213);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1214);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1215);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1216);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1217);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1218);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1219);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1220);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1221);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1222);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1223);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1224);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1225);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1226);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1227);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1228);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1229);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1230);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1231);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1232);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1233);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1234);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1235);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1236);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1237);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1238);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1239);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1240);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1241);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1242);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1243);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1244);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1245);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1246);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1247);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1248);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1249);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1250);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1251);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1252);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1253);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1254);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1255);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1256);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1257);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1258);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1259);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1260);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1261);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1262);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1263);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1264);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1265);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1266);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1267);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1268);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1269);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1270);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1271);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1272);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1273);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1274);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1275);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1276);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1277);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1278);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1279);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1280);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1281);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1282);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1283);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1284);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1285);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1286);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1287);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1288);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1289);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1290);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1291);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1292);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1293);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1294);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1295);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1296);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1297);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1298);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1299);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1300);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1301);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1302);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1303);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1304);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1305);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1306);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1307);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1308);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1309);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1310);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1311);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1312);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1313);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1314);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1315);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1316);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1317);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1318);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1319);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1320);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1321);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1322);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1323);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1324);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1325);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1326);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1327);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1328);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1329);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1330);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1331);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1332);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1333);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1334);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1335);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1336);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1337);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1338);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1339);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1340);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1341);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1342);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1343);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1344);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1345);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1346);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1347);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1348);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1349);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1350);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1351);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1352);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1353);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1354);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1355);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1356);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1357);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1358);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1359);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1360);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1361);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1362);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1363);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1364);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1365);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1366);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1367);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1368);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1369);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1370);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1371);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1372);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1373);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1374);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1375);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1376);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1377);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1378);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1379);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1380);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1381);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1382);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1383);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1384);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1385);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1386);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1387);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1388);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1389);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1390);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1391);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1392);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1393);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1394);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1395);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1396);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1397);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1398);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1399);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1400);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1401);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1402);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1403);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1404);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1405);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1406);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1407);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1408);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1409);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1410);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1411);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1412);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1413);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1414);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1415);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1416);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1417);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1418);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1419);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1420);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1421);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1422);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1423);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1424);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1425);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1426);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1427);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1428);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1429);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1430);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1431);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1432);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1433);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1434);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1435);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1436);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1437);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1438);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1439);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1440);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1441);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1442);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1443);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1444);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1445);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1446);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1447);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1448);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1449);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1450);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1451);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1452);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1453);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1454);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1455);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1456);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1457);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1458);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1459);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1460);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1461);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1462);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1463);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1464);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1465);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1466);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1467);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1468);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1469);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1470);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1471);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1472);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1473);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1474);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1475);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1476);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1477);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1478);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1479);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1480);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1481);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1482);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1483);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1484);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1485);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1486);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1487);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1488);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1489);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1490);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1491);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1492);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1493);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1494);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1495);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1496);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1497);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1498);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1499);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1500);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1501);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1502);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1503);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1504);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1505);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1506);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1507);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1508);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1509);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1510);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1511);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1512);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1513);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1514);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1515);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1516);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1517);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1518);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1519);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1520);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1521);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1522);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1523);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1524);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1525);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1526);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1527);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1528);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1529);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1530);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1531);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1532);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1533);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1534);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1535);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1536);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1537);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1538);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1539);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1540);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1541);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1542);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1543);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1544);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1545);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1546);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1547);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1548);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1549);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1550);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1551);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1552);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1553);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1554);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1555);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1556);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1557);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1558);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1559);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1560);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1561);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1562);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1563);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1564);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1565);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1566);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1567);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1568);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1569);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1570);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1571);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1572);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1573);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1574);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1575);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1576);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1577);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1578);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1579);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1580);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1581);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1582);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1583);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1584);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1585);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1586);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1587);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1588);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1589);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1590);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1591);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1592);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1593);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1594);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1595);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1596);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1597);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1598);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1599);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1600);

  suite_add_tcase(s, tc_core);
  return s;
}

Suite *from_float_to_decimal_suite5(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("from_float_to_decimal_suite5");
  tc_core = tcase_create("Core");
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1601);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1602);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1603);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1604);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1605);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1606);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1607);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1608);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1609);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1610);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1611);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1612);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1613);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1614);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1615);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1616);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1617);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1618);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1619);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1620);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1621);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1622);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1623);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1624);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1625);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1626);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1627);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1628);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1629);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1630);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1631);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1632);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1633);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1634);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1635);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1636);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1637);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1638);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1639);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1640);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1641);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1642);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1643);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1644);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1645);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1646);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1647);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1648);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1649);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1650);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1651);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1652);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1653);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1654);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1655);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1656);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1657);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1658);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1659);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1660);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1661);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1662);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1663);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1664);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1665);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1666);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1667);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1668);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1669);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1670);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1671);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1672);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1673);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1674);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1675);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1676);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1677);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1678);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1679);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1680);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1681);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1682);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1683);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1684);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1685);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1686);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1687);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1688);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1689);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1690);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1691);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1692);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1693);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1694);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1695);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1696);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1697);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1698);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1699);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1700);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1701);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1702);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1703);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1704);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1705);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1706);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1707);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1708);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1709);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1710);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1711);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1712);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1713);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1714);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1715);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1716);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1717);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1718);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1719);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1720);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1721);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1722);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1723);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1724);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1725);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1726);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1727);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1728);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1729);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1730);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1731);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1732);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1733);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1734);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1735);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1736);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1737);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1738);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1739);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1740);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1741);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1742);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1743);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1744);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1745);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1746);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1747);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1748);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1749);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1750);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1751);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1752);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1753);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1754);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1755);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1756);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1757);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1758);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1759);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1760);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1761);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1762);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1763);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1764);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1765);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1766);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1767);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1768);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1769);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1770);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1771);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1772);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1773);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1774);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1775);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1776);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1777);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1778);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1779);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1780);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1781);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1782);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1783);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1784);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1785);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1786);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1787);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1788);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1789);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1790);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1791);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1792);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1793);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1794);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1795);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1796);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1797);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1798);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1799);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1800);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1801);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1802);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1803);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1804);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1805);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1806);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1807);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1808);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1809);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1810);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1811);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1812);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1813);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1814);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1815);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1816);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1817);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1818);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1819);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1820);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1821);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1822);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1823);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1824);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1825);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1826);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1827);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1828);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1829);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1830);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1831);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1832);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1833);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1834);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1835);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1836);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1837);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1838);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1839);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1840);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1841);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1842);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1843);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1844);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1845);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1846);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1847);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1848);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1849);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1850);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1851);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1852);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1853);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1854);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1855);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1856);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1857);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1858);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1859);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1860);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1861);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1862);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1863);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1864);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1865);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1866);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1867);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1868);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1869);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1870);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1871);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1872);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1873);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1874);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1875);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1876);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1877);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1878);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1879);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1880);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1881);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1882);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1883);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1884);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1885);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1886);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1887);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1888);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1889);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1890);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1891);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1892);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1893);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1894);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1895);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1896);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1897);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1898);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1899);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1900);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1901);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1902);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1903);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1904);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1905);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1906);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1907);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1908);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1909);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1910);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1911);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1912);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1913);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1914);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1915);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1916);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1917);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1918);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1919);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1920);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1921);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1922);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1923);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1924);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1925);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1926);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1927);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1928);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1929);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1930);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1931);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1932);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1933);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1934);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1935);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1936);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1937);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1938);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1939);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1940);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1941);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1942);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1943);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1944);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1945);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1946);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1947);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1948);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1949);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1950);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1951);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1952);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1953);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1954);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1955);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1956);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1957);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1958);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1959);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1960);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1961);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1962);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1963);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1964);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1965);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1966);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1967);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1968);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1969);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1970);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1971);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1972);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1973);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1974);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1975);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1976);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1977);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1978);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1979);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1980);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1981);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1982);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1983);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1984);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1985);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1986);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1987);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1988);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1989);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1990);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1991);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1992);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1993);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1994);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1995);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1996);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1997);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1998);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok1999);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2000);

  suite_add_tcase(s, tc_core);
  return s;
}

Suite *from_float_to_decimal_suite6(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("from_float_to_decimal_suite6");
  tc_core = tcase_create("Core");
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2001);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2002);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2003);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2004);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2005);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2006);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2007);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2008);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2009);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2010);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2011);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2012);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2013);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2014);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2015);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2016);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2017);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2018);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2019);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2020);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2021);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2022);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2023);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2024);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2025);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2026);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2027);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2028);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2029);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2030);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2031);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2032);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2033);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2034);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2035);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2036);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2037);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2038);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2039);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2040);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2041);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2042);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2043);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2044);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2045);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2046);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2047);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2048);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2049);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2050);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2051);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2052);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2053);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2054);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2055);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2056);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2057);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2058);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2059);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2060);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2061);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2062);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2063);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2064);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2065);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2066);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2067);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2068);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2069);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2070);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2071);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2072);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2073);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2074);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2075);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2076);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2077);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2078);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2079);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2080);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2081);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2082);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2083);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2084);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2085);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2086);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2087);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2088);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2089);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2090);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2091);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2092);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2093);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2094);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2095);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2096);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2097);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2098);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2099);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2100);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2101);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2102);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2103);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2104);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2105);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2106);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2107);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2108);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2109);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2110);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2111);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2112);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2113);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2114);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2115);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2116);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2117);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2118);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2119);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2120);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2121);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2122);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2123);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2124);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2125);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2126);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2127);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2128);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2129);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2130);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2131);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2132);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2133);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2134);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2135);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2136);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2137);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2138);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2139);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2140);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2141);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2142);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2143);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2144);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2145);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2146);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2147);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2148);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2149);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2150);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2151);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2152);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2153);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2154);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2155);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2156);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2157);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2158);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2159);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2160);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2161);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2162);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2163);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2164);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2165);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2166);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2167);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2168);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2169);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2170);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2171);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2172);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2173);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2174);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2175);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2176);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2177);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2178);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2179);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2180);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2181);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2182);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2183);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2184);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2185);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2186);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2187);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2188);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2189);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2190);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2191);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2192);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2193);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2194);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2195);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2196);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2197);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2198);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2199);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2200);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2201);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2202);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2203);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2204);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2205);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2206);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2207);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2208);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2209);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2210);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2211);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2212);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2213);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2214);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2215);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2216);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2217);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2218);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2219);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2220);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2221);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2222);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2223);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2224);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2225);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2226);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2227);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2228);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2229);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2230);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2231);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2232);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2233);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2234);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2235);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2236);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2237);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2238);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2239);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2240);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2241);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2242);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2243);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2244);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2245);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2246);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2247);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2248);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2249);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2250);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2251);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2252);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2253);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2254);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2255);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2256);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2257);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2258);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2259);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2260);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2261);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2262);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2263);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2264);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2265);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2266);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2267);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2268);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2269);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2270);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2271);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2272);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2273);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2274);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2275);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2276);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2277);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2278);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2279);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2280);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2281);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2282);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2283);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2284);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2285);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2286);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2287);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2288);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2289);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2290);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2291);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2292);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2293);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2294);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2295);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2296);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2297);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2298);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2299);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2300);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2301);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2302);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2303);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2304);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2305);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2306);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2307);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2308);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2309);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2310);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2311);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2312);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2313);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2314);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2315);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2316);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2317);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2318);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2319);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2320);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2321);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2322);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2323);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2324);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2325);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2326);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2327);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2328);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2329);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2330);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2331);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2332);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2333);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2334);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2335);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2336);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2337);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2338);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2339);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2340);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2341);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2342);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2343);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2344);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2345);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2346);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2347);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2348);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2349);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2350);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2351);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2352);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2353);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2354);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2355);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2356);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2357);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2358);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2359);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2360);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2361);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2362);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2363);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2364);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2365);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2366);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2367);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2368);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2369);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2370);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2371);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2372);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2373);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2374);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2375);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2376);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2377);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2378);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2379);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2380);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2381);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2382);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2383);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2384);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2385);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2386);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2387);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2388);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2389);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2390);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2391);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2392);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2393);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2394);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2395);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2396);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2397);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2398);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2399);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2400);

  suite_add_tcase(s, tc_core);
  return s;
}

Suite *from_float_to_decimal_suite7(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("from_float_to_decimal_suite7");
  tc_core = tcase_create("Core");
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2401);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2402);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2403);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2404);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2405);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2406);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2407);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2408);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2409);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2410);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2411);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2412);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2413);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2414);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2415);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2416);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2417);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2418);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2419);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2420);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2421);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2422);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2423);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2424);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2425);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2426);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2427);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2428);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2429);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2430);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2431);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2432);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2433);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2434);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2435);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2436);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2437);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2438);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2439);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2440);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2441);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2442);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2443);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2444);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2445);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2446);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2447);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2448);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2449);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2450);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2451);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2452);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2453);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2454);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2455);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2456);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2457);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2458);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2459);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2460);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2461);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2462);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2463);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2464);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2465);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2466);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2467);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2468);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2469);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2470);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2471);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2472);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2473);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2474);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2475);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2476);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2477);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2478);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2479);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2480);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2481);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2482);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2483);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2484);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2485);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2486);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2487);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2488);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2489);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2490);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2491);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2492);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2493);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2494);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2495);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2496);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2497);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2498);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2499);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2500);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2501);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2502);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2503);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2504);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2505);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2506);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2507);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2508);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2509);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2510);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2511);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2512);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2513);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2514);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2515);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2516);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2517);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2518);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2519);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2520);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2521);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2522);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2523);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2524);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2525);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2526);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2527);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2528);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2529);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2530);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2531);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2532);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2533);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2534);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2535);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2536);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2537);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2538);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2539);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2540);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2541);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2542);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2543);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2544);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2545);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2546);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2547);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2548);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2549);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2550);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2551);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2552);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2553);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2554);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2555);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2556);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2557);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2558);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2559);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2560);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2561);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2562);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2563);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2564);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2565);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2566);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2567);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2568);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2569);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2570);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2571);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2572);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2573);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2574);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2575);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2576);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2577);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2578);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2579);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2580);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2581);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2582);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2583);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2584);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2585);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2586);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2587);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2588);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2589);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2590);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2591);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2592);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2593);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2594);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2595);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2596);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2597);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2598);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2599);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2600);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2601);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2602);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2603);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2604);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2605);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2606);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2607);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2608);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2609);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2610);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2611);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2612);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2613);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2614);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2615);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2616);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2617);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2618);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2619);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2620);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2621);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2622);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2623);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2624);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2625);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2626);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2627);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2628);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2629);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2630);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2631);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2632);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2633);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2634);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2635);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2636);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2637);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2638);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2639);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2640);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2641);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2642);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2643);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2644);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2645);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2646);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2647);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2648);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2649);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2650);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2651);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2652);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2653);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2654);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2655);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2656);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2657);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2658);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2659);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2660);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2661);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2662);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2663);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2664);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2665);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2666);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2667);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2668);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2669);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2670);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2671);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2672);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2673);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2674);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2675);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2676);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2677);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2678);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2679);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2680);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2681);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2682);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2683);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2684);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2685);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2686);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2687);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2688);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2689);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2690);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2691);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2692);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2693);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2694);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2695);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2696);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2697);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2698);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2699);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2700);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2701);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2702);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2703);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2704);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2705);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2706);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2707);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2708);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2709);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2710);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2711);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2712);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2713);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2714);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2715);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2716);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2717);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2718);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2719);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2720);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2721);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2722);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2723);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2724);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2725);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2726);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2727);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2728);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2729);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2730);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2731);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2732);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2733);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2734);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2735);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2736);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2737);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2738);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2739);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2740);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2741);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2742);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2743);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2744);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2745);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2746);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2747);
  tcase_add_test(tc_core, test_from_float_to_decimal_ok2748);

  suite_add_tcase(s, tc_core);
  return s;
}

Suite *from_float_to_decimal_suite0(void) {
  Suite *s;
  TCase *tc_core;

  s = suite_create("from_float_to_decimal0");
  tc_core = tcase_create("Core");

  tcase_add_loop_test(tc_core, test_from_float_to_decimal_fail_big, 0,
                      sizeof(fails_big) / sizeof(*fails_big));
  tcase_add_loop_test(tc_core, test_from_float_to_decimal_fail_big_negate, 0,
                      sizeof(fails_big) / sizeof(*fails_big));
  tcase_add_loop_test(tc_core, test_from_float_to_decimal_fail_small, 0,
                      sizeof(fails_small) / sizeof(*fails_small));
  tcase_add_loop_test(tc_core, test_from_float_to_decimal_fail_small_negate, 0,
                      sizeof(fails_small) / sizeof(*fails_small));

  tcase_add_test(tc_core, test_from_float_to_decimal_incorrect1);
  tcase_add_test(tc_core, test_from_float_to_decimal_unnormal1);
  tcase_add_test(tc_core, test_from_float_to_decimal_unnormal2);
  tcase_add_test(tc_core, test_from_float_to_decimal_unnormal3);
  tcase_add_test(tc_core, test_from_float_to_decimal_unnormal4);
  tcase_add_test(tc_core, test_from_float_to_decimal_unnormal5);
  tcase_add_test(tc_core, test_from_float_to_decimal_unnormal6);

  suite_add_tcase(s, tc_core);

  return s;
}

void test_from_float_to_decimal(int f, my_decimal decimal_check) {
  my_decimal result;

  float_cast_test cast_float;
  cast_float.int32_bytes = f;

  int code = my_from_float_to_decimal(cast_float.f, &result);

#if defined(__DEBUG)
  printf("---------------------------------\n");
  printf("Float:   %.28f\n", cast_float.f);
  printf("Decimal_check: \n");
  my_print_decimal_bits(decimal_check);
  my_print_decimal_string(decimal_check);
  printf("Decimal_result: \n");
  my_print_decimal_bits(result);
  my_print_decimal_string(result);
#endif

  ck_assert_int_eq(code, TEST_CONVERSION_OK);
  ck_assert_int_eq(my_is_equal(result, decimal_check), 1);
}
