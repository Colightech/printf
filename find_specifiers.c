#include "main.h"

/**
 * find_specifiers - despense the right function for arequire specifier
 * @format: format parameter
 * Return: point to function
 */

int (*find_specifiers(const char *format))(va_list)
{
	int x;

	func_t my_arr[4] = {
		{"c", print_ch},
		{"s", print_str},
		{"%", print_pcent},
		{NULL, NULL}};

	for (x = 0; my_arr[x].t != NULL; x++)
	{
		if (*(my_arr[x].t) == *format)
		{
			return (my_arr[x].f);
		}
	}
	return (NULL);
}
