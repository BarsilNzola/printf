#include "main.h"

/**
 * print_char - prints a character to stdout
 * @args: list of arguments
 * Return: number of characters printed
 */
int print_char(va_list args)
{
  char c = va_arg(args, int);
  _putchar(c);
  return (1);
}

/**
 * print_string - prints a string to stdout
 * @args: list of arguments
 * Return: number of characters printed
 */
int print_string(va_list args)
{
  char *str = va_arg(args, char *);
  int chars_printed = 0;

  if (str == NULL)
    str = "(null)";

  while (*str != '\0')
  {
    _putchar(*str);
    chars_printed++;
    str++;
  }

  return (chars_printed);
}

/**
 * print_integer - prints an integer to stdout
 * @args: list of arguments
 * Return: number of characters printed
 */
int print_integer(va_list args)
{
  int n = va_arg(args, int);
  unsigned int num;

  if (n < 0)
  {
    _putchar('-');
    num = -n;
  }
  else
  {
    num = n;
  }

  return (print_integer_helper(num));
}

/**
 * print_integer_helper - helper function for printing integers
 * @n: the integer to be printed
 * Return: number of characters printed
 */
int print_integer_helper(unsigned int n)
{
  if (n / 10 != 0)
  {
    print_integer_helper(n / 10);
  }

  _putchar((n % 10) + '0');

  return (1);
}

