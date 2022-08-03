/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkong <tkong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 16:08:11 by tkong             #+#    #+#             */
/*   Updated: 2022/08/03 09:33:40 by tkong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static t_buf	*find_buf(t_buf *buf, int fd);
static int		fill_buf(t_buf *buf);

char	*get_next_line(int fd)
{
	static t_buf	buf[MAX_FILE];
	t_buf			*cur;
	char			str[MAX_LENGTH];
	int				idx;

	cur = buf;
	if (fd)
		cur = find_buf(buf + 1, fd);
	idx = 0;
	while (1)
	{
		if (cur->idx == cur->len && !fill_buf(cur))
			return (0);
		str[idx++] = cur->buf[cur->idx++];
		if (str[idx - 1] == '\n')
			return (ft_strdup(str, idx));
		if (!~str[idx - 1] || !str[idx - 1])
			return (ft_strdup(str, idx - 1));
	}
}

static t_buf	*find_buf(t_buf *buf, int fd)
{
	while (buf->fd && buf->fd != fd)
		++buf;
	if (!(buf->fd))
		buf->fd = fd;
	return (buf);
}

static int	fill_buf(t_buf *buf)
{
	buf->idx = 0;
	buf->len = read(buf->fd, buf->buf, BUFFER_SIZE);
	if (buf->len <= 0)
	{
		buf->idx = buf->len;
		return (0);
	}
	return (1);
}
