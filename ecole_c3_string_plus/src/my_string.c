#include "my_string.h"

#include <math.h>
#include <stdlib.h>

#define ABS(value) (value < 0) ? -value : value
#define GET_DECIMAL(value, length)          \
  do {                                      \
    if (length == 'h')                      \
      value = (short int)va_arg(args, int); \
    else if (length == 'l')                 \
      value = va_arg(args, long int);       \
    else                                    \
      value = va_arg(args, int);            \
  } while (0)

#define GET_UNSIGNED(value, length)                       \
  do {                                                    \
    if (length == 'h')                                    \
      value = (unsigned short)va_arg(args, unsigned int); \
    else if (length == 'l')                               \
      value = va_arg(args, unsigned long);                \
    else                                                  \
      value = va_arg(args, unsigned int);                 \
  } while (0)

#ifdef __linux__
#define NULL_POINTER_ASCII_STRING \
  do {                            \
    prefix[0] = 0;                \
    val_str[0] = '(';             \
    val_str[1] = 'n';             \
    val_str[2] = 'i';             \
    val_str[3] = 'l';             \
    val_str[4] = ')';             \
    val_str[5] = '\0';            \
  } while (0)

#elif defined __APPLE__
#define NULL_POINTER_ASCII_STRING \
  do {                            \
    prefix[0] = 0;                \
    val_str[0] = '0';             \
    val_str[1] = 'x';             \
    val_str[2] = '0';             \
    val_str[3] = '\0';            \
  } while (0)

#endif

#define HEXADECIMAL_BASE 16
#define DECIMAL_BASE 10
#define OCTAL_BASE 8
#define MAX_LEN_VAL_STR 2000

#define IS_UNSIGNED 1
#define IS_SIGNED 0
#define SHORT_FORM 1
#define NOT_SHORT_FORM 0
#define NOT_ALTER_FORM 0

#define FLAG_LEFT_JUSTIFY (1 << 0)
#define FLAG_FORCE_SIGN (1 << 1)
#define FLAG_BLANK_POSITIVE (1 << 2)
#define FLAG_ALTERNATE_FORM (1 << 3)
#define FLAG_ZEROPAD (1 << 4)

#define AS_ARGUMENT_WIDTH -1
#define AS_ARGUMENT_PREC -1
#define PRECISION_NOT_SPEC -2
#define FLOATING_DEFAULT_PREC 6

void* my_memchr(const void* str, int c, my_size_t n) {
  my_size_t i = 0;
  while (i < n && ((unsigned char*)str)[i] != c) i++;

  return (i < n) ? &((unsigned char*)str)[i] : my_NULL;
}

int my_memcmp(const void* str1, const void* str2, my_size_t count) {
  int res;
  if (count) {
    while (--count && *((unsigned char*)str1) == *((unsigned char*)str2)) {
      str1 = (unsigned char*)str1 + 1;
      str2 = (unsigned char*)str2 + 1;
    }
    res = *((unsigned char*)str1) - *((unsigned char*)str2);
  } else {
    res = 0;
  }

  return res;
}

void* my_memcpy(void* dest, const void* src, my_size_t n) {
  my_size_t i = 0;

  for (; i < n; i++) ((unsigned char*)dest)[i] = ((unsigned char*)src)[i];

  return dest;
}

void* my_memset(void* str, int c, my_size_t n) {
  for (my_size_t i = 0; i < n; i++)
    ((unsigned char*)str)[i] = (unsigned char)c;

  return str;
}

my_size_t my_strlen(const char* str) {
  if (!str) return 0;

  const char* s;
  for (s = str; *s; ++s);
  return (s - str);
}

char* my_strncat(char* dest, const char* src, my_size_t n) {
  my_size_t idx_dest = 0;
  for (; dest[idx_dest] != '\0'; idx_dest++);

  my_size_t i = 0;
  for (; i < n && src[i] != '\0'; i++) dest[idx_dest + i] = src[i];

  dest[idx_dest + i] = 0;

  return dest;
}

char* my_strchr(const char* str, int c) {
  for (; *str != '\0' && *str != c; ++str);

  return *str == c ? (char*)str : my_NULL;
}

int my_strncmp(const char* str1, const char* str2, my_size_t n) {
  int res = 0;
  my_size_t i = 0;

  for (; i < n && str1[i] == str2[i] && str1[i] != 0; i++);

  if (i < n) {
    res = ((int)(unsigned char)str1[i]) - ((int)(unsigned char)str2[i]);
    if (res < 0)
      res = -1;
    else if (res > 0)
      res = 1;
  } else
    res = 0;

  return res;
}

char* my_strncpy(char* dest, const char* src, my_size_t n) {
  if (!dest || !src) return my_NULL;

  my_size_t i = 0;
  while (i < n && src[i] != '\0') {
    dest[i] = src[i];
    i++;
  }

  while (i < n) {
    dest[i] = '\0';
    i++;
  }

  return dest;
}

char* my_strpbrk(char* str1, const char* str2) {
  char* p1 = str1;
  int match_found = 0;

  while (*p1 != '\0' && match_found == 0) {
    const char* p2 = str2;

    while (*p2 != '\0' && *p1 != *p2) p2++;

    if (*p1 == *p2) match_found = 1;

    if (match_found == 0) p1++;
  }

  if (match_found == 0) p1 = my_NULL;

  return p1;
}

char* my_strrchr(const char* str, int c) {
  const char first_char = *str;
  for (; *str != '\0'; str++);
  for (; *str != c && *str != first_char; --str);

  return *str == c ? (char*)str : my_NULL;
}

