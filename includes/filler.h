/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spentti <spentti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 18:35:11 by spentti           #+#    #+#             */
/*   Updated: 2020/02/27 16:30:16 by spentti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

#include <stdlib.h>
#include "../libft/ft_printf/includes/ft_printf.h"
#include "../libft/libft/includes/libft.h"

typedef struct	s_piece
{
	char		**data;
	int			width;
	int			height;
	int			size;
	
}				t_piece;

typedef struct	s_info
{
	char		player;
	char		enemy;
	int			enemy_pos_x;
	int			enemy_pos_y;
	int			my_pos_x;
	int			my_pos_y;
	t_piece		*board;
	t_piece		*piece;
}				t_info;

#endif