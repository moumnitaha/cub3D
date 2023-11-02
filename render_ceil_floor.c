/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_ceil_floor.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoumni <tmoumni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/01 12:16:06 by tmoumni           #+#    #+#             */
/*   Updated: 2023/11/02 18:10:03 by tmoumni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

void	img_pix_put(t_game *g, int x, int y, int color)
{
	char	*pixel;
	int		i;

	if (g->img == NULL)
		return ;
	if (x < 0 || x >= g->width || y < 0 || y >= g->height)
		return ;
	i = g->img->bpp - 8;
	pixel = g->img->addr + (y * g->img->line_len + x * (g->img->bpp / 8));
	while (i >= 0)
	{
		if (g->img->endian != 0)
		{
			if (pixel >= g->img->addr && pixel + 1 <= g->img->addr + g->img->line_len * (int)g->height)
				*pixel++ = (color >> i) & 0xFF;
			else
				break ;
		}
		else
		{
			if (pixel >= g->img->addr && pixel + 1 <= g->img->addr + g->img->line_len * (int)g->height)
				*pixel++ = (color >> (g->img->bpp - 8 - i)) & 0xFF;
			else
				break ;
		}
		i -= 8;
	}
}
