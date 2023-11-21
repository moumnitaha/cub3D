/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_mem.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoumni <tmoumni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 15:12:23 by tmoumni           #+#    #+#             */
/*   Updated: 2023/11/20 15:40:21 by tmoumni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	free_mem(t_game *game)
{
	int	i;

	i = 0;
	while (i < game->m_h)
	{
		free(game->map[i]);
		i++;
	}
	free(game->map);
	free(game->so_txt);
	free(game->no_txt);
	free(game->we_txt);
	free(game->ea_txt);
	free(game);
}
