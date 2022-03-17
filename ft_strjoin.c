/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asabbar <asabbar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 13:38:39 by asabbar           #+#    #+#             */
/*   Updated: 2022/03/12 19:58:12 by asabbar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

void	ft_fre(char **cmd)
{
	int	i;

	i = -1;
	while (cmd[++i])
		free(cmd[i]);
	free(cmd);
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
	if (!s2)
		return (NULL);
	a = ft_strlen(s1);
	s = (char *)malloc(a + ft_strlen(s2) + 1);
	if (s == NULL)
		return (NULL);
	s = move(s1, s2, s);
	if (s1)
		free(s1);
	return (s);
}
