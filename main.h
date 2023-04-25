#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stddef.h>
#include <stdio.h>

/**
 * struct print_fn - struct to select correct print function
 * @type: the type to be printed
 * @fn: the print function to use
 */
typedef struct print_fn
{
    char type;
    int (*fn)(va_list);
} print_fn_t;

int _putchar(char c);
int _printf(const char *format, ...);

/* printf_functions.c */
int print_char(va_list args);
int print_string(va_list args);
int print_int(va_list args);
int print_binary(va_list args);
int print_unsigned(va_list args);
int print_octal(va_list args);
int print_hex(va_list args);
int print_HEX(va_list args);
int print_rev(va_list args);
int print_rot13(va_list args);

/* print_integer_helper.c */
int print_integer_helper(int n);

#endif /* MAIN_H */

