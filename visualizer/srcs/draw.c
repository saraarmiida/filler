#include "../includes/visualizer.h"

void	draw_background(t_visu *p)
{
	int i;

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

void	draw_rectangle(int x, int y, t_visu *p)
{
	int		i;
	int		i2;
	int		t;

	i2 = 0;
	t = 0;
	while (i2 < (p->height * 4))
	{
		i = 0;
		while (i < (p->width * 4))
		{
			p->ret[i + t + ((y * WIDTH * 4) + (x * 4))] = p->red;
			p->ret[i + t + 1 + ((y * WIDTH * 4) + (x * 4))] = p->green;
			p->ret[i + t + 2 + ((y * WIDTH * 4) + (x * 4))] = p->blue;
			p->ret[i + t + 3 + ((y * WIDTH * 4) + (x * 4))] = 0;
			i += 4;
		}
		i2 += 4;
		t += (WIDTH * 4);
	}
}

void	draw_menu(t_visu *p)
{
	int		width;

	width = WIDTH;
	p->red = 24;
	p->green = 24;
	p->blue = 24;
	p->width = 50;
	p->height = HEIGHT;
	draw_rectangle(WIDTH / 2, 0, p);
	draw_rectangle(WIDTH - p->width, 0, p);
	p->width = WIDTH;
	p->height = 50;
	draw_rectangle(0, 0, p);
	draw_rectangle(0, HEIGHT - p->height, p);
	p->width = WIDTH / 2;
	p->height = HEIGHT;
	draw_rectangle(0, 0, p);
}

void	draw_map(t_visu *p)
{
	draw_background(p);
	draw_menu(p);
}
