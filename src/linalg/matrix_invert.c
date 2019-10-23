#include "libft.h"
#include "ft_linalg.h"

static void	swap_rows(t_mat *A, t_mat *B, int i, int j)
{
	double tmp[MAT_RANK];
	size_t s;

	s = sizeof(double) * MAT_RANK;
	ft_memcpy(tmp, A->data[i], s);
	ft_memcpy(A->data[i], A->data[j], s);
	ft_memcpy(A->data[j], tmp, s);
	ft_memcpy(tmp, B->data[i], s);
	ft_memcpy(B->data[i], B->data[j], s);
	ft_memcpy(B->data[j], tmp, s);
}

static void	div_row(t_mat *A, t_mat *B, int i, double c)
{
	int j;

	j = -1;
	while (++j < MAT_RANK)
	{
		A->data[i][j] /= c;
		B->data[i][j] /= c;
	}
}

static void	sub_row(t_mat *A, t_mat *B, int i, int k, double c)
{
	int j;

	j = -1;
	while (++j < MAT_RANK)
	{
		A->data[i][j] -= A->data[k][j] * c;
		B->data[i][j] -= B->data[k][j] * c;
	}
}

t_mat		t_mat_inverted(t_mat m)
{
	int i;
	int n;
	t_mat R;

	t_mat_reset(&R);
	n = -1;
	while (++n < MAT_RANK)
	{
		if (m.data[n][n] < MAT_INVERT_EPS && m.data[n][n] > -MAT_INVERT_EPS)
		{
			i = n + 1 - 1;
			while (++i < MAT_RANK)
				if (m.data[i][n] > MAT_INVERT_EPS || m.data[i][n] < -MAT_INVERT_EPS)
				{
					swap_rows(&m, &R, n, i);
					break;
				}
		}
		div_row(&m, &R, n, m.data[n][n]);
		i = n + 1 - 1;
		while (++i < MAT_RANK)
			if (m.data[i][n])
				sub_row(&m, &R, i, n, m.data[i][n] / m.data[n][n]);
	}
	//	at this point m is a triangle matrix
	n = MAT_RANK - 1 + 1;
	while (--n >= 0)
	{
		div_row(&m, &R, n, m.data[n][n]);
		i = -1;
		while (++i < n)
			if (m.data[i][n])
				sub_row(&m, &R, i, n, m.data[i][n] / m.data[n][n]);
	}
	return (R);
}
