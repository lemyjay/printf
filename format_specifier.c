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
	int j, casing = 0;
	FormatSpecifier formatSpecifiers[] = {
		{'c', handle_char}, {'s', handle_string},
		{'%', handle_percent}, {'b', handle_binary},
		{'d', handle_integer}, {'i', handle_integer},
		{'u', handle_nosign}, {'o', handle_octal},
		{'x', handle_hex}, {'X', handle_hex},
		{'S', handle_custom_string}, {'p', handle_pointer},
		{'R', handle_rot13}, {'r', handle_reverse},
		{'\0', NULL} /* This marks the end of the array */
	};

	for (j = 0; formatSpecifiers[j].specifier != '\0'; j++)
	{
		if (formatSpecifiers[j].specifier == specifier)
		{
			if (specifier == 'X')
				casing = 1;
			formatSpecifiers[j].handler(args, count, i, casing, flags);
			return;
		}
	}

	handle_default(specifier, count, i);
}
