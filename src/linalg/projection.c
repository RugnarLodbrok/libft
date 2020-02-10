/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   projection.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rpoetess <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/21 21:50:45 by ksticks           #+#    #+#             */
/*   Updated: 2019/11/21 21:50:47 by ksticks          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_linalg.h"
#include "libft_math.h"
#include <math.h>

t_mat	proj_iso(REAL fov_width, REAL fov_height)
{
	return ((t_mat){{
							{2. / fov_width, 0, 0, 0},
							{0, 2. / fov_height, 0, 0},
							{0, 0, 0, 0},
							{0, 0, 0, 1}}});
}

t_mat	proj_pers_nwh(REAL n, REAL w, REAL h, REAL f)
{
	REAL l;
	REAL r;
	REAL b;
	REAL t;

	l = -w / 2;
	r = w / 2;
	b = -h / 2;
	t = h / 2;
	return ((t_mat){{
						{2 * n / (r - l), 0, (r + l) / (r - l), 0},
						{0, 2 * n / (t - b), (t + b) / (t - b), 0},
						{0, 0, -(f + n) / (f - n), -2 * f * n / (f - n)},
						{0, 0, -1, 0}}});
}

t_mat	proj_pers(REAL fov, REAL aspect, REAL near, REAL far)
{
	REAL tg;

	tg = TAN(radians(fov) / 2.);
	if (aspect > 1.)
		return (proj_pers_nwh(near, near * tg, near * tg / aspect, far));
	else
		return (proj_pers_nwh(near, near * tg * aspect, near * tg, far));
}
