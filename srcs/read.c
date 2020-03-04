/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spentti <spentti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 14:43:00 by spentti           #+#    #+#             */
/*   Updated: 2020/03/04 15:39:47 by spentti          ###   ########.fr       */
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

t_piece	*read_tokenp(char *line, int offset, int fd)
{
	int		i;
	char	**arr;
	t_piece	*token;

	if (!(token = (t_piece *)malloc(sizeof(t_piece))))
		return (NULL);
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
	if (!(token->data = ft_memalloc(token->h * sizeof(char *))))
		return (NULL);
	i = 0;
	while (i < token->h)
	{
		get_next_line(fd, &line);
		token->data[i] = line + offset;
		i++;
	}
	return (token);
}

t_piece	*read_token(char *line, int offset, int fd)
{
	int		i;
	char	**arr;
	t_piece	*token;

	if (!(token = (t_piece *)malloc(sizeof(t_piece))))
		return (NULL);
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
	if (!(token->data = (char **)malloc(sizeof(char *) * token->h)))
		return (NULL);
	i = 0;
	while (i < token->h)
	{
		get_next_line(fd, &line);
		token->data[i] = line + offset;
		i++;
	}
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
	if (!(i->piece = read_tokenp(line, 0, i->fd)))
		return (1);
	find_offset(i);
	return (0);
}
