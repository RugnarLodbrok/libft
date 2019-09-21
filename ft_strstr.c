/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksticks <ksticks@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/06 17:28:03 by ksticks           #+#    #+#             */
/*   Updated: 2019/09/17 19:13:05 by ksticks          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strstr(const char *haystack, const char *needle)
{
	char *hay;
	char *nee;

	if (!*needle)
		return (char *)(haystack);
	while (*haystack++)
	{
		hay = (char *)haystack - 1;
		nee = (char *)needle;
		while (1)
		{
			if (!*hay)
				if (!*nee)
					return (char *)(haystack - 1);
				else
					return (0);
			else if (!*nee)
				return (char *)(haystack - 1);
			if (*hay != *nee)
				break ;
			hay++;
			nee++;
		}
	}
	return (0);
}
