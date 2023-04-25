#include "main.h"
#include <stdarg.h>

/**
 * _printf - produces output according to a format
 * @format: character string containing zero or more directives
 *
 * Return: the number of characters printed (excluding the null byte used to end output to strings)
 */
int _printf(const char *format, ...)
{
	va_list args;
	int printed_chars = 0;

	va_start(args, format);

	while (*format)
	{
		if (*format == '%')
		{
			format++;

			switch (*format)
			{
				case 'c':
					printed_chars += _putchar(va_arg(args, int));
					break;
				case 's':
					printed_chars += _puts(va_arg(args, char *));
					break;
				case 'd':
				case 'i':
					printed_chars += print_number(va_arg(args, int));
					break;
				case 'b':
					printed_chars += print_binary(va_arg(args, unsigned int));
					break;
				case '%':
					printed_chars += _putchar('%');
					break;
				default:
					_putchar('%');
					_putchar(*format);
					printed_chars += 2;
					break;
			}
		}
		else
		{
			_putchar(*format);
			printed_chars++;
		}

		format++;
	}

	va_end(args);

	return (printed_chars);
}

/**
 * print_number - prints an integer
 * @n: integer to print
 *
 * Return: number of characters printed
 */
int print_number(int n)
{
	unsigned int num;
	int len = 0;

	if (n < 0)
	{
		_putchar('-');
		len++;
		num = -n;
	}
	else
	{
		num = n;
	}

	if (num / 10)
	{
		len += print_number(num / 10);
	}

	_putchar((num % 10) + '0');
	len++;

	return (len);
}

/**
 * print_binary - prints an unsigned integer in binary format
 * @n: unsigned integer to print
 *
 * Return: number of characters printed
 */
int print_binary(unsigned int n)
{
	if (n / 2)
	{
		print_binary(n / 2);
	}

	_putchar((n % 2) + '0');

	return (1);
}

