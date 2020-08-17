#include "../includes/visualiser.h"

void	draw_rectangle(int xs, int ys, t_env *p)
{
	int		x;
	int		y;
	int		tmp;

	y = 0;
	tmp = 0;
	while (y < (p->size.y * 4))
	{
		x = 0;
		while (x < (p->size.x * 4))
		{
			p->ret[x + tmp + ((ys * WIDTH * 4) + (xs * 4))] = p->blue;
			p->ret[x + tmp + 1 + ((ys * WIDTH * 4) + (xs * 4))] = p->green;
			p->ret[x + tmp + 2 + ((ys * WIDTH * 4) + (xs * 4))] = p->red;
			p->ret[x + tmp + 3 + ((ys * WIDTH * 4) + (xs * 4))] = 0;
			x += 4;
		}
		y += 4;
		tmp += (WIDTH * 4);
	}
}

void	calc_score(t_env *p)
{
	int		y;
	int		x;

	y = 0;
	p->scorep1 = 0;
	p->scorep2 = 0;
	while (y < p->map_size_y)
	{
		x = 0;
		while (x < p->map_size_x)
		{
			if (p->map[y][x] == 'O' || p->map[y][x] == 'o')
				p->scorep1 += 1;
			if (p->map[y][x] == 'X' || p->map[y][x] == 'x')
				p->scorep2 += 1;
			x++;
		}
		y++;
	}
}

void	modif_color(int red, int green, int blue, t_env *p)
{
	p->red = red;
	p->green = green;
	p->blue = blue;
}

void	print_score(t_env *p)
{
	mlx_string_put(p->mlx, p->win, (WIDTH / 2) - 150, 60, 0xFFFFFF, p->p1);
	mlx_string_put(p->mlx, p->win, (WIDTH / 2) - 150, 90, 0xFFFFFFF, \
	ft_itoa(p->scorep1));
	mlx_string_put(p->mlx, p->win, (WIDTH / 2) - 10, 60, 0xFFFFFF, "vs");
	mlx_string_put(p->mlx, p->win, (WIDTH / 2) + 20, 60, 0xFFFFFF, p->p2);
	mlx_string_put(p->mlx, p->win, (WIDTH / 2) + 20, 90, 0xFFFFFFF, \
	ft_itoa(p->scorep2));
}

void	free_map(char **str)
{
	int		i;

	i = 0;
	while (str[i] != NULL)
	{
		ft_strdel(&str[i]);
		i++;
	}
	free(str);
	str = NULL;
}
