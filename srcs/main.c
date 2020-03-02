/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spentti <spentti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 19:07:39 by spentti           #+#    #+#             */
/*   Updated: 2020/03/02 15:48:00 by spentti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

void	free_token(t_piece *token, int offset)
{
	int		i;

	if (!token->data)
		return ;
	i = 0;
	while (i < token->height)
	{
		ft_strdel(&token->data[i] - offset);
		i++;
	}
	ft_memdel((void **)&token->data);
}

void	read_token(t_piece *token, char *line, int offset)
{
	int	i;
	
	free_token(token, offset);
	line = ft_strchr(line, ' ') + 1;
	token->height = ft_atoi(line);
	token->width = ft_atoi(line + ft_intlen(token->height) + 1);
	token->size = token->height * token->width;
	ft_strdel(&line);
	if (offset)
	{
		get_next_line(0, &line);
		ft_strdel(&line);
	}
	token->data = ft_memalloc(token->height * sizeof(char *));
	i = 0;
	while (i < token->height)
	{
		get_next_line(0, &line);
		token->data[i] = line + offset;
		i++;
	}
}

void		print_board(t_info *info)
{
	int i;
	
	i = 0;
	while (i < info->board->height)
	{
		ft_printf("%s\n", info->board->data[i]);
	}
	i = 0;
	if (i < info->piece->height)
	{
		ft_printf("%s\n", info->piece->data[i]);
	}
}

int		read_map(t_info *info)
{
	char *line;

	line = NULL;
	if (get_next_line(0, &line) < 0)
		return (1);
	if (ft_strncmp(line, "Plateau", 8))
		return (1);
	read_token(info->board, line, 4);
	return (0);
}

int		read_piece(t_info *info)
{
	char *line;

	line = NULL;
	if (get_next_line(0, &line) < 0)
		return (1);
	if (ft_strncmp(line, "Piece", 6))
		return (1);
	read_token(info->piece, line, 0);
	return (0);
}

int		loop_game(t_info *info)
{
	while (1)
	{
		if (read_map(info))
			return (1);
		heat_map(info);
		if (read_piece(info))
			return (1);
		place(info);
	}
	return (0);
}	

int			get_player(t_info *info)
{
	char	*line;

	line = NULL;
	if (get_next_line(0, &line) && line && ft_strlen(line) > 10 &&\
	 !(ft_strncmp(line, "$$$ exec p", 9)) && (line[10] == '1' || line[10] == '2'))
	{
		info->player.id = (line[10] == '1' ? 'O' : 'X');
		info->enemy.id = (line[10] == '2' ? 'O' : 'X');
		ft_strdel(&line);
	}
	else
		return (1);
	return (0);

}

static int	init_struct(t_info *info)
{
	info->inited = 0;
	return (0);
}

int		main(void)
{
	t_info	*info;

	if (!(info = ft_memalloc(sizeof(t_info))))
		return (1);
	init_struct(info);
	if (get_player(info))
		return (1);
	if (loop_game(info))
		return (0);
	return (0);
}