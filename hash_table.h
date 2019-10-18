#ifndef HASH_TABLE_H
# define HASH_TABLE_H

typedef struct
{
	char *k;
	char *v;
} t_ht_item;

typedef struct
{
	int base_size;
	int size;
	int count;
	t_ht_item **items;
	t_ht_item null_item;
	int (*hash_f_str)(const char *s, int i);
} t_ht;

void t_ht_init(t_ht *t, int base_size);
void t_ht_del(t_ht *t);
void t_ht_set(t_ht *t, const char *k, const char *v);
char *t_ht_get(t_ht *t, const char *k);
void t_ht_remove(t_ht *t, const char *k);

#endif
