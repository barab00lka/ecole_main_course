#include <stdlib.h>
#include <unistd.h>

#include "../common/arg_parsing.h"
#include "../common/my_string.h"
#include "my_grep.h"
#define PARAMS "e:ivclnhs"

int main(int argc, char *argv[]) {
  int options[52] = {0};
  int re_c = 0;

  char **regstring_buf = calloc(argc / 2, sizeof(char *));
  if (regstring_buf == NULL) exit(1);

  int invalFlag = argParse(argc, argv, PARAMS, options, &regstring_buf, &re_c);

  if (invalFlag || (!argv[optind] && !options[ASCII_INDEX('e')])) {
    print_usage();
  } else {
    if (optind == argc) {
      linerep(stdin, "(standard input)", re_c,
              (const char *const *)regstring_buf, options, argc - optind);
    } else {
      FILE *fp = NULL;
      if (options[ASCII_INDEX('e')] == 0 && argv[optind]) {
        regstring_buf[re_c] =
            calloc(my_strlen(argv[optind]) + 1, sizeof(char));
        my_strcpy(regstring_buf[re_c++], argv[optind++]);
      }
      for (int i = optind; i < argc; i++) {
        if (openFile(argv[i], &fp, argv[0], options[ASCII_INDEX('s')]) == 0) {
          linerep(fp, argv[i], re_c, (const char *const *)regstring_buf,
                  options, argc - optind);
          fclose(fp);
        }
      }
    }
  }
  free_buffer(&regstring_buf, re_c);
  return 0;
}
