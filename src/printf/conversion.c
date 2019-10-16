/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edrowzee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 12:21:57 by edrowzee          #+#    #+#             */
/*   Updated: 2019/10/16 13:29:35 by edrowzee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "libft.h"
#include "ft_printf.h"
#include "unistd_compat.h"

void		prepend_str(char *buff, const char *s)
{
	int len;

	len = ft_strlen(s);
	ft_memmove(buff + len, buff, ft_strlen(buff) + 1);
	ft_memcpy(buff, s, len);
}

char		*convert_uint(char *b, unsigned long long int v, t_printf_spec *s)
{
	if (s->type == 'u')
		ft_ultoa_buf(b, v, 10);
	else if (s->type == 'o')
		ft_ultoa_buf(b, v, 8);
	else if (ft_tolower(s->type) == 'x')
		ft_ultoa_buf(b, v, 16);
	if (!s->precision && !v && (!(s->flags & PRINTF_HASH)
		| (ft_tolower(s->type) == 'x')))
		b[0] = 0;
	if ((s->flags & PRINTF_HASH) && v && s->type == 'o')
	{
		prepend_str(b, "0");
		s->prefix_w = 1;
	}
	while (s->precision > (int)ft_strlen(b))
		prepend_str(b, "0");
	if ((s->flags & PRINTF_HASH) && ft_tolower(s->type) == 'x' && v)
	{
		prepend_str(b, "0x");
		s->prefix_w = 2;
	}
	if (s->type == 'X')
		ft_toupper_inplace(b);
	return (b);
}

char		*convert_int(char *b, long long int v, t_printf_spec *s)
{
	ft_itoa_buf(b, v, 10);
	if (s->flags & PRINTF_PLUS && v >= 0)
		prepend_str(b, "+");
	else if (s->flags & PRINTF_SPACE && v >= 0)
		prepend_str(b, " ");
	if (v < 0 || (s->flags & (PRINTF_SPACE | PRINTF_PLUS)))
		s->prefix_w = 1;
	if (s->precision == 0 && !v && ft_strchr(b, '0'))
	{
		*ft_strchr(b, '0') = 0;
		return (b);
	}
	while (s->precision > (int)ft_strlen(b + s->prefix_w))
		prepend_str(b + s->prefix_w, "0");
	return (b);
}

char		*convert_double(char *b, long double v, t_printf_spec *s)
{
	ft_ftoa_buf(b, v, s->precision >= 0 ? s->precision : 6);
	if (s->flags & PRINTF_HASH && !s->precision)
		ft_strcat(b, ".");
	if (s->flags & PRINTF_PLUS && v >= 0)
		prepend_str(b, "+");
	else if (s->flags & PRINTF_SPACE && v >= 0)
		prepend_str(b, " ");
	if (v < 0 || (s->flags & (PRINTF_SPACE | PRINTF_PLUS)))
		s->prefix_w = 1;
	return (b);
}

void		apply_fw_width(char *b, char fill_c, t_printf_spec s, size_t len)
{
	if (s.field_width > len)
	{
		if (s.flags & PRINTF_MINUS)
			ft_memset(b + len, ' ', s.field_width - len);
		else
		{
			ft_memmove(b + s.field_width - len, b, len + 1);
			ft_memset(b, fill_c, s.field_width - len);
		}
		b[s.field_width] = 0;
	}
}

char		*apply_fw(char *b, t_printf_spec s)
{
	char	fill_c;
	size_t	len;
	char	*b_initial;

	fill_c = ' ';
	b_initial = b;
	if (s.flags & PRINTF_ZERO && (ft_strchr("diouxXpf", s.type) || MACOS)
		&& (s.type == 'f' || s.precision < 0))
	{
		fill_c = '0';
		b += s.prefix_w;
		if (s.field_width < s.prefix_w)
			s.field_width = 0;
		else
			s.field_width -= s.prefix_w;
	}
	len = ft_strlen(b);
	apply_fw_width(b, fill_c, s, len);
	return (b_initial);
}

static int	convert_string(int fd, int ret, t_printf_spec s, char *str)
{
	size_t	len;
	char	fill_c;

	fill_c = ' ';
	if ((s.flags & PRINTF_ZERO) && MACOS)
		fill_c = '0';
	if (!str)
		str = "(null)";
	len = ft_strlen(str);
	if (s.precision >= 0 && s.precision < (int)len)
		len = s.precision;
	if (s.flags & PRINTF_MINUS)
	{
		ret += write(fd, str, len);
		while (s.field_width-- > len)
			ret += write(fd, &fill_c, 1);
	}
	else
	{
		while (s.field_width-- > len)
			ret += write(fd, &fill_c, 1);
		ret += write(fd, str, len);
	}
	return (ret);
}

int			ft_printf_conversion_di(char *b, t_printf_arg *v,
			t_printf_spec *s, va_list ap)
{
	if (!ft_strcmp(s->modifiers, "ll"))
		v->d = va_arg(ap, long long int);
	else if (!ft_strcmp(s->modifiers, "l"))
		v->d = va_arg(ap, long int);
	else if (!ft_strcmp(s->modifiers, "hh"))
		v->d = (signed char)va_arg(ap, int);
	else if (!ft_strcmp(s->modifiers, "h"))
		v->d = (short int)va_arg(ap, int);
	else if (!ft_strcmp(s->modifiers, ""))
		v->d = va_arg(ap, int);
	convert_int(b, v->d, s);
	return (0);
}

int			ft_printf_conversion_uox(char *b, t_printf_arg *v,
			t_printf_spec *s, va_list ap)
{
	if (!ft_strcmp(s->modifiers, "ll"))
		v->u = va_arg(ap, unsigned long long int);
	else if (!ft_strcmp(s->modifiers, "l"))
		v->u = va_arg(ap, ulong);
	else if (!ft_strcmp(s->modifiers, "hh"))
		v->u = (unsigned char)va_arg(ap, uint);
	else if (!ft_strcmp(s->modifiers, "h"))
		v->u = (unsigned short int)va_arg(ap, uint);
	else if (!ft_strcmp(s->modifiers, ""))
		v->u = va_arg(ap, uint);
	convert_uint(b, v->u, s);
	return (0);
}

int			ft_printf_conversion_f(char *b, t_printf_arg *v,
			t_printf_spec *s, va_list ap)
{
	if (!ft_strcmp("", s->modifiers))
		v->f = va_arg(ap, double);
	else if (!ft_strcmp("L", s->modifiers))
		v->f = va_arg(ap, long double);
	convert_double(b, v->f, s);
	return (0);
}

int			ft_printf_conversion_c(int fd, t_printf_spec *s, va_list ap)
{
	char			b[256];

	ft_bzero(b, sizeof(b));
	b[0] = 'Q';
	apply_fw(b, *s);
	*ft_strchr(b, 'Q') = (char)va_arg(ap, int);
	ft_putstr_fd(b, fd);
	return (ft_strlen(b));
}

int			ft_printf_conversion(int fd, va_list ap, t_printf_spec s)
{
	char			b[256];
	t_printf_arg	v;

	ft_bzero(b, sizeof(b));
	if (ft_strchr("di", s.type))
		ft_printf_conversion_di(b, &v, &s, ap);
	else if (ft_strchr("uoxX", s.type))
		ft_printf_conversion_uox(b, &v, &s, ap);
	else if (s.type == 'f')
		ft_printf_conversion_f(b, &v, &s, ap);
	else if (s.type == 'c')
		return (ft_printf_conversion_c(fd, &s, ap));
	else if (s.type == 's')
		return (convert_string(fd, 0, s, va_arg(ap, char*)));
	else if (s.type == 'p')
	{
		ft_ultoa_buf(ft_strcpy(b, "0x") + 2, (ulong)va_arg(ap, void*), 16);
		s.prefix_w = 2;
	}
	else if (s.type == '%')
		ft_strcpy(b, "%");
	else
		return (0);
	return (ft_putstr_fd(apply_fw(b, s), fd));
}
