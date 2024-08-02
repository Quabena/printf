#include "main.h"

/**
* print_hex_lower - Outputs an unsigned integer as a
* lowercase hexadecimal string.
* @args: Variable argument list containing the integer to convert
* @format: Structure containing formatting flags
* Return: The number of characters printed
* Authors: Evans Adu and Enoch Kabange
*/

int print_hex_lower(va_list args, flag_settings *format)
{
unsigned long int number = va_arg(args, unsigned long int);
int length = 0;

char *hex_str = convert_to_base(number, 16, 1);

if (format->hash == 1 && hex_str[0] != '0')
length += _puts("0x");
length += _puts(hex_str);
return (length);
}
