#include <stdarg.h>
#include "libft.h"
#include "ft_printf.h"

int	putstr_and_free(char *s, int fd)
{
	size_t len;

	ft_putstr_fd(s, fd);
	len = ft_strlen(s);
	free(s);
	return (len);
}

int ft_printf_item(int fd, va_list ap, char *f)
{
	if (!ft_strcmp("d", f) || !ft_strcmp("i", f))
		return (putstr_and_free(ft_itoa(va_arg(ap, int)), fd));
	if (!ft_strcmp("hi", f))
		return (putstr_and_free(ft_itoa((short int) va_arg(ap, int)), fd));
	if (!ft_strcmp("hhi", f))
		return (putstr_and_free(ft_itoa((signed char) va_arg(ap, int)), fd));
	if (!ft_strcmp("li", f))
		return (putstr_and_free(ft_itoa(va_arg(ap, long int)), fd));
	if (!ft_strcmp("lli", f))
		return (putstr_and_free(ft_itoa(va_arg(ap, long long int)), fd));
	if (!ft_strcmp("u", f))
		return (putstr_and_free(ft_ultoa_base(va_arg(ap, uint), 10), fd));
	if (!ft_strcmp("hu", f))
		return (putstr_and_free(ft_ultoa_base((short int) va_arg(ap, uint), 10), fd));
	if (!ft_strcmp("hhu", f))
		return (putstr_and_free(ft_ultoa_base((signed char) va_arg(ap, uint), 10), fd));
	if (!ft_strcmp("lu", f))
		return (putstr_and_free(ft_ultoa_base(va_arg(ap, ulong), 10), fd));
	if (!ft_strcmp("llu", f))
		return (putstr_and_free(ft_ultoa_base(va_arg(ap, long long int), 10), fd));
	if (!ft_strcmp("o", f))
		return (putstr_and_free(ft_ultoa_base(va_arg(ap, uint), 8), fd));
	if (!ft_strcmp("ho", f))
		return (putstr_and_free(ft_ultoa_base((short int) va_arg(ap, uint), 8), fd));
	if (!ft_strcmp("hho", f))
		return (putstr_and_free(ft_ultoa_base((signed char) va_arg(ap, uint), 8), fd));
	if (!ft_strcmp("lo", f))
		return (putstr_and_free(ft_ultoa_base(va_arg(ap, ulong), 8), fd));
	if (!ft_strcmp("llo", f))
		return (putstr_and_free(ft_ultoa_base(va_arg(ap, long long int), 8), fd));
	if (!ft_strcmp("x", f))
		return (putstr_and_free(ft_ultoa_base(va_arg(ap, uint), 16), fd));
	if (!ft_strcmp("hx", f))
		return (putstr_and_free(ft_ultoa_base((short int) va_arg(ap, uint), 16), fd));
	if (!ft_strcmp("hhx", f))
		return (putstr_and_free(ft_ultoa_base((signed char) va_arg(ap, uint), 16), fd));
	if (!ft_strcmp("lx", f))
		return (putstr_and_free(ft_ultoa_base(va_arg(ap, ulong), 16), fd));
	if (!ft_strcmp("llx", f))
		return (putstr_and_free(ft_ultoa_base(va_arg(ap, long long int), 16), fd));
	if (!ft_strcmp("X", f))
		return (putstr_and_free(ft_toupper_inplace(ft_ultoa_base(va_arg(ap, uint), 16)), fd));
	if (!ft_strcmp("hX", f))
		return (putstr_and_free(ft_toupper_inplace(ft_ultoa_base((short int) va_arg(ap, uint), 16)), fd));
	if (!ft_strcmp("hhX", f))
		return (putstr_and_free(ft_toupper_inplace(ft_ultoa_base((signed char) va_arg(ap, uint), 16)), fd));
	if (!ft_strcmp("lX", f))
		return (putstr_and_free(ft_toupper_inplace(ft_ultoa_base(va_arg(ap, ulong), 16)), fd));
	if (!ft_strcmp("llX", f))
		return (putstr_and_free(ft_toupper_inplace(ft_ultoa_base(va_arg(ap, long long int), 16)), fd));
	if (!ft_strcmp("c", f))
		return ft_putchar_fd(va_arg(ap, int), fd);
	if (!ft_strcmp("s", f))
		return ft_putstr_fd(va_arg(ap, char*), fd);
	if (!ft_strcmp("p", f))
		return (int) (ft_putstr_fd("0x", fd) * 0
					  + putstr_and_free(ft_ultoa_base((ulong) va_arg(ap, void*), 16), fd) + 2);
	if (!ft_strcmp("f", f))
		return (putstr_and_free(ft_ftoa(va_arg(ap, double), 6), fd));
	if (!ft_strcmp("Lf", f))
		return (putstr_and_free(ft_ftoa(va_arg(ap, long double), 6), fd));
	return (-1);
}
