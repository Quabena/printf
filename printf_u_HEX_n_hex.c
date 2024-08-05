#include "main.h"

/**
 * print_hex - A function an unsigned number in hexadecimal notation
 * @args: List of arguments
 * @output_buffer: Array to handle print
 * @active_flags: Active flags
 * @field_width: Width for printing
 * @precision_speci: Precision
 * @size_specifier: Size specifier
 * Return: Number of characters printed
 */

int print_hex(va_list args, char output_buffer[],
              int active_flags, int field_width, int precision_speci, int size_specifier)
{
    return (print_hex_generic(args, "0123456789abcdef", output_buffer,
                       active_flags, 'x', field_width, precision_speci, size_specifier));
}

/**
 * print_hex_uppercase - For printing an unsigned number in upper
 * hexadecimal notation
 * @args: List of arguments
 * @output_buffer: Array to handle print
 * @active_flags: Active flags
 * @field_width: Width
 * @precision_speci: Precision
 * @size_specifier: Size specifier
 * Return: Number of characters to be printed
 */
int print_hex_uppercase(va_list args, char output_buffer[],
                        int active_flags, int field_width, int precision_speci, int size_specifier)
{
    return (print_hex_generic(args, "0123456789ABCDEF", output_buffer,
                       active_flags, 'X', field_width, precision_speci, size_specifier));
}

/**
 * print_hex_generic - Prints a number in hexadecimal format (lowercase or uppercase).
 * @args: List of arguments
 * @hex_digits: Array of values to map the number to
 * @output_buffer: Buffer array to handle print
 * @active_flags: Calculates active flags
 * @active_charac: Calculates active flags
 * @field_width: Width
 * @precision_speci: Precision
 * @size_specifier: Size specifier
 * @size_spec: Size
 * Return: Number of chars printed
 */
int print_hex_generic(va_list args, char hex_digits[], char output_buffer[], int active_flags,
                                    char flag_charac, int field_width, int precision_speci, int size_specifier)
{
    int idx = BUFF_SIZE - 2;
    unsigned long int number = va_arg(args, unsigned long int);
    unsigned long int proto_number = number;

    UNUSED(field_width);

    number = convert_unsigned_size(number, size_specifier);
    if (number == 0)
        output_buffer[idx--] = '0';
    output_buffer[BUFF_SIZE - 1] = '\0';
    while (number > 0)
    {
        output_buffer[idx--] = hex_digits[number % 16];
        number /= 16;
    }
    if (active_flags & HASH_FLAG && proto_number != 0)
    {
        output_buffer[idx--] = flag_charac;
        output_buffer[idx--] = '0';
    }
    idx++;
    return (generic_unsigned_handler(0, idx, output_buffer, active_flags, field_width, precision_speci, size_specifier));
}

/**
 * add_hex_code - Appends ASCII code in hexadecimal format to buffer.
 * @output_buffer:Buffer array for handling print operations
 * @index: Index at which to start appending in the buffer
 * @code_asc: ASCII code to convert
 * Return: Always 3 (number of characters appended)
 */

int add_hex_code(char code_asc, char output_buffer[], int index)
{
    char hex_digits[] = "0123456789ABCDEF";

    if (code_asc < 0)
        code_asc *= -1;
    output_buffer[index++] = '\\';
    output_buffer[index++] = 'x';
    output_buffer[index++] = hex_digits[code_asc / 16];
    output_buffer[index] = hex_digits[code_asc % 16];
    return (3);
}