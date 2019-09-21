/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksticks <ksticks@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 17:32:53 by ksticks           #+#    #+#             */
/*   Updated: 2019/09/17 19:13:05 by ksticks          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t n)
{
	unsigned int hay_i;
	unsigned int nee_i;
	unsigned int len;

	len = ft_strlen(needle);
	if (!len)
		return ((char *)haystack);
	hay_i = 0;
	while (haystack[hay_i] && hay_i < n)
	{
		nee_i = 0;
		while (haystack[hay_i + nee_i] == needle[nee_i]
				&& haystack[hay_i + nee_i]
				&& needle[nee_i]
				&& hay_i + nee_i < n)
			nee_i++;
		if (nee_i == len)
			return ((char *)haystack + hay_i);
		hay_i++;
	}
	return (0);
}
