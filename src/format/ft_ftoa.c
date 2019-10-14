#include <stdlib.h>
#include "libft.h"

char *ft_ftoa_buf(char *s, long double n, int decimals)
{
	char *ptr;
	int base;

	base = 10;
	ptr = s;
	if (n < 0)
	{
		*ptr++ = '-';
		n *= -1;
	}
	n += 5 * ft_fpow(base, -(decimals + 1));
	ptr += ft_strlen(ft_ultoa_buf(ptr, (long int)n, base));
	if (!decimals)
		return (s);
	*ptr++ = '.';
	while (decimals--)
	{
		n *= base;
		*ptr++ = '0' + (int)((ulong)n % base);
	}
	*ptr = 0;
	return (s);
}

char *ft_ftoa(long double n, int decimals)
{
	size_t d;
	char *s;
	int base;

	base = 10;
	d = ft_count_int_digits((long int)n, base) + decimals + 1;
	if (!(s = malloc(sizeof(char) * (d + 1))))
		return (0);
	return (ft_ftoa_buf(s, n, decimals));
}
