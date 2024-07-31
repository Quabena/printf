#include "main.h"

/**
* print_str - prints a string
* @args: argument list
* Return: number of characters printed
* Printf project by Evans Adu and Enoch Kabange
*/

int print_str(va_list args)
{
char *string = va_arg(args, char *);
int itrt;

if (!string)
string = "(null)";

for (itrt = 0; string[itrt] != '\0'; itrt++)
{
_putchar(string[itrt]);
}

return (itrt);
}
