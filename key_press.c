/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoumni <tmoumni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 18:24:05 by tmoumni           #+#    #+#             */
/*   Updated: 2023/10/31 16:40:07 by tmoumni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	go_up_down(t_game *game)
{
	double	p_x;
	double	p_y;
	double	w_dir;

	w_dir = game->player->walk_dir;
	p_x = game->player->x + (8 * cos(game->player->dir)) * w_dir;
	p_y = game->player->y + (8 * sin(game->player->dir)) * w_dir;
	if (game->map[(int)(p_y / DM)][(int)(p_x / DM)] == '1')
		return ;
	if (game->map[(int)(p_y / DM)][(int)(p_x / DM)] == ' ')
		return ;
	game->player->x = p_x;
	game->player->y = p_y;
}

int	key_press(int keycode, t_game *game)
{
	if (keycode == KEY_ESC)
		exit_game(game);
	if (keycode == KEY_UP)
	{
		game->player->walk_dir = 1;
		go_up_down(game);
	}
	else if (keycode == KEY_DOWN)
	{
		game->player->walk_dir = -1;
		go_up_down(game);
	}
	else if (keycode == KEY_LEFT)
	{
		game->player->dir -= deg_to_rad(game->player->turn_dir);
	}
	else if (keycode == KEY_RIGHT)
	{
		game->player->dir += deg_to_rad(game->player->turn_dir);
	}
	else
		return (0);
	main_draws(game);
	return (0);
}
