/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix_transform.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksticks <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 20:42:21 by ksticks           #+#    #+#             */
/*   Updated: 2019/11/14 20:42:23 by ksticks          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "libft.h"
#include "ft_linalg.h"

void	t_mat_translate(t_mat *m, t_vec v)
{
	m->data[0][3] += v.x;
	m->data[1][3] += v.y;
	m->data[2][3] += v.z;
}

t_mat	t_mat_rot(t_vec axis, double theta)
{
	t_mat w;
	t_mat w2;

	t_vec_normalize(&axis);
	ft_bzero(&w, sizeof(w));
	w.data[0][0] = 0;
	w.data[0][1] = -axis.z;
	w.data[0][2] = axis.y;
	w.data[1][0] = axis.z;
	w.data[1][1] = 0;
	w.data[1][2] = -axis.x;
	w.data[2][0] = -axis.y;
	w.data[2][1] = axis.x;
	w.data[2][2] = 0;
	w.data[3][3] = 1;
	w2 = t_mat_mul_ref(&w, &w);
	t_mat_mul_c(&w, sin(theta));
	t_mat_mul_c(&w2, 1 - cos(theta));
	w.data[0][0] += 1.;
	w.data[1][1] += 1.;
	w.data[2][2] += 1.;
	t_mat_add_ref(&w, &w2);
	w.data[3][3] = 1;
	return (w);
}

t_mat	t_mat_rotation(t_vec axis, double theta, t_vec p)
{
	t_mat m;
	t_mat t;

	m = t_mat_rot(axis, theta);
	t_mat_reset(&t);
	t_mat_translate(&t, p);
	m = t_mat_mul_ref(&t, &m);
	t = t_mat_inverted(t);
	m = t_mat_mul_ref(&m, &t);
	return (m);
}
