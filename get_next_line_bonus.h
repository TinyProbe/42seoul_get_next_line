#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# define MAX_FILE   100000000 / BUFFER_SIZE
# define MAX_LENGTH 100000

# include <unistd.h>
# include <stdlib.h>

typedef struct s_buf
{
    char    buf[BUFFER_SIZE];
    int     idx;
    int     fd;
}   t_buf;

char    *get_next_line(int fd);
char    *ft_strdup(const char *s1, size_t len);

#endif
