/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_mem_bn.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoumni <tmoumni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 15:12:23 by tmoumni           #+#    #+#             */
/*   Updated: 2023/11/23 13:25:47 by tmoumni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

void	free_mem(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->m_h)
	{
		free(game->map[i]);
		i++;
	}
	free(game->map);
	free(game->so_txt);
	free(game->no_txt);
	free(game->we_txt);
	free(game->ea_txt);
	free(game);
}

void	free_imgs(t_game *g, t_ray *ray)
{
	mlx_destroy_image(g->mlx, g->east.mlx_img);
	mlx_destroy_image(g->mlx, g->west.mlx_img);
	mlx_destroy_image(g->mlx, g->north.mlx_img);
	mlx_destroy_image(g->mlx, g->south.mlx_img);
	free(ray);
}
