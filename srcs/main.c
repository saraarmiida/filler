/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spentti <spentti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 19:07:39 by spentti           #+#    #+#             */
/*   Updated: 2020/07/30 20:00:12 by spentti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/*
** 30.7
** - exits (doesnt find cooordinates) for no reason
** - changed use of piece offset to allow giving minus coordinates
*/

#include "../includes/filler.h"
#include <fcntl.h>
#include <stdarg.h>

static void	print_result(int y, int x)
{
	ft_putnbr(y);
	ft_putchar(' ');
	ft_putnbr(x);
	ft_putchar('\n');
}

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
		read_input(info);
		heat_map(info);
		print_int_to_file(info->piece_off.y, info->piece_off.x);
		if (place(info) == 1)
		{
			/* add freeing everything here */
			exit(1);
		}
		print_res_to_file(info->res);
		free_all(info);
		print_result(info->res.y, info->res.x);
	}
	return (0);
}
