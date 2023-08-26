#include "main.h"
/**
 * _printf - function that produces output according to a format.
 * @format: placeholder
 * Return: return the numbers printed
 */
int _printf(const char *format, ...)
{
	int x = 0, count = 0, result = 0;
	int (*f)(va_list);
	va_list arglist;

	if (!format)
		return (-1);
	va_start(arglist, format);
	while (format[x])
	{
		if (format[x] != '%')
		{
			result = write(1, &format[x], 1);
			count += result;
			x++;
			continue;
		}
		else if (format[x] == '%')
		{
			f = find_specifiers(&format[x + 1]);
			if (f != NULL)
			{
				result = f(arglist);
				count += result;
				x = x + 2;
				continue;
			}
			if (format[x + 1] == '\0')
				break;
			if (format[x + 1] != '\0')
			{
				result = write(1, &format[x + 1], 1);
				count += result;
				x = x + 2;
				continue;
			}
		}
	}
	va_end(arglist);
	return (count);
}
