/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksticks <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 15:50:28 by ksticks           #+#    #+#             */
/*   Updated: 2019/10/17 15:50:30 by ksticks          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dst, char *src, size_t size)
{
	unsigned int	len;
	int				ended;

	len = 0;
	ended = 0;
	while (size > 1)
	{
		size--;
		*dst = *src;
		if (!*src)
		{
			ended = 1;
			break ;
		}
		dst++;
		src++;
		len++;
	}
	if (size && !ended)
		*dst = 0;
	while (*(src++))
		len++;
	return (len);
}
