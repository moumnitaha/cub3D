/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3D.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akhaliss <akhaliss@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/21 13:43:22 by tmoumni           #+#    #+#             */
/*   Updated: 2023/10/30 11:45:19 by akhaliss         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include <stdio.h>
# include <stdlib.h>
# include "gnl/get_next_line.h"

typedef struct s_data
{
    char	**map;
    char	*no_txt;
    char	*so_txt;
    char	*we_txt;
    char	*ea_txt;
    int	    floor_c;
    int	    ceilling_c;
    int     mlen;
}	t_data;

// *** LIBFT FUNCTIONS *** //

char	*ft_strjoin(char const *s1, char const *s2);
char	**ft_split(char const *s, char c);
char	*ft_strdup(const char *s1);
void	ft_putstr_fd(char *s, int fd);
size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize);
int		ft_atoi(const char *str);
int		ft_isdigit(int c);
char	*ft_substr(char const *s, unsigned int start, size_t len);
size_t  ft_strlen(const char *str);
int     ft_strcmp(const char *s1, const char *s2);


// *** CUB3D FUNCTIONS *** //

int     ft_open(char *file, int perm, t_data *game);
void	init_map(t_data *game);
void	read_map(char *file, t_data *game);
int		get_info(t_data *game, char *line);
void	_error(char *err);
int     _line(t_data *game, char *line, int l);
void	set_txt(t_data *game, char c, char *path);
int		get_color(char *line);
int		_colors(char *line, int *rgb);

#endif