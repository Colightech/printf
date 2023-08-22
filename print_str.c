#include "main.h"

/**
 * print_str - function that print string format
 * @arglist: variadic parameter
 * Return: number of string printed
 */

int print_str(va_list arglist)
{
	char *str;
	int x, slen = 0;
	int count = 0;

	str = va_arg(arglist, char *);
	if (str)
	{
		for (x = 0; str[x] != '\0'; x++)
			slen++;
		count = write(1, str, slen);
		count += slen;
	}
	return (count);
}
