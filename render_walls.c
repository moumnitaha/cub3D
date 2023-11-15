/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_walls.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhaliss <akhaliss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 15:40:26 by akhaliss          #+#    #+#             */
/*   Updated: 2023/11/15 10:08:32 by akhaliss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	r_no(t_game *g, t_ray *ray, double wall_height, int j)
{
	int		color;
	double	offset_y;
	double	ot_x;
	double	offset_x;
	int		h;

	h = (g->height - wall_height) / 2;
	offset_x = off_x(ray);
	if (ray->is_hz_hit && ray->is_ray_fup)
	{
		offset_y = j * (g->no_h / wall_height);
		ot_x = offset_x * (g->no_w / DM);
		if (ot_x + offset_y * g->no_w < g->no_w * g->no_h
			&& ot_x + offset_y * g->no_w > 0 && j + h < g->height && j + h > 0)
		{
			color = g->north.addr[((int)offset_y * g->no_w) + (int)ot_x];
			img_pix_put(g, ray->index, j + h, color);
		}
	}
}

void	r_so(t_game *g, t_ray *ray, double wall_height, int j)
{
	int		color;
	double	offset_y;
	double	ot_x;
	double	offset_x;
	int		h;

	h = (g->height - wall_height) / 2;
	offset_x = off_x(ray);
	if (ray->is_hz_hit && ray->is_ray_fdw)
	{
		offset_y = j * (g->so_h / wall_height);
		ot_x = offset_x * (g->so_w / DM);
		if (ot_x + offset_y * g->so_w < g->so_w * g->so_h
			&& ot_x + offset_y * g->so_w > 0 && j + h < g->height && j + h > 0)
		{
			color = g->south.addr[((int)offset_y * g->so_w) + (int)ot_x];
			img_pix_put(g, ray->index, j + h, color);
		}
	}
}

void	r_we(t_game *g, t_ray *ray, double wall_height, int j)
{
	int		color;
	double	offset_y;
	double	ot_x;
	double	offset_x;
	int		h;

	h = (g->height - wall_height) / 2;
	offset_x = off_x(ray);
	if (ray->is_vc_hit && ray->is_ray_flf)
	{
		offset_y = j * (g->we_h / wall_height);
		ot_x = offset_x * (g->we_w / DM);
		if (ot_x + offset_y * g->we_w < g->we_w * g->we_h
			&& ot_x + offset_y * g->we_w > 0 && j + h < g->height && j + h > 0)
		{
			color = g->west.addr[((int)offset_y * g->we_w) + (int)ot_x];
			img_pix_put(g, ray->index, j + h, color);
		}
	}
}

void	r_ea(t_game *g, t_ray *ray, double wall_height, int j)
{
	int		color;
	double	offset_y;
	double	ot_x;
	double	offset_x;
	int		h;

	h = (g->height - wall_height) / 2;
	offset_x = off_x(ray);
	if (ray->is_vc_hit && ray->is_ray_frt)
	{
		offset_y = j * (g->ea_h / wall_height);
		ot_x = offset_x * (g->ea_w / DM);
		if (ot_x + offset_y * g->ea_w < g->ea_w * g->ea_h
			&& ot_x + offset_y * g->ea_w > 0 && j + h < g->height && j + h > 0)
		{
			color = g->east.addr[((int)offset_y * g->ea_w) + (int)ot_x];
			img_pix_put(g, ray->index, j + h, color);
		}
	}
}

void	render_wall(t_game *g, t_ray *ray, double wall_height)
{
	int	j;
	int	h;

	h = (g->height - wall_height) / 2;
	r_ceiling(g, wall_height, ray->index);
	j = 0;
	while (j < wall_height)
	{
		if (ray->is_hz_hit && ray->is_ray_fup)
			r_no(g, ray, wall_height, j);
		else if (ray->is_hz_hit && ray->is_ray_fdw)
			r_so(g, ray, wall_height, j);
		else if (ray->is_vc_hit && ray->is_ray_flf)
			r_we(g, ray, wall_height, j);
		else if (ray->is_vc_hit && ray->is_ray_frt)
			r_ea(g, ray, wall_height, j);
		j++;
	}
	r_floor(g, j, wall_height, ray->index);
}
