/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ajacinto <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/18 07:18:59 by ajacinto          #+#    #+#             */
/*   Updated: 2024/05/18 07:19:00 by ajacinto         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*begin;
	t_list	*current;

	if (!lst || !f || !(*del))
		return (NULL);
	begin = ft_lstnew((*f)(lst->content));
	if (!begin)
		return (NULL);
	current = begin;
	lst = lst->next;
	while (lst)
	{
		current->next = ft_lstnew((*f)(lst->content));
		if (!current->next)
		{
			ft_lstclear(&begin, (*del));
			return (NULL);
		}
		current = current->next;
		lst = lst->next;
	}
	return (begin);
}
