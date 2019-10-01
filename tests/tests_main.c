#include <stdio.h>
#include "libft.h"
#include "ft_printf.h"

void test_gnl();
void test_printf();
void ft_printf_tests();

int main(void)
{
	double x;
	ft_printf_tests();
	test_printf();
//	test_gnl();
	for (x = 0; x < 6.; x += 0.1)
		printf("cos(%f) = %f, cos2(%f) = %f\n", x, ft_cos(x), x, ft_cos2(x));
	return (0);
}

void test_printf()
{

}
