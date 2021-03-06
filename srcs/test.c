/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spentti <spentti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/05 17:35:11 by spentti           #+#    #+#             */
/*   Updated: 2020/08/12 13:07:49 by spentti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"
#include <fcntl.h>
#include <stdarg.h>
#include <stdio.h>

void	print_to_file(char *format)
{
	FILE	*fd;

	fd = fopen("filler_log.txt", "a+");
	fprintf(fd, "%s\n", format);
	fclose(fd);
}

void	print_int_to_file(int i, int a)
{
	FILE	*fd;

	fd = fopen("filler_log.txt", "a+");
	fprintf(fd, "%d %d\n", i, a);
	fclose(fd);
}

void	print_res_to_file(t_point res)
{
	FILE	*fd;

	fd = fopen("filler_log.txt", "a+");
	fprintf(fd, "result: %d %d\n", res.y, res.x);
	fclose(fd);
}

void	print_heat(t_info *i)
{
	FILE	*fd;
	int		y;
	int		x;

	fd = fopen("filler_log.txt", "a+");
	y = 0;
	while (y < i->board_h)
	{
		x = 0;
		while (x < i->board_w)
		{
			fprintf(fd, "%3d ", i->hmap[y][x]);
			x++;
		}
		fprintf(fd, "\n");
		y++;
	}
	fprintf(fd, "\n");
	fclose(fd);
}

void	print_int_string(int *str, int width)
{
	FILE	*fd;
	int		x;

	fd = fopen("filler_log.txt", "a+");
	x = 0;
	while (x < width)
	{
		fprintf(fd, "%3d ", str[x]);
		x++;
	}
	fprintf(fd, "\n");
	fclose(fd);
}
