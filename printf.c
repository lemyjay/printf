#include "main.h"

/**
 * _printf - A function that produces output according to a format.
 * this is the main file that contains the printf function
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

	if (format == NULL && format[i] == '\0')
		return (-1);

	va_start(args, format);

	while (format[i] != '\0')
	{
		if (format[i] == '%' && format[i + 1] != '\0')
		{
			int flags = handle_flags(format, &i);

			handle_format_specifier(format[i + 1], args, &count, &i, flags);
		}
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
