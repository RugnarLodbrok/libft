#include "ft_printf.h"

static int parse_field_width(char **s)
{
	int r;

	r = 0;
	if (**s != '0' && ft_isdigit(**s))
	{
		r = (10 * r) + (**s - '0');
		(*s)++;
	}
	while (ft_isdigit(**s))
	{
		r = (10 * r) + (**s - '0');
		(*s)++;
	}
	return (r);
}

static uint parse_flags(char **s)
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

static char parse_format(char *dst, char **s)
{
	while (ft_strchr("lhL", **s))
		*dst++ = *(*s)++;
	if (ft_strchr("diouxXscpf%", **s))
	{
		*dst++ = *(*s)++;
		*dst = 0;
		return (*(*s - 1));
	}
	*dst = 0;
	return (0);
}

static int parse_precision(char **s)
{
	int r;

	r = 0;
	if (**s != '.')
		return (-1);
	else
		(*s)++;
	while (ft_isdigit(**s))
	{
		r *= 10;
		r += **s - '0';
		(*s)++;
	}
	return (r);
}

t_printf_spec parse_printf_spec(char **ptr)
{
	t_printf_spec spec;

	(*ptr)++;
	spec.prefix_w = 0;
	spec.flags = parse_flags(ptr);
	spec.field_width = parse_field_width(ptr);
	spec.precision = parse_precision(ptr);
	spec.type = parse_format(spec.format, ptr);
	return (spec);
}