/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spentti <spentti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/19 16:34:56 by spentti           #+#    #+#             */
/*   Updated: 2020/08/19 19:39:38 by spentti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/visualiser.h"

/*
** Draw_background sets the whole background to grey color.
*/

void			draw_background(t_env *p)
{
	int		i;

	i = 0;
	while (i < (HEIGHT * WIDTH * 4))
	{
		(p->ret)[i] = 52;
		(p->ret)[i + 1] = 52;
		(p->ret)[i + 2] = 52;
		(p->ret)[i + 3] = 0;
		i += 4;
	}
}

/*
** Tug_of_war creates a block where you can see in real time which player
** is winning.
*/

static void		tug_of_war(t_env *p)
{
	float	scorep1;
	float	scorep2;

	calc_score(p);
	scorep1 = p->scorep1 / (p->scorep1 + p->scorep2);
	scorep2 = p->scorep2 / (p->scorep1 + p->scorep2);
	modif_color(238, 152, 12, p);
	p->size.x = 300 * scorep1;
	p->size.y = 15;
	draw_rectangle((WIDTH / 2) - 150, 120, p);
	modif_color(81, 172, 154, p);
	p->size.x = 300 * scorep2;
	draw_rectangle((WIDTH / 2) - 150 + (300 * scorep1), 120, p);
	modif_color(0, 0, 0, p);
	p->size.x = 1;
	draw_rectangle(WIDTH / 2, 120, p);
}

/*
** Based on the saved map, draw_map draws either a black square if
** spot is empty, or a colored square in the color of the player.
*/

static void		draw_map(t_env *p)
{
	int		y;
	int		x;
	int		s;
	t_size	off;

	s = ((WIDTH / 2) / (p->map_size_x)) + 2;
	p->size.x = s - 2;
	p->size.y = s - 2;
	off.x = (WIDTH - (p->map_size_x * s)) / 2;
	off.y = (HEIGHT - (p->map_size_y * s)) / 2 + p->map_size_y;
	y = -1;
	while (++y < p->map_size_y)
	{
		x = -1;
		while (++x < p->map_size_x)
		{
			if (p->map[y][x] == '.')
				modif_color(0, 0, 0, p);
			else if (p->map[y][x] == 'X' || p->map[y][x] == 'x')
				modif_color(81, 172, 154, p);
			else if (p->map[y][x] == 'O' || p->map[y][x] == 'o')
				modif_color(238, 152, 12, p);
			draw_rectangle(s * x + off.x, y * s + off.y, p);
		}
	}
}

void			draw(t_env *p)
{
	draw_background(p);
	tug_of_war(p);
	draw_map(p);
}
