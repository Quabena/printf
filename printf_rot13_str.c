#include "main.h"

/**
 * print_rot13_str - A function that rints a string encoded in ROT13.
 * @args: List of arguments (should contain the string to encode)
 * @output_buffer: Buffer array for handling print operations
 * @active_flags: Active formatting flags
 * @field_width: Field width for printing
 * @precision_spec: Precision specification for printing
 * @size_specifier: Size specifier for type casting
 * Return: Number of characters printed
 */

int print_rot13_str(va_list args, char output_buffer[],
                    int active_flags, int field_width, int precision_speci, int size_specifier)
{
    char *str;
    char ch;
    unsigned int index, itrt;
    int count = 0;
    char rot1[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    char rot2[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

    str = va_arg(args, char *);
    UNUSED(output_buffer);
    UNUSED(active_flags);
    UNUSED(field_width);
    UNUSED(precision_speci);
    UNUSED(size_specifier);

    if (str == NULL)
        str = "(null)";

    for (index = 0; str[index]; index++)
    {
        for (itrt = 0; rot1[itrt]; itrt++)
        {
            if (rot1[itrt] == str[index])
            {
                ch = rot2[itrt];
                write(1, &ch, 1);
                count++;
                break;
            }
        }
        if (!rot1[itrt])
        {
            ch = str[index];
            write(1, &ch, 1);
            count++;
        }
    }
    return (count);
}