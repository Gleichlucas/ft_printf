/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkunz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/07 18:20:15 by lkunz             #+#    #+#             */
/*   Updated: 2018/07/11 15:49:46 by lkunz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int		ft_wordcounter(char const *s, char c)
{
	char	flag;
	int		wordc;

	flag = 0;
	wordc = 0;
	while (*s)
	{
		if (*s != c)
		{
			if (!flag)
				wordc++;
			flag = 1;
		}
		if (*(s + 1) == '\0' || *(s + 1) == c)
			flag = 0;
		s++;
	}
	return (wordc);
}

static	char	*ft_wordcutter(char const *s, char c)
{
	char			*word;
	size_t			i;
	unsigned int	start;
	int				u;

	u = 0;
	i = 0;
	start = 0;
	while (s[u])
	{
		if (s[u] != c)
		{
			i++;
			if (s[u + 1] == '\0' || s[u + 1] == c)
			{
				word = ft_strsub(s, start, i);
				return (word);
			}
		}
		else
			start++;
		u++;
	}
	return (NULL);
}

char			**ft_strsplit(char const *s, char c)
{
	char	**arr;
	int		wordc;
	size_t	wordl;
	size_t	i;

	i = 0;
	if (s == NULL)
		return (NULL);
	wordc = ft_wordcounter(s, c);
	if (!(arr = (char **)malloc(sizeof(char *) * wordc + 1)))
		return (NULL);
	while (wordc > 0)
	{
		wordl = ft_strlen(ft_wordcutter(s, c));
		if (ft_wordcutter(s, c) && (*(arr + i) = (char *)malloc(wordl)))
			arr[i++] = ft_wordcutter(s, c);
		while (*s == c && *s)
			s++;
		while (*s != c && *s)
			s++;
		wordc--;
	}
	*(arr + i) = NULL;
	return (arr);
}
