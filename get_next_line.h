/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkong <tkong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 16:08:35 by tkong             #+#    #+#             */
/*   Updated: 2022/08/11 13:06:04 by tkong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1024
# endif

# define MAX_FILE 10000
# define MAX_LEN 500000

# include <unistd.h>
# include <stdlib.h>

typedef struct s_buf
{
	char	buf[BUFFER_SIZE];
	int		idx;
	int		len;
	int		fd;
}	t_buf;

char	*get_next_line(int fd);
char	*ft_strdup(const char *s1, size_t len);

#endif
