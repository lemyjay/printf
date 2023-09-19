#include "main.h"

/**
 * handle_int_min - helper function to handle INT_MIN
 *
 * Return: buffer.
 */

static char *handle_int_min(void)
{
	char min_str[] = "-2147483648";
	int i, length = sizeof(min_str) - 1;
	char *buffer = (char *)malloc(length + 1);

	if (buffer == NULL)
		return (NULL);

	for (i = 0; i < length; i++)
		buffer[i] = min_str[i];

	buffer[length] = '\0';

	return (buffer);
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
	int temp, length = 1, index, is_negative = 0;
	char *buffer;

	if (num < 0)
	{
		if (num == INT_MIN)
			return (handle_int_min());
		is_negative = 1;
		num = -num;
	}

	temp = num;
	while (temp >= 10)
	{
		temp /= 10;
		length++;
	}

	buffer = (char *)malloc(length + (is_negative ? 2 : 1));
	if (buffer == NULL)
		return (NULL);

	index = length + (is_negative ? 1 : 0);
	buffer[index] = '\0';
	do {
		buffer[--index] = num % 10 + '0';
		num /= 10;
	} while (num > 0);

	if (is_negative)
		buffer[0] = '-';

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
