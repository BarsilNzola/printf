#include "main.h"
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>

/**
 * handle_integer - handles the integer conversion specifier
 * @args: the argument list
 *
 * Return: the number of characters printed
 */
int handle_integer(va_list args)
{
    int n = va_arg(args, int);
    int len = 0;

    if (n < 0) {
        putchar('-');
        n = -n;
        len++;
    }

    if (n / 10)
        len += handle_integer(args);

    putchar(n % 10 + '0');
    len++;

    return len;
}

/**
 * handle_decimal - handles the decimal conversion specifier
 * @args: the argument list
 *
 * Return: the number of characters printed
 */
int handle_decimal(va_list args)
{
    return handle_integer(args);
}

/**
 * _printf - prints a formatted string to stdout
 * @format: the format string
 *
 * Return: the number of characters printed
 */
int _printf(const char *format, ...)
{
    va_list args;
    int len = 0;

    va_start(args, format);

    while (*format) {
        if (*format == '%') {
            format++;
            switch (*format) {
                case 'd':
                case 'i':
                    len += handle_decimal(args);
                    break;
                default:
                    putchar(*format);
                    len++;
                    break;
            }
        } else {
            putchar(*format);
            len++;
        }
        format++;
    }

    va_end(args);

    return len;
}

