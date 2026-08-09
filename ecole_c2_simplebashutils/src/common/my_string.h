#ifndef MY_STRING_H_
#define MY_STRING_H_

unsigned int my_strlen(const char* string);
int my_strcmp(const char* string1, const char* string2);
char* my_strcpy(char* dst, const char* src);
char* my_strcat(char* string1, const char* string2);
char* my_strchr(const char* string, int c);
char* my_strstr(const char* hay, const char* needle);
char* my_strtok(char* str, const char* sep);

#endif
