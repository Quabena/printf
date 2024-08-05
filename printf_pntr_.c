#include "main.h"

/**
 * print_pointer - A function that prints the value of a
 * pointer variable
 * @args: List a of arguments
 * @outputbuffer: Array to handle print
 * @active_flags: Active flags
 * @field_width: Width precision
 * @precision_speci: Precision
 * @size_specifier: Size specifier
 * Return: Number of chars printed.
 */

int print_pointer(va_list args, char output_buffer[],
                int active_flags, int field_width, int precision_speci, int size_specifier)
{
    char additional_char = 0, char_padding = ' ';
    int idx = BUFF_SIZE - 2, length = 2, padding_start = 1;

    unsigned long addr_value;

    char hex_digits[] = "0123456789abcdef";
    void *ptr = va_arg(args, void *);

    UNUSED(field_width);
    UNUSED(size_specifier);

    if (ptr == NULL)
        return (write(1, "(nil)", 5));

    output_buffer[BUFF_SIZE - 1] = '\0';

    UNUSED(precision_speci);

    addr_value = (unsigned long)ptr;
    while (addr_value > 0)
    {
        output_buffer[idx--] = hex_digits[addr_value % 16];
        addr_value /= 16;
        length++;
    }
    if ((active_flags & ZERO_FLAG) && !(active_flags & MINUS_FLAG))
        char_padding = '0';

    if (active_flags & PLUS_FLAG)
        additional_char = '+', length++;
    else if (active_flags & SPACE_FLAG)
        additional_char = ' ', length++;
    idx++;

    return (pointer_address_handler(output_buffer, idx, length, field_width, active_flags, char_padding, additional_char, padding_start));
}

/**
 * pointer_address_handler - A function that prints a memory address
 * @output_buffer: Arrays of characters
 * @index: Start index in the buffer
 * @length: Length of number
 * @field_width: Width specifier
 * @active_flags: Active flag specifier
 * @char_padding: Character padding representation
 * @additional_char: Additional character
 * @padding_start: Index at which padding should start
 * Return: Number of written chars.
 */

int pointer_address_handler(char output_buffer[], int index, int length,
               int field_width, int active_flags, char char_padding, char additional_char, int padding_start)
{
    int itrt;
    if (field_width > length)
    {
        for (itrt = 3; itrt < field_width - length + 3; itrt++)
            output_buffer[itrt] = char_padding;

        output_buffer[itrt] = '\0';

        if (active_flags & MINUS_FLAG && char_padding == ' ')
        {
            output_buffer[--index] = 'x';
            output_buffer[--index] = '0';
            if (additional_char)
                output_buffer[--index] = additional_char;
            return (write(1, &output_buffer[index], length) + write(1,
                                                           &output_buffer[3], itrt - 3));
        }
        else if (!(active_flags & MINUS_FLAG) && char_padding == ' ') 
        {
            output_buffer[--index] = 'x';
            output_buffer[--index] = '0';
            if (additional_char)
                output_buffer[--index] = additional_char;
            return (write(1, &output_buffer[3], itrt - 3) + write(1,
                                                        &output_buffer[index], length));
        }
        else if (!(active_flags & MINUS_FLAG) && char_padding == '0')
        {
            if (additional_char)
                output_buffer[--padding_start] = additional_char;
            output_buffer[1] = '0';
            output_buffer[2] = 'x';
            return (write(1, &output_buffer[padding_start], itrt - padding_start) +
                    write(1, &output_buffer[index], length - (1 - padding_start) - 2));
        }
    }
    output_buffer[--index] = 'x';
    output_buffer[--index] = '0';
    if (additional_char)
        output_buffer[--index] = additional_char;
    return (write(1, &output_buffer[index], BUFF_SIZE - index - 1));
}