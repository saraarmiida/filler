/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visualizer.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spentti <spentti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/02 17:34:23 by spentti           #+#    #+#             */
/*   Updated: 2020/07/14 18:25:20 by spentti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VISUALIZER_H
# define VISUALIZER_H

# include "mlx.h"
# include "../../includes/filler.h"

# define WIDTH 1200
# define HEIGHT 600

typedef struct	s_visu
{
	char		**map;
	char		*p1;
	char		*p2;
	int			map_size_x;
	int			map_size_y;
	int			red;
	int			green;
	int			blue;
	char		*ret;
	void		*mlx;
	void		*win;
	void		*img;
	int			bits_per_pixel;
	int			size_line;
	int			endian;
	int			height;
	int			width;
	int			pause;
}				t_visu;

void			readinput(t_visu *p);
void			draw_map(t_visu *p);

void			print_file(char *format);

#endif
