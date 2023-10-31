/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoumni <tmoumni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 15:12:52 by tmoumni           #+#    #+#             */
/*   Updated: 2023/10/31 18:14:24 by tmoumni          ###   ########.fr       */
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

	start = 0;
	i = 0;
	end = strlen(game->map[0]) - 1;
	while (i < game->m_h)
	{
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
		printf("checkfirsNlast\n");
		return (false);
	}
	if (!check_around_spaces(game))
	{
		printf("check_around_spaces\n");
		return (false);
	}
	if (!check_columns(game))
	{
		printf("check_columns\n");
		return (false);
	}
	return (true);
}
