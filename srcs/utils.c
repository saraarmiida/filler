/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spentti <spentti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 16:47:43 by spentti           #+#    #+#             */
/*   Updated: 2020/08/19 16:32:23 by spentti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

/*
** Is_around checks if there is an integer 'a' anywhere around a point (x,y)
*/

int		is_around(t_info *i, int x, int y, int a)
{
	if (x + 1 < i->board_w && i->hmap[y][x + 1] == a)
		return (1);
	if (x + 1 < i->board_w && y + 1 < i->board_h && \
	i->hmap[y + 1][x + 1] == a)
		return (2);
	if (y + 1 < i->board_h && i->hmap[y + 1][x] == a)
		return (3);
	if (x - 1 >= 0 && y + 1 < i->board_h && i->hmap[y + 1][x - 1] == a)
		return (4);
	if (x - 1 >= 0 && i->hmap[y][x - 1] == a)
		return (5);
	if (x - 1 >= 0 && y - 1 >= 0 && i->hmap[y - 1][x - 1] == a)
		return (6);
	if (y - 1 >= 0 && i->hmap[y - 1][x] == a)
		return (7);
	if (x + 1 < i->board_w && y - 1 >= 0 && i->hmap[y - 1][x + 1] == a)
		return (8);
	return (0);
}

void	free_heat(int **arr, int h)
{
	int	i;

	i = 0;
	if (!arr)
		return ;
	while (i < h)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

void	free_piece(char **str)
{
	int		i;

	i = 0;
	while (str[i] != NULL)
	{
		ft_strdel(&str[i]);
		i++;
	}
	free(str);
	str = NULL;
}

void	exit_loop(t_info *i)
{
	free_heat(i->hmap, i->board_h);
	free_piece(i->piece);
	free(i);
	i = NULL;
	exit(1);
}
