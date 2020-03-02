/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   heat_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spentti <spentti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 13:20:28 by spentti           #+#    #+#             */
/*   Updated: 2020/03/02 15:58:55 by spentti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

static void	locate_players(int *y, t_info *i)
{
	int x;

	x = 0;
	while (x < i->board->width)
	{
		if (i->board->data[*y][x] == '.')
			i->hmap[*y][x] = 0;
		else if (i->board->data[*y][x] == i->player.id || i->board->data[*y][x] == i->player.id + 32)
			i->hmap[*y][x] = -2;
		else if (i->board->data[*y][x] == i->enemy.id || i->board->data[*y][x] == i->enemy.id + 32)
			i->hmap[*y][x] = -1;
		x++;
	}
}

static int	create_heat_map(t_info *i)
{
	int	y;

	y = 0;
	if (!(i->hmap = (int **)malloc(sizeof(int *) * i->board->height)))
		return (1);
	while (y < i->board->height)
	{
		if (!(i->hmap[y] = (int *)malloc(sizeof(int) * i->board->width)))
			return (1);
		locate_players(&y, i);
		y++;
	}
	return (0);
}

int			is_around(t_info *i, int x, int y, int a)
{
	if (x + 1 < i->board->width && i->hmap[y][x + 1] == a)
		return (1);
	if (x + 1 < i->board->width && y + 1 < i->board->height && i->hmap[y + 1][x + 1] == a)
		return (1);
	if (y + 1 < i->board->height && i->hmap[y + 1][x] == a)
		return (1);
	if (x - 1 >= 0 && y + 1 < i->board->height && i->hmap[y + 1][x - 1] == a)
		return (1);
	if (x - 1 >= 0 && i->hmap[y][x - 1] == a)
		return (1);
	if (x - 1 >= 0 && y - 1 >= 0 && i->hmap[y - 1][x - 1] == a)
		return (1);
	if (y - 1 >= 0 && i->hmap[y - 1][x] == a)
		return (1);
	if (x + 1 < i->board->width && y - 1 >= 0 && i->hmap[y - 1][x + 1] == a)
		return (1);
	return (0);
}

static void	init_heat_map(t_info *i)
{
	int	x;
	int y;

	y = 0;
	while (y < i->board->height)
	{
		x = 0;
		while (x < i->board->width)
		{
			if (i->hmap[y][x] == 0)
			{
				if(is_around(i, x, y, -1))
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
	while (a < i->board->width || a < i->board->height)
	{
		y = 0;
		while (y < i->board->height)
		{
			x = 0;
			while (x < i->board->width)
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
