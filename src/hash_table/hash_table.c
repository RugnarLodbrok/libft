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
	t->null_item = (t_ht_item){0, 0};
}

static void t_ht_item_del(t_ht_item *ti)
{
	free(ti->k);
	free(ti->v);
	free(ti);
}

static void t_ht_del_item(t_ht *t, int idx)
{
	t_ht_item **item;

	item = &t->items[idx];
	t_ht_item_del(*item);
	*item = &t->null_item;
}

void t_ht_del(t_ht *t)
{
	t_ht_item *item;
	int i;

	for (i = 0; i < t->size; ++i)
	{
		item = t->items[i];
		if (item && item != &t->null_item)
			t_ht_del_item(t, i);
	}
}

static void t_ht_resize(t_ht *t, int new_size)
{
	(void)t;
	(void)new_size;
}

static int t_ht_hash(t_ht *t, const char *s, int i)
{
	(void)t;
	(void)s;
	return (i);
}

void t_ht_set(t_ht *t, const char *k, const char *v)
{
	int i;
	int hash;
	t_ht_item *item;
	t_ht_item *cur;

	item = malloc(sizeof(t_ht_item));
	item->k = ft_strdup(k);
	item->v = ft_strdup(v);
	i = 0;
	while ((cur = t->items[(hash = t_ht_hash(t, item->k, i++))]))
		if (cur != &t->null_item && !ft_strcmp(cur->k, k))
		{
			t_ht_item_del(cur);
			break;
		}
	t->items[hash] = item;
	t->count++;
	if (t->count * 100 > t->size * 70)
		t_ht_resize(t, t->size * 2);
}

static int t_ht_get_idx(t_ht *t, const char *k)
{
	int i;
	t_ht_item *item;
	int hash;

	i = 0;
	while ((item = t->items[hash = t_ht_hash(t, k, i++)]))
		if (item != &t->null_item && !ft_strcmp(item->k, k))
			return (hash);
	return -1;
}

char *t_ht_get(t_ht *t, const char *k)
{
	int idx;

	if ((idx = t_ht_get_idx(t, k)) >= 0)
		return t->items[idx]->v;
	return 0;
}

void t_ht_remove(t_ht *t, const char *k)
{
	int idx;

	if ((idx = t_ht_get_idx(t, k)) < 0)
		return;
	t_ht_del_item(t, idx);
	t->size--;
	if (t->count * 100 / t->size < 10)
		t_ht_resize(t, (t->size + 1) / 2);
}
