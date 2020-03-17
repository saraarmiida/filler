/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spentti <spentti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 14:43:00 by spentti           #+#    #+#             */
/*   Updated: 2020/03/06 17:42:48 by spentti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

void	get_token_size(int *h, int *w, const char *line)
{
	int		off;

	print_to_file("						size point 1");
	off = ft_strncmp(line, "Plateau", 7) == 0 ? 8 : 6;
	print_to_file("						size point 2");
	*h = ft_atoi(&line[off]);
	print_int_to_file(1, *h);
	print_to_file("						size point 3");
	*w = ft_atoi(line + off + ft_intlen(*h) + 1);
	print_to_file("						size point 4");
	print_to_file("						size point 5");
}

int		read_board2(const char *line, t_info *in)
{
	int		i;
	char	*line2;

	print_to_file("				token point 1");
	get_token_size(&in->board_h, &in->board_w, line);
	print_to_file("				token point 2");
	print_to_file("				token point 3");
	get_next_line(in->fd, &line2);
	ft_strdel(&line2);
	print_to_file("				token point 4");
	if (!(in->board = (char **)malloc(sizeof(char *) * (in->board_h + 1))))
		return (1);
	print_to_file("				token point 5");
	i = 0;
	while (i < in->board_h)
	{
		print_to_file("				token point 6");
		get_next_line(in->fd, &line2);
		in->board[i] = ft_strdup(line2 + 4);
		// print_to_file(in->board[i]);
		ft_strdel(&line2);
		i++;
		print_to_file("				token point 7");
	}
	print_to_file("				token point 8");
	// print_to_file("\n\n");
	in->board[i] = NULL;
	return (0);
}

int		read_piece2(const char *line, t_info *in)
{
	int		i;
	char	*line2;
	
	get_token_size(&in->piece_h, &in->piece_w, line);
	if (!(in->piece = (char **)malloc(sizeof(char *) * (in->piece_h + 1))))
		return (1);
	i = 0;
	while (i < in->piece_h)
	{
		get_next_line(in->fd, &line2);
		in->piece[i] = ft_strdup(line2);
		ft_strdel(&line2);
		i++;
	}
	in->piece[i] = NULL;
	return (0);
}

int		read_map(t_info *i, const char *line)
{
	print_to_file("read map point 1");
	read_board2(line, i);
	print_to_file("read map point 2");
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

int		read_piece(t_info *i, const char *line)
{
	read_piece2(line, i);
	if (!i->piece)
		return (1);
	find_offset(i);
	return (0);
}
