/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   u_parse.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhaliss <akhaliss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 09:40:20 by akhaliss          #+#    #+#             */
/*   Updated: 2023/10/31 15:59:34 by akhaliss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	get_info(t_game *game, char *line)
{
	int		i;
	int		j;
	char	*key ;

	i = -1;
	while (line[++i])
	{
		if ((i == 0 || line[i - 1] == ' ') && line[i] != ' ' && line[i] != '\n')
		{
			j = i + 1;
			while (line[j] && line[j] != ' ')
				j++;
			key = malloc((j - i) + 1);
			if (!key)
				return (0);
			ft_strlcpy(key, line + i, (j - i) + 1);
			if (ft_strcmp(key, "NO") == 0 || ft_strcmp(key, "SO") == 0
				|| ft_strcmp(key, "WE") == 0 || ft_strcmp(key, "EA") == 0
				|| ft_strcmp(key, "F") == 0 || ft_strcmp(key, "C") == 0)
				return (free(key), _line(game, line + j, j - i));
			else
				_error("Error: Invalid Format\n");
		}
	}
	return (0);
}

void	fill_spaces(t_game *game, size_t len, char **map)
{
	size_t	j;
	size_t	i;

	printf("mlen : %d\n", game->mlen);
	game->map = malloc(sizeof(char *) * (game->mlen + 1));
	if (!game->map)
		return ;
	j = -1;
	while (map[++j])
	{
		game->map[j] = malloc(len + 1);
		if (game->map[j] == NULL)
			return ;
		i = -1;
		while (++i < len)
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
		}
		game->map[j][i] = '\0';
	}
	game->map[j] = NULL;
	free(map);
	// int i = -1;
	// while ()
}

void	_map(char **map, t_game *game)
{
	size_t	len;
	int		j;

	j = 0;
	len = ft_strlen(map[0]);
	while (map[++j])
	{
		if (ft_strlen(map[j]) > len)
			len = ft_strlen(map[j]);
	}
	fill_spaces(game, len, map);
}

char	*read_line(char *file, t_game *game)
{
	int		fd;
	int		i;
	char	*line;
	char	*l_map;

	i = 0;
	l_map = ft_strdup("");
	fd = ft_open(file, O_RDONLY, game);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
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
	return (free(line), close(fd), l_map);
}

void	read_map(char *file, t_game *game)
{
	char	*l_map;

	l_map = read_line(file, game);
	_map(ft_split(l_map, '\n'), game);
	free(l_map);
}
