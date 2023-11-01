/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_move.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoumni <tmoumni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 18:33:24 by tmoumni           #+#    #+#             */
/*   Updated: 2023/11/01 16:20:45 by tmoumni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	mouse_move(int x, int y, t_game *g)
{
	if (x > 0 && y > 0 && y < g->height && x < g->width)
	{
		g->player->dir = atan2((y - g->height / 2), (x - g->width / 2));
		main_draws(g);
	}
	return (0);
}
