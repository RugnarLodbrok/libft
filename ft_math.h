#ifndef FT_MATH_H
# define FT_MATH_H

# define EPSILON .0000000000001
# define DOUBLE_PI 3.141592653589793115997963468544185161590576171875
# define FLOAT_PI 3.1415927410125732421875
# define MAXIMUM_PI 3.1415926535897932384626433832795028841971693993751058209749445923078164062
# define PI DOUBLE_PI
# define E 2.7182818284590452353602874713527

/*
 * https://albertveli.wordpress.com/2015/01/10/zx-sine/
 * */
# define T0(x) ( 1 )
# define T1(x) ( x )
# define T2(x) ( 2 * x*x - 1 )
# define T3(x) ( 4 * x*x*x - 3 * x )
# define T4(x) ( 8 * x*x*x*x - 8 * x*x + 1 )
# define T5(x) ( 16 * x*x*x*x*x - 20 * x*x*x + 5 * x )

# define C0 1.276278962f
# define C1 -.285261569f
# define C2 0.009118016f
# define C3 -.000136587f
# define C4 0.000001185f
# define C5 -.000000007f

# define P(z) ( C0 * T0(z) + C1 * T1(z) + C2 * T2(z) + C3 * T3(z) + C4 * T4(z) + C5 * T5(z) )

# include "libft.h"

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
double	zx_sin(double x);
double	ft_log(double x);
double	radians(double degrees);

#endif
