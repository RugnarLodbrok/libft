#include <stdio.h>
#include "libft.h"
#include "ft_printf.h"

int main(void)
{
	char *s;
	void *p;

	s = "abc";
	p = s;
	printf("str address:\t\t\t%p, size = %lu\n", p, sizeof(p));
	printf("s =         \t\t\t%p, size = %lu\n", s, sizeof(s));
	printf("%d\n", endian());
//	ft_printf("hello! `%s` %c`%d` `%c` %d\n", s, '@', 42, '!', 666);
//	ft_printf("hello! `%s` %c`%d` `%c` %d\n", s, '@', 42, '!', 666);
	ft_printf("hello! %s %d%d%d%d\n", s, 1, 2, 3, 4);
//	ft_printf("hello! `%d`\n", 42);

//	ft_printf_arg arg;
//	arg.d = 42;
//	printf_handler_d(arg);
	return (0);
}
