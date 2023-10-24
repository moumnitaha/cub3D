/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhaliss <akhaliss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 13:43:18 by tmoumni           #+#    #+#             */
/*   Updated: 2023/10/24 12:12:05 by akhaliss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3D.h"


// void leaks(void)
// {
// 	system("leaks cub3D");
// }



int parse(char *s)
{
	int	i;

	i = strlen(s);
	if(s[i - 1] == 'b' && s[i - 2] == 'u'
		&& s[i - 3] == 'c' && s[i - 4] == '.')
		return (1);
	return (0);
}


int main(int ac, char **av)
{
	if (ac != 2)
		write(2, "invalid path\n", 13);
	else
	{
		if(parse(av[1]))
			printf("done\n");
		
	}
}

// int	main(int ac, char **av)
// {
// 	int length;
// 	length = 0;
// 	char **map = malloc(sizeof(char*) * 22);
// 	if (ac == 2)
// 	{
// 		int fd = open(av[1], O_RDONLY);
// 		if (fd == -1)
// 		{
// 			puts("Error\n");
// 			return (0);
// 		}
// 		char *line;
// 		line = get_next_line(fd);
// 		int i;
// 		while (line)
// 		{
// 			printf("%d => %s",ft_strlen(line) - 1, line);
// 			map[length] = ft_strdup(line);
// 			free(line);
// 			i = 0;
// 			while(map[length][i] &&  map[length][i] == 32)
// 				i++;
// 			if (length >= 8 && (map[length][i] != '1' || map[length][ft_strlen(map[length]) - 2] != '1'))
// 			{
// 				printf("Error at %s\n", map[length]);
// 				return (0);
// 			}
// 			if (map[length + 1] && map[length + 1][i] != '1')
// 			{
// 				printf("Error at %s\n", map[length + 1]);
// 				return (0);
// 			}
// 			line = get_next_line(fd);
// 			length++;
// 		}
// 	}
// 	// atexit(leaks);
// 	return (0);
// }
