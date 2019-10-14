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

void t_vec_scale(t_vec *v, double n)
{
	v->x *= n;
	v->y *= n;
	v->z *= n;
}

t_vec t_vec_mul(t_vec a, double n)
{
	t_vec r;

	r.x = a.x * n;
	r.y = a.y * n;
	r.z = a.z * n;
	return (r);
}

void t_vec_decay(t_vec *v, double x)
{
	double len;

	len = t_vec_len(*v);
	if (len <= x)
	{
		ft_bzero(v, sizeof(t_vec));
		return;
	}
	*v = t_vec_mul(*v, (len - x) / len);
}

t_vec t_vec_cross(t_vec a, t_vec b)
{
	t_vec r;

	r.x = a.y * b.z - a.z * b.y;
	r.y = a.z * b.x - a.x * b.z;
	r.z = a.x * b.y - a.y * b.x;
	return (r);
}

t_vec t_vec_transform(t_vec v, t_mat A)
{
	t_vec r;

	r.x = (A.data[0][0] * v.x + A.data[0][1] * v.y + A.data[0][2] * v.z) + A.data[0][3];
	r.y = (A.data[1][0] * v.x + A.data[1][1] * v.y + A.data[1][2] * v.z) + A.data[1][3];
	r.z = (A.data[2][0] * v.x + A.data[2][1] * v.y + A.data[2][2] * v.z) + A.data[2][3];
	return (r);
}
