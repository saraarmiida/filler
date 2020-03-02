/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spentti <spentti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 18:35:11 by spentti           #+#    #+#             */
/*   Updated: 2020/03/02 15:50:30 by spentti          ###   ########.fr       */
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
	int			width;
	int			height;
	int			size;
	
}				t_piece;

typedef struct	s_info
{
	t_player	player;
	t_player	enemy;
	t_piece		*board;
	t_piece		*piece;
	int			**hmap;
	int			inited;
}				t_info;

int		heat_map(t_info *i);
void	place(t_info *i);

#endif