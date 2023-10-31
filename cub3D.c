/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhaliss <akhaliss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 13:43:18 by tmoumni           #+#    #+#             */
/*   Updated: 2023/10/31 17:34:26 by akhaliss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	main(int ac, char **av)
{
	t_game		*g;
	t_player	*p;
	t_ray		*ray;

	g = malloc(sizeof(t_game));
	p = malloc(sizeof(t_player));
	ray = malloc(sizeof(t_ray));
	if (ac != 2)
		write(2, "invalid path\n", 13);
	else
	{
		if (cub(av[1], g))
		{		
			g->mlx = mlx_init();
			init_game(g, p);
			init_player(g);
			main_draws(g);
			mlx_hook(g->win, X_EVENT_KEY_PRESS, 0, &key_press, g);
			mlx_hook(g->win, 6, 1L << 6, mouse_move, g);
			mlx_hook(g->win, X_EVENT_KEY_EXIT, 0, &escape_game, g);
			mlx_loop(g->mlx);
		}
		// printf("done\n");
		else
		{
			write(2, "invalid map\n", 12);
			return (0);
		}
	}
	return (0);
}
