/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spentti <spentti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 10:05:05 by spentti           #+#    #+#             */
/*   Updated: 2020/07/30 19:58:45 by spentti          ###   ########.fr       */
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
		xp = 0;
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

	yp = 0;
	xb = x;
	yb = y;
	overlap = 0;
	while (yp < i->piece_h)
	{
		xp = 0;
		xb = x;
		while (xp < i->piece_w)
		{
			if (i->piece[yp][xp] == '*')
			{
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
	if (overlap != 1)
		return (1);
	return (0);
}

int		find_place(t_info *i)
{
	int	x;
	int	y;
	int	score;
	int	min_score;

	y = 0 - i->piece_off.y;
	min_score = 0;
	score = -1;
	while (y < i->board_h)
	{
		x = 0 - i->piece_off.x;
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
	if (score == -1)
		return (1);
	return (0);
}

int		place(t_info *i)
{
	i->res.y = 0;
	i->res.x = 0;
	if (find_place(i) == 1)
		return (1);
	return (0);
}
