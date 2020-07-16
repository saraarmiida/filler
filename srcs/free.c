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

void	free_token(char **str)
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

void	free_board(const char **token, int h, int w)
{
	int		i;
	char	*str;

	if (!token)
		return ;
	i = 0;
	while (i < h)
	{
		str = (char *)token[i] - 4;
		if (ft_strlen(str) == (size_t)w)
			ft_strdel(&str);
		i++;
	}
	free(token);
}

void	free_all(t_info *i)
{
	free_int_arr(i->hmap, i->board_h);
	print_to_file("heat freed");
	print_map(i->board, i->board_h);
	free_board(i->board, i->board_h, i->board_w);
	print_to_file("board freed");
	free_token(i->piece);
	print_to_file("piece freed");
}
