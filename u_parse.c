#include "cub3D.h"

int	maplen(int fd)
{
	char	*line;
	int		count;

	count = 0;
	line = get_next_line(fd);
	while (line != NULL)
	{
		free(line);
		line = get_next_line(fd);
		count++;
	}
	free(line);
	return (count);
}

int	ft_open(char *file, int perm)
{
	int	fd;
	int	fd_len;

	fd = open(file, perm);
	if (fd < 0)
	{
		write(2, "Wrong file\n", 11);
		exit(1);
	}
	fd_len = maplen(fd);
	if (!fd_len)
	{
		write(2, "Empty file\n", 11);
		exit(1);
	}
	close(fd);
	fd = open(file, perm);
	return (fd);
}

static int	_spaces(char *line)
{
	while (*line)
	{
		if (*line != ' ' || *line != '\t'
			|| *line != '\n')
			return (0);
		line++;
	}
	return (1);
}

int get_info(t_data *game, char *line)
{
    int i;
    int flag;
    int j;

    flag = 0;
    i = 0;
    while (line[i])
    {
        if ((i == 0 || line[i - 1] == ' ') && line[i] != ' ' && line[i] != '\n')
        {
            j = i + 1;
            while (line[j] && line[j] != ' ')
                j++;
            if (j - i == 2)
            {
                flag = _line(game, line + j);
            }
        }
        i++;
    }
    return (flag);
}

void	read_map(char *file, t_data *game)
{
	int	fd;
	int	i;
	char	*map;
	char	*line;

	i = 0;
	map = ft_strdup("");
	fd = ft_open(file, O_RDONLY);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break;
		if (!_spaces(line) && i < 6)
			i += get_info(game, line);
		else if (i >= 6)
		{
			if (_spaces(line))
				write(2, "Map not found\n", 14);
			map = ft_strjoin(map, line);
			i++;
		}
	}
	game->map = ft_split(map, '\n');
}
