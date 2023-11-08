/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_draws.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoumni <tmoumni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 18:31:11 by tmoumni           #+#    #+#             */
/*   Updated: 2023/11/08 14:56:35 by tmoumni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	mimg_pix_put(t_game *g, int x, int y, int color)
{
	g->mini_map->addr[y * (int)g->mini_map_w + x] = color;
}

void	draw_line(t_game *g, double x_1, double y_1)
{
	double	p_x;
	double	p_y;
	double	x_inc;
	double	y_inc;
	double	steps;

	p_x = (g->mini_map_w / 2);
	p_y = (g->mini_map_h / 2);
	if (fabs(x_1 - p_x) > fabs(y_1 - p_y))
		steps = fabs(x_1 - p_x);
	else
		steps = fabs(y_1 - p_y);
	x_inc = (x_1 - p_x) / (double)steps;
	y_inc = (y_1 - p_y) / (double)steps;
	while ((int)steps)
	{
		mimg_pix_put(g, p_x, p_y, RED);
		p_x += x_inc;
		p_y += y_inc;
		steps -= 1;
	}
}

void	draw_player(t_game *g, double x_pos, double y_pos)
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
			mimg_pix_put(g, (j - width / 2), (i - height / 2), BLUE);
			j++;
		}
		i++;
	}
}

int	check_wall_collision(t_game *g, double x, double y)
{
	int	x0;
	int	y0;

	if (x < 0 || x > g->width || y < 0 || y > g->height)
		return (-1);
	x0 = floor(x / DM);
	y0 = floor(y / DM);
	if (x0 < 0 || x0 > g->m_w - 1 || y0 < 0 || y0 > g->m_h - 1)
		return (-1);
	if (g->map[y0][x0] == '1' || g->map[y0][x0] == ' ')
		return (1);
	else
		return (0);
}

int	mis_wall(t_game *game, double x, double y)
{
	if (check_wall_collision(game, x, y) == 1)
		return (1);
	else if (check_wall_collision(game, x, y) == -1)
		return (-1);
	else
		return (0);
}

void	draw_map(t_game *g)
{
	double	p_ang;
	int		i;
	int		j;
	double	tmp_y;
	double	tmp_x;
	double	p_x;
	double	p_y;

	p_ang = g->player->dir;
	p_x = g->player->x - (g->mini_map_w / 2);
	p_y = g->player->y - (g->mini_map_h / 2);
	i = 0;
	j = 0;
	tmp_x = p_x;
	while (i < g->mini_map_w)
	{
		j = 0;
		tmp_y = p_y;
		while (j < g->mini_map_h)
		{
			if (mis_wall(g, tmp_x, tmp_y) == 1)
				mimg_pix_put(g, i, j, BLACK);
			else if (mis_wall(g, tmp_x, tmp_y) == 0)
				mimg_pix_put(g, i, j, WHITE);
			else if (mis_wall(g, tmp_x, tmp_y) == -1)
				mimg_pix_put(g, i, j, BLACK);
			j++;
			tmp_y++;
		}
		i++;
		tmp_x++;
	}
	draw_player(g, (g->mini_map_w / 2), (g->mini_map_h / 2));
	draw_line(g, ((g->mini_map_w / 2) + cos(p_ang) * 14), 
		((g->mini_map_h / 2) + sin(p_ang) * 14));
	mlx_put_image_to_window(g->mlx, g->win, g->mini_map->mlx_img, 5, 5);
}

int	main_draws(t_game *game)
{
	mlx_clear_window(game->mlx, game->win);
	update_player(game);
	render_rays(game);
	draw_map(game);
	return (0);
}
