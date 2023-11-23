/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D_bn.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoumni <tmoumni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 13:43:18 by tmoumni           #+#    #+#             */
/*   Updated: 2023/11/23 15:06:22 by tmoumni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D_bonus.h"

void	validate_rgb(int value)
{
	if (value < 0 || value > 255)
		_error("Error\nInvalid Color\n");
}

void	_vr(char *line)
{
	int	i;
	int	count;

	count = 0;
	i = -1;
	while (line[++i])
	{
		if (line[i] == ',' && i != 0 && line[i + 1] != ',')
			count++;
	}
	if (count > 2 || count < 2)
		_error("Error\nInvalid Color\n");
}

int	extract_rgb(char *line, int *rgb, int *j)
{
	int	i;
	int	start;

	i = 0;
	_vr(line);
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
			else if ((line[i] != ' ' && line[i] != '\n'))
				_error("Error\nInvalid Color\n");
			i++;
		}
		start = i;
		while (line[i] && ft_isdigit(line[i]))
			i++;
		validate_rgb(rgb[*j] = ft_atoi(line + start));
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
		_error("Error\ninvalid path\n");
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
	}
	return (0);
}
