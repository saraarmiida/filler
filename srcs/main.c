/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spentti <spentti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 19:07:39 by spentti           #+#    #+#             */
/*   Updated: 2020/08/13 19:40:09 by spentti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

/*
** finds player information
*/

static int	get_player(t_info *i)
{
	char	*line;

	line = NULL;
	if (get_next_line(i->fd, &line) && line && ft_strlen(line) > 10 && \
	!(ft_strncmp(line, "$$$ exec p", 9)) && (line[10] == '1' || \
	line[10] == '2'))
	{
		i->player_id = (line[10] == '1' ? 'O' : 'X');
		i->enemy_id = (line[10] == '2' ? 'O' : 'X');
	}
	ft_strdel(&line);
	return (0);
}

/*
** initializes struct values
*/

static void	init_struct(t_info *i)
{
	i->player_id = 0;
	i->enemy_id = 0;
	i->piece_off.x = 0;
	i->piece_off.y = 0;
	i->res.x = 0;
	i->res.y = 0;
	i->fd = 0;
	i->first = 1;
}

int			main(void)
{
	t_info	*info;

	if (!(info = (t_info*)malloc(sizeof(t_info))))
		return (1);
	init_struct(info);
	if (get_player(info))
		return (1);
	while (read_input(info))
	{
		heat_map(info);
		if (place(info) == 0)
			exit_loop(info);
		free_heat(info->hmap, info->board_h);
		free_piece(info->piece);
		ft_printf("%d %d\n", info->res.y, info->res.x);
	}
	free_heat(info->hmap, info->board_h);
	free_piece(info->piece);
	free(info);
	info = NULL;
	return (0);
}
