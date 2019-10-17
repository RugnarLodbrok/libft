/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edrowzee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 12:21:57 by edrowzee          #+#    #+#             */
/*   Updated: 2019/10/16 13:44:56 by edrowzee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include "libft.h"
#include "ft_printf.h"
#include "unistd_compat.h"

static int	ft_printf_conversion_di(char *b, t_printf_arg *v,
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

static int	ft_printf_conversion_uox(char *b, t_printf_arg *v,
			t_printf_spec *s, va_list ap)
{
	if (!ft_strcmp(s->modifiers, "ll"))
		v->u = va_arg(ap, ullong);
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

static int	ft_printf_conversion_f(char *b, t_printf_arg *v,
			t_printf_spec *s, va_list ap)
{
	if (!ft_strcmp("", s->modifiers))
		v->f = va_arg(ap, double);
	else if (!ft_strcmp("L", s->modifiers))
		v->f = va_arg(ap, long double);
	convert_double(b, v->f, s);
	return (0);
}

static int	ft_printf_conversion_c(int fd, t_printf_spec *s, va_list ap)
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
