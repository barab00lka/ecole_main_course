#include <check.h>
#include <errno.h>
#include <stdlib.h>
#include <string.h>

#include "../my_string.h"

#define BUF_SIZE 512

// - my_memchr -
START_TEST(memchr_standard_hit) {
  char str[] = "Hello, World!";
  ck_assert_ptr_eq((char*)my_memchr(str, 'W', 13),
                   (char*)memchr(str, 'W', 13));
}
END_TEST

START_TEST(memchr_null_byte_search) {
  char str[] = "abc\0def";
  ck_assert_ptr_eq(my_memchr(str, '\0', 7), memchr(str, '\0', 7));
}
END_TEST

START_TEST(memchr_limit_n_miss) {
  char str[] = "ABCDE";
  ck_assert_ptr_eq(my_memchr(str, 'E', 4),
                   memchr(str, 'E', 4));  // 'E' is at index 4, outside n=4
}
END_TEST

START_TEST(memchr_limit_n_hit) {
  char str[] = "ABCDE";
  ck_assert_ptr_eq(my_memchr(str, 'E', 5), memchr(str, 'E', 5));
}
END_TEST

START_TEST(memchr_not_found) {
  char str[] = "Test";
  ck_assert_ptr_eq(my_memchr(str, 'Z', 4), memchr(str, 'Z', 4));
}
END_TEST

START_TEST(memchr_n_zero) {
  char str[] = "Test";
  ck_assert_ptr_eq(my_memchr(str, 'T', 0), memchr(str, 'T', 0));
}
END_TEST

// - my_memcmp -
START_TEST(memcmp_full_match) {
  ck_assert_int_eq(my_memcmp("Same", "Same", 4), memcmp("Same", "Same", 4));
}
END_TEST

START_TEST(memcmp_s1_less) {
  ck_assert_int_eq(my_memcmp("Apple", "Banana", 5),
                   memcmp("Apple", "Banana", 5));
}
END_TEST

START_TEST(memcmp_s1_greater) {
  ck_assert_int_eq(my_memcmp("Banana", "Apple", 5),
                   memcmp("Banana", "Apple", 5));
}
END_TEST

START_TEST(memcmp_partial_match) {
  ck_assert_int_eq(my_memcmp("ABCD", "ABCE", 3), memcmp("ABCD", "ABCE", 3));
}
END_TEST

START_TEST(memcmp_n_zero) {
  ck_assert_int_eq(my_memcmp("XYZ", "ABC", 0), memcmp("XYZ", "ABC", 0));
}
END_TEST

START_TEST(memcmp_binary_data) {
  char b1[] = {0x01, 0xFF};
  char b2[] = {0x01, 0x00};
  ck_assert_int_eq(my_memcmp(b1, b2, 2) > 0, memcmp(b1, b2, 2) > 0);
}
END_TEST

START_TEST(memcmp_null_vs_char) {
  char s1[] = "ABC\0";
  char s2[] = "ABCD";
  ck_assert_int_eq(my_memcmp(s1, s2, 5) < 0, memcmp(s1, s2, 5) < 0);
}
END_TEST

// - my_memcpy -
START_TEST(memcpy_standard_copy) {
  char dest[20] = "AAAAAAAA";
  char src[] = "NewData";
  ck_assert_str_eq((char*)my_memcpy(dest, src, 8),
                   (char*)memcpy(dest, src, 8));
}
END_TEST

START_TEST(memcpy_partial_copy) {
  char dest[11] = "XXXXXXXXXX";
  char src[] = "ABCDEF";
  ck_assert_str_eq((char*)my_memcpy(dest, src, 3),
                   (char*)memcpy(dest, src, 3));
}
END_TEST

START_TEST(memcpy_copy_null_bytes) {
  char dest1[6] = "AAAAA";
  char dest2[6] = "AAAAA";
  char src[] = {'a', '\0', 'b'};
  my_memcpy(dest1, src, 3);
  memcpy(dest2, src, 3);
  ck_assert_int_eq(dest1[1], dest2[1]);
  ck_assert_int_eq(dest2[2], dest2[2]);
}
END_TEST

START_TEST(memcpy_return_value) {
  char dest[10];
  char* ret1 = my_memcpy(dest, "Hi", 3);
  char* ret2 = memcpy(dest, "Hi", 3);
  ck_assert_ptr_eq(ret1, ret2);
}
END_TEST

START_TEST(memcpy_n_zero) {
  char dest[10] = "Original";
  ck_assert_str_eq(my_memcpy(dest, "New", 0), memcpy(dest, "New", 0));
}
END_TEST

START_TEST(memcpy_large_data) {
  char dest[50];
  char src[50];
  memset(src, 'L', 50);
  my_memcpy(dest, src, 50);
  ck_assert_int_eq(memcmp(dest, src, 50), 0);
}
END_TEST

START_TEST(memcpy_source_shorter) {
  char dest[10] = "AAAAAAAAA";
  char src[] = "S";
  ck_assert_str_eq(my_memcpy(dest, src, 2), memcpy(dest, src, 2));  // S\0
}
END_TEST

// - my_memset -
START_TEST(memset_standard_char) {
  char dest[11] = "1234567890";
  // s22_memset(dest, 'X', 5);
  ck_assert_str_eq((char*)my_memset(dest, 'X', 5),
                   (char*)memset(dest, 'X', 5));
}
END_TEST

START_TEST(memset_null_byte) {
  char dest1[6] = "ABCDE";
  char dest2[6] = "ABCDE";
  memset(dest2, 0, 5);
  my_memset(dest1, 0, 5);
  ck_assert_int_eq(dest1[0], dest2[0]);
  ck_assert_int_eq(dest1[4], dest2[4]);
}
END_TEST

START_TEST(memset_full_buffer) {
  char dest[10];
  // my_memset(dest, '#', 10);
  ck_assert_str_eq((char*)my_memset(dest, '#', 10),
                   (char*)memset(dest, '#', 10));
}
END_TEST

START_TEST(memset_integer_c_masking) {
  unsigned char dest[1];
  ck_assert_int_eq(
      ((unsigned char*)my_memset(dest, 0xAAFF, 1))[0],
      ((unsigned char*)memset(dest, 0xAAFF, 1))[0]);  // both eq 0xFF
}
END_TEST

START_TEST(memset_return_value) {
  char dest[10];
  char* ret1 = my_memset(dest, 'M', 5);
  char* ret2 = memset(dest, 'M', 5);
  ck_assert_ptr_eq(ret1, ret2);
}
END_TEST

