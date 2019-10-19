#include "libft.h"
#include "hash_table.h"

// https://softwareengineering.stackexchange.com/questions/49550/which-hashing-algorithm-is-best-for-uniqueness-and-speed;
static uint pow_mod(uint a, uint b, uint m)
{
	uint r;

	r = 1;
	while (b--)
		r = (r * a) % m;
	return (r);
}

uint hash_str_1(const char *s, const int prime)
{
	uint r;
	uint i;
	uint c;

	i = 0;
	r = 0;
	while ((c = (unsigned char)*s++))
		r = (r + (pow_mod(prime, i++, MAX_INT_PRIME) * c
				 ) % MAX_INT_PRIME) % MAX_INT_PRIME;
	return (r);
}

uint hash_djb2(const char *str)
{
	uint r;
	uint c;

	r = 5381;
	while ((c = (unsigned char)*str++))
		r = (r << 5) + r + c; // r = r*33 + c
	return (r);
}

uint hash_djb2a(const char *str)
{
	uint r;
	uint c;

	r = 5381;
	while ((c = (unsigned char)*str++))
		r = (r << 5) ^ r ^ c;
	return (r);
}

uint hash_sdbm(const char *str)
{
	uint r;
	uint c;

	r = 0;
	while ((c = (unsigned char)*str++))
		r = c + (r << 6) + (r << 16) - r;
	return (r);
}

uint hash_lose_lose(const char *str)
{
	uint r;
	uint c;

	r = 0;
	while ((c = (unsigned char)*str++))
		r += c;
	return r;
}

uint hash_fnv1a(const char *s)
{
	uint r;
	uint c;

	r = 2166136261;
	while ((c = (unsigned char)*s++))
		r = (r ^ c) * 16777619;
	return (r);
}

uint ht_get_hash(const char *s, const int attempt)
{
	uint a;
	uint b;

	a = hash_str_1(s, HT_PRIME_1);
	b = hash_str_1(s, HT_PRIME_2);
	return (a + (attempt * (b + 1))) % MAX_INT_PRIME;
}
