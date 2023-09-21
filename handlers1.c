#include "main.h"

/**
 * handle_long_min - helper function to handle INT_MIN and LONG_MIN
 *
 * @n: to determine if INT_MIN or LONG_MIN
 *
 * Return: buffer.
 */

static char *handle_long_min(int n)
{
	char imin_str[] = "-2147483648"; /* For INT_MIN */
	char lmin_str[] = "-9223372036854775808"; /* For LONG_MIN */
	int i, length;
	char *buffer;

	if (n == 1)
		length = sizeof(lmin_str) - 1;
	else if (n == 0)
		length = sizeof(imin_str) - 1;

	buffer = (char *)malloc(length + 1);

	if (buffer == NULL)
		return (NULL);

	if (n == 1)
	{
		for (i = 0; i < length; i++)
			buffer[i] = lmin_str[i];
	}
	else if (n == 0)
	{
		for (i = 0; i < length; i++)
			buffer[i] = imin_str[i];
	}

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
char *int_to_string(long num)
{
	int temp, length = 1, index, is_negative = 0;
	char *buffer;

	if (num < 0)
	{
		if (num == LONG_MIN)
			return (handle_long_min(1));
		else if (num == INT_MIN)
			return (handle_long_min(0));
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
 * nosign_to_string - converts an unsigned integer to a string.
 *
 * @num: the unsigned integer to convert.
 * Return: a dynamically allocated string representing the unsigned integer.
 * The caller is responsible for freeing the memory.
 */
char *nosign_to_string(unsigned long num)
{
	int index, length = 1;
	unsigned long temp = num;
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
 * @casing: 0 for lowercase, 1 for uppercase.
 * @flags: the flags for the specifier.
 * @width: handles width.
 * @precision: handles precision.
 */
void handle_integer(
va_list args, unsigned int *count, unsigned int *i, int casing, char flags,
int width, int precision)
{
	long num;
	char *buffer;

	if (flags == 'l')
	{
		num = va_arg(args, long);
		buffer = int_to_string(num);
	}
	else
	{
		num = va_arg(args, int);
		buffer = int_to_string((int)num);
	}

	(void) casing;
	(void) width;
	(void) precision;

	if (buffer == NULL)
		return;

	if (flags == '+' && num >= 0)
	{
		write(1, "+", 1);
		(*count)++;
	}
	else if (flags == ' ' && num >= 0)
	{
		write(1, " ", 1);
		(*count)++;
	}

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
 * @casing: 0 for lowercase, 1 for uppercase.
 * @flags: the flags for the specifier
 * @width: handles width.
 * @precision: handles precision..
 */
void handle_nosign(
va_list args, unsigned int *count, unsigned int *i, int casing, char flags,
int width, int precision)
{
	unsigned long num;
	char *buffer;

	(void) casing;
	(void) width;
	(void) precision;

	if (flags == 'l')
	{
		num = va_arg(args, unsigned long);
		buffer = nosign_to_string(num);
	}
	else if (flags == 'h')
	{
		num = va_arg(args, unsigned int);
		buffer = nosign_to_string((unsigned short)num);
	}
	else
	{
		num = va_arg(args, unsigned int);
		buffer = nosign_to_string((unsigned int)num);
	}

	if (buffer == NULL)
		return;

	(*count) += print_string(buffer);
	free(buffer);
	(*i)++;
}