// - my_strncat -
START_TEST(strncat_standard) {
  char dest[20] = "Hello ";
  ck_assert_str_eq(my_strncat(dest, "World", 6),
                   strncat(dest, "World", 6));  // EDGE CASE N = 5
}
END_TEST

START_TEST(strncat_limit_n) {
  char dest[20] = "Prefix";
  ck_assert_str_eq(my_strncat(dest, "Suffix", 3), strncat(dest, "Suffix", 3));
}
END_TEST

START_TEST(strncat_n_too_large) {
  char dest[20] = "Pre";
  ck_assert_str_eq(my_strncat(dest, "Fix", 10), strncat(dest, "Fix", 10));
}
END_TEST

START_TEST(strncat_n_zero) {
  char dest[20] = "Original";
  ck_assert_str_eq(my_strncat(dest, "New", 0), strncat(dest, "New", 0));
}
END_TEST

START_TEST(strncat_empty_src) {
  char dest[20] = "Dest";
  ck_assert_str_eq(my_strncat(dest, "", 5), strncat(dest, "", 5));
}
END_TEST

START_TEST(strncat_empty_dest) {
  char dest[20] = "";
  ck_assert_str_eq(my_strncat(dest, "Src", 4),
                   strncat(dest, "Src", 4));  // EDGE CASE N = 3
}
END_TEST

START_TEST(strncat_return_value) {
  char dest[20] = "Check";
  char* ret1 = my_strncat(dest, "Ret", 4);
  char* ret2 = my_strncat(dest, "Ret", 4);
  ck_assert_ptr_eq(ret1, ret2);
}
END_TEST

// - my_strchr -
START_TEST(strchr_standard_hit) {
  char str[] = "banana";
  ck_assert_ptr_eq(my_strchr(str, 'a'), strchr(str, 'a'));
}
END_TEST

START_TEST(strchr_null_terminator) {
  char str[] = "abc";
  ck_assert_ptr_eq(my_strchr(str, '\0'), strchr(str, '\0'));
}
END_TEST

START_TEST(strchr_not_found) {
  char str[] = "Test";
  ck_assert_ptr_eq(my_strchr(str, 'z'), strchr(str, 'z'));
}
END_TEST

START_TEST(strchr_at_start) {
  char str[] = "Start";
  ck_assert_ptr_eq(my_strchr(str, 'S'), strchr(str, 'S'));
}
END_TEST

START_TEST(strchr_case_sensitive) {
  char str[] = "Apple";
  ck_assert_ptr_eq(my_strchr(str, 'a'), strchr(str, 'a'));
}
END_TEST

START_TEST(strchr_in_empty) {
  ck_assert_ptr_eq(my_strchr("", 'a'), strchr("", 'a'));
}
END_TEST

// - my_strncmp -
START_TEST(strncmp_equal) {
  ck_assert_int_eq(my_strncmp("Hello", "Hello", 5), 0);
}
END_TEST

START_TEST(strncmp_s1_less) { ck_assert_int_lt(my_strncmp("A", "B", 1), 0); }
END_TEST

START_TEST(strncmp_s1_greater) {
  ck_assert_int_gt(my_strncmp("B", "A", 1), 0);
}
END_TEST

START_TEST(strncmp_difference_beyond_n) {
  ck_assert_int_eq(my_strncmp("123X", "123Y", 3), 0);
}
END_TEST

START_TEST(strncmp_s1_shorter) {
  ck_assert_int_lt(my_strncmp("ABC", "ABCD", 4), 0);
}
END_TEST

START_TEST(strncmp_s2_shorter) {
  ck_assert_int_gt(my_strncmp("ABCD", "ABC", 4), 0);
}
END_TEST

START_TEST(strncmp_n_zero) {
  ck_assert_int_eq(my_strncmp("Anything", "Goes", 0), 0);
}
END_TEST

// - my_strncpy -
START_TEST(strncpy_truncate) {
  char dest[11] = "1234567890";
  // my_strncpy(dest, "ABCDE", 3);
  ck_assert_str_eq(my_strncpy(dest, "ABCDE", 3), strncpy(dest, "ABC", 4));
}
END_TEST

START_TEST(strncpy_exact_copy) {
  char dest[5];
  my_strncpy(dest, "XYZ", 4);
  ck_assert_str_eq(my_strncpy(dest, "XYZ", 4), strncpy(dest, "XYZ", 4));
}
END_TEST

START_TEST(strncpy_with_padding) {
  char dest[] = "1111111111";
  my_strncpy(dest, "HI", 5);
  ck_assert_str_eq(my_strncpy(dest, "HI", 5), strncpy(dest, "HI", 5));
}
END_TEST

START_TEST(strncpy_empty_src_padding) {
  char dest[] = "ABCDE";
  ck_assert_str_eq(my_strncpy(dest, "", 3), strncpy(dest, "", 3));
}
END_TEST

/*
START_TEST(strncpy_n_zero) {
    char dest[] = "ABCDE";
    ck_assert_str_eq(my_strncpy(dest, "New", 0), strncpy(dest, "New", 0));
} END_TEST
*/

START_TEST(strncpy_copy_full_size) {
  char dest[11];
  char src[] = "0123456789";
  ck_assert_str_eq(my_strncpy(dest, src, 11), strncpy(dest, src, 11));
}
END_TEST

START_TEST(strncpy_return_value) {
  char dest[10];
  char* ret1 = my_strncpy(dest, "R", 2);
  char* ret2 = strncpy(dest, "R", 2);
  ck_assert_ptr_eq(ret1, ret2);
}
END_TEST

// - my_strcspn -
START_TEST(strcspn_standard) {
  ck_assert_int_eq(my_strcspn("ABCDEF", "XYCD"),
                   strcspn("ABCDEF", "XYCD"));  // Breaks at 'C'
}
END_TEST

START_TEST(strcspn_no_match) {
  ck_assert_int_eq(my_strcspn("12345", "ABC"), strcspn("12345", "ABC"));
}
END_TEST

START_TEST(strcspn_hit_at_start) {
  ck_assert_int_eq(my_strcspn("Test", "eT"), strcspn("Test", "eT"));
}
END_TEST

START_TEST(strcspn_empty_accept) {
  ck_assert_int_eq(my_strcspn("Test", ""), strcspn("Test", ""));
}
END_TEST

START_TEST(strcspn_empty_str1) {
  ck_assert_int_eq(my_strcspn("", "Test"), strcspn("", "Test"));
}
END_TEST

