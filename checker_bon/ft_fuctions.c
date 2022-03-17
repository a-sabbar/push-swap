/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fuctions.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asabbar <asabbar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/28 16:18:30 by asabbar           #+#    #+#             */
/*   Updated: 2022/03/16 22:16:17 by asabbar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	ft_push_a(t_vars	*nb)
{
	int	i;
	int	*push;
	int	*newb;

	if (!nb->count_stacks_b)
		return ;
	nb->count_stacks_a++;
	nb->count_stacks_b--;
	push = malloc(nb->count_stacks_a * sizeof(int));
	ft_protect_int(push);
	push[0] = nb->stacks_b[0];
	i = 0;
	while (++i < nb->count_stacks_a)
		push[i] = nb->stacks_a[i - 1];
	newb = malloc(nb->count_stacks_b * sizeof(int));
	ft_protect_int(newb);
	i = -1;
	while (++i < nb->count_stacks_b)
		newb[i] = nb->stacks_b[i + 1];
	free(nb->stacks_a);
	free(nb->stacks_b);
	nb->stacks_b = newb;
	nb->stacks_a = push;
}

void	ft_push_b(t_vars	*nb)
{
	int	*push;
	int	*newa;
	int	i;

	if (!nb->count_stacks_a)
		return ;
	nb->count_stacks_b++;
	nb->count_stacks_a--;
	push = malloc(nb->count_stacks_b * sizeof(int));
	ft_protect_int(push);
	push[0] = nb->stacks_a[0];
	i = 0;
	while (++i < nb->count_stacks_b)
		push[i] = nb->stacks_b[i - 1];
	newa = malloc(nb->count_stacks_a * sizeof(int));
	ft_protect_int(newa);
	i = -1;
	while (++i < nb->count_stacks_a)
		newa[i] = nb->stacks_a[i + 1];
	free(nb->stacks_a);
	free(nb->stacks_b);
	nb->stacks_a = newa;
	nb->stacks_b = push;
}

void	ft_rr_b(t_vars	*nb)
{
	int	*push;
	int	i;
	int	j;

	if (!nb->count_stacks_b)
		return ;
	push = malloc(nb->count_stacks_b * sizeof(int));
	ft_protect_int(push);
	push[0] = nb->stacks_b[nb->count_stacks_b - 1];
	i = 1;
	j = nb->count_stacks_b;
	while (i < j)
	{
		push[i] = nb->stacks_b[i - 1];
		i++;
	}
	free(nb->stacks_b);
	nb->stacks_b = push;
}

void	ft_rr_a(t_vars	*nb)
{
	int	*push;
	int	i;

	if (!nb->count_stacks_a)
		return ;
	push = malloc(nb->count_stacks_a * sizeof(int));
	ft_protect_int(push);
	push[0] = nb->stacks_a[nb->count_stacks_a - 1];
	i = 1;
	while (i < nb->count_stacks_a)
	{
		push[i] = nb->stacks_a[i - 1];
		i++;
	}
	free(nb->stacks_a);
	nb->stacks_a = push;
}

void	ft_rr(t_vars	*nb)
{
	if (!nb->count_stacks_a || !nb->count_stacks_b)
		return ;
	ft_rr_a(nb);
	ft_rr_b(nb);
}
