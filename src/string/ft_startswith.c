/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_startswith.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksticks <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 17:53:34 by ksticks           #+#    #+#             */
/*   Updated: 2019/11/14 17:53:35 by ksticks          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_startswith(const char *s, const char *prefix)
{
	if (!s)
		return (0);
	while (*prefix)
	{
		if (!*s)
			return (0);
		if (*prefix++ != *s++)
			return (0);
	}
	return (1);
}
