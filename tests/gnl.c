#include <fcntl.h>
#include <stdio.h>
#include "libft.h"

#include "get_next_line.h"

void test_gnl()
{
	int fd;
	char *s;
	int status;

/*	t_gnl_state state;
	ft_strcpy(state.chunk, "ABCD");
	printf("before: %s\n", state.chunk);
	ft_bzero(&state, sizeof(t_gnl_state));
	printf("after: %s\n", state.chunk);
	return;*/
//	fd = open("l1", O_RDONLY);
//	fd = open("nl", O_RDONLY);
//	fd = open("KO", O_RDONLY);
//	fd = open("stdarg_man.txt", O_RDONLY);
	fd = open("Makefile", O_RDONLY);
	while ((status = get_next_line(fd, &s)) > 0)
	{
		printf("%s\n", s);
		free(s);
	}
	if (status < 0)
		printf("----ERROR----\n");
	else
		printf("-----END-----\n");
}
