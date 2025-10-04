#include "main.h"

/**
 * print_bin_rec - recursive helper to print n in base 2
 * @n: unsigned int
 * Return: chars printed
 */
static int print_bin_rec(unsigned int n)
{
	int count = 0;

	if (n / 2)
		count += print_bin_rec(n / 2);
	count += _putchar((char)('0' + (n % 2)));
	return (count);
}

/**
 * print_bin - print an unsigned int in binary (no leading zeros)
 * @n: number to print
 * Return: number of printed characters
 */
int print_bin(unsigned int n)
{
	if (n == 0)
		return (_putchar('0'));
	return (print_bin_rec(n));
}
