/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_memory.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksticks <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/11 20:31:23 by ksticks           #+#    #+#             */
/*   Updated: 2019/06/11 20:31:24 by ksticks          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	put_memory(const char *str, int size)
{
	int		i;
	char	c;

	i = 0;
	while (1)
	{
		c = *(str + i);
		if (c >= 32 && c <= 126)
			ft_putchar(c);
		else
			ft_putchar('.');
		i++;
		if (i == size)
			break ;
	}
}

static void	put_hex(uint v, int digits)
{
	unsigned int a;
	unsigned int b;

	if (!digits)
		return ;
	a = v / 16;
	b = v - a * 16;
	put_hex(a, digits - 1);
	if (b < 10)
		ft_putchar('0' + b);
	else
		ft_putchar('a' - 10 + b);
}

static void	put_shit(unsigned int i)
{
	if (!(i % 16))
	{
		put_hex(i, 8);
		put_memory(": ", 2);
	}
	else if (!(i % 2))
		ft_putchar(' ');
}

static void	put_end(void *addr, int tail_len)
{
	put_memory("  ", 2);
	put_memory((char*)(addr - 16), tail_len);
	ft_putchar('\n');
}

void		*ft_print_memory(void *addr, uint size)
{
	uint	i;
	int		tail_len;

	if (!size)
		return (addr);
	i = 0;
	while (1)
	{
		if (i && !(i % 16))
		{
			put_end(addr + i, tail_len);
			if (i >= size)
				break ;
		}
		put_shit(i);
		if (i < size)
		{
			put_hex((unsigned int)(*(char*)(addr + i)), 2);
			tail_len = i % 16 + 1;
		}
		else
			put_memory("  ", 2);
		i++;
	}
	return (addr);
}
