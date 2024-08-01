#include "main.h"

/**
* print_hex - prints a hexadecimal representation on an integer
* @args: argument list containing the number to print
* Return: number of characters printed
* Printf project by Evans Adu and Enoch Kabange
*/

int print_hex(va_list args)
{
unsigned int number = va_arg(args, unsigned int);

return (print_hex_extra(number));
}
