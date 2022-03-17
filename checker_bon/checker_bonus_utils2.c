/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus_utils2.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asabbar <asabbar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 17:46:04 by asabbar           #+#    #+#             */
/*   Updated: 2022/03/16 22:16:17 by asabbar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

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
