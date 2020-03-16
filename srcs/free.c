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

void	free_token(t_piece *token)
{
	int		i;

	if (!token->data || !token)
		return ;
	i = 0;
	while (i < token->h)
	{
		ft_strdel(&token->data[i]);
		i++;
	}
	free(token->data);
	free(token);
}

void	free_all(t_info *i)
{
	free_int_arr(i->hmap, i->board->h);
	free_token(i->board);
	free_token(i->piece);
}
