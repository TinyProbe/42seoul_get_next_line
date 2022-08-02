/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tkong <tkong@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/02 16:08:45 by tkong             #+#    #+#             */
/*   Updated: 2022/08/02 16:24:07 by tkong            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

#define BYTE	unsigned char
#define UNT_T	unsigned long long
#define UNTSIZE	8

static void	copy(long long p1, long long p2, size_t n);
static void	*ft_memcpy(void *dst, const void *src, size_t n);

char	*ft_strdup(const char *s1, size_t len)
{
	void	*res;

	res = malloc(len + 1);
	if (res)
		((char *) ft_memcpy(res, s1, len))[len] = '\0';
	return (res);
}

static void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	copy((long long) dst, (long long) src, n);
	return (dst);
}

static void	copy(long long p1, long long p2, size_t n)
{
	while (n >= UNTSIZE * 8)
	{
		((UNT_T *) p1)[0] = ((UNT_T *) p2)[0];
		((UNT_T *) p1)[1] = ((UNT_T *) p2)[1];
		((UNT_T *) p1)[2] = ((UNT_T *) p2)[2];
		((UNT_T *) p1)[3] = ((UNT_T *) p2)[3];
		((UNT_T *) p1)[4] = ((UNT_T *) p2)[4];
		((UNT_T *) p1)[5] = ((UNT_T *) p2)[5];
		((UNT_T *) p1)[6] = ((UNT_T *) p2)[6];
		((UNT_T *) p1)[7] = ((UNT_T *) p2)[7];
		p1 += UNTSIZE * 8;
		p2 += UNTSIZE * 8;
		n -= UNTSIZE * 8;
	}
	while (n >= UNTSIZE)
	{
		*(UNT_T *) p1 = *(UNT_T *) p2;
		p1 += UNTSIZE;
		p2 += UNTSIZE;
		n -= UNTSIZE;
	}
	while (n--)
		*(BYTE *) p1++ = *(BYTE *) p2++;
}
