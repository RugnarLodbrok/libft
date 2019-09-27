#ifndef FT_PRINTF_H
# define FT_PRINTF_H

typedef union
{
	void *p;
	long int li;
	unsigned long int lu;
	double f;
	int d;
	char c;
	char *s;
} t_printf_arg;

typedef struct
{
	char *literal;
	void (*f)(t_printf_arg);
	char *type_name;
	size_t size;
} t_printf_handler;

void printf_handler_d(t_printf_arg d);
void printf_handler_s(t_printf_arg v);
void printf_handler_c(t_printf_arg v);
void printf_handler_p(t_printf_arg v);
void printf_handler_o(t_printf_arg v);
void printf_handler_u(t_printf_arg v);
void printf_handler_x(t_printf_arg v);
void printf_handler_X(t_printf_arg v);
void printf_handler_f(t_printf_arg v);

#endif
