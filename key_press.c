/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoumni <tmoumni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 18:24:05 by tmoumni           #+#    #+#             */
/*   Updated: 2023/10/30 18:47:27 by tmoumni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

// int		key_press(int keycode, t_game *game)
// {
// 	if (keycode == KEY_ESC)
// 	{
// 		mlx_destroy_window(game->mlx_ptr, game->win_ptr);
// 		exit(0);
// 	}
// 	if (keycode == KEY_LEFT)
// 		game->player->turn_dir = -1;
// 	if (keycode == KEY_RIGHT)
// 		game->player->turn_dir = 1;
// 	if (keycode == KEY_UP)
// 		game->player->walk_dir = 1;
// 	if (keycode == KEY_DOWN)
// 		game->player->walk_dir = -1;
// 	return (0);
// }

int	key_press(int keycode, t_game *game)
{
	double pX;
	double pY;
	if (keycode == KEY_ESC)
		exit_game(game);
	if (keycode == KEY_UP)
	{
		pX = game->player->x + 8 * cos(game->player->dir);
		pY = game->player->y + 8 * sin(game->player->dir);
		if(map[(int)(pY / DM)][(int)(pX/ DM)] == '1')
			return (0);
		if(map[(int)(pY / DM)][(int)(pX/ DM)] == ' ')
			return (0);
		game->player->x = pX;
		game->player->y = pY;
	}
	else if (keycode == KEY_DOWN)
	{
		pX = game->player->x - 8 * cos(game->player->dir);
		pY = game->player->y - 8 * sin(game->player->dir);
		if(map[(int)(pY / DM)][(int)(pX/ DM)] == '1')
			return (0);
		if(map[(int)(pY / DM)][(int)(pX/ DM)] == ' ')
			return (0);
		game->player->x = pX;
		game->player->y = pY;
	}
	else if (keycode == KEY_LEFT)
	{
		game->player->dir -= degToRad(6);
		pX = game->player->x;
		pY = game->player->y;
	}
	else if (keycode == KEY_RIGHT)
	{
		game->player->dir += degToRad(6);
		pX = game->player->x;
		pY = game->player->y;
	}
	else
		return (0);
	mainDraws(game);
	return (0);
}