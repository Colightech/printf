#include "main.h"
/**
 * _printf - function that produces output according to a format.
 * @format: placeholder
 * Return: return the numbers printed
 */
int _printf(const char *format, ...)
{
	int count = 0, result = 0;
	int (*fp)(va_list);
	va_list arglist;

	if (!format || (format[0]  == '%' && format[1] == '0'))
		return (-1);
	va_start(arglist, format);
	while (*format)
	{
		if (*format != '%')
		{
			write(1, format, 1);
			count ++;
		}
		else
		{
			format++;
			fp = find_specifiers(format);
			if (fp != NULL)
			{
				result = fp(arglist);
				count += result;
			}
			else if (fp == NULL)
			{
				break;
			}
		}
		format++;
	}
	va_end(arglist);
	return (count);
}
