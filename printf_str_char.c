#include "main.h"

/**
* print_string - Outputs a string to the standard output.
* @args: Variable argument list containing the string to print
* @format: Structure holding formatting flags
* Return: The number of characters printed, or -1 if an error occurs
* Authors: Evans Adu and Enoch Kabange
*/

int print_string(va_list args, flag_settings *format)
{
	char *str = va_arg(args, char *);

	(void)format;

	if (!str)
		str = "(null)";
	return (_puts(str));
}

/**
 * print_char - Outputs a single character to the standard output.
 * @args: Variable argument list containing the character to print
 * @format: Structure holding formatting flags
 * Return: The number of characters printed, which is always 1
 */

int print_char(va_list args, flag_settings *format)
{
	(void)format;
	_putchar(va_arg(args, int));
	return (1);
}
