#include "libft.h"
#include <time.h>

double swatch()
{
	static clock_t t0 = 0;
	clock_t t;
	double ret;

	t = clock();
	ret = (double)(t - t0) / CLOCKS_PER_SEC;
	t0 = t;
	return ret;
}

void swatch_print()
{
	ft_printf("swatch: %f\n", swatch());
}
