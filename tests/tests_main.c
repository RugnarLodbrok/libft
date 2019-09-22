#include <stdio.h>
#include "libft.h"
#include "ft_printf.h"

int main(void)
{
	ft_printf("hello! %c`%d`, `%s`, '!' %d\n", '@', 42, "abc", '!', 666);
//	ft_printf("hello! `%d`\n", 42);

//	ft_printf_arg arg;
//	arg.d = 42;
//	printf_handler_d(arg);
	return (0);
}
