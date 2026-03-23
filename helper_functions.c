#include "main.h"

/**
 * print_char - print a single character
 * @args: va_list containing the character
 *
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
 * @args: va_list containing the string
 *
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
 * print_number - prints an unsigned number recursively
 * @num: the unsigned number to print
 *
 * Return: number of characters printed
 */
int print_number(unsigned int num)
{
	int count = 0;
	char c;

	if (num >= 10) /* print all digits before the last one first */
		count += print_number(num / 10);

	c = (num % 10) + '0'; /* convert digit to ASCII character */
	write(1, &c, 1);
	count++;

	return (count);
}

/**
 * manager_int - prints an integer argument
 * @args: va_list containing the integer
 *
 * Return: number of characters printed
 */
int manager_int(va_list args)
{
	int n;
	unsigned int num;
	int count = 0;

	n = va_arg(args, int);

	if (n < 0)
	{
		write(1, "-", 1);
		count++;
		num = (unsigned int)(-(n + 1)) + 1; /* safe conversion, handles INT_MIN */
	}
	else
		num = (unsigned int)n;

	count += print_number(num);
	return (count);
}
