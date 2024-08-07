#include "main.h"

/**
 * handle_uoxX_specifier - Handles the %u, %o, %x, and %X specifiers
 * @args: argument list
 * @buffer: buffer array to handle output
 * @buffer_index: index in buffer array
 * @width: field width
 * @precision: field precision
 * @flags: format flags
 * @length_mod: length modifier
 * Return: number of characters printed
 */
int handle_uoxX_specifier(va_list args, char *buffer, int *buffer_index, int width, int precision, int flags, int length_mod, char specifier)
{
    unsigned long num;
    int len = 0;
    int base, is_upper = 0;

    /* Determine the base and if uppercase is needed */
    if (specifier == 'u')
        base = 10;
    else if (specifier == 'o')
        base = 8;
    else if (specifier == 'x')
    {
        base = 16;
        is_upper = 0;
    }
    else if (specifier == 'X')
    {
        base = 16;
        is_upper = 1;
    }
    else
        return (0); /* Invalid specifier */

    /* Determine the length of the number */
    if (length_mod == LENGTH_LONG)
        num = va_arg(args, unsigned long);
    else
        num = va_arg(args, unsigned int);

    /* Handle the 'hash' flag for 'o', 'x', 'X' specifiers */
    if (flags & FLAG_HASH && num != 0)
    {
        if (specifier == 'o')
        {
            _putchar('0', buffer, buffer_index);
            len++;
        }
        else if (specifier == 'x')
        {
            _putchar('0', buffer, buffer_index);
            _putchar('x', buffer, buffer_index);
            len += 2;
        }
        else if (specifier == 'X')
        {
            _putchar('0', buffer, buffer_index);
            _putchar('X', buffer, buffer_index);
            len += 2;
        }
    }

    /* Print the number using _putunsigned */
    len += _putunsigned(num, base, is_upper, flags, width, precision, buffer, buffer_index);

    return (len);
}
