/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils1.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asabbar <asabbar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/26 13:44:17 by asabbar           #+#    #+#             */
/*   Updated: 2022/03/16 22:14:06 by asabbar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_util_big_list(t_var	*var, t_vars	nb)
{
	var->count = nb.count;
	var->x = var->i;
	var->check = var->x;
	var->len = 0;
	while (var->count)
	{
		if (nb.stacks_a[var->x] <= nb.stacks_a[var->check])
		{
			var->nbs1[var->i][var->check] = 1;
			var->x = var->check;
			var->len++;
		}
		else
			var->nbs1[var->i][var->check] = 0;
		var->check++;
		var->count--;
		if (var->count == var->i)
			var->check = 0;
	}
	if (var->len >= var->last)
	{
		var->last = var->len;
		var->b = var->i;
	}
}

int	*ft_big_list(t_vars nb)
{
	t_var	var;

	var.nbs1 = malloc(nb.count * sizeof(int *));
	ft_protect_dint(var.nbs1);
	var.i = -1;
	while (++var.i < nb.count)
	{
		var.nbs1[var.i] = malloc(nb.count * sizeof(int));
		ft_protect_int(var.nbs1[var.i]);
	}
	var.i = -1;
	var.last = 0;
	var.b = 0;
	while (++var.i < nb.count)
		ft_util_big_list(&var, nb);
	var.list = malloc(nb.count * sizeof(int));
	ft_protect_int(var.list);
	ft_memmove(var.list, var.nbs1[var.b], nb.count * sizeof(int));
	var.i = 0;
	while (var.i < nb.count)
		free(var.nbs1[var.i++]);
	free(var.nbs1);
	return (var.list);
}

int	**ft_utils_mv_fa_to_b(t_vars *nb, int **list, int l)
{
	while (l <= nb->count_stacks_a)
	{
		*list = ft_rr_arry(nb, *list);
		ft_rr_a(nb, '1');
		if (*list[0] != 1)
		{
			ft_push_b(nb);
			*list = ft_push_arry(nb, *list);
		}
		l++;
	}
	return (list);
}

int	**ft_utils_mv_fa_to_b1(t_vars *nb, int **list, int l)
{
	while (l)
	{
		*list = ft_r_arry(*list, nb);
		ft_r_a(nb, '1');
		if (*list[0] != 1)
		{
			ft_push_b(nb);
			*list = ft_push_arry(nb, *list);
		}
		l--;
	}
	return (list);
}

void	ft_mv_fa_to_b(t_vars *nb, int **list)
{
	int		l;
	int		l2;

	l = 0;
	l2 = 0;
	while (ft_count0(*list, nb->count_stacks_a))
	{
		l = ft_sersh0(*list, nb->count_stacks_a);
		if (l == -1)
			break ;
		l2 = ft_best_move_count(l, nb);
		if (l2 == 1)
			list = ft_utils_mv_fa_to_b(nb, list, l);
		else
			list = ft_utils_mv_fa_to_b1(nb, list, l);
		if (*list[0] != 1)
		{
			ft_push_b(nb);
			*list = ft_push_arry(nb, *list);
		}
	}
}
