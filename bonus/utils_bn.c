/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bn.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoumni <tmoumni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 18:19:35 by akhaliss          #+#    #+#             */
/*   Updated: 2023/11/23 13:26:43 by tmoumni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

void	_error(char *err)
{
	ft_putstr_fd(err, 2);
	exit(1);
}

int	_spaces(char *line)
{
	while (*line)
	{
		if (*line != ' ' && *line != '\t'
			&& *line != '\n')
			return (0);
		line++;
	}
	return (1);
}

int	p_name(char *s)
{
	int	i;

	i = ft_strlen(s);
	if (s[i - 1] == 'b' && s[i - 2] == 'u'
		&& s[i - 3] == 'c' && s[i - 4] == '.')
		return (1);
	return (0);
}

void	init_map(t_game *game)
{
	game->ceilling_c = -1;
	game->floor_c = -1;
	game->no_txt = NULL;
	game->ea_txt = NULL;
	game->so_txt = NULL;
	game->we_txt = NULL;
	game->m_h = 0;
	game->m_w = 0;
}

int	cub(char *av, t_game *game)
{
	int	i;

	i = 0;
	if (!p_name(av))
		return (free(game), _error("Error\nInvalid map name\n"), 0);
	init_map(game);
	read_map(av, game);
	if (!is_surrounded_by_walls(game))
	{
		if (!game->map[0])
			_error("Error\nMap not found\n");
		else
			_error("Error\nThe map is not completely surrounded by walls.\n");
		free_mem(game);
		return (0);
	}
	return (1);
}
