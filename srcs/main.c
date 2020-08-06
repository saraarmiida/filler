/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spentti <spentti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 19:07:39 by spentti           #+#    #+#             */
/*   Updated: 2020/08/06 17:35:08 by spentti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** 30.7
** - exits (doesnt find cooordinates) for no reason
** - changed use of piece offset to allow giving minus coordinates
** 5.8
** - sometimes random line from previous map gets left on the first line of a map
*/

#include "../includes/filler.h"
#include <fcntl.h>
#include <stdarg.h>

static int	get_player(t_info *i)
{
	char	*line;

	line = NULL;
	if (get_next_line(i->fd, &line) && line && ft_strlen(line) > 10 && \
	!(ft_strncmp(line, "$$$ exec p", 9)) && (line[10] == '1' || \
	line[10] == '2'))
	{
		i->player.id = (line[10] == '1' ? 'O' : 'X');
		i->enemy.id = (line[10] == '2' ? 'O' : 'X');
	}
	ft_strdel(&line);
	return (0);
}

void		init_struct(t_info *i)
{
	i->player.id = 0;
	i->player.start.x = 0;
	i->player.start.y = 0;
	i->enemy.id = 0;
	i->enemy.start.x = 0;
	i->enemy.start.y = 0;
	i->piece_off.x = 0;
	i->piece_off.y = 0;
	i->start.x = 0;
	i->start.y = 0;
	i->res.x = 0;
	i->res.y = 0;
	i->hmap = NULL;
	i->fd = 0;
	i->first_time = 1;
}

int			main(void)
{
	t_info	*info;

	if (!(info = (t_info*)malloc(sizeof(t_info))))
		return (1);
	init_struct(info);
	if (get_player(info))
		return (1);
	while (1)
	{
		print_to_file("\n\nSTARTING NEW ROUND\n\n");
		if (read_input(info) == 0)
		{
			ft_printf("%d %d\n", info->res.y, info->res.x);
			print_to_file("exiting because nothing to read...");
			free_all(info);
			free(info);
			info = NULL;
			exit(1);
		}
		// print_to_file(info->board[0]);
		heat_map(info);
		// print_to_file(info->board[0]);
		if (place(info) == 1)
		{
			ft_printf("%d %d\n", info->res.y, info->res.x);
			print_to_file("exiting...");
			free_all(info);
			free(info);
			info = NULL;
			exit(1);
		}
		print_to_file("result printed at the end");
		print_res_to_file(info->res);
		// free_all(info);
		ft_printf("%d %d\n", info->res.y, info->res.x);
	}
	return (0);
}
