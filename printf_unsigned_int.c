#include "main.h"
#include <stdarg.h>

/**
* print_unsigned_int - Prints an unsigned integer in decimal format.
* @args: Variable argument list containing the unsigned integer to print
* @format: Structure containing formatting flags (unused in this function)
* Return: The number of characters printed
* Authors: Evans Adu and Enoch Kabange
*/

int print_unsigned_int(va_list args, flag_settings *format)
{
	unsigned int value = va_arg(args, unsigned int);
	char *str_rep = convert_to_base(value, 10, 0);

	(void)format;
	return (_puts(str_rep));
}

/**
 * get_integer - Recursively prints the digits of an integer.
 * @number: The integer whose digits are to be printed
 */
void get_integer(int number)
{
	unsigned int abs_value;

	if (number < 0)
	{
		_putchar('-');
		abs_value = -number;
	}
	else
	{
		abs_value = number;
	}

	if (abs_value / 10)
		get_integer(abs_value / 10);
	_putchar((abs_value % 10) + '0');
}
