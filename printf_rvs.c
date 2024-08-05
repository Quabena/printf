#include "main.h"

/**
 * print_reverse_string - A function that prints a string in reverse order.
 * @args: List of arguments (should contain the string to reverse)
 * @output_buffer: Buffer array for handling print operations
 * @active_flags: Active formatting flags
 * @field_width: Field width for printing
 * @precision_preci: Precision specification for printing
 * @size_specifier: Size specifier for type casting
 * Return: Number of characters printed
 */

int print_reverse_string(va_list args, char output_buffer[],
                         int active_flags, int field_width, int precision_speci, int size_specifier)
{
    char *str;
    int index, charac_count = 0;

    UNUSED(output_buffer);
    UNUSED(active_flags);
    UNUSED(field_width);
    UNUSED(size_specifier);

    str = va_arg(args, char *);

    if (str == NULL)
    {
        UNUSED(precision_speci);

        str = "(null)";
    }
    for (index = 0; str[index]; index++)
        ;
    for (index = index - 1; index >= 0; index--)
    {
        char z = str[index];
        write(1, &z, 1);
        charac_count++;
    }
    return (charac_count);
}