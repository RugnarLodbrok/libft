#include <stdio.h>
#include <stdarg.h>
#include "libft.h"
#include "unistd_compat.h"
#include "ft_printf.h"

t_printf_handler g_handler_tab[] =
		{
				{"d", &printf_handler_d, "int",   sizeof(int)},
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

ft_printf_arg get_next_arg(va_list ap, const char *literal)
{
	ft_printf_arg arg;

	if (!ft_strcmp(literal, "d"))
		arg.d = va_arg(ap, int);
	else if (!ft_strcmp(literal, "c"))
		arg.c = (char) va_arg(ap, int);
	else if (!ft_strcmp(literal, "s"))
		arg.s = va_arg(ap, char*);
	else
		arg.s = 0;
	return (arg);
}

size_t count_va_len(const char *format)
{
	char *ptr;
	size_t ret;

	ret = 0;
	ptr = (char *) format;
	while ((ptr = ft_strchr(ptr, '%')))
		ret += get_handler(&ptr)->size;
	return (ret);
}

void ft_printf_make_print(const char *format, ft_printf_args *args)
{
	ft_printf_arg arg;
	t_printf_handler *h;
	char *ptr;
	char *ptr1;

	ptr = (char *) format;
	ptr1 = ptr;
	while ((ptr = ft_strchr(ptr, '%')))
	{
		write(1, ptr1, ptr - ptr1);
		h = get_handler(&ptr);
		arg = ft_printf_args_next(args, h->size);
		h->f(arg);
		ptr1 = ptr;
	}
	ft_putstr(ptr1);
}

void ft_printf(const char *format, ...)
{
	va_list ap;
	size_t va_len;
	ft_printf_args args;

	va_len = count_va_len(format);
	va_start(ap, format);
	ft_printf_args_init(&args, ap, va_len);
	ft_printf_make_print(format, &args);
	va_end(ap);
}
//1 way: copy all var_arg data using va_arg macro, then manually extract variables
//2 way: run va_arg in nested calls
