#include "test_me.h"

#define ASSERT_SIGN_EQ(s1, s2, n) ck_assert_int_eq(my_strncmp(s1, s2, n), 0)

#define ASSERT_SIGN_GT(s1, s2, n) ck_assert_int_gt(my_strncmp(s1, s2, n), 0)

#define ASSERT_SIGN_LT(s1, s2, n) ck_assert_int_lt(my_strncmp(s1, s2, n), 0)

START_TEST(strncmp_1) { ASSERT_SIGN_EQ("Hello, world!", "Hello, world!", 13); }
END_TEST

START_TEST(strncmp_2) { ASSERT_SIGN_GT("Hello, world!", "Hello, World!", 13); }
END_TEST

START_TEST(strncmp_3) { ASSERT_SIGN_EQ("Hello, world!", "Hello", 5); }
END_TEST

START_TEST(strncmp_4) { ASSERT_SIGN_LT("Hello", "Hello, world!", 10); }
END_TEST

START_TEST(strncmp_5) { ASSERT_SIGN_LT("", "Hello", 5); }
END_TEST

START_TEST(strncmp_6) { ASSERT_SIGN_GT("Hello", "", 5); }
END_TEST

START_TEST(strncmp_7) { ASSERT_SIGN_EQ("\0Hello", "\0World", 6); }
END_TEST

START_TEST(strncmp_8) { ASSERT_SIGN_EQ("abcdef", "abcxyz", 3); }
END_TEST

START_TEST(strncmp_9) { ASSERT_SIGN_LT("abcdef", "abcxyz", 6); }
END_TEST

START_TEST(strncmp_10) { ASSERT_SIGN_EQ("Same", "Same", 0); }
END_TEST

Suite* test_strncmp(void) {
  Suite* s = suite_create("\033[45m-=MY_STRNCMP=-\033[0m");
  TCase* tc = tcase_create("strncmp_tc");

  suite_add_tcase(s, tc);
  tcase_add_test(tc, strncmp_1);
  tcase_add_test(tc, strncmp_2);
  tcase_add_test(tc, strncmp_3);
  tcase_add_test(tc, strncmp_4);
  tcase_add_test(tc, strncmp_5);
  tcase_add_test(tc, strncmp_6);
  tcase_add_test(tc, strncmp_7);
  tcase_add_test(tc, strncmp_8);
  tcase_add_test(tc, strncmp_9);
  tcase_add_test(tc, strncmp_10);

  suite_add_tcase(s, tc);
  return s;
}
