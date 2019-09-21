/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksticks <ksticks@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 18:45:24 by ksticks           #+#    #+#             */
/*   Updated: 2019/09/17 19:13:05 by ksticks          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static unsigned int	count_digits(int n)
{
	unsigned int i;

	if (n == 0)
		return (1);
	i = 0;
	if (n > 0)
		n *= -1;
	else
		i++;
	while (n)
	{
		n /= 10;
		i++;
	}
	return (i);
}

static void			ft_itoa_static(char *s, unsigned int d, int n)
{
	if (n >= 0)
		n *= -1;
	else
		s[0] = '-';
	s[d] = 0;
	if (n == 0)
		s[0] = '0';
	while (n)
	{
		s[d-- - 1] = '0' - (n % 10);
		n /= 10;
	}
}

char				*ft_itoa(int n)
{
	unsigned int	d;
	char			*s;

	d = count_digits(n);
	if (!(s = malloc(sizeof(char) * (d + 1))))
		return (0);
	ft_itoa_static(s, d, n);
	return (s);
}
