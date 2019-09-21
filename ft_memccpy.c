/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksticks <ksticks@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 15:06:34 by ksticks           #+#    #+#             */
/*   Updated: 2019/09/17 19:13:05 by ksticks          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char cc;
	unsigned char *s;
	unsigned char *d;

	cc = (unsigned char)c;
	s = (unsigned char *)src;
	d = (unsigned char *)dst;
	while (n--)
	{
		*d++ = *s++;
		if (cc == *(s - 1))
			return ((void *)d);
	}
	return (NULL);
}
