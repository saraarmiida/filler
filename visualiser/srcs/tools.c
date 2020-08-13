#include "../includes/visualiser.h"

void		draw_rectangle(int x, int y, t_env *p)
{
	int		i;
	int		i2;
	int		tmp;

	i2 = 0;
	tmp = 0;
	while (i2 < (p->size.height * 4))
	{
		i = 0;
		while (i < (p->size.width * 4))
		{
			p->ret[i + tmp + ((y * WIDTH * 4) + (x * 4))] = p->blue;
			p->ret[i + tmp + 1 + ((y * WIDTH * 4) + (x * 4))] = p->green;
			p->ret[i + tmp + 2 + ((y * WIDTH * 4) + (x * 4))] = p->red;
			p->ret[i + tmp + 3 + ((y * WIDTH * 4) + (x * 4))] = 0;
			i += 4;
		}
		i2 += 4;
		tmp += (WIDTH * 4);
	}
}

void		calc_score(t_env *p)
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

void		modif_color(int red, int green, int blue, t_env *p)
{
	p->red = red;
	p->green = green;
	p->blue = blue;
}

void		print_final(t_env *p)
{
	char	*str;

	str = ft_itoa(p->scorep1);
	mlx_string_put(p->mlx, p->win, (WIDTH / 2) + 390, 90,
		0xFFFFFFF, str);
	str = ft_itoa(p->scorep2);
	mlx_string_put(p->mlx, p->win, (WIDTH / 2) + 180, 90,
		0xFFFFFFF, str);
	str = p->p1;
	mlx_string_put(p->mlx, p->win, (WIDTH / 2) + 330, 60,
		0xFFFFFF, str);
	str = p->p2;
	mlx_string_put(p->mlx, p->win, (WIDTH / 2) + 120, 60,
		0xFFFFFF, str);
}
