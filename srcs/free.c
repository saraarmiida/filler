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
	print_to_file("    			free token point 1");
	while (i < h)
	{
		ft_strdel(&token[i]);
		print_to_file("    			free token point 2");
		i++;
	}
	print_to_file("    			free token point 3");
	free(token);
	print_to_file("    			free token point 4");
}

void	free_board(const char **token, int h, int w)
{
	int		i;
	char	*str;

	if (!token)
		return ;
	i = 0;
	print_to_file("    			free board point 1");
	print_map(token, h);
	while (i < h)
	{
		print_to_file("    			free board point 1.1");
		print_to_file((char *)token[i] - 4);
		str = (char *)token[i] - 4;
		if (ft_strlen(str) == (size_t)w)
			ft_strdel(&str);
		print_to_file("    			free board point 2");
		i++;
	}
	print_to_file("    			free board point 3");
	free(token);
	print_to_file("    			free board point 4");
}

void	free_all(t_info *i)
{
	print_to_file("    		free point 1");
	free_int_arr(i->hmap, i->board_h);
	print_to_file("    		free point 2");
	free_board(i->board, i->board_h, i->board_w);
	print_to_file("    		free point 3");
	free_token(i->piece, i->piece_h);
	print_to_file("    		free point 4");
}
