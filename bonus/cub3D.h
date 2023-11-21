/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoumni <tmoumni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 13:43:22 by tmoumni           #+#    #+#             */
/*   Updated: 2023/11/21 12:52:06 by tmoumni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include <string.h>
# include <math.h>
# include <mlx.h>
# include "../gnl/get_next_line.h"
# include "math.h"

# define GRAYF 0x00778899
# define RED  0x00FF0000
# define BLUE 0x000000FF
# define WHITE 0x00FFFFFF
# define BLACK 0x00000000
# define GRAY 0x00C0C0C0
# define BLUESKY 0x00199EF3

# define DM				        16
# define X_EVENT_KEY_PRESS		2
# define X_EVENT_KEY_RELEASE	3
# define X_EVENT_KEY_EXIT		17
# define KEY_W					13
# define KEY_A					0
# define KEY_S					1
# define KEY_D					2

# define KEY_ESC				53
# define KEY_LEFT				123
# define KEY_RIGHT				124
# define KEY_DOWN				125
# define KEY_UP					126

typedef struct s_img
{
	void	*mlx_img;
	int		*addr;
	int		bpp;
	int		line_len;
	int		endian;
	int		bits_pp;
	int		ll;
	int		en;

}	t_img;
typedef struct s_player {
	double		x;
	double		y;
	double		m_x;
	double		m_y;
	double		dir;
	double		lf;
	double		fov;
	double		turn_speed;
	double		walk_speed;
	int			turn_dir;
	int			walk_dir;
}	t_player;

typedef struct s_ray {
	double		ray_ang;
	double		x_h_hit;
	double		y_h_hit;
	double		x_v_hit;
	double		y_v_hit;
	double		h_hit_dis;
	double		v_hit_dis;
	double		dist;
	double		d_to_pp;
	bool		is_hz_hit;
	bool		is_vc_hit;
	bool		is_ray_fup;
	bool		is_ray_fdw;
	bool		is_ray_flf;
	bool		is_ray_frt;
	int			index;
}	t_ray;

typedef struct s_game
{
	int			floor_c;
	int			ceilling_c;
	int			m_h;
	int			m_w;
	int			no_w;
	int			ea_w;
	int			we_w;
	int			so_w;
	int			no_h;
	int			ea_h;
	int			we_h;
	int			so_h;
	double		height;
	double		width;
	double		scale;
	double		mini_map_w;
	double		mini_map_h;
	char		**map;
	char		*no_txt;
	char		*so_txt;
	char		*we_txt;
	char		*ea_txt;
	void		*mlx;
	void		*win;
	t_img		north;
	t_img		south;
	t_img		east;
	t_img		west;
	t_img		*img;
	t_img		*mini_map;
	t_player	*player;
}	t_game;

void			init_ray_direction(t_ray *ray);
void			horizontal_intersection(t_game *g, t_ray *ray);
void			vertical_intersection(t_game *g, t_ray *ray);
void			render_rays(t_game *g);
bool			check_firs_last(t_game *game);
bool			check_columns(t_game *game);
bool			check_around_spaces(t_game *game);
bool			is_surrounded_by_walls(t_game *game);
int				get_player_position(t_game *game);
int				mouse_move(int x, int y, t_game *game);
void			draw_line(t_game *g, double x_1, double y_1);
void			draw_player(t_game *g, double x_pos, double y_pos);
void			draw_map(t_game *g);
int				main_draws(t_game *game);
double			fix_ang(double angle);
double			deg_to_rad(double deg);
double			d_t_pnts(double x1, double y1, double x2, double y2);
void			init_ray_direction(t_ray *ray);
void			init_player(t_game *game);
void			init_game(t_game *g, t_player*player, t_img *img);
int				key_press(int keycode, t_game *game);
int				key_release(int keycode, t_game *game);
int				exit_game(t_game *game);
int				escape_game(t_game *game);
void			img_pix_put(t_game *g, int x, int y, int color);
void			update_player(t_game *game);
void			mimg_pix_put(t_game *g, int x, int y, int color);

// *** LIBFT FUNCTIONS *** //

char			*ft_strjoin(char const *s1, char const *s2);
char			**ft_split(char const *s, char c);
char			*ft_strdup(const char *s1);
void			ft_putstr_fd(char *s, int fd);
int				ft_atoi(const char *str);
int				ft_isdigit(int c);
char			*ft_substr(char const *s, unsigned int start, size_t len);
int				ft_strcmp(const char *s1, const char *s2);
size_t			ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t			ft_strlen(const char *str);

// *** CUB3D FUNCTIONS *** //

int				cub(char *av, t_game *game);
int				maplen(int fd);
int				p_name(char *s);
int				ft_open(char *file, int perm, t_game *game);
int				get_info(t_game *game, char *line);
void			validate_rgb(int value);
int				extract_rgb(char *line, int *rgb, int *j);
int				_line(t_game *game, char *line, int l);
int				get_color(char *line);
int				_colors(char *line, int *rgb);
int				_spaces(char *line);
void			_error(char *err);
void			read_map(char *file, t_game *game);
void			init_map(t_game *game);
void			set_txt(t_game *game, char c, char *path);
char			*_path(char *path);
unsigned int	get_txt_color(t_game *g, int x, int y);
void			xpm_files(t_game *g);
double			off_x(t_ray *ray);
void			wall_tex(t_game *g, double wall_height, t_ray *ray, int dir);
void			render_wall(t_game *g, t_ray *ray, double wall_height);
void			r_floor(t_game *g, int wall_height, int rayIndex);
void			r_ceiling(t_game *g, int wall_height, int rayIndex);
void			free_mem(t_game *game);
#endif