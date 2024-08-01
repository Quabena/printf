#include "main.h"

/**
* print_reverse_str - prints a string a in reversed order
* @args: argument list
* Return: number of characters printed
* Printf project by Evans Adu and Enoch Kabange
*/

int print_reverse_str(va_list args)
{
char *input_string = va_arg(args, char *);
int index, count = 0;

if (input_string == NULL)
input_string = "(null)";
while (input_string[count])
count++;

for (index = count - 1; index >= 0; index--)
_putchar(input_string[index]);

return (count);
}
