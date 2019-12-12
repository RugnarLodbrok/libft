/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksticks <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 18:52:31 by ksticks           #+#    #+#             */
/*   Updated: 2019/11/14 18:52:32 by ksticks          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_linalg.h"
#include <math.h>

REAL	t_vec_len(t_vec v)
{
	return (sqrt((v.x) * (v.x) + (v.y) * (v.y) + (v.z) * (v.z)));
}

t_vec	*t_vec_normalize(t_vec *v)
{
	double len;

	len = t_vec_len(*v);
	if (len)
	{
		v->x /= len;
		v->y /= len;
		v->z /= len;
	}
	else
	{
		v->x = 0;
		v->y = 0;
		v->z = 1;
	}
	return (v);
}

void	t_vec_scale(t_vec *v, REAL n)
{
	v->x *= n;
	v->y *= n;
	v->z *= n;
}

t_vec	t_vec_mul(t_vec a, REAL n)
{
	t_vec r;

	r.x = a.x * n;
	r.y = a.y * n;
	r.z = a.z * n;
	return (r);
}

void	t_vec_decay(t_vec *v, REAL x)
{
	REAL len;

	len = t_vec_len(*v);
	if (len <= x)
	{
		ft_bzero(v, sizeof(t_vec));
		return ;
	}
	*v = t_vec_mul(*v, (len - x) / len);
}
