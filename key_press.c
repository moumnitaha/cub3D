/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoumni <tmoumni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 18:24:05 by tmoumni           #+#    #+#             */
/*   Updated: 2023/11/02 22:50:32 by tmoumni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	go_up_down(t_game *game, int c, int w_dir)
{
	double	p_x;
	double	p_y;

	p_x = game->player->x + (8 * cos(game->player->dir + c * M_PI_2)) * w_dir;
	p_y = game->player->y + (8 * sin(game->player->dir + c * M_PI_2)) * w_dir;
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
		go_up_down(game, 0, 1);
	else if (keycode == KEY_DOWN)
		go_up_down(game, 0, -1);
	else if (keycode == KEY_LEFT)
		game->player->dir -= deg_to_rad(game->player->turn_dir);
	else if (keycode == KEY_RIGHT)
		game->player->dir += deg_to_rad(game->player->turn_dir);
	else if (keycode == KEY_A)
		go_up_down(game, -1, 1);
	else if (keycode == KEY_D)
		go_up_down(game, -1, -1);
	else
		return (0);
	main_draws(game);
	return (0);
}
