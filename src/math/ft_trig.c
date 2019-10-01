#include "libft.h"

double ft_cos(double x)
{
	int i = 1;
	double r = x;
	double acc = 1;
	double den = 1;
	double num = x;

	while (ft_fabs(acc) > .0000000001 && i < 100)
	{
		den *= ((2 * i) * (2 * i + 1));
		num *= -1 * x * x;
		acc = num / den;
		r += acc;
		i++;
	}
	return r;
}

double ft_cos2(double x)
{
	double t, s;
	int p;
	p = 0;
	s = 1.0;
	t = 1.0;
	while (ft_fabs(t / s) > .00000000001)
	{
		p++;
		t = (-t * x * x) / ((2 * p - 1) * (2 * p));
		s += t;
	}
	return s;
}

double ft_sin(double x)
{
	int k = 2;
	double r = x;
	double acc = 1;
	double den = 1;
	double num = x;

	while (ft_fabs(acc) > .0000000001 && k < 200)
	{
		den *= k * (k + 1);
		num *= -1 * x * x;
		acc = num / den;
		r += acc;
		k += 2;
	}
	return r;
}