char* my_strstr(const char* haystack, const char* needle) {
  char* result_ptr = my_NULL;

  if (*needle == 0) {
    result_ptr = (char*)haystack;
  } else {
    const char* h_ptr = haystack;

    while (*h_ptr != 0 && result_ptr == my_NULL) {
      const char* n_ptr;
      const char* h_start = h_ptr;
      n_ptr = needle;

      while (*h_ptr == *n_ptr && *h_ptr != 0 && *n_ptr != 0) {
        h_ptr++;
        n_ptr++;
      }

      if (*n_ptr == 0) result_ptr = (char*)h_start;

      if (result_ptr == my_NULL) h_ptr = h_start + 1;
    }
  }

  return result_ptr;
}

my_size_t my_strcspn(const char* str1, const char* str2) {
  const char* p1 = str1;
  my_size_t size = 0;
  int match_found = 0;

  while (*p1 != '\0' && match_found == 0) {
    const char* p2 = str2;

    while (*p2 != '\0' && *p1 != *p2) p2++;

    if (*p1 == *p2) match_found = 1;

    if (match_found == 0) {
      p1++;
      size++;
    }
  }

  return size;
}

// basically not inversed version of strcspn (stands for complemented span)
my_size_t my_strspn(const char* s, const char* accept) {
  const char* delim;
  int end_loop = 0;
  my_size_t size = 0;

  while (*s != '\0' && end_loop == 0) {
    for (delim = accept; *delim != '\0' && *s != *delim; delim++);

    if (*delim == '\0') {
      end_loop = 1;
    } else {
      size++;
    }

    s++;
  }

  return size;
}

char* my_strtok(char* str, const char* delim) {
  static char* pos;
  char* token = my_NULL;

  if (!delim) return my_NULL;

  if (str == my_NULL) str = pos;
  if (str == my_NULL || *str == '\0') {
    pos = my_NULL;
    return my_NULL;
  }

  str += my_strspn(str, delim);

  if (*str == '\0') {
    pos = my_NULL;
    return my_NULL;
  }

  token = str;

  str += my_strcspn(str, delim);

  if (*str != '\0') {
    *str = '\0';
    str++;
    pos = str;
  } else
    pos = my_NULL;

  return token;
}

void* my_to_upper(const char* str) {
  if (!str) return my_NULL;
  my_size_t string_length = my_strlen(str);
  char* new_string = malloc((string_length + 1) * sizeof(char));
  if (new_string) {
    my_size_t i = 0;
    for (; i < string_length; i++)
      new_string[i] =
          (str[i] >= 'a' && str[i] <= 'z') ? str[i] - 'a' + 'A' : str[i];
    new_string[i] = '\0';
  }
  return (void*)new_string;
}

void* my_to_lower(const char* str) {
  if (!str) return my_NULL;
  my_size_t string_length = my_strlen(str);
  char* new_string = malloc(string_length + 1 * sizeof(char));
  if (new_string) {
    my_size_t i = 0;
    for (; i < string_length; i++)
      new_string[i] =
          (str[i] >= 'A' && str[i] <= 'Z') ? str[i] - 'A' + 'a' : str[i];

    new_string[i] = '\0';
  }
  return (void*)new_string;
}

void* my_insert(const char* src, const char* str, size_t start_index) {
  if (!str || !src) return my_NULL;

  my_size_t src_len = my_strlen(src);
  if (start_index > src_len) return my_NULL;

  my_size_t str_len = my_strlen(str);
  my_size_t total_len = src_len + str_len;

  char* new_string = malloc((total_len + 1) * sizeof(char));
  if (new_string) {
    my_size_t n = 0;
    for (; n < start_index; n++) new_string[n] = src[n];
    for (my_size_t o = 0; o < str_len; o++, n++) new_string[n] = str[o];
    for (; n < total_len; n++) new_string[n] = src[n - str_len];
    new_string[n] = '\0';
  }
  return (void*)new_string;
}

void* my_trim(const char* src, const char* trim_chars) {
  if (!src) return my_NULL;

  const char* trim_set = my_NULL;
  if (!trim_chars)
    trim_set = " \t\n\r\f\v";
  else
    trim_set = trim_chars;

  my_size_t src_len = my_strlen(src);
  my_size_t start = 0;
  while (start < src_len && my_strchr(trim_set, src[start])) start++;

  my_size_t end = src_len;
  while (end > start && my_strchr(trim_set, src[end - 1])) end--;

  my_size_t res_len = end - start;
  char* result = malloc((res_len + 1) * sizeof(char));

  if (result) {
    for (my_size_t i = 0; i < res_len; i++) result[i] = src[start + i];

    result[res_len] = '\0';
  }

  return (void*)result;
}

/* strerror realization and error list definition.
 * Different errors for OS_X and linux */

#define ERR_STR_LEN 64

