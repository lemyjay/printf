#include "main.h"

/**
 * handle_format_specifier - A function that handles the various
 * format specifiers.
 *
 * @specifier: the format specifier character
 * @args: the va_list containing the arguments.
 * @count: a pointer to the count of characters printed.
 * @i: a pointer to the current position in the format string.
 */
void handle_format_specifier(
		char specifier, va_list args, unsigned int *count, unsigned int *i)
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
			handle_integer(args, count, i);
			break;
		case 'u':
			handle_nosign(args, count, i);
			break;
		case 'o':
			handle_octal(args, count, i);
			break;
		case 'x':
			handle_hex(args, count, i, 0);
			break;
		case 'X':
			handle_hex(args, count, i, 1);
			break;
		case 'S':
			handle_custom_string(args, count, i);
			break;
		case 'p':
			handle_pointer(args, count, i);
			break;
		default:
			handle_default(specifier, count, i);
			break;
	}
}
