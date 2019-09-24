#include "libft.h"

int endian()
{
	int i = 1;
	char *p;

	p = (char *) &i;
	if (p[0] == 1)
		return LITTLE_ENDIAN;
	else
		return BIG_ENDIAN;
}