START_TEST(strcspn_null_byte) {
  ck_assert_int_eq(my_strcspn("AB\0CD", "D"),
                   strcspn("AB\0CD",
                           "D"));  // Stops at \0 cuz assuming that
                                   // initial string is correct
}
END_TEST

// - my_strerror -
START_TEST(strerror_zero) { ck_assert_ptr_ne(my_strerror(0), my_NULL); }
END_TEST

START_TEST(strerror_eperm) { ck_assert_ptr_ne(my_strerror(EPERM), my_NULL); }
END_TEST

START_TEST(strerror_enoent) {
  ck_assert_ptr_ne(my_strerror(ENOENT), my_NULL);
  ck_assert_str_eq(my_strerror(ENOENT), strerror(ENOENT));
}
END_TEST

START_TEST(strerror_efault) {
  ck_assert_ptr_ne(my_strerror(EFAULT), my_NULL);
}
END_TEST

START_TEST(strerror_high_valid) {
  ck_assert_ptr_ne(my_strerror(EDQUOT), my_NULL);
}
END_TEST

START_TEST(strerror_out_of_bounds_positive) {
  char* msg = my_strerror(9999);
  ck_assert_ptr_ne(msg, my_NULL);
  ck_assert_int_gt(strlen(msg), 0);
}
END_TEST

START_TEST(strerror_out_of_bounds_negative) {
  char* msg = my_strerror(-1);
  ck_assert_ptr_ne(msg, my_NULL);
  ck_assert_int_gt(strlen(msg), 0);
}
END_TEST

START_TEST(strerror_consistency) {
  ck_assert_ptr_ne(my_strerror(EAGAIN), my_NULL);
  ck_assert_ptr_ne(my_strerror(EIO), my_NULL);
}
END_TEST

// - my_strlen -
START_TEST(strlen_standard) {
  ck_assert_int_eq(my_strlen("Test"), strlen("Test"));
}
END_TEST

START_TEST(strlen_empty) { ck_assert_int_eq(my_strlen(""), strlen("")); }
END_TEST

START_TEST(strlen_long) {
  ck_assert_int_eq(my_strlen("ABCDEFGHIJKLMNOPQRSTUVWXYZ"),
                   strlen("ABCDEFGHIJKLMNOPQRSTUVWXYZ"));
}
END_TEST

START_TEST(strlen_with_spaces) {
  ck_assert_int_eq(my_strlen(" Hello World "), strlen(" Hello World "));
}
END_TEST

START_TEST(strlen_embedded_null) {
  char str[] = {'a', 'b', '\0', 'c'};
  ck_assert_int_eq(my_strlen(str), strlen(str));
}
END_TEST

// - my_strpbrk -
START_TEST(strpbrk_standard) {
  char str[] = "Test data for break";
  ck_assert_ptr_eq(my_strpbrk(str, "df"), strpbrk(str, "df"));
}
END_TEST

START_TEST(strpbrk_first_char_wins) {
  char str[] = "apple pie";
  ck_assert_ptr_eq(my_strpbrk(str, "ep"), strpbrk(str, "ep"));
}
END_TEST

START_TEST(strpbrk_no_match) {
  char str[] = "test";
  ck_assert_ptr_eq(my_strpbrk(str, "XYZ"), strpbrk(str, "XYZ"));
}
END_TEST

START_TEST(strpbrk_match_at_start) {
  char str[] = "Start";
  ck_assert_ptr_eq(my_strpbrk(str, "S"), strpbrk(str, "S"));
}
END_TEST

START_TEST(strpbrk_match_at_end) {
  char str[] = "End";
  ck_assert_ptr_eq(my_strpbrk(str, "dX"), strpbrk(str, "dX"));
}
END_TEST

START_TEST(strpbrk_empty_str2) {
  ck_assert_ptr_eq(my_strpbrk("Test", ""), strpbrk("Test", ""));
}
END_TEST

START_TEST(strpbrk_empty_str1) {
  ck_assert_ptr_eq(my_strpbrk("", "T"), strpbrk("", "T"));
}
END_TEST

// - my_strrchr -
START_TEST(strrchr_standard) {
  char str[] = "Mississippi";
  ck_assert_ptr_eq(my_strrchr(str, 'i'), strrchr(str, 'i'));
}
END_TEST

START_TEST(strrchr_not_found) {
  char str[] = "Test";
  ck_assert_ptr_eq(my_strrchr(str, 'z'), strrchr(str, 'z'));
}
END_TEST

START_TEST(strrchr_null_terminator) {
  char str[] = "abc";
  ck_assert_ptr_eq(my_strrchr(str, '\0'), strrchr(str, '\0'));
}
END_TEST

START_TEST(strrchr_single_occurrence) {
  char str[] = "Unique";
  ck_assert_ptr_eq(my_strrchr(str, 'U'), strrchr(str, 'U'));
}
END_TEST

START_TEST(strrchr_in_empty_for_char) {
  ck_assert_ptr_eq(my_strrchr("", 'a'), strrchr("", 'a'));
}
END_TEST

START_TEST(strrchr_in_empty_for_null) {
  ck_assert_ptr_eq(my_strrchr("", '\0'), strrchr("", '\0'));
}
END_TEST

// - my_strstr -
START_TEST(strstr_standard) {
  char str[] = "This is a substring test";
  ck_assert_ptr_eq(my_strstr(str, "string"), strstr(str, "string"));
}
END_TEST

START_TEST(strstr_at_start) {
  char str[] = "Start Test";
  ck_assert_ptr_eq(my_strstr(str, "Start"), strstr(str, "Start"));
}
END_TEST

START_TEST(strstr_at_end) {
  char str[] = "End test";
  ck_assert_ptr_eq(my_strstr(str, "test"), strstr(str, "test"));
}
END_TEST

START_TEST(strstr_no_match) {
  ck_assert_ptr_eq(my_strstr("Haystack", "Needle"),
                   strstr("Haystack", "Needle"));
}
END_TEST

START_TEST(strstr_empty_needle) {
  char str[] = "Test";
  ck_assert_ptr_eq(my_strstr(str, ""), strstr(str, ""));
}
END_TEST

START_TEST(strstr_empty_haystack) {
  ck_assert_ptr_eq(my_strstr("", "a"), strstr("", "a"));
}
END_TEST

START_TEST(strstr_case_sensitive) {
  ck_assert_ptr_eq(my_strstr("TEST", "test"), strstr("TEST", "test"));
}
END_TEST

