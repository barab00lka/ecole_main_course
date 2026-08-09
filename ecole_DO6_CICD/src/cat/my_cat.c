#include "my_cat.h"

#include <stdio.h>
#include <sys/stat.h>
#include <unistd.h>

#include "../common/arg_parsing.h"

void cat(FILE *fp, const int *arguments, int *lineCount) {
  if (fp) {
    if (arguments[ASCII_INDEX('b')])
      catNumberNonBlank(fp, lineCount);
    else if (arguments[ASCII_INDEX('n')])
      catNumber(fp, lineCount);
    else if (arguments[ASCII_INDEX('e')])
      catShowEnds(fp);
    else if (arguments[ASCII_INDEX('t')])
      catShowTabs(fp);
    else if (arguments[ASCII_INDEX('s')])
      catSqueeze(fp);
    else if (arguments[ASCII_INDEX('E')])
      catShowEndswNonPrint(fp);
    else if (arguments[ASCII_INDEX('T')])
      catShowTabswNonPrint(fp);
    else if (arguments[ASCII_INDEX('v')])
      catShowNonPrint(fp);
    else
      catConcat(fp);
    if (fp != stdin) fclose(fp);
  }
}

void catConcat(FILE *fp) {
  int ch = EOF;
  while ((ch = fgetc(fp)) != EOF) {
    putchar(ch);
  }
}

void catNumber(FILE *fp, int *lineCount) {
  int ch = EOF;
  int lineStart = 1;
  while ((ch = fgetc(fp)) != EOF) {
    if (lineStart) {
      printf("%6d\t", ++(*lineCount));
      lineStart = 0;
    }
    putchar(ch);
    if (ch == '\n' || ch == '\r') {
      lineStart = 1;
    }
  }
}

void catNumberNonBlank(FILE *fp, int *lineCount) {
  int ch = EOF;
  int lineStart = 1;
  while ((ch = fgetc(fp)) != EOF) {
    if (lineStart && ch != '\r' && ch != '\n') {
      printf("%6d\t", ++(*lineCount));
      lineStart = 0;
    }
    putchar(ch);
    if (ch == '\n' || ch == '\r') {
      lineStart = 1;
    }
  }
}

void catShowEndswNonPrint(FILE *fp) {
  int ch = EOF;
  while ((ch = fgetc(fp)) != EOF) {
    if (ch == '\r' || ch == '\n') putchar('$');
    putchar(ch);
  }
}

void catShowEnds(FILE *fp) {
  int c = EOF;
  while ((c = fgetc(fp)) != EOF) {
    if (c < 32 && c != '\t' && c != '\n') {
      printf("^%c", c + 64);
      //} else if (c == '\n' || c == '\r') { for Windows systems
    } else if (c == '\n') {
      printf("$%c", c);
    } else if (c > 127 && c < 160) {
      printf("M-^%c", c - 64);
    } else if (c >= 160) {
      printf("M-%c", c - 128);
    } else if (c == 127) {
      printf("^?");
    } else {
      printf("%c", c);
    }
  }
}

void catSqueeze(FILE *fp) {
  int ch = EOF;
  int lineStart = 1;
  while ((ch = fgetc(fp)) != EOF) {
    if (lineStart && ch != '\r' && ch != '\n') {
      lineStart = 0;
    }
    if (lineStart < 2) putchar(ch);
    if (ch == '\n' || ch == '\r') {
      lineStart += 1;
    }
  }
}

void catShowTabswNonPrint(FILE *fp) {
  int ch = EOF;
  while ((ch = fgetc(fp)) != EOF) {
    if (ch == '\t')
      printf("^I");
    else
      putchar(ch);
  }
}

void catShowTabs(FILE *fp) {
  int c = EOF;
  while ((c = fgetc(fp)) != EOF) {
    if (c < 32 && c != '\t' && c != '\n') {
      printf("^%c", c + 64);
    } else if (c == '\t') {
      printf("^I");
    } else if (c > 127 && c < 160) {
      printf("M-^%c", c - 64);
    } else if (c >= 160) {
      printf("M-%c", c - 128);
    } else if (c == 127) {
      printf("^?");
    } else {
      printf("%c", c);
    }
  }
}

void catShowNonPrint(FILE *fp) {
  int c = EOF;
  while ((c = fgetc(fp)) != EOF) {
    if (c < 32 && c != '\t' && c != '\n') {
      printf("^%c", c + 64);
    } else if (c > 127 && c < 160) {
      printf("M-^%c", c - 64);
    } else if (c >= 160) {
      printf("M-%c", c - 128);
    } else if (c == 127) {
      printf("^?");
    } else {
      printf("%c", c);
    }
  }
}
