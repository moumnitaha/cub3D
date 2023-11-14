/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_rays.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhaliss <akhaliss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 18:23:32 by tmoumni           #+#    #+#             */
/*   Updated: 2023/11/14 15:06:46 by akhaliss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	img_pix_put(t_game *g, int x, int y, int color)
{
	g->img->addr[y * (int)g->width + x] = color;
}

void r_ceiling(t_game *g, int wall_height, int rayIndex)
{
    int j;
	int h;

	h = (g->height - wall_height) / 2;
	j = 0;
    while (j < h)
	{
        img_pix_put(g, rayIndex, j, g->ceilling_c);
        j++;
    }
}

void r_floor(t_game *g, int j, int wall_height, int rayIndex)
{
	int h;

	h = (g->height - wall_height) / 2;
    while (j + h < g->height)
	{
        img_pix_put(g, rayIndex, j + h, g->floor_c);
        j++;
    }
}

void renderWallSection(t_game *g, /*double offset_x, double offset_y, int ot_x, int j,*//* int h, int dir,*/ t_ray *ray, double wall_height) {
    
	// int color;
	double offset_x;
	// double offset_y;
    int h;
	// int	ot_x;
	// int	dir;
	// int j;
	
	h = (g->height - wall_height) / 2;
	offset_x = off_x(ray);
	// ot_x = 0;
	// color = 0;
	// dir = _dir(ray);
	// j = 0;
	// while(j < wall_height)
	// {
	// 	if (ray->is_hz_hit  && ray->is_ray_fup)
	// 	{
	// 		offset_y = j * (g->no_h / wall_height);
	// 		ot_x = offset_x * (g->no_w / DM);
	// 		if(ot_x + offset_y * g->no_w < g->no_w * g->no_h && ot_x + offset_y * g->no_w > 0 
	// 			&& j + h < g->height && j + h > 0)
	// 		{
	// 			color = g->north.addr[((int)offset_y * g->no_w) + (int)ot_x];
	// 			img_pix_put(g, ray->index, j + h, color);
	// 		}
	// 	}
	// 	else if (ray->is_hz_hit && ray->is_ray_fdw)
	// 	{
	// 		offset_y = j * (g->so_h / wall_height);
	// 		ot_x = offset_x * (g->so_w / DM);

	// 		if(ot_x + offset_y * g->so_w < g->so_w * g->so_h && ot_x + offset_y * g->so_w > 0 
	// 			&& j + h < g->height && j + h > 0)
	// 		{
	// 			color = g->south.addr[((int)offset_y * g->so_w) + (int)ot_x];
	// 			img_pix_put(g, ray->index, j + h, color);
	// 		}
	// 	}
	// 	j++;
	// }
	r_so_no(g, ray, offset_x, wall_height);
	// j = 0;
	// while(j < wall_height)
	// {
	// 	if (ray->is_vc_hit && ray->is_ray_flf)
	// 	{
	// 		offset_y = j * (g->we_h / wall_height);
	// 		ot_x = offset_x * (g->we_w / DM);

	// 		if(ot_x + offset_y * g->we_w < g->we_w * g->we_h && ot_x + offset_y * g->we_w > 0 
	// 			&& j + h < g->height && j + h > 0)
	// 		{
	// 			color = g->west.addr[((int)offset_y * g->we_w) + (int)ot_x];
	// 			img_pix_put(g, ray->index, j + h, color);
	// 		}
    // 	}
	// 	else if (ray->is_vc_hit && ray->is_ray_frt)
	// 	{
	// 		offset_y = j * (g->ea_h / wall_height);
	// 		ot_x = offset_x * (g->ea_w / DM);

	// 		if(ot_x + offset_y * g->ea_w < g->ea_w * g->ea_h && ot_x + offset_y * g->ea_w > 0 
	// 			&& j + h < g->height && j + h > 0)
	// 		{
	// 			color = g->east.addr[((int)offset_y * g->ea_w) + (int)ot_x];
	// 			img_pix_put(g, ray->index, j + h, color);
	// 		}
	// 	}
	// 	j++;
	// }
	r_we_ea(g, ray, offset_x, wall_height);
}



void renderWal(t_game *g, double wall_height, t_ray *ray/*, int dir*/)
{
    // double offset_x;
    // int j;
	// int ot_x;
	// double offset_y;
    // int h;

	// h = (g->height - wall_height) / 2;
	// offset_x = off_x(ray);
    // r_ceiling_floor(g, wall_height, ray->index);
        // ot_x = offset_x * (g->no_w / DM);
        // offset_y = j * (g->no_h / wall_height);
    renderWallSection(g,/* offset_x, offset_y, ot_x, j,*/ /*h, dir,*/ ray, wall_height);

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
	// int	dir;
	ray = malloc(sizeof(t_ray));
	if (ray == NULL)
		return ;
	ray->index = 0;
	g->player->dir = fix_ang(g->player->dir);
	ray->ray_ang = g->player->dir - deg_to_rad(g->player->fov / 2);
	mlx_clear_window(g->mlx, g->win);
	xpm_files(g);
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
		r_ceiling(g, wall_height, ray->index);
	    renderWallSection(g,/* offset_x, offset_y, ot_x, j,*/ /*h, dir,*/ ray, wall_height);
		// dir = _dir(ray);
		// renderWal(g, wall_height, ray/*, dir*/);
		ray->ray_ang += deg_to_rad(g->player->fov / g->width);
		ray->index++;
	}
	mlx_put_image_to_window(g->mlx, g->win, g->img->mlx_img, 0, 0);
	free(ray);
}
