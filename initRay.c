/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initRay.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoumni <tmoumni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 18:29:24 by tmoumni           #+#    #+#             */
/*   Updated: 2023/10/30 18:47:13 by tmoumni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void initRayDirection(t_ray *ray)
{
	ray->isRayFacingDown = false;
	ray->isRayFacingUp = false;
	ray->isRayFacingLeft = false;
	ray->isRayFacingRight = false;
	if (fixAngle(ray->rayAngle) > 0 && fixAngle(ray->rayAngle) < M_PI)
		ray->isRayFacingDown = true;
	ray->isRayFacingUp = !ray->isRayFacingDown;
	if ((fixAngle(ray->rayAngle) < 0.5 * M_PI) || (fixAngle(ray->rayAngle) > 1.5 * M_PI))
		ray->isRayFacingRight =	true;
	ray->isRayFacingLeft = !ray->isRayFacingRight;
}