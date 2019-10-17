/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: edrowzee <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/16 13:33:20 by edrowzee          #+#    #+#             */
/*   Updated: 2019/10/16 13:48:38 by edrowzee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include "libft.h"

# define PRINTF_HASH 1
# define PRINTF_ZERO 2
# define PRINTF_MINUS 4
# define PRINTF_SPACE 8
# define PRINTF_PLUS 16

typedef	struct		s_printf_spec
{
	uint			flags;
	size_t			field_width;
	char			type;
	unsigned char	prefix_w;
	int				precision;
	char			modifiers[4];
}					t_printf_spec;

typedef union
{
	long double		f;
	long long int	d;
	ullong			u;
}					t_printf_arg;

t_printf_spec		parse_printf_spec(char **ptr);
int					ft_printf_ap(int fd,
					const char *format, va_list ap);
int					ft_printf_conversion(int fd,
					va_list ap, t_printf_spec s);
char				*convert_uint(char *b, unsigned long long int v,
					t_printf_spec *s);
char				*convert_int(char *b, long long int v,
					t_printf_spec *s);
char				*convert_double(char *b, long double v,
					t_printf_spec *s);
int					convert_string(int fd, int ret,
					t_printf_spec s, char *str);
char				*apply_fw(char *b, t_printf_spec s);

#endif
