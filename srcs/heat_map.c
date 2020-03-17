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
	// print_to_file("            locate point 1");
	while (x < i->board_w)
	{
		// print_int_to_file(*y);
		// print_to_file(i->board.data[*y + 1]);
		// print_to_file("            locate point 2");
		if (i->board[*y][x] == '.')
		{
			// print_to_file("            locate point 3");
			map[*y][x] = 0;
		}
		else if (i->board[*y][x] == i->player.id || \
		i->board[*y][x] == i->player.id + 32)
		{
			// print_to_file("            locate point 4");
			map[*y][x] = -2;
		}
		else if (i->board[*y][x] == i->enemy.id || \
		i->board[*y][x] == i->enemy.id + 32)
		{
			// print_to_file("            locate point 5");
			map[*y][x] = -1;
		}
		// print_to_file("            locate point 6");
		x++;
	}
}

static int	create_heat_map(t_info *i)
{
	int	y;
	int	**map;

	y = 0;
	// print_to_file("        create point 1");
	if (!(map = (int **)malloc(sizeof(int *) * i->board_h)))
		return (1);
	// print_to_file("        create point 2");
	while (y < i->board_h)
	{
		// print_to_file("        create point 3");
		if (!(map[y] = (int *)malloc(sizeof(int) * i->board_w)))
			return (1);
		// print_to_file("        create point 4");
		locate_players(&y, i, map);
		// print_to_file("        create point 5");
		y++;
	}
	// print_to_file("        create point 6");
	i->hmap = map;
	return (0);
}

static void	init_heat_map(t_info *i)
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
	// print_to_file("heat point 1");
	create_heat_map(i);
	// print_to_file("heat point 2");
	init_heat_map(i);
	// print_to_file("heat point 3");
	count_heat_map(i);
	// print_to_file("heat point 4");
	return (0);
}
