#include "main.h"

/**
* print_octal - Converts an integer to its octal representation and outputs it.
* @args: Variable argument list containing the integer to convert
* @format: Structure containing formatting flags
* Return: The total number of characters printed
* Authors: Evans Adu and Enoch Kabange
*/

int print_octal(va_list args, flag_settings *format)
{
unsigned long int number = va_arg(args, unsigned long int);
int length = 0;
char *octal_str = convert_to_base(number, 8, 0);

if (format->hash == 1 && octal_str[0] != '0')
length += _putchar('0');

length += _puts(octal_str);

return (length);
}
