#include <unistd.h>

#include "../common/arg_parsing.h"
#include "my_cat.h"
#define PARAMS "benstETv"

int main(int argc, char *argv[]) {
  int arguments[52] = {0};
  int lineCount = 0;
  FILE *fp = NULL;
  if (argParse(argc, argv, PARAMS, arguments, NULL, 0) == 0) {
    if (optind >= argc) {
      cat(stdin, arguments, &lineCount);
    } else {
      for (int i = optind; i < argc; i++) {
        openFile(argv[i], &fp, argv[0], 0);
        cat(fp, arguments, &lineCount);
      }
    }
  }
  return 0;
}
