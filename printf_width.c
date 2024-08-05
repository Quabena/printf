#include "main.h"

/**
 * retrieve_width - Determines the field width for printing.
 * @format: The formatted string containing the formatting specifiers.
 * @index: Pointer to the current index in the format string.
 * @args: List of arguments to be printed.
 * Return: The calculated field width.
 */

int retrieve_width(const char *format, int *index, va_list args)
{
    int current_pos;
    int field_width = 0;
    for (current_pos = *index + 1; format[current_pos] != '\0'; current_pos++)
    {
        if (is_numeric(format[current_pos]))
        {
            field_width *= 10;
            field_width += format[current_pos] - '0';
        }
        else if (format[current_pos] == '*')
        {
            current_pos++;
            field_width = va_arg(args, int);
            break;
        }
        else
            break;
    }
    *index = current_pos - 1;
    return (field_width);
}
