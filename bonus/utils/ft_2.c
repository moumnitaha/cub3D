/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tmoumni <tmoumni@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/28 09:39:06 by akhaliss          #+#    #+#             */
/*   Updated: 2023/11/23 13:27:39 by tmoumni          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub3D_bonus.h"

static size_t	ft_lenw(char *c, char s, size_t j)
{
	while (c[j] && c[j] != s)
	{
		j++;
	}
	return (j);
}

static size_t	ft_countw(char *c, char s)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (c[i] != '\0')
	{
		while (c[i] != '\0' && c[i] == s)
			i++;
		if (c[i] != '\0' && c[i] != s)
			j++;
		while (c[i] != '\0' && c[i] != s)
			i++;
	}
	return (j);
}

static char	**ft_free(char **ptr)
{
	unsigned int	i;

	i = 0;
	while (ptr[i])
	{
		free(ptr[i]);
		i++;
	}
	free(ptr);
	return (0);
}

static char	**fill(char **s1, char const *s, char c)
{
	size_t	lenw;
	size_t	countw;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	countw = ft_countw((char *)s, c);
	s1 = malloc(sizeof(char *) * (countw + 1));
	if (!s1)
		return (NULL);
	while (j < countw)
	{
		while (s[i] == c)
			i++;
		lenw = ft_lenw((char *)s, c, i);
		s1[j] = ft_substr(s, i, (lenw - i));
		if (!s1[j])
			return (ft_free(s1));
		i = 0;
		i += lenw;
		j++;
	}
	s1[j] = NULL;
	return (s1);
}

char	**ft_split(char const *s, char c)
{
	char	**s1;
	char	**arr;

	arr = NULL;
	if (!s)
		return (NULL);
	s1 = fill (arr, s, c);
	return (s1);
}
