#include "arg_parsing.h"

#include <errno.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <unistd.h>

#include "my_string.h"

int argParse(int argc, char *const *argv, const char *shortopts, int *options,
             char **optarg_buf[], int *optarg_c) {
  int opt = 0;
  int invalFlag = 0;
  while ((opt = getopt(argc, argv, shortopts)) != -1 && invalFlag == 0)
    switch (opt) {
      case 'e':
        if (optarg) {
          if (((*optarg_buf)[*optarg_c] =
                   calloc(my_strlen(optarg) + 1, sizeof(char)))) {
            my_strcpy((*optarg_buf)[*optarg_c], optarg);
            (*optarg_c)++;
          } else
            // memory allocation failed
            invalFlag++;
        }
        options[ASCII_INDEX(opt)] = 1;
        break;
      case 'a':
      case 'A':
      case 'b':
      case 'B':
      case 'c':
      case 'C':
      case 'd':
      case 'D':
      case 'E':
      case 'f':
      case 'F':
      case 'g':
      case 'G':
      case 'h':
      case 'H':
      case 'i':
      case 'I':
      case 'j':
      case 'J':
      case 'k':
      case 'K':
      case 'l':
      case 'L':
      case 'm':
      case 'M':
      case 'n':
      case 'N':
      case 'o':
      case 'O':
      case 'p':
      case 'P':
      case 'q':
      case 'Q':
      case 'r':
      case 'R':
      case 's':
      case 'S':
      case 't':
      case 'T':
      case 'u':
      case 'U':
      case 'v':
      case 'V':
      case 'w':
      case 'W':
      case 'x':
      case 'X':
      case 'y':
      case 'Y':
      case 'z':
      case 'Z':
        options[ASCII_INDEX(opt)] = 1;
        break;
      default:
        invalFlag++;
        break;
    }
  return invalFlag;
}

int openFile(char *filename, FILE **fp, const char *programname,
             const int silent) {
  int flag = errno = 0;
  struct stat st;
  if (stat(filename, &st) != 0) {
    if (errno == ENOENT) {
      flag = ENOENT;
      if (!silent)
        fprintf(stderr, "%s: %s: No such file or directory\n", programname,
                filename);
    } else if (errno == EACCES) {
      if (!silent)
        fprintf(stderr, "%s: %s: Permission denied\n ", programname, filename);
      flag = EACCES;
    } else {
      if (!silent) fprintf(stderr, "%s: *Stat failed", programname);
      flag = 1;
    }
  } else {
    if (S_ISDIR(st.st_mode)) {
      if (!silent)
        fprintf(stderr, "%s: %s: Is a directory\n", programname, filename);
      flag = EISDIR;
    } else {
      *fp = fopen(filename, "r");
      if (errno == EACCES) {
        if (!silent)
          fprintf(stderr, "%s: %s: Permission denied\n", programname, filename);
        flag = EACCES;
      }
    }
  }
  return flag;
}

void debug_msg() { fprintf(stderr, "DEBUG: "); }
