/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksticks <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/26 17:12:34 by ksticks           #+#    #+#             */
/*   Updated: 2019/11/26 17:12:36 by ksticks          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "threading.h"

static THREAD_F_TYPE t_thread_func(void *p)
{
	t_thread *t;

	t = p;
	t->f(t->p);
	return (0);
}

t_thread t_thread_create(void (*f)(void *p), void *p)
{
	t_thread t;
	t.handle = 0;
	t.is_started = 0;
	t.is_finished = 0;
	t.f = f;
	t.p = p;
	return (t);
}

int t_thread_start(t_thread *t)
{
#ifdef _WIN32
	t->handle = CreateThread(
			NULL,
			0,
			t_thread_func,
			t,
			0,
			NULL);
	if (t->handle)
		t->is_started = 1;
	return t->is_started;
#else
	if (!pthread_create(
			&t->handle,
			NULL,
			t_thread_func,
			t))
		t->is_started = 1;
	return t->is_started;
#endif
}

int t_thread_wait(t_thread *t, int millis)
{
#ifdef _WIN32
	DWORD ret;

	ret = WaitForSingleObject(t->handle, millis);
	if (ret == WAIT_TIMEOUT)
		return 0;
	return 1;
#else
	(void)millis;
	pthread_join(t->handle, NULL);
	return (1);
#endif
}

