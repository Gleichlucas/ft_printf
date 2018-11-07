/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkunz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/07 14:35:03 by lkunz             #+#    #+#             */
/*   Updated: 2018/07/11 16:01:22 by lkunz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_checker(const char *needle, const char *haystack, size_t len)
{
	size_t i;

	i = 0;
	while (needle[i] && i < len)
	{
		if (needle[i] != haystack[i])
			return (NULL);
		i++;
	}
	if (needle[i] != '\0')
		return (NULL);
	return ((char *)haystack);
}

char		*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	char	*check;
	size_t	needle_len;

	check = NULL;
	if ((needle_len = ft_strlen(needle)) == 0)
		return ((char *)haystack);
	while (*haystack && len >= needle_len)
	{
		if (*needle == *haystack)
			check = ft_checker(needle, haystack, len);
		if (check)
			return (check);
		haystack++;
		len--;
	}
	return (NULL);
}
