/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksticks <ksticks@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 16:28:00 by ksticks           #+#    #+#             */
/*   Updated: 2019/09/17 19:13:05 by ksticks          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t	n;
	char	*ret;

	n = ft_strlen(s1);
	if (!(ret = malloc(sizeof(char) * (n + 1))))
		return (0);
	ft_strcpy(ret, s1);
	return (ret);
}

char	*ft_strndup(const char *s1, size_t n)
{
	char	*str;
	char	*s2;
	size_t	len;

	len = ft_strlen(s1);
	len = (len > n ? n : len);
	str = (char*)malloc(sizeof(char) * (len + 1));
	if ((s2 = str))
	{
		while (len--)
			*s2++ = *s1++;
		*s2 = '\0';
	}
	return (str);
}
