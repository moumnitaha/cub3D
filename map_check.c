/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoumni <tmoumni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 18:45:44 by tmoumni           #+#    #+#             */
/*   Updated: 2023/10/31 13:14:22 by tmoumni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

bool	check_firs_last(void)
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

bool	check_columns(void)
{
	int	start;
	int	end;
	int	i;

	i = 0;
	while (i < MAX_ROWS)
	{
		start = 0;
		end = strlen(map[0]) - 1;
		while (map[i][start] == ' ')
		{
			if (i < MAX_ROWS - 1 && map[i + 1][start] == '0')
				return (false);
			if (i > 0 && map[i - 1][start] == '0')
				return (false);
			start++;
		}
		while (map[i][end] == ' ')
		{
			if (i < MAX_ROWS - 1 && map[i + 1][end] == '0')
				return (false);
			if (i > 0 && map[i - 1][end] == '0')
				return (false);
			end--;
		}
		if (map[i][start] != '1' || map[i][end] != '1')
			return (false);
		i++;
	}
	return (true);
}

bool	check_around_spaces(void)
{
	int start;
	int end;

	start = 0;
	end = strlen(map[0]) - 1;
	for (int i = 0; i < MAX_ROWS; i++) {
		while (map[i][start] == ' ')
			start++;
		while (map[i][end] == ' ')
			end--;
		for (int j = start; j <= end; j++)
		{
			if (map[i][j] == ' ')
			{
				int right = j;
				int left = j;
				while (map[i][right] == ' ')
					right++;
				while (map[i][left] == ' ')
					left--;
				if (map[i][right] != '1' || map[i][left] != '1')
					return (false);
				int top = i;
				int bottom = i;
				while (map[top][j] == ' ' && top > 0)
					top--;
				while (map[bottom][j] == ' ' && bottom < MAX_ROWS - 1)
					bottom++;
				if (map[top][j] == '0' || map[bottom][j] == '0')
					return (false);
			}
		}
	}
	return (true);
}

bool	is_surrounded_by_walls(void)
{
	if (!check_firs_last())
	{
		printf("checkfirsNlast\n");
		return (false);
	}
	if (!check_columns())
	{
		printf("check_columns\n");
		return (false);
	}
	if (!check_around_spaces())
	{
		printf("check_around_spaces\n");
		return (false);
	}
	return (true);
}