#ifdef __linux__
#define UNKNOWN_ERR_FMT "Unknown error %d"
#define ERR_LIST_SIZE 134
static const char errors_list[ERR_LIST_SIZE][ERR_STR_LEN] = {
    "Success",
    "Operation not permitted",
    "No such file or directory",
    "No such process",
    "Interrupted system call",
    "Input/output error",
    "No such device or address",
    "Argument list too long",
    "Exec format error",
    "Bad file descriptor",
    "No child processes",
    "Resource temporarily unavailable",
    "Cannot allocate memory",
    "Permission denied",
    "Bad address",
    "Block device required",
    "Device or resource busy",
    "File exists",
    "Invalid cross-device link",
    "No such device",
    "Not a directory",
    "Is a directory",
    "Invalid argument",
    "Too many open files in system",
    "Too many open files",
    "Inappropriate ioctl for device",
    "Text file busy",
    "File too large",
    "No space left on device",
    "Illegal seek",
    "Read-only file system",
    "Too many links",
    "Broken pipe",
    "Numerical argument out of domain",
    "Numerical result out of range",
    "Resource deadlock avoided",
    "File name too long",
    "No locks available",
    "Function not implemented",
    "Directory not empty",
    "Too many levels of symbolic links",
    "Unknown error 41",
    "No message of desired type",
    "Identifier removed",
    "Channel number out of range",
    "Level 2 not synchronized",
    "Level 3 halted",
    "Level 3 reset",
    "Link number out of range",
    "Protocol driver not attached",
    "No CSI structure available",
    "Level 2 halted",
    "Invalid exchange",
    "Invalid request descriptor",
    "Exchange full",
    "No anode",
    "Invalid request code",
    "Invalid slot",
    "Unknown error 58",
    "Bad font file format",
    "Device not a stream",
    "No data available",
    "Timer expired",
    "Out of streams resources",
    "Machine is not on the network",
    "Package not installed",
    "Object is remote",
    "Link has been severed",
    "Advertise error",
    "Srmount error",
    "Communication error on send",
    "Protocol error",
    "Multihop attempted",
    "RFS specific error",
    "Bad message",
    "Value too large for defined data type",
    "Name not unique on network",
    "File descriptor in bad state",
    "Remote address changed",
    "Can not access a needed shared library",
    "Accessing a corrupted shared library",
    ".lib section in a.out corrupted",
    "Attempting to link in too many shared libraries",
    "Cannot exec a shared library directly",
    "Invalid or incomplete multibyte or wide character",
    "Interrupted system call should be restarted",
    "Streams pipe error",
    "Too many users",
    "Socket operation on non-socket",
    "Destination address required",
    "Message too long",
    "Protocol wrong type for socket",
    "Protocol not available",
    "Protocol not supported",
    "Socket type not supported",
    "Operation not supported",
    "Protocol family not supported",
    "Address family not supported by protocol",
    "Address already in use",
    "Cannot assign requested address",
    "Network is down",
    "Network is unreachable",
    "Network dropped connection on reset",
    "Software caused connection abort",
    "Connection reset by peer",
    "No buffer space available",
    "Transport endpoint is already connected",
    "Transport endpoint is not connected",
    "Cannot send after transport endpoint shutdown",
    "Too many references: cannot splice",
    "Connection timed out",
    "Connection refused",
    "Host is down",
    "No route to host",
    "Operation already in progress",
    "Operation now in progress",
    "Stale file handle",
    "Structure needs cleaning",
    "Not a XENIX named type file",
    "No XENIX semaphores available",
    "Is a named type file",
    "Remote I/O error",
    "Disk quota exceeded",
    "No medium found",
    "Wrong medium type",
    "Operation canceled",
    "Required key not available",
    "Key has expired",
    "Key has been revoked",
    "Key was rejected by service",
    "Owner died",
    "State not recoverable",
    "Operation not possible due to RF-kill",
    "Memory page has hardware error"};

#elif defined __APPLE__
#define UNKNOWN_ERR_FMT "Unknown error: %d"
#define ERR_LIST_SIZE 107

static const char errors_list[ERR_LIST_SIZE][ERR_STR_LEN] = {
    "Undefined error: 0",
    "Operation not permitted",
    "No such file or directory",
    "No such process",
    "Interrupted system call",
    "Input/output error",
    "Device not configured",
    "Argument list too long",
    "Exec format error",
    "Bad file descriptor",
    "No child processes",
    "Resource deadlock avoided",
    "Cannot allocate memory",
    "Permission denied",
    "Bad address",
    "Block device required",
    "Resource busy",
    "File exists",
    "Cross-device link",
    "Operation not supported by device",
    "Not a directory",
    "Is a directory",
    "Invalid argument",
    "Too many open files in system",
    "Too many open files",
    "Inappropriate ioctl for device",
    "Text file busy",
    "File too large",
    "No space left on device",
    "Illegal seek",
    "Read-only file system",
    "Too many links",
    "Broken pipe",
    "Numerical argument out of domain",
    "Result too large",
    "Resource temporarily unavailable",
    "Operation now in progress",
    "Operation already in progress",
    "Socket operation on non-socket",
    "Destination address required",
    "Message too long",
    "Protocol wrong type for socket",
    "Protocol not available",
    "Protocol not supported",
    "Socket type not supported",
    "Operation not supported",
    "Protocol family not supported",
    "Address family not supported by protocol family",
    "Address already in use",
    "Can't assign requested address",
    "Network is down",
    "Network is unreachable",
    "Network dropped connection on reset",
    "Software caused connection abort",
    "Connection reset by peer",
    "No buffer space available",
    "Socket is already connected",
    "Socket is not connected",
    "Can't send after socket shutdown",
    "Too many references: can't splice",
    "Operation timed out",
    "Connection refused",
    "Too many levels of symbolic links",
    "File name too long",
    "Host is down",
    "No route to host",
    "Directory not empty",
    "Too many processes",
    "Too many users",
    "Disc quota exceeded",
    "Stale NFS file handle",
    "Too many levels of remote in path",
    "RPC struct is bad",
    "RPC version wrong",
    "RPC prog. not avail",
    "Program version wrong",
    "Bad procedure for program",
    "No locks available",
    "Function not implemented",
    "Inappropriate file type or format",
    "Authentication error",
    "Need authenticator",
    "Device power is off",
    "Device error",
    "Value too large to be stored in data type",
    "Bad executable (or shared library)",
    "Bad CPU type in executable",
    "Shared library version mismatch",
    "Malformed Mach-o file",
    "Operation canceled",
    "Identifier removed",
    "No message of desired type",
    "Illegal byte sequence",
    "Attribute not found",
    "Bad message",
    "EMULTIHOP (Reserved)",
    "No message available on STREAM",
    "ENOLINK (Reserved)",
    "No STREAM resources",
    "Not a STREAM",
    "Protocol error",
    "STREAM ioctl timeout",
    "Operation not supported on socket",
    "Policy not found",
    "State not recoverable",
    "Previous owner died",
    "Interface output queue is full"};

