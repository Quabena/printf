#include "main.h"

/**
* convert_to_base - Converts an unsigned long integer to a
* string representation
* @number: The number to convert
* @base: The base for conversion (e.g., 2 for binary, 16 for hexadecimal)
* @is_lowercase: Determines if the hexadecimal digits should be lowercase
* Return: Pointer to the resulting string representation
* Authors: Evans Adu and Enoch Kabange
*/

char *convert_to_base(unsigned long int number, int base, int is_lowercase)
{
	static char *digits;
	static char buffer[50];
	char *pntr;

	digits = (is_lowercase)
				 ? "0123456789abcdef"
				 : "0123456789ABCDEF";
	pntr = &buffer[49];
	*pntr = '\0';
	do {
		*--pntr = digits[number % base];
		number /= base;
	} while (number != 0);

	return (pntr);
}
