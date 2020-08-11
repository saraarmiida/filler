/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spentti <spentti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 10:05:05 by spentti           #+#    #+#             */
/*   Updated: 2020/08/11 14:23:16 by spentti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

int		count_score(t_info *i, int x, int y)
{
	int	score;
	int xp;
	int yp;

	yp = 0;
	score = 0;
	while (yp < i->piece_h)
	{
		xp = 0;
		while (xp < i->piece_w)
		{
			if (i->piece[yp][xp] == '*' && i->hmap[y + yp][x + xp] != -2)
				score += i->hmap[y + yp][x + xp];
			xp++;
		}
		yp++;
	}
	return (score);
}

int		try_place(t_info *i, int x, int y)
{
	int	xp;
	int	yp;
	int	overlap;

	yp = -1;
	overlap = 0;
	while (++yp < i->piece_h)
	{
		xp = -1;
		while (++xp < i->piece_w)
		{
			if (i->piece[yp][xp] == '*')
			{
				if (y + yp >= i->board_h || x + xp >= i->board_w \
				|| i->hmap[y + yp][x + xp] == -1)
					return (-1000);
				if (i->hmap[y + yp][x + xp] == -2)
					overlap++;
			}
		}
	}
	if (overlap != 1)
		return (-1000);
	return (count_score(i, x, y));
}

int		find_place(t_info *i)
{
	int	x;
	int	y;
	int	score;
	int	min_score;

	y = -1;
	min_score = -1000;
	score = -1000;
	while (++y < i->board_h)
	{
		x = -1;
		while (++x < i->board_w)
		{
			score = try_place(i, x, y);
			if (score != -1000 && (min_score == -1000 || score < min_score))
			{
				min_score = score;
				i->res.y = y;
				i->res.x = x;
			}
		}
	}
	return (min_score);
}

/*
** Initializes result coordinates and resets them with offset
*/

int		place(t_info *i)
{
	i->res.y = 0;
	i->res.x = 0;
	print_heat(i);
	if (find_place(i) == -1000)
		return (0);
	i->res.y -= i->piece_off.y;
	i->res.x -= i->piece_off.x;
	return (1);
}
