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
	t->hash_f_str = &hash_fnv1a;
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

void t_ht_set(t_ht *t, const char *k, const char *v)
{
	int i;
	u_uint_string hash;
	t_ht_item *item;
	t_ht_item *cur;

	item = malloc(sizeof(t_ht_item));
	item->k = ft_strdup(k);
	item->v = ft_strdup(v);
	i = 0;
	hash.s[4] = 0;
	while ((cur = t->items[(hash.u = t->hash_f_str(i++ ? (char *)hash.s : k)) % t->size]))
	{
		if (cur != &t->null_item && !ft_strcmp(cur->k, k))
		{
			t_ht_item_del(cur);
			break;
		}
	}
	t->items[hash.u % t->size] = item;
	t->count++;
	if (t->count * 100 > t->size * 70)
		t_ht_resize(t, t->size * 2);
}

static uint t_ht_get_idx(t_ht *t, const char *k)
{
	int i;
	t_ht_item *item;
	u_uint_string hash;

	i = 0;
	hash.s[4] = 0;
	while ((item = t->items[(hash.u = t->hash_f_str(i++ ? (char *)hash.s : k)) % t->size]))
		if (item != &t->null_item && !ft_strcmp(item->k, k))
			return (hash.u % t->size);
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
	t->count--;
	if (t->count * 100 / t->size < 10)
		t_ht_resize(t, (t->size + 1) / 2);
}
