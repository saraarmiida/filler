/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spentti <spentti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 18:35:11 by spentti           #+#    #+#             */
/*   Updated: 2020/03/06 17:43:56 by spentti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

#include <stdlib.h>
#include "../libft/ft_printf/includes/ft_printf.h"
#include "../libft/libft/includes/libft.h"

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

typedef struct	s_piece
{
	char		**data;
	int			w;
	int			h;
	int			size;
	
}				t_piece;

typedef struct	s_info
{
	t_player	player;
	t_player	enemy;
	t_piece		*board;
	t_piece		*piece;
	t_point		piece_off;
	t_point		start;
	t_point		res;
	int			**hmap;
	int			inited;
	int			fd;
}				t_info;

int				heat_map(t_info *i);
void			place(t_info *i);
int				is_around(t_info *i, int x, int y, int a);
int				read_map(t_info *info, char *line);
int				read_piece(t_info *info, char *line);
void			free_all(t_info *i);

void			print_map(t_piece *map);
void			print_to_file(char *format);
void			print_res_to_file(t_point res);
void			print_heat(t_info *i);
void			print_int_to_file(int i, int a);

#endif