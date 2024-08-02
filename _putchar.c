#include "main.h"

/**
* _putchar - Prints the character 'c' to stdout
* @c: The character to print
* Return: On success 1, or -1 on error
* Evans Adu and Enoch Kabange
*/

int _putchar(char c)
{
static char buffer[1024];
static int a;

if (a >= 1024 || c == -1)
{
write(1, &buffer, a);
a = 0;
}
if (c != -1)
{
buffer[a] = c;
a++;
}
return (1);
}
