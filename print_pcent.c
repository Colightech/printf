#include "main.h"

/**
 * print_pcent - function that print character format
 * @arglist: variadic parameter
 * Return: percentage (%)
 */

int print_pcent(va_list arglist)
{
	int pcent = '%';

	write(1, &pcent, 1);
	return (pcent);
}
