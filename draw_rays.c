/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_rays.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoumni <tmoumni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 18:23:32 by tmoumni           #+#    #+#             */
/*   Updated: 2023/10/30 18:44:42 by tmoumni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void draw_rays(t_game *g)
{
	t_ray *ray;
	double vWallStripHeight;
	double hWallStripHeight;
	double mapWidth = g->player->FOV / g->width;
	int i = 0;

	ray = malloc(sizeof(t_ray));
	ray->rayAngle = g->player->dir - degToRad(g->player->FOV / 2);
	while(ray->rayAngle < g->player->dir + degToRad(g->player->FOV / 2))
	{
		initRayDirection(ray);
		ray->isHzHit = false;
		horizontalIntersection(g, ray);
		ray->isVcHit = false;
		verticalIntersection(g, ray);
		ray->dToPP = (g->width / 2) / tanf(degToRad(g->player->FOV / 2));
		hWallStripHeight = (DM / ray->hHitDis) * ray->dToPP / cos(g->player->dir - ray->rayAngle);
		vWallStripHeight = (DM / ray->vHitDis) * ray->dToPP / cos(g->player->dir - ray->rayAngle);
		if (ray->isHzHit && ray->isVcHit)
		{
			if (ray->hHitDis < ray->vHitDis + (0.1 / g->width))
				render3DProjectedWalls(g, hWallStripHeight, i, gray);
			else
				render3DProjectedWalls(g, vWallStripHeight, i, green);
		}
		else if (ray->isHzHit)
			render3DProjectedWalls(g, hWallStripHeight, i, gray);
		else if (ray->isVcHit)
			render3DProjectedWalls(g, vWallStripHeight, i, green);
		ray->rayAngle += degToRad(mapWidth);
		i++;
	}
	printf("I => [%d]\n", i);
	free(ray);
}