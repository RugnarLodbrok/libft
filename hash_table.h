#ifndef HASH_TABLE_H
# define HASH_TABLE_H

# include <limits.h>

# define MAX_UINT_PRIME 4294967291
# define MAX_INT_PRIME INT_MAX
# define HT_PRIME_1 163
# define HT_PRIME_2 199

typedef struct
{
	uint u;
	char s[5];
} u_uint_string;

typedef struct s_ht_item
{
	char *k;
	char *v;
	struct s_ht_item *next;
} t_ht_item;

typedef struct
{
	int base_size;
	int size;
	int count;
	t_ht_item **items;
	uint (*hash_f_str)(const char *s);
} t_ht;

void t_ht_init(t_ht *t, int base_size);
void t_ht_del(t_ht *t);
void t_ht_set(t_ht *t, const char *k, const char *v);
char *t_ht_get(t_ht *t, const char *k);
void t_ht_remove(t_ht *t, const char *k);
uint hash_fnv1a(const char *s);

#endif
