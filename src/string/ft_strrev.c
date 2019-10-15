#include "libft.h"

char *ft_strrev(char *str)
{
	int len;
	int i;

	len = ft_strlen(str);
	i = 0;
	while (i < len / 2)
	{
		ft_swap_char(str + i, str + len - i - 1);
		i++;
	}
	return (str);
}

char *ft_memrev(char *str, size_t len)
{
	int i;

	i = 0;
	while (i < (int)len / 2)
	{
		ft_swap_char(str + i, str + len - i - 1);
		i++;
	}
	return (str);
}

unsigned char ft_bitrev(unsigned char b)
{
	int i;
	unsigned char r;

	i = 8;
	r = 0;
	while (i--)
	{
		r <<= 1;
		r |= b & 1;
		b >>= 1;
	}
	return (r);
}
