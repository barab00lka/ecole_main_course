#include <stdlib.h>
#include <string.h>
#include <unistd.h>

#include "../common/arg_parsing.h"
#include "my_grep.h"
#define PARAMS "e:ivclnhs"

void free_buffer(char ***buf, int nreg);

int main(int argc, char *argv[]) {
  int options[52] = {0};
  int re_c = 0;

  char **regstring_buf = calloc(argc / 2, sizeof(char *));
  if (regstring_buf == NULL) exit(1);

  // // debug
  // debug_msg();
  // printf("BEFORE argParse! argv[optind]: %s\nargc: %i\noptind: %i\n\n",
  //        argv[optind], argc, optind);
  // debug_msg();

  // for (int i = optind; i < argc; i++) {
  //   debug_msg();
  //   printf("argv[%i]:%s\n", i, argv[i]);
  // }
  // debug

  int invalFlag = argParse(argc, argv, PARAMS, options, &regstring_buf, &re_c);

  // debug
  // debug_msg();
  // printf("AFTER argParse! argv[optind]: %s\nargc: %i\noptind: %i\n\n",
  //       argv[optind], argc, optind);
  // debug_msg();
  // for (int i = optind; i < argc; i++) {
  //  debug_msg();
  //  printf("argv[%i]:%s\n", i, argv[i]);
  //}
  // debug

  if (invalFlag || (!argv[optind] && !options[ASCII_INDEX('e')])) {
    print_usage();
  } else {
    if (optind == argc) {
      // debug_msg();
      // printf("(standard input)\n");
      linerep(stdin, "(standard input)", re_c,
              (const char *const *)regstring_buf, options, argc - optind);

    }

    else {
      FILE *fp = NULL;
      if (options[ASCII_INDEX('e')] == 0 && argv[optind]) {
        // if (options[ASCII_INDEX('e')]) {
        regstring_buf[re_c] = calloc(strlen(argv[optind]) + 1, sizeof(char));
        strcpy(regstring_buf[re_c++], argv[optind++]);
      }

      for (int i = optind; i < argc; i++) {
        if (openFile(argv[i], &fp, argv[0], options[ASCII_INDEX('s')]) == 0) {
          int linerep_res =
              linerep(fp, argv[i], re_c, (const char *const *)regstring_buf,
                      options, argc - optind);
          linerep_res += 1;
          fclose(fp);
        }
      }
    }
  }
  free_buffer(&regstring_buf, re_c);

  return 0;
}

void free_buffer(char ***buf, int nreg) {
  if (buf == NULL || *buf == NULL) {
    return;
  }
  for (int j = 0; j < nreg; j++) {
    free((*buf)[j]);
  }
  free(*buf);
}
