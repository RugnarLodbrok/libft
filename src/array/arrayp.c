/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   arrayp.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksticks <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 18:07:27 by ksticks           #+#    #+#             */
/*   Updated: 2019/11/26 18:07:29 by ksticks          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		t_arrayp_init(t_arrayp *a)
{
	a->size = 4;
	a->count = 0;
	a->data = malloc(a->size * sizeof(void*));
}

void		*t_arrayp_get(t_arrayp *a, int i, void *default_v)
{
	if ((uint)i >= a->count)
		return (default_v);
	return (a->data[i]);
}

static void	*t_arrayp_extend(t_arrayp *a)
{
	a->size *= 2;
	a->data = ft_realloc(a->data,
						a->size * sizeof(void*),
						a->count * sizeof(void*));
	return (a->data);
}

int			t_arrayp_push(t_arrayp *a, void *v)
{
	if (a->count == a->size - 1)
		if (!t_arrayp_extend(a))
			return (0);
	a->data[a->count] = v;
	return (++a->count);
}

void		t_arrayp_del(t_arrayp *a)
{
	free(a->data);
}
