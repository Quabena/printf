#include "main.h"

/**
 * print_unsigned_integer - Outputs an unsigned integer in decimal notation.
 * @args: List of arguments (containing the unsigned number)
 * @output_buffer: Buffer array for print operations
 * @active_flags: Active formatting flags
 * @field_width: Minimum width for printing
 * @precision_speci: Precision for printing
 * @size_specifier: Size specifier for type casting
 * Return: Number of characters printed
 */

int print_unsigned_integer(va_list args, char output_buffer[],
                           int active_flags, int field_width, int precision_speci, int size_specifier)
{
    int buf_index = BUFF_SIZE - 2;
    unsigned long int number = va_arg(args, unsigned long int);
    number = convert_unsigned_size(number, size_specifier);

    if (number == 0)
        output_buffer[buf_index--] = '0';
    output_buffer[BUFF_SIZE - 1] = '\0';
    while (number > 0)
    {
        output_buffer[buf_index--] = (number % 10) + '0';
        number /= 10;
    }
    buf_index++;
    return (generic_unsigned_handler(0, buf_index, output_buffer, active_flags, field_width, precision_speci, size_specifier));
}

/**
 * generic_unsigned_handler - Writes an unsigned number
 * @neg_num: Number indicating if the num is negative
 * @index: Index at which the number starts in the buffer
 * @output_buffer: Array of chars
 * @active_flags: Flags specifiers
 * @field_width: Width specifier
 * @precision_speci: Precision specifier
 * @size_specifier: Size specifier
 *
 * Return: Number of written chars.
 */
int generic_unsigned_handler(int neg_num, int index, char output_buffer[],
                 int active_flags, int field_width, int precision_speci, int size_specifier)
{
    /* The number is stored at the bufer's right and starts at position
    i */
    int length = BUFF_SIZE - index - 1, i = 0;

    char charac_padding = ' ';

    UNUSED(neg_num);
    UNUSED(size_specifier);

    if (precision_speci == 0 && index == BUFF_SIZE - 2 && output_buffer[index] == '0')
        return (0);

    if (precision_speci > 0 && precision_speci < length)
        charac_padding = ' ';
    while (precision_speci > length)
    {
        output_buffer[--index] = '0';
        length++;
    }
    if ((active_flags & ZERO_FLAG) && !(active_flags & MINUS_FLAG))
        charac_padding = '0';
    if (field_width > length)
    {
        for (i = 0; i < field_width - length; i++)
            output_buffer[i] = charac_padding;
        output_buffer[i] = '\0';
        if (active_flags & MINUS_FLAG)
        {
            return (write(1, &output_buffer[index], length) + write(1,
                                                           &output_buffer[0], i));
        }
        else 
        {
            return (write(1, &output_buffer[0], i) + write(1, &output_buffer[index],
                                                    length));
        }
    }
    return (write(1, &output_buffer[index], length));
}