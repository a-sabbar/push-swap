/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asabbar <asabbar@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/23 09:27:16 by asabbar           #+#    #+#             */
/*   Updated: 2022/03/16 22:00:12 by asabbar          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

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
}	t_vars;

int		ft_strncmp(char *str1, char *str2);
void	ft_ckeck_null(int ac, char **av);
void	ft_ckeck_space(char **av);
char	*ft_strjoin(char *s1, char *s2);
char	**ft_check_is_digit(char *p);
void	ft_check_dub(int	*nb, int count);
int		*ft_ckeck(char **av, int ac);
char	*move(char *s1, char *s2, char *s);
int		ft_strlen(char *s);
int		words_count(char *s, char c);
void	move_word(char *from, char *to, int start, int j);
void	ft_free(char **p, int a);
void	ft_mallocnmove(char **p, char *s, char c);
char	**ft_split(char *s, char c);
void	ft_swapa(t_vars *nb);
void	ft_swapb(t_vars *nb);
void	ft_r_a(t_vars	*nb);
void	ft_r_b(t_vars	*nb);
void	ft_r(t_vars	*nb);
void	ft_push_a(t_vars	*nb);
void	ft_push_b(t_vars	*nb);
void	ft_rr_b(t_vars	*nb);
void	ft_rr_a(t_vars	*nb);
void	ft_rr(t_vars	*nb);
void	ft_fre(char **cmd);
char	*ft_join(char **av);
char	*ft_strjoin1(char *s1, char *s2);
int		*ft_type(char **str, int j);
int		ft_atoi(char *str);
int		ft_isdigit(int c);
int		ft_count_av(char **av);
char	*ft_strchr(const char *s, int c);
char	*get_next_line(int fd);
void	ft_putstr(char	*c);
void	ft_protect(char *str);
void	ft_protect_int(int *str);
void	ft_protect_dint(int **str);
#endif