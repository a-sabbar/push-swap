/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asabbar <asabbar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 17:42:55 by asabbar           #+#    #+#             */
/*   Updated: 2022/03/16 22:16:17 by asabbar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	ft_putstr(char	*c)
{
	int		i;

	i = 0;
	if (!c)
		ft_putstr("(null)");
	while (c[i] != '\0')
	{
		write(1, &c[i], 1);
		i++;
	}
}

int	ft_strncmp(char *str1, char *str2)
{
	int	i;

	i = 0;
	while (str1[i] && str2[i] && str1[i] == str2[i])
		i++;
	return (str1[i] - str2[i]);
}

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

void	ft_fre(char **cmd)
{
	int	i;

	i = -1;
	while (cmd[++i])
		free(cmd[i]);
	free(cmd);
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
