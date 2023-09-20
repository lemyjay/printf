#include "main.h"

/**
 * reverse_string - a function that reverses a string in place
 *
 * @str: the string to be reversed
 */

void reverse_string(char *str)
{
	int length = strlen(str);
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
 */
void handle_reverse(va_list args, unsigned int *count, unsigned int *i)
{
	char *str = va_arg(ags, char *);

	if (str == NULL)
	{
		write(1, "(null)", 6);
		(*count) += 6;
	}
	else
	{
		reverse_string(str);
		(*count) += print_string(str);
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
 * handle_rot13 - a funtion that handles the custom specifier %R.
 *
 * @args: the va_list containing the arguments.
 * @count: a pointer to the count of characters printed.
 * @i: a pointer to the current position in the format string.
 */
void handle_rot13(va_list args, unsigned int *count, unsigned int *i)
{
	char *str = va_arg(args, char *);

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
}
