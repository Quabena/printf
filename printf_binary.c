#include "main.h"

/**
 * print_binary - Outputs an unsigned integer
 * in binary format.
 * @args: List of arguments
 * @output_buffer: Buffer array for storing the output.
 * @active_flags: Current active flags
 * @field_width: Specified field width.
 * @precision_speci: Specified precision 
 * @size_specifier: Size specifier
 * Return: Numbers of characters printed.
 */
int print_binary_format(va_list args, char output_buffer[],
                        int active_flags, int field_width, int precision_speci, int size_specifier)
{
    unsigned int number, mask, index, total_bits;
    unsigned int bit_array[32];
    int printed_chars_count;

    UNUSED(output_buffer);
    UNUSED(active_flags);
    UNUSED(field_width);
    UNUSED(precision_speci);
    UNUSED(size_specifier);

    number = va_arg(args, unsigned int);
    mask = 2147483648; /* (2 ^ 31) */
    bit_array[0] = number / mask;

    for (index = 1; index < 32; index++)
    {
        mask /= 2;
        bit_array[index] = (number / mask) % 2;
    }
    for (index = 0, total_bits = 0, printed_chars_count = 0; index < 32; index++)
    {
        total_bits += bit_array[index];

        if (total_bits || index == 31)
        {
            char bit_char = '0' + bit_array[index];
            write(1, &bit_char, 1);
            printed_chars_count++;
        }
    }
    return (printed_chars_count);
}