/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spentti <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/21 18:32:04 by spentti           #+#    #+#             */
/*   Updated: 2019/10/25 13:37:42 by spentti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		**ft_strsplit(char const *s, char c)
{
	int		i;
	int		j;
	int		y;
	char	**arr;

	if (!s || !c)
		return (NULL);
	if (!(arr = (char **)malloc(sizeof(char *) * (ft_wordcount(s, c) + 1))))
		return (NULL);
	i = 0;
	y = -1;
	while (++y < ft_wordcount(s, c))
	{
		j = 0;
		while (s[i] == c)
			i++;
		arr[y] = (char *)malloc(sizeof(char) * (ft_strclen(s, i, c) + 1));
		if (!arr[y])
			return (NULL);
		while (s[i] != c && s[i] != '\0')
			arr[y][j++] = s[i++];
		arr[y][j] = '\0';
	}
	arr[y] = 0;
	return (arr);
}
