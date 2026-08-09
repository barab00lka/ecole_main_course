#include "my_string.h"

#include <stdio.h>
#include <stdlib.h>
#define MATCH 1
#define NO_MATCH 0

unsigned int my_strlen(const char *string) {
  unsigned int i = 0;
  while (string[i] != '\0') i++;
  return i;
}

int my_strcmp(const char *string1, const char *string2) {
  for (; *string1 && *string2 && *string1 == *string2; string1++, string2++);
  return *string1 - *string2;
}

char *my_strcpy(char *dst, const char *src) {
  int i = 0;
  for (; src[i] != '\0'; i++) dst[i] = src[i];
  dst[i] = '\0';
  return dst;
}

char *my_strcat(char *string1, const char *string2) {
  int i = 0;
  for (; string1[i] != '\0'; i++);
  int j = 0;
  string1[i++] = string2[j];
  for (j = 1; string2[j] != '\0'; j++, i++) string1[i] = string2[j];
  string1[i] = '\0';
  return string1;
}

char *my_strchr(const char *string, int c) {
  while (*string && *string != c) string++;
  return (*string == c) ? (char *)string : NULL;
}

char *my_strstr(const char *hay, const char *needle) {
  const char *ptr = hay;
  if (*needle) {
    unsigned int flag = 0;
    for (; *hay && flag != my_strlen(needle); hay++) {
      const char *needle0 = needle;
      if (*hay == *needle) {
        flag += 1;
        do {
          hay++;
          needle++;
          if (*hay == *needle) flag++;
        } while (*hay == *needle && *needle && flag != my_strlen(needle));
        needle = needle0;
        if (flag != my_strlen(needle)) flag = 0;
      }
    }
    flag == 0 ? ptr = NULL : (ptr = hay - flag - 1);
  }
  return (char *)ptr;
}

char *my_strtok(char *str, const char *sep) {
  static char *olds;
  if (str == NULL) str = olds;
  unsigned int i = 0;
  for (; i < my_strlen(str); i++) {
    for (int j = 0; sep[j] != '\0' && str[i] != '\0'; j++) {
      if (str[i] == sep[j]) str[i] = '\0';
    }
  }
  olds = (str + i + 1);
  return str;
}
