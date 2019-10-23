/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash_table.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksticks <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 17:53:45 by ksticks           #+#    #+#             */
/*   Updated: 2019/10/23 17:53:46 by ksticks          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HASH_TABLE_H
# define HASH_TABLE_H

# include <limits.h>

# define MAX_UINT_PRIME 4294967291
# define MAX_INT_PRIME INT_MAX
# define HT_PRIME_1 163
# define HT_PRIME_2 199
# define HT_MIN_SIZE 11

typedef struct	s_ht_item
{
	char				*k;
	char				*v;
	struct s_ht_item	*next;
}				t_ht_item;

typedef struct	s_ht
{
	int			size;
	int			count;
	t_ht_item	**items;
	uint		(*hash_f_str)(const char *s);
}				t_ht;

void			t_ht_init(t_ht *t, int size);
void			t_ht_del(t_ht *t);
void			t_ht_set(t_ht *t, const char *k, const char *v);
char			*t_ht_get(t_ht *t, const char *k);
void			t_ht_remove(t_ht *t, const char *k);
uint			hash_fnv1a(const char *s);
uint			hash_djb2(const char *str);
uint			hash_djb2a(const char *str);
uint			hash_sdbm(const char *str);
uint			hash_lose_lose(const char *str);

#endif
