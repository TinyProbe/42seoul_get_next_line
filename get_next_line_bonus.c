/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkong <tkong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 16:08:39 by tkong             #+#    #+#             */
/*   Updated: 2022/08/11 13:06:28 by tkong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static t_buf	*find_buf(t_buf *buf, int fd);
static int		fill_buf(t_buf *buf);

char	*get_next_line(int fd)
{
	static t_buf	buf[MAX_FILE];
	t_buf			*cur;
	char			str[MAX_LEN];
	int				idx;

	if (fd < 0)
		return (0);
	cur = buf;
	if (fd)
		cur = find_buf(buf + 1, fd);
	idx = 0;
	while (1)
	{
		if (cur->idx == cur->len && !fill_buf(cur))
		{
			if (idx)
				return (ft_strdup(str, idx));
			return (0);
		}
		str[idx++] = cur->buf[cur->idx++];
		if (str[idx - 1] == '\n')
			return (ft_strdup(str, idx));
	}
}

static t_buf	*find_buf(t_buf *buf, int fd)
{
	while (buf->fd && buf->fd != fd)
		++buf;
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
