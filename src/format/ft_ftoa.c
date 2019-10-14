#include <stdlib.h>
#include <limits.h>
#include "libft.h"

static unsigned long long mod(long double a, int b)
{
	unsigned long long c;

	c = (ULONG_LONG_MAX / b) * b;
	a -= ((unsigned long long int)(a / c)) * c;
	return (((unsigned long long)a) % b);
}

char *ft_ftoa_buf(char *s, long double n, int decimals)
{
	char *ptr;
	int base;
	long double m;

	base = 10;
	ptr = s;
	if (n < 0)
	{
		*ptr++ = '-';
		n *= -1;
	}
	n += 5 * ft_fpow(base, -(decimals + 1));
	m = n;
	while (m >= 1.)
	{
		*ptr++ = '0' + (int)mod(m, base);
		m /= base;
	}
	*ptr = 0;
	ft_strrev(*s == '-' ? s + 1 : s);
	if (!decimals)
		return (s);
	*ptr++ = '.';
	while (decimals--)
	{
		n *= base;
		*ptr++ = '0' + (int)(mod(n, base));
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
