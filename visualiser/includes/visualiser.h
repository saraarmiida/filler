#ifndef VISUALISER_H
# define VISUALISER_H

# include <stdlib.h>
# include <string.h>
# include <unistd.h>
# include <fcntl.h>
# include "../../libft/libft/includes/libft.h"
# include "../../libft/ft_printf/includes/ft_printf.h"
# include "../../includes/filler.h"
# define WIDTH 800
# define HEIGHT 1000
# define ESC	53
# define WINDOW_NAME "FILLER"

typedef struct	s_size
{
	int			width;
	int			height;
}				t_size;

typedef struct		s_env
{
	char			*p1;
	char			*p2;
	float			scorep1;
	float			scorep2;
	char			**map;
	t_size			size;
	int				red;
	int				green;
	int				blue;
	int				map_size_x;
	int				map_size_y;
	char			*ret;
	void			*ret2;
	void			*win;
	void			*mlx;
	void			*img;
	void			*img2;
	int				bits_per_pixel;
	int				size_line;
	int				endian;
	int				pause;
}					t_env;

/*
** ------ MAIN.C ------
*/

int					main(void);
void				init_env(t_env *p);
int					mouse_hook(int button, int x, int y, t_env *p);
int					key_hook(int keycode, t_env *p);

/*
** ------ INPUT_SCAN.C ------
*/

void				get_input(t_env *p);

/*
** ------ DRAWING_MODE.C ------
*/

void				draw(t_env *p);

/*
** ------ TOOLS.C ------
*/

void				draw_rectangle(int start_x, int start_y, t_env *p);
void				print_final(t_env *p);
int					is_number(char c);
void				modif_color(int r, int v, int b, t_env *p);
void				calc_score(t_env *p);

#endif
