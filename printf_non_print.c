#include "main.h"

/**
* print_non_printable - Outputs non-printable characters in a specific format.
* @args: Variable argument list containing the string to process
* @format: Structure containing formatting flags
* Return: The total number of characters printed
* Authors: Evans Adu and Enoch Kabange
*/

int print_non_printable(va_list args, flag_settings *format)
{
	int index = 0, char_count = 0;
	char *hex_str;
	char *str = va_arg(args, char *);

	(void)format;

	if (!str)
		return (_puts("(null)"));

	while (str[index])
	{
		if (str[index] < 32 || str[index] >= 127)
		{
			_puts("\\x");
			char_count += 2;
			hex_str = convert_to_base((unsigned long int)str[index], 16, 1);
			if (!hex_str[1])
				char_count += _putchar('0');
			char_count += _puts(hex_str);
			free(hex_str);
		}
		else
			char_count += _putchar(str[index]);
		index++;
	}

	return (char_count);
}