#include "libft.h"
#include "tests.h"

int assert(int expr, const char *msg)
{
	if (!expr)
		ft_printf("%s: %s\n", FAIL, msg);
	return (!expr);
}

int main(void)
{
	test_gnl();
	test_ft_printf();
	test_ft_math();
	test_ht();
}
