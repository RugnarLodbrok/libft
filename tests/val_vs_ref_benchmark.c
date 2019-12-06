#include "libft.h"

#define N 10000000


double by_val(t_vec v)
{
	double x;

	x = v.x;
	x = v.y;
	x = v.z;
	x = v.x;
	x = v.y;
	x = v.z;
	return (x);
}

double by_ref(t_vec *v)
{
	double x;

	x = v->x;
	x = v->y;
	x = v->z;
	x = v->x;
	x = v->y;
	x = v->z;
	return (x);
}

void val_vs_ref_benchmark()
{
	int i;
//	t_vec v;
	t_mat m;

	m = (t_mat){{
						{1, 1, 1, 1},
						{1, 1, 1, 1},
						{1, 1, 1, 1},
						{1, 1, 1, 1},
				}};
//	v = (t_vec){1., 2., 3.};
	swatch();
	for (i = 0; i < N; ++i)
		t_mat_mul(m, m);
//		by_val(v);
	swatch_print();
	for (i = 0; i < N; ++i)
		t_mat_mul_ref(&m, &m);
//		by_ref(&v);
	swatch_print();
}
