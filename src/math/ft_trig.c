#include "libft.h"
#include <stdio.h>

double ft_cos(double x)
{
	int k = 1;
	double r = 1;
	double acc = 1;
	double den = 1;
	double num = 1;

	while (x > PI)
		x -= PI;
	while (x < -PI)
		x += PI;
	while (acc > EPSILON || acc < -EPSILON)
	{
		num *= -1 * x * x;
		den /= k * (k + 1);
		acc = num * den;
		r += acc;
		k += 2;
	}
	return r;
}

double ft_sin(double x)
{
	int k = 2;
	double r = x;
	double acc = 1;
	double den = 1;
	double num = x;

	while (x > PI)
		x -= PI;
	while (x < -PI)
		x += PI;
	while (acc > EPSILON || acc < -EPSILON)
	{
		num *= -1 * x * x;
		den /= k * (k + 1);
		acc = num * den;
		r += acc;
		k += 2;
	}
	return r;
}
