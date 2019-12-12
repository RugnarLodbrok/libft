/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_arithmetic.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksticks <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 21:01:22 by ksticks           #+#    #+#             */
/*   Updated: 2019/11/14 21:01:23 by ksticks          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_linalg.h"

t_mat	*t_mat_add_ref(t_mat *a, t_mat *b)
{
	int i;
	int j;

	i = -1;
	while (++i < MAT_RANK)
	{
		j = -1;
		while (++j < MAT_RANK)
		{
			a->data[i][j] += b->data[i][j];
		}
	}
	return (a);
}

t_mat	t_mat_mul(t_mat a, t_mat b)
{
	t_mat	r;
	int		i;
	int		j;
	int		k;

	i = -1;
	while (++i < MAT_RANK)
	{
		j = -1;
		while (++j < MAT_RANK)
		{
			r.data[i][j] = 0;
			k = -1;
			while (++k < MAT_RANK)
			{
				r.data[i][j] += a.data[i][k] * b.data[k][j];
			}
		}
	}
	return (r);
}

t_mat	t_mat_mul_ref(t_mat *a, t_mat *b)
{
	t_mat	r;
	int		i;
	int		j;
	int		k;

	i = -1;
	while (++i < MAT_RANK)
	{
		j = -1;
		while (++j < MAT_RANK)
		{
			r.data[i][j] = 0;
			k = -1;
			while (++k < MAT_RANK)
			{
				r.data[i][j] += a->data[i][k] * b->data[k][j];
			}
		}
	}
	return (r);
}

t_mat	*t_mat_mul_c(t_mat *m, REAL c)
{
	int i;
	int j;

	i = -1;
	while (++i < MAT_RANK)
	{
		j = -1;
		while (++j < MAT_RANK)
		{
			m->data[i][j] *= c;
		}
	}
	return (m);
}
