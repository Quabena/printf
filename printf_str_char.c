#include "main.h"

/**
 * print_character - Prints a single character.
 * @args: List of arguments (should contain the character to print)
 * @output_buffer: Buffer array for handling print operations
 * @active_flags: Active formatting flags
 * @field_width: Field width for printing
 * @precision_speci: Precision specification for printing
 * @size_specifier: Size specifier for type conversion
 * Return: Number of characters printed
 */

int print_character(va_list args, char output_buffer[],
                    int active_flags, int field_width, int precision_speci, int size_specifier)
{
    char str = va_arg(args, int);
    return (handler_char_write(str, output_buffer, active_flags, field_width, precision_speci, size_specifier));
}

/**
 * print_string - Prints a string.
 * @args: List of arguments (should contain the string to print)
 * @output_buffer: Buffer array for handling print operations
 * @active_flags: Active formatting flags
 * @field_width: Field width for printing
 * @precision_speci: Precision specification for printing
 * @size_specifier: Size specifier for type casting
 * Return: Number of characters printed
 */

int print_string(va_list args, char output_buffer[],
                 int active_flags, int field_width, int precision_speci, int size_specifier)
{
    int length = 0, index;
    char *str = va_arg(args, char *);

    UNUSED(output_buffer);
    UNUSED(active_flags);
    UNUSED(field_width);
    UNUSED(precision_speci);
    UNUSED(size_specifier);

    if (str == NULL)
    {
        str = "(null)";
        if (precision_speci >= 6)
            str = " ";
    }
    while (str[length] != '\0')
        length++;
    if (precision_speci >= 0 && precision_speci < length)
        length = precision_speci;
    if (field_width > length)
    {
        if (active_flags & MINUS_FLAG)
        {
            write(1, &str[0], length);
            for (index = field_width - length; index > 0; index--)
                write(1, " ", 1);
            return (field_width);
        }
        else
        {
            for (index = field_width - length; index > 0; index--)
                write(1, " ", 1);
            write(1, &str[0], length);
            return (field_width);
        }
    }
    return (write(1, str, length));
}