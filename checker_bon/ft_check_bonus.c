/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asabbar <asabbar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 20:00:55 by asabbar           #+#    #+#             */
/*   Updated: 2022/03/16 17:46:51 by asabbar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

char	**ft_check_is_digit(char *p)
{
	char	**str;
	int		i;
	int		j;

	i = 0;
	j = 0;
	str = ft_split(p, ' ');
	while (str[i])
	{
		j = 0;
		while (str[i][j])
		{
			if (!ft_isdigit(str[i][j]) || ((str[i][j] == '-'
				|| str[i][j] == '+') && !ft_isdigit(str[i][j + 1])))
			{
				ft_putstr("Error\n");
				exit(1);
			}
			j++;
		}
		i++;
	}
	return (str);
}

void	ft_check_dub(int	*nb, int count)
{
	int		i;
	int		j;
	int		n;

	i = 0;
	j = 0;
	n = count;
	while (i < count)
	{
		j = i + 1;
		while (j < count)
		{
			if (nb[i] == nb[j])
			{
				ft_putstr("Error\n");
				exit(1);
			}
			j++;
		}
		i++;
	}
}

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

int	ft_isdigit(int c)
{
	if ((c < 48 || c > 57) && c != '-' && c != '+')
		return (0);
	else
		return (1);
}
