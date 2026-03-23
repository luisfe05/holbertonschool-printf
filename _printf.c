#include "main.h"

/**
 * _printf - print output according to a format string
 * @format: format string containing text and conversion specifiers
 *
 * Return: number of characters printed, -1 if format is NULL
 */
int _printf(const char *format, ...)
{
	va_list args;
	int count;
	const char *ptr_string;

	if (format == NULL)
		return (-1);
	va_start(args, format);
	count = 0;
	ptr_string = format;
	while (*ptr_string)
	{
		if (*ptr_string != '%')
		{
			write(1, ptr_string, 1);
			count++;
		}
		else
		{
			ptr_string++; /* skip '%' and move to the specifier */
			if (!*ptr_string) /* '%' at end of string is invalid */
			{
				va_end(args);
				return (-1);
			}
			if (*ptr_string == 'c')
				count += print_char(args);
			else if (*ptr_string == 's')
				count += print_string(args);
			else if (*ptr_string == 'd' || *ptr_string == 'i')
				count += manager_int(args);
			else if (*ptr_string == '%')
			{
				write(1, "%", 1);
				count++;
			}
			else /* unknown specifier: print '%' and the letter as-is */
			{
				write(1, "%", 1);
				write(1, ptr_string, 1);
				count += 2;
			}
		}
		ptr_string++;
	}
	va_end(args);
	return (count);
}
