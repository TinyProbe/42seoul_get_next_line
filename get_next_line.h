/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkong <tkong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 16:08:35 by tkong             #+#    #+#             */
/*   Updated: 2022/08/05 13:08:40 by tkong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

# define MAX_LENGTH 8379365

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>

typedef struct s_buf
{
	char	buf[BUFFER_SIZE];
	int		idx;
	int		len;
}	t_buf;

char	*get_next_line(int fd);
char	*ft_strdup(const char *s1, size_t len);

#endif
