#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <stdarg.h>
#include "libft.h"

# define PRINTF_HASH 1
# define PRINTF_ZERO 2
# define PRINTF_MINUS 4
# define PRINTF_SPACE 8
# define PRINTF_PLUS 16
# define PRINTF_UPPERCASE 32

typedef struct
{
	uint flags;
	size_t field_width;
	char type;
	unsigned char prefix_w;
	int precision;
	char format[4];
} t_printf_spec;

typedef union {
	long double f;
	long long int d;
	unsigned long long int u;
} t_printf_arg;

int ft_printf_ap(int fd, const char *format, va_list ap);
int ft_printf_item(int fd, va_list ap, t_printf_spec s);

#endif
