#include "main.h"

/**
 * print_ch - function that print character format
 * @arglist: variadic parameter
 * Return: number ofncharater printed
 */

int print_ch(va_list arglist)
{
	char ch;
	int count = 0;

	ch = (char)va_arg(arglist, int);
	if (ch)
	{
		count = write(1, &ch, 1);
		return (count);
	}
	return (0);
}
