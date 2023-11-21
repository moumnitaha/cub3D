/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hzIntersection.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoumni <tmoumni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 18:27:29 by tmoumni           #+#    #+#             */
/*   Updated: 2023/11/03 12:43:20 by tmoumni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	get_hintersections(t_game *g, t_ray *ray, double x_step, double y_step)
{
	while (ray->x_h_hit >= 0 && ray->x_h_hit < g->m_w * DM
		&& ray->y_h_hit >= 0 && ray->y_h_hit < g->m_h * DM)
	{
		if (g->map[(int)(ray->y_h_hit / DM)][(int)(ray->x_h_hit / DM)] == '1')
		{
			ray->is_hz_hit = true;
			break ;
		}
		ray->x_h_hit += x_step;
		ray->y_h_hit += y_step;
	}
}

void	horizontal_intersection(t_game *g, t_ray *ray)
{
	double	x_step;
	double	y_step;

	ray->y_h_hit = floor(g->player->y / DM) * DM;
	if (ray->is_ray_fdw)
		ray->y_h_hit += DM;
	ray->x_h_hit = g->player->x + 
		(ray->y_h_hit - g->player->y) / tan(ray->ray_ang);
	y_step = DM;
	if (ray->is_ray_fup)
		y_step *= -1;
	x_step = DM / tan(ray->ray_ang);
	if (ray->is_ray_flf && x_step > 0)
		x_step *= -1;
	if (ray->is_ray_frt && x_step < 0)
		x_step *= -1;
	if (ray->is_ray_fup)
		ray->y_h_hit -= 1;
	get_hintersections(g, ray, x_step, y_step);
	if (ray->is_ray_fup)
		ray->y_h_hit += 1;
	ray->h_hit_dis = d_t_pnts(g->player->x, g->player->y,
			ray->x_h_hit, ray->y_h_hit);
}
