#include "main.h"

/**
 * handle_r - Handles the %r specifier (reversed string)
 * @args: argument list
 * @buffer: buffer array to handle output
 * @buffer_index: index in buffer array
 * @width: field width
 * @precision: field precision
 * @flags: format flags
 * Return: number of characters printed
 */
int handle_r(va_list args, char *buffer, int *buffer_index, int width, int precision, int flags)
{
    char *str = va_arg(args, char *);
    int actual_len;
    int i;

    if (!str)
        str = "(null)";

    actual_len = 0;
    for (i = 0; str[i] && (precision < 0 || i < precision); i++)
        actual_len++;

    for (i = actual_len - 1; i >= 0; i--)
        _putchar(str[i], buffer, buffer_index);

    /* Handle field width */
    if (flags & FLAG_MINUS)
    {
        while (width > actual_len)
        {
            _putchar(' ', buffer, buffer_index);
            actual_len++;
            width--;
        }
    }
    else
    {
        char pad_char = (flags & FLAG_ZERO) ? '0' : ' ';
        while (width > actual_len)
        {
            _putchar(pad_char, buffer, buffer_index);
            actual_len++;
            width--;
        }
    }

    return (actual_len);
}

/**
 * handle_R - Handles the %R specifier (ROT13)
 * @args: argument list
 * @buffer: buffer array to handle output
 * @buffer_index: index in buffer array
 * @width: field width
 * @precision: field precision
 * @flags: format flags
 * Return: number of characters printed
 */
int handle_R(va_list args, char *buffer, int *buffer_index, int width, int precision, int flags)
{
    char *str = va_arg(args, char *);
    int i, j;
    int len = 0;
    char rot13[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";
    char alphabet[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";

    if (!str)
        str = "(null)";

    if (precision < 0)
        precision = INT_MAX;

    for (i = 0; str[i] && i < precision; i++)
    {
        if ((str[i] >= 'A' && str[i] <= 'Z') || (str[i] >= 'a' && str[i] <= 'z'))
        {
            for (j = 0; j < 52; j++)
            {
                if (str[i] == alphabet[j])
                {
                    _putchar(rot13[j], buffer, buffer_index);
                    break;
                }
            }
        }
        else
        {
            _putchar(str[i], buffer, buffer_index);
        }
        len++;
    }

    /* Handle field width */
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