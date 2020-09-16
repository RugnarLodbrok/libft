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

# define BUFF_SIZE 1024*32
# define GNL_LAST_EMPTY_LINE_BEHAVIOUR 0

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

/* USAGE EXAMPLE

#include <stdio.h>
#include <fcntl.h>

int main() {
    int fd;
    int status;

	fd = open("data.txt", O_RDONLY);
	while ((status = get_next_line(fd, &s)) > 0)
	{
		printf("%s\n", s);
		free(s);
	}
	if (status < 0)
		printf("----ERROR----\n");
	else
		printf("-----END-----\n");
	return 0;
}

*/

#endif
