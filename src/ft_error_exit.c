#include "libft.h"
#include "ft_printf.h"
#include <stdarg.h>

void ft_error_exit(const char *msg, ...)
{
	va_list ap;

	va_start(ap, msg);
	ft_printf_ap(2, msg, ap);
	ft_fprintf(2, "\n");
	va_end(ap);
	exit(1);
}
