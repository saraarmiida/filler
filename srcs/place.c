/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spentti <spentti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 10:05:05 by spentti           #+#    #+#             */
/*   Updated: 2020/06/10 16:24:17 by spentti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

int		count_score(t_info *i, int x, int y)
{
	int	score;
	int xp;
	int yp;

	yp = i->piece_off.y;
	score = 0;
	while (yp < i->piece_h)
	{
		xp = i->piece_off.x;
		while (xp < i->piece_w)
		{
			if (i->piece[yp][xp] == '*')
				score += i->hmap[y][x];
			xp++;
			x++;
		}
		yp++;
		y++;
	}
	return (score);
}

int		try_place(t_info *i, int x, int y)
{
	int	xp;
	int	yp;
	int	xb;
	int	yb;
	int	overlap;

	yp = i->piece_off.y;
	xb = x;
	yb = y;
	overlap = 0;
	print_to_file("try1");
	while (yp < i->piece_h)
	{
		print_to_file("try2");
		xp = i->piece_off.x;
		xb = x;
		while (xp < i->piece_w)
		{
			print_to_file("try3");
			if (i->piece[yp][xp] == '*')
			{
				print_to_file("try4");
				if (yb >= i->board_h)
					return (1);
				if (xb >= i->board_w)
					return (1);
				if (i->hmap[yb][xb] == -2)
					overlap++;
				if (i->hmap[yb][xb] == -1)
					return (1);
			}
			xb++;
			xp++;
		}
		yb++;
		yp++;
	}
	print_to_file("try5");
	if (overlap != 1)
		return (1);
	return (0);
}

void	find_place(t_info *i)
{
	int	x;
	int	y;
	int	score;
	int	min_score;

	y = 0;
	min_score = 0;
	print_to_file("place2");
	while (y < i->board_h)
	{
		x = 0;
		print_to_file("place3");
		while (x < i->board_w)
		{
			print_to_file("place4");
			if (try_place(i, x, y) == 0)
			{
				print_to_file("place4.5");
				score = count_score(i, x, y);
				print_to_file("place5");
				if (min_score == 0)
				{
					print_to_file("place6");
					min_score = score;
					i->res.y = y;
					i->res.x = x;
				}
				else if (score < min_score)
				{
					print_to_file("place7");
					min_score = score;
					i->res.y = y;
					i->res.x = x;
				}

			}
			x++;
		}
		y++;
	}
}

void	place(t_info *i)
{
	i->res.y = 0;
	i->res.x = 0;
	print_to_file("place1");
	find_place(i);
	print_to_file("place5");
	i->res.x -= i->piece_off.x;
}
