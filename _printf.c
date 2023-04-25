#include <stdio.h>
#include <stdarg.h>
#include "main.h"

/**
 * _printf - prints output according to a format
 * @format: format string
 *
 * Return: number of characters printed
 */
int _printf(const char *format, ...)
{
    int count = 0;
    va_list args;

    va_start(args, format);

    while (*format)
    {
        if (*format == '%')
        {
            format++;
            if (*format == 'c')
            {
                char c = va_arg(args, int);
                putchar(c);
                count++;
            }
            else if (*format == 's')
            {
                char *str = va_arg(args, char *);
                while (*str)
                {
                    putchar(*str++);
                    count++;
                }
            }
            else if (*format == '%')
            {
                putchar('%');
                count++;
            }
            else
            {
                putchar('%');
                putchar(*format);
                count += 2;
            }
        }
        else
        {
            putchar(*format);
            count++;
        }
        format++;
    }

    va_end(args);

    return (count);
}

