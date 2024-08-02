#include "main.h"

/**
* print_binary - Converts an integer to its binary representation
* and outputs it.
* @args: Variable argument list containing the integer to convert
* @format: Structure containing formatting flags
* Return: The number of characters printed
* Authors: Evans Adu and Enoch Kabange
*/

int print_binary(va_list args, flag_settings *format)
{
	unsigned long int number = va_arg(args, unsigned long int);
	char *binary_str = convert_to_base(number, 2, 0);

	(void)format;
	return (_puts(binary_str));
}


