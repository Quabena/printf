#include "main.h"

/**
 * print_octal - A function that prints an unsigned number
 *  in octal.
 * @args: Lista of arguments
 * @outputbuffer: A buffer array to handle the print
 * @active_flags: Active flags
 * @field_width:  width precision
 * @precision_speci: Precision
 * @size_specifier: Size specifier
 * Return: Number of characters printed
 */
int print_octal(va_list args, char output_buffer[],
                int active_flags, int field_width, int precision_speci, int size_specifier)
{
    int idx = BUFF_SIZE - 2;
    unsigned long int number = va_arg(args, unsigned long int);
    unsigned long int initial_number = number;

    UNUSED(field_width);

    number = convert_unsigned_size(number, size_specifier);
    if (number == 0)
        output_buffer[idx--] = '0';
    output_buffer[BUFF_SIZE - 1] = '\0';
    while (number > 0)
    {
        output_buffer[idx--] = (number % 8) + '0';
        number /= 8;
    }
    if (active_flags & HASH_FLAG && initial_number != 0)
        output_buffer[idx--] = '0';
    idx++;
    return (generic_unsigned_handler(0, idx, output_buffer, active_flags, field_width, precision_speci, size_specifier));
}
