#include "main.h"

/**
 * dispatch_format - Handles and prints an argument
 * based on its type
 * @format: The formatted string specifying how to print the arguments
 * @index: Pointer to the current position in the format string
 * @args: List of arguments to be printed
 * @output_buffer: Buffer array to manage printing
 * @active_flags: Active flags that affect the formatting
 * @field_width: Field width for printing
 * @precision_speci: Precision specification for printing
 * @size_specifier: Size specifier for type casting
 * Return: Number of characters printed or -1 if an error occurred
 */

int dispatch_format(const char *format, int *index,
                    va_list args, char output_buffer[], int active_flags, int field_width, int precision_speci, int size_specifier)
{
    int i, len = 0, printed_characters = -1;

    format_handler_t format_handlers[] = {
        {'c', print_character}, {'s', print_string}, {'%', print_percentage}, {'i', print_integer}, {'d', print_integer}, {'b', print_binary_format}, {'u', print_unsigned_integer}, {'o', print_octal}, {'x', print_hex}, {'X', print_hex_uppercase}, {'p', print_pointer}, {'S', print_non_printable_chars}, {'r', print_reverse_string}, {'R', print_rot13_str}, {'\0', NULL}};
    for (i = 0; format_handlers[i].specifier != '\0'; i++)
        if (format[*index] == format_handlers[i].specifier)
            return (format_handlers[i].handler(args, output_buffer, active_flags, field_width,
                                    precision_speci, size_specifier));
    if (format_handlers[i].specifier == '\0')
    {
        if (format[*index] == '\0')
            return (-1);
        len += write(1, "%%", 1);
        if (format[*index - 1] == ' ')
            len += write(1, " ", 1);
        else if (field_width)
        {
            --(*index);
            while (format[*index] != ' ' && format[*index] != '%')
                --(*index);
            if (format[*index] == ' ')
                --(*index);
            return (1);
        }
        len += write(1, &format[*index], 1);
        return (len);
    }
    return (printed_characters);
}