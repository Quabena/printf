#include "main.h"

/**
 * print_integer - Prints an integer
 * @args: List of arguments
 * @output_buffer: Buffer array to manage printing
 * @activeflags: Calculated active flags
 * @field_width: Specified width
 * @precision_speci: Precision specification
 * @size_specifier: Size specifier
 *
 * Return: Number of characters printed
 */

int print_integer(va_list args, char output_buffer[],
                 int active_flags, int field_width, int precision_speci, int size_specifier)
{
    int idx = BUFF_SIZE - 2;
    int neg = 0;
    long int value = va_arg(args, long int);
    unsigned long int abs_value;

    value = convert_signed_size(value, size_specifier);

    if (value == 0)
        output_buffer[idx--] = '0';
    
    output_buffer[BUFF_SIZE - 1] = '\0';
    abs_value = (unsigned long int)value;
    if (value < 0)
    {
        abs_value = (unsigned long int)((-1) * value);
        neg = 1;
    }
    while (abs_value > 0)
    {
        output_buffer[idx--] = (abs_value % 10) + '0';
        abs_value /= 10;
    }
    idx++;
    return (handler_number_write(neg, idx, output_buffer, active_flags, field_width,
                         precision_speci, size_specifier));
}

/**
 * handler_number_write - Outputs a number string
 * @neg_flag: Indicates if number is negative
 * @index: Starting index for buffer
 * @output_buffer: Buffer array to manage printing
 * @active_flags: Calculated active flags
 * @field_width: Specified width
 * @precision_speci: Precision specifier
 * @size_specifier: Size specifier
 * Return: Number of characters printed
 */

int handler_number_write(int neg_flag, int index, char output_buffer[],
                         int active_flags, int field_width, int precision_speci, int size_specifier)
{
    int length = BUFF_SIZE - index - 1;
    char pad_char = ' ', new_flag = 0;

    UNUSED(size_specifier);

    if ((active_flags & ZERO_FLAG) && !(active_flags & MINUS_FLAG))
        pad_char = '0';

    if (neg_flag)
        new_flag = '-';

    else if (active_flags & PLUS_FLAG)
        new_flag = '+';

    else if (active_flags & SPACE_FLAG)
        new_flag = ' ';

    return (handler_generic_number(index, output_buffer, active_flags, field_width, precision_speci,
                      length, pad_char, new_flag));
}
