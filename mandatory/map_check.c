/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoumni <tmoumni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 18:45:44 by tmoumni           #+#    #+#             */
/*   Updated: 2023/11/01 15:25:39 by tmoumni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

bool	check_fl(t_game *game)
{
	int	start;
	int	end;

	start = 0;
	end = ft_strlen(game->map[0]) - 1;
	if (end < 0)
		return (false);
	while (game->map[0][start] == ' ')
		start++;
	while (game->map[0][end] == ' ')
		end--;
	while (start < end)
	{
		if (game->map[0][start] != '1' && game->map[0][start] != ' ')
			return (false);
		start++;
	}
	return (true);
}

bool	check_ll(t_game *game)
{
	int	start;
	int	end;

	start = 0;
	end = ft_strlen(game->map[0]) - 1;
	while (game->map[game->m_h - 1][start] == ' ')
		start++;
	while (game->map[game->m_h - 1][end] == ' ')
		end--;
	while (start <= end)
	{
		if (game->map[game->m_h - 1][start] != '1' && 
			game->map[game->m_h - 1][start] != ' ')
			return (false);
		start++;
	}
	return (true);
}

bool	check_firs_last(t_game *game)
{
	if (!check_fl(game))
		return (false);
	if (!check_ll(game))
		return (false);
	return (true);
}

bool	check_clm(int i, int index, t_game *game)
{
	if (i < game->m_h - 1 && game->map[i + 1][index] == '0')
		return (false);
	if (i > 0 && game->map[i - 1][index] == '0')
		return (false);
	return (true);
}

bool	check_columns(t_game *game)
{
	int	start;
	int	end;
	int	i;

	i = -1;
	while (++i < game->m_h)
	{
		start = 0;
		end = ft_strlen(game->map[0]) - 1;
		while (game->map[i][start] == ' ')
		{
			if (!check_clm(i, start, game))
				return (false);
			start++;
		}
		while (game->map[i][end] == ' ')
		{
			if (!check_clm(i, end, game))
				return (false);
			end--;
		}
		if (game->map[i][start] != '1' || game->map[i][end] != '1')
			return (false);
	}
	return (true);
}
