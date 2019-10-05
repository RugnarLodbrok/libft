#include "libft.h"
#include "ft_linalg.h"

t_vec t_vec_add(t_vec a, t_vec b)
{
	a.x += b.x;
	a.y += b.y;
	a.z += b.z;
	return (a);
}

double t_vec_len(t_vec v)
{
	return (ft_sqrt((v.x) * (v.x) + (v.y) * (v.y) + (v.z) * (v.z)));
}

t_vec *t_vec_normalize(t_vec *v)
{
	double len;

	len = t_vec_len(*v);
	if (len)
	{
		v->x /= len;
		v->y /= len;
		v->z /= len;
	}
	else
	{
		v->x = 0;
		v->y = 0;
		v->z = 1;
	}
	return (v);
}

double t_vec_dot(t_vec a, t_vec b)
{
	return (a.x * b.x + a.y * b.y + a.z * b.z);
}

t_vec t_vec_mul(t_vec a, double n)
{
	t_vec r;

	r.x = a.x * n;
	r.y = a.y * n;
	r.z = a.z * n;
	return (r);
}

t_vec t_vec_cross(t_vec a, t_vec b)
{
	t_vec r;

	r.x = a.y * b.z - a.z * b.y;
	r.y = a.z * b.x - a.x * b.z;
	r.z = a.x * b.y - a.y * b.x;
	return (r);
}

