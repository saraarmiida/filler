/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spentti <spentti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 14:43:00 by spentti           #+#    #+#             */
/*   Updated: 2020/07/14 18:18:15 by spentti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

void	get_token_size(int *h, int *w, char *line)
{
	int		off;

	off = ft_strncmp(line, "Plateau", 7) == 0 ? 8 : 6;
	*h = ft_atoi(&line[off]);
	*w = ft_atoi(line + off + ft_intlen(*h) + 1);
}

int		read_map(t_info *i, char *line)
{
	int			k;

	ft_strdel(&line);
	get_next_line(i->fd, &line);
	ft_strdel(&line);
	k = 0;
	while (k < i->board_h)
	{
		get_next_line(i->fd, &line);
		i->board[k] = line + 4;
		k++;
	}
	i->board[k] = NULL;
	if (!i->board)
		return (1);
	return (0);
}

void	find_offset(t_info *i)
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
				i->piece_off.y = (y < i->piece_off.y) ? y : i->piece_off.y;
				i->piece_off.x = (x < i->piece_off.x) ? x : i->piece_off.x;
			}
			x++;
		}
		y++;
	}
}

int		read_piece(t_info *i, char *line)
{
	int		k;

	get_token_size(&i->piece_h, &i->piece_w, line);
	ft_strdel(&line);
	if (!(i->piece = (char **)malloc(sizeof(char *) * (i->piece_h + 1))))
		return (1);
	k = 0;
	while (k < i->piece_h)
	{
		get_next_line(i->fd, &line);
		i->piece[k] = ft_strdup(line);
		ft_strdel(&line);
		k++;
	}
	i->piece[k] = NULL;
	if (!i->piece)
		return (1);
	find_offset(i);
	return (0);
}

int		read_input(t_info *i)
{
	char	*line;

	line = NULL;
	while (get_next_line(i->fd, &line) == 1)
	{
		if (ft_strncmp(line, "Plateau", 7) == 0)
		{
			if (read_map(i, line))
				return (1);
		}
		else if (ft_strncmp(line, "Piece", 5) == 0)
		{
			if (read_piece(i, line))
				return (1);
		}
	}
	return (0);
}
