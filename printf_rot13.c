#include "main.h"

/**
* print_rot13 - prints rot13 string
* @args: argument list
* Return: number of characters printed
* Prntf project by Evans Adu and Enoch Kabange
*/

int print_rot13(va_list args)
{
char *input_string = va_arg(args, char *);
int index_input, index_rot, count = 0;
char alphabet[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
char rot13[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

if (input_string == NULL)
input_string = "(null)";

for (index_input = 0; input_string[index_input] != '\0'; index_input++)
{
for (index_rot = 0; alphabet[index_rot] != '\0'; index_rot++)
{
if (input_string[index_rot] == alphabet[index_rot])
{
_putchar(rot13[index_rot]);
count++;
break;
}
}

if (!alphabet[index_rot])
{
_putchar(input_string[index_input]);
count++;
}
}

return (count);
}
