/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoumni <tmoumni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 15:13:39 by tmoumni           #+#    #+#             */
/*   Updated: 2023/10/28 23:10:19 by tmoumni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include <stdio.h>
#include <stdbool.h>
#include <string.h>
#include "cub3D.h"
#include <math.h>
#include <time.h>
#include "math.h"

#define MAX_ROWS 10
#define MAX_COLS 33
#define green 0x00008000
#define red  0x00FF0000
#define blue 0x000000FF
#define white 0x00FFFFFF
#define black 0x00000000
#define gray 0x00C0C0C0
#define bluesky 0x00199EF3


char* map[] = {
    "111111111111111111111111111111111",
    "10000000000000000011011111110011 ",
    "111101111111110110000000000000101",
    "111101111111110111010100000011111",
    "11100000111  10111000000000000001",
    "10000000001  10011000000000011111",
    "10000000000111000101010P00001    ",
    "110000011100010111000111000111   ",
    "11110111 1110001 1111100000111   ",
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

double degToRad(double deg)
{
	return deg * M_PI / 180;
}

void draw_rect(t_game *g, int x , int y, int color, double scale)
{
	double width = (DM * scale) + y;
	double height = (DM * scale) + x;
	int i = y;
	int j = x;
	while (i < width)
	{
		j = x;
		while (j < height)
		{
			// if ((double)(j % (DM * scale)) == 0 || (double)(i % (DM * scale)) == 0)
			// 	mlx_pixel_put(g->mlx, g->win, j, i, gray);
			// else
				mlx_pixel_put(g->mlx, g->win, j, i, color);
			j++;
		}
		i++;
	}
}

void draw_line(t_game *g, double X0, double Y0, double X1, double Y1, int color)
{
	double dx = X1 - X0;
	double dy = Y1 - Y0;
	double steps = fabs(dx) > fabs(dy) ? fabs(dx) : fabs(dy);
	double Xinc = dx / (double)steps;
	double Yinc = dy / (double)steps;
	double X = X0;
	double Y = Y0;
	for (int i = 0; i <= steps; i++)
	{
		mlx_pixel_put(g->mlx, g->win, X, Y, color);
		X += Xinc;
		Y += Yinc;
	}  
}

void draw_player(t_game *g, double x_pos, double y_pos, double scale)
{
	double width = 18 + y_pos;
	double height = 18 + x_pos;
	double i = y_pos;
	double j = x_pos;
	while (i < width)
	{
		j = x_pos;
		while (j < height)
		{
			mlx_pixel_put(g->mlx, g->win, (j - 9) * scale, (i - 9) * scale, blue);
			j++;
		}
		i++;
	}
}

void	draw_map(t_game *g, double scale)
{
	double pX = g->player->x;
	double pY = g->player->y;
	double pAngle = g->player->dir;
	for (int i = 0; i < MAX_ROWS; i++)
	{
		for (int j = 0; j < MAX_COLS; j++)
		{
			if (map[i][j] == '1')
				draw_rect(g, j * (DM * scale) , i * (DM * scale) , black, scale);
			else if (map[i][j] == ' ')
				draw_rect(g, j * (DM * scale), i * (DM * scale), red, scale);
			else if (map[i][j] == '0' || map[i][j] == 'P')
				draw_rect(g, j * (DM * scale), i * (DM * scale), white, scale);
		}
	}
	draw_player(g, g->player->x, g->player->y, scale);
	draw_line(g, pX * scale, pY * scale, (pX + cos(pAngle) * 40) * scale, (pY + sin(pAngle) * 40) * scale, red);
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

void mlx_draw_cercle(t_game *g)
{
	int x = 10;
	int y = 10;
	int r = 5;
	int i = 0;
	int j = 0;
	while (i < 2 * r)
	{
		j = 0;
		while (j < 2 * r)
		{
			if ((int)sqrt((i - r) * (i - r) + (j - r) * (j - r)) == r)
				mlx_pixel_put(g->mlx, g->win, x + i, y + j, red);
			j++;
		}
		i++;
	}
}

double dis_two_pnts(double x1, double y1, double x2, double y2)
{
	return(sqrtf((x2 - x1) * (x2 - x1) + (y2 - y1) * (y2 - y1)));
}

void render3DProjectedWalls(t_game *game, double wallStripHeight, int X, int color)
{
	if (wallStripHeight > game->height)
		wallStripHeight = game->height;
	for (int i = 0; i <= (game->height - wallStripHeight) / 2; i++)
	{
		mlx_pixel_put(game->mlx, game->win, X, i, bluesky);
	}
	for (int i = 0; i <= wallStripHeight; i++)
	{
		mlx_pixel_put(game->mlx, game->win, X, ((game->height  - wallStripHeight) / 2) + i, color);
	}
	for (int i = 0; i <= (game->height - wallStripHeight) / 2; i++)
	{
		mlx_pixel_put(game->mlx, game->win, X, game->height - i, white);
	}
}

double fixAngle(double angle)
{
	angle = fmod(angle , 2 * M_PI);
	if (angle < 0)
		angle = (2 * M_PI) + angle;
	return angle;
}

void draw_rays(t_game *g)
{
	double pX = g->player->x;
	double pY = g->player->y;
	double distanceProjectionPlane;
	double wallStripHeight;
	double mapDistance;
	double mapWidth = 60 / g->width;
	double rayAngle = g->player->dir - degToRad(30);
	double yIntercept;
	double xIntercept;
	bool isFacingUp;
	bool isFacingDown;
	bool isFacingRight;
	bool isFacingLeft;
	double xStep;
	double yStep;
	int i = 0;
	// rayAngle = fixAngle(rayAngle);
	while(rayAngle < g->player->dir + degToRad(30))
	{
		isFacingDown = fixAngle(rayAngle) > 0 && fixAngle(rayAngle) < M_PI;
		isFacingUp = !isFacingDown;
		isFacingRight = (fixAngle(rayAngle) < 0.5 * M_PI) || (fixAngle(rayAngle) > 1.5 * M_PI);
		isFacingLeft = !isFacingRight;
		
		bool hitHz = false;

		//y-coord to the closest horz grid intersection
		yIntercept = floor(pY / DM) * DM;
		yIntercept += isFacingDown ? DM : 0;
		//x-coord to the closest horz grid intersection
		xIntercept = pX + (yIntercept - pY) / tanf(rayAngle);
		yStep = DM;
		yStep *= isFacingUp ? -1 : 1;
		xStep = DM / tanf(rayAngle);
		xStep *= (isFacingLeft && xStep > 0) ? -1 : 1;
		xStep *= (isFacingRight && xStep < 0) ? -1 : 1;
		double xH = xIntercept;
		double yH = yIntercept;
		if (isFacingUp)
			yH--;
		while (xH >= 0 && xH < g->width && yH >= 0 && yH < g->height )
		{
			if (map[(int)(yH / DM)][(int)(xH / DM)] == '1')
			{
				hitHz = true;
				break;
			}
			else {
				xH += xStep;
				yH += yStep;
			}
		}
		//VERTICAL
		bool hitVc = false;
		xIntercept = floor(pX / DM) * DM;
		xIntercept += isFacingRight ? DM : 0;
		//x-coord to the closest horz grid intersection
		yIntercept = pY + (xIntercept - pX) * tanf(rayAngle);
		xStep = DM;
		xStep *= isFacingLeft ? -1 : 1;
		
		yStep = DM * tanf(rayAngle);
		yStep *= (isFacingUp && yStep > 0) ? -1 : 1;
		yStep *= (isFacingDown && yStep < 0) ? -1 : 1;
		distanceProjectionPlane = (g->width / 2) / tanf(degToRad(30));
		double xV = xIntercept;
		double yV = yIntercept;
		if (isFacingLeft)
			xV--;
		while (xV >= 0 && xV < g->width && yV >= 0 && yV < g->height )
		{
			if (map[(int)(yV / DM)][(int)(xV / DM)] == '1')
			{
				hitVc = true;
				break;
			}
			else {
				xV += xStep;
				yV += yStep;
			}
		}
		if (hitHz && hitVc)
		{
			double hHitDis = dis_two_pnts(pX, pY, xH, yH);
			double vHitDis = dis_two_pnts(pX, pY, xV, yV);

			if (hHitDis < vHitDis)
			{
				// Draw a horizontal wall
				wallStripHeight = (DM / hHitDis) * distanceProjectionPlane / cos(g->player->dir - rayAngle);
				render3DProjectedWalls(g, wallStripHeight, i, gray);
				// draw_line(g, pX, pY, xH, yH, blue);
			}
			else
			{
				// Draw a vertical wall
				wallStripHeight = (DM / vHitDis) * distanceProjectionPlane / cos(g->player->dir - rayAngle);
				render3DProjectedWalls(g, wallStripHeight, i, green);
				// draw_line(g, pX, pY, xV, yV, bluesky);
			}
			// printf("rayAngle => [%f][%f]\n", rayAngle, rayAngle + degToRad(mapWidth));
		}
		else if (hitHz)
		{
			// Draw a horizontal wall
			wallStripHeight = (DM / dis_two_pnts(pX, pY, xH, yH)) * distanceProjectionPlane / cos(g->player->dir - rayAngle);
			render3DProjectedWalls(g, wallStripHeight, i, gray);
			// draw_line(g, pX, pY, xH, yH, green);
		}
		else if (hitVc)
		{
			// Draw a vertical wall
			wallStripHeight = (DM / dis_two_pnts(pX, pY, xV, yV)) * distanceProjectionPlane / cos(g->player->dir - rayAngle);
			render3DProjectedWalls(g, wallStripHeight, i, green);
			// draw_line(g, pX, pY, xV, yV, red);
		}
		rayAngle += degToRad(mapWidth);
		i++;
	}
	printf("I => [%d]\n", i);
}

int mainDraws(t_game *game)
{
	mlx_clear_window(game->mlx, game->win);
	draw_rays(game);
	draw_map(game, 0.2);
	return (0);
}

int	key_press(int keycode, t_game *game)
{
	double pX;
	double pY;
	double mapX = 0;
	double mapY = 0;
	if (keycode == KEY_ESC)
		exit_game(game);
	if (keycode == KEY_UP)
	{
		pX = game->player->x + 4 * cos(game->player->dir);
		pY = game->player->y + 4 * sin(game->player->dir);
		if(map[(int)(pY / DM)][(int)(pX/ DM)] == '1')
			return (0);
		game->player->x = pX;
		game->player->y = pY;
	}
	else if (keycode == KEY_DOWN)
	{
		pX = game->player->x - 4 * cos(game->player->dir);
		pY = game->player->y - 4 * sin(game->player->dir);
		if(map[(int)(pY / DM)][(int)(pX/ DM)] == '1')
			return (0);
		game->player->x = pX;
		game->player->y = pY;
	}
	else if (keycode == KEY_LEFT)
	{
		game->player->dir -= degToRad(2.5);
		pX = game->player->x;
		pY = game->player->y;
	}
	else if (keycode == KEY_RIGHT){
		game->player->dir += degToRad(2.5);
		pX = game->player->x;
		pY = game->player->y;
	}
	// mlx_clear_window(game->mlx, game->win);
	// draw_map(game, 0.2);
	// draw_player(game, pX, pY);
	// draw_rays(game);
	mainDraws(game);
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
	g->height = MAX_ROWS * DM;
	g->width = MAX_COLS * DM;
	g->win = mlx_new_window(g->mlx, g->width, g->height, "./cub3D");

	p->x = (get_player_position() % MAX_COLS) * DM + DM / 2;
	p->y = (get_player_position() / MAX_COLS) * DM + DM / 2;
	p->dir = -M_PI_2;
	g->player = p;

	mainDraws(g);
	// mlx_hook(g->win, X_EVENT_KEY_PRESS, 0, &key_press, g);
	mlx_key_hook(g->win, &key_press, g);
	// mlx_loop_hook(g->mlx, &mainDraws, g);
	mlx_hook(g->win, X_EVENT_KEY_EXIT, 0, &escape_game, g);
	mlx_loop(g->mlx);
    return 0;
}
