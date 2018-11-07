/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkunz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/11 12:39:54 by lkunz             #+#    #+#             */
/*   Updated: 2018/07/11 15:59:10 by lkunz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *lst;
	t_list *tmp;

	if (!alst || !*alst)
		return ;
	lst = *alst;
	if (del)
	{
		while (lst)
		{
			tmp = lst->next;
			ft_lstdelone(&lst, del);
			lst = tmp;
		}
	}
	*alst = NULL;
}
