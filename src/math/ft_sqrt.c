/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksticks <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/18 18:09:45 by ksticks           #+#    #+#             */
/*   Updated: 2019/09/18 18:09:47 by ksticks          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int ft_sqrt_int(int nb)
{
	int r;
	int div;
	int avg;

	if (nb < 1)
		return (0);
	r = 1;
	while (1)
	{
		div = nb / r;
		avg = (r + div) / 2;
		if (avg == r || div == avg)
			break;
		r = avg;
	}
	return (avg);
}

int ceil_div(int a, int b)
{
	return (a + b - 1) / b;
}

int ft_sqrt_ceil(int nb)
{
	int r;
	int div;
	int avg;

	nb--;
	if (nb < 1)
		return (0);
	r = 1;
	while (1)
	{
		div = ceil_div(nb, r);
		avg = ceil_div(r + div, 2);
		if (avg == r || div == avg)
			break;
		r = avg;
	}
	return (avg);
}
