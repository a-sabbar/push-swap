/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asabbar <asabbar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 13:41:47 by asabbar           #+#    #+#             */
/*   Updated: 2022/03/16 22:16:17 by asabbar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_mv_utils(t_vars *nb)
{
	int		*list;

	list = ft_big_list(*nb);
	if (nb->count_stacks_a < 100)
		ft_mv_fa_to_b2(nb, list);
	else
		ft_mv_fa_to_b(nb, &list);
	free(list);
}

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

void	push_swap(t_vars *nb)
{
	int		l;

	nb->stacks_b = (int *)malloc(nb->count * sizeof(int));
	ft_protect_int(nb->stacks_b);
	nb->count_stacks_a = nb->count;
	nb->count_stacks_b = 0;
	ft_mv_utils(nb);
	ft_mv_fb_to_a(nb);
	l = ft_small(nb->stacks_a, nb->count_stacks_a);
	l = ft_index_nb(nb->stacks_a, l, nb->count_stacks_a);
	if (l <= (nb->count_stacks_a / 2))
	{
		l += 1;
		while (--l)
			ft_r_a(nb, '1');
	}
	else
	{
		l -= 1;
		while (++l < nb->count_stacks_a)
			ft_rr_a(nb, '1');
	}
}

int	ft_big(int *arry, int count)
{
	int	i;
	int	j;

	j = arry[0];
	i = 0;
	while (i < count)
	{
		if (arry[i] > j)
		{
			j = arry[i];
		}
		i++;
	}
	return (j);
}

int	main(int ac, char **av)
{
	t_vars	nb;
	int		max;

	if (ac == 1)
		exit(1);
	nb.stacks_a = ft_ckeck(av, ac);
	nb.count = ft_count_av(av);
	nb.count_stacks_a = nb.count;
	if (nb.count == 3)
	{
		max = ft_big(nb.stacks_a, nb.count);
		if (nb.stacks_a[0] == max)
			ft_r_a(&nb, '1');
		else if (nb.stacks_a[1] == max)
			ft_rr_a(&nb, '1');
		if (nb.stacks_a[0] > nb.stacks_a[1])
			ft_swapa(&nb);
	}
	else
		push_swap(&nb);
	free(nb.stacks_b);
	free(nb.stacks_a);
}
