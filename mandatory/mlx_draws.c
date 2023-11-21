/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_draws.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoumni <tmoumni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 18:31:11 by tmoumni           #+#    #+#             */
/*   Updated: 2023/11/21 13:38:04 by tmoumni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	main_draws(t_game *g)
{
	mlx_clear_window(g->mlx, g->win);
	update_player(g);
	render_rays(g);
	return (0);
}
