/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spentti <spentti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 14:43:00 by spentti           #+#    #+#             */
/*   Updated: 2020/08/06 17:42:44 by spentti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

void		get_token_size(int *h, int *w, char *line)
{
	int		off;

	off = ft_strncmp(line, "Plateau", 7) == 0 ? 8 : 6;
	*h = ft_atoi(&line[off]);
	*w = ft_atoi(line + off + ft_intlen(*h) + 1);
}

int			find_offset(t_info *i)
{
	int	y;
	int	x;

	y = 0;
	i->piece_off.y = i->piece_h;
	i->piece_off.x = i->piece_w;
	while (y < i->piece_h)
	{
		x = 0;
		while (x < i->piece_w)
		{
			if (i->piece[y][x] == '*')
			{
				i->piece_off.y = y < i->piece_off.y ? y : i->piece_off.y;
				i->piece_off.x = x < i->piece_off.x ? x : i->piece_off.x;
			}
			x++;
		}
		y++;
	}
	return (0);
}

static void	get_map(t_info *i)
{
	int		k;
	char	*line;

	k = 0;
	get_next_line(i->fd, &line);
	ft_strdel(&line);
	print_to_file("after deleting extra row in map reading");
	i->board = (char**)malloc(sizeof(char*) * i->board_h + 1);
	while (k < i->board_h && get_next_line(i->fd, &line) == 1)
	{
		print_to_file(line);
		i->board[k] = line + 4;
		print_to_file(i->board[k]);
		// ft_strdel(&line);
		k++;
		print_to_file(i->board[k - 1]);
	}
	print_to_file("right after getting map");
	print_to_file(i->board[0]);
	i->board[k] = NULL;
}

static void	get_piece(t_info *i)
{
	int		k;
	char	*line;

	k = 0;
	i->piece = (char**)malloc(sizeof(char*) * i->piece_h + 1);
	while (k < i->piece_h)
	{
		get_next_line(i->fd, &line);
		i->piece[k] = ft_strdup((const char*)line);
		k++;
		ft_strdel(&line);
		print_to_file("when reading piece");
	}
	i->piece[k] = NULL;
}

void		read_map(t_info *i, char *line)
{
	get_token_size(&i->board_h, &i->board_w, line);
	get_map(i);
	// print_to_file(i->board[0]);
}

void		read_piece(t_info *i, char *line)
{
	get_token_size(&i->piece_h, &i->piece_w, line);
	get_piece(i);
	find_offset(i);
	trim_piece(i);
}

int			read_input(t_info *i)
{
	char	*line;

	while (get_next_line(0, &line) > 0)
	{
		if (ft_strncmp(line, "Plateau", 6) == 0)
		{
			read_map(i, line);
			// print_to_file(i->board[0]);
			ft_strdel(&line);
			// print_to_file(i->board[0]);
			print_to_file("after reading map");
		}
		else if (ft_strncmp("Piece", line, 4) == 0)
		{
			// print_to_file(i->board[0]);
			read_piece(i, line);
			// print_to_file(i->board[0]);
			ft_strdel(&line);
			// print_to_file(i->board[0]);
			print_to_file("after reading piece");
			return (1);
		}
		else
		{
			print_to_file(line);
			ft_strdel(&line);
			print_to_file("after else");
		}
	}
	return (0);
}
