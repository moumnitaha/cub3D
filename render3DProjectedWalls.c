/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render3DProjectedWalls.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoumni <tmoumni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 18:30:29 by tmoumni           #+#    #+#             */
/*   Updated: 2023/10/30 18:48:15 by tmoumni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void render3DProjectedWalls(t_game *game, double wallStripHeight, int X, int color)
{
	wallStripHeight = round(wallStripHeight);
	if (wallStripHeight > game->height)
		wallStripHeight = game->height;
	int i = 0;
	for (i = 0; i < (game->height - wallStripHeight) / 2; i++)
	{
		mlx_pixel_put(game->mlx, game->win, X, i, bluesky);
	}
	for (i = 0; i <= wallStripHeight; i++)
	{
		mlx_pixel_put(game->mlx, game->win, X, ((game->height  - wallStripHeight) / 2) + i, color);
	}
	for (i = 0; i < (game->height - wallStripHeight) / 2; i++)
	{
		mlx_pixel_put(game->mlx, game->win, X, game->height - i, white);
	}
}