#include "main.h"

/**
* select_format_function - Determines the appropriate function
* based on the format specifier.
* @specifier: The format specifier character to look up
* Return: Pointer to the function that handles the format specifier,
* or NULL if not found
* Authors: Evans Adu and Enoch Kabange
*/

int (*select_format_function(char specifier))(va_list, flag_settings *)
{
	int index;

	format_specifier_map handlers[] = {
		{'i', print_integer},
		{'s', print_string},
		{'c', print_char},
		{'d', print_integer},
		{'u', print_unsigned_int},
		{'x', print_hex_lower},
		{'X', print_hex_upper},
		{'b', print_binary},
		{'o', print_octal},
		{'R', print_rot13},
		{'r', reverse_string},
		{'S', print_non_printable},
		{'p', print_address},
		{'%', print_percent}};
	int num_handlers = sizeof(handlers) / sizeof(handlers[0]);

	for (index = 0; index < num_handlers; index++)
	{
		if (handlers[index].d == specifier)
		return (handlers[index].format);
	}
	return (NULL);
}
