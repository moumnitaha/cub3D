/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoumni <tmoumni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 13:43:22 by tmoumni           #+#    #+#             */
/*   Updated: 2023/10/25 17:45:11 by tmoumni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include "gnl/get_next_line.h"
# include "mlx.h"

# define DM				        32
# define X_EVENT_KEY_PRESS		2
# define X_EVENT_KEY_RELEASE	3
# define X_EVENT_KEY_EXIT		17
# define KEY_ESC				53
# define KEY_W					13
# define KEY_A					0
# define KEY_S					1
# define KEY_D					2
# define KEY_UP					126
# define KEY_DOWN				125
# define KEY_LEFT				123
# define KEY_RIGHT				124

typedef struct s_player {
	int		x;
	int		y;
	double		dir;
	int		turn_dir;
	int		walk_dir;
	int		rotation_angle;
	int		walk_speed;
	int		turn_speed;
}	t_player;

typedef struct s_game {
	int		height;
	int		clctbls;
	int		width;
	int		mvmnts;
	int		clcted;
	int		pos_x;
	int		pos_y;
	int		clct_x;
	int		clct_y;
	char	**map;
	void	*mlx;
	void	*win;
	char	*wall;
	char	*clct;
	char	*exit;
	char	*open;
	char	*crc_l;
	char	*crc_r;
	char	*land;
	t_player	*player;
}	t_game;

#endif