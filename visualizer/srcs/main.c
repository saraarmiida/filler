/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spentti <spentti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 17:39:55 by spentti           #+#    #+#             */
/*   Updated: 2020/07/14 18:24:07 by spentti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/visualizer.h"

int		loop_key_hook(t_visu *p)
{
	p->ret = mlx_get_data_addr(p->img, &(p->bits_per_pixel), \
	&(p->size_line), &(p->endian));
	readinput(p);
	draw_map(p);
	mlx_put_image_to_window(p->mlx, p->win, p->img, 0, 0);
	return (0);
}

void	init_struct(t_visu *p)
{
	p->height = 0;
	p->width = 0;
	p->map = NULL;
	p->map_size_x = 0;
	p->map_size_y = 0;
	p->pause = 0;
}

int		main(void)
{
	t_visu	*p;

	if (!(p = (t_visu *)malloc(sizeof(t_visu))))
		return (1);
	init_struct(p);
	p->mlx = mlx_init();
	p->win = mlx_new_window(p->mlx, WIDTH, HEIGHT, "Filler");
	p->img = mlx_new_image(p->mlx, WIDTH, HEIGHT);
	mlx_loop_hook(p->mlx, loop_key_hook, p);
	mlx_loop(p->mlx);
	return (0);
}
