#ifndef FT_PRINTF_H
# define FT_PRINTF_H

typedef union
{
	long int li;
	float f;
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

void printf_handler_d(ft_printf_arg d);
void printf_handler_s(ft_printf_arg v);
void printf_handler_c(ft_printf_arg v);

#endif
