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
	while (x > ft_sqrt(E))
	{
		x /= E;
		r += 1;
	}
	while (x < 1/ft_sqrt(E))
	{
		x *= E;
		r -= 1;
	}
	x -= 1;
	k = 1;
	num = -1;
	acc = 1;
	while (acc > EPSILON || acc < -EPSILON)
	{
		num *= -x;
		acc = num / k;
		r += acc;
		k++;
	}
	return (r);
}
