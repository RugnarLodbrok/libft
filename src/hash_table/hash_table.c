#include "libft.h"
#include "hash_table.h"

static inline int next_prime(int n)
{
//	ft_printf("get next prime\n");
//	while (1)
//	{
//		if (n / 2 * 2 != n)
//			if (n / 3 * 3 != n)
//				if (n / 5 * 5 != n)
//					if (n / 7 * 7 != n)
//						if (n / 11 * 11 != n)
//							break;
//		n++;
//		ft_printf("inc!\n");
//	}
//	const int m = 32;
//	n = (((n - 1) / m + 1) * m);
//	n+=1;
//	ft_printf("n: %d\n", n);
	return (n);
}

void t_ht_init(t_ht *t, int size)
{
	t->size = (size < HT_MIN_SIZE) ? HT_MIN_SIZE : size;
	t->size = t->size;
	t->count = 0;
	t->items = malloc(sizeof(t_ht_item *) * t->size);
	ft_bzero(t->items, sizeof(t_ht_item *) * t->size);
	t->hash_f_str = &hash_fnv1a;
}

static void t_ht_item_del(t_ht_item *ti)
{
	free(ti->k);
	free(ti->v);
	free(ti);
}

void t_ht_del(t_ht *t)
{
	t_ht_item *item;
	t_ht_item *next;
	int i;

	for (i = 0; i < t->size; ++i)
	{
		item = t->items[i];
		while (item)
		{
			next = item->next;
			t_ht_item_del(item);
			item = next;
		}
	}
}

static void t_ht_resize(t_ht *t, int new_size)
{
	t_ht t2;
	int i;
	t_ht_item *item;

	if (new_size < HT_MIN_SIZE)
		return;
	t_ht_init(&t2, new_size);
	i = 0;
	while (i < t->size)
	{
		item = t->items[i];
		while (item)
		{
			t_ht_set(&t2, item->k, item->v);
			t_ht_item_del(item);
			item = item->next;
		}
		i++;
	}
	free(t->items);
	t->items = t2.items;
	t->size = t2.size;
}

void t_ht_set(t_ht *t, const char *k, const char *v)
{
	t_ht_item *item;
	t_ht_item **ptr;

	ptr = &t->items[t->hash_f_str(k) % t->size];
	while (*ptr)
	{
		if (!ft_strcmp((*ptr)->k, k))
			break;
		ptr = &(*ptr)->next;
	}
	item = malloc(sizeof(t_ht_item));
	item->k = ft_strdup(k);
	item->v = ft_strdup(v);
	item->next = 0;
	if (*ptr)
	{
		item->next = (*ptr)->next;
		t_ht_item_del(*ptr);
	}
	*ptr = item;
	t->count++;
	if (t->count * 100 > t->size * 70)
		t_ht_resize(t, t->size * 2);
}

char *t_ht_get(t_ht *t, const char *k)
{
	uint hash;
	t_ht_item *item;

	hash = t->hash_f_str(k);
	item = t->items[hash % t->size];
	while (item)
	{
		if (!ft_strcmp(item->k, k))
			break;
		item = item->next;
	}
	if (item)
		return (item->v);
	return (0);
}

void t_ht_remove(t_ht *t, const char *k)
{
	t_ht_item *item;
	t_ht_item **ptr;

	ptr = &t->items[t->hash_f_str(k) % t->size];
	while (*ptr)
	{
		if (!ft_strcmp((*ptr)->k, k))
			break;
		ptr = &(*ptr)->next;
	}
	item = *ptr;
	if (!item)
		return;
	*ptr = item->next;
	t_ht_item_del(item);
	t->count--;
	if (t->count * 100 / t->size < 10)
		t_ht_resize(t, (t->size + 1) / 2);
}
