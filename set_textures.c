/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_textures.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhaliss <akhaliss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 13:03:25 by akhaliss          #+#    #+#             */
/*   Updated: 2023/11/15 10:03:25 by akhaliss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	img_pix_put(t_game *g, int x, int y, int color)
{
	g->img->addr[y * (int)g->width + x] = color;
}

void	xpm_files(t_game *g)
{
	g->img->mlx_img = mlx_new_image(g->mlx, g->width, g->height);
	g->img->addr = (int *)mlx_get_data_addr(g->img->mlx_img,
			&g->img->bpp, &g->img->line_len, &g->img->endian);
	g->north.mlx_img = mlx_xpm_file_to_image(g->mlx,
			g->no_txt, &g->no_w, &g->no_h);
	g->north.addr = (int *)mlx_get_data_addr(g->north.mlx_img, &g->img->bits_pp,
			&g->img->ll, &g->img->en);
	g->south.mlx_img = mlx_xpm_file_to_image(g->mlx, g->so_txt,
			&g->so_w, &g->so_h);
	g->south.addr = (int *)mlx_get_data_addr(g->south.mlx_img, &g->img->bits_pp,
			&g->img->ll, &g->img->en);
	g->east.mlx_img = mlx_xpm_file_to_image(g->mlx, g->ea_txt,
			&g->ea_w, &g->ea_h);
	g->east.addr = (int *)mlx_get_data_addr(g->east.mlx_img, &g->img->bits_pp,
			&g->img->ll, &g->img->en);
	g->west.mlx_img = mlx_xpm_file_to_image(g->mlx, g->we_txt,
			&g->we_w, &g->we_h);
	g->west.addr = (int *)mlx_get_data_addr(g->west.mlx_img, &g->img->bits_pp,
			&g->img->ll, &g->img->en);
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