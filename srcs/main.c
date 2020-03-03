/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spentti <spentti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 19:07:39 by spentti           #+#    #+#             */
/*   Updated: 2020/03/03 17:57:47 by spentti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"
#include <fcntl.h>

static void	print_result(t_point p)
{
	ft_printf("%d %d\n", p.x, p.y);
}

static int	loop_game(t_info *info)
{
	while (1)
	{
		if (read_map(info))
			return (1);
		heat_map(info);
		if (read_piece(info))
			return (1);
		place(info);
		print_result(info->res);
	}
	return (0);
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
		return (1);
	return (0);
}

int			main(int argc, char **argv)
{
	t_info	*info;

	if (argc != 2)
		return (0);
	if (!(info = ft_memalloc(sizeof(t_info))))
		return (1);
	info->fd = open(argv[1], O_RDONLY);
	if (get_player(info))
		return (1);
	if (loop_game(info))
		return (0);
	return (0);
}
