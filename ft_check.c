/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asabbar <asabbar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 13:41:27 by asabbar           #+#    #+#             */
/*   Updated: 2022/03/16 22:02:40 by asabbar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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

int	*ft_ckeck(char **av, int ac)
{
	int		*nb;
	char	*p;
	char	**str;
	int		count;

	ft_ckeck_null(ac, av);
	ft_ckeck_space(av);
	p = ft_join(av);
	str = ft_check_is_digit(p);
	free(p);
	count = ft_count_av(av);
	nb = ft_type(str, count);
	ft_fre(str);
	ft_check_dub(nb, count);
	return (nb);
}
