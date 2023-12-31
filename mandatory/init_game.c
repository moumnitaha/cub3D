/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoumni <tmoumni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 14:45:59 by tmoumni           #+#    #+#             */
/*   Updated: 2023/11/23 15:13:19 by tmoumni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	init_game(t_game *g, t_player*player, t_img *img)
{
	g->width = 1200;
	g->height = 600;
	if (g->width < 0 || g->height < 0 || g->width > 2560 || g->height > 1440)
		_error("Error\nInvalid Resolution\n");
	g->mini_map_w = g->width / 5;
	g->mini_map_h = g->height / 5;
	g->win = mlx_new_window(g->mlx, g->width, g->height, "./cub3D");
	g->scale = 0.2;
	g->player = player;
	g->img = img;
	g->img->mlx_img = mlx_new_image(g->mlx, g->width, g->height);
	g->img->addr = (int *)mlx_get_data_addr(g->img->mlx_img, &g->img->bpp, 
			&g->img->line_len, &g->img->endian);
}
