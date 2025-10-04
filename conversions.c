#include "main.h"

/**
 * print_unsigned - prints an unsigned integer
 * @args: va_list containing the unsigned int
 *
 * Return: number of characters printed
 */
int print_unsigned(va_list args)
{
	unsigned int n = va_arg(args, unsigned int);

	return (print_number(n));
}

/**
 * print_octal_recursive - prints octal recursively
 * @n: number to print
 *
 * Return: number of characters printed
 */
int print_octal_recursive(unsigned int n)
{
	int count = 0;

	if (n / 8)
		count += print_octal_recursive(n / 8);
	_putchar((n % 8) + '0');
	count++;
	return (count);
}

/**
 * print_octal - prints an unsigned int in octal
 * @args: va_list containing the unsigned int
 *
 * Return: number of characters printed
 */
int print_octal(va_list args)
{
	unsigned int n = va_arg(args, unsigned int);

	return (print_octal_recursive(n));
}

/**
 * print_hex_recursive - prints hexadecimal recursively
 * @n: number to print
 * @uppercase: 1 for uppercase, 0 for lowercase
 *
 * Return: number of characters printed
 */
int print_hex_recursive(unsigned int n, int uppercase)
{
	int count = 0;
	int digit;
	char offset;

	if (n / 16)
		count += print_hex_recursive(n / 16, uppercase);

	digit = n % 16;
	if (digit < 10)
		_putchar(digit + '0');
	else
	{
		offset = uppercase ? 'A' : 'a';
		_putchar(digit - 10 + offset);
	}
	count++;
	return (count);
}

/**
 * print_hex_lower - prints an unsigned int in lowercase hexadecimal
 * @args: va_list containing the unsigned int
 *
 * Return: number of characters printed
 */
int print_hex_lower(va_list args)
{
	unsigned int n = va_arg(args, unsigned int);

	return (print_hex_recursive(n, 0));
}

/**
 * print_hex_upper - prints an unsigned int in uppercase hexadecimal
 * @args: va_list containing the unsigned int
 *
 * Return: number of characters printed
 */
int print_hex_upper(va_list args)
{
	unsigned int n = va_arg(args, unsigned int);

	return (print_hex_recursive(n, 1));
}
