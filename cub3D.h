/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoumni <tmoumni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 13:43:22 by tmoumni           #+#    #+#             */
/*   Updated: 2023/10/31 12:47:40 by tmoumni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdbool.h>
# include <stdio.h>
# include <string.h>
# include <math.h>
# include <mlx.h>
# include "gnl/get_next_line.h"
# include "math.h"
# include "map.h"

# define MAX_ROWS 10
# define MAX_COLS 33
# define GREEN 0x00008000
# define RED  0x00FF0000
# define BLUE 0x000000FF
# define WHITE 0x00FFFFFF
# define BLACK 0x00000000
# define GRAY 0x00C0C0C0
# define BLUESKY 0x00199EF3

# define DM				        32
# define X_EVENT_KEY_PRESS		2
# define X_EVENT_KEY_RELEASE	3
# define X_EVENT_KEY_EXIT		17
// # define KEY_W					13
// # define KEY_A					0
// # define KEY_S					1
// # define KEY_D					2

# define KEY_ESC				53
# define KEY_LEFT				123
# define KEY_RIGHT				124
# define KEY_DOWN				125
# define KEY_UP					126

// # define KEY_ESC				65307
// # define KEY_LEFT				65361
// # define KEY_RIGHT				65363
// # define KEY_DOWN				65364
// # define KEY_UP					65362

typedef struct s_player {
	double		x;
	double		y;
	double		dir;
	double		fov;
	int			turn_dir;
	int			walk_dir;
	int			rotation_angle;
	int			walk_speed;
	int			turn_speed;
}	t_player;

typedef struct s_ray {
	double		ray_ang;
	double		x_h_hit;
	double		y_h_hit;
	double		x_v_hit;
	double		y_v_hit;
	double		h_hit_dis;
	double		v_hit_dis;
	double		d_to_pp;
	bool		is_hz_hit;
	bool		is_vc_hit;
	bool		is_ray_fup;
	bool		is_ray_fdw;
	bool		is_ray_flf;
	bool		is_ray_frt;
	int			index;
}	t_ray;

typedef struct s_game {
	double		height;
	double		width;
	char		**map;
	void		*mlx;
	void		*win;
	double		scale;
	t_player	*player;
}	t_game;

void		init_ray_direction(t_ray *ray);
void		horizontal_intersection(t_game *g, t_ray *ray);
void		vertical_intersection(t_game *g, t_ray *ray);
void		draw_rays(t_game *g);
void		render_3d_walls(t_game *g, double wall_height, int i, int color);
bool		check_firs_last(void);
bool		check_columns(void);
bool		check_around_spaces(void);
bool		is_surrounded_by_walls(void);
int			get_player_position(void);
int			mouse_move(int x, int y, t_game *game);
void		draw_rect(t_game *g, int x, int y, int color);
void		draw_line(t_game *g, double x_1, double y_1);
void		draw_player(t_game *g, double x_pos, double y_pos, double scale);
void		draw_map(t_game *g, double scale);
int			main_draws(t_game *game);
double		fix_ang(double angle);
double		deg_to_rad(double deg);
double		d_t_pnts(double x1, double y1, double x2, double y2);
void		init_ray_direction(t_ray *ray);
int			key_press(int keycode, t_game *game);
int			exit_game(t_game *game);
int			escape_game(t_game *game);
#endif