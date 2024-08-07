#include "main.h"

/**
 * handle_c_s_percent - Handles the %c, %s, and %% specifiers
 * @specifier: the format specifier
 * @args: argument list
 * @buffer: buffer array to handle output
 * @buffer_index: index in buffer array
 * @width: field width
 * @precision: field precision
 * @flags: format flags
 * Return: number of characters printed
 */
int handle_c_s_percent(const char *specifier, va_list args, char *buffer, int *buffer_index, int width, int precision, int flags)
{
    int len = 0;
    int i;

    if (*specifier == 'c')
    {
        char c = va_arg(args, int);
        _putchar(c, buffer, buffer_index);
        len = 1;
    }
    else if (*specifier == 's')
    {
        char *str = va_arg(args, char *);
        if (!str)
            str = "(null)";
        if (precision < 0)
            precision = INT_MAX;
        for (i = 0; str[i] && i < precision; i++)
        {
            _putchar(str[i], buffer, buffer_index);
            len++;
        }
    }
    else if (*specifier == '%')
    {
        _putchar('%', buffer, buffer_index);
        len = 1;
    }

    /* Handle field width and flags */
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
