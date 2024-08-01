#include "main.h"
/**
 * print_special_str - prints strings exclusively
 * @args: arguments expected
 * Return: an integer
 */

int print_special_str(va_list args)
{
    char *s = va_arg(args, char *);
    int i, length = 0, value;

    if (s == NULL)
        s = "(null)";

    for (i = 0; s[i] != '\0'; i++)
    {
        if (s[i] < 32 || s[i] >= 127)
        {
            _putchar('\\');
            _putchar('x');
            length += 2;
            value = s[i];
            if (value < 16)
            {
                _putchar('0');
                length++;
            }
            length += print_hex_extra(value);
        }
        else
        {
            _putchar(s[i]);
            length++;
        }
    }
    return (length);
}
