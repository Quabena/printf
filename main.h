#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>

/* Macros for flags */
#define FLAG_PLUS 1
#define FLAG_SPACE 2
#define FLAG_HASH 4
#define FLAG_ZERO 8
#define FLAG_MINUS 16

/* Macros for length modifiers */
#define LENGTH_SHORT 1
#define LENGTH_LONG 2

/* Buffer size */
#define BUFFER_SIZE 1024

/* Main printf function prototype */
int _printf(const char *format, ...);

/* Function prototypes for handling conversion specifiers */
int handle_conversion(char specifier, va_list args, int flags, int width,
		      int precision, int length, char *buffer, int *buffer_index);

/* Utility functions */
int _putchar(char c, char *buffer, int *buffer_index);
int _putstr(char *str, int width, int precision,
	    char *buffer, int *buffer_index);
int _putnum(long num, int base, int is_upper, int flags,
	    int width, int precision, char *buffer, int *buffer_index);
int _putunsigned(unsigned long num, int base, int is_upper, int flags,
		 int width, int precision, char *buffer, int *buffer_index);

/* Conversion specifier functions */
int handle_c_specifier(va_list args, char *buffer, int *buffer_index);
int handle_s_specifier(va_list args, char *buffer, int *buffer_index);
int handle_percent_specifier(char *buffer, int *buffer_index);
int handle_di_specifier(va_list args, char *buffer, int *buffer_index,
			int width, int precision, int flags, int length_mod);
int handle_b_specifier(va_list args, char *buffer,
		       int *buffer_index, int width, int precision, int flags);
int handle_uoxX_specifier(va_list args, char *buffer, int *buffer_index,
			  int width, int precision, int flags, int length_mod, char specifier);
int handle_S_specifier(va_list args, char *buffer, int *buffer_index,
		       int width, int precision, int flags);
int handle_p_specifier(va_list args, char *buffer, int *buffer_index,
		       int width, int precision, int flags);
int handle_r(va_list args, char *buffer, int *buffer_index, int width,
	     int precision, int flags);
int handle_R(va_list args, char *buffer, int *buffer_index,
	     int width, int precision, int flags);
int handle_c_s_percent(const char *specifier, va_list args, char *buffer,
		       int *buffer_index, int width, int precision, int flags);

/* Helper functions */
int handle_flags(const char **format, int *flags);
int handle_width(const char **format, va_list args);
int handle_precision(const char **format, va_list args);
int handle_length(const char **format);

/* Buffer management */
void flush_buffer(char *buffer, int *buffer_index);

#endif /* MAIN_H */
