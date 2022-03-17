/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils3.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asabbar <asabbar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 19:26:42 by asabbar           #+#    #+#             */
/*   Updated: 2022/03/16 22:16:17 by asabbar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*ft_push_arry(t_vars	*nbr, int *nb)
{
	int	*push;
	int	i;

	push = malloc(nbr->count_stacks_a * sizeof(int));
	ft_protect_int(push);
	push[0] = nb[1];
	i = 1;
	while (i < nbr->count_stacks_a)
	{
		push[i] = nb[i + 1];
		i++;
	}
	free(nb);
	nb = NULL;
	return (push);
}

int	ft_small(int *arry, int count)
{
	int	i;
	int	j;

	j = arry[0];
	i = 0;
	while (count)
	{
		if (arry[i] < j)
			j = arry[i];
		i++;
		count--;
	}
	return (j);
}

int	ft_index_nb(int *arry, int nb, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		if (arry[i] == nb)
			return (i);
		i++;
	}
	return (-1);
}

int	ft_location_in_a(t_vars *stack, int nb)
{
	int	i;
	int	j;
	int	nbr;

	i = 1;
	j = ft_small(stack->stacks_a, stack->count_stacks_a);
	while (i < stack->count_stacks_a)
	{
		if (nb < stack->stacks_a[i] && nb > stack->stacks_a[i - 1])
			return (i);
		i++;
	}
	if (nb < j)
	{
		nbr = ft_index_nb(stack->stacks_a, j, stack->count_stacks_a);
		return (nbr);
	}
	if (nb < stack->stacks_a[0]
		&& nb > stack->stacks_a[stack->count_stacks_a - 1])
		return (0);
	if (nb > stack->stacks_a[0]
		&& nb < stack->stacks_a[stack->count_stacks_a - 1])
		return (stack->count_stacks_a - 1);
	return (-1);
}
