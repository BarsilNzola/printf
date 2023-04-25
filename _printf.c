#include "main.h"
#include "printf_functions.c"

/**
 * _printf - prints formatted output
 * @format: character string
 *
 * Return: number of characters printed
 */
int _printf(const char *format, ...)
{
	va_list args;
	int chars_printed;

	if (format == NULL)
		return (-1);

	va_start(args, format);

	chars_printed = parse_format_string((char *)format, args);

	va_end(args);

	return (chars_printed);
}

