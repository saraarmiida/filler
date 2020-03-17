/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: spentti <spentti@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/03/03 16:47:43 by spentti           #+#    #+#             */
/*   Updated: 2020/03/03 16:53:05 by spentti          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

int			is_around(t_info *i, int x, int y, int a)
{
	if (x + 1 < i->board_w && i->hmap[y][x + 1] == a)
		return (1);
	if (x + 1 < i->board_w && y + 1 < i->board_h && \
	i->hmap[y + 1][x + 1] == a)
		return (1);
	if (y + 1 < i->board_h && i->hmap[y + 1][x] == a)
		return (1);
	if (x - 1 >= 0 && y + 1 < i->board_h && i->hmap[y + 1][x - 1] == a)
		return (1);
	if (x - 1 >= 0 && i->hmap[y][x - 1] == a)
		return (1);
	if (x - 1 >= 0 && y - 1 >= 0 && i->hmap[y - 1][x - 1] == a)
		return (1);
	if (y - 1 >= 0 && i->hmap[y - 1][x] == a)
		return (1);
	if (x + 1 < i->board_w && y - 1 >= 0 && i->hmap[y - 1][x + 1] == a)
		return (1);
	return (0);
}
