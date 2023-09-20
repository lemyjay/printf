#include "main.h"

/**
 * handle_flags - A function that handles flag characters.
 *
 * @i: a pointer to the current position in the format string.
 * @format: the format string.
 *
 * Return: the flags as an integer.
 */
int handle_flags(const char *format, unsigned int *i)
{
	int flags = 0;

	while (format[*i] == '+' || format[*i] == ' ' || format[*i] == '#')
	{
		switch (format[*i])
		{
			case '+':
				flags |= FLAG_PLUS;
				break;
			case ' ':
				flags |= FLAG_SPACE;
				break;
			case '#':
				flags |= FLAG_HASH;
				break;
		}

		(*i)++;
	}

	return (flags);
}


/**
 * handle_format_specifier - A function that handles format specifiers.
 *
 * @specifier: the format specifier character
 * @args: the va_list containing the arguments.
 * @count: a pointer to the count of characters printed.
 * @i: a pointer to the current position in the format string.
 * @flags: the flags for the specifier.
 */
void handle_format_specifier(
char specifier, va_list args, unsigned int *count, unsigned int *i, int flags)
{
	switch (specifier)
	{
		case 'c':
			handle_char(args, count, i);
			break;
		case 's':
			handle_string(args, count, i);
			break;
		case '%':
			handle_percent(count, i);
			break;
		case 'b':
			handle_binary(args, count, i);
			break;
		case 'd':
		case 'i':
			handle_integer(args, count, i, flags);
			break;
		case 'u':
			handle_nosign(args, count, i);
			break;
		case 'o':
			handle_octal(args, count, i, flags);
			break;
		case 'x':
			handle_hex(args, count, i, 0, flags);
			break;
		case 'X':
			handle_hex(args, count, i, 1, flags);
			break;
		case 'S':
			handle_custom_string(args, count, i);
			break;
		case 'p':
			handle_pointer(args, count, i);
			break;
		case 'R':
			handle_rot13(args, count, i);
		default:
			handle_default(specifier, count, i);
			break;
	}
}
