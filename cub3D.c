/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoumni <tmoumni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 13:43:18 by tmoumni           #+#    #+#             */
/*   Updated: 2023/10/21 18:21:10 by tmoumni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"


void leaks(void)
{
	system("leaks cub3D");
}



int	main(int ac, char **av)
{
	int length;
	length = 0;
	char **map = malloc(sizeof(char*) * 22);
	if (ac == 2)
	{
		int fd = open(av[1], O_RDONLY);
		if (fd == -1)
		{
			puts("Error\n");
			return (0);
		}
		char *line;
		line = get_next_line(fd);
		while (line)
		{
			printf("%d => %s",ft_strlen(line), line);
			map[length] = ft_strdup(line);
			free(line);
			line = get_next_line(fd);
			length++;
		}
		printf("\nlength = %d\n", length);
		printf("\nmap = %s\n", map[length - 1]);
	}
	// atexit(leaks);
	return (0);
}
