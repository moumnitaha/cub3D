/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_ceil_floor.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoumni <tmoumni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 12:16:06 by tmoumni           #+#    #+#             */
/*   Updated: 2023/11/01 12:31:18 by tmoumni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	img_pix_put(t_img *img, int x, int y, int color)
{
	char	*pixel;
	int		i;

	i = img->bpp - 8;
	pixel = img->addr + (y * img->line_len + x * (img->bpp / 8));
	while (i >= 0)
	{
		if (img->endian != 0)
			*pixel++ = (color >> i) & 0xFF;
		else
			*pixel++ = (color >> (img->bpp - 8 - i)) & 0xFF;
		i -= 8;
	}
}

int	make_img(t_game *g, int x, int y, int color)
{
	int		i;
	int		j;
	double	width;
	double	height;
	t_img	*img;

	img = &g->img;
	width = g->width;
	height = g->height / 2;
	i = y;
	while (i < y + height)
	{
		j = x;
		while (j < x + width)
			img_pix_put(img, j++, i, color);
		++i;
	}
	return (0);
}

int	render(t_game *g)
{
	if (g->win == NULL)
		return (1);
	make_img(g, 0, 0, BLUESKY);
	mlx_put_image_to_window(g->mlx, g->win, g->img.mlx_img, 0, 0);
	make_img(g, 0, g->height / 2, WHITE);
	mlx_put_image_to_window(g->mlx, g->win, g->img.mlx_img, 0, 0);
	return (0);
}
