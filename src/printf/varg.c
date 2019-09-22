#include <stdio.h>
#include "libft.h"
#include "ft_printf.h"

void varg_init(t_varg *ap, void *last, size_t last_size)
{
	ap->p = last;
	ap->p += last_size;
}

ft_printf_arg varg_next(t_varg *ap, size_t size)
{
	ft_printf_arg ret;

	ft_memcpy(&ret, ap->p, size);
	ap->p += size;
	return (ret);
}
