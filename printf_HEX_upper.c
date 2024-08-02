#include "main.h"

/**
* print_hex_upper - Outputs an unsigned integer as an
* uppercase hexadecimal string.
* @args: Variable argument list containing the integer to convert
* @format: Structure containing formatting flags (used for hash flag)
* Return: The number of characters printed
* Authors: Evans Adu and Enoch Kabange
*/

int print_hex_upper(va_list args, flag_settings *format)
{
	int length = 0;
	unsigned long int number = va_arg(args, unsigned long int);
	char *hex_str = convert_to_base(number, 16, 0);

	if (format->hash == 1 && hex_str[0] != '0')
		length += _puts("0X");
	length += _puts(hex_str);
	return (length);
}

