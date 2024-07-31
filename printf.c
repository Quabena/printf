#include "main.h"


char buffer[BUFFER_SIZE];

static int handle_format(const char *format, va_list args);
static void flush_buffer(int *count);

/**
 * _printf - Custom printf function
 * @format: Format string
 * @...: Variable arguments
 *
 * Return: Number of characters printed
 */
int _printf(const char *format, ...)
{
    va_list args;
    int count = 0;

    va_start(args, format);
    count = handle_format(format, args);
    va_end(args);

    flush_buffer(&count);

    return count;
}

/**
 * handle_format - Processes the format string and handles specifiers
 * @format: The format string
 * @args: The variable arguments
 *
 * Return: Number of characters printed
 */
static int handle_format(const char *format, va_list args)
{
    int count = 0;
    const char *p = format;
    int buf_index = 0;

    for (; *p; p++)
    {
        if (buf_index >= BUFFER_SIZE - 1) 
        {
            flush_buffer(&count);
            buf_index = 0;
        }

        if (*p == '%' && (*(p + 1) == 'c' || *(p + 1) == 's' || *(p + 1) == '%' || *(p + 1) == 'd' || *(p + 1) == 'i' || *(p + 1) == 'b' || *(p + 1) == 'u' || *(p + 1) == 'o' || *(p + 1) == 'x' || *(p + 1) == 'X' || *(p + 1) == 'S'))
        {
            p++;
            if (*p == 'c')
            {
                char ch = (char)va_arg(args, int);
                buffer[buf_index++] = ch;
                count++;
            }
            else if (*p == 's')
            {
                char *str = va_arg(args, char *);
                while (*str)
                {
                    if (buf_index >= BUFFER_SIZE - 1)
                    {
                        flush_buffer(&count);
                        buf_index = 0;
                    }
                    buffer[buf_index++] = *str++;
                    count++;
                }
            }
            else if (*p == '%')
            {
                buffer[buf_index++] = '%';
                count++;
            }
            else if (*p == 'd' || *p == 'i')
            {
                int num = va_arg(args, int);
                char *num_str = int_to_string(num);
                char *str = num_str;

                while (*str)
                {
                    if (buf_index >= BUFFER_SIZE - 1)
                    {
                        flush_buffer(&count);
                        buf_index = 0;
                    }
                    buffer[buf_index++] = *str++;
                    count++;
                }

                free(num_str);
            }
            else if (*p == 'b')
            {
                unsigned int num = va_arg(args, unsigned int);
                char *bin_str = unsigned_int_to_binary(num);
                char *str = bin_str;

                while (*str)
                {
                    if (buf_index >= BUFFER_SIZE - 1) 
                    {
                        flush_buffer(&count);
                        buf_index = 0;
                    }
                    buffer[buf_index++] = *str++;
                    count++;
                }

                free(bin_str);
            }
            else if (*p == 'u')
            {
                unsigned int num = va_arg(args, unsigned int);
                char *num_str = unsigned_int_to_string(num);
                char *str = num_str;

                while (*str)
                {
                    if (buf_index >= BUFFER_SIZE - 1)
                    {
                        flush_buffer(&count);
                        buf_index = 0;
                    }
                    buffer[buf_index++] = *str++;
                    count++;
                }

                free(num_str);
            }
            else if (*p == 'o')
            {
                unsigned int num = va_arg(args, unsigned int);
                char *oct_str = unsigned_int_to_octal(num);
                char *str = oct_str;

                while (*str)
                {
                    if (buf_index >= BUFFER_SIZE - 1)
                    {
                        flush_buffer(&count);
                        buf_index = 0;
                    }
                    buffer[buf_index++] = *str++;
                    count++;
                }

                free(oct_str);
            }
            else if (*p == 'x')
            {
                unsigned int num = va_arg(args, unsigned int);
                char *hex_str = unsigned_int_to_hex(num);
                char *str = hex_str;

                while (*str)
                {
                    if (buf_index >= BUFFER_SIZE - 1) 
                    {
                        flush_buffer(&count);
                        buf_index = 0;
                    }
                    buffer[buf_index++] = *str++;
                    count++;
                }

                free(hex_str);
            }
            else if (*p == 'X')
            {
                unsigned int num = va_arg(args, unsigned int);
                char *hex_str = unsigned_int_to_hex_upper(num);
                char *str = hex_str;

                while (*str)
                {
                    if (buf_index >= BUFFER_SIZE - 1)
                    {
                        flush_buffer(&count);
                        buf_index = 0;
                    }
                    buffer[buf_index++] = *str++;
                    count++;
                }

                free(hex_str);
            }
            else if (*p == 'S')
            {
                char *str = va_arg(args, char *);
                char *processed_str = process_string_with_non_printable(str);
                char *s = processed_str;

                while (*s)
                {
                    if (buf_index >= BUFFER_SIZE - 1)
                    {
                        flush_buffer(&count);
                        buf_index = 0;
                    }
                    buffer[buf_index++] = *s++;
                    count++;
                }

                free(processed_str);
            }
        }
        else
        {
            if (buf_index >= BUFFER_SIZE - 1)
            {
                flush_buffer(&count);
                buf_index = 0;
            }
            buffer[buf_index++] = *p;
            count++;
        }
    }

    return count;
}

/**
 * flush_buffer - Writes the contents of the buffer to stdout
 * @count: Pointer to the character count
 */
static void flush_buffer(int *count)
{
    write(1, buffer, *count);
    *count = 0;
}
#include "main.h"


