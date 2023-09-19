#include "main.h"

/**
 * hanlde_default - Handles the default case for unrecognized format specifiers
 *
 * @specifier: the unrecognized format specifier character.
 * @count: a pointer to the count of characters printed.
 * @i: a pointer to the current position in the format string.
 */
void handle_default(char specifier, unsigned int *count, unsigned int *i)
{
	write(1, "%", 1);
	write(1, &specifier, 1);
	(*count) += 2;
	(*i)++;
}

/**
 * print_hex - prints a hexadecimal number (always 2 characters wide).
 *
 * @num: the number to print in hexadecimal.
 * @count: a pointer to the count of characters printed.
 */
void print_hex(unsigned char num, unsigned int *count)
{
	char hex_chars[] = "0123456789ABCDEF";
	char hex[2];

	hex[0] = hex_chars[(num >> 4) & 0xF];
	hex[1] = hex_chars[num & 0xF];

	write(1, hex, 2);
	(*count) += 2;
}

/**
 * print_hexPointer - converts a hexadecimal number to a string and prints it.
 *
 * @hex: the hexadecimal number to convert and print.
 * @count: a pointer to the count of characters printed.
 */
void print_hexPointer(unsigned long hex, unsigned int *count)
{
	char hex_chars[] = "0123456789abcdef";
	char *buffer;
	int index = 0, length = 0;
	unsigned long temp = hex;

	if (hex == 0)
	{
		write(1, "0", 1);
		(*count)++;
	}
	else
	{
		do {
			temp /= 16;
			length++;
		} while (temp > 0);

		buffer = (char *)malloc(length);

		if (buffer == NULL)
			return;

		while (hex != 0)
		{
			buffer[index++] = hex_chars[hex % 16];
			hex /= 16;
		}

		while (index > 0)
		{
			write(1, &buffer[--index], 1);
			(*count)++;
		}

		free(buffer);
	}
}

/**
 * handle_custom_string - handles the custom string specifier %S.
 *
 * @args: the va_list containing the arguments.
 * @count: a pointer to the count of characters printed.
 * @i: a pointer to the current position in the format string.
 */
void handle_custom_string(va_list args, unsigned int *count, unsigned int *i)
{
	char *str = va_arg(args, char *);
	int j;

	if (str == NULL)
	{
		write(1, "(null)", 6);
		(*count) += 6;
	}
	else
	{
		for (j = 0; str[j] != '\0'; j++)
		{
			if (str[j] < 32 || str[j] >= 127)
			{
				write(1, "\\x", 2);
				(*count) += 2;
				print_hex(str[j], count);
			}
			else
			{
				write(1, &str[j], 1);
				(*count)++;
			}
		}
	}

	(*i)++;

}

/**
 * handle_pointer - handles the pointer specifier %p.
 *
 * @args: the va_list containing the arguments.
 * @count: a pointer to the count of characters printed.
 * @i: a pointer to the current position in the format string.
 */
void handle_pointer(va_list args, unsigned int *count, unsigned int *i)
{
	void *ptr = va_arg(args, void *);

	if (ptr == NULL)
	{
		write(1, "(nil)", 5);
		(*count) += 5;
	}
	else
	{
		write(1, "0x", 2);
		(*count) += 2;
		print_hexPointer((unsigned long)ptr, count);
	}

	(*i)++;
}
