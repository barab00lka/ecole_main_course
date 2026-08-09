#ifndef MY_CAT_H_
#define MY_CAT_H_
#include <stdio.h>
void cat(FILE *fp, const int *arguments, int *lineCount);
void catConcat(FILE *fp);
void catNumberNonBlank(FILE *fp, int *lineCount);
void catShowNonPrint(FILE *fp);
void catShowEnds(FILE *fp);
void catShowEndswNonPrint(FILE *fp);
void catNumber(FILE *fp, int *lineCount);
void catSqueeze(FILE *fp);
void catShowTabs(FILE *fp);
void catShowTabswNonPrint(FILE *fp);

#endif
