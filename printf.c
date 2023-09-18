#include "main.h"

/**
 * print_string - A function that prints a string
 *
 * @str: a pointer to the string to be printed.
 * Return: number of characters printed.
 */
int print_string(char *str)
{
	unsigned int i = 0;

	if (str == NULL)
		return (-1);

	while (str[i] != '\0')
	{
		write(1, &str[i], 1);
		i++;
	}
	return (i);
}

/**
 * handle_format_specifier - A function that handles format specifiers.
 *
 * @specifier: the format specifier character ('c', 's', '%').
 * @args: the va_list containing the arguments.
 * @count: a pointer to the count of characters printed.
 * @i: a pointer to the current position in the format string.
 */
void handle_format_specifier(
char specifier, va_list args, unsigned int *count, unsigned int *i
)
{
	char c;

	switch (specifier)
	{
		case 'c':
			c = va_arg(args, int);
			write(1, &c, 1);
			(*count)++;
			(*i)++;
			break;
		case 's':
			(*count) += print_string(va_arg(args, char *));
			(*i)++;
			break;
		case '%':
			write(1, "%", 1);
			(*count)++;
			(*i)++;
			break;
		default:
			write(1, "%", 1);
			write(1, &specifier, 1);
			(*count) += 2;
			(*i)++;
			break;
	}
}

/**
 * _printf - A function that produces output according to a format.
 *
 * @format: a character string that composes of zero or more directives.
 *
 * Return: the number of characters printed (excluding the null byte used to
 * end the output to strings).
 */

int _printf(const char *format, ...)
{
	va_list args;
	unsigned int i = 0, count = 0;

	if (!format || format[0] == '\0')
		return (0);

	va_start(args, format);

	while (format[i])
	{
		if (format[i] == '%' && format[i + 1] != '\0')
			handle_format_specifier(format[i + 1], args, &count, &i);
		else
		{
			write(1, &format[i], 1);
			count++;
		}
		i++;
	}

	va_end(args);

	return (count);
}

