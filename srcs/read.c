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

void	get_token_size(t_piece *token, char *line)
{
	char **arr;

	arr = ft_strsplit(line, ' ');
	token->h = ft_atoi(arr[1]);
	token->w = ft_atoi(arr[2]);
	token->size = token->h * token->w;
	free(arr[0]);
	free(arr[1]);
	free(arr[2]);
	free(arr);
	ft_strdel(&line);
}

t_piece	*read_token(char *line, int offset, t_info *in)
{
	int		i;
	
	get_token_size(in->board, line);
	// ft_strdel(&line);
	if (offset)
	{
		get_next_line(in->fd, &line);
		ft_strdel(&line);
	}
	if (!(in->board->data = (char **)malloc(sizeof(char *) * (in->board->h + 1))))
		return (NULL);
	i = 0;
	while (i < in->board->h)
	{
		get_next_line(in->fd, &line);
		in->board->data[i] = ft_strdup(line + offset);
		ft_strdel(&line);
		i++;
	}
	in->board->data[i] = NULL;
	return (in->board);
}

t_piece	*read_tokenp(char *line, t_info *in)
{
	int		i;
	
	get_token_size(in->piece, line);
	// ft_strdel(&line);
	if (!(in->piece->data = (char **)malloc(sizeof(char *) * (in->piece->h + 1))))
		return (NULL);
	i = 0;
	while (i < in->piece->h)
	{
		get_next_line(in->fd, &line);
		in->piece->data[i] = ft_strdup(line);
		ft_strdel(&line);
		i++;
	}
	in->piece->data[i] = NULL;
	return (in->piece);
}

int		read_map(t_info *i, char *line)
{
	if (!(i->board = (t_piece *)malloc(sizeof(t_piece))))
		return (1);
	read_token(line, 4, i);
	if (!i->board)
		return (1);
	return (0);
}

void	find_offset(t_info *i)
{
	int	y;
	int	x;

	y = 0;
	i->piece_off.y = i->piece->h;
	i->piece_off.x = i->piece->w;
	while (y < i->piece->h)
	{
		x = 0;
		while (x < i->piece->w)
		{
			if (i->piece->data[y][x] == '*')
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
	if (!(i->piece = (t_piece *)malloc(sizeof(t_piece))))
		return (1);
	read_tokenp(line, i);
	if (!i->piece)
		return (1);
	find_offset(i);
	return (0);
}
