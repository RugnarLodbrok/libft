#include <fcntl.h>
#include <time.h>
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

void test_ht_perf(double time_ref)
{
	int i;
	t_ht t;
	int fd;
	int status;
	const char *f_name = "words.txt";
	char *word;
	int count;
	clock_t t0;
	double time;

	if (access(f_name, F_OK) == -1)
		system("wget https://raw.githubusercontent.com/dwyl/english-words/master/words.txt");

	t_ht_init(&t, 10);
	fd = open(f_name, O_RDONLY);
	i = 0;
	t0 = clock();
	while ((status = get_next_line(fd, &word)) > 0)
	{
		i++;
		t_ht_set(&t, word, word);
		free(word);
	}
	if (status < 0)
	{
		ft_printf("----ERROR----\n");
		return;
	}
	close(fd);
	count = i;
	if (assert(count == t.count, "invalid count after inserts"))
		return;
	fd = open(f_name, O_RDONLY);
	i = 0;
	while ((status = get_next_line(fd, &word)) > 0)
	{
		if (assert(!ft_strcmp(t_ht_get(&t, word), word), word))
			return;

		if (i % 10000 != 0)
		{
			t_ht_remove(&t, word);
			count--;
			if (assert(t_ht_get(&t, word) == 0, word))
				return;
		}
		else
		{
			if (assert(!ft_strcmp(t_ht_get(&t, word), word), word))
				return;
		}
		free(word);
		i++;
	}
	if (status < 0)
	{
		ft_printf("----ERROR----\n");
		return;
	}
	close(fd);
	time = ((double)(clock() - t0)) / CLOCKS_PER_SEC;
	assert(t.count == count, "invalid count after removes");
	if(assert(time < 1.1 * time_ref, "slow!"))
	{
		ft_printf("time: %f\n", time);
		return;
	}
	else
		ft_printf("%s: time: %f\n", OK, time);
}

void test_ht()
{
	test_ht_perf(.8);
}
