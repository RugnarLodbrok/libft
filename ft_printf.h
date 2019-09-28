#ifndef FT_PRINTF_H
# define FT_PRINTF_H

typedef union
{
	signed char hhi;
	short int hi;
	int d;
	long int li;
	long long int lli;

	unsigned char hhu;
	unsigned short int hu;
	unsigned int u;
	unsigned long int lu;
	unsigned long long int llu;

	void *p;
	double f;
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

void printf_handler_hhi(t_printf_arg d);
void printf_handler_hi(t_printf_arg d);
void printf_handler_d(t_printf_arg d);
void printf_handler_li(t_printf_arg d);
void printf_handler_lli(t_printf_arg d);

void printf_handler_hhu(t_printf_arg v);
void printf_handler_hu(t_printf_arg v);
void printf_handler_u(t_printf_arg v);
void printf_handler_lu(t_printf_arg v);
void printf_handler_llu(t_printf_arg v);

void printf_handler_hho(t_printf_arg v);
void printf_handler_ho(t_printf_arg v);
void printf_handler_o(t_printf_arg v);
void printf_handler_lo(t_printf_arg v);
void printf_handler_llo(t_printf_arg v);

void printf_handler_hhx(t_printf_arg v);
void printf_handler_hx(t_printf_arg v);
void printf_handler_x(t_printf_arg v);
void printf_handler_lx(t_printf_arg v);
void printf_handler_llx(t_printf_arg v);

void printf_handler_hhX(t_printf_arg v);
void printf_handler_hX(t_printf_arg v);
void printf_handler_X(t_printf_arg v);
void printf_handler_lX(t_printf_arg v);
void printf_handler_llX(t_printf_arg v);

void printf_handler_s(t_printf_arg v);
void printf_handler_c(t_printf_arg v);
void printf_handler_p(t_printf_arg v);
void printf_handler_f(t_printf_arg v);

#endif
