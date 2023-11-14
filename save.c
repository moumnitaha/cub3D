

// void renderWal(t_game *g, double wall_height, t_ray *ray, int dir)
// {
// 	double offset_x;
// 	int j;
// 	int color;
// 	double offset_y;
// 	int ot_x;
// 	int h;

// 	j = 0;
// 	ot_x = 0;
// 	offset_x = 0;
// 	offset_y = 0;
// 	wall_height = floor(wall_height);
// 	h = (g->height - wall_height) / 2;
// 	offset_x = off_x(ray);
// 	while (j < h)
// 	{
// 		img_pix_put(g, ray->index, j, g->ceilling_c);
// 		j++;
// 	}
// 	j = 0;
// 	while(j < wall_height)
// 	{
// 		if (dir == 1)
// 		{
// 			offset_y = j * (g->no_h / wall_height);
// 			ot_x = offset_x * (g->no_w / DM);

// 			if(ot_x + offset_y * g->no_w < g->no_w * g->no_h && ot_x + offset_y * g->no_w > 0 
// 				&& j + h < g->height && j + h > 0)
// 			{
// 				color = g->north.addr[((int)offset_y * g->no_w) + (int)ot_x];
// 				img_pix_put(g, ray->index, j + h, color);
// 			}
// 		}
// 		else if (dir == 2)
// 		{	
// 			offset_y = j * (g->so_h / wall_height);
// 			ot_x = offset_x * (g->so_w / DM);

// 			if(ot_x + offset_y * g->so_w < g->so_w * g->so_h && ot_x + offset_y * g->so_w > 0 
// 				&& j + h < g->height && j + h > 0)
// 			{
// 				color = g->south.addr[((int)offset_y * g->so_w) + (int)ot_x];
// 				img_pix_put(g, ray->index, j + h, color);
// 			}
// 		}
// 		j++;
// 	}
// 	j = 0;
// 	while(j < wall_height)
// 	{
// 		if (dir == 3)
// 		{	
// 			offset_y = j * (g->we_h / wall_height);
// 			ot_x = offset_x * (g->we_w / DM);

// 			if(ot_x + offset_y * g->we_w < g->we_w * g->we_h && ot_x + offset_y * g->we_w > 0 
// 				&& j + h < g->height && j + h > 0)
// 			{
// 				color = g->west.addr[((int)offset_y * g->we_w) + (int)ot_x];
// 				img_pix_put(g, ray->index, j + h, color);
// 			}
// 		}
// 		else if (dir == 4)
// 		{	
// 			offset_y = j * (g->ea_h / wall_height);
// 			ot_x = offset_x * (g->ea_w / DM);

// 			if(ot_x + offset_y * g->ea_w < g->ea_w * g->ea_h && ot_x + offset_y * g->ea_w > 0 
// 				&& j + h < g->height && j + h > 0)
// 			{
// 				color = g->east.addr[((int)offset_y * g->ea_w) + (int)ot_x];
// 				img_pix_put(g, ray->index, j + h, color);
// 			}
// 		}
// 		j++;
// 	}
// 	while (j + h < g->height)
// 	{
// 		img_pix_put(g, ray->index, j + h, g->floor_c);
// 		j++;
// 	}
// }