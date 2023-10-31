/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoumni <tmoumni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 18:33:54 by tmoumni           #+#    #+#             */
/*   Updated: 2023/10/31 17:03:43 by tmoumni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	get_player_position(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < MAX_ROWS)
	{
		j = 0;
		while (j < MAX_COLS)
		{
			if (game->map[i][j] == 'N')
				return (i * MAX_COLS + j);
			j++;
		}
		i++;
	}
	return (-1);
}

void	init_player(t_game *game)
{
	game->player->x = (get_player_position(game) % MAX_COLS) * DM + DM / 2;
	game->player->y = (get_player_position(game) / MAX_COLS) * DM + DM / 2;
	game->player->dir = -M_PI_2;
	game->player->fov = 60;
	game->player->walk_dir = 0;
	game->player->turn_dir = 6;
}
