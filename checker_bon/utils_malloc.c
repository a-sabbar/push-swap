/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_malloc.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asabbar <asabbar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/16 21:50:58 by asabbar           #+#    #+#             */
/*   Updated: 2022/03/16 22:14:55 by asabbar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

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
