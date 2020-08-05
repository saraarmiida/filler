#include "../includes/filler.h"

static int		get_new_height(int piece_h, char **piece)
{
	int	new_h;
	int	y;

	new_h = 0;
	y = 0;
	while (y < piece_h)
	{
		if (ft_strchr(piece[y], '*') != NULL)
			new_h++;
		y++;
	}
	return(new_h);
}

static int		get_new_width(int piece_h, int piece_w, char **piece)
{
	int	new_w;
	int	y;
	int	x;

	new_w = 0;
	x = 0;
	while (x < piece_w)
	{
		y = 0;
		while (y < piece_h)
		{
			if (piece[y][x] == '*')
			{
				new_w++;
				break;
			}
			y++;
		}
		x++;
	}
	return(new_w);
}

void	trim_piece(t_info *i)
{
	int		y;
	char	**new_piece;
	int		y_temp;

	y_temp = get_new_height(i->piece_h, i->piece);
	i->piece_w = get_new_width(i->piece_h, i->piece_w, i->piece);
	i->piece_h = y_temp;
	y = 0;
	y_temp = i->piece_off.y;
	new_piece = (char**)malloc(sizeof(char*) * i->piece_h + 1);
	while (y < i->piece_h)
	{
		new_piece[y] = ft_strndup((const char*)i->piece[y_temp] + i->piece_off.x, i->piece_w);
		y_temp++;
		y++;
	}
	new_piece[y] = NULL;
	free_token(i->piece);
	i->piece = new_piece;
}