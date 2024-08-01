#include "main.h"

/**
* print_ptr - prints a pointer address
* @args: argument list
* Return: number of characters printed
* Printf project by Evans Adu and Enoch Kabange
*/

int print_ptr(va_list args)
{
unsigned long int ptr_address = va_arg(args, unsigned long int);
int char_count = 0;

if (!ptr_address)
{
const char *null_rep = "(nil)";

while (*null_rep)
{
_putchar(*null_rep++);
char_count++;
}

return (char_count);
}

_putchar('0');
_putchar('x');
char_count += 2;

char_count += 2;

char_count += print_hex_extra(ptr_address);

return (char_count);
}
