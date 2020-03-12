/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heat_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spentti <spentti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 13:20:28 by spentti           #+#    #+#             */
/*   Updated: 2020/03/04 12:55:17 by spentti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

static void	locate_players(int *y, t_info *i, int **map)
{
	int x;

	x = 0;
	while (x < i->board->w)
	{
		if (i->board->data[*y][x] == '.')
			map[*y][x] = 0;
		else if (i->board->data[*y][x] == i->player.id || \
		i->board->data[*y][x] == i->player.id + 32)
			map[*y][x] = -2;
		else if (i->board->data[*y][x] == i->enemy.id || \
		i->board->data[*y][x] == i->enemy.id + 32)
			map[*y][x] = -1;
		x++;
	}
}

static int	create_heat_map(t_info *i)
{
	int	y;
	int	**map;

	y = 0;
	if (!(map = (int **)malloc(sizeof(int *) * i->board->h)))
		return (1);
	while (y < i->board->h)
	{
		if (!(map[y] = (int *)malloc(sizeof(int) * i->board->w)))
			return (1);
		locate_players(&y, i, map);
		y++;
	}
	i->hmap = map;
	return (0);
}

static void	init_heat_map(t_info *i)
{
	int	x;
	int y;

	y = 0;
	while (y < i->board->h)
	{
		x = 0;
		while (x < i->board->w)
		{
			if (i->hmap[y][x] == 0)
			{
				if (is_around(i, x, y, -1))
					i->hmap[y][x] += 1;
			}
			x++;
		}
		y++;
	}
}

static void	count_heat_map(t_info *i)
{
	int	x;
	int y;
	int a;

	a = 1;
	while (a < i->board->w || a < i->board->h)
	{
		y = 0;
		while (y < i->board->h)
		{
			x = 0;
			while (x < i->board->w)
			{
				if (i->hmap[y][x] == 0)
					if (is_around(i, x, y, a))
						i->hmap[y][x] = a + 1;
				x++;
			}
			y++;
		}
		a++;
	}
}

int			heat_map(t_info *i)
{
	create_heat_map(i);
	init_heat_map(i);
	count_heat_map(i);
	return (0);
}