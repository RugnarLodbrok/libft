#include <stdio.h>
#include "libft.h"
#include "ft_printf.h"

int main(void)
{
	char *s;

	s = "abc";
	ft_printf("hello! %d `%s` %c`%d` `%c` %d\n", 999, s, '@', 42, '!', 666);
	return (0);
}
