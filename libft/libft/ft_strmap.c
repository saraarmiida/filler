/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spentti <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 13:06:12 by spentti           #+#    #+#             */
/*   Updated: 2019/10/25 13:38:16 by spentti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char	*fresh;
	int		i;

	if (!s || !f)
		return (NULL);
	if (!(fresh = (char *)ft_memalloc(ft_strlen(s) + 1)))
		return (NULL);
	i = 0;
	if (!s || !f)
		return (0);
	while (s[i] != '\0')
	{
		fresh[i] = (*f)(s[i]);
		i++;
	}
	fresh[i] = '\0';
	return (fresh);
}
