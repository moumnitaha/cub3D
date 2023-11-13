/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_textures.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhaliss <akhaliss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 13:03:25 by akhaliss          #+#    #+#             */
/*   Updated: 2023/11/13 11:30:26 by akhaliss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void    xpm_files(t_game *g)
{
    // g->img->mlx_img = mlx_new_image(g->mlx, g->width, g->height);
    // g->img->addr = (int *)mlx_get_data_addr(g->img->mlx_img, &g->img->bpp, &g->img->line_len, &g->img->endian);
    g->north.mlx_img = mlx_xpm_file_to_image(g->mlx, g->no_txt, &g->no_w, &g->no_h);
    g->north.addr = (int *)mlx_get_data_addr(g->north.mlx_img, &g->img->bits_pp,
        &g->img->ll, &g->img->en);
    g->south.mlx_img = mlx_xpm_file_to_image(g->mlx, g->so_txt, &g->so_w, &g->so_h);
    g->south.addr = (int *)mlx_get_data_addr(g->south.mlx_img, &g->img->bits_pp,
        &g->img->ll, &g->img->en);
    g->east.mlx_img = mlx_xpm_file_to_image(g->mlx, g->ea_txt, &g->ea_w, &g->ea_h);
    g->east.addr = (int *)mlx_get_data_addr(g->east.mlx_img, &g->img->bits_pp,
        &g->img->ll, &g->img->en);
    g->west.mlx_img = mlx_xpm_file_to_image(g->mlx, g->we_txt, &g->we_w, &g->we_h);
    g->west.addr = (int *)mlx_get_data_addr(g->west.mlx_img, &g->img->bits_pp,
        &g->img->ll, &g->img->en);
}

double  off_x(t_ray *ray)
{
    double offset_x;

	offset_x = 0;
    if (ray->is_vc_hit && ray->is_ray_flf)
		offset_x = DM - fmod(ray->y_v_hit , DM);
	else if (ray->is_vc_hit && ray->is_ray_frt)
		offset_x = fmod(ray->y_v_hit , DM);
	else if (ray->is_hz_hit && ray->is_ray_fdw)
		offset_x = DM - fmod(ray->x_h_hit , DM);
	else if (ray->is_hz_hit && ray->is_ray_fup)
		offset_x = fmod(ray->x_h_hit , DM);
    return (offset_x);
}

int _dir(t_ray *ray)
{
    int dir;
    
    dir = 0;
    // if (ray->ray_ang >= 0 && ray->ray_ang <= 180)
    // {
    //     if (ray->is_vc_hit)
    //         dir = 4;
    //     else if (ray->is_hz_hit)
    //         dir = 2;
    // }
    // if (ray->ray_ang >= 180 && ray->ray_ang <= 360)
    // {
	    if (ray->is_hz_hit  && ray->is_ray_fup)
            dir = 1;
        else if (ray->is_vc_hit && ray->is_ray_frt)
            dir = 4;
    	else if (ray->is_vc_hit && ray->is_ray_flf)
            dir = 3;
    // }
    // else if (ray->ray_ang >= 0 && ray->ray_ang <= 180)
    // {
	    else if (ray->is_hz_hit && ray->is_ray_fdw)
            dir = 2;
    //     else if (ray->is_vc_hit && ray->is_ray_flf)
    //         dir = 3;
    // 	else if (ray->is_vc_hit && ray->is_ray_frt)
    //         dir = 4;
    // }
    // else if ((ray->ray_ang >= 0 && ray->ray_ang <= 90) || (ray->ray_ang >= 270 && ray->ray_ang <= 360))
    // {
    //     dir = 4;
    // }
    // else if (ray->ray_ang >= 900 && ray->ray_ang <= 270)
    // {
    //     dir = 3;
    // }
    // if (ray->ray_ang >= 180 && ray->ray_ang <= 360)
    // {
    //     if (ray->is_vc_hit)
    //         dir = 1;
    //     else if (ray->is_hz_hit)
    //         dir = 4;
    // }
    return (dir);

}

// int n_color(t_game *game, int x, int y)
// {
    
//     int offset = (y * game->ea_w + x);
//     // printf("%d\n", game->ea_w);
//     int color = game->north.addr[offset];
//     // unsigned int color = game->north.addr[offset];
//     // unsigned int color = game->west.addr[offset];
//     // unsigned int color = game->south.addr[offset];

//     return (color);
// }