#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include <limits.h>
#include <stdlib.h>

/* Define macro for flag values */
#define FLAG_PLUS 1
#define FLAG_SPACE 2
#define FLAG_HASH 4

int handle_flags(const char *format, unsigned int *i);

/* Declaration of functions to be used in the printf project */
int _printf(const char *format, ...);

void handle_format_specifier(char specifier, va_list args, unsigned int *count, unsigned int *i, int flags);

void handle_char(va_list args, unsigned int *count, unsigned int *i);
void handle_string(va_list args, unsigned int *count, unsigned int *i);
void handle_percent(unsigned int *count, unsigned int *i);
void handle_binary(va_list args, unsigned int *count, unsigned int *i);

void handle_integer(va_list args, unsigned int *count, unsigned int *i, int flags);

void handle_nosign(va_list args, unsigned int *count, unsigned int *i);

void handle_octal(va_list args, unsigned int *count, unsigned int *i, int flags);

void handle_hex(va_list args, unsigned int *count, unsigned int *i, int casing, int flags);
void handle_pointer(va_list args, unsigned int *count, unsigned int *i);
void handle_custom_string(va_list args, unsigned int *count, unsigned int *i);
void handle_default(char specifier, unsigned int *count, unsigned int *i);
int print_string(const char *str);
void handle_rot13(va_list args, unsigned int *count, unsigned int *i);
void rot13(char *str);

void reverse_string(char *str);
void handle_reverse(va_list args, unsigned int *count, unsigned int *i);
#endif /* MAIN_H */
