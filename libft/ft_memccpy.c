/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkunz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/07 08:34:15 by lkunz             #+#    #+#             */
/*   Updated: 2018/07/07 08:48:14 by lkunz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	size_t			i;
	unsigned char	*csrc;
	unsigned char	*cdst;

	i = 0;
	csrc = (unsigned char *)src;
	cdst = (unsigned char *)dst;
	while (i < n)
	{
		*(cdst + i) = *(csrc + i);
		if (*(csrc + i) == (unsigned char)c)
			return (dst + i + 1);
		i++;
	}
	return (NULL);
}
