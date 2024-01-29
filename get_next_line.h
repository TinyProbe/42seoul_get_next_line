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
#  define BUFFER_SIZE 512
# endif

# define MAX_FILE 10000
# define MAX_LEN 100000

# include <unistd.h>
# include <stdlib.h>

typedef struct s_file
{
  int fd;
  char buf[BUFFER_SIZE];
  int len;
  int idx;
} t_file;

char *get_next_line(int fd);

#endif
