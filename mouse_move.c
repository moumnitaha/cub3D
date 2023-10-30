/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_move.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoumni <tmoumni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 18:33:24 by tmoumni           #+#    #+#             */
/*   Updated: 2023/10/30 19:17:00 by tmoumni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int mouse_move(int x, int y, t_game *game)
{
	if (x > 0 && y > 0 && y < game->height && x < game->width)
	{
		game->player->dir = atan2((y - game->player->y) / 10, (x - game->player->x) / 10);
		// printf("Angle => [%f]\n", game->player->dir);
		mainDraws(game);
	}
    return 0;
}