// - my_strtok -
START_TEST(strtok_first_call) {
  char s1[] = "one,two.three";
  char s2[] = "one,two.three";
  ck_assert_str_eq(my_strtok(s1, ",."), strtok(s2, ",."));
}
END_TEST

START_TEST(strtok_second_call) {
  char s1[] = "one,two.three";
  char s2[] = "one,two.three";
  my_strtok(s1, ",.");
  strtok(s2, ",.");
  ck_assert_str_eq(my_strtok(my_NULL, ",."), strtok(my_NULL, ",."));
}
END_TEST

START_TEST(strtok_null_return) {
  char s1[] = "one";
  char s2[] = "one";
  my_strtok(s1, ",");
  strtok(s2, ",");
  ck_assert_ptr_eq(my_strtok(my_NULL, ","), strtok(my_NULL, ","));
}
END_TEST

START_TEST(strtok_consecutive_delimiters) {
  char s1[] = "a,,b";
  char s2[] = "a,,b";
  ck_assert_str_eq(my_strtok(s1, ","), strtok(s2, ","));
  ck_assert_str_eq(my_strtok(my_NULL, ","), strtok(my_NULL, ","));
}
END_TEST

START_TEST(strtok_delimiters_at_start) {
  char s1[] = ",,test";
  char s2[] = ",,test";
  ck_assert_str_eq(my_strtok(s1, ","), strtok(s2, ","));
}
END_TEST

START_TEST(strtok_delimiters_at_end) {
  char s1[] = "test,,";
  char s2[] = "test,,";
  my_strtok(s1, ",");
  strtok(s2, ",");
  ck_assert_ptr_eq(my_strtok(my_NULL, ","), strtok(my_NULL, ","));
}
END_TEST

START_TEST(strtok_all_delimiters) {
  char s1[] = ",,,";
  char s2[] = ",,,";
  ck_assert_ptr_eq(my_strtok(s1, ","), strtok(s2, ","));
}
END_TEST

START_TEST(strtok_multiple_delimiters_set) {
  char s1[] = "one.two-three";
  char s2[] = "one.two-three";
  ck_assert_str_eq(my_strtok(s1, ".-"), strtok(s2, ".-"));
  ck_assert_str_eq(my_strtok(my_NULL, ".-"), strtok(my_NULL, ".-"));
  ck_assert_str_eq(my_strtok(my_NULL, ".-"), strtok(my_NULL, ".-"));
}
END_TEST

START_TEST(strtok_null_input_empty_delim) {
  char s1[] = "a";
  char s2[] = "a";
  my_strtok(s1, ".");
  strtok(s2, ".");
  ck_assert_ptr_eq(my_strtok(my_NULL, ""),
                   strtok(my_NULL, ""));  // Delimiter is empty, should stop
}
END_TEST

START_TEST(strtok_reinit) {
  char s1_1[] = "1:2";
  char s2_1[] = "A-B";

  char s1_2[] = "1:2";
  char s2_2[] = "A-B";
  ck_assert_str_eq(my_strtok(s1_1, ":"), strtok(s1_2, ":"));  // Init s1
  ck_assert_str_eq(my_strtok(s2_1, "-"), strtok(s2_2, "-"));  // Reinit with s2
  ck_assert_str_eq(my_strtok(my_NULL, "-"),
                   strtok(my_NULL, "-"));  // Continue s2
}
END_TEST

// ==================== to_upper Tests ====================

START_TEST(test_to_upper_basic) {
  char* result = my_to_upper("hello");
  ck_assert_ptr_ne(result, NULL);
  ck_assert_str_eq(result, "HELLO");
  free(result);
}
END_TEST

START_TEST(test_to_upper_mixed_case) {
  char* result = my_to_upper("HeLLo WoRLd");
  ck_assert_ptr_ne(result, NULL);
  ck_assert_str_eq(result, "HELLO WORLD");
  free(result);
}
END_TEST

START_TEST(test_to_upper_null_input) {
  char* result = my_to_upper(NULL);
  ck_assert_ptr_eq(result, NULL);
}
END_TEST

START_TEST(test_to_upper_empty_string) {
  char* result = my_to_upper("");
  ck_assert_ptr_ne(result, NULL);
  ck_assert_str_eq(result, "");
  free(result);
}
END_TEST

START_TEST(test_to_upper_no_change) {
  char* result = my_to_upper("HELLO123");
  ck_assert_ptr_ne(result, NULL);
  ck_assert_str_eq(result, "HELLO123");
  free(result);
}
END_TEST

// ==================== to_lower Tests ====================

START_TEST(test_to_lower_basic) {
  char* result = my_to_lower("HELLO");
  ck_assert_ptr_ne(result, NULL);
  ck_assert_str_eq(result, "hello");
  free(result);
}
END_TEST

START_TEST(test_to_lower_mixed_case) {
  char* result = my_to_lower("HeLLo WoRLd");
  ck_assert_ptr_ne(result, NULL);
  ck_assert_str_eq(result, "hello world");
  free(result);
}
END_TEST

START_TEST(test_to_lower_null_input) {
  char* result = my_to_lower(NULL);
  ck_assert_ptr_eq(result, NULL);
}
END_TEST

// ==================== insert Tests ====================

START_TEST(test_insert_basic) {
  char* result = my_insert("hello", " world", 5);
  ck_assert_ptr_ne(result, NULL);
  ck_assert_str_eq(result, "hello world");
  free(result);
}
END_TEST

START_TEST(test_insert_middle) {
  char* result = my_insert("hello", " beautiful", 5);
  ck_assert_ptr_ne(result, NULL);
  ck_assert_str_eq(result, "hello beautiful");
  free(result);
}
END_TEST

START_TEST(test_insert_beginning) {
  char* result = my_insert("world", "hello ", 0);
  ck_assert_ptr_ne(result, NULL);
  ck_assert_str_eq(result, "hello world");
  free(result);
}
END_TEST

START_TEST(test_insert_empty_string) {
  char* result = my_insert("hello", "", 2);
  ck_assert_ptr_ne(result, NULL);
  ck_assert_str_eq(result, "hello");
  free(result);
}
END_TEST

START_TEST(test_insert_null_input) {
  char* result = my_insert(my_NULL, "test", 0);
  ck_assert_ptr_eq(result, NULL);

  result = my_insert("test", my_NULL, 0);
  ck_assert_ptr_eq(result, NULL);
}
END_TEST

START_TEST(test_insert_index_out_of_bounds) {
  char* result = my_insert("hello", " world", 10);
  ck_assert_ptr_eq(result, NULL);
}
END_TEST

