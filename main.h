#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdarg.h>

/**
 * struct format_t - struct for format specifiers
 * @spec: format specifier
 * @f: function pointer to handle specifier
 */
typedef struct format_t
{
	char *spec;
	int (*f)(va_list);
} format_t;

int _printf(const char *format, ...);
int print_c(va_list args);
int print_s(va_list args);
int print_i(va_list args);
int print_d(va_list args);
int print_u(va_list args);
int print_o(va_list args);
int print_x(va_list args);
int print_X(va_list args);
int print_p(va_list args);
int print_b(va_list args);

#endif /* MAIN_H */

