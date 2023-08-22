#include "main.h"
/**
 * _printf - function that produces output according to a format.
 * @format: placeholder
 * Return: return the numbers printed
 */
int _printf(const char *format, ...)
{
	int x = 0, count = 0, result = 0;
	int (*fp)(va_list);
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
			fp = find_specifiers(&format[x + 1]);
			if (fp != NULL)
			{
				result = fp(arglist);
				count += result;
				x = x + 2;
				continue;
			}
			if (format[x + 1] == '\0')
			{
				break;
			}
		}
		format++;
	}
	va_end(arglist);
	return (count);
}
