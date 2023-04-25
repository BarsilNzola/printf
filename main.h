#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>

int _printf(const char *format, ...);
int print_char(va_list args);
int print_string(va_list args);
int print_integer(va_list args);
int print_integer_helper(unsigned int n);
int parse_format_string(char *format, va_list args);

#endif /* MAIN_H */

