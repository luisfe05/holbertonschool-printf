#include "main.h"
/**
 * _printf - print output according to a format string
 * @format: format string
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
    va_start(args, format); /*start the arguments*/
    count = 0;
    ptr_string = format;
    while (*ptr_string) /*go across all letter up to 0*/
    {
        if (*ptr_string != '%')
        {
            write(1, ptr_string, 1); /*print letter*/
            count++;/*sum 1*/
        }
        else
        {
            ptr_string++; /*jumps % and points to 's'*/
            if (!*ptr_string)
            {
                    va_end(args); /*end the arguments*/
                    return (count); /*return the number of printed characters*/
            }
            if (*ptr_string == 'c') /*prints 1 character for c*/
                count += print_char(args); 
            else if (*ptr_string == 's') /*print a string for %s*/
                count += print_string(args);
            else if (*ptr_string == 'd' || *ptr_string == 'i') /*prints interger for %d and %i */
                count += print_int(args); 
            else if (*ptr_string == '%') /*prints '%'*/
            {
                write(1, "%", 1); /*prints '%'*/
                count ++;
            }
            else
            {
                write(1, "%", 1);
                write(1, ptr_string, 1); /*prints unknown character*/
                count += 2;
            }
        }
        ptr_string++;
    }
    va_end(args); /*end the arguments*/
    return (count); /*return the number of printed characters*/
}
