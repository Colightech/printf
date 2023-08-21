#include "main.h"
/**
 * _printf - function that produces output according to a format.
 * @format: placeholder
 * Return: return the numbers printed
 */
int _printf(const char *format, ...)
{
	char *str;
	int slen, ch, x, print_ch = 0;
	va_list arglist;

	if (format == NULL)
		return (-1);
	va_start(arglist, format);

	while (*format)
	{
		if (*format != '%')
		{
			write(1, format, 1);
			print_ch++;
		}
		else
		{
			format++;
			if (*format == '\0')
			{
				break;
			}
			else if (*format == '%')
			{
				write(1, format, 1);
				print_ch++;
			}
			else if (*format == 'c')
			{
				ch = va_arg(arglist, int);
				write(1, &ch, 1);
				print_ch++;
			}
			else if (*format == 's')
			{
				str = va_arg(arglist, char *);
				for (x = 0; str[x] != '\0'; x++)
					slen++;
				write(1, str, slen);
				print_ch += slen;
			}
		}
		format++;
	}
	va_end(arglist);
	return (print_ch);
}
