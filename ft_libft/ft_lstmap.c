/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marianamestre <marianamestre@student.42    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/16 15:38:11 by mabrito-          #+#    #+#             */
/*   Updated: 2024/09/21 16:43:02 by marianamest      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*newnode;
	t_list	*newlist;

	if (lst == NULL)
		return (NULL);
	newlist = NULL;
	while (lst)
	{
		newnode = (t_list *)malloc(sizeof(t_list));
		if (!newnode)
		{
			ft_lstclear(&newlist, del);
			return (NULL);
		}
		newnode->content = f(lst->content);
		newnode->next = NULL;
		ft_lstadd_back(&newlist, newnode);
		lst = lst->next;
	}
	return (newlist);
}
