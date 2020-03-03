/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spentti <spentti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 10:05:05 by spentti           #+#    #+#             */
/*   Updated: 2020/03/03 16:56:24 by spentti          ###   ########.fr       */
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
	while (yp < i->piece->h)
	{
		xp = i->piece_off.x;
		while (xp < i->piece->w)
		{
			score += i->board->data[y][x];
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
	while (yp < i->piece->h)
	{
		xp = i->piece_off.x;
		xb = x;
		while (xp < i->piece->w)
		{
			if (i->piece->data[yp][xp] == '*')
			{
				if (yb >= i->board->h)
					return (1);
				if (xb >= i->board->w)
					return (1);
				if (i->board->data[yb][xb] == -2)
					overlap += 1;
				if (overlap > 1)
					return (1);
				if (i->board->data[yb][xb] == -1)
					return (1);
			}
			x++;
			xp++;
		}
		y++;
		yp++;
	}
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

	x = 0;
	y = 0;
	min_score = 0;
	while (y < i->board->h)
	{
		x = 0;
		while (x < i->board->w)
		{
			if (!(try_place(i, x, y)))
			{
				if ((score = count_score(i, x, y)) < min_score)
				{
					min_score = score;
					i->res.y = y;
					i->res.x = x;
				}
				else if (min_score == 0)
				{
					min_score = score;
					i->res.y = y;
					i->res.x = x;
				}
			}
		}
	}
}

void	place(t_info *i)
{
	find_place(i);
	i->res.y -= i->piece_off.y;
	i->res.x -= i->piece_off.x;
}
