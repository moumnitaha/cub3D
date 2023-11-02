/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vcIntersection.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoumni <tmoumni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 18:27:58 by tmoumni           #+#    #+#             */
/*   Updated: 2023/11/02 12:23:20 by tmoumni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	get_vintersections(t_game *g, t_ray *ray, double x_step, double y_step)
{
	while (ray->x_v_hit >= 0 && ray->x_v_hit < g->width
		&& ray->y_v_hit >= 0 && ray->y_v_hit < g->height)
	{
		if (g->map[(int)(ray->y_v_hit / DM)][(int)(ray->x_v_hit / DM)] == '1')
		{
			ray->is_vc_hit = true;
			break ;
		}
		ray->x_v_hit += x_step;
		ray->y_v_hit += y_step;
	}
}

void	vertical_intersection(t_game *g, t_ray *ray)
{
	double	x_step;
	double	y_step;

	ray->x_v_hit = floor(g->player->x / DM) * DM;
	if (ray->is_ray_frt)
		ray->x_v_hit += DM;
	ray->y_v_hit = g->player->y + 
		(ray->x_v_hit - g->player->x) * tan(ray->ray_ang);
	x_step = DM;
	if (ray->is_ray_flf)
		x_step *= -1;
	y_step = DM * tan(ray->ray_ang);
	if (ray->is_ray_fup && y_step > 0)
		y_step *= -1;
	if (ray->is_ray_fdw && y_step < 0)
		y_step *= -1;
	if (ray->is_ray_flf)
		ray->x_v_hit -= 0.1 / (g->m_w * g->m_h);
	get_vintersections(g, ray, x_step, y_step);
	// if (ray->is_vc_hit)
	// 	ray->x_v_hit += 0.1 / (g->m_w * g->m_h);
	ray->v_hit_dis = d_t_pnts(g->player->x, g->player->y,
			ray->x_v_hit, ray->y_v_hit);
}
