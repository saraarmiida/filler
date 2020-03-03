/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spentti <spentti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 14:43:00 by spentti           #+#    #+#             */
/*   Updated: 2020/03/03 17:56:54 by spentti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

void	free_token(t_piece *token, int offset)
{
	int		i;

	if (!token->data)
		return ;
	i = 0;
	while (i < token->h)
	{
		ft_strdel(&token->data[i] - offset);
		i++;
	}
	ft_memdel((void **)&token->data);
}

void	read_token(t_piece *token, char *line, int offset, int fd)
{
	int		i;
	char	**arr;

	// free_token(token, offset);
	token = (t_piece *)malloc(sizeof(t_piece));
	arr = ft_strsplit(line, ' ');
	token->h = ft_atoi(arr[1]);
	token->w = ft_atoi(arr[2]);
	token->size = token->h * token->w;
	free(arr[0]);
	free(arr[1]);
	free(arr[2]);
	free(arr);
	ft_strdel(&line);
	if (offset)
	{
		get_next_line(fd, &line);
		ft_strdel(&line);
	}
	token->data = ft_memalloc(token->h * sizeof(char *));
	i = 0;
	while (i < token->h)
	{
		get_next_line(fd, &line);
		token->data[i] = line + offset;
		i++;
	}
}

int		read_map(t_info *i)
{
	char *line;

	line = NULL;
	if (get_next_line(i->fd, &line) < 0)
		return (1);
	if (ft_strncmp(line, "Plateau", 7))
		return (1);
	read_token(i->board, line, 4, i->fd);
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
		}
	}
}

int		read_piece(t_info *i)
{
	char *line;

	line = NULL;
	if (get_next_line(i->fd, &line) < 0)
		return (1);
	if (ft_strncmp(line, "Piece", 6))
		return (1);
	read_token(i->piece, line, 0, i->fd);
	find_offset(i);
	return (0);
}
