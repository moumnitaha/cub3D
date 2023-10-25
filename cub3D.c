/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoumni <tmoumni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 15:13:39 by tmoumni           #+#    #+#             */
/*   Updated: 2023/10/25 22:58:58 by tmoumni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "cub3D.h"
#include <math.h>
#include <time.h>
#include "math.h"

#define MAX_ROWS 14
#define MAX_COLS 33
#define green 0x00008000
#define red  0x00FF0000
#define blue 0x000000FF
#define white 0x00FFFFFF
#define black 0x00000000


char* map[] = {
    "111111111 11111111111111111111111",
    "11111111111110000000000001111111 ",
    "        1011000001110000111111111",
    "       1100100000000000000000001 ",
    "111111111011000001110000000000011",
    "10000000000000000111011111110011 ",
    "111101111111110111000000100000101",
    "111101111111110111010100100011111",
    "11100000111  10111000000100000001",
    "10000000001  10011000000100011111",
    "10000000000111000101010P10001    ",
    "110000011101010111000111000111   ",
    "11110111 1110101 1111100000111   ",
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

void draw_rect(t_game *g, int x , int y, int color)
{
	int width = DM + y;
	int height = DM + x;
	int i = y;
	int j = x;
	while (i < width)
	{
		j = x;
		while (j < height)
		{
			mlx_pixel_put(g->mlx, g->win, j, i, color);
			j++;
		}
		i++;
	}
}

void DDA(t_game *g, int X0, int Y0, int X1, int Y1)
{
	int dx = X1 - X0;
	int dy = Y1 - Y0;
	int steps = abs(dx) > abs(dy) ? abs(dx) : abs(dy);
	float Xinc = dx / (float)steps;
	float Yinc = dy / (float)steps;
	float X = X0;
	float Y = Y0;
	for (int i = 0; i <= steps; i++)
	{
		mlx_pixel_put(g->mlx, g->win, X, Y, red);
		X += Xinc;
		Y += Yinc;
	}  
} 

void	mlx_put_imgs(t_game *g)
{
	for (int i = 0; i < MAX_ROWS; i++)
	{
		for (int j = 0; j < MAX_COLS; j++)
		{
			if (map[i][j] == '1')
				draw_rect(g, j * DM , i * DM , black);
			else if (map[i][j] == ' ')
				draw_rect(g, j * DM, i * DM, red);
			// else if (map[i][j] == 'P')
			// 	draw_rect(g, j * DM, i * DM, blue);
			else if (map[i][j] == '0' || map[i][j] == 'P')
				draw_rect(g, j * DM, i * DM, white);
		}
	}
}

void draw_player(t_game *g, int x_pos, int y_pos)
{
	int width = 8 + y_pos;
	int height = 8 + x_pos;
	int i = y_pos;
	int j = x_pos;
	while (i < width)
	{
		j = x_pos;
		while (j < height)
		{
			mlx_pixel_put(g->mlx, g->win, j - 4, i - 4, blue);
			j++;
		}
		i++;
	}
}


int get_player_position()
{
	for (int i = 0; i < MAX_ROWS; i++)
	{
		for (int j = 0; j < MAX_COLS; j++)
		{
			if (map[i][j] == 'P')
				return i * MAX_COLS + j;
		}
	}
	return -1;
}

int	exit_game(t_game *game)
{
	mlx_destroy_window(game->mlx, game->win);
	exit(0);
}


int	key_press(int keycode, t_game *game)
{
	time_t t;
    time(&t);
	if (keycode == KEY_UP)
	{
		// if (map[(game->player->y - 8) / DM][game->player->x / DM] == '1')
		// 	return (0);
		game->player->y += 8 * sin(game->player->dir);
		game->player->x += 8 * cos(game->player->dir);
		if (map[game->player->y / DM][game->player->x / DM] == '1')
			printf("%s POSITIONS : X = %d, Y = %d\n",ctime(&t), game->player->x / DM, game->player->y / DM);
		mlx_clear_window(game->mlx, game->win);
		mlx_put_imgs(game);
		draw_player(game, game->player->x, game->player->y);
		DDA(game, game->player->x, game->player->y, game->player->x + cos(game->player->dir) * 30, game->player->y + sin(game->player->dir) * 30);

	}
	else if (keycode == KEY_DOWN)
	{
		game->player->y -= 8 * sin(game->player->dir);
		game->player->x -= 8 * cos(game->player->dir);
		if (map[game->player->y / DM][game->player->x / DM] == '1')
			printf("POSITIONS : X = %d, Y = %d\n", game->player->x / DM, game->player->y / DM);
		mlx_clear_window(game->mlx, game->win);
		mlx_put_imgs(game);
		draw_player(game, game->player->x, game->player->y);
		DDA(game, game->player->x, game->player->y, game->player->x + cos(game->player->dir) * 30, game->player->y + sin(game->player->dir) * 30);
	}
	else if (keycode == KEY_LEFT)
	{
		game->player->dir -= 0.1;
		mlx_clear_window(game->mlx, game->win);
		mlx_put_imgs(game);
		draw_player(game, game->player->x, game->player->y);
		DDA(game, game->player->x, game->player->y, game->player->x + cos(game->player->dir) * 30, game->player->y + sin(game->player->dir) * 30);
	}
	else if (keycode == KEY_RIGHT){
		game->player->dir += 0.1;
		mlx_clear_window(game->mlx, game->win);
		mlx_put_imgs(game);
		draw_player(game, game->player->x, game->player->y);
		DDA(game, game->player->x, game->player->y, game->player->x + cos(game->player->dir) * 30, game->player->y + sin(game->player->dir) * 30);
	}
	if (keycode == KEY_ESC)
		exit_game(game);
	return (0);
}

int	escape_game(t_game *game)
{
	printf("\033[1;31m[[ U gaved up :/ ]]\033[0m\n");
	return (exit_game(game));
}

int main()
{
    if (isSurroundedByWalls()) {
        printf("The map is completely surrounded by walls.\n");
    } else {
        printf("XXXX The map is not completely surrounded by walls. XXXX\n");
    }

	t_game		*g;
	t_player	*p;
	p = malloc(sizeof(t_player));
	g = malloc(sizeof(t_game));
	g->mlx = mlx_init();
	g->height = MAX_ROWS;
	g->width = MAX_COLS;
	g->win = mlx_new_window(g->mlx, DM * g->width, DM * g->height, "./cub3D");

	p->x = (get_player_position() % MAX_COLS) * DM;
	p->y = (get_player_position() / MAX_COLS) * DM;
	p->dir = -M_PI_2;
	g->player = p;

	mlx_put_imgs(g);
	draw_player(g, p->x, p->y);
	DDA(g, p->x, p->y, p->x + (cos(p->dir) * 30), p->y + (sin(p->dir) * 30));
	// mlx_hook(g->win, X_EVENT_KEY_PRESS, 0, &key_press, g);
	mlx_key_hook(g->win, &key_press, g);
	mlx_hook(g->win, X_EVENT_KEY_EXIT, 0, &escape_game, g);
	mlx_loop(g->mlx);
    return 0;
}
