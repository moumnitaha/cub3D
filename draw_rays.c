/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_rays.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoumni <tmoumni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 18:23:32 by tmoumni           #+#    #+#             */
/*   Updated: 2023/11/05 09:45:25 by tmoumni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	img_pix_put(t_game *g, int x, int y, int color)
{
	g->img->addr[y * (int)g->width + x] = color;
}

void	fill_wall_img(t_game *g, int x, double wall_height, int color)
{
	int	y;
	int	height;

	wall_height = round(wall_height);
	if (wall_height > g->height)
		wall_height = g->height;
	y = 0;
	height = (g->height - wall_height) / 2;
	while (y < g->height)
	{
		if (y < height)
			img_pix_put(g, x, y, g->ceilling_c);
		else if (y < height + wall_height)
			img_pix_put(g, x, y, color);
		else if (y < g->height)
			img_pix_put(g, x, y, g->floor_c);
		y++;
	}
}

void	handle_render(t_game *g, t_ray *ray, double w_height)
{
	if (ray->is_hz_hit && ray->is_vc_hit)
	{
		if (ray->h_hit_dis < ray->v_hit_dis)
			fill_wall_img(g, ray->index, w_height, GRAY);
		else
			fill_wall_img(g, ray->index, w_height, GRAYF);
	}
	else if (ray->is_hz_hit)
		fill_wall_img(g, ray->index, w_height, GRAY);
	else if (ray->is_vc_hit)
		fill_wall_img(g, ray->index, w_height, GRAYF);
}

void	handle_ray_dis(t_ray *ray)
{
	if (ray->is_hz_hit && ray->is_vc_hit)
		ray->dist = fmin(ray->h_hit_dis, ray->v_hit_dis);
	else if (ray->is_hz_hit)
		ray->dist = ray->h_hit_dis;
	else if (ray->is_vc_hit)
		ray->dist = ray->v_hit_dis;
}

void	render_rays(t_game *g)
{
	t_ray	*ray;
	double	wall_height;

	ray = malloc(sizeof(t_ray));
	if (ray == NULL)
		return ;
	ray->index = 0;
	ray->ray_ang = g->player->dir - deg_to_rad(g->player->fov / 2);
	while (ray->ray_ang < g->player->dir + deg_to_rad(g->player->fov / 2) 
		&& ray->index < g->width)
	{
		init_ray_direction(ray);
		horizontal_intersection(g, ray);
		vertical_intersection(g, ray);
		ray->d_to_pp = (g->width / 2) / tan(deg_to_rad(g->player->fov / 2));
		handle_ray_dis(ray);
		wall_height = (DM / ray->dist) * ray->d_to_pp;
		wall_height /= cos(g->player->dir - ray->ray_ang);
		handle_render(g, ray, wall_height);
		ray->ray_ang += deg_to_rad(g->player->fov / g->width);
		ray->index++;
	}
	mlx_put_image_to_window(g->mlx, g->win, g->img->mlx_img, 0, 0);
	free(ray);
}
