#include "libft.h"
#include "unistd_compat.h"
#include "ft_printf.h"

#include <stdio.h>

void printf_handler_d(ft_printf_arg v)
{
	char *s;

	s = ft_itoa(v.d);
	ft_putstr(s);
	free(s);
}

void printf_handler_s(ft_printf_arg v)
{
	ft_putstr(v.s);
}

void printf_handler_c(ft_printf_arg v)
{
	ft_putchar(v.c);
}
