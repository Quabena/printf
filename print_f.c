#include "main.h"

/**
* _printf - Formats and outputs data based on a given format string
* @format: Format string containing specifiers and text to print
* Return: The total number of characters printed, or -1
* if an error occurs
* Authors: Evans Adu and Enoch Kabange
*/

int _printf(const char *format, ...)
{
	int (*format_function)(va_list, flag_settings *);
	const char *current;
	va_list args;
	flag_settings settings = {0, 0, 0, 0, 0};

	register int printed_chars = 0;

	va_start(args, format);

	if (!format || (format[0] == '%' && !format[1]))
	{
		return (-1);
	}
	if (format[0] == '%' && format[1] == ' ' && !format[2])
	{
		return (-1);
	}
	for (current = format; *current; current++)
	{
		if (*current == '%')
		{
			current++;
			if (*current == '%')
			{
				_putchar(*current++);
				continue;
			}
			while (apply_flags(*current, &settings))
				current++;
			format_function = select_format_function(*current);
			printed_chars += (format_function) ? format_function(args,
									     &settings) : _printf("%%%c", *current);
		}
		else
			printed_chars += _putchar(*current);
	}

	_putchar(-1);
	va_end(args);
	return (printed_chars);
}
