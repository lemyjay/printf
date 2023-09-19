#include "main.h"

/**
 * encountered_error - used to return -1 at any point in the custom printf
 * function when an error is encounted.
 *
 * Return: -1 for failure.
 */
int encountered_error(void)
{
	return (-1);
}

/**
 * int_to_string - converts an integer to a string.
 *
 * @num: the integer to convert.
 *
 * Return: a dynamically allocated string representing the integer.
 * The caller is responsible for freeing the memory.
 */
char *int_to_string(int num)
{
	int length, temp, index, is_negative = 0;
	char *buffer;

	if (num < 0)
	{
		is_negative = 1;
		if (num == INT_MIN)
		{
			num = -(num + 1) + 1;
		}
		else
			num = -num;
	}

	length = is_negative ? 2 : 1;
	temp = num;
	while (temp > 0)
	{
		temp /= 10;
		length++;
	}

	buffer = (char *)malloc(length + 1);
	if (buffer == NULL)
		return (NULL);

	index = length - 1;
	do {
		buffer[index--] = num % 10 + '0';
		num /= 10;
	} while (num > 0);

	if (is_negative)
		buffer[0] = '-';

	buffer[length] = '\0';

	return (buffer);
}

/**
 * unsigned_int_to_string - converts an unsigned integer to a string.
 *
 * @num: the unsigned integer to convert.
 * Return: a dynamically allocated string representing the unsigned integer.
 * The caller is responsible for freeing the memory.
 */
char *unsigned_int_to_string(unsigned int num)
{
	int index, length = 1;
	unsigned int temp = num;
	char *buffer;

	while (temp >= 10)
	{
		temp /= 10;
		length++;
	}

	buffer = (char *)malloc(length + 1);

	if (buffer == NULL)
		return (NULL);

	index = length - 1;

	do {
		buffer[index--] = num % 10 + '0';
		num /= 10;
	} while (num > 0);

	buffer[length] = '\0';

	return (buffer);
}

/**
 * handle_integer - handles the integer specifier.
 *
 * @args: the va_list containing the arguments.
 * @count: a pointer to the count of characters printed.
 * @i: a pointer to the current position in the format string.
 */
void handle_integer(va_list args, unsigned int *count, unsigned int *i)
{
	int num = va_arg(args, int);
	char *buffer = int_to_string(num);

	if (buffer == NULL)
		return;

	(*count) += print_string(buffer);
	free(buffer);
	(*i)++;
}

/**
 * handle_nosign - handles the unsigned specifier.
 *
 * @args: the va_list containing the argument
 * @count: a pointer to the count of characters printed.
 * @i: a pointer to the current position in the format string.
 */
void handle_nosign(va_list args, unsigned int *count, unsigned int *i)
{
	unsigned int num = va_arg(args, unsigned int);
	char *buffer = unsigned_int_to_string(num);

	if (buffer == NULL)
		return;

	(*count) += print_string(buffer);
	free(buffer);
	(*i)++;
}
