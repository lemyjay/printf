#include "main.h"

/**
 * get_width - Handles getting the width for printing..
 *
 * @args: the va_list containing the argument for width.
 * @format: the format string being processed.
 * @i: a pointer to the current position in the format string.
 *
 * Return: the width.
 */
int get_width(va_list args, const char *format, unsigned int *i)
{
	unsigned int curr_i = (*i) + 1;
	int width = 0;

	for ( ; format[curr_i] != '\0'; curr_i++)
	{
		if (format[curr_i] == '*')
		{
			curr_i++;
			width = va_arg(args, int);
			break;
		}
		else if (format[curr_i] >= '0' && format[curr_i] <= '9')
		{
			width *= 10;
			width += format[curr_i] - '0';
		}
		else
			break;
	}

	(*i) = curr_i - 1;

	return (width);
}

/**
 * get_precision - Handles getting the precision for printing.
 *
 * @args: the va_list containing the argument for precision.
 * @format: the format string being processed.
 * @i: a pointer to the current position in the format string.
 *
 * Return: the precision.
 */
int get_precision(va_list args, const char *format, unsigned int *i)
{
	unsigned int curr_i = (*i) + 1;
	int precision = -1;

	if (format[curr_i] == '.')
	{
		curr_i++;
		if (format[curr_i] == '*')
		{
			curr_i++;
			precision = va_arg(args, int);
		}
		else if (format[curr_i] >= '0' && format[curr_i] <= '9')
		{
			precision = 0;
			while (format[curr_i] >= '0' && format[curr_i] <= '9')
			{
				precision = precision * 10 + (format[curr_i] - '0');
				curr_i++;
			}
		}
	}

	(*i) = curr_i - 1;

	return (precision);
}

/**
 * handle_precision - Handles precision for a string.
 *
 * @str: The string to apply precision to.
 * @precision: The precision value.
 * @num_len: A pointer to the length of the string.
 *
 * Return: a pointer to the modified string, or the original string if no
 * modification is performed.
 */
char *handle_precision(char *str, int precision, int *num_len)
{
	if (precision >= 0 && precision < *num_len)
	{
		char *nstr = malloc(precision + 1);
		int i = 0;

		if (nstr == NULL)
			return (NULL);
		while (str[i] != '\0' && i < precision)
		{
			nstr[i] = str[i];
			i++;
		}
		nstr[i] = '\0';
		*num_len = i;

		return (nstr);
	}

	return (str);
}
