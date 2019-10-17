/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksticks <ksticks@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/09 19:20:06 by ksticks           #+#    #+#             */
/*   Updated: 2019/09/20 13:57:07 by edrowzee         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft_compat.h"
#include "libft.h"

size_t	ft_putendl_fd(char *s, int fd)
{
	size_t r;

	r = write(fd, s, ft_strlen(s));
	r += ft_putchar_fd('\n', fd);
	return (r);
}
