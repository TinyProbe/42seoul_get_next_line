#include "get_next_line_bonus.h"

static t_buf    *get_buf(t_buf *buf, int fd);

char    *get_next_line(int fd)
{
    static t_buf    buf[1000];
    t_buf           *cur;
    char            str[100000];
    int             idx;

    cur = buf;
    if (fd)
        cur = get_buf(buf + 1, fd);
    idx = 0;
    while ()
    {

    }
}

static t_buf    *get_buf(t_buf *buf, int fd)
{
    while (buf->fd && buf->fd != fd)
        ++buf;
    buf->fd = fd;
    return (buf);
}
