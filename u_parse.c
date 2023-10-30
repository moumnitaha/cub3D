/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   u_parse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhaliss <akhaliss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 09:40:20 by akhaliss          #+#    #+#             */
/*   Updated: 2023/10/30 13:57:08 by akhaliss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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

int	ft_open(char *file, int perm, t_data *game)
{
	int	fd;
	int	fd_len;
	// t_data	*game;

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
	game->mlen = fd_len;
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
    int j;
	char *key ;
	int	key_length;

    i = 0;
    while (line[i])
	{
        if ((i == 0 || line[i - 1] == ' ') && line[i] != ' ' && line[i] != '\n')
		{
            j = i + 1;
            while (line[j] && line[j] != ' ')
                j++;
			key_length = j - i;
			key = malloc(key_length + 1);
			if (!key)
				return(0);
            ft_strlcpy(key, line + i, key_length + 1);
            if (ft_strcmp(key, "NO") == 0 || ft_strcmp(key, "SO") == 0 || ft_strcmp(key, "WE") == 0
				|| ft_strcmp(key, "EA") == 0 || ft_strcmp(key, "F") == 0 || ft_strcmp(key, "C") == 0)
                return(free(key), _line(game, line + j, j - i));
            else
                _error("Error: Invalid Format\n");
        }
        i++;
    }
    return (0);
}

void	fill_spaces(t_data *game, size_t len, char **map)
{
	int j;
	int	i;

	j = -1;
	printf("lenn : %zu\n", len);
	game->map = malloc(sizeof(char *) * game->mlen);
	while(game->map[++j])
		// printf("%s\n", game->map[j]);
		game->map[j] = malloc(sizeof(char) * len);
	j = -1;
	i = -1;
	while(map[++j])
	{
		while(map[j][++i] && ft_strlen(&map[j][i]) < len)
		{
			if(map[j][i] == ' ' || map[j][i] == '\t')
				map[j][i] = 'X';
		}
	}
	game->map = map;
	j = -1;
	// i = -1;
	while(game->map[++j])
	{
		// while(game->map[j][++i])
		// {
			printf("%s\n", game->map[j]);
		// }
	}	
}

void	read_map(char *file, t_data *game)
{
	int	fd;
	int	i;
	char	*l_map;
	char	*line;
	char	**map;

	i = 0;
	l_map = ft_strdup("");
	fd = ft_open(file, O_RDONLY, game);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break;
		if (i >= 6)
		{
			if (_spaces(line))
				write(2, "Map not found\n", 14);
			
			l_map = ft_strjoin(l_map, line);
			i++;
		}
		else if (!_spaces(line) && i < 6)
			i += get_info(game, line);
	}
	map = ft_split(l_map, '\n');
	int j = 0;
	free(l_map);
	size_t len = ft_strlen(map[0]);
	while(map[++j])
	{
		if (ft_strlen(map[j]) > len)
			len = ft_strlen(map[j]);
	}
	// j = -1;
	// while(map[++j])
	// {
		// if(ft_strlen(map[j]) < len)
		// printf("%s\n", map[j]);
	fill_spaces(game, len, map);
	// }
	printf("len : %zu\n", len);
}
