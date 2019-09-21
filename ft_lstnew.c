/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksticks <ksticks@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/11 20:49:49 by ksticks           #+#    #+#             */
/*   Updated: 2019/09/17 19:13:05 by ksticks          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list *e;

	if (!(e = malloc(sizeof(t_list))))
		return (0);
	e->next = 0;
	if (!content)
	{
		e->content = 0;
		e->content_size = 0;
		return (e);
	}
	if (!(e->content = malloc(content_size)))
	{
		free(e);
		return (0);
	}
	ft_memcpy(e->content, content, content_size);
	e->content_size = content_size;
	return (e);
}
