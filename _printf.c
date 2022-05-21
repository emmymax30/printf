#include "main.h"
#include <stddef.h>
#include <stdarg.h>

int _printf(const char * const format, ...)
{
	va_list args;
	int i = 0, j = 0;
	char *s = NULL;

	int n_display = 0;

	va_start(args, format);

	while(format[i] != '\0')
	{
		if (format[i] != '%')
		{
			_putchar(format[i]);
			n_display++;
		}
		else if (format[i+1] == 'c')
		{
			_putchar(va_arg(args, int));
			n_display++;
			i++;
		}
		else if (format[i+1] == 's')
		{
			i++;
			s = va_arg(args, char *);
			j = 0;
			while (s[j] != '\0')
			{
				_putchar(s[j]);
				n_display++;
				j++;
			}
		
		}
		else if (format[i+1] == '%')
		{
			i++;
			_putchar('%');
			n_display++;
		}
		i++;
	}

	va_end(args);

	return (n_display);
}
