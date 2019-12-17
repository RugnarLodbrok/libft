/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_trig.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksticks <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 18:05:55 by ksticks           #+#    #+#             */
/*   Updated: 2019/10/23 18:05:56 by ksticks          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static REAL	trig_mod(REAL x)
{
	while (x > PI)
		x -= PI;
	while (x < -PI)
		x += PI;
	return (x);
}

REAL		ft_cos(REAL x)
{
	int		k;
	REAL	r;
	REAL	acc;
	REAL	den;
	REAL	num;

	k = 1;
	r = 1;
	acc = 1;
	den = 1;
	num = 1;
	x = trig_mod(x);
	if (x > PI / 2)
		return (-ft_cos(PI - x));
	if (x < -PI / 2)
		return (-ft_cos(-PI - x));
	while (acc > EPSILON || acc < -EPSILON)
	{
		num *= -x * x;
		den *= k * (k + 1);
		acc = num / den;
		r += acc;
		k += 2;
	}
	return (r);
}

REAL		ft_sin(REAL x)
{
	int		k;
	REAL	r;
	REAL	acc;
	REAL	den;
	REAL	num;

	k = 2;
	acc = 1;
	den = 1;
	x = trig_mod(x);
	if (x > PI / 2)
		return (ft_sin(PI - x));
	if (x < -PI / 2)
		return (ft_sin(-PI - x));
	r = x;
	num = x;
	while (acc > EPSILON || acc < -EPSILON)
	{
		num *= -x * x;
		den *= k * (k + 1);
		acc = num / den;
		r += acc;
		k += 2;
	}
	return (r);
}

REAL		radians(REAL degrees)
{
	return (degrees * PI / 180.0);
}
