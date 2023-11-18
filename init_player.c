/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhaliss <akhaliss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 18:33:54 by tmoumni           #+#    #+#             */
/*   Updated: 2023/11/18 11:53:08 by akhaliss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

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

void	set_player_direction(t_game *game, char direction)
{
	if (direction == 'N')
		game->player->dir = deg_to_rad(270);
	else if (direction == 'S')
		game->player->dir = deg_to_rad(90);
	else if (direction == 'W')
		game->player->dir = deg_to_rad(180);
	else
		game->player->dir = deg_to_rad(0);
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
		set_player_direction(game, game->map[i][j]);
	}
	return (position);
}

void	init_player(t_game *game)
{
	game->player->x = (get_player_position(game) % game->m_w) * DM + DM / 2;
	game->player->y = (get_player_position(game) / game->m_w) * DM + DM / 2;
	// game->player->dir = -M_PI;
	game->player->fov = 60;
	game->player->walk_dir = 0;
	game->player->turn_dir = 0;
	game->player->walk_speed = 2.5;
	game->player->turn_speed = 2.5;
	game->player->lf = 0;
}
