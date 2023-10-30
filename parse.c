/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhaliss <akhaliss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 09:39:27 by akhaliss          #+#    #+#             */
/*   Updated: 2023/10/30 18:39:22 by akhaliss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

int _colors(char *line, int *rgb)
{
    int i;
    int j;
    int start;

    j = 0;
    i = 0;
    while (line[i])
    {
        while (line[i] && !ft_isdigit(line[i]))
        {
            if (line[i] == ',')
            {
                j++;
                if (j > 2)
                    _error("Error: Invalid Color 2\n");
            }
            else if (line[i] != ' ' && line[i] != '\n')
            {
                _error("Error: Invalid Color 2\n");
            }
            i++;
        }
        start = i;
        while (line[i] && ft_isdigit(line[i]))
            i++;
        rgb[j] = ft_atoi(line + start);
        if ((i - start > 3) || rgb[j] < 0 || rgb[j] > 255)
            _error("Error: Invalid Color 1\n");
    }
    return (i);
}


int get_color(char *line)
{
    int rgb[3];
    size_t i;

    rgb[0] = 0;
    rgb[1] = 0;
    rgb[2] = 0;
    i = 0;
    i = _colors(line, rgb);
    if (i == 0 || (i < ft_strlen(line) && ft_isdigit(line[i])))
    {
        _error("Error: Invalid Color 3\n");
    }
    return ((rgb[0] << 16) | (rgb[1] << 8) | rgb[2]);
}

char    *_path(char *path)
{
    int fd;

    fd = open(path, O_RDONLY);
    if (fd < 0)
        _error("Wrong File\n");
    close(fd);
    return (path);
}

void set_txt(t_game *game, char c, char *path)
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
        _error("Error: Invalid Texture Key\n");
}

int _line(t_game *game, char *line, int l)
{
    int start;
    int end;
    char c;
    int i;
    char *value;

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
    if ((c == 'N' && game->no_txt) || (c == 'S' && game->so_txt)
        || (c == 'W' && game->we_txt) || (c == 'E' && game->ea_txt)
        || (c == 'F' && game->floor_c != -1)
        || (c == 'C' && game->ceilling_c != -1))
    {
        _error("Error: Duplicate values\n");
    }
    if (c == 'N' || c == 'S' || c == 'W' || c == 'E' || c == 'F' || c == 'C')
    {
        if (c == 'N' || c == 'S' || c == 'W' || c == 'E' )
        {
            printf("texture : %c%c %s\n", c, *(line - l + 1), value);
            set_txt(game, c, value);
        } 
        else if (c == 'F' || c == 'C')
        {
            printf("texture : %c%c %s\n", c, *(line - l + 1), value);
            if (c == 'F')
                game->floor_c = get_color(value);
            else
                game->ceilling_c = get_color(value);
        }
    }
    else
    {
        _error("Error: Invalid Key\n");
    }
    free(value);
    return (1);
}