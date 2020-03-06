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
	ft_printf("%d %d\n", p.y, p.x);
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
		return (1);
	ft_strdel(&line);
	return (0);
}

int			read_input(t_info *i)
{
	char	*line;

	line = NULL;
	while (get_next_line(i->fd, &line) > 0)
	{
		if (ft_strncmp(line, "Plateau", 7) == 0)
		{
			if (read_map(i, line))
				return (0);
		}
		else if (ft_strncmp(line, "Piece", 5) == 0)
		{
			if (read_piece(i, line))
				return (0);
			print_map(i->piece);
			return (0);
		}
		else
			ft_strdel(&line);
	}
	return (0);
}

int			main(void)
{
	t_info	*info;


	if (!(info = (t_info*)malloc(sizeof(t_info))))
		return (1);
	info->fd = 0;
	if (get_player(info))
		return (1);
	while (1)
	{
		if (read_input(info))
			return (1);
		heat_map(info);
		place(info);
		free_all(info);
		print_result(info->res);
	}
	return (0);
}
