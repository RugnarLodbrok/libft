#include <stdarg.h>
#include "libft.h"
#include "ft_printf.h"

void prepend_str(char *buff, const char *s)
{
	int len;

	len = ft_strlen(s);
	ft_memmove(buff + len, buff, ft_strlen(buff) + 1);
	ft_memcpy(buff, s, len);
}

char *convert_uint(char *b, unsigned long long int v, t_printf_spec s)
{
	if (s.type == 'u')
		ft_ultoa_buf(b, v, 10);
	else if (s.type == 'o')
		ft_ultoa_buf(b, v, 8);
	else if (ft_tolower(s.type) == 'x')
		ft_ultoa_buf(b, v, 16);
	if ((s.flags & PRINTF_HASH) && v && s.type == 'o')
		prepend_str(b, "0");
	if ((s.flags & PRINTF_HASH) && ft_tolower(s.type) == 'x')
		prepend_str(b, "0x");
	if (s.flags & PRINTF_PLUS) // && v >= 0
		prepend_str(b, "+");
	else if (s.flags & PRINTF_SPACE) // && v >= 0
		prepend_str(b, " ");
	if (s.type == 'X')
		ft_toupper_inplace(b);
	return (b);
}

char *convert_int(char *b, long long int v, t_printf_spec s)
{
	ft_itoa_buf(b, v, 10);
	if (s.flags & PRINTF_PLUS && v >= 0)
		prepend_str(b, "+");
	else if (s.flags & PRINTF_SPACE && v >= 0)
		prepend_str(b, " ");
	return (b);
}
char *convert_double(char *b, long double v, t_printf_spec s)
{
	ft_ftoa_buf(b, v, 6);
	if (s.flags & PRINTF_PLUS && v >= 0)
		prepend_str(b, "+");
	else if (s.flags & PRINTF_SPACE && v >= 0)
		prepend_str(b, " ");
	return (b);
}

char *apply_fw(char *b, t_printf_spec s)
{
	char fill_c;
	size_t len;

	fill_c = ' ';
	if (s.flags & PRINTF_ZERO)
		fill_c = '0';
	len = ft_strlen(b);
	if (s.field_width > len)
	{
		if (s.flags & PRINTF_MINUS)
			ft_memset(b + len, fill_c, s.field_width - len);
		else
		{
			ft_memmove(b + s.field_width - len, b, len + 1);
			ft_memset(b, fill_c, s.field_width - len);
		}
		b[s.field_width] = 0;
	}
	return (b);
}

int ft_printf_item(int fd, va_list ap, t_printf_spec s)
{
	char b[64];
	t_printf_arg v;

	ft_bzero(b, sizeof(b));
	if (ft_strchr("di", s.type))
	{
		if (ft_strstr(s.format, "ll"))
			v.d = va_arg(ap, long long int);
		else if (ft_strstr(s.format, "l"))
			v.d = va_arg(ap, long int);
		else if (ft_strstr(s.format, "hh"))
			v.d = (signed char) va_arg(ap, int);
		else if (ft_strstr(s.format, "h"))
			v.d = (short int) va_arg(ap, int);
		else
			v.d = va_arg(ap, int);
		convert_int(b, v.d, s);
	}
	else if (ft_strchr("uoxX", s.type))
	{
		if (ft_strstr(s.format, "ll"))
			v.u = va_arg(ap, unsigned long long int);
		else if (ft_strstr(s.format, "l"))
			v.u = va_arg(ap, ulong);
		else if (ft_strstr(s.format, "hh"))
			v.u = (unsigned char) va_arg(ap, uint);
		else if (ft_strstr(s.format, "h"))
			v.u = (short int) va_arg(ap, uint);
		else
			v.u = va_arg(ap, uint);
		convert_uint(b, v.u, s);
	}
	else if (s.type == 'f')
	{
		if (!ft_strcmp("f", s.format))
			v.f = va_arg(ap, double);
		else if (!ft_strcmp("Lf", s.format))
			v.f = va_arg(ap, long double);
		convert_double(b, v.f, s);
	}
	else if ('c' == s.type)
		b[0] = (char) va_arg(ap, int);
	else if (!ft_strcmp("s", s.format))
		ft_strcpy(b, va_arg(ap, char*));
	else if (!ft_strcmp("p", s.format))
		ft_ultoa_buf(ft_strcpy(b, "0x") + 2, (ulong) va_arg(ap, void*), 16);
	else if (!ft_strcmp("%", s.format))
		return ft_putchar_fd('%', fd);
	else
		return (-1);
	return ft_putstr_fd(apply_fw(b, s), fd);
}
