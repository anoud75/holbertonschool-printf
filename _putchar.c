#include "main.h"

#define BUFFER_SIZE 1024

static char buffer[BUFFER_SIZE];
static int buffer_index = 0;

/**
 * flush_buffer - writes buffer content to stdout and resets index
 *
 * Return: number of characters written
 */
int flush_buffer(void)
{
	int written = 0;

	if (buffer_index > 0)
	{
		written = write(1, buffer, buffer_index);
		buffer_index = 0;
	}
	return (written);
}

/**
 * _putchar - writes the character c to buffer
 * @c: The character to print
 *
 * Return: On success 1
 */
int _putchar(char c)
{
	if (buffer_index >= BUFFER_SIZE)
		flush_buffer();

	buffer[buffer_index++] = c;
	return (1);
}
