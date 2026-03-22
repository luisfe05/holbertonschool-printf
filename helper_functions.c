#include "main.h"

/**
 * print_char - pritnt a single character
 * @args: va_list of arguments
 * return: number of characters printed
 */
int print_char(va_list args)
{    char c;
    int num;
    int count;
    char *buffer;
    int i;

    num = va_arg(args, int); /*get the integer from the arguments*/
    if (num == 0)
    {        write(1, "0", 1); /*if the integer is 0, print 0*/
        return (1); 
    }
    buffer = malloc(12 * sizeof(char)); /*allocate memory for the buffer*/
    if (buffer == NULL)
        return (-1); /*return -1 if malloc error*/
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
        count++; 
    }
    free(buffer); /*free the allocated memory*/
    return (count); /*return the number of printed characters*/
}
