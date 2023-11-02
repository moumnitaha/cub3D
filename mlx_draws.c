/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_draws.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoumni <tmoumni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 18:31:11 by tmoumni           #+#    #+#             */
/*   Updated: 2023/11/02 13:39:25 by tmoumni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	draw_rect(t_game *g, int x, int y, int color)
{
	double	width;
	double	height;
	int		i;
	int		j;

	width = (DM * g->scale) + y;
	height = (DM * g->scale) + x;
	i = y;
	j = x;
	while (i < width)
	{
		j = x;
		while (j < height)
		{
			mlx_pixel_put(g->mlx, g->win, j, i, color);
			j++;
		}
		i++;
	}
}

void	draw_line(t_game *g, double x_1, double y_1)
{
	double	p_x;
	double	p_y;
	double	x_inc;
	double	y_inc;
	double	steps;

	p_x = g->player->x * g->scale;
	p_y = g->player->y * g->scale;
	if (fabs(x_1 - p_x) > fabs(y_1 - p_y))
		steps = fabs(x_1 - p_x);
	else
		steps = fabs(y_1 - p_y);
	x_inc = (x_1 - p_x) / (double)steps;
	y_inc = (y_1 - p_y) / (double)steps;
	while ((int)steps)
	{
		mlx_pixel_put(g->mlx, g->win, p_x, p_y, RED);
		p_x += x_inc;
		p_y += y_inc;
		steps -= 1;
	}
}

void	draw_player(t_game *g, double x_pos, double y_pos, double scale)
{
	double	width;
	double	height;
	double	i;
	double	j;

	width = DM * 0.5;
	height = DM * 0.5;
	i = y_pos;
	j = x_pos;
	while (i < width + y_pos)
	{
		j = x_pos;
		while (j < height + x_pos)
		{
			mlx_pixel_put(g->mlx, g->win, (j - width / 2) * 
				scale, (i - height / 2) * scale, BLUE);
			j++;
		}
		i++;
	}
}

void	draw_map(t_game *g, double scale)
{
	double	p_ang;
	int		i;
	int		j;

	p_ang = g->player->dir;
	i = 0;
	j = 0;
	while (i < g->m_h)
	{
		j = 0;
		while (j < g->m_w)
		{
			if (g->map[i][j] == '1')
				draw_rect(g, j * (DM * scale), i * (DM * scale), BLACK);
			else if (g->map[i][j] == ' ')
				draw_rect(g, j * (DM * scale), i * (DM * scale), RED);
			else if (g->map[i][j] == '0' || g->map[i][j] == 'N')
				draw_rect(g, j * (DM * scale), i * (DM * scale), WHITE);
			j++;
		}
		i++;
	}
	draw_player(g, g->player->x, g->player->y, scale);
	draw_line(g, (g->player->x + cos(p_ang) * 40) * 
		scale, (g->player->y + sin(p_ang) * 40) * scale);
}

// void mlx_draw_cercle(t_game *g)
// {
// 	int x = 10;
// 	int y = 10;
// 	int r = 5;
// 	int i = 0;
// 	int j = 0;
// 	while (i < 2 * r)
// 	{
// 		j = 0;
// 		while (j < 2 * r)
// 		{
// 			if ((int)sqrt((i - r) * (i - r) + (j - r) * (j - r)) == r)
// 				mlx_pixel_put(g->mlx, g->win, x + i, y + j, RED);
// 			j++;
// 		}
// 		i++;
// 	}
// }

int	main_draws(t_game *game)
{
	mlx_clear_window(game->mlx, game->win);
	render_ceil_floor(game);
	render_rays(game);
	draw_map(game, game->scale);
	return (0);
}