#endif

/* ---------- my_sprintf realization --------- */

typedef struct {
  int flag;
  int width;
  int prec;
  char length;
} FmtSpec;

typedef int (*format_handler_t)(char** str, const char** format, va_list args,
                                FmtSpec curr_spec);

typedef struct {
  char specifier;
  format_handler_t handler;
} spec_entry_t;

int handle_char(char** str, const char** format, va_list args,
                FmtSpec curr_spec);
int handle_string(char** str, const char** format, va_list args,
                  FmtSpec curr_spec);
int handle_integer(char** str, const char** format, va_list args,
                   FmtSpec curr_spec);
int handle_unsigned(char** str, const char** format, va_list args,
                    FmtSpec curr_spec);
int handle_float(char** str, const char** format, va_list args,
                 FmtSpec curr_spec);
int handle_short_float(char** str, const char** format, va_list args,
                       FmtSpec curr_spec);
int handle_scientific(char** str, const char** format, va_list args,
                      FmtSpec curr_spec);
int handle_hex(char** str, const char** format, va_list args,
               FmtSpec curr_spec);
int handle_octal(char** str, const char** format, va_list args,
                 FmtSpec curr_spec);
int handle_pointer(char** str, const char** format, va_list args,
                   FmtSpec curr_spec);

static const spec_entry_t dispatch_table[] = {
    {'c', handle_char},        {'s', handle_string},
    {'d', handle_integer},     {'u', handle_unsigned},
    {'f', handle_float},       {'g', handle_short_float},
    {'G', handle_short_float}, {'e', handle_scientific},
    {'E', handle_scientific},  {'x', handle_hex},
    {'X', handle_hex},         {'o', handle_octal},
    {'p', handle_pointer},     {0, NULL}};

void build_alt_prefix(const FmtSpec* s, const char* digits, char spec,
                      char* prefix);
void build_signed_prefix(long double val, const FmtSpec* s, char* prefix);
void pad_and_copy(char** out, const FmtSpec* s, const char* prefix,
                  const char* digits, char type);

int my_sprintf(char* str, const char* format, ...);

void read_flags(const char** format, FmtSpec* curr_spec);
void read_width(const char** format, FmtSpec* curr_spec);
void read_precision(const char** format, FmtSpec* curr_spec);
void read_length_modifier(const char** format, FmtSpec* curr_spec);

int find_specifier(char** str, const char** format, va_list args,
                   FmtSpec curr_spec);

int _itoa(unsigned long long u_value, char* val_str, int prec, int base);

void _ftoa(long double value, char* value_string, int afterpoint,
           int short_form, int alternate_form);

void _scitoa(long double value, char* val_str, int precision,
             int alternate_form, char specifier);

void _gtoa(long double value, char* value_string, int P, int use_e_format,
           int alternate_form, char type_char);

int my_sprintf(char* str, const char* format, ...) {
  va_list args;
  va_start(args, format);

  int chars_written = 0;
  int read_error = 0;

  while (*format != 0) {
    //	%[flags][width][.precision][length]specifier
    if (*format == '%') {
      format++;

      if (*format == '%') {
        *str++ = *format++;
        chars_written++;
        continue;
      }

      FmtSpec curr_spec = {0};

      read_flags(&format, &curr_spec);
      read_width(&format, &curr_spec);
      read_precision(&format, &curr_spec);
      read_length_modifier(&format, &curr_spec);

      int temp = find_specifier(&str, &format, args, curr_spec);
      if (temp > -1)
        chars_written += temp;
      else
        read_error++;
    } else {
      *str++ = *format++;
      chars_written++;
    }
  }

  *str = '\0';

  va_end(args);
  if (read_error) chars_written = -1;
  return chars_written;
}

void build_signed_prefix(long double val, const FmtSpec* s, char* prefix) {
  int i = 0;
  if (val < 0) {
    prefix[i++] = '-';
  } else {
    if (s->flag & FLAG_FORCE_SIGN)
      prefix[i++] = '+';
    else {
      if (s->flag & FLAG_BLANK_POSITIVE) prefix[i++] = ' ';
    }
  }
  prefix[i++] = '\0';
}

void build_alt_prefix(const FmtSpec* s, const char* digits, char spec,
                      char* prefix) {
  int i = 0;
  if (s->flag & FLAG_ALTERNATE_FORM) {
    if (spec == 'x' || spec == 'X') {
      int is_zero = (digits[0] == '0' && digits[1] == '\0');
      if (!is_zero) {
        prefix[i++] = '0';
        prefix[i++] = (spec == 'x' ? 'x' : 'X');
      }
    } else if (spec == 'o') {
      if (digits[0] != '0') {
        prefix[i++] = '0';
      }
    }
  } else if (spec == 'p') {
    prefix[i++] = '0';
    prefix[i++] = 'x';
  }
  prefix[i] = '\0';
}

