#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <limits.h>

/**
* struct format - structure for format specifier and corresponding function
* @specifier: format specifier, as a string.
* @func: functions that handles conversion for the specifier
*
* Description: used to map format specifiers to their handler functions
*/

typedef struct format
{
char *specifier;
int (*func)(va_list);
} convert;


/* Buffer definition and size */
#define BUFFER_SIZE 1024

/* _printf function prototype */
int _printf(const char *format, ...);

/* Other relevant prototypes */
int print_str(va_list args);
int print_percent(va_list args);
int print_char(va_list args);
int print_integer(va_list args);
int print_decimal(va_list args);
int print_bin(va_list args);
int print_unsigned_int(va_list args);
int print_hex(va_list args);
int print_HEX(va_list args);
int print_hex_extra(unsigned long int num);
int print_octal(va_list args);
int print_special_str(va_list args);
int print_ptr(va_list args);
int print_reverse_str(va_list args);
int print_rot13(va_list args);

int _putchar(char c);
int _strlenc(const char *s);
int _strlen(char *s);


#endif
