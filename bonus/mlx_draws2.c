/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_draws2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoumni <tmoumni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 12:38:32 by tmoumni           #+#    #+#             */
/*   Updated: 2023/11/21 14:31:39 by tmoumni          ###   ########.fr       */
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
		mimg_pix_put(g, p_x, p_y, BLUE);
		p_x += x_inc;
		p_y += y_inc;
		steps -= 1;
	}
}

void	draw_player(t_game *g, double x_pos, double y_pos)
{
	double	width;
	double	height;
	double	p_ang;
	double	i;
	double	j;

	p_ang = g->player->dir;
	width = 10;
	height = 10;
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
	draw_line(g, x_pos + cos(p_ang) * 14, 
		y_pos + sin(p_ang) * 14);
}