void read_flags(const char** format, FmtSpec* curr_spec) {
  while (**format == '-' || **format == '+' || **format == ' ' ||
         **format == '#' || **format == '0') {
    if (**format == '-')
      curr_spec->flag |= FLAG_LEFT_JUSTIFY;
    else if (**format == '+')
      curr_spec->flag |= FLAG_FORCE_SIGN;
    else if (**format == ' ')
      curr_spec->flag |= FLAG_BLANK_POSITIVE;
    else if (**format == '#')
      curr_spec->flag |= FLAG_ALTERNATE_FORM;
    else if (**format == '0')
      curr_spec->flag |= FLAG_ZEROPAD;

    (*format)++;
  }

  if (curr_spec->flag & FLAG_FORCE_SIGN)
    curr_spec->flag &= ~FLAG_BLANK_POSITIVE;

  if (curr_spec->flag & FLAG_LEFT_JUSTIFY) curr_spec->flag &= ~FLAG_ZEROPAD;
}

int is_digit(const char sym) {
  return (sym - '0' <= 9 && sym - '0' >= 0) ? 1 : 0;
}

void read_width(const char** format, FmtSpec* curr_spec) {
  if (*((*format) - 1) != '.') {
    if (is_digit(**format)) {
      int w = 0;
      while (is_digit(**format)) {
        w = w * 10 + (**format - '0');
        (*format)++;
      }
      curr_spec->width = w;
    } else if (**format == '*') {
      curr_spec->width = AS_ARGUMENT_WIDTH;
      (*format)++;
    }
  }
}

void read_precision(const char** format, FmtSpec* curr_spec) {
  if (**format == '.') {
    (*format)++;
    if (is_digit(**format)) {
      int p = 0;
      while (is_digit(**format)) {
        p = p * 10 + (**format - '0');
        (*format)++;
      }
      curr_spec->prec = p;
    } else if (**format == '*') {
      curr_spec->prec = AS_ARGUMENT_PREC;
      (*format)++;
    } else {
      curr_spec->prec = 0;
    }
  } else {
    curr_spec->prec = PRECISION_NOT_SPEC;
  }
}

void read_length_modifier(const char** format, FmtSpec* curr_spec) {
  if (**format == 'h' || **format == 'l' || **format == 'L') {
    curr_spec->length = **format;
    (*format)++;
  }
}

format_handler_t find_handler(char specifier) {
  int i = 0;
  for (; dispatch_table[i].specifier != 0 &&
         dispatch_table[i].specifier != specifier;
       i++);

  return dispatch_table[i].handler;
}

// 'c'
int handle_char(char** str, const char** format, va_list args,
                FmtSpec curr_spec) {
  const char* start_str = *str;
  int non_ascii_char_found = 0;

  // for wchar_t (wide char 4 bytes)
  if (curr_spec.length == 'l') {
    wchar_t input_wcs[2];
    char mbs_buf[MB_CUR_MAX + 1];
    input_wcs[0] = va_arg(args, wchar_t);

    if (input_wcs[0] > 127) non_ascii_char_found++;

    input_wcs[1] = L'\0';
    my_size_t mbs_len = wcstombs(mbs_buf, input_wcs, sizeof(mbs_buf) - 1);

    /* mbs_len will be (my_size_t)-1 in the case when current
     locale MB_CUR_MAX is less than sizeof(wchar_t) because in
     this case wcstombs will return (size_t)-1 */
    if (non_ascii_char_found && mbs_len == (my_size_t)-1) {
      mbs_len = 0;
    }
    mbs_buf[mbs_len] = '\0';

    pad_and_copy(str, &curr_spec, "", mbs_buf, **format);

  } else {
    // for (char) type
    char tmp[2];
    tmp[0] = (char)va_arg(args, int);
    tmp[1] = '\0';
    pad_and_copy(str, &curr_spec, "", tmp, **format);
  }

  (*format)++;
  int chars_written = (*str) - start_str;
  return (non_ascii_char_found && (my_size_t)MB_CUR_MAX < sizeof(wchar_t))
             ? -1
             : chars_written;
}

// 's'
int handle_string(char** str, const char** format, va_list args,
                  FmtSpec curr_spec) {
  const char* start_str = *str;
  const char* digits_ptr = NULL;
  char mbs_buf[1024];

  if (curr_spec.length == 'l') {
    const wchar_t* input_wcs = va_arg(args, wchar_t*);

    if (!input_wcs) {
      digits_ptr = "(null)";
    } else {
      my_size_t max_mbs_len = sizeof(mbs_buf) - 1;
      my_size_t mbs_len = wcstombs(mbs_buf, input_wcs, max_mbs_len);

      if (mbs_len == (my_size_t)-1) {
        mbs_len = 0;
      }

      if (curr_spec.prec != PRECISION_NOT_SPEC &&
          curr_spec.prec < (int)mbs_len) {
        mbs_len = curr_spec.prec;
      }

      mbs_buf[mbs_len] = '\0';
      digits_ptr = mbs_buf;
    }
  } else {
    const char* input_str = va_arg(args, char*);

    if (!input_str) {
      digits_ptr = "(null)";
    } else {
      my_size_t len = my_strlen(input_str);
      my_size_t copy_len = len;

      if (curr_spec.prec != PRECISION_NOT_SPEC && curr_spec.prec < (int)len) {
        copy_len = curr_spec.prec;
      }

      my_memcpy(mbs_buf, input_str, copy_len);
      mbs_buf[copy_len] = '\0';
      digits_ptr = mbs_buf;
    }
  }

  pad_and_copy(str, &curr_spec, "", digits_ptr, **format);
  (*format)++;
  return (*str) - start_str;
}

