#include <stdio.h>
#include "libft.h"
#include "ft_linalg.h"

t_mat t_mat_identity()
{
	t_mat m;

	t_mat_reset(&m);
	return (m);
}

t_mat *t_mat_reset(t_mat *m)
{
	int i;

	ft_bzero(m, sizeof(*m));
	i = -1;
	while (++i < MAT_RANK)
		m->data[i][i] = 1;
	return m;
}

static t_mat *t_mat_add_ref(t_mat *a, t_mat *b)
{
	int i;
	int j;

	i = -1;
	while (++i < MAT_RANK)
	{
		j = -1;
		while (++j < MAT_RANK)
		{
			a->data[i][j] += b->data[i][j];
		}
	}
	return (a);
}

void t_mat_translate(t_mat *m, t_vec v)
{
	m->data[0][3] += v.x;
	m->data[1][3] += v.y;
	m->data[2][3] += v.z;
}

t_mat t_mat_mul(t_mat a, t_mat b)
{
	t_mat R;
	int i;
	int j;
	int k;

	i = -1;
	while (++i < MAT_RANK)
	{
		j = -1;
		while (++j < MAT_RANK)
		{
			R.data[i][j] = 0;
			k = -1;
			while (++k < MAT_RANK)
			{
				R.data[i][j] += a.data[i][k] * b.data[k][j];
			}
		}
	}
	return (R);
}

t_mat t_mat_mul_ref(t_mat *A, t_mat *B)
{
	t_mat R;
	int i;
	int j;
	int k;

	i = -1;
	while (++i < MAT_RANK)
	{
		j = -1;
		while (++j < MAT_RANK)
		{
			R.data[i][j] = 0;
			k = -1;
			while (++k < MAT_RANK)
			{
				R.data[i][j] += A->data[i][k] * B->data[k][j];
			}
		}
	}
	return (R);
}

t_mat *t_mat_mul_c(t_mat *m, double c)
{
	int i;
	int j;

	i = -1;
	while (++i < MAT_RANK)
	{
		j = -1;
		while (++j < MAT_RANK)
		{
			m->data[i][j] *= c;
		}
	}
	return (m);
}

t_mat t_mat_rot(t_vec axis, double theta)
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
	t_mat_mul_c(&w, ft_sin(theta));
	t_mat_mul_c(&w2, 1 - ft_cos(theta));
	w.data[0][0] += 1.;
	w.data[1][1] += 1.;
	w.data[2][2] += 1.;
	t_mat_add_ref(&w, &w2);
	w.data[3][3] = 1;
	return (w);
}

t_mat t_mat_rotation(t_vec axis, double theta, t_vec p)
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

void t_mat_printf(t_mat m)
{
	int i;
	int j;

	printf("Matrix[\n");
	for (i = 0; i < MAT_RANK; ++i)
	{
		for (j = 0; j < MAT_RANK; ++j)
		{
			printf("%.2f\t", m.data[i][j]);
		}
		printf("\n");
	}
	printf("]\n");
}