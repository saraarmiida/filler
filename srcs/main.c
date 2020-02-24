/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spentti <spentti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 19:07:39 by spentti           #+#    #+#             */
/*   Updated: 2020/02/03 19:16:46 by spentti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

static int	init_struct(t_map *map, t_piece *piece)
{
	if (!(map = (t_map *)malloc(sizeof(*map))))
		return (1);
	if (!(piece = (t_piece *)malloc(sizeof(*piece))))
		return (1);
	map->map = NULL;
	map->map_size_x = 0;
	map->map_size_y = 0;
	map->enemy_pos_x = 0;
	map->enemy_pos_y = 0;
	map->my_pos_x = 0;
	map->my_pos_y = 0;
	piece->piece = 0;
	piece->size_x = 0;
	piece->size_y = 0;

}

int		main(void)
{
	t_map	*map;
	t_piece	*piece;

	if (init_struct(map, piece))
		return (0);
	
}