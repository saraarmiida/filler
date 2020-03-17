#include "../includes/filler.h"

void	free_int_arr(int **arr, int h)
{
	int	i;

	i = 0;
    if (!arr)
		return ;
	while (i < h)
	{
		free(arr[i]);
		i++;
	}
	free(arr);
}

void	free_token(char **token, int h)
{
	int		i;

	if (!token)
		return ;
	i = 0;
	while (i < h)
	{
		ft_strdel(&token[i]);
		i++;
	}
	free(token);
}

void	free_all(t_info *i)
{
	free_int_arr(i->hmap, i->board_h);
	free_token(i->board, i->board_h);
	free_token(i->piece, i->piece_h);
}
