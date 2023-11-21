/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoumni <tmoumni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 15:12:52 by tmoumni           #+#    #+#             */
/*   Updated: 2023/11/21 12:27:55 by tmoumni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

bool	check_lr(int i, int j, t_game *game)
{
	int	right;
	int	left;

	right = j;
	left = j;
	while (game->map[i][right] == ' ')
		right++;
	while (game->map[i][left] == ' ')
		left--;
	if (game->map[i][right] != '1' || game->map[i][left] != '1')
		return (false);
	return (true);
}

bool	check_ud(int i, int j, t_game *game)
{
	int	top;
	int	bottom;

	top = i;
	bottom = i;
	while (game->map[top][j] == ' ' && top > 0)
		top--;
	while (game->map[bottom][j] == ' ' && bottom < game->m_h - 1)
		bottom++;
	if (game->map[top][j] == '0' || game->map[bottom][j] == '0')
		return (false);
	return (true);
}

bool	check_around_spaces(t_game *game)
{
	int	start;
	int	end;
	int	i;
	int	j;

	i = 0;
	while (i < game->m_h)
	{
		start = 0;
		end = ft_strlen(game->map[0]) - 1;
		while (game->map[i][start] == ' ')
			start++;
		while (game->map[i][end] == ' ')
			end--;
		j = start;
		while (j <= end)
		{
			if (game->map[i][j] == ' ')
				if (!check_lr(i, j, game) || !check_ud(i, j, game))
					return (false);
			j++;
		}
		i++;
	}
	return (true);
}

bool	is_surrounded_by_walls(t_game *game)
{
	if (!check_firs_last(game))
	{
		return (false);
	}
	if (!check_around_spaces(game))
	{
		return (false);
	}
	if (!check_columns(game))
	{
		return (false);
	}
	return (true);
}
