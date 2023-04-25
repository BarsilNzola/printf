#include "main.h"
#include <stddef.h>
#include <stdarg.h>

/**
 * print_char - Prints a character
 * @args: A list of arguments containing the character to be printed
 *
 * Return: The number of characters printed
 */
int print_char(va_list args)
{
        char c = va_arg(args, int);
        return (_putchar(c));
}

/**
 * print_string - Prints a string
 * @args: A list of arguments containing the string to be printed
 *
 * Return: The number of characters printed
 */
int print_string(va_list args)
{
        char *str = va_arg(args, char *);
        int len = 0;

        if (str == NULL)
                str = "(null)";

        while (str[len])
                len += _putchar(str[len]);

        return (len);
}

/**
 * print_integer - Prints an integer
 * @args: A list of arguments containing the integer to be printed
 *
 * Return: The number of characters printed
 */
int print_integer(va_list args)
{
        int num = va_arg(args, int);
        int len = 0;

        if (num < 0) {
                len += _putchar('-');
                num = -num;
        }

        len += print_integer_helper(num);

        return (len);
}

/**
 * print_integer_helper - Recursively prints an integer
 * @num: The integer to be printed
 *
 * Return: The number of characters printed
 */
int print_integer_helper(int num)
{
        int len = 0;

        if (num / 10)
                len += print_integer_helper(num / 10);

        len += _putchar(num % 10 + '0');

        return (len);
}

