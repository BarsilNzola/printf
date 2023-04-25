#include <stdio.h>
#include <stdarg.h>
#include "main.h"

/**
 * _printf - prints output according to a format
 * @format: character string with format specifier
 *
 * Return: number of characters printed
 */

int _printf(const char *format, ...)
{
    va_list args;
    int count = 0;

    va_start(args, format);

    for (; *format; ++format) {
        if (*format == '%') {
            ++format;
            if (*format == 'c') {
                int c = va_arg(args, int);
                putchar(c);
                ++count;
            }
            else if (*format == 's') {
                char *s = va_arg(args, char *);
                while (*s) {
                    putchar(*s);
                    ++s;
                    ++count;
                }
            }
            else if (*format == '%') {
                putchar('%');
                ++count;
            }
            else {
                // Handle invalid format specifier
                putchar('?');
                ++count;
            }
        }
        else {
            putchar(*format);
            ++count;
        }
    }

    va_end(args);
    return count;
}

