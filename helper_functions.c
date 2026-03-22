#include "main.h"
#include <stdlib.h>

/**
 * print_char - print a single character
 * @args: va_list of arguments
 * Return: number of characters printed
 */
int print_char(va_list args)
{
	char c;

	c = va_arg(args, int);
	write(1, &c, 1);
	return (1);
}

/**
 * print_string - print a string
 * @args: va_list of arguments
 * Return: number of characters printed
 */
int print_string(va_list args)
{
	char *str;
	int count;

	str = va_arg(args, char *);
	if (str == NULL)
		str = "(null)";
	count = 0;
	while (*str)
	{
		write(1, str, 1);
		count++;
		str++;
	}
	return (count);
}

/**
 * print_int - print an integer
 * @args: va_list of arguments
 * Return: number of characters printed
 */
int print_int(va_list args)
{
	int num;
	int count;
	char *buffer;
	int i;

	num = va_arg(args, int);
	if (num == 0)
	{
		write(1, "0", 1);
		return (1);
	}
	buffer = malloc(12 * sizeof(char));
	if (buffer == NULL)
		return (-1);
	count = 0;
	if (num < 0)
	{
		write(1, "-", 1);
		count++;
		num = -num;
	}
	i = 0;
	while (num > 0)
	{
		buffer[i++] = (num % 10) + '0';
		num /= 10;
	}
	while (i > 0)
	{
		write(1, &buffer[--i], 1);
		count++;
	}
	free(buffer);
	return (count);
}
