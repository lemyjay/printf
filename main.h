#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include <limits.h>
#include <stdlib.h>

/* Declaration of functions to be used in the printf project */
int _printf(const char *format, ...);
void handle_format_specifier(
	char specifier, va_list args, unsigned int *count, unsigned int *i);
void handle_char(va_list args, unsigned int *count, unsigned int *i);
void handle_string(va_list args, unsigned int *count, unsigned int *i);
void handle_percent(unsigned int *count, unsigned int *i);
void handle_binary(va_list args, unsigned int *count, unsigned int *i);
void handle_integer(va_list args, unsigned int *count, unsigned int *i);
void handle_nosign(va_list args, unsigned int *count, unsigned int *i);
void handle_octal(va_list args, unsigned int *count, unsigned int *i);
void handle_hex(
	va_list args, unsigned int *count, unsigned int *i, int casing);
void handle_pointer(va_list args, unsigned int *count, unsigned int *i);
void handle_custom_string(va_list args, unsigned int *count, unsigned int *i);
void handle_default(char specifier, unsigned int *count, unsigned int *i);
int print_string(const char *str);

#endif /* MAIN_H */
