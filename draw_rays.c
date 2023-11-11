/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_rays.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoumni <tmoumni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 18:23:32 by tmoumni           #+#    #+#             */
/*   Updated: 2023/11/11 17:32:18 by tmoumni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	img_pix_put(t_game *g, int x, int y, int color)
{
	g->img->addr[y * (int)g->width + x] = color;
}

void renderWal(t_game *g, double wall_height, t_ray *ray, int dir, int width, int height, char *texture)
{
	int j;
	int color;
	double offset_x;
	double offset_y;
	int h;

	j = 0;
	offset_x = 0;
	offset_y = 0;
	wall_height = floor(wall_height);
	h = (g->height - wall_height) / 2;
	if (ray->is_vc_hit && ray->is_ray_flf)
		offset_x = DM - fmod(ray->y_v_hit , DM);
	else if (ray->is_vc_hit && ray->is_ray_frt)
		offset_x = fmod(ray->y_v_hit , DM);
	else if (ray->is_hz_hit && ray->is_ray_fdw)
		offset_x = DM - fmod(ray->x_h_hit , DM);
	else if (ray->is_hz_hit && ray->is_ray_fup)
		offset_x = fmod(ray->x_h_hit , DM);
	offset_x = offset_x * (width / DM);
	while (j < h)
	{
		img_pix_put(g, ray->index, j, g->ceilling_c);
		j++;
	}
	j = 0;
	while(j < wall_height)
	{
		offset_y = j * (height / wall_height);
		if (dir == 1)
		{	
			if(offset_x + offset_y * width < width * height && offset_x + offset_y * width > 0 
				&& j + h < g->height && j + h > 0)
			{
				color = ((int *)texture)[((int)offset_y * width) + (int)offset_x];
				img_pix_put(g, ray->index, j + h, color);
			}
		}
		else if (dir == 2)
			color = (int)g->so_txt[(int)offset_y * 64 + (int)offset_x * 4];
		else if (dir == 3)
			color = (int)g->we_txt[(int)offset_y * 64 + (int)offset_x * 4];
		else if (dir == 4)
			color = (int)g->ea_txt[(int)offset_y * 64 + (int)offset_x * 4];
		j++;
	}
	while (j + h < g->height)
	{
		img_pix_put(g, ray->index, j + h, g->floor_c);
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
	char *texture;
	char *tex;
	int width;
	int height;
	char *path = "./xpms/bricksx64.xpm";
	tex = mlx_xpm_file_to_image(g->mlx, path, &width, &height);
	texture = mlx_get_data_addr(tex, &g->img->bpp, &g->img->line_len, &g->img->endian);
	ray = malloc(sizeof(t_ray));
	if (ray == NULL)
		return ;
	ray->index = 0;
	g->player->dir = fix_ang(g->player->dir);
	ray->ray_ang = g->player->dir - deg_to_rad(g->player->fov / 2);
	mlx_clear_window(g->mlx, g->win);
	mlx_destroy_image(g->mlx, g->img->mlx_img);
	g->img->mlx_img = mlx_new_image(g->mlx, g->width, g->height);
	g->img->addr = (int *)mlx_get_data_addr(g->img->mlx_img, &g->img->bpp, &g->img->line_len, &g->img->endian);
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
		handle_hit(ray);
		renderWal(g, wall_height, ray, 1, width, height, texture);
		ray->ray_ang += deg_to_rad(g->player->fov / g->width);
		ray->index++;
	}
	mlx_put_image_to_window(g->mlx, g->win, g->img->mlx_img, 0, 0);
	free(ray);
}
