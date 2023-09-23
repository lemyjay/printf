#include "main.h"

/**
 * _strlen - a function that calculates the length of a string
 *
 * @str: the string to be measured
 * Return: the length of the string
 */
int _strlen(const char *str)
{
	int length = 0;

	while (str[length] != '\0')
		length++;

	return (length);
}

/**
 * reverse_string - a function that reverses a string in place
 *
 * @str: the string to be reversed
 */

void reverse_string(char *str)
{
	int length = _strlen(str);
	int i, j;
	char temp;

	for (i = 0, j = length - 1; i < j; i++, j--)
	{
		temp = str[i];
		str[i] = str[j];
		str[j] = temp;
	}
}

/**
 * handle_reverse - a function that prints a string in reverse
 * @args: the va_list that contains the argument
 * @count: a pointer to the count of characters printed
 * @i: a pointer to the current position of the string
 * @casing: 0 for lowercase, 1 for uppercase.
 * @flags: the flags for the specifier.
 * @width: handles width.
 * @precision: handles precision.
 */
void handle_reverse(
va_list args, unsigned int *count, unsigned int *i, int casing, char flags,
int width, int precision)
{
	char *str = va_arg(args, char *), *new_str;

	(void) casing;
	(void) flags;

	if (str == NULL)
	{
		write(1, "(null)", 6);
		(*count) += 6;
	}
	else
	{
		int length = _strlen(str);

		new_str = handle_precision(str, precision, &length);
		if (width > length)
		{
			int padding = width - length;

			while (padding > 0)
			{
				write(1, " ", 1);
				(*count)++;
				padding--;
			}
		}
		reverse_string(new_str);
		(*count) += print_string(new_str);
		(new_str != str) ? free(new_str) : (void)0;
	}
	(*i)++;
}

/**
 * rot13 - a function that applies the rot13 algorithm to a string
 * @str: the string that will ne rot13'ed
 */

void rot13(char *str)
{
	while (*str)
	{
		if ((*str >= 'a' && *str <= 'z'))
		{
			if (*str > 'm')
			{
				*str = *str - 13;
			}
			else
			{
				*str = *str + 13;
			}
		}
		else if ((*str >= 'A' && *str <= 'Z'))
		{
			if (*str > 'M')
			{
				*str = *str - 13;
			}
			else
			{
				*str = *str + 13;
			}
		}
		str++;
	}
}

/**
 * handle_rot13 - a funtion that handles the custom specifier %R
 * for rot13
 *
 * @args: the va_list containing the arguments.
 * @count: a pointer to the count of characters printed.
 * @i: a pointer to the current position in the format string.
 * @casing: 0 for lowercase, 1 for uppercase.
 * @flags: the flags for the specifier.
 * @width: handles width.
 * @precision: handles precision.
 */
void handle_rot13(
va_list args, unsigned int *count, unsigned int *i, int casing, char flags,
int width, int precision)
{
	char *str = va_arg(args, char *);

	(void) casing;
	(void) flags;
	(void) precision;
	(void) width;

	if (str == NULL)
	{
		write(1, "(null)", 6);
		(*count) += 6;
	}
	else
	{
		rot13(str);
		(*count) += print_string(str);
	}

	(*i)++;
}
