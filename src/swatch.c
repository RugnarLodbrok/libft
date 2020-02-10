/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swatch.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksticks <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/10 16:01:33 by ksticks           #+#    #+#             */
/*   Updated: 2020/02/10 16:01:35 by ksticks          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <time.h>
#include "libft.h"

double	swatch_clock(clock_t *t0)
{
	clock_t	t;
	double	ret;

	t = clock();
	ret = (double)(t - *t0) / CLOCKS_PER_SEC;
	*t0 = t;
	return (ret);
}

double	swatch(void)
{
	static clock_t t0 = 0;

	return (swatch_clock(&t0));
}

void	swatch_print(void)
{
	ft_printf("swatch: %f\n", swatch());
}
