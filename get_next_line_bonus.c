/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkong <tkong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 16:08:39 by tkong             #+#    #+#             */
/*   Updated: 2022/08/02 16:26:15 by tkong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static t_buf	*get_buf(t_buf *buf, int fd);
static ssize_t	fill_buf(t_buf *buf);

char	*get_next_line(int fd)
{
	static t_buf	buf[MAX_FILE];
	t_buf			*cur;
	char			str[MAX_LENGTH];
	int				idx;

	cur = buf;
	if (fd)
		cur = get_buf(buf + 1, fd);
	idx = 0;
	while (1)
	{
		if (cur->idx == BUFFER_SIZE && fill_buf(cur) <= 0)
		{
			cur->idx = BUFFER_SIZE;
			return (0);
		}
		str[idx++] = cur->buf[cur->idx++];
		if (str[idx - 1] == '\n' || !~str[idx - 1] || !str[idx - 1])
			return (ft_strdup(str, idx));
	}
}

static t_buf	*get_buf(t_buf *buf, int fd)
{
	while (buf->fd && buf->fd != fd)
		++buf;
	if (!(buf->fd))
	{
		buf->fd = fd;
		buf->idx = BUFFER_SIZE;
	}
	return (buf);
}

static ssize_t	fill_buf(t_buf *buf)
{
	buf->idx = 0;
	return (read(buf->fd, buf->buf, BUFFER_SIZE));
}
