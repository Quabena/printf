#include "main.h"

/**
 * print_non_printable_chars - A func that prints ASCII codes in
 * hexadecimal for non-printable characters
 * @args: List of arguments
 * @output_buffer: Buffer array to manage printing
 * @active_flags: Active flags
 * @field_width: Specified width
 * @precision_speci: Precision specification
 * @size_specifier: Size specifier
 * Return: Number of characters printed
 */

int print_non_printable_chars(va_list args, char output_buffer[],
                              int active_flags, int field_width, int precision_speci, int size_specifier)
{
    int idx = 0, offset = 0;
    char *str = va_arg(args, char *);

    UNUSED(active_flags);
    UNUSED(field_width);
    UNUSED(precision_speci);
    UNUSED(size_specifier);

    if (str == NULL)
        return (write(1, "(null)", 6));
    while (str[idx] != '\0')
    {
        if (printable_char(str[idx]))
            output_buffer[idx + offset] = str[idx];
        else
            offset += add_hex_code(str[idx], output_buffer, idx + offset);
        idx++;
    }
    output_buffer[idx + offset] = '\0';
    return (write(1, output_buffer, idx + offset));
}   