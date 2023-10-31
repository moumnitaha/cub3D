/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_rays.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoumni <tmoumni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 18:23:32 by tmoumni           #+#    #+#             */
/*   Updated: 2023/10/31 11:57:35 by tmoumni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	handle_render(t_game *g, t_ray *ray, double vw_height, double hw_height)
{
	if (ray->is_hz_hit && ray->is_vc_hit)
	{
		if (ray->h_hit_dis < ray->v_hit_dis + (0.1 / g->width))
			render_3d_walls(g, hw_height, ray->index, GRAY);
		else
			render_3d_walls(g, vw_height, ray->index, GREEN);
	}
	else if (ray->is_hz_hit)
		render_3d_walls(g, hw_height, ray->index, GRAY);
	else if (ray->is_vc_hit)
		render_3d_walls(g, vw_height, ray->index, GREEN);
}

void	draw_rays(t_game *g)
{
	t_ray	*ray;
	double	v_wall_height;
	double	h_wall_height;

	ray = malloc(sizeof(t_ray));
	ray->index = 0;
	ray->ray_ang = g->player->dir - deg_to_rad(g->player->fov / 2);
	while (ray->ray_ang < g->player->dir + deg_to_rad(g->player->fov / 2))
	{
		init_ray_direction(ray);
		horizontal_intersection(g, ray);
		vertical_intersection(g, ray);
		ray->d_to_pp = (g->width / 2) * cos(deg_to_rad(g->player->fov / 2));
		h_wall_height = (DM / ray->h_hit_dis) * ray->d_to_pp;
		h_wall_height /= cos(g->player->dir - ray->ray_ang);
		v_wall_height = (DM / ray->v_hit_dis) * ray->d_to_pp;
		v_wall_height /= cos(g->player->dir - ray->ray_ang);
		handle_render(g, ray, v_wall_height, h_wall_height);
		ray->ray_ang += deg_to_rad(g->player->fov / g->width);
		ray->index++;
	}
	free(ray);
}
