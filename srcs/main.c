/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spentti <spentti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/03 19:07:39 by spentti           #+#    #+#             */
/*   Updated: 2020/07/16 18:39:10 by spentti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


// - visualizer base done, i suspect it doesnt work because filler doesnt work
// - filler timeout
// - cleaned filler input reading, might cause some problems
// - checked norminette on both filler & visualizer

// problems:
// - segfault at create heat 4
// - segfault at hello3 reason: piece not read correctly (null) because: doesn't go to loop of reading in read_input
// - malloc, pointer being freed was not allocated (free_all map) (fixed in read_map)

#include "../includes/filler.h"
#include <fcntl.h>
#include <stdarg.h>

static void	print_result(int y, int x)
{
	ft_putnbr(y);
	ft_putchar(' ');
	ft_putnbr(x);
	ft_putchar('\n');
}

static int	get_player(t_info *i)
{
	char	*line;

	line = NULL;
	if (get_next_line(i->fd, &line) && line && ft_strlen(line) > 10 && \
	!(ft_strncmp(line, "$$$ exec p", 9)) && (line[10] == '1' || \
	line[10] == '2'))
	{
		i->player.id = (line[10] == '1' ? 'O' : 'X');
		i->enemy.id = (line[10] == '2' ? 'O' : 'X');
	}
	ft_strdel(&line);
	return (0);
}

void		init_struct(t_info *i)
{
	i->player.id = 0;
	i->player.start.x = 0;
	i->player.start.y = 0;
	i->enemy.id = 0;
	i->enemy.start.x = 0;
	i->enemy.start.y = 0;
	i->piece_off.x = 0;
	i->piece_off.y = 0;
	i->start.x = 0;
	i->start.y = 0;
	i->res.x = 0;
	i->res.y = 0;
	i->hmap = NULL;
	i->fd = 0;
	i->first_time = 1;
}

int			main(void)
{
	t_info	*info;

	if (!(info = (t_info*)malloc(sizeof(t_info))))
		return (1);
	init_struct(info);
	if (get_player(info))
		return (1);
	while (1)
	{
		print_to_file("hello1");
		read_input(info);
		print_to_file("hello2");
		heat_map(info);
		print_to_file("hello3");
		place(info);
		print_to_file("hello4");
		free_all(info);
		print_to_file("hello5");
		print_res_to_file(info->res);
		print_to_file("hello6");
		print_result(info->res.y, info->res.x);
		print_to_file("hello7");
	}
	return (0);
}
