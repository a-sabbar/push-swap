/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asabbar <asabbar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 09:27:16 by asabbar           #+#    #+#             */
/*   Updated: 2022/03/16 22:34:25 by asabbar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

typedef struct s_vars {
	int	*stacks_a;
	int	*stacks_b;
	int	count;
	int	count_stacks_b;
	int	count_stacks_a;
	int	*push;
	int	*list;
}	t_vars;
typedef struct s_var {
	int		check;
	int		i;
	int		len;
	int		x;
	int		last;
	int		count;
	int		b;
	int		**nbs1;
	int		*list;
}	t_var;
void	ft_protect_dint(int **str);
void	ft_protect(char *str);
void	ft_protect_int(int *str);
int		ft_best_move_count(int nb, t_vars *nbs);
int		ft_sersh0(int *nbs, int count);
int		ft_count0(int *nbs, int count);
int		*ft_r_arry(int *nb, t_vars *nbr);
int		*ft_rr_arry(t_vars	*nbr, int *nb);
int		*ft_push_arry(t_vars	*nbr, int *nb);
int		ft_small(int *arry, int count);
int		ft_index_nb(int *arry, int nb, int count);
int		ft_location_in_a(t_vars *stack, int nb);
int		best_move_stack_a(t_vars *nb);
int		*ft_big_list(t_vars nb);
void	ft_r(t_vars	*nb);
void	ft_rr(t_vars	*nb);
char	*ft_strjoin(char *s1, char *s2);
int		ft_count_av(char **av);
int		*ft_type(char **str, int j);
int		ft_atoi(char *str);
int		ft_strncmp(char *str1, char *str2);
char	**ft_split(char *s, char c);
void	ft_fre(char **cmd);
int		ft_strlen(char *s);
int		ft_isdigit(int c);
int		*ft_ckeck(char **av, int ac);
char	*ft_strjoin1(char *s1, char *s2);
void	ft_swapb(t_vars *nb);
void	ft_swapa(t_vars *nb);
int		ft_strlen(char *s);
void	ft_push_a(t_vars	*nb);
void	ft_push_b(t_vars	*nb);
void	ft_r_a(t_vars	*nb, char c);
void	ft_r_b(t_vars	*nb, char c);
void	ft_rr_b(t_vars	*nb, char c);
void	ft_rr_a(t_vars	*nb, char c);
void	ft_rr_a2(t_vars	*nb, char c);
void	ft_r_a2(t_vars	*nb, char c);
void	ft_mv_fa_to_b(t_vars *nb, int **list);
void	ft_mv_fb_to_a(t_vars *nb);
void	ft_ckeck_null(int ac, char **av);
void	ft_ckeck_space(char **av);
char	*ft_join(char **av);
void	ft_mv_fb_to_a(t_vars *nb);
void	*ft_memmove(void *dest, const void *src, size_t n);
void	ft_mv_fa_to_b2(t_vars *nb, int *list);
void	ft_putstr(char	*c);
#endif