/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spentti <spentti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 19:07:39 by spentti           #+#    #+#             */
/*   Updated: 2020/03/06 17:28:55 by spentti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"
#include <fcntl.h>
#include <stdarg.h>

static void	print_result(t_point p)
{
	ft_putnbr(p.y);
	ft_putchar(' ');
	ft_putnbr(p.x);
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
	else
	{
		ft_strdel(&line);
		return (1);
	}
	ft_strdel(&line);
	return (0);
}

int			read_input(t_info *i)
{
	char	*line;

	line = NULL;
	print_to_file("read point 1");
	while (get_next_line(i->fd, &line) > 0)
	{
		print_to_file("read point 2");
		if (ft_strncmp(line, "Plateau", 7) == 0)
		{
			print_to_file("read point 3");
			if (read_map(i, line))
				return (1);
			print_to_file("read point 4");
		}
		else if (ft_strncmp(line, "Piece", 5) == 0)
		{
			print_to_file("read point 5");
			if (read_piece(i, line))
				return (1);
			print_to_file("read point 6");
		}
		print_to_file("read point 7");
		ft_strdel(&line);
	}
	print_to_file("read point 8");
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
}

int			main(void)
{
	t_info	*info;

	if (!(info = (t_info*)malloc(sizeof(t_info))))
		return (1);
	init_struct(info);
	if (get_player(info))
		return (1);
	print_to_file("main point 1");
	while (1)
	{
		print_to_file("    main point 2");
		if (read_input(info))
			return (1);
		// print_int_to_file(info->board->h, info->board->w);
		// print_map(info->board);
		// print_int_to_file(info->piece->h, info->piece->w);
		// print_map(info->piece);
		print_to_file("    main point 3");
		heat_map(info);
		// print_heat(info);
		print_to_file("    main point 4");
		place(info);
		print_to_file("    main point 5");
		free_all(info);
		print_to_file("    main point 6");
		print_result(info->res);
		print_to_file("    main point 7");
	}
	return (0);
}
