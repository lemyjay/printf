#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

/* Declaration of functions to be used in the printf project */
int _printf(const char *format, ...);
void handle_format_specifier(char specifier, va_list args, unsigned int *count, unsigned int *i);
int print_string(char *str);
void print_integer(int num, unsigned int *count);
void print_binary(int num, unsigned int *count);
void print_octal(unsigned int num, unsigned int *count);
void print_hex(unsigned int num, unsigned int *count, int uppercase);
void print_unsigned(unsigned int num, unsigned int *count);
#endif /* MAIN_H */
