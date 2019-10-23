/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error_exit.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksticks <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/23 17:04:20 by ksticks           #+#    #+#             */
/*   Updated: 2019/10/23 17:04:23 by ksticks          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "ft_printf.h"
#include <stdarg.h>

void	ft_error_exit(const char *msg, ...)
{
	va_list ap;

	va_start(ap, msg);
	ft_printf_ap(2, msg, ap);
	ft_fprintf(2, "\n");
	va_end(ap);
	exit(1);
}
