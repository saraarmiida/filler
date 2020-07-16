/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spentti <spentti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 10:05:05 by spentti           #+#    #+#             */
/*   Updated: 2020/07/16 18:27:52 by spentti          ###   ########.fr       */
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
	// print_to_file("count_score1");
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
	// print_to_file("try_place1");
	while (yp < i->piece_h)
	{
		xp = i->piece_off.x;
		xb = x;
		while (xp < i->piece_w)
		{
			// print_to_file("try_place2");
			// print_int_to_file(yp, xp);
			// print_map((const char **)i->piece, i->piece_h);
			if (i->piece[yp][xp] == '*')
			{
				// print_to_file("try_place3");
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
	// print_to_file("try_place4");
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
	print_to_file("find_place1");
	while (y < i->board_h)
	{
		x = 0;
		while (x < i->board_w)
		{
			if (try_place(i, x, y) == 0)
			{
				score = count_score(i, x, y);
				if (min_score == 0)
				{
					min_score = score;
					i->res.y = y;
					i->res.x = x;
				}
				else if (score < min_score)
				{
					min_score = score;
					i->res.y = y;
					i->res.x = x;
				}
			}
			x++;
		}
		y++;
	}
	print_to_file("find_place2");
}

void	place(t_info *i)
{
	i->res.y = 0;
	i->res.x = 0;
	find_place(i);
	i->res.x -= i->piece_off.x;
}
