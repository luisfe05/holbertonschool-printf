#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h> 
#include <unistd.h>

int _printf(const char *format, ...);
int print_char(va_list args); /*prints %c*/
int print_string(va_list args); /*prints %s*/
int print_int(va_list args); /*prints %d and %i*/

#endif
