/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksticks <ksticks@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 17:04:10 by ksticks           #+#    #+#             */
/*   Updated: 2019/09/17 19:13:05 by ksticks          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t n)
{
	char *d;

	d = dst;
	if (!n)
		return (ft_strlen(src));
	while (*d++)
		if (!--n)
			return (d - dst + ft_strlen(src));
	d--;
	while (--n)
		if (!(*d++ = *src++))
			return (d - dst - 1);
	*d = 0;
	return (d - dst + ft_strlen(src));
}
