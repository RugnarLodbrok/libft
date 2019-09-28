#include <stdio.h>
#include "libft.h"
#include "ft_printf.h"

void test_gnl();
void test_printf();
void ft_printf_tests();
int		main(void)
{
	ft_printf_tests();
	test_printf();
//	test_gnl();
	return (0);
}

void	test_printf()
{
	char *s;
//	t_printf_arg arg;

	s = "abc";
	printf("hello! %d `%s` %c`%d` `%c` %d %f\n",
		   999, s, '@', 42, '!', 666, 45543.3244231);
	ft_printf("hello! %d `%s` %c`%d` `%c` %d %f\n",
			  999, s, '@', 42, '!', 666, 45543.3244231);

//	printf("%X\n", 412345);
//	ft_printf("%X\n", 412345);
	printf("%f\n", 32.0);
	ft_printf("%f\n", 32.0);
	printf("%f\n", 5.555555555);
	ft_printf("%f\n", 5.555555555);
//	printf("%s\n", ft_itoa_base(-123456, 16));
//	printf("%lx\n", 335123123456);
//	printf("%s\n", ft_ultoa_base(335123123456, 16));
//	printf("%p\n", s);
//	ft_printf("%p\n", s);
//	printf("\n\n");
//	ft_printf("%s\n", ft_ftoa(5843.335445342321, 6));

}
