#include "main.h"

/**
 * _printf - produces output according to a format
 * @format: character string with zero or more directives
 *
 * Return: number of characters printed (excluding null byte)
 */
int _printf(const char *format, ...)
{
	va_list args;
	int i = 0, count = 0;

	if (format == NULL)
		return (-1);
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			if (format[i] == '\0')
			{
				flush_buffer();
				return (-1);
			}
			if (format[i] == 'c')
				count += print_char(args);
			else if (format[i] == 's')
				count += print_string(args);
			else if (format[i] == 'S')
				count += print_string_special(args);
			else if (format[i] == '%')
				count += print_percent();
			else if (format[i] == 'd' || format[i] == 'i')
				count += print_int(args);
			else if (format[i] == 'b')
				count += print_binary(args);
			else if (format[i] == 'u')
				count += print_unsigned(args);
			else if (format[i] == 'o')
				count += print_octal(args);
			else if (format[i] == 'x')
				count += print_hex_lower(args);
			else if (format[i] == 'X')
				count += print_hex_upper(args);
			else
			{
				count += _putchar('%');
				count += _putchar(format[i]);
			}
		}
		else
			count += _putchar(format[i]);
		i++;
	}
	flush_buffer();
	va_end(args);
	return (count);
}
