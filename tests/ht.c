#include <fcntl.h>
#include "libft.h"
#include "get_next_line.h"
#include "hash_table.h"
#include "tests.h"
void t_ht_print(t_ht *t)
{
	int i;
	t_ht_item *item;
	ft_printf("Hash_table {\n");
	for (i = 0; i < t->size; ++i)
	{
		item = t->items[i];
		while (item)
		{
			ft_printf("\t\"%s\": \"%s\"\n", item->k, item->v);
			item = item->next;
		}
	}
	ft_printf("}\n");
}

void test_ht_basic()
{
	t_ht t;

	t_ht_init(&t, 10);
	t_ht_set(&t, "a", "b");
	t_ht_set(&t, "c", "d");
	t_ht_set(&t, "x", "y");
	t_ht_set(&t, "123", "456");
	t_ht_remove(&t, "x");
	t_ht_print(&t);
	ft_printf("t[\"123\"] = %s\n", t_ht_get(&t, "123"));
	ft_printf("t[\"1234\"] = %s\n", t_ht_get(&t, "1234"));
	t_ht_del(&t);
}

void test_ht_perf()
{
	int i;
	t_ht t;
	int fd;
	int status;
	const char *f_name = "words.txt";
	char *s;

	if (access(f_name, F_OK) == -1)
		system("wget https://raw.githubusercontent.com/dwyl/english-words/master/words.txt");

	fd = open(f_name, O_RDONLY);
	i = 0;
	t_ht_init(&t, 10);
	while ((status = get_next_line(fd, &s)) > 0)
	{
		if (!(i % 10000))
			ft_printf("%d words; size: %d\n", i, t.size);
		if (i > 50000)
			break;
		t_ht_set(&t, s, s);
		free(s);
		i++;
	}
	ft_printf("%s\n", t_ht_get(&t, "abaisse"));
	ft_printf("%s\n", t_ht_get(&t, "dsadw"));
	if (status < 0)
		ft_printf("----ERROR----\n");
}

void test_ht()
{
	test_ht_basic();
	test_ht_perf();
}
