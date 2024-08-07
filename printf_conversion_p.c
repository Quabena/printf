#include "main.h"

/**
 * handle_p_specifier - Handles the %p specifier (pointer)
 * @args: argument list
 * @buffer: buffer array to handle output
 * @buffer_index: index in buffer array
 * @width: field width
 * @precision: field precision
 * @flags: format flags
 * Return: number of characters printed
 */
int handle_p_specifier(va_list args, char *buffer, int *buffer_index, int width, int precision, int flags)
{
    void *ptr = va_arg(args, void *);
    unsigned long addr = (unsigned long)ptr;
    char str[100];
    int i;
    int len = snprintf(str, sizeof(str), "%*.*lx", width, precision, addr);

    (void)flags;

    _putchar('0', buffer, buffer_index);
    _putchar('x', buffer, buffer_index);
    for (i = 0; i < len; i++)
        _putchar(str[i], buffer, buffer_index);

    return (len + 2);
}
