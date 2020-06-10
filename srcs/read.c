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

void	get_token_size(int *h, int *w, char *line)
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
}

int		read_board2(char *line, t_info *in)
{
	int			i;

	print_to_file("\nLINE2: ");
	print_to_file(line);
	ft_strdel(&line);
	get_next_line(in->fd, &line);
	print_to_file("\nLINE2: ");
	print_to_file(line);
	ft_strdel(&line);
	i = 0;
	while (i < in->board_h)
	{
		get_next_line(in->fd, &line);
		// print_to_file("\nLINE:");
		// print_to_file(line);
		in->board[i] = line + 4;
		// print_to_file("\nBOARD[i]:");
		// print_to_file((char *)in->board[i]);
		i++;
		// print_to_file("\nBOARD0:");
		// print_map(in->board, i);
	}
	print_to_file("\nBOARD1:");
	print_to_file((char *)in->board[0]);
	print_to_file((char *)in->board[1]);
	print_to_file((char *)in->board[2]);
	print_to_file((char *)in->board[3]);
	print_to_file((char *)in->board[4]);
	print_to_file((char *)in->board[5]);
	print_to_file((char *)in->board[6]);
	print_to_file((char *)in->board[7]);
	print_to_file((char *)in->board[8]);
	print_to_file((char *)in->board[9]);
	print_to_file((char *)in->board[10]);
	print_to_file((char *)in->board[11]);
	print_to_file((char *)in->board[12]);
	print_to_file((char *)in->board[13]);
	print_to_file((char *)in->board[14]);
	print_to_file("\nBOARD2:");
	print_map(in->board, in->board_h);
	print_to_file("				token point 8");
	// print_to_file("\n\n");
	in->board[i] = NULL;
	return (0);
}

int		read_piece2(char *line, t_info *in)
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

int		read_map(t_info *i, char *line)
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

int		read_piece(t_info *i, char *line)
{
	read_piece2(line, i);
	if (!i->piece)
		return (1);
	find_offset(i);
	return (0);
}
