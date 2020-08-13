#include "../includes/visualiser.h"

void		draw_background(t_env *p)
{
	int		i;

	i = 0;
	while (i < (HEIGHT * WIDTH * 4))
	{
		(p->ret)[i] = 52;
		(p->ret)[i + 1] = 52;
		(p->ret)[i + 2] = 52;
		(p->ret)[i + 3] = 0;
		i += 4;
	}
}

void		draw_menu(t_env *p)
{
	int		width;

	width = WIDTH;
	p->red = 24;
	p->green = 24;
	p->blue = 24;
	p->size.width = 50;
	p->size.height = HEIGHT;
	draw_rectangle(WIDTH / 2, 0, p);
	draw_rectangle(WIDTH - p->size.width, 0, p);
	p->size.width = WIDTH;
	p->size.height = 50;
	draw_rectangle(0, 0, p);
	draw_rectangle(0, HEIGHT - p->size.height, p);
	p->size.width = WIDTH / 2;
	p->size.height = HEIGHT;
	draw_rectangle(0, 0, p);
}

void		tug_of_war(t_env *p)
{
	calc_score(p);
	modif_color(238, 152, 12, p);
	p->size.width = 330;
	p->size.height = 15;
	draw_rectangle((WIDTH / 2) + 120, 120, p);
}

// void		tug_of_war(t_env *p)
// {
// 	int		scorep1;
// 	int		scorep2;

// 	calc_score(p);
// 	scorep1 = p->scorep1 / (p->scorep1 + p->scorep2);
// 	scorep2 = p->scorep2 / (p->scorep1 + p->scorep2);
// 	modif_color(238, 152, 12, p);
// 	p->size.width = 330 * scorep1;
// 	p->size.height = 15;
// 	draw_rectangle((WIDTH / 2) + 120, 120, p);
// 	// modif_color(81, 172, 154, p);
// 	// p->size.width = 330 * scorep2;
// 	// p->size.height = 15;
// 	// draw_rectangle((WIDTH / 2) + 120 + (330 * scorep1), 120, p);
// }

void		draw_score(t_env *p)
{
	char	*str;

	calc_score(p);
	modif_color(238, 152, 12, p);
	p->size.width = 150;
	p->size.height = ((HEIGHT / 3) * (p->scorep1 / (p->map_size_x * p->map_size_y)));
	draw_rectangle((WIDTH / 2) + 330, (HEIGHT / 2) + 170, p);
	modif_color(81, 172, 154, p);
	p->size.width = 150;
	p->size.height = ((HEIGHT / 3) * (p->scorep2 / (p->map_size_x * p->map_size_y)));
	draw_rectangle((WIDTH / 2) + 120, (HEIGHT / 2) + 170, p);
}

void		draw_map(t_env *p)
{
	int		i;
	int		i2;
	int		s;

	p->size.height = ((WIDTH / 2) / (p->map_size_x)) - 2;
	p->size.width = ((WIDTH / 2) / (p->map_size_x)) - 2;
	s = ((WIDTH / 2) / (p->map_size_x)) - 2;
	i = -1;
	while (++i < p->map_size_y)
	{
		i2 = -1;
		while (++i2 < p->map_size_x)
		{
			if (p->map[i][i2] == '.')
				modif_color(0, 0, 0, p);
			else if (p->map[i][i2] == 'X' || p->map[i][i2] == 'x')
				modif_color(81, 172, 154, p);
			else if (p->map[i][i2] == 'O' || p->map[i][i2] == 'o')
				modif_color(238, 152, 12, p);
			draw_rectangle((i2 * s) + (i2 * 2) + 2, (i * s) + (i * 2) +
				((600 - (p->map_size_y * s) - (p->map_size_y * 2)) / 2), p);
		}
	}
}

void		draw(t_env *p)
{
	draw_background(p);
	draw_menu(p);
	// draw_score(p);
	tug_of_war(p);
	draw_map(p);
}
