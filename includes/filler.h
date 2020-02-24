/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spentti <spentti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 18:35:11 by spentti           #+#    #+#             */
/*   Updated: 2020/02/03 19:09:50 by spentti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H

#include <stdlib.h>

typedef struct	s_map
{
	char		**map;
	int			map_size_x;
	int			map_size_y;
	int			enemy_pos_x;
	int			enemy_pos_y;
	int			my_pos_x;
	int			my_pos_y;
}				t_map;

typedef struct	s_piece
{
	char		**piece;
	int			size_x;
	int			size_y;
}				t_piece;

#endif