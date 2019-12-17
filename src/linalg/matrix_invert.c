/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_invert.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksticks <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 18:55:55 by ksticks           #+#    #+#             */
/*   Updated: 2019/11/14 18:55:56 by ksticks          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libft_linalg.h"

static void	swap_rows(t_mat *a, t_mat *b, int i, int j)
{
	double	tmp[MAT_RANK];
	size_t	s;

	s = sizeof(REAL) * MAT_RANK;
	ft_memcpy(tmp, a->data[i], s);
	ft_memcpy(a->data[i], a->data[j], s);
	ft_memcpy(a->data[j], tmp, s);
	ft_memcpy(tmp, b->data[i], s);
	ft_memcpy(b->data[i], b->data[j], s);
	ft_memcpy(b->data[j], tmp, s);
}

static void	div_row(t_mat *a, t_mat *b, int i, REAL c)
{
	int j;

	j = -1;
	while (++j < MAT_RANK)
	{
		a->data[i][j] /= c;
		b->data[i][j] /= c;
	}
}

static void	sub_row(t_mat *a, t_mat *b, t_point ik, REAL c)
{
	int j;
	int i;
	int k;

	i = ik.x;
	k = ik.y;
	j = -1;
	while (++j < MAT_RANK)
	{
		a->data[i][j] -= a->data[k][j] * c;
		b->data[i][j] -= b->data[k][j] * c;
	}
}

void		t_mat_invert_first_pass(t_mat *m, t_mat *r)
{
	int i;
	int n;

	n = -1;
	while (++n < MAT_RANK)
	{
		if (m->data[n][n] < MAT_INV_C && m->data[n][n] > -MAT_INV_C)
		{
			i = n + 1 - 1;
			while (++i < MAT_RANK)
				if (m->data[i][n] > MAT_INV_C || m->data[i][n] < -MAT_INV_C)
				{
					swap_rows(m, r, n, i);
					break ;
				}
		}
		div_row(m, r, n, m->data[n][n]);
		i = n + 1 - 1;
		while (++i < MAT_RANK)
			if (m->data[i][n])
				sub_row(m, r, (t_point){i, n}, m->data[i][n] / m->data[n][n]);
	}
}

t_mat		t_mat_inverted(t_mat m)
{
	int		i;
	int		n;
	t_mat	r;

	t_mat_reset(&r);
	t_mat_invert_first_pass(&m, &r);
	n = MAT_RANK - 1 + 1;
	while (--n >= 0)
	{
		div_row(&m, &r, n, m.data[n][n]);
		i = -1;
		while (++i < n)
			if (m.data[i][n])
				sub_row(&m, &r, (t_point){i, n}, m.data[i][n] / m.data[n][n]);
	}
	return (r);
}