// ==================== trim Tests ====================

START_TEST(test_trim_basic) {
  char* result = (char*)my_trim("  hello  ", " ");
  ck_assert_ptr_ne(result, NULL);
  ck_assert_str_eq(result, "hello");
  free(result);
}
END_TEST

START_TEST(test_trim_multiple_chars) {
  char* result = (char*)my_trim("abchelloabc", "abc");
  ck_assert_ptr_ne(result, NULL);
  ck_assert_str_eq(result, "hello");
  free(result);
}
END_TEST

START_TEST(test_trim_all_trimmed) {
  char* result = (char*)my_trim("hihi", "hi");
  ck_assert_ptr_ne(result, NULL);
  ck_assert_str_eq(result, "");
  free(result);
}
END_TEST

START_TEST(test_trim_no_trim_chars) {
  char* result = (char*)my_trim("hello", "");
  ck_assert_ptr_ne(result, NULL);
  ck_assert_str_eq(result, "hello");
  free(result);
}
END_TEST

START_TEST(test_trim_null_input) {
  char* result = (char*)my_trim(my_NULL, " ");
  ck_assert_ptr_eq(result, NULL);
}
END_TEST

START_TEST(test_trim_empty_string) {
  char* result = (char*)my_trim("", "abc");
  ck_assert_ptr_ne(result, NULL);
  ck_assert_str_eq(result, "");
  free(result);
}
END_TEST

START_TEST(test_trim_middle_unchanged) {
  char* result = (char*)my_trim("xxhelloxx", "x");
  ck_assert_ptr_ne(result, NULL);
  ck_assert_str_eq(result, "hello");
  free(result);
}
END_TEST

START_TEST(test_trim_default_whitespace) {
  // Test that it trims whitespace when trim_chars is NULL or empty
  char* result = (char*)my_trim("  \t\nhello\n\t  ", my_NULL);
  ck_assert_ptr_ne(result, NULL);
  ck_assert_str_eq(result, "hello");
  free(result);
}
END_TEST

