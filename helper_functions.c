#include "main.h"

/**
 * print_char - pritnt a single character
 * @args: va_list of arguments
 * return: number of characters printed
 */
int print_char(va_list args)
{    char c;

    c = va_arg(args, int); /*get the character from the arguments*/
    write(1, &c, 1); /*print the character*/
    return (1); /*return 1 because it printed one character*/
}

/**
 * print_string - print a string
 * @args: va_list of arguments
 * return: number of characters printed
 */
int print_string(va_list args)
{    char *str;
    int count;

    str = va_arg(args, char *); /*get the string from the arguments*/
    if (str == NULL)
        str = "(null)"; /*if the string is NULL, print (null)*/
    count = 0;
    while (*str) /*go across all letter up to 0*/
    {        write(1, str, 1); /*print the letter*/
        count++; /*sum 1*/
        str++;
    }
    return (count); /*return the number of printed characters*/
}

/**
 * print_int - print an integer
 * @args: va_list of arguments
 * return: number of characters printed
 */
int print_int(va_list args)
{    int num;
    int count;
    char buffer[12]; /*buffer to hold the string representation of the integer*/
    int i;

    num = va_arg(args, int); /*get the integer from the arguments*/
    if (num == 0)
    {        write(1, "0", 1); /*if the integer is 0, print 0*/
        return (1); /*return 1 because we printed one character*/
    }
    count = 0;
    if (num < 0)
    {        write(1, "-", 1); /*if the integer is negative, print '-'*/
        count++; /*sum 1*/
        num = -num; /*make the integer positive*/
    }
    i = 0;
    while (num > 0)
    {        buffer[i++] = (num % 10) + '0'; /*get the last digit and convert it to a character*/
        num /= 10; /*remove the last digit*/
    }
    while (i > 0)
    {        write(1, &buffer[--i], 1); /*print the digits in reverse order*/
        count++; /*sum 1*/
    }
    return (count); /*return the number of printed characters*/
}
