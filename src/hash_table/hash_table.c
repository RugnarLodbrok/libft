/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash_table.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksticks <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 18:30:36 by ksticks           #+#    #+#             */
/*   Updated: 2019/11/15 18:30:38 by ksticks          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "hash_table.h"

void	t_ht_init(t_ht *t, int size)
{
	t->size = (size < HT_MIN_SIZE) ? HT_MIN_SIZE : size;
	t->count = 0;
	t->items = malloc(sizeof(t_ht_item *) * t->size);
	ft_bzero(t->items, sizeof(t_ht_item *) * t->size);
	t->hash_f_str = &hash_fnv1a;
}

char	*t_ht_get(t_ht *t, const char *k)
{
	uint		hash;
	t_ht_item	*item;

	hash = t->hash_f_str(k);
	item = t->items[hash % t->size];
	while (item)
	{
		if (!ft_strcmp(item->k, k))
			break ;
		item = item->next;
	}
	if (item)
		return (item->v);
	return (0);
}
