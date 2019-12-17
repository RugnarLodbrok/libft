/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_log.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksticks <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 18:00:10 by ksticks           #+#    #+#             */
/*   Updated: 2019/10/23 18:00:11 by ksticks          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_math.h"

static void	move_to_zero(REAL *x, REAL *r)
{
	while (*x > 2 / (1 + 1 / E))
	{
		*x /= E;
		*r += 1;
	}
	while (*x < 2 / (1 + 1 / E) / E)
	{
		*x *= E;
		*r -= 1;
	}
}

REAL		ft_log(REAL x)
{
	int		k;
	REAL	r;
	REAL	acc;
	REAL	num;

	if (x <= 0)
		return (0);
	r = 0;
	move_to_zero(&x, &r);
	x -= 1;
	k = 1;
	num = -1;
	acc = 1;
	while (acc > EPSILON / 100 || acc < -EPSILON / 100)
	{
		num *= -x;
		acc = num / k;
		r += acc;
		k++;
	}
	return (r);
}