// 'd'
int handle_integer(char** str, const char** format, va_list args,
                   FmtSpec curr_spec) {
  // 0$(WIDTH).$(PREC) case - 0 flag is turned off and precision is kept
  if (curr_spec.prec != PRECISION_NOT_SPEC) curr_spec.flag &= ~FLAG_ZEROPAD;

  const char* start_str = *str;
  char val_str[MAX_LEN_VAL_STR];
  char prefix[3];
  long long value = 0;

  GET_DECIMAL(value, curr_spec.length);

  _itoa(ABS(value), val_str,
        (curr_spec.prec == PRECISION_NOT_SPEC) ? 0 : curr_spec.prec,
        DECIMAL_BASE);

  build_signed_prefix(value, &curr_spec, prefix);

  pad_and_copy(str, &curr_spec, prefix, val_str, **format);
  (*format)++;

  return (*str) - start_str;
}

// 'u'
int handle_unsigned(char** str, const char** format, va_list args,
                    FmtSpec curr_spec) {
  // 0$(WIDTH).$(PREC) case - 0 flag is turned off and precision is kept
  if (curr_spec.prec != PRECISION_NOT_SPEC) curr_spec.flag &= ~FLAG_ZEROPAD;

  const char* start_str = *str;
  char val_str[MAX_LEN_VAL_STR];
  unsigned long long value = 0;

  GET_UNSIGNED(value, curr_spec.length);

  _itoa(value, val_str,
        (curr_spec.prec == PRECISION_NOT_SPEC) ? 0 : curr_spec.prec,
        DECIMAL_BASE);

  pad_and_copy(str, &curr_spec, "", val_str, **format);
  (*format)++;

  return (*str) - start_str;
}

// 'f'
int handle_float(char** str, const char** format, va_list args,
                 FmtSpec curr_spec) {
  const char* start_str = *str;
  char val_str[MAX_LEN_VAL_STR];
  char prefix[4];
  long double value = (curr_spec.length == 'L') ? va_arg(args, long double)
                                                : va_arg(args, double);

  _ftoa(ABS(value), val_str,
        (curr_spec.prec != PRECISION_NOT_SPEC) ? curr_spec.prec
                                               : FLOATING_DEFAULT_PREC,
        NOT_SHORT_FORM, curr_spec.flag & FLAG_ALTERNATE_FORM);

  build_signed_prefix(value, &curr_spec, prefix);

  pad_and_copy(str, &curr_spec, prefix, val_str, **format);
  (*format)++;

  return (*str) - start_str;
}

// 'g' and 'G'
int handle_short_float(char** str, const char** format, va_list args,
                       FmtSpec curr_spec) {
  const char* start_str = *str;
  char val_str[MAX_LEN_VAL_STR];
  char* val_str_ptr;
  char prefix[4];
  long double value = (curr_spec.length == 'L') ? va_arg(args, long double)
                                                : va_arg(args, double);
  long double abs_value = ABS(value);

  int P = (curr_spec.prec != PRECISION_NOT_SPEC) ? curr_spec.prec
                                                 : FLOATING_DEFAULT_PREC;

  if (P == 0) P = 1;

  int E = 0;
  if (abs_value != 0) E = floor(log10(abs_value));

  int use_e_format = (abs_value != 0 && (E < -4 || E >= P));

  _gtoa(value, val_str, P, use_e_format, curr_spec.flag & FLAG_ALTERNATE_FORM,
        **format);
  if (**format == 'G') val_str_ptr = my_to_upper(val_str);

  build_signed_prefix(value, &curr_spec, prefix);

  pad_and_copy(str, &curr_spec, prefix,
               (**format == 'G') ? val_str_ptr : val_str, **format);

  if (**format == 'G') free(val_str_ptr);

  (*format)++;

  return (*str) - start_str;
}

// 'e' and 'E'
int handle_scientific(char** str, const char** format, va_list args,
                      FmtSpec curr_spec) {
  const char* start_str = *str;
  char val_str[MAX_LEN_VAL_STR];
  char prefix[4];
  long double value = (curr_spec.length == 'L') ? va_arg(args, long double)
                                                : va_arg(args, double);

  _scitoa(ABS(value), val_str,
          (curr_spec.prec != PRECISION_NOT_SPEC) ? curr_spec.prec
                                                 : FLOATING_DEFAULT_PREC,
          curr_spec.flag & FLAG_ALTERNATE_FORM, **format);
  build_signed_prefix(value, &curr_spec, prefix);

  pad_and_copy(str, &curr_spec, prefix, val_str, **format);
  (*format)++;

  return (*str) - start_str;
}

// 'x' and 'X'
int handle_hex(char** str, const char** format, va_list args,
               FmtSpec curr_spec) {
  // 0$(WIDTH).$(PREC) case - 0 flag is turned off and precision is kept
  if (curr_spec.prec != PRECISION_NOT_SPEC) curr_spec.flag &= ~FLAG_ZEROPAD;

  const char* start_str = *str;
  char val_str[MAX_LEN_VAL_STR];
  char* val_str_ptr;
  char prefix[3];
  unsigned long long value;

  GET_UNSIGNED(value, curr_spec.length);
  _itoa(value, val_str,
        (curr_spec.prec == PRECISION_NOT_SPEC) ? 0 : curr_spec.prec,
        HEXADECIMAL_BASE);
  if (**format == 'X') val_str_ptr = my_to_upper(val_str);

  build_alt_prefix(&curr_spec, (**format == 'X') ? val_str_ptr : val_str,
                   **format, prefix);
  pad_and_copy(str, &curr_spec, prefix,
               (**format == 'X') ? val_str_ptr : val_str, **format);
  if (**format == 'X') free(val_str_ptr);

  (*format)++;

  return (*str) - start_str;
}

