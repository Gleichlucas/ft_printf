/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkunz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/07 13:15:09 by lkunz             #+#    #+#             */
/*   Updated: 2018/07/09 15:15:37 by lkunz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	src_s;
	size_t	dst_s;
	size_t	i;

	src_s = ft_strlen(src);
	dst_s = ft_strlen(dst);
	i = 0;
	if (dst_s > size)
		return (size + src_s);
	while (src[i] && dst_s + i + 1 < size)
	{
		dst[dst_s + i] = src[i];
		i++;
	}
	dst[dst_s + i] = '\0';
	return (dst_s + src_s);
}
