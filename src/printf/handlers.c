#include "libft.h"
#include "unistd_compat.h"
#include "ft_printf.h"

#include <stdio.h>

void putstr_and_free(char *s)
{
	ft_putstr(s);
	free(s);
}
/*
 * -----------------int----------------------
 * */
void printf_handler_d(t_printf_arg v)
{
	putstr_and_free(ft_itoa(v.d));
}

void printf_handler_li(t_printf_arg v)
{
	putstr_and_free(ft_itoa(v.li));
}

void printf_handler_lli(t_printf_arg v)
{
	putstr_and_free(ft_itoa(v.lli));
}

void printf_handler_hi(t_printf_arg v)
{
	putstr_and_free(ft_itoa(v.hi));
}

void printf_handler_hhi(t_printf_arg v)
{
	putstr_and_free(ft_itoa(v.hhi));
}

/*
 * -----------------unsigned int----------------------
 * */

void printf_handler_u(t_printf_arg v)
{
	putstr_and_free(ft_ultoa_base(v.u, 10));
}

void printf_handler_lu(t_printf_arg v)
{
	putstr_and_free(ft_ultoa_base(v.lu, 10));
}

void printf_handler_llu(t_printf_arg v)
{
	putstr_and_free(ft_ultoa_base(v.llu, 10));
}

void printf_handler_hu(t_printf_arg v)
{
	putstr_and_free(ft_ultoa_base(v.hu, 10));
}

void printf_handler_hhu(t_printf_arg v)
{
	putstr_and_free(ft_ultoa_base(v.hhu, 10));
}

/*
 * -----------------unsigned oct----------------------
 * */

void printf_handler_o(t_printf_arg v)
{
	putstr_and_free(ft_ultoa_base(v.u, 8));
}

void printf_handler_lo(t_printf_arg v)
{
	putstr_and_free(ft_ultoa_base(v.lu, 8));
}

void printf_handler_llo(t_printf_arg v)
{
	putstr_and_free(ft_ultoa_base(v.llu, 8));
}

void printf_handler_ho(t_printf_arg v)
{
	putstr_and_free(ft_ultoa_base(v.hu, 8));
}

void printf_handler_hho(t_printf_arg v)
{
	putstr_and_free(ft_ultoa_base(v.hhu, 8));
}

/*
 * -----------------unsigned hex----------------------
 * */

void printf_handler_x(t_printf_arg v)
{
	putstr_and_free(ft_ultoa_base(v.u, 16));
}

void printf_handler_lx(t_printf_arg v)
{
	putstr_and_free(ft_ultoa_base(v.lu, 16));
}

void printf_handler_llx(t_printf_arg v)
{
	putstr_and_free(ft_ultoa_base(v.llu, 16));
}

void printf_handler_hx(t_printf_arg v)
{
	putstr_and_free(ft_ultoa_base(v.hu, 16));
}

void printf_handler_hhx(t_printf_arg v)
{
	putstr_and_free(ft_ultoa_base(v.hhu, 16));
}

/*
 * -----------------unsigned HEX----------------------
 * */

void printf_handler_X(t_printf_arg v)
{
	char *s;

	s = ft_ultoa_base(v.u, 16);
	ft_toupper_inplace(s);
	ft_putstr(s);
	free(s);
}

void printf_handler_lX(t_printf_arg v)
{
	char *s;

	s = ft_ultoa_base(v.lu, 16);
	ft_toupper_inplace(s);
	ft_putstr(s);
	free(s);
}

void printf_handler_llX(t_printf_arg v)
{
	char *s;

	s = ft_ultoa_base(v.llu, 16);
	ft_toupper_inplace(s);
	ft_putstr(s);
	free(s);
}

void printf_handler_hX(t_printf_arg v)
{
	char *s;

	s = ft_ultoa_base(v.hu, 16);
	ft_toupper_inplace(s);
	ft_putstr(s);
	free(s);
}

void printf_handler_hhX(t_printf_arg v)
{
	char *s;

	s = ft_ultoa_base(v.hhu, 16);
	ft_toupper_inplace(s);
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
	ft_putstr("0x");
	putstr_and_free(ft_ultoa_base(v.lu, 16));
}



void printf_handler_f(t_printf_arg v)
{
	putstr_and_free(ft_ftoa(v.f, 6));
}
