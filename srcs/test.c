/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spentti <spentti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 17:35:11 by spentti           #+#    #+#             */
/*   Updated: 2020/03/05 17:37:39 by spentti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"
#include <fcntl.h>
#include <stdarg.h>

void	print_to_file(char *format, ...)
{
	FILE	*fd;
	va_list	ap;

	fd = fopen("filler_log.txt", "a+");
	va_start(ap, format);
	fprintf(fd, format, ap);
	va_end(ap);
	fclose(fd);
}

void		print_res_to_file(t_point res)
{
	FILE	*fd;

	fd = fopen("filler_log.txt", "a+");
	fprintf(fd, "%d %d\n", res.y, res.x);
	fclose(fd);
}

void		print_heat(t_info *i)
{
	FILE	*fd;
	int y;
	int x;

	fd = fopen("filler_log.txt", "a+");
	y = 0;
	while (y < i->board->h)
	{
		x = 0;
		while (x < i->board->w)
		{
			fprintf(fd, "%d ", i->hmap[y][x]);
			x++;
		}
		fprintf(fd, "\n");
		y++;
	}
	fprintf(fd, "\n");
	fclose(fd);
}

void		print_map(t_piece *map)
{
	FILE	*fd;
	int y;

	fd = fopen("filler_log.txt", "a+");
	y = 0;
	while (y < map->h)
	{
		fprintf(fd, "%s\n", map->data[y]);
		y++;
	}
	fprintf(fd, "\n");
	fclose(fd);
}
