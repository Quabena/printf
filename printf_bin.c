#include "main.h"

/**
 * print_bin - prints an unsigned integer in binary
 * @args: argument list
 * Return: number of characters printed
 */
int print_bin(va_list args)
{
    unsigned int num = va_arg(args, unsigned int);
    int count = 0, i;
    unsigned int temp = num;
    int *arr;

    while (num / 2 != 0)
    {
        num /= 2;
        count++;
    }
    count++;

    arr = malloc(count * sizeof(int));

    for (i = 0; i < count; i++)
    {
        arr[i] = temp % 2;
        temp /= 2;
    }

    for (i = count - 1; i >= 0; i--)
    {
        _putchar(arr[i] + '0');
    }

    free(arr);
    return (count);
}
