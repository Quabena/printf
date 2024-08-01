#include "main.h"

/**
* print_unsigned_int - prints an unsigned integer
* @args: argument list
* Return: number of characters printed
* Printf project by Evans Adu and Enoch Kabange
*/

int print_unsigned_int(va_list args)
{
unsigned int number = va_arg(args, unsigned int);
int digit_count = 0, itrt;
unsigned int temp_num = number;
int *digit_array;

while (number / 10 != 0)
{
number /= 10;
digit_count++;
}
digit_count++;

digit_array = malloc(digit_count *sizeof(int));

for (itrt = 0; itrt < digit_count; itrt++)
{
digit_array[itrt] = temp_num % 10;
temp_num /= 10;
}

for (itrt = digit_count - 1; itrt >= 0; itrt--)
{
_putchar(digit_array[itrt] + '0');
}

free(digit_array);

return (digit_count);
}