// 'o'
int handle_octal(char** str, const char** format, va_list args,
                 FmtSpec curr_spec) {
  // 0$(WIDTH).$(PREC) case - 0 flag is turned off and precision is kept
  if (curr_spec.prec != PRECISION_NOT_SPEC) curr_spec.flag &= ~FLAG_ZEROPAD;

  const char* start_str = *str;
  char val_str[MAX_LEN_VAL_STR];
  char prefix[4];
  unsigned long long value;

  GET_UNSIGNED(value, curr_spec.length);

  _itoa(value, val_str,
        (curr_spec.prec == PRECISION_NOT_SPEC) ? 0 : curr_spec.prec,
        OCTAL_BASE);

  build_alt_prefix(&curr_spec, val_str, **format, prefix);
  pad_and_copy(str, &curr_spec, prefix, val_str, **format);
  (*format)++;

  return (*str) - start_str;
}

int handle_pointer(char** str, const char** format, va_list args,
                   FmtSpec curr_spec) {
  const char* start_str = *str;
  char val_str[MAX_LEN_VAL_STR];
  char prefix[4];
  unsigned long long value = (unsigned long long)va_arg(args, void*);

  _itoa(value, val_str,
        (curr_spec.prec == PRECISION_NOT_SPEC) ? 0 : curr_spec.prec,
        HEXADECIMAL_BASE);

  if (value != 0) {
    int idx = 0;
    if (curr_spec.flag & FLAG_FORCE_SIGN)
      prefix[idx++] = '+';
    else if (curr_spec.flag & FLAG_BLANK_POSITIVE)
      prefix[idx++] = ' ';

    prefix[idx++] = '0';
    prefix[idx++] = 'x';
    prefix[idx] = '\0';
  } else {
    // 0x0 for OS_X and (nil) for Linux
    NULL_POINTER_ASCII_STRING;
  }

  pad_and_copy(str, &curr_spec, prefix, val_str, **format);
  (*format)++;

  return (*str) - start_str;
}

int find_specifier(char** str, const char** format, va_list args,
                   FmtSpec curr_spec) {
  int chars_written = 0;

  if (curr_spec.width == AS_ARGUMENT_WIDTH) curr_spec.width = va_arg(args, int);

  if (curr_spec.prec == AS_ARGUMENT_PREC) curr_spec.prec = va_arg(args, int);

  if (curr_spec.width < 0) {
    curr_spec.flag |= FLAG_LEFT_JUSTIFY;
    curr_spec.width *= -1;
  }

  if (curr_spec.prec < 0) curr_spec.prec = PRECISION_NOT_SPEC;

  format_handler_t handler = find_handler(**format);

  if (handler) chars_written += handler(str, format, args, curr_spec);

  return chars_written;
}

void pad_and_copy(char** out, const FmtSpec* s, const char* prefix,
                  const char* digits, char type) {
  int is_float =
      type == 'f' || type == 'g' || type == 'G' || type == 'e' || type == 'E';

  int is_int = !(is_float) && type != 'c' && type != 's';

  int plen = (int)my_strlen(prefix);
  int dlen = (digits[0] == '0' && s->prec == 0 && is_int)
                 ? 0
                 : (int)my_strlen(digits);
  int is_null = !my_strncmp("(null)", digits, 6);
  if (is_null && s->prec < 7 && s->prec >= 0) dlen = 0;

  int total = plen + dlen;
  int pad = (s->width > total) ? (s->width - total) : 0;
  int use_zero_pad = 0;

  int precision_not_specified = s->prec == PRECISION_NOT_SPEC;

  if (!(s->flag & FLAG_LEFT_JUSTIFY)) {
    if ((precision_not_specified && is_int) || is_float) {
      int is_num = (type == 'd' || type == 'u' || type == 'x' || type == 'X' ||
                    type == 'o' || type == 'p' || type == 'f' || type == 'g' ||
                    type == 'G' || type == 'e' || type == 'E');

      if (is_num && (s->flag & FLAG_ZEROPAD)) use_zero_pad = 1;
    }
  }

  if (!(s->flag & FLAG_LEFT_JUSTIFY) && !use_zero_pad) {
    for (int i = 0; i < pad; i++) *(*out)++ = ' ';
  }

  if (digits[0] == '\0' && type == 'c') *(*out)++ = '\0';

  my_memcpy(*out, prefix, (my_size_t)plen);
  *out += plen;

  int zero_value_and_precision =
      (digits[0] == '0' && digits[1] == '\0' && s->prec == 0);
  if (!zero_value_and_precision || is_float) {
    if (use_zero_pad) {
      for (int i = 0; i < pad; i++) *(*out)++ = '0';
      my_memcpy(*out, digits, (my_size_t)dlen);
      *out += dlen;
    } else {
      if (is_null) {
        if (s->prec >= 7 || s->prec == PRECISION_NOT_SPEC) {
          my_memcpy(*out, digits, (my_size_t)dlen);
          *out += dlen;
        }
      } else {
        my_memcpy(*out, digits, (my_size_t)dlen);
        *out += dlen;
      }

      if (s->flag & FLAG_LEFT_JUSTIFY)
        for (int i = 0; i < pad; i++) *(*out)++ = ' ';
    }
  }
}

