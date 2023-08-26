#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>

int _printf(const char *format, ...);
int (*find_specifiers(const char *format))(va_list);

/**
 * struct func - for specifier to pointer
 * @t: character to check
 * @f: function pointer
 */

typedef struct func
{
	char *t;
	int (*f)(va_list);
} func_t;

int print_ch(va_list arglist);
int print_str(va_list arglist);
int print_pcent(va_list arglist);


#endif
