/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksticks <ksticks@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 19:20:08 by ksticks           #+#    #+#             */
/*   Updated: 2019/09/17 19:13:05 by ksticks          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_putnbr_fd(int nb, int fd)
{
	char buff[12];

	ft_itoa_stack(buff, nb, 10);
	return (ft_putstr_fd(buff, fd));
}
