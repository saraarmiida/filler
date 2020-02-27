/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spentti <spentti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 19:07:39 by spentti           #+#    #+#             */
/*   Updated: 2020/02/27 16:30:53 by spentti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

void	read_token(t_piece *token, char *line, int offset)
{
	int	i;
	
	free_token(token, offset);
	line = ft_srtchr(line, ' ') + 1;
	token->height = ft_atoi(line);
	token->width = ft_atoi(line + ft_intlen(token->height) + 1);
	token->size = token->height * token->width;
	ft_strdel(&line);
	if (offset)
	{
		get_next_line(0, &line);
		ft_strdel(&line);
	}
	token->data = ft
}

void	loop_game(t_info *info)
{
	char	*line;
	
	while ((get_next_line(0, &line)) > -1)
	{
		if (!line)
			continue;
		if (ft_strncmp(line, "Plateau", 8) == 0)
		{
			read_token(info->board, line, 4);
		}
		else if (ft_strncmp(line, "Piece", 6) == 0)
		{
			read_token(info->piece, line, 0);
		}
	}
}	

int			get_player(t_info *info)
{
	char	*line;

	line = NULL;
	if (get_next_line(0, &line) && line && ft_strlen(line) > 10 &&\
	 !(ft_strncmp(line, "$$$ exec p", 9)) && (line[10] == '1' || line[10] == '2'))
	{
		info->player = (line[10] == '1' ? 'O' : 'X');
		info->enemy = (line[10] == '2' ? 'O' : 'X');
		ft_strdel(&line);
	}
	else
		return (1);
	return (0);

}

void		print_board(void)
{
	char	*line;
	
	while (get_next_line(0, &line) == 1)
	{
		printf("%s\n", line);
		free(line);
	}
	if (get_next_line(0, &line) == 0)
	{
		printf("%s\n", line);
		free(line);
	}
}

static int	init_struct(t_info *info)
{
	info->player = 0;
	info->enemy_pos_x = 0;
	info->enemy_pos_y = 0;
	info->my_pos_x = 0;
	info->my_pos_y = 0;
	return (0);
}

int		main(void)
{
	t_info	*info;

	if (!(info = (t_info *)malloc(sizeof(*info))))
		return (1);
	init_struct(info);
	if (get_player(info))
		return (1);
	loop_game(info);
	return (0);
}