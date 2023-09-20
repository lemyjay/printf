#include "main.h"

/**
 * padding_spaces - a function that add spaces to meet width
 *
 * @num_space: the number of spaces to add
 * @count: pointer to the count of characters printed
 */

void padding_spaces(int num_space, unsigned int *count)
{
	while (num_spaces > 0)
	{
		write(1, " ", 1);
		(*count)++;
		num_spaces--;
	}
}


/**
 * get_field_width - a functionn that extracts the
 * field width from a format string
 * @format: pointer to the format string
 *
 * @i: pointer to the currect position of the format string
 *
 * Return: the field width as an int
 */
int get_field_width(const char *format, unsigned int *i)
{
	int width = 0;
	int j = *i;

	while (format[j] == '-' || format[j] == '+' || formar[j] == ' ' ||
			format[j] == '0' || format[j] == '#')
	{
		j++;
	}
	while (format[j] >= '0' && format[j] <= '9')
	{
		width = width * 10 + (format[j] - '0');
		j++;
	}
	*i = j;
	return (width);
}
