#include <stdarg.h>
#include <stdio.h>
#include "main.h"

/**
 * _printf - prints output according to a format
 * @format: format string
 *
 * Return: number of characters printed
 */
int _printf(const char *format, ...)
{
    va_list args;
    int i = 0, j = 0, len = 0;
    char buffer[1024];
    char *str;

    va_start(args, format);

    while (format && format[i])
    {
        if (format[i] == '%')
        {
            i++;
            switch (format[i])
            {
                case 'c':
                    buffer[j++] = va_arg(args, int);
                    break;
                case 's':
                    str = va_arg(args, char *);
                    if (!str)
                        str = "(null)";
                    while (*str)
                        buffer[j++] = *str++;
                    break;
                case 'd':
                case 'i':
                    itoa(va_arg(args, int), buffer + j);
                    j += _strlen(buffer + j);
                    break;
                case 'b':
                    itob(va_arg(args, unsigned int), buffer + j);
                    j += _strlen(buffer + j);
                    break;
                case '%':
                    buffer[j++] = '%';
                    break;
                default:
                    buffer[j++] = '%';
                    buffer[j++] = format[i];
                    break;
            }
        }
        else
        {
            buffer[j++] = format[i];
        }
        i++;
        if (j >= 1024)
        {
            len += j;
            write(1, buffer, j);
            j = 0;
        }
    }

    len += j;
    write(1, buffer, j);

    va_end(args);

    return (len);
}

