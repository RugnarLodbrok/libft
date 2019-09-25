#include <stdlib.h>
#include <float.h>
#include "libft.h"

char *ft_ftoa(double n, int decimals)
{
	size_t d;
	char *s;
	char *ptr;
	int base;
	long int decimal_part;

	base = 10;
	decimal_part = (long int) ((n - (double) (long int) n) \
			* ft_pow(base, decimals));
	d = ft_count_int_digits((long int) n, base) + decimals + 1;
	if (!(s = malloc(sizeof(char) * (d + 1))))
		return (0);
	ptr = s + ft_itoa_stack(s, (long int) n, 10);
	ptr[0] = '.';
	ft_itoa_stack(ptr + 1,
				  decimal_part,
				  10);
	return (s);
}
