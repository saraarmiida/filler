/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spentti <spentti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 18:35:11 by spentti           #+#    #+#             */
/*   Updated: 2020/08/07 17:47:28 by spentti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

# include <stdlib.h>
# include "../libft/ft_printf/includes/ft_printf.h"
# include "../libft/libft/includes/libft.h"

typedef struct	s_point
{
	int			x;
	int			y;
}				t_point;

typedef struct	s_info
{
	char		player_id;
	char		enemy_id;
	int			board_w;
	int			board_h;
	char		**piece;
	int			piece_w;
	int			piece_h;
	t_point		piece_off;
	t_point		res;
	int			**hmap;
	int			fd;
}				t_info;

int				read_input(t_info *i);
void			init_heat_map(t_info *i);
int				place(t_info *i);
int				is_around(t_info *i, int x, int y, int a);
void			free_piece(char **str);
void			free_heat(int **arr, int h);
void			trim_piece(t_info *i);
void			locate_players(int *y, t_info *i, char *line);
void			exit_loop(t_info *i);

void			print_map(char **map, int h);
void			print_to_file(char *format);
void			print_res_to_file(t_point res);
void			print_heat(t_info *i);
void			print_int_to_file(int i, int a);
void			print_int_string(int *str, int width);

#endif
