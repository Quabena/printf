#include "main.h"

/**
 * handle_di_specifier - Handles the %d and %i specifiers
 * @args: argument list
 * @buffer: buffer array to handle output
 * @buffer_index: index in buffer array
 * @width: field width
 * @precision: field precision
 * @flags: format flags
 * @length_mod: length modifier
 * Return: number of characters printed
 */
int handle_di_specifier(va_list args, char *buffer, int *buffer_index, int width, int precision, int flags, int length_mod)
{
    long int num;
    char str[100];
    int i, len, sign = 1;

    if (length_mod == LENGTH_LONG)
        num = va_arg(args, long int);
    else
        num = va_arg(args, int);

    if (num < 0)
    {
        num = -num;
        sign = -1;
    }

    len = snprintf(str, sizeof(str), "%*.*ld", width, precision, num * sign);

    if (sign < 0)
        _putchar('-', buffer, buffer_index);
    else if (flags & FLAG_PLUS)
        _putchar('+', buffer, buffer_index);
    else if (flags & FLAG_SPACE)
        _putchar(' ', buffer, buffer_index);

    for (i = 0; i < len; i++)
        _putchar(str[i], buffer, buffer_index);

    return (len);
}
