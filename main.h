#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <Stdio.h>
#include <unistd.h>

/* Declaration of functions to be used in the printf project */
int _printf(const char *format, ...);
void handle_format_specifier(char specifier, va_list args, unsigned int *count, unsigned int *i);
int print_string(char *str);
#endif /* MAIN_H */
