/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spentti <spentti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 17:39:55 by spentti           #+#    #+#             */
/*   Updated: 2020/03/02 19:11:50 by spentti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/visualizer.h"

void	init_struct(t_visu *p)
{
	p->height = 0;
	p->width = 0;
}

int	main(void)
{
	t_visu	*p;

	if (!(p = (t_visu *)malloc(sizeof(t_visu))))
		return (1);
	init_struct(p);
	p->mlx_ptr = mlx_init();
	p->win_ptr = mlx_new_window(p->mlx_ptr, WIDTH, HEIGHT, "Filler");
	p->img_ptr = mlx_new_image(p->mlx_ptr, WIDTH, HEIGHT);
	
	mlx_loop(p->mlx_ptr);
	return (0);
}