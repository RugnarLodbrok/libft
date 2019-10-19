#include "libft.h"
#include "hash_table.h"

static int next_prime(int n)
{
	return (n);
}

void t_ht_init(t_ht *t, int base_size)
{
	t->base_size = base_size;
	t->size = next_prime(base_size);
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
	(void)t;
	(void)new_size;
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
