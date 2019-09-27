#include <stdlib.h>
#include "libft.h"

void	*ft_realloc(void *ptr, size_t n, size_t len)
{
	void *ret;

	ret = malloc(n);
	if (ret)
		ft_memcpy(ret, ptr, len);
	free(ptr);
	return (ret);
}
