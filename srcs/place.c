/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   place.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spentti <spentti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/28 10:05:05 by spentti           #+#    #+#             */
/*   Updated: 2020/03/04 12:24:09 by spentti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

int		count_score(t_info *i, int x, int y)
{
	int	score;
	int xp;
	int yp;

	print_to_file("    				count score point 1");
	print_int_to_file(x, y);
	yp = i->piece_off.y;
	score = 0;
	print_to_file("    				count score point 2");
	while (yp < i->piece_h)
	{
		print_to_file("    				count score point 3");
		print_int_to_file(x, y);
		xp = i->piece_off.x;
		while (xp < i->piece_w)
		{
			print_to_file("    				count score point 4");
			print_int_to_file(x, y);
			if (i->piece[yp][xp] == '*')
				score += i->hmap[y][x];
			xp++;
			x++;
		}
		yp++;
		y++;
	}
	print_to_file("    				count score point 5");
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
	print_to_file("    				try place point 1");
	while (yp < i->piece_h)
	{
		print_to_file("    				try place point 2");
		xp = i->piece_off.x;
		xb = x;
		while (xp < i->piece_w)
		{
			print_to_file("    				try place point 3");
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
	print_to_file("    				try place point 3");
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
	print_to_file("    			find place point 1");
	while (y < i->board_h)
	{
		x = 0;
		while (x < i->board_w)
		{
			// print_to_file("    			find place point 2");
			if (try_place(i, x, y) == 0)
			{
				print_to_file("    			find place point 3");
				score = count_score(i, x, y);
				print_to_file("    			find place point 3.2");
				if (min_score == 0)
				{
					print_to_file("    			find place point 4");
					min_score = score;
					i->res.y = y;
					i->res.x = x;
				}
				else if (score < min_score)
				{
					print_to_file("    			find place point 5");
					min_score = score;
					i->res.y = y;
					i->res.x = x;
				}
				print_to_file("    			find place point 5.2");
			}
			x++;
		}
		y++;
	}
	print_to_file("    			find place point 6");
}

void	place(t_info *i)
{
	print_to_file("    		place point 1");
	i->res.y = 0;
	i->res.x = 0;
	find_place(i);
	print_to_file("    		place point 2");
	i->res.y -= i->piece_off.y;
	i->res.x -= i->piece_off.x;
	print_to_file("    		place point 3");
	print_to_file("\n\nRESULT:");
	print_int_to_file(i->res.y, i->res.x);
}
