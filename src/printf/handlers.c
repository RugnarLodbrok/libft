#include "libft.h"
#include "unistd_compat.h"
#include "ft_printf.h"

#include <stdio.h>

void printf_handler_d(t_printf_arg v)
{
	char *s;

	s = ft_itoa(v.d);
	ft_putstr(s);
	free(s);
}

void printf_handler_s(t_printf_arg v)
{
	ft_putstr(v.s);
}

void printf_handler_c(t_printf_arg v)
{
	ft_putchar(v.c);
}

void printf_handler_p(t_printf_arg v)
{
	char *s;
	ft_putstr("0x");
	s = ft_ultoa_base(v.lu, 16);
	ft_putstr(s);
	free(s);
}
