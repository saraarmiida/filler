/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spentti <spentti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 19:07:39 by spentti           #+#    #+#             */
/*   Updated: 2020/02/24 16:28:30 by spentti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

void		get_player(t_map *map)
{
	char	*line;

	get_next_line(0, &line);
	if (ft_strncmp(line, "$$$", 2) == 0 && )

}

void		print_board(void)
{
	char	*line;
	
	while (get_next_line(0, &line) == 1)
	{
		printf("%s\n", line);
		free(line);
	}
	if (get_next_line(0, &line) == 0)
	{
		printf("%s\n", line);
		free(line);
	}
}

static int	init_struct(t_map *map, t_piece *piece)
{
	map->map = NULL;
	map->player = 0;
	map->map_size_x = 0;
	map->map_size_y = 0;
	map->enemy_pos_x = 0;
	map->enemy_pos_y = 0;
	map->my_pos_x = 0;
	map->my_pos_y = 0;
	piece->piece = NULL;
	piece->size_x = 0;
	piece->size_y = 0;
	return (0);
}

int		main(void)
{
	t_map	*map;
	t_piece	*piece;

	if (!(map = (t_map *)malloc(sizeof(*map))))
		return (1);
	if (!(piece = (t_piece *)malloc(sizeof(*piece))))
		return (1);
	init_struct(map, piece);
	get_player(map);
	return (0);
}