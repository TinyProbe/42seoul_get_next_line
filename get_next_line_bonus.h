/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkong <tkong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 16:08:42 by tkong             #+#    #+#             */
/*   Updated: 2022/08/05 13:08:49 by tkong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10000
# endif

# define MAX_FILE 10000
# define MAX_LENGTH 1000000

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
