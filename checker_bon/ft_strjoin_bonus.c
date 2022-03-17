/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asabbar <asabbar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 17:52:48 by asabbar           #+#    #+#             */
/*   Updated: 2022/03/16 22:21:20 by asabbar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

int	ft_strlen(char *s)
{	
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

char	*move(char *s1, char *s2, char *s)
{
	int		a;
	int		i;

	a = ft_strlen(s1);
	i = 0;
	if (s1)
	{
		while (s1[i])
		{
			s[i] = s1[i];
			i++;
		}
	}
	i = 0;
	while (s2[i])
	{
		s[a] = s2[i];
		a++;
		i++;
	}
	s[a] = '\0';
	return (s);
}

char	*ft_strjoin(char *s1, char *s2)
{
	int		a;
	int		i;
	int		j;
	char	*s;

	i = 0;
	j = 0;
	if (!s2)
		return (NULL);
	a = ft_strlen(s1);
	s = (char *)malloc(a + ft_strlen(s2) + 1);
	if (s == NULL)
		return (NULL);
	s = move(s1, s2, s);
	return (s);
}

char	*ft_strjoin1(char *s1, char *s2)
{
	int		a;
	int		i;
	char	*s;

	i = 0;
	if (!s1)
	{
		s1 = (char *)malloc(1 * sizeof(char));
		ft_protect(s1);
		s1[0] = '\0';
	}
	if (!s2)
		return (NULL);
	a = ft_strlen(s1);
	s = (char *)malloc(a + ft_strlen(s2) + 1);
	if (s == NULL)
		return (NULL);
	s = move(s1, s2, s);
	free(s1);
	return (s);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;

	i = 0;
	if (!s)
		return (NULL);
	while (s[i] != (char)c)
	{
		if (s[i] == '\0')
			return (NULL);
		i++;
	}
	return ((char *)s);
}
