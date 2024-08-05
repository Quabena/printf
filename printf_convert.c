#include "main.h"

/**
 * convert_signed_size - Converts a number to the specified size
 * @number: Number to be converted
 * @size_specifier: The type specifier
 * Return: Casted value of the number
 */

long int convert_signed_size(long int number, int size_specifier)
{
    if (size_specifier == SIZE_LONG)
        return (number);
    else if (size_specifier == SIZE_SHORT)
        return ((short)number);
    return ((int)number);
}

/**
 * convert_unsigned_size - Conversts an unsigned integer
 * @number: Number to be converted
 * @size_specifier: The size specifier
 * Return: THe converted number
 */

long int convert_unsigned_size(unsigned long int number, int size_specifier)
{
    if (size_specifier == SIZE_LONG)
        return (number);
    else if (size_specifier == SIZE_SHORT)
        return ((unsigned short)number);
        
    return ((unsigned int)number);
}