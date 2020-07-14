#include "../includes/visualizer.h"

static void	get_map_size(t_visu *p, char *line)
{
	int		off;

	off = ft_strncmp(line, "Plateau", 7) == 0 ? 8 : 6;
	p->map_size_y = ft_atoi(&line[off]);
	p->map_size_x = ft_atoi(line + off + ft_intlen(p->map_size_y) + 1);
}

static void	get_map(t_visu *p, char *line)
{
	int			i;

	get_map_size(p, line);
	ft_strdel(&line);
	get_next_line(0, &line);
	ft_strdel(&line);
	i = 0;
	p->map = (char**)malloc(sizeof(char*) * p->map_size_y + 1);
	while (i < p->map_size_y && get_next_line(0, &line) == 1)
	{
		p->map[i] = ft_strdup((const char*)&line[4]);
		ft_strdel(&line);
		i++;
	}
	p->map[i] = NULL;
}

static void	get_player(t_visu *p, char *line)
{
	int i;

	i = 23;
	while (line[i] != '.')
		i++;
	if (line[10] == 1)
		p->p1 = ft_strsub((const char *)line, 23, i - 23);
	if (line[10] == 2)
		p->p2 = ft_strsub((const char *)line, 23, i - 23);
	ft_strdel(&line);
}

void		readinput(t_visu *p)
{
	char	*line;

	print_file("	kukka1");
	while (get_next_line(0, &line) == 1)
	{
		print_file(line);
		if (ft_strncmp(line, "$$$ exec p", 9) == 0)
		{
			get_player(p, line);
		}
		else if (ft_strncmp(line, "Plateau", 7) == 0)
		{
			get_map(p, line);
		}
		else if (ft_strncmp(line, "Piece", 5) == 0)
		{
			ft_strdel(&line);
			return ;
		}
		else
			ft_strdel(&line);
	}
}
