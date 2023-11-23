/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_game_bn.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoumni <tmoumni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 14:45:59 by tmoumni           #+#    #+#             */
/*   Updated: 2023/11/23 15:12:38 by tmoumni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

void	init_game(t_game *g, t_player*player, t_img *img)
{
	g->width = 1200;
	g->height = 600;
	if (g->width < 0 || g->height < 0 || g->width > 2560 || g->height > 1440)
		_error("Error\nInvalid Resolution\n");
	g->mini_map_w = g->width / 5;
	g->mini_map_h = g->height / 5;
	g->win = mlx_new_window(g->mlx, g->width, g->height, "./cub3D_bonus");
	g->scale = 0.2;
	g->player = player;
	g->img = img;
	g->img->mlx_img = mlx_new_image(g->mlx, g->width, g->height);
	g->img->addr = (int *)mlx_get_data_addr(g->img->mlx_img, &g->img->bpp, 
			&g->img->line_len, &g->img->endian);
	g->mini_map = malloc(sizeof(t_img));
	if (!g->mini_map)
		return ;
	g->mini_map->mlx_img = mlx_new_image(g->mlx, g->mini_map_w, g->mini_map_h);
	g->mini_map->addr = (int *)mlx_get_data_addr(g->mini_map->mlx_img, 
			&g->mini_map->bpp, &g->mini_map->line_len, &g->mini_map->endian);
}
