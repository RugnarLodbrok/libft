#ifndef THREADING_H
# define THREADING_H

# ifdef _WIN32
#  include <Windows.h>
#  define T_THREAD_ID HANDLE
#  define THREAD_F_TYPE DWORD WINAPI
# else
#  include <pthread.h>
#  define T_THREAD_ID pthread_t
#  define THREAD_F_TYPE void*
# endif

typedef struct
{
	int i;
	int c;
} t_thread_id;

typedef struct
{
	T_THREAD_ID handle;
	void (*f)(void *p);
	void *p;
	int is_started;
	int is_finished;
} t_thread;


typedef struct
{
	t_thread thread;
	t_thread_id ti;
	void (*f)(void *p, t_thread_id ti);
	void *p;
} t_tpool_worker;

typedef struct
{
	int n;
	t_tpool_worker *workers;
} t_tpool;

t_thread t_thread_create(void (*f)(void *p), void *p);
int t_thread_start(t_thread *t);
int t_thread_wait(t_thread *t, int millis);

t_tpool t_tpool_create(int n,
					   void (*f)(void *p, t_thread_id ti),
					   void *p);
void t_pool_start(t_tpool *pool);

#endif
