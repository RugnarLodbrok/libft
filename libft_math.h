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

#ifndef LIBFT_MATH_H
# define LIBFT_MATH_H

# define FLOAT_PI 3.1415927410125732421875
# define DOUBLE_PI 3.141592653589793115997963468544185161590576171875
# define PI DOUBLE_PI
# define E 2.7182818284590452353602874713527

# ifndef REAL_FLOAT
#  define REAL_FLOAT 0
# endif

# if !REAL_FLOAT
#  define REAL double
#  define EPSILON .0000000000001
#  define SIN(x) sin(x)
#  define COS(x) cos(x)
#  define TAN(x) tan(x)
# else
#  define REAL float
#  define EPSILON .00001f
#  define SIN(x) sinf(x)
#  define COS(x) cosf(x)
#  define TAN(x) tanf(x)
# endif

/*
** https://albertveli.wordpress.com/2015/01/10/zx-sine/
*/

# include "libft_compat.h"

int		ft_sqrt_int(int nb);
int		ft_sqrt_ceil(int nb);
REAL	ft_sqrt(REAL nb);
int		ft_pow(int a, int b);
REAL	ft_fpow(REAL a, int b);
ullong	ft_ullpow(ullong a, ullong b);
int		ft_abs(int a);
REAL	ft_fabs(REAL a);
REAL	ft_sin(REAL a);
REAL	ft_cos(REAL a);
REAL	ft_log(REAL x);
REAL	radians(REAL degrees);

#endif
