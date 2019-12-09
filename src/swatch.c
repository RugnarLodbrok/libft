#include <time.h>
#include "libft.h"

double swatch_clock(clock_t *t0)
{
	clock_t t;
	double ret;

	t = clock();
	ret = (double)(t - *t0) / CLOCKS_PER_SEC;
	*t0 = t;
	return ret;
}

double swatch()
{
	static clock_t t0 = 0;

	return swatch_clock(&t0);
}

void swatch_print()
{
	ft_printf("swatch: %f\n", swatch());
}
