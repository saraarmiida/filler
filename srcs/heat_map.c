/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heat_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spentti <spentti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 13:20:28 by spentti           #+#    #+#             */
/*   Updated: 2020/08/11 14:58:14 by spentti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

/*
** Locate players gives integer values describing if a spot is free,
**  or reserved by enemy or own player.
*/

void	locate_players(int y, t_info *i, char *line)
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
	// print_int_string(i->hmap[y], i->board_w);
	// print_int_string(i->hmap[0], i->board_w);
}

void		heat_map(t_info *i)
{
	int	x;
	int y;
	int a;

	a = -1;
	while (a < i->board_w || a < i->board_h)
	{
		y = 0;
		while (y < i->board_h)
		{
			x = 0;
			while (x < i->board_w)
			{
				if (i->hmap[y][x] == 0)
					if (is_around(i, x, y, a))
					{
						if (a == -1)
							a++;
						i->hmap[y][x] = a + 1;
					}
				x++;
			}
			y++;
		}
		a++;
	}
}
