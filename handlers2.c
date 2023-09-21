#include "main.h"
/**
 * octal_to_string -a function that converts an octal number to a string.
 *
 * @octal: the octal number to convert.
 * Return: a dynamically allocated string representing the octal number.
 * The caller is responsible for freeing the memory.
 */
char *octal_to_string(unsigned long octal)
{
	int length = 0, index;
	char *buffer;
	unsigned long temp = octal;

	do {
		temp /= 8;
		length++;
	} while (temp > 0);

	buffer = (char *)malloc(length + 1);

	if (buffer == NULL)
		return (NULL);

	index = length - 1;

	do {
		buffer[index--] = (octal % 8) + '0';
		octal /= 8;
	} while (octal > 0);

	buffer[length] = '\0';

	return (buffer);
}

/**
 * handle_octal - a function that handles the octal specifier.
 *
 * @args: the va_list containing the argument.
 * @count: a pointer to the count of characters printed.
 * @i: a pointer to the current position in the format string.
 * @casing: 0 for lowercase, 1 for uppercase.
 * @flags: the flags for the specifier.
 */
void handle_octal(
va_list args, unsigned int *count, unsigned int *i, int casing, char flags)
{
	unsigned long octal;
	char *buffer;

	(void) casing;

	if (flags == 'l')
	{
		octal = va_arg(args, unsigned long);
		buffer = octal_to_string(octal);
	}
	else if (flags == 'h')
	{
		octal = va_arg(args, int);
		buffer = octal_to_string((unsigned int)(unsigned short)octal);
	}
	else
	{
		octal = va_arg(args, unsigned int);
		buffer = octal_to_string((unsigned int)octal);
	}

	if (buffer == NULL)
		return;

	if (flags == '#' && octal != 0)
	{
		write(1, "0", 1);
		(*count)++;
	}

	(*count) += print_string(buffer);

	free(buffer);

	(*i)++;
}

/**
 * hex_to_string - a function that converts a hexadecimal number to a string.
 *
 * @hex: the hexadecimal number to convert.
 * @casing: 0 for lowercase, 1 for uppercase.
 * Return: a dynamically allocated string representing the hexadecimal number.
 * The caller is responsible for freeing the memory.
 */
char *hex_to_string(unsigned long hex, int casing)
{
	const char *hex_chars;
	int length = 0, index;
	unsigned long temp = hex;
	char *buffer;

	hex_chars = (casing == 0) ? "0123456789abcdef" : "0123456789ABCDEF";

	do {
		temp /= 16;
		length++;
	} while (temp > 0);

	buffer = (char *)malloc(length + 1);

	if (buffer == NULL)
		return (NULL);

	index = length - 1;

	do {
		buffer[index--] = hex_chars[hex % 16];
		hex /= 16;
	} while (hex > 0);

	buffer[length] = '\0';

	return (buffer);
}

/**
 * handle_hex - a function that handles the hexadecimal specifier.
 *
 * @args: the va_list containing the argument.
 * @count: a pointer to the count of characters printed.
 * @i: a pointer to the current position in the format string.
 * @casing: 0 for lowercase, 1 for uppercase.
 * @flags: the flags for the specifier.
 */
void handle_hex(
va_list args, unsigned int *count, unsigned int *i, int casing, char flags)
{
	unsigned long hex;
	char *buffer;

	if (flags == 'l')
	{
		hex = va_arg(args, unsigned long);
		buffer = hex_to_string(hex, casing);
	}
	else if (flags == 'h')
	{
		hex = va_arg(args, unsigned int);
		buffer = hex_to_string((unsigned short)hex, casing);
	}
	else
	{
		hex = va_arg(args, unsigned int);
		buffer = hex_to_string((unsigned int)hex, casing);
	}

	if (buffer == NULL)
		return;

	if (flags == '#' && hex != 0)
	{
		write(1, (casing == 0) ? "0x" : "0X", 2);
		(*count) += 2;
	}

	(*count) += print_string(buffer);

	free(buffer);

	(*i)++;
}

/**
 * handle_percent - a function that handles the percent specifier.
 *
 * @args: the va_list containing the arguments.
 * @count: a pointer to the count of characters printed.
 * @i: a pointer to the current position in the format string.
 * @casing: 0 for lowercase, 1 for uppercase.
 * @flags: the flags for the specifier.
 */
void handle_percent(
va_list args, unsigned int *count, unsigned int *i, int casing, char flags)
{
	(void) casing;
	(void) flags;
	(void) args;

	write(1, "%", 1);
	(*count)++;
	(*i)++;
}
