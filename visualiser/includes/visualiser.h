/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   visualiser.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spentti <spentti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/19 16:34:13 by spentti           #+#    #+#             */
/*   Updated: 2020/08/19 19:41:59 by spentti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VISUALISER_H
# define VISUALISER_H

# include "../../libft/libft/includes/libft.h"
# include "mlx.h"
# include <stdlib.h>
# define WIDTH	800
# define HEIGHT	900
# define ESC	53
# define WINDOW_NAME "FILLER"

typedef struct	s_size
{
	int			x;
	int			y;
}				t_size;

typedef struct	s_env
{
	char		*p1;
	char		*p2;
	float		scorep1;
	float		scorep2;
	char		**map;
	t_size		size;
	int			red;
	int			green;
	int			blue;
	int			map_size_x;
	int			map_size_y;
	char		*ret;
	void		*win;
	void		*mlx;
	void		*img;
	int			bits_per_pixel;
	int			size_line;
	int			endian;
	int			pause;
}				t_env;

int				main(void);
void			get_input(t_env *p);
void			draw(t_env *p);

void			draw_rectangle(int start_x, int start_y, t_env *p);
void			draw_background(t_env *p);
void			print_score(t_env *p);
void			modif_color(int r, int v, int b, t_env *p);
void			calc_score(t_env *p);
void			free_map(char **str);

#endif
