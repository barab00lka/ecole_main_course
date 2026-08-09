#ifndef MY_GREP_H_
#define MY_GREP_H_
#include <stdio.h>
void print_usage();
int find_regex(const char *haystack, const int nregstring,
               const char *const *regstrings, const int *grep_options);
int linerep(FILE *fp, char *filename, const int nregstring,
            const char *const *regexs, const int *grep_options,
            const int filecount);
int grep_prints(const int *grep_options, char *filename, char *line,
                const int line_count, const int filecount);
void free_buffer(char ***buf, int nreg);
#endif
