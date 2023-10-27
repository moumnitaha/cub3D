#include "../cub3D.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	int		i;
	int		j;
	char	*s;

	j = 0;
	i = 0;
	if (!s1 || !s2)
		return (NULL);
	s = malloc(ft_strlen (s1) + ft_strlen(s2) + 1);
	if (!s)
		return (NULL);
	if ((s1[i] || s2[i]) != '\0')
	{
		while (s1[i])
			s[j++] = s1[i++];
		i = 0;
		while (s2[i])
			s[j++] = s2[i++];
	}
	s[j] = '\0';
	return (s);
}

char	*ft_strdup(const char *s1)
{
	char	*s01;
	int		i;

	i = 0;
	s01 = malloc(sizeof(char) * (ft_strlen(s1) + 1));
	if (!s01)
		return (NULL);
	while (s1[i])
	{
		s01[i] = s1[i];
		i++;
	}
	s01[i] = '\0';
	return (s01);
}

void	ft_putstr_fd(char *s, int fd)
{
	int	i;

	i = 0;
	if (!s || !fd)
		return ;
	while (s[i] != '\0')
	{
		write(fd, &s[i], 1);
		i++;
	}
}

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	srcl;

	srcl = ft_strlen(src);
	i = 0;
	if (dstsize)
	{
		while (src[i] && i < (dstsize - 1))
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
	}
	return (srcl);
}

int	ft_atoi(const char *str)
{
	int	i ;
	int	res;
	int	sign;

	i = 0;
	res = 0;
	sign = 1;
	while (str[i] == ' ' || str[i] == '\n' || str[i] == '\t'
		|| str[i] == '\v' || str[i] == '\r' || str[i] == '\f')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign *= (-1);
			i++;
	}
	while (str[i] && (str[i] >= 48 && str[i] <= 57))
	{
		res = (res * 10) + str[i] - '0';
		i++;
	}
	return (res * sign);
}
