#include <math.h>
#include <stdio.h>
#include "ft_math.h"

/*void performance()
{
	int i;
	double x;
	int n = ft_pow(10, 7);
//	int n = 100;
	double sup = 3;
	double step = sup / n;
	double y;

	for (x = 0; x < sup; x += step)
	{
//		printf("%f, %f\n", x, ft_cos(x) - cos(x));
		y = ft_sqrt(x);
//		y = sqrt(x);
//		y = cos(x);
	}
}
*/
void test_double_f_x(char *f_name, double (*f)(double), double (*f_ref)(double),
					 double start, double stop, int n,
					 double ref_max, double ref_avg)
{
	double x;
	double step = (stop - start) / n;
	double v;
	double max_err = 0;
	double total_err = 0;
	char *status = "OK";

	for (x = start; x < stop; x += step)
	{
		v = ft_fabs(f(x) - f_ref(x));
		if (max_err < v / EPSILON)
			max_err = v / EPSILON;
		total_err += v / EPSILON;
//		if (v > EPSILON)
//			printf("[FAIL]: f(%f) error =\t%.30f\n\t\t\t\t\t%.30f", x, v, EPSILON);
	}
	if (max_err > ref_max * 1.1)
		status = "WARNING";
	if (max_err > ref_max * 2)
		status = "FAIL";
	if (total_err / n > ref_avg * 1.1)
		status = "WARNING";
	if (total_err / n > ref_avg * 2)
		status = "FAIL";
	printf("[%s] %s\n"
		   "\tmax_err:\t%f Epsilon (ref: %f)\n"
		   "\tavg_err:\t%f Epsilon (ref: %f)\n"
		   "\tEpsilon:\t%.30f\n", status, f_name,
		   max_err, ref_max, total_err / n, ref_avg, EPSILON);
}

void test_ft_math()
{
	test_double_f_x("ft_sin", &ft_sin, &sin, 0, PI, 1000, 0.0056, 0.00097);
	test_double_f_x("ft_cos", &ft_cos, &cos, 0, PI, 1000, 0.0061, 0.00092);
	test_double_f_x("ft_sqrt", &ft_sqrt, &sqrt, 0, 100, 1000, 0.018, 0.03);
	test_double_f_x("ft_log", &ft_log, &log, .000001, 997, 1000, .55, .19);
}
