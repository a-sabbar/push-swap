/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils_check.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asabbar <asabbar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 19:51:37 by asabbar           #+#    #+#             */
/*   Updated: 2022/03/16 22:19:59 by asabbar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_ckeck_null(int ac, char **av)
{
	int	i;

	i = ac - 1;
	while (i)
	{
		if (av[i][0] == '\0')
		{
			ft_putstr("Error\n");
			exit(1);
		}
		i--;
	}
}

void	ft_ckeck_space(char **av)
{
	int	i;
	int	j;
	int	n;

	i = 1;
	while (av[i])
	{
		j = 0;
		n = 0;
		while (av[i][j])
		{
			if (ft_isdigit(av[i][j]))
				n++;
			j++;
		}
		if (n == 0)
		{
			ft_putstr("Error\n");
			exit(1);
		}
		i++;
	}
}

char	*ft_join(char **av)
{
	int		i;
	char	*p;
	char	*p1;

	i = 1;
	p = malloc(1);
	ft_protect(p);
	p[0] = '\0';
	while (av[i])
	{
		p1 = ft_strjoin(" ", av[i]);
		p = ft_strjoin1(p, p1);
		free(p1);
		i++;
	}
	return (p);
}
