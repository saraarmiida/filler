/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spentti <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 18:11:16 by spentti           #+#    #+#             */
/*   Updated: 2019/10/25 17:44:29 by spentti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *new;
	t_list *head;

	new = NULL;
	while (lst)
	{
		if (new)
		{
			new->next = f(lst);
			new = new->next;
			lst = lst->next;
		}
		else
		{
			if (!(new = (*f)(lst)))
				return (NULL);
			head = new;
			lst = lst->next;
		}
	}
	new->next = NULL;
	return (head);
}
