/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heat_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spentti <spentti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 13:20:28 by spentti           #+#    #+#             */
/*   Updated: 2020/08/19 16:18:16 by spentti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

/*
** locate_players gives integer values describing if a spot is free,
** reserved by enemy or reserved by own player.
*/

void		locate_players(int y, t_info *i, char *line)
{
	int x;

	x = 4;
	while (x - 4 < i->board_w)
	{
		if (line[x] == '.')
			i->hmap[y][x - 4] = 0;
		else if (line[x] == i->player_id || line[x] == i->player_id + 32)
			i->hmap[y][x - 4] = -2;
		else if (line[x] == i->enemy_id || line[x] == i->enemy_id + 32)
			i->hmap[y][x - 4] = -1;
		x++;
	}
}

/*
** count_heat_map goes through the map giving free spots
** descending values according to how far they are from
** enemy pieces
*/

void	count_heat_map(t_info *i)
{
	int	x;
	int y;
	int a;

	a = 100;
	while (100 - a < i->board_w || 100 - a < i->board_h)
	{
		y = 0;
		while (y < i->board_h)
		{
			x = 0;
			while (x < i->board_w)
			{
				if (i->hmap[y][x] == 0)
					if (is_around(i, x, y, a))
						i->hmap[y][x] = a - 1;
				x++;
			}
			y++;
		}
		a--;
	}
}

/*
** heat_map sets the free spots right next to enemy pieces
** to the highest value of heatmap
*/

void		heat_map(t_info *i)
{
	int	x;
	int y;

	y = 0;
	while (y < i->board_h)
	{
		x = 0;
		while (x < i->board_w)
		{
			if (i->hmap[y][x] == 0)
				if (is_around(i, x, y, -1))
					i->hmap[y][x] = 100;
			x++;
		}
		y++;
	}
	count_heat_map(i);
}
