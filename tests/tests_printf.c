#include <stdio.h>
#include <fcntl.h>
#include <stdarg.h>
#include "ft_printf.h"
#include "unistd_compat.h"

#include "libft.h"

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
	int ret1;
	int ret2;

	if ((fd = open("tmp.txt", O_CREAT | O_WRONLY | O_TRUNC)) < 0)
	{
		printf("[ERROR]\n");
		return -1;
	}
	va_start(ap, format);
	ret1 = ft_printf_ap(fd, format, ap);
	va_end(ap);
	close(fd);
	CHECK1RET1(read_to_buff("tmp.txt", buff1, BUFF_SIZE));

	if ((fd = open("tmp.txt", O_CREAT | O_WRONLY | O_TRUNC)) < 0)
	{
		printf("[ERROR]\n");
		return -1;
	}
	va_start(ap, format);
	ret2 = vdprintf(fd, format, ap);
	va_end(ap);
	close(fd);
	CHECK1RET1(read_to_buff("tmp.txt", buff2, BUFF_SIZE));
	if (ft_strcmp(buff1, buff2))
	{
		printf("[FAIL]:\t%s\n", format);
		if (!ft_strchr(buff1, '\n') && !ft_strchr(buff2, '\n'))
			printf("\tgot:\t\t`%s`\n\texpected:\t`%s`\n", buff1, buff2);
	} else if (ret1 != ret2)
		printf("[FAIL]:\t%s\treturn expected %d got %d\n", format, ret2, ret1);
	else
		printf("[OK]:\t\t%s -> %s\n", format, buff1);
	return (0);
}

void ft_printf_tests()
{
	comapre_prints("abc");
	comapre_prints("abc%dqqq", 123);
	comapre_prints("123%%abc", 123);
	comapre_prints("abc%ffff", 32.5435434);
	comapre_prints("%f", 0.999999999);
	comapre_prints("%f", -9.99999999);
	comapre_prints("%f", 55.555555555);
	comapre_prints("%f", -55.555555555);
	comapre_prints("%f", (float) 55.555555555);
	comapre_prints("%f", (float) -55.555555555);
	comapre_prints("%Lf", (long double) 55.555555555);
	comapre_prints("%Lf", (long double) -55.555555555);
	comapre_prints("abc%fddd", 32.0);
	comapre_prints("abc%cfds", 'c');
	comapre_prints("%li", (long int) -123456789 * 100);
	comapre_prints("%lu", (long int) -123456789 * 100);
	comapre_prints("%lu", (ulong) 123456789 * 100);
	comapre_prints("%llu", (ulong) 123456789 * 100);
	comapre_prints("%hu", (ulong) 123456789 * 100);
	comapre_prints("%hhu", (ulong) 123456789 * 100);
	comapre_prints("%o", 0);
	comapre_prints("%lo", 0);
	comapre_prints("%lo", (ulong) 123456789 * 100);
	comapre_prints("%#lo", (ulong) 123456789 * 100);
	comapre_prints("%#lo", (ulong) 0);
	comapre_prints("%lx", (ulong) 123456789 * 100);
	comapre_prints("%lX", (ulong) 123456789 * 100);
	comapre_prints("%#lx", (ulong) 123456789 * 100);
	comapre_prints("%#lX", (ulong) 123456789 * 100);
//TODO: test for %#f
	comapre_prints("%p", &comapre_prints);
	comapre_prints("%d %f %p `%s` %c %lX %llx %Lf %f",
			123, (double)4, &comapre_prints, "", '~',
			(ulong)432543, (unsigned long long int)54935734,
			(long double)945.1232387665, (double)0.9999999);
}
