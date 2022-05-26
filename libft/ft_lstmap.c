/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tberube- <tberube-@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 14:30:36 by tberube-          #+#    #+#             */
/*   Updated: 2021/11/03 15:36:10 by tberube-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*first;
	t_list	*node;

	first = NULL;
	node = NULL;
	while (lst)
	{
		if (node)
		{
			node->next = ft_lstnew(f(lst->content));
			node = node->next;
		}
		else
			node = ft_lstnew(f(lst->content));
		if (!first)
			first = node;
		if (!node)
		{
			ft_lstclear(&first, del);
			return (NULL);
		}
		lst = lst->next;
	}
	return (first);
}