#define SPRINTF_TEST(name, format, ...)         \
  START_TEST(name) {                            \
    char std_buf[BUF_SIZE] = {0};               \
    char my_buf[BUF_SIZE] = {0};                \
    sprintf(std_buf, format, ##__VA_ARGS__);    \
    my_sprintf(my_buf, format, ##__VA_ARGS__); \
    ck_assert_str_eq(std_buf, my_buf);          \
  }                                             \
  END_TEST

// ==================== Sprintf Tests ====================
// - (d, i, s, c, u, o, x, X, p, %) -

SPRINTF_TEST(test_1_basic_string, "Hello %s!", "World")
SPRINTF_TEST(test_2_basic_int_positive, "The number is %d.", 42)
SPRINTF_TEST(test_3_basic_int_negative, "The number is %d.", -123)
SPRINTF_TEST(test_4_basic_char, "Character: %c", 'A')
SPRINTF_TEST(test_5_multiple_args, "String: %s, Int: %d, Char: %c", "Test", 100,
             'Z')
SPRINTF_TEST(test_6_unsigned_int, "Unsigned max: %u", 4294967295U)
SPRINTF_TEST(test_7_octal, "Octal of 64: %o", 64)
SPRINTF_TEST(test_8_hex_lower, "Hex of 255: %x", 255)

// - (f, e, E, g, G) -

SPRINTF_TEST(test_9_float_f_default_precision, "Basic float: %f", 123.456789)
SPRINTF_TEST(test_10_float_f_precision_2, "Float precision 2: %.2f", 3.14159)
SPRINTF_TEST(test_11_float_f_precision_0, "Float precision 0: %.0f", 99.5)
SPRINTF_TEST(test_12_float_e_basic, "Scientific notation: %e", 0.0000123)
SPRINTF_TEST(test_13_float_E_uppercase, "Scientific upper: %E", 1.2345678e+5)
SPRINTF_TEST(test_14_float_g_short_rep, "Short representation: %g", 1234567.0)
SPRINTF_TEST(test_15_float_G_with_precision, "G with precision: %.4G",
             0.000012345)
SPRINTF_TEST(test_16_float_f_hash_flag, "Float # flag: %#.0f",
             123.0)  // Forces decimal point
SPRINTF_TEST(test_17_float_g_hash_flag, "G # flag: %#g",
             1230000.0)  // Keeps trailing zeros on 'e' form
SPRINTF_TEST(test_18_float_f_plus_flag, "Float + flag: %+f", 55.5)

// - (+, space, #, 0, -) and Width/Precision -

SPRINTF_TEST(test_19_width_int, "Padded int: |%5d|", 123)
SPRINTF_TEST(test_20_width_string, "Padded string: |%10s|", "text")
SPRINTF_TEST(test_21_left_align, "Left aligned: |%-8d|", 99)
SPRINTF_TEST(test_22_zero_padding, "Zero padded: |%05d|", 7)
SPRINTF_TEST(test_23_precision_int_expand, "Precision int (expand): %.5d", 123)
SPRINTF_TEST(test_24_precision_string_truncate, "Precision string: %.5s",
             "longstring")
SPRINTF_TEST(test_25_width_precision_int, "Width & Precision: |%10.5d|", 42)
SPRINTF_TEST(test_26_width_precision_string,
             "Width & Precision String: |%10.5s|", "longtextvalue")
SPRINTF_TEST(test_27_flag_plus_positive, "Plus flag (+): %+d", 100)
SPRINTF_TEST(test_28_flag_space, "Space flag: |% d|", 5)
SPRINTF_TEST(test_29_flag_hash_octal, "Hash octal: %#o", 16)
SPRINTF_TEST(test_30_flag_hash_hex_upper, "Hash hex upper: %#X", 255)
SPRINTF_TEST(test_31_mixed_flags_plus_minus, "Mixed flags: |%+-10d|", 500)
SPRINTF_TEST(test_32_zero_padding_negative, "Zero pad negative: %05d", -10)
// SPRINTF_TEST(test_33_left_align_overrides_zero_pad, "Left align overrides 0:
// |%-05d|", 12)

// - (h, l, L) -

SPRINTF_TEST(test_34_long_decimal_l, "Long decimal: %ld", 2147483646L)
// SPRINTF_TEST(test_35_long_long_decimal, "Long long: %lld",
// 9223372036854775807LL)
SPRINTF_TEST(test_36_unsigned_long, "Unsigned long: %lu", 4294967295UL)
SPRINTF_TEST(test_37_short_int, "Short int: %hd", (short)32767)
SPRINTF_TEST(test_38_short_hex, "Short hex: %hx", (short)0xFFFF)
// SPRINTF_TEST(test_39_long_long_unsigned_octal, "LL unsigned octal: %llo",
// 18446744073709551615ULL)
SPRINTF_TEST(test_40_long_double_L_basic, "Long double f: %Lf",
             1234.5678912345L)
SPRINTF_TEST(test_41_long_double_L_precision, "Long double e: %.10Le",
             1.0L / 3.0L)
// SPRINTF_TEST(test_42_length_l_string, "Long string: %ls", L"Wide String") //
// Not standard, but checks %ls usage SPRINTF_TEST(test_43_length_l_char, "Long
// char: %lc", L'Ω') // Not standard, but checks %lc usage

// Dynamic Width/Precision (*) and Edge Cases

SPRINTF_TEST(test_44_dynamic_width, "Dynamic width: |%*d|", 5, 123)
SPRINTF_TEST(test_45_dynamic_precision_int, "Dynamic precision int: |%.*d|", 5,
             123)
SPRINTF_TEST(test_46_dynamic_width_precision_string,
             "Dynamic w/p string: |%*.*s|", 10, 5, "longtext")
SPRINTF_TEST(test_47_dynamic_width_float, "Dynamic width float: |%*f|", 15,
             1.23)
SPRINTF_TEST(test_48_dynamic_negative_width, "Dynamic negative width: |%*d|",
             -5, 123)  // Should act as left align
SPRINTF_TEST(test_49_width_zero_value, "Width zero value: |%3d|", 0)
SPRINTF_TEST(test_50_precision_zero_int_zero_val,
             "Zero precision on zero: %.0d", 0)  // Should print nothing
SPRINTF_TEST(test_51_precision_zero_int_non_zero,
             "Zero precision on non-zero: %.0d", 1)  // Should print '1'
// SPRINTF_TEST(test_52_null_string, "Null string: %s", (char *)my_NULL)
SPRINTF_TEST(test_53_pointer, "Pointer: %p", (void*)0xDEADBEEF)
SPRINTF_TEST(test_54_pointer_null, "Null pointer: %p", (void*)my_NULL)
SPRINTF_TEST(test_55_percent_sign, "Literal percent: 50%% off")
SPRINTF_TEST(test_56_hash_flag_on_zero_hex, "Hash on 0 hex: %#x",
             0)  // Should print just '0'
// SPRINTF_TEST(test_57_i_specifier_hex_input, "i specifier (hex): %i", 0xFF) //
// %i handles base detection (not for sprintf though)

// ====================================================================
// SECTION 6: Advanced Combinations (x, o, p, s, and flags)
// ====================================================================

SPRINTF_TEST(test_60_hex_full_combo, "Hex combo: |%#-10.5x|",
             0xabc)  // #,-,width,precision,x
SPRINTF_TEST(test_61_octal_zero_precision, "Octal zero precision: %.0o",
             0)  // Should print nothing
SPRINTF_TEST(test_62_pointer_width, "Pointer with width: |%20p|",
             (void*)0x12345)
SPRINTF_TEST(test_63_string_left_align_precision, "String combo: |%-10.5s|",
             "abcdefghijkl")  // Left align, width 10, truncate to 5
SPRINTF_TEST(test_64_string_zero_precision, "String zero precision: '%.0s'",
             "hello")  // Should print ''
SPRINTF_TEST(test_65_unsigned_precision_width, "Unsigned combo: |%8.6u|",
             1234)  // Width 8, Precision 6
SPRINTF_TEST(test_66_dynamic_precision_zero, "Dynamic precision zero: |%.*d|",
             0, 0)  // Dynamic precision is 0, value is 0 -> prints nothing
SPRINTF_TEST(test_67_char_width_left, "Char width left: |%-5c|", 'Z')
SPRINTF_TEST(test_68_d_space_zero_padding, "D space 0 pad: |% 08d|",
             123)  // space and 0 flag conflict (0 wins for padding)
SPRINTF_TEST(test_69_float_L_width_precision, "Long double combo: |%15.8LE|",
             1.2345678912345L)

// -------------------------------------------------------------------------
// |                               MAIN SETUP                              |
// -------------------------------------------------------------------------

Suite* my_string_suite() {
  Suite* s = suite_create("String Library Tests");

  TCase* tc_mem = tcase_create("Memory_Functions");
  tcase_add_test(tc_mem, memchr_standard_hit);
  tcase_add_test(tc_mem, memchr_null_byte_search);
  tcase_add_test(tc_mem, memchr_limit_n_miss);
  tcase_add_test(tc_mem, memchr_limit_n_hit);
  tcase_add_test(tc_mem, memchr_not_found);
  tcase_add_test(tc_mem, memchr_n_zero);

  tcase_add_test(tc_mem, memcmp_full_match);
  tcase_add_test(tc_mem, memcmp_s1_less);
  tcase_add_test(tc_mem, memcmp_s1_greater);
  tcase_add_test(tc_mem, memcmp_partial_match);
  tcase_add_test(tc_mem, memcmp_n_zero);
  tcase_add_test(tc_mem, memcmp_binary_data);
  tcase_add_test(tc_mem, memcmp_null_vs_char);

  tcase_add_test(tc_mem, memcpy_standard_copy);
  tcase_add_test(tc_mem, memcpy_partial_copy);
  tcase_add_test(tc_mem, memcpy_copy_null_bytes);
  tcase_add_test(tc_mem, memcpy_return_value);
  tcase_add_test(tc_mem, memcpy_n_zero);
  tcase_add_test(tc_mem, memcpy_large_data);
  tcase_add_test(tc_mem, memcpy_source_shorter);

  tcase_add_test(tc_mem, memset_standard_char);
  tcase_add_test(tc_mem, memset_null_byte);
  // tcase_add_test(tc_mem, memset_n_zero);
  tcase_add_test(tc_mem, memset_full_buffer);
  tcase_add_test(tc_mem, memset_integer_c_masking);
  tcase_add_test(tc_mem, memset_return_value);
  suite_add_tcase(s, tc_mem);

  TCase* tc_str_util = tcase_create("String_Utility_Functions");
  tcase_add_test(tc_str_util, strncat_standard);
  tcase_add_test(tc_str_util, strncat_limit_n);
  tcase_add_test(tc_str_util, strncat_n_too_large);
  tcase_add_test(tc_str_util, strncat_n_zero);
  tcase_add_test(tc_str_util, strncat_empty_src);
  tcase_add_test(tc_str_util, strncat_empty_dest);
  tcase_add_test(tc_str_util, strncat_return_value);

  tcase_add_test(tc_str_util, strncpy_truncate);
  tcase_add_test(tc_str_util, strncpy_exact_copy);
  tcase_add_test(tc_str_util, strncpy_with_padding);
  tcase_add_test(tc_str_util, strncpy_empty_src_padding);
  // tcase_add_test(tc_str_util, strncpy_n_zero);
  tcase_add_test(tc_str_util, strncpy_copy_full_size);
  tcase_add_test(tc_str_util, strncpy_return_value);

  tcase_add_test(tc_str_util, strlen_standard);
  tcase_add_test(tc_str_util, strlen_empty);
  tcase_add_test(tc_str_util, strlen_long);
  tcase_add_test(tc_str_util, strlen_with_spaces);
  tcase_add_test(tc_str_util, strlen_embedded_null);

  tcase_add_test(tc_str_util, strncmp_equal);
  tcase_add_test(tc_str_util, strncmp_s1_less);
  tcase_add_test(tc_str_util, strncmp_s1_greater);
  tcase_add_test(tc_str_util, strncmp_difference_beyond_n);
  tcase_add_test(tc_str_util, strncmp_s1_shorter);
  tcase_add_test(tc_str_util, strncmp_s2_shorter);
  tcase_add_test(tc_str_util, strncmp_n_zero);
  suite_add_tcase(s, tc_str_util);

  TCase* tc_str_search = tcase_create("String_Search_Functions");
  tcase_add_test(tc_str_search, strchr_standard_hit);
  tcase_add_test(tc_str_search, strchr_null_terminator);
  tcase_add_test(tc_str_search, strchr_not_found);
  tcase_add_test(tc_str_search, strchr_at_start);
  tcase_add_test(tc_str_search, strchr_case_sensitive);
  tcase_add_test(tc_str_search, strchr_in_empty);

  tcase_add_test(tc_str_search, strrchr_standard);
  tcase_add_test(tc_str_search, strrchr_not_found);
  tcase_add_test(tc_str_search, strrchr_null_terminator);
  tcase_add_test(tc_str_search, strrchr_single_occurrence);
  tcase_add_test(tc_str_search, strrchr_in_empty_for_char);
  tcase_add_test(tc_str_search, strrchr_in_empty_for_null);

  tcase_add_test(tc_str_search, strcspn_standard);
  tcase_add_test(tc_str_search, strcspn_no_match);
  tcase_add_test(tc_str_search, strcspn_hit_at_start);
  tcase_add_test(tc_str_search, strcspn_empty_accept);
  tcase_add_test(tc_str_search, strcspn_empty_str1);
  tcase_add_test(tc_str_search, strcspn_null_byte);

  tcase_add_test(tc_str_search, strpbrk_standard);
  tcase_add_test(tc_str_search, strpbrk_first_char_wins);
  tcase_add_test(tc_str_search, strpbrk_no_match);
  tcase_add_test(tc_str_search, strpbrk_match_at_start);
  tcase_add_test(tc_str_search, strpbrk_match_at_end);
  tcase_add_test(tc_str_search, strpbrk_empty_str2);
  tcase_add_test(tc_str_search, strpbrk_empty_str1);

  tcase_add_test(tc_str_search, strstr_standard);
  tcase_add_test(tc_str_search, strstr_at_start);
  tcase_add_test(tc_str_search, strstr_at_end);
  tcase_add_test(tc_str_search, strstr_no_match);
  tcase_add_test(tc_str_search, strstr_empty_needle);
  tcase_add_test(tc_str_search, strstr_empty_haystack);
  tcase_add_test(tc_str_search, strstr_case_sensitive);
  suite_add_tcase(s, tc_str_search);

  TCase* tc_strtok = tcase_create("Strtok_Stateful_Tests");
  tcase_add_test(tc_strtok, strtok_first_call);
  tcase_add_test(tc_strtok, strtok_second_call);
  tcase_add_test(tc_strtok, strtok_null_return);
  tcase_add_test(tc_strtok, strtok_consecutive_delimiters);
  tcase_add_test(tc_strtok, strtok_delimiters_at_start);
  tcase_add_test(tc_strtok, strtok_delimiters_at_end);
  tcase_add_test(tc_strtok, strtok_all_delimiters);
  tcase_add_test(tc_strtok, strtok_multiple_delimiters_set);
  tcase_add_test(tc_strtok, strtok_null_input_empty_delim);
  tcase_add_test(tc_strtok, strtok_reinit);
  suite_add_tcase(s, tc_strtok);

  TCase* tc_strerror = tcase_create("Strerror_Tests");
  tcase_add_test(tc_strerror, strerror_zero);
  tcase_add_test(tc_strerror, strerror_eperm);
  tcase_add_test(tc_strerror, strerror_enoent);
  tcase_add_test(tc_strerror, strerror_efault);
  tcase_add_test(tc_strerror, strerror_high_valid);
  tcase_add_test(tc_strerror, strerror_out_of_bounds_positive);
  tcase_add_test(tc_strerror, strerror_out_of_bounds_negative);
  tcase_add_test(tc_strerror, strerror_consistency);
  suite_add_tcase(s, tc_strerror);

  // C# string manipulation functions
  TCase* tc_csharp = tcase_create("C#_String_Functions");

  // to_upper tests
  tcase_add_test(tc_csharp, test_to_upper_basic);
  tcase_add_test(tc_csharp, test_to_upper_mixed_case);
  tcase_add_test(tc_csharp, test_to_upper_null_input);
  tcase_add_test(tc_csharp, test_to_upper_empty_string);
  tcase_add_test(tc_csharp, test_to_upper_no_change);

  // to_lower tests
  tcase_add_test(tc_csharp, test_to_lower_basic);
  tcase_add_test(tc_csharp, test_to_lower_mixed_case);
  tcase_add_test(tc_csharp, test_to_lower_null_input);

  // insert tests
  tcase_add_test(tc_csharp, test_insert_basic);
  tcase_add_test(tc_csharp, test_insert_middle);
  tcase_add_test(tc_csharp, test_insert_beginning);
  tcase_add_test(tc_csharp, test_insert_empty_string);
  tcase_add_test(tc_csharp, test_insert_null_input);
  tcase_add_test(tc_csharp, test_insert_index_out_of_bounds);

  // trim tests
  tcase_add_test(tc_csharp, test_trim_basic);
  tcase_add_test(tc_csharp, test_trim_multiple_chars);
  tcase_add_test(tc_csharp, test_trim_all_trimmed);
  tcase_add_test(tc_csharp, test_trim_no_trim_chars);
  tcase_add_test(tc_csharp, test_trim_null_input);
  tcase_add_test(tc_csharp, test_trim_empty_string);
  tcase_add_test(tc_csharp, test_trim_middle_unchanged);
  tcase_add_test(tc_csharp, test_trim_default_whitespace);
  suite_add_tcase(s, tc_csharp);

  TCase* tc_sprintf = tcase_create("Sprintf");
  // Section 1: Basic Types
  tcase_add_test(tc_sprintf, test_1_basic_string);
  tcase_add_test(tc_sprintf, test_2_basic_int_positive);
  tcase_add_test(tc_sprintf, test_3_basic_int_negative);
  tcase_add_test(tc_sprintf, test_4_basic_char);
  tcase_add_test(tc_sprintf, test_5_multiple_args);
  tcase_add_test(tc_sprintf, test_6_unsigned_int);
  tcase_add_test(tc_sprintf, test_7_octal);
  tcase_add_test(tc_sprintf, test_8_hex_lower);

  // Section 2: Floating Point Specifiers
  tcase_add_test(tc_sprintf, test_9_float_f_default_precision);
  tcase_add_test(tc_sprintf, test_10_float_f_precision_2);
  tcase_add_test(tc_sprintf, test_11_float_f_precision_0);
  tcase_add_test(tc_sprintf, test_12_float_e_basic);
  tcase_add_test(tc_sprintf, test_13_float_E_uppercase);
  tcase_add_test(tc_sprintf, test_14_float_g_short_rep);
  tcase_add_test(tc_sprintf, test_15_float_G_with_precision);
  tcase_add_test(tc_sprintf, test_16_float_f_hash_flag);
  tcase_add_test(tc_sprintf, test_17_float_g_hash_flag);
  tcase_add_test(tc_sprintf, test_18_float_f_plus_flag);

  // Section 3: Flags and Width/Precision
  tcase_add_test(tc_sprintf, test_19_width_int);
  tcase_add_test(tc_sprintf, test_20_width_string);
  tcase_add_test(tc_sprintf, test_21_left_align);
  tcase_add_test(tc_sprintf, test_22_zero_padding);
  tcase_add_test(tc_sprintf, test_23_precision_int_expand);
  tcase_add_test(tc_sprintf, test_24_precision_string_truncate);
  tcase_add_test(tc_sprintf, test_25_width_precision_int);
  tcase_add_test(tc_sprintf, test_26_width_precision_string);
  tcase_add_test(tc_sprintf, test_27_flag_plus_positive);
  tcase_add_test(tc_sprintf, test_28_flag_space);
  tcase_add_test(tc_sprintf, test_29_flag_hash_octal);
  tcase_add_test(tc_sprintf, test_30_flag_hash_hex_upper);
  tcase_add_test(tc_sprintf, test_31_mixed_flags_plus_minus);
  tcase_add_test(tc_sprintf, test_32_zero_padding_negative);
  // tcase_add_test(tc_sprintf, test_33_left_align_overrides_zero_pad);

  // Section 4: Length Modifiers
  tcase_add_test(tc_sprintf, test_34_long_decimal_l);
  // tcase_add_test(tc_sprintf, test_35_long_long_decimal);
  tcase_add_test(tc_sprintf, test_36_unsigned_long);
  tcase_add_test(tc_sprintf, test_37_short_int);
  tcase_add_test(tc_sprintf, test_38_short_hex);
  // tcase_add_test(tc_sprintf, test_39_long_long_unsigned_octal);
  tcase_add_test(tc_sprintf, test_40_long_double_L_basic);
  tcase_add_test(tc_sprintf, test_41_long_double_L_precision);
  // tcase_add_test(tc_sprintf, test_42_length_l_string);
  // tcase_add_test(tc_sprintf, test_43_length_l_char);

  // Section 5: Dynamic Width/Precision and Edge Cases
  tcase_add_test(tc_sprintf, test_44_dynamic_width);
  tcase_add_test(tc_sprintf, test_45_dynamic_precision_int);
  tcase_add_test(tc_sprintf, test_46_dynamic_width_precision_string);
  tcase_add_test(tc_sprintf, test_47_dynamic_width_float);
  tcase_add_test(tc_sprintf, test_48_dynamic_negative_width);
  tcase_add_test(tc_sprintf, test_49_width_zero_value);
  tcase_add_test(tc_sprintf, test_50_precision_zero_int_zero_val);
  tcase_add_test(tc_sprintf, test_51_precision_zero_int_non_zero);
  // tcase_add_test(tc_sprintf, test_52_null_string);
  tcase_add_test(tc_sprintf, test_53_pointer);
  tcase_add_test(tc_sprintf, test_54_pointer_null);
  tcase_add_test(tc_sprintf, test_55_percent_sign);
  tcase_add_test(tc_sprintf, test_56_hash_flag_on_zero_hex);
  // tcase_add_test(tc_sprintf, test_57_i_specifier_hex_input);

  // Section 6: Advanced Combinations (new tests)
  tcase_add_test(tc_sprintf, test_60_hex_full_combo);
  tcase_add_test(tc_sprintf, test_61_octal_zero_precision);
  tcase_add_test(tc_sprintf, test_62_pointer_width);
  tcase_add_test(tc_sprintf, test_63_string_left_align_precision);
  tcase_add_test(tc_sprintf, test_64_string_zero_precision);
  tcase_add_test(tc_sprintf, test_65_unsigned_precision_width);
  tcase_add_test(tc_sprintf, test_66_dynamic_precision_zero);
  tcase_add_test(tc_sprintf, test_67_char_width_left);
  tcase_add_test(tc_sprintf, test_68_d_space_zero_padding);
  tcase_add_test(tc_sprintf, test_69_float_L_width_precision);
  // tcase_add_test(tc_sprintf, test_70_n_with_long_long_placement);

  suite_add_tcase(s, tc_sprintf);
  return s;
}

int main() {
  int number_failed;
  Suite* s = my_string_suite();
  SRunner* sr = srunner_create(s);

  srunner_run_all(sr, CK_NORMAL);

  number_failed = srunner_ntests_failed(sr);
  srunner_free(sr);

  return (number_failed == 0) ? 0 : 1;
}
