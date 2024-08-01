#include "main.h"

/**
* print_integer - prints an integer
* @args: list of arguments
* Return: number of characters printed
* Printf project by Evans Adu and Enoch Kabange
*/

int print_integer(va_list args)
{
int value = va_arg(args, int);
int original_value = value;
int divisor = 1;
int last_digit = value % 10;
int char_count = 1;
int temp_value;
 
if (original_value < 0)
{
_putchar('-');
original_value = -original_value;
last_digit = -last_digit;
char_count++;
}

temp_value = original_value;

while (temp_value / 10 != 0)
{
divisor *= 10;
temp_value /= 10;
}

while (divisor > 0)
{
_putchar((original_value / divisor) +'0');
original_value %= divisor;
divisor /= 10;
char_count++;
}

_putchar(last_digit + '0');

return (char_count);
}
