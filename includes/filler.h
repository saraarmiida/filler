/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spentti <spentti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 18:35:11 by spentti           #+#    #+#             */
/*   Updated: 2020/08/06 14:31:05 by spentti          ###   ########.fr       */
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

typedef struct	s_player
{
	char		id;
	t_point		start;
}				t_player;

typedef struct	s_info
{
	t_player	player;
	t_player	enemy;
	char		**board;
	int			board_w;
	int			board_h;
	char		**piece;
	int			piece_w;
	int			piece_h;
	t_point		piece_off;
	t_point		start;
	t_point		res;
	int			**hmap;
	int			inited;
	int			fd;
	int			first_time;
}				t_info;

int				read_input(t_info *i);
int				heat_map(t_info *i);
int				place(t_info *i);
int				is_around(t_info *i, int x, int y, int a);
void			free_all(t_info *i);
void			free_token(char **str);
void			free_int_arr(int **arr, int h);
void			trim_piece(t_info *i);

void			print_map(char **map, int h);
void			print_to_file(char *format);
void			print_res_to_file(t_point res);
void			print_heat(t_info *i);
void			print_int_to_file(int i, int a);

#endif
