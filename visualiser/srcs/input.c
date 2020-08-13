#include "../includes/visualiser.h"

char			*get_player_name(char *line)
{
	int	i;
	int	off;

	i = 14;
	while (line[i] != '/' && line[i])
		i++;
	off = i + 1;
	while (line[i])
	{
		if (line[i] == '.')
			break ;
		i++;
	}
	return (ft_strsub((const char *)line, off, i - off));
}

void			fetch_player_name(char *line, t_env *p)
{
	if (line[9] == 'p' && line[10] == '1')
		p->p1 = get_player_name(line);
	if (line[9] == 'p' && line[10] == '2')
		p->p2 = get_player_name(line);
	ft_strdel(&line);
}

void			fetch_map(char *s_line, t_env *p)
{
	int		y;
	char	*line;

	y = 0;
	p->map_size_y = ft_atoi(&s_line[8]);
	p->map_size_x = ft_atoi(s_line + 8 + ft_intlen(p->map_size_y) + 1);
	ft_strdel(&s_line);
	get_next_line(0, &line);
	ft_strdel(&line);
	p->map = (char**)malloc(sizeof(char*) * p->map_size_y + 1);
	while (y < p->map_size_y && get_next_line(0, &line) == 1)
	{
		p->map[y] = ft_strdup((const char*)&line[4]);
		ft_strdel(&line);
		y++;
	}
	p->map[y] = NULL;
}

void			get_input(t_env *p)
{
	char *line;

	while (get_next_line(0, &line) == 1)
	{
		if (ft_strncmp(line, "$$$", 2) == 0)
			fetch_player_name(line, p);
		if (ft_strncmp(line, "Plateau", 6) == 0)
			fetch_map(line, p);
		if (ft_strncmp(line, "Piece", 4) == 0)
		{
			ft_strdel(&line);
			return ;
		}
	}
}
