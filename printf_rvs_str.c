#include "main.h"

/**
* reverse_string - Reverses a given string and prints it.
* @args: Variable argument list containing the string to reverse
* @format: Structure containing formatting flags (unused in this function)
* Return: The length of the string
* Authors: Evans Adu and Enoch Kabange
*/

int reverse_string(va_list args, flag_settings *format)
{
int length = 0, index;
char *str = va_arg(args, char *);

(void)format;

if (!str)
str = "(null)";

while (str[length])
length++;

for (index = length - 1; index >= 0; index--)
_putchar(str[index]);

return (length);
}
