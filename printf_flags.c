#include "main.h"
/**
 * retrieve_flags - Determines active flags from the formatted string.
 * @format: Formatted string to interpret.
 * @position: Position within the formatted string.
 * Return: Active Flags
 */

int retrieve_flags(const char *format, int *position)
{
    int index, current_position;
    int active_flags = 0;
    const char FLAGS_CHARAC[] = {'-', '+', '0', '#', ' ', '\0'};
    const int FLAGS_VALUES[] = {MINUS_FLAG, PLUS_FLAG, ZERO_FLAG, HASH_FLAG, SPACE_FLAG,
                             0};
    for (current_position = *position + 1; format[current_position] != '\0'; current_position++)
    {
        for (index = 0; FLAGS_CHARAC[index] != '\0'; index++)
            if (format[current_position] == FLAGS_CHARAC[index])
            {
                active_flags |= FLAGS_VALUES[index];
                break;
            }
        if (FLAGS_CHARAC[index] == 0)
            break;
    }
    *position = current_position - 1;
    return (active_flags);
}