char buffer[BUFFER_SIZE];

static int handle_format(const char *format, va_list args);
static void flush_buffer(int *count);

/**
 * _printf - Custom printf function
 * @format: Format string
 * @...: Variable arguments
 *
 * Return: Number of characters printed
 */
int _printf(const char *format, ...)
{
    va_list args;
    int count = 0;

    va_start(args, format);
    count = handle_format(format, args);
    va_end(args);

    flush_buffer(&count);

    return count;
}

/**
 * handle_format - Processes the format string and handles specifiers
 * @format: The format string
 * @args: The variable arguments
 *
 * Return: Number of characters printed
 */
static int handle_format(const char *format, va_list args)
{
    int count = 0;
    const char *p = format;
    int buf_index = 0;

    for (; *p; p++)
    {
        if (buf_index >= BUFFER_SIZE - 1) 
        {
            flush_buffer(&count);
            buf_index = 0;
        }

        if (*p == '%' && (*(p + 1) == 'c' || *(p + 1) == 's' || *(p + 1) == '%' || *(p + 1) == 'd' || *(p + 1) == 'i' || *(p + 1) == 'b' || *(p + 1) == 'u' || *(p + 1) == 'o' || *(p + 1) == 'x' || *(p + 1) == 'X' || *(p + 1) == 'S'))
        {
            p++;
            if (*p == 'c')
            {
                char ch = (char)va_arg(args, int);
                buffer[buf_index++] = ch;
                count++;
            }
            else if (*p == 's')
            {
                char *str = va_arg(args, char *);
                while (*str)
                {
                    if (buf_index >= BUFFER_SIZE - 1)
                    {
                        flush_buffer(&count);
                        buf_index = 0;
                    }
                    buffer[buf_index++] = *str++;
                    count++;
                }
            }
            else if (*p == '%')
            {
                buffer[buf_index++] = '%';
                count++;
            }
            else if (*p == 'd' || *p == 'i')
            {
                int num = va_arg(args, int);
                char *num_str = int_to_string(num);
                char *str = num_str;

                while (*str)
                {
                    if (buf_index >= BUFFER_SIZE - 1)
                    {
                        flush_buffer(&count);
                        buf_index = 0;
                    }
                    buffer[buf_index++] = *str++;
                    count++;
                }

                free(num_str);
            }
            else if (*p == 'b')
            {
                unsigned int num = va_arg(args, unsigned int);
                char *bin_str = unsigned_int_to_binary(num);
                char *str = bin_str;

                while (*str)
                {
                    if (buf_index >= BUFFER_SIZE - 1) 
                    {
                        flush_buffer(&count);
                        buf_index = 0;
                    }
                    buffer[buf_index++] = *str++;
                    count++;
                }

                free(bin_str);
            }
            else if (*p == 'u')
            {
                unsigned int num = va_arg(args, unsigned int);
                char *num_str = unsigned_int_to_string(num);
                char *str = num_str;

                while (*str)
                {
                    if (buf_index >= BUFFER_SIZE - 1)
                    {
                        flush_buffer(&count);
                        buf_index = 0;
                    }
                    buffer[buf_index++] = *str++;
                    count++;
                }

                free(num_str);
            }
            else if (*p == 'o')
            {
                unsigned int num = va_arg(args, unsigned int);
                char *oct_str = unsigned_int_to_octal(num);
                char *str = oct_str;

                while (*str)
                {
                    if (buf_index >= BUFFER_SIZE - 1)
                    {
                        flush_buffer(&count);
                        buf_index = 0;
                    }
                    buffer[buf_index++] = *str++;
                    count++;
                }

                free(oct_str);
            }
            else if (*p == 'x')
            {
                unsigned int num = va_arg(args, unsigned int);
                char *hex_str = unsigned_int_to_hex(num);
                char *str = hex_str;

                while (*str)
                {
                    if (buf_index >= BUFFER_SIZE - 1) 
                    {
                        flush_buffer(&count);
                        buf_index = 0;
                    }
                    buffer[buf_index++] = *str++;
                    count++;
                }

                free(hex_str);
            }
            else if (*p == 'X')
            {
                unsigned int num = va_arg(args, unsigned int);
                char *hex_str = unsigned_int_to_hex_upper(num);
                char *str = hex_str;

                while (*str)
                {
                    if (buf_index >= BUFFER_SIZE - 1)
                    {
                        flush_buffer(&count);
                        buf_index = 0;
                    }
                    buffer[buf_index++] = *str++;
                    count++;
                }

                free(hex_str);
            }
            else if (*p == 'S')
            {
                char *str = va_arg(args, char *);
                char *processed_str = process_string_with_non_printable(str);
                char *s = processed_str;

                while (*s)
                {
                    if (buf_index >= BUFFER_SIZE - 1)
                    {
                        flush_buffer(&count);
                        buf_index = 0;
                    }
                    buffer[buf_index++] = *s++;
                    count++;
                }

                free(processed_str);
            }
        }
        else
        {
            if (buf_index >= BUFFER_SIZE - 1)
            {
                flush_buffer(&count);
                buf_index = 0;
            }
            buffer[buf_index++] = *p;
            count++;
        }
    }

    return count;
}

/**
 * flush_buffer - Writes the contents of the buffer to stdout
 * @count: Pointer to the character count
 */
static void flush_buffer(int *count)
{
    write(1, buffer, *count);
    *count = 0;
}
