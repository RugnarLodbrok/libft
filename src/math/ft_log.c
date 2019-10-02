#include "ft_math.h"

double ft_log(double x)
{
	double r;
	int k;
	double acc;
	double num;

	if (x <= 0)
		return (0);
	r = 0;
	while (x > 2 / (1 + 1 / E))
	{
		x /= E;
		r += 1;
	}
	while (x < 2 / (1 + 1 / E) / E)
	{
		x *= E;
		r -= 1;
	}
	x -= 1;
	k = 1;
	num = -1;
	acc = 1;
	while (acc > EPSILON / 100 || acc < -EPSILON / 100)
	{
		num *= -x;
		acc = num / k;
		r += acc;
		k++;
	}
	return (r);
}