void _gtoa(long double value, char* value_string, int P, int use_e_format,
           int alternate_form, char type_char) {
  if (P == 0) P = 1;

  if (use_e_format) {
    int e_prec = P - 1;
    _scitoa(value, value_string, e_prec, alternate_form, type_char);
  } else {
    int E = 0;
    if (value != 0) E = floor(log10(ABS(value)));

    int f_prec = P - 1 - E;
    if (f_prec < 0) f_prec = 0;

    _ftoa(value, value_string, f_prec, NOT_SHORT_FORM, NOT_ALTER_FORM);
  }

  if (!alternate_form) {
    char* end = value_string + (int)my_strlen(value_string) - 1;

    if (use_e_format) {
      while (end > value_string && (*end != 'e' && *end != 'E')) end--;
    }

    const char* decimal_point = my_strchr(value_string, '.');
    if (decimal_point) {
      char* current = use_e_format ? (end - 1) : end;

      if (use_e_format) {
        while (current > decimal_point && *current == '0') {
          *current = '\0';
          current--;
        }
      } else {
        while (*current == '0' && current > decimal_point) {
          *current = '\0';
          current--;
        }
      }

      if (*current == '.') {
        *current = '\0';
      }
      if (use_e_format) {
        const char* src = end;
        char* dst = current;
        dst++;
        while ((*dst++ = *src++) != '\0');
      }
    }
  }
}

void _scitoa(long double value, char* val_str, int precision,
             int alternate_form, char specifier) {
  long long exponent =
      (value == 0.0) ? 0 : (long long)floor(log10(fabs((double)value)));
  long double mantissa = value / pow(10, exponent);
  if (value != 0.0) {
    while ((int)round(mantissa) == 0) {
      mantissa *= 10.0;
      exponent--;
    }
  } else {
    mantissa = 0.0L;
  }

  char str_exp[2048];
  char str_mant[2048];
  _ftoa(mantissa, str_mant, precision,
        (specifier == 'g' || specifier == 'G') ? SHORT_FORM : NOT_SHORT_FORM,
        NOT_ALTER_FORM);
  str_exp[0] = (exponent >= 0) ? '+' : '-';
  _itoa(ABS(exponent), str_exp + 1, 2, DECIMAL_BASE);

  int i = 0;
  while ((*val_str++ = str_mant[i++]) != '\0');

  if (alternate_form && precision == 0) {
    *(val_str - 1) = '.';
    val_str++;
  }

  if (specifier == 'E')
    *(val_str - 1) = 'E';
  else
    *(val_str - 1) = 'e';

  i = 0;
  while ((*val_str++ = str_exp[i++]) != '\0');

  *val_str++ = 0;
}

int _itoa(unsigned long long u_value, char* val_str, int prec, int base) {
  int len = 0;
  if (base > 2 && base < 36) {
    char* ptr = val_str;

    do {
      *ptr++ =
          "zyxwvutsrqponmlkjihgfedcba9876543210123456789abcde"
          "fghijklmnopqrstuvw"
          "xyz"[35 + (u_value % base)];
      u_value /= base;
    } while (u_value > 0);

    int digits_len = ptr - val_str;

    while (digits_len < prec) {
      *ptr++ = '0';
      digits_len++;
    }

    char* start = val_str;

    *ptr-- = '\0';

    len = ptr - val_str;

    while (start < ptr) {
      char tmp_char = *ptr;
      *ptr-- = *start;
      *start++ = tmp_char;
    }
  } else {
    *val_str = '\0';
  }

  return len;
}

void _ftoa(long double value, char* value_string, int afterpoint,
           int short_form, int alternate_form) {
  long double abs_val = (long double)((value < 0) ? -value : value);
  long long int_part = (long long)(abs_val);

  long double float_part = abs_val - (long double)int_part;
  float_part *= (float_part < 0) ? -1 : 1;

  if (afterpoint > 0) {
    long double fpart_scaled = float_part * (long double)pow(10, afterpoint);
    unsigned long long rounded_fpart = (unsigned long long)round(fpart_scaled);
    unsigned long long max_fpart = (long long)pow(10, afterpoint);

    if (rounded_fpart >= max_fpart) {
      int_part++;
      rounded_fpart = 0;
    }
    if (!alternate_form) {
      while (short_form && rounded_fpart % 10 == 0 && rounded_fpart != 0) {
        rounded_fpart /= 10;
      }
    }

    int len_ipart = _itoa(ABS(int_part), value_string, 0, DECIMAL_BASE);
    int i = len_ipart + 1;
    value_string[i] = '.';
    i++;

    int len_fpart = _itoa(rounded_fpart, value_string + i,
                          (short_form) ? 0 : afterpoint, DECIMAL_BASE);

    if (short_form) {
      int k = i + len_fpart + 1;
      int precision = ABS((afterpoint - len_fpart - 1));
      for (int t = 1; t <= precision; t++) {
        value_string[k] = '0';
        k++;
      }

      value_string[k] = 0;
    }

  } else {
    int idx = _itoa((unsigned long long)ABS(round((long double)value)),
                    value_string, 0, DECIMAL_BASE);
    if (alternate_form) {
      value_string[++idx] = '.';
      value_string[++idx] = '\0';
    }
  }
}

/* -------- end of my_sprintf ------ */

char* my_strerror(int errnum) {
  static char unknown_error_str[ERR_STR_LEN];
  char* res_ptr = my_NULL;

  if (errnum >= 0 && errnum < ERR_LIST_SIZE)
    res_ptr = (char*)errors_list[errnum];
  else {
    my_sprintf(unknown_error_str, UNKNOWN_ERR_FMT, errnum);
    res_ptr = unknown_error_str;
  }

  return res_ptr;
}
