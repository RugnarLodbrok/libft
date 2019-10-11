#ifndef FT_LINALG_H
# define FT_LINALG_H

# define MAT_RANK 4
# define MAT_INVERT_EPS 0.01

typedef struct
{
	double x;
	double y;
	double z;
} t_vec;

/*
 * | x1 x2 x3 dx |
 * | y1 y2 y3 dy |
 * | z1 z2 z3 dz |
 * | 0  0  0  1  |
 */

typedef struct
{
	double data[MAT_RANK][MAT_RANK];
} t_mat;

double t_vec_len(t_vec v);
t_vec t_vec_add(t_vec a, t_vec b);
t_vec t_vec_mul(t_vec a, double n);
t_vec *t_vec_normalize(t_vec *v);
t_vec t_vec_transform(t_vec v, t_mat A);
void t_vec_decay(t_vec *v, double x);
t_mat *t_mat_reset(t_mat *m);
t_mat t_mat_mul(t_mat A, t_mat B);
t_mat t_mat_rot(t_vec axis, double theta);
t_mat t_mat_rot_point(t_vec axis, double theta, t_vec p);
t_mat t_mat_inverted(t_mat M);
void t_mat_printf(t_mat m);

#endif
