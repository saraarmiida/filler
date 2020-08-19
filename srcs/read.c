/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spentti <spentti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 14:43:00 by spentti           #+#    #+#             */
/*   Updated: 2020/08/19 16:28:24 by spentti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

/*
** Get_token_size saves map and piece dimensions.
*/

static void	get_token_size(int *h, int *w, char *line)
{
	int		off;

	off = ft_strncmp(line, "Plateau", 7) == 0 ? 8 : 6;
	*h = ft_atoi(&line[off]);
	*w = ft_atoi(line + off + ft_intlen(*h) + 1);
}

/*
** Find_offset finds the upper left coordinates of where piece starts.
** Used for trimming the piece and to give correct coordinates
** after finding a place for the trimmed piece.
*/

static int	find_offset(t_info *i)
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

/*
** Read_map creates an integer map based of map read from stdin.
*/

static int	read_map(t_info *i)
{
	int		y;
	char	*line;

	y = 0;
	get_next_line(i->fd, &line);
	ft_strdel(&line);
	if (!(i->hmap = (int**)malloc(sizeof(int*) * i->board_h)))
		return (1);
	while (y < i->board_h && get_next_line(i->fd, &line) == 1)
	{
		if (!(i->hmap[y] = (int*)malloc(sizeof(int) * i->board_w)))
			return (1);
		locate_players(y, i, line);
		ft_strdel(&line);
		y++;
	}
	return (0);
}

/*
** Read_piece reads and saves piece to struct.
*/

static void	read_piece(t_info *i)
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
	}
	i->piece[k] = NULL;
	find_offset(i);
	trim_piece(i);
}

/*
** Read_input reads information given from stdin.
*/

int			read_input(t_info *i)
{
	char	*line;

	while (get_next_line(0, &line) > 0)
	{
		if (ft_strncmp(line, "Plateau", 6) == 0)
		{
			get_token_size(&i->board_h, &i->board_w, line);
			if (read_map(i) == 1)
				return (1);
			ft_strdel(&line);
		}
		else if (ft_strncmp("Piece", line, 4) == 0)
		{
			get_token_size(&i->piece_h, &i->piece_w, line);
			read_piece(i);
			ft_strdel(&line);
			return (1);
		}
		else
			ft_strdel(&line);
	}
	return (0);
}
