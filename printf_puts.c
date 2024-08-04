#include "main.h"

/**
* _puts - Prints the string 'str' to stdout
* @str: String to be printed
* Return: The printed string
* Authors: Evans Adu and Enoch Kabange
*/

int _puts(char *str)
{
	register int i;

	for (i = 0; str[i] != '\0'; i++)
		_putchar(str[i]);
	return (i);
}
