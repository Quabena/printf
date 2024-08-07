#include "main.h"

/**
 * _printf - Custom printf function
 * @format: format string
 * @...: variable arguments
 * Return: number of characters printed
 */

int _printf(const char *format, ...)
{
    va_list args;
    char buffer[1024];
    int buffer_index = 0;
    int total_len = 0;
    int width, precision;
    int flags = 0;
    int length_mod = 0;
    va_start(args, format);
    while (*format)
    {
        if (*format == '%')
        {
            format++;
            width = -1;
            precision = -1;
            flags = 0;
            length_mod = 0;
            while (*format == '+' || *format == ' ' || *format == '#' || *format == '0' || *format == '-')
            {
                if (*format == '+')
                    flags |= FLAG_PLUS;
                else if (*format == ' ')
                    flags |= FLAG_SPACE;
                else if (*format == '#')
                    flags |= FLAG_HASH;
                else if (*format == '0')
                    flags |= FLAG_ZERO;
                else if (*format == '-')
                    flags |= FLAG_MINUS;
                format++;
            }
            if (*format >= '0' && *format <= '9')
            {
                width = 0;
                while (*format >= '0' && *format <= '9')
                {
                    width = width * 10 + (*format - '0');
                    format++;
                }
            }
            if (*format == '.')
            {
                format++;
                precision = 0;
                while (*format >= '0' && *format <= '9')
                {
                    precision = precision * 10 + (*format - '0');
                    format++;
                }
            }
            if (*format == 'l')
                length_mod = LENGTH_LONG, format++;
            else if (*format == 'h')
                length_mod = LENGTH_SHORT, format++;
            switch (*format)
            {
            case 'c':
            case 's':
            case '%':
                total_len += handle_c_s_percent(format, args, buffer, &buffer_index, width, precision, flags);
                break;
            case 'd':
            case 'i':
                total_len += handle_di_specifier(args, buffer, &buffer_index, width, precision, flags, length_mod);
                break;
            case 'b':
                total_len += handle_b_specifier(args, buffer, &buffer_index, width, precision, flags);
                break;
            case 'u':
            case 'o':
            case 'x':
            case 'X':
                total_len += handle_uoxX_specifier(args, buffer, &buffer_index, width, precision, flags, length_mod, *format);
                break;
            case 'S':
                total_len += handle_S_specifier(args, buffer, &buffer_index, width, precision, flags);
                break;
            case 'p':
                total_len += handle_p_specifier(args, buffer, &buffer_index, width, precision, flags);
                break;
            case 'r':
                total_len += handle_r(args, buffer, &buffer_index, width, precision, flags);
                break;
            case 'R':
                total_len += handle_R(args, buffer, &buffer_index, width, precision, flags);
                break;
            default:
                _putchar('%', buffer, &buffer_index);
                _putchar(*format, buffer, &buffer_index);
                total_len += 2;
                break;
            }
        }
        else
        {
            _putchar(*format, buffer, &buffer_index);
            total_len++;
        }
        format++;
    }
    if (buffer_index > 0)
        write(1, buffer, buffer_index);

    va_end(args);
    return (total_len);
}
