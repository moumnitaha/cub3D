/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_params_bn.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoumni <tmoumni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 19:17:27 by tmoumni           #+#    #+#             */
/*   Updated: 2023/11/23 13:26:24 by tmoumni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

int	exit_game(t_game *game)
{
	mlx_destroy_image(game->mlx, game->img->mlx_img);
	mlx_destroy_image(game->mlx, game->mini_map->mlx_img);
	mlx_clear_window(game->mlx, game->win);
	mlx_destroy_window(game->mlx, game->win);
	exit(0);
}

int	escape_game(t_game *game)
{
	printf("\033[1;31m[[ U gaved up :/ ]]\033[0m\n");
	return (exit_game(game));
}
