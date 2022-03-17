/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils0.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asabbar <asabbar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 13:42:42 by asabbar           #+#    #+#             */
/*   Updated: 2022/03/16 22:20:09 by asabbar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_count_av(char **av)
{
	int	i;
	int	j;
	int	count;

	i = 0;
	j = 0;
	count = 0;
	while (av[i])
	{
		j = 0;
		while (av[i][j])
		{
			if (ft_isdigit(av[i][j]) && !ft_isdigit(av[i][j + 1]))
				count++;
			j++;
		}
		i++;
	}
	return (count);
}

int	*ft_type(char **str, int j)
{
	int		*nbs;
	int		i;

	i = 0;
	nbs = malloc(j * sizeof(int));
	ft_protect_int(nbs);
	while (str[i] != '\0')
	{
		nbs[i] = ft_atoi(str[i]);
		i++;
	}
	return (nbs);
}

int	ft_atoi(char *str)
{
	int		i;
	long	r;
	int		sn;

	r = 0;
	i = 0;
	sn = 1;
	if (str[i] == '-')
		sn *= -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		r = (r * 10) + str[i] - '0';
		i++;
	}
	if (((r * sn) < -2147483648 || (r * sn) > 2147483647)
		|| (str[i] == '-' || str[i] == '+'))
	{
		ft_putstr("Error\n");
		exit(1);
	}
	return (r * sn);
}

int	ft_isdigit(int c)
{
	if ((c < 48 || c > 57) && c != '-' && c != '+')
		return (0);
	else
		return (1);
}

int	ft_strncmp(char *str1, char *str2)
{
	unsigned int	i;

	i = 0;
	while (str1[i] && str2[i] && str1[i] == str2[i])
		i++;
	return (((unsigned char *)str1)[i] - ((unsigned char *)str2)[i]);
}
