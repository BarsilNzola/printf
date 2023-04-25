#include "main.h"
#include <stdio.h>
#include <stdarg.h>

/**
 * _printf - prints output according to a format
 * @format: format string containing zero or more directives
 *
 * Return: number of characters printed
 */
int _printf(const char *format, ...)
{
	va_list args;
	int count = 0;

	va_start(args, format);

	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			switch (*format)
			{
				case 'c':
					count += _putchar(va_arg(args, int));
					break;
				case 's':
					count += _puts(va_arg(args, char *));
					break;
				case '%':
					count += _putchar('%');
					break;
				case 'd':
				case 'i':
					count += _print_int(va_arg(args, int));
					break;
				default:
					count += _putchar('%');
					count += _putchar(*format);
					break;
			}
		}
		else
		{
			count += _putchar(*format);
		}
		format++;
	}
	va_end(args);
	return (count);
}

