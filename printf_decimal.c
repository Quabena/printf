#include "main.h"

/**
 * print_decimal - prints decimals
 * @args: input arguments to be printed
 * Return: number of integers printed
 */

int print_decimal(va_list args)
{
    int n = va_arg(args, int);
    unsigned int num, temp, divisor = 1;
    int count = 0;

    if (n < 0)
    {
        _putchar('-');
        count++;
        num = -n;
    }
    else
    {
        num = n;
    }

    temp = num;

    while (temp / 10)
    {
        divisor *= 10;
        temp /= 10;
    }

    while (divisor)
    {
        _putchar((num / divisor) % 10 + '0');
        divisor /= 10;
        count++;
    }

    return (count);
}
