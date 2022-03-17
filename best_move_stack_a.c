/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   best_move_stack_a.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asabbar <asabbar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 19:35:22 by asabbar           #+#    #+#             */
/*   Updated: 2022/03/16 22:18:10 by asabbar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	*ft_utils(t_vars *nb, int *moves, int ca, int i)
{
	int	a;

	a = ft_location_in_a(nb, nb->stacks_b[i]);
	moves[0] = a;
	if (a < i)
		moves[0] = i;
	moves[1] = ca - a;
	if (moves[1] < (nb->count_stacks_b - i))
		moves[1] = nb->count_stacks_b - i;
	moves[2] = (ca - a) + i;
	moves[3] = a + (nb->count_stacks_b - i);
	return (moves);
}

void	ft_protect(char *str)
{
	if (str == NULL)
		exit(0);
}

void	ft_protect_int(int *str)
{
	if (str == NULL)
		exit(0);
}

void	ft_protect_dint(int **str)
{
	if (str == NULL)
		exit(0);
}

int	best_move_stack_a(t_vars *nb)
{
	int	i;
	int	ca;
	int	*list;
	int	*moves;
	int	best_move;

	ca = nb->count_stacks_a;
	i = 0;
	list = malloc(nb->count_stacks_b * sizeof(int));
	ft_protect_int(list);
	moves = malloc(4 * sizeof(int));
	ft_protect_int(moves);
	while (i < nb->count_stacks_b)
	{
		moves = ft_utils(nb, moves, ca, i);
		list[i] = ft_small(moves, 4);
		i++;
	}
	best_move = ft_small(list, nb->count_stacks_b);
	best_move = ft_index_nb(list, best_move, nb->count_stacks_b);
	free(moves);
	free(list);
	return (best_move);
}
