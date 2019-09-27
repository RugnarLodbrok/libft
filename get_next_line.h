/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksticks <ksticks@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 17:38:36 by ksticks           #+#    #+#             */
/*   Updated: 2019/09/17 19:06:51 by ksticks          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFF_SIZE 256
# define GNL_LAST_EMPTY_LINE_BEHAVIOUR 1

typedef struct	s_gnl_iterator_state
{
	int		fd;
	char	chunk[BUFF_SIZE];
	char	*cursor;
	char	*end_cursor;
	size_t	chunk_size;
	int		file_ended;
}				t_gnl_state;

int				get_next_line(const int fd, char **line);

#endif
