/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhaliss <akhaliss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 13:43:22 by tmoumni           #+#    #+#             */
/*   Updated: 2023/10/31 12:57:04 by akhaliss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <stdlib.h>
# include <stdbool.h>
# include "gnl/get_next_line.h"

typedef struct s_player
{
	double	x;
	double	y;
	double	dir;
	double	FOV;
	int		turn_dir;
	int		walk_dir;
	int		rotation_angle;
	int		walk_speed;
	int		turn_speed;
}	t_player;

typedef struct s_ray
{
	double	rayAngle;
	double	xHhit;
	double	yHhit;
	double	xVhit;
	double	yVhit;
	double	hHitDis;
	double	vHitDis;
	double	dToPP;
	bool	isHzHit;
	bool	isVcHit;
	bool	isRayFacingUp;
	bool	isRayFacingDown;
	bool	isRayFacingLeft;
	bool	isRayFacingRight;
}	t_ray;

typedef struct s_game
{
	int			floor_c;
	int			ceilling_c;
	int			mlen;
	double		height;
	double		width;
	char		**map;
	char		*no_txt;
	char		*so_txt;
	char		*we_txt;
	char		*ea_txt;
	void		*mlx;
	void		*win;
	t_player	*player;
}	t_game;
// *** LIBFT FUNCTIONS *** //

char	*ft_strjoin(char const *s1, char const *s2);
char	**ft_split(char const *s, char c);
char	*ft_strdup(const char *s1);
void	ft_putstr_fd(char *s, int fd);
int		ft_atoi(const char *str);
int		ft_isdigit(int c);
char	*ft_substr(char const *s, unsigned int start, size_t len);
int		ft_strcmp(const char *s1, const char *s2);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
size_t	ft_strlen(const char *str);

// *** CUB3D FUNCTIONS *** //

int		cub(char *av);
int		maplen(int fd);
int		p_name(char *s);
int		ft_open(char *file, int perm, t_game *game);
int		get_info(t_game *game, char *line);
int		_line(t_game *game, char *line, int l);
int		get_color(char *line);
int		_colors(char *line, int *rgb);
int		_spaces(char *line);
void	_error(char *err);
void	read_map(char *file, t_game *game);
void	init_map(t_game *game);
void	set_txt(t_game *game, char c, char *path);
char	*_path(char *path);

#endif