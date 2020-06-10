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

static void	print_result(int y, int x)
{
	print_to_file("    		print point 1");
	ft_putnbr(y);
	ft_putchar(' ');
	print_to_file("    		print point 2");
	ft_putnbr(x);
	ft_putchar('\n');
	print_to_file("    		print point 3");
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
		ft_strdel(&line);
	}
	else
	{
		ft_strdel(&line);
		return (1);
	}
	return (0);
}

int			read_input(t_info *i)
{
	char	*line;
	int		counter; 

	line = NULL;
	counter = 0;
	print_to_file("read point 1");
	while (counter < 2 && get_next_line(i->fd, &line) > 0)
	{
		print_to_file("read point 2");
		if (ft_strncmp(line, "Plateau", 7) == 0 && i->first_time != 1)
		{
			print_to_file("read point 3");
			if (read_map(i, line))
				return (1);
			print_to_file("read point 4");
			counter++;
		}
		if (i->first_time == 1)
		{
			i->first_time = 0;
			counter++;
		}
		else if (ft_strncmp(line, "Piece", 5) == 0)
		{
			print_to_file("read point 5");
			if (read_piece(i, line))
				return (1);
			print_to_file("read point 6");
			counter++;
		}
		print_to_file("read point 7");
		ft_strdel(&line);
	}
	print_to_file("read point 8");
	return (0);
}

int			init_map(t_info *i)
{
	char	*line;

	if (get_next_line(i->fd, &line) > 0 && ft_strncmp(line, "Plateau", 7) == 0)
	{
		get_token_size(&i->board_h, &i->board_w, line);
		if (!(i->board = (const char **)malloc(sizeof(char *) * (i->board_h + 1))))
			return (1);
		if (read_map(i, line))
			return (1);
		return (0);
	}
	return (1);
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
	if (init_map(info))
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
		print_res_to_file(info->res);
		print_result(info->res.y, info->res.x);
		print_to_file("    main point 7");
	}
	return (0);
}
