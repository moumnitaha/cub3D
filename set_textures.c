/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_textures.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhaliss <akhaliss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 13:03:25 by akhaliss          #+#    #+#             */
/*   Updated: 2023/11/13 12:47:04 by akhaliss         ###   ########.fr       */
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

	    if (ray->is_hz_hit  && ray->is_ray_fup)
            dir = 1;
        else if (ray->is_vc_hit && ray->is_ray_frt)
            dir = 4;
    	else if (ray->is_vc_hit && ray->is_ray_flf)
            dir = 3;
	    else if (ray->is_hz_hit && ray->is_ray_fdw)
            dir = 2;
    return (dir);

}

// int n_color(t_game *g, int x, int y, int j)
// {
//     int color;
//     // (void)j;
    
//     color = 0;
//     if(x + y * g->no_w < g->no_w * g->no_h && x + y * g->no_w > 0 
//     	&& j < g->height && j > 0)
//     {
//         color = g->north.addr[y * g->no_w + x];
//     }
//     return (color);
// }
// void wall_tex(t_game *g, double wall_height, t_ray *ray, int dir)
// {
//     int j;
// 	int color;
// 	double offset_y;
// 	int ot_x;
// 	int h;

//     j = 0;
// 	ot_x = 0;
// 	// offset_x = 0;
// 	offset_y = 0;
// 	wall_height = floor(wall_height);
// 	h = (g->height - wall_height) / 2;
//     j = 0;
// 	while(j < wall_height)
// 	{
// 		if (dir == 1)
// 		{
// 			offset_y = j * (g->no_h / wall_height);
// 			ot_x = off_x(ray) * (g->no_w / DM);

// 			if(ot_x + offset_y * g->no_w < g->no_w * g->no_h && ot_x + offset_y * g->no_w > 0 
// 				&& j + h < g->height && j + h > 0)
// 			{
// 				color = g->north.addr[((int)offset_y * g->no_w) + (int)ot_x];
// 				// color = n_color(g, ot_x, offset_y, j + h);
// 				img_pix_put(g, ray->index, j + h, color);
// 			}
// 		}
// 		else if (dir == 2)
// 		{	
// 			offset_y = j * (g->so_h / wall_height);
// 			ot_x = off_x(ray) * (g->so_w / DM);

// 			if(ot_x + offset_y * g->so_w < g->so_w * g->so_h && ot_x + offset_y * g->so_w > 0 
// 				&& j + h < g->height && j + h > 0)
// 			{
// 				color = g->south.addr[((int)offset_y * g->so_w) + (int)ot_x];
// 				// color = n_color(g, off_x(ray), offset_y);
// 				img_pix_put(g, ray->index, j + h, color);
// 			}
// 		}
// 		else if (dir == 3)
// 		{	
// 			offset_y = j * (g->we_h / wall_height);
// 			ot_x = off_x(ray) * (g->we_w / DM);

// 			if(ot_x + offset_y * g->we_w < g->we_w * g->we_h && ot_x + offset_y * g->we_w > 0 
// 				&& j + h < g->height && j + h > 0)
// 			{
// 				color = g->west.addr[((int)offset_y * g->we_w) + (int)ot_x];
// 				// color = n_color(g, off_x(ray), offset_y);
// 				img_pix_put(g, ray->index, j + h, color);
// 			}
// 		}
// 		else if (dir == 4)
// 		{	
// 			offset_y = j * (g->ea_h / wall_height);
// 			ot_x = off_x(ray) * (g->ea_w / DM);

// 			if(ot_x + offset_y * g->ea_w < g->ea_w * g->ea_h && ot_x + offset_y * g->ea_w > 0 
// 				&& j + h < g->height && j + h > 0)
// 			{
// 				color = g->east.addr[((int)offset_y * g->ea_w) + (int)ot_x];
// 				// color = n_color(g, off_x(ray), offset_y);
// 				img_pix_put(g, ray->index, j + h, color);
// 			}

// 		}
// 		j++;
// 	}
// }
