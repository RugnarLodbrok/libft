#ifndef FT_PRINTF_H
# define FT_PRINTF_H

typedef struct
{
	char *p;
} t_varg;

typedef union
{
	int d;
	char c;
	char *s;
} ft_printf_arg;

typedef struct
{
	char *literal;
	void (*f)(ft_printf_arg);
	char *type_name;
	size_t size;
} t_printf_handler;

typedef struct
{
	void *data;
	void *iter_ptr;
	size_t len;
} ft_printf_args;

void printf_handler_d(ft_printf_arg d);
void printf_handler_s(ft_printf_arg v);
void printf_handler_c(ft_printf_arg v);

void varg_init(t_varg *ap, void *last, size_t last_size);
ft_printf_arg varg_next(t_varg *ap, size_t size);

void ft_printf_args_init(ft_printf_args *a, va_list ap, size_t va_len);
ft_printf_arg ft_printf_args_next(ft_printf_args *a, size_t size);

#endif
