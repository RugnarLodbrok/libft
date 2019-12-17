#include <math.h>
#include <stdio.h>
#include "libft.h"
#include "tests.h"

void test_real_f_x(char *f_name, REAL (*f)(REAL), double (*f_ref)(double),
				   REAL start, REAL stop, int n,
				   REAL ref_max, REAL ref_avg, double time_ref)
{
	REAL x;
	REAL step = (stop - start) / n;
	REAL v;
	REAL max_err = 0;
	REAL total_err = 0;
	char *status = OK;
	double t;

	swatch();
	for (x = start; x < stop; x += step)
	{
		v = ft_fabs(f(x) - (REAL)f_ref(x));
		if (max_err < v / EPSILON)
			max_err = v / EPSILON;
		total_err += v / EPSILON;
//		if (v > EPSILON)
//			printf("[FAIL]: f(%f) error =\t%.30f\n\t\t\t\t\t%.30f", x, v, EPSILON);
	}
	t = swatch() * 1000 * 1000 * 1000 / n;
	if (t > time_ref * 1.1)
		status = WARN;
	if (max_err > ref_max * 1.1)
		status = WARN;
	if (total_err / n > ref_avg * 1.1)
		status = WARN;
	if (t > time_ref * 2)
		status = FAIL;
	if (max_err > ref_max * 2)
		status = FAIL;
	if (total_err / n > ref_avg * 2)
		status = FAIL;
	printf("%s %s\n"
		   "\tmax_err:\t%f Epsilon (ref: %f)\n"
		   "\tavg_err:\t%f Epsilon (ref: %f)\n"
		   "\tEpsilon:\t%.30f\n"
		   "\ttime:\t\t%.2fns\t\t(ref: %f)\n", status, f_name,
		   max_err, ref_max, total_err / n, ref_avg, EPSILON, t, time_ref);
}

void test_ft_math()
{
	test_real_f_x("ft_sin", &ft_sin, &sin,
				  0, PI, 1000000,
				  0.0078, 0.00097, 62.);
	test_real_f_x("ft_cos", &ft_cos, &cos,
				  0, PI, 1000000,
				  0.0078, 0.00092, 62.);
	test_real_f_x("ft_sqrt", &ft_sqrt, &sqrt,
				  0, 10000, 1000000,
				  0.14, 0.03, 125.);
	test_real_f_x("ft_log", &ft_log, &log,
				  .000001, 77777, 666666,
				  .14, .019, 164.);
}
