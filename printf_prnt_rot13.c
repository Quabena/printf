#include "main.h"

/**
* print_rot13 - Encodes and prints a string using ROT13 cipher.
* @args: Variable argument list containing the string to encode
* @format: Structure containing formatting flags
* Return: The number of characters printed
* Authors: Evans Adu and Enoch Kabange
*/

int print_rot13(va_list args, flag_settings *format)
{
	int index, char_count, i;
	char original_chars[] =
	  "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
	char encoded_chars[] =
	  "nopqrstuvwxyzabcdefghijklmNOPQRSTUVWXYZABCDEFGHIJKLM";
	char *str = va_arg(args, char *);

	(void)format;

	if (!str)
		return (_puts("(null)"));

	char_count = 0;

	for (index = 0; str[index]; index++)
	{
		if ((str[index] < 'A' ||
		     (str[index] > 'Z' && str[index] < 'a') ||
		     str[index] > 'z'))
			char_count += _putchar(str[index]);
		else
		{
			int match_found = 0;

			for (i = 0; i < 52; i++)
			{
				if (str[index] == original_chars[i])
				{
					char_count += _putchar(encoded_chars[i]);
					match_found = 1;
					break;
				}
			}
			if (!match_found)
				char_count += _putchar(str[index]);
		}
	}

	return (char_count);
}

