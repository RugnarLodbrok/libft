/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   array.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksticks <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/08 15:44:13 by rpoetess          #+#    #+#             */
/*   Updated: 2019/11/08 15:44:14 by rpoetess         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		t_array_init(t_array *a, size_t item_size)
{
	a->size = 4;
	a->item_size = item_size;
	a->count = 0;
	a->data = malloc(a->size * a->item_size);
}

void		*t_array_get(t_array *a, int i)
{
	if (i >= a->count)
		return (0);
	return (a->data + i * a->item_size);
}

static void	*t_array_extend(t_array *a)
{
	a->size *= 2;
	a->data = ft_realloc(a->data,
			a->size * a->item_size,
			a->count * a->item_size);
	return (a->data);
}

void		*t_array_push(t_array *a, void *content)
{
	if (a->count == a->size - 1)
		if (!t_array_extend(a))
			return (0);
	ft_memcpy(a->data + a->item_size * a->count, content, a->item_size);
	a->count++;
	return (a->data + a->item_size * (a->count - 1));
}

void		t_array_del(t_array *a)
{
	free(a->data);
}
