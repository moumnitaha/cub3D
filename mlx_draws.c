/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_draws.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoumni <tmoumni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 18:31:11 by tmoumni           #+#    #+#             */
/*   Updated: 2023/11/09 12:49:31 by tmoumni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

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
	int		i;
	int		j;
	double	p_x;
	double	p_y;

	i = -1;
	p_x = g->player->x - (g->mini_map_w / 2);
	while (++i < g->mini_map_w)
	{
		j = -1;
		p_y = g->player->y - (g->mini_map_h / 2);
		while (++j < g->mini_map_h)
		{
			if (mis_wall(g, p_x, p_y) == 1 || mis_wall(g, p_x, p_y) == -1)
				mimg_pix_put(g, i, j, BLACK);
			else if (mis_wall(g, p_x, p_y) == 0)
				mimg_pix_put(g, i, j, WHITE);
			if (i < 5 || i > g->mini_map_w - 5 || j < 5 || 
				j > g->mini_map_h - 5)
				mimg_pix_put(g, i, j, GRAYF);
			p_y++;
		}
		p_x++;
	}
}

int	main_draws(t_game *g)
{
	mlx_clear_window(g->mlx, g->win);
	update_player(g);
	render_rays(g);
	draw_map(g);
	draw_player(g, (g->mini_map_w / 2), (g->mini_map_h / 2));
	mlx_put_image_to_window(g->mlx, g->win, g->mini_map->mlx_img, 0, 0);
	return (0);
}
