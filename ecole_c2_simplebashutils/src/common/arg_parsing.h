#ifndef ARG_PARSING_H_
#define ARG_PARSING_H_
#define ASCII_INDEX(ch) \
  (((ch) >= 'a' && (ch) <= 'z') ? ((ch) - 'a') : ((ch) - 'A' + 26))
#include <stdio.h>

void debug_msg();
int argParse(int argc, char *const *argv, const char *shortopts, int *options,
             char ***optarg_buf, int *optarg_c);
int openFile(char *filename, FILE **fp, const char *programname,
             const int silent);

#endif
