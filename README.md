# ft_printf

The goal of the project was to rewrite libc function printf.

## Usage

```c
int   ft_printf(const char *format, ...)
```
ft_printf works with:<br>
* Conversions: ``c`` ``s`` ``p`` ``d`` ``i`` ``u`` ``x`` ``X`` ``%`` ``n``
* Flags: ``space`` ``#`` ``+`` ``0`` ``*`` ``-``
* Minimum width
* Precision ``.``
