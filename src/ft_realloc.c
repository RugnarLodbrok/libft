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

void	*ft_realloc(void *ptr, size_t n, size_t len)
{
	void *ret;

	ret = malloc(n);
	if (ret)
		ft_memcpy(ret, ptr, len);
	free(ptr);
	return (ret);
}
