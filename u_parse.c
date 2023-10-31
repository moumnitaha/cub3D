/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   u_parse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhaliss <akhaliss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 09:40:20 by akhaliss          #+#    #+#             */
/*   Updated: 2023/10/31 12:57:07 by akhaliss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	ft_open(char *file, int perm, t_game *game)
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
	game->mlen = fd_len;
	close(fd);
	fd = open(file, perm);
	return (fd);
}

int get_info(t_game *game, char *line)
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
				return (0);
            ft_strlcpy(key, line + i, key_length + 1);
            if (ft_strcmp(key, "NO") == 0 || ft_strcmp(key, "SO") == 0
				|| ft_strcmp(key, "WE") == 0|| ft_strcmp(key, "EA") == 0
				|| ft_strcmp(key, "F") == 0 || ft_strcmp(key, "C") == 0)
                return(free(key), _line(game, line + j, j - i));
            else
                _error("Error: Invalid Format\n");
        }
        i++;
    }
    return (0);
}


void fill_spaces(t_game *game, size_t len, char **map)
{
    size_t j;
    size_t i;

    game->map = malloc(sizeof(char *) * (game->mlen + 1));
    if (!game->map)
        return ;
    j = -1;
    while (map[++j])
    {
        game->map[j] = malloc(len + 1);
        if (game->map[j] == NULL)
            return ;
        i = 0;
		while (i < len)
        {
            if (i < ft_strlen(map[j]))
            {
                if (map[j][i] == ' ' || map[j][i] == '\t')
                    game->map[j][i] = 'X';
                else
                    game->map[j][i] = map[j][i];
            }
            else
                game->map[j][i] = 'X';
            i++;
        }
        game->map[j][i] = '\0';
    }
    game->map[j] = NULL;
	free(map);
	j = -1;
	printf("len : %zu\n" ,ft_strlen(game->map[++j]));
    while (game->map[++j])
    {
        printf("%s\n", game->map[j]);
    }
	
}

void	_map(char **map, t_game *game)
{
	size_t len;
	int		j;

	j = 0;
	len = ft_strlen(map[0]);
	while(map[++j])
	{
		if (ft_strlen(map[j]) > len)
			len = ft_strlen(map[j]);
	}
	fill_spaces(game, len, map);
}

void	read_map(char *file, t_game *game)
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
	free(l_map);
	free(line);
	close(fd);
	_map(map, game);
}
