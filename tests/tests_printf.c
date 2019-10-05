#include <stdio.h>
#include <fcntl.h>
#include <stdarg.h>
#include "ft_printf.h"
#include "unistd_compat.h"
#include "tests.h"
#include "libft.h"

#define BUFF_SIZE 1024

static int read_to_buff(const char *fn, char *buff, size_t len)
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

static int compare_prints(char *format, ...)
{
	va_list ap;
	int fd;
	char buff1[BUFF_SIZE];
	char buff2[BUFF_SIZE];
	int ret1;
	int ret2;

	if ((fd = open("tmp.txt", O_CREAT | O_WRONLY | O_TRUNC)) < 0)
	{
		printf("%s\n", ERROR);
		return -1;
	}
	va_start(ap, format);
	ret1 = ft_printf_ap(fd, format, ap);
	va_end(ap);
	close(fd);
	CHECK1RET1(read_to_buff("tmp.txt", buff1, BUFF_SIZE));

	if ((fd = open("tmp.txt", O_CREAT | O_WRONLY | O_TRUNC)) < 0)
	{
		printf("%s\n", ERROR);
		return -1;
	}
	va_start(ap, format);
	ret2 = vdprintf(fd, format, ap);
	va_end(ap);
	close(fd);
	CHECK1RET1(read_to_buff("tmp.txt", buff2, BUFF_SIZE));
	if (ft_strcmp(buff1, buff2))
	{
		printf("%s:\t%s\n", FAIL, format);
		if (!ft_strchr(buff1, '\n') && !ft_strchr(buff2, '\n'))
			printf("\tgot:\t\t`%s`\n\texpected:\t`%s`\n", buff1, buff2);
	}
	else if (ret1 != ret2)
		printf("%s:\t%s\treturn expected %d got %d\n", FAIL, format, ret2, ret1);
	else
		printf("%s:\t\t%s -> `%s`\n", OK, format, buff1);
	return (0);
}

