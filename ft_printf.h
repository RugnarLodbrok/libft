#ifndef FT_PRINTF_H
# define FT_PRINTF_H

#include <stdarg.h>

int ft_printf_ap(int fd, const char *format, va_list ap);
int ft_printf_item(int fd, va_list ap, char *f);

#endif
