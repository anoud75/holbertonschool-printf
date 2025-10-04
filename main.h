#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>

/* Core printf and helpers */
int _printf(const char *format, ...);
int _putchar(char c);
int print_int(int n);

/* Custom specifiers */
int print_bin(unsigned int n); /* prints an unsigned int in binary for %b */

#endif /* MAIN_H */
