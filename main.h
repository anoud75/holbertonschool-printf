#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>

int _printf(const char *format, ...);
int _putchar(char c);
int flush_buffer(void);
int print_char(va_list args);
int print_string(va_list args);
int print_int(va_list args);
int print_percent(void);
int print_number(unsigned int n);
int print_binary(va_list args);
int print_unsigned(va_list args);
int print_octal(va_list args);
int print_hex_lower(va_list args);
int print_hex_upper(va_list args);

#endif
