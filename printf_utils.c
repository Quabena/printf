/**
 * printable_char - Checks if a character is printable.
 * @c: The character to be checked.
 *
 * Return: 1 if the character is printable, 0 otherwise.
 */

int printable_char(char c)
{
    if (c >= 32 && c < 127)
        return (1);
    return (0);
}

/**
 * is_numeric - Determines if a character is a digit.
 * @c: The character to be checked.
 *
 * Return: 1 if the character is a digit, 0 otherwise.
 */

int is_numeric(char c)
{
    if (c >= '0' && c <= '9')
        return (1);
    return (0);
}