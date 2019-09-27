#include <fcntl.h>
#include <stdio.h>
#include "libft.h"

void test_gnl()
{
	int fd;
	char *s;
	int status;

	fd = open("KO", O_RDONLY);
	while ((status = get_next_line(fd, &s)) > 0)
		printf("%s\n", s);
	if (status < 0)
		printf("----ERROR----\n");
	else
		printf("-----END-----\n");
}
