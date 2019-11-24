#include "libft.h"

void	t_arrayi_init(t_arrayi *a)
{
	a->size = 4;
	a->count = 0;
	a->data = malloc(a->size * sizeof(int));
}

int		t_arrayi_get(t_arrayi *a, int i, int default_v)
{
	if (i >= a->count)
		return (default_v);
	return a->data[i];
}

static void	*t_arrayi_extend(t_arrayi *a)
{
	a->size *= 2;
	a->data = ft_realloc(a->data,
						 a->size * sizeof(int),
						 a->count * sizeof(int));
	return (a->data);
}

int			t_arrayi_push(t_arrayi *a, int v)
{
	if (a->count == a->size - 1)
		if (!t_arrayi_extend(a))
			return (0);
	a->data[a->count] = v;
	return ++a->count;
}

void		t_arrayi_del(t_arrayi *a)
{
	free(a->data);
}
