/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mv_fa_to_b2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asabbar <asabbar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 16:42:30 by asabbar           #+#    #+#             */
/*   Updated: 2022/03/16 16:59:34 by asabbar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_mv_fa_to_b2_utils(t_vars *nb, int index, int nbr)
{
	index++;
	while (--index != 0)
		ft_r_a(nb, '1');
	index = ft_index_nb(nb->stacks_a, nbr, nb->count_stacks_a);
	ft_push_b(nb);
	return (index);
}

int	ft_mv_fa_to_b2_utils2(t_vars *nb, int index, int nbr)
{
	index--;
	while (++index < nb->count_stacks_a)
		ft_rr_a(nb, '1');
	index = ft_index_nb(nb->stacks_a, nbr, nb->count_stacks_a);
	ft_push_b(nb);
	return (index);
}

void	ft_mv_fa_to_b2(t_vars *nb, int *list)
{
	int		index;
	int		i;
	int		j;
	int		nbr;

	j = 0;
	i = 0;
	index = 0;
	i = 0;
	while (i < nb->count)
	{
		if (list[i] == 0)
		{
			index = ft_index_nb(nb->stacks_a,
					nb->stacks_a[j], nb->count_stacks_a);
			nbr = nb->stacks_a[index];
			if (index <= nb->count_stacks_a / 2)
				index = ft_mv_fa_to_b2_utils(nb, index, nbr);
			else
				index = ft_mv_fa_to_b2_utils2(nb, index, nbr);
			j = index - 1;
		}
		i++;
		j++;
	}
}
