#include <stdlib.h>
#include "libft.h"

static void trail_zeros(char *s, int n)
{
	while (*s++)
		if(!--n)
			return;
	s--;
	while (n--)
		*s++ = '0';
	*s = 0;
}

char *ft_ftoa(long double n, int decimals)
{
	size_t d;
	char *s;
	char *ptr;
	int base;
	long int decimal_part;

	base = 10;
	decimal_part = (long int) ((n - (double) (long int) n) \
			* ft_pow(base, decimals + 1));
	decimal_part = (ABS(decimal_part) + 5) / 10;
	d = ft_count_int_digits((long int) n, base) + decimals + 1;
	if (!(s = malloc(sizeof(char) * (d + 1))))
		return (0);
	if (decimal_part < ft_pow(base, decimals))
		ptr = s + ft_strlen(ft_itoa_stack(s, (long int) n, 10));
	else if (n > 0)
		ptr = s + ft_strlen(ft_itoa_stack(s, ((long int) n) + 1, 10));
	else
		ptr = s + ft_strlen(ft_itoa_stack(s, ((long int) n) - 1, 10));
	decimal_part %= ft_pow(base, decimals);
	ptr[0] = '.';
	ft_itoa_stack(ptr + 1, decimal_part, 10);
	trail_zeros(ptr + 1, decimals);
	return (s);
}
