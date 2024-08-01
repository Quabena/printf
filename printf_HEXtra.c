#include "main.h"

/**
* print_hex_extra - prints a hexadecimal representation
* @value: the number to be printed in hexadecimal
* Return: number of characters printed
* Printf project by Evans Adu and Enoch Kabange
*/

int print_hex_extra(unsigned long int value)
{
int itrt;
int *digits;
unsigned long int temp = value;
int char_count = 0;

unsigned long int temp_value = value;

while (temp_value / 16 != 0)
{
temp_value /= 16;
char_count++;
}

char_count++;

digits = malloc(char_count *sizeof(int));

for (itrt = 0; itrt < char_count; itrt++)
{
digits[itrt] = temp % 16;
temp /= 16
}

for (itrt = char_count - 1; itrt >= 0; itrt--)
{
if (digits[itrt] > 9)
{
_putchar(digits[itrt] + 'a' - 10);

else
_putchar(digits[itrt] + '0');

}

free(digits);
return (char_count);
}
