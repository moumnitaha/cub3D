/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_textures.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoumni <tmoumni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 13:03:25 by akhaliss          #+#    #+#             */
/*   Updated: 2023/11/22 13:54:40 by tmoumni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	img_pix_put(t_game *g, int x, int y, int color)
{
	g->img->addr[y * (int)g->width + x] = color;
}

void	xpms_(t_game *g)
{
	g->north.mlx_img = mlx_xpm_file_to_image(g->mlx,
			g->no_txt, &g->no_w, &g->no_h);
	if (!g->north.mlx_img)
		_error("Error\nxpm protected");
	g->north.addr = (int *)mlx_get_data_addr(g->north.mlx_img, &g->img->bits_pp,
			&g->img->ll, &g->img->en);
	if (!g->north.addr)
		_error("Error\nxpm protected");
	g->south.mlx_img = mlx_xpm_file_to_image(g->mlx, g->so_txt,
			&g->so_w, &g->so_h);
	if (!g->south.mlx_img)
		_error("Error\nxpm protected");
	g->south.addr = (int *)mlx_get_data_addr(g->south.mlx_img, &g->img->bits_pp,
			&g->img->ll, &g->img->en);
	if (!g->south.addr)
		_error("Error\nxpm protected");
}

void	xpm_files(t_game *g)
{
	mlx_destroy_image(g->mlx, g->img->mlx_img);
	mlx_clear_window(g->mlx, g->win);
	g->img->mlx_img = mlx_new_image(g->mlx, g->width, g->height);
	g->img->addr = (int *)mlx_get_data_addr(g->img->mlx_img,
			&g->img->bpp, &g->img->line_len, &g->img->endian);
	xpms_(g);
	g->east.mlx_img = mlx_xpm_file_to_image(g->mlx, g->ea_txt,
			&g->ea_w, &g->ea_h);
	if (!g->east.mlx_img)
		_error("Error\nxpm protected");
	g->east.addr = (int *)mlx_get_data_addr(g->east.mlx_img, &g->img->bits_pp,
			&g->img->ll, &g->img->en);
	if (!g->east.addr)
		_error("Error\nxpm protected");
	g->west.mlx_img = mlx_xpm_file_to_image(g->mlx, g->we_txt,
			&g->we_w, &g->we_h);
	if (!g->west.mlx_img)
		_error("Error\nxpm protected");
	g->west.addr = (int *)mlx_get_data_addr(g->west.mlx_img, &g->img->bits_pp,
			&g->img->ll, &g->img->en);
	if (!g->west.addr)
		_error("Error\nxpm protected");
}

double	off_x(t_ray *ray)
{
	double	offset_x;

	offset_x = 0;
	if (ray->is_vc_hit && ray->is_ray_flf)
		offset_x = DM - fmod(ray->y_v_hit, DM);
	else if (ray->is_vc_hit && ray->is_ray_frt)
		offset_x = fmod(ray->y_v_hit, DM);
	else if (ray->is_hz_hit && ray->is_ray_fdw)
		offset_x = DM - fmod(ray->x_h_hit, DM);
	else if (ray->is_hz_hit && ray->is_ray_fup)
		offset_x = fmod(ray->x_h_hit, DM);
	return (offset_x);
}
