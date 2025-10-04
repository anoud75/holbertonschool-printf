#include "main.h"

/**
 * print_binary - prints an unsigned int in binary
 * @args: va_list containing the unsigned int
 *
 * Return: number of characters printed
 */
int print_binary(va_list args)
{
	unsigned int n = va_arg(args, unsigned int);
	int count = 0;
	int i;
	int started = 0;

	if (n == 0)
	{
		_putchar('0');
		return (1);
	}

	for (i = 31; i >= 0; i--)
	{
		if ((n >> i) & 1)
		{
			_putchar('1');
			count++;
			started = 1;
		}
		else if (started)
		{
			_putchar('0');
			count++;
		}
	}

	return (count);
}
