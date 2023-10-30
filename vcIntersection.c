/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vcIntersection.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoumni <tmoumni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 18:27:58 by tmoumni           #+#    #+#             */
/*   Updated: 2023/10/30 18:48:21 by tmoumni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void verticalIntersection(t_game *g, t_ray *ray)
{
	double xStep;
	double yStep;

	ray->xVhit = floor(g->player->x / DM) * DM;
	if (ray->isRayFacingRight)
		ray->xVhit += DM;
	ray->yVhit = g->player->y + (ray->xVhit - g->player->x) * tanf(ray->rayAngle);
	xStep = DM;
	if (ray->isRayFacingLeft)
		xStep *= -1;
	yStep = DM * tanf(ray->rayAngle);
	if (ray->isRayFacingUp && yStep > 0)
		yStep *= -1;
	if (ray->isRayFacingDown && yStep < 0)
		yStep *= -1;
	if (ray->isRayFacingLeft)
		ray->xVhit -= (0.1 / g->width);
	while (ray->xVhit >= 0 && ray->xVhit < g->width && ray->yVhit >= 0 && ray->yVhit < g->height)
	{
		if (map[(int)(ray->yVhit / DM)][(int)(ray->xVhit / DM)] == '1')
		{
			ray->isVcHit = true;
			break;
		}
		ray->xVhit += xStep;
		ray->yVhit += yStep;
	}
	ray->vHitDis = dis_two_pnts(g->player->x, g->player->y, ray->xVhit, ray->yVhit);
}