#include "main.h"

/**
* print_octal - prints an unsigned integer in octal format
* @args: argument list
* Return: number of characters printed
* Printf project by Evans Adu and Enoch Kabange
*/

int print_octal(va_list args)
{
unsigned int value = va_arg(args, unsigned int);
int char_count = 0, index;
unsigned int temp_value = value;
int *digits;

while (value / 8 != 0)
{
value /= 8;
char_count++;
}

char_count++;

digits = malloc(char_count *sizeof(int));

for (index = 0; index < char_count; index++)
{
digits[index] = temp_value % 8;
temp_value /= 8;
}

for (index = char_count - 1; index >= 0; index--)
{
_putchar(digits[index] + '0');
}

free(digits);

return (char_count);
}
