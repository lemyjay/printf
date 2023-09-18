#include "main.h"

/**
 * print_string - A function that prints a string
 * created by Lemyjay and Samuel
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
 * print_binary - a function that prints an integer in binary
 * @num: the integer to be printed
 * @count: a pointer to the count of characters
 */

void print_binary(int num, unsigned int *count)
{
	unsigned int mask = 1U << 31;
	while (mask > 0)
	{
		char bit = ((num & mask) != 0) ? '1' : '0';
		write(1, &bit, 1);
		(*count)++;
		mask >>= 1;
	}
}

/** 
 * print_integer - a function that prints an integer
 * @num: integer to be printed
 * @count: pointer to the count of characters
 */

void print_integer(int num, unsigned int *count)
{
	char buffer[12];
	int index = 0;
	if (num < 0)
	{
		write(1, "-", 1);
		(*count)++;
		num = -num;
	}

	do
	{
		buffer[index++] = num % 10 + '0';
		num /= 10;
	}
	while (num > 0);
	while (index > 0)
	{
		write(1, &buffer[--index], 1);
		(*count)++;
	}
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
	char *s;
	int num;

	switch (specifier)
	{
		case 'c':
			c = va_arg(args, int);
			write(1, &c, 1);
			(*count)++;
			(*i)++;
			break;
		case 's':
			s = va_arg(args, char *);

			if (s == NULL)
			{
				write(1, "(null)", 6);
				(*count) += 6;
			}
			else
				(*count) += print_string(s);
			(*i)++;
			break;
		case '%':
			write(1, "%", 1);
			(*count)++;
			(*i)++;
			break;
		case 'b':
			num = va_arg(args, int);
			print_binary(num, count);
			(*i)++;
			break;
		case 'd':
		case 'i':
			num = va_arg(args, int);
			print_integer(num, count);
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

	if (format == NULL)
		return (-1);

	va_start(args, format);

	while (format[i] != '\0' && format)
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

