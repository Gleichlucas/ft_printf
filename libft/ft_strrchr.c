/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkunz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/07 14:11:14 by lkunz             #+#    #+#             */
/*   Updated: 2018/07/09 18:59:17 by lkunz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char *res;

	if (c == 0)
		return ((char *)(s + ft_strlen(s)));
	else
	{
		res = NULL;
		while (*s)
		{
			if (*s == (char)c)
				res = s;
			s++;
		}
		return ((char *)(res));
	}
	return (NULL);
}
