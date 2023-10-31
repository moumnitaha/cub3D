/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   u1_parse.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhaliss <akhaliss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/31 12:55:19 by akhaliss          #+#    #+#             */
/*   Updated: 2023/10/31 12:56:42 by akhaliss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"

char	*_path(char *path)
{
	int	fd;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		_error("Wrong File\n");
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