#include "main.h"

/**
* _printf - A custom printf function.
* @format: The formatted string that specifies
* the output format.
* Return: Number of characters printed, or -1 on failure.
*/

int _printf(const char *format, ...)
{
int idx, total_chars_printed = 0, chars_printed = 0;
int format_flags, field_width, precision_speci, size_specifier;
int buffer_index = 0;
va_list args;
char buffer[BUFF_SIZE];
if (format == NULL)
return (-1);
va_start(args, format);
for (idx = 0; format && format[idx] != '\0'; idx++)
{
if (format[idx] != '%')
{
buffer[buffer_index++] = format[idx];
if (buffer_index == BUFF_SIZE)
print_output_buffer(buffer, &buffer_index);
chars_printed++;
}
else
{
print_output_buffer(buffer, &buffer_index);
format_flags = retrieve_flags(format, &idx);
field_width = retrieve_width(format, &idx, args);
precision_speci = retrieve_precision(format, &idx, args);
size_specifier = determine_size(format, &idx);
++idx;
chars_printed = dispatch_format(format, &idx, args, buffer, format_flags,
				field_width, precision_speci, size_specifier);
if (chars_printed == -1)
return (-1);

total_chars_printed += chars_printed;
}
}
print_output_buffer(buffer, &buffer_index);
va_end(args);
return (total_chars_printed);
}

/**
* print_output_buffer - Prints the contents of the buffer if it exist
* @output_buffer: Array of chars
* @buffer_index: Index at which to add next char, represents the length.
*/

void print_output_buffer(char output_buffer[], int *buffer_index)
{
if (*buffer_index > 0)
write(1, &output_buffer[0], *buffer_index);
*buffer_index = 0;
}
