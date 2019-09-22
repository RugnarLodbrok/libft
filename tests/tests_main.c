#include <stdio.h>
#include "libft.h"
#include "ft_printf.h"

int main(void)
{
	char *s;

	s = "abc";
//	ft_printf("hello! %d `%s` %c`%d` `%c` %d\n", 999, s, '@', 42, '!', 666);
	printf("%s\n", ft_itoa_base(-123456, 16));
	printf("%lx\n", 335123123456);
	printf("%s\n", ft_ultoa_base(335123123456, 16));
	return (0);
}
