#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include <limits.h>
#include <stdlib.h>

/* Define macro for flag values */
#define FLAG_MINUS (1 << 0)
#define FLAG_PLUS (1 << 1)
#define FLAG_SPACE (1 << 2)
#define FLAG_HASH (1 << 3)

int handle_flags(const char *format, unsigned int *i);

/**
 * struct FormatSpecifier - Represents format specifiers and their handlers.
 *
 * @specifier: the format specifier character.
 * @handler: a function pointer to the handler for this specifier.
 *
 * Description: This structure is used to associate format specifier characters
 * with their corresponding handler functions.
 */
struct FormatSpecifier
{
	char specifier;
	void (*handler)(va_list, unsigned int *, unsigned int *, int, int);
};

/**
 * FormatSpecifier - Typedef for struct FormatSpecifier.
 */
typedef struct FormatSpecifier FormatSpecifier;

/* Declaration of functions to be used in the printf project */
int _printf(const char *format, ...);

void handle_format_specifier(
char specifier, va_list args, unsigned int *count, unsigned int *i, int flags);

void handle_char(
va_list args, unsigned int *count, unsigned int *i, int casing, int flags);

void handle_string(
va_list args, unsigned int *count, unsigned int *i, int casing, int flags);

void handle_percent(
va_list args, unsigned int *count, unsigned int *i, int casing, int flags);

void handle_binary(
va_list args, unsigned int *count, unsigned int *i, int casing, int flags);

void handle_integer(
va_list args, unsigned int *count, unsigned int *i, int casing, int flags);

void handle_nosign(
va_list args, unsigned int *count, unsigned int *i, int casing, int flags);

void handle_octal(
va_list args, unsigned int *count, unsigned int *i, int casing, int flags);

void handle_hex(
va_list args, unsigned int *count, unsigned int *i, int casing, int flags);

void handle_pointer(
va_list args, unsigned int *count, unsigned int *i, int casing, int flags);

void handle_custom_string(
va_list args, unsigned int *count, unsigned int *i, int casing, int flags);

void handle_default(char specifier, unsigned int *count, unsigned int *i);

int print_string(const char *str);

void handle_rot13(
va_list args, unsigned int *count, unsigned int *i, int casing, int flags);

void rot13(char *str);
void reverse_string(char *str);

void handle_reverse(
va_list args, unsigned int *count, unsigned int *i, int casing, int flags);

void padding_spaces(int num_spaces, unsigned int *count);
int get_field_width(const char *format, unsigned int *i);
#endif /* MAIN_H */
