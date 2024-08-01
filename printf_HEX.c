#include "main.h"

/**
 * print_HEX - prints hexadecimal in uppercase
 * @args: arguments expected
 * Return: counter
 */
int print_HEX(va_list args)
{
    unsigned int num = va_arg(args, unsigned int);
    int counter = 0;
    char *hex_digits = "0123456789ABCDEF";
    unsigned int temp = num;

    while (temp)
    {
        counter++;
        temp /= 16;
    }

    while (counter)
    {
        _putchar(hex_digits[(num / (1 << (4 * (counter - 1)))) % 16]);
        counter--;
    }
    return (counter);
}
