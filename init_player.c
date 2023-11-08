/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoumni <tmoumni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 18:33:54 by tmoumni           #+#    #+#             */
/*   Updated: 2023/11/08 14:46:09 by tmoumni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	get_player_position(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < game->m_h)
	{
		j = 0;
		while (j < game->m_w)
		{
			if (game->map[i][j] == 'N')
				return (i * game->m_w + j);
			j++;
		}
		i++;
	}
	return (-1);
}

void	init_player(t_game *game)
{
	game->player->x = (get_player_position(game) % game->m_w) * DM + DM / 2;
	game->player->y = (get_player_position(game) / game->m_w) * DM + DM / 2;
	game->player->dir = -M_PI;
	game->player->fov = 60;
	game->player->walk_dir = 0;
	game->player->turn_dir = 0;
	game->player->walk_speed = 2.5;
	game->player->turn_speed = 2.5;
	game->player->lf = 0;
}
