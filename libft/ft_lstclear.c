/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tberube- <tberube-@student.42quebec.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 13:37:09 by tberube-          #+#    #+#             */
/*   Updated: 2021/11/02 14:22:09 by tberube-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*new;
	t_list	*free_new;

	if (!lst)
		return ;
	new = *lst;
	while (new)
	{
		free_new = new;
		new = new->next;
		ft_lstdelone(free_new, del);
	}
	*lst = 0;
}
