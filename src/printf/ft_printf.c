#include <stdio.h>
#include <stdarg.h>
#include "libft.h"
#include "unistd_compat.h"
#include "ft_printf.h"

int parse_format(char *s)
{
	if (*s == 'h' || *s == 'l' || *s == 'L')
		return (1 + parse_format(s + 1));
	return 1;
}

int ft_printf_ap(int fd, const char *format, va_list ap)
{
	char *ptr;
	char *ptr1;
	char s[8];
	int n;
	int r;

	r = 0;
	ptr = (char *) format;
	ptr1 = ptr;
	while ((ptr = ft_strchr(ptr, '%')))
	{
		r += write(fd, ptr1, ptr - ptr1);
		n = parse_format(ptr + 1);
		ft_memcpy(s, ptr + 1, n);
		s[n] = 0;
		ptr += n + 1;
		CHECK1RET1(n = ft_printf_item(fd, ap, s));
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
