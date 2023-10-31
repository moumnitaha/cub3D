/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhaliss <akhaliss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 13:43:18 by tmoumni           #+#    #+#             */
/*   Updated: 2023/10/31 12:14:45 by akhaliss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	main(int ac, char **av)
{
	if (ac != 2)
		write(2, "invalid path\n", 13);
	else
	{
		if (cub(av[1]))
			printf("done\n");
	}

	t_game		*g;
	t_player	*p;
	t_ray		*ray;

	if (!is_surrounded_by_walls())
	{
		printf("XXXX The map is not completely surrounded by walls. XXXX\n");
		return (0);
	}
	p = malloc(sizeof(t_player));
	g = malloc(sizeof(t_game));
	ray = malloc(sizeof(t_ray));
	g->mlx = mlx_init();
	init_game(g, p);
	init_player(g);
	main_draws(g);
	mlx_hook(g->win, X_EVENT_KEY_PRESS, 0, &key_press, g);
	mlx_hook(g->win, 6, 1L << 6, mouse_move, g);
	mlx_hook(g->win, X_EVENT_KEY_EXIT, 0, &escape_game, g);
	mlx_loop(g->mlx);
	return (0);
}
