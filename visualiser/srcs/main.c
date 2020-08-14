#include "../includes/visualiser.h"

static int	loop_key_hook(t_env *p)
{
	char	*str;

	if (p->pause == 0)
	{
		p->ret = mlx_get_data_addr(p->img, &(p->bits_per_pixel),
		&(p->size_line), &(p->endian));
		get_input(p);
		draw(p);
		mlx_put_image_to_window(p->mlx, p->win, p->img, 0, 0);
		mlx_destroy_image(p->mlx, p->img);
		p->img = mlx_new_image(p->mlx, WIDTH, HEIGHT);
		print_score(p);
	}
	if (p->pause == 1)
	{
		str = "PAUSE";
		mlx_string_put(p->mlx, p->win, (WIDTH / 2) - 10, (HEIGHT / 2) - 1,
			0x0FFFFFF, str);
	}
	return (0);
}

int			key_hook(int keycode, t_env *p)
{
	int		i;
	int		j;

	i = 1;
	if (keycode == ESC)
	{
		free_map(p->map);
		free(p);
		exit(1);
	}
	loop_key_hook(p);
	return (0);
}

int			mouse_hook(int button, int x, int y, t_env *p)
{
	if (button == 1)
		p->pause = p->pause == 0 ? 1 : 0;
	loop_key_hook(p);
	return (0);
}

void		init_env(t_env *p)
{
	p->pause = 0;
	p->red = 0;
	p->green = 0;
	p->blue = 0;
	p->map = NULL;
	p->scorep1 = 0;
	p->scorep2 = 0;
	p->map_size_x = 0;
	p->map_size_y = 0;
}

int			main(void)
{
	t_env	*p;

	p = (t_env *)malloc(sizeof(t_env));
	init_env(p);
	p->mlx = mlx_init();
	p->win = mlx_new_window(p->mlx, WIDTH, HEIGHT, WINDOW_NAME);
	p->img = mlx_new_image(p->mlx, WIDTH, HEIGHT);
	mlx_hook(p->win, 2, 2, key_hook, p);
	mlx_mouse_hook(p->win, mouse_hook, p);
	loop_key_hook(p);
	mlx_loop_hook(p->mlx, loop_key_hook, p);
	free_map(p->map);
	mlx_loop(p->mlx);
	free(p);
	return (0);
}
