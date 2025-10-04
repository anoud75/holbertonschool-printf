#include "main.h"

/**
 * print_char - prints a character
 * @args: va_list containing the character
 *
 * Return: 1 (number of characters printed)
 */
int print_char(va_list args)
{
	char c = va_arg(args, int);

	return (_putchar(c));
}

/**
 * print_string - prints a string
 * @args: va_list containing the string
 *
 * Return: number of characters printed
 */
int print_string(va_list args)
{
	char *s = va_arg(args, char *);
	int count = 0;

	if (s == NULL)
		s = "(null)";

	while (*s)
	{
		_putchar(*s);
		s++;
		count++;
	}
	return (count);
}

/**
 * print_percent - prints a percent sign
 *
 * Return: 1 (number of characters printed)
 */
int print_percent(void)
{
	return (_putchar('%'));
}

/**
 * print_number - prints a number recursively
 * @n: number to print
 *
 * Return: number of characters printed
 */
int print_number(unsigned int n)
{
	int count = 0;

	if (n / 10)
		count += print_number(n / 10);

	_putchar((n % 10) + '0');
	count++;

	return (count);
}

/**
 * print_int - prints an integer
 * @args: va_list containing the integer
 *
 * Return: number of characters printed
 */
int print_int(va_list args)
{
	int n = va_arg(args, int);
	int count = 0;
	unsigned int num;

	if (n < 0)
	{
		_putchar('-');
		count++;
		num = -n;
	}
	else
		num = n;

	count += print_number(num);

	return (count);
}
