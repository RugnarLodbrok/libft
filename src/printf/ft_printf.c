#include <stdio.h>
#include <stdarg.h>
#include "libft.h"
#include "unistd_compat.h"
#include "ft_printf.h"

t_printf_handler g_handler_tab[] =
		{
				{"d", &printf_handler_d, "int", sizeof(int)},
				{"s", &printf_handler_s, "char*", sizeof(char*)},
				{"c", &printf_handler_c, "char", sizeof(char)}
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
		arg.c = va_arg(ap, char);
	else if (!ft_strcmp(literal, "s"))
		arg.s = va_arg(ap, char*);
	else
		arg.s = 0;
	return (arg);
}

void ft_printf(const char *format, ...)
{
	va_list ap;
	char *ptr;
	char *ptr1;
	ft_printf_arg arg;
	t_printf_handler *h;
	t_varg varg;
	t_list *arg_stack;

	varg_init(&varg, &format, sizeof(format));
//			va_start(ap, format);
	ptr = (char *) format;
	ptr1 = ptr;
	while ((ptr = ft_strchr(ptr, '%')))
	{
		write(1, ptr1, ptr - ptr1);
		h = get_handler(&ptr);
		printf("\nprocess: `%s`\n", h->literal);
		arg = varg_next(&varg, h->size);
//		arg = get_next_arg(ap, h->literal);
//		arg.d = va_arg(ap, int);
		h->f(arg);
		ptr1 = ptr;
	}
	ft_putstr(ptr1);
//			va_end(ap);
}
