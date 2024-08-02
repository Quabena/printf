#include "main.h"

/**
* apply_flags - Processes and sets formatting flags based on the
* format specifier.
* @specifier: The flag character found in the format string
* @format: Pointer to the structure holding current flag settings
* Return: 1 if a flag was set, 0 otherwise
* Authors: Evans Adu and Enoch Kabange
*/

int apply_flags(char specifier, flag_settings *format)
{
	int flag_set = 0;

	switch (specifier)
	{
	case '+':
		format->plus = 1;
		flag_set = 1;
		break;
	case ' ':
		format->space = 1;
		flag_set = 1;
		break;
	case '#':
		format->hash = 1;
		flag_set = 1;
		break;
	case '0':
		format->zero = 1;
		flag_set = 1;
		break;
	case '-':
		format->negative = 1;
		flag_set = 1;
		break;
	}
	return (flag_set);
}
