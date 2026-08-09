#include "test_me.h"

int main(void) {
  int failed = 0;
  Suite* my_string_test[] = {test_insert(),
                              test_memchr(),
                              test_memcpy(),
                              test_memcmp(),
                              test_memset(),
                              test_strchr(),
                              test_strerror(),
                              test_strcspn(),
                              test_strlen(),
                              test_strncat(),
                              test_strncmp(),
                              test_strncpy(),
                              test_strpbrk(),
                              test_strrchr(),
                              test_strstr(),
                              test_strtok(),
                              test_to_lower(),
                              test_to_upper(),
                              test_trim(),
                              test_sprintf_octal(),
                              test_sprintf_percent(),
                              test_sprintf_unsigned(),
                              test_sprintf_HEX(),
                              test_sprintf_hex(),
                              test_sprintf_pointer(),
                              test_sprintf_signed(),
                              test_sprintf_e(),
                              test_sprintf_f(),
                              test_sprintf_g(),
                              test_sprintf_c(),
                              test_sprintf_string(),
                              NULL};

  for (int i = 0; my_string_test[i] != NULL; i++) {  // (&& failed == 0)
    SRunner* sr = srunner_create(my_string_test[i]);

    srunner_set_fork_status(sr, CK_NOFORK);
    srunner_run_all(sr, CK_NORMAL);

    failed += srunner_ntests_failed(sr);
    srunner_free(sr);
  }
  printf("========= FAILED: %d =========\n", failed);

  return failed == 0 ? 0 : 1;
}
