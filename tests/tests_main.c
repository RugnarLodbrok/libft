#include <stdio.h>
#include "libft.h"
#include "ft_printf.h"

int main(void)
{
	char *s;
	t_printf_arg arg;

	s = "abc";
	printf("hello! %d `%s` %c`%d` `%c` %d %f\n",
		   999, s, '@', 42, '!', 666, 45543.3244231);
	ft_printf("hello! %d `%s` %c`%d` `%c` %d %f\n",
			  999, s, '@', 42, '!', 666, 45543.3244231);
//	printf("%s\n", ft_itoa_base(-123456, 16));
//	printf("%lx\n", 335123123456);
//	printf("%s\n", ft_ultoa_base(335123123456, 16));
//	printf("%p\n", s);
//	ft_printf("%p\n", s);
//	printf("\n\n");
//	ft_printf("%s\n", ft_ftoa(5843.335445342321, 6));
	return (0);
}
