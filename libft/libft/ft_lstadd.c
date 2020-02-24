/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spentti <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/24 17:21:17 by spentti           #+#    #+#             */
/*   Updated: 2019/10/24 18:04:23 by spentti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd(t_list **alst, t_list *new)
{
	if (new != NULL && *alst != NULL)
	{
		new->next = *alst;
		*alst = new;
	}
	else if (*alst == NULL)
		*alst = new;
}
