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

size_t	ft_count_int_digits(long int n, unsigned int base)
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
		n /= base;
		i++;
	}
	return (i);
}

size_t			ft_itoa_stack(char *s, long int n, unsigned int base)
{
	size_t	r;
	size_t	d;
	char	c;
	int		rem;

	d = ft_count_int_digits(n, base);
	r = d;
	if (n >= 0)
		n *= -1;
	else
		s[0] = '-';
	s[d] = 0;
	if (n == 0)
		s[0] = '0';
	while (n)
	{
		rem = (int ) (- (n % base));
		if (rem > 9)
			c = 'a' + rem - 10;
		else
			c = '0' + rem;
		s[d-- - 1] = c;
		n /= base;
	}
	return (r);
}

char				*ft_itoa(long int n)
{
	size_t	d;
	char	*s;

	d = ft_count_int_digits(n, 10);
	if (!(s = malloc(sizeof(char) * (d + 1))))
		return (0);
	ft_itoa_stack(s, n, 10);
	return (s);
}

char				*ft_itoa_base(long int n, int base)
{
	unsigned int	d;
	char			*s;

	if (base < 2 || base > 32)
		return (0);
	d = ft_count_int_digits(n, base);
	if (!(s = malloc(sizeof(char) * (d + 1))))
		return (0);
	ft_itoa_stack(s, n, base);
	return (s);
}
