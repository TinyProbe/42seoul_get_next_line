/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkong <tkong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 16:08:11 by tkong             #+#    #+#             */
/*   Updated: 2022/08/11 13:06:23 by tkong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static t_file *find(t_file *file, int fd)
{
  while (file->fd && file->fd != fd)
    ++file;
  file->fd = fd;
  return (file);
}

static int fill(t_file *file)
{
  file->len = read(file->fd, file->buf, BUFFER_SIZE);
  file->idx = 0;
  if (file->len <= 0)
  {
    file->idx = file->len;
    return (0);
  }
  return (1);
}

static int pulchr(char *buf, t_file *f, unsigned long *idx)
{
  if (f->idx >= f->len && fill(f) == 0)
  {
    if (*idx > 0)
      return (2);
    else
      return (1);
  }
  buf[(*idx)++] = f->buf[f->idx++];
  if (buf[*idx - 1] == '\n')
    return (2);
  return (0);
}

static void *ft_memdup(void const *p, unsigned long size)
{
  void *rtn;

  rtn = (void *)malloc(size);
  while (size--)
    ((char *)rtn)[size] = ((char *)p)[size];
  return (rtn);
}

char *get_next_line(int fd)
{
  static t_file file[MAX_FILE];
  char buf[MAX_LEN];
  t_file *f;
  unsigned long idx;
  unsigned long sel;

  f = file;
  idx = 0;
  if (fd > 0)
    f = find(file + 1, fd);
  while (1)
  {
    sel = pulchr(buf, f, &idx);
    if (sel == 1)
      return ((char *)0);
    else if (sel == 2)
      return ((char *)ft_memdup(buf, idx));
  }
}
