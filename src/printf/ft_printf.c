#include <stdio.h>
#include <stdarg.h>
#include "libft.h"
#include "unistd_compat.h"
#include "ft_printf.h"

int parse_field_width(char **s)
{
	int r;

	r = 0;
	if (**s != '0' && ft_isdigit(**s))
	{
		r++;
		(*s)++;
	}
	while (ft_isdigit(**s))
	{
		r++;
		(*s)++;
	}
	return (r);
}

uint parse_flags(char **s)
{
	uint flags;

	flags = 0;
	while (ft_strchr("#0+- ", **s))
	{
		if (**s == '#')
			flags |= PRINTF_HASH;
		else if (**s == '0')
			flags |= PRINTF_ZERO;
		else if (**s == '-')
			flags |= PRINTF_MINUS;
		else if (**s == '+')
			flags |= PRINTF_PLUS;
		else if (**s == ' ')
			flags |= PRINTF_SPACE;
		(*s)++;
	}
	return (flags);
}

void parse_format(char *dst, char **s)
{
	while (ft_strchr("lhL", **s))
		*dst++ = *(*s)++;
	if (ft_strchr("diouxXscpf%", **s))
		*dst++ = *(*s)++;
	*dst = 0;
}

static int printf_conversion(int fd, va_list ap, char **ptr)
{
	t_printf_spec spec;
	int n;

	(*ptr)++;
	spec.field_width = parse_field_width(ptr);
	spec.flags = parse_flags(ptr);
	parse_format(spec.format, ptr);
	if ((n = ft_printf_item(fd, ap, spec)) >= 0)
		return (n);
	ft_putchar_fd('%', fd);
	return 1;
}

int ft_printf_ap(int fd, const char *format, va_list ap)
{
	char *ptr;
	char *ptr1;
	int r;

	r = 0;
	ptr = (char *) format;
	ptr1 = ptr;
	while ((ptr = ft_strchr(ptr, '%')))
	{
		r += write(fd, ptr1, ptr - ptr1);
		r += printf_conversion(fd, ap, &ptr);
		ptr1 = ptr;
	}
	r += ft_putstr_fd(ptr1, fd);
	return (r);
}

int ft_printf(const char *format, ...)
{
	int r;
	va_list ap;

	va_start(ap, format);
	r = ft_printf_ap(1, format, ap);
	va_end(ap);
	return (r);
}

int ft_fprintf(int fd, const char *format, ...)
{
	int r;
	va_list ap;

	va_start(ap, format);
	r = ft_printf_ap(fd, format, ap);
	va_end(ap);
	return (r);
}
