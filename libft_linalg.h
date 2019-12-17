/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_linalg.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksticks <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 17:07:14 by ksticks           #+#    #+#             */
/*   Updated: 2019/10/23 17:07:15 by ksticks          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_LINALG_H
# define FT_LINALG_H

# include "libft_math.h"

# define MAT_RANK 4
# define MAT_INV_C 0.2

typedef struct	s_vec
{
	REAL x;
	REAL y;
	REAL z;
}				t_vec;

typedef struct	s_mat
{
	REAL data[MAT_RANK][MAT_RANK];
}				t_mat;

REAL			t_vec_len(t_vec v);
t_vec			t_vec_add(t_vec a, t_vec b);
t_vec			t_vec_sub(t_vec a, t_vec b);
t_vec			t_vec_mul(t_vec a, REAL n);
void			t_vec_scale(t_vec *v, REAL n);
t_vec			*t_vec_normalize(t_vec *v);
REAL			t_vec_dot(t_vec a, t_vec b);
t_vec			t_vec_cross(t_vec a, t_vec b);
t_vec			t_vec_proj(t_vec a, t_vec b);
void			t_vec_translate(t_vec *v, t_vec t);
t_vec			t_vec_transform(t_vec v, t_mat *a);
t_vec			t_vec_transform3(t_vec v, t_mat *a);
t_vec			t_vec_transform4(t_vec v, t_mat *a);

void			t_vec_decay(t_vec *v, REAL x);
t_mat			*t_mat_reset(t_mat *m);
t_mat			*t_mat_add_ref(t_mat *a, t_mat *b);
t_mat			t_mat_mul(t_mat a, t_mat b);
t_mat			t_mat_mul_ref(t_mat *a, t_mat *b);
t_mat			*t_mat_mul_c(t_mat *m, REAL c);
t_mat			t_mat_rot(t_vec axis, REAL theta);
t_mat			t_mat_rotation(t_vec axis, REAL theta, t_vec p);
t_mat			t_mat_inverted(t_mat m);
void			t_mat_printf(t_mat m);
void			t_mat_translate(t_mat *m, t_vec v);

t_mat			proj_iso(REAL fov_width, REAL fov_height);
t_mat			proj_pers_nwh(REAL n, REAL w, REAL h, REAL f);
t_mat			proj_pers(REAL fov, REAL aspect, REAL near, REAL far);

#endif
