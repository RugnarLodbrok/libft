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

#include <stdlib.h>
#include "libft.h"

void	*re_alloc(void *ptr, size_t n, size_t len)
{
	void *ret;

	ret = malloc(n);
	if (ret)
		ft_memcpy(ret, ptr, len);
	free(ptr);
	return (ret);
}

void	*t_buff_init(t_buff *b, size_t size)
{
	b->size = size;
	b->len = 0;
	b->data = malloc(sizeof(char) * (size + 1));
	return (b->data);
}

int		t_buff_extend(t_buff *b)
{
	size_t size_old;

	size_old = b->size;
	b->size *= 2;
	if (!(b->data = re_alloc(b->data, b->size + 1, size_old)))
		return (0);
	return (b->size);
}

int		t_buff_add_len(t_buff *b, size_t len)
{
	b->len += len;
	while (b->len > b->size)
		if (!t_buff_extend(b))
			return (0);
	return (b->len);
}
