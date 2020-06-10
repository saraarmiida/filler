/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spentti <spentti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 14:43:00 by spentti           #+#    #+#             */
/*   Updated: 2020/06/10 15:55:10 by spentti          ###   ########.fr       */
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

int		read_board2(char *line, t_info *in)
{
	int			i;

	ft_strdel(&line);
	get_next_line(in->fd, &line);
	ft_strdel(&line);
	i = 0;
	while (i < in->board_h)
	{
		get_next_line(in->fd, &line);
		in->board[i] = line + 4;
		i++;
	}
	in->board[i] = NULL;
	return (0);
}

int		read_piece2(char *line, t_info *in)
{
	int		i;
	
	get_token_size(&in->piece_h, &in->piece_w, line);
	ft_strdel(&line);
	if (!(in->piece = (char **)malloc(sizeof(char *) * (in->piece_h + 1))))
		return (1);
	i = 0;
	while (i < in->piece_h)
	{
		get_next_line(in->fd, &line);
		in->piece[i] = ft_strdup(line);
		ft_strdel(&line);
		i++;
	}
	in->piece[i] = NULL;
	return (0);
}

int		read_map(t_info *i, char *line)
{
	read_board2(line, i);
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
	read_piece2(line, i);
	if (!i->piece)
		return (1);
	find_offset(i);
	return (0);
}
