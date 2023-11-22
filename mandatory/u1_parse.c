/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   u1_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoumni <tmoumni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 12:55:19 by akhaliss          #+#    #+#             */
/*   Updated: 2023/11/22 15:54:42 by tmoumni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

char	*_path(char *path)
{
	int	fd;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		_error("Error\nWrong File\n");
	close(fd);
	return (path);
}

int	maplen(int fd)
{
	char	*line;
	int		count;

	count = 0;
	line = get_next_line(fd);
	while (line != NULL)
	{
		free(line);
		line = get_next_line(fd);
		count++;
	}
	free(line);
	return (count);
}

int	ft_open(char *file, int perm, t_game *game)
{
	int	fd;
	int	fd_len;

	(void)game;
	fd = open(file, perm);
	if (fd < 0)
	{
		_error("Error\nCan't open File\n");
	}
	fd_len = maplen(fd);
	if (!fd_len)
	{
		close(fd);
		_error("Error\nEmpty File\n");
	}
	close(fd);
	fd = open(file, perm);
	return (fd);
}
