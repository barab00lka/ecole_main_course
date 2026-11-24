#include "errno.h"
#include "test_me.h"

// Helper: compare safely even if system strerror returns NULL (rare)
#define CK_ASSERT_STRERROR_EQ(code)  \
  do {                               \
    char *sys = strerror(code);      \
    char *my = my_strerror(code);  \
    ck_assert_ptr_ne(my, my_NULL); \
    ck_assert_ptr_ne(sys, NULL);     \
    ck_assert_pstr_eq(my, sys);     \
  } while (0)

START_TEST(test_strerror_all_known) {
  // iterate through a reasonable errno range; actual ERR_LIST_SIZE may
  // differ covers most known OS_X and Linux errno codes
  for (int i = 0; i < 135; i++) {
    CK_ASSERT_STRERROR_EQ(i);
  }
}
END_TEST

START_TEST(test_strerror_negative) {
  char *sys = strerror(-1);
  char *my = my_strerror(-1);
  ck_assert_ptr_ne(my, my_NULL);
  ck_assert_ptr_ne(sys, NULL);
  ck_assert_pstr_eq(my, sys);  // both should produce "Unknown error -1"
}
END_TEST

START_TEST(test_strerror_large_positive) {
  int code = 9999;
  char *sys = strerror(code);
  char *my = my_strerror(code);

  ck_assert_ptr_ne(my, my_NULL);
  ck_assert_ptr_ne(sys, NULL);
  ck_assert_pstr_eq(my, sys);  // both "Unknown error 9999"
}
END_TEST

START_TEST(test_strerror_boundary_low) {
  CK_ASSERT_STRERROR_EQ(0);  // "Success"
}
END_TEST

START_TEST(test_strerror_boundary_high) {
  CK_ASSERT_STRERROR_EQ(EDQUOT);  // near top of defined range
}
END_TEST

START_TEST(test_strerror_consistency) {
  // multiple calls should return same pointer or identical contents
  char *first = my_strerror(EIO);
  char *second = my_strerror(EIO);
  ck_assert_ptr_ne(first, my_NULL);
  ck_assert_ptr_ne(second, my_NULL);
  ck_assert_pstr_eq(first, second);
}
END_TEST

Suite *test_strerror(void) {
  Suite *s = suite_create("\033[45m-=MY_STRERROR=-\033[0m");
  TCase *tc = tcase_create("strerror_tc");

  tcase_add_test(tc, test_strerror_all_known);
  tcase_add_test(tc, test_strerror_negative);
  tcase_add_test(tc, test_strerror_large_positive);
  tcase_add_test(tc, test_strerror_boundary_low);
  tcase_add_test(tc, test_strerror_boundary_high);
  tcase_add_test(tc, test_strerror_consistency);

  suite_add_tcase(s, tc);
  return s;
}
