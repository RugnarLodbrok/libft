
#include <stdlib.h>

static uint	count_digits(ulong n, uint base)
{
	unsigned int i;

	if (n == 0)
		return (1);
	i = 0;
	while (n)
	{
		n /= base;
		i++;
	}
	return (i);
}

void		ft_ultoa_stack(char *s, ulong n, uint base)
{
	unsigned  int	d;
	char			c;
	int				rem;

	d = count_digits(n, base);
	s[d] = 0;
	if (n == 0)
		s[0] = '0';
	while (n)
	{
		rem = (int ) (n % base);
		if (rem > 9)
			c = 'a' + rem - 10;
		else
			c = '0' + rem;
		s[d-- - 1] = c;
		n /= base;
	}
}

char		*ft_ultoa(ulong n)
{
	unsigned int	d;
	char			*s;

	d = count_digits(n, 10);
	if (!(s = malloc(sizeof(char) * (d + 1))))
		return (0);
	ft_ultoa_stack(s, n, 10);
	return (s);
}

char		*ft_ultoa_base(ulong n, uint base)
{
	unsigned int	d;
	char			*s;

	if (base < 2 || base > 32)
		return (0);
	d = count_digits(n, base);
	if (!(s = malloc(sizeof(char) * (d + 1))))
		return (0);
	ft_ultoa_stack(s, n, base);
	return (s);
}
