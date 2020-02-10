/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_pool.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksticks <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 17:12:41 by ksticks           #+#    #+#             */
/*   Updated: 2019/11/26 17:12:43 by ksticks          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "threading.h"
#include "libft.h"

static void	t_pool_worker_foo(void *p)
{
	t_tpool_worker *w;

	w = p;
	w->f(w->p, w->ti);
}

t_tpool		t_tpool_create(
		int n,
		void (*f)(void *p, t_thread_id ti),
		void *p)
{
	int				i;
	t_tpool			pool;
	t_tpool_worker	*w;

	pool.n = n;
	pool.workers = ft_memalloc(sizeof(t_tpool_worker) * n);
	i = -1;
	while (++i < n)
	{
		w = &pool.workers[i];
		ft_bzero(w, sizeof(t_tpool_worker));
		w->p = p;
		w->f = f;
		w->ti = (t_thread_id){i, n};
		w->thread = t_thread_create(t_pool_worker_foo, w);
	}
	return (pool);
}

void		t_pool_start(t_tpool *pool)
{
	int i;

	i = -1;
	while (++i < pool->n)
		t_thread_start(&pool->workers[i].thread);
}
