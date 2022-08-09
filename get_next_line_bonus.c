/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkong <tkong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 16:08:39 by tkong             #+#    #+#             */
/*   Updated: 2022/08/03 13:19:29 by tkong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static int	fill_buf(t_buf *buf, int fd);

char	*get_next_line(int fd)
{
	static t_buf	buf[INT_MAX];
	char			str[MAX_LENGTH];
	int				idx;

	if (fd < 0)
		return (0);
	idx = 0;
	while (1)
	{
		if (buf[fd].idx == buf[fd].len && !fill_buf(buf, fd))
		{
			if (idx)
				return (ft_strdup(str, idx));
			return (0);
		}
		str[idx++] = buf[fd].buf[buf[fd].idx++];
		if (str[idx - 1] == '\n')
			return (ft_strdup(str, idx));
	}
}

static int	fill_buf(t_buf *buf, int fd)
{
	buf[fd].idx = 0;
	buf[fd].len = read(fd, buf[fd].buf, BUFFER_SIZE);
	if (buf[fd].len <= 0)
	{
		buf[fd].idx = buf[fd].len;
		return (0);
	}
	return (1);
}
