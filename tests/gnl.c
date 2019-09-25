#include <fcntl.h>
#include <stdio.h>
#include "libft.h"

void test_gnl()
{
	int fd;
	char *s;

	fd = open("KO", O_RDONLY);
	while (get_next_line(fd, &s))
	{
		printf("%s\n", s);
	}
	printf("-----END-----\n");
}
