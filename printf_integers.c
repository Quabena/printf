#include "main.h"

/**
* print_integer - Outputs an integer to the standard output
* with appropriate formatting.
* This function retrieves an integer from the variable argument
* list and prints it,
* applying formatting flags such as space, plus, and zero as needed.
* @args: Variable argument list containing the integer to print
* @format: Format string containing specifiers and text to print
* Return: The total number of characters printed
* Authors: Evans Adu and Enoch Kabange
*/

int print_integer(va_list args, flag_settings *format)

{
	int number = va_arg(args, int);
	int char_count = integer_length(number);

	if (format->space == 1 && format->plus == 0 && number >= 0)
		char_count += _putchar(' ');
	if (format->plus == 1 && number >= 0)
		char_count += _putchar('+');
	if (format->zero == 1 && format->space == 1 && number == 0)
		char_count += _putchar('0');
	if (format->negative == 1 && number < 0)
		char_count += _putchar('-');
	if (number <= 0)
		char_count++;

	get_integer(number);

	return (char_count);
}

/**
* integer_length - Counts the number of digits in an integer.
* @value: The integer whose digits are to be counted
* Return: The length of the integer
* Authors: Evans Adu and Enoch Kabange
*/

int integer_length(int value)
{
	unsigned int digit_count = 0;
	unsigned int abs_value;

	abs_value = (value < 0) ? -value : value;

if (abs_value == 0)
return (1);

	while (abs_value != 0)
	{
		abs_value /= 10;
		digit_count++;
	}

	return (digit_count);
}
