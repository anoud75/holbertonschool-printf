#include <stddef.h>
#include "main.h"

/**
 * _printf - minimal printf supporting c, s, %, d, i, b
 * @format: format string
 * Return: number of characters printed, or -1 on error
 */
int _printf(const char *format, ...)
{
	va_list ap;
	int count = 0;
	unsigned int i = 0;
	char *s;

	if (format == NULL)
		return (-1);

	va_start(ap, format);

	while (format[i] != '\0')
	{
		if (format[i] != '%')
		{
			count += _putchar(format[i]);
			i++;
			continue;
		}

		i++;
		if (format[i] == '\0')
		{
			va_end(ap);
			return (-1);
		}

		if (format[i] == 'c')
		{
			count += _putchar(va_arg(ap, int));
		}
		else if (format[i] == 's')
		{
			s = va_arg(ap, char *);
			if (s == NULL)
				s = "(null)";
			while (*s)
			{
				count += _putchar(*s);
				s++;
			}
		}
		else if (format[i] == '%')
		{
			count += _putchar('%');
		}
		else if (format[i] == 'd' || format[i] == 'i')
		{
			count += print_int(va_arg(ap, int));
		}
		else if (format[i] == 'b')
		{
			/* read as int (correct variadic type), then print */
			int v = va_arg(ap, int);
			unsigned int u;

			if (v < 0)
			{
				count += _putchar('-');
				u = (unsigned int)(-(long)v); /* avoid INT_MIN overflow */
			}
			else
			{
				u = (unsigned int)v;
			}
			count += print_bin(u);
		}
		else
		{
			/* unknown specifier: print verbatim */
			count += _putchar('%');
			count += _putchar(format[i]);
		}
		i++;
	}

	va_end(ap);
	return (count);
}
