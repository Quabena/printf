#include "main.h"

/**
 * print_percent - A function that prints the percent sign
 * @args: List of arguments
 * @output_buffer: Array to handle print
 * @active_flags: Active flags specifier
 * @field_width: Width Specifier
 * @precision_speci: Precision 
 * @size_specifier: Size specifier
 * Return: Number of characters printed
 */
int print_percentage(va_list args, char output_buffer[],
                     int active_flags, int field_width, int precision_speci, int size_specifier)
{
    UNUSED(args);
    UNUSED(output_buffer);
    UNUSED(active_flags);
    UNUSED(field_width);
    UNUSED(precision_speci);
    UNUSED(size_specifier);

    return (write(1, "%%", 1));
}
