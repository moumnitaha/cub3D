/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_check.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoumni <tmoumni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 18:45:44 by tmoumni           #+#    #+#             */
/*   Updated: 2023/10/30 18:48:58 by tmoumni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

bool checkfirsNlast()
{
	int start = 0;
	int end = strlen(map[0]) - 1;
	while(map[0][start] == ' ')
		start++;
	while(map[0][end] == ' ')
		end--;
	for (int i = start; i < end; i++) {
		if(map[0][i] != '1' && map[0][i] != ' ')
			return false;
	}
	start = 0;
	end = strlen(map[0]) - 1;
	while(map[MAX_ROWS - 1][start] == ' ')
		start++;
	while(map[MAX_ROWS - 1][end] == ' ')
		end--;
	for (int i = start; i <= end; i++) {
		if(map[MAX_ROWS - 1][i] != '1' && map[MAX_ROWS - 1][i] != ' ')
			return false;
	}
	return true;
}

bool checkColumns(){
	int	start = 0;
	int	end = strlen(map[0]) - 1;
	for (int i = 0; i < MAX_ROWS; i++) {
		start = 0;
		end = strlen(map[0]) - 1;
		while(map[i][start] == ' ')
		{
			if (i < MAX_ROWS - 1 && map[i + 1][start] == '0')
				return false;
			if (i > 0 && map[i - 1][start] == '0')
				return false;
			start++;
		}
		while(map[i][end] == ' ')
		{
			if (i < MAX_ROWS - 1 && map[i + 1][end] == '0')
				return false;
			if (i > 0 && map[i - 1][end] == '0')
				return false;
			end--;
		}
		if(map[i][start] != '1' || map[i][end] != '1')
			return false;
	}
	return true;
}

bool checkAroundSpaces()
{
	int start = 0;
	int end = strlen(map[0]) - 1;
	for (int i = 0; i < MAX_ROWS; i++) {
		while(map[i][start] == ' ')
			start++;
		while(map[i][end] == ' ')
			end--;
		for (int j = start; j <= end; j++)
		{
			if (map[i][j] == ' ')
			{
				int right = j;
				int left = j;
				while(map[i][right] == ' ')
					right++;
				while(map[i][left] == ' ')
					left--;
				if (map[i][right] != '1' || map[i][left] != '1')
					return false;
				int top = i;
				int bottom = i;
				while(map[top][j] == ' ' && top > 0)
					top--;
				while(map[bottom][j] == ' ' && bottom < MAX_ROWS - 1)
					bottom++;
				if (map[top][j] == '0' || map[bottom][j] == '0')
					return false;
			}
		}
	}
	return true;
}

bool isSurroundedByWalls() {
	if (!checkfirsNlast())
	{
		printf("checkfirsNlast\n");
		return false;
	}
	if (!checkColumns())
	{
		printf("checkColumns\n");
		return false;
	}
	if (!checkAroundSpaces())
	{
		printf("checkAroundSpaces\n");
		return false;
	}
	return true;
}