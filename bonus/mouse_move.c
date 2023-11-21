/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse_move.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoumni <tmoumni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 18:33:24 by tmoumni           #+#    #+#             */
/*   Updated: 2023/11/21 10:16:49 by tmoumni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	mouse_move(int x, int y, t_game *g)
{
	if (x > 0 && y > 0 && y < g->height && x < g->width)
	{
		if (x > g->player->m_x)
			g->player->dir += deg_to_rad(2.5);
		else
			g->player->dir -= deg_to_rad(2.5);
		g->player->m_x = x;
		g->player->m_y = y;
		main_draws(g);
	}
	return (0);
}
