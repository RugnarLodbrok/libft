#include "libft.h"
#include "ft_linalg.h"

static void swap_rows(t_mat *A, t_mat *B, int i, int j)
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

static void div_row(t_mat *A, t_mat *B, int i, double c)
{
	int j;

	j = -1;
	while (++j < MAT_RANK)
	{
		A->data[i][j] /= c;
		B->data[i][j] /= c;
	}
}

static void sub_row(t_mat *A, t_mat *B, int i, int k, double c)
{
	int j;

	j = -1;
	while (++j < MAT_RANK)
	{
		A->data[i][j] -= A->data[k][j] * c;
		B->data[i][j] -= B->data[k][j] * c;
	}
}

t_mat t_mat_inverted(t_mat M)
{
	int i;
	int m;
	t_mat R;

	t_mat_reset(&R);
	m = -1;
	while (++m < MAT_RANK)
	{
		if (M.data[m][m] < MAT_INVERT_EPS && M.data[m][m] > -MAT_INVERT_EPS)
		{
			i = m + 1 - 1;
			while (++i < MAT_RANK)
				if (M.data[i][m] > MAT_INVERT_EPS || M.data[i][m] < -MAT_INVERT_EPS)
				{
					swap_rows(&M, &R, m, i);
					break;
				}
		}
		div_row(&M, &R, m, M.data[m][m]);
		i = m + 1 - 1;
		while (++i < MAT_RANK)
			if (M.data[i][m])
				sub_row(&M, &R, i, m, M.data[i][m] / M.data[m][m]);
	}
	//	at this point M is a triangle matrix
	m = MAT_RANK - 1 + 1;
	while (--m >= 0)
	{
		div_row(&M, &R, m, M.data[m][m]);
		i = -1;
		while (++i < m)
			if (M.data[i][m])
				sub_row(&M, &R, i, m, M.data[i][m] / M.data[m][m]);
	}
	return (R);
}
