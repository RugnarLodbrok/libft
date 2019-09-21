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

	printf("call varg_next, size = %zu; sizeof(arg) = %zu\n", size, sizeof(ret));
	printf("ptr: %p\n", ap->p);
	if (size == 8)
		printf("ptrs: %s\n", (char*)(ap->p));
	ft_memcpy(&ret, ap->p, size);
	ap->p += size;
	return (ret);
}
