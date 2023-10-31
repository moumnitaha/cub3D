/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoumni <tmoumni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 11:25:20 by tmoumni           #+#    #+#             */
/*   Updated: 2023/10/31 12:47:40 by tmoumni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int main()
{
    if (is_surrounded_by_walls()) {
        printf("The map is completely surrounded by walls.\n");
    } else {
        printf("XXXX The map is not completely surrounded by walls. XXXX\n");
		return (0);
    }
	t_game		*g;
	t_player	*p;
	t_ray		*ray;

	p = malloc(sizeof(t_player));
	g = malloc(sizeof(t_game));
	ray = malloc(sizeof(t_ray));
	g->mlx = mlx_init();
	g->height = MAX_ROWS * DM;
	g->width = MAX_COLS * DM;
	g->win = mlx_new_window(g->mlx, g->width, g->height, "./cub3D");
	g->scale = 0.2;
	p->x = (get_player_position() % MAX_COLS) * DM + DM / 2;
	p->y = (get_player_position() / MAX_COLS) * DM + DM / 2;
	p->dir = -M_PI_2;
	p->fov = 60;

	g->player = p;
	main_draws(g);
	mlx_hook(g->win, X_EVENT_KEY_PRESS, 0, &key_press, g);
	mlx_hook(g->win, 6, 1L << 6, mouse_move, g);
	mlx_hook(g->win, X_EVENT_KEY_EXIT, 0, &escape_game, g);
	mlx_loop(g->mlx);
    return 0;
}
