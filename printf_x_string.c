#include "main.h"

/**
* print_special_str - prints a string with special character in hex
* @args: argument list
* Return: number of characters printed
* Printf project by Evans Adu and Enoch Kabange
*/

int print_special_str(va_list args)
{
char *str = va_arg(args, char *);
int index, len = 0, char_value;

if (str == NULL)
str = "(null)";

for (index = 0; str[index] != '\0'; index++)
{
if (str[index] < 32 || str[index] >= 127)
{
_putchar('\\');
_putchar('x');
len += 2;

char_value = str[index];

if (char_value < 16)
{
_putchar('0');
len++;
}

len += print_hex_extra(char_value);
}
else
{
_putchar(str[index]);
len++;
}
}

return (len);
}
