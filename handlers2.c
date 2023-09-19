#include "main.h"
/**
 * octal_to_string - converts an octal number to a string.
 *
 * @octal: the octal number to convert.
 * Return: a dynamically allocated string representing the octal number.
 * The caller is responsible for freeing the memory.
 */
char *octal_to_string(unsigned int octal)
{
	int length = 0, index;
	char *buffer;
	unsigned int temp = octal;

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
 * handle_octal - handles the octal specifier.
 *
 * @args: the va_list containing the argument.
 * @count: a pointer to the count of characters printed.
 * @i: a pointer to the current position in the format string.
 */
void handle_octal(va_list args, unsigned int *count, unsigned int *i)
{
	unsigned int octal = va_arg(args, unsigned int);
	char *buffer = octal_to_string(octal);

	if (buffer == NULL)
		return;

	(*count) += print_string(buffer);

	free(buffer);

	(*i)++;
}

/**
 * hex_to_string - converts a hexadecimal number to a string.
 *
 * @hex: the hexadecimal number to convert.
 * @casing: 0 for lowercase, 1 for uppercase.
 * Return: a dynamically allocated string representing the hexadecimal number.
 * The caller is responsible for freeing the memory.
 */
char *hex_to_string(unsigned int hex, int casing)
{
	const char *hex_chars;
	int length = 0, index;
	unsigned int temp = hex;
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
 * handle_hex - handles the hexadecimal specifier.
 *
 * @args: the va_list containing the argument.
 * @count: a pointer to the count of characters printed.
 * @i: a pointer to the current position in the format string.
 * @casing: 0 for lowercase, 1 for uppercase.
 */
void handle_hex(va_list args, unsigned int *count, unsigned int *i, int casing)
{
	unsigned int hex = va_arg(args, unsigned int);
	char *buffer = hex_to_string(hex, casing);

	if (buffer == NULL)
		return;

	(*count) += print_string(buffer);

	free(buffer);

	(*i)++;
}

/**
 * handle_percent - handles the percent specifier.
 *
 * @count: a pointer to the count of characters printed.
 * @i: a pointer to the current position in the format string.
 */
void handle_percent(unsigned int *count, unsigned int *i)
{
	write(1, "%", 1);
	(*count)++;
	(*i)++;
}