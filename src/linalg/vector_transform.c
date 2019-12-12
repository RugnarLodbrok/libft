/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_transform.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksticks <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/14 17:59:16 by ksticks           #+#    #+#             */
/*   Updated: 2019/11/14 17:59:20 by ksticks          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_linalg.h"

void	t_vec_translate(t_vec *v, t_vec t)
{
	v->x += t.x;
	v->y += t.y;
	v->z += t.z;
}

t_vec	t_vec_transform3(t_vec v, t_mat *a)
{
	t_vec r;

	r.x =
			a->data[0][0] * v.x +
			a->data[0][1] * v.y +
			a->data[0][2] * v.z;
	r.y =
			a->data[1][0] * v.x +
			a->data[1][1] * v.y +
			a->data[1][2] * v.z;
	r.z =
			a->data[2][0] * v.x +
			a->data[2][1] * v.y +
			a->data[2][2] * v.z;
	return (r);
}

t_vec	t_vec_transform(t_vec v, t_mat *a)
{
	t_vec r;

	r.x =
			a->data[0][0] * v.x +
			a->data[0][1] * v.y +
			a->data[0][2] * v.z +
			a->data[0][3];
	r.y =
			a->data[1][0] * v.x +
			a->data[1][1] * v.y +
			a->data[1][2] * v.z +
			a->data[1][3];
	r.z =
			a->data[2][0] * v.x +
			a->data[2][1] * v.y +
			a->data[2][2] * v.z +
			a->data[2][3];
	return (r);
}

t_vec	t_vec_transform4(t_vec v, t_mat *a)
{
	t_vec	r;
	REAL	w;

	w =
			a->data[3][0] * v.x +
			a->data[3][1] * v.y +
			a->data[3][2] * v.z +
			a->data[3][3];
	r.x = (
			a->data[0][0] * v.x +
			a->data[0][1] * v.y +
			a->data[0][2] * v.z +
			a->data[0][3]) / w;
	r.y = (
			a->data[1][0] * v.x +
			a->data[1][1] * v.y +
			a->data[1][2] * v.z +
			a->data[1][3]) / w;
	r.z = (
			a->data[2][0] * v.x +
			a->data[2][1] * v.y +
			a->data[2][2] * v.z +
			a->data[2][3]) / w;
	return (r);
}
