#include "main.h"

/**
 * handle_b_specifier - Handles the %b specifier (binary)
 * @args: argument list
 * @buffer: buffer array to handle output
 * @buffer_index: index in buffer array
 * @width: field width
 * @precision: field precision
 * @flags: format flags
 * Return: number of characters printed
 */
int handle_b_specifier(va_list args, char *buffer, int *buffer_index, int width, int precision, int flags)
{
    unsigned int n = va_arg(args, unsigned int);
    char bin[32];
    int len = 0, i = 0;

    if (n == 0)
    {
        bin[i++] = '0';
        len++;
    }
    while (n > 0)
    {
        bin[i++] = (n % 2) + '0';
        n /= 2;
        len++;
    }

    /* Handle precision */
    while (len < precision)
    {
        _putchar('0', buffer, buffer_index);
        len++;
    }

    /* Handle field width with flags */
    if (flags & FLAG_MINUS)
    {
        while (--i >= 0)
            _putchar(bin[i], buffer, buffer_index);

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

        while (--i >= 0)
            _putchar(bin[i], buffer, buffer_index);
    }

    return (len);
}
