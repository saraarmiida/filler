/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spentti <spentti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 19:07:39 by spentti           #+#    #+#             */
/*   Updated: 2020/03/04 16:02:50 by spentti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"
#include <fcntl.h>

static void	print_result(t_point p)
{
	ft_printf("%d %d\n", p.x, p.y);
}

void		print_map(t_piece *map)
{
	int y;

	y = 0;
	while (y < map->h)
	{
		ft_printf("%s\n", map->data[y]);
		y++;
	}
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

void	read_to_file(void)
{
	int		fd;
	char	*line;

	line = NULL;
	fd = open("debugfile", O_RDWR);
	while (get_next_line(0, &line) >= 0)
	{
		ft_putendl_fd(line, fd);
		ft_strdel(&line);
	}
}

int			main(void)
{
	t_info	*info;
	char	*line;

	if (!(info = ft_memalloc(sizeof(t_info))))
		return (1);
	info->fd = 0;
	line = NULL;
	if (get_player(info))
		return (1);
	while (get_next_line(info->fd, &line) > 0)
	{
		if (!*line)
		{
			ft_strdel(&line);
			continue ;
		}
		if (ft_strncmp(line, "Plateau", 7) == 0)
		{
			if (read_map(info, line))
				return (1);
			heat_map(info);
		}
		else if (ft_strncmp(line, "Piece", 5) == 0)
		{
			if (read_piece(info, line))
				return (1);
			place(info);
			print_result(info->res);
		}
		else
			ft_strdel(&line);
	}
	return (0);
}

// int			main(int argc, char **argv)
// {
// 	t_info	*info;
// 	char	*line;

// 	if (argc != 2)
// 		return (0);
// 	if (!(info = ft_memalloc(sizeof(t_info))))
// 		return (1);
// 	info->fd = open(argv[1], O_RDONLY);
// 	line = NULL;
// 	if (get_player(info))
// 		return (1);
// 	while (get_next_line(info->fd, &line) > 0)
// 	{
// 		if (!*line)
// 		{
// 			ft_strdel(&line);
// 			continue ;
// 		}
// 		if (ft_strncmp(line, "Plateau", 7) == 0)
// 		{
// 			if (read_map(info, line))
// 				return (1);
// 			heat_map(info);
// 		}
// 		else if (ft_strncmp(line, "Piece", 5) == 0)
// 		{
// 			if (read_piece(info, line))
// 				return (1);
// 			place(info);
// 			print_result(info->res);
// 		}
// 		else
// 			ft_strdel(&line);
// 	}
// 	return (0);
// }
