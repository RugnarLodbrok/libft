#include <stdio.h>
#include "libft.h"
#include "ft_printf.h"
#include <math.h>

void test_gnl();
void test_printf();
void ft_printf_tests();

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
					 double start, double stop, int n)
{
	double x;
	double step = (stop - start) / n;
	double v;
	double max_err = 0;
	double total_err = 0;

	for (x = start; x < stop; x += step)
	{
		v = ft_fabs(f(x) - f_ref(x));
		if (max_err < v / EPSILON)
			max_err = v / EPSILON;
		total_err += v / EPSILON;
		if (v > EPSILON)
			printf("[FAIL]: f(%f) error =\t%.30f\n\t\t\t\t\t%.30f", x, v, EPSILON);
	}
	printf("[OK] %s\n"
		   "max_err:\t%f Epsilon (ref: 0.015543)\n"
		   "avg_err:\t%f Epsilon (ref: 0.003160)\n"
		   "Epsilon:\t%.30f\n", f_name,
		   max_err, total_err / n, EPSILON);
}

int main(void)
{
//	ft_printf_tests();
//	test_gnl();
//	performance();
	test_double_f_x("ft_sin", &ft_sin, &sin, 0, PI, 1000);
	test_double_f_x("ft_cos", &ft_cos, &cos, 0, PI, 1000);
	test_double_f_x("ft_sqrt", &ft_sqrt, &sqrt, 0, 100, 1000);
//	printf("%f\n", ft_sin2(0.434));
}
