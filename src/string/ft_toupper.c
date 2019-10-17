/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksticks <ksticks@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 17:56:11 by ksticks           #+#    #+#             */
/*   Updated: 2019/09/17 19:13:05 by ksticks          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	islow(int c)
{
	return (c >= 'a' && c <= 'z');
}

int			ft_toupper(int c)
{
	if (islow(c))
		return (c - 32);
	return (c);
}

char		*ft_toupper_inplace(char *s)
{
	char *p;

	p = s;
	while ((*p = (char)ft_toupper(*p)))
		p++;
	return (s);
}
