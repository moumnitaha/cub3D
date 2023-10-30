/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoumni <tmoumni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/30 11:25:20 by tmoumni           #+#    #+#             */
/*   Updated: 2023/10/30 18:17:24 by tmoumni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

char*	map[] = {
	"111111111111111111111111111111111",
	"10000000000000000011011111110011 ",
	"111101111111110110000000000000001",
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
	wallStripHeight = round(wallStripHeight);
	if (wallStripHeight > game->height)
		wallStripHeight = game->height;
	int i = 0;
	for (i = 0; i < (game->height - wallStripHeight) / 2; i++)
	{
		mlx_pixel_put(game->mlx, game->win, X, i, bluesky);
	}
	for (i = 0; i <= wallStripHeight; i++)
	{
		mlx_pixel_put(game->mlx, game->win, X, ((game->height  - wallStripHeight) / 2) + i, color);
	}
	for (i = 0; i < (game->height - wallStripHeight) / 2; i++)
	{
		mlx_pixel_put(game->mlx, game->win, X, game->height - i, white);
	}
}


void horizontalIntersection(t_game *g, t_ray *ray)
{
	double xStep;
	double yStep;

	ray->yHhit = floor(g->player->y / DM) * DM;
	if (ray->isRayFacingDown)
		ray->yHhit += DM;
	ray->xHhit = g->player->x + (ray->yHhit - g->player->y) / tanf(ray->rayAngle);
	yStep = DM;
	if (ray->isRayFacingUp)
		yStep *= -1;
	xStep = DM / tanf(ray->rayAngle);
	if (ray->isRayFacingLeft && xStep > 0)
		xStep *= -1;
	if (ray->isRayFacingRight && xStep < 0)
		xStep *= -1;
	if (ray->isRayFacingUp)
		ray->yHhit -= (0.1 / g->width);
	while (ray->xHhit >= 0 && ray->xHhit < g->width && ray->yHhit >= 0 && ray->yHhit < g->height)
	{
		if (map[(int)(ray->yHhit / DM)][(int)(ray->xHhit / DM)] == '1')
		{
			ray->isHzHit = true;
			break;
		}
		ray->xHhit += xStep;
		ray->yHhit += yStep;
	}
	ray->hHitDis = dis_two_pnts(g->player->x, g->player->y, ray->xHhit, ray->yHhit);
}

void verticalIntersection(t_game *g, t_ray *ray)
{
	double xStep;
	double yStep;

	ray->xVhit = floor(g->player->x / DM) * DM;
	if (ray->isRayFacingRight)
		ray->xVhit += DM;
	ray->yVhit = g->player->y + (ray->xVhit - g->player->x) * tanf(ray->rayAngle);
	xStep = DM;
	if (ray->isRayFacingLeft)
		xStep *= -1;
	yStep = DM * tanf(ray->rayAngle);
	if (ray->isRayFacingUp && yStep > 0)
		yStep *= -1;
	if (ray->isRayFacingDown && yStep < 0)
		yStep *= -1;
	if (ray->isRayFacingLeft)
		ray->xVhit -= (0.1 / g->width);
	while (ray->xVhit >= 0 && ray->xVhit < g->width && ray->yVhit >= 0 && ray->yVhit < g->height)
	{
		if (map[(int)(ray->yVhit / DM)][(int)(ray->xVhit / DM)] == '1')
		{
			ray->isVcHit = true;
			break;
		}
		ray->xVhit += xStep;
		ray->yVhit += yStep;
	}
	ray->vHitDis = dis_two_pnts(g->player->x, g->player->y, ray->xVhit, ray->yVhit);
}

double fixAngle(double angle)
{
	angle = fmod(angle , 2 * M_PI);
	if (angle < 0)
		angle = (2 * M_PI) + angle;
	return angle;
}

void initDirection(t_ray *ray)
{
	ray->isRayFacingDown = false;
	ray->isRayFacingUp = false;
	ray->isRayFacingLeft = false;
	ray->isRayFacingRight = false;
	if (fixAngle(ray->rayAngle) > 0 && fixAngle(ray->rayAngle) < M_PI)
		ray->isRayFacingDown = true;
	ray->isRayFacingUp = !ray->isRayFacingDown;
	if ((fixAngle(ray->rayAngle) < 0.5 * M_PI) || (fixAngle(ray->rayAngle) > 1.5 * M_PI))
		ray->isRayFacingRight =	true;
	ray->isRayFacingLeft = !ray->isRayFacingRight;
}

void draw_rays(t_game *g)
{
	t_ray *ray;
	double vWallStripHeight;
	double hWallStripHeight;
	double mapWidth = g->player->FOV / g->width;
	int i = 0;

	ray = malloc(sizeof(t_ray));
	ray->rayAngle = g->player->dir - degToRad(g->player->FOV / 2);
	while(ray->rayAngle < g->player->dir + degToRad(g->player->FOV / 2))
	{
		initDirection(ray);
		ray->isHzHit = false;
		horizontalIntersection(g, ray);
		ray->isVcHit = false;
		verticalIntersection(g, ray);
		ray->dToPP = (g->width / 2) / tanf(degToRad(g->player->FOV / 2));
		hWallStripHeight = (DM / ray->hHitDis) * ray->dToPP / cos(g->player->dir - ray->rayAngle);
		vWallStripHeight = (DM / ray->vHitDis) * ray->dToPP / cos(g->player->dir - ray->rayAngle);
		if (ray->isHzHit && ray->isVcHit)
		{
			if (ray->hHitDis < ray->vHitDis + (0.1 / g->width))
				render3DProjectedWalls(g, hWallStripHeight, i, gray);
			else
				render3DProjectedWalls(g, vWallStripHeight, i, green);
		}
		else if (ray->isHzHit)
			render3DProjectedWalls(g, hWallStripHeight, i, gray);
		else if (ray->isVcHit)
			render3DProjectedWalls(g, vWallStripHeight, i, green);
		ray->rayAngle += degToRad(mapWidth);
		i++;
	}
	printf("I => [%d]\n", i);
	free(ray);
}

int mainDraws(t_game *game)
{
	mlx_clear_window(game->mlx, game->win);
	draw_rays(game);
	draw_map(game, 2 / (game->height / DM));
	return (0);
}

int	key_press(int keycode, t_game *game)
{
	double pX;
	double pY;
	if (keycode == KEY_ESC)
		exit_game(game);
	if (keycode == KEY_UP)
	{
		pX = game->player->x + 8 * cos(game->player->dir);
		pY = game->player->y + 8 * sin(game->player->dir);
		if(map[(int)(pY / DM)][(int)(pX/ DM)] == '1')
			return (0);
		if(map[(int)(pY / DM)][(int)(pX/ DM)] == ' ')
			return (0);
		game->player->x = pX;
		game->player->y = pY;
	}
	else if (keycode == KEY_DOWN)
	{
		pX = game->player->x - 8 * cos(game->player->dir);
		pY = game->player->y - 8 * sin(game->player->dir);
		if(map[(int)(pY / DM)][(int)(pX/ DM)] == '1')
			return (0);
		if(map[(int)(pY / DM)][(int)(pX/ DM)] == ' ')
			return (0);
		game->player->x = pX;
		game->player->y = pY;
	}
	else if (keycode == KEY_LEFT)
	{
		game->player->dir -= degToRad(6);
		pX = game->player->x;
		pY = game->player->y;
	}
	else if (keycode == KEY_RIGHT)
	{
		game->player->dir += degToRad(6);
		pX = game->player->x;
		pY = game->player->y;
	}
	else
		return (0);
	mainDraws(game);
	return (0);
}

int	escape_game(t_game *game)
{
	printf("\033[1;31m[[ U gaved up :/ ]]\033[0m\n");
	return (exit_game(game));
}

int mouse_move(int x, int y, t_game *game) {
	if (x > 0 && y > 0 && y < game->height && x < game->width)
	{
		game->player->dir = atan2((y - game->player->y) / 10, (x - game->player->x) / 10);
		printf("Angle => [%f]\n", game->player->dir);
		mainDraws(game);
	}
    return 0;
}

int main()
{
    if (isSurroundedByWalls()) {
        printf("The map is completely surrounded by walls.\n");
    } else {
        printf("XXXX The map is not completely surrounded by walls. XXXX\n");
		return (0);
    }
	t_game		*g;
	t_player	*p;
	t_ray		*ray;

	p = malloc(sizeof(t_player));
	g = malloc(sizeof(t_game));
	ray = malloc(sizeof(t_ray));
	g->mlx = mlx_init();
	g->height = MAX_ROWS * DM;
	g->width = MAX_COLS * DM;
	g->win = mlx_new_window(g->mlx, g->width, g->height, "./cub3D");
	p->x = (get_player_position() % MAX_COLS) * DM + DM / 2;
	p->y = (get_player_position() / MAX_COLS) * DM + DM / 2;
	p->dir = -M_PI_2;
	p->FOV = 60;

	g->player = p;
	mainDraws(g);
	mlx_hook(g->win, X_EVENT_KEY_PRESS, 0, &key_press, g);
	mlx_hook(g->win, 6, 1L << 6, mouse_move, g);
	mlx_hook(g->win, X_EVENT_KEY_EXIT, 0, &escape_game, g);
	mlx_loop(g->mlx);
    return 0;
}
