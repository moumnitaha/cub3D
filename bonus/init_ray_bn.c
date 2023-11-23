/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_ray_bn.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoumni <tmoumni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 18:29:24 by tmoumni           #+#    #+#             */
/*   Updated: 2023/11/23 13:26:04 by tmoumni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

void	init_ray_direction(t_ray *ray)
{
	float	fixed_angle;

	fixed_angle = fix_ang(ray->ray_ang);
	ray->is_ray_fdw = false;
	ray->is_ray_fup = false;
	ray->is_ray_flf = false;
	ray->is_ray_frt = false;
	ray->is_hz_hit = false;
	ray->is_vc_hit = false;
	ray->h_hit_dis = INT_MAX;
	ray->v_hit_dis = INT_MAX;
	ray->dist = 0;
	if (fixed_angle > 0 && fixed_angle < M_PI)
		ray->is_ray_fdw = true;
	ray->is_ray_fup = !ray->is_ray_fdw;
	if ((fixed_angle < M_PI_2) || (fixed_angle > 1.5 * M_PI))
		ray->is_ray_frt = true;
	ray->is_ray_flf = !ray->is_ray_frt;
}
