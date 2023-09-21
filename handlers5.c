#include "main.h"

/**
 * handle_width - Handles width specifier and prints spaces accordingly.
 *
 * @args: the va_list containing the argument for width.
 * @format: the format string being processed.
 * @count: a pointer to the count of characters printed.
 * @i: a pointer to the current position in the format string.
 * @width: a pointer to store the width value.
 */
void handle_width(
va_list args, const char *format, unsigned int *count,
unsigned int *i, int *width)
{
	*width = 0;

	if (format[(*i) + 1] == '*')
	{
		(*width) = va_arg(args, int);
		(*i)++;
	}
	else if (format[(*i) + 1] >= '0' && format[(*i) + 1] <= '9')
	{
		while (format[(*i) + 1] >= '0' && format[(*i) + 1] <= '9')
		{
			(*width) = (*width) * 10 + (format[(*i) + 1] - '0');
			(*i)++;
		}
	}

	if ((*width) > 0)
	{
		char space = ' ';

		while ((*width) > 0)
		{
			write(1, &space, 1);
			(*count)++;
			(*width)--;
		}
	}
}
