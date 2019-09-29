#include <stdio.h>
#include <stdarg.h>
#include "libft.h"
#include "unistd_compat.h"
#include "ft_printf.h"

int parse_format(char *s, uint *flags)
{
	if (*s == '#')
		*flags |= PRINTF_HASH;
	else if (*s == '0')
		*flags |= PRINTF_ZERO;
	else if (*s == '-')
		*flags |= PRINTF_MINUS;
	else if (*s == '+')
		*flags |= PRINTF_PLUS;
	else if (*s == ' ')
		*flags |= PRINTF_SPACE;
	if (ft_strchr("lhL#0+- ", *s))
		return (1 + parse_format(s + 1, flags));
	return 1;
}

static int printf_conversion(int fd, va_list ap, char **ptr)
{
	char s[64];
	int n;
	uint flags;

	flags = 0;
	n = parse_format(++(*ptr), &flags);
	ft_memcpy(s, *ptr, n);
	s[n] = 0;
	*ptr += n;
	return ft_printf_item(fd, ap, s);
}

int ft_printf_ap(int fd, const char *format, va_list ap)
{
	char *ptr;
	char *ptr1;
	int n;
	int r;

	r = 0;
	ptr = (char *) format;
	ptr1 = ptr;
	while ((ptr = ft_strchr(ptr, '%')))
	{
		r += write(fd, ptr1, ptr - ptr1);
		CHECK1RET1(n = printf_conversion(fd, ap, &ptr));
		r += n;
		ptr1 = ptr;
	}
	r += ft_putstr_fd(ptr1, fd);
	return (r);
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
