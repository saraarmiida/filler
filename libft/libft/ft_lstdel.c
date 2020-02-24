/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spentti <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 17:03:18 by spentti           #+#    #+#             */
/*   Updated: 2019/10/24 18:04:42 by spentti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *list;
	t_list *nextlist;

	list = *alst;
	while (list != NULL)
	{
		nextlist = list->next;
		(*del)(list->content, list->content_size);
		free(list);
		list = nextlist;
	}
	*alst = NULL;
}
