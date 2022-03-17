/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mv_fb_to_a.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asabbar <asabbar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 20:15:03 by asabbar           #+#    #+#             */
/*   Updated: 2022/03/15 12:08:52 by asabbar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_util_mv_b_to_a(t_vars *nb, int x, int l)
{
	while (x <= (nb->count_stacks_b / 2) && x > 0)
	{
		ft_r_b(nb, '1');
		x--;
	}
	while (l <= (nb->count_stacks_a / 2) && l > 0)
	{
		ft_r_a(nb, '1');
		l--;
	}
	while (l > (nb->count_stacks_a / 2) && l < nb->count_stacks_a)
	{
		ft_rr_a(nb, '1');
		l++;
	}
	while (x > (nb->count_stacks_b / 2) && x < nb->count_stacks_b)
	{
		ft_rr_b(nb, '1');
		x++;
	}
}

void	ft_util_mv_b_to_a1(t_vars *nb, int x, int l)
{
	while (x <= (nb->count_stacks_b / 2) && l <= (nb->count_stacks_a / 2)
		&& l > 0 && x > 0)
	{
		ft_r(nb);
		x--;
		l--;
	}
	while (x > (nb->count_stacks_b / 2) && l > (nb->count_stacks_a / 2)
		&& l < nb->count_stacks_a && x < nb->count_stacks_b)
	{
		ft_rr(nb);
		x++;
		l++;
	}
	ft_util_mv_b_to_a(nb, x, l);
}

void	ft_mv_fb_to_a(t_vars *nb)
{
	int		l;
	int		x;

	l = 0;
	x = 0;
	while (nb->count_stacks_b)
	{
		x = best_move_stack_a(nb);
		l = ft_location_in_a(nb, nb->stacks_b[x]);
		ft_util_mv_b_to_a1(nb, x, l);
		ft_push_a(nb);
	}
}
