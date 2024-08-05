#include "main.h"
/**
 * determine_size - Determines the size for casting the argument.
 * @format: The formatted string containing the specifiers.
 * @index: Pointer to the current index in the formatted string.
 *
 * Return: The size specifier.
 */

int determine_size(const char *format, int *index)
{
    int current_index = *index + 1;
    int size_specifier = 0;

    if (format[current_index] == 'l')
        size_specifier = SIZE_LONG;
    else if (format[current_index] == 'h')
        size_specifier = SIZE_SHORT;
    if (size_specifier == 0)
        *index = current_index - 1;
    else
        *index = current_index;
    return (size_specifier);
}