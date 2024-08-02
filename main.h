#ifndef MAIN_H
#define MAIN_H

#include <stdlib.h>
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>


/**
* struct flags - struct with flags for plus, space, hash, negative and zero
* @plus: '+' flag
* @space: ' ' flag
* @hash: '#' flag
* @negative: '-' flag
* @zero: '0' flag
*/
typedef struct flags
{
	int plus;
	int space;
	int hash;
	int negative;
	int zero;
} flag_settings;

/**
 * struct format_spec_func - struct that determines the format
 * @d: Stores the format specifier character
 * @format: Points to the flag_settings structure
 * Authors: Evans Adu and Enoch Kabange
 */

typedef struct format_spec_func
{
	char d;
	int (*format)(va_list args, flag_settings *format);
} format_specifier_map;

int _printf(const char *format, ...);

void get_integer(int n);
int print_integer(va_list args, flag_settings *format);
int integer_length(int value);
int apply_flags(char specifier, flag_settings *format);
char *convert_to_base(unsigned long int number, int base, int is_lowercase);
int print_unsigned_int(va_list args, flag_settings *format);
int print_address(va_list args, flag_settings *format);
int (*select_format_function(char specifier))(va_list, flag_settings *);
int print_char(va_list args, flag_settings *format);
int print_string(va_list args, flag_settings *format);
int print_hex_upper(va_list args, flag_settings *format);
int print_hex_lower(va_list args, flag_settings *format);

int reverse_string(va_list args, flag_settings *format);
int print_binary(va_list args, flag_settings *format);
int print_non_printable(va_list args, flag_settings *format);
int _putchar(char c);
int _puts(char *str);
int print_rot13(va_list args, flag_settings *format);
int print_percent(va_list args, flag_settings *format);
int print_octal(va_list args, flag_settings *format);

#endif
