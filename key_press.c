/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_press.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoumni <tmoumni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 18:24:05 by tmoumni           #+#    #+#             */
/*   Updated: 2023/11/04 18:18:50 by tmoumni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

bool	has_wall(t_game *game, double x, double y)
{
	if (game->map[(int)(y / DM)][(int)(x / DM)] == '1')
		return (true);
	return (false);
}

bool	is_wall(t_game *game, double x, double y)
{
	int	t;

	t = 4;
	if (has_wall(game, x - t, y - t) || has_wall(game, x + t, y + t)
		|| has_wall(game, x - t, y + t) || has_wall(game, x + t, y - t))
		return (true);
	return (false);
}

void	update_player(t_game *game)
{
	double	p_x;
	double	p_y;
	int		w_dir;
	int		c;

	c = game->player->lf;
	w_dir = game->player->walk_dir;
	p_x = game->player->x + (cos(game->player->dir + c * M_PI_2)) * w_dir * 5;
	p_y = game->player->y + (sin(game->player->dir + c * M_PI_2)) * w_dir * 5;
	if (!is_wall(game, p_x, game->player->y))
		game->player->x = p_x;
	if (!is_wall(game, game->player->x, p_y))
		game->player->y = p_y;
	game->player->dir += deg_to_rad(game->player->turn_dir);
}

int	key_press(int keycode, t_game *game)
{
	if (keycode == KEY_ESC)
		exit_game(game);
	if (keycode == KEY_UP)
		game->player->walk_dir = 1;
	if (keycode == KEY_DOWN)
		game->player->walk_dir = -1;
	if (keycode == KEY_LEFT)
		game->player->turn_dir = -3.5;
	if (keycode == KEY_RIGHT)
		game->player->turn_dir = 3.5;
	if (keycode == KEY_A)
		game->player->lf = -1;
	if (keycode == KEY_D)
		game->player->lf = 1;
	return (0);
}

int	key_release(int keycode, t_game *game)
{
	if (keycode == KEY_UP)
		game->player->walk_dir = 0;
	if (keycode == KEY_DOWN)
		game->player->walk_dir = 0;
	if (keycode == KEY_LEFT)
		game->player->turn_dir = 0;
	if (keycode == KEY_RIGHT)
		game->player->turn_dir = 0;
	if (keycode == KEY_A)
		game->player->lf = 0;
	if (keycode == KEY_D)
		game->player->lf = 0;
	return (0);
}
