#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <unistd.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

typedef struct s_buf
{
    char    buf[BUFFER_SIZE];
    int     idx;
    int     fd;
}   t_buf;

char    *get_next_line(int fd);

#endif
