#include "libft.h"

static double trig_mod(double x)
{
	while (x > PI)
		x -= PI;
	while (x < -PI)
		x += PI;
	return (x);
}

double ft_cos(double x)
{
	int k;
	double r;
	double acc;
	double den;
	double num;

	k = 1;
	r = 1;
	acc = 1;
	den = 1;
	num = 1;
	x = trig_mod(x);
	if (x > PI / 2)
		return (-ft_cos(PI - x));
	if (x < -PI / 2)
		return (-ft_cos(-PI - x));
	while (acc > EPSILON || acc < -EPSILON)
	{
		num *= -x * x;
		den *= k * (k + 1);
		acc = num / den;
		r += acc;
		k += 2;
	}
	return (r);
}

double ft_sin(double x)
{
	int k;
	double r;
	double acc;
	double den;
	double num;

	k = 2;
	r = x;
	acc = 1;
	den = 1;
	num = x;
	x = trig_mod(x);
	if (x > PI / 2)
		return (ft_sin(PI - x));
	if (x < -PI / 2)
		return (ft_sin(-PI - x));
	while (acc > EPSILON || acc < -EPSILON)
	{
		num *= -x * x;
		den *= k * (k + 1);
		acc = num / den;
		r += acc;
		k += 2;
	}
	return (r);
}

double radians(double degrees)
{
	return (degrees * PI / 180.0);
}

double zx_sin(double x)
{
	double w;
	double z;

	x = trig_mod(x);
	w = 4 * x;
	z = 2 * w * w - 1;
	return P(z) * w;
}
