/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksticks <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 17:00:48 by ksticks           #+#    #+#             */
/*   Updated: 2019/10/17 17:00:50 by ksticks          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	void *r;

	r = malloc(size * count);
	if (r)
		ft_bzero(r, size * count);
	return (r);
}

void	*ft_realloc(void *ptr, size_t new_size, size_t old_size)
{
	void *ret;

	ret = malloc(new_size);
	if (ret)
		ft_memcpy(ret, ptr, old_size);
	free(ptr);
	return (ret);
}
