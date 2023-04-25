#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>

/**
 * struct format_specifier - A structure holding information about format
 *                           specifiers in printf-style formatting.
 *
 * @specifier: The conversion specifier character.
 * @handler:   The corresponding function to handle this specifier.
 */
typedef struct format_specifier
{
    char specifier;
    int (*handler)(va_list);
} format_specifier_t;

int _putchar(char c);
int _printf(const char *format, ...);
int print_char(va_list args);
int print_string(va_list args);
int print_percent(va_list args);
int print_integer(va_list args);
int print_unsigned_integer(va_list args);
int print_octal(va_list args);
int print_hex(va_list args);
int print_hex_uppercase(va_list args);
int print_binary(va_list args);

#endif /* MAIN_H */

