/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_abs.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksticks <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/17 15:53:04 by ksticks           #+#    #+#             */
/*   Updated: 2019/10/17 15:53:05 by ksticks          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_math.h"

int		ft_abs(int a)
{
	if (a < 0)
		return (-a);
	return (a);
}

REAL	ft_fabs(REAL a)
{
	if (a < 0)
		return (-a);
	return (a);
}
