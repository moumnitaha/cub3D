/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoumni <tmoumni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 13:43:18 by tmoumni           #+#    #+#             */
/*   Updated: 2023/11/20 15:44:43 by tmoumni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	validate_rgb(int value)
{
	if (value < 0 || value > 255)
		_error("Error: Invalid Color 1\n");
}

int	extract_rgb(char *line, int *rgb, int *j)
{
	int	i;
	int	start;

	i = 0;
	while (line[i])
	{
		while (line[i] && !ft_isdigit(line[i]))
		{
			if (line[i] == ',')
			{
				(*j)++;
				if (*j > 2)
					_error("Error: Invalid Color 2\n");
			}
			else if (line[i] != ' ' && line[i] != '\n')
				_error("Error: Invalid Color 2\n");
			i++;
		}
		start = i;
		while (line[i] && ft_isdigit(line[i]))
			i++;
		rgb[*j] = ft_atoi(line + start);
		validate_rgb(rgb[*j]);
	}
	return (i);
}

void	main_hooks(t_game *g)
{
	mlx_hook(g->win, X_EVENT_KEY_PRESS, 0, &key_press, g);
	mlx_hook(g->win, X_EVENT_KEY_RELEASE, 0, &key_release, g);
	mlx_hook(g->win, 6, 1L << 6, mouse_move, g);
	mlx_hook(g->win, X_EVENT_KEY_EXIT, 0, &escape_game, g);
	mlx_loop_hook(g->mlx, main_draws, g);
	mlx_loop(g->mlx);
}

int	main(int ac, char **av)
{
	t_game		*g;
	t_player	*p;
	t_img		*myimg;

	if (ac != 2)
		write(2, "invalid path\n", 13);
	else
	{
		g = malloc(sizeof(t_game));
		if (cub(av[1], g))
		{
			p = malloc(sizeof(t_player));
			myimg = malloc(sizeof(t_img));
			g->mlx = mlx_init();
			init_game(g, p, myimg);
			init_player(g);
			main_hooks(g);
			mlx_clear_window(g->mlx, g->win);
			mlx_destroy_image(g->mlx, g->img->mlx_img);
		}
		else
			write(2, "invalid map\n", 12);
	}
	return (0);
}
