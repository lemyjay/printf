#include "main.h"

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
