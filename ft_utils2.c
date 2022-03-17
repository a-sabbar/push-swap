/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asabbar <asabbar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/11 19:54:23 by asabbar           #+#    #+#             */
/*   Updated: 2022/03/16 22:16:17 by asabbar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_best_move_count(int nb, t_vars *nbs)
{
	int	i;
	int	j;

	j = nbs->count_stacks_a;
	i = j / 2;
	if (nb > i)
		return (1);
	else if (nb <= i)
		return (0);
	return (0);
}

int	ft_sersh0(int *nbs, int count)
{
	int	i;
	int	j;

	j = count;
	i = 0;
	while (count)
	{
		if (nbs[i] != 1)
			return (i);
		i++;
		count--;
	}
	return (-1);
}

int	ft_count0(int *nbs, int count)
{
	int	i;
	int	b;
	int	j;

	j = count;
	i = 0;
	b = 0;
	while (count)
	{
		if (nbs[i] != 1)
			b++;
		i++;
		count--;
	}
	return (b);
}

int	*ft_r_arry(int *nb, t_vars *nbr)
{
	int	*push;
	int	i;

	push = malloc(nbr->count_stacks_a * sizeof(int));
	ft_protect_int(push);
	push[nbr->count_stacks_a - 1] = nb[0];
	i = 0;
	while (i < nbr->count_stacks_a - 1)
	{
		push[i] = nb[i + 1];
		i++;
	}
	free(nb);
	nb = NULL;
	return (push);
}

int	*ft_rr_arry(t_vars	*nbr, int *nb)
{
	int	*push;
	int	i;

	push = malloc(nbr->count_stacks_a * sizeof(int));
	ft_protect_int(push);
	push[0] = nb[nbr->count_stacks_a - 1];
	i = 1;
	while (i < nbr->count_stacks_a - 1)
	{
		push[i] = nb[i - 1];
		i++;
	}
	free(nb);
	nb = NULL;
	return (push);
}
