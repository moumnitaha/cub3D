/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhaliss <akhaliss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 13:43:18 by tmoumni           #+#    #+#             */
/*   Updated: 2023/11/22 10:01:56 by akhaliss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	validate_rgb(int value)
{
	if (value < 0 || value > 255)
		_error("Error\nInvalid Color\n");
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
					_error("Error\nInvalid Color\n");
			}
			else if (line[i] != ' ' && line[i] != '\n')
				_error("Error\nInvalid Color\n");
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
		_error("Error\ninvalid path\n");
	else
	{
		g = malloc(sizeof(t_game));
		if (!g)
			return (0);
		if (cub(av[1], g))
		{
			p = malloc(sizeof(t_player));
			if (!p)
				return (0);
			myimg = malloc(sizeof(t_img));
			if (!myimg)
				return (0);
			g->mlx = mlx_init();
			init_game(g, p, myimg);
			init_player(g);
			main_hooks(g);
			mlx_clear_window(g->mlx, g->win);
			mlx_destroy_image(g->mlx, g->img->mlx_img);
		}
		else
			_error("Error\ninvalid map\n");
	}
	return (0);
}
