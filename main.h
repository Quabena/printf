#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

#define UNUSED(x) (void)(x)
#define BUFF_SIZE 1024

#define MINUS_FLAG 1
#define PLUS_FLAG 2
#define ZERO_FLAG 4
#define HASH_FLAG 8
#define SPACE_FLAG 16

#define SIZE_LONG 2
#define SIZE_SHORT 1

/**
* format_specifier - Struct representing a
* format specifier.
*
* @specifier: The format specifier character.
* @handler: Pointer to the function handling this
* format specifier.
*/

struct format_specifier
{
char specifier;
int (*handler)(va_list, char[], int, int, int, int);
};

typedef struct format_specifier format_handler_t;


int _printf(const char *format, ...);

int dispatch_format(const char *format, int *index,
		    va_list args, char output_buffer[],
		    int active_flags, int field_width, int precision_speci,
		    int size_specifier);



int print_character(va_list args, char output_buffer[],
		    int active_flags, int field_width,
		    int precision_speci, int size_specifier);

int print_string(va_list args, char output_buffer[],
		 int active_flags, int field_width,
		 int precision_speci, int size_specifier);
int print_percentage(va_list args, char output_buffer[],
		     int active_flags, int field_width,
		     int precision_speci, int size_specifier);

int print_integer(va_list args, char output_buffer[],
		  int active_flags, int field_width,
		  int precision_speci, int size_specifier);

int print_binary_format(va_list args, char output_buffer[], int active_flags,
			int field_width, int precision_speci, int size_specifier);

int print_unsigned_integer(va_list args, char output_buffer[],
			   int active_flags, int field_width,
			   int precision_speci, int size_specifier);

int print_octal(va_list args, char output_buffer[], int active_flags,
		int field_width, int precision_speci, int size_specifier);

int print_hex(va_list args, char output_buffer[], int active_flags,
	      int field_width, int precision_speci, int size_specifier);

int print_hex_uppercase(va_list args, char output_buffer[], int active_flags,
			int field_width, int precision_speci, int size_specifier);

int print_hex_generic(va_list args, char map_to[], char output_buffer[],
		      int active_flags, char flag_ch, int field_width,
		      int precision_speci,
		      int size_specifier);

int print_non_printable_chars(va_list args, char output_buffer[],
			      int active_flags, int field_width,
			      int precision_speci, int size_specifier);

int print_pointer(va_list args, char output_buffer[], int active_flags,
		  int field_width, int precision_speci, int size_specifier);

int retrieve_flags(const char *format, int *position);
int retrieve_width(const char *format, int *i, va_list list);
int retrieve_precision(const char *format, int *index, va_list args);
int determine_size(const char *format, int *index);

int print_reverse_string(va_list args, char output_buffer[],
			 int active_flags,
			 int field_width, int precision_speci, int size_specifier);

int print_rot13_str(va_list args, char output_buffer[], int active_flags,
		    int field_width,
		    int precision_speci, int size_specifier);

int handler_char_write(char c, char output_buffer[], int active_flags,
		       int field_width,
		       int precision_speci, int size_specifier);

int handler_number_write(int neg_flag, int index, char output_buffer[],
			 int active_flags,
			 int field_width, int precision_speci, int size_specifier);

int handler_generic_number(int index, char output_buffer[], int active_flags,
			   int field_width,
			   int precision_speci, int length, char padding_char,
			   char holder);

int pointer_address_handler(char output_buffer[], int index, int length,
			    int field_width,
			    int active_flags, char char_padding, char additional_char,
			    int padding_start);

int generic_unsigned_handler(int neg_num, int index, char output_buffer[],
			     int active_flags,
			     int field_width, int precision_speci, int size_specifier);

int printable_char(char);

int add_hex_code(char code_asc, char buffer[], int index);

int is_numeric(char);

long int convert_signed_size(long int num, int size_specifier);

long int convert_unsigned_size(unsigned long int num, int size_specifier);

void print_output_buffer(char output_buffer[], int *buffer_index);

#endif /* MAIN_H */
