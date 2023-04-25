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
	char c;
	char *s;

	int i = 0, count = 0;

	va_start(args, format);

	if (format == NULL)
		return (-1);

	while (format[i] != '\0')
	{
		if (format[i] == '%')
		{
			i++;
			switch (format[i])
			{
			case 'c':
				c = va_arg(args, int);
				putchar(c);
				count++;
				break;

			case 's':
				s = va_arg(args, char *);
				if (s == NULL)
					s = "(null)";
				while (*s)
				{
					putchar(*s);
					s++;
					count++;
				}
				break;

			case '%':
				putchar('%');
				count++;
				break;

			default:
				putchar('%');
				putchar(format[i]);
				count += 2;
				break;
			}
		}
		else
		{
			putchar(format[i]);
			count++;
		}
		i++;
	}

	va_end(args);

	return (count);
}

