/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render3DProjectedWalls.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoumni <tmoumni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 18:30:29 by tmoumni           #+#    #+#             */
/*   Updated: 2023/10/31 10:42:57 by tmoumni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	render_3d_walls(t_game *g, double wall_height, int x, int clr)
{
	int	i;
	int	height;

	wall_height = round(wall_height);
	if (wall_height > g->height)
		wall_height = g->height;
	i = 0;
	while (i < (g->height - wall_height) / 2)
	{
		mlx_pixel_put(g->mlx, g->win, x, i, BLUESKY);
		i++;
	}
	i = 0;
	height = (g->height - wall_height) / 2;
	while (i <= wall_height)
	{
		mlx_pixel_put(g->mlx, g->win, x, height + i, clr);
		i++;
	}
	i = 0;
	while (i < (g->height - wall_height) / 2)
	{
		mlx_pixel_put(g->mlx, g->win, x, g->height - i, WHITE);
		i++;
	}
}
