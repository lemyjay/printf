#include "main.h"
/**
 * handle_char - handles the char specifier.
 *
 * @args: the va_list containing the arguments.
 * @count: a pointer to the count of characters printed.
 * @i: a pointer to the current position in the format string.
 * @casing: 0 for lowercase, 1 for uppercase.
 * @flags: the flags for the specifier
 * @precision: handles precision.
 * @width: handles width.
 */
void handle_char(
va_list args, unsigned int *count, unsigned int *i, int casing, char flags,
int width, int precision)
{
	char c = va_arg(args, int);

	(void) casing;
	(void) flags;
	(void) precision;

	if (width > 0)
	{
		while (width > 1)
		{
			write(1, " ", 1);
			(*count)++;
			width--;
		}
	}

	write(1, &c, 1);
	(*count)++;
	(*i)++;
}

/**
 * print_string - prints a string and returns the number of characters printed.
 *
 * @str: a pointer to the string to be printed.
 * Return: the number of characters to be printed.
 */
int print_string(const char *str)
{
	unsigned int len = 0;

	while (str[len] != '\0')
	{
		write(1, &str[len], 1);
		len++;
	}

	return (len);
}

/**
 * handle_string - handles the string specifier.
 *
 * @args: the va_list containing the arguments.
 * @count: a pointer to the count of characters printed.
 * @i: a pointer to the current position in the format string.
 * @casing: 0 for lowercase, 1 for uppercase.
 * @flags: the flags for the specifier.
 * @width: handles width.
 * @precision: handles precision.
 */
void handle_string(
va_list args, unsigned int *count, unsigned int *i, int casing, char flags,
int width, int precision)
{
	char *str = va_arg(args, char *);
	int len;

	(void) casing;
	(void) flags;

	if (str == NULL)
		str = "(null)";

	len = print_string(str);
	handle_precision(str, precision, &len);

	if (width > len)
	{
		char pad_char = (flags == '0') ? '0' : ' ';

		while (width > len)
		{
			write(1, &pad_char, 1);
			(*count)++;
			width--;
		}
	}

	(*count) += len;
	(*i)++;
}

/**
 * binary_to_string - a function that converts a binary number to a string.
 *
 * @binary: the binary number to convert.
 * Return: a dynamically allocated string representing the binary number.
 * The caller is responsible for freeing the memory.
 */
char *binary_to_string(unsigned int binary)
{
	int length = 0, i;
	unsigned int temp = binary;
	char *buffer;

	do {
		temp >>= 1;
		length++;
	} while (temp > 0);

	buffer = (char *)malloc(length + 1);

	if (buffer == NULL)
		return (NULL);

	for (i = length - 1; i >= 0; i--)
	{
		buffer[i] = (binary & 1) ? '1' : '0';
		binary >>= 1;
	}

	buffer[length] = '\0';

	return (buffer);
}


/**
 * handle_binary - handles the binary specifier.
 *
 * @args: the va_list containing the argument
 * @count: a pointer to the count of characters printed.
 * @i: a pointer to the current position in the format string.
 * @casing: 0 for lowercase, 1 for uppercase.
 * @flags: the flags for the specifier.
 * @width: handles width.
 * @precision: handles precision.
 */
void handle_binary(
va_list args, unsigned int *count, unsigned int *i, int casing, char flags,
int width, int precision)
{
	unsigned int num = va_arg(args, unsigned int);
	char *buffer = binary_to_string(num);
	int len;

	(void) casing;
	(void) flags;
	(void) precision;

	if (buffer == NULL)
		return;

	len = _strlen(buffer);

	if (width > len)
	{
		while (width > len)
		{
			write(1, "0", 1);
			(*count)++;
			width--;
		}
	}

	(*count) += print_string(buffer);

	free(buffer);

	(*i)++;
}
