/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_math.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksticks <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 17:47:40 by ksticks           #+#    #+#             */
/*   Updated: 2019/10/23 17:47:42 by ksticks          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_MATH_H
# define FT_MATH_H

# define EPSILON .0000000000001
# define FLOAT_PI 3.1415927410125732421875
# define DOUBLE_PI 3.141592653589793115997963468544185161590576171875
# define PI DOUBLE_PI
# define E 2.7182818284590452353602874713527

// https://albertveli.wordpress.com/2015/01/10/zx-sine/

# include "libft_compat.h"

int		ft_sqrt_int(int nb);
int		ft_sqrt_ceil(int nb);
double	ft_sqrt(double nb);
int		ft_pow(int a, int b);
double	ft_fpow(double a, int b);
ullong	ft_ullpow(ullong a, ullong b);
int		ft_abs(int a);
double	ft_fabs(double a);
double	ft_sin(double a);
double	ft_cos(double a);
double	ft_log(double x);
double	radians(double degrees);

#endif
