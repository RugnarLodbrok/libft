#ifndef FT_MATH_H
# define FT_MATH_H

# define EPSILON .0000000000000000001
# define DOUBLE_PI 3.141592653589793115997963468544185161590576171875
# define FLOAT_PI 3.1415927410125732421875
# define MAXIMUM_PI 3.1415926535897932384626433832795028841971693993751058209749445923078164062
# define PI DOUBLE_PI

int					ft_sqrt_int(int nb);
int					ft_sqrt_ceil(int nb);
double				ft_sqrt(double nb);
int					ft_pow(int a, int b);
int					ft_abs(int a);
double				ft_fabs(double a);
double				ft_sin(double a);
double				ft_cos(double a);

#endif