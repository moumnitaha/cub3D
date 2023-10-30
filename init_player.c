/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoumni <tmoumni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 18:33:54 by tmoumni           #+#    #+#             */
/*   Updated: 2023/10/30 18:47:21 by tmoumni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

// void	init_player(t_game *game)
// {
// 	game->player->x = 0;
// 	game->player->y = 0;
// 	game->player->dir = 0;
// 	game->player->walkDirection = 0;
// 	game->player->turnDirection = 0;
// 	game->player->rotationAngle = 0;
// 	game->player->moveSpeed = 5.0;
// 	game->player->rotationSpeed = 3 * (M_PI / 180);
// }

int get_player_position()
{
	for (int i = 0; i < MAX_ROWS; i++)
	{
		for (int j = 0; j < MAX_COLS; j++)
		{
			if (map[i][j] == 'P')
				return i * MAX_COLS + j;
		}
	}
	return -1;
}