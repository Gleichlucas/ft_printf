/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkunz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/07 22:46:12 by lkunz             #+#    #+#             */
/*   Updated: 2018/07/10 17:41:40 by lkunz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_itoa_size(int *n, int *negative)
{
	int cpy;
	int size;

	size = 2;
	if (*n < 0)
	{
		*n *= -1;
		*negative = 1;
		size++;
	}
	cpy = *n;
	while (cpy >= 10)
	{
		cpy /= 10;
		size++;
	}
	return (size);
}

char			*ft_itoa(int n)
{
	int			size;
	int			negative;
	char		*str;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	negative = 0;
	size = ft_itoa_size(&n, &negative);
	if (!(str = (char*)malloc(size)))
		return (NULL);
	str[--size] = '\0';
	while (--size > 0)
	{
		str[size] = n % 10 + '0';
		n /= 10;
	}
	if (negative)
		str[0] = '-';
	else
		str[0] = n % 10 + '0';
	return (str);
}
