/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksticks <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/15 18:30:47 by ksticks           #+#    #+#             */
/*   Updated: 2019/11/15 18:30:53 by ksticks          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "hash_table.h"

/*
** https://softwareengineering.stackexchange.com/questions/49550/which-hashing-algorithm-is-best-for-uniqueness-and-speed;
*/

static uint	pow_mod(uint a, uint b, uint m)
{
	uint r;

	r = 1;
	while (b--)
		r = (r * a) % m;
	return (r);
}

uint		hash_str_1(const char *s, const int prime)
{
	uint r;
	uint i;
	uint c;

	i = 0;
	r = 0;
	while ((c = (unsigned char)*s++))
		r = (r + (pow_mod(prime, i++, MAX_INT_PRIME) * c)
				% MAX_INT_PRIME) % MAX_INT_PRIME;
	return (r);
}

uint		hash_djb2(const char *str)
{
	uint r;
	uint c;

	r = 5381;
	while ((c = (unsigned char)*str++))
		r = (r << 5) + r + c;
	return (r);
}

uint		hash_djb2a(const char *str)
{
	uint r;
	uint c;

	r = 5381;
	while ((c = (unsigned char)*str++))
		r = (r << 5) ^ r ^ c;
	return (r);
}

uint		hash_sdbm(const char *str)
{
	uint r;
	uint c;

	r = 0;
	while ((c = (unsigned char)*str++))
		r = c + (r << 6) + (r << 16) - r;
	return (r);
}

uint		hash_lose_lose(const char *str)
{
	uint r;
	uint c;

	r = 0;
	while ((c = (unsigned char)*str++))
		r += c;
	return (r);
}

uint		hash_fnv1a(const char *s)
{
	uint r;
	uint c;

	r = 2166136261;
	while ((c = (unsigned char)*s++))
		r = (r ^ c) * 16777619;
	return (r);
}
