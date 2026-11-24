#include "test_me.h"

START_TEST(strncat_1) {
  char s1[30] = "Hello, world!";
  char s2[30] = "Hello, world!";
  char s3[] = "Hello, world!";
  ck_assert_pstr_eq(strncat(s1, s3, 13), my_strncat(s2, s3, 13));
}
END_TEST

START_TEST(strncat_2) {
  char s1[45] = "Hello, world!";
  char s2[45] = "Hello, world!";
  char s3[] = "\0";
  ck_assert_pstr_eq(strncat(s1, s3, 5), my_strncat(s2, s3, 5));
}
END_TEST

START_TEST(strncat_3) {
  char s1[30] = "Hello, world!";
  char s2[30] = "Hello, world!";
  char s3[] = "\n\0\\d\f\\g\7";
  ck_assert_pstr_eq(strncat(s1, s3, 2), my_strncat(s2, s3, 2));
}
END_TEST

START_TEST(strncat_4) {
  char s1[30] = "Hello, world!";
  char s2[30] = "Hello, world!";
  char s3[] = "";
  ck_assert_pstr_eq(strncat(s1, s3, 10), my_strncat(s2, s3, 10));
}
END_TEST

START_TEST(strncat_5) {
  char s1[30] = "";
  char s2[30] = "";
  char s3[] = "Hello, world!";
  ck_assert_pstr_eq(strncat(s1, s3, 13), my_strncat(s2, s3, 13));
}
END_TEST

START_TEST(strncat_6) {
  char s1[100] = "Hello, world!";
  char s2[100] = "Hello, world!";
  char s3[] =
      "My name is Polina. I hate this, maybe I'm not supposed for this.";
  ck_assert_pstr_eq(strncat(s1, s3, 30), my_strncat(s2, s3, 30));
}
END_TEST

START_TEST(strncat_7) {
  char s1[100] = "Hello\0world!";
  char s2[100] = "Hello\0world!";
  char s3[] =
      "My name is Polina. I hate this, maybe I'm not supposed for this.";
  ck_assert_pstr_eq(strncat(s1, s3, 20), my_strncat(s2, s3, 20));
}
END_TEST

START_TEST(strncat_8) {
  char s1[100] = "\0";
  char s2[100] = "\0";
  char s3[] =
      "My name is Polina. I hate this\0, maybe I'm not supposed for "
      "this.";
  ck_assert_pstr_eq(strncat(s1, s3, 10), my_strncat(s2, s3, 10));
}
END_TEST

START_TEST(strncat_9) {
  char s1[100] = "";
  char s2[100] = "";
  char s3[] = "\0";
  ck_assert_pstr_eq(strncat(s1, s3, 1), my_strncat(s2, s3, 1));
}
END_TEST

START_TEST(strncat_10) {
  char s1[100] = "Hell0000\0";
  char s2[100] = "Hell0000\0";
  char s3[] = "";
  ck_assert_pstr_eq(strncat(s1, s3, 5), my_strncat(s2, s3, 5));
}
END_TEST

Suite* test_strncat(void) {
  Suite* s = suite_create("\033[45m-=MY_STRNCAT=-\033[0m");
  TCase* tc = tcase_create("strncat_tc");

  suite_add_tcase(s, tc);
  tcase_add_test(tc, strncat_1);
  tcase_add_test(tc, strncat_2);
  tcase_add_test(tc, strncat_3);
  tcase_add_test(tc, strncat_4);
  tcase_add_test(tc, strncat_5);
  tcase_add_test(tc, strncat_6);
  tcase_add_test(tc, strncat_7);
  tcase_add_test(tc, strncat_8);
  tcase_add_test(tc, strncat_9);
  tcase_add_test(tc, strncat_10);

  suite_add_tcase(s, tc);
  return s;
}
