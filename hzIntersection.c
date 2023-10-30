/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hzIntersection.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoumni <tmoumni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 18:27:29 by tmoumni           #+#    #+#             */
/*   Updated: 2023/10/30 18:47:07 by tmoumni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void horizontalIntersection(t_game *g, t_ray *ray)
{
	double xStep;
	double yStep;

	ray->yHhit = floor(g->player->y / DM) * DM;
	if (ray->isRayFacingDown)
		ray->yHhit += DM;
	ray->xHhit = g->player->x + (ray->yHhit - g->player->y) / tanf(ray->rayAngle);
	yStep = DM;
	if (ray->isRayFacingUp)
		yStep *= -1;
	xStep = DM / tanf(ray->rayAngle);
	if (ray->isRayFacingLeft && xStep > 0)
		xStep *= -1;
	if (ray->isRayFacingRight && xStep < 0)
		xStep *= -1;
	if (ray->isRayFacingUp)
		ray->yHhit -= (0.1 / g->width);
	while (ray->xHhit >= 0 && ray->xHhit < g->width && ray->yHhit >= 0 && ray->yHhit < g->height)
	{
		if (map[(int)(ray->yHhit / DM)][(int)(ray->xHhit / DM)] == '1')
		{
			ray->isHzHit = true;
			break;
		}
		ray->xHhit += xStep;
		ray->yHhit += yStep;
	}
	ray->hHitDis = dis_two_pnts(g->player->x, g->player->y, ray->xHhit, ray->yHhit);
}