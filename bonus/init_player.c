/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoumni <tmoumni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 18:33:54 by tmoumni           #+#    #+#             */
/*   Updated: 2023/11/21 14:38:46 by tmoumni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

bool	check_map_chars(t_game *game)
{
	int	i;
	int	j;

	i = -1;
	while (++i < game->m_h)
	{
		j = -1;
		while (++j < game->m_w)
		{
			if (game->map[i][j] != '1' && game->map[i][j] != '0' 
				&& game->map[i][j] != ' '
				&& game->map[i][j] != 'N' && game->map[i][j] != 'S' 
				&& game->map[i][j] != 'W'
				&& game->map[i][j] != 'E')
				return (false);
		}
	}
	return (true);
}

int	get_chars_num(t_game *game)
{
	int	i;
	int	j;
	int	num;

	num = 0;
	i = -1;
	while (++i < game->m_h)
	{
		j = -1;
		while (++j < game->m_w)
		{
			if (game->map[i][j] == 'N' || game->map[i][j] == 'S' 
				|| game->map[i][j] == 'W' || game->map[i][j] == 'E')
				num++;
		}
	}
	return (num);
}

int	find_player_position(t_game *game)
{
	int	i;
	int	j;

	i = -1;
	while (++i < game->m_h)
	{
		j = -1;
		while (++j < game->m_w)
		{
			if (game->map[i][j] == 'N' || game->map[i][j] == 'S'
				|| game->map[i][j] == 'W' || game->map[i][j] == 'E')
				return (i * game->m_w + j);
		}
	}
	return (-1);
}

int	get_player_position(t_game *game)
{
	int	i;
	int	position;
	int	j;

	position = find_player_position(game);
	if (position != -1)
	{
		i = position / game->m_w;
		j = position % game->m_w;
		if (game->map[i][j] == 'N')
			game->player->dir = deg_to_rad(270);
		else if (game->map[i][j] == 'S')
			game->player->dir = deg_to_rad(90);
		else if (game->map[i][j] == 'W')
			game->player->dir = deg_to_rad(180);
		else
			game->player->dir = deg_to_rad(0);
	}
	return (position);
}

void	init_player(t_game *game)
{
	double	x;
	double	y;

	if (!check_map_chars(game) || get_chars_num(game) != 1)
	{
		ft_putstr_fd("Error\nInvalid map\n", 2);
		exit(0);
	}
	x = (get_player_position(game) % game->m_w) * DM + (DM / 2);
	y = (get_player_position(game) / game->m_w) * DM + (DM / 2);
	game->player->x = x;
	game->player->y = y;
	game->player->m_x = x;
	game->player->m_y = y;
	game->player->fov = 60;
	game->player->walk_dir = 0;
	game->player->turn_dir = 0;
	game->player->walk_speed = 1.75 + (DM / 15);
	game->player->turn_speed = 2;
	game->player->lf = 0;
}
