/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_buff.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksticks <ksticks@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/16 20:57:25 by ksticks           #+#    #+#             */
/*   Updated: 2019/09/17 19:01:42 by ksticks          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*t_buff_init(t_buff *b, size_t size)
{
	b->size = size;
	b->len = 0;
	b->data = malloc(sizeof(char) * (size + 1));
	return (b->data);
}

size_t	t_buff_extend(t_buff *b)
{
	size_t size_old;

	size_old = b->size;
	b->size *= 2;
	if (!(b->data = ft_realloc(b->data, b->size + 1, size_old)))
		return (0);
	return (b->size);
}

int		t_buff_append(t_buff *b, void *data, size_t len)
{
	while (b->len + len > b->size)
		if(!t_buff_extend(b))
			return (0);
	ft_memcpy(b->data + b->len, data, len);
	b->len += len;
	return (1);
}
