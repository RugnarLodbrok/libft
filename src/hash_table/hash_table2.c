/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash_table2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksticks <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 18:35:12 by ksticks           #+#    #+#             */
/*   Updated: 2019/11/15 18:35:13 by ksticks          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "hash_table.h"

static void	t_ht_item_del(t_ht_item *ti)
{
	free(ti->k);
	free(ti->v);
	free(ti);
}

static void	t_ht_resize(t_ht *t, int new_size)
{
	t_ht		t2;
	int			i;
	t_ht_item	*item;
	t_ht_item	*tmp;

	if (new_size < HT_MIN_SIZE)
		return ;
	t_ht_init(&t2, new_size);
	i = 0;
	while (i < t->size)
	{
		item = t->items[i];
		while (item)
		{
			t_ht_set(&t2, item->k, item->v);
			tmp = item->next;
			t_ht_item_del(item);
			item = tmp;
		}
		i++;
	}
	free(t->items);
	t->items = t2.items;
	t->size = t2.size;
}

void		t_ht_set(t_ht *t, const char *k, const char *v)
{
	t_ht_item *item;
	t_ht_item **ptr;

	ptr = &t->items[t->hash_f_str(k) % t->size];
	while (*ptr)
	{
		if (!ft_strcmp((*ptr)->k, k))
			break ;
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
	if (t->count * 10 > t->size * 7)
		t_ht_resize(t, t->size * 2);
}

void		t_ht_remove(t_ht *t, const char *k)
{
	t_ht_item *item;
	t_ht_item **ptr;

	ptr = &t->items[t->hash_f_str(k) % t->size];
	while (*ptr)
	{
		if (!ft_strcmp((*ptr)->k, k))
			break ;
		ptr = &(*ptr)->next;
	}
	item = *ptr;
	if (!item)
		return ;
	*ptr = item->next;
	t_ht_item_del(item);
	t->count--;
	if (t->count * 10 < t->size)
		t_ht_resize(t, (t->size + 1) / 2);
}

void		t_ht_del(t_ht *t)
{
	int			i;
	t_ht_item	*item;
	t_ht_item	*next;

	i = -1;
	while (++i < t->size)
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
