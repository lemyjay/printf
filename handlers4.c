#include "main.h"

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
