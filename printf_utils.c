#include "main.h"

/**
 * _putchar - Writes the character c to the buffer
 * @c: The character to print
 * @buffer: Buffer to hold the output
 * @buffer_index: Current index in the buffer
 * Return: On success 1.
 */
int _putchar(char c, char *buffer, int *buffer_index)
{
    if (*buffer_index >= BUFFER_SIZE)
    {
        write(1, buffer, *buffer_index);
        *buffer_index = 0;
    }
    buffer[*buffer_index] = c;
    (*buffer_index)++;
    return (1);
}

/**
 * _putstr - Writes the string to the buffer
 * @str: The string to print
 * @width: Field width
 * @precision: Precision
 * @buffer: Buffer to hold the output
 * @buffer_index: Current index in the buffer
 * Return: Number of characters printed
 */
int _putstr(char *str, int width, int precision, char *buffer, int *buffer_index)
{
    int i, len = 0;

    if (!str)
        str = "(null)";
    while (str[len])
        len++;

    if (precision >= 0 && precision < len)
        len = precision;

    while (width > len)
    {
        _putchar(' ', buffer, buffer_index);
        width--;
    }

    for (i = 0; i < len; i++)
        _putchar(str[i], buffer, buffer_index);

    return (len);
}

/**
 * _putnum - Writes a number to the buffer
 * @num: The number to print
 * @base: The base for the number (e.g., 10 for decimal, 16 for hex)
 * @is_upper: Flag for uppercase hexadecimal letters
 * @flags: Flags for formatting
 * @width: Field width
 * @precision: Precision
 * @buffer: Buffer to hold the output
 * @buffer_index: Current index in the buffer
 * Return: Number of characters printed
 */
int _putnum(long num, int base, int is_upper, int flags, int width, int precision, char *buffer, int *buffer_index)
{
    int len = 0, negative = 0, pad_zero = 0;
    char num_str[50], *digits;

    digits = is_upper ? "0123456789ABCDEF" : "0123456789abcdef";

    if (num == 0 && precision == 0)
        return (0);

    if (num < 0)
    {
        negative = 1;
        num = -num;
    }

    while (num)
    {
        num_str[len++] = digits[num % base];
        num /= base;
    }

    if (precision > len)
        pad_zero = precision - len;

    len += pad_zero;

    if (negative || (flags & FLAG_PLUS) || (flags & FLAG_SPACE))
        len++;

    /* Handle width and flags */
    if (!(flags & FLAG_MINUS) && (width > len))
    {
        char pad_char = (flags & FLAG_ZERO) ? '0' : ' ';
        while (width-- > len)
            _putchar(pad_char, buffer, buffer_index);
    }

    if (negative)
        _putchar('-', buffer, buffer_index);
    else if (flags & FLAG_PLUS)
        _putchar('+', buffer, buffer_index);
    else if (flags & FLAG_SPACE)
        _putchar(' ', buffer, buffer_index);

    while (pad_zero--)
        _putchar('0', buffer, buffer_index);

    while (len--)
        _putchar(num_str[len], buffer, buffer_index);

    /* Handle width after number for left alignment */
    while (width-- > len + 1)
        _putchar(' ', buffer, buffer_index);

    return (len + 1);
}

/**
 * _putunsigned - Writes an unsigned number to the buffer
 * @num: The unsigned number to print
 * @base: The base for the number (e.g., 10 for decimal, 16 for hex)
 * @is_upper: Flag for uppercase hexadecimal letters
 * @flags: Flags for formatting
 * @width: Field width
 * @precision: Precision
 * @buffer: Buffer to hold the output
 * @buffer_index: Current index in the buffer
 * Return: Number of characters printed
 */
int _putunsigned(unsigned long num, int base, int is_upper, int flags, int width, int precision, char *buffer, int *buffer_index)
{
    int len = 0, pad_zero = 0;
    char num_str[50], *digits;

    digits = is_upper ? "0123456789ABCDEF" : "0123456789abcdef";

    if (num == 0 && precision == 0)
        return (0);

    while (num)
    {
        num_str[len++] = digits[num % base];
        num /= base;
    }

    if (precision > len)
        pad_zero = precision - len;

    len += pad_zero;

    /* Handle width and flags */
    if (!(flags & FLAG_MINUS) && (width > len))
    {
        char pad_char = (flags & FLAG_ZERO) ? '0' : ' ';
        while (width-- > len)
            _putchar(pad_char, buffer, buffer_index);
    }

    while (pad_zero--)
        _putchar('0', buffer, buffer_index);

    while (len--)
        _putchar(num_str[len], buffer, buffer_index);

    /* Handle width after number for left alignment */
    while (width-- > len + 1)
        _putchar(' ', buffer, buffer_index);

    return (len + 1);
}
