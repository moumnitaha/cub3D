/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_rays_bn.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoumni <tmoumni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 18:23:32 by tmoumni           #+#    #+#             */
/*   Updated: 2023/11/23 13:25:43 by tmoumni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

void	r_ceiling(t_game *g, int wall_height, int rayIndex)
{
	int	j;
	int	h;

	h = (g->height - wall_height) / 2;
	j = 0;
	while (j < h)
	{
		img_pix_put(g, rayIndex, j, g->ceilling_c);
		j++;
	}
}

void	r_floor(t_game *g, int wall_height, int rayIndex)
{
	int	h;
	int	j;

	j = wall_height;
	h = (g->height - wall_height) / 2;
	while (j + h < g->height)
	{
		img_pix_put(g, rayIndex, j + h, g->floor_c);
		j++;
	}
}

void	handle_hit(t_ray *ray)
{
	if (ray->is_hz_hit && ray->is_vc_hit)
	{
		if (ray->h_hit_dis < ray->v_hit_dis)
			ray->is_vc_hit = false;
		else
			ray->is_hz_hit = false;
	}
}

void	handle_ray_dis(t_game *g, t_ray *ray, double *wall_height)
{
	if (ray->is_hz_hit == ray->is_vc_hit)
		ray->dist = fmin(ray->h_hit_dis, ray->v_hit_dis);
	else if (ray->is_hz_hit)
		ray->dist = ray->h_hit_dis;
	else if (ray->is_vc_hit)
		ray->dist = ray->v_hit_dis;
	*wall_height = (DM / ray->dist) * ray->d_to_pp;
	*wall_height /= cos(g->player->dir - ray->ray_ang);
}

void	render_rays(t_game *g)
{
	t_ray	*ray;
	double	wall_height;

	ray = malloc(sizeof(t_ray));
	if (ray == NULL)
		return ;
	ray->index = 0;
	g->player->dir = fix_ang(g->player->dir);
	ray->ray_ang = g->player->dir - deg_to_rad(g->player->fov / 2);
	xpm_files(g);
	while (ray->ray_ang < g->player->dir + deg_to_rad(g->player->fov / 2) 
		&& ray->index < g->width)
	{
		init_ray_direction(ray);
		horizontal_intersection(g, ray);
		vertical_intersection(g, ray);
		ray->d_to_pp = (g->width / 2) / tan(deg_to_rad(g->player->fov / 2));
		handle_hit(ray);
		handle_ray_dis(g, ray, &wall_height);
		render_wall(g, ray, wall_height);
		ray->ray_ang += deg_to_rad(g->player->fov / g->width);
		ray->index++;
	}
	mlx_put_image_to_window(g->mlx, g->win, g->img->mlx_img, 0, 0);
	free_imgs(g, ray);
}
