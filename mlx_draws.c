/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_draws.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoumni <tmoumni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 18:31:11 by tmoumni           #+#    #+#             */
/*   Updated: 2023/10/30 18:48:01 by tmoumni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void draw_rect(t_game *g, int x , int y, int color, double scale)
{
	double width = (DM * scale) + y;
	double height = (DM * scale) + x;
	int i = y;
	int j = x;
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

void draw_line(t_game *g, double X0, double Y0, double X1, double Y1, int color)
{
	double dx = X1 - X0;
	double dy = Y1 - Y0;
	double steps = fabs(dx) > fabs(dy) ? fabs(dx) : fabs(dy);
	double Xinc = dx / (double)steps;
	double Yinc = dy / (double)steps;
	double X = X0;
	double Y = Y0;
	for (int i = 0; i <= steps; i++)
	{
		mlx_pixel_put(g->mlx, g->win, X, Y, color);
		X += Xinc;
		Y += Yinc;
	}  
}

void draw_player(t_game *g, double x_pos, double y_pos, double scale)
{
	double width = 18 + y_pos;
	double height = 18 + x_pos;
	double i = y_pos;
	double j = x_pos;
	while (i < width)
	{
		j = x_pos;
		while (j < height)
		{
			mlx_pixel_put(g->mlx, g->win, (j - 9) * scale, (i - 9) * scale, blue);
			j++;
		}
		i++;
	}
}

void	draw_map(t_game *g, double scale)
{
	double pX = g->player->x;
	double pY = g->player->y;
	double pAngle = g->player->dir;
	for (int i = 0; i < MAX_ROWS; i++)
	{
		for (int j = 0; j < MAX_COLS; j++)
		{
			if (map[i][j] == '1')
				draw_rect(g, j * (DM * scale) , i * (DM * scale) , black, scale);
			else if (map[i][j] == ' ')
				draw_rect(g, j * (DM * scale), i * (DM * scale), red, scale);
			else if (map[i][j] == '0' || map[i][j] == 'P')
				draw_rect(g, j * (DM * scale), i * (DM * scale), white, scale);
		}
	}
	draw_player(g, g->player->x, g->player->y, scale);
	draw_line(g, pX * scale, pY * scale, (pX + cos(pAngle) * 40) * scale, (pY + sin(pAngle) * 40) * scale, red);
}

void mlx_draw_cercle(t_game *g)
{
	int x = 10;
	int y = 10;
	int r = 5;
	int i = 0;
	int j = 0;
	while (i < 2 * r)
	{
		j = 0;
		while (j < 2 * r)
		{
			if ((int)sqrt((i - r) * (i - r) + (j - r) * (j - r)) == r)
				mlx_pixel_put(g->mlx, g->win, x + i, y + j, red);
			j++;
		}
		i++;
	}
}

int mainDraws(t_game *game)
{
	mlx_clear_window(game->mlx, game->win);
	draw_rays(game);
	draw_map(game, 2 / (game->height / DM));
	return (0);
}