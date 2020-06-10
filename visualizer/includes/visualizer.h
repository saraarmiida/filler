/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visualizer.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spentti <spentti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 17:34:23 by spentti           #+#    #+#             */
/*   Updated: 2020/03/02 18:20:40 by spentti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VISUALIZER_H
# define VISUALIZER_H

# include "mlx.h"
# include "../../includes/filler.h"

# define WIDTH 1200
# define HEIGHT 800

typedef struct	s_visu
{
	char		**map;
	int			map_size_x;
	int			map_size_y;
	void		*mlx;
	void		*win;
	void		*img;
	int			bits_per_pixel;
	int			size_line;
	int			endian;
	int			height;
	int			width;
}				t_visu;

#endif