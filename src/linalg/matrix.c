/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksticks <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 21:03:13 by ksticks           #+#    #+#             */
/*   Updated: 2019/11/14 21:03:14 by ksticks          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "libft_linalg.h"

t_mat	t_mat_identity(void)
{
	t_mat m;

	t_mat_reset(&m);
	return (m);
}

t_mat	*t_mat_reset(t_mat *m)
{
	int i;

	ft_bzero(m, sizeof(*m));
	i = -1;
	while (++i < MAT_RANK)
		m->data[i][i] = 1;
	return (m);
}

void	t_mat_printf(t_mat m)
{
	int i;
	int j;

	ft_printf("Matrix[\n");
	i = -1;
	while (++i < MAT_RANK)
	{
		j = -1;
		while (++j < MAT_RANK)
			ft_printf("%.2f\t", m.data[i][j]);
		ft_printf("\n");
	}
	ft_printf("]\n");
}
