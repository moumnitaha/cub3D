/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhaliss <akhaliss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 09:39:27 by akhaliss          #+#    #+#             */
/*   Updated: 2023/11/22 10:03:42 by akhaliss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int	_colors(char *line, int *rgb)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	i = extract_rgb(line, rgb, &j);
	return (i);
}

int	get_color(char *line)
{
	int		rgb[3];
	size_t	i;

	rgb[0] = 0;
	rgb[1] = 0;
	rgb[2] = 0;
	i = 0;
	i = _colors(line, rgb);
	if (i == 0 || (i < ft_strlen(line) && ft_isdigit(line[i])))
	{
		_error("Error\nInvalid Color\n");
	}
	free(line);
	return ((rgb[0] << 16) | (rgb[1] << 8) | rgb[2]);
}

void	set_txt(t_game *game, char c, char *path)
{
	if (c == 'N')
		game->no_txt = _path(path);
	else if (c == 'S')
		game->so_txt = _path(path);
	else if (c == 'W')
		game->we_txt = _path(path);
	else if (c == 'E') 
		game->ea_txt = _path(path);
	else
		_error("Error\nInvalid Texture Key\n");
}

void	m_elem(t_game *game, char c, char *value)
{
	if ((c == 'N' && game->no_txt) || (c == 'S' && game->so_txt)
		|| (c == 'W' && game->we_txt) || (c == 'E' && game->ea_txt)
		|| (c == 'F' && game->floor_c != -1)
		|| (c == 'C' && game->ceilling_c != -1))
		_error("Error\nDuplicate values\n");
	if (c == 'N' || c == 'S' || c == 'W' || c == 'E' )
	{
		set_txt(game, c, value); 
	}
	else if (c == 'F' || c == 'C')
	{
		if (c == 'F')
			game->floor_c = get_color(value);
		else
			game->ceilling_c = get_color(value);
	}
	else
		_error("Error\nInvalid Key\n");
}

int	_line(t_game *game, char *line, int l)
{
	int		start;
	int		end;
	char	c;
	int		i;
	char	*value;

	c = *(line - l);
	i = 0;
	while (line[i] && line[i] == ' ')
		i++;
	start = i;
	while (line[i] && line[i] != '\n')
		i++;
	end = i;
	if (start >= end)
		return (0);
	value = malloc(end - start + 1);
	if (!value)
		return (0);
	ft_strlcpy(value, line + start, end - start + 1);
	m_elem(game, c, value);
	return (1);
}
