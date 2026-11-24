#include "my_grep.h"

#include <regex.h>
#include <stdlib.h>

#include "../common/arg_parsing.h"

int find_regex(const char *haystack, const int nregstring,
               const char *const *regstrings, const int *grep_options) {
  int result_of_search = 1;
  int cflag = REG_NEWLINE;  // REG_NEWLINE == 4
  if (grep_options[ASCII_INDEX('i')])
    cflag |= REG_ICASE;  // REG_NEWLINE | REG_ICASE bitwise operation
  regex_t regex[nregstring];
  regmatch_t pmatch[nregstring];

  for (int i = 0; i < nregstring; i++)
    if (regcomp(&regex[i], regstrings[i], cflag)) return 1;

  for (int i = 0; i < nregstring; i++) {
    result_of_search *=
        regexec(&regex[i], haystack, regex[i].re_nsub + 1, &pmatch[i], 0);
  }

  for (int i = 0; i < nregstring; i++) regfree(&regex[i]);

  return result_of_search;
}

int linerep(FILE *fp, char *filename, const int nregstring,
            const char *const *regexs, const int *grep_options,
            const int filecount) {
  int string_with_matches = 0;
  int lc = 1;
  char line[8192];

  for (; fgets(line, 8191 + 1, fp) != NULL; lc++) {
    if (find_regex(line, nregstring, regexs, grep_options) == 0) {
      /* not inverted!!*/
      if (grep_options[ASCII_INDEX('c')]) string_with_matches++;
      // else {
      if (!grep_options[ASCII_INDEX('v')]) {
        if (grep_prints(grep_options, filename, line, lc, filecount)) break;
      }
      //}
    }
    /* inverted (-v)!!!*/
    else if (grep_options[ASCII_INDEX('v')]) {
      if (grep_prints(grep_options, filename, line, lc, filecount)) break;
    }
  }
  if (grep_options[ASCII_INDEX('v')])
    string_with_matches = (lc - 1) - string_with_matches;
  if (grep_options[ASCII_INDEX('c')] && !grep_options[ASCII_INDEX('l')]) {
    if (filecount > 1 && !grep_options[ASCII_INDEX('h')]) {
      printf("%s:", filename);
    }
    printf("%d\n", string_with_matches);
  }
  return string_with_matches;
}

void print_usage() { printf("Usage: grep [OPTION]... PATTERNS [FILE]...\n"); }

int grep_prints(const int *grep_options, char *filename, char *line,
                const int line_count, const int filecount) {
  int only_match_files = 0;
  if (grep_options[ASCII_INDEX('l')]) {
    printf("%s\n", filename);
    only_match_files++;
  } else if (!grep_options[ASCII_INDEX('c')]) {
    if (filecount > 1 && !grep_options[ASCII_INDEX('h')] &&
        !grep_options[ASCII_INDEX('l')] && !grep_options[ASCII_INDEX('c')])
      printf("%s:", filename);
    if (grep_options[ASCII_INDEX('n')]) printf("%d:", line_count);
    for (int i = 0; line[i] != '\0' && line[i] != '\n'; i++) putchar(line[i]);
    putchar('\n');
  }
  return only_match_files;
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
