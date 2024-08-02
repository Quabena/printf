#include "main.h"

/**
* print_address - Prints the address of a pointer in
* hexadecimal format.
* @args: Variable argument list containing the pointer address
* @format: Structure containing formatting flags
* Return: The number of characters printed
* Authors: Evans Adu and Enoch Kabange
*/

int print_address(va_list args, flag_settings *format)
{
	unsigned long int address = va_arg(args, unsigned long int);
	char *address_str;

	register int length = 0;

	(void)format;

	if (!address)
		return (_puts("(nil)"));
	address_str = convert_to_base(address, 16, 1);
	length += _puts("0x");
	length += _puts(address_str);

	return (length);
}
