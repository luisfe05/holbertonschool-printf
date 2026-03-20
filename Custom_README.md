# _printf — Custom C printf Function

> A custom implementation of the standard `printf` function in C.

---

## Authors

| Name | GitHub |
|------|--------|
| 🎵 Antonio Torres | [@atanih](https://github.com/atanih) |
| 🐕 Luis Felipe Gonzalez | [@luisfe05](https://github.com/luisfe05) |
| 🐈 Joshua Santiago | [@jSantiago318](https://github.com/jSantiago318) |

---

## Description

This project implements a custom function, `_printf`, that produces formatted output based on a format string — mimicking the behavior of the standard C `printf`.

```c
int _printf(const char *format, ...);
```

---

## Supported Format Specifiers

| Specifier | Description |
|-----------|-------------|
| `%c` | Prints a single character |
| `%s` | Prints a string |
| `%%` | Prints a literal `%` sign |

---

## 📁 Files

| File | Description |
|------|-------------|
| `main.h` | Header file with function prototypes and macros |
| `_printf.c` | Core implementation of the `_printf` function |

---

## Man Page

```bash
man _printf
```

---

## Example Usage

```c
#include "main.h"

int main(void)
{
    _printf("Hello, %s!\n", "world");
    _printf("Letter: %c\n", 'A');
    _printf("Percent sign: %%\n");
    return (0);
}
```

---