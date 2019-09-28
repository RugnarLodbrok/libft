#include <stdio.h>
#include <fcntl.h>
#include <stdarg.h>
#include <ft_printf.h>
#include "unistd_compat.h"

#include "libft.h"
#include "test.h"

#define BUFF_SIZE 1024

int read_to_buff(const char *fn, char *buff, size_t len)
{
	int fd;
	int n;

	if ((fd = open(fn, O_RDONLY)) < 0)
		return -1;
	if ((n = read(fd, buff, len - 1)) < 0)
		return -1;
	buff[n] = 0;
	close(fd);
	return 0;
}

int comapre_prints(char *format, ...)
{
	va_list ap;
	int fd;
	char buff1[BUFF_SIZE];
	char buff2[BUFF_SIZE];

	if ((fd = open("tmp.txt", O_WRONLY)) < 0)
	{
		printf("[ERROR]\n");
		return -1;
	}
	va_start(ap, format);
	ft_printf_ap(fd, format, ap);
	va_end(ap);
	close(fd);
	CHECK1RET1(read_to_buff("tmp.txt", buff1, BUFF_SIZE));

	if ((fd = open("tmp.txt", O_WRONLY)) < 0)
	{
		printf("[ERROR]\n");
		return -1;
	}
	va_start(ap, format);
	vdprintf(fd, format, ap);
	va_end(ap);
	close(fd);
	CHECK1RET1(read_to_buff("tmp.txt", buff2, BUFF_SIZE));
	if (ft_strcmp(buff1, buff2))
		printf("[FAIL]: \t%s\n", format);
	else
		printf("[OK]: \t\t%s\n", format);
	return (0);
}

void ft_printf_tests()
{

	system("touch tmp.txt");
	comapre_prints("abc");
	comapre_prints("abc%dqqq", 123);
	comapre_prints("abc%ffff", 32.5435434);
	comapre_prints("abc%fddd", 32.0);
	comapre_prints("abc%cfds", 'c');
}
