/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoumni <tmoumni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 18:45:44 by tmoumni           #+#    #+#             */
/*   Updated: 2023/10/31 15:20:10 by tmoumni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

bool	check_fl(void)
{
	int	start;
	int	end;

	start = 0;
	end = strlen(map[0]) - 1;
	while (map[0][start] == ' ')
		start++;
	while (map[0][end] == ' ')
		end--;
	while (start < end)
	{
		if (map[0][start] != '1' && map[0][start] != ' ')
			return (false);
		start++;
	}
	return (true);
}

bool	check_ll(void)
{
	int	start;
	int	end;

	start = 0;
	end = strlen(map[0]) - 1;
	while (map[MAX_ROWS - 1][start] == ' ')
		start++;
	while (map[MAX_ROWS - 1][end] == ' ')
		end--;
	while (start <= end)
	{
		if (map[MAX_ROWS - 1][start] != '1' && map[MAX_ROWS - 1][start] != ' ')
			return (false);
		start++;
	}
	return (true);
}

bool	check_firs_last(void)
{
	if (!check_fl())
		return (false);
	if (!check_ll())
		return (false);
	return (true);
}

bool	check_clm(int i, int index)
{
	if (i < MAX_ROWS - 1 && map[i + 1][index] == '0')
		return (false);
	if (i > 0 && map[i - 1][index] == '0')
		return (false);
	return (true);
}

bool	check_columns(void)
{
	int	start;
	int	end;
	int	i;

	i = -1;
	while (++i < MAX_ROWS)
	{
		start = 0;
		end = strlen(map[0]) - 1;
		while (map[i][start] == ' ')
		{
			if (!check_clm(i, start))
				return (false);
			start++;
		}
		while (map[i][end] == ' ')
		{
			if (!check_clm(i, end))
				return (false);
			end--;
		}
		if (map[i][start] != '1' || map[i][end] != '1')
			return (false);
	}
	return (true);
}
