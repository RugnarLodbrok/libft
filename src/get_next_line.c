/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ksticks <ksticks@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/12 20:26:41 by ksticks           #+#    #+#             */
/*   Updated: 2019/09/17 19:29:07 by ksticks          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "libft.h"
#include "get_next_line.h"

int		do_chunk(t_buff *buff, char *chunk, size_t chunk_size, char **ptr)
{
	size_t	line_size;

	*ptr = ft_memchr(chunk, '\n', chunk_size);
	if (*ptr)
	{
		line_size = *ptr - chunk;
		CHECK0RET0(!line_size || t_buff_add_len(buff, line_size));
		ft_memcpy(buff->data + buff->len - line_size, chunk, line_size);
		ft_bzero(chunk, line_size + 1);
	}
	else
	{
		CHECK0RET0(!chunk_size || t_buff_add_len(buff, chunk_size));
		ft_memcpy(buff->data + buff->len - chunk_size, chunk, chunk_size);
		ft_bzero(chunk, chunk_size);
	}
	return (1);
}


int		do_chunk_remainder(t_buff *buff, t_gnl_state *s)
{
	size_t chunk_size;

	chunk_size = BUFF_SIZE;
	if (s->cursor)
		chunk_size -= s->cursor - s->chunk + 1;
	if (s->end_cursor)
		chunk_size = s->end_cursor - (s->chunk + BUFF_SIZE - chunk_size);
	if (s->cursor && s->cursor < s->chunk + BUFF_SIZE - 1)
	{
		CHECK0RET1(do_chunk(buff, s->cursor + 1, chunk_size, &(s->cursor)));
		if (s->cursor)
			return (1);
	}
	return (0);
}

int		do_next_reads(int fd, t_buff *b, t_gnl_state *s)
{
	int i;

	while (1)
	{
		i = read(fd, s->chunk, BUFF_SIZE);
		if (i < 0)
		{
			free(b->data);
			return (-1);
		}
		if (!i)
		{
			if (b->len)
				return (1);
			return (0);
		}
		if (i < BUFF_SIZE)
			s->end_cursor = s->chunk + i;
		else
			s->end_cursor = 0;
		CHECK0RET1(do_chunk(b, s->chunk, i, &(s->cursor)));
		if (s->cursor)
			return (1);
	}
}

t_gnl_state	*gnl_state_get(t_list **lst, const int fd)
{
	t_list *e;
	t_gnl_state *s;

	e = *lst;
	while (e)
	{
		if (((t_gnl_state *)(e->content))->fd == fd)
			return (e->content);
		e = e->next;
	}
	CHECK0RET0(s = malloc(sizeof(t_gnl_state)));
	ft_memset(s->chunk, '0', BUFF_SIZE);
	s->fd = fd;
	s->cursor = 0;
	s->end_cursor = 0;
	if (!(e = ft_lstnew(s, sizeof(t_gnl_state))))
	{
		free(s);
		return (0);
	}
	ft_lstadd(lst, e);
	return (e->content);
}

void	gnl_state_remove(t_list **lst, const int fd)
{
	t_list	*ptr;
	t_list	*prev;
	t_list	*for_delete;

	prev = 0;
	ptr = *lst;
	while (ptr)
	{
		if (((t_gnl_state*)(ptr->content))->fd == fd)
		{
			if (!prev)
				*lst = ptr->next;
			else
				prev->next = ptr->next;
			for_delete = ptr;
			ptr = ptr->next;
			free(for_delete->content);
			free(for_delete);
		}
		else
		{
			prev = ptr;
			ptr = ptr->next;
		}
	}
}

int		terminate(t_buff *b, char **line, int return_val)
{
	b->data[b->len] = 0;
	*line = b->data;
	return (return_val);
}

int		get_next_line(const int fd, char **line)
{
	static t_list		*state_lst;
	t_gnl_state			*state;
	t_buff				buff;
	int					ret;

	CHECK0RET1(state = gnl_state_get(&state_lst, fd))
	CHECK0RET1(t_buff_init(&buff, 16))
	CHECK0RET1(line)
	if (do_chunk_remainder(&buff, state))
		return (terminate(&buff, line, 1));
	ret = do_next_reads(fd, &buff, state);
	if (ret > 0)
		return (terminate(&buff, line, 1));
	if (ret == 0)
		gnl_state_remove(&state_lst, fd);
	return (ret);
}
