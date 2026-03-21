# Group Project - C - _printf

## Authors

- Antonio Torres 🎵
- Luis Felipe Gonzalez 🐕
- Joshua Santiago 🐱

## Synopsis

This project implements a custom function, `_printf`, that produces output based on a format string.

Supported format specifiers:

- `%c` - prints a character
- `%s` - prints a string
- `%d` - prints a decimal integer
- `%i` - prints an integer
- `%%` - prints a literal percent sign

## Prototype
```c
int _printf(const char *format, ...);
```

## Files

- `main.h` - Header file containing function prototypes.
- `_printf.c` - Implementation of the custom `_printf` function.
- `man_3_printf.3` - Man page with information about `_printf`.