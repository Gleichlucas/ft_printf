/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkunz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/07 08:06:18 by lkunz             #+#    #+#             */
/*   Updated: 2018/07/07 08:28:35 by lkunz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;
	char	*src_cpy;
	char	*dst_cpy;

	i = 0;
	src_cpy = (char *)src;
	dst_cpy = dst;
	while (i < n)
	{
		*(dst_cpy + i) = *(src_cpy + i);
		i++;
	}
	return (dst);
}
