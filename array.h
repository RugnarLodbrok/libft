#ifndef ARRAY_H
# define ARRAY_H

typedef struct	s_array
{
	size_t	item_size;
	size_t	count;
	size_t	size;
	void	*data;
}				t_array;

typedef struct	s_arrayi
{
	size_t	count;
	size_t	size;
	int		*data;
}				t_arrayi;

void	t_array_init(t_array *a, size_t item_size);
void	*t_array_get(t_array *a, int i);
void	*t_array_push(t_array *a, void *content);
void	t_array_del(t_array *a);

void	t_arrayi_init(t_arrayi *a);
int		t_arrayi_get(t_arrayi *a, int i, int default_v);
int		t_arrayi_push(t_arrayi *a, int v);
void	t_arrayi_del(t_arrayi *a);

#endif