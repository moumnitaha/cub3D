/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_textures.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhaliss <akhaliss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/12 13:03:25 by akhaliss          #+#    #+#             */
/*   Updated: 2023/11/12 17:05:38 by akhaliss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void    xpm_files(t_game *g)
{
    // puts(g->so_txt);
    // g->img->mlx_img = mlx_new_image(g->mlx, g->width, g->height);
    // g->img->addr = (int *)mlx_get_data_addr(g->img->mlx_img, &g->img->bpp, &g->img->line_len, &g->img->endian);
    g->south.mlx_img = mlx_xpm_file_to_image(g->mlx, g->so_txt, &g->so_w, &g->so_h);
    g->south.addr = (int *)mlx_get_data_addr(g->south.mlx_img, &g->img->bits_pp,
        &g->img->ll, &g->img->en);
    g->north.mlx_img = mlx_xpm_file_to_image(g->mlx, g->no_txt, &g->no_w, &g->no_h);
    g->north.addr = (int *)mlx_get_data_addr(g->north.mlx_img, &g->img->bits_pp,
        &g->img->ll, &g->img->en);
    g->east.mlx_img = mlx_xpm_file_to_image(g->mlx, g->ea_txt, &g->ea_w, &g->ea_h);
    g->east.addr = (int *)mlx_get_data_addr(g->east.mlx_img, &g->img->bits_pp,
        &g->img->ll, &g->img->en);
    g->west.mlx_img = mlx_xpm_file_to_image(g->mlx, g->we_txt, &g->we_w, &g->we_h);
    g->west.addr = (int *)mlx_get_data_addr(g->west.mlx_img, &g->img->bits_pp,
        &g->img->ll, &g->img->en);
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