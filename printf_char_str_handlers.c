#include "main.h"

/**
 * handler_char_write - Outputs a character with formatting.
 * @c: The character to be printed.
 * @output_buffer: Buffer array to handle print.
 * @format: Active flags for formatting.
 * @field_width: Width specifier.
 * @precision_speci: Precision specifier.
 * @size_specifier: Size specifier.
 * Return: Number of characters printed.
 */

int handler_char_write(char c, char output_buffer[],
                       int active_flags, int field_width, int precision_speci, int size_specifier)
{
    int idx = 0;
    char padding_char = ' ';

    UNUSED(precision_speci);
    UNUSED(size_specifier);
    if (active_flags & ZERO_FLAG)
        padding_char = '0';
    output_buffer[idx++] = c;
    output_buffer[idx] = '\0';
    if (field_width > 1)
    {
        output_buffer[BUFF_SIZE - 1] = '\0';
        for (idx = 0; idx < field_width - 1; idx++)
            output_buffer[BUFF_SIZE - idx - 2] = padding_char;
        if (active_flags & MINUS_FLAG)
            return (write(1, &output_buffer[0], 1) +
                    write(1, &output_buffer[BUFF_SIZE - idx - 1], field_width - 1));
        else
            return (write(1, &output_buffer[BUFF_SIZE - idx - 1], field_width - 1) +
                    write(1, &output_buffer[0], 1));
    }
    return (write(1, &output_buffer[0], 1));
}

int handler_generic_number(int index, char output_buffer[], int active_flags, int field_width,
                           int precision_speci, int length, char padding_char, char holder)
{
    int idx, padding_start = 1;

    if (precision_speci == 0 && index == BUFF_SIZE - 2 && output_buffer[index] == '0' && field_width == 0)
        return (0);

    if (precision_speci == 0 && index == BUFF_SIZE - 2 && output_buffer[index] == '0')
        output_buffer[index] = padding_char = ' '; 
    
    if (precision_speci > 0 && precision_speci < length)
        padding_char = ' ';
    while (precision_speci > length)
        output_buffer[--index] = '0', length++;

    if (holder != 0)
        length++;

    if (field_width > length)
    {
        for (idx = 1; idx < field_width - length + 1; idx++)
            output_buffer[idx] = padding_char;
        output_buffer[idx] = '\0';

        if (active_flags & MINUS_FLAG && padding_char == ' ') 
        {
            if (holder)
                output_buffer[--index] = holder;
            return (write(1, &output_buffer[index], length) + write(1,
                                                           &output_buffer[1], idx - 1));
        }
        else if (!(active_flags & MINUS_FLAG) && padding_char == ' ')
        {
            if (holder)
                output_buffer[--index] = holder;
            return (write(1, &output_buffer[1], idx - 1) + write(1,
                                                        &output_buffer[index], length));
        }
        else if (!(active_flags & MINUS_FLAG) && padding_char == '0')
        {
            if (holder)
                output_buffer[--padding_start] = holder;
            return (write(1, &output_buffer[padding_start], idx - padding_start) +
                    write(1, &output_buffer[index], length - (1 - padding_start)));
        }
    }
    if (holder)
        output_buffer[--index] = holder;
    return (write(1, &output_buffer[index], length));
}

