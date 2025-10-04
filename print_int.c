#include "main.h"

/**
 * print_int - print a signed integer
 * @n: number
 * Return: number of printed characters
 */
int print_int(int n)
{
	long num = n;      /* handle INT_MIN safely */
	char buf[20];
	int i = 0, count = 0;

	if (num == 0)
		return (_putchar('0'));

	if (num < 0)
	{
		count += _putchar('-');
		num = -num;
	}

	while (num > 0)           /* collect digits reversed */
	{
		buf[i++] = (char)('0' + (num % 10));
		num /= 10;
	}
	while (i--)               /* print in normal order */
		count += _putchar(buf[i]);

	return (count);
}
