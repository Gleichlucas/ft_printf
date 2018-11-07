/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkunz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/06 15:58:02 by lkunz             #+#    #+#             */
/*   Updated: 2018/07/11 15:56:48 by lkunz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	unsigned int	i;
	size_t			len;
	char			*s1;

	i = 0;
	if (!s)
		return (NULL);
	if (!s[i])
		return ((char *)s);
	len = ft_strlen(s);
	s1 = (char *)s;
	while (s1[i] == ' ' || s1[i] == '\n' || s1[i] == '\t')
		i++;
	if (i == (unsigned int)len)
		return (ft_strnew(0));
	len--;
	while (s1[len] == ' ' || s1[len] == '\n' || s1[len] == '\t')
		len--;
	len++;
	s1 = ft_strsub(s, i, len - (size_t)i);
	return (s1);
}
