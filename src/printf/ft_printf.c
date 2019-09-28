#include <stdio.h>
#include <stdarg.h>
#include "libft.h"
#include "unistd_compat.h"
#include "ft_printf.h"

t_printf_handler g_handler_tab[] =
{
	{"d", &printf_handler_d, "int",   sizeof(int)},
	{"i", &printf_handler_d, "int",   sizeof(int)},
	{"o", &printf_handler_o, "unsigned int", sizeof(unsigned int)},
	{"u", &printf_handler_u, "unsigned int", sizeof(unsigned int)},
	{"x", &printf_handler_x, "unsigned int", sizeof(unsigned int)},
	{"X", &printf_handler_X, "unsigned int", sizeof(unsigned int)},

	{"ld", &printf_handler_li, "long int",   sizeof(long int)},
	{"li", &printf_handler_li, "long int",   sizeof(long int)},
	{"lo", &printf_handler_lo, "unsigned long int", sizeof(unsigned long int)},
	{"lu", &printf_handler_lu, "unsigned long int", sizeof(unsigned long int)},
	{"lx", &printf_handler_lx, "unsigned long int", sizeof(unsigned long int)},
	{"lX", &printf_handler_lX, "unsigned long int", sizeof(unsigned long int)},

	{"lld", &printf_handler_lli, "long long int",   sizeof(long long int)},
	{"lli", &printf_handler_lli, "long long int",   sizeof(long long int)},
	{"llo", &printf_handler_llo, "unsigned long long int", sizeof(unsigned long long int)},
	{"llu", &printf_handler_llu, "unsigned long long int", sizeof(unsigned long long int)},
	{"llx", &printf_handler_llx, "unsigned long long int", sizeof(unsigned long long int)},
	{"llX", &printf_handler_llX, "unsigned long long int", sizeof(unsigned long long int)},

	{"hd", &printf_handler_hi, "short int",   sizeof(short int)},
	{"hi", &printf_handler_hi, "short int",   sizeof(short int)},
	{"ho", &printf_handler_ho, "unsigned short int", sizeof(unsigned short int)},
	{"hu", &printf_handler_hu, "unsigned short int", sizeof(unsigned short int)},
	{"hx", &printf_handler_hx, "unsigned short int", sizeof(unsigned short int)},
	{"hX", &printf_handler_hX, "unsigned short int", sizeof(unsigned short int)},

	{"hhd", &printf_handler_hhi, "signed char",   sizeof(signed char)},
	{"hhi", &printf_handler_hhi, "signed char",   sizeof(signed char)},
	{"hho", &printf_handler_hho, "unsigned char", sizeof(unsigned char)},
	{"hhu", &printf_handler_hhu, "unsigned char", sizeof(unsigned char)},
	{"hhx", &printf_handler_hhx, "unsigned char", sizeof(unsigned char)},
	{"hhX", &printf_handler_hhX, "unsigned char", sizeof(unsigned char)},

	{"f", &printf_handler_f, "double", sizeof(double)},
	{"p", &printf_handler_p, "void*", sizeof(void *)},
	{"s", &printf_handler_s, "char*", sizeof(char *)},
	{"c", &printf_handler_c, "char",  4/*sizeof(char)*/}
};

t_printf_handler *get_handler(char **p)
{
	int i;
	char r[8];

	(*p)++;
	r[0] = **p;
	r[1] = 0;
	(*p)++;
	i = -1;
	while (++i < (int) (sizeof(g_handler_tab) / sizeof(t_printf_handler)))
		if (!ft_strcmp(r, g_handler_tab[i].literal))
			return (&(g_handler_tab[i]));
	return (0);
}

int ft_printf_ap(int fd, const char *format, va_list ap)
{
	t_printf_arg arg;
	t_printf_handler *h;
	char *ptr;
	char *ptr1;

	ptr = (char *) format;
	ptr1 = ptr;
	while ((ptr = ft_strchr(ptr, '%')))
	{
		write(fd, ptr1, ptr - ptr1);
		h = get_handler(&ptr);
		if (!ft_strcmp(h->literal, "f"))
			arg.f = va_arg(ap, double);
		else
			arg = va_arg(ap, t_printf_arg);
		h->f(arg, fd);
		ptr1 = ptr;
	}
	ft_putstr_fd(ptr1, fd);
	return (1);
}

int	ft_printf(const char *format, ...)
{
	int r;
	va_list ap;

	va_start(ap, format);
	r = ft_printf_ap(1, format, ap);
	va_end(ap);
	return (r);
}

int	ft_fprintf(int fd, const char *format, ...)
{
	int r;
	va_list ap;

	va_start(ap, format);
	r = ft_printf_ap(fd, format, ap);
	va_end(ap);
	return (r);
}
