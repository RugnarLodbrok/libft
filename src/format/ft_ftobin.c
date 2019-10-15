#include "libft.h"

void btoa_buf(char **ptr, unsigned char c, size_t len)
{
	while (len--)
	{
		*(*ptr)++ = '0' + ((c & 0b10000000) != 0);
		c <<= 1;
	}
}

char *ft_double_to_bin_buf(char *b, double x)
{
	char *ptr;
	int i;
	unsigned char data[8];

	ptr = b;
	ft_memcpy(data, &x, 8);
	if (endian() == LITTLE_ENDIAN)
		ft_memrev((char *)data, 8);
//	else // this is not needed probably
//		for (i = 0; i < 8; ++i)
//			data[i] = ft_bitrev(data[i]);
	btoa_buf(&ptr, data[0], 1);
	*ptr++ = ' ';
	btoa_buf(&ptr, data[0] << 1, 7);
	btoa_buf(&ptr, data[1], 4);
	*ptr++ = ' ';
	btoa_buf(&ptr, data[1] << 4, 4);
	for (i = 2; i < 8; ++i)
		btoa_buf(&ptr, data[i], 8);

	return (b);
}

char *ft_double_to_bin(double x)
{
	char *s;
	CHECK0RET0(s = malloc(sizeof(char) * 67));
	ft_double_to_bin_buf(s, x);
	return (s);
}
