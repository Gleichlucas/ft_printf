/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkunz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/07 09:46:16 by lkunz             #+#    #+#             */
/*   Updated: 2018/07/11 15:42:13 by lkunz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t		i;
	char		*src_cpy;
	char		*dst_cpy;
	int			lenc;

	lenc = (int)len;
	i = 0;
	src_cpy = (char *)src;
	dst_cpy = (char *)dst;
	if (dst_cpy < src_cpy)
	{
		while (i < len)
		{
			*(dst_cpy + i) = *(src_cpy + i);
			i++;
		}
	}
	else
	{
		while (--lenc >= 0)
			*(dst_cpy + lenc) = *(src_cpy + lenc);
	}
	return (dst);
}
