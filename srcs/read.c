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

void	free_int_arr(int **arr, int h)
{
	int	i;

	i = 0;
	while (i < h)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

void	free_token(t_piece *token)
{
	int		i;

	if (!token->data)
		return ;
	i = 0;
	while (i < token->h)
	{
		ft_strdel(&token->data[i]);
		i++;
	}
	ft_memdel((void **)&token->data);
	free(token);
}

void	free_all(t_info *i)
{
	free_int_arr(i->hmap, i->board->h);
	free_token(i->board);
	free_token(i->piece);
}

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

t_piece	*read_token(char *line, int offset, int fd)
{
	int		i;
	t_piece	*token;

	if (!(token = (t_piece *)malloc(sizeof(t_piece))))
		return (NULL);
	get_token_size(token, line);
	if (offset)
	{
		get_next_line(fd, &line);
		ft_strdel(&line);
	}
	if (!(token->data = (char **)malloc(sizeof(char *) * token->h + 1)))
		return (NULL);
	i = 0;
	while (i < token->h)
	{
		get_next_line(fd, &line);
		token->data[i] = ft_strdup(line + offset);
		ft_strdel(&line);
		i++;
	}
	token->data[i] = NULL;
	return (token);
}

int		read_map(t_info *i, char *line)
{
	if (!(i->board = read_token(line, 4, i->fd)))
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
	if (!(i->piece = read_token(line, 0, i->fd)))
		return (1);
	find_offset(i);
	return (0);
}
