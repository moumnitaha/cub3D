/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoumni <tmoumni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 15:12:52 by tmoumni           #+#    #+#             */
/*   Updated: 2023/10/31 15:13:14 by tmoumni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

bool	check_lr(int i, int j)
{
	int	right;
	int	left;

	right = j;
	left = j;
	while (map[i][right] == ' ')
		right++;
	while (map[i][left] == ' ')
		left--;
	if (map[i][right] != '1' || map[i][left] != '1')
		return (false);
	return (true);
}

bool	check_ud(int i, int j)
{
	int	top;
	int	bottom;

	top = i;
	bottom = i;
	while (map[top][j] == ' ' && top > 0)
		top--;
	while (map[bottom][j] == ' ' && bottom < MAX_ROWS - 1)
		bottom++;
	if (map[top][j] == '0' || map[bottom][j] == '0')
		return (false);
	return (true);
}

bool	check_around_spaces(void)
{
	int	start;
	int	end;
	int	i;
	int	j;

	start = 0;
	i = 0;
	end = strlen(map[0]) - 1;
	while (i < MAX_ROWS)
	{
		while (map[i][start] == ' ')
			start++;
		while (map[i][end] == ' ')
			end--;
		j = start;
		while (j <= end)
		{
			if (map[i][j] == ' ')
				if (!check_lr(i, j) || !check_ud(i, j))
					return (false);
			j++;
		}
		i++;
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
	if (!check_around_spaces())
	{
		printf("check_around_spaces\n");
		return (false);
	}
	if (!check_columns())
	{
		printf("check_columns\n");
		return (false);
	}
	return (true);
}
