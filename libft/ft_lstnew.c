/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: lkunz <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/11 09:42:05 by lkunz             #+#    #+#             */
/*   Updated: 2018/07/11 10:29:41 by lkunz            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list *head;

	if (!(head = (t_list *)malloc(sizeof(t_list))))
		return (NULL);
	if (!content)
	{
		head->content = NULL;
		head->content_size = 0;
	}
	else
	{
		head->content = malloc(content_size);
		ft_memmove(head->content, content, content_size);
		head->content_size = content_size;
	}
	head->next = NULL;
	return (head);
}
