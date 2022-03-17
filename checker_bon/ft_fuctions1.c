/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fuctions1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asabbar <asabbar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/01 09:14:10 by asabbar           #+#    #+#             */
/*   Updated: 2022/03/16 22:16:17 by asabbar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	ft_swapa(t_vars *nb)
{
	int	*a;
	int	i;

	if (!nb->count_stacks_a)
		return ;
	a = malloc(nb->count_stacks_a * sizeof(int));
	ft_protect_int(a);
	a[0] = nb->stacks_a[1];
	a[1] = nb->stacks_a[0];
	i = 2;
	while (i < nb->count_stacks_a)
	{
		a[i] = nb->stacks_a[i];
		i++;
	}
	free(nb->stacks_a);
	nb->stacks_a = a;
}

void	ft_swapb(t_vars *nb)
{
	int	*a;
	int	i;

	if (!nb->count_stacks_b)
		return ;
	a = malloc(nb->count_stacks_b * sizeof(int));
	ft_protect_int(a);
	a[0] = nb->stacks_b[1];
	a[1] = nb->stacks_b[0];
	i = 2;
	while (i < nb->count_stacks_b)
	{
		a[i] = nb->stacks_b[i];
		i++;
	}
	free(nb->stacks_b);
	nb->stacks_a = a;
}

void	ft_r_a(t_vars	*nb)
{
	int	*push;
	int	i;
	int	j;

	if (!nb->count_stacks_a)
		return ;
	push = malloc(nb->count_stacks_a * sizeof(int));
	ft_protect_int(push);
	push[nb->count_stacks_a - 1] = nb->stacks_a[0];
	i = 0;
	j = nb->count_stacks_a;
	while (--j)
	{
		push[i] = nb->stacks_a[i + 1];
		i++;
	}
	free(nb->stacks_a);
	nb->stacks_a = push;
}

void	ft_r_b(t_vars	*nb)
{
	int	*push;
	int	i;
	int	j;

	if (!nb->count_stacks_b)
		return ;
	push = malloc(nb->count_stacks_b * sizeof(int));
	ft_protect_int(push);
	push[nb->count_stacks_b - 1] = nb->stacks_b[0];
	i = 0;
	j = nb->count_stacks_b;
	while (--j)
	{
		push[i] = nb->stacks_b[i + 1];
		i++;
	}
	free(nb->stacks_b);
	nb->stacks_b = push;
}

void	ft_r(t_vars	*nb)
{
	if (!nb->count_stacks_a || !nb->count_stacks_b)
		return ;
	ft_r_a(nb);
	ft_r_b(nb);
}
