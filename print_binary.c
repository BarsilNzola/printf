#include "main.h"
#include <stdarg.h>
#include <stdio.h>

/**
 * print_binary - prints an unsigned int in binary
 * @n: the unsigned int to print
 *
 * Return: the number of digits printed
 */
int print_binary(unsigned int n)
{
    int count = 0;

    if (n > 1)
        count += print_binary(n >> 1);
    count += _putchar((n & 1) + '0');
    return (count);
}

/**
 * _printf - prints a formatted string to the standard output
 * @format: the format string
 *
 * Return: the number of characters printed
 */
int _printf(const char *format, ...)
{
    int count = 0;
    va_list args;

    va_start(args, format);
    while (*format != '\0')
    {
        if (*format == '%')
        {
            format++;
            if (*format == 'b')
            {
                count += print_binary(va_arg(args, unsigned int));
                format++;
                continue;
            }
            /* handle other conversion specifiers */
        }
        count += _putchar(*format);
        format++;
    }
    va_end(args);
    return (count);
}

