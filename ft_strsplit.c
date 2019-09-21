/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksticks <ksticks@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 18:00:20 by ksticks           #+#    #+#             */
/*   Updated: 2019/09/17 19:13:05 by ksticks          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static int	chunk_len(const char *s, char c)
{
	int n;

	n = 0;
	while (*s && *s != c)
	{
		n++;
		s++;
	}
	return (n);
}

static int	count_chunks(const char *s, char c)
{
	int n;

	n = 0;
	while (1)
	{
		while (*s && *s == c)
			s++;
		if (!*s)
			return (n);
		n++;
		s += chunk_len(s, c);
	}
}

static char	**clear(char **p)
{
	char *ptr;

	ptr = *p;
	while (ptr)
		free(ptr++);
	free(p);
	return (0);
}

char		**ft_strsplit(char const *s, char c)
{
	char	**ret;
	char	**ptr;
	int		l;

	if (!(ret = malloc(sizeof(char *) * (count_chunks(s, c) + 1))))
		return (0);
	ptr = ret;
	while (1)
	{
		while (*s && *s == c)
			s++;
		if (!*s)
		{
			*ptr = 0;
			return (ret);
		}
		l = chunk_len(s, c);
		if (!(*ptr = malloc(sizeof(char) * (l + 1))))
			return (clear(ret));
		(*ptr)[l] = 0;
		ft_strncpy(*ptr++, s, l);
		s += l;
	}
}
