#include "main.h"

/**
 * print_char - prints characters
 * @args: input arguments
 * Return: 1 (Success)
 */

int print_char(va_list args)
{
    char c = va_arg(args, int);
    _putchar(c);
    return (1);
}
