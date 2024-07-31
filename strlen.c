#include "main.h"

/**
* _strlen - computes the length of a string
* @s: pointer to the string
* Return: the length of the string
* Printf project by Evans Adu and Enoch Kabange
*/

int _strlen(char *s)
{
int itrt;
int length = 0;

for (itrt = 0; s[itrt] != '\0'; itrt++)
length++;

return (length);
}

/**
*_strlenc - calculates the length of a constant string
* @s: pointer to the constant string
* Return: length of the string
*/

int _strlenc(const char *s)
{
int itrt;
int length = 0;

for (itrt = 0; s[itrt] != '\0'; itrt++)
length++;

return (length);
}

