/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhaliss <akhaliss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 18:19:35 by akhaliss          #+#    #+#             */
/*   Updated: 2023/10/30 18:37:58 by akhaliss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	_error(char *err)
{
	ft_putstr_fd(err, 2);
	exit(1);
}

int p_name(char *s)
{
	int	i;

	i = ft_strlen(s);
	if(s[i - 1] == 'b' && s[i - 2] == 'u'
		&& s[i - 3] == 'c' && s[i - 4] == '.')
		return (1);
	return (0);
}

void	init_map(t_game *game)
{
	game->ceilling_c = -1;
	game->floor_c = -1;
	game->no_txt = NULL;
	game->ea_txt = NULL;
	game->so_txt = NULL;
	game->we_txt = NULL;
	game->mlen = 0;
}

int	cub(char *av)
{
	t_game	*game;

	if (!p_name(av))
		return(write(2, "Invalid map name\n", 17), 0);
	game = malloc(sizeof(t_game));
	init_map(game);
	read_map(av, game);
	// if (parse_map(game))
	// 	return (1);
	// return (0);
	return (1);	
}
