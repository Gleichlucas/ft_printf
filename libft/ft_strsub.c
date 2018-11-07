/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkunz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/06 14:51:34 by lkunz             #+#    #+#             */
/*   Updated: 2018/07/09 19:58:33 by lkunz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	char			*substr;

	i = 0;
	if (!s || start > ft_strlen(s) || !(substr = ft_strnew(len)))
		return (NULL);
	while (i < len)
	{
		substr[i] = s[start + i];
		i++;
	}
	return (substr);
}
