/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asabbar <asabbar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/13 20:20:06 by asabbar           #+#    #+#             */
/*   Updated: 2022/03/16 22:16:17 by asabbar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	ft_check_moves(t_vars *nb, char *str)
{
	if (ft_strncmp(str, "pa") == 0)
		ft_push_a(nb);
	else if (ft_strncmp(str, "pb") == 0)
		ft_push_b(nb);
	else if (ft_strncmp(str, "sa") == 0)
		ft_swapa(nb);
	else if (ft_strncmp(str, "sb") == 0)
		ft_swapb(nb);
	else if (ft_strncmp(str, "ra") == 0)
		ft_r_a(nb);
	else if (ft_strncmp(str, "rb") == 0)
		ft_r_b(nb);
	else if (ft_strncmp(str, "rra") == 0)
		ft_rr_a(nb);
	else if (ft_strncmp(str, "rrb") == 0)
		ft_rr_b(nb);
	else if (ft_strncmp(str, "rr") == 0)
		ft_r(nb);
	else if (ft_strncmp(str, "rrr") == 0)
		ft_rr(nb);
	else if (ft_strncmp(str, "ss"))
	{
		ft_putstr("Error\n");
		exit(1);
	}
}

void	ft_check_sort(t_vars nb)
{
	int				i;
	int				l;
	int				nbr;

	i = 1;
	l = -1;
	nbr = nb.stacks_a[0];
	while (i < nb.count)
	{
		if (nb.stacks_a[i] > nbr && !nb.count_stacks_b)
			nbr = nb.stacks_a[i];
		else
		{
			ft_putstr("KO\n");
			free(nb.stacks_b);
			free(nb.stacks_a);
			exit(1);
		}
		i++;
	}
	ft_putstr("OK\n");
	free(nb.stacks_b);
	free(nb.stacks_a);
	exit(0);
}

void	ft_check_sort2(t_vars nb, char *str)
{
	int				i;
	int				nbr;

	i = 1;
	nbr = nb.stacks_a[0];
	while (i < nb.count)
	{
		if (nb.stacks_a[i] > nbr)
			nbr = nb.stacks_a[i];
		else
			return ;
		i++;
	}
	if (str)
		return ;
	ft_putstr("OK\n");
	free(nb.stacks_b);
	free(nb.stacks_a);
	exit(0);
}

int	main(int ac, char **av)
{
	char			*str;
	int				i;
	t_vars			nb;

	nb.stacks_a = ft_ckeck(av, ac);
	nb.count = ft_count_av(av);
	nb.stacks_b = (int *)malloc(nb.count * sizeof(int));
	ft_protect_int(nb.stacks_b);
	nb.count_stacks_a = nb.count;
	nb.count_stacks_b = 0;
	i = 0;
	str = get_next_line(0);
	ft_check_sort2(nb, str);
	while (str)
	{
		ft_check_moves(&nb, str);
		free(str);
		str = get_next_line(0);
		i++;
	}
	ft_check_sort(nb);
}