void test_ft_printf()
{
	compare_prints("abc");
	compare_prints("%#+3lc", '!');
	compare_prints("%3lc", '!');
	compare_prints("abc%dqqq", 123);
	compare_prints("123%%abc", 123);
	compare_prints("abc%ffff", 32.5435434);
	compare_prints("%f", 0.999999999);
	compare_prints("%f", -9.99999999);
	compare_prints("%f", 55.555555555);
	compare_prints("%f", -55.555555555);
	compare_prints("%f", (float) 55.555555555);
	compare_prints("%f", (float) -55.555555555);
	compare_prints("%Lf", (long double) 55.555555555);
	compare_prints("%Lf", (long double) -55.555555555);
	compare_prints("abc%fddd", 32.0);
	compare_prints("abc%cfds", '!');
	compare_prints("%li", (long int) -123456789 * 100);
	compare_prints("%lu", (long int) -123456789 * 100);
	compare_prints("%lu", (ulong) 123456789 * 100);
	compare_prints("%llu", (ulong) 123456789 * 100);
	compare_prints("%hu", (ulong) 123456789 * 100);
	compare_prints("%hhu", (ulong) 123456789 * 100);
	compare_prints("%o", 0);
	compare_prints("%lo", 0);
	compare_prints("%lo", (ulong) 123456789 * 100);
	compare_prints("%#lo", (ulong) 123456789 * 100);
	compare_prints("%#lo", (ulong) 0);
	compare_prints("%lx", (ulong) 123456789 * 100);
	compare_prints("%lX", (ulong) 123456789 * 100);
	compare_prints("%#lx", (ulong) 123456789 * 100);
	compare_prints("%#lX", (ulong) 123456789 * 100);
//TODO: test for %#f
	compare_prints("%p", &compare_prints);
	compare_prints("%10d", 123);
	compare_prints("%010d", 123);
	compare_prints("%010d", -123);
	compare_prints("%+010d", 123);
	compare_prints("%+010u", 123);
	compare_prints("% 010u", 123);
	compare_prints("%010s", "-10");
	compare_prints("%020p", &compare_prints);
	compare_prints("%#020x", &compare_prints);
	compare_prints("%020x", &compare_prints);
	compare_prints("%+10d", 123);
	compare_prints("%+d", 123);
	compare_prints("% d", 123);
	compare_prints("%-10d", 123);
	compare_prints("%3d", 12345);
	compare_prints("%3c", '!');
	compare_prints("%010d", -123);
	compare_prints("%10d", -123);

	compare_prints("%-#7.4o", 169);
	compare_prints("%.6d", 168);
	compare_prints("%.06d", 168);
	compare_prints("%10.06d", 168);
	compare_prints("%10.6d", 168);
	compare_prints("%#10.6x", 168);
	compare_prints("%#.5o", 123);
	compare_prints("%#10.6x", 123123);
	compare_prints("%.0d", 168);
	compare_prints("%-#7f", -1.3432356542323);
	compare_prints("%-#7.0f", -123.3432356542323);
	compare_prints("%-7.0f", -123.3432356542323);
	compare_prints("%5.0f", -123.3432356542323);
	compare_prints("%.0f", -123.3432356542323);
	compare_prints("%#5.0f", -123.3432356542323);
	compare_prints("%#.0f", -123.3432356542323);
	compare_prints("%.1f", -1.3432356542323);
	compare_prints("%-#7.4f", -1.3432356542323);
	compare_prints("%-#7.4f", -1.3);
	// edrowzee
	compare_prints("|%d|  ", 5);
	compare_prints("|%d|", -5);
	compare_prints("|%+d|", 5);
	compare_prints("|%+d|", -5);
	compare_prints("|% d|", 5);
	compare_prints("|% d|", -5);
	compare_prints("|%5d|", 5);
	compare_prints("|%5d|", -5);
	compare_prints("|%05d|", 5);
	compare_prints("|%05d|", -5);
	compare_prints("|%0 5d|", 5);
	compare_prints("|%0 5d|", -5);
	compare_prints("|%0 +5d|", 5);
	compare_prints("|%0 +5d|", -5);
	compare_prints("|%-5d|", 5);
	compare_prints("|%-5d|", -5);
	compare_prints("|%-05d|", 5);
	compare_prints("|%-05d|", -5);
	compare_prints("|%- +05d|", 5);
	compare_prints("|%- +05d|", -5);
	compare_prints("|%-+5d|", 5);
	compare_prints("|%-+5d|", -5);
	compare_prints("|% 5d|", 0);
	compare_prints("|% 5d|", -0);
	compare_prints("|% 05d|", 0);
	compare_prints("|% 05d|", -0);
	compare_prints("|% 5d|", 5);
	compare_prints("|% 5d|", -5);
	compare_prints("|% +5d|", 5);
	compare_prints("|% +5d|", -5);

	compare_prints("|%#08x|", 168);
	compare_prints("|%#8x|", 168);
	compare_prints("|%#08.10x|", 168);
	compare_prints("|%#8.6x|", 168);
	compare_prints("|%#4.6x|", 168);
	compare_prints("|%-#8.6x|", 168);
	compare_prints("|%-#4.6x|", 168);

	compare_prints("|%#7.4o|", 168);
	compare_prints("|%-#7.4o|", 168);
	compare_prints("|%#7.4x|", 168);
	compare_prints("|%-#7.4x|", 168);
	// edrowzee end
	compare_prints("%d %f %p `%s` %c %lX %llx %Lf %f",
				   123, (double) 4, &compare_prints, "", '~',
				   (ulong) 432543, (unsigned long long int) 54935734,
				   (long double) -945.1232387665, (double) 0.99999999);
	printf("\n----OS dependant and undefined behavoiur tests----\n\n");
	compare_prints("%5+c", '!'); // edrowzee
	compare_prints("|%5+d|", 5); // edrowzee
	compare_prints("%03lc", '!');
	compare_prints("undefined %l#X behaviour", (ulong) 123456789 * 100); //not copying undefined behaviour
	compare_prints("%yX", (ulong) 123456789 * 100);
}
