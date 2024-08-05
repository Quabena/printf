#include "main.h"
/**
 * retrieve_precision - A function that computes the
 * precision for printing
 * @format: Formatted string to print the arguments
 * @index: Indexed character to be printed.
 * @args: list of arguments.
 *
 * Return: Precision.
 */
int retrieve_precision(const char *format, int *index, va_list args)
{
    int position = *index + 1;
    int precision = -1;

    if (format[position] != '.')
        return (precision);

    precision = 0;

    for (position += 1; format[position] != '\0'; position++)
    {
        if (is_numeric(format[position]))
        {
            precision *= 10;
            precision += format[position] - '0';
        }
        else if (format[position] == '*')
        {
            position++;
            precision = va_arg(args, int);
            break;
        }
        else
            break;
    }
    *index = position - 1;
    return (precision);
}