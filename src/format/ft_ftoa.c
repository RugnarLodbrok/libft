#include <stdlib.h>
#include "libft.h"

static void trail_zeros(char *s, int n)
{
	if (n <= 0)
		return;
	while (*s++)
		if(!--n)
			return;
	s--;
	while (n--)
		*s++ = '0';
	*s = 0;
}

char *ft_ftoa_buf(char *s, long double n, int decimals)
{
	char *ptr;
	int base;
	long int decimal_part;

	base = 10;
	ptr = s;
	if (n < 0)
	{
		*ptr++ = '-';
		n *= -1;
	}
	decimal_part = (long int) ((n - (double) (long int) n) \
			* ft_pow(base, decimals + 1));
	decimal_part = (ABS(decimal_part) + 5) / 10;
	if (decimal_part < ft_pow(base, decimals))
		ptr += ft_strlen(ft_ultoa_buf(ptr, (long int) n, 10));
	else if (n > 0)
		ptr += ft_strlen(ft_ultoa_buf(ptr, ((long int) n) + 1, 10));
	else
		ptr += ft_strlen(ft_ultoa_buf(s, ((long int) n) - 1, 10));
	decimal_part %= ft_pow(base, decimals);
	if (!decimals)
		return (s);
	ptr[0] = '.';
	ft_ultoa_buf(ptr + 1, decimal_part, 10);
	trail_zeros(ptr + 1, decimals);
	return (s);
}

char *ft_ftoa(long double n, int decimals)
{
	size_t d;
	char *s;
	int base;

	base = 10;
	d = ft_count_int_digits((long int) n, base) + decimals + 1;
	if (!(s = malloc(sizeof(char) * (d + 1))))
		return (0);
	return (ft_ftoa_buf(s, n, decimals));
}
