/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_move.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoumni <tmoumni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 18:33:24 by tmoumni           #+#    #+#             */
/*   Updated: 2023/10/31 12:05:42 by tmoumni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	mouse_move(int x, int y, t_game *g)
{
	if (x > 0 && y > 0 && y < g->height && x < g->width)
	{
		g->player->dir = atan2((y - g->player->y) / 5, (x - g->player->x) / 5);
		main_draws(g);
	}
	return (0);
}
