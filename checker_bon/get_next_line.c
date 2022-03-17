/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asabbar <asabbar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 17:22:13 by asabbar           #+#    #+#             */
/*   Updated: 2022/03/16 22:16:17 by asabbar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

char	*ft_read(char *rest, int fd)
{
	int		i;
	char	*s;

	s = malloc(2);
	ft_protect(s);
	if (!s)
		return (NULL);
	i = 1;
	while (!ft_strchr(rest, '\n'))
	{
		i = read (fd, s, 1);
		if (i == -1)
		{
			free(s);
			return (NULL);
		}
		s[i] = '\0';
		rest = ft_strjoin1(rest, s);
		if (rest[0] == '\0')
			break ;
	}
	free(s);
	return (rest);
}

char	*ft_line(char *rest)
{
	int		i;
	char	*line;

	i = 0;
	if (!rest[i])
		return (NULL);
	while (rest[i] != '\n' && rest[i])
		i++;
	line = (char *)malloc(sizeof(char) * (i + 1));
	ft_protect(line);
	i = 0;
	while (rest[i] != '\n' && rest[i])
	{
		line[i] = rest[i];
		i++;
	}
	line[i] = '\0';
	return (line);
}

char	*get_next_rest(char *rest)
{
	int		i;
	int		x;
	char	*newrest;
	int		lnrest;

	i = 0;
	while (rest[i] != '\0' && rest[i] != '\n')
		i++;
	if (!rest[i])
	{
		free(rest);
		return (NULL);
	}
	i++;
	x = 0;
	lnrest = ft_strlen(&rest[i]);
	newrest = malloc(lnrest + 1);
	ft_protect(newrest);
	if (!newrest)
		return (NULL);
	while (rest[i])
		newrest[x++] = rest[i++];
	newrest[x] = '\0';
	free(rest);
	return (newrest);
}

char	*get_next_line(int fd)
{
	static char	*rest;
	char		*line;

	if (fd < 0)
		return (NULL);
	rest = ft_read(rest, fd);
	if (!rest[0])
		return (NULL);
	line = ft_line(rest);
	rest = get_next_rest(rest);
	return (line);
}
