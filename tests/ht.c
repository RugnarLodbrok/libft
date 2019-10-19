#include "libft.h"
#include "hash_table.h"

void t_ht_print(t_ht *t)
{
	int i;
	t_ht_item *item;
	ft_printf("Hash_table {\n");
	for (i = 0; i < t->size; ++i)
	{
		item = t->items[i];
		while (item){
			ft_printf("\t\"%s\": \"%s\"\n", item->k, item->v);
			item = item->next;
		}
	}
	ft_printf("}\n");
}

void test_ht()
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
