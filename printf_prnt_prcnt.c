#include "main.h"

/**
* print_percent - Prints a percentage sign to the standard output.
* @args: Variable argument list (unused in this function)
* @format: Structure containing formatting flags (unused in this function)
* Return: The number of characters printed, which is always 1
* Authors: Evans Adu and Enoch Kabange
*/

int print_percent(va_list args, flag_settings *format)
{
(void)args;
(void)format;
return (_putchar('%'));
}
