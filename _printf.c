#include "main.h"

/**
 * print_char - Prints a character to stdout
 * @c: The character to print
 *
 * Return: The number of characters printed
 */
int print_char(va_list c)
{
  return (_putchar(va_arg(c, int)));
}

/**
 * print_string - Prints a string to stdout
 * @s: The string to print
 *
 * Return: The number of characters printed
 */
int print_string(va_list s)
{
  char *str;

  str = va_arg(s, char *);
  if (str == NULL)
    str = "(null)";
  return (puts(str));
}

/**
 * print_integer - Prints an integer to stdout
 * @i: The integer to print
 *
 * Return: The number of characters printed
 */
int print_integer(va_list i)
{
  int len = 0;
  int n = va_arg(i, int);
  unsigned int num;

  if (n < 0)
  {
    len += _putchar('-');
    num = -n;
  }
  else
    num = n;

  len += print_integer_helper(num);

  return (len);
}

/**
 * print_integer_helper - Recursive function to print an integer to stdout
 * @n: The integer to print
 *
 * Return: The number of digits printed
 */
int print_integer_helper(int n)
{
  int len = 1;

  if (n / 10)
    len += print_integer_helper(n / 10);

  _putchar(n % 10 + '0');

  return (len);
}

