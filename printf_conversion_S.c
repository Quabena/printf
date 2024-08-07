#include "main.h"
/**
 * handle_S_specifier - Handles the %S specifier
 * @args: argument list
 * @buffer: buffer array to handle output
 * @buffer_index: index in buffer array
 * @width: field width
 * @precision: field precision
 * @flags: format flags
 * Return: number of characters printed
 */

int handle_S_specifier(va_list args, char *buffer, int *buffer_index, int width, int precision, int flags)
{
    char *str = va_arg(args, char *);
    int i;
    int len = 0;

    if (!str)
        str = "(null)";

    if (precision < 0)
        precision = INT_MAX;

    for (i = 0; str[i] && i < precision; i++)
    {
        if (str[i] < 32 || str[i] >= 127)
        {
            _putchar('\\', buffer, buffer_index);
            _putchar('x', buffer, buffer_index);
            _putchar("0123456789ABCDEF"[(str[i] >> 4) & 0xF], buffer, buffer_index);
            _putchar("0123456789ABCDEF"[str[i] & 0xF], buffer, buffer_index);
            len += 4;
        }
        else
        {
            _putchar(str[i], buffer, buffer_index);
            len++;
        }
    }

    if (flags & FLAG_MINUS)
    {
        while (width > len)
        {
            _putchar(' ', buffer, buffer_index);
            len++;
            width--;
        }
    }
    else
    {
        char pad_char = (flags & FLAG_ZERO) ? '0' : ' ';
        while (width > len)
        {
            _putchar(pad_char, buffer, buffer_index);
            len++;
            width--;
        }
    }

    return (len);
}
