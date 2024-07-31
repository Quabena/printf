#include "main.h"

/**
 * my_printf - prints formatted output
 * @format: format string
 * Return: length of printed string
 */
int _printf(const char *format, ...)
{
    convert specifiers[] = {
        {"%s", print_str}, {"%c", print_char}, {"%%", print_percent}, {"%i", print_integer}, {"%d", print_decimal}, {"%r", print_reverse_str}, {"%R", print_rot13}, {"%b", print_bin}, {"%u", print_unsigned_int}, {"%o", print_octal}, {"%x", print_hex}, {"%X", print_HEX}, {"%S", print_special_str}, {"%p", print_ptr}};

    va_list args;
    int i = 0, j, length = 0;

    va_start(args, format);
    if (format == NULL || (format[0] == '%' && format[1] == '\0'))
        return (-1);

    while (format[i] != '\0')
    {
        for (j = 0; j < (int)(sizeof(specifiers) / sizeof(specifiers[0])); j++)
        {
            if (specifiers[j].specifier[0] == format[i] && specifiers[j].specifier[1] == format[i + 1])
            {
                length += specifiers[j].func(args);
                i += 2;
                break;
            }
        }
        if (j == (int)(sizeof(specifiers) / sizeof(specifiers[0])))
        {
            _putchar(format[i]);
            length++;
            i++;
        }
    }
    va_end(args);
    return (length);
}
