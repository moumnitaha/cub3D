/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoumni <tmoumni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 13:43:18 by tmoumni           #+#    #+#             */
/*   Updated: 2023/10/24 18:56:12 by tmoumni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdbool.h>
#include <string.h>

#define MAX_ROWS 14
#define MAX_COLS 30

char* map[] = {
    "111111111 1111111111111111       ",
    "11111111111110000000000001       ",
    "        1011000001110000111111111",
    "       1100100000000000000000001 ",
    "111111111011000001110000000000011",
    "10000000001100000111011111110011 ",
    "111101111111110111000000100000101",
    "111101111111110111010100100011111",
    "11100000111 110111000000100000001",
    "10000000001 100011000000100011111",
    "10000000000100000101010010001    ",
    "1100000111010101111011110N0111   ",
    "11110111 1110101 1111101000111   ",
    "11111111 1111111 111111111111    "
};

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
	// int start = 0;
	// int end = strlen(map[0]) - 1;
	// while(map[0][start] == ' ')
	// 	start++;
	// while(map[0][end] == ' ')
	// 	end--;
	// for (int i = start; i < end; i++) {
	// 	if(map[0][i] != '1' && map[0][i] != ' ')
	// 		return false;
	// }
	// start = 0;
	// end = strlen(map[0]) - 1;
	// while(map[MAX_ROWS - 1][start] == ' ')
	// 	start++;
	// while(map[MAX_ROWS - 1][end] == ' ')
	// 	end--;
	// for (int i = start; i <= end; i++) {
	// 	if(map[MAX_ROWS - 1][i] != '1' && map[MAX_ROWS - 1][i] != ' ')
	// 		return false;
	// }
	// ======
	// for (int i = 0; i < MAX_ROWS; i++) {
	// 	start = 0;
	// 	end = strlen(map[0]) - 1;
	// 	while(map[i][start] == ' ')
	// 	{
	// 		if (i < MAX_ROWS - 1 && map[i + 1][start] == '0')
	// 			return false;
	// 		if (i > 0 && map[i - 1][start] == '0')
	// 			return false;
	// 		start++;
	// 	}
	// 	while(map[i][end] == ' ') {
	// 		if (i < MAX_ROWS - 1 && map[i + 1][end] == '0')
	// 			return false;
	// 		if (i > 0 && map[i - 1][end] == '0')
	// 			return false;
	// 		end--;
	// 	}
	// 	if(map[i][start] != '1' || map[i][end] != '1')
	// 		return false;
	// =========
		// for (int j = start; j <= end; j++)
		// {
		// 	if (map[i][j] == ' ')
		// 	{
		// 		int right = j;
		// 		int left = j;
		// 		while(map[i][right] == ' ')
		// 			right++;
		// 		while(map[i][left] == ' ')
		// 			left--;
		// 		if (map[i][right] != '1' || map[i][left] != '1')
		// 			return false;
		// 		int top = i;
		// 		int bottom = i;
		// 		while(map[top][j] == ' ' && top > 0)
		// 			top--;
		// 		while(map[bottom][j] == ' ' && bottom < MAX_ROWS - 1)
		// 			bottom++;
		// 		if (map[top][j] == '0' || map[bottom][j] == '0')
		// 			return false;
		// 	}
		// }
	// }
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

int main() {
    if (isSurroundedByWalls()) {
        printf("The map is completely surrounded by walls.\n");
    } else {
        printf("XXXX The map is not completely surrounded by walls. XXXX\n");
    }
    return 0;
}

