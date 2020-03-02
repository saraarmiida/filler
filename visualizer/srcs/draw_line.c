/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_line.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spentti <spentti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 17:47:22 by spentti           #+#    #+#             */
/*   Updated: 2020/03/02 18:12:16 by spentti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/visualizer.h"

void	no_slope(t_line *line, t_info *i)
{
	mlx_pixel_put(i->mlx_ptr, i->win_ptr, line->start->x, line->start->y, i->color);
	if (line->start->y > line->end->y)
	{
		line->sign = -1;
		line->dy = -line->dy;
	}
	while (line->start->y != line->end->y)
	{
		line->start->y = line->start->y + line->sign;
		mlx_pixel_put(i->mlx_ptr, i->win_ptr, line->start->x, line->start->y, i->color);
	}
}

void	low_slope(t_line *line, t_info *i)
{
	int p;

	p = 2 * line->dy - line->dx;
	while (line->start->x != line->end->x)
	{
		if (p < 0)
		{
			line->start->x = line->start->x + line->xsign;
			mlx_pixel_put(i->mlx_ptr, i->win_ptr, line->start->x, line->start->y, i->color);
			p = p + (2 * line->dy);
		}
		else
		{
			line->start->x = line->start->x + line->xsign;
			line->start->y = line->start->y + line->sign;
			mlx_pixel_put(i->mlx_ptr, i->win_ptr, line->start->x, line->start->y, i->color);
			p = p + (2 * line->dy) - (2 * line->dx);
		}
	}
}

void	high_slope(t_line *line, t_info *i)
{
	int p;

	p = (2 * line->dx) - line->dy;
	while (line->start->y != line->end->y)
	{
		if (p < 0)
		{
			line->start->y = line->start->y + line->sign;
			mlx_pixel_put(i->mlx_ptr, i->win_ptr, line->start->x, line->start->y, i->color);
			p = p + (2 * line->dx);
		}
		else
		{
			line->start->x = line->start->x + line->xsign;
			line->start->y = line->start->y + line->sign;
			mlx_pixel_put(i->mlx_ptr, i->win_ptr, line->start->x, line->start->y, i->color);
			p = p + (2 * line->dx) - (2 * line->dy);
		}
	}
}

void	signs(t_line *line, int *m)
{
	*m = line->dy / line->dx;
	if (line->dy < 0)
	{
		line->sign = -1;
		line->dy = -line->dy;
	}
	if (line->dx < 0)
	{
		line->xsign = -1;
		line->dx = -line->dx;
	}
	if (*m < 0)
		*m = -*m;
}

int		draw_line(t_line *line, t_visu *info)
{
	int m;
	int c;

	line->sign = 1;
	line->xsign = 1;
	c = info->color;
	if (line->start->x == line->end->x)
		no_slope(line, info);
	else
	{
		signs(line, &m);
		mlx_pixel_put(info->mlx_ptr, info->win_ptr, line->start->x, line->start->y, c);
		if (m < 1 && m >= 0)
			low_slope(line, info);
		if (m >= 1)
			high_slope(line, info);
	}
	return (0);
